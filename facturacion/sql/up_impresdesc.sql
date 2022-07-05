set veri off
update FAT_INTERIMPRESION
set DIR_WEB = '&1',  COD_ESTADO= '&2'
where NUM_PROCESO = &3;
commit;
exit;
