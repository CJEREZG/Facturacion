set ver off;
set feedback off;
set echo off;
set pagesize 0;
spool $WORKDIR/cuenta_con.dat;
select lpad(to_char(count(*)),8,'0') from siscel.fa_factconc_&1 ; 
spool off;
exit;
