whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

SET SHOWMODE ON

SET SERVEROUTPUT ON

VARIABLE CodigoCiclo NUMBER;
VARIABLE CodigoDeDestino NUMBER;
VARIABLE ERROR_ORA NUMBER;


--@../sql/CreaTabla.sql &&1


DECLARE
  TYPE ind_orden IS TABLE OF number INDEX BY BINARY_INTEGER;
  IndOrdenTotal  	ind_orden;

  TYPE tCol_Codest IS TABLE OF Varchar2(4) INDEX BY BINARY_INTEGER;
  ColCodigosDestino 	tCol_Codest;
  Col_codconcepto_new	tCol_Codest;


  Tecnologia 		Varchar2(10);
  sSql 			Varchar2(32767);

  i 			NUMBER;
  k			NUMBER;
  nConsulta 		NUMBER;

  --excepciones
  ERROR_1		EXCEPTION;   -- error en sumatoria de ajustes
  ERROR_2		EXCEPTION;   -- error en sumatoria fa_histconc_ciclo

  ErrorOracle		NUMBER;

  /* Variables para verificar consistencia en AJUSTES*/
  vImp_Facturable1	NUMBER;
  vImp_Concepto1	NUMBER;

  vImp_Facturable2	NUMBER;
  vImp_Concepto2	NUMBER;

  /* Variables para verificar consistencia en FA_HISTCONC_19010102*/
  vImp_concepto3	NUMBER;
  vImp_dcto3		NUMBER;
  vImp_Facturable3	NUMBER;
  vImp_Montobase3	NUMBER;
  vImp_ImpReal3		NUMBER;

  vImp_concepto4	NUMBER;
  vImp_dcto4		NUMBER;
  vImp_Facturable4	NUMBER;
  vImp_Montobase4	NUMBER;
  vImp_ImpReal4		NUMBER;

BEGIN

   /* ----->CONSULTA 14.1 <------ */
	nConsulta:=14.1;

	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Sumatoria de los totales de los montos de la tabla fa_histconc_&&1');

	SELECT 	sum(IMP_CONCEPTO),
		sum(IMP_DCTO),
		sum(IMP_FACTURABLE),
		sum(IMP_MONTOBASE),
		sum(IMP_REAL)
	INTO
		vImp_concepto3,
		vImp_dcto3,
		vImp_Facturable3,
		vImp_Montobase3,
		vImp_ImpReal3
	FROM fa_histconc_&&1;

   --
   --       AA           AAA
   --      AAAA         AAAA
   --     AA  AA       AA AA
   --    AA    AA         AA
   --   AAAAAAAAAA        AA
   --  AA        AA       AA
   -- AA          AA      AA
   --AA            AA     AA

   -- A1 Inserta los registros que no tienen Nota de Credito y agrupados
   --
   --

   /* ----->CONSULTA 15 <------ */
   nConsulta:=15;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Seleciona el detalle de las facturas que no tienen nota de credito');



   EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM fa_histconc_&&1 '
   		|| ' WHERE Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '
   		|| ' AND IND_ORDENTOTAL NOT IN ( SELECT IND_ORDENTOTAL_F FROM VM_FA_HISTDOCU ) '
		BULK COLLECT INTO IndOrdenTotal;


   /* ----->CONSULTA 16 <------ */
      nConsulta:=16;
      FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Este bloque permite generar las nuevas llaves'); 

   		IF IndOrdenTotal.COUNT >0 THEN
   			
   			
              FOR i in 1..Indordentotal.count LOOP
                       
                    	
		   	SELECT DISTINCT cod_concepto_new
			BULK COLLECT INTO Col_codconcepto_new
			FROM                       
                    	(SELECT 
                    	DISTINCT cod_concepto_new
                    	FROM ( SELECT 
                    	   		  ind_ordentotal, 
                    			  cod_concepto, 
                    			  columna, 
                    			  cod_concerel, 
                    			  columna_rel,
                    			  cod_tipconce, 
                    			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
                    	FROM fa_histconc_&&1 a, 		FA_ENTRADA_TO b 
                    	   		WHERE ind_ordentotal	= Indordentotal(i) 
                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    			  AND cod_tipconce	<> 1)
			UNION ALL
			SELECT	 
                    	DISTINCT cod_concepto_new
                    	FROM ( SELECT 
                    	   		  ind_ordentotal, 
                    			  cod_concepto, 
                    			  columna, 
                    			  cod_concerel, 
                    			  columna_rel,
                    			  cod_tipconce,
					  NVL((SELECT cod_concepto FROM fa_conceptos WHERE cod_concorig = (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new  	   
                    	FROM fa_histconc_&&1 a, FA_ENTRADA_TO b 
                    	   		WHERE ind_ordentotal		= Indordentotal(i)  
                    	   			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    				  AND cod_tipconce	= 2));			  
		  
                    	
                          sSql:='INSERT INTO FA_CAMBIA_LLAVE_TO '
                    	  ||'(IND_ORDENTOTAL,    '
                    	  ||'  COD_CONCEPTO ,     '
                    	  ||'  COLUMNA       ,    '
                      	  ||'	COD_CONCEREL   ,   '
                      	  ||'	COLUMNA_REL     ,  '
                      	  ||'	COD_TIPCONCE     , '
                      	  ||'	COD_CONCEPTO_NEW  ,'
                      	  ||'	COLUMNA_REL_NEW,'
			  ||'	COD_CONCEREL_NEW ) '
                      	  ||'SELECT '
                    	  ||'  ind_ordentotal, '
                    	  ||'  cod_concepto, '
                    	  ||'  columna, '
                    	  ||'  cod_concerel,' 
                    	  ||'  columna_rel, '
                     	  ||'  cod_tipconce,'
			  ||'  COD_CONCEPTO_NEW ,'
                    	  ||'  ROWNUM columna_rel_new, '
			  ||'  CASE WHEN cod_tipconce=2 THEN NVL((SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO=cod_concerel), cod_concerel) END COD_CONCEREL_NEW '
                    	  ||'  FROM ( SELECT '
                    	  ||' 		  a.ind_ordentotal,' 
                    	  ||'		  a.cod_concepto, '
                     	  ||'		  a.columna, '
                    	  ||'		  a.cod_concerel,' 
                    	  ||'		  a.columna_rel,'
                    	  ||'		  a.cod_tipconce,'
			  ||'  CASE WHEN cod_tipconce=2 THEN NVL((SELECT cod_concepto FROM fa_conceptos WHERE cod_concorig = (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO=cod_concerel)), cod_concepto) ' 
			  ||'        WHEN cod_tipconce!=2 THEN  NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, ' 
			  ||'  CASE WHEN cod_tipconce=2 THEN CODIGO_DESTINO END cod_concerel_new '
                    	  ||'  FROM fa_histconc_&&1 a, 		FA_ENTRADA_TO b '
                    	  ||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
                    	  ||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
                    	  ||'			  and cod_tipconce	<>1   ) x '
                          ||' WHERE cod_concepto_new= :CODIGODEST ';

                         
                    	  FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last 
                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);
                    	  
                    
		        END LOOP;
   			
	 
   		END IF;	
   		
	COMMIT;



	/* ----->CONSULTA 17 <------ */
   	nConsulta:=17;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla FA_CAMBIA_LLAVE_TO los impuestos con la nueva llave');


   	/*Inserta los registros de tipo concepto 1*/

        INSERT INTO FA_CAMBIA_LLAVE_TO
        (ind_ordentotal,
        cod_concepto,
        columna,
        cod_concerel,
        columna_rel,
        cod_tipconce,
        cod_concepto_new,
        columna_rel_new,
	cod_concerel_new)
        SELECT     			--busca el impuesto a traves del concepto origen, relacionando al concepto nuevo
        a.ind_ordentotal,	--no a traves de la funcion cambia llave de arriva
        a.cod_concepto,
        a.columna,
        a.cod_concerel,
        a.columna_rel,
        a.cod_tipconce,
        b.cod_concepto_new,
        b.columna_rel_new,
	b.cod_concerel_new
        FROM fa_histconc_&&1 a, FA_CAMBIA_LLAVE_TO b
        WHERE a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1
        AND a.ind_ordentotal NOT IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);



        COMMIT;

   	/* ----->CONSULTA 18 <------ */
   	nConsulta:=18;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla FA_HISTCONC_&&1._AUX los registros con las nuevas llaves de aquellos registros de tipo cargos');


   	INSERT INTO FA_HISTCONC_&&1._AUX
   	(IND_ORDENTOTAL  	,
    	COD_CONCEPTO    	,
    	COLUMNA         	,
    	COD_MONEDA      	,
    	COD_PRODUCTO    	,
    	COD_TIPCONCE    	,
    	FEC_VALOR       	,
    	FEC_EFECTIVIDAD 	,
    	IMP_CONCEPTO    	,
    	COD_REGION      	,
    	COD_PROVINCIA   	,
    	COD_CIUDAD      	,
    	IMP_MONTOBASE   	,
    	IND_FACTUR      	,
    	IMP_FACTURABLE  	,
    	IND_SUPERTEL    	,
    	NUM_ABONADO     	,
    	COD_PORTADOR    	,
    	DES_CONCEPTO    	,
    	SEG_CONSUMIDO   	,
    	NUM_CUOTAS      	,
    	ORD_CUOTA       	,
    	NUM_UNIDADES    	,
    	NUM_SERIEMEC    	,
    	NUM_SERIELE     	,
    	PRC_IMPUESTO    	,
    	VAL_DTO         	,
    	TIP_DTO         	,
    	MES_GARANTIA    	,
    	NUM_GUIA        	,
    	IND_ALTA        	,
    	NUM_PAQUETE     	,
    	FLAG_IMPUES     	,
    	FLAG_DTO        	,
    	COD_CONCEREL    	,
    	COLUMNA_REL     	,
    	SEQ_CUOTAS      	,
    	COD_PLANTARIF   	,
    	COD_CARGOBASICO 	,
    	TIP_PLANTARIF   	,
    	IMP_DCTO        	,
    	IMP_REAL        	,
    	DUR_DCTO        	,
    	DUR_REAL        	,
    	CNT_LLAM_REAL   	,
    	CNT_LLAM_DCTO   	,
    	CNT_LLAM_FACT      )
   	SELECT
          a.IND_ORDENTOTAL   ,
          b.COD_CONCEPTO_new    ,
          b.COLUMNA_rel_new columna_new        ,
          a.COD_MONEDA      ,
          a.COD_PRODUCTO    ,
          a.COD_TIPCONCE     ,
          a.FEC_VALOR        ,
          a.FEC_EFECTIVIDAD  ,
          a.IMP_CONCEPTO     ,
          a.COD_REGION       ,
          a.COD_PROVINCIA    ,
          a.COD_CIUDAD       ,
          a.IMP_MONTOBASE    ,
          a.IND_FACTUR       ,
          a.IMP_FACTURABLE   ,
          a.IND_SUPERTEL     ,
          a.NUM_ABONADO      ,
          a.COD_PORTADOR     ,
          a.DES_CONCEPTO     ,
          a.SEG_CONSUMIDO    ,
          a.NUM_CUOTAS       ,
          a.ORD_CUOTA        ,
          a.NUM_UNIDADES     ,
          a.NUM_SERIEMEC     ,
          a.NUM_SERIELE      ,
          a.PRC_IMPUESTO     ,
          a.VAL_DTO          ,
          a.TIP_DTO          ,
          a.MES_GARANTIA     ,
          a.NUM_GUIA         ,
          a.IND_ALTA         ,
          a.NUM_PAQUETE      ,
          a.FLAG_IMPUES      ,
          a.FLAG_DTO         ,
          a.COD_CONCEREL     ,
          a.COLUMNA_REL      ,
          a.SEQ_CUOTAS       ,
          a.COD_PLANTARIF    ,
          a.COD_CARGOBASICO  ,
          a.TIP_PLANTARIF    ,
          a.IMP_DCTO         ,
          a.IMP_REAL         ,
          a.DUR_DCTO         ,
          a.DUR_REAL         ,
          a.CNT_LLAM_REAL    ,
          a.CNT_LLAM_DCTO    ,
          a.CNT_LLAM_FACT
          FROM fa_histconc_&&1 a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and b.cod_concepto_new=c.cod_concepto
          	  and a.cod_tipconce	>2;

	commit;


	/* ----->CONSULTA 19 <------ */
   	nConsulta:=19;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla FA_HISTCONC_&&1._AUX los registros con las nuevas llaves de aquellos registros de tipo descuento e impuesto');


	INSERT INTO FA_HISTCONC_&&1._AUX
   	(IND_ORDENTOTAL   ,
        COD_CONCEPTO    ,
        COLUMNA         ,
        COD_MONEDA      ,
        COD_PRODUCTO    ,
        COD_TIPCONCE     ,
        FEC_VALOR        ,
        FEC_EFECTIVIDAD  ,
        IMP_CONCEPTO     ,
        COD_REGION       ,
        COD_PROVINCIA    ,
        COD_CIUDAD       ,
        IMP_MONTOBASE    ,
        IND_FACTUR       ,
        IMP_FACTURABLE   ,
        IND_SUPERTEL     ,
        NUM_ABONADO      ,
        COD_PORTADOR     ,
        DES_CONCEPTO     ,
        SEG_CONSUMIDO    ,
        NUM_CUOTAS       ,
        ORD_CUOTA        ,
        NUM_UNIDADES     ,
        NUM_SERIEMEC     ,
        NUM_SERIELE      ,
        PRC_IMPUESTO     ,
        VAL_DTO          ,
        TIP_DTO          ,
        MES_GARANTIA     ,
        NUM_GUIA         ,
        IND_ALTA         ,
        NUM_PAQUETE      ,
        FLAG_IMPUES      ,
        FLAG_DTO         ,
        COD_CONCEREL     ,
        COLUMNA_REL      ,
        SEQ_CUOTAS       ,
        COD_PLANTARIF    ,
        COD_CARGOBASICO  ,
        TIP_PLANTARIF    ,
        IMP_DCTO         ,
        IMP_REAL         ,
        DUR_DCTO         ,
        DUR_REAL         ,
        CNT_LLAM_REAL    ,
        CNT_LLAM_DCTO    ,
        CNT_LLAM_FACT    )
        SELECT
          a.IND_ORDENTOTAL   ,
          CASE WHEN a.cod_tipconce=1 THEN a.cod_concepto
	       WHEN a.cod_tipconce=2 THEN b.cod_concepto_new END cod_concepto,
          CASE WHEN a.cod_tipconce=1 THEN a.columna
	       WHEN a.cod_tipconce=2 THEN b.columna_rel_new END COLUMNA         ,
          a.COD_MONEDA      ,
          a.COD_PRODUCTO    ,
          a.COD_TIPCONCE     ,
          a.FEC_VALOR        ,
          a.FEC_EFECTIVIDAD  ,
          a.IMP_CONCEPTO     ,
          a.COD_REGION       ,
          a.COD_PROVINCIA    ,
          a.COD_CIUDAD       ,
          a.IMP_MONTOBASE    ,
          a.IND_FACTUR       ,
          a.IMP_FACTURABLE   ,
          a.IND_SUPERTEL     ,
          a.NUM_ABONADO      ,
          a.COD_PORTADOR     ,
          CASE WHEN a.cod_tipconce=1 THEN a.DES_CONCEPTO
	       WHEN a.cod_tipconce=2 THEN a.DES_CONCEPTO  /*(SELECT des_concepto FROM FA_CONCEPTOS WHERE b.COD_CONCEPTO_NEW=cod_concepto) END DES_concepto,*/
          END DES_concepto,
          a.SEG_CONSUMIDO    ,
          a.NUM_CUOTAS       ,
          a.ORD_CUOTA        ,
          a.NUM_UNIDADES     ,
          a.NUM_SERIEMEC     ,
          a.NUM_SERIELE      ,
          a.PRC_IMPUESTO     ,
          a.VAL_DTO          ,
          a.TIP_DTO          ,
          a.MES_GARANTIA     ,
          a.NUM_GUIA         ,
          a.IND_ALTA         ,
          a.NUM_PAQUETE      ,
          a.FLAG_IMPUES      ,
          a.FLAG_DTO         ,
          CASE WHEN a.cod_tipconce=1 THEN b.cod_concepto_new
	       WHEN a.cod_tipconce=2 THEN b.cod_concerel_new
	  END  COD_CONCEREL     ,
	  b.columna_rel_new COLUMNA_REL      ,
          a.SEQ_CUOTAS       ,
          a.COD_PLANTARIF    ,
          a.COD_CARGOBASICO  ,
          a.TIP_PLANTARIF    ,
          a.IMP_DCTO         ,
          a.IMP_REAL         ,
          a.DUR_DCTO         ,
          a.DUR_REAL         ,
          a.CNT_LLAM_REAL    ,
          a.CNT_LLAM_DCTO    ,
          a.CNT_LLAM_FACT
          FROM fa_histconc_&&1 a, FA_CAMBIA_LLAVE_TO b
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and a.cod_tipconce	<=2;


   	COMMIT;





   --
   --       AA          AAAAAAA
   --      AAAA        AA     AA
   --     AA  AA              AA
   --    AA    AA           AA
   --   AAAAAAAAAA       AA
   --  AA        AA    AA
   -- AA          AA   AA
   --AA            AA  AAAAAAAAA

   -- A2 SE DEBE HACER UN INSERT DE LOS RESTANTES QUE NO TIENEN AGRUPACION Y SIN NC


   /* ----->CONSULTA 20 <------ */
   nConsulta:=20;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla FA_HISTCONC_&&1._AUX aquellos registros que no tienen ningun tipo de modificacion y no poseeen nota de credito');


    INSERT INTO FA_HISTCONC_&&1._AUX
    (IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT   )
    SELECT
    IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT
    FROM  FA_HISTCONC_&&1 a
    WHERE ind_ordentotal NOT IN
	(SELECT DISTINCT ind_ordentotal
		FROM ( SELECT IND_ORDENTOTAL
			FROM FA_HISTCONC_&&1
			WHERE Cod_concepto IN
			(SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO)
			UNION
			SELECT IND_ORDENTOTAL_F FROM OPS$XPFACTUR.VM_FA_HISTDOCU ) B
			WHERE B.IND_ORDENTOTAL = A.IND_ORDENTOTAL ) ;

     COMMIT;

   --  TTTTTTTTTTTTT       TTTT
   --  T    TT     T      TT TT
   --       TT           TT  TT
   --       TT               TT
   --       TT               TT
   --       TT               TT
   --       TT               TT
   --       TT              TTTT
   	   --
   -- SE DEBE INSERTAR EN LA TABLA TECNOLOGIA SI EXISTE
   -- CONSULTAR POR ALL_TABLES

--   /* ----->CONSULTA 21 <------ */
--   nConsulta:=21;
--   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Verifica si el ciclo &&1 tiene tecnologia');
--
--
--   BEGIN
--   	SELECT DISTINCT 'EXISTE'
--   	INTO Tecnologia
--   	FROM all_tables WHERE table_name='FA_HISTECNO_TH_&&1';
--   EXCEPTION
--   	WHEN OTHERS THEN
--   		Tecnologia:='NO EXISTE';
--   END;
--
--
--
--    IF Tecnologia='EXISTE' AND IndOrdenTotal.COUNT >0 THEN
--   	--T1 SE DEBE INSERTAR SOLAMENTE LOS REGISTROS QUE NO TIENEN NOTA DE CREDITO
--   	-- LOS QUE TIENEN SE REALIZAN EN UN PROCESO A PARTE ADEMAS DE AQUELLOS QUE TIENEN CONCEPTOS AGRUPADOS
--
--   	/* ----->CONSULTA 22 <------ */
--   	nConsulta:=22;
--   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla auxiliar de tecnologia aquellos registros que no tienen nota de credito y que tengan conceptos a cambiar, su tipo de registro debe ser cargo');
--
--
--
--   	 INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	 IND_ORDENTOTAL ,
--	 COD_CONCEPTO  ,
--	 COLUMNA       ,
--	 COD_TECNOLOGIA,
--	 PRC_TECNOLOGIA )
--   	 SELECT
--            a.IND_ORDENTOTAL ,
--            b.COD_CONCEPTO_new  ,
--            b.COLUMNA_rel_new       ,
--	    a.COD_TECNOLOGIA,
--            a.PRC_TECNOLOGIA
--            FROM FA_HISTECNO_TH_&&1 a, FA_CAMBIA_LLAVE_TO b
--			WHERE a.ind_ordentotal      =b.ind_ordentotal
--				  AND a.cod_concepto=b.cod_concepto
--				  AND a.columna     =b.columna
--				  AND b.cod_tipconce >2
--				  AND a.ind_ordentotal NOT IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);
--	 COMMIT;
--
--	 /* ----->CONSULTA 23 <------ */
--   	nConsulta:=23;
--   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla auxiliar de tecnologia aquellos registros que no tienen nota de credito y que tengan conceptos a cambiar y su tipo de concepto sea impuesto y descuento');
--
--
--	 INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	 IND_ORDENTOTAL ,
--	 COD_CONCEPTO  ,
--	 COLUMNA       ,
--	 COD_TECNOLOGIA,
--	 PRC_TECNOLOGIA )
--   	 SELECT
--         a.IND_ORDENTOTAL ,
--	   CASE WHEN b.cod_tipconce=1 THEN a.cod_concepto
--            	WHEN b.cod_tipconce=2 THEN b.COD_CONCEPTO_new  END COD_CONCEPTO,
--	   CASE WHEN b.cod_tipconce=1 THEN a.columna
--            	WHEN b.cod_tipconce=2 THEN b.COLUMNA_rel_new  END COLUMNA,
--	 a.COD_TECNOLOGIA,
--         a.PRC_TECNOLOGIA
--         FROM FA_HISTECNO_TH_&&1 a, FA_CAMBIA_LLAVE_TO b
--			WHERE a.ind_ordentotal      =b.ind_ordentotal
--				  AND a.cod_concepto=b.cod_concepto
--				  AND a.columna     =b.columna
--				  AND b.cod_tipconce <=2
--				  AND a.ind_ordentotal NOT IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);
--         COMMIT;
--
--
--
--   	--
--   	--  TTTTTTTTTTTTT       2222
--   	--  T    TT     T     22    22
--   	--       TT                 22
--   	--       TT              222
--   	--       TT             22
--   	--       TT            22
--   	--       TT           22
--   	--       TT           22222222
--   	-- FALTA INSERTAR TECNOLOGIA DE NO AGRUPADOS Y SIN NOTA DE CREDITO
--   	--
--
--   	/* ----->CONSULTA 24 <------ */
--   	nConsulta:=24;
--   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los registros que no seran agrupados');
--
--
--   	 INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	        IND_ORDENTOTAL ,
--	        COD_CONCEPTO  ,
--		COLUMNA       ,
--		COD_TECNOLOGIA,
--		PRC_TECNOLOGIA )
--   	        SELECT
--                	IND_ORDENTOTAL ,
--             		COD_CONCEPTO  ,
--             		COLUMNA       ,
--             		COD_TECNOLOGIA,
--             		PRC_TECNOLOGIA
--             	FROM FA_HISTECNO_TH_&&1
--		WHERE ind_ordentotal NOT IN
--			(SELECT DISTINCT ind_ordentotal
--			 FROM FA_HISTECNO_TH_&&1
--			 WHERE Cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO )
--			 )
--		AND IND_ORDENTOTAL NOT IN ( SELECT IND_ORDENTOTAL_F FROM VM_FA_HISTDOCU ) ;
--
--
--	COMMIT;
--
--
--   END IF;






   --BBBBBBBB      1111
   --BB    BBB    11 11
   --BB   BBBB       11
   --BBBBBB          11
   --BB    BBB       11
   --BB    BBBB      11
   --BBBBBBBB     1111111
   --
   -- B1 AQUI PROCESAR LOS QUE TIENEN NOTA DE CREDITO Y SERAN AGRUPADOS


   	/* ----->CONSULTA 25 <------ */
   	nConsulta:=25;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Selecciona las facturas que tienen notas de credito para el ciclo &&1 ');


   	EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM fa_histconc_&&1 '
   		|| ' WHERE ind_ordentotal in (SELECT ind_ordentotal_f FROM vm_fa_histdocu) '
   		|| ' And Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '
		BULK COLLECT INTO IndOrdenTotal;

		/* ----->CONSULTA 26 <------ */
   		nConsulta:=26;
   		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Bloque para generar las nuevas llaves');



   		IF IndOrdenTotal.COUNT >0 THEN


            FOR i in 1..Indordentotal.count LOOP


		   	SELECT DISTINCT cod_concepto_new
			BULK COLLECT INTO Col_codconcepto_new
			FROM
                    	(SELECT
                    	DISTINCT cod_concepto_new
                    	FROM ( SELECT
                    	   		  ind_ordentotal,
                    			  cod_concepto,
                    			  columna,
                    			  cod_concerel,
                    			  columna_rel,
                    			  cod_tipconce,
                    			  NVL(CODIGO_DESTINO, cod_concepto) cod_concepto_new
                    	FROM fa_histconc_&&1 a, FA_ENTRADA_TO b
                    	   		WHERE ind_ordentotal	= Indordentotal(i)
                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    			  AND cod_tipconce	<> 1)
			UNION ALL
			SELECT
                    	DISTINCT cod_concepto_new
                    	FROM ( SELECT
                    	   		  ind_ordentotal,
                    			  cod_concepto,
                    			  columna,
                    			  cod_concerel,
                    			  columna_rel,
                    			  cod_tipconce,
					  NVL((select cod_concepto from fa_conceptos where cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new
                    	FROM fa_histconc_&&1 a, FA_ENTRADA_TO b
                    	   		WHERE ind_ordentotal		= Indordentotal(i)
                    	   			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    				  AND cod_tipconce	=2));




                          sSql:='INSERT INTO FA_CAMBIA_LLAVE_TO '
                    	  ||'(IND_ORDENTOTAL,    '
                    	  ||'  COD_CONCEPTO ,     '
                    	  ||'  COLUMNA       ,    '
                      	  ||'	COD_CONCEREL   ,   '
                      	  ||'	COLUMNA_REL     ,  '
                      	  ||'	COD_TIPCONCE     , '
                      	  ||'	COD_CONCEPTO_NEW  ,'
                      	  ||'	COLUMNA_REL_NEW,'
			  			||'	COD_CONCEREL_NEW ) '
                      	  ||'SELECT '
                    	  ||'  ind_ordentotal, '
                    	  ||'  cod_concepto, '
                    	  ||'  columna, '
                    	  ||'  cod_concerel,'
                    	  ||'  columna_rel, '
                     	  ||'  cod_tipconce,'
			  ||'  COD_CONCEPTO_NEW ,'
                    	  ||'  ROWNUM columna_rel_new, '
			  ||'  CASE WHEN cod_tipconce=2 THEN NVL((select distinct CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel), cod_concerel) END COD_CONCEREL_NEW '
                    	  ||'  FROM ( SELECT '
                    	  ||' 		  a.ind_ordentotal,'
                    	  ||'		  a.cod_concepto, '
                     	  ||'		  a.columna, '
                    	  ||'		  a.cod_concerel,'
                    	  ||'		  a.columna_rel,'
                    	  ||'		  a.cod_tipconce,'
			  ||'  CASE WHEN cod_tipconce=2  THEN NVL((SELECT cod_concepto FROM fa_conceptos WHERE cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) '
			  ||'       WHEN cod_tipconce!=2 THEN  NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, '
			  ||'  CASE WHEN cod_tipconce=2  THEN CODIGO_DESTINO END cod_concerel_new '
                    	  ||'  FROM fa_histconc_&&1 a, 		FA_ENTRADA_TO b '
                    	  ||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
                    	  ||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
                    	  ||'			  and cod_tipconce	<>1   ) x '
                          ||' WHERE cod_concepto_new= :CODIGODEST ';


                    	  FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last
                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);


		        END LOOP;

   		END IF;


	COMMIT;


	/* ----->CONSULTA 27 <------ */
   	nConsulta:=27;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Bloque para generar las nuevas llaves');


	/*Inserta los registros de tipo concepto 1*/

	INSERT INTO FA_CAMBIA_LLAVE_TO
        (ind_ordentotal,
        cod_concepto,
        columna,
        cod_concerel,
        columna_rel,
        cod_tipconce,
        cod_concepto_new,
        columna_rel_new,
	cod_concerel_new)
        SELECT
        a.ind_ordentotal,
        a.cod_concepto,
        a.columna,
        a.cod_concerel,
        a.columna_rel,
        a.cod_tipconce,
        b.cod_concepto_new,
        b.columna_rel_new,
	b.cod_concerel_new
        FROM fa_histconc_&&1 a, FA_CAMBIA_LLAVE_TO b
        WHERE a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1
        AND a.ind_ordentotal IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);


        COMMIT;


	/* ----->CONSULTA 28 <------ */
   	nConsulta:=28;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla auxiliar FA_HISTCONC_&&1._AUX el detalle de las facturas que tienen notas de credito y sean registros de tipo cargo');


   INSERT INTO FA_HISTCONC_&&1._AUX
   (IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT   )
   SELECT DISTINCT       --- EL DISTINCT ES PORQUE PUEDE TENER MAS DE UNA NOTA DE CREDITO POR FACTURA, LO QUE CAUSABA ANTIGUAMENTE PRODUCTO CARTECIANO Y GENERABA ERROR DE LLAVE DUPLICADA
    a.IND_ORDENTOTAL  	,
    b.COD_CONCEPTO_new    	,
    b.COLUMNA_rel_new  as columna_new    	,
    a.COD_MONEDA      	,
    a.COD_PRODUCTO    	,
    a.COD_TIPCONCE    	,
    a.FEC_VALOR       	,
    a.FEC_EFECTIVIDAD 	,
    a.IMP_CONCEPTO    	,
    a.COD_REGION      	,
    a.COD_PROVINCIA   	,
    a.COD_CIUDAD      	,
    a.IMP_MONTOBASE   	,
    a.IND_FACTUR      	,
    a.IMP_FACTURABLE  	,
    a.IND_SUPERTEL    	,
    a.NUM_ABONADO     	,
    a.COD_PORTADOR    	,
    a.DES_CONCEPTO    	,   ---modifique descripcion
    a.SEG_CONSUMIDO   	,
    a.NUM_CUOTAS      	,
    a.ORD_CUOTA       	,
    a.NUM_UNIDADES    	,
    a.NUM_SERIEMEC    	,
    a.NUM_SERIELE     	,
    a.PRC_IMPUESTO    	,
    a.VAL_DTO         	,
    a.TIP_DTO         	,
    a.MES_GARANTIA    	,
    a.NUM_GUIA        	,
    a.IND_ALTA        	,
    a.NUM_PAQUETE     	,
    a.FLAG_IMPUES     	,
    a.FLAG_DTO        	,
    a.COD_CONCEREL    	,
    a.COLUMNA_REL     	,
    a.SEQ_CUOTAS      	,
    a.COD_PLANTARIF   	,
    a.COD_CARGOBASICO 	,
    a.TIP_PLANTARIF   	,
    a.IMP_DCTO        	,
    a.IMP_REAL        	,
    a.DUR_DCTO        	,
    a.DUR_REAL        	,
    a.CNT_LLAM_REAL   	,
    a.CNT_LLAM_DCTO   	,
    a.CNT_LLAM_FACT
    FROM fa_histconc_&&1 a , FA_CAMBIA_LLAVE_TO b, vm_fa_histdocu c, fa_conceptos d
    WHERE a.ind_ordentotal	=b.ind_ordentotal
	  AND a.cod_concepto	=b.cod_concepto
	  AND a.columna		=b.columna
	  AND a.ind_ordentotal	=c.ind_ordentotal_f
	  AND b.cod_concepto_new=d.cod_concepto
	  AND a.cod_tipconce	>2;

    Commit;

    /* impuestos <=2*/

    /* ----->CONSULTA 29 <------ */
   nConsulta:=29;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'inserta en la tabla auxiliar FA_HISTCONC_&&1._AUX el detalle de las facturas que tienen notas de credito');


    INSERT INTO FA_HISTCONC_&&1._AUX
    (IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT   )
    SELECT DISTINCT --------------------ESTO ES POSI TIENE MAS DE UAN NOTA DE CREIDITO, YA QUE EL JOIN CON VM_HISTDOCU TRAE MAS DE UN REGISTRO PROVOCANDO PRODUCTO CARTECIANO
    a.IND_ORDENTOTAL  	,
    CASE WHEN a.cod_tipconce=1 THEN a.cod_concepto
	 WHEN a.cod_tipconce=2 THEN b.cod_concepto_new
    END cod_concepto,
    CASE WHEN a.cod_tipconce=1 THEN a.columna
	 WHEN a.cod_tipconce=2 THEN b.columna_rel_new
    END COLUMNA         ,
    a.COD_MONEDA      	,
    a.COD_PRODUCTO    	,
    a.COD_TIPCONCE    	,
    a.FEC_VALOR       	,
    a.FEC_EFECTIVIDAD 	,
    a.IMP_CONCEPTO    	,
    a.COD_REGION      	,
    a.COD_PROVINCIA   	,
    a.COD_CIUDAD      	,
    a.IMP_MONTOBASE   	,
    a.IND_FACTUR      	,
    a.IMP_FACTURABLE  	,
    a.IND_SUPERTEL    	,
    a.NUM_ABONADO     	,
    a.COD_PORTADOR    	,
    CASE WHEN a.cod_tipconce=1 THEN a.DES_CONCEPTO
	 WHEN a.cod_tipconce=2 THEN (SELECT des_concepto FROM FA_CONCEPTOS WHERE b.COD_CONCEPTO_NEW=cod_concepto)
    END DES_concepto,
    a.SEG_CONSUMIDO   	,
    a.NUM_CUOTAS      	,
    a.ORD_CUOTA       	,
    a.NUM_UNIDADES    	,
    a.NUM_SERIEMEC    	,
    a.NUM_SERIELE     	,
    a.PRC_IMPUESTO    	,
    a.VAL_DTO         	,
    a.TIP_DTO         	,
    a.MES_GARANTIA    	,
    a.NUM_GUIA        	,
    a.IND_ALTA        	,
    a.NUM_PAQUETE     	,
    a.FLAG_IMPUES     	,
    a.FLAG_DTO        	,
    CASE WHEN a.cod_tipconce=1 THEN b.cod_concepto_new
         WHEN a.cod_tipconce=2  THEN b.cod_concerel_new
    END  COD_CONCEREL     ,
    b.columna_rel_new COLUMNA_REL,
    a.SEQ_CUOTAS      	,
    a.COD_PLANTARIF   	,
    a.COD_CARGOBASICO 	,
    a.TIP_PLANTARIF   	,
    a.IMP_DCTO        	,
    a.IMP_REAL        	,
    a.DUR_DCTO        	,
    a.DUR_REAL        	,
    a.CNT_LLAM_REAL   	,
    a.CNT_LLAM_DCTO   	,
    a.CNT_LLAM_FACT
    FROM fa_histconc_&&1 a , FA_CAMBIA_LLAVE_TO b, vm_fa_histdocu c
    WHERE a.ind_ordentotal	=b.ind_ordentotal
	  AND a.cod_concepto	=b.cod_concepto
	  AND a.columna		=b.columna
	  AND a.ind_ordentotal	=c.ind_ordentotal_f
	  AND a.cod_tipconce	<=2;


	COMMIT;

   -- SE ELIMINAN LOS REGISTROS DE FA_HISTCONC_19010102 DE AQUELLOS REGISTROS QUE TIENEN NOTA DE CREDITO
   -- Y QUE ESTEN DENTRO DEL GRUPO DE CODIGOS DE ORIGEN

    /* ----->CONSULTA 30 <------ */
   nConsulta:=30;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Elimina registros de la FA_HISTCONC_19010102 para ser reemplazados por las nuevas llaves');


--   DELETE
--   FROM fa_histconc_19010102 a
--	 WHERE exists (SELECT 1
--	                 FROM VM_FA_HISTCONC_DNOTAC b,  FA_ENTRADA_TO c
--	 		WHERE a.ind_ordentotal = b.ind_ordentotal
--	 		  AND b.cod_concepto   = c.codigo_concepto );


   DELETE
   FROM fa_histconc_19010102 a
	 WHERE a.ind_ordentotal in  (SELECT b.ind_ordentotal_dnc
	                 			   FROM vm_fa_histdocu b);

   COMMIT;

   /* ----->CONSULTA 31 <------ */
   nConsulta:=31;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Elimina registros de la FA_HISTCONC_19010102 para ser reemplazados por las nuevas llaves');


   /* En esta parte se procesaran las notas de credito */
   EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM VM_FA_HISTCONC_DNOTAC '
   		|| ' WHERE Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '
		BULK COLLECT INTO IndOrdenTotal;

   /* ----->CONSULTA 32 <------ */
   nConsulta:=32;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Procesa las llaves de las notas de credito');


   		IF IndOrdenTotal.COUNT >0 THEN
                FOR i in 1..Indordentotal.count LOOP

                       		SELECT DISTINCT cod_concepto_new
				BULK COLLECT INTO Col_codconcepto_new
				FROM
                    		(SELECT
                    		DISTINCT cod_concepto_new
                    		FROM ( SELECT
                    	   		  ind_ordentotal,
                    			  cod_concepto,
                    			  columna,
                    			  cod_concerel,
                    			  columna_rel,
                    			  cod_tipconce,
                    			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
                    		FROM VM_FA_HISTCONC_DNOTAC a, 		FA_ENTRADA_TO b
                    	   		WHERE ind_ordentotal		= Indordentotal(i)
                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    			  AND cod_tipconce		<> 1)
				UNION ALL
				SELECT
                    		DISTINCT cod_concepto_new
                    		FROM ( SELECT
                    	   		  ind_ordentotal,
                    			  cod_concepto,
                    			  columna,
                    			  cod_concerel,
                    			  columna_rel,
                    			  cod_tipconce,
					  NVL((select cod_concepto from fa_conceptos where cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new
                    		FROM VM_FA_HISTCONC_DNOTAC a, FA_ENTRADA_TO b
                    	   		WHERE ind_ordentotal		= Indordentotal(i)
                    	   			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                    				  AND cod_tipconce		=2));

                          	sSql:='INSERT INTO FA_CAMBIA_LLAVE_TO '
                    	  	||'(IND_ORDENTOTAL,    '
                    	  	||'  COD_CONCEPTO ,     '
                    	  	||'  COLUMNA       ,    '
                      	  	||'	COD_CONCEREL   ,   '
                      	  	||'	COLUMNA_REL     ,  '
                      	  	||'	COD_TIPCONCE     , '
                      	  	||'	COD_CONCEPTO_NEW  ,'
                      	  	||'	COLUMNA_REL_NEW,'
			  	||'	COD_CONCEREL_NEW ) '
                      	  	||'SELECT '
                    	  	||'  ind_ordentotal, '
                    	  	||'  cod_concepto, '
                    	  	||'  columna, '
                    	  	||'  cod_concerel,'
                    	  	||'  columna_rel, '
                     	  	||'  cod_tipconce,'
			  	||'  COD_CONCEPTO_NEW ,'
                    	  	||'  ROWNUM columna_rel_new, '
			  	||'  CASE WHEN cod_tipconce=2 THEN NVL((select distinct CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel), cod_concerel) END COD_CONCEREL_NEW '
                    	  	||'  FROM ( SELECT '
                    	  	||' 		  a.ind_ordentotal,'
                    	  	||'		  a.cod_concepto, '
                     	  	||'		  a.columna, '
                    	  	||'		  a.cod_concerel,'
                    	  	||'		  a.columna_rel,'
                    	  	||'		  a.cod_tipconce,'
			  	||'  CASE WHEN cod_tipconce=2   THEN NVL((select cod_concepto from fa_conceptos where cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) '
			  	||'       WHEN cod_tipconce!=2  THEN NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, '
			  	||'  CASE WHEN cod_tipconce=2   THEN CODIGO_DESTINO END cod_concerel_new '
                    	  	||'  FROM VM_FA_HISTCONC_DNOTAC a, 		FA_ENTRADA_TO b '
                    	  	||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
                    	  	||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
                    	  	||'			  and cod_tipconce	<>1   ) x '
                          	||' where cod_concepto_new= :CODIGODEST ';


                    	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last
                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);


		        END LOOP;


   		END IF;


	COMMIT;

	/* ----->CONSULTA 33 <------ */
   	nConsulta:=33;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta registros en la tabla FA_CAMBIA_LLAVE_TO de seolamente aquellos registros de tipo impuesto');


	/*Inserta los registros de tipo concepto 1*/


        INSERT INTO FA_CAMBIA_LLAVE_TO
        (ind_ordentotal,
        cod_concepto,
        columna,
        cod_concerel,
        columna_rel,
        cod_tipconce,
        cod_concepto_new,
        columna_rel_new)
        SELECT
        a.ind_ordentotal,
        a.cod_concepto,
        a.columna,
        a.cod_concerel,
        a.columna_rel,
        a.cod_tipconce,
        b.cod_concepto_new,
        b.columna_rel_new
        FROM VM_FA_HISTCONC_DNOTAC a, FA_CAMBIA_LLAVE_TO b
        WHERE a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1;

        COMMIT;

    /* ----->CONSULTA 34 <------ */
   	nConsulta:=34;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta el detalle de la nota de credito de aquellos registros de tipo cargo');


   INSERT INTO FA_HISTCONC_19010102
   (
  IND_ORDENTOTAL,
  COD_CONCEPTO  ,
  COLUMNA        ,
  COD_MONEDA      ,
  COD_PRODUCTO     ,
  COD_TIPCONCE     ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  IMP_MONTOBASE    ,
  IND_FACTUR       ,
  IMP_FACTURABLE   ,
  IND_SUPERTEL     ,
  NUM_ABONADO      ,
  COD_PORTADOR     ,
  DES_CONCEPTO     ,
  SEG_CONSUMIDO    ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  NUM_UNIDADES     ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  MES_GARANTIA     ,
  NUM_GUIA         ,
  IND_ALTA         ,
  NUM_PAQUETE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  SEQ_CUOTAS       ,
  COD_PLANTARIF    ,
  COD_CARGOBASICO  ,
  TIP_PLANTARIF    ,
  IMP_DCTO         ,
  IMP_REAL         ,
  DUR_DCTO         ,
  DUR_REAL         ,
  CNT_LLAM_REAL    ,
  CNT_LLAM_DCTO    ,
  CNT_LLAM_FACT    ,
  MIN_PLANTARIF    ,
  COD_UNIDAD       ,
  COD_OPERADOR         )
  SELECT
  a.IND_ORDENTOTAL,
  b.COD_CONCEPTO_new  ,
  b.COLUMNA_REL_new   ,
  a.COD_MONEDA      ,
  a.COD_PRODUCTO     ,
  a.COD_TIPCONCE     ,
  a.FEC_VALOR        ,
  a.FEC_EFECTIVIDAD  ,
  a.IMP_CONCEPTO     ,
  a.COD_REGION       ,
  a.COD_PROVINCIA    ,
  a.COD_CIUDAD       ,
  a.IMP_MONTOBASE    ,
  a.IND_FACTUR       ,
  a.IMP_FACTURABLE   ,
  a.IND_SUPERTEL     ,
  a.NUM_ABONADO      ,
  a.COD_PORTADOR     ,
  c.DES_CONCEPTO     ,   /*--modificaion de la descriocion del concepto antes era a---*/
  a.SEG_CONSUMIDO    ,
  a.NUM_CUOTAS       ,
  a.ORD_CUOTA        ,
  a.NUM_UNIDADES     ,
  a.NUM_SERIEMEC     ,
  a.NUM_SERIELE      ,
  a.PRC_IMPUESTO     ,
  a.VAL_DTO          ,
  a.TIP_DTO          ,
  a.MES_GARANTIA     ,
  a.NUM_GUIA         ,
  a.IND_ALTA         ,
  a.NUM_PAQUETE      ,
  a.FLAG_IMPUES      ,
  a.FLAG_DTO         ,
  a.COD_CONCEREL     ,
  a.COLUMNA_REL      ,
  a.SEQ_CUOTAS       ,
  a.COD_PLANTARIF    ,
  a.COD_CARGOBASICO  ,
  a.TIP_PLANTARIF    ,
  a.IMP_DCTO         ,
  a.IMP_REAL         ,
  a.DUR_DCTO         ,
  a.DUR_REAL         ,
  a.CNT_LLAM_REAL    ,
  a.CNT_LLAM_DCTO    ,
  a.CNT_LLAM_FACT    ,
  a.MIN_PLANTARIF    ,
  a.COD_UNIDAD       ,
  a.COD_OPERADOR
  FROM VM_FA_HISTCONC_DNOTAC a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
  WHERE     a.ind_ordentotal 	= b.ind_ordentotal
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna
	AND b.cod_concepto_new	= c.cod_concepto
  	AND a.ind_ordentotal IN (SELECT ind_ordentotal_dnc FROM vm_fa_histdocu x, VM_FA_HISTCONC_DNOTAC y
	 			WHERE x.ind_ordentotal_dnc=y.ind_ordentotal
	 				AND y.cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO))
   	AND a.cod_tipconce>2;
   commit;


  /* ----->CONSULTA 35 <------ */
  nConsulta:=35;
  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta el detalle de la nota de credito de aquellos registros de tipo impuesto y descuento');


  INSERT INTO FA_HISTCONC_19010102
  (
  IND_ORDENTOTAL,
  COD_CONCEPTO  ,
  COLUMNA        ,
  COD_MONEDA      ,
  COD_PRODUCTO     ,
  COD_TIPCONCE     ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  IMP_MONTOBASE    ,
  IND_FACTUR       ,
  IMP_FACTURABLE   ,
  IND_SUPERTEL     ,
  NUM_ABONADO      ,
  COD_PORTADOR     ,
  DES_CONCEPTO     ,
  SEG_CONSUMIDO    ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  NUM_UNIDADES     ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  MES_GARANTIA     ,
  NUM_GUIA         ,
  IND_ALTA         ,
  NUM_PAQUETE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  SEQ_CUOTAS       ,
  COD_PLANTARIF    ,
  COD_CARGOBASICO  ,
  TIP_PLANTARIF    ,
  IMP_DCTO         ,
  IMP_REAL         ,
  DUR_DCTO         ,
  DUR_REAL         ,
  CNT_LLAM_REAL    ,
  CNT_LLAM_DCTO    ,
  CNT_LLAM_FACT    ,
  MIN_PLANTARIF    ,
  COD_UNIDAD       ,
  COD_OPERADOR         )
  SELECT
  a.IND_ORDENTOTAL,
  a.COD_CONCEPTO  ,
  a.COLUMNA   ,
  a.COD_MONEDA      ,
  a.COD_PRODUCTO     ,
  a.COD_TIPCONCE     ,
  a.FEC_VALOR        ,
  a.FEC_EFECTIVIDAD  ,
  a.IMP_CONCEPTO     ,
  a.COD_REGION       ,
  a.COD_PROVINCIA    ,
  a.COD_CIUDAD       ,
  a.IMP_MONTOBASE    ,
  a.IND_FACTUR       ,
  a.IMP_FACTURABLE   ,
  a.IND_SUPERTEL     ,
  a.NUM_ABONADO      ,
  a.COD_PORTADOR     ,
  a.DES_CONCEPTO     ,   /*--modificaion de la descriocion del concepto antes era a---*/
  a.SEG_CONSUMIDO    ,
  a.NUM_CUOTAS       ,
  a.ORD_CUOTA        ,
  a.NUM_UNIDADES     ,
  a.NUM_SERIEMEC     ,
  a.NUM_SERIELE      ,
  a.PRC_IMPUESTO     ,
  a.VAL_DTO          ,
  a.TIP_DTO          ,
  a.MES_GARANTIA     ,
  a.NUM_GUIA         ,
  a.IND_ALTA         ,
  a.NUM_PAQUETE      ,
  a.FLAG_IMPUES      ,
  a.FLAG_DTO         ,
  b.COD_CONCEPTO_new ,
  b.COLUMNA_REL_new      ,
  a.SEQ_CUOTAS       ,
  a.COD_PLANTARIF    ,
  a.COD_CARGOBASICO  ,
  a.TIP_PLANTARIF    ,
  a.IMP_DCTO         ,
  a.IMP_REAL         ,
  a.DUR_DCTO         ,
  a.DUR_REAL         ,
  a.CNT_LLAM_REAL    ,
  a.CNT_LLAM_DCTO    ,
  a.CNT_LLAM_FACT    ,
  a.MIN_PLANTARIF    ,
  a.COD_UNIDAD       ,
  a.COD_OPERADOR
    FROM VM_FA_HISTCONC_DNOTAC a, FA_CAMBIA_LLAVE_TO b
  WHERE     a.ind_ordentotal	= b.ind_ordentotal
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna
  	AND a.ind_ordentotal IN (SELECT ind_ordentotal_dnc 
  					FROM vm_fa_histdocu x, VM_FA_HISTCONC_DNOTAC y
	 				WHERE x.ind_ordentotal_dnc=y.ind_ordentotal 
	 				AND y.cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO))
   	AND a.cod_tipconce<=2;

   COMMIT;


   /* VERIFICA SI LOS MONTOS QUEDAN IGUALES EN AJUSTES*/


   /* ----->CONSULTA 35.1 <------ */
   nConsulta:=35.1;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de los ajustes originales para determinar diferencias');


   SELECT sum(IMP_FACTURABLE) ,
   	  sum(IMP_CONCEPTO)
   INTO vImp_Facturable1,
	vImp_Concepto1
   FROM fa_ajusteconc;



   /* ELIMINA LOS AJUSTES*/

   /* ----->CONSULTA 36 <------ */
   	nConsulta:=36;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Elimina los ajustes para ser reemplazados por los registros con la nueva llave');

   DELETE FROM fa_ajusteconc a
  WHERE (PREF_PLAZA, NUM_FOLIO, COD_CLIENTE)IN  
 	   				(SELECT B.PREF_PLAZA, B.NUM_FOLIO, B.COD_CLIENTE 
					  FROM ops$xpfactur.vm_fa_histdocu b, FA_CAMBIA_LLAVE_TO C
  		 			 WHERE c.Ind_ordentotal = b.ind_ordentotal_dnc);

   COMMIT;


   -- REPONE LOS REGISTROS ELIMINADOS PERO CON LOS NUEVOS CODIGOS

   /* ----->CONSULTA 37 <------ */
   	nConsulta:=37;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los ajustes correspondientes a la nota de credito modificada con la nueva llave');


  INSERT INTO FA_AJUSTECONC
  (
  NUM_FOLIO     ,
  COD_CLIENTE  ,
  COD_CONCEPTO  ,
  COD_MONEDA     ,
  COLUMNA         ,
  IMP_FACTURABLE   ,
  COD_PRODUCTO     ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_TIPCONCE     ,
  COD_CIUDAD       ,
  FEC_VALOR        ,
  COD_MODULO       ,
  IMP_MONTOBASE    ,
  IND_FACTUR       ,
  NUM_UNIDADES     ,
  IND_SUPERTEL     ,
  NUM_SERIEMEC     ,
  NUM_ABONADO      ,
  COD_PORTADOR     ,
  DES_CONCEPTO     ,
  SEQ_CUOTAS       ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  NUM_SERIELE      ,
  MES_GARANTIA     ,
  NUM_GUIA         ,
  IND_ALTA         ,
  NUM_PAQUETE      ,
  NUM_VENTA        ,
  NUM_TRANSACCION  ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  COD_TIPDOCUM     ,
  PREF_PLAZA
  )
  SELECT
  a.NUM_FOLIO     ,
  a.COD_CLIENTE  ,
  b.COD_CONCEPTO_new  ,
  a.COD_MONEDA     ,
  b.COLUMNA_rel_new     ,
  a.IMP_FACTURABLE   ,
  a.COD_PRODUCTO     ,
  a.FEC_EFECTIVIDAD  ,
  a.IMP_CONCEPTO     ,
  a.COD_REGION       ,
  a.COD_PROVINCIA    ,
  a.COD_TIPCONCE     ,
  a.COD_CIUDAD       ,
  a.FEC_VALOR        ,
  a.COD_MODULO       ,
  a.IMP_MONTOBASE    ,
  a.IND_FACTUR       ,
  a.NUM_UNIDADES     ,
  a.IND_SUPERTEL     ,
  a.NUM_SERIEMEC     ,
  a.NUM_ABONADO      ,
  a.COD_PORTADOR     ,
  c.DES_CONCEPTO     , /*--modificaion de la descriocion del concepto antes era a---*/
  a.SEQ_CUOTAS       ,
  a.NUM_CUOTAS       ,
  a.ORD_CUOTA        ,
  a.NUM_SERIELE      ,
  a.MES_GARANTIA     ,
  a.NUM_GUIA         ,
  a.IND_ALTA         ,
  a.NUM_PAQUETE      ,
  a.NUM_VENTA        ,
  a.NUM_TRANSACCION  ,
  a.FLAG_IMPUES      ,
  a.FLAG_DTO         ,
  a.COD_TIPDOCUM     ,
  a.PREF_PLAZA
  FROM  VM_FA_AJUSTECONC a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
  WHERE a.IND_ORDENTOTAL_DNC	= b.ind_ordentotal
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna
  	AND b.cod_concepto_new 	= c.cod_concepto
  	AND b.cod_tipconce 	> 2;


  commit;


   --BBBBBBBB      222222
   --BB    BBB    22    22
   --BB   BBBB         22
   --BBBBBB          22
   --BB    BBB      22
   --BB    BBBB    22    2
   --BBBBBBBB     22222222

   --B2 SE DEBE HACER UN INSERT DE LOS RESTANTES QUE NO TIENEN AGRUPACION Y CON NC

    /* ----->CONSULTA 38 <------ */
    nConsulta:=38;
    FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los restantes registros que no se agruparan en la tabla FA_HISTCONC_&&1 ');

    INSERT INTO FA_HISTCONC_&&1._AUX
    (
    IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT   )
    SELECT
    IND_ORDENTOTAL  	,
    COD_CONCEPTO    	,
    COLUMNA         	,
    COD_MONEDA      	,
    COD_PRODUCTO    	,
    COD_TIPCONCE    	,
    FEC_VALOR       	,
    FEC_EFECTIVIDAD 	,
    IMP_CONCEPTO    	,
    COD_REGION      	,
    COD_PROVINCIA   	,
    COD_CIUDAD      	,
    IMP_MONTOBASE   	,
    IND_FACTUR      	,
    IMP_FACTURABLE  	,
    IND_SUPERTEL    	,
    NUM_ABONADO     	,
    COD_PORTADOR    	,
    DES_CONCEPTO    	,
    SEG_CONSUMIDO   	,
    NUM_CUOTAS      	,
    ORD_CUOTA       	,
    NUM_UNIDADES    	,
    NUM_SERIEMEC    	,
    NUM_SERIELE     	,
    PRC_IMPUESTO    	,
    VAL_DTO         	,
    TIP_DTO         	,
    MES_GARANTIA    	,
    NUM_GUIA        	,
    IND_ALTA        	,
    NUM_PAQUETE     	,
    FLAG_IMPUES     	,
    FLAG_DTO        	,
    COD_CONCEREL    	,
    COLUMNA_REL     	,
    SEQ_CUOTAS      	,
    COD_PLANTARIF   	,
    COD_CARGOBASICO 	,
    TIP_PLANTARIF   	,
    IMP_DCTO        	,
    IMP_REAL        	,
    DUR_DCTO        	,
    DUR_REAL        	,
    CNT_LLAM_REAL   	,
    CNT_LLAM_DCTO   	,
    CNT_LLAM_FACT
    FROM  FA_HISTCONC_&&1 X
        WHERE ind_ordentotal NOT IN 
    	(SELECT distinct ind_ordentotal FROM FA_HISTCONC_&&1 WHERE Cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO))
     	AND IND_ORDENTOTAL IN ( SELECT IND_ORDENTOTAL_F FROM vm_fa_histdocu ); 


    COMMIT;


   --  TTTTTTTTTTTTT      333333
   --  T    TT     T     33    33
   --       TT                 33
   --       TT             3333
   --       TT                33
   --       TT                 33
   --       TT           33    33
   --       TT            333333
   -- T3 TECNOLOGIA
   -- SE DEBE INSERTAR SOLAMENTE LOS REGISTROS QUE TIENEN NOTA DE CREDITO
   -- LOS QUE TIENEN SE REALIZAN EN UN PROCESO A PARTE ADEMAS DE AQUELLOS QUE TIENEN CONCEPTOS AGRUPADOS



--   IF Tecnologia='EXISTE' AND IndOrdenTotal.COUNT >0 THEN
--
--   	/* ----->CONSULTA 39 <------ */
--    	nConsulta:=39;
--    	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los registros en la tabla auxiliar de tecnologia de los registros que tienen nota de credito por concepto de cargo');
--
--
--   	INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	 IND_ORDENTOTAL ,
--	 COD_CONCEPTO  ,
--	 COLUMNA       ,
--	 COD_TECNOLOGIA,
--	 PRC_TECNOLOGIA )
--   	 SELECT
--            a.IND_ORDENTOTAL ,
--            b.COD_CONCEPTO_new  ,
--            b.COLUMNA_rel_new       ,
--	    a.COD_TECNOLOGIA,
--            a.PRC_TECNOLOGIA
--            FROM FA_HISTECNO_TH_&&1 a, FA_CAMBIA_LLAVE_TO b
--			WHERE a.ind_ordentotal      =b.ind_ordentotal
--				  AND a.cod_concepto=b.cod_concepto
--				  AND a.columna     =b.columna
--				  AND b.cod_tipconce >2
--				  AND a.ind_ordentotal IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);
--	 COMMIT;
--
--	  /* ----->CONSULTA 40 <------ */
-- 	  nConsulta:=40;
--    	  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los registros en la tabla auxiliar de tecnologia de los registros que tienen nota de credito por concepto de impuesto y descuento');
--
--
--	 INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	 IND_ORDENTOTAL ,
--	 COD_CONCEPTO  ,
--	 COLUMNA       ,
--	 COD_TECNOLOGIA,
--	 PRC_TECNOLOGIA )
--   	 SELECT
--           a.IND_ORDENTOTAL ,
--            CASE WHEN b.cod_tipconce=1 THEN a.cod_concepto
--            	 WHEN b.cod_tipconce=2 THEN b.COD_CONCEPTO_new  END COD_CONCEPTO,
--	    CASE WHEN b.cod_tipconce=1 THEN a.columna
--            	 WHEN b.cod_tipconce=2 THEN b.COLUMNA_rel_new  END COLUMNA,
--	    a.COD_TECNOLOGIA,
--            a.PRC_TECNOLOGIA
--            FROM FA_HISTECNO_TH_&&1 a, FA_CAMBIA_LLAVE_TO b
--			WHERE a.ind_ordentotal      =b.ind_ordentotal
--				  AND a.cod_concepto=b.cod_concepto
--				  AND a.columna     =b.columna
--				  AND b.cod_tipconce <=2
--				  AND a.ind_ordentotal IN (SELECT ind_ordentotal_f FROM vm_fa_histdocu);
--
--         COMMIT;
--
--   -- T3 TECNOLOGIA
--   -- SE DEBE INSERTAR SOLAMENTE LOS REGISTROS QUE TIENEN NOTA DE CREDITO
--   -- LOS QUE TIENEN SE REALIZAN EN UN PROCESO A PARTE ADEMAS DE AQUELLOS QUE TIENEN CONCEPTOS AGRUPADOS
--
--   --  TTTTTTTTTTTTT        444
--   --  T    TT     T       4444
--   --       TT            44 44
--   --       TT           44  44
--   --       TT          4444444
--   --       TT               44
--   --       TT               44
--   --       TT               44
--   	-- FALTA INSERTAR TECNOLOGIA DE NO AGRUPADOS Y CON NOTA DE CREDITO
--   	--
--
--   	  /* ----->CONSULTA 41 <------ */
-- 	  nConsulta:=41;
--    	  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Inserta los restantes registros en la tabla auxiliar de tecnologia de los registros que tienen nota de credito y no poseen codigos de concepto por agrupar');
--
--
--   	INSERT INTO FA_HISTECNO_TH_&&1._AUX (
--   	        IND_ORDENTOTAL ,
--	        COD_CONCEPTO  ,
--		COLUMNA       ,
--		COD_TECNOLOGIA,
--		PRC_TECNOLOGIA )
--   	        SELECT
--                	IND_ORDENTOTAL ,
--             		COD_CONCEPTO  ,
--             		COLUMNA       ,
--             		COD_TECNOLOGIA,
--             		PRC_TECNOLOGIA
--             	FROM FA_HISTECNO_TH_&&1
--		WHERE ind_ordentotal NOT IN
--			(SELECT DISTINCT ind_ordentotal
--			FROM FA_HISTECNO_TH_&&1
--			WHERE Cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO ) )
--			AND IND_ORDENTOTAL  IN ( SELECT IND_ORDENTOTAL_F FROM VM_FA_HISTDOCU ) ;
--
--	END IF;
--
--  COMMIT;


  /* ----->CONSULTA 41.1 <------ */
  /* VERIFICA SI LOS MONTOS QUEDAN IGUALES EN FA_AJUSTES*/

   nConsulta:=41.1;
   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de los ajustes alterados para determinar diferencias');

   SELECT sum(IMP_FACTURABLE) ,
   	sum(IMP_CONCEPTO)
   INTO vImp_Facturable2,
	vImp_Concepto2
   FROM fa_ajusteconc;

   IF 	vImp_Facturable1 <> vImp_Facturable2 OR vImp_Concepto1 <> vImp_Concepto2 THEN
   	RAISE ERROR_1;
   END IF;

	 /* ----->CONSULTA 41.2 <------ */
   nConsulta:=41.2;

   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Sumatoria de los totales de los montos de la tabla fa_histconc_&&1');

   SELECT 	sum(IMP_CONCEPTO),
		sum(IMP_DCTO),
		sum(IMP_FACTURABLE),
		sum(IMP_MONTOBASE),
		sum(IMP_REAL)
   INTO
		vImp_concepto4,
		vImp_dcto4,
		vImp_Facturable4,
		vImp_Montobase4,
		vImp_ImpReal4
   FROM fa_histconc_&&1;

   IF vImp_concepto3 <> vImp_concepto4
   	OR vImp_dcto3 <> vImp_dcto4
   	OR vImp_Facturable3 <> vImp_Facturable4
   	OR vImp_Montobase3 <> vImp_Montobase4
   	OR vImp_ImpReal3 <> vImp_ImpReal4 THEN
   		RAISE ERROR_2;
   END IF;


--   /* ----->CONSULTA 41.3 <------ */
--   nConsulta:=41.3;
--   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Actualizao descripcion de conceptos en la tabla fa_histconc_&&1');
--
--   UPDATE FA_HISTCONC_&&1._AUX A
--	SET DES_CONCEPTO=(SELECT B.DES_CONCEPTO
--	FROM FA_ENTRADA_TO B
--	WHERE A.COD_CONCEPTO=B.CODIGO_DESTINO
--	GROUP BY B.DES_CONCEPTO)
--   WHERE A.COD_CONCEPTO=(SELECT C.CODIGO_DESTINO
--   FROM FA_ENTRADA_TO C WHERE A.COD_CONCEPTO=C.CODIGO_DESTINO GROUP BY CODIGO_DESTINO);


EXCEPTION
WHEN ERROR_1 THEN
 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(&&1, 'ERROR', SYSDATE);
 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Los Montos no corresponden en los ajustes');
WHEN ERROR_2 THEN
 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(&&1, 'ERROR', SYSDATE);
 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, 'Los Montos no corresponden la tabla fa_histconc_19010102');


WHEN OTHERS THEN
        	FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(&&1, 'ERROR', SYSDATE);
        	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, nConsulta, null, sysdate, sqlcode, sqlerrm);




END;
/



UPDATE FA_CICLOS_PROCESADOS_TO
SET FECHA_TERMINO=SYSDATE, ESTADO='OK'
WHERE COD_CICLFACT=&&1;

COMMIT;

-- actualiza descripcion en de conceptos
UPDATE FA_HISTCONC_&&1._AUX A
	SET DES_CONCEPTO=(SELECT B.DES_CONCEPTO
	FROM FA_ENTRADA_TO B
	WHERE A.COD_CONCEPTO=B.CODIGO_DESTINO
	GROUP BY B.DES_CONCEPTO)
	WHERE A.COD_CONCEPTO=(SELECT C.CODIGO_DESTINO
	FROM FA_ENTRADA_TO C WHERE A.COD_CONCEPTO=C.CODIGO_DESTINO GROUP BY CODIGO_DESTINO);

commit;

-- actualiza descripcion en de conceptos

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.4, null, sysdate, sqlcode, 'ACTUALIZA DESCRIPCION CARGOS'); 

UPDATE FA_HISTCONC_&&1._AUX A
	SET DES_CONCEPTO=(SELECT B.DES_CONCEPTO
	FROM FA_ENTRADA_TO B
	WHERE A.COD_CONCEPTO=B.CODIGO_DESTINO
	GROUP BY B.DES_CONCEPTO)
	WHERE A.COD_CONCEPTO=(SELECT C.CODIGO_DESTINO
	FROM FA_ENTRADA_TO C WHERE A.COD_CONCEPTO=C.CODIGO_DESTINO GROUP BY CODIGO_DESTINO);

commit;

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.5, null, sysdate, sqlcode, 'ACTUALIZA DESCRIPCION DESCUENTOS'); 

UPDATE FA_HISTCONC_&&1._AUX A
SET DES_CONCEPTO=(SELECT B.DES_CONCEPTO_DCTO
		FROM FA_ENTRADA_TO B, FA_CONCEPTOS C
		WHERE B.CODIGO_DESTINO=C.COD_CONCORIG
		AND A.COD_CONCEPTO=C.COD_CONCEPTO
		GROUP BY B.DES_CONCEPTO_DCTO)
WHERE A.COD_CONCEPTO=(SELECT D.COD_CONCEPTO
			FROM FA_CONCEPTOS D, FA_ENTRADA_TO E 
			WHERE D.COD_CONCORIG=E.CODIGO_DESTINO
			AND A.COD_CONCEPTO=D.COD_CONCEPTO
			GROUP BY D.COD_CONCEPTO);

COMMIT;

SELECT 'CANTIDAD REGISTROS TABLA HISTCONC_AUX:' FROM DUAL;

SELECT COUNT (*) FROM FA_HISTCONC_&&1._AUX;

EXIT 0;
   