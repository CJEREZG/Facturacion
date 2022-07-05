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

#define MAXFETCH       2000
#define ERR62		62
#define STR_LONG  256
#define STR_HUGE  8192

#define  FALSE  0
#define  TRUE   !FALSE

#define NOTECNO "NOTECNO"

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


typedef struct reg_prctecno
{
	char 	szCodTecno [8];
	int 	iCantTecno	  ;
	double 	dPrcTecno	  ;
	struct reg_prctecno * sgte;
}reg_prctecno;
typedef struct reg_prctecno stPrcTecno; 
stPrcTecno * lstTecno = NULL;



static BOOL bfnPasoHistDocu   (int )     		;
static BOOL bfnPasoHistClie   ()                ;
static BOOL bfnPasoHistAbo    ()                ;
static BOOL bfnPasoHistConc   ()                ;
static BOOL bfnPasoHistTecno ()					;

static void vfnComposicionNumCTC (char *)           ;
static BOOL bfnDBUpdateVenta  (HISTDOCU *)          ;
static BOOL bfnGetTotDocu     (HISTDOCU *)          ;
static BOOL bfnValCatImpDocu  (long, BOOL*, BOOL*)  ;
static BOOL bfnGetMonedaCobros(char *)              ;
static BOOL bfnGetSaldoAnt    (long,double *,char *);
static BOOL bfnGetRangoTabla  (long,long)           ;

static BOOL bfnFindActividad    (int,char *,int)    ;
static BOOL bfnGetTotCargosMeAbo(HISTABO  *)        ;

static BOOL bfnGetLimCredito    (int,int,double *,int)      ;
static BOOL bfnGetDatosAbonado  (HISTABO *,int)             ;
static BOOL bfnInsertHistAbo    (HISTABOP *,int Produc )      ;
static BOOL bfnGetAcumProducto  (int, HISTABO *, ACUMPROD *);
static BOOL bfnInsertAcumuloProd(ACUMPROD stAcP)            ;
static void vfnPrintAcumuloProd (BOOL,int,ACUMPROD)         ;

static void vfnInitCadenaInsertHistConc (char *,char *)		;
static void vfnInitCadenaInsertHistDocu (char *,char *)		;
static void vfnInitCadenaInsertHistClie (char *,char *)		;
static void vfnInitCadenaInsertHistAbo  (char *,char *)		;
static void vfnInitCadenaInsertHistTec  (char *,char *)		;

static BOOL bfnInsertHistDocu    (HISTDOCU *);
static BOOL bfnInsertHistClie    (void)      ;
static BOOL bfnGetAcumMiscelanea (ACUMPROD *);
static BOOL bfnInsertHistTecno   (void)		 ;

static void vfnPrintHistConc (int i,BOOL,HISTCONC *,char *)	;
static void vfnPrintHistDocu (HISTDOCU *,char *szTable)  	;
static void vfnPrintHistAbo  (HISTABO *,int,BOOL)      		;
static void vfnPrintHistClie (HISTCLIE *,char *szTable)  	;
static void vfnInitHistConc  (HISTCONCP *)               	;
static void vfnPrintHistTecno ( BOOL     bError  ,
								HISTECNO  *stHisTecno,
                                int      j  )				;

static BOOL bfnAddHistAboCero 	(void)                  	;
static BOOL bfnCargosNivCliente (int *ipIndiceAbon)     	;
static void vLiberaAcumulados	(void)		;
static BOOL bfnCalcPrcTecno 	(void)						;
void vLiberaTecno				(void) 						;

static BOOL bfnTrapazaTecnoNC			(char *szTablaTecno);
static BOOL bfnValidaTecnoCicloNotaC	(long lCodCiclFact	,
										 char *szTablaTecno);

#else
#define access extern
access BOOL bfnPasoHistoricos (void);
access void vfnFreeHistAbo    (void);


#endif
#endif

