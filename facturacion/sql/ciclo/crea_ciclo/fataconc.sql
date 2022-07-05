set echo off verify off
spool $WORKDIR/log/tab_FA_FACTCONC_&1..log

--Se aplican modificaciones hechas en la operadora CH-200507052957
 
prompt Table  FA_FACTCONC_&1

CREATE TABLE FA_FACTCONC_&1
(
  IND_ORDENTOTAL   NUMBER(12)   NOT NULL,
  COD_CONCEPTO     NUMBER(9)    NOT NULL,
  COLUMNA          NUMBER(6)    DEFAULT 1       NOT NULL,
  COD_MONEDA       VARCHAR2(3)  NOT NULL,
  COD_PRODUCTO     NUMBER(1)    NOT NULL,
  COD_TIPCONCE     NUMBER(2)    NOT NULL,
  FEC_VALOR        DATE         NOT NULL,
  FEC_EFECTIVIDAD  DATE         NOT NULL,
  IMP_CONCEPTO     NUMBER(14,4) NOT NULL,
  COD_REGION       VARCHAR2(3)  NOT NULL,
  COD_PROVINCIA    VARCHAR2(5)  NOT NULL,
  COD_CIUDAD       VARCHAR2(5)  NOT NULL,
  IMP_MONTOBASE    NUMBER(14,4) NOT NULL,
  IND_FACTUR       NUMBER(1)    NOT NULL,
  IMP_FACTURABLE   NUMBER(14,4) NOT NULL,
  IND_SUPERTEL     NUMBER(1)    DEFAULT 0   NOT NULL,
  NUM_ABONADO      NUMBER(8)    DEFAULT 0   NOT NULL,
  COD_PORTADOR     NUMBER(5)    DEFAULT 0   NOT NULL,
  DES_CONCEPTO     VARCHAR2(60) NOT NULL,
  SEG_CONSUMIDO    NUMBER(9)    DEFAULT 0   NOT NULL,
  NUM_CUOTAS       NUMBER(3),
  ORD_CUOTA        NUMBER(3),
  NUM_UNIDADES     NUMBER(9),
  NUM_SERIEMEC     VARCHAR2(25),
  NUM_SERIELE      VARCHAR2(25),
  PRC_IMPUESTO     NUMBER(5,2),
  VAL_DTO          NUMBER(12,2),
  TIP_DTO          NUMBER(1),
  MES_GARANTIA     NUMBER(2),
  NUM_GUIA         NUMBER(10),
  IND_ALTA         NUMBER(1),
  NUM_PAQUETE      NUMBER(3),
  FLAG_IMPUES      NUMBER(1),
  FLAG_DTO         NUMBER(1),
  COD_CONCEREL     NUMBER(9),
  COLUMNA_REL      NUMBER(6),
  SEQ_CUOTAS       NUMBER(8),
  COD_PLANTARIF    VARCHAR2(3),
  COD_CARGOBASICO  VARCHAR2(3),
  TIP_PLANTARIF    CHAR(1),
  IMP_DCTO         NUMBER(14,4),
  IMP_REAL         NUMBER(14,4),
  DUR_DCTO         NUMBER(9),
  DUR_REAL         NUMBER(9),
  CNT_LLAM_REAL    NUMBER(8),
  CNT_LLAM_DCTO    NUMBER(8),
  CNT_LLAM_FACT    NUMBER(8),
  MIN_PLANTARIF    NUMBER(9),
  COD_OPERADOR     NUMBER(5)    DEFAULT 0                     NOT NULL,
  COD_UNIDAD       VARCHAR2(5)
)
TABLESPACE QTL_HISTCONC_SCL001
PCTUSED    60
PCTFREE    5
INITRANS   4
MAXTRANS   255
STORAGE    (INITIAL          20M
            NEXT             10M
            MINEXTENTS       1
            MAXEXTENTS       256
            PCTINCREASE      0
            FREELISTS        8
            FREELIST GROUPS  1
            BUFFER_POOL      DEFAULT)
LOGGING 
NOCACHE
NOPARALLEL;

COMMENT ON TABLE FA_FACTCONC_&1 IS 'Conceptos que pertenecen a un documento';

COMMENT ON COLUMN FA_FACTCONC_&1..TIP_DTO IS 'Tipo de Descuento 1=% 0=$';

COMMENT ON COLUMN FA_FACTCONC_&1..MES_GARANTIA IS 'Mes de Garantia del articulo';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_GUIA IS 'Numero de Guia';

COMMENT ON COLUMN FA_FACTCONC_&1..IND_ALTA IS 'Indicativo de Alta';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_PAQUETE IS 'Numero Paquete';

COMMENT ON COLUMN FA_FACTCONC_&1..FLAG_IMPUES IS 'Marca el Concepto al que se ha Aplicado Impuesto';

COMMENT ON COLUMN FA_FACTCONC_&1..FLAG_DTO IS 'Marca el Concepto al que se ha Aplicado Descuento';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_CONCEREL IS 'Codigo de Concepto Relacionado';

COMMENT ON COLUMN FA_FACTCONC_&1..COLUMNA_REL IS 'Columna Relacionada';

COMMENT ON COLUMN FA_FACTCONC_&1..SEQ_CUOTAS IS 'Secuencia de Cuotas';

COMMENT ON COLUMN FA_FACTCONC_&1..IMP_DCTO IS 'Importe descontado';

COMMENT ON COLUMN FA_FACTCONC_&1..IMP_REAL IS 'Importe real tasado';

COMMENT ON COLUMN FA_FACTCONC_&1..DUR_DCTO IS 'Tiempo descontado';

COMMENT ON COLUMN FA_FACTCONC_&1..DUR_REAL IS 'Tiempo real tasado';

COMMENT ON COLUMN FA_FACTCONC_&1..IND_ORDENTOTAL IS 'Indice que Asocia todos los Conceptos de una Factura';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_CONCEPTO IS 'Codigo de Concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..COLUMNA IS 'Secuencia';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_MONEDA IS 'Moneda del Concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_PRODUCTO IS 'Producto al que pertenece el concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_TIPCONCE IS 'Codigo de Tipo de Concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..FEC_VALOR IS 'Fecha en la que realmente se hizo efect.';

COMMENT ON COLUMN FA_FACTCONC_&1..FEC_EFECTIVIDAD IS 'Fecha de Efectividad';

COMMENT ON COLUMN FA_FACTCONC_&1..IMP_CONCEPTO IS 'Importe del concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_REGION IS 'Codigo de region';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_PROVINCIA IS 'Codigo de provincia';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_CIUDAD IS 'Codigo de ciudad';

COMMENT ON COLUMN FA_FACTCONC_&1..IMP_MONTOBASE IS 'Monto base sobre el que se aplica';

COMMENT ON COLUMN FA_FACTCONC_&1..IND_FACTUR IS 'Indicativo de Facturable';

COMMENT ON COLUMN FA_FACTCONC_&1..IMP_FACTURABLE IS 'Importe del concepto en la moneda de Facturacion';

COMMENT ON COLUMN FA_FACTCONC_&1..IND_SUPERTEL IS 'Indicativo de Super Telefono';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_ABONADO IS 'Numero de abonado';

COMMENT ON COLUMN FA_FACTCONC_&1..COD_PORTADOR IS 'Numero de Abonado';

COMMENT ON COLUMN FA_FACTCONC_&1..DES_CONCEPTO IS 'Descripcion de Concepto';

COMMENT ON COLUMN FA_FACTCONC_&1..SEG_CONSUMIDO IS 'Segundos Consumidos';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_CUOTAS IS 'Numero de Cuotas';

COMMENT ON COLUMN FA_FACTCONC_&1..ORD_CUOTA IS 'Orden Cuota';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_UNIDADES IS 'Numero de unidades';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_SERIEMEC IS 'Numero de serie mecanico (opcional)';

COMMENT ON COLUMN FA_FACTCONC_&1..NUM_SERIELE IS 'numero de serie electronico';

COMMENT ON COLUMN FA_FACTCONC_&1..PRC_IMPUESTO IS 'Porcentaje de Impuesto aplicado';

COMMENT ON COLUMN FA_FACTCONC_&1..VAL_DTO IS 'Monto o porcentaje del desCuento';


CREATE INDEX AK_FA_HISTCONC_&1._PRODUCTO ON FA_FACTCONC_&1
(COD_PRODUCTO)
LOGGING
TABLESPACE QIL_HISTCONC_SCL001
PCTFREE    5
INITRANS   8
MAXTRANS   255
STORAGE    (
            INITIAL          5M
            NEXT             5M
            MINEXTENTS       1
            MAXEXTENTS       256
            PCTINCREASE      0
            FREELISTS        8
            FREELIST GROUPS  1
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;

--Se crea nuevo indice para la relacion entre descuentos y sus cargos Inc 69334 PPV 01/10/2008
CREATE INDEX AK_FA_HISTCONC_&1._CONCEREL ON FA_FACTCONC_&1
(IND_ORDENTOTAL, COD_CONCEREL, COLUMNA_REL)
LOGGING
TABLESPACE QIL_HISTCONC_SCL001
PCTFREE    5
INITRANS   8
MAXTRANS   255
STORAGE    (
            INITIAL          5M
            NEXT             5M
            MINEXTENTS       1
            MAXEXTENTS       256
            PCTINCREASE      0
            FREELISTS        8
            FREELIST GROUPS  1
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;

CREATE UNIQUE INDEX PK_FA_HISTCONC&1 ON FA_FACTCONC_&1
(IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA)
LOGGING
TABLESPACE QIL_HISTCONC_SCL001
PCTFREE    5
INITRANS   8
MAXTRANS   255
STORAGE    (
            INITIAL          20M
            NEXT             5M
            MINEXTENTS       1
            MAXEXTENTS       256
            PCTINCREASE      0
            FREELISTS        8
            FREELIST GROUPS  1
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;


CREATE PUBLIC SYNONYM FA_FACTCONC_&1 FOR FA_FACTCONC_&1;


ALTER TABLE FA_FACTCONC_&1 ADD (
  CONSTRAINT PK_FA_HISTCONC&1 PRIMARY KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA)
    USING INDEX 
    TABLESPACE QIL_HISTCONC_SCL001
    PCTFREE    5
    INITRANS   8
    MAXTRANS   255
    STORAGE    (
                INITIAL          20M
                NEXT             5M
                MINEXTENTS       1
                MAXEXTENTS       256
                PCTINCREASE      0
                FREELISTS        8
                FREELIST GROUPS  1
               ));

GRANT SELECT ON FA_FACTCONC_&1 TO SISCEL_SELECT;
GRANT DELETE ON FA_FACTCONC_&1 TO  ops$xpfactur;
GRANT INSERT ON FA_FACTCONC_&1 TO  ops$xpfactur;
GRANT SELECT ON FA_FACTCONC_&1 TO  ops$xpfactur;
GRANT UPDATE ON FA_FACTCONC_&1 TO  ops$xpfactur;


spool off

exit;

--******************************************************************************************
--** Información de Versionado *************************************************************
--******************************************************************************************
--** Pieza                                               : 
--**  %ARCHIVE%
--** Identificador en PVCS                               : 
--**  %PID%
--** Producto                                            : 
--**  %PP%
--** Revisión                                            : 
--**  %PR%
--** Autor de la Revisión                                :          
--**  %AUTHOR%
--** Estado de la Revisión ($TO_BE_DEFINED es Check-Out) : 
--**  %PS%
--** Fecha de Creación de la Revisión                    : 
--**  %DATE% 
--** Worksets ******************************************************************************
--** %PIRW%
--** Historia ******************************************************************************
--** %PL%
--******************************************************************************************

