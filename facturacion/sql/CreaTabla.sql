whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

VARIABLE Tecnologia VARCHAR2(10);

--
-- Registra los ciclos que han sido procesados
--

DECLARE
	nExisteCiclo NUMBER;
BEGIN

	SELECT COUNT(1) INTO nExisteCiclo
	FROM FA_CICLOS_PROCESADOS_TO WHERE COD_CICLFACT = &&1;
	
	IF nExisteCiclo>0 THEN
		UPDATE FA_CICLOS_PROCESADOS_TO
		SET ESTADO='INICIADO',
		    FECHA_INICIO=SYSDATE
		WHERE COD_CICLFACT=&&1;
	ELSE
		INSERT INTO FA_CICLOS_PROCESADOS_TO (COD_CICLFACT, ESTADO, FECHA_INICIO, FECHA_TERMINO, DURACION)
		VALUES (&&1, 'INICIADO',SYSDATE, NULL, NULL);

	END IF;
	
	
END;
/

-- En este bloque se añaden las columnas faltantes para FA_HISTCONC_ciclo
-- esto se debe a que con el tiempo las tablas han cambiado su estructura y la finalidad es 
-- estandarizarlas para el proceso (solo se han contemplado modificar tipos de datos de las columnas)

/* ----->CONSULTA 1 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 1, null, sysdate, sqlcode, 'Cambia la estructura de la tabla FA_HISTCONC_<ciclo> para que sea uniforme dentro del proceso'); 


DECLARE
	 CURSOR Columnas IS
	 SELECT 
	   column_name, 
	   data_type, 
	   data_length, 
	   data_precision, 
	   data_scale, 
	   nullable 
	 FROM all_tab_cols 
	 WHERE table_name=(SELECT table_name 
	 			FROM all_tables 
	 			WHERE table_name LIKE 'FA_HISTCONC____05' AND rownum =1) 
	 AND column_name NOT IN (SELECT column_name 
	 			FROM all_tab_cols 
	 			WHERE table_name='FA_HISTCONC_&&1' );
	 
	 Cur_columnas COLUMNAS%ROWTYPE;
	 sSql         VARCHAR2(10000);
BEGIN
	 OPEN Columnas;
	 LOOP
	 	 FETCH Columnas INTO Cur_columnas;
		 EXIT WHEN Columnas%NOTFOUND;
		 
		 sSql:=' ALTER TABLE SISCEL.FA_HISTCONC_&&1 ADD (' || Cur_Columnas.column_name || ' ' || Cur_Columnas.data_type;
		 
		 IF Cur_Columnas.data_type='NUMBER' THEN
		 	sSql:=sSql || '(' || Cur_Columnas.data_precision || ',' || Cur_Columnas.data_scale || '))';
		 ELSIF Cur_Columnas.data_type='CHAR' OR Cur_Columnas.data_type='VARCHAR2' THEN
		 	sSql:=sSql || '(' || Cur_Columnas.data_length || '))';
		 END IF; 
		 dbms_output.put_line(sSql);
		 EXECUTE IMMEDIATE sSql;
	 END LOOP;
	 
	 CLOSE Columnas;
END;
/


COMMIT;

/* ----->CONSULTA 2 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 2, null, sysdate, sqlcode, 'Crea las estructuras de paso auxiliares donde va a dejar la llave nueva de los registros comprometidos'); 

CREATE TABLE FA_HISTCONC_&&1._AUX AS SELECT * FROM FA_HISTCONC_&&1 WHERE ROWNUM < 0;

/* ----->CONSULTA 3 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 3, null, sysdate, sqlcode, 'Crea el indice AK_FA_HISTCONC_&&1._PRODUCTO de la tabla FA_HISTCONC_&&1._AUX referenciando al campo COD_PRODUCTO'); 

CREATE INDEX AK_FA_HISTCONC_&&1._PRODUCTO ON FA_HISTCONC_&&1._AUX
(COD_PRODUCTO);

/* ----->CONSULTA 4 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 4, null, sysdate, sqlcode, 'Crea el indice PK_FA_HISTCONC&&1._AUX de la tabla FA_HISTCONC_&&1._AUX referenciando a los campos IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA'); 


CREATE UNIQUE INDEX PK_FA_HISTCONC&&1._AUX ON FA_HISTCONC_&&1._AUX (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA);

/* ----->CONSULTA 5 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 5, null, sysdate, sqlcode, 'Crea primary key PK_FA_HISTCONC&&1._AUX de la tabla FA_HISTCONC_&&1._AUX referenciando a los campos IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA'); 


ALTER TABLE FA_HISTCONC_&&1._AUX ADD (
  CONSTRAINT PK_FA_HISTCONC&&1._AUX PRIMARY KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA));


ALTER TABLE FA_HISTCONC_&&1._AUX ADD (
  CONSTRAINT FK_HCON_HISTDOCU_&&1._AUX FOREIGN KEY (IND_ORDENTOTAL) 
    REFERENCES SISCEL.FA_HISTDOCU (IND_ORDENTOTAL)
    ON DELETE CASCADE);
    
/* ----->CONSULTA 6 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 6, null, sysdate, sqlcode, 'Verifica si existe tabla tecnologia para el ciclo &&1'); 
--
--
--DECLARE
--                  sSql varchar2(10000);
--BEGIN  
--   	BEGIN
--   		SELECT DISTINCT 'EXISTE' 
--   		INTO :Tecnologia
--   		FROM all_tables WHERE table_name='FA_HISTECNO_TH_&&1';  
--   	EXCEPTION 
--   	WHEN OTHERS THEN
--   		:Tecnologia:='NO EXISTE';
--	END;
--   	
--   	IF :Tecnologia='EXISTE' THEN
--		  
--                  
--                  sSql:= 'CREATE TABLE FA_HISTECNO_TH_&&1._AUX(IND_ORDENTOTAL  NUMBER(12)  NOT NULL,'
--                    		||' COD_CONCEPTO    NUMBER(4)                     NOT NULL,'
--                    		||' COLUMNA         NUMBER(6)                     NOT NULL,'
--                    		||' COD_TECNOLOGIA  VARCHAR2(7)                   NOT NULL,'
--                    		||' PRC_TECNOLOGIA  NUMBER(5,2)                   NOT NULL	)';
--                  		
--                  EXECUTE IMMEDIATE sSql;	
--                  
--                  sSql:= 'CREATE UNIQUE INDEX PK_FAHISTEC_&&1._AUX ON FA_HISTECNO_TH_&&1._AUX (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA, COD_TECNOLOGIA)';	
--                  EXECUTE IMMEDIATE sSql;	
--                  
--                  sSql:= 'ALTER TABLE FA_HISTECNO_TH_&&1._AUX ADD ( CONSTRAINT PK_FAHISTEC_&&1._AUX PRIMARY KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA, COD_TECNOLOGIA))';	
--                  EXECUTE IMMEDIATE sSql;	
--                  
--                  sSql:= 'ALTER TABLE FA_HISTECNO_TH_&&1._AUX ADD ( CONSTRAINT FA_FACTCO_TEC_FK_&&1._AUX FOREIGN KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA) REFERENCES FA_HISTCONC_&&1._AUX (IND_ORDENTOTAL,COD_CONCEPTO,COLUMNA))';	
--                  EXECUTE IMMEDIATE sSql;	
--                  
--                  
--	END IF;
--
--END;	
--/    
    
-- C  

/* ----->CONSULTA 7 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 7, null, sysdate, sqlcode, 'Crea una vista previa para filtrar registros de la tabla FA_HISTDOCU para posteriores joins'); 

  
CREATE TABLE VM_FA_HISTDOCU_PRE_CICLO AS                                          
SELECT a.NUM_SECUENCI,                                    
  a.COD_TIPDOCUM    ,                                       
  a.COD_CLIENTE            ,                                
  a.IND_ORDENTOTAL ,
  A.NUM_FOLIO ,                               
  a.COD_CICLFACT           ,                                
  a.NUM_SECUREL            ,                                
  a.PREF_PLAZA       ,
  a.COD_TIPDOCUMREL  ,
  a.letra,
  a.COD_CENTREMI                                     
FROM fa_histdocu a
WHERE cod_ciclfact=&&1;                             


/* ----->CONSULTA 8 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 8, null, sysdate, sqlcode, 'Crea una indice llamado IND_FA_HISTDOCU_PRE, de la vista VM_FA_HISTDOCU_PRE_CICLO, referenciando al campo NUM_SECUENCI'); 

CREATE INDEX IND_FA_HISTDOCU_PRE_CICLO ON VM_FA_HISTDOCU_PRE_CICLO(NUM_SECUENCI);

/* ----->CONSULTA 9 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 9, null, sysdate, sqlcode, 'Crea la vista VM_FA_HISTDOCU donde se concetran las facturas con sus notas de credito del ciclo &&1'); 

                                                            
CREATE TABLE VM_FA_HISTDOCU AS                            
SELECT /*+  index (fa_histdocu IND_FA_HISTDOCU_SECUREL) */ a.NUM_SECUENCI,                                    
  a.COD_TIPDOCUM    ,                                       
  a.COD_CLIENTE            ,                                
  a.IND_ORDENTOTAL AS IND_ORDENTOTAL_F       , -- con este rescato el detalle de la factura en la tabla de ciclo respectiva
  A.NUM_FOLIO                                , -- con el folio de la factura se va a la tabla de ajustes (fa_ajusteconc)para ver los conceptos rebajados del documento
  b.IND_ORDENTOTAL AS IND_ORDENTOTAL_DNC     , -- con este camp obtengo el detalle de la nota de credito en la tabla (fa_histconc_19010102)
  a.COD_CICLFACT           ,                                
  a.NUM_SECUREL            ,                                
  a.PREF_PLAZA             ,
  b.COD_TIPDOCUMREL                                 
FROM VM_FA_HISTDOCU_PRE_CICLO a ,VM_FA_HISTDOCU_NCRED b -- a factura b nota de credito se rescata el num_folio
WHERE a.num_secuenci		= b.num_securel
	AND A.COD_CLIENTE 	= B.COD_CLIENTE   
	AND a.COD_TIPDOCUM	= b.COD_TIPDOCUMREL
	and a.LETRA		= b.LETRAREL
	aND a.COD_CENTREMI	= b.COD_CENTRREL ;
--	AND b.cod_ciclfact	= &&1;                             

/* ----->CONSULTA 10 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 10, null, sysdate, sqlcode, 'Crea el indice IND_FA_HISTDOCU1 de la vista VM_FA_HISTDOCU referenciando a los campos PREF_PLAZA, NUM_FOLIO'); 

	
/*--MODIFICACION BM SE AGREGO NUEVO INDICE COD_CLIENTE PARA FILTROS EN DELETE AJUSTECONC CONS 36--*/
CREATE INDEX IND_FA_HISTDOCU1 ON VM_FA_HISTDOCU (PREF_PLAZA, NUM_FOLIO, COD_CLIENTE); 

/* ----->CONSULTA 11 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 11, null, sysdate, sqlcode, 'Crea el indice IND_FA_HISTDOCU2 de la vista VM_FA_HISTDOCU referenciando al campo IND_ORDENTOTAL_F'); 


CREATE INDEX IND_FA_HISTDOCU2 ON VM_FA_HISTDOCU (IND_ORDENTOTAL_F) STORAGE(INITIAL 512M NEXT 128M);

/* ----->CONSULTA 12 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 12, null, sysdate, sqlcode, 'Crea el indice IND_FA_HISTDOCU3 de la vista VM_FA_HISTDOCU referenciando al campo IND_ORDENTOTAL_DNC'); 


CREATE INDEX IND_FA_HISTDOCU3 ON VM_FA_HISTDOCU (IND_ORDENTOTAL_DNC);
 

-- D

/* ----->CONSULTA 13 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 13, null, sysdate, sqlcode, 'Crea la vista VM_FA_AJUSTECONC donde se encuentran el detalle de las facturas que tienen nota de credito'); 


CREATE TABLE VM_FA_AJUSTECONC AS
SELECT      
  b.IND_ORDENTOTAL_DNC,   
  b.IND_ORDENTOTAL_F,                         
  a.NUM_FOLIO     ,                    
  a.COD_CLIENTE  ,                     
  a.COD_CONCEPTO  ,                    
  a.COD_MONEDA     ,                   
  a.COLUMNA         ,                  
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
  a.DES_CONCEPTO     ,                 
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
FROM fa_ajusteconc a, vm_fa_histdocu b 
WHERE a.PREF_PLAZA=b.PREF_PLAZA        
AND a.NUM_FOLIO=b.NUM_FOLIO
and a.cod_cliente=b.cod_cliente
and a.cod_tipdocum=b.cod_tipdocum;
                            

--E

--aqui se incluyen las Notas de credito que tengan o no tengan los codigos de origen para cambiar

/* ----->CONSULTA 14 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 14, null, sysdate, sqlcode, 'Crea la vista VM_FA_HISTCONC_DNOTAC donde se encuentran los registros en detalle de la nota de credito'); 

CREATE TABLE VM_FA_HISTCONC_DNOTAC (
  IND_ORDENTOTAL   NUMBER(12)     NOT NULL,
  --COD_CONCEPTO     NUMBER(4)      NOT NULL, AFGS - D-P-TMC-09031
  COD_CONCEPTO     NUMBER(9)      NOT NULL,
  COLUMNA          NUMBER(6)      DEFAULT 1                     NOT NULL,
  COD_MONEDA       VARCHAR2(3)    NOT NULL,
  COD_PRODUCTO     NUMBER(1)      NOT NULL,
  COD_TIPCONCE     NUMBER(2)      NOT NULL,
  FEC_VALOR        DATE           NOT NULL,
  FEC_EFECTIVIDAD  DATE           NOT NULL,
  IMP_CONCEPTO     NUMBER(14,4)   NOT NULL,
  COD_REGION       VARCHAR2(3)    NOT NULL,
  COD_PROVINCIA    VARCHAR2(5)    NOT NULL,
  COD_CIUDAD       VARCHAR2(5)    NOT NULL,
  IMP_MONTOBASE    NUMBER(14,4)   NOT NULL,
  IND_FACTUR       NUMBER(1)      NOT NULL,
  IMP_FACTURABLE   NUMBER(14,4)   NOT NULL,
  IND_SUPERTEL     NUMBER(1)      DEFAULT 0                     NOT NULL,
  NUM_ABONADO      NUMBER(8)      DEFAULT 0                     NOT NULL,
  COD_PORTADOR     NUMBER(5)      DEFAULT 0                     NOT NULL,
  DES_CONCEPTO     VARCHAR2(60)   NOT NULL,
  SEG_CONSUMIDO    NUMBER(9)      DEFAULT 0                     NOT NULL,
  NUM_CUOTAS       NUMBER(3),
  ORD_CUOTA        NUMBER(3),
  NUM_UNIDADES     NUMBER(6),
  NUM_SERIEMEC     VARCHAR2(25),
  NUM_SERIELE      VARCHAR2(25),
  PRC_IMPUESTO     NUMBER(11,6),
  VAL_DTO          NUMBER(14,4),
  TIP_DTO          NUMBER(1),
  MES_GARANTIA     NUMBER(2),
  NUM_GUIA         NUMBER(10),
  IND_ALTA         NUMBER(1),
  NUM_PAQUETE      NUMBER(3),
  FLAG_IMPUES      NUMBER(1),
  FLAG_DTO         NUMBER(1),
  COD_CONCEREL     NUMBER(4),
  COLUMNA_REL      NUMBER(6),
  SEQ_CUOTAS       NUMBER(8),
  COD_PLANTARIF    VARCHAR2(3),
  COD_CARGOBASICO  VARCHAR2(3),
  TIP_PLANTARIF    CHAR(1),
  IMP_DCTO         NUMBER(14,4)                 DEFAULT 0,
  IMP_REAL         NUMBER(14,4)                 DEFAULT 0,
  DUR_DCTO         NUMBER(9)                    DEFAULT 0,
  DUR_REAL         NUMBER(9)                    DEFAULT 0,
  CNT_LLAM_REAL    NUMBER(8),
  CNT_LLAM_DCTO    NUMBER(8),
  CNT_LLAM_FACT    NUMBER(8),
  MIN_PLANTARIF    NUMBER(6),
  COD_UNIDAD       VARCHAR2(5),
  COD_OPERADOR     NUMBER(5)
)
STORAGE    (INITIAL 512M NEXT    128M);

insert into VM_FA_HISTCONC_DNOTAC (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA, COD_MONEDA, COD_PRODUCTO, COD_TIPCONCE, FEC_VALOR, FEC_EFECTIVIDAD, IMP_CONCEPTO, COD_REGION, COD_PROVINCIA, COD_CIUDAD, IMP_MONTOBASE, IND_FACTUR, IMP_FACTURABLE, IND_SUPERTEL, NUM_ABONADO, COD_PORTADOR, DES_CONCEPTO, SEG_CONSUMIDO, NUM_CUOTAS, ORD_CUOTA, NUM_UNIDADES, NUM_SERIEMEC, NUM_SERIELE, PRC_IMPUESTO, VAL_DTO, TIP_DTO, MES_GARANTIA, NUM_GUIA, IND_ALTA, NUM_PAQUETE, FLAG_IMPUES, FLAG_DTO, COD_CONCEREL, COLUMNA_REL, SEQ_CUOTAS, COD_PLANTARIF, COD_CARGOBASICO, TIP_PLANTARIF, IMP_DCTO, IMP_REAL, DUR_DCTO, DUR_REAL, CNT_LLAM_REAL, CNT_LLAM_DCTO, CNT_LLAM_FACT, MIN_PLANTARIF, COD_UNIDAD, COD_OPERADOR)
SELECT B.IND_ORDENTOTAL, B.COD_CONCEPTO, B.COLUMNA, B.COD_MONEDA, B.COD_PRODUCTO, B.COD_TIPCONCE, B.FEC_VALOR, B.FEC_EFECTIVIDAD, B.IMP_CONCEPTO, B.COD_REGION, B.COD_PROVINCIA, B.COD_CIUDAD, B.IMP_MONTOBASE, B.IND_FACTUR, B.IMP_FACTURABLE, B.IND_SUPERTEL, B.NUM_ABONADO, B.COD_PORTADOR, B.DES_CONCEPTO, B.SEG_CONSUMIDO, B.NUM_CUOTAS, B.ORD_CUOTA, B.NUM_UNIDADES, B.NUM_SERIEMEC, B.NUM_SERIELE, B.PRC_IMPUESTO, B.VAL_DTO, B.TIP_DTO, B.MES_GARANTIA, B.NUM_GUIA, B.IND_ALTA, B.NUM_PAQUETE, B.FLAG_IMPUES, B.FLAG_DTO, B.COD_CONCEREL, B.COLUMNA_REL, B.SEQ_CUOTAS, B.COD_PLANTARIF, B.COD_CARGOBASICO, B.TIP_PLANTARIF, B.IMP_DCTO, B.IMP_REAL, B.DUR_DCTO, B.DUR_REAL, B.CNT_LLAM_REAL, B.CNT_LLAM_DCTO, B.CNT_LLAM_FACT, B.MIN_PLANTARIF, B.COD_UNIDAD, B.COD_OPERADOR
FROM fa_histconc_19010102 b, vm_fa_histdocu a  where b.ind_ordentotal= a.ind_ordentotal_dnc;

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 14.1, null, sysdate, sqlcode, 'Termino proceso creacion de tablas temporales'); 

exit 0;



