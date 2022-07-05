-- Script : permiso_con.sql
-- Date   : 23/9/99
set ver off feed off term off echo off
spool $WORKDIR/permiso_con
grant alter on fa_histconc_&1 to SISCEL_ADMIN;
grant delete on fa_histconc_&1 to SISCEL_ADMIN;
grant insert on fa_histconc_&1 to SISCEL_ADMIN;
grant select on fa_histconc_&1 to SISCEL_ADMIN;
grant update on fa_histconc_&1 to SISCEL_ADMIN;
grant select on fa_histconc_&1 to SISCEL_SELECT;
grant delete on fa_histconc_&1 to SISCEL_FA;
grant insert on fa_histconc_&1 to SISCEL_FA;
grant select on fa_histconc_&1 to SISCEL_FA;
grant update on fa_histconc_&1 to SISCEL_FA;
create public synonym fa_histconc_&1 for fa_histconc_&1;
spool off
exit;

