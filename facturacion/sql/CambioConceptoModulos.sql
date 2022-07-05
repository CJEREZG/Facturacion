WHENEVER sqlerror exit sql.sqlcode
WHENEVER oserror  exit oscode

--Variables para sumatorias en el bloque que trata la tabla FA_DETPASOCOBROS
--Variable antes del procesamiento
VARIABLE vg_SumImpDetPasAntes NUMBER;       

----Variable antes del procesamiento
VARIABLE vg_SumImpDetPasDespues NUMBER;       

/* ----->CONSULTA 100 <------ */

INSERT INTO FA_CICLOS_PROCESADOS_TO 
(
COD_CICLFACT, 
ESTADO, 
FECHA_INICIO, 
FECHA_TERMINO, 
DURACION
)
VALUES 
(
null, 
'INICIADO',
SYSDATE, 
NULL, 
NULL);

COMMIT;

--TRUNCATE TABLE SISCEL.FA_CAMBIA_LLAVE_TO;


/* ----->CONSULTA 101 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 101, null, sysdate, sqlcode, 'Creacion de la vista VM_'); 


CREATE TABLE VM_AL_ARTICULOS AS 
SELECT * FROM al_articulos a
WHERE A.COD_CONCEPTOART in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO)
	  OR A.COD_CONCEPTOARTALQ in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO); 

	  
/* ----->CONSULTA 102 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 102, null, sysdate, sqlcode, 'Actualizacion de los campos COD_CONCEPTOART y COD_CONCEPTODTO de la tabla AL_ARTICULOS'); 

	  
/*--------- PREPARA CONSULTA PARA COD_CONCEPTOART DE AL ARTICULOS---------------*/		
				
UPDATE	AL_ARTICULOS	A	
SET	COD_CONCEPTOART	=(SELECT DISTINCT CODIGO_DESTINO 
					  FROM FA_ENTRADA_TO B 
					  WHERE A.COD_CONCEPTOART=B.CODIGO_CONCEPTO)
WHERE A.COD_CONCEPTOART IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;

/*-------   PREPARA CONSULTA PARA COD_CONCEPTODTO DE AL ARTICULOS------------------*/

UPDATE	AL_ARTICULOS	A	
SET	COD_CONCEPTODTO	=(SELECT DISTINCT C.COD_CONCEPTO
			  FROM FA_ENTRADA_TO B, FA_CONCEPTOS C 
			  WHERE A.COD_CONCEPTOART=B.CODIGO_CONCEPTO
			  AND B.CODIGO_DESTINO=C.COD_CONCORIG)
WHERE A.COD_CONCEPTODTO  IN (SELECT COD_CONCEPTO 
			 	FROM FA_CONCEPTOS D, FA_ENTRADA_TO E
				WHERE A.COD_CONCEPTODTO=D.COD_CONCEPTO
				AND D.COD_CONCORIG=E.CODIGO_CONCEPTO);
				
COMMIT;

/* ----->CONSULTA 103 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 103, null, sysdate, sqlcode, 'Actualizacion de los campos COD_CONCEPTOARTALQ y COD_CONCEPTODTOALQ de la tabla AL_ARTICULOS'); 

/*--------- PREPARA CONSULTA PARA COD_CONCEPTOARTALQ  DE AL ARTICULOS---------------*/
UPDATE	AL_ARTICULOS	A	
SET	A.COD_CONCEPTOARTALQ=(SELECT DISTINCT CODIGO_DESTINO 
				  FROM FA_ENTRADA_TO B 
				  WHERE A.COD_CONCEPTOARTALQ=B.CODIGO_CONCEPTO)
WHERE A.COD_CONCEPTOARTALQ IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;

/*--------- PREPARA CONSULTA PARA COD_CONCEPTODTOALQ DE AL ARTICULOS---------------*/

UPDATE	AL_ARTICULOS  A	
SET	COD_CONCEPTODTOALQ = (SELECT DISTINCT C.COD_CONCEPTO
  		 		 FROM FA_ENTRADA_TO B, FA_CONCEPTOS C 
  				 WHERE A.COD_CONCEPTOARTALQ=B.CODIGO_CONCEPTO
  				 AND B.CODIGO_DESTINO=C.COD_CONCORIG)
WHERE COD_CONCEPTODTOALQ IN (SELECT COD_CONCEPTO 
 	 			FROM FA_CONCEPTOS D, FA_ENTRADA_TO E
				WHERE A.COD_CONCEPTODTOALQ=D.COD_CONCEPTO
				AND D.COD_CONCORIG=E.CODIGO_CONCEPTO);

COMMIT;

	  
/* ----->CONSULTA 104 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 104, null, sysdate, sqlcode, 'Creacion de la vista VM_AL_CARGOS'); 

	  
CREATE TABLE VM_AL_CARGOS AS 
SELECT * FROM AL_CARGOS A, FA_ENTRADA_TO B
WHERE A.COD_CONCEPTO =B.CODIGO_CONCEPTO 
OR A.COD_CONCEPTO_DTO =B.CODIGO_CONCEPTO;

/* ----->CONSULTA 105 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 105, null, sysdate, sqlcode, 'Actualiza los campos COD_CONCEPTO y COD_CONCEPTO_DTO de la tabla AL_CARGOS'); 



UPDATE	AL_CARGOS	A	
SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO 
			  FROM FA_ENTRADA_TO B 
			  WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO),
	COD_CONCEPTO_DTO=(SELECT DISTINCT COD_CONCEPTO 
			  FROM FA_CONCEPTOS B, FA_ENTRADA_TO C 
			  WHERE A.COD_CONCEPTO=C.CODIGO_CONCEPTO
			  		AND C.CODIGO_DESTINO	 =B.COD_CONCORIG)		  	
WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);



/* ----->CONSULTA 106 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 106, null, sysdate, sqlcode, 'Creacion de la vista VM_AL_PETIGUIAS_ABO'); 

	  
CREATE TABLE VM_AL_PETIGUIAS_ABO AS
SELECT * FROM AL_PETIGUIAS_ABO A
WHERE A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO from FA_ENTRADA_TO);


/* ----->CONSULTA 107 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 107, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla AL_PETIGUIAS_ABO'); 

UPDATE	AL_PETIGUIAS_ABO	A	
SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)	
WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;


--/* ----->CONSULTA 108 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 108, null, sysdate, sqlcode, ' Creacion de la vista VM_FAD_CONCEVAL'); 
--
--
--CREATE TABLE VM_FAD_CONCEVAL AS
--SELECT * FROM FAD_CONCEVAL A 
--WHERE A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 109 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 109, null, sysdate, sqlcode, ' Se eliminan los registros de la FAD_CONCEVAL dado a que se tienen que agrupar '); 
--
--
--
--DELETE FROM fad_conceval a WHERE 
--EXISTS (SELECT cod_grupo, cod_concepto, fec_desde 
--	   FROM vm_fad_conceval b 
--	   WHERE b.cod_grupo=a.cod_grupo
--	   		 AND b.cod_concepto=a.cod_concepto
--			 AND b.fec_desde=a.fec_desde );
--
--commit;			 
--
--/* ----->CONSULTA 110 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 110, null, sysdate, sqlcode, ' Inserta los registros agrupados a partir de la vista VM_FAD_CONCEVAL'); 
--
--
--INSERT INTO fad_conceval
-- (COD_GRUPO     ,
--  COD_CONCEPTO ,
--  FEC_DESDE    ,
--  FEC_HASTA    ,
--  IND_OBLIGA   ,
--  MTO_MINFACT  ,
--  FEC_ULTMOD   ,
--  NOM_USUARIO)
--SELECT cod_grupo, 
--	   CODIGO_DESTINO, 
--	   min(fec_desde), 
--	   max(fec_hasta), 
--	   max(ind_obliga), 
--	   max(mto_minfact), 
--	   max(fec_ultmod), 
--	   min(nom_usuario) 
--FROM vm_fad_conceval a, FA_ENTRADA_TO b
--WHERE a.cod_concepto=b.CODIGO_CONCEPTO
--GROUP BY cod_grupo, b.CODIGO_DESTINO;
--
-- 
--commit;
--
--
--/* ----->CONSULTA 111 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 111, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_FAD_CONCAPLI'); 
--
--CREATE TABLE VM_FAD_CONCAPLI AS
--SELECT * FROM FAD_CONCAPLI A
--WHERE A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--
--
--/* ----->CONSULTA 112 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 112, null, sysdate, sqlcode, 'Se eliminan los registros de la FAD_CONCAPLI dado a que se tienen que agrupar '); 
--
--DELETE FROM fad_concapli a WHERE 
--EXISTS (SELECT cod_grupo
--	   FROM vm_fad_concapli b 
--	   WHERE b.cod_grupo		= a.cod_grupo
--	   	AND b.cod_concepto	= a.cod_concepto
--		AND b.fec_desde		= a.fec_desde );
--COMMIT;
--
--
--/* ----->CONSULTA 113 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 113, null, sysdate, sqlcode, 'Se insertan los registros en forma a grupada a partir de la vista VM_FAD_CONCAPLI '); 
--
--
--INSERT INTO FAD_CONCAPLI
-- (COD_GRUPO     ,
--  COD_CONCEPTO ,
--  FEC_DESDE    ,
--  FEC_HASTA    ,
--  COD_CONREL   ,
--  FEC_ULTMOD   ,
--  NOM_USUARIO)
--SELECT cod_grupo, 
--	   CODIGO_DESTINO, 
--	   MIN(fec_desde), 
--	   MAX(fec_hasta), 
--	   (SELECT cod_concepto FROM fa_conceptos b WHERE cod_concorig=b.CODIGO_DESTINO ),
--	   MAX(fec_ultmod), 
--	   MIN(nom_usuario) 
--FROM vm_fad_concapli a, FA_ENTRADA_TO b
--WHERE a.cod_concepto=b.CODIGO_CONCEPTO
--GROUP BY cod_grupo, CODIGO_DESTINO; 
--
--COMMIT;
--
--
--/* ----->CONSULTA 114 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 114, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_FAD_DETPLANDESC'); 
--
--
--CREATE TABLE VM_FAD_DETPLANDESC	 AS
--SELECT *
--from FAD_DETPLANDESC	a
--WHERE	A.COD_CONCDESC IN (select cod_concepto 
--from (select cod_concepto, cod_concorig from fa_conceptos ) b
--where b.cod_concorig in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO));

/* ----->CONSULTA 115 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 115, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCDESC de la tabla FAD_DETPLANDESC'); 
--
--UPDATE	FAD_DETPLANDESC	A	
--SET	COD_CONCDESC	=(SELECT DISTINCT cod_concepto FROM fa_conceptos WHERE cod_concorig=(
--							 SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO B, FA_CONCEPTOS C 
--							 WHERE A.COD_CONCDESC=C.COD_CONCEPTO
--							 AND C.COD_CONCORIG=B.CODIGO_CONCEPTO))	
--WHERE	A.COD_CONCDESC IN (SELECT cod_concepto 
--FROM (SELECT cod_concepto, cod_concorig FROM fa_conceptos ) b
--WHERE b.cod_concorig IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO));
--
--COMMIT;


/* Modificacion Jorge Lizama, Mauricio Villagra*/
/* CONSULTA 116 */
/* ----->CONSULTA 117 <------ */ 
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 117, null, sysdate, sqlcode, 'Creando tabla temporal VM_FA_DETPASOCOBROS ...');

CREATE TABLE VM_FA_DETPASOCOBROS AS
select * 
from fa_detpasocobros
where cod_concepto in ( select codigo_concepto
			from fa_entrada_to
			union all
			select c.cod_concepto
			from fa_conceptos c, fa_entrada_to e
			where c.cod_concorig = e.codigo_concepto);

/* ----->CONSULTA 117.1 <------ */ 
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 117.1, null, sysdate, sqlcode, 'Obteniendo Sumatoria en FA_DETPASOCBROS');

DECLARE
	numSumImpDetPas NUMBER;
	numSumImpDetPres  NUMBER;
BEGIN
	select sum(imp_concepto)
	into numSumImpDetPas
	from vm_fa_detpasocobros;
	
	
	/* ----->CONSULTA 117.2 <------ */ 
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 117.2, null, sysdate, sqlcode, 'Valida que los montos no hayan variado'); 

	select sum(imp_concepto)
	into numSumImpDetPres
	from 
		(select 
			COD_OPERADORA_SCL, 
			COD_PLAZA, 
			NUM_PROCPASOCOBRO, 
			COD_TIPDOCUM, 
			CODIGO_DESTINO, 
			PER_CONTABLE, 
			COD_CATEGORIA, 
			COD_TIPCOMIS, 
			COD_TECNOLOGIA, 
			sum(imp_concepto) imp_concepto
		from vm_fa_detpasocobros d, fa_entrada_to e
		where d.cod_concepto = e.codigo_concepto
		group by COD_OPERADORA_SCL, COD_PLAZA, NUM_PROCPASOCOBRO, COD_TIPDOCUM, 
		CODIGO_DESTINO, PER_CONTABLE, COD_CATEGORIA, COD_TIPCOMIS, COD_TECNOLOGIA
		UNION ALL
		select 
			COD_OPERADORA_SCL, 
			COD_PLAZA, 
			NUM_PROCPASOCOBRO, 
			COD_TIPDOCUM, 
			k.COD_concepto, 
			PER_CONTABLE, 
			COD_CATEGORIA, 
			COD_TIPCOMIS, 
			COD_TECNOLOGIA, 
			sum(imp_concepto) imp_concepto
		from vm_fa_detpasocobros d, fa_conceptos c, fa_entrada_to e, fa_conceptos k
		where d.cod_concepto = c.cod_concepto
		and c.cod_concorig = e.codigo_concepto
		and e.codigo_destino = k.cod_concorig
		group by COD_OPERADORA_SCL, COD_PLAZA, NUM_PROCPASOCOBRO, COD_TIPDOCUM, 
		k.COD_concepto, PER_CONTABLE, COD_CATEGORIA, COD_TIPCOMIS, COD_TECNOLOGIA);
				
		IF numSumImpDetPas <> numSumImpDetPres THEN
			FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 117.2, null, sysdate, sqlcode, 'No cuadran los montos en FA_DETPASOCOBROS, no se procesara'); 	
		ELSE
			FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 117.2, null, sysdate, sqlcode, 'Montos cuadrados correctamente en FA_DETPASOCOBROS'); 	
			
			
			/* ----->CONSULTA 118 <------ */ 

			FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 118, null, sysdate, sqlcode, 'Elimina los registros de conceptos FA_DETPASOCOBROS'); 
			
			DELETE 
			FROM fa_detpasocobros 
			WHERE cod_concepto IN ( 
			SELECT UNIQUE cod_concepto 
			FROM VM_FA_DETPASOCOBROS );
			
			COMMIT;
			
			/* ----->CONSULTA 119 <------ */ 
			
			FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 119, null, sysdate, sqlcode, 'Valida que los montos no hayan variado'); 
			
			insert into fa_detpasocobros (
				COD_OPERADORA_SCL, 
				COD_PLAZA, 
				NUM_PROCPASOCOBRO, 
				COD_TIPDOCUM, 
				COD_CONCEPTO, 
				PER_CONTABLE, 
				COD_CATEGORIA, 
				COD_TIPCOMIS, 
				COD_TECNOLOGIA, 
				imp_concepto)
			select 
				COD_OPERADORA_SCL, 
				COD_PLAZA, 
				NUM_PROCPASOCOBRO, 
				COD_TIPDOCUM, 
				CODIGO_DESTINO, 
				PER_CONTABLE, 
				COD_CATEGORIA, 
				COD_TIPCOMIS, 
				COD_TECNOLOGIA, 
			sum(imp_concepto) imp_concepto
			from vm_fa_detpasocobros d, fa_entrada_to e
			where d.cod_concepto = e.codigo_concepto
			group by COD_OPERADORA_SCL, COD_PLAZA, NUM_PROCPASOCOBRO, 
				COD_TIPDOCUM, CODIGO_DESTINO, PER_CONTABLE, 
				COD_CATEGORIA, COD_TIPCOMIS, COD_TECNOLOGIA
			UNION ALL
			select 
				COD_OPERADORA_SCL, 
				COD_PLAZA, 
				NUM_PROCPASOCOBRO, 
				COD_TIPDOCUM, 
				k.COD_concepto, 
				PER_CONTABLE, 
				COD_CATEGORIA, 
				COD_TIPCOMIS, 
				COD_TECNOLOGIA, 
				sum(imp_concepto) imp_concepto
			from vm_fa_detpasocobros d, fa_conceptos c, 
				fa_entrada_to e, fa_conceptos k
			where d.cod_concepto = c.cod_concepto
				and c.cod_concorig = e.codigo_concepto
				and e.codigo_destino = k.cod_concorig
			group by COD_OPERADORA_SCL, COD_PLAZA, 
				NUM_PROCPASOCOBRO, COD_TIPDOCUM, 
				k.COD_concepto, PER_CONTABLE, 
				COD_CATEGORIA, COD_TIPCOMIS, 
				COD_TECNOLOGIA;
		END IF;
		
END;
/
commit;
/

/* ----->CONSULTA 120 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 120, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_FA_NCPARCIAL'); 

CREATE TABLE VM_FA_NCPARCIAL AS
SELECT * FROM FA_NCPARCIAL a
WHERE EXISTS  (SELECT num_secuencia 
 	   		  FROM fa_ncparcial b 
			  WHERE a.num_secuencia		=b.num_secuencia
 	   		  	AND a.cod_cliente 	=b.cod_cliente
				AND a.ind_ordentotal	=b.ind_ordentotal 
				AND b.cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO ));

/* ----->CONSULTA 121 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 121, null, sysdate, sqlcode, 'Crea indice llamado I2 con los campos NUM_SECUENCIA, IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA de la vista VM_FA_NCPARCIAL'); 



CREATE INDEX I2 ON VM_FA_NCPARCIAL( 
NUM_SECUENCIA,
IND_ORDENTOTAL,
COD_CONCEPTO,
COLUMNA
 );


/* ----->CONSULTA 122 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 122, null, sysdate, sqlcode, 'Elimina los registos de la tabla FA_NCPARCIAL para ser reemplazados por los nuevos'); 



DELETE FROM FA_NCPARCIAL a
WHERE EXISTS  (SELECT num_secuencia 
 	   		  FROM vm_fa_ncparcial b 
			  WHERE a.num_secuencia		=b.num_secuencia
 	   		  	AND a.cod_cliente 	=b.cod_cliente
				AND a.ind_ordentotal	=b.ind_ordentotal 
				AND b.cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO ));
				
commit;				

/* ----->CONSULTA 123 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 123, null, sysdate, sqlcode, 'Elimina los registos de la tabla FA_NCPARCIAL para ser reemplazados por los nuevos'); 


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

BEGIN


   	EXECUTE IMMEDIATE 'SELECT DISTINCT num_secuencia FROM vm_fa_ncparcial '
   	|| ' WHERE Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '   	
	BULK COLLECT INTO IndOrdenTotal;
	

   	IF IndOrdenTotal.COUNT >0 THEN
   			
            FOR i in 1..Indordentotal.count LOOP
                    
                SELECT DISTINCT cod_concepto_new
				BULK COLLECT INTO Col_codconcepto_new
				FROM                       
                    		(SELECT 
                    		DISTINCT cod_concepto_new
                    		FROM ( SELECT
					  num_secuencia,
					  cod_cliente, 
                    	   		  ind_ordentotal, 
                    			  cod_concepto, 
                    			  columna, 
                    			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
                    			FROM vm_fa_ncparcial a, 		FA_ENTRADA_TO b 
                    	   		WHERE num_secuencia	= Indordentotal(i) 
                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)));			 
                    				  
                    		/* ----->CONSULTA 23 <------ */   		  
                    		
                    		sSql:='INSERT INTO fa_ncparcial '
                    	  	||'(num_secuencia,    '
                    	  	||'  cod_cliente ,     '
                    	  	||'  ind_ordentotal       ,    '
                      	  	||'	cod_tipdocum   ,   '
                      	  	||'	cod_concepto     ,  '
                      	  	||'	columna     , '
                      	  	||'	imp_concepto  ,'
                      	  	||'	flg_eminc,'
			  	||'	fec_solicitud,'
				||' nom_usuario,'
				||' num_proceso, '
				||' cod_origen) '
				||' SELECT '
 				||' num_secuencia,' 
				||' cod_cliente, '
				||' ind_ordentotal, ' 
				||' cod_tipdocum, '
				||' CODIGO_DESTINO, '
				||' rownum columna, ' 
				||' imp_concepto, ' 
				||' flg_eminc, '
				||' fec_solicitud, ' 
				||' nom_usuario, '
				||' num_proceso, ' 
				||' cod_origen '
				||' FROM vm_fa_ncparcial a, FA_ENTRADA_TO b '
				||' WHERE a.cod_concepto=b.CODIGO_CONCEPTO AND num_secuencia=' || Indordentotal(i)  || ' AND CODIGO_DESTINO=:CODDEST ';
                    	   
                    	  
                    	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last 
                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);
                    	  
        			
	       END LOOP;
   			
	 
   	END IF;	


END;				
/

INSERT INTO FA_NCPARCIAL
(
  NUM_SECUENCIA   ,
  COD_CLIENTE     ,
  IND_ORDENTOTAL  ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  IMP_CONCEPTO    ,
  FLG_EMINC       ,
  FEC_SOLICITUD   ,
  NOM_USUARIO     ,
  NUM_PROCESO     ,
  COD_ORIGEN      
)
SELECT 
NUM_SECUENCIA   ,
  COD_CLIENTE     ,
  IND_ORDENTOTAL  ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  IMP_CONCEPTO    ,
  FLG_EMINC       ,
  FEC_SOLICITUD   ,
  NOM_USUARIO     ,
  NUM_PROCESO     ,
  COD_ORIGEN
FROM VM_FA_NCPARCIAL a
WHERE cod_concepto NOT IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;

/* ----->CONSULTA 124 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 124, null, sysdate, sqlcode, 'consulta eliminada VM_FAD_CTLINFCONC'); 

		
/* ----->CONSULTA 125 <------ */   


/* ----->CONSULTA 126 N/APLICA no se ocuoa<------ */   


/* ----->CONSULTA 140 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 140, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_GA_ACTUASERV'); 



CREATE TABLE VM_GA_ACTUASERV AS
SELECT * FROM GA_ACTUASERV 
WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);


/* ----->CONSULTA 141 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 141, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla  GA_ACTUASERV'); 


UPDATE	GA_ACTUASERV	A	
SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)	
WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;

/* ----->CONSULTA 142 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 142, null, sysdate, sqlcode, 'Crea la vista de respaldo llamada VM_GA_AUTORIZA'); 



CREATE TABLE VM_GA_AUTORIZA AS
SELECT * FROM 	GA_AUTORIZA WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);


/* ----->CONSULTA 143 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 143, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla GA_AUTORIZA'); 


UPDATE	GA_AUTORIZA	A	
SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)	
WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;

/* ----->CONSULTA 144 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 144, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_GA_CARGOS_RECHAZADOS'); 

--CREATE TABLE VM_GA_CARGOS_RECHAZADOS AS
--SELECT * FROM GA_CARGOS_RECHAZADOS WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 145 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 145, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla GA_CARGOS_RECHAZADOS'); 
--
--
--
--UPDATE	GA_CARGOS_RECHAZADOS	A	
--SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)	
--WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--COMMIT;
--
--UPDATE GA_CARGOS_RECHAZADOS	A	
--SET	COD_CONCEPTO_DTO	=(SELECT DISTINCT COD_CONCEPTO FROM FA_CONCEPTOS B WHERE A.COD_CONCEPTO=B.COD_CONCORIG)	
--WHERE	A.COD_CONCEPTO_DTO IS NOT NULL
--		AND A.COD_CONCEPTO IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);
--
--
--COMMIT;
--


/* ----->CONSULTA 146 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 146, null, sysdate, sqlcode, 'Consulta eliminada de  VM_GA_DET_PRELIQ'); 



/* ----->CONSULTA 147 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 147, null, sysdate, sqlcode, 'Consulta eliminada GA_DET_PRELIQ'); 


/* ----->CONSULTA 148 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 148, null, sysdate, sqlcode, 'Crea la vista de respaldo GA_HSERVSUPLABO'); 


--CREATE TABLE VM_GA_HSERVSUPLABO AS
--SELECT * FROM 	GA_HSERVSUPLABO WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 149 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 149, null, sysdate, sqlcode, 'Actualiza el campo COD_FACTURACION de la tabla GA_HSERVSUPLABO'); 
--
--
--UPDATE	GA_HSERVSUPLABO 	A	
--SET	COD_CONCEPTO	=	(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)		
--WHERE   A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--COMMIT;

/* ----->CONSULTA 150 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 150, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_GA_SERVSUPLABO'); 
--
--
--CREATE TABLE VM_GA_SERVSUPLABO AS
--SELECT *  FROM GA_SERVSUPLABO WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 151 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 151, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla GA_SERVSUPLABO '); 
--
--
--
--UPDATE GA_SERVSUPLABO 	A	
--SET COD_CONCEPTO=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)		
--WHERE   A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--COMMIT;

/* ----->CONSULTA 152 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 152, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_GE_CARGOS'); 


CREATE TABLE VM_GE_CARGOS AS
SELECT * FROM GE_CARGOS WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);


/* ----->CONSULTA 153 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 153, null, sysdate, sqlcode, 'Actualiza los campos COD_CONCEPTO y COD_CONCEPTO_DTO de la tabla GE_CARGOS'); 


UPDATE	GE_CARGOS	A	
SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO 
			  FROM FA_ENTRADA_TO B 
			  WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO),
	COD_CONCEPTO_DTO	=(SELECT DISTINCT COD_CONCEPTO 
			  FROM FA_CONCEPTOS B, FA_ENTRADA_TO C 
			  WHERE A.COD_CONCEPTO	    = C.CODIGO_CONCEPTO
			  	AND C.CODIGO_DESTINO = B.COD_CONCORIG)		  	
WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);

COMMIT;


/* ----->CONSULTA 154 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 154, null, sysdate, sqlcode, 'Crea la tabla de respaldo VM_RE_FACTURA_DETALLE_TO'); 
--
--
--CREATE TABLE VM_RE_FACTURA_DETALLE_TO AS
--SELECT * FROM RE_FACTURA_DETALLE_TO a 
--	   WHERE EXISTS (SELECT num_reclamo FROM RE_FACTURA_DETALLE_TO b
--	   		 		WHERE a.num_reclamo		= b.num_reclamo
--						  AND a.tip_categoria	= b.tip_categoria
--						  AND a.ind_ordentotal	= b.ind_ordentotal
--						  AND b.cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO));
						  

/* ----->CONSULTA 155 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 155, null, sysdate, sqlcode, 'Elimina los registros para su posterior reemplazo de la tabla RE_FACTURA_DETALLE_TO'); 
--
--						  
--DELETE FROM RE_FACTURA_DETALLE_TO a 
--	   WHERE EXISTS (SELECT num_reclamo FROM RE_FACTURA_DETALLE_TO b
--	   		 		WHERE a.num_reclamo		= b.num_reclamo
--						  AND a.tip_categoria	= b.tip_categoria
--						  AND a.ind_ordentotal	= b.ind_ordentotal
--						  AND b.cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO));
--				
--commit;	

--TRUNCATE TABLE SISCEL.FA_CAMBIA_LLAVE_TO;			

/* ----->CONSULTA 156 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 156, null, sysdate, sqlcode, 'Bloque de codigo que permite insertar los nuevos conceptos en la tabla RE_FACTURA_DETALLE_TO'); 
--
--
--DECLARE
--
--   TYPE ind_orden IS TABLE OF number INDEX BY BINARY_INTEGER;
--  Arreglo  	ind_orden;
--  
--  TYPE tCol_Codest IS TABLE OF Varchar2(4) INDEX BY BINARY_INTEGER;
--  ColCodigosDestino 	tCol_Codest;
--  Col_codconcepto_new	tCol_Codest;
--  
-- 
--  Tecnologia 		Varchar2(10);
--  sSql 			Varchar2(32767);
--  
--  i 			NUMBER;
--  k			NUMBER;
--  nConsulta 		NUMBER;
--
--BEGIN
--
--
--   	EXECUTE IMMEDIATE 'SELECT DISTINCT num_reclamo FROM VM_RE_FACTURA_DETALLE_TO '
--   	|| ' WHERE Cod_Concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO) '   	
--	BULK COLLECT INTO Arreglo;
--	
--
--   	IF Arreglo.COUNT >0 THEN
--   			
--            FOR i in 1..Arreglo.count LOOP
--                    
--                SELECT DISTINCT cod_concepto_new
--				BULK COLLECT INTO Col_codconcepto_new
--				FROM                       
--                    		(SELECT 
--                    		DISTINCT cod_concepto_new
--                    		FROM ( SELECT
--					  num_reclamo,
--					  tip_categoria, 
--                    	   		  ind_ordentotal, 
--                    			  cod_concepto, 
--                    			  columna, 
--                    			  nvl(CODIGO_DESTINO, cod_concepto) cod_concepto_new
--                    			FROM VM_RE_FACTURA_DETALLE_TO a, 		FA_ENTRADA_TO b 
--                    	   		WHERE num_reclamo	= Arreglo(i) 
--                    			  AND a.cod_concepto	= b.CODIGO_CONCEPTO(+)));			 
--                    				  
--                    		/* ----->CONSULTA 23 <------ */   		  
--                    		
--                    		sSql:='INSERT INTO RE_FACTURA_DETALLE_TO '
--                    	  	||'(    num_reclamo	,'
--                    	  	||'     tip_categoria 	,'
--                    	  	||'     ind_ordentotal  ,'
--                      	  	||'	cod_concepto    ,'
--                      	  	||'	columna         ,'
--                      	  	||'	mto_reclamado   ,'
--                      	  	||'	mto_operadora ) '
--				||' SELECT 		'
-- 				||' num_reclamo,	' 
--				||' tip_categoria, 	'
--				||' ind_ordentotal, 	'	 
--				||' CODIGO_DESTINO, 	'
--				||' rownum columna, 	' 
--				||' mto_reclamado, 	' 
--				||' mto_operadora 	'
--				||' FROM VM_RE_FACTURA_DETALLE_TO a, FA_ENTRADA_TO b '
--				||' WHERE a.cod_concepto=b.CODIGO_CONCEPTO AND num_reclamo =' || Arreglo(i)  || ' AND CODIGO_DESTINO=:CODDEST ';
--                    	   
--                    	  	
--                    	  	
--                    	  	
--                    	  	FORALL idx in Col_codconcepto_new.first..Col_codconcepto_new.last 
--                    	  		 EXECUTE IMMEDIATE sSql USING IN Col_codconcepto_new(idx);
--                    	  
--        			
--	       END LOOP;
--   			
--	 
--   	END IF;	
--
--
--END;				
--/
--
--COMMIT;


--INSERT INTO RE_FACTURA_DETALLE_TO
--( NUM_RECLAMO     ,
--  TIP_CATEGORIA   ,
--  IND_ORDENTOTAL  ,
--  COD_CONCEPTO    ,
--  COLUMNA         ,
--  MTO_RECLAMADO   ,
--  MTO_OPERADORA   
--) 
--SELECT
--  NUM_RECLAMO     ,
--  TIP_CATEGORIA   ,
--  IND_ORDENTOTAL  ,
--  COD_CONCEPTO    ,
--  COLUMNA         ,
--  MTO_RECLAMADO   ,
--  MTO_OPERADORA   
--FROM  VM_RE_FACTURA_DETALLE_TO
--WHERE cod_concepto NOT IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--COMMIT;

/* ----->CONSULTA 157 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 157, null, sysdate, sqlcode, 'Crea la vista de respaldo SP_AVERIAS'); 
						  
						  
--CREATE TABLE VM_SP_AVERIAS AS
--SELECT * FROM SP_AVERIAS WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--
--/* ----->CONSULTA 158 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 158, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO y COD_CONCEPDTO de la tabla SP_AVERIAS'); 
--
--
--UPDATE	SP_AVERIAS	A	
--SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO 
--			  FROM FA_ENTRADA_TO B 
--			  WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO),
--	COD_CONCEPDTO	=(SELECT DISTINCT COD_CONCEPTO 
--			  FROM FA_CONCEPTOS B, FA_ENTRADA_TO C 
--			  WHERE A.COD_CONCEPTO=C.CODIGO_CONCEPTO
--			  		AND C.CODIGO_DESTINO	 =B.COD_CONCORIG)		  	
--WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--COMMIT;


/* ----->CONSULTA 159 <------ */   

--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 159, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_SP_AVERIAS_CARGOCTA'); 
--
--
--
--CREATE TABLE VM_SP_AVERIAS_CARGOCTA AS
--SELECT * FROM 	SP_AVERIAS_CARGOCTA WHERE cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 160 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 160, null, sysdate, sqlcode, 'Actualiza el campo COD_CONCEPTO de la tabla SP_AVERIAS_CARGOCTA'); 
--
--
--UPDATE	SP_AVERIAS_CARGOCTA	A	
--SET	COD_CONCEPTO	=(SELECT DISTINCT CODIGO_DESTINO FROM FA_ENTRADA_TO B WHERE A.COD_CONCEPTO=B.CODIGO_CONCEPTO)	
--WHERE	A.COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--
--COMMIT;


/* ----->CONSULTA 161 <------ */   

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 161, null, sysdate, sqlcode, 'Crea la vista de respaldo VM_TA_CONCEPFACT'); 


--CREATE TABLE VM_TA_CONCEPFACT AS
--SELECT * FROM 	TA_CONCEPFACT WHERE cod_facturacion IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--/* ----->CONSULTA 162 <------ */   
--
--EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 162, null, sysdate, sqlcode, 'Elimina los registros que tienen codigos de conceptos a cambiar de la tabla TA_CONCEPFACT'); 
--
--
--DELETE FROM 	TA_CONCEPFACT WHERE cod_facturacion IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
--
--								
--COMMIT;

/*---------------PROCEDIMIENTO QUE ELIMINA DE CONCEPTOS EN FA_CONCEPTOS------*/

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 168.01, null, sysdate, sqlcode, 'Creacion de la TABLA VM_FA_CONCEPTOS');

CREATE TABLE VM_FA_CONCEPTOS AS
SELECT * FROM FA_CONCEPTOS;

DECLARE                                                                                                                                                                                                                                         

BEGIN   
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 168.1, null, sysdate, sqlcode, 'ACTUALIZANDO PARAMETROS GA_DATOSGENER'); 
		
	UPDATE GA_DATOSGENER
	SET COD_CNIVEQTRUNK=144, COD_CNIVEQTREK=150,
	    COD_CDEDTRUNK=144, COD_CDEDTREK=150,
	    COD_CTRASTRUNK=144, COD_CTRASTREK=150;
	
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
         	
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 168.2, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_ARRIENDO'); 
	
	DELETE FROM FA_ARRIENDO
	WHERE COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
                                                                                                                                                                                                                                 
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	
	
	--bdo
	DELETE FROM FA_ARRIENDO
	WHERE COD_CONCEPTO IN
	(SELECT c.COD_CONCEPTO 
		FROM FA_ENTRADA_TO E, fa_conceptos c
		WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
		and c.cod_concorig = e.codigo_concepto);
	
	
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;	
	
	                                                                                                                                                                                                                                 
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 168.3, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FAD_IMPCONCEPTOS'); 
	
	DELETE FROM FAD_IMPCONCEPTOS
	WHERE COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
                                                                                                                                                                                                                                 
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                           
	
	---bdo
	DELETE FROM FAD_IMPCONCEPTOS
	WHERE COD_CONCEPTO IN 
	(SELECT c.COD_CONCEPTO 
		FROM FA_ENTRADA_TO E, fa_conceptos c
		WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
		and c.cod_concorig = e.codigo_concepto);
		
                                                                                                                                                                                                                                 
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	
	
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 169, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_FACTCOBR'); 
	
	DELETE FROM FA_FACTCOBR
	WHERE COD_CONCFACT IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
                                                                                                                                                                                                                                 
	DELETE FROM FA_FACTCOBR
	WHERE COD_CONCFACT IN 
	(SELECT c.COD_CONCEPTO 
		FROM FA_ENTRADA_TO E, fa_conceptos c
		WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
		and c.cod_concorig = e.codigo_concepto);
				
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

                                                                                                                                                                                                                            
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 170, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_FACTCOBR'); 
	
	DELETE FROM FA_GRPSERCONC
	WHERE COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
	                                                                                                                                                                                                                         
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	DELETE FROM FA_GRPSERCONC
	WHERE COD_CONCEPTO IN 
	(SELECT c.COD_CONCEPTO 
				FROM FA_ENTRADA_TO E, fa_conceptos c
				WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
				and c.cod_concorig = e.codigo_concepto);
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	                                                                                                                                                                                                                         
        
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 171, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_GRUPOCOB '); 
	
	DELETE FROM FA_GRUPOCOB
	WHERE COD_CONCEPTO IN 
	(SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
                                                                                                                                                                                                                                 
       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
        
	DELETE FROM FA_GRUPOCOB
	WHERE COD_CONCEPTO IN 
	(SELECT c.COD_CONCEPTO 
				FROM FA_ENTRADA_TO E, fa_conceptos c
				WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
				and c.cod_concorig = e.codigo_concepto);
                                                                                                                                                                                                                                 
       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 172, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_IMP_GRUPOTOT  '); 
	
	DELETE FROM FA_IMP_GRUPOTOT
	WHERE COD_CONCEPTO IN 
	(SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);
	
       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	DELETE FROM FA_IMP_GRUPOTOT
	WHERE COD_CONCEPTO IN 
	(SELECT c.COD_CONCEPTO 
				FROM FA_ENTRADA_TO E, fa_conceptos c
				WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
				and c.cod_concorig = e.codigo_concepto);
	
       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
        
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 173, null, sysdate, sqlcode, 'Eliminaci¢n de concepto en FA_IMPCONCEPTOS');

	DELETE FROM FA_IMPCONCEPTOS
	WHERE COD_CONCEPTO IN 
	(SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);

       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	DELETE FROM FA_IMPCONCEPTOS
	WHERE COD_CONCEPTO IN 
	(SELECT c.COD_CONCEPTO 
				FROM FA_ENTRADA_TO E, fa_conceptos c
				WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
				and c.cod_concorig = e.codigo_concepto);

       	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

        FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 174, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO sc_concepto');
                                                                                                                                                                                                                                 
	DELETE
	from
	(SELECT (substr(COD_CONCEPTO, length(COD_CONCEPTO) -5, length(COD_CONCEPTO))) cod
	from sc_concepto where COD_DOMINIO_CTO = 7)
	where
	cod in 
	(SELECT lpad(CODIGO_CONCEPTO,6,'0') FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	                                                                                                                                                                                                                         
                                                                                                                                                                                                                                 
	DELETE
	from
	(SELECT (substr(COD_CONCEPTO, length(COD_CONCEPTO) -5, length(COD_CONCEPTO))) cod
	from sc_concepto where COD_DOMINIO_CTO = 7)
	where
	cod in 
	(SELECT lpad(COD_CONCEPTO,6,'0') 
	FROM FA_ENTRADA_TO E, FA_CONCEPTOS C
	WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
	AND C.cod_concorig = e.codigo_concepto);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

        FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 175, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO SC_GRP_DOMINIO_DET');
                                                                                                                                                                                                                            


	--DELETE SOLANGE
	DECLARE
	CONTADOR number(8) :=0;
	sCodCto  SC_GRP_DOMINIO_DET.COD_CTO_GRP%TYPE;
	sDesConcepto SC_GRP_DOMINIO_DET.DES_CONCEPTO_GRP%TYPE;
	cursor K is
	select c.des_concepto
	from fa_conceptos c, fa_entrada_to e
	where c.cod_concepto = e.codigo_concepto
	and e.codigo_concepto != e.codigo_destino;
	cursor B is
	select rowid as tid  
	from sc_grp_dominio_det
	where cod_dominio_cto  in (7,12,20)
	and cod_grp_dominio  in (15 , 21)
	and des_concepto_grp like '%'||sDesConcepto||'%';
	begin
	for L in K loop
	        sDesConcepto := L.des_concepto;
	        FOR M IN B LOOP
		DELETE sc_grp_dominio_det where rowid = M.tid;
		contador := contador + 1;
	        end loop;
	if mod(contador,10000) =0 then
	   commit;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 175.1, null, sysdate, sqlcode, 'Se han eliminado '||contador||' registros.');
	end if;
	end loop;
	commit;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 175.1, null, sysdate, sqlcode, 'Se eliminaron '||contador||' registros.');
	end;

	--DELETE SOLANGE 2
	DECLARE
	CONTADOR number(8) :=0;
	sCodCto  SC_GRP_DOMINIO_DET.COD_CTO_GRP%TYPE;
	sDesConcepto SC_GRP_DOMINIO_DET.DES_CONCEPTO_GRP%TYPE;
	cursor K is
	select c.des_concepto
	from fa_conceptos c, fa_entrada_to e
	where c.cod_concorig = e.codigo_concepto
	and e.codigo_concepto != e.codigo_destino;
	cursor B is
	select rowid as tid  
	from sc_grp_dominio_det
	where cod_dominio_cto  in (7,12,20)
	and cod_grp_dominio  in (15 , 21)
	and des_concepto_grp like '%'||sDesConcepto||'%';
	begin
	for L in K loop
	        sDesConcepto := L.des_concepto;
	        FOR M IN B LOOP
		DELETE sc_grp_dominio_det where rowid = M.tid;
		contador := contador + 1;
	        end loop;
	if mod(contador,10000) =0 then
	   commit;
		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 175.1, null, sysdate, sqlcode, 'Se han eliminado '||contador||' registros.');
	end if;
	end loop;
	commit;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 175.1, null, sysdate, sqlcode, 'Se eliminaron '||contador||' registros.');
	end;


	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 176, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO SC_CTO_CTA');

	DELETE
	from
	(SELECT (substr(COD_CONCEPTO, length(COD_CONCEPTO) -5, length(COD_CONCEPTO))) cod
	from SC_CTO_CTA where COD_DOMINIO_CTO in (15))
	where cod in 
	(SELECT lpad(CODIGO_CONCEPTO,6,'0') FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	                                                                                                                                                                                                                         
	DELETE
	from
	(SELECT (substr(COD_CONCEPTO, length(COD_CONCEPTO) -5, length(COD_CONCEPTO))) cod
	from SC_CTO_CTA where COD_DOMINIO_CTO in (15))
	where cod in 
	(SELECT lpad(COD_CONCEPTO,6,'0') 
	FROM FA_ENTRADA_TO E, FA_CONCEPTOS C
	WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
	AND C.cod_concorig = e.codigo_concepto);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 177, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO DE CARGO EN GE_MULTIIDIOMA');
	
	DELETE FROM ge_multiidioma
	WHERE nom_tabla = 'FA_CONCEPTOS'
	and COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 177.1, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO DE DESCUENTO EN GE_MULTIIDIOMA');
	
	DELETE FROM ge_multiidioma
	WHERE nom_tabla = 'FA_CONCEPTOS'
	and COD_CONCEPTO IN (
				SELECT COD_CONCEPTO 
				FROM FA_ENTRADA_TO E, FA_CONCEPTOS C
				WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO
				AND COD_CONCORIG = CODIGO_CONCEPTO);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;



	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 177.5, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO DE CARGO EN FA_CONCEPTOS');
	
	DELETE FROM FA_CONCEPTOS
	WHERE COD_CONCEPTO IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO WHERE CODIGO_CONCEPTO <> CODIGO_DESTINO);

	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;
	                                                                                                                                                                                                                         
	--delete los conceptos de tipo descuento             
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 178, null, sysdate, sqlcode, 'ELIMINACION DE CONCEPTO DE DESCUENTO EN FA_CONCEPTOS');
	
	DELETE FROM fa_conceptos a
	WHERE a.COD_CONCORIG in (select B.codigo_concepto from fa_entrada_to b   --tabla pivote
		                 where a.COD_CONCORIG=b.CODIGO_CONCEPTO
		                 AND B.CODIGO_CONCEPTO <> B.CODIGO_DESTINO);
		                 		                 
	IF TO_CHAR(SQLCODE)= '0' THEN
           COMMIT;
        ELSE
           ROLLBACK;
        END IF;

exception
      when others then
            RAISE_APPLICATION_ERROR (-20100,'ERRROR : '|| TO_CHAR(SQLCODE) ||' ' || SQLERRM);

END;

/ 

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 179, null, sysdate, sqlcode, 'REINSERCION DE CONCEPTOS CON GLOSA DISPONIBLE'); 


DECLARE
CONTADOR NUMBER (4) :=1;
TOTAL NUMBER (4) :=0;
CURSOR K IS
SELECT  COD_CONCEPTO, COD_PRODUCTO,
                        DES_CONCEPTO, COD_TIPCONCE, COD_MODULO,
                        IND_ACTIVO, COD_MONEDA, COD_CONCORIG,
                        COD_TIPDESCU, NOM_USUARIO, FEC_ULTMOD,
                        COD_PRODSERVTFN, IND_RECURRENTE, COD_SUBCONCEPTO,
                        IND_TECNOLOGIA, DEF_TECNOLOGIA
FROM (
SELECT CODIGO_CONCEPTO AS COD_CONCEPTO, 1 AS COD_PRODUCTO,
                'REUTILIZABLE' AS DES_CONCEPTO ,  4 AS COD_TIPCONCE,
                'FA' AS COD_MODULO, 1 AS IND_ACTIVO, '001' AS COD_MONEDA,
                 NULL AS COD_CONCORIG, '1' AS COD_TIPDESCU, USER AS NOM_USUARIO,
                 SYSDATE AS FEC_ULTMOD, 1 AS COD_PRODSERVTFN, 0 AS IND_RECURRENTE,
                'TC' AS COD_SUBCONCEPTO, 0 AS IND_TECNOLOGIA,
                'NOTECNO' AS DEF_TECNOLOGIA
FROM FA_ENTRADA_TO
WHERE CODIGO_CONCEPTO != CODIGO_DESTINO
UNION ALL
SELECT COD_CONCEPTO AS COD_CONCEPTO, 1 AS COD_PRODUCTO,
                'REUTILIZABLE' AS DES_CONCEPTO ,  4 AS COD_TIPCONCE,
                'FA' AS COD_MODULO, 1 AS IND_ACTIVO, '001' AS COD_MONEDA,
                 NULL AS COD_CONCORIG, '1' AS COD_TIPDESCU, USER AS NOM_USUARIO,
                 SYSDATE AS FEC_ULTMOD, 1 AS COD_PRODSERVTFN, 0 AS IND_RECURRENTE,
                'TC' AS COD_SUBCONCEPTO, 0 AS IND_TECNOLOGIA,
                'NOTECNO' AS DEF_TECNOLOGIA
FROM FA_ENTRADA_TO  E, VM_FA_CONCEPTOS C
WHERE CODIGO_CONCEPTO  = COD_CONCORIG
AND CODIGO_CONCEPTO != CODIGO_DESTINO
ORDER BY COD_CONCEPTO ) J
WHERE J.COD_CONCEPTO NOT IN (
SELECT COD_CONCEPTO 
FROM FA_CONCEPTOS K
WHERE J.COD_CONCEPTO = K.COD_CONCEPTO);
BEGIN
FOR L IN K LOOP
INSERT INTO FA_CONCEPTOS (COD_CONCEPTO, COD_PRODUCTO,
                        DES_CONCEPTO, COD_TIPCONCE, COD_MODULO,
                        IND_ACTIVO, COD_MONEDA, COD_CONCORIG,
                        COD_TIPDESCU, NOM_USUARIO, FEC_ULTMOD,
                        COD_PRODSERVTFN, IND_RECURRENTE, COD_SUBCONCEPTO,
                        IND_TECNOLOGIA, DEF_TECNOLOGIA)
VALUES ( L.COD_CONCEPTO, L.COD_PRODUCTO, L.DES_CONCEPTO, L.COD_TIPCONCE, L.COD_MODULO, L.IND_ACTIVO, L.COD_MONEDA,
L.COD_CONCORIG, L.COD_TIPDESCU, L.NOM_USUARIO, L.FEC_ULTMOD, L.COD_PRODSERVTFN, L.IND_RECURRENTE, L.COD_SUBCONCEPTO,
L.IND_TECNOLOGIA, L.DEF_TECNOLOGIA);
IF CONTADOR > 49 THEN
	COMMIT;
	TOTAL := TOTAL + CONTADOR;
	FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 179.1, null, sysdate, sqlcode, 'Se han insertado '||TOTAL||' Conceptos');
	CONTADOR := 0;
END IF;
CONTADOR := CONTADOR + 1;
END LOOP;
COMMIT;
END;
/

--NUEVA MODIFICACION BERNARDO MORA 17-04-2007 INC 39534, SE GUARDAN LOS CONCEPTOS QUE .
--SE REASIGNARON EN LA TABLA HISTORICA RESPALDO DE LA TABLA PIVOTE FA_ENTRADA_TO

INSERT INTO FA_HIST_ENTRADA_TH (CODIGO_CONCEPTO, CODIGO_DESTINO, DES_CONCEPTO, DES_CONCEPTO_DCTO)
SELECT A.CODIGO_CONCEPTO, A.CODIGO_DESTINO, A.DES_CONCEPTO, A.DES_CONCEPTO_DCTO
FROM FA_ENTRADA_TO A  
WHERE A.CODIGO_CONCEPTO NOT IN (SELECT CODIGO_CONCEPTO FROM FA_HIST_ENTRADA_TH);

COMMIT;

UPDATE FA_CICLOS_PROCESADOS_TO
SET FECHA_TERMINO=SYSDATE, ESTADO='OK'
WHERE COD_CICLFACT=-1;

COMMIT;


EXIT;

