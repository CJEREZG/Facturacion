
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "./pc/precob.pc"
};


static unsigned long sqlctx = 865595;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[1];
   unsigned int   sqhstl[1];
            int   sqhsts[1];
            void  *sqindv[1];
            int   sqinds[1];
   unsigned int   sqharm[1];
   unsigned int   *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {10,1};

/* SQLLIB Prototypes */
extern sqlcxt (/*_ void **, unsigned long *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlcx2t(/*_ void **, unsigned long *,
                   struct sqlexd *, struct sqlcxp * _*/);
extern sqlbuft(/*_ void **, char * _*/);
extern sqlgs2t(/*_ void **, char * _*/);
extern sqlorat(/*_ void **, unsigned long *, void * _*/);

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem(/*_ char *, int * _*/);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4130,0,0,0,
};


#line 1 "./pc/precob.pc"
/****************************************************************************/
/* Fichero    : precob.pc                                                   */
/* Descripcion: Funciones para Interface con el modulo de Cobros            */
/* Autor      : Javier Garcia Paredes                                       */
/* Fecha      : 6-05-1997                                                   */
/****************************************************************************/

#define _PRECOB_PC_

#include <precob.h>

/* EXEC SQL INCLUDE sqlca;
 */ 
#line 1 "/app/oracle/OraHome1/precomp/public/sqlca.h"
/*
 * $Header: sqlca.h,v 1.3 1994/12/12 19:27:27 jbasu Exp $ sqlca.h 
 */

/* Copyright (c) 1985,1986, 1998 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/*  */ 
#line 1 "/app/oracle/OraHome1/precomp/public/sqlca.h"
/*
 * $Header: sqlca.h,v 1.3 1994/12/12 19:27:27 jbasu Exp $ sqlca.h 
 */

/* Copyright (c) 1985,1986, 1998 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

#line 13 "./pc/precob.pc"

/*****************************************************************************/
/*                              funcion : bIFCobros                          */
/*****************************************************************************/
BOOL bIFCobros (void)
{
   static CONCEPTO stConcepto      ;
   static int  iInd            = 0 ;
   static int  iCodCredito     = 0 ;
   static char szFecCobros [9] = "";

   memset (&stConcepto,0,sizeof(CONCEPTO));

   strcpy (stAnomProceso.szDesProceso,"PreBilling Cobros");

   vDTrazasLog (szExeName,"\n\t\t* Obtencion de Recargos",LOG03);

   if (stArrRec.iCont == 0)
   {
       iDError (szExeName,ERR038,vInsertarIncidencia,"Recargos");
       return FALSE;
   }
   if (stArrCan.iCont == 0)
   {
       iDError (szExeName,ERR038,vInsertarIncidencia,"Cantidades");
       return FALSE;
   }
   if (stArrPor.iCont == 0)
   {
       iDError (szExeName,ERR038,vInsertarIncidencia,"Porcentaje");
       return FALSE;
   }

   if (!bfnDBObtConCre (&iCodCredito))
   {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Select->Obtencion CodCredito",szfnORAerror());
        return FALSE;
   }
   strncpy (szFecCobros,szSysDate,8);
   szFecCobros [8] = '\0'           ;

   vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada para Recargos"
                          "\n\t\t=>Cod.Cliente  [%ld]"
                          "\n\t\t=>Fecha        [%s] "
                          "\n\t\t=>Cod.CalClien [%s] "
                          "\n\t\t=>Cod.Credito  [%d] ",LOG04,
                          stCliente.lCodCliente  ,
                          szFecCobros            ,
                          stCliente.szCodCalClien,
                          iCodCredito);
/*
   if (ifnDBCompRecargos (stCliente.lCodCliente  ,&stArrRec,&stArrPor,&stArrCan,
                          szFecCobros,iCodCredito,stCliente.szCodCalClien      ,
                          &stCliente.dImpRecargo))
   {
       iDError (szExeName,ERR037,vInsertarIncidencia);
       return FALSE;
   }
*/

   if (!bFindConcepto (stDatosGener.iCodRecargo,&stConcepto))
   {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos");
        return FALSE;
   }
   if (stPreFactura.iNumRegistros >= MAX_CONCFACTUR)
   {
       iDError (szExeName,ERR035,vInsertarIncidencia);
       return FALSE;
   }
   if (stCliente.dImpRecargo >= 0.01)
   {
       iInd = stPreFactura.iNumRegistros;
       stPreFactura.A_PFactura.lNumProceso [iInd] = stStatus.IdPro          ;
       stPreFactura.A_PFactura.lCodCliente [iInd] = stCliente.lCodCliente   ;
       stPreFactura.A_PFactura.iCodConcepto[iInd] = stDatosGener.iCodRecargo;

       strcpy (stPreFactura.A_PFactura.szDesConcepto[iInd],
               stConcepto.szDesConcepto)                                    ;

       if (!bGetMaxColPreFa (stPreFactura.A_PFactura.iCodConcepto [iInd],
                             &stPreFactura.A_PFactura.lColumna    [iInd]))
            return FALSE;

       stPreFactura.A_PFactura.iCodProducto [iInd]=stConcepto.iCodProducto;
       /* RAO20021216: SE cambia por fec_emision 
       strcpy (stPreFactura.A_PFactura.szFecValor       [iInd],szSysDate) ;*/
       strcpy (stPreFactura.A_PFactura.szFecValor       [iInd],stCiclo.szFecEmision) ;
       strcpy (stPreFactura.A_PFactura.szFecEfectividad [iInd],szSysDate) ;

       stPreFactura.A_PFactura.dImpConcepto  [iInd]=stCliente.dImpRecargo ;
       stPreFactura.A_PFactura.dImpFacturable[iInd]=stCliente.dImpRecargo ;
            
       if (!bConverMoneda (stConcepto.szCodMoneda                      ,
                           stDatosGener.szCodMoneFact                  ,
                           stCiclo.szFecEmision                        ,
                          &stPreFactura.A_PFactura.dImpFacturable[iInd],
                           stProceso.iCodTipDocum))
            return FALSE;
       stPreFactura.A_PFactura.dImpFacturable[iInd] =
                    fnCnvDouble( stPreFactura.A_PFactura.dImpFacturable[iInd],
                                                   USOFACT);

       stPreFactura.A_PFactura.dImpMontoBase [iInd]= 0.0   ;

       strcpy (stPreFactura.A_PFactura.szCodMoneda [iInd],
               stConcepto.szCodMoneda)  ;
       strcpy (stPreFactura.A_PFactura.szCodRegion[iInd],
               stCliente.szCodRegion)   ;
       strcpy (stPreFactura.A_PFactura.szCodProvincia[iInd],
               stCliente.szCodProvincia);
       strcpy (stPreFactura.A_PFactura.szCodCiudad[iInd],
               stCliente.szCodCiudad)   ;

       strcpy (stPreFactura.A_PFactura.szCodModulo[iInd],
               stConcepto.szCodMoneda);

       stPreFactura.A_PFactura.lCodPlanCom [iInd]= stCliente.lCodPlanCom  ;
       stPreFactura.A_PFactura.iIndFactur  [iInd]= FACTURABLE             ;
       stPreFactura.A_PFactura.iCodCatImpos[iInd]= stCliente.iCodCatImpos ;
       stPreFactura.A_PFactura.iCodPortador[iInd]= 0                      ;
       stPreFactura.A_PFactura.iIndEstado  [iInd]= EST_NORMAL             ;
       stPreFactura.A_PFactura.iCodTipConce[iInd]= stConcepto.iCodTipConce;
       stPreFactura.A_PFactura.lNumUnidades[iInd]= 1                      ;
       stPreFactura.A_PFactura.lCodCiclFact[iInd]= stCiclo.lCodCiclFact   ;
       stPreFactura.A_PFactura.iCodConceRel[iInd]= 0                      ;
       stPreFactura.A_PFactura.lColumnaRel [iInd]= 0                      ;
       stPreFactura.A_PFactura.lNumAbonado [iInd]= 0                      ;

       stPreFactura.A_PFactura.szNumTerminal[iInd][0] = 0;
       stPreFactura.A_PFactura.lCapCode     [iInd]    = 0;
       stPreFactura.A_PFactura.szNumSerieMec[iInd][0] = 0;
       stPreFactura.A_PFactura.szNumSerieLe [iInd][0] = 0;

       stPreFactura.A_PFactura.iFlagImpues [iInd] = 0  ;
       stPreFactura.A_PFactura.iFlagDto    [iInd] = 0  ;
       stPreFactura.A_PFactura.fPrcImpuesto[iInd] = 0  ;
       stPreFactura.A_PFactura.dValDto     [iInd] = 0.0;

       stPreFactura.A_PFactura.iTipDto        [iInd] = 0;
       stPreFactura.A_PFactura.lNumVenta      [iInd] = 0;
       stPreFactura.A_PFactura.lNumTransaccion[iInd] = 0;
       stPreFactura.A_PFactura.iMesGarantia   [iInd] = 0;
       stPreFactura.A_PFactura.iIndAlta       [iInd] = 0;
       stPreFactura.A_PFactura.iIndSuperTel   [iInd] = 0;
       stPreFactura.A_PFactura.iNumPaquete    [iInd] = 0;
       stPreFactura.A_PFactura.iIndCuota      [iInd] = 0;
       stPreFactura.A_PFactura.iNumCuotas     [iInd] = 0;
       stPreFactura.A_PFactura.iOrdCuota      [iInd] = 0;

       vDTrazasLog (szExeName,"\t\t=> Importe de Recargo (Pesos) : [%f]",LOG03,
                    stPreFactura.A_PFactura.dImpFacturable); 

       stPreFactura.iNumRegistros++;
   }
   if (!bfnDBUpdImpRecargo (stCliente.lCodCliente))
   {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Update->Co_Cartera",
                 szfnORAerror());
        return FALSE;
   }
   return TRUE; 
}/****************************** Final bIFCobros *****************************/


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

