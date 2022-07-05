-- Programa : cuenta_PFDet.sql
-- Author   : PGG
-- Date     : 30/08/2007
-- Remarks  : Cuenta la cantidad de registros de la tabla 
--            PF_TARIFICADAS
-- Params   : &1 --> Cod_CiclFact
--            &2 --> Modulo de cliente.
--						&3 --> Ciclo			
-- ==================================================================
set ver off;
set feedback off;
set echo off;
set pagesize 0;
set serveroutput on;
--
DECLARE
	LN_Cantidad NUMBER(10);
BEGIN	
	LN_Cantidad := 0;
	
	SELECT LPAD(TO_CHAR(COUNT(1)),8,'0') 
	INTO LN_Cantidad
	FROM PF_TARIFICADAS TA 
	WHERE EXISTS 
		(SELECT 'X'
		FROM FA_CICLOCLI CLI 
		WHERE CLI.COD_CLIENTE = TA.COD_CLIENTE
		AND CLI.NUM_ABONADO = TA.NUM_ABONADO 
		AND CLI.COD_CICLO = &3
		AND CLI.NUM_PROCESO <= 0
		AND CLI.COD_PRODUCTO = 1)
	AND TA.COD_PERIODO=&1;
	
	DBMS_OUTPUT.PUT_LINE(LN_Cantidad);
	
END;
/
exit;
