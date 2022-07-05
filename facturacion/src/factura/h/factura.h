/*******************************************************************************
Fichero    :  factura.h
Descripcion:  Declaracion de tipos y prototipos de factura.h

Fecha      :  19-02-1997  
Autor      :  Javier Garcia Paredes 
*******************************************************************************/
#ifndef _FACTURA_H_
#define _FACTURA_H_

#include <GenFA.h>
#include <prebilling.h>
#include <composi.h>

/*****************************************************************************/
/* Versionamiento 															 */
/*****************************************************************************/
/* RAO20030628: Se inicia el versionamiento con la incidencia TM-260620030157*/
/*#define szVersionActual        "1.12"  CJG XXXXX 25-06-2007 */
/*#define szUltimaModificacion "08.07.2007" CJG XXXXX 25-06-2007 */
/* #define szVersionActual        "1.14" */ /*CJG 42136 30-07-2007 */
/* #define szVersionActual        "1.15" */ /*PGG 42917 3-08-2007 */
/*#define szVersionActual        "1.17"  PGG 42970 7-08-2007 */
/*#define szUltimaModificacion "08.08.2007" PGG 42970 07-08-2007 */
/*#define szVersionActual        "1.18" */ /* MA-64457 */
/*#define szUltimaModificacion "12.05.2008" */ /* MA-64457 */
/* #define szUltimaModificacion "30.07.2007" */ /*CJG 42136 30-07-2007 */
/*#define szVersionActual       "1.19" */ 			/* PGG SOPORTE - 70685 - 23-09-2008 */
/*#define szUltimaModificacion 	"23.09.2008" */ 	/* PGG SOPORTE - 70685 - 23-09-2008 */
/*#define szVersionActual       "1.20"                    PGG SOPORTE - 71849 - 17-10-2008 */
/*#define szUltimaModificacion    "17.10.2008"     PGG SOPORTE - 71849 - 17-10-2008 */
/*#define szVersionActual       "1.21"                     CJG 73156 
#define szUltimaModificacion    "20.11.2008"     CJG 73156 */

/*#define szVersionActual         "1.22"        AFGS 73505 
#define szUltimaModificacion    "26.11.2008"  AFGS 73505 */

/*#define szVersionActual         "1.23"        AFGS 79605
#define szUltimaModificacion    "02.03.2009" AFGS 79605*/
/*#define szVersionActual         "1.25"        PPQL 79840*/
/*#define szUltimaModificacion    "09.03.2009" PPQL 79840*/

/* #define szVersionActual         "1.26"    */    /*PPQL 189483*/
/* #define szUltimaModificacion    "29.11.2012" */ /*PPQL 189483*/

/* #define szVersionActual         "1.27"        PGG 193496*/
/* #define szUltimaModificacion    "28.03.2013" PGG 193496*/
#define szVersionActual         "1.28"        /*PPQL PBI000000012038*/
#define szUltimaModificacion    "25.08.2014" /*PPQL PBI000000012038*/


/*****************************************************************************/

typedef struct tagConfig
{
 long   lNumProceso       ;
 char   szUsuario     [31];
 char   szPassWord    [31];
 long   lCodCliente       ;
 long   lNumAbonado       ;
 int    iCodProducto      ;
 long   lNumAlquiler      ;
 long   lNumEstaDia       ;
 long   lCodCiclFact      ;
 long   lNumTransaccion   ;
 long   lNumVenta         ;
 int    iTipoFactura      ;
 int    iNivelLog         ;
 int    iCaso             ;
 long   lClienteIni       ; 
 long   lClienteFin       ;
 BOOL   bOptPreBilling    ;
 BOOL   bOptComposicion   ;
 BOOL   bOptBaja          ;
 BOOL   bOptCompra        ;
 BOOL   bOptMiscelanea    ;
 BOOL   bOptLiquidacion   ;
 BOOL   bOptRentPhone     ;
 BOOL   bOptRoamingVis    ;
 BOOL   bOptCliente       ;
 BOOL   bOptTransaccion   ;
 BOOL   bOptNumVenta      ;
 BOOL   bOptNumProceso    ;
 BOOL   bOptContado       ;
 BOOL   bOptCiclo         ;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

 BOOL   bOptMemShared     ;

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

 BOOL   bOptSizeLog       ;
 BOOL   bOptUsuario       ;
 BOOL   bOptCiclFact      ;
 BOOL   bOptAbonado       ;
 BOOL   bOptProducto      ;
 BOOL   bOptNumAlquiler   ;
 BOOL   bOptNumEstaDia    ;
 BOOL   bOptNota          ;
 BOOL   bOptClienteIni    ;
 BOOL   bOptClienteFin    ;
}CONFIG;

#define iLOGNIVEL_DEF 3

#undef access
#ifdef _FACTURAUX_C_
#define access
access void vDatosFinTiempo (void)       ;
access void vInitProceso(PROCESO*)       ;

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

/*access BOOL bInitInstance (int iTipoFact);          */

access BOOL bInitInstance (int iTipoFact, BOOL MemShared);

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

access BOOL bExitInstance(void)          ;
access void vInitConfig (void)           ;                                     

#else
#define access extern

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

/*access BOOL bInitInstance (int iTipoFact);          */

access BOOL bInitInstance (int iTipoFact, BOOL MemShared);

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

access BOOL bExitInstance(void)          ;                                     
access BOOL bEntradaFactura (void)       ;                                     
access void vInitConfig (void)           ;                                     
access void vInitProceso(PROCESO*)       ;                                     

#endif /*_FACTURAUX_C_*/

access CONFIG stConfig;

#undef access
#endif /* _FACTURA_H_ */


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

