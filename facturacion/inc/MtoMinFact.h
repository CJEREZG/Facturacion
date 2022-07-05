/* ***********************************************
Nombre : MotoMinFact.h
Autor  : Guido Antio Cares
*********************************************** */
#ifndef _MOTOMINFACT_H_
#define _MOTOMINFACT_H_

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

#define  MONTOMIN       "P"
 
typedef struct regMMF
{
    long    lNumAbonado     ;
    double  dImpCargoBasico ;
    double  dImpTrafico     ;
    char    szPlantarif  [4];
    int     iIndMMF         ;
    int     iPosCargoBasico ;

}REGMMF;


/****************************************************************/
/* declaracion de funciones */
/****************************************************************/

/* BOOL bfnVerificaPlan(char *szPlanTarif, double *dImpFacturable); */

#undef access
#ifdef _MTOMINFACT_PC_

char modulo[]   = "bfnMontoMin_Fact";

/****************************** Declaracion de Prototipos ********************/
#define access  

BOOL bfnGeneraCptoMMF    ( long lNroConcCB
                         , double dImpCragoBasico, double dImpTrafico);
BOOL bfnRebajaCargoBasico( int iNroCpto);
BOOL bBuscaCodTraficoLocal (int iCodConcepto);
int  ifnCmpCodConcep      ( const void *cad1,const void *cad2);
BOOL bfnRebajaCargoBasico();
BOOL bfnValidaPlanTarifMFF (char  *szPlanTarif);
BOOL bfnGetConcParam     ( long    lCodParametro
                         , int    *iCodConcep
                         , char   *szDesConcep);

#else

#define access extern

access BOOL bfnMontoMin_Fact (long lCliente);

#endif /* _MTOMINFACT_PC_ */
#endif /* _MTOMINFACT_H_  */



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

