/*Se eliminan los registros de las facturas sin nota de credito que fueron alteradas*/

DELETE   
 FROM fa_histconc_19010102 a
	 WHERE EXISTS (	SELECT ind_ordentotal 
	 			FROM vm_fa_histconc_f b
	 			WHERE b.Ind_ordentotal=b.Ind_ordentotal 
	 			AND   a.cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));			

commit;
	 			
/* inserta los registros originales de las facturas sin nota de credito*/

INSERT INTO FA_HISTCONC_19010102
(IND_ORDENTOTAL    ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_MONEDA       ,
  COD_PRODUCTO     ,
  COD_TIPCONCE     ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  IMP_MONTOBASE    ,
  IND_FACTUR       ,
  IMP_FACTURABLE   ,
  IND_SUPERTEL     ,
  NUM_ABONADO      ,
  COD_PORTADOR     ,
  DES_CONCEPTO     ,
  SEG_CONSUMIDO    ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  NUM_UNIDADES     ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  MES_GARANTIA     ,
  NUM_GUIA         ,
  IND_ALTA         ,
  NUM_PAQUETE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  SEQ_CUOTAS       ,
  COD_PLANTARIF    ,
  COD_CARGOBASICO  ,
  TIP_PLANTARIF    ,
  IMP_DCTO         ,
  IMP_REAL         ,
  DUR_DCTO         ,
  DUR_REAL         ,
  CNT_LLAM_REAL    ,
  CNT_LLAM_DCTO    ,
  CNT_LLAM_FACT    ,
  MIN_PLANTARIF    ,
  COD_UNIDAD       ,
  COD_OPERADOR     )
  SELECT
  b.IND_ORDENTOTAL    ,
  b.COD_CONCEPTO     ,
  b.COLUMNA          ,
  b.COD_MONEDA       ,
  b.COD_PRODUCTO     ,
  b.COD_TIPCONCE     ,
  b.FEC_VALOR        ,
  b.FEC_EFECTIVIDAD  ,
  b.IMP_CONCEPTO     ,
  b.COD_REGION       ,
  b.COD_PROVINCIA    ,
  b.COD_CIUDAD       ,
  b.IMP_MONTOBASE    ,
  b.IND_FACTUR       ,
  b.IMP_FACTURABLE   ,
  b.IND_SUPERTEL     ,
  b.NUM_ABONADO      ,
  b.COD_PORTADOR     ,
  b.DES_CONCEPTO     ,
  b.SEG_CONSUMIDO    ,
  b.NUM_CUOTAS       ,
  b.ORD_CUOTA        ,
  b.NUM_UNIDADES     ,
  b.NUM_SERIEMEC     ,
  b.NUM_SERIELE      ,
  b.PRC_IMPUESTO     ,
  b.VAL_DTO          ,
  b.TIP_DTO          ,
  b.MES_GARANTIA     ,
  b.NUM_GUIA         ,
  b.IND_ALTA         ,
  b.NUM_PAQUETE      ,
  b.FLAG_IMPUES      ,
  b.FLAG_DTO         ,
  b.COD_CONCEREL     ,
  b.COLUMNA_REL      ,
  b.SEQ_CUOTAS       ,
  b.COD_PLANTARIF    ,
  b.COD_CARGOBASICO  ,
  b.TIP_PLANTARIF    ,
  b.IMP_DCTO         ,
  b.IMP_REAL         ,
  b.DUR_DCTO         ,
  b.DUR_REAL         ,
  b.CNT_LLAM_REAL    ,
  b.CNT_LLAM_DCTO    ,
  b.CNT_LLAM_FACT    ,
  b.MIN_PLANTARIF    ,
  b.COD_UNIDAD       ,
  b.COD_OPERADOR
  FROM FA_CAMBIA_LLAVE_TO a, vm_fa_histconc_f b
  WHERE b.ind_ordentotal	= a.ind_ordentotal
	And b.cod_concepto	= a.cod_concepto
	And b.columna		= a.columna ;

COMMIT;



DELETE			
	FROM fa_histconc_19010102 a
       	WHERE EXISTS (SELECT ind_ordentotal 
	  			   FROM vm_fa_histconc_gdnc b 
	  			   WHERE b.ind_ordentotal		= a.ind_ordentotal 
	  			         and a.cod_concepto in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO ));	

COMMIT;

/* deja las facturas con nota de credito tal cual como estaban*/

INSERT INTO FA_HISTCONC_19010102
(IND_ORDENTOTAL    ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_MONEDA       ,
  COD_PRODUCTO     ,
  COD_TIPCONCE     ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  IMP_MONTOBASE    ,
  IND_FACTUR       ,
  IMP_FACTURABLE   ,
  IND_SUPERTEL     ,
  NUM_ABONADO      ,
  COD_PORTADOR     ,
  DES_CONCEPTO     ,
  SEG_CONSUMIDO    ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  NUM_UNIDADES     ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  MES_GARANTIA     ,
  NUM_GUIA         ,
  IND_ALTA         ,
  NUM_PAQUETE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  SEQ_CUOTAS       ,
  COD_PLANTARIF    ,
  COD_CARGOBASICO  ,
  TIP_PLANTARIF    ,
  IMP_DCTO         ,
  IMP_REAL         ,
  DUR_DCTO         ,
  DUR_REAL         ,
  CNT_LLAM_REAL    ,
  CNT_LLAM_DCTO    ,
  CNT_LLAM_FACT    ,
  MIN_PLANTARIF    ,
  COD_UNIDAD       ,
  COD_OPERADOR     )
  SELECT
  b.IND_ORDENTOTAL    ,
  b.COD_CONCEPTO     ,
  b.COLUMNA          ,
  b.COD_MONEDA       ,
  b.COD_PRODUCTO     ,
  b.COD_TIPCONCE     ,
  b.FEC_VALOR        ,
  b.FEC_EFECTIVIDAD  ,
  b.IMP_CONCEPTO     ,
  b.COD_REGION       ,
  b.COD_PROVINCIA    ,
  b.COD_CIUDAD       ,
  b.IMP_MONTOBASE    ,
  b.IND_FACTUR       ,
  b.IMP_FACTURABLE   ,
  b.IND_SUPERTEL     ,
  b.NUM_ABONADO      ,
  b.COD_PORTADOR     ,
  b.DES_CONCEPTO     ,
  b.SEG_CONSUMIDO    ,
  b.NUM_CUOTAS       ,
  b.ORD_CUOTA        ,
  b.NUM_UNIDADES     ,
  b.NUM_SERIEMEC     ,
  b.NUM_SERIELE      ,
  b.PRC_IMPUESTO     ,
  b.VAL_DTO          ,
  b.TIP_DTO          ,
  b.MES_GARANTIA     ,
  b.NUM_GUIA         ,
  b.IND_ALTA         ,
  b.NUM_PAQUETE      ,
  b.FLAG_IMPUES      ,
  b.FLAG_DTO         ,
  b.COD_CONCEREL     ,
  b.COLUMNA_REL      ,
  b.SEQ_CUOTAS       ,
  b.COD_PLANTARIF    ,
  b.COD_CARGOBASICO  ,
  b.TIP_PLANTARIF    ,
  b.IMP_DCTO         ,
  b.IMP_REAL         ,
  b.DUR_DCTO         ,
  b.DUR_REAL         ,
  b.CNT_LLAM_REAL    ,
  b.CNT_LLAM_DCTO    ,
  b.CNT_LLAM_FACT    ,
  b.MIN_PLANTARIF    ,
  b.COD_UNIDAD       ,
  b.COD_OPERADOR
  FROM FA_CAMBIA_LLAVE_TO a, vm_fa_histconc_gdnc b
  WHERE b.ind_ordentotal	= a.ind_ordentotal
	And b.cod_concepto	= a.cod_concepto
	And b.columna		= a.columna ;
	
commit;




DELETE
FROM fa_ajusteconc x WHERE EXISTS (
		SELECT b.num_folio 
		FROM vm_fa_histconc_gdnc a, vm_fa_histdocu_g b
		WHERE a.ind_ordentotal = b.ind_ordentotal_dnc
	  	AND b.num_folio =x.num_folio AND x.cod_concepto  in (select CODIGO_DESTINO from FA_ENTRADA_TO));
COMMIT;



INSERT INTO FA_AJUSTECONC
(   	NUM_FOLIO     ,                    
  	COD_CLIENTE  ,                     
  	COD_CONCEPTO  ,                    
  	COD_MONEDA     ,                   
  	COLUMNA         ,                  
  	IMP_FACTURABLE   ,                 
  	COD_PRODUCTO     ,                 
  	FEC_EFECTIVIDAD  ,                 
  	IMP_CONCEPTO     ,                 
  	COD_REGION       ,                 
  	COD_PROVINCIA    ,                 
  	COD_TIPCONCE     ,                 
  	COD_CIUDAD       ,                 
  	FEC_VALOR        ,                 
  	COD_MODULO       ,                 
  	IMP_MONTOBASE    ,                 
  	IND_FACTUR       ,                 
  	NUM_UNIDADES     ,                 
  	IND_SUPERTEL     ,                 
  	NUM_SERIEMEC     ,                 
  	NUM_ABONADO      ,                 
  	COD_PORTADOR     ,                 
  	DES_CONCEPTO     ,                 
  	SEQ_CUOTAS       ,                 
  	NUM_CUOTAS       ,                 
  	ORD_CUOTA        ,                 
  	NUM_SERIELE      ,                 
  	MES_GARANTIA     ,                 
  	NUM_GUIA         ,                 
  	IND_ALTA         ,                 
  	NUM_PAQUETE      ,                 
  	NUM_VENTA        ,                 
  	NUM_TRANSACCION  ,                 
  	FLAG_IMPUES      ,                 
  	FLAG_DTO         ,                 
  	COD_TIPDOCUM     ,                 
  	PREF_PLAZA        
)
SELECT
  	a.NUM_FOLIO     ,                    
  	a.COD_CLIENTE  ,                     
  	a.COD_CONCEPTO_new  ,                    
  	a.COD_MONEDA     ,                   
  	a.COLUMNA_rel_new     ,                  
  	a.IMP_FACTURABLE   ,                 
  	a.COD_PRODUCTO     ,                 
  	a.FEC_EFECTIVIDAD  ,                 
  	a.IMP_CONCEPTO     ,                 
  	a.COD_REGION       ,                 
  	a.COD_PROVINCIA    ,                 
  	a.COD_TIPCONCE     ,                 
  	a.COD_CIUDAD       ,                 
  	a.FEC_VALOR        ,                 
  	a.COD_MODULO       ,                 
  	a.IMP_MONTOBASE    ,                 
  	a.IND_FACTUR       ,                 
  	a.NUM_UNIDADES     ,                 
  	a.IND_SUPERTEL     ,                 
  	a.NUM_SERIEMEC     ,                 
  	a.NUM_ABONADO      ,                 
  	a.COD_PORTADOR     ,                 
  	a.DES_CONCEPTO     ,                 
  	a.SEQ_CUOTAS       ,                 
  	a.NUM_CUOTAS       ,                 
  	a.ORD_CUOTA        ,                 
  	a.NUM_SERIELE      ,                 
  	a.MES_GARANTIA     ,                 
  	a.NUM_GUIA         ,                 
  	a.IND_ALTA         ,                 
  	a.NUM_PAQUETE      ,                 
  	a.NUM_VENTA        ,                 
  	a.NUM_TRANSACCION  ,                 
  	a.FLAG_IMPUES      ,                 
  	a.FLAG_DTO         ,                 
  	a.COD_TIPDOCUM     ,                 
  	a.PREF_PLAZA        
FROM  VM_FA_AJUSTES_G a, FA_CAMBIA_LLAVE_TO b, fa_conceptos c, VM_FA_HISTDOCU_G d
  	WHERE a.num_folio	= d.num_folio
	AND b.IND_ORDENTOTAL 	= d.Ind_ordentotal_dnc
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna
  	AND b.cod_concepto_new 	= c.cod_concepto
  	AND b.cod_tipconce 	> 2;

commit;



UPDATE FA_CICLOS_PROCESADOS_TO
SET ESTADO='REVERSADO'
WHERE COD_CICLFACT=19010102;
 
COMMIT;
 
exit; 
 