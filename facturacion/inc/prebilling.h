/*****************************************************************************/
/* Fichero    : prebilling.pc                                                */
/* Descripcion:                                                              */
/* Fecha      : 14-Ene-97                                                    */
/* Autor      : Javier Garcia Paredes                                        */
/*****************************************************************************/

#ifndef _PREBILLING_H_
#define _PREBILLING_H_

#include <geora.h>
#include <predefs.h>
#include <GenFA.h>
#include <ORAcarga.h>
/* rao #include <precob.h> */
#include <presac.h>
#include <preser.h>
#include <prebilco.h>
#include <prebilnot.h>
#include <prebilcic.h>
#include <prebilext.h>
#include <prebilbaj.h>
#include <trazafact.h>
#include <rutinasgen.h>
#undef access
#ifdef _PREBILLING_PC_

#define access
static BOOL bGetFecEmFactNotas (PROCESO,char*);
static BOOL bGetFecEmFactManual(long   ,char*);
static void vFreeAbonoCli (void)              ;
static int  iCliente_A_Facturar (void)        ;
static BOOL bGetDirecCli (long lCodCliente)   ;
static BOOL bGetFecCategoria (int ,char*)     ;

static BOOL bGestionLog (void)          ;
static void vInitRegCliente (void)      ;
static char *szMenorFecDesdeCiclo (void);

BOOL bfnOraCommitPGG(void);  /* PGG SOPORTE 42970  7/08/2007 */

static BOOL bfnFinOkCliente    (void);
static void vfnFinErrorCliente (int   , TRANSCONTADO *, VENTAS *);
static BOOL bfnInicioCiclo     (char *, int, ABONOCLI) ;
static void vfnPrintFin        (void);
static int  ifnRangoClientes   (GABONOCLI *, long, long, int, long, long);

static void vfnFreeGAbonoCli   (GABONOCLI *);
access void vfnPrintRangoCliente (GABONOCLI)                   ;
static BOOL bfnSkipBadRecord(int iTipoFact, TRANSCONTADO *, VENTAS *  );
access BOOL bCargaGeneralPreBilling (int iTipoFact,long lNumAbonado)       ;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

static int  ifnRangoClientes_MC   (GABONOCLI *, long,int,long);
BOOL bfnProcesarClientes(FAC_CLIENTES **pstCliente,FAC_CICLO *, long *,long, int);
int   bfnCreaSemaforo(void); 
BOOL attach_shared_ciclo(
	TIPIMPUES *,int *,
	IMPUESTOS *,int *,
	CABCUOTAS *,int *,
	TACONCEPFACT *,int *,
	CONCEPTO **,int *,
	CONCEPTO_MI *,long *,
	ACTIVIDADES *,int *,
	RANGOTABLA *,int *,
	LIMCREDITOS *,int *,
	PROVINCIAS *,int *,
	REGIONES *,int *,
	CATIMPOSITIVA *,int *,
	ZONACIUDAD *,int *,
	GRPSERCONC *,int *,
	CONVERSION *,int *,
	DOCUMSUCURSAL *,int *,
	LETRAS *,int *,
	GRUPOCOB *,int *,
	TARIFAS *,int *,
	ACTUASERV *,int *,
	CUOTAS *,int *,
	FACTCARRIERS *,int *,
	CUADCTOPLAN *,int *,
	CTOPLAN *,int *,
	PLANCTOPLAN *,int *,
	ARRIENDO *,int *,
	CARGOSBASICO *,int *,
	OPTIMO *,int *,
	FERIADOS *,int *,
	PLANTARIF *, int *,
	PENALIZA *, int *,
	OFICINA **, int *,
	FACTCOBR **, int *,
/*	DETPLANDESC **pstlGeDetPlanDesc, int *piNumDetPlanDesc, */
	DETCARG_PUNTUALES **, int *,
	long *
);
/* BOOL bCargaGeneralPreBilling_MC (int iTipoFact, long lNumAbonado)       ;PPQL 203066*/
BOOL bCargaGeneralPreBilling_MC ();
BOOL bCargaCargos_MC (CARGOS * ,int*,int,long,long,long,long);
static BOOL bfnInicioCiclo_MC (char *, int, ABONOCLI) ;

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/


access BOOL bCargaPreBillingContado(int iTipoFact,long lNumTransaccion,long lNumVenta);
void vFreeModulos (void);
#else
#define access extern
access BOOL bfnPreBilling(int  iTipoFact   , long lCodCliente ,
                          long lNumAbonado , int  iCodProducto,
                          long lNumAlquiler, long lNumEstaDia ,
                          long lCodCiclFact, long lNumProceso ,
                          long lNumVenta   , long lNumTrans   ,
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

			  /*long lClienteIni , long lClienteFin );*/

			  long lClienteIni , long lClienteFin, BOOL MemSharedL );

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

access BOOL bCargaPrebillingContado (int iTipoFact,long ,long );
access void vFreeModulos (void);

#endif /*_PREBILLING_PC_*/
#undef access
#endif /* _PREBILLING_H_ */


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

