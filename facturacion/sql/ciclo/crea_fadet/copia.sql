-- Programa : copia.sql
-- Author   : ACT
-- Date     : 23/9/99
-- Remarks  : Crea la fa_detcelular_<ciclo> a partir de la pf_tarificadas.
-- =======================================================================
set ver off
spool $WORKDIR/copia
create table siscel.fa_detcelular_&1 tablespace FACTURACION_LLAMADAS_HTAB
pctfree 0
pctused 99
storage (initial 1024M next 510M pctincrease 0)
as select * from siscel.pf_tarificadas;
spool off
exit;
