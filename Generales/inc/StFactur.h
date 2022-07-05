/************************************************************/
/*  -Incoporado por PGonzaleg 26-02-2002                    */
/*  Modificaciones de tipo de dato para el campo            */
/*  NUM_UNIDADES de las distintas tablas.                   */
/*      int ---> long                                       */
/************************************************************/
/*  -Incorporado por PGonzaleg 13-03-2002                   */
/*  Incorporacion del campo szCodIdioma para el             */
/*  manejo de multi idiomas                                 */
/************************************************************/
/*  -PGonzaleg 1-08-2002                                    */
/*  Modificacion del largo del los campos                   */
/*  "Codigo de Banco" de las sgtes. estructuras:            */
/*      HISTCLIE    TRANSCONTADO                            */
/*      VENTAS      CLIENTE                                 */
/************************************************************/

#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_

/* -------------------------------------------------------------------------- */
/*                     Estructuras Generales                                  */
/* -------------------------------------------------------------------------- */

typedef struct PreFactura
{
    char   szRowid         [19];      /* Rowid de la dupla                 */
    long   lNumProceso         ;      /* Numero de proceso                 */
    long   lCodCliente         ;      /* Codigo Cliente           Not Null */
    int    iCodConcepto        ;      /* Codigo Concepto          Not Null */
    long   lColumna            ;      /* Columna                  Not Null */
    short  iCodProducto        ;
    char   szCodMoneda      [4];
    char   szFecValor      [15];      /* Fecha Valor              Not Null */
    char   szFecEfectividad[15];
    double dImpConcepto        ;      /* Importe del Concepto     Not Null */
    double dImpMontoBase       ;      /* Importe Monto Base       Not Null */
    char   szCodRegion      [4];
    char   szCodProvincia   [6];
    char   szCodCiudad      [6];
    char   szCodModulo      [3];      /* Codigo del Modulo        Not Null */
    long   lCodPlanCom         ;      /* Codigo Plan Comercial        Null */
    long   iCodCatImpos        ;
    short  iIndFactur          ;
    long   lNumUnidades        ;      /* Numero de Unidades           Null */ /* Incorporado por PGonzaleg 26-02-2002 */
    short  iIndEstado          ;
    int    iCodTipConce        ;
    long   lCodCiclFact        ;      /* Codigo Ciclo Facturacion     Null */
    int    iCodConceRel        ;      /* Codigo Concepto Relacionado  Null */
    long   lColumnaRel         ;      /* Codigo Columna Relacionada   Null */
    long   lNumAbonado         ;      /* Numero Abonado               Null */
    char   szNumTerminal   [16];
    long   lCapCode            ;
    char   szNumSerieMec   [26];      /* Numero de Serie ?            Null */
    char   szNumSerieLe    [26];
    short  iFlagImpues         ;
    short  iFlagDto            ;
    float  fPrcImpuesto        ;      /* Poncentaje Imp si tipconc=1  Null */
    double dValDto             ;
    short  iTipDto             ;
    long   lNumVenta           ;      /* Numero de Venta              Null */
    long   lNumTransaccion     ;      /* Informacion que arrastro de Cargos */
    char   szNumGuia       [11];
    int    iMesGarantia        ;
    short  iIndAlta            ;
    short  iIndSuperTel        ;
    int    iNumPaquete         ;
    short  iIndCuota           ;
    int    iNumCuotas          ;
    int    iOrdCuota           ;
    char   szCodCuota       [3];      /*             ''                     */
    BOOL   bOptPenaliza        ;
    BOOL   bOptCargos          ;
    BOOL   bOptServicios       ;
    BOOL   bOptAbonos          ;
    BOOL   bOptTrafico         ;
    BOOL   bOptCuotas          ;
    BOOL   bFinCargos          ; /* Campos para la gestion de los Host Array's */
    BOOL   bFinServicios       ; /*                   ''                       */
    BOOL   bFinAbonos          ; /*                   ''                       */
    BOOL   bFinTrafico         ; /*                   ''                       */
    BOOL   bFinPenaliza        ; /*                   ''                       */
} PFACTURA;

/*****************************************************************************/
/* -Esta estructura gestiona el Insert de todos los Conceptos de un Cliente a*/
/*  facturar. El MAX_CONCFACTUR se define constante en caso de desbordamiento*/
/*  aumentar.                                                                */
/*****************************************************************************/
/*#define MAX_CONCFACTUR 60000 CH-3463 FPH Homologando Mexico*/
/* #define MAX_CONCFACTUR 99999 INC 176801 LIA 20.10.2011 */
/*#define MAX_CONCFACTUR 150000*/
#define MAX_CONCFACTUR 400000 /* INC 201172 GCASTRO 24/01/2014 - Se aumenta */

typedef struct tagFa_PreFactura
{
    long   lNumProceso     [MAX_CONCFACTUR]    ;
    long   lCodCliente     [MAX_CONCFACTUR]    ;
    int    iCodConcepto    [MAX_CONCFACTUR]    ;
    char   szDesConcepto   [MAX_CONCFACTUR][61];
    long   lColumna        [MAX_CONCFACTUR]    ;
    short  iCodProducto    [MAX_CONCFACTUR]    ;
    char   szCodMoneda     [MAX_CONCFACTUR] [4];
    char   szFecValor      [MAX_CONCFACTUR][15];
    char   szFecEfectividad[MAX_CONCFACTUR][15];
    double dImpConcepto    [MAX_CONCFACTUR]    ;
    double dImpMontoBase   [MAX_CONCFACTUR]    ;
    double dImpFacturable  [MAX_CONCFACTUR]    ;/* Importe en Moneda Facturac. */
    long   lSegConsumido   [MAX_CONCFACTUR]    ;/* En el caso de ser Trafico.  */
    char   szCodRegion     [MAX_CONCFACTUR] [4];
    char   szCodProvincia  [MAX_CONCFACTUR] [6];
    char   szCodCiudad     [MAX_CONCFACTUR] [6];
    char   szCodModulo     [MAX_CONCFACTUR] [3];
    long   lCodPlanCom     [MAX_CONCFACTUR]    ;
    int    iCodCatImpos    [MAX_CONCFACTUR]    ;
    int    iCodPortador    [MAX_CONCFACTUR]    ;
    short  iIndFactur      [MAX_CONCFACTUR]    ;
    long   lNumUnidades    [MAX_CONCFACTUR]    ;/* Incorporado por PGonzaleg 26-02-2002 */
    short  iIndEstado      [MAX_CONCFACTUR]    ;
    int    iCodTipConce    [MAX_CONCFACTUR]    ;
    long   lCodCiclFact    [MAX_CONCFACTUR]    ;
    int    iCodConceRel    [MAX_CONCFACTUR]    ;
    long   lColumnaRel     [MAX_CONCFACTUR]    ;
    long   lNumAbonado     [MAX_CONCFACTUR]    ;
    char   szNumTerminal   [MAX_CONCFACTUR][16];
    long   lCapCode        [MAX_CONCFACTUR]    ;
    char   szNumSerieMec   [MAX_CONCFACTUR][26];
    char   szNumSerieLe    [MAX_CONCFACTUR][26];
    short  iFlagImpues     [MAX_CONCFACTUR]    ;
    short  iFlagDto        [MAX_CONCFACTUR]    ;
    float  fPrcImpuesto    [MAX_CONCFACTUR]    ;
    double dValDto         [MAX_CONCFACTUR]    ;
    short  iTipDto         [MAX_CONCFACTUR]    ;
    long   lNumVenta       [MAX_CONCFACTUR]    ;
    long   lNumTransaccion [MAX_CONCFACTUR]    ;
    long   lNumCargo       [MAX_CONCFACTUR]    ;
    int    iMesGarantia    [MAX_CONCFACTUR]    ;
    char   szNumGuia       [MAX_CONCFACTUR][11];
    short  iIndAlta        [MAX_CONCFACTUR]    ;
    short  iIndSuperTel    [MAX_CONCFACTUR]    ;
    int    iNumPaquete     [MAX_CONCFACTUR]    ;
    short  iIndCuota       [MAX_CONCFACTUR]    ;
    long   lSeqCuotas      [MAX_CONCFACTUR]    ;
    int    iNumCuotas      [MAX_CONCFACTUR]    ;
    int    iOrdCuota       [MAX_CONCFACTUR]    ;
    char   szCodCuota      [MAX_CONCFACTUR] [3];
    char   szFecVenta      [MAX_CONCFACTUR][15];
    char   szCodPlanTarif  [MAX_CONCFACTUR] [4];
    char   szCodCargoBasico[MAX_CONCFACTUR] [4];
    char   szTipPlanTarif  [MAX_CONCFACTUR] [2];
    double dImpConcDescApli[MAX_CONCFACTUR]    ;
    BOOL   bOptPenaliza    [MAX_CONCFACTUR]    ;
    BOOL   bOptCargos      [MAX_CONCFACTUR]    ;
    BOOL   bOptServicios   [MAX_CONCFACTUR]    ;
    BOOL   bOptAbonos      [MAX_CONCFACTUR]    ;
    BOOL   bOptTrafico     [MAX_CONCFACTUR]    ;
    BOOL   bOptCuotas      [MAX_CONCFACTUR]    ;
    BOOL   bOptDescuento   [MAX_CONCFACTUR]    ;
    BOOL   bOptImpuesto    [MAX_CONCFACTUR]    ;
    BOOL   bOptArriendo    [MAX_CONCFACTUR]    ;

/* TOL*/
    char   szCodRegi       [MAX_CONCFACTUR] [3];
    long   lhCodGrupo      [MAX_CONCFACTUR]    ;
    long   lhCodCliente    [MAX_CONCFACTUR]    ;
    long   lhCodCiclFact   [MAX_CONCFACTUR]    ;
    long   lhNumProceso    [MAX_CONCFACTUR]    ;
    char   szIndExcedente  [MAX_CONCFACTUR] [2];
    char   szCodPlan       [MAX_CONCFACTUR] [6];
    char   szIndBillete    [MAX_CONCFACTUR] [3];
    char   szTipDcto       [MAX_CONCFACTUR] [6];
    char   szCodDcto       [MAX_CONCFACTUR] [6];
    char   szCodItem       [MAX_CONCFACTUR] [6];
    char   szIndUnidad     [MAX_CONCFACTUR] [6];
    double dhCntAux        [MAX_CONCFACTUR]    ;
    double dhMtoReal       [MAX_CONCFACTUR]    ;
    double dhMtoDcto       [MAX_CONCFACTUR]    ;
    long   lhDurReal       [MAX_CONCFACTUR]    ;
    long   lhDurDcto       [MAX_CONCFACTUR]    ;
    char   szDesPlan       [MAX_CONCFACTUR][31];
/* TOL*/
/* Tecnologia */
	char   szCodTecnologia [MAX_CONCFACTUR][8] ;
    long   lhCntLlamReal   [MAX_CONCFACTUR]    ;
    long   lhCntLlamFact   [MAX_CONCFACTUR]    ;
    long   lhCntLlamDcto   [MAX_CONCFACTUR]    ;
    char   szCod_Unidad    [MAX_CONCFACTUR][6] ;
    long   lhNumUniFree    [MAX_CONCFACTUR]    ;
    int    ihCodOperador   [MAX_CONCFACTUR]    ;

} FAPFACTURA;

typedef struct tagInd_PreFactura
{
    short  i_iIndEstado      [MAX_CONCFACTUR];
    short  i_iCodTipConce    [MAX_CONCFACTUR];
    short  i_lCodCiclFact    [MAX_CONCFACTUR];
    short  i_iCodConceRel    [MAX_CONCFACTUR];
    short  i_lColumnaRel     [MAX_CONCFACTUR];
    short  i_lNumAbonado     [MAX_CONCFACTUR];
    short  i_szNumTerminal   [MAX_CONCFACTUR];
    short  i_lCapCode        [MAX_CONCFACTUR];
    short  i_iNumUnidades    [MAX_CONCFACTUR];
    short  i_szNumSerieMec   [MAX_CONCFACTUR];
    short  i_szNumSerieLe    [MAX_CONCFACTUR];
    short  i_iFlagImpues     [MAX_CONCFACTUR];
    short  i_iFlagDto        [MAX_CONCFACTUR];
    short  i_fPrcImpuesto    [MAX_CONCFACTUR];
    short  i_dValDto         [MAX_CONCFACTUR];
    short  i_iTipDto         [MAX_CONCFACTUR];
    short  i_lNumVenta       [MAX_CONCFACTUR];
    short  i_lNumTransaccion [MAX_CONCFACTUR];
    short  i_iMesGarantia    [MAX_CONCFACTUR];
    short  i_szNumGuia       [MAX_CONCFACTUR];
    short  i_iIndAlta        [MAX_CONCFACTUR];
    short  i_iIndSuperTel    [MAX_CONCFACTUR];
    short  i_iNumPaquete     [MAX_CONCFACTUR];
    short  i_iIndCuota       [MAX_CONCFACTUR];
    short  i_iNumCuotas      [MAX_CONCFACTUR];
    short  i_iOrdCuota       [MAX_CONCFACTUR];
    short  i_szCodCuota      [MAX_CONCFACTUR];
    short  i_szFecVenta      [MAX_CONCFACTUR];
}IND_PREFACTURA;

typedef struct tagPreFactura
{
    int            iNumRegistros;
    int            iCodModVenta ;
    int            iCodZonaImpo ;
    FAPFACTURA     A_PFactura   ;
    IND_PREFACTURA A_Ind        ;
}PREFACTURA;

typedef struct tagHistClie
{
    char   szIndOrdenTotal[13];
    long   lCodCliente        ;
    char   szNomCliente   [51];
    long   lCodPlanCom        ;
    char   szNomApeClien1 [21];
    char   szNomApeClien2 [21];
/* INICIO CH-200606283727 CJG*/
/*    char   szTefCliente1  [13];
    char   szTefCliente2  [13];*/
    char   szTefCliente1  [15+1];
    char   szTefCliente2  [15+1];
/* FIN CH-200606283727 CJG*/ 
    char   szDesActividad [41];
    char   szNomCalle     [51];
    char   szNumCalle     [11];
    char   szNumPiso      [11];
    char   szDesComuna    [31];
    char   szDesCiudad    [31];
    char   szCodPais       [4];
    char   szIndDebito     [2];
    double dImpStopDebit      ;
    /*char   szCodBanco      [4];*/
    char   szCodBanco     [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szCodSucursal   [5];
    char   szIndTipCuenta  [2];
    char   szCodTipTarjeta [4];
    char   szNumCtaCorr   [19];
    char   szNumTarjeta   [19];
    char   szFecVenciTarj [15];
    /*char   szCodBancoTarj  [4];*/
    char   szCodBancoTarj [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szCodTipIdTrib  [3];
    char   szNumIdentTrib [21];
    char   szNumFax       [16];
    char   szCodIdioma     [6]; /* Incorporado por PHB 28-03-2002 */
    char   szGlsDirecClie[251]; /* Incorporado por NCH 13-06-2002 */
    char   szCodPlaza     [6];
}HISTCLIE;

typedef struct tagHistDocu
{
    char   szRowid           [19];
    long   lNumSecuenci          ;
    char   szLetra            [2];
    int    iCodTipDocum          ;
    long   lCodVendedorAgente    ;
    int    iCodCentrEmi          ;
    char   szFecValor        [15];
    double dTotCuotas            ;
    double dTotPagar             ;
    double dTotDescuento         ;
    double dTotFactura           ;
    double dTotCargosMe          ;
    long   lCodVendedor          ;
    long   lCodCliente           ;
    char   szFecEmision      [15];
    char   szFecCambioMo     [15];
    char   szNomUsuarOra     [31];
    double dAcumIva              ;
    double dAcumNetoNoGrav       ;
    double dAcumNetoGrav         ;
    char   szIndOrdenTotal   [13];
    char   szNumCTC          [13];
    short  iIndVisada            ;
    short  iIndLibroIva          ;
    short  iIndPasoCobro         ;
    short  iIndCredito           ;
    short  iIndAnulada           ;
    short  iIndSuperTel          ;
    short  iIndImpresa           ;
    long   lNumProceso           ;
    /*char   szPrefPlaza        [4]; */	/* Comentado   por PGonzalez 17-03-2004 */
    char   szPrefPlaza       [11];	/* Incorporado por PGonzalez 17-03-2004 */
    long   lNumFolio             ;
    long   lCodPlanCom           ;
    int    iCodCatImpos          ;
    char   szFecVencimie     [15];
    char   szFecCaducida     [15];
    char   szFecProxVenc     [15];
    long   lCodCiclFact          ;
    long   lNumSecuRel           ;
    char   szLetraRel         [2];
    int    iCodTipDocumRel       ;
    long   lCodVendedorAgenteRel ;
    int    iCodCentrRel          ;
    long   lNumVenta             ;
    long   lNumTransaccion       ;
    int    iCodModVenta          ;
    int    iNumCuotas            ;
    double dImpSaldoAnt          ;
    int    iCodOpRedFija         ;
    int    iIndFactur            ;
    char   szCodOficina       [3];
    int    iCodZonaImpo          ;
    char   szCodOperadora     [6];
    char   szCodPlaza         [6];

}HISTDOCU;

typedef struct tagHistConc
{
    char   szIndOrdenTotal [MAX_CONCFACTUR][13];
    int    iCodConcepto    [MAX_CONCFACTUR]    ;
    char   szDesConcepto   [MAX_CONCFACTUR][61];
    long   lColumna        [MAX_CONCFACTUR]    ;
    short  iCodProducto    [MAX_CONCFACTUR]    ;
    char   szCodMoneda     [MAX_CONCFACTUR] [4];
    char   szFecValor      [MAX_CONCFACTUR][15];
    char   szFecEfectividad[MAX_CONCFACTUR][15];
    double dImpConcepto    [MAX_CONCFACTUR]    ;
    double dImpMontoBase   [MAX_CONCFACTUR]    ;
    long   lSegConsumido   [MAX_CONCFACTUR]    ;
    char   szCodRegion     [MAX_CONCFACTUR] [4];
    char   szCodProvincia  [MAX_CONCFACTUR] [6];
    char   szCodCiudad     [MAX_CONCFACTUR] [6];
    short  iIndFactur      [MAX_CONCFACTUR]    ;
    double dImpFacturable  [MAX_CONCFACTUR]    ;
    long   lNumUnidades    [MAX_CONCFACTUR]    ;/* Incorporado por PGonzaleg 26-02-2002 */
    int    iCodTipConce    [MAX_CONCFACTUR]    ;
    int    iCodConceRel    [MAX_CONCFACTUR]    ;
    long   lColumnaRel     [MAX_CONCFACTUR]    ;
    long   lNumAbonado     [MAX_CONCFACTUR]    ;
    int    iCodPortador    [MAX_CONCFACTUR]    ;
    long   lCodCliente     [MAX_CONCFACTUR]    ;
    short  iIndSuperTel    [MAX_CONCFACTUR]    ;
    char   szNumSerieMec   [MAX_CONCFACTUR][26];
    char   szNumSerieLe    [MAX_CONCFACTUR][26];
    short  iFlagImpues     [MAX_CONCFACTUR]    ;
    short  iFlagDto        [MAX_CONCFACTUR]    ;
    float  fPrcImpuesto    [MAX_CONCFACTUR]    ;
    double dValDto         [MAX_CONCFACTUR]    ;
    short  iTipDto         [MAX_CONCFACTUR]    ;
    int    iMesGarantia    [MAX_CONCFACTUR]    ;
    char   szNumGuia       [MAX_CONCFACTUR][11];
    short  iIndAlta        [MAX_CONCFACTUR]    ;
    int    iNumPaquete     [MAX_CONCFACTUR]    ;
    long   lSeqCuotas      [MAX_CONCFACTUR]    ;
    int    iNumCuotas      [MAX_CONCFACTUR]    ;
    int    iOrdCuota       [MAX_CONCFACTUR]    ;
    char   szCodPlanTarif  [MAX_CONCFACTUR] [4];
    char   szCodCargoBasico[MAX_CONCFACTUR] [4];
    char   szTipPlanTarif  [MAX_CONCFACTUR] [2];

/* TOL*/
    double  dhMtoReal      [MAX_CONCFACTUR]    ;
    double  dhMtoDcto      [MAX_CONCFACTUR]    ;
    long    lhDurReal      [MAX_CONCFACTUR]    ;
    long    lhDurDcto      [MAX_CONCFACTUR]    ;
    long    lhCntLlamReal  [MAX_CONCFACTUR]    ;
    long    lhCntLlamFact  [MAX_CONCFACTUR]    ;
    long    lhCntLlamDcto  [MAX_CONCFACTUR]    ;
/* TOL*/
	/* tmc-04079 */
    char   szCod_Unidad    [MAX_CONCFACTUR][6] ;
    long   lhNumUniFree    [MAX_CONCFACTUR]    ;
    int    ihCodOperador   [MAX_CONCFACTUR]    ;

} HISTCONC;

typedef struct tagInd_HistConc
{
    short i_iCodConcepto    [MAX_CONCFACTUR];
    short i_iCodProducto    [MAX_CONCFACTUR];
    short i_szCodMoneda     [MAX_CONCFACTUR];
    short i_szFecValor      [MAX_CONCFACTUR];
    short i_szFecEfectividad[MAX_CONCFACTUR];
    short i_dImpConcepto    [MAX_CONCFACTUR];
    short i_dImpMontoBase   [MAX_CONCFACTUR];
    short i_szCodRegion     [MAX_CONCFACTUR];
    short i_szCodProvincia  [MAX_CONCFACTUR];
    short i_szCodCiudad     [MAX_CONCFACTUR];
    short i_szCodModulo     [MAX_CONCFACTUR];
    short i_iIndFactur      [MAX_CONCFACTUR];
    short i_iNumUnidades    [MAX_CONCFACTUR];
    short i_iCodTipConce    [MAX_CONCFACTUR];
    short i_iCodConceRel    [MAX_CONCFACTUR];
    short i_lColumnaRel     [MAX_CONCFACTUR];
    short i_lNumAbonado     [MAX_CONCFACTUR];
    short i_szNumTerminal   [MAX_CONCFACTUR];
    short i_szNumSerieMec   [MAX_CONCFACTUR];
    short i_szNumSerieLe    [MAX_CONCFACTUR];
    short i_iFlagImpues     [MAX_CONCFACTUR];
    short i_iFlagDto        [MAX_CONCFACTUR];
    short i_fPrcImpuesto    [MAX_CONCFACTUR];
    short i_dValDto         [MAX_CONCFACTUR];
    short i_iTipDto         [MAX_CONCFACTUR];
    short i_iMesGarantia    [MAX_CONCFACTUR];
    short i_szNumGuia       [MAX_CONCFACTUR];
    short i_iIndAlta        [MAX_CONCFACTUR];
    short i_iNumPaquete     [MAX_CONCFACTUR];
    short i_lSeqCuotas      [MAX_CONCFACTUR];
    short i_iNumCuotas      [MAX_CONCFACTUR];
    short i_iOrdCuota       [MAX_CONCFACTUR];
    short i_dhMtoReal       [MAX_CONCFACTUR];
    short i_dhMtoDcto       [MAX_CONCFACTUR];
    short i_lhDurReal       [MAX_CONCFACTUR];
    short i_lhDurDcto       [MAX_CONCFACTUR];
    short i_lhCntLlamReal   [MAX_CONCFACTUR];
    short i_lhCntLlamFact   [MAX_CONCFACTUR];
    short i_lhCntLlamDcto   [MAX_CONCFACTUR];
    short i_szCod_Unidad    [MAX_CONCFACTUR];
    short i_lhNumUniFree    [MAX_CONCFACTUR];
}IND_HISTCONC ;

typedef struct tagHistConcP
{
/*    int          iNumReg      ; */	/* PGG SOPORTE 8-08-2007 42970 CAMBIO DE TIPO DE DATO */  
    long          iNumReg      ;  		/* PGG SOPORTE 8-08-2007 42970 CAMBIO DE TIPO DE DATO */	
    HISTCONC     stHistConc   ;
} HISTCONCP;

/* Numero Maximo de Abonados por Cliente */
/*    #define NUM_ABONADOS_CLIENTE 3400 CH-3643 FPH*/
/*#define NUM_ABONADOS_CLIENTE 100000 INC 202872 - JTE 120514*/ 
/* #define NUM_ABONADOS_CLIENTE 50000 */ /*PBI000000012038 en este problema se define que la cantidad de abonados por clientes queda asi- PPQL*/ 

#define NUM_ABONADOS_CLIENTE 60000 /* INC INC000001293497 - 1-OCT-2018 */

typedef struct tagHistAbo
{
    int    iCodProducto         ;
    char   szIndOrdenTotal  [13];
    long   lNumAbonado          ;
    long   lCodCliente          ;
    double dTotCargosMe         ;
    double dAcumCargo           ;
    double dAcumIva             ;
    double dAcumDto             ;
    char   szNumTerminal    [16];
    long   lCapCode             ;
    short  iCodDetFact          ;
    char   szFecFinContra   [15];
    short  iIndFactur           ;
    int    iCodCredMor          ;
    long   lCodGrupo            ;
    char   szNomUsuario     [21];
    char   szNomApellido1   [21];
    char   szNomApellido2   [21];
    char   szCodPlanTarif    [4];
    double dLimCredito          ;
    short  iIndSuperTel         ;
    char   szNumTeleFija    [16];
    char   szFecPeriDesde   [15];
    char   szFecPeriHasta   [15];

}HISTABO;

typedef struct tagHistAboP
{
    int      iNumReg;
    HISTABO *pAbo   ;
} HISTABOP;

/***********************************************************/
/* rao20030812: Proyecto Apertura contable por tecnologia  */
/***********************************************************/
typedef struct tagHistTec
{
    char   	szIndOrdenTotal  [13];
    long 	lNumAbonado			 ;
    int    	iCodConcepto    	 ;
    long   	lColumna        	 ;
    char	szCodTecnologia  [8] ;
    float	fPrcTecnologia	 	 ;
}HISTECNO;

typedef struct tagHistTecp
{
    int      iNumReg;
    HISTECNO *pTec   ;
} HISTECNOP;


/***********************************************************/



/* Numero de Productos Posibles */
    #define iNPROD 5

typedef struct tagAcumProd
{
    int    iCodProducto   [iNPROD]    ;
    char   szIndOrdenTotal[iNPROD][13];
    double dTotProducto   [iNPROD]    ;
    char   szDesTotalProd [iNPROD][61];
    double dAcumCargo     [iNPROD]    ;
    char   szDesAcumCargo [iNPROD][61];
    double dAcumDto       [iNPROD]    ;
    char   szDesAcumDto   [iNPROD][61];
    double dAcumIva       [iNPROD]    ;
    char   szDesAcumIva   [iNPROD][61];
}ACPROD;

typedef struct tagAcumuloProd
{
    int    iNumReg ;
    ACPROD stAcProd;
}ACUMPROD;


typedef struct tagNotaCD
{
    long     lNumSecuenci         ;
    char     szLetra           [2];
    int      iCodTipDocum         ;
    long     lCodVendedorAgente   ;
    int      iCodCentrEmi         ;
    char     szIndOrdenTotal  [13];
    char     szFecEmision     [15];
    long     lCodCliente          ;
    /*char     szPrefPlaza      [4] ;*/	/* Comentado   por PGonzalez 17-03-2004 */
    char     szPrefPlaza      [11];     /* Incorporado por PGonzalez 17-03-2004 */
    long     lNumFolio            ;
    long     lCodPlanCom          ;
    long     iCodCatImpos         ;
    int      iNumConceptos        ;
    int      iCodZonaImpo         ;
    char     szCodPlaza        [6];
    char     szCodOperadora    [6];
    char     szCodOficina      [3];
    long     lCodCiclFact	  ;
    HISTCONC A_HistConc           ;
}NOTACD;


typedef struct tagFACTURA
{
    long   lNumProceso       ;
    int    iCodTipDocum      ;
    long   lCodVendedorAgente;
    char   szLetra       [2] ;
    int    iCodCentrEmi      ;
    long   lNumSecuenci      ;
    long   lCodCliente       ;
    long   lNumAbonado       ;
    short  iCodProducto      ;
    long   lCodCiclFact      ;
    char   szFecVencimie[15] ;
    char   szFecCaducida[15] ;
    double dTotPagar         ;
}FACTURA;

typedef struct tagArriendo
{
    char   szRowid      [19];
    long   lCodCliente      ;
    long   lNumAbonado      ;
    char   szFecDesde   [15];
    char   szFecHasta   [15];
    int    iNumDiasArriendo ;
    int    iCodProducto     ;
    int    iCodConcepto     ;
    char   szDesConcepto[61];
    long   lCodArticulo     ;
    double dPrecioMes       ;
    double dImpConcepto     ;
    char   szCodMoneda   [4];
    char   szCodGrpServ  [3];
    char   szCodModulo   [3];
}ARRIENDO;

typedef struct tagFactCli
{
    short iIndPenaliza        ;
    short iIndPagare          ;
    short iIndCargos          ;
    char  szFecUltPagare  [15];
    char  szFecUltPenaliza[15];
    char  szFecUltCargos  [15];
}FACTCLI;

typedef struct tagConcepExt
{
    char   szRowid      [19];
    int    iCodTipDocum     ;
    long   lCodCliente      ;
    int    iCodConcepto     ;
    char   szDesConcepto[61];
    long   lColumna         ;
    char   szCodMoneda   [4];
    short  iCodProducto     ;
    double dImpConcepto     ;
    double dImpMontoBase    ;
    float  fPrcImpues       ;
    double dValDto          ;
    short  iTipDto          ;
    char   szUsuario    [31];
    char   szFecValor   [15];
    int    iCodConceRel     ;
    long   lColumnaRel      ;
    long   lNumProceso      ;
    char   szDesDto     [41];
}CONCEPEXT;


typedef struct tagCATIMPCLIENTES
{
    char   szRowid       [19];
    long   lCodCliente       ;
    char   szFecDesde    [15];
    char   szFecHasta    [15];
    int    iCodCatImpos      ;
} CATIMPCLIENTES          ;

typedef struct tagZonaImpositiva
{
    char   szRowid        [19];
    int    iCodZonaImpo       ;
    char   szDesZonaImpo  [41];
}ZONAIMPOSITIVA            ;

typedef struct tagCONCEPTO
{
    short  iFlagExiste	     ;
    short  iCodProducto      ;
    char   szDesConcepto [61];
    int    iCodTipConce      ;
    char   szCodModulo   [3] ;
    char   szCodMoneda   [4] ;
    short  iIndActivo        ;
    int    iCodConcOrig      ;
    char   szCodTipDescu [2] ;
    short  sIndTecnologia    ;
    char   szDefTecnologia[8];
    int    iCodConCobr       ;
    /*CONCEPTO_MI *pstConcepto_mi;*/
} CONCEPTO                ;

/* Definicion de estructura para solucion de multiidiomas */
/* CDescouv 27-03-2002                                    */
typedef struct tagCONCEPTO_MI
{
    int    iCodConcepto      ;
    char   szCodIdioma   [6] ;
    char   szDesConcepto [61];
} CONCEPTO_MI;

typedef struct tagRangoConcepto
{
    int iCodConcIni;
    int iCodConcFin;
    long  lIndInicial;
    long  lIndFinal  ;
}RANGO_CONCEPTO ;

typedef struct tagIndConcepto
{
    long            lNumRangos    ;
    RANGO_CONCEPTO *pRangoConcepto;
}IND_CONCEPTO;

/* Tamano de cada Rango en el puntero de Indices de Conceptos */
    #define iRANGO_CONCEPTO 1000

IND_CONCEPTO stIndConcepto;

IND_CONCEPTO stIndConcepto_mi;

typedef struct tagRangoTabla
{
    long  lCodCiclFact  ;
    long  lRangoIni     ;
    long  lRangoFin     ;
    int   iCodProducto  ;
    char  szNomTabla[21];
}RANGOTABLA;

typedef struct tagDesAcumulado
{
    int   iCodProducto      ;
    char  szDesTotalProd[61];
    char  szDesAcumCargo[61];
    char  szDesAcumIva  [61];
    char  szDesAcumDto  [61];
}DESACUMULADO;

/* ----- Datos Generales Ciclo de Facturacion (FA_CICLFACT) -----  */

typedef struct tagCiclo
{
    char  szRowid          [19];   /* Rowid                    NOT NULL */
    char  szRowidCiclo     [19];   /* Rowid Fa_Ciclos          NOT NULL */
    int   iCodCiclo            ;   /* Codigo Ciclo N(1)        NOT NULL */
    int   iAno                 ;   /* Ano del Ciclo     N(2)   NOT NULL */
    long  lCodCiclFact         ;   /* Ciclo Facturacion N(5)   NOT NULL */
    char  szFecEmision     [15];   /* Fecha Emision     (Date) NOT NULL */
    char  szFecVencimie    [15];   /* Fecha Vencimeinto (Date) NOT NULL */
    char  szFecCaducida    [15];   /* Fecha Caducidad   (Date) NOT NULL */
    char  szFecProxVenc    [15];   /* Fecha Prox. Venc. (Date) NOT NULL */
    char  szFecDesdeLlam   [15];   /* Fecha Desde LLamadas     NOT NULL */
    char  szFecHastaLlam   [15];   /* Fecha Hasta LLamadas     NOT NULL */
    char  szFecDesdeCFijos [15];   /* Fecha Desde Cargos Fijos NOT NULL */
    char  szFecHastaCFijos [15];   /* Fecha Hasta Cargos Fijos NOT NULL */
    char  szFecDesdeOCargos[15];   /* Fecha Desde Otros Cargos NOT NULL */
    char  szFecHastaOCargos[15];   /* Fecha Hasta Otros Cargos NOT NULL */
    char  szFecDesdeRoa    [15];   /* Fecha Desde Roaming      NOT NULL */
    char  szFecHastaRoa    [15];   /* Fecha Hasta Roaming      NOT NULL */
    char  szFecDCFijosAnt  [15];   /* Fecha Desde Cargos Fijos NOT NULL */
    char  szFecHCFijosAnt  [15];   /* Fecha Hasta Cargos Fijos NOT NULL */
    char  szFecHMenos      [15];   /* FecDesdeCFijos-1/86400            */
    short iIndFacturacion      ;   /* Indicativo de Factura    NOT NULL */
    int   iDiaPeriodo          ;
    char  szDirLogs       [101];
    char  szDirSpool      [101];
    char  szDesLeyen1      [81];
    char  szDesLeyen2      [81];
    char  szDesLeyen3      [81];
    char  szDesLeyen4      [81];
    char  szDesLeyen5      [81];
    int   iInd_Tasacion        ; /* SAAM-20030116 Nuevo Campo de Estructura TOL*/
    int   iDigD                ;
    int   iDigC                ;
    int   iDigSec              ;
}CICLO;


typedef struct tagGeImpuestos
{
    char  szRowid        [19];
    int   iCodCatImpos       ;
    int   iCodZonaImpo       ;
    int   iCodTipImpues      ;
    int   iCodGrpServi       ;
    int   iCodConcGene       ;
    char  szFecDesde     [15];
    char  szFecHasta     [15];
    float fPrcImpuesto       ;
}IMPUESTOS                ;

typedef struct tagPlanCtoPlan
{
    char  szRowid            [19];
    long  lCodPlanCom            ;
    short iCodProducto           ;
    long  lCodCtoPlan            ;
    char  szFecEfectividad   [15];
    char  szFecFinEfectividad[15];
    char  szNomUsuario       [31];
}PLANCTOPLAN;

typedef struct tagCtoPlan
{
    char   szRowid       [19];
    long   lCodCtoPlan       ;
    short  iCodProducto      ;
    char   szCodTipCtoPlan[2];
    char   szCodMoneda    [4];
    int    iCodCtoFac        ;
    double dImpDescuento     ;
    short  iCodTipoDto       ;
    short  iIndCuadrante     ;
    short  iCodTipoCuad      ;
    char   szNomUsuario  [31];
    double dImpUmbDesde      ;
    double dImpUmbHasta      ;
    int    iNumDias          ;
}CTOPLAN;


typedef struct tagCuadCtoPlan
{
    char   szRowid      [19];
    long   lCodCtoPlan      ;
    double dImpUmbDesde     ;
    double dImpUmbHasta     ;
    double dImpDescuento    ;
    short  iCodTipoDto      ;
}CUADCTOPLAN;

typedef struct tagGeZonaCiudad
{
    char  szFecDesde     [15];
    char  szFecHasta     [15];
    char  szCodRegion     [4];
    char  szCodProvincia  [6];
    char  szCodCiudad     [6];
    int   iCodZonaImpo       ;
}ZONACIUDAD                 ;

typedef struct tagFaGrpserconc
{
    int   iCodConcepto       ;
    char  szFecDesde     [15];
    int   iCodGrpServi       ;
    char  szFecHasta     [15];
}GRPSERCONC               ;

typedef struct tagDIRECCIONES
{
    char   szRowid        [19];
    long   lCodDireccion      ;
    char   szCodRegion    [4] ;
    char   szCodProvincia [6] ;
    char   szCodCiudad    [6] ;
    char   szCodComuna    [6] ;
    char   szNomCalle     [51];
    char   szNumCalle     [11];
    char   szNumPiso      [11];
    char   szNumCasilla   [16];
    char   szObsDireccion [51];
    char   szGls_DirecClie[250]; /* Incorporado por PGonzaleg  9-04-2002 */
}DIRECCIONES               ;


typedef struct tagDIRECCLI
{
    char   szRowid        [19];
    long   lCodCliente        ;
    short  iCodTipDireccion   ;
    long   lCodDireccion      ;
}DIRECCLI                  ;

typedef struct tagComunas
{
    char   szRowid        [19];
    char   szCodRegion     [4];
    char   szCodProvincia  [6];
    char   szCodComuna     [6];
    char   szDesComuna    [31];
    int    iAntiguedad        ;
}COMUNAS;

/* Numero Max. de Registros de la Cache de Comunas */
    #define MAX_COMUNAS 100

typedef struct tagCacheComunas
{
    COMUNAS A_Comunas [MAX_COMUNAS];
    int     iContador              ;
}C_COMUNAS;

typedef struct tagProvincias
{
    char  szRowid       [19];
    char  szCodRegion    [4];
    char  szCodProvincia [6];
    char  szDesProvincia[31];
}PROVINCIAS;

typedef struct tagCiudades
{
    char  szRowid       [19];
    char  szCodRegion    [4];
    char  szCodProvincia [6];
    char  szCodCiudad    [6];
    char  szDesCiudad   [31];
    char  szCodCelda     [8];
    short iIndCiudad        ;
    int   iAntiguedad       ;
    char   szCodPlaza [6] ;
}CIUDADES;

typedef struct tagCorreo
{
    char szCodRegion     [4];
    char szCodProvincia  [6];
    char szCodCiudad     [6];
    char szDesCiudad    [31];
    char szCodComuna     [6];
    char szDesComuna    [31];
    char szNomCalle     [51];
    char szNumCalle     [11];
    char szNumPiso      [11];
    char szGls_DirecClie[250]; /* Incorporado por PGonzaleg  9-04-2002 */
}CORREO;

typedef struct tagAlms
{
    char szCodAlm  [4];
    char szDesAlm [31];
}ALMS;

/* Numero Max. de Registros de la Cache de Ciudades */
    #define MAX_CIUDADES 100

typedef struct tagCacheCiudad
{
    CIUDADES A_Ciudades [MAX_CIUDADES];
    int      iContador                ;
}C_CIUDADES;


typedef struct tagRegiones
{
    char szRowid     [19];
    char szCodRegion  [4];
    char szDesRegion [31];

}REGIONES;

typedef struct tagTipImpues
{
    char   szRowid        [19];
    int    iCodTipImpue       ;
    char   szDesTipImpue  [41];
    double dImpUmbral         ;
}TIPIMPUES                 ;

typedef struct tagActividades
{
    char  szRowid       [19];
    int   iCodActividad     ;
    char  szDesActividad[51];
}ACTIVIDADES;

typedef struct tagCatImpositiva
{
    char   szRowid        [19];
    int    iCodCatImpos       ;
    char   szDesCatImpos  [41];
}CATIMPOSITIVA             ;

typedef struct tagLimCreditos
{
    char  szRowid       [19];
    int   iCodCredMor       ;
    int   iCodProducto      ;
    char  szCodCalClien  [3];
    char  szDesCredMor  [41];
    double dImpMorosidad    ;
}LIMCREDITOS;

typedef struct tagCargos
{
    char   szRowid       [19];
    long   lNumProceso       ;
    long   lNumCargo         ;
    long   lNumVenta         ;
    long   lCodCliente       ;
    short  iCodProducto      ;
    int    iCodConcepto      ;
    char   szDesConcepto [61];
    long   lColumna          ;
    char   szFecAlta     [15];
    double dImpCargo         ;
    char   szCodMoneda    [4];
    long   lCodPlanCom       ;
    long   lNumUnidades      ;/* Incorporado por PGonzaleg 26-02-2002 */
    long   lNumAbonado       ;
    char   szNumTerminal [16];
    long   lCodCiclFact      ;
    char   szNumSerie    [26];
    char   szNumSerieMec [26];
    long   lCapCode          ;
    int    iIndCuota         ;
    int    iMesGarantia      ;
    char   szNumPreGuia  [11];
    char   szNumGuia     [11];
    long   lNumTransaccion   ;
    long   lNumFactura       ;
    int    iCodConceptoDto   ;
    double dValDto           ;
    int    iTipDto           ;
    short  iIndFactur        ;
    int    iNumPaquete       ;
    short  iIndSuperTel      ;
    char   szCodRegion    [4];
    char   szCodProvincia [6];
    char   szCodCiudad    [6]; /* Informacion de Ga_Ventas o de Cliente */
    char   szCodCuota     [3]; /* Informacion de Ga_Ventas              */
    int    iCodModVenta      ; /* Informacion de Ga_Ventas              */
    char   szCodModulo    [3]; /* Informacion a nivel del Concepto      */
    char   szCodTecnologia[8];
}CARGOS;

typedef struct tagVentas
{
    char   szRowid        [19];
    long   lNumVenta          ;
    short  iCodProducto       ;
    char   szCodOficina    [3];
    long   lCodVendedor       ;
    long   lCodVendedorAgente ;
    int    iNumUnidades       ;
    char   szFecVenta     [15];
    char   szCodRegion     [4];
    char   szCodProvincia  [6];
    char   szCodCiudad     [6];
    char   szIndEstVenta   [2];
    char   szCodTipContrato[4];
    short  iIndTipVenta       ;
    long   lNumTransaccion    ;
    long   lCodCliente        ;
    int    iCodModVenta       ;
    int    iTipValor          ;
    char   szCodTipTarjeta [4];
    char   szNumTarjeta   [19];
    char   szCodAutTarj   [20];
    char   szFecVenciTarj [15];
    /*char   szCodBancoTarj [16];*/
    char   szCodBancoTarj [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szNumCtaCorr   [19];
    char   szNumCheque    [21];
    /*char   szCodBanco      [4];*/
    char   szCodBanco     [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szCodSucursal   [5];
    char   szCodCuota      [3];
}VENTAS;

typedef struct tagTransContado
{
    char   szRowid         [19];
    long   lNumTransaccion     ;
    short  iCodProducto        ;
    char   szCodOficina     [3];
    long   lCodVendedorAgente  ;
    int    iNumUnidades        ;
    char   szFecTransaccion[15];
    char   szCodRegion      [4];
    char   szCodProvincia   [6];
    char   szCodCiudad      [6];
    double dImpVenta           ;
    char   szCodMoneda      [4];
    short  iIndPasoCob         ;
    char   szNomUsuarOra   [31];
    long   lCodCliente         ;
    int    iTipValor           ;
    char   szCodCuota       [3];
    char   szCodTipTarjeta  [4];
    char   szNumTarjeta    [19];
    char   szCodAutTarj    [20];
    char   szFecVenciTarj  [15];
    /*char   szCodBancoTarj   [4]; */
    char   szCodBancoTarj  [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szNumCtaCorr    [19];
    char   szNumCheque     [21];
    /*char   szCodBanco       [4];*/
    char   szCodBanco      [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char   szCodSucursal    [5];
}TRANSCONTADO;

typedef struct tagLetras
{
    char  szRowid      [19];
    int   iCodTipDocum     ;
    int   iCodCatImpos     ;
    char  szLetra       [2];
}LETRAS;

typedef struct tagSecuenciasEmi
{
    char szRowid     [19];
    int  iCodTipDocum    ;
    int  iCodCentrEmi    ;
    char szLetra      [2];
    long lNumSecuenci    ;
}SECUENCIASEMI;

typedef struct tagFeriados
{
    char szFecFeriado  [15];
}FERIADOS;



/* -------------------------------------------------------------------------- */
/*  Estructuras Imagen TOL_Acumoper                                           */
/* -------------------------------------------------------------------------- */

#define MAX_ACUMTOL             5000 /* SAAM-20030529 Según correo de R Arzola a N Contreras 20030430 04:44 */
#define MAX_TOLPROMO            3000
#define MAX_TOLDCTO             3000
#define MAX_TOLPROMODCTO_MI     3000
#define MAX_TOLDESCRIPCIONES	3000


typedef struct stConcTOL
{
    char    szhRowid[19];
    char    szCodRegi[3];
    long    lhCodGrupo;
    long    lhCodCliente;
    long    lhNumAbonado;
    long    lhCodCiclFact;
    long    lhNumProceso;
    char    szIndExcedente[2];
    char    szCodPlan[6];
    char    szIndBillete[3];
    int     ihCodCarg;
    char    szTipDcto[6];
    char    szCodDcto[6];
    char    szCodItem[6];
    char    szIndUnidad[6];
    double  dhCntInicial;
    double  dhCntAux;
    double  dhMtoReal;
    double  dhMtoFact;
    double  dhMtoDcto;
    long    lhDurReal;
    long    lhDurFact;
    long    lhDurDcto;
    char    szDesConcepto[61];
    int     iCodTipConce;
    char    szCodMoneda[4];
    int     iCodProducto;
    int     iCodOperador;
    char    szDesPlan[31];
    long    lCntLlamReal;
    long    lCntLlamFact;
    long    lCntLlamDcto;
}CONCTOL;

typedef struct tagACUMTOL
{
    int iNumATOL;
    CONCTOL asATOL[MAX_ACUMTOL];
} tagACUMTOL;

typedef struct TOLPROMO
{
    char   szRowid       [19];
    char   szUnidadPromo [6] ;
    int    iCodConcepto      ;
    char   szFecDesde    [15];
    char   szFecHasta    [15];
    char   szFecUltMod   [15];
    char   szNomUsuario  [31];
    char   szDesPromo    [61];
}TOLPROMO              ;

typedef struct tagTOLPROMO
{
    int iNumTolPromo;
    TOLPROMO asTolPromo[MAX_TOLPROMO];
}tagTOLPROMO;

typedef struct TOLPROMODCTO_MI
{
    int     iCodProducto;
    char    szCodConcepto [13];
    char    szCodIdioma   [6] ;
    char    szDesConcepto [256];
} TOLPROMODCTO_MI;

typedef struct tagTOLPROMODCTO_MI
{
    int iNumTolPromoDcto;
    TOLPROMODCTO_MI asTolPromoDcto_MI[MAX_TOLPROMODCTO_MI];
}tagTOLPROMODCTO_MI;


typedef struct TOLDCTO
{
    char  szhRowid    [19] ;
    char  szTipDcto   [6]  ;
    char  szCodDcto   [6]  ;
    char  szGlsDcto   [41] ;
    char  szIndAplica [5]  ;
    char  szFecIniVig [15] ;
    char  szFecTerVig [15] ;
    char  szCodUser   [31] ;
    char  szFecUmod   [15] ;
    int   iNTipDcto        ;
}TOLDCTO;

typedef struct tagTOLDCTO
{
    int iNumTolDcto;
    TOLDCTO asTolDcto[MAX_TOLDCTO];
}tagTOLDCTO;


typedef struct TOLDescripcion
{
    char  szTipDcto		[6] ;
    int   iCodConcepto		;
    char  szDescripcion	[61];
}TOLDescripcion;

typedef struct tagTOLDescripcion
{
    int iNumTolDesc;
    TOLDescripcion asTolDesc[MAX_TOLDESCRIPCIONES];
}tagTOLDescripcion;


/*------------------------ Estructura del Modulo de Tarificaion -------------*/
typedef struct tagTaConcepFact
{
    short  iCodProducto    ;
    int    iCodFacturacion ;
    short  iIndTabla       ;
    short  iIndEntSal      ;
    int    iCodTarificacion;
    int    iIndDestino     ;
    char   szCodServicio[6];  /* Incorporado por NCONTRER 26-04-2002 */
}TACONCEPFACT;

typedef struct tagFactCarriers
{
    int    iCodConcFact   ;
    int    iCodConcCarrier;
}FACTCARRIERS;

typedef struct tagConcTar
{
    char   szRowid       [19]; /* Tabla Ta_ConcepFact */
    long   lNumAbonado       ;
    short  iCodProducto      ;
    int    iCodFacturacion   ;
    char   szDesConcepto [61];
    int    iCodTipConce      ;
    char   szCodMoneda    [4];
    short  iIndTabla         ;
    short  iIndEntSal        ;
    double dImpConsumido     ;
    long   lSegConsumido     ;
    long   lNumPulsos        ;
    long   lNumProceso       ;
    int    iCodOperador      ;
    int    iCodFranHoraSoc   ;
    long   lNumAlquiler      ; /* Ga_InfacRent   */
    long   lNumEstaDia       ; /* Ga_InfacRoaVis */
    int    iCarrier          ; /* 1: Fortas 2 : Foradi */
    int    iIndDestino       ;
    char   szCodPlanTarif [4];
    char   szCod_Unidad  [6];
    long   lhNumUniFree      ;
    int    iCodTarificacion	 ;
    char   szCodServicioOrig[6];  /* rao: cta unica */
    int		 iValParametro;  /* PGG - 193496 - 28-03-2013 */  
} CONCTAR;

typedef struct tagAbonTar
{
    char     szRowid [19]; /* Rowid del reg. de la tablas Ga_Infa% */
    long     lNumAbonado ;
    short    iCodProducto;
    int      iIndFactur  ;
    int      iNumConcTar ;
    int      iNumConcTOL ;
    CONCTAR* pConcTar    ;
    CONCTOL* pConcTOL    ;
}ABONTAR;


/*--------------- Estructura de Penalizaciones del SAC ---------------------*/
typedef struct tagPenaliza
{
    char   szRowid         [19];
    long   lCodCliente         ;
    int    iTipIncidencia      ;
    char   szFecEfectividad[15];
    char   szCodMoneda      [4];
    char   szCodModulo      [3];
    double dImpPenaliz         ;
    long   lCodCiclFact        ;
    int    iCodConcepto        ;
    char   szDesConcepto   [61];
    int    iCodTipConce        ;
    short  iIndActivo          ;
    short  iIndFactur          ;
    int    iCodProducto        ;
    long   lNumAbonado         ;
    long   lNumProceso         ;
} PENALIZA                   ;

/*-------------------------- Estructuras Servicios -------------------------*/
typedef struct TagServicios
{
    int    iCodConcepto     ;
    char   szDesConcepto[61];
    char   szCodMoneda   [4];
    double dImpConcepto     ;
    double dImpPeriodo      ;
    int    iNumDiasPro      ;
    int    iNumPeriodos     ;
    BOOL   bIndCargo        ;
    char   szFecAltaCen [15];
    char   szFecBajaBD  [15];
    long   lColumna         ;
}SERVICIOS;

typedef struct TagSERVABO
{
    char       szRowid      [19];
    long       lNumAbonado      ;
    int        iCodProducto     ;
    char       szFecDesde   [15];
    char       szFecHasta   [15];
    char       szCodPlanServ[4] ;
    char       szCodGrpServ [3] ;
    char       szNumTerminal[16];
    short      iIndAlta         ;
    short      iIndFactur       ;
    char       szFecValor   [15];
    long       lCapCode         ;
    long       lCodPlanCom      ;
    SERVICIOS* pServicios       ;
    int        iNumServicios    ;
}SERVABO;

typedef struct tagCBasico
{
    char   szRowid         [19];/* Rowid de Ga_Intar%                          */
    int    iCodAbono           ;/* Codigo de Concepto del Abono (Ge_DatosGener)*/
    char   szDesAbono      [61];/* Descripcion del Concepto Abono              */
    int    iCodAbonoFin        ;/* Codigo de Concepto de Fin Abono "     "     */
    char   szDesAbonoFin   [61];/* Descripcion del Concepto AbonoFin           */
    char   szCodMoneda      [4];
    char   szCodMonedaFin   [4];
    char   szCodModulo      [3];
    int    iNumDiasAbono       ;/* Dias Prorratebles del Abono                 */
    int    iNumPerAbono        ;/* Numero de Periodos a factura del Abono      */
    int    iNumDiasFin         ;/* Dias Hasta Fin de Contrato                  */
    double dImpPeriodo         ;/* Importe de Cargo Basico                     */
    double dImpConcepto        ;/* ImpDiasAbono + dImpPeriodo * iNumPerAbono   */
    double dImpFinContrato     ;
    char   szFecDesde      [15];/* Ga_Infac% */
    char   szFecHasta      [15];/* Ga_Infac% */
    char   szCodCargoBasico[4] ;
    char   szTipPlanTarif  [2] ;/* I: Individual, H: Holding, E: Empresa       */
    char   szCodPlanTarif  [4] ;
    long   lCodGrupo           ;
    char   szCodPlanServ   [4] ;
    char   szCodGrpServ    [3] ;
    long   lCodPlanCom         ;
    char   szNumTerminal   [16];
    long   lCapCode            ;
    char   szCod_Unidad   [6] ; /* Tipo de unidades del plan tarifario 	   */
    long   lNumUniFree		   ; /* Numero de minutos libres del plan		   */
}CARGOFIJO;

typedef struct tagAbonos
{
    char   szRowid         [19];/* Rowid de Ga_Infac% (% =>iCodProducto)       */
    long   lNumAbonado         ;
    short  iCodProducto        ;
    short  iIndAlta            ;
    int    iIndActuacOld       ;
    int    iIndActuacNew       ;
    short  iIndFactur          ;
    short  iIndCargos          ;/* Indicativo de Cargos                        */
    short  iIndPenaliza        ;/* Indicativo de Penalizaciones a Nivel Abono  */
    short  iIndCuotas          ;
    short  iIndArriendo        ;/* Indicativo de Arriendo a Nivel Abono        */
    int    iIndCargoPro        ;
    int    iIndBloqueo         ;
    char   szFecAlta       [15];/* Ga_Intar% */
    char   szFecBaja       [15];
    char   szFecFinContrato[15];
    char   szNumTerminal   [16];
    char   szCodGrpServ    [3] ;
    char   szTipPlanTarif  [2] ;/* I: Individual, H: Holding, E: Empresa       */
    char   szCodPlanTarif  [4] ;/* Plan Tarifario en vigencia                  */
    long   lCodGrupo           ;
    long   lCodPlanCom         ;
    BOOL   bPlanOptimo         ;/* True al Abonado se le Aplicado Plan Optimo */
    long   lColumna            ;
    int    iIndCuenControlada  ;
    int    iNumCBasicos        ;
    CARGOFIJO *pstCBasico      ;
}ABONOS;


typedef struct tagAboRent
{
    long     lNumAbonado     ;
    long     lNumAlquiler    ;
    char     szFecAlta   [15];
    char     szFecBaja   [15];
    long     lNumCelular     ;
    short    iIndActuac      ;
    short    iIndDetalle     ;
    short    iIndPenaliza    ;
    int      iNumConcTar     ;
    CONCTAR *pConcTar        ;
}ABORENT;

typedef struct tagAboRoaV
{
    long     lNumAbonado     ;
    long     lNumEstaDia     ;
    char     szFecAlta   [15];
    char     szFecBaja   [15];
    long     lNumCelular     ;
    long     lNumCelularOrig ;
    short    iIndActuac      ;
    short    iIndFactur      ;
    short    iIndPenaliza    ;
    short    iIndCargos      ;
    int      iNumConcTar     ;
    CONCTAR *pConcTar        ;
}ABOROAVIS;

typedef struct tagCuotas
{
    char   szRowid     [19];
    long   lSeqCuotas      ;
    int    iOrdCuota       ;
    char   szFecEmision[15];
    double dImpCuota       ;
    short  iIndFacturado   ;
    short  iIndFactur      ;
    short  iIndPagado      ;
}CUOTAS;

typedef struct tagCabCuotas
{
    char    szRowid      [19];
    long    lSeqCuotas       ;
    long    lCodCliente      ;
    int     iCodConcepto     ;
    char    szDesConcepto[61];
    char    szCodMoneda   [4];
    char    szCodModulo   [3];
    short   iCodProducto     ;
    int     iNumCuotas       ;
    double  dImpTotal        ;
    short   iIndPagada       ;
    long    lNumAbonado      ;
    char    szCodCuota    [3];
    long    lNumPagare       ;
    int     iNCuotas         ;
    CUOTAS *pCuotas          ;
}CABCUOTAS;


typedef struct tagCicloCli
{
    char   szRowid       [19];
    long   lCodCliente       ;
    int    iCodCiclo         ;
    short  iCodProducto      ;
    long   lNumAbonado       ;
    char   szCodCalClien  [3];
    char   szNumTerminal [16];
    short  iIndCambio        ;
    short  iIndFactur        ;
    short  iIndDetalle       ;
    char   szIndDebito    [2];
    short  iIndSuperTel      ;
    int    iCodCredMor       ;
    char   szNomUsuario  [21];
    char   szNomApellido1[21];
    char   szNomApellido2[21];
    char   szFecFinContra[15];
    char   szNumTeleFija [16];
    char   szFecAlta     [15];
    char   szCodPlanTarif [4];
    int    iCodCicloNue      ;
    long   lCapCode          ;
    long   lCodGrupo         ;
    double dTotCargosMe      ;
    char   szFecUltFact  [15];
    char   szCodTecnologia[8];
    char   szFecPeriDesde   [15];
    char   szFecPeriHasta   [15];
}CICLOCLI;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
typedef struct tag_FAC_CLIENTES
{
    long   lRowNum           ;
    long   lCargos           ;
    long   lCodCliente       ;
    int    iCodEstado        ;
    pthread_mutex_t mMutexLock;
    char   szNomCliente   [51];
    char   szNomApeClien1 [21];
    char   szNomApeClien2 [21];
    char   szTefCliente1  [16];
    char   szTefCliente2  [16];
    char   szCodPais       [4];
    char   szIndDebito     [2];
    double dImpStopDebit      ;
    char   szCodBanco     [16];
    char   szCodSucursal   [5];
    char   szIndTipCuenta  [2];
    char   szCodTipTarjeta [4];
    char   szNumCtaCorr   [19];
    char   szNumTarjeta   [19];
    char   szFecVenciTarj [15];
    char   szCodBancoTarj [16];
    char   szCodTipIdTrib  [3];
    char   szNumIdentTrib [21];
    int    iCodActividad      ;
    char   szCodOficina    [3];
    int    iIndFactur         ;
    char   szNumFax       [16];
    char   szFecAlta      [15];
    long   lCodCuenta         ;
    char   szCodIdioma    [6] ;
    char   szCodOperadora  [6];
    int    iCodCatImpos		;
    char   szIndOrdenTotal[13]	;
    char   szCodRegion_1 [4]   	;
    char   szCodProvincia_1 [6]	;
    char   szCodCiudad_1 [6]  	;
    char   szCodComuna_1 [6]  	;
    char   szNomCalle_1  [51]  	;
    char   szNumCalle_1  [11]  	;
    char   szNumPiso_1   [11] 	;
    char   szCodRegion_3 [4]   	;
    char   szCodProvincia_3 [6]	;
    char   szCodCiudad_3 [6]  	;
    char   szCodComuna_3 [6]  	;
    char   szNomCalle_3  [51]  	;
    char   szNumCalle_3  [11]  	;
    char   szNumPiso_3   [11] 	;
    char   szCodBancoUniPac[16];
}FAC_CLIENTES;

typedef struct tag_FAC_CICLO		
{                                   
    char   szRowid       [19];      
    long   lCodCliente       ;      
    int    iCodCiclo         ;      
    short  iCodProducto      ;      
    long   lNumAbonado       ;      
    char   szCodCalClien  [3];      
    char   szNumTerminal [16];      
    short  iIndCambio        ;      
    short  iIndFactur        ;      
    short  iIndDetalle       ;      
    char   szIndDebito    [2];      
    short  iIndSuperTel      ;      
    int    iCodCredMor       ;      
    char   szNomUsuario  [21];      
    char   szNomApellido1[21];      
    char   szNomApellido2[21];      
    char   szFecFinContra[15];      
    char   szNumTeleFija [16];      
    char   szFecAlta     [15];      
    char   szCodPlanTarif [4];      
    int    iCodCicloNue      ;      
    long   lCapCode          ;      
    long   lCodGrupo         ;      
    double dTotCargosMe      ;      
    char   szFecUltFact  [15];      
    char   szCodTecnologia[8];      
    char   szFecPeriDesde   [15];
    char   szFecPeriHasta   [15];
}FAC_CICLO;                         
                                    
typedef struct tag_FAC_PID          
{
    int    iPID;
}FAC_PID;
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

typedef struct tagAbonoCli
{
    long      lNumAbonados;
    CICLOCLI *pCicloCli   ;
}ABONOCLI;

typedef struct tagGAbonoCli
{
    long      lNumReg    ;
    ABONOCLI *pstAbonoCli;
}GABONOCLI;

/* ----- Datos Generales Cliente ----- */
typedef struct tagCliente
{
    long          lCodCliente        ; /* Codigo Cliente                       */
    char          szFecAlta      [15];
    int           iCodCatImpos       ; /* Categoria impositiva cliente         */
    long          lCodPlanCom        ;
    short         iIndFactur         ;
    char          szCodCalClien   [3]; /* Calidad Cliente                      */
    char          szCodOficina    [3];
    char          szIndDebito     [2];
    double        dImpStopDebit      ;
    char          szNomCliente   [51];
    char          szNomApeClien1 [21];
    char          szNomApeClien2 [21];
/* INICIO CH-200606283727 CJG*/
/*    char          szTefCliente1  [13];
    char          szTefCliente2  [13];*/
    char          szTefCliente1  [15+1];
    char          szTefCliente2  [15+1];    
/* FIN CH-200606283727 CJG*/    
    char          szCodPais       [4];
    char          szCodRegion     [4];
    char          szDesRegion    [31];
    char          szCodProvincia  [6];
    char          szDesProvincia [31];
    char          szCodCiudad     [6];
    char          szDesCiudad    [31];
    char          szCodComuna     [6];
    char          szDesComuna    [31];
    char          szNomCalle     [51];
    char          szNumCalle     [11];
    char          szNumPiso      [11];
    /*char          szCodBanco      [4];*/
    char          szCodBanco     [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char          szCodSucursal   [5];
    char          szIndTipCuenta  [2];
    char          szCodTipTarjeta [4];
    char          szNumCtaCorr   [19];
    char          szNumTarjeta   [19];
    char          szFecVenciTarj [15];
    /*char          szCodBancoTarj  [4];*/
    char          szCodBancoTarj [16]; /* Modificacion Incorporada por PGonzaleg 1-08-2002 */
    char          szCodTipIdTrib  [3];
    char          szNumIdentTrib [21];
    int           iCodActividad      ;
    double        dImpRecargo        ; /* Importe de Recargos -> Cobros        */
    double        dImpSaldoAnt       ; /* Haber-Debe en Co_Cartera (MonedaCobr)*/
    char          szNumFax       [16];
    int           iCodOpRedFija      ;
    char          szTipPlanTarif  [2];
    char          szTableCelular [21];
    char          szTableBeeper  [21];
    char          szTableTrunk   [21];
    char          szTableTrek    [21];
    char          szTableGene    [21];
    short         iIndCredito        ;
    short         iIndSuperTel       ;
    ABOROAVIS*    pAboRoaVis         ;
    ABORENT*      pAboRent           ;/* Abonado de Rent Phone                */
    int           iNumAbonados       ;
    ABONTAR*      pAbonados          ;/* Modulo Tarificacion                  */
    int           iNumPenaliza       ;
    PENALIZA*     pPenaliza          ;/* Modulo S.A.C                         */
    int           iNumServAbo        ;
    SERVABO*      pServAbo           ;/* Servicios suplementarios del abonado */
    int           iNumAbonos         ;
    ABONOS*       pAbonos            ;/* Modulo Abonados                      */
    int           iNumCargos         ;
    CARGOS*       pCargos            ;/* Modulo Cargos                        */
    int           iNumCabCuotas      ;
    CABCUOTAS*    pCabCuotas         ;/* Cuotas de Cliente y Abonado          */
    int           iNumArriendos      ;
    ARRIENDO*     pArriendo          ;
    short         iModVenta          ;/* Valores Posibles 1 y 2 :             */
    long          lCodCuenta         ; /* Codigo de Cuenta                    */
    char          szCodIdioma    [6] ; /* Incorporado por PGonzaleg 13-03-2002*/
    char          szGls_DirecClie[250];/* Incorporado por PGonzaleg  9-04-2002*/
    char          szCodOperadora [6] ; /* Codigo de la operadora del Cliente  */
} CLIENTE                           ;/*   1 =>Unica modalidad de Venta en    */
                                     /*       PVenta (Contado o Credito)     */
                                     /*   2 =>Contado y Credito en una Venta */

/*typedef struct tagConcColumna
{
    int  iCodConcepto;
    long lColumna    ;
}CONCOLUMNA;

typedef struct tagMaxColPreFa
{
    int        iNumConceptos;
    CONCOLUMNA *pConcCol    ;
}MAXCOLPREFA;*/

typedef struct tagConcDto
{
    long    lCodCtoPlan            ;
    int     iCodCtoFac             ;
    char    szDesConcepto      [61];
    char    szCodTipCtoPlan    [2] ;
    short   iCodProducto           ;
    char    szCodMoneda        [4] ;
    double  dImpDescuento          ;
    char    szNomUsuario       [31];
    short   iCodTipoDto            ;
    short   iIndCuadrante          ;
    short   iCodTipoCuad           ;
    int     iNumDias               ;
    double  dImpUmbDesde           ;
    double  dImpUmbHasta           ;
    char    szFecEfectividad   [15];
    char    szFecFinEfectividad[15];
} CTODTO                         ;


typedef struct tagConversion
{
    /*char   szRowid      [19];*/
    char   szCodMoneda   [4];
    char   szFecDesde   [15];
    char   szFecHasta   [15];
    double dCambio          ;
    /*char   szCodUsuario [31];*/
}CONVERSION               ;

typedef struct tagTarifas
{
/*    char   szRowid      [19];
    short  iCodProducto     ;
    char   szCodActAbo   [3];*/
    char   szCodTipServ  [2];
    char   szCodServicio [4];
    char   szCodPlanServ [4];
    char   szFecDesde   [15];
    double dImpTarifa       ;
    char   szCodMoneda   [4];
    char   szIndPeriodico[2];
    char   szFecHasta   [15];
}TARIFAS;

typedef struct tagAlDocumSucursal
{
    char  szRowid     [19];
    char  szCodOficina [3];
    int   iCodTipDocum    ;
    int   iCodCentrEmi    ;
}DOCUMSUCURSAL;

typedef struct tagPlanTarif
{
    short iCodProducto        ;
    char  szCodPlanTarif  [4] ;
    char  szTipTerminal   [2] ;
    char  szCodLimConsumo [4] ;
    char  szCodCargoBasico[4] ;
    char  szCodMoneda     [4] ;
    char  szTipPlanTarif  [2] ;
    char  szCod_Unidad   [6] ;
    long  lNumUnidades        ;
    short iIndArrastre        ;
    int   iNumDias            ;
    long  lNumAbonados        ;
    char  szFecDesde      [15];
    char  szFecHasta      [15];
    char  szInd_Francons  [3] ;
}PLANTARIF;

typedef struct tagCargosBasico
{
    short  iCodProducto        ;
    char   szCodCargoBasico[4] ;
    char   szFecDesde      [15];
    char   szFecHasta      [15];
    double dImpCargoBasico     ;
    char   szCodMoneda      [4];
}CARGOSBASICO;

typedef struct tagActuaServ
{
/*    char   szRowid      [19];
    short  iCodProducto     ;
    char   szCodActAbo  [3] ;*/
    char   szCodTipServ [2] ;
    char   szCodServicio[4] ;
    int    iCodConcepto     ;
}ACTUASERV;

typedef struct tagGrupoCob
{
    char   szCodGrupo  [3] ;
    short  iCodProducto    ;
    int    iCodConcepto    ;
    int    iCodCiclo       ;
    char   szFecDesde  [15];
    char   szFecHasta  [15];
    short  iTipCobro       ;
    short  iTipCobroAnt    ;
}GRUPOCOB;

typedef struct tagOptimo
{
    char   szCodPlanTarif [4];
    long   lMinDesde         ;
    long   lMinHasta         ;
    float  fPrcAbono         ;
    float  fPrcNormal        ;
    float  fPrcBajo          ;
}OPTIMO;

typedef struct tagOperador
{
    int  iCodOperador      ;
    char szDesOperador [31];
}OPERADORES;

typedef struct tagGOperador
{
    int         iNumReg    ;
    OPERADORES *pstOperador;
}GOPERADORES;

typedef struct tagSEspeciales
{
    int  iCodOperador          ;
    char szNumServEspecial [13];
    char szDesServEspecial [31];
}SERVESPECIALES;

typedef struct tagGSEspeciales
{
    int             iNumReg;
    SERVESPECIALES *pstSEsp;
}GSERVESPECIALES;

typedef struct tagTiposTerminales
{
    int    iCodProducto       ;
    char  szTipTerminal    [2];
    char  szDesTerminal   [16];
}TIPOSTERMINALES;

typedef struct tagGTiposTerminales
{
    int                        iNumReg;
    TIPOSTERMINALES    *pstTipTerminal;
}GTIPOSTERMINALES;

typedef struct tagTipCobertura
{
    int  iTipCobertura      ;
    char szDesTipCobert [31];
    char szCodServicio   [4];
    int  iCodProducto       ;
}TIPCOBERTURA;

typedef struct tagGTipCobertura
{
    int                    iNumReg;
    TIPCOBERTURA  *pstTipCobertura;
}GTIPCOBERTURA;

/*****************************************************************************/
/* rao20040505:																 */
/*****************************************************************************/
#define TAM_HOSTS_PEQ 2000

#define TAM_HOSTS_PEQ_OF 2500   /* INC INC000001293497 - 1-OCT-2018 */ 

typedef struct tagOficina
{
	char szCodOficina	[3];
	char szCodRegion	[4];
	char szCodProvincia	[6];
	char szCodCiudad 	[6];
	char szCodPlaza		[6];
}OFICINA;

typedef struct tagOficina_Hosts
{
	char szCodOficina	[TAM_HOSTS_PEQ_OF][3];
	char szCodRegion	[TAM_HOSTS_PEQ_OF][4];
	char szCodProvincia	[TAM_HOSTS_PEQ_OF][6];
	char szCodCiudad 	[TAM_HOSTS_PEQ_OF][6];
	char szCodPlaza		[TAM_HOSTS_PEQ_OF][6];
}OFICINA_HOSTS;

typedef struct tagOficinas
{
    int         iNumOficinas;
    OFICINA  	*stOficina;
}OFICINAS;


typedef struct tagFactCobr
{
	int iCodConcFact;
	int	iCodConCobr;
}FACTCOBR;

typedef struct tagFactCobr_Hosts
{
	int 	iCodConcFact[TAM_HOSTS_PEQ];
	int 	iCodConCobr	[TAM_HOSTS_PEQ];
}FACTCOBR_HOSTS;

typedef struct tagFactCobros
{
    int         iNumFactCobros;
    FACTCOBR  	*stFactCobr;
}FACTCOBROS;


typedef struct tagOperServEsp
{
	int  iCodOperEspe   ;
	char szCodUnidad [6];
	int  iNumFactor     ;
}OPERSERVESP;

typedef struct tagOperServEsp_Hosts
{
	int  iCodOperEspe [TAM_HOSTS_PEQ]   ;
	char szCodUnidad  [TAM_HOSTS_PEQ][6];
	int  iNumFactor   [TAM_HOSTS_PEQ]   ;

}OPERSERVESP_HOSTS;

typedef struct tagOperSerEsp
{
    int         iNumOperSerEsp;
    OPERSERVESP *stOperServEspec;
}OPERSERVESPS;

typedef struct tagDetPlanDesc
{
	char 	szCodPlan 			[6] ;
    char 	szCodTipeval      	[2] ;
    char 	szCodTipapli      	[2] ;
    int  	iCodGrupoeval 		;
    int  	iCodGrupoapli 		;
    int  	iNumCuadrante 		;
    char 	szTipUnidad      	[3] ;
    int  	iCodConcdesc 			;
    double 	dMtoMinfact  			;

}DETPLANDESC;

typedef struct tagDetPlanDesc_Hosts
{
	char 	szCodPlan 			[TAM_HOSTS_PEQ][6] ;
    char 	szCodTipeval      	[TAM_HOSTS_PEQ][2] ;
    char 	szCodTipapli      	[TAM_HOSTS_PEQ][2] ;
    int  	iCodGrupoeval 		[TAM_HOSTS_PEQ]	;
    int  	iCodGrupoapli 		[TAM_HOSTS_PEQ]	;
    int  	iNumCuadrante 		[TAM_HOSTS_PEQ]	;
    char 	szTipUnidad      	[TAM_HOSTS_PEQ][3] ;
    int  	iCodConcdesc 		[TAM_HOSTS_PEQ]	;
    double 	dMtoMinfact  		[TAM_HOSTS_PEQ]	;

    short  	i_shCodGrupoeval   [TAM_HOSTS_PEQ]	;
    short 	i_shCodGrupoapli   [TAM_HOSTS_PEQ]	;
    short 	i_shNumCuadrante   [TAM_HOSTS_PEQ]	;
    short 	i_shCodConcdesc    [TAM_HOSTS_PEQ]	;
    short 	i_shMtoMinfact     [TAM_HOSTS_PEQ]	;

}DETPLANDESC_HOSTS;

typedef struct tagDetPlanDescs
{
    int         iNumRegs;
    DETPLANDESC *stDetPlanDesc;
}DETPLANDESCS;
/*PILDORITA RAO*/
typedef struct tagConcColumna
{
    int  iFlagExiste ;
    long lColumna   ;
}CONCOLUMNA;


typedef struct tag_DetCarg_Puntuales
{
    long   lCodCliente     ;
    long   lNumAbonado     ;
    int    iCodTipDescu    ;
    long   lCodConcCargo   ;
    long   lCodConcDesc    ;
    double dMtoDcto        ;
    double dMtoAplicado    ;
    char   szRowid         [19];
}DETCARG_PUNTUALES;

typedef struct tag_DetCarg_Puntuales_host
{
    long   lCodCliente       [TAM_HOSTS_PEQ];
    long   lNumAbonado       [TAM_HOSTS_PEQ];
    int    iCodTipDescu      [TAM_HOSTS_PEQ];
    long   lCodConcCargo     [TAM_HOSTS_PEQ]; 
    long   lCodConcDesc      [TAM_HOSTS_PEQ];
    double dMtoDcto          [TAM_HOSTS_PEQ];
    double dMtoAplicado      [TAM_HOSTS_PEQ];
    char   szRowid           [TAM_HOSTS_PEQ][19];
}DETCARG_PUNTUALES_HOSTS;

typedef struct tag_DetCarga_Puntuales
{
    int iNumDetCargPunt;
    DETCARG_PUNTUALES *stDetCargPunt;
}DETCARGA_PUNTUALES;


/*****************************************************************************/
/* Defincion de constantes simbolicas, que estiman de manera aproximada siem-*/
/* al alza, del numero de reg. que tienen las distintas tablas que se van a  */
/* cargar en memoria . En caso de desbordamiento, al efectuar la carga de una*/
/* tabla, la ejecucion se aborta y se debe modificar la constante correspon- */
/* diente (con una estimacion sensiblemente mayor al count(*) sobre la tabla)*/
/* y volver a makear los fuentes.                                            */
/*****************************************************************************/
#define MAX_PROVINCIAS     10000         /* Ge_Provincias     */
#define MAX_REGIONES       1000         /* Ge_Regiones       */
#define MAX_CATIMPCLIENTES 1000         /* Ge_CatImpClientes */
#define MAX_CATIMPOSITIVA  1000         /* Ge_CatImpositiva  */
#define MAX_ZONAIMPOSITIVA 100          /* Ge_ZonaImpositiva */
#define MAX_ACTIVIDADES    2000         /* Ge_Actividades    */
#define MAX_IMPUESTOS      500          /* Ge_Impuestos      */
/* #define MAX_CONVERSION     2000          Ge_Conversion     */
/* #define MAX_CONVERSION     5000 */ /* 3500*/         /* Ge_Conversion     *//*87145*/

#define MAX_CONVERSION     10000  /* PGG - 182804 - 03-04-2012 */
   
#define MAX_LETRAS         100          /* Ge_Letras         */
#define MAX_DIRECCIONES    1            /* Ge_Direcciones    */
#define MAX_ZONACIUDAD     3500         /* Ge_ZonaMuni       */
#define MAX_TIPIMPUES      50           /* Ge_TipImpues      */
#define MAX_CARGOS         15000        /* Ge_Cargos         */
#define MAX_DIRECCLI       1000         /* Ga_DirecCli       */
/*#define MAX_DOCUMSUCURSAL  35000         Al_Docum_Sucursal */
#define MAX_DOCUMSUCURSAL  50000        /* Al_Docum_Sucursal *//*87145*/
#define MAX_GRPSERCONC     50000        /* Fa_GrpSerConc     */
#define MAX_CONCEPTOS      50000        /* Fa_Conceptos      */
#define MAX_CONCEPTOS_MI   50000        /* Ge_MultiIdiomas   */
#define MAX_CICLFACT       2000         /* Fa_CiclFact       */
#define MAX_CABCUOTAS      15000        /* Fa_CabCuotas      */
#define MAX_CUOTAS         50000        /* Fa_Cuotas         */
#define MAX_ARRIENDO       10000        /* Fa_Arriendo       */
/*#define MAX_RANGOTABLA     500           Fa_Rango_Tabla    *//*INC 202872 - JTE 120514*/ 
#define MAX_RANGOTABLA     700          /* Fa_Rango_Tabla    */
#define MAX_DESACUMULADO   10           /* Fa_DesAcumulado   */
#define MAX_PENALIZACIONES 5000         /* Ca_Penalizaciones */
/* #define MAX_TARIFAS        2000    */     /* Ga_Tarifas        */
#define MAX_TARIFAS        5000        /* PGG - 1174950 - 4-06-2018 */
/* #define MAX_ACTUASERV      2000    */     /* Ga_ActuaServ      */
#define MAX_ACTUASERV      5000        /* PGG - 1174950 - 4-06-2018 */
#define MAX_PLANCTOPLAN    5000         /* Ve_Plan_CtoPlan   */
#define MAX_CTOPLAN        5000         /* Ve_CtoPlan        */
#define MAX_CUADCTOPLAN    5000         /* Ve_CuadCtoPlan    */
#define MAX_TACONCEPFACT   3000         /* Ta_ConcepFact     */
#define MAX_FACTCARRIERS   500          /* Fa_FactCarriers   */
/* #define MAX_PLANTARIF      5000      *//* Ta_PlanTarif    */	/* PGG SOPORTE 3-08-07 42905 */ 
/* #define MAX_CARGOSBASICO   5000      *//* Ta_CargosBasico */ /* PGG SOPORTE 3-08-07 42905 */ 
/*#define MAX_PLANTARIF      7000          Ta_PlanTarif      */ /* 87145 */ 
/*#define MAX_PLANTARIF      15000 *//*9000*/         /* Ta_PlanTarif      */ /* PGG SOPORTE 3-08-07 42905 */ /*CMD --189483-- ADELANTANDOME PARA QUE NO SE CAIGA LA WEA,CUANDO HICE UNA PRUEBA SE CAYO POR ESTO SE AGRANDA A 17000--*/
/*#define MAX_PLANTARIF      17000*/
/*#define MAX_PLANTARIF      21000 *//*GCASTRO 24-01-2014 - se aumenta*//*INC 202872 - JTE 120514*/
/*#define MAX_PLANTARIF      25000 *//*21000*//*Ta_PlanTarif*/
#define MAX_PLANTARIF      30000  /* PGG - 1174950 - 4-06-2018 */  
/*#define MAX_CARGOSBASICO   20000 *//*9000*/         /* Ta_CargosBasico   *//*INC 202872 - JTE 120514*/  
/*#define MAX_CARGOSBASICO   25000 *//*20000*/         /* Ta_CargosBasico   */ 
#define MAX_CARGOSBASICO   30000   /* PGG - 1174950 - 4-06-2018 */ 

/*#define MAX_GRUPOCOB       60000         Fa_Grupocob       ***FPH*/
#define MAX_GRUPOCOB       80000        /* Fa_Grupocob       JEM - INC 182804 */
#define MAX_LIMCREDITOS    100          /* Co_LimCreditos    */
#define MAX_OPTIMO         1000         /* Fa_Optimo         */
#define MAX_ALMS           50           /* Ge_Alms           */
/* #define MAX_OPERADORES     500         */ /* Ta_Operadores     */ /* Homologado por PGonzalez 23-08-2004 CH-200403091727 */
#define MAX_OPERADORES     1000         /* Ta_Operadores     */
/*#define MAX_FERIADOS       100*/          /* Ta_DiasFest       */ /*CMD --189483-- ADELANTANDOME PARA QUE NO SE CAIGA LA WEA,CUANDO HICE UNA PRUEBA SE CAYO POR ESTO SE AGRANDA A 105--*/
/*#define MAX_FERIADOS       150*/
#define MAX_FERIADOS       300 /*GCASTRO 24-01-2014 - se aumenta*/
              /* Ta_DiasFest       */ 
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
/*#define MAX_ABONADOS	   60000          Fa_CicloCli       */
/* #define MAX_ABONADOS	   100000         INC 201172 GCASTRO 24/01/2014 - Se aumenta */
/* #define MAX_ABONADOS	   50000       */  /*PBI000000012038 en este problema se define que la cantidad de abonados por clientes queda asi- PPQL*/ 

#define MAX_ABONADOS    60000          /* INC INC000001293497 - 1-OCT-2018  */ 

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

/*    Declaracion de Array's globales para la carga de tablas en memoria     */
/*****************************************************************************/
#undef access
#ifdef _GENFA_PC_
    #define access
#else
    #define access extern
#endif /* fin _GENFA_PC_      */

access PROVINCIAS     pstProvincias     [MAX_PROVINCIAS]    ;
access REGIONES       pstRegiones       [MAX_REGIONES]      ;
access ALMS           pstAlms           [MAX_ALMS]          ;
access CATIMPCLIENTES pstCatImpClientes [MAX_CATIMPCLIENTES];
access ACTIVIDADES    pstActividades    [MAX_ACTIVIDADES]   ;
access CARGOS         pstCargos         [MAX_CARGOS]        ;
access LIMCREDITOS    pstLimCreditos    [MAX_LIMCREDITOS]   ;
access CICLO          pstCiclFact       [MAX_CICLFACT]      ;
access ZONAIMPOSITIVA pstZonaImpositiva [MAX_ZONAIMPOSITIVA];
access CATIMPOSITIVA  pstCatImpositiva  [MAX_CATIMPOSITIVA] ;
access TIPIMPUES      pstTipImpues      [MAX_TIPIMPUES]     ;
access DIRECCLI       pstDirecCli       [MAX_DIRECCLI]      ;
access DIRECCIONES    pstDirecciones    [MAX_DIRECCIONES]   ;
access GRPSERCONC     pstGrpSerConc     [MAX_GRPSERCONC]    ;
access ZONACIUDAD     pstZonaCiudad     [MAX_ZONACIUDAD]    ;
access IMPUESTOS      pstImpuestos      [MAX_IMPUESTOS]     ;
access CONCEPTO_MI    pstConceptos_mi   [MAX_CONCEPTOS_MI]  ;
access ARRIENDO       pstArriendo       [MAX_ARRIENDO]      ;
access RANGOTABLA     pstRangoTabla     [MAX_RANGOTABLA]    ;
access DESACUMULADO   pstDesAcumulado   [MAX_DESACUMULADO]  ;
access PENALIZA       pstPenalizaciones [MAX_PENALIZACIONES];
access TACONCEPFACT   pstTaConcepFact   [MAX_TACONCEPFACT  ];
access FACTCARRIERS   pstFactCarriers   [MAX_FACTCARRIERS]  ;
access CONVERSION     pstConversion     [MAX_CONVERSION]    ;
access TARIFAS        pstTarifas        [MAX_TARIFAS]       ;
access PLANCTOPLAN    pstPlanCtoPlan    [MAX_PLANCTOPLAN]   ;
access CTOPLAN        pstCtoPlan        [MAX_CTOPLAN]       ;
access CUADCTOPLAN    pstCuadCtoPlan    [MAX_CUADCTOPLAN]   ;
access LETRAS         pstLetras         [MAX_LETRAS]        ;
access DOCUMSUCURSAL  pstDocumSucursal  [MAX_DOCUMSUCURSAL] ;
access CABCUOTAS      pstCabCuotas      [MAX_CABCUOTAS]     ;
access CUOTAS         pstCuotas         [MAX_CUOTAS]        ;

access ACTUASERV      pstActuaServ      [MAX_ACTUASERV]     ;
access CARGOSBASICO   pstCargosBasico   [MAX_CARGOSBASICO]  ;
access PLANTARIF      pstPlanTarif      [MAX_PLANTARIF]     ;
access GRUPOCOB       pstGrupoCob       [MAX_GRUPOCOB]      ;
access OPTIMO         pstOptimo         [MAX_OPTIMO]        ;
access OPERADORES     pstOperadores     [MAX_OPERADORES]    ;
access FERIADOS       pstFeriados       [MAX_FERIADOS]      ;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
access FAC_CICLO      pstAbonados	[MAX_ABONADOS]      ;
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
access CONCOLUMNA     pstMaxColPreFa     [MAX_CONCEPTOS];/*Pildorita RAO*/
access int            iArrCiclo         [MAX_CICLFACT]      ;


access GSERVESPECIALES   stGServEspeciales ;
access GTIPOSTERMINALES  stGTiposTerminales;
access GTIPCOBERTURA     stGTipCoberturas  ;
access OFICINAS			 pstOficinas	   ;
access FACTCOBROS		 pstFactCobros	   ;
access OPERSERVESPS		 pstOperServEspec  ;
access DETPLANDESCS		 pstDetPlanDescs   ;
access DETCARGA_PUNTUALES 	 pstDescPuntual    ;

access CONCEPTO          *pstConceptos      ;

/*****************************************************************************/
/* Variables globales que indican el numero de registros que contiene cada   */
/* tabla carga en memoria en el momento de la ejecucion.                     */
/*****************************************************************************/
access int  NUM_PROVINCIAS    ;
access int  NUM_REGIONES      ;
access int  NUM_ALMS          ;
access int  NUM_CATIMPCLIENTES;
access int  NUM_SOLICITUD     ;
access int  NUM_CARGOS        ;
access int  NUM_CICLFACT      ;
access int  NUM_ZONAIMPOSITIVA;
access int  NUM_CATIMPOSITIVA ;
access int  NUM_ACTIVIDADES   ;
access int  NUM_TIPIMPUES     ;
access int  NUM_DIRECCLI      ;
access int  NUM_DIRECCIONES   ;
access int  NUM_GRPSERCONC    ;
access int  NUM_ZONACIUDAD    ;
access int  NUM_IMPUESTOS     ;
access int  NUM_CONCEPTOS     ;
access long  NUM_CONCEPTOS_MI  ;
access int  NUM_RANGOTABLA    ;
access int  NUM_DESACUMULADO  ;
access int  NUM_ARRIENDOS     ;
access int  NUM_PENALIZACIONES;
access int  NUM_TACONCEPFACT  ;
access int  NUM_FACTCARRIERS  ;
access int  NUM_CONVERSION    ;
access int  NUM_TARIFAS       ;
access int  NUM_PLANCTOPLAN   ;
access int  NUM_CTOPLAN       ;
access int  NUM_CUADCTOPLAN   ;
access int  NUM_LETRAS        ;
access int  NUM_DOCUMSUCURSAL ;
access int  NUM_ACTUASERV     ;
access int  NUM_PLANTARIF     ;
access int  NUM_CARGOSBASICO  ;
access int  NUM_GRUPOCOB      ;
access int  NUM_CABCUOTAS     ;
access int  NUM_CUOTAS        ;
access int  NUM_LIMCREDITOS   ;
access int  NUM_OPTIMO        ;
access int  NUM_OPERADORES    ;
access int  NUM_FERIADOS      ;

access int  NUM_IARRCICLO     ;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
access long  NUM_FAC_CICLO     ;
access long  NUM_ABONADOS      ;
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

#endif /* fin _ESTRUCTURAS_H_ */
/******************************************************************************************/
/** Información de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisión                                            : */
/**  %PR% */
/** Autor de la Revisión                                : */
/**  %AUTHOR% */
/** Estado de la Revisión ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creación de la Revisión                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/
