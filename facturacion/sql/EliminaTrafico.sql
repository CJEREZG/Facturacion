-----------------------------------------------
-- Elimina trafico de TA_LLAMADASROA
-----------------------------------------------
-- Parametros
-- $1 Ciclo facturacion DDMMYY

SET serveroutput on
SET term on
SET feedback off
SET verify off

DECLARE 
LN_Cantidad NUMBER(10);

BEGIN
    BEGIN
    
        SELECT  count(1)
        INTO LN_Cantidad
        FROM TA_LLAMADASROA
        WHERE COD_CICLFACT = '&1';
    
        EXCEPTION 
        WHEN OTHERS THEN
             DBMS_OUTPUT.PUT_LINE(SQLERRM);
              RAISE_APPLICATION_ERROR (-20000, 'ERROR de SELECT en EliminaTrafico.sql' );
    END;
	
    IF (LN_Cantidad=0) THEN 
       DBMS_OUTPUT.PUT_LINE('NO SE ENCONTRARON REGISTROS A ELIMINAR');
    ELSE
       BEGIN
   
           DELETE TA_LLAMADASROA
           WHERE COD_CICLFACT = '&1';
   	                  
           COMMIT;	
           DBMS_OUTPUT.PUT_LINE('REGISTROS ELIMININADOS '||LN_Cantidad);
   	       
   	    
           EXCEPTION 
           WHEN OTHERS THEN
               DBMS_OUTPUT.PUT_LINE(SQLERRM);
               RAISE_APPLICATION_ERROR (-20001,'ERROR de DELETE en EliminaTrafico.sql' );
       END;
    END IF;
    
    COMMIT;
	
END;
/
EXIT;
