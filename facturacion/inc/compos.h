/****************************************************************************/
/* Fichero    : compos.h                                                    */
/* Descripcio : funciones para el paso a Historicos de los datos facturados */
/* Autor      : Javier Garcia Paredes                                       */
/* Fecha      : 09-05-1997                                                  */
/****************************************************************************/

#ifndef _COMPOSICION_H_
#define _COMPOSICION_H_

#include <FaORA.h>
#include <GenFA.h>
#include <ORAcarga.h>
#include <stdlib.h>
#include <PlanVcto.h>
#include <geora.h>

/* En una Nota Debito la FecVecimiento = FecEmision + iDIAS_VENCIMIENTO */
#define iDIAS_VENCIMIENTO       15

#define szCODCATRIBUT_AFECTO      "A"
#define szCODCATRIBUT_EXENTO      "E"

#define iCODCATRIBUT_EXENTO        0
#define iCODCATRIBUT_AFECTO        1

#define ERR62		62
#define STR_LONG  256
#define STR_HUGE  8192

#define  FALSE  0
#ifdef TRUE
#undef TRUE
#define TRUE   1
#endif

#undef access
#ifdef _COMPOSICION_PC_
#define ACCESS

typedef struct reg_acumulador
{
	long 	lAbonado;
	long	lCod_ConCobr;
	double	dMonto;
	struct	reg_acumulador 	* sgte;
}reg_acumulador;
typedef struct reg_acumulador stAcumulador;
stAcumulador * lstAcumulador = NULL;

/* rao : optimizacion busqueda oficina emisora */
typedef struct tagOfiEmisora
{
    char    szCodOperadora   [5];
	char    szCodOficina     [3];
    char    szCodOficinaEmis [3];
}OFICINAEMIS;

typedef struct tagOfiEmisoras
{
    int         iNumOfiEmis;
    OFICINAEMIS *stOfiEmis;
}OFICINASEMISORAS;

OFICINASEMISORAS pstOficinasEmisoras;

static BOOL bfnPasoHistDocu   (int )     		;
static BOOL bfnPasoHistClie   ()                ;
static BOOL bfnPasoHistAbo    ()                ;
static BOOL bfnPasoHistConc   ()                ;

static void vfnComposicionNumCTC (char *)           ;
static BOOL bfnDBUpdateVenta  (HISTDOCU *)          ;
static BOOL bfnGetTotDocu     (HISTDOCU *)          ;
static BOOL bfnValCatImpDocu  (long, BOOL*, BOOL*)  ;
static BOOL bfnGetSaldoAnt    (long,double *,char *);

static BOOL bfnFindActividad    (int,char *,int)    ;
static BOOL bfnGetTotCargosMeAbo(HISTABO  *)        ;

static BOOL bfnGetLimCredito    (int,int,double *,int)      ;
static BOOL bfnInsertHistAbo    (HISTABOP *,int Produc )      ;

static void vfnInitCadenaInsertHistConc (char *,char *)		;
static void vfnInitCadenaInsertHistDocu (char *,char *)		;
static void vfnInitCadenaInsertHistClie (char *,char *)		;
static void vfnInitCadenaInsertHistAbo  (char *,char *)		;

static BOOL bfnInsertHistDocu    (HISTDOCU *);
static BOOL bfnInsertHistClie    (void)      ;

static BOOL bfnInsertHistConc();

static void vfnPrintHistDocu (HISTDOCU *,char *szTable)  	;
static void vfnPrintHistAbo  (HISTABO *,int,BOOL)      		;
static void vfnPrintHistClie (HISTCLIE *,char *szTable)  	;

static BOOL bfnAddHistAboCero 	(void)                  	;
static BOOL bfnCargosNivCliente (long *lpIndiceAbon)     	;
									 
static BOOL bfnGetOficinaEmisora (OFICINAEMIS * pstOficina, int iTipoFact);
BOOL bfnObtieneOficinaEmisora(char *Oficina, char *Operadora, char *OficinaRet);

#else
#define access extern
access BOOL bfnPasoHistoricos (void);
access void vfnFreeHistAbo    (void);


#endif
#endif

