set veri off
update fa_ciclocli a  
SET a.num_proceso = 0, a.ind_mascara = 0
where exists (select 1 from ga_intarcel b
				where b.cod_cliente=a.cod_cliente
				and (b.fec_hasta > sysdate -90
				or b.fec_hasta>=sysdate)) 
and a.cod_ciclo=&1
and a.num_abonado=0
and a.cod_producto=1
and a.num_proceso<>-99;
commit;
exit;
