-- Programa : val_ciclo.sql
-- Author   : PGG
-- Date     : 30/08/2007
-- Remarks  : Valida el ciclo ingresado como parametro
-- Params   : &1 --> Ciclo de Facturacion
-- ==================================================================
set ver off;
set feedback off;
set echo off;
set pagesize 0;
--
spool $WORKDIR/val_ciclo.dat;
--
SELECT RPAD(TO_CHAR(COD_CICLO),8,' ') FROM FA_CICLFACT WHERE COD_CICLFACT=&1 AND IND_FACTURACION=1;
--
spool off;
exit;
