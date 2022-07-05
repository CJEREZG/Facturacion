/* ***********************************************
Nombre : PlanDcto.h
Autor  : Guido Antio Cares
*********************************************** */
#ifndef _DESCUENTOS_H_
#define _DESCUENTOS_H_

/* Librerias                        */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <GenFA.h>
#include <trazafact.h>
#include <geora.h>


/*#define     MAX_REGISTROS       1000 42136 CJG*/
#define     MAX_REGISTROS       3000 /*42136 CJG*/
#define     UNIDADMINUTOS       "MI"
#define     MONTOFACTURA        "MT"
#define     CANTIDADABONADOS    "CA"
#define     ANTIGUEDADCLIENTE   "AN"
#define     CONCEPTOBLIGADO     "1"
#define     CONCEPTONOBLIGADO   "0"
#define     PORCONCEPTO         "C"
#define     PORFACTURA          "F"
#define     TIPOPORCENTAJE      "P"
#define     TIPOMONTO           "M"
#define     TIPOENTGRUPO        "G"
#define     TIPOENTABONA        "A"
#define     TIPOENTCLIEN        "C"

/*#define     MAX_PLANES          10 Incidencia 37998 12/03/07*/
#define     MAX_PLANES          6  /* XXXXX CJG 25/06/07*/
#define     MAX_PLANES_ABO      20     /*42136 CJG*/

#define     NUM_VERSION         "1.0"
#define     FECHA_VERSION       "21-12-2004"

#define lRANGO_DESC_PUNTUAL 10000 /* PGG - 183297 - Probando performance - 17-04-2012 */
/*#define lRANGO_DESC_PUNTUAL 95 */ /* PGG - 183297 - Probando performance - 17-04-2012 */

/****************************************************************/
/* Estructuras                                                  */
/****************************************************************/
/* PGG - 183297 - Probando performance / Estructura nueva usada solo para el update - 17-04-2012 */
typedef struct tag_HA_DESC_PUNTUAL
{
    double dMtoDescuento   [lRANGO_DESC_PUNTUAL];
    double dMtoSaldo       [lRANGO_DESC_PUNTUAL];
    char   szRowid         [lRANGO_DESC_PUNTUAL][19];
    char   szIndOrdenTotal [lRANGO_DESC_PUNTUAL][13];
}HA_DESC_PUNTUAL;


typedef struct tagPLANDCTO
{
/*    char   szDes_Plandesc      [31];
    char   szInd_Restriccion   [2] ;*/
    char   szCod_Tipeval       [2] ;
    char   szCod_Tipapli       [2] ;
    int    iCod_Grupoeval          ;
    int    iCod_Grupoapli          ;
    int    iNum_Cuadrante          ;
    char   szTip_Unidad        [3] ;
    int    iCod_Concdesc           ;
    double dMto_Minfact            ;
    long   lNumSecuencia           ;
    int    iCodEstado              ;
}PLANDCTO;

/****************************************************************/
typedef struct tagPLANDESC
{
    char        szCod_Plandesc[6]       ;
    int         iCodEstado              ;
    char        szTipEntidad  [6]       ;
    PLANDCTO    stPD                    ;
}PLANDESC;

typedef struct tagREGPLANABO
{
    long        lNumAbonado             ;
    int         iNumPlanes              ;
/*    PLANDESC    stPlanDes[MAX_PLANES]   ; 42136 CJG*/
    PLANDESC    stPlanDes[MAX_PLANES_ABO]   ;
}REGPLANABO;

typedef struct tagREGPLANES
{
    int         iNumAbonados            ;
    REGPLANABO  stAbonado[NUM_ABONADOS_CLIENTE];
}REGPLANES;


/****************************************************************/
typedef struct tagCONCEVAL
{
    int    iCod_Grupo              ;
    int    iCod_Concepto           ;
    char   szInd_Obliga        [2] ;
    double dMto_MinFact            ;
}CONCEVAL;

typedef struct tagGRUPOCONCEVAL
{
    int        iNumEval ;
    CONCEVAL   stRegistro[MAX_REGISTROS];
}GRUPOCONCEVAL;


/****************************************************************/
/****************************************************************/
typedef struct tagCONCAPLI
{
    int         iCod_Grupo              ;
    int         iCod_Concepto           ;
    int         iCod_ConRel             ;
}CONCAPLI;

typedef struct tagGRUPOCONAPLI
{
    int        iNumAplica ;
    CONCAPLI   stRegistro[MAX_REGISTROS];
}GRUPOCONAPLI;


/****************************************************************/
/****************************************************************/
typedef struct tagCUADRANDESC
{
    int    iNum_Cuadrante        ;
    double dVal_Desde            ;
    double dVal_Hasta            ;
    char   szTip_Descuento   [2] ;
    double dVal_Descuento        ;
    char   szTip_Moneda      [3] ;
}CUADRANDESC;

typedef struct tagGRUPOCUADRANTE
{
    int          iNumCuadrantes ;
    CUADRANDESC  stRegistro[MAX_REGISTROS];
}GRUPOCUADRANTE;


typedef struct tagVALORDESCUENTO
{
    int    iNum_Cuadrante        ;
    int    iCod_Concepto         ;
    char   szDescConcepto    [61];
    double dVal_Desde            ;
    double dVal_Hasta            ;
    char   szTip_Descuento   [2] ;
    double dVal_Descuento        ;
    char   szTip_Moneda      [3] ;
    double dValor_Monto          ;
    long   lNumAbonado           ;
    long   lNumSecuencia         ;
    int    iPosPrefac            ;
}VALORDESCUENTO;

typedef struct tagVALORESDCTOS
{
    int             iNumDescuentos ;
    VALORDESCUENTO  stDescuentos[MAX_PLANES*NUM_ABONADOS_CLIENTE];
}DESCUENTOS;


/****************************************************************/
/****************************************************************/
typedef struct tagABONADOSGRUPO
{
    long         lNumAbonado ;
    long         lNumSecuencia ; /* CH-151020031403 - EL numero de Secuencia DEBE IR a nivel de GRUPO abonado... */
}ABONADOSGRUPO;

typedef struct tagPLANGRUPO
{
    char            szCod_Plandesc [6];
    PLANDCTO        stPD;
    long            lTotUnidad;
    double          dTotMonto ;
    int             iNumAbonados;
    ABONADOSGRUPO   stAbonadosGrupo[NUM_ABONADOS_CLIENTE];
}PLANGRUPO;

typedef struct tagPLANESGRUPALES
{
    int             iNumPlanesGrupo;
    PLANGRUPO       stPlanGrupo[MAX_PLANES];
}PLANESGRUPALES;

/****************************************************************/
/* declaracion de funciones */
#undef access
#ifdef _DESCUENTOS_PC_

/****************************************************************/
/*   Definiendo Variables y Estructuras Globales                */
/****************************************************************/
int             idxDesc ; /* Contador de descuentos generados   */
double          dAjuste= 0.0 ; /* Acumula el ajuste de monto    */
int             indGrupo; /* Indicador de Planes de Grupo       */

double          dTotalMontoPrefacDesc= 0.0;

DESCUENTOS      stValDesc;
REGPLANES       stPlanesDesc;
PLANESGRUPALES  stPlanesGrupo;

/****************************************************************/

/***************** Declaracion de Prototipos ********************/
#define access


static BOOL bfnCargaPlanDesc            (long lCliente);
static BOOL bfnCargaDatosPlan           ( char *szFecParam
                                        , PLANDCTO *pstPD
                                        , char *szCod_Plandesc );
static BOOL bCargaConceptoEvalua        ( int iCod_Grupo
                                        , char *szFecParam
                                        , GRUPOCONCEVAL  *pstEval);
static BOOL bCargaConceptoAplica        ( int iCod_Grupo
                                        , char *szFecParam
                                        , GRUPOCONAPLI   *pstApli);
static BOOL bCargaCuadrante             ( int iNum_Cuadrante
                                        , char *szFecParam
                                        , GRUPOCUADRANTE *pstCuadra);
static double dValidaMontoMinimo        ();
static double dActualizaDescuentos      ();
void   vPrintPlanDcto                   ( PLANDCTO *stPD);
static BOOL bEvaluaciondeConceptos      ( PLANDCTO *stPD
                                        , GRUPOCONCEVAL *stEval
                                        , double *dTotalfac
                                        , char *szFecParam
                                        , double dTotalMontoPrefactura);
static BOOL bAplicacionConceptos        ( long lNumAbonado
                                        , PLANDCTO *stPD
                                        , GRUPOCONAPLI *stApli
                                        , VALORDESCUENTO *pstDescPaso
                                        , char *szFecParam);
static BOOL bfnDescporConceptoAbonado   ( long lNumAbonado
                                        , PLANDCTO *stPD
                                        , char *szFecParam
                                        , double dTotalMontoPrefactura);
static BOOL bfnDescporConceptoCliente   ( long lNumAbonado
                                        , PLANDCTO *stPD
                                        , char *szFecParam
                                        , double dTotalMontoPrefactura );
static BOOL bfnDescporFacturaCliente    ( long lNumAbonado
                                        , PLANDCTO *stPD
                                        , char *szFecParam
                                        , double dTotalMontoPrefactura);
static BOOL bAplicacionConceptosCliente ( long lNumAbonado
                                        , long lNumAbonadoOrig
                                        , PLANDCTO *stPD
                                        , GRUPOCONAPLI *stApli
                                        , VALORDESCUENTO *stDescuentos
                                        , char *szFecParam );
/*static BOOL bAplicacionConceptosFacturaCliente (long lNumAbonado
					, PLANDCTO *stPD
                                        , VALORDESCUENTO *stDescuentos
                                        , char *szFecParam 
                                        , double dTotalMontoPrefactura ); */
static BOOL bAplicacionConceptosFacturaCliente (long lNumAbonado, PLANDCTO *stPD, VALORDESCUENTO *stDescuentos, double dTotalMontoPrefactura );
                                        
static BOOL bValidacionDto              ( VALORDESCUENTO *stValDesc);
static BOOL bCargaPreFactura            ( int iNumConceptos
                                        , VALORDESCUENTO *pstDesc);
static BOOL bModifBeneficios            ( long          lNumSecuencia);
void   vfnPrintCuadrante                ( VALORDESCUENTO *stDescuentos);
static BOOL bCalculaDescuento           ( long          lNumAbonado
                                        , VALORDESCUENTO *pstValDesc
                                        , GRUPOCUADRANTE *stCuadra
                                        , double        dTotalfac);
static BOOL bfnCargaPlanesGrupo         ( );
static BOOL bfnDescporGrupo             ( char      *szFecParam
                                        , double    dTotalMontoPrefactura );
static BOOL bfnDescporConceptoGrupo     ( PLANDCTO      *stPD
                                        , PLANGRUPO     *pstPlanGrupo
                                        , char          *szFecParam
                                        , double        dTotalMontoPrefactura);
static BOOL bfnEvaluaciondeConceptosGrupo ( PLANDCTO      *stPD
                                          , GRUPOCONCEVAL *stEval
	                                      , PLANGRUPO     *pstPlanGrupo
                                          , char          *szFecParam
                                          , double        dTotalMontoPrefactura);
                                          
BOOL bCargaDescPuntPreFactura ( long lIndCargo, DETCARG_PUNTUALES *pstDescPuntual);

static BOOL bModifDescPuntuales         ( DETCARG_PUNTUALES *pstDescPuntual);

#else
#define access extern

extern BOOL bfnDescuentos (long lCliente,  char *szFecParam);

extern BOOL bfnDescPuntuales (long lCliente);

/*static BOOL bCargaPreFactura            ( int iNumConceptos
                                        , VALORDESCUENTO *pstDesc); P-TMC-10063*/
access BOOL bCargaDescPuntPreFactura ( long lIndCargo, DETCARG_PUNTUALES *pstDescPuntual);

#endif /* _DESCUENTOS_PC_ */
#endif /* _DESCUENTOS_H_  */



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

