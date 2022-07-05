-- ULTIMA MODIFICACION : 01-01-2003
-- AUTOR : NICOLAS MIRANDA
-- AREA RESPONSABLE : FACTURACION
-- MOTIVO CAMBIO : AGREGACION DE CAMPOS PARA SOPORTAR PROYECTO MEXICO.

--Se aplican modificaciones hechas en la operadora CH-200507052957

set echo off verify off
spool $WORKDIR/log/tab_FA_FACTDOCU_&1..log

prompt Table  FA_FACTDOCU_&1

Create table FA_FACTDOCU_&1
(NUM_SECUENCI                            NUMBER   (8,0)   NOT NULL
,COD_TIPDOCUM                            NUMBER   (2,0)   NOT NULL
,COD_VENDEDOR_AGENTE                     NUMBER   (6,0)   NOT NULL
,LETRA                                   CHAR (1)     NOT NULL
,COD_CENTREMI                            NUMBER   (4,0)   NOT NULL
,TOT_PAGAR                               NUMBER   (14,4)  NOT NULL
,TOT_CARGOSME                            NUMBER   (14,4)  NOT NULL
,COD_VENDEDOR                            NUMBER   (6,0)   NOT NULL
,COD_CLIENTE                             NUMBER   (8,0)   NOT NULL
,FEC_EMISION                             DATE          NOT NULL
,FEC_CAMBIOMO                            DATE          NOT NULL
,NOM_USUARORA                            VARCHAR2 (30)    NOT NULL
,ACUM_NETOGRAV                           NUMBER   (14,4)  NOT NULL
,ACUM_NETONOGRAV                         NUMBER   (14,4)  NOT NULL
,ACUM_IVA                                NUMBER   (14,4)  NOT NULL
,IND_ORDENTOTAL                          NUMBER   (12,0)  NOT NULL
,IND_VISADA                              NUMBER   (1,0)   NOT NULL
,IND_LIBROIVA                            NUMBER   (1,0)   NOT NULL
,IND_PASOCOBRO                           NUMBER   (1,0)   NOT NULL
,IND_SUPERTEL                            NUMBER   (1,0)   NOT NULL
,IND_ANULADA                             NUMBER   (1,0)   NOT NULL
,NUM_PROCESO                             NUMBER   (8,0)   NOT NULL
,NUM_FOLIO                               NUMBER   (9,0)   NOT NULL
,COD_PLANCOM                             NUMBER   (6,0)   NOT NULL
,COD_CATIMPOS                            NUMBER   (2,0)   NOT NULL
,FEC_VENCIMIE                            DATE          NULL
,FEC_CADUCIDA                            DATE          NULL
,FEC_PROXVENC                            DATE          NULL
,COD_CICLFACT                            NUMBER   (8,0)   NULL
,NUM_SECUREL                             NUMBER   (8,0)   NULL
,LETRAREL                                CHAR (1)     NULL
,COD_TIPDOCUMREL                         NUMBER   (2,0)   NULL
,COD_VENDEDOR_AGENTEREL                  NUMBER   (6,0)   NULL
,COD_CENTRREL                            NUMBER   (4,0)   NULL
,NUM_VENTA                               NUMBER   (8,0)   NULL
,NUM_TRANSACCION                         NUMBER   (9,0)   NULL
,IMP_SALDOANT                            NUMBER   (14,4)  NULL
,IND_IMPRESA                             NUMBER   (1,0)   NOT NULL
,SEQ_FORCOB                              NUMBER   (12,0)  NOT NULL
,SEQ_PAC                                 NUMBER   (12,0)  NOT NULL
,SEQ_SUPERTFN                            NUMBER   (12,0)  NOT NULL
,SEQ_FORFAC                              NUMBER   (12,0)  NOT NULL
,COD_OPREDFIJA                           NUMBER   (5,0)   NULL
,NUM_CTC                                 VARCHAR2 (12)    NULL
,COD_MODVENTA                            NUMBER   (2,0)   NULL
,TOT_FACTURA                             NUMBER   (14,4)  NOT NULL
,TOT_CUOTAS                              NUMBER   (14,4)  NOT NULL
,TOT_DESCUENTO                           NUMBER   (14,4)  NOT NULL
,COD_BARRAS                              VARCHAR2 (20)    NULL
,IND_FACTUR                              NUMBER   (1,0)   NOT NULL
,COD_DESPACHO				 VARCHAR2 (5)	  NULL
,IND_RECUPIVA                            CHAR     (1)
,NUM_CUOTAS  				 NUMBER(3) NOT NULL
,NUM_PROCPASOCOBRO                       NUMBER(8)
,COD_OFICINA                             VARCHAR2(2)
-- PROYECTO FACTURACION:FOLIACION
,PREF_PLAZA                  VARCHAR2 (3) 
,COD_OPERADORA               VARCHAR2 (5)  NOT NULL
,COD_PLAZA                   VARCHAR2 (5)  NOT NULL
-- PROYECTO FACTURACION:IMPUESTO
,COD_ZONAIMPO                NUMBER   (2)  NOT NULL
-- PROYECTO FACTURACION:IMPRESION DESCENTRALIZADA
,NUM_COPIAS                  NUMBER   (3)
,NUM_DUPLICADOS              NUMBER   (3)
)
pctfree  5
pctused  60
initrans  4
maxtrans  255
tablespace     QTL_FADOC_SCL001
storage
(initial        120M  
next           20M   
minextents  1
maxextents  256
pctincrease    0
freelists  8)
/

alter table FA_FACTDOCU_&1 modify IND_VISADA default 0
/
alter table FA_FACTDOCU_&1 modify IND_LIBROIVA default 0
/
alter table FA_FACTDOCU_&1 modify IND_PASOCOBRO default 0
/
alter table FA_FACTDOCU_&1 modify IND_SUPERTEL default 0
/
alter table FA_FACTDOCU_&1 modify IND_ANULADA default 0
/
alter table FA_FACTDOCU_&1 modify NUM_FOLIO default 0
/
alter table FA_FACTDOCU_&1 modify IND_IMPRESA default 0
/
alter table FA_FACTDOCU_&1 modify SEQ_FORCOB default 0
/
alter table FA_FACTDOCU_&1 modify SEQ_PAC default 0
/
alter table FA_FACTDOCU_&1 modify SEQ_SUPERTFN default 0
/
alter table FA_FACTDOCU_&1 modify SEQ_FORFAC default 0
/
alter table FA_FACTDOCU_&1 modify NUM_CTC default 0
/
alter table FA_FACTDOCU_&1 modify TOT_FACTURA default 0.0
/
alter table FA_FACTDOCU_&1 modify TOT_CUOTAS default 0.0
/
alter table FA_FACTDOCU_&1 modify TOT_DESCUENTO default 0.0
/
alter table FA_FACTDOCU_&1 modify IND_FACTUR default 1
/
alter table FA_FACTDOCU_&1 modify NUM_CUOTAS default 0 
/   

-- PROYECTO FACTURACION:FOLIACION
alter table FA_FACTDOCU_&1 modify COD_OPERADORA default 'TMC'
/   
alter table FA_FACTDOCU_&1 modify PREF_PLAZA default '000'
/   
alter table FA_FACTDOCU_&1 modify COD_PLAZA default '00001' 
/   
alter table FA_FACTDOCU_&1 modify COD_ZONAIMPO default 1
/   


prompt Primary key PK_FA_FACTDOCU_&1

alter table FA_FACTDOCU_&1
add constraint PK_FA_FACTDOCU_&1 PRIMARY KEY
(NUM_SECUENCI
,COD_TIPDOCUM
,COD_VENDEDOR_AGENTE
,LETRA
,COD_CENTREMI
)
using index
pctfree     5
initrans    8
maxtrans    255
tablespace  QIL_FADOC_SCL001
storage
(initial   20M   
next        5M  
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

prompt Unique key UK_FACTDOCU_&1._OTOTAL

alter table FA_FACTDOCU_&1
add constraint UK_FACTDOCU_&1._OTOTAL UNIQUE
(IND_ORDENTOTAL
)
using index
pctfree     5
initrans    8
maxtrans    255
tablespace   QIL_FADOC_SCL001
storage
(initial     10M  
next          2M 
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

prompt index AK_FACTDOCU_&1._CLIENTE

create  index AK_FACTDOCU_&1._CLIENTE on FA_FACTDOCU_&1
(COD_CLIENTE
)
pctfree     5
initrans    8
maxtrans    255
tablespace   QIL_FADOC_SCL001
storage
(initial    10M   
next         2M  
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/


    
                                                                                                                       
-- Sacado del indice solicitado por Mauricio V. 06/1/2000
-- prompt index AK_FACTDOCU_&1._NUM_CTC

-- create  index AK_FACTDOCU_&1._NUM_CTC on FA_FACTDOCU_&1
-- (NUM_CTC)
-- pctfree     5
-- initrans    8
-- maxtrans    255
-- tablespace  PF_TIND   
-- storage
-- (initial      10M    
-- next         2M    
-- minextents  1
-- maxextents  256
-- pctincrease 0
-- freelists   8)
-- /

prompt index AK_FACTDOCU_&1._NUM_FACTURA


create  index AK_FACTDOCU_&1._NUM_FACTURA on FA_FACTDOCU_&1
(NUM_FOLIO,PREF_PLAZA)
pctfree     5
initrans    8
maxtrans    255
tablespace  QIL_FADOC_SCL001
storage
(initial     10M    
next          2M     
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

comment on table FA_FACTDOCU_&1 is
'Datos generales de documentos Facturados';

comment on column FA_FACTDOCU_&1..NUM_SECUENCI is
'Numero de secuencia del
documento';

comment on column FA_FACTDOCU_&1..COD_TIPDOCUM is
'Codigo de Tipo de Documento';

comment on column FA_FACTDOCU_&1..COD_VENDEDOR_AGENTE is
'Codigo de Agente
Comercial';

comment on column FA_FACTDOCU_&1..LETRA is
'Letra de un documento';

comment on column FA_FACTDOCU_&1..COD_CENTREMI is
'Codigo de Centro Emisor';

comment on column FA_FACTDOCU_&1..TOT_PAGAR is
'Total a pagar en pesos';

comment on column FA_FACTDOCU_&1..TOT_CARGOSME is
'Total del documento sin deuda';

comment on column FA_FACTDOCU_&1..COD_VENDEDOR is
'codigo de vendedor';

comment on column FA_FACTDOCU_&1..COD_CLIENTE is
'Codigo de Cliente';

comment on column FA_FACTDOCU_&1..FEC_EMISION is
'Fecha de emision';

comment on column FA_FACTDOCU_&1..FEC_CAMBIOMO is
'Fecha cambio moneda';

comment on column FA_FACTDOCU_&1..NOM_USUARORA is
'Nombre Usuario Oracle';

comment on column FA_FACTDOCU_&1..ACUM_NETOGRAV is
'Acumulado del Neto Gravado';

comment on column FA_FACTDOCU_&1..ACUM_NETONOGRAV is
'Acumulado del Neto No
Gravado';

comment on column FA_FACTDOCU_&1..ACUM_IVA is
'Acumulado de Iva';

comment on column FA_FACTDOCU_&1..IND_ORDENTOTAL is
'Indice que relaciona toda la
informacion de una Factura';

comment on column FA_FACTDOCU_&1..IND_VISADA is
'Indicativo de revisada';

comment on column FA_FACTDOCU_&1..IND_LIBROIVA is
'Indicativio de si esta impresa
en el Libro de Iva';

comment on column FA_FACTDOCU_&1..IND_PASOCOBRO is
'Indicativo de Paso a Cobros';

comment on column FA_FACTDOCU_&1..IND_SUPERTEL is
'Indicativo de SuperTelefono';

comment on column FA_FACTDOCU_&1..IND_ANULADA is
'Indicativo de Anulada';

comment on column FA_FACTDOCU_&1..NUM_PROCESO is
'Numero de Proceso de
Facturacion';

comment on column FA_FACTDOCU_&1..NUM_FOLIO is
'Numero de Folio';

comment on column FA_FACTDOCU_&1..COD_PLANCOM is
'Codigo de Plan Comercial';

comment on column FA_FACTDOCU_&1..COD_CATIMPOS is
'Codigo de Categoria Impositiva';

comment on column FA_FACTDOCU_&1..FEC_VENCIMIE is
'Fecha de vencimiento';

comment on column FA_FACTDOCU_&1..FEC_CADUCIDA is
'Fecha de caducidad';

comment on column FA_FACTDOCU_&1..FEC_PROXVENC is
'Fecha de proximo vencimiento';

comment on column FA_FACTDOCU_&1..COD_CICLFACT is
'Codigo de ciclo de facturacion';

comment on column FA_FACTDOCU_&1..NUM_SECUREL is
'Secuencia de documento relacionado';

comment on column FA_FACTDOCU_&1..LETRAREL is
'Letra de documento relacionado';

comment on column FA_FACTDOCU_&1..COD_TIPDOCUMREL is
'Codigo de tipo de documento';

comment on column FA_FACTDOCU_&1..COD_VENDEDOR_AGENTEREL is
'Codigo de agente';

comment on column FA_FACTDOCU_&1..COD_CENTRREL is
'Centro emisor de documento relacionado';

comment on column FA_FACTDOCU_&1..NUM_VENTA is
'Numero de Venta asociado a la Factura';

comment on column FA_FACTDOCU_&1..NUM_TRANSACCION is
'Numero de Transaccion';

comment on column FA_FACTDOCU_&1..IMP_SALDOANT is
'Importe del Saldo Anterior';

comment on column FA_FACTDOCU_&1..IND_IMPRESA is
'Indicativo Impresa';

comment on column FA_FACTDOCU_&1..SEQ_FORCOB is
'Secuencia FORCOB';

comment on column FA_FACTDOCU_&1..SEQ_PAC is
'Secuencia PACC';

comment on column FA_FACTDOCU_&1..SEQ_SUPERTFN is
'Secuencia SUPERTFN';

comment on column FA_FACTDOCU_&1..SEQ_FORFAC is
'Secuencia FORFAC';

comment on column FA_FACTDOCU_&1..COD_OPREDFIJA is
'Codigo de Operadora Fija';

comment on column FA_FACTDOCU_&1..NUM_CTC is
'Numero CTC';

comment on column FA_FACTDOCU_&1..COD_MODVENTA is
'Modalidad de Venta';

comment on column FA_FACTDOCU_&1..TOT_FACTURA is
'Total Factura';

comment on column FA_FACTDOCU_&1..TOT_CUOTAS is
'Total Cuotas';

comment on column FA_FACTDOCU_&1..TOT_DESCUENTO is
'Total Descuento';

comment on column FA_FACTDOCU_&1..COD_BARRAS is
'codigo de barras';

comment on column FA_FACTDOCU_&1..IND_FACTUR is
'Indicativo de Facturable 1:Si 0: No';

comment on column FA_FACTDOCU_&1..COD_DESPACHO is
'Codigo de Despacho';

comment on column FA_FACTDOCU_&1..NUM_CUOTAS is 
'Numero de cuotas de la venta.';

comment on column FA_FACTDOCU_&1..NUM_PROCPASOCOBRO is
'Numero de proceso de paso Cobros';

comment on column FA_FACTDOCU_&1..COD_OFICINA is
'Oficina de Emision del Documento para Libro de Ventas';

-- PROYECTO FACTURACION:FOLIACION
comment on column FA_FACTDOCU_&1..PREF_PLAZA is
'PREFIJO PLAZA DEL FOLIO';

comment on column FA_FACTDOCU_&1..COD_OPERADORA is
'CODIGO DE LA OPERADORA';

comment on column FA_FACTDOCU_&1..COD_PLAZA is
'CODIGO DE LA PLAZA';

comment on column FA_FACTDOCU_&1..COD_ZONAIMPO is
'PREFIJO PLAZA DEL FOLIO';

comment on column FA_FACTDOCU_&1..NUM_COPIAS is
'ALMACENA LA CANTIDAD DE COPIAS EMITIDAS  DE UN DOCUMENTO';

comment on column FA_FACTDOCU_&1..NUM_DUPLICADOS is
'ALMACENA LA CANTIDAD DE DUPLICADOS EMITIDOS  DE UN DOCUMENTO';



grant SELECT on FA_FACTDOCU_&1. to  SISCEL_SELECT;
grant DELETE on FA_FACTDOCU_&1. to  ops$xpfactur;
grant INSERT on FA_FACTDOCU_&1. to  ops$xpfactur;
grant SELECT on FA_FACTDOCU_&1. to  ops$xpfactur;
grant UPDATE on FA_FACTDOCU_&1. to  ops$xpfactur;
grant SELECT on FA_FACTDOCU_&1. to  TMCROL_FACTURACION;

create public synonym FA_FACTDOCU_&1. for
      FA_FACTDOCU_&1.;
spool off
exit;
--******************************************************************************************
--** Informaci�n de Versionado *************************************************************
--******************************************************************************************
--** Pieza                                               : 
--**  %ARCHIVE%
--** Identificador en PVCS                               : 
--**  %PID%
--** Producto                                            : 
--**  %PP%
--** Revisi�n                                            : 
--**  %PR%
--** Autor de la Revisi�n                                :          
--**  %AUTHOR%
--** Estado de la Revisi�n ($TO_BE_DEFINED es Check-Out) : 
--**  %PS%
--** Fecha de Creaci�n de la Revisi�n                    : 
--**  %DATE% 
--** Worksets ******************************************************************************
--** %PIRW%
--** Historia ******************************************************************************
--** %PL%
--******************************************************************************************
