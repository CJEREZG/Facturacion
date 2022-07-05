/*****************************************************************************/
/*  Fichero    : imptoiva.h                                                  */
/*  Descripcion: Declaracion de tipos y prototipos de imptoiva.pc            */
/*  Fecha      : 20-Nov-96                                                   */
/*  Autor      : Javier Garcia Paredes                                       */
/*****************************************************************************/

#ifndef _IMPTOIVA_H_
#define _IMPTOIVA_H_
#include <predefs.h>
#include <ORAcarga.h>
#include <geora.h>


#define ZICXOFICLIE 2 /* ZONA IMPOSITIVA CICLO X DIREC. OFICINA CLIENTE */
#define TAM_HOSTS 20000


typedef struct tagImptos
{
    int        iNumImpuestos;
    IMPUESTOS* pImpuestos   ;
}IMPTOS                   ;

/********************************************************/
/* Estructura para acumular los totales por abonado		*/
/********************************************************/
typedef struct tagTAbon
{
    long      lNumAbonado;
    double    dTotFactur;
}TABON                  ;


typedef struct tagTotAbon
{
    int     iNumAbonados;
    TABON   stAbon [NUM_ABONADOS_CLIENTE];
}TOTABON                   ;
/********************************************************/
/* Estructura para acumular los totales por impuesto 	*/
/********************************************************/
typedef struct tagTotImpto
{
    int     iCodImpto;
    float   fPorcent;
    double  dTotImpto;
    double  dTotMBase;
}TOTIMPTO;

typedef struct tagTotImptos
{
    int       iNumTotImptos;
    TOTIMPTO* stTotImptos;
}TOTIMPTOS;

/********************************************************/

/********************************************************/
/* Estructura para cargar conceptos de retención de iva */
/* SAAM-20050110, Proyecto P-TMC-05040 RETENCIÓN DE IVA */
/********************************************************/
typedef struct TagConcReten_Hosts
{
    long      lConcepto_Origen [TAM_HOSTS];
    long      lConcepto_Reten  [TAM_HOSTS];
    double    dMonto_Unitario  [TAM_HOSTS];
    double    dMonto_Total     [TAM_HOSTS];
}CONCRETEN_HOSTS;

typedef struct TagConcReten
{
    long      lConcepto_Origen;
    long      lConcepto_Reten ;
    double    dMonto_Unitario ;
    double    dMonto_Total    ;
}CONCRETEN;

typedef struct TagConcReten_Init
{
    int       iCantConcRetencion;
    CONCRETEN *stConcRetencion  ;

}CONCRETEN_S;

CONCRETEN_S pstConcReten;
/********************************************************/


#undef access
#ifdef _IMPTOIVA_PC_
#define access 
/*****************************************************************************/
/*                         Declaracion de Funciones Locales                  */
/*****************************************************************************/
static char *szGetFecZonaImp (int iTipoFact);
BOOL bGetZonaImpositiva (char*
                        ,char*
                        ,char*
                        ,int *piCodZonaImpo
                        ,char*szFecZonaImpo
                        ,int );
static BOOL bAddZonaCiudad (ZONACIUDAD* );
static BOOL bGetGrupoServicios (int  iCodConcepto
                               ,int  *piCodGrpServi
                               ,char *szFecGrp,int);
static BOOL bAddGrpSerConc (GRPSERCONC*);
static BOOL bTipoConceptoValido (int iNumReg);

static BOOL bCalculaImptos (int iInd
                           ,IMPUESTOS pImpuesto);

BOOL bGetImpuestos (int     iCodCatImpos
                   ,int     iCodZonaImpo
                   ,int     iCodGrpServi
                   ,char    *szFecVenc
                   ,IMPTOS  *pImpto
                   ,int     iTipFa);
void vPrintImpuestos (IMPTOS*)               ;
void vFreeImpuestos (IMPTOS*)               ;
static BOOL bGeneraCuotas (long  lNumCargo
                          ,char  *szCodCuota
                          ,float fPrcImpues
                          ,int   iCodConcepto);
static BOOL bfnAcumTotImptos (TOTIMPTOS *pstTotImptos ,
                              int       iCodConcBase	,
                              int       iCodConcepto	,
                              double    dImpMontoBase	,
                              double    dImpConcepto	,
                              float     fPrcImpuesto);

static BOOL bfnAjusteImptos ( TOTIMPTOS *pstTotImptos);
static BOOL bfnValidaAbonados();
BOOL bfnEvalZonasImpos (char *pszFecZonaImpo
                       ,int  piTipoFact
                       ,int  *iCodZonaImpo
                       ,int  piIndZonaImpCic);
BOOL bfnGetDirOficina (char  *pszCodOficina
                      ,char  *szCodRegion
                      ,char  *szCodProvincia
                      ,char  *szCodCiudad);
BOOL bfnGetDirOfiVend (long  lCodVendedor
                      ,char  *szCodOficina );
BOOL bfnAplicaImpto (int iIdxOri
                    ,int iIdxFin
                    ,int iTipoFact);
                    
BOOL bfnAplicaRetencion (int iIdxOri, int iIdxFin,int iTipoFact);

#else
#define access extern
access BOOL bfnEvalZonasImpos (char *pszFecZonaImpo
                              ,int  piTipoFact
                              ,int  *iCodZonaImpo
                              ,int piIndZonaImpCic);
#endif /* _IMPTOIVA_PC_ */
access BOOL bImptosIvaClienteGeneral (int iTipoFact);
access BOOL bImptosIvaNotas (int iTipoFact);
BOOL bfnEvaluaClienteconRetencion (long);
BOOL bfnCargaConceptosConRetencion (CONCRETEN **pstConcReten, int *iCantConcRetencion);
BOOL bfnFindConceptosConRetencion (long lCodConcepto, CONCRETEN *stConcRetenPaso);
#endif /* _IMPTOIVA_H_  */

