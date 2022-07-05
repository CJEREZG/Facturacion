/*******************************************************************************
Fichero:      pretar.h
Descripcion:  Declaracion de tipos y prototipos de pretar.pc

Fecha:        27/01/97
Autor:        Javier Garcia Paredes
*******************************************************************************/

#ifndef _PRETAR_H_
#define _PRETAR_H_

#include <GenFA.h>
#include <geora.h> /*PGG probando no mas*/

/* -------------------------------------------------------------------------- */
/*                     Estructuras Generales                                  */
/* -------------------------------------------------------------------------- */
#define iFORTAS 1
#define iFORADI 2

typedef struct tagEST
{
  int    iNumConcLocalEnt;
  int    iNumConcLocalSal;
  int    iNumConcOper    ;
  int    iNumConcRoaming ;
  int    iNumConcCarriers;
  double dTotImpLocalEnt ;
  double dTotImpLocalSal ;
  double dTotImpOper     ;
  double dTotImpRoaming  ;
  double dTotImpCarriers ;
  long   lSegTotLocal    ;
} EST;

typedef struct tagESTAR
{
  int iNumEst;
  EST *pEst  ;
} ESTAR;

/* typedef struct tagConcep
{
  int       iNumConc;
  CONCTAR   stConcTar [MAX_TACONCEPFACT];
}CONCEP;
*/
typedef struct tagConcep
{
  int       iNumConc;
  CONCTAR   *stConcTar;
}CONCEP;


#undef access

extern BOOL bCarga_TOLDescuentos();
extern BOOL bCarga_TOLPromociones();
extern BOOL bCarga_TOLDescripciones();

extern BOOL bfnLeeAbonadosTOL(int);

extern BOOL bfnLee_TOL_Acumper(ABONTAR *);
extern BOOL bfn_EMTOLTarificacion(int);
extern BOOL bGetCodServGenerico(char *szCodServicio);
extern BOOL bLiberaEstrConc(CONCEP *stConcep);

#ifdef _PRETAR_PC_

#define access
/*--------------------------- Variables Globales ----------------------------*/
access EST stPlanOptimo;
access char gszCodServicioGene [6]= "";
access int bIndCodServicioGene=0 ;
/* -------------------------------------------------------------------------- */
/*               Prototipos de Funciones locales del pretar.pc                */
/* -------------------------------------------------------------------------- */
static BOOL bfnLeeAbonados          (int iTipoFact)                ;
static BOOL bfnLeeConceptos         (ABONTAR *)                    ;
static BOOL bfnLeeConceptosRentPhone(ABORENT *)                    ;
static BOOL bfnLeeConceptosRoamingVis(ABOROAVIS *)                 ;
static BOOL bfnValidacionConcTar    (CONCTAR *)                    ;
static BOOL bfnValidacionCarrier    (CONCTAR *, CONCEPTO)          ;
/* static BOOL bfnLeeAcumFraSoc        (CONCTAR*,int iCodTarificacion); */
static BOOL bfnLeeAcumFraSoc        (CONCEP *pstConcep,
                                     long lNumAbonado, int iCodProducto);
static BOOL bfnLeeAcumOper          (CONCEP *pstConcep,
                                     long lNumAbonado);
static BOOL bfnLeeAcumLlamadasRoa   (CONCEP *pstConcep,
                                     long lNumAbonado);
static BOOL bfnLeeAcumAireFraSocAlq (CONCTAR*,int iCodTarificacion);
static BOOL bfnLeeAcumOperAlq       (CONCTAR*,int iCodTarificacion);
static BOOL bfnLeeAcumRoaming       (CONCTAR*,int iCodTarificacion);

static BOOL bfnEscribeAnoTar(CONCTAR*)     ;

static BOOL bfnCargaAbonadosCliente (CICLOCLI *,int iTipoFact);
static BOOL bfnCargaAbonadosCelular (CICLOCLI *,int iTipoFact);

static BOOL bfnLeeConceptosCarriers (ABONTAR *, ABORENT *,int);
static BOOL bfnDBLeeAcumFortas (CONCTAR *, int, int);
static BOOL bfnDBLeeAcumForadi (CONCTAR *, int, int);

static void   vfnPrintConcTarificacion(void)        ;
access void   vfnFreeTarificacion(int iTipoFact)    ;
static void   vfnAplicaPlanOptimo(CONCTAR *, double);
static double dfnTotMinutosLocales(ABONTAR *)         ;
/* static BOOL   bfnDBAplicaDtosTarif(long,long,long)  ; */
static void   vfnRelacionCarrier  ()                ;
static BOOL bfnBuscaAcumCodTarif(CONCEP *pstConcep    , long lNumAbonado
                                 ,int iCodTarificacion, long lSegConsumido
                                 ,double dImpConsumido, long lNumPulsos
                                 ,int sIndEntSal      , int  sIndDestino
                                 ,int iIndTabla       , char *szCodServicio
                                 ,char *szCodPlanTarif, char *szCod_Unidad
                                 ,long lhNumUniFree   , int iCodOperador, int iParametro);

/* TOL  Defines */
#define PROMOCION_TAG   "PR"
#define ADICIONAL_TAG   "AD"
#define NO_HAY_DESC     "***"


/* TOL Functions */

extern char * ltrim(char *s);
extern char * rtrim(char *s);
extern char * alltrim(char *s);
extern BOOL bCarga_TOLDescuentosMI();
extern BOOL bfnLeeAcumTOL(long);
extern int bfnBusca_PromoConcepto(char *, char *);
extern int bfnBusca_Promo(char *, char *);
extern int bfnBusca_UnidadPromo(char *);
extern BOOL bfn_LeeDescTOLPromo();

extern BOOL bBuscaPlanTarifAbon (long lNumAbonado,char *szCodPlanTarif);

#else
#define access extern
/* -------------------------------------------------------------------------- */
/*               Prototipos de Funciones exportables pretar.pc                */
/* -------------------------------------------------------------------------- */
access BOOL bfnIFTarificacion (int );
access BOOL bfnEMTarificacion (int );
access void vfnFreeTarificacion(void);




#endif /*_PRETAR_PC_ */
#endif /*_PRETAR_H_ */



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

