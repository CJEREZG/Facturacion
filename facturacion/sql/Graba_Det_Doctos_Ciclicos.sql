whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

VARIABLE nErrorCiclo NUMBER;

--sqlplus mas_06010/des_06010 @LOOP_BDO.SQL 
--ejecuta de forma rápida el vaciado a la tabla ciclcica respectic de los datos procesados
SET SERVEROUTPUT ON size 1000000

ALTER SESSION SET DB_FILE_MULTIBLOCK_READ_COUNT = 1024;

--setear variable para manejo de error, asignar valor cuando pase 
--por el if y preguntar por ella para mandar el error al registro log

SELECT 'GRABA DATOS CANTIDAD REGISTROS TABLA HISTCONC_AUX:' FROM DUAL;

SELECT COUNT (1) FROM FA_HISTCONC_&&1._AUX;

--registro procesos en  log de proceso
EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.3, null, sysdate, sqlcode, 'CARGANDO DETALLE DE FACTURAS PROCESADAS DE UN CICLO, EN LA TABLA CICLICA RESPECTIVA: FA_HISTCONC_&&1'); 

/*----------Incorporo control de errores antes de eliminar la tabla de ciclo---------------------*/
/* ----->CONSULTA 41.30 MODIFICACION BM 04/05/2007 <------ */

DECLARE
	 nExisteError	NUMBER;
BEGIN

	select COUNT(1) INTO nExisteError
	from fa_detalle_procesados_to 
	where cod_error <> 0
	and cod_ciclfact = &&1;
	
	:nErrorCiclo:=nExisteError;

 	EXCEPTION
	 WHEN NO_DATA_FOUND THEN
	 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
	 		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 41.33, null, sysdate, sqlcode, 'NO EXISTEN INCONSISTENCIAS EN EL CICLO');
	 RAISE;
	 WHEN OTHERS THEN
    		FA_REASIG_COD_CONCEPT_FACT_PG.FA_ERRORES(19010102, 'ERROR', SYSDATE);
    		FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(19010102, 41.33, null, sysdate, sqlcode, sqlerrm);
    	RAISE;



END;
/

COMMIT;



DECLARE
	 CURSOR Columnas IS

	 SELECT 
	 table_name,
	 column_name
	 FROM all_tab_cols 
	 WHERE table_name='FA_HISTCONC_&&1'
	 AND OWNER='SISCEL';

	 Cur_columnas COLUMNAS%ROWTYPE;
 	 sSql         	VARCHAR2(32767);
 	 lsSql          VARCHAR2(32767);

BEGIN
	--MENSAJE QUE INDICA DONDE SE ENCUENTRA EL PROCESO
		
	OPEN Columnas;
	LOOP
		FETCH Columnas INTO Cur_columnas;
		EXIT WHEN Columnas%NOTFOUND;
		
		sSql:= sSql || Cur_Columnas.column_name || ',' ;
		lsSql:= lsSql || 'A.' ||Cur_Columnas.column_name || ',' ;

	END LOOP;
	
		
	--saco la  coma de mas que deja la concatenacion
	sSql:=(SUBSTR(sSql,1,length(sSql)-1));
	lsSql:=(SUBSTR(lsSql,1,length(lsSql)-1));
	
	--genera query dinámico con los campos de la tabla, sepro en 2 variables para que de el largo
	sSql:='INSERT INTO FA_HISTCONC_&&1 (' || sSql || ') ';
	
	lsSql:= ' SELECT ' || lsSql || ' FROM FA_HISTCONC_&&1.' || '_AUX A' ;
	
--	dbms_output.put_line(sSql,1,200);
	dbms_output.put_line(:nErrorCiclo);
	
	
    	IF :nErrorCiclo = 0 THEN	
	   
	   --ejecuto borrado de datos en la tabla ciclica
	   FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.4, null, sysdate, sqlcode, 'EJECUTA TRUNCATE EN LA TABLA CICLICA RESPECTIVA: FA_HISTCONC_');  
	   EXECUTE IMMEDIATE 'TRUNCATE TABLE SISCEL.FA_HISTCONC_&&1';

	   EXECUTE IMMEDIATE sSql || lsSql;

		--pregunto si hay erroreS en la
		IF TO_CHAR(SQLCODE)='0' THEN
			COMMIT;
			--mandar error al registro de error, setear variable que indique el
	        	  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.4, null, sysdate, sqlcode, 'INSERTA DATOS PROCESADOS DE UN CICLO, EN LA TABLA CICLICA RESPECTIVA: FA_HISTCONC_'); 
	        ELSE
	        	ROLLBACK;
	        	--mandar error al registro de error, setear variable que indique el
	        	  FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.5, null, sysdate, TO_CHAR(SQLCODE), 'NO INSERTA DATOS PROCESADOS DE UN CICLO, EN LA TABLA CICLICA RESPECTIVA: FA_HISTCONC_'); 
	        END IF;
	ELSE
		 FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(&&1, 41.6, null, sysdate, TO_CHAR(SQLCODE), 'NO SE GRABARON DATOS CICLO &&1 CON ERROR'); 
		 EXECUTE IMMEDIATE 'CREATE TABLE FA_HISTCONC_&&1.' || '_ERR AS SELECT * FROM FA_HISTCONC_&&1.' || '_AUX';
	END IF;
	
	CLOSE Columnas;
	
END;
/

EXIT 0;