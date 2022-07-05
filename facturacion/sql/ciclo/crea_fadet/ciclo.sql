-- Programa : ciclo.sql
-- Author   : ACT
-- Date     : 23/9/99
-- Remarks  : Revisa que ciclo ingresado por usuario sea valido en la B. de Datos.s.
-- ===============================================================================
set ver off;
set feedback off;
set echo off;
set pagesize 0;
spool $WORKDIR/ciclo.dat;
select rpad(to_char(cod_ciclfact),8,' ') from siscel.fa_ciclfact where cod_ciclfact=&1 and ind_facturacion=1; 
spool off;
exit;
