set ver off;
set feedback off;
set echo off;
set pagesize 0;
spool $WORKDIR/cuenta_doc_n.dat;
select lpad(to_char(count(*)),10,'0') from siscel.fa_histdocu; 
spool off;
exit;
