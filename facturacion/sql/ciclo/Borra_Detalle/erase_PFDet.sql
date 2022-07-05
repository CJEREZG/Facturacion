-- Programa : erase_PFDet.sql (nueva version)
-- Author   : PGG
-- Date     : 03/07/2008
-- Remarks  : Elimina registros de PF_TARIFICADAS, que NO FUERON FACTURADOS
--
-- Params   : &1 --> Cod_CiclFact
--            &2 --> Modulo de cliente.
--						&3 --> Ciclo
-- ===============================================================================
set ver off;
set feedback off;
set echo off;
set pagesize 0;
set serveroutput on;
--
DECLARE
iTotal NUMBER;
BEGIN
	iTotal := 0;
	LOOP
		DELETE FROM PF_TARIFICADAS TA
		WHERE EXISTS
			(SELECT 'X'
			FROM FA_CICLOCLI CLI
			WHERE CLI.COD_CLIENTE = TA.COD_CLIENTE
			AND CLI.NUM_ABONADO = TA.NUM_ABONADO
			AND CLI.COD_CICLO = &3
			AND CLI.NUM_PROCESO <= 0
			AND CLI.COD_PRODUCTO = 1)
		AND TA.COD_PERIODO=&1
		AND ROWNUM <= 5000;

		iTotal := iTotal + SQL%ROWCOUNT;
	
		EXIT WHEN SQL%NOTFOUND;

		COMMIT;
	END LOOP;
	DBMS_OUTPUT.PUT_LINE(iTotal);
END;
/
exit;
