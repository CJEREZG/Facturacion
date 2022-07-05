/*-------- AL_ARTICULOS -----------*/

DELETE FROM al_articulos a
WHERE EXISTS (SELECT cod_articulo 
	  FROM vm_al_articulos b 
	  WHERE b.cod_articulo=a.cod_articulo) 
	  AND (  A.COD_CONCEPTOART in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO)
	  OR A.COD_CONCEPTOARTALQ in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO) );
	  
COMMIT;

INSERT INTO al_articulos
( COD_ARTICULO         ,
  DES_ARTICULO       ,
  COD_FABRICANTE     ,
  TIP_ARTICULO       ,
  COD_MODELO         ,
  COD_UNIDAD         ,
  IND_SERIADO        ,
  IND_EQUIACC        ,
  COD_PROVEEDOR      ,
  REF_FABRICANTE     ,
  COD_BARRAS         ,
  MES_FABRICANTE     ,
  MES_CADUCIDAD      ,
  MES_GARANTIA       ,
  COD_CONCEPTOART    ,
  COD_CONCEPTODTO    ,
  COD_CONCEPTOARTALQ ,
  COD_CONCEPTODTOALQ ,
  COD_PRODUCTO       ,
  IND_ORACLE         ,
  TIP_TERMINAL       ,
  MES_AFIJO          ,
  IND_PROC           ,
  IND_OBS            ,
  IND_AGRU           )
SELECT
  COD_ARTICULO         ,
  DES_ARTICULO       ,
  COD_FABRICANTE     ,
  TIP_ARTICULO       ,
  COD_MODELO         ,
  COD_UNIDAD         ,
  IND_SERIADO        ,
  IND_EQUIACC        ,
  COD_PROVEEDOR      ,
  REF_FABRICANTE     ,
  COD_BARRAS         ,
  MES_FABRICANTE     ,
  MES_CADUCIDAD      ,
  MES_GARANTIA       ,
  COD_CONCEPTOART    ,
  COD_CONCEPTODTO    ,
  COD_CONCEPTOARTALQ ,
  COD_CONCEPTODTOALQ ,
  COD_PRODUCTO       ,
  IND_ORACLE         ,
  TIP_TERMINAL       ,
  MES_AFIJO          ,
  IND_PROC           ,
  IND_OBS            ,
  IND_AGRU	  
  FROM vm_al_articulos;

COMMIT;


DROP MATERIALIZED VIEW vm_al_articulos;


/*-------- AL_CARGOS -----------*/

DELETE FROM AL_CARGOS A 
WHERE EXISTS (SELECT num_cargo FROM VM_AL_CARGOS b WHERE b.num_cargo=a.num_cargo ) 
AND (A.COD_CONCEPTO  in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO)
OR A.COD_CONCEPTO_DTO in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));

COMMIT;


INSERT INTO AL_CARGOS
(NUM_CARGO        ,
  COD_CLIENTE      ,
  COD_PRODUCTO     ,
  COD_CONCEPTO     ,
  FEC_ALTA         ,
  IMP_CARGO        ,
  COD_MONEDA       ,
  COD_PLANCOM      ,
  NUM_UNIDADES     ,
  IND_FACTUR       ,
  NUM_TRANSACCION  ,
  NUM_VENTA        ,
  NUM_ABONADO      ,
  NUM_TERMINAL     ,
  COD_CICLFACT     ,
  NUM_SERIE        ,
  MES_GARANTIA     ,
  COD_CONCEPTO_DTO ,
  VAL_DTO          ,
  TIP_DTO          ,
  COD_BODEGA       ,
  TIP_STOCK        ,
  COD_ARTICULO     ,
  COD_USO          ,
  COD_ESTADO       ,
  IND_TELEFONO     ,
  COD_CENTRAL      ,
  COD_SUBALM       ,
  COD_CAT          ,
  PLAN             ,
  CARGA            )
SELECT
  NUM_CARGO        ,
  COD_CLIENTE      ,
  COD_PRODUCTO     ,
  COD_CONCEPTO     ,
  FEC_ALTA         ,
  IMP_CARGO        ,
  COD_MONEDA       ,
  COD_PLANCOM      ,
  NUM_UNIDADES     ,
  IND_FACTUR       ,
  NUM_TRANSACCION  ,
  NUM_VENTA        ,
  NUM_ABONADO      ,
  NUM_TERMINAL     ,
  COD_CICLFACT     ,
  NUM_SERIE        ,
  MES_GARANTIA     ,
  COD_CONCEPTO_DTO ,
  VAL_DTO          ,
  TIP_DTO          ,
  COD_BODEGA       ,
  TIP_STOCK        ,
  COD_ARTICULO     ,
  COD_USO          ,
  COD_ESTADO       ,
  IND_TELEFONO     ,
  COD_CENTRAL      ,
  COD_SUBALM       ,
  COD_CAT          ,
  PLAN             ,
  CARGA            
FROM VM_AL_CARGOS;

COMMIT;

DROP MATERIALIZED VIEW VM_AL_CARGOS;

/*-------- AL_PETIGUIAS_ABO -----------*/

DELETE FROM AL_PETIGUIAS_ABO A
WHERE EXISTS (SELECT num_peticion 
	  		 FROM VM_AL_PETIGUIAS_ABO b 
	  		 WHERE a.num_peticion		= b.num_peticion
			 	   AND a.num_abonado	= b.num_abonado
				   AND a.num_orden	= b.num_orden) 
AND A.COD_CONCEPTO IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO AL_PETIGUIAS_ABO 
( NUM_PETICION  ,
  NUM_ABONADO   ,
  NUM_ORDEN     ,
  COD_CLIENTE   ,
  COD_BODEGA    ,
  COD_ARTICULO  ,
  NUM_CANTIDAD  ,
  COD_OFICINA   ,
  COD_MONEDA    ,
  VAL_LINEA     ,
  NUM_SERIE     ,
  NUM_CARGO     ,
  COD_CONCEPTO  ,
  NUM_VENTA     ,
  NUM_TELEFONO  )
SELECT
  NUM_PETICION  ,
  NUM_ABONADO   ,
  NUM_ORDEN     ,
  COD_CLIENTE   ,
  COD_BODEGA    ,
  COD_ARTICULO  ,
  NUM_CANTIDAD  ,
  COD_OFICINA   ,
  COD_MONEDA    ,
  VAL_LINEA     ,
  NUM_SERIE     ,
  NUM_CARGO     ,
  COD_CONCEPTO  ,
  NUM_VENTA     ,
  NUM_TELEFONO
FROM VM_AL_PETIGUIAS_ABO a
WHERE EXISTS (SELECT num_peticion 
	  		 FROM VM_AL_PETIGUIAS_ABO b 
	  		 WHERE a.num_peticion		= b.num_peticion
			 	   AND a.num_abonado	= b.num_abonado
				   AND a.num_orden	= b.num_orden);

COMMIT;

DROP MATERIALIZED VIEW VM_AL_PETIGUIAS_ABO;

/*--------  FAD_CONCEVAL  -----------*/

DELETE  FROM FAD_CONCEVAL A 
WHERE A.COD_CONCEPTO IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;


INSERT INTO fad_conceval
 (COD_GRUPO     ,
  COD_CONCEPTO ,
  FEC_DESDE    ,
  FEC_HASTA    ,
  IND_OBLIGA   ,
  MTO_MINFACT  ,
  FEC_ULTMOD   ,
  NOM_USUARIO)
SELECT  
  COD_GRUPO     ,
  COD_CONCEPTO ,
  FEC_DESDE    ,
  FEC_HASTA    ,
  IND_OBLIGA   ,
  MTO_MINFACT  ,
  FEC_ULTMOD   ,
  NOM_USUARIO
FROM vm_fad_conceval;

commit;

DROP MATERIALIZED VIEW vm_fad_conceval;



/*--------  fad_concapli  -----------*/

DELETE FROM fad_concapli WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO FAD_CONCAPLI 
 (COD_GRUPO     ,
  COD_CONCEPTO ,
  FEC_DESDE    ,
  FEC_HASTA    ,
  COD_CONREL   ,
  FEC_ULTMOD   ,
  NOM_USUARIO)
 SELECT
  COD_GRUPO     ,
  COD_CONCEPTO ,
  FEC_DESDE    ,
  FEC_HASTA    ,
  COD_CONREL   ,
  FEC_ULTMOD   ,
  NOM_USUARIO
 FROM  VM_FAD_CONCAPLI;
 
COMMIT;
 
DROP MATERIALIZED VIEW VM_FAD_CONCAPLI; 
 
  
/*--------  FAD_DETPLANDESC  -----------*/

DELETE
FROM FAD_DETPLANDESC	A
WHERE	A.COD_CONCDESC IN (SELECT cod_concepto 
			   FROM (SELECT cod_concepto, cod_concorig FROM fa_conceptos ) b
			   WHERE b.cod_concorig IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));

COMMIT;

INSERT INTO FAD_DETPLANDESC
( COD_PLANDESC   ,
  FEC_DESDE      ,
  FEC_HASTA      ,
  COD_TIPEVAL    ,
  COD_TIPAPLI    ,
  COD_GRUPOEVAL  ,
  COD_GRUPOAPLI  ,
  NUM_CUADRANTE  ,
  TIP_UNIDAD     ,
  COD_CONCDESC   ,
  MTO_MINFACT    ,
  FEC_ULTMOD     ,
  NOM_USUARIO)
SELECT       
  COD_PLANDESC   ,
  FEC_DESDE      ,
  FEC_HASTA      ,
  COD_TIPEVAL    ,
  COD_TIPAPLI    ,
  COD_GRUPOEVAL  ,
  COD_GRUPOAPLI  ,
  NUM_CUADRANTE  ,
  TIP_UNIDAD     ,
  COD_CONCDESC   ,
  MTO_MINFACT    ,
  FEC_ULTMOD     ,
  NOM_USUARIO
FROM VM_FAD_DETPLANDESC;

DROP MATERIALIZED VIEW VM_FAD_DETPLANDESC; 


/*--------  FA_DETPASOCOBROS  -----------*/

DELETE FROM  FA_DETPASOCOBROS a
WHERE COD_CONCEPTO IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);


COMMIT;

DELETE FROM FA_DETPASOCOBROS a WHERE
EXISTS (SELECT num_procpasocobro  
  			    FROM VM_FA_DETPASOCOBROS  B
				   WHERE     B.COD_OPERADORA_SCL=A.COD_OPERADORA_SCL
					 AND B.COD_PLAZA	=A.COD_PLAZA
				     	 AND B.NUM_PROCPASOCOBRO=A.NUM_PROCPASOCOBRO
					 AND B.COD_TIPDOCUM	=A.COD_TIPDOCUM)
AND COD_CONCEPTO NOT IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO FA_DETPASOCOBROS A
 (  NUM_PROCPASOCOBRO ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  IMP_CONCEPTO    ,
  PER_CONTABLE     ,  
  COD_CATEGORIA     , 
  COD_TIPCOMIS       ,
  COD_OPERADORA_SCL  ,
  COD_PLAZA          ,
  COD_TECNOLOGIA )
SELECT
  NUM_PROCPASOCOBRO ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  IMP_CONCEPTO    ,
  PER_CONTABLE     ,  
  COD_CATEGORIA     , 
  COD_TIPCOMIS       ,
  COD_OPERADORA_SCL  ,
  COD_PLAZA          ,
  COD_TECNOLOGIA
FROM VM_FA_DETPASOCOBROS;

COMMIT;

DROP MATERIALIZED VIEW VM_FA_DETPASOCOBROS; 

/*--------  FA_NCPARCIAL  -----------*/

DELETE FROM FA_NCPARCIAL a
WHERE EXISTS  (SELECT num_secuencia 
 	   		  FROM vm_fa_ncparcial b 
			  WHERE a.num_secuencia		=b.num_secuencia
 	   		  	AND a.cod_cliente 	=b.cod_cliente
				AND a.ind_ordentotal	=b.ind_ordentotal 
				AND b.cod_concepto in (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO ));

COMMIT;

INSERT INTO FA_NCPARCIAL
(
  NUM_SECUENCIA   ,
  COD_CLIENTE     ,
  IND_ORDENTOTAL  ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  IMP_CONCEPTO    ,
  FLG_EMINC       ,
  FEC_SOLICITUD   ,
  NOM_USUARIO     ,
  NUM_PROCESO     ,
  COD_ORIGEN      
)
SELECT 
  NUM_SECUENCIA   ,
  COD_CLIENTE     ,
  IND_ORDENTOTAL  ,
  COD_TIPDOCUM    ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  IMP_CONCEPTO    ,
  FLG_EMINC       ,
  FEC_SOLICITUD   ,
  NOM_USUARIO     ,
  NUM_PROCESO     ,
  COD_ORIGEN
FROM VM_FA_NCPARCIAL a;

COMMIT;



DROP MATERIALIZED VIEW VM_FA_NCPARCIAL; 



/*--------  FAT_PRESUPTEMP  -----------*/


DELETE FROM FAT_PRESUPTEMP a
WHERE EXISTS (SELECT num_proceso 
	  		 FROM FAT_PRESUPTEMP b
			 WHERE a.num_proceso=b.num_proceso
			 	   AND b.cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));

COMMIT;
				   
INSERT INTO FAT_PRESUPTEMP
(
  NUM_PROCESO      ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_CLIENTE      ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  IMP_FACTURABLE   ,
  COD_TIPCONCE     ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  FLAG_IMPUES      ,
  PRC_IMPUESTO     ,
  NUM_UNIDADES
)
SELECT
  NUM_PROCESO      ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_CLIENTE      ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  IMP_FACTURABLE   ,
  COD_TIPCONCE     ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  FLAG_IMPUES      ,
  PRC_IMPUESTO     ,
  NUM_UNIDADES				   
FROM VM_FAT_PRESUPTEMP;

COMMIT;

DROP MATERIALIZED VIEW VM_FAT_PRESUPTEMP;

/*--------  fa_prefactura  -----------*/

DELETE FROM fa_prefactura a 
WHERE EXISTS (
	SELECT num_proceso FROM fa_prefactura b 
	WHERE a.num_proceso	= b.num_proceso
	AND a.cod_cliente	= b.cod_cliente
	AND b.cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));
						 
COMMIT;


INSERT INTO fa_prefactura
(NUM_PROCESO     ,
  COD_CLIENTE     ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  COD_PRODUCTO    ,
  COD_MONEDA      ,
  FEC_VALOR       ,
  FEC_EFECTIVIDAD ,
  IMP_CONCEPTO    ,
  IMP_FACTURABLE  ,
  IMP_MONTOBASE   ,
  COD_REGION      ,
  COD_PROVINCIA   ,
  COD_CIUDAD      ,
  COD_MODULO      ,
  COD_PLANCOM     ,
  IND_FACTUR      ,
  NUM_UNIDADES    ,
  COD_CATIMPOS    ,
  IND_ESTADO      ,
  COD_PORTADOR    ,
  COD_TIPCONCE    ,
  COD_CICLFACT    ,
  COD_CONCEREL    ,
  COLUMNA_REL     ,
  NUM_ABONADO     ,
  NUM_TERMINAL    ,
  CAP_CODE        ,
  NUM_SERIEMEC    ,
  NUM_SERIELE     ,
  FLAG_IMPUES     ,
  FLAG_DTO        ,
  PRC_IMPUESTO    ,
  VAL_DTO         ,
  TIP_DTO         ,
  NUM_VENTA       ,
  MES_GARANTIA    ,
  IND_ALTA        ,
  IND_SUPERTEL    ,
  NUM_PAQUETE     ,
  NUM_TRANSACCION ,
  IND_CUOTA       ,
  NUM_GUIA        ,
  NUM_CUOTAS      ,
  ORD_CUOTA       ,
  DES_NOTACREDC   ,
  IND_MODVENTA    ,
  IND_RECUPIVA    ,
  COD_TIPDOCUM    ,
  COD_TECNOLOGIA  )
SELECT
  NUM_PROCESO     ,
  COD_CLIENTE     ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  COD_PRODUCTO    ,
  COD_MONEDA      ,
  FEC_VALOR       ,
  FEC_EFECTIVIDAD ,
  IMP_CONCEPTO    ,
  IMP_FACTURABLE  ,
  IMP_MONTOBASE   ,
  COD_REGION      ,
  COD_PROVINCIA   ,
  COD_CIUDAD      ,
  COD_MODULO      ,
  COD_PLANCOM     ,
  IND_FACTUR      ,
  NUM_UNIDADES    ,
  COD_CATIMPOS    ,
  IND_ESTADO      ,
  COD_PORTADOR    ,
  COD_TIPCONCE    ,
  COD_CICLFACT    ,
  COD_CONCEREL    ,
  COLUMNA_REL     ,
  NUM_ABONADO     ,
  NUM_TERMINAL    ,
  CAP_CODE        ,
  NUM_SERIEMEC    ,
  NUM_SERIELE     ,
  FLAG_IMPUES     ,
  FLAG_DTO        ,
  PRC_IMPUESTO    ,
  VAL_DTO         ,
  TIP_DTO         ,
  NUM_VENTA       ,
  MES_GARANTIA    ,
  IND_ALTA        ,
  IND_SUPERTEL    ,
  NUM_PAQUETE     ,
  NUM_TRANSACCION ,
  IND_CUOTA       ,
  NUM_GUIA        ,
  NUM_CUOTAS      ,
  ORD_CUOTA       ,
  DES_NOTACREDC   ,
  IND_MODVENTA    ,
  IND_RECUPIVA    ,
  COD_TIPDOCUM    ,
  COD_TECNOLOGIA  
  FROM VM_fa_prefactura;

COMMIT;

DROP MATERIALIZED VIEW VM_fa_prefactura;

/*--------  GA_ACTUASERV  -----------*/


DELETE FROM GA_ACTUASERV A 
WHERE EXISTS (SELECT COD_PRODUCTO 
	  		  FROM VM_GA_ACTUASERV B
			  WHERE a.cod_producto 	=b.cod_producto
			  		AND a.cod_actabo=b.cod_actabo
					AND a.cod_tipserv=b.cod_tipserv
					AND a.cod_servicio = b.cod_servicio)
AND cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO GA_ACTUASERV
(
  COD_PRODUCTO  ,
  COD_ACTABO    ,
  COD_TIPSERV   ,
  COD_SERVICIO  ,
  COD_CONCEPTO  
)
SELECT
  COD_PRODUCTO  ,
  COD_ACTABO    ,
  COD_TIPSERV   ,
  COD_SERVICIO  ,
  COD_CONCEPTO  
FROM VM_GA_ACTUASERV;

COMMIT;

DROP MATERIALIZED VIEW VM_GA_ACTUASERV; 

/*-------- ga_autoriza  -----------*/


DELETE FROM ga_autoriza a
WHERE EXISTS ( SELECT num_autoriza 
	  		   FROM vm_ga_autoriza b
			   WHERE a.num_autoriza=b.num_autoriza
			   		 AND a.lin_autoriza=b.lin_autoriza
					 AND a.num_venta=b.num_venta) 
AND cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;


INSERT INTO ga_autoriza 
( NUM_AUTORIZA           ,
  LIN_AUTORIZA           ,
  COD_ESTADO             ,
  NOM_USUAAUTORIZAVENTA  ,
  NUM_VENTA              ,
  COD_OFICINA            ,
  COD_VENDEDOR           ,
  NUM_UNIDADES           ,
  FEC_VENTA              ,
  NOM_USUAR_VTA          ,
  PRC_ORIGIN             ,
  IND_TIPVENTA           ,
  COD_CLIENTE            ,
  COD_MODVENTA           ,
  COD_CONCEPTO           ,
  IMP_CARGO              ,
  COD_MONEDA             ,
  NUM_ABONADO            ,
  NUM_SERIE              ,
  COD_CONCEPTO_DTO       ,
  VAL_DTO                ,
  TIP_DTO                ,
  ORIGEN                 ,
  IND_MODIFI             )
SELECT
  NUM_AUTORIZA           ,
  LIN_AUTORIZA           ,
  COD_ESTADO             ,
  NOM_USUAAUTORIZAVENTA  ,
  NUM_VENTA              ,
  COD_OFICINA            ,
  COD_VENDEDOR           ,
  NUM_UNIDADES           ,
  FEC_VENTA              ,
  NOM_USUAR_VTA          ,
  PRC_ORIGIN             ,
  IND_TIPVENTA           ,
  COD_CLIENTE            ,
  COD_MODVENTA           ,
  COD_CONCEPTO           ,
  IMP_CARGO              ,
  COD_MONEDA             ,
  NUM_ABONADO            ,
  NUM_SERIE              ,
  COD_CONCEPTO_DTO       ,
  VAL_DTO                ,
  TIP_DTO                ,
  ORIGEN                 ,
  IND_MODIFI             
FROM VM_ga_autoriza;   

COMMIT;


DROP MATERIALIZED VIEW VM_ga_autoriza;


/*-------- GA_CARGOS_RECHAZADOS  -----------*/


DELETE FROM GA_CARGOS_RECHAZADOS WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO GA_CARGOS_RECHAZADOS
( NUM_VENTA         ,
  NUM_CARGO         ,
  COD_CLIENTE       ,
  COD_PRODUCTO      ,
  COD_CICLFACT      ,
  NUM_TRANSACCION   ,
  COD_CONCEPTO      ,
  IMP_CARGO         ,
  COD_MONEDA        ,
  NUM_UNIDADES      ,
  NOM_USUARIO       ,
  NUM_PAQUETE       ,
  NUM_ABONADO       ,
  NUM_TERMINAL      ,
  NUM_SERIE         ,
  CAP_CODE          ,
  COD_CONCEPTO_DTO  ,
  VAL_DTO           ,
  TIP_DTO           ,
  IND_CUOTA         )
SELECT
  NUM_VENTA         ,
  NUM_CARGO         ,
  COD_CLIENTE       ,
  COD_PRODUCTO      ,
  COD_CICLFACT      ,
  NUM_TRANSACCION   ,
  COD_CONCEPTO      ,
  IMP_CARGO         ,
  COD_MONEDA        ,
  NUM_UNIDADES      ,
  NOM_USUARIO       ,
  NUM_PAQUETE       ,
  NUM_ABONADO       ,
  NUM_TERMINAL      ,
  NUM_SERIE         ,
  CAP_CODE          ,
  COD_CONCEPTO_DTO  ,
  VAL_DTO           ,
  TIP_DTO           ,
  IND_CUOTA         
FROM   VM_GA_CARGOS_RECHAZADOS;

COMMIT;

DROP MATERIALIZED VIEW VM_GA_CARGOS_RECHAZADOS;


/*--------GA_HSERVSUPLABO-----------*/


DELETE FROM 	GA_HSERVSUPLABO 
WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO GA_HSERVSUPLABO 
( NUM_ABONADO    ,
  COD_SERVICIO   ,
  FEC_ALTABD     ,
  COD_SERVSUPL   ,
  COD_NIVEL      ,
  COD_PRODUCTO   ,
  NUM_TERMINAL   ,
  NOM_USUARORA   ,
  IND_ESTADO     ,
  FEC_HISTORICO  ,
  FEC_ALTACEN    ,
  FEC_BAJABD     ,
  FEC_BAJACEN    ,
  COD_CONCEPTO   ,
  NUM_DIASNUM    )
SELECT 
  NUM_ABONADO    ,
  COD_SERVICIO   ,
  FEC_ALTABD     ,
  COD_SERVSUPL   ,
  COD_NIVEL      ,
  COD_PRODUCTO   ,
  NUM_TERMINAL   ,
  NOM_USUARORA   ,
  IND_ESTADO     ,
  FEC_HISTORICO  ,
  FEC_ALTACEN    ,
  FEC_BAJABD     ,
  FEC_BAJACEN    ,
  COD_CONCEPTO   ,
  NUM_DIASNUM
FROM  VM_GA_HSERVSUPLABO;

COMMIT;

DROP MATERIALIZED VIEW VM_GA_HSERVSUPLABO;

/*--------GA_SERVSUPLABO-----------*/

DELETE FROM GA_SERVSUPLABO WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO GA_SERVSUPLABO
( NUM_ABONADO   ,
  COD_SERVICIO  ,
  FEC_ALTABD    ,
  COD_SERVSUPL  ,
  COD_NIVEL     ,
  COD_PRODUCTO  ,
  NUM_TERMINAL  ,
  NOM_USUARORA  ,
  IND_ESTADO    ,
  FEC_ALTACEN   ,
  FEC_BAJABD    ,
  FEC_BAJACEN   ,
  COD_CONCEPTO  ,
  NUM_DIASNUM   
  )
SELECT
  NUM_ABONADO   ,
  COD_SERVICIO  ,
  FEC_ALTABD    ,
  COD_SERVSUPL  ,
  COD_NIVEL     ,
  COD_PRODUCTO  ,
  NUM_TERMINAL  ,
  NOM_USUARORA  ,
  IND_ESTADO    ,
  FEC_ALTACEN   ,
  FEC_BAJABD    ,
  FEC_BAJACEN   ,
  COD_CONCEPTO  ,
  NUM_DIASNUM   
FROM VM_GA_SERVSUPLABO;

COMMIT;

DROP MATERIALIZED VIEW VM_GA_SERVSUPLABO;


/*--------GE_CARGOS-----------*/

DELETE FROM GE_CARGOS WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO GE_CARGOS
(
  NUM_CARGO         ,
  COD_CLIENTE       ,
  COD_PRODUCTO      ,
  COD_CONCEPTO      ,
  FEC_ALTA          ,
  IMP_CARGO         ,
  COD_MONEDA        ,
  COD_PLANCOM       ,
  NUM_UNIDADES      ,
  IND_FACTUR        ,
  NUM_TRANSACCION   ,
  NUM_VENTA         ,
  NUM_PAQUETE       ,
  NUM_ABONADO       ,
  NUM_TERMINAL      ,
  COD_CICLFACT      ,
  NUM_SERIE         ,
  NUM_SERIEMEC      ,
  CAP_CODE          ,
  MES_GARANTIA      ,
  NUM_PREGUIA       ,
  NUM_GUIA          ,
  NUM_FACTURA       ,
  COD_CONCEPTO_DTO  ,
  VAL_DTO           ,
  TIP_DTO           ,
  IND_CUOTA         ,
  IND_SUPERTEL      ,
  IND_MANUAL        ,
  NOM_USUARORA      ,
  PREF_PLAZA        ,
  COD_TECNOLOGIA    
)
SELECT 
  NUM_CARGO         ,
  COD_CLIENTE       ,
  COD_PRODUCTO      ,
  COD_CONCEPTO      ,
  FEC_ALTA          ,
  IMP_CARGO         ,
  COD_MONEDA        ,
  COD_PLANCOM       ,
  NUM_UNIDADES      ,
  IND_FACTUR        ,
  NUM_TRANSACCION   ,
  NUM_VENTA         ,
  NUM_PAQUETE       ,
  NUM_ABONADO       ,
  NUM_TERMINAL      ,
  COD_CICLFACT      ,
  NUM_SERIE         ,
  NUM_SERIEMEC      ,
  CAP_CODE          ,
  MES_GARANTIA      ,
  NUM_PREGUIA       ,
  NUM_GUIA          ,
  NUM_FACTURA       ,
  COD_CONCEPTO_DTO  ,
  VAL_DTO           ,
  TIP_DTO           ,
  IND_CUOTA         ,
  IND_SUPERTEL      ,
  IND_MANUAL        ,
  NOM_USUARORA      ,
  PREF_PLAZA        ,
  COD_TECNOLOGIA    
FROM VM_GE_CARGOS;


COMMIT;

DROP MATERIALIZED VIEW VM_GE_CARGOS;

/*--------RE_FACTURA_DETALLE_TO-----------*/

DELETE FROM RE_FACTURA_DETALLE_TO a 
	   WHERE EXISTS (SELECT num_reclamo FROM RE_FACTURA_DETALLE_TO b
	   		 		WHERE a.num_reclamo		= b.num_reclamo
						  AND a.tip_categoria	= b.tip_categoria
						  AND a.ind_ordentotal	= b.ind_ordentotal
						  AND b.cod_concepto in (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));

COMMIT;

INSERT INTO RE_FACTURA_DETALLE_TO 
( NUM_RECLAMO     ,
  TIP_CATEGORIA   ,
  IND_ORDENTOTAL  ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  MTO_RECLAMADO   ,
  MTO_OPERADORA   
)
SELECT
  NUM_RECLAMO     ,
  TIP_CATEGORIA   ,
  IND_ORDENTOTAL  ,
  COD_CONCEPTO    ,
  COLUMNA         ,
  MTO_RECLAMADO   ,
  MTO_OPERADORA   
FROM VM_RE_FACTURA_DETALLE_TO; 

COMMIT;

DROP MATERIALIZED VIEW VM_RE_FACTURA_DETALLE_TO; 


/*--------SP_AVERIAS-----------*/


DELETE FROM SP_AVERIAS WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO SP_AVERIAS
(
  COD_PRODUCTO   ,
  COD_AVERIA     ,
  DES_AVERIA     ,
  COD_MONEDA     ,
  COD_CONCEPTO   ,
  COD_CONCEPDTO  ,
  IND_GARANTIA   ,
  IND_SEGURO     ,
  IND_VIGENCIA   ,
  COD_ARTICULO   
)  
SELECT 
  COD_PRODUCTO   ,
  COD_AVERIA     ,
  DES_AVERIA     ,
  COD_MONEDA     ,
  COD_CONCEPTO   ,
  COD_CONCEPDTO  ,
  IND_GARANTIA   ,
  IND_SEGURO     ,
  IND_VIGENCIA   ,
  COD_ARTICULO   
FROM VM_SP_AVERIAS;

COMMIT;

DROP MATERIALIZED VIEW VM_SP_AVERIAS;  

/*-------- SP_AVERIAS_CARGOCTA -----------*/

DELETE FROM SP_AVERIAS_CARGOCTA WHERE cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;

INSERT INTO SP_AVERIAS_CARGOCTA
( NUM_SOLICITUD  ,
  COD_CONCEPTO   ,
  COD_PRODUCTO   ,
  COD_AVERIA     ,
  COD_MONEDA     ,
  IMP_CONCEPTO     
 )
 SELECT 
  NUM_SOLICITUD  ,
  COD_CONCEPTO   ,
  COD_PRODUCTO   ,
  COD_AVERIA     ,
  COD_MONEDA     ,
  IMP_CONCEPTO     
 FROM  VM_SP_AVERIAS_CARGOCTA;
 
COMMIT;

DROP MATERIALIZED VIEW VM_SP_AVERIAS_CARGOCTA; 
 
/*-------- VM_TA_CONCEPFACT -----------*/  
  
DELETE FROM VM_TA_CONCEPFACT WHERE cod_facturacion IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO);

COMMIT;
  
INSERT INTO TA_CONCEPFACT
(
  COD_PRODUCTO      ,
  COD_FACTURACION   ,
  IND_ENTSAL        ,
  IND_TABLA         ,
  COD_TARIFICACION  ,
  IND_DESTINO       ,
  COD_SERVICIO        
) 
SELECT 
  COD_PRODUCTO      ,
  COD_FACTURACION   ,
  IND_ENTSAL        ,
  IND_TABLA         ,
  COD_TARIFICACION  ,
  IND_DESTINO       ,
  COD_SERVICIO        
FROM VM_TA_CONCEPFACT;

COMMIT;

DROP MATERIALIZED VIEW VM_TA_CONCEPFACT;


/*-------- fa_presupuesto -----------*/  

DELETE FROM fa_presupuesto a WHERE EXISTS (SELECT num_proceso FROM fa_presupuesto b
   		 	   		     WHERE a.num_proceso	= b.num_proceso
						   AND a.cod_cliente	= b.cod_cliente
						   AND b.cod_concepto IN (SELECT CODIGO_DESTINO FROM FA_ENTRADA_TO));

COMMIT;

INSERT INTO fa_presupuesto
(NUM_PROCESO      ,
  COD_CLIENTE      ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_PRODUCTO     ,
  COD_MONEDA       ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  IMP_FACTURABLE   ,
  IMP_MONTOBASE    ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  COD_MODULO       ,
  COD_PLANCOM      ,
  IND_FACTUR       ,
  FEC_VENTA        ,
  NUM_UNIDADES     ,
  COD_CATIMPOS     ,
  IND_ESTADO       ,
  COD_PORTADOR     ,
  COD_TIPCONCE     ,
  COD_CICLFACT     ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  NUM_ABONADO      ,
  NUM_TERMINAL     ,
  CAP_CODE         ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  NUM_VENTA        ,
  MES_GARANTIA     ,
  IND_ALTA         ,
  IND_SUPERTEL     ,
  NUM_PAQUETE      ,
  NUM_TRANSACCION  ,
  IND_CUOTA        ,
  NUM_GUIA         ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  COD_TECNOLOGIA    )
  SELECT
  NUM_PROCESO      ,
  COD_CLIENTE      ,
  COD_CONCEPTO     ,
  COLUMNA          ,
  COD_PRODUCTO     ,
  COD_MONEDA       ,
  FEC_VALOR        ,
  FEC_EFECTIVIDAD  ,
  IMP_CONCEPTO     ,
  IMP_FACTURABLE   ,
  IMP_MONTOBASE    ,
  COD_REGION       ,
  COD_PROVINCIA    ,
  COD_CIUDAD       ,
  COD_MODULO       ,
  COD_PLANCOM      ,
  IND_FACTUR       ,
  FEC_VENTA        ,
  NUM_UNIDADES     ,
  COD_CATIMPOS     ,
  IND_ESTADO       ,
  COD_PORTADOR     ,
  COD_TIPCONCE     ,
  COD_CICLFACT     ,
  COD_CONCEREL     ,
  COLUMNA_REL      ,
  NUM_ABONADO      ,
  NUM_TERMINAL     ,
  CAP_CODE         ,
  NUM_SERIEMEC     ,
  NUM_SERIELE      ,
  FLAG_IMPUES      ,
  FLAG_DTO         ,
  PRC_IMPUESTO     ,
  VAL_DTO          ,
  TIP_DTO          ,
  NUM_VENTA        ,
  MES_GARANTIA     ,
  IND_ALTA         ,
  IND_SUPERTEL     ,
  NUM_PAQUETE      ,
  NUM_TRANSACCION  ,
  IND_CUOTA        ,
  NUM_GUIA         ,
  NUM_CUOTAS       ,
  ORD_CUOTA        ,
  COD_TECNOLOGIA   
FROM VM_FA_PRESUPUESTO;


COMMIT;


DROP MATERIALIZED VIEW VM_FA_PRESUPUESTO;



EXIT;

