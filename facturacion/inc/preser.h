/*****************************************************************************/
/* Fichero     : preser.h                                                    */
/* Descripcion : Declaracion de tipos y funciones                            */
/* Autor       : Javier Garcia Paredes                                       */
/* Fecha       : 12-03-1997                                                  */
/*****************************************************************************/
#ifndef _PRESER_H_
#define _PRESER_H_

#include <GenFA.h>
#include <preabo.h>
#include <precuo.h>
#include <presac.h>
#include <geora.h>

#define NUMORIGINAL 0
#define iNUMHOLD    10 /* Dimension del Host-Array */
#define CRIT_PLANTARIF 1 /* Codigo de criterio relativo a plan tarifario */


#undef access
#ifdef _PRESER_PC_
#define access 

/******************************************************************************/
/* Estructura para paso de parametros de rutinas de prorrateo                 */
/******************************************************************************/
typedef struct tagPasoProrrateo
{
char 	szFecInicio	[15];
char 	szFecTermino	[15];
double	dImpServicio;
short   sIndTipoCobro;
double	dImpConcepto;
short   sDiasAbono;
short	sIndAlta;
short 	sIndProrrateo;
}PASOPRORRATEO;


/* -------------------------------------------------------------------------- */
/*               Prototipos de Funciones locales del preser                   */
/* -------------------------------------------------------------------------- */
static BOOL bCargaAbonosCelular  (CICLOCLI *,int iTipoFact);
static int  ifnClienteFacturable (void)                    ;
static BOOL bfnObtImpCargoBasico (ABONOS   *,char *, char *,
                                  int , int,CICLOCLI *pCicloCli);
static BOOL bfnCargaCargoBasico  (ABONOS   *, char *, char *, 
                                  int       , int)          ;
static BOOL bCargaServGenerales  (ABONOS    ,int iTipoFact);

static BOOL bCargaServOcasionales   (int iNumServs,int iIndFactur);
static BOOL bCargaServSuplementarios(int iNumServs,int iIndFactur, int iTipFac);
static BOOL bfnGetServicios         (int iNumServs,int iIndFactur,
                                     int iBloqueo ,int iTipFact);   

static BOOL bCargaArriendos (long,long,int,char *);

static BOOL bFindGrupoCob       (GRUPOCOB  *)                ;
static BOOL bInsertaCargosBasicos (void)                     ;
static BOOL bValidacionAbono    (int, long, CARGOFIJO *)     ;
static BOOL bValidacionServicio (SERVICIOS *)                ;
static BOOL bValidacionArriendo (ARRIENDO  *)                ;

static void vfnEstadisticas (long lNumAbonado)               ;
static BOOL bUpdateIndInfas (void)                           ;
static BOOL bEMArriendos (void)                              ;

static int  ifnDBOpenIntar (long, char*, char*, long,int,int);
static int  ifnDBFetchIntar(CARGOFIJO *, int)                ;
static int  ifnDBCloseIntar(int)                             ;

static BOOL   bfnDBGetMinFree(int, char*, long*, char *);

static BOOL   bfnTrataCBasico (ABONOS *, CICLOCLI *pCicloCli)          ;
static BOOL   bfnInfServicios (ABONOS *, CARGOFIJO);

static void   vfnPrintCBasico (void )                                 ;
static BOOL   bfnGetSegCBasico  ( long lNumAbonado
                                , char *szCodPlantarif
                                , long lCodCiclFact
                                , long *lSegundosFree);
                                
static BOOL bfnProrrateoStandar(PASOPRORRATEO *);

BOOL BfnObtieneValorCrit_PlanTarif(char* szCodServicio, int iCodProducto ,
				                   char* szPlanTarifario,
				                   long lNumAbonado);

#else
#define access extern
access BOOL bIFAbonos    (ABONOCLI, int iTipoFact);
access BOOL bEMAbonos    (void)                   ;
access BOOL bEMServicios (void)                   ;
access void vFreeServicios (void)                 ;
access void vFreeAbonos (void)	;
#endif  /*_PRESER_PC_*/

#endif  /*_PRESER_H_*/



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

