/* ***********************************************
Nombre : PlanDcto.h
Autor  : Guido Antio Cares
*********************************************** */
#ifndef _PLANVCTO_H_
#define _PLANVCTO_H_

/* Librerias                        */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "GenFA.h"
#include "trazafact.h"


/****************************************************************/
/* declaracion de funciones 					*/
#undef access
#ifdef _PLANVCTO_PC_
/******************* Declaracion de Prototipos ******************/
#define access  
BOOL 	bfnDiasVencimiento (long , long ,int , char *, char *, char *);
BOOL  	bBuscaDiaHabil (char *, char *);
BOOL  	bDiaFeriado (char *, int *);
BOOL  	bGetTipoDia (char *, int *);
#else
#define access extern
access BOOL 	bGetNumDiasPlanVcto (long , long , int , char *, int *);
access BOOL    bfnDiasVencimiento (long , long ,int , char *, char *, char *);
#endif /* _PLANVCTO_PC_ */
#endif /* _PLANVCTO_H_  */








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

