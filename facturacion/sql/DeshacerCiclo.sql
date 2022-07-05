drop table FA_HISTECNO_TH_&&1._AUX;
 
drop table FA_HISTCONC_&&1._AUX;
 

/* ELIMINAR LOS DATOS INSERTADOS EN FA_HISTCONC_19010102 Y EN FA_AJUSTECONC*/

DELETE   
 FROM fa_histconc_19010102 a
	 WHERE EXISTS (	SELECT ind_ordentotal 
	 			FROM VM_FA_HISTCONC_DNOTAC b
	 			WHERE b.Ind_ordentotal=a.Ind_ordentotal 
	 			AND   b.cod_concepto IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO));
COMMIT;
 
 
DELETE FROM fa_ajusteconc a
   WHERE EXISTS (SELECT num_folio 
   		FROM vm_fa_histdocu b 
   		WHERE b.num_folio=a.num_folio 
   		AND EXISTS ( SELECT ind_ordentotal 
   				FROM FA_CAMBIA_LLAVE_TO  c
   				WHERE  c.Ind_ordentotal = b.ind_ordentotal_dnc ));
 	 			
COMMIT;

/* APLICAR INSERT PARA RESTAURAR LOS DATOS */

INSERT INTO fa_histconc_19010102
( IND_ORDENTOTAL   ,
  COD_CONCEPTO   ,
  COLUMNA        ,
  COD_MONEDA     ,
  COD_PRODUCTO   ,
  COD_TIPCONCE   ,
  FEC_VALOR      ,
  FEC_EFECTIVIDAD,
  IMP_CONCEPTO   ,
  COD_REGION     ,
  COD_PROVINCIA  ,
  COD_CIUDAD     ,
  IMP_MONTOBASE  ,
  IND_FACTUR     ,
  IMP_FACTURABLE ,
  IND_SUPERTEL   ,
  NUM_ABONADO    ,
  COD_PORTADOR   ,
  DES_CONCEPTO   ,
  SEG_CONSUMIDO  ,
  NUM_CUOTAS     ,
  ORD_CUOTA      ,
  NUM_UNIDADES   ,
  NUM_SERIEMEC   ,
  NUM_SERIELE    ,
  PRC_IMPUESTO   ,
  VAL_DTO        ,
  TIP_DTO        ,
  MES_GARANTIA   ,
  NUM_GUIA       ,
  IND_ALTA       ,
  NUM_PAQUETE    ,
  FLAG_IMPUES    ,
  FLAG_DTO       ,
  COD_CONCEREL   ,
  COLUMNA_REL    ,
  SEQ_CUOTAS     ,
  COD_PLANTARIF  ,
  COD_CARGOBASICO,
  TIP_PLANTARIF  ,
  IMP_DCTO       ,
  IMP_REAL       ,
  DUR_DCTO       ,
  DUR_REAL       ,
  CNT_LLAM_REAL  ,
  CNT_LLAM_DCTO  ,
  CNT_LLAM_FACT  ,
  MIN_PLANTARIF  ,
  COD_UNIDAD     ,
  COD_OPERADOR   
  )			
  SELECT 
  a.IND_ORDENTOTAL   ,
  a.COD_CONCEPTO   ,
  a.COLUMNA        ,
  a.COD_MONEDA     ,
  a.COD_PRODUCTO   ,
  a.COD_TIPCONCE   ,
  a.FEC_VALOR      ,
  a.FEC_EFECTIVIDAD,
  a.IMP_CONCEPTO   ,
  a.COD_REGION     ,
  a.COD_PROVINCIA  ,
  a.COD_CIUDAD     ,
  a.IMP_MONTOBASE  ,
  a.IND_FACTUR     ,
  a.IMP_FACTURABLE ,
  a.IND_SUPERTEL   ,
  a.NUM_ABONADO    ,
  a.COD_PORTADOR   ,
  a.DES_CONCEPTO   ,
  a.SEG_CONSUMIDO  ,
  a.NUM_CUOTAS     ,
  a.ORD_CUOTA      ,
  a.NUM_UNIDADES   ,
  a.NUM_SERIEMEC   ,
  a.NUM_SERIELE    ,
  a.PRC_IMPUESTO   ,
  a.VAL_DTO        ,
  a.TIP_DTO        ,
  a.MES_GARANTIA   ,
  a.NUM_GUIA       ,
  a.IND_ALTA       ,
  a.NUM_PAQUETE    ,
  a.FLAG_IMPUES    ,
  a.FLAG_DTO       ,
  a.COD_CONCEREL   ,
  a.COLUMNA_REL    ,
  a.SEQ_CUOTAS     ,
  a.COD_PLANTARIF  ,
  a.COD_CARGOBASICO,
  a.TIP_PLANTARIF  ,
  a.IMP_DCTO       ,
  a.IMP_REAL       ,
  a.DUR_DCTO       ,
  a.DUR_REAL       ,
  a.CNT_LLAM_REAL  ,
  a.CNT_LLAM_DCTO  ,
  a.CNT_LLAM_FACT  ,
  a.MIN_PLANTARIF  ,
  a.COD_UNIDAD     ,
  a.COD_OPERADOR   
  FROM VM_FA_HISTCONC_DNOTAC a, FA_CAMBIA_LLAVE_TO b
  WHERE a.ind_ordentotal	= b.Ind_ordentotal
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna;
  	
  COMMIT;  	
  
INSERT INTO Fa_ajusteconc
( NUM_FOLIO        ,
  COD_CLIENTE      ,
  COD_CONCEPTO     ,
  COD_MONEDA       ,
  COLUMNA          ,
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
  PREF_PLAZA       ) 
  SELECT 
  a.NUM_FOLIO        ,
  a.COD_CLIENTE      ,
  a.COD_CONCEPTO     ,
  a.COD_MONEDA       ,
  a.COLUMNA          ,
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
  FROM VM_FA_AJUSTECONC a, FA_CAMBIA_LLAVE_TO b, vm_fa_histdocu c
  WHERE a.num_folio		= c.num_folio
  	AND b.ind_ordentotal	= c.ind_ordentotal_dnc
  	AND a.cod_concepto	= b.cod_concepto
  	AND a.columna		= b.columna;    
  	
  COMMIT;  	

drop table vm_fa_histdocu;

drop materialized view vm_fa_histconc_dnotac;

drop materialized view vm_fa_ajusteconc; 

drop materialized view VM_FA_HISTDOCU_PRE;

TRUNCATE TABLE SISCEL.FA_CAMBIA_LLAVE_TO;

UPDATE FA_CICLOS_PROCESADOS_TO
SET ESTADO='REVERSADO'
WHERE COD_CICLFACT=&&1;
 
COMMIT;
 
exit; 
 