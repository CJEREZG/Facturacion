set veri off
update fa_ciclocli A 
SET A.num_proceso = 0, A.ind_mascara = 0
WHERE A.cod_ciclo = &1
AND A.num_proceso <> -99;
commit;
exit;
