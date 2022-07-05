whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

VARIABLE vg_IndNcred NUMBER;

 ----->CONSULTA 0 <------ --
DECLARE
	nExisteCiclo NUMBER;
BEGIN

	SELECT COUNT(1) INTO nExisteCiclo
	FROM FA_CICLOS_PROCESADOS_TO WHERE COD_CICLFACT = 19010102;

	IF nExisteCiclo>0 THEN
		UPDATE FA_CICLOS_PROCESADOS_TO
		SET ESTADO='INICIADO',
		    FECHA_INICIO=SYSDATE
		WHERE COD_CICLFACT=19010102;
	ELSE
		INSERT INTO FA_CICLOS_PROCESADOS_TO (COD_CICLFACT, ESTADO, FECHA_INICIO, FECHA_TERMINO, DURACION)
		VALUES (19010102, 'INICIADO',SYSDATE, NULL, NULL);

	END IF;

END;

/

COMMIT;

DECLARE 
	sSql varchar2 (2048);
	nConsulta number;
BEGIN

	-- ----->CONSULTA 2 <------ --
	nConsulta := 2;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 2, null, sysdate, sqlcode, 'Crea la vista VM_FA_HISTDOCU_PRE que sirve para acotar el universo de registros de la tabla FA_HISTDOCU');

	sSql:= 'CREATE TABLE VM_FA_HISTDOCU_PRE AS ';
	sSql:= sSql || 'SELECT a.NUM_SECUENCI, a.COD_TIPDOCUM,';
	sSql:= sSql || '  a.COD_CLIENTE  , a.IND_ORDENTOTAL ,';
	sSql:= sSql || '  A.NUM_FOLIO    , a.COD_CICLFACT   ,';
	sSql:= sSql || '  a.NUM_SECUREL , a.PREF_PLAZA      ,';
	sSql:= sSql || '  a.COD_TIPDOCUMREL , a.letra,';
	sSql:= sSql || '  a.COD_CENTREMI,';
	sSql:= sSql || '  a.COD_VENDEDOR_AGENTE ';
	sSql:= sSql || 'FROM fa_histdocu a ';
	sSql:= sSql || 'WHERE A.cod_ciclfact=19010102 ';
	sSql:= sSql || '  AND EXISTS (SELECT 1 FROM fa_histconc_19010102 b, FA_ENTRADA_TO C ';
	sSql:= sSql || '	       WHERE B.IND_ORDENTOTAL = A.IND_ORDENTOTAL ';
	sSql:= sSql || '  	         AND C.CODIGO_CONCEPTO= B.COD_CONCEPTO) ';
	sSql:= sSql || '  AND a.COD_TIPDOCUM != 25 '; --que no considere las NC jlizama
	
	EXECUTE IMMEDIATE sSql;

-- ----->CONSULTA 3 <------ --
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 3, null, sysdate, sqlcode, 'Crea indice IND_FA_HISTDOCU_PRE a la vista VM_FA_HISTDOCU_PRE');

	sSql:= 'CREATE INDEX IND_FA_HISTDOCU_PRE ON VM_FA_HISTDOCU_PRE(NUM_SECUENCI, COD_TIPDOCUM, COD_VENDEDOR_AGENTE, LETRA, COD_CENTREMI) ' ;

	EXECUTE IMMEDIATE sSql;

	EXCEPTION
	 WHEN NO_DATA_FOUND THEN
	 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
	 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'NO EXISTEN DOCUMENTOS NO CICLO A ACTUALIZAR');
	 		raise;

	 WHEN OTHERS THEN
    		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
    		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, sqlerrm);
    		raise;

END;

/


-- CREACION UNIVERSO DE NOTAS DE CREDITO A MODIFCAR --
DECLARE 

   sSql varchar2 (2048);
	nConsulta number;
BEGIN 
	
	-- ----->CONSULTA 4 <------ --
	nConsulta := 4;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 4, null, sysdate, sqlcode, 'Crea vista VM_FA_HISTDOCU_G, en esta se encontraran registros encabezados de facturas y sus respectivas notas de credito');

	sSql:= 'CREATE TABLE VM_FA_HISTDOCU_G AS ';
	sSql:=sSql || 'SELECT --+  index (fa_histdocu IND_FA_HISTDOCU_SECUREL) -- a.NUM_SECUENCI, ';
	sSql:=sSql || '	  a.COD_TIPDOCUM    ,';
	sSql:=sSql || '	  a.COD_CLIENTE            ,';
	sSql:=sSql || '	  a.IND_ORDENTOTAL AS IND_ORDENTOTAL_F       ,';  -- con este rescato el detalle de la factura en la tabla de ciclo respectiva
	sSql:=sSql || '	  A.NUM_FOLIO                                ,'; -- con el folio de la factura se va a la tabla de ajustes (fa_ajusteconc)para ver los conceptos rebajados del documento
	sSql:=sSql || '	  b.IND_ORDENTOTAL AS IND_ORDENTOTAL_DNC     ,'; -- con este camp obtengo el detalle de la nota de credito en la tabla (fa_histconc_19010102)
	sSql:=sSql || '	  a.COD_CICLFACT           ,';
	sSql:=sSql || '	  a.NUM_SECUREL            ,';
	sSql:=sSql || '	  a.PREF_PLAZA             ,';
	sSql:=sSql || '	  b.COD_TIPDOCUMREL ';
	sSql:=sSql || 'FROM vm_fa_histdocu_pre a ,vm_fa_histdocu_ncred b '; -- a factura b nota de credito se rescata el num_folio
	sSql:=sSql || 'WHERE A.num_secuenci		= b.num_securel ';
	sSql:=sSql || '	AND A.COD_TIPDOCUM		= b.COD_TIPDOCUMREL ';
	sSql:=sSql || '	AND A.COD_VENDEDOR_AGENTE= B.COD_VENDEDOR_AGENTEREL ';
	sSql:=sSql || '	AND a.LETRA				= b.LETRAREL ';
	sSql:=sSql || '	AND a.COD_CENTREMI		= b.COD_CENTRREL';
	sSql:=sSql || '	AND A.COD_CLIENTE 		= B.COD_CLIENTE';
	sSql:=sSql || '	AND b.num_securel is not null	';

	EXECUTE IMMEDIATE sSql;

EXCEPTION
	WHEN NO_DATA_FOUND THEN 
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 999, null, sysdate, sqlcode, 'No existen notas de credito a procesar');
		:vg_IndNcred := 0;
	WHEN OTHERS THEN
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 999, null, sysdate, sqlcode, 'Error no controlado nla obtencion de Ncredito');		
		RAISE;
		
END;
/

-- FACTURAS QUE TIENEN NOTA DE CREDITO --
-------------------------------------- --
	

-- ----->CONSULTA 5 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 5, null, sysdate, sqlcode, 'Crea vista VM_FA_HISTCONC_G, en esta se encontraran registros detalle de facturas que tienen notas de credito');

-- -----Modificacion no traer todo el universo del detalle de la factura -------------------
--CREATE TABLE VM_FA_HISTCONC_G AS
--SELECT A.*
--FROM FA_HISTCONC_19010102 A, ops$xpfactur.VM_FA_HISTDOCU_G G, FA_ENTRADA_TO E
--WHERE A.IND_ORDENTOTAL = G.IND_ORDENTOTAL_F
--AND A.COD_CONCEPTO = E.CODIGO_CONCEPTO;

CREATE TABLE VM_FA_HISTCONC_G AS                                             
SELECT UNIQUE A.*                                                                   
FROM FA_HISTCONC_19010102 A, ops$xpfactur.VM_FA_HISTDOCU_G G
WHERE A.IND_ORDENTOTAL = G.IND_ORDENTOTAL_F;


-- ----->CONSULTA 6 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 6, null, sysdate, sqlcode, 'Crea indice IND_TMP62 de la vista VM_FA_HISTCONC_G');

CREATE UNIQUE INDEX IND_TMP6 ON VM_FA_HISTCONC_G (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA );

-- ----->CONSULTA 6.1 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 6.1, null, sysdate, sqlcode, 'CREA INDICE IND_TMP66 EN VM_FA_HISTCONC_F');

CREATE INDEX IND_TMP66 ON VM_FA_HISTCONC_G (COD_CONCEREL, COLUMNA_REL, IND_ORDENTOTAL );


-- FACTURAS QUE TIENEN NOTA DE CREDITO--
----------------------------------------
-- ----->CONSULTA 7 <------ --

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 7, null, sysdate, sqlcode, 'Crea la vista VM_FA_HISTCONC_GDNC donde se encuentra el detalle de las notas de credito que tienen conceptos que se van a cambiar');
-- --Modificacion de select debido a que no trae el detalle conpleto de la factura -----
--CREATE TABLE VM_FA_HISTCONC_GDNC  AS
--SELECT A.*
--FROM FA_HISTCONC_19010102 A, VM_FA_HISTDOCU_G G, FA_ENTRADA_TO E
--WHERE A.IND_ORDENTOTAL = G.IND_ORDENTOTAL_DNC
--AND A.COD_CONCEPTO = E.CODIGO_CONCEPTO;

CREATE TABLE VM_FA_HISTCONC_GDNC  AS
SELECT A.*
FROM FA_HISTCONC_19010102 A, VM_FA_HISTDOCU_G G
WHERE A.IND_ORDENTOTAL = G.IND_ORDENTOTAL_DNC;

-- ----->CONSULTA 8 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 8, null, sysdate, sqlcode, 'Crea el indice IND_TMP8 de la vista VM_FA_HISTCONC_GDNC ');

CREATE INDEX IND_TMP8 ON VM_FA_HISTCONC_GDNC (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA );

-- ----->CONSULTA 8.1 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 8.1, null, sysdate, sqlcode, 'Crea indice TMP88 en VM_FA_HISTCONC_F');

CREATE INDEX IND_TMP88 ON VM_FA_HISTCONC_GDNC (COD_CONCEREL, COLUMNA_REL, IND_ORDENTOTAL );

-- AJUSTES QUE TIENE LA NOTA DE CREDITO--
----------------------------------------
-- ----CREO INDICE EN LA TABLA vm_fa_histdocu_g ------
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 10, null, sysdate, sqlcode, 'Crea el indice IND_TMP99 para la vista vm_fa_histdocu_g');

CREATE INDEX IND_TMP99 ON VM_FA_HISTDOCU_G (NUM_FOLIO, COD_CLIENTE, COD_TIPDOCUM );

-- ----->CONSULTA 11 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 11, null, sysdate, sqlcode, 'Crea el indice IND_TMP10 para la vista VM_FA_AJUSTES_G para los campos (PREF_PLAZA, NUM_FOLIO)');

CREATE INDEX IND_TMP10 ON VM_FA_HISTDOCU_G (PREF_PLAZA, NUM_FOLIO) ;

-- ----->CONSULTA 9 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 9, null, sysdate, sqlcode, 'Identifica los ajustes en la vista llamada VM_FA_AJUSTES_G de los registros correspondientes a las notas de credito');


CREATE TABLE VM_FA_AJUSTES_G  AS
SELECT 
NUM_FOLIO, COD_CLIENTE, COD_CONCEPTO, 
COD_MONEDA, COLUMNA, IMP_FACTURABLE, COD_PRODUCTO, 
FEC_EFECTIVIDAD, IMP_CONCEPTO, COD_REGION, COD_PROVINCIA, 
COD_TIPCONCE, COD_CIUDAD, FEC_VALOR, COD_MODULO, IMP_MONTOBASE, 
IND_FACTUR, NUM_UNIDADES, IND_SUPERTEL, NUM_SERIEMEC, NUM_ABONADO, 
COD_PORTADOR, DES_CONCEPTO, SEQ_CUOTAS, NUM_CUOTAS, ORD_CUOTA, NUM_SERIELE, 
MES_GARANTIA, NUM_GUIA, IND_ALTA, NUM_PAQUETE, NUM_VENTA, NUM_TRANSACCION, 
FLAG_IMPUES, FLAG_DTO, COD_TIPDOCUM, PREF_PLAZA
FROM fa_ajusteconc x
WHERE exists (SELECT 1
		FROM ops$xpfactur.vm_fa_histdocu_pre b
		WHERE b.pref_plaza = x.pref_plaza
		AND b.num_folio = x.num_folio
		and b.cod_tipdocum = x.cod_tipdocum
		and b.cod_cliente = x.cod_cliente);

-- ----->CONSULTA 10 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 10, null, sysdate, sqlcode, 'Crea el indice IND_TMP9 para la vista VM_FA_AJUSTES_G');

CREATE INDEX IND_TMP9 ON VM_FA_AJUSTES_G (NUM_FOLIO);

-- ----->CONSULTA 12 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 12, null, sysdate, sqlcode, 'Crea el indice IND_TMP11 para la vista VM_FA_AJUSTES_G para el campo (IND_ORDENTOTAL_F) que representa el numero de la factura');

CREATE INDEX IND_TMP11 ON VM_FA_HISTDOCU_G (IND_ORDENTOTAL_F);

-- ----->CONSULTA 13 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 13, null, sysdate, sqlcode, 'Crea el indice IND_TMP12 para la vista VM_FA_AJUSTES_G para el campo (IND_ORDENTOTAL_DNC) que representa el numero del detalle de la nota de credito');

CREATE INDEX IND_TMP12 ON VM_FA_HISTDOCU_G (IND_ORDENTOTAL_DNC);

----end if;------

-- se extraen la cabecera de la factura
-- ----->CONSULTA 14 <------ --
----IF :vg_IndNcred THEN-------
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 14, null, sysdate, sqlcode, 'Crea la vista VM_FA_HISTDOCU_F que contiene el detalle de las facturas que no tienen notas de credito con tabla G');

CREATE TABLE VM_FA_HISTDOCU_F AS
SELECT                                                      
  a.NUM_SECUENCI,              
  a.COD_TIPDOCUM ,             
  a.COD_CLIENTE             ,  
  a.IND_ORDENTOTAL ,           
  a.NUM_FOLIO               ,  
  a.COD_CICLFACT            ,  
  a.NUM_SECUREL                
 FROM vm_fa_histdocu_pre a     
WHERE NOT EXISTS (SELECT 1     
		  FROM VM_FA_HISTDOCU_G B  
	   	 WHERE B.IND_ORDENTOTAL_F=A.IND_ORDENTOTAL);

-- ----->CONSULTA 15 <------ --

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 15, null, sysdate, sqlcode, 'Crea el indice IND_TMP1 para la vista VM_FA_HISTDOCU_F que representa al campo NUM_FOLIO');

CREATE INDEX IND_TMP1 ON VM_FA_HISTDOCU_F (NUM_FOLIO );

-- ----->CONSULTA 16 <------ --

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 16, null, sysdate, sqlcode, 'Crea el indice IND_TMP2 para la vista VM_FA_HISTDOCU_F que representa al campo IND_ORDENTOTAL');

CREATE INDEX IND_TMP2 ON VM_FA_HISTDOCU_F (IND_ORDENTOTAL );

-- ----->CONSULTA 17 <------ --

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 17, null, sysdate, sqlcode, 'Crea el indice IND_TMP3 para la vista VM_FA_HISTDOCU_F que representa al campo NUM_SECUREL');

CREATE INDEX IND_TMP3 ON VM_FA_HISTDOCU_F (NUM_SECUREL );

-- ----->CONSULTA 18 <------ --

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 18, null, sysdate, sqlcode, 'Crea el indice IND_TMP4 para la vista VM_FA_HISTDOCU_F que representa al campo NUM_SECUENCI');

CREATE INDEX IND_TMP4 ON VM_FA_HISTDOCU_F (NUM_SECUENCI );

-- se extraen la cabecera de la factura

-- ----->CONSULTA 19 antigua<------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 19, null, sysdate, sqlcode, 'Obtiene el detalle de las facturas que no tienen notas de credito asociadas');

--CREATE TABLE VM_FA_HISTCONC_F AS
--SELECT *
--FROM FA_HISTCONC_19010102 A
--WHERE EXISTS (SELECT 1
--		FROM VM_FA_HISTDOCU_F X, FA_ENTRADA_TO E
--	        WHERE X.IND_ORDENTOTAL=A.IND_ORDENTOTAL
--	 	AND A.COD_CONCEPTO = E.CODIGO_CONCEPTO);
--
---- ----->CONSULTA 19 PERFORMANCE JORGE LIZAMA<------ --                                                                                                                                             
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 19, null, sysdate, sqlcode, 'Obtiene el detalle de las facturas que no tienen notas de credito asociadas');
--                                                                                                                                                                            
--CREATE TABLE VM_FA_HISTCONC_F AS                                                                                                                                            
--SELECT A.*                                                                                                                                                                  
--FROM FA_HISTCONC_19010102 A, ops$xpfactur.VM_FA_HISTDOCU_F X, FA_ENTRADA_TO E                                                                                               
--WHERE A.IND_ORDENTOTAL=X.IND_ORDENTOTAL                                                                                                                                     
--AND A.COD_CONCEPTO = E.CODIGO_CONCEPTO;  

CREATE TABLE VM_FA_HISTCONC_F AS                        
SELECT A.*                                                
FROM FA_HISTCONC_19010102 A, VM_FA_HISTDOCU_F X                             
WHERE X.IND_ORDENTOTAL > 0
AND  A.IND_ORDENTOTAL=X.IND_ORDENTOTAL;

-- ----->CONSULTA 20 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20, null, sysdate, sqlcode, 'Crea indice IMP_TMP5 para la vista VM_FA_HISTCONC_F representando a los campos IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA');

CREATE INDEX IND_TMP5 ON VM_FA_HISTCONC_F (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA );

-- ----->CONSULTA 20.01 <------ --
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20.01, null, sysdate, sqlcode, 'CREATE INDEX IND_TMP55 ON VM_FA_HISTCONC_F (COD_CONCEREL, COLUMNA_REL, IND_ORDENTOTAL)');

CREATE INDEX IND_TMP55 ON VM_FA_HISTCONC_F (COD_CONCEREL, COLUMNA_REL, IND_ORDENTOTAL);

-------->CONSULTA 20.02 BM-----------
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20.01, null, sysdate, sqlcode, 'CREA TABLA TEMPORAL FA_AJUSTECONC_TMP');

CREATE TABLE FA_AJUSTECONC_TMP AS
SELECT * FROM FA_AJUSTECONC WHERE ROWNUM < 1;


EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20.02, null, sysdate, sqlcode, 'CREA INDICE TEMPORAL PARA TABLA DE AJUSTES PK_FA_AJUSTECONC_TMP');
CREATE INDEX PK_FA_AJUSTECONC_TMP ON FA_AJUSTECONC_TMP (PREF_PLAZA, NUM_FOLIO, COD_CLIENTE, COD_TIPDOCUM, COD_CONCEPTO,COLUMNA);

-------->CONSULTA 20.03 BM-----------
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20.03, null, sysdate, sqlcode, 'CREA TABLA TEMPORAL FA_HISTCONC_19010102_tmp');

create table FA_HISTCONC_19010102_tmp as
SELECT * FROM FA_HISTCONC_19010102
where rownum <1;


-------->CONSULTA 20.04 BM-----------

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 20.04, null, sysdate, sqlcode, 'CREA INDICE TEMPORAL PK_FA_HISTCONC_19010102_TMP');

CREATE UNIQUE INDEX PK_FA_HISTCONC_19010102_TMP ON FA_HISTCONC_19010102_tmp (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA);


-----------------Inicio bloque de procesamiento----------------------

DECLARE
  TYPE ind_orden IS TABLE OF number INDEX BY BINARY_INTEGER;
  IndOrdenTotal  	ind_orden;

  TYPE tCol_Codest IS TABLE OF Varchar2(4) INDEX BY BINARY_INTEGER;

  Col_codconcepto_new   tCol_Codest;

  Tecnologia 		VARCHAR2(10);
  sSql 			VARCHAR2(32767);

  i 			NUMBER;
  k			NUMBER;


  --excepciones
  
  ---- error en sumatoria de ajustes--
  ERROR_1		EXCEPTION;   
  
  ---- error en sumatoria fa_histconc_19010102--
  ERROR_2		EXCEPTION;   

  ErrorOracle		NUMBER;
  nConsulta		NUMBER;

  -- Variables para verificar consistencia en AJUSTES--

  vImp_Facturable1	NUMBER;
  vImp_Concepto1	NUMBER;

  vImp_Facturable2	NUMBER;
  vImp_Concepto2	NUMBER;


  -- Variables para verificar consistencia en FA_HISTCONC_19010102--


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


	--     FFFFFFFFFFF
	--     FF
	--     FF
   	--     FF
   	--     FFFFFFF
   	--     FF
   	--     FF
   	--     FF
   	--     FF


 ------En esta parte se debe procesar solamente las que no tienen Nota de Credito-----

	-- ----->CONSULTA 20.1 <------ --
--	nConsulta:=20.1;
--
--	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Sumatoria de los totales de los montos de la tabla fa_histconc_19010102');
--
--	SELECT 	sum(IMP_CONCEPTO),
--		sum(IMP_DCTO),
--		sum(IMP_FACTURABLE),
--		sum(IMP_MONTOBASE),
--		sum(IMP_REAL)
--	INTO
--		vImp_concepto3,
--		vImp_dcto3,
--		vImp_Facturable3,
--		vImp_Montobase3,
--		vImp_ImpReal3
--	FROM fa_histconc_19010102;
--
 
   		-- ----->CONSULTA 21 <------ --
   		nConsulta:=21;

   		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Consulta para procesar solamente las facturas que no tienen nota de credito');

   		EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM vm_fa_histconc_f '
   		|| ' WHERE Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '
		BULK COLLECT INTO IndOrdenTotal;

		-- ----->CONSULTA 22 <------ --
		nConsulta:=22;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Se procesan los registros sin impuestos');
		nConsulta:=23;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Consulta dinamica para cambiar llave');

   		IF IndOrdenTotal.COUNT >0 THEN
        		FOR i in 1..Indordentotal.count LOOP
	           		SELECT DISTINCT cod_concepto_new
					BULK COLLECT INTO Col_codconcepto_new
					FROM (SELECT DISTINCT cod_concepto_new
	                    	FROM ( SELECT
	                    	   		  ind_ordentotal,
	                    			  cod_concepto,
	                    			  columna,
	                    			  cod_concerel,
	                    			  columna_rel,
	                    			  cod_tipconce,
	                    			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
	                    			FROM vm_fa_histconc_f a, FA_ENTRADA_TO b
	                    	   		WHERE ind_ordentotal	= Indordentotal(i)
	                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
	                    			  AND cod_tipconce	<> 1)
							UNION ALL
							SELECT DISTINCT cod_concepto_new
	                    	  FROM ( SELECT
	                    	   		  ind_ordentotal,
	                    			  cod_concepto,
	                    			  columna,
	                    			  cod_concerel,
	                    			  columna_rel,
	                    			  cod_tipconce,
			  			  NVL((SELECT cod_concepto 
			  			  		 FROM fa_conceptos 
			  			  		WHERE cod_concorig = (SELECT CODIGO_DESTINO 
			  			  					FROM FA_ENTRADA_TO 
			  			  					WHERE CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new
	                    			FROM vm_fa_histconc_f a, FA_ENTRADA_TO b
                    	   		WHERE ind_ordentotal		= Indordentotal(i)
                   	   			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                   				  AND cod_tipconce	= 2));

                    		-- ----->CONSULTA 23 <------ --

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
                    	  	||' 	  a.ind_ordentotal,'
                    	  	||'	  a.cod_concepto, '
                     	  	||'	  a.columna, '
                    	  	||'	  a.cod_concerel,'
                    	  	||'	  a.columna_rel,'
                    	  	||'	  a.cod_tipconce,'
			  	||'  	  CASE WHEN cod_tipconce=2  THEN NVL((SELECT cod_concepto FROM fa_conceptos WHERE cod_concorig = (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO=cod_concerel)), cod_concepto) '
			  	||'       	WHEN cod_tipconce!=2 THEN NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, '
			  	||'  	  CASE WHEN cod_tipconce=2  THEN CODIGO_DESTINO END cod_concerel_new '
                    	  	||'  	  FROM vm_fa_histconc_f a, 		FA_ENTRADA_TO b '
                    	  	||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
                    	  	||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
                    	  	||'			  and cod_tipconce	<>1   ) x '
                          	||' WHERE cod_concepto_new= :CODIGODEST ';


                    	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last
                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);
		        END LOOP;
   		END IF;
   	COMMIT;

	-- ----->CONSULTA 24 <------ --
	nConsulta:=24;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_CAMBIA_LLAVE_TO los registros cuyo tipo de concepto sea 1');


	--Inserta los registros de tipo concepto 1--

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
        FROM vm_fa_histconc_f a, FA_CAMBIA_LLAVE_TO b
        WHERE b.ind_ordentotal > 0
        and a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1;

        COMMIT;
	--
   	-- Se eliminan los registros antes de la insercion
   	--
--
--   	-- ----->CONSULTA 25 <------ --
--   	nConsulta:=25;
--	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Elimina datos de la tabla FA_HISTCONC_19010102 para reemplazarlos por los registros con nueva llave');
--
--
--		DELETE FROM fa_histconc_19010102 a
--	  	   			WHERE EXISTS (SELECT a.ind_ordentotal, a.cod_concepto, a.columna
--			  			   		FROM fa_histconc_19010102 a, vm_fa_histconc_f b
--			  			   	   WHERE b.ind_ordentotal	= a.ind_ordentotal
--						   	 	 And b.cod_concepto	= a.cod_concepto
--								 And b.columna		= a.columna
--								 and b.ind_ordentotal > 0)
--					and ind_ordentotal >0;
--
--   	COMMIT;
--
   	--
   	-- Se reponen los registros de facturas de no ciclo sin nota de credito
   	--

   	-- ----->CONSULTA 26 <------ --

   	nConsulta:=26;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_HISTCONC_19010102 los registros cuyo tipo de concepto sea mayor que 2, con la nueva llave');

   	INSERT INTO FA_HISTCONC_19010102_tmp
   	(
   	IND_ORDENTOTAL   ,
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	)
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
          c.DES_CONCEPTO     ,
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
          FROM vm_fa_histconc_f a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
          WHERE a.ind_ordentotal	= b.ind_ordentotal
          	  and a.cod_concepto	= b.cod_concepto
          	  and a.columna		= b.columna
          	  and b.cod_concepto_new= c.cod_concepto
          	  and a.cod_tipconce	> 2
          	  AND b.ind_ordentotal > 0;


	COMMIT;

   	-- ----->CONSULTA 27 <------ --

   	nConsulta:=27;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_HISTCONC_19010102 los registros cuyo tipo de concepto 1 y 2, con la nueva llave');

   	INSERT INTO FA_HISTCONC_19010102_tmp               
   	(
   	IND_ORDENTOTAL   ,
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	)
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
	       WHEN a.cod_tipconce=2 THEN (SELECT des_concepto FROM FA_CONCEPTOS WHERE b.COD_CONCEPTO_NEW=cod_concepto) END DES_concepto,
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
          a.CNT_LLAM_FACT    ,
          a.MIN_PLANTARIF    ,
          a.COD_UNIDAD       ,
          a.COD_OPERADOR
          FROM vm_fa_histconc_f a, FA_CAMBIA_LLAVE_TO b
          WHERE a.ind_ordentotal	= b.ind_ordentotal
          	  and a.cod_concepto	= b.cod_concepto
          	  and a.columna		= b.columna
          	  and a.cod_tipconce	<=2
          	  AND b.ind_ordentotal > 0;

   	COMMIT;


		--     GGGGGGGG
		--   GG        GG
		--  GG
		-- GG
		-- GG    GGGGGGGG
		-- GG          GG
		--  GG         GG
		--   GG       GG
		--    GGGGGGGG         --- NO CICLO CON NOTA DE CREDITO

		-- la tabla FA_CAMBIA_LLAVE_TO contiene el campo columna, cod_concepto, cod_concerel, columna_rel, antiguas y nuevas
		-- de aquellos que solamente tienen nota de credito

   		-- ----->CONSULTA 28 <------ --
   		nConsulta:=28;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Selecciona las facturas que tienen nota de credito');

   		EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM vm_fa_histconc_g '
		BULK COLLECT INTO IndOrdenTotal;

		-- ----->CONSULTA 29 <------ --
		nConsulta:=29;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Bloque para cambiar la llave');
		nConsulta:=30;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Consulta dinamica para insertar las llaves cambiadas');

   		IF IndOrdenTotal.COUNT >0 THEN
            		FOR i in 1..Indordentotal.count LOOP
          		SELECT DISTINCT cod_concepto_new
				BULK COLLECT INTO Col_codconcepto_new
				FROM (SELECT DISTINCT cod_concepto_new
            			FROM ( SELECT ind_ordentotal,
			            			  cod_concepto,
			            			  columna,
			            			  cod_concerel,
			            			  columna_rel,
			            			  cod_tipconce,
			            			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
		            			FROM vm_fa_histconc_g a, 		FA_ENTRADA_TO b
		            	   		WHERE ind_ordentotal	= Indordentotal(i)
		            			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
		            			  AND cod_tipconce	<> 1)
					  UNION ALL
					   SELECT DISTINCT cod_concepto_new
                         FROM ( SELECT ind_ordentotal,
	                    			  cod_concepto,
	                    			  columna,
	                    			  cod_concerel,
	                    			  columna_rel,
	                    			  cod_tipconce,
						  NVL((select cod_concepto 
						  		 from fa_conceptos 
						  		where cod_concorig = (select CODIGO_DESTINO 
		  						from FA_ENTRADA_TO 
		  						where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new
                    			 FROM vm_fa_histconc_g a, FA_ENTRADA_TO b
                    	   		WHERE a.ind_ordentotal = Indordentotal(i)
                    	   		  AND a.cod_concepto   = b.CODIGO_CONCEPTO(+)
                    			  AND cod_tipconce	= 2));

	    		-- ----->CONSULTA 30 <------ --
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
	    	  	||' 	  a.ind_ordentotal,'
	    	  	||'	  a.cod_concepto, '
	     	  	||'	  a.columna, '
	    	  	||'	  a.cod_concerel,'
	    	  	||'	  a.columna_rel,'
           	  	||'	  a.cod_tipconce,'
			  	||'  	  CASE WHEN cod_tipconce=2  THEN NVL((select cod_concepto from fa_conceptos where cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) '
			  	||'       	WHEN cod_tipconce!=2 THEN NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, '
			  	||'  	  CASE WHEN cod_tipconce=2  THEN CODIGO_DESTINO END cod_concerel_new '
	    	  	||'  	  FROM vm_fa_histconc_g a, 		FA_ENTRADA_TO b '
	    	  	||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
	    	  	||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
	    	  	||'			  and cod_tipconce	<>1   ) x '
	          	||' WHERE cod_concepto_new= :CODIGODEST ';

	    	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last
	    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);

	        	END LOOP;
   		END IF;
   	COMMIT;

    --Inserta los registros de tipo concepto 1--

   	-- ----->CONSULTA 31 <------ --
   	nConsulta:=31;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_CAMBIA_LLAVE_TO los registros con las llaves facturas con nota de credito solamente los impuestos');

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
        FROM vm_fa_histconc_g a, FA_CAMBIA_LLAVE_TO b
        WHERE a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1
	and b.ind_ordentotal > 0;
        
        COMMIT;
        

--        -- ----->CONSULTA 32 <------ --
--	   	nConsulta:=32;
--		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Se eliminan los registros de detalle de facturas con nota de credito de FA_HISTCONC_19010102 para ser reemplazados por la nueva llave');
--
--        DELETE FROM fa_histconc_19010102 a
--        WHERE EXISTS (SELECT ind_ordentotal, cod_concepto, columna
--		  			   FROM vm_fa_histconc_g b
--		  			   WHERE b.ind_ordentotal	= a.ind_ordentotal
--				   		 And b.cod_concepto	= a.cod_concepto
--						 And b.columna		= a.columna );
--
--	COMMIT;
--
	-- ----->CONSULTA 33 <------ --
	nConsulta:=33;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Se insertan los nuevos registros en FA_HISTCONC_19010102 con tipo de concepto 3 y 4');

	INSERT INTO FA_HISTCONC_19010102_tmp
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	) SELECT
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
          c.DES_CONCEPTO     ,
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
          FROM vm_fa_histconc_g a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and b.cod_concepto_new=c.cod_concepto
          	  and a.cod_tipconce	>2
          	  and b.ind_ordentotal > 0;
	commit;

   -- ----->CONSULTA 34 <------ --
    nConsulta:=34;
    FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Se insertan los nuevos registros en FA_HISTCONC_19010102 con tipo de concepto 1 y 2');


    INSERT INTO FA_HISTCONC_19010102_tmp
   	(
   	IND_ORDENTOTAL   ,
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	) SELECT
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
	       WHEN a.cod_tipconce=2 THEN (SELECT des_concepto FROM FA_CONCEPTOS WHERE b.COD_CONCEPTO_NEW=cod_concepto) END DES_concepto,
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
          a.CNT_LLAM_FACT    ,
          a.MIN_PLANTARIF    ,
          a.COD_UNIDAD       ,
          a.COD_OPERADOR
          FROM vm_fa_histconc_g a, FA_CAMBIA_LLAVE_TO b
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and a.cod_tipconce	<=2
		  and b.ind_ordentotal > 0;
	   	COMMIT;

      -- CAMBIA LAS NOTA DE CREDITO
      -- la tabla FA_CAMBIA_LLAVE_TO contiene el campo columna, cod_concepto, cod_concerel, columna_rel, antiguas y nuevas
      -- de aquellos que solamente tienen nota de credito

   		-- ----->CONSULTA 35 <------ --
   	nConsulta:=35;
   	
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Selecciona las notas de creditos de las facturas que fueron alteradas');
               
               
   	EXECUTE IMMEDIATE 'SELECT DISTINCT ind_ordentotal FROM vm_fa_histconc_gdnc '
	BULK COLLECT INTO IndOrdenTotal;
               
	-- ----->CONSULTA 36 <------ --
	nConsulta:=36;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Bloque para procesar las llaves de las notas de credito');
               
	nConsulta:=37;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Consulta que insera las nuevas llaves junto con las anteriores en la tabla temporal');
               
   	IF IndOrdenTotal.COUNT >0 THEN
               FOR i in 1..Indordentotal.count LOOP
          		SELECT DISTINCT cod_concepto_new
			BULK COLLECT INTO Col_codconcepto_new
			FROM (SELECT DISTINCT cod_concepto_new
                   				FROM ( SELECT
                   	   			  ind_ordentotal,
                   				  cod_concepto,
                   				  columna,
                   				  cod_concerel,
                   				  columna_rel,
                   				  cod_tipconce,
                   				  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
                   				FROM vm_fa_histconc_gdnc a, 		FA_ENTRADA_TO b
                   	   			WHERE ind_ordentotal	= Indordentotal(i)
                   				  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                   				  AND cod_tipconce	<> 1)
						UNION ALL
						SELECT  DISTINCT cod_concepto_new
                   	  FROM ( SELECT
                   	   		  ind_ordentotal,
                   			  cod_concepto,
                   			  columna,
                   			  cod_concerel,
                   			  columna_rel,
                   			  cod_tipconce,
				  			  NVL((SELECT cod_concepto 
				  			  		 FROM fa_conceptos 
				  			  		 WHERE cod_concorig = (SELECT CODIGO_DESTINO 
				  			  		                         from FA_ENTRADA_TO 
				  			  		                        where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) cod_concepto_new
                   			FROM vm_fa_histconc_gdnc a, FA_ENTRADA_TO b
                   	   		WHERE a.ind_ordentotal		= Indordentotal(i)
                   	   			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)
                   				  AND cod_tipconce	= 2));
               
                   		-- ----->CONSULTA 37 <------ --
               
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
           	  	||' 	  a.ind_ordentotal,'
           	  	||'	  a.cod_concepto, '
            	  	||'	  a.columna, '
           	  	||'	  a.cod_concerel,'
           	  	||'	  a.columna_rel,'
           	  	||'	  a.cod_tipconce,'
			||'  	  CASE WHEN cod_tipconce=2  THEN NVL((select cod_concepto from fa_conceptos where cod_concorig = (select CODIGO_DESTINO from FA_ENTRADA_TO where CODIGO_CONCEPTO=cod_concerel)), cod_concepto) '
			||'       	WHEN cod_tipconce!=2 THEN NVL(CODIGO_DESTINO, cod_concepto)  END COD_CONCEPTO_NEW, '
			||'  	  CASE WHEN cod_tipconce=2  THEN CODIGO_DESTINO END cod_concerel_new '
           	  	||'  	  FROM vm_fa_histconc_gdnc a, 		FA_ENTRADA_TO b '
           	  	||' 		WHERE ind_ordentotal		= ' || indordentotal(i)
           	  	||' 			  and a.cod_concepto	= b.CODIGO_CONCEPTO(+) '
           	  	||'			  and cod_tipconce	<>1   ) x '
                 	||' WHERE cod_concepto_new= :CODIGODEST ';
               
               
           	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last
           	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);
	END LOOP;
   	END IF;
	--Inserta los registros de tipo concepto 1--
               
	  	-- ----->CONSULTA 38 <------ --
	  	nConsulta:=38;
	  	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'inserta las llaves procesadas solamente de los impuestos');

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
        FROM vm_fa_histconc_gdnc a, FA_CAMBIA_LLAVE_TO b
        WHERE a.ind_ordentotal	= b.ind_ordentotal
        AND a.cod_concerel	= b.cod_concepto
        AND a.columna_rel	= b.columna
        AND a.cod_tipconce	= 1
        AND b.ind_ordentotal > 0;

        COMMIT;

--   	-- ELIMINA LAS NOTAS DE CREDITO QUE TIENEN CONCEPTOS POR AGRUPAR Y LAS REEMPLAZA POR LA NUEVA LLAVE--
--
--	-- ----->CONSULTA 39 <------ --
--	nConsulta:=39;
--   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Se eliminan las notas de credito con las llaves originales para insertar la misma informacion con las nuevas llaves');
--	DELETE
--	FROM fa_histconc_19010102 a
--      	WHERE EXISTS (SELECT ind_ordentotal, cod_concepto, columna
--	  			   FROM vm_fa_histconc_gdnc b
--	  			   WHERE b.ind_ordentotal		= a.ind_ordentotal
--				   		 And b.cod_concepto	= a.cod_concepto
--						 And b.columna		= a.columna );
--
--   	COMMIT;
--
   	-- ----->CONSULTA 40 <------ --
   	nConsulta:=40;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_HISTCONC_19010102 el detalle de las notas de credito con la nueva llave correspondiente a la factura referenciada, de aquellos registros que tengan tipo de concepto 3 y 4');

   	INSERT INTO FA_HISTCONC_19010102_tmp
   	(
   		IND_ORDENTOTAL   ,
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	)
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
          c.DES_CONCEPTO     ,
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
          FROM vm_fa_histconc_gdnc a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and b.cod_concepto_new=c.cod_concepto
          	  and a.cod_tipconce	>2
          	  and b.ind_ordentotal > 0;
	commit;

    -- ----->CONSULTA 41 <------ --
    nConsulta:=41;
    FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta en la tabla FA_HISTCONC_19010102 el detalle de las notas de credito con la nueva llave correspondiente a la factura referenciada, de aquellos registros que tengan tipo de concepto 1 y 2');

    INSERT INTO FA_HISTCONC_19010102_tmp
   	( IND_ORDENTOTAL   ,
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
        CNT_LLAM_FACT    ,
        MIN_PLANTARIF    ,
        COD_UNIDAD       ,
        COD_OPERADOR
   	)
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
	       WHEN a.cod_tipconce=2 THEN (SELECT des_concepto FROM FA_CONCEPTOS WHERE b.COD_CONCEPTO_NEW=cod_concepto) END DES_concepto,
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
          a.CNT_LLAM_FACT    ,
          a.MIN_PLANTARIF    ,
          a.COD_UNIDAD       ,
          a.COD_OPERADOR
          FROM vm_fa_histconc_gdnc a, FA_CAMBIA_LLAVE_TO b
          WHERE a.ind_ordentotal	=b.ind_ordentotal
          	  and a.cod_concepto	=b.cod_concepto
          	  and a.columna		=b.columna
          	  and a.cod_tipconce	<=2
          	  and b.ind_ordentotal > 0;

   	COMMIT;

 	-- AJUSTES --

-- 	-- VERIFICA SI LOS MONTOS QUEDAN IGUALES --
-- 	-- ----->CONSULTA 41.1 <------ --
--   	nConsulta:=41.1;
--   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de los ajustes originales para determinar diferencias');
--
--   	SELECT sum(IMP_FACTURABLE),
--   	       sum(IMP_CONCEPTO)
--	INTO vImp_Facturable1,
--	     vImp_Concepto1
--   	FROM fa_ajusteconc;

   	-- ----->CONSULTA 42 <------ --
   	nConsulta:=42;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta los ajustes con las llaves nuevas');


  	INSERT INTO FA_AJUSTECONC_tmp
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
  	SELECT UNIQUE --jlizama
  	d.NUM_FOLIO     ,
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
  	c.DES_CONCEPTO     ,
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
  	FROM  VM_FA_AJUSTES_G a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c, VM_FA_HISTDOCU_G d
  	WHERE a.num_folio	= d.num_folio
	AND b.IND_ORDENTOTAL 	= d.Ind_ordentotal_F
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna
  	AND b.cod_concepto_new 	= c.cod_concepto
  	AND b.cod_tipconce 	> 2;

  commit;

   	-- ----->CONSULTA 43 <------ --
   	nConsulta:=43;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Elimina los ajustes para ser reemplazados por las llaves nuevas');


   	DELETE
   	FROM fa_ajusteconc x 
   	WHERE EXISTS (
		SELECT b.num_folio
		FROM vm_fa_histconc_gdnc a, vm_fa_histdocu_g b
		WHERE a.ind_ordentotal = b.ind_ordentotal_dnc
	  	AND b.num_folio =x.num_folio);

--   	COMMIT;
   	
 -- ----->CONSULTA 44 <------ --
   	
   	nConsulta:=44;
   	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Inserta los ajustes con las llaves nuevas en la tabla FA_AJUSTES');

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
  	FROM  FA_AJUSTECONC_TMP;
  
   	COMMIT;

-- -- ----->CONSULTA 45 <------ --
-- -- VERIFICA SI LOS MONTOS QUEDAN IGUALES EN FA_AJUSTES --
--
--   nConsulta:=45;
--   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de la FA_AJUSTES_TMP.');
--
--	SELECT	sum(IMP_FACTURABLE),
--		sum(IMP_CONCEPTO)        
--	INTO	vImp_Facturable2,
--		vImp_Concepto2
--	FROM FA_AJUSTECONC_tmp;
--

 -- ----->CONSULTA 50 <------ --
 -- VERIFICA SI LOS MONTOS QUEDAN IGUALES EN FA_HISTCONC_190010102 --
--
--   nConsulta:=50;
--   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de la FA_HISTCONC_19010102_TMP.');
--
--   SELECT sum(IMP_FACTURABLE) ,
--   	sum(IMP_CONCEPTO)
--   INTO vImp_Facturable2,
--	vImp_Concepto2
--   FROM fa_histconc_19010102_tmp;
--
--   nConsulta:=51;
--   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Rescata la sumatoria de las otras 3 tablas de detalle: F, G y GDNC.');
--
--   SELECT sum(IMP_FACTURABLE) ,
--   	sum(IMP_CONCEPTO)
--   INTO vImp_Facturable1,
--	vImp_Concepto1
--   FROM (
--   SELECT IMP_FACTURABLE, IMP_CONCEPTO
--   FROM VM_FA_HISTCONC_F
--   UNION ALL
--   SELECT IMP_FACTURABLE, IMP_CONCEPTO
--   FROM VM_FA_HISTCONC_G
--   UNION ALL
--   SELECT IMP_FACTURABLE, IMP_CONCEPTO
--   FROM VM_FA_HISTCONC_GDNC );
--
--   IF 	vImp_Facturable1 <> vImp_Facturable2 OR vImp_Concepto1 <> vImp_Concepto2 THEN
--	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 51.1, null, sysdate, sqlcode, 'Los Montos de la FA_HISTCONC_19010102 NO estan Cuadrados.');
--   	RAISE ERROR_1;
--   END IF;
--
--    FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 51.1, null, sysdate, sqlcode, 'Los Montos de la FA_HISTCONC_19010102 estan Cuadrados.');
-- 
--   -- ----->CONSULTA 43.2 <------ --
   
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 56, null, sysdate, sqlcode, 'ACTUALIZA DESCRIPCION CARGOS'); 
   
UPDATE FA_HISTCONC_19010102_TMP A
	     SET DES_CONCEPTO=(SELECT B.DES_CONCEPTO
	     FROM FA_ENTRADA_TO B
	     WHERE A.COD_CONCEPTO=B.CODIGO_DESTINO
	GROUP BY B.DES_CONCEPTO)
	WHERE A.COD_CONCEPTO=(SELECT C.CODIGO_DESTINO
	FROM FA_ENTRADA_TO C WHERE A.COD_CONCEPTO=C.CODIGO_DESTINO GROUP BY CODIGO_DESTINO);

commit;

	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 57, null, sysdate, sqlcode, 'ACTUALIZA DESCRIPCION DESCUENTOS'); 

UPDATE FA_HISTCONC_19010102_TMP A
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
   
EXCEPTION
   
 WHEN ERROR_1 THEN
 	     	FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
 	     	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Los Montos no corresponden en los ajustes');
 WHEN ERROR_2 THEN
 	     	FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
 	     	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, 'Los Montos no corresponden la tabla fa_histconc_19010102');
   
 WHEN OTHERS THEN
        	FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
        	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, nConsulta, null, sysdate, sqlcode, sqlerrm);
   
END;
/  

   -- ----->CONSULTA 52 <------ --
--    nConsulta:=52;
EXECUTE  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 52, null, sysdate, 0, 'Borra de la tabla FA_HISTCONC_19010102.');

	CREATE table tmp_ind_ordentotal as             
        select unique ind_ordentotal as null_ordentotal
        from FA_HISTCONC_19010102_tmp;                 
        
    -- ----->CONSULTA 55 <------ --
--    nConsulta:=55;

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 55, null, sysdate, 0, 'Inserta en la tabla FA_HISTCONC_19010102 el detalle de las notas de credito con la nueva.');
   
	create table FA_HISTCONC_19010102_diff as
	select
	IND_ORDENTOTAL   ,
	COD_CONCEPTO     ,
	COLUMNA          ,
	COD_MONEDA       ,
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
	COD_OPERADOR     
	from ( select *
	from FA_HISTCONC_19010102 c, tmp_ind_ordentotal f
	where c.ind_ordentotal > 0
	and c.ind_ordentotal = f.null_ordentotal (+) )
	where null_ordentotal is null;

EXIT;
