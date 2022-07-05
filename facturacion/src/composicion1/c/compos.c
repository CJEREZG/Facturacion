
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
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
static const struct sqlcxp sqlfpn =
{
    14,
    "./pc/compos.pc"
};


static unsigned int sqlctx = 862947;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[50];
   unsigned long  sqhstl[50];
            int   sqhsts[50];
            short *sqindv[50];
            int   sqinds[50];
   unsigned long  sqharm[50];
   unsigned long  *sqharc[50];
   unsigned short  sqadto[50];
   unsigned short  sqtdso[50];
} sqlstm = {12,50};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(char *, int *);

 static const char *sq0005 = 
"select  /*+  index (CO_CARTERA PK_CO_CARTERA)  +*/ (IMPORTE_DEBE-IMPORTE_HAB\
ER)  from CO_CARTERA where (((((COD_CLIENTE=:b0 and FEC_ANTIGUEDAD<=TO_DATE(:b\
1,'YYYYMMDD')) and (NUM_CUOTA=0 or NUM_CUOTA is null )) and COD_TIPDOCUM<>5) a\
nd COD_TIPDOCUM<>59) and COD_TIPDOCUM<>60)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,67,0,260,409,0,0,1,0,0,1,0,2,5,0,0,
24,0,0,2,145,0,261,620,0,0,4,4,0,1,0,1,4,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
55,0,0,3,119,0,261,629,0,0,3,3,0,1,0,1,4,0,0,1,97,0,0,1,3,0,0,
82,0,0,4,143,0,261,643,0,0,3,3,0,1,0,1,4,0,0,1,97,0,0,1,3,0,0,
109,0,0,5,285,0,265,696,0,0,2,2,0,1,0,1,3,0,0,1,5,0,0,
132,0,0,5,0,0,269,707,0,0,1,0,0,1,0,2,4,0,0,
151,0,0,5,0,0,271,720,0,0,0,0,0,1,0,
166,0,0,6,0,0,273,896,0,0,1,1,0,1,0,1,97,0,0,
185,0,0,6,0,0,277,906,0,0,50,50,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
4,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
400,0,0,7,126,0,260,1284,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
423,0,0,8,0,0,273,1473,0,0,1,1,0,1,0,1,97,0,0,
442,0,0,8,0,0,277,1484,0,0,30,30,0,1,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,
97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,0,
577,0,0,9,147,0,260,2009,0,0,3,2,0,1,0,2,4,0,0,1,3,0,0,1,3,0,0,
604,0,0,10,0,0,273,2102,0,0,1,1,0,1,0,1,97,0,0,
623,0,0,10,0,0,277,2118,0,0,24,24,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
734,0,0,10,0,0,277,2241,0,0,24,24,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,4,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
845,0,0,11,0,0,273,2539,0,0,1,1,0,1,0,1,97,0,0,
864,0,0,11,0,0,277,2609,0,0,50,50,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,3,0,
0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1079,0,0,11,0,0,277,2889,0,0,50,50,0,1,0,1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,3,0,
0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
1294,0,0,12,325,0,260,3317,0,0,3,2,0,1,0,2,97,0,0,1,97,0,0,1,97,0,0,
};


/****************************************************************************/
/* Fichero    : compos.pc                                                   */
/* Descripcio : funciones para el paso a Historicos de los datos facturados */
/* Autor      : Mauricio Villagra Villalobos                                */
/* Fecha      : 09-08-1999                                                  */
/*              Modificación para Insertar facturas y detalle en nuevas     */
/*              tablas de proceso, FA_FACTDOCU_CICLO, FA_FACTCLIE_CICLO,    */
/*              FA_FACTABON_CICLO; FA_FACTCONC_CICLO. (MVV)                 */
/****************************************************************************/
/* Fecha      : 17-11-1999                                                  */
/*              Modificación de Composision para Incorporar Tipos de Doc.   */
/*              Boletas y Facturas Exentas. (MVV)                           */
/****************************************************************************/
/* Fecha      : 24-04-2003                                                  */
/*              Modificación de Composision para Incorporar Codigo operadora*/
/*              a tabla de documentos. (NMV)                                */
/****************************************************************************/

#define _COMPOSICION_PC_

#include <compos.h>

/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
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
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
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



#define NREG_CONC_HOSTARRAY 100 /* 42970 */

extern char * alltrim(char *s);

/*---------------------------------------------------------------------------*/
/* OBTENCION DE OFICINA EMISORA A PARTIR DE LA OFICINA DE LA PRIMER VENTA    */
/* Incorporado por PGonzalez 17-03-2004                      */
/*---------------------------------------------------------------------------*/

double round(double valor)
{
        return((double)(long)(valor+0.5));
}


/*---------------------------------------------------------------------------*/
/* QUITA LOS ESPACIOS EN BLANCO AL INICIO Y AL FINAL DE UNA CADENA DE        */
/* CARACTERES                                                */
/*---------------------------------------------------------------------------*/
char * szfnTrim(char * strin)

{
    int   i = 0, l = 0;
    char strtmps[STR_LONG];

    memset(strtmps, 0, STR_LONG);

    while (*(strin + i) == ' ')
        i++;

    strcpy(strtmps,(strin + i));


    l = strlen(strtmps) - 1;
    while ((l >= 0) && ((*(strtmps + l ) == ' ')||(*(strtmps + l ) == '\n')))
    {
        *(strtmps + l ) = '\0';l--;
    }

    strcpy(strin,strtmps);
    return(strin);
}

/****************************************************************************/
/*                            funcion : bfnPasoHistoricos                   */
/****************************************************************************/
BOOL bfnPasoHistoricos (void)
{
    int bConcAfecto = FALSE;
    int bConcExento = FALSE;
    int iCaTriBut   = 0;
    strcpy (stAnomProceso.szDesProceso,"Paso a Historicos")  ;
    vDTrazasLog (szExeName,"\n\t\t* %s",LOG03,stAnomProceso.szDesProceso);

    /********************************************************************/
    /*  Validacion de Conceptos Afectos y Exentos en un Documento       */
    /********************************************************************/

    if (!bfnValCatImpDocu(stCliente.lCodCliente,&bConcAfecto, &bConcExento))
    {
        iDError(szExeName, ERR000, vInsertarIncidencia, "Paso a Historicos"
                             ,"Flag de Impuestos Inconsistente (bfnValCatImpDocu)");
        return FALSE;
    }

    /********************************************************************/
    /*  Validacion de Documentos Puntuales Exentos o Afectos  No Valido */
    /********************************************************************/

    if (stProceso.iCodTipDocum != stDatosGener.iCodCiclo)
    {
        if (!bConcAfecto && !bConcExento)
        {
            vDTrazasError(szExeName,"\n\t=> Error en el Paso Historico de Documentos"
                                    "\n\t   No Se Puede Emitir Documento con Conceptos Afectos y Exentos",LOG03);
            iDError(szExeName, ERR000, vInsertarIncidencia, "Paso a Historicos"
                             ,"No Se Puede Emitir Documento con Conceptos Afectos y Exentos");
            return FALSE;
        }
    }
    else
    /********************************************************************/
    /*  Validacion de Documentos Puntuales Exentos y Afectos            */
    /*  Dtermionar la Categoria Tributaria del Cliente Factura o Boleta */
    /********************************************************************/
    {
        if (!bGetCatTribCliente(stCliente.lCodCliente   ,
                           stInterFact.szCodCaTribut    ,
                           stCiclo.szFecEmision         ))
        {
            vDTrazasError(szExeName,"\n\t=> Error al Obtener Categoria Tributaria del Clientes "
                                    "\n\t\t Cod. Cliente [%ld]",LOG03,stCliente.lCodCliente);
            iDError(szExeName, ERR000, vInsertarIncidencia, "Paso a Historicos","bGetCatTribCliente");
            return FALSE;
        }
        stInterFact.iCodTipMovimien =   stDatosGener.iCodCiclo  ;
        stInterFact.iCodModVenta    =   iCONTADO                ;
        stInterFact.iNumCuotas      =   0                       ;
        if (!bfnAddHistAboCero())
        {
            iDError(szExeName, ERR000, vInsertarIncidencia, "Paso a Historicos","bfnAddHistAboCero");
            return FALSE;
        }
    }
    /********************************************************************/

    if (((bConcAfecto) && (bConcExento)) || (bConcAfecto))
    {
        vDTrazasLog(szExeName,"\n\t\t\t** Documento Afecto **",LOG03);
        iCaTriBut=iCODCATRIBUT_AFECTO;
    }
    else
    {
        vDTrazasLog(szExeName,"\n\t\t\t** Documento Exento **",LOG03);
        iCaTriBut=iCODCATRIBUT_EXENTO;
    }

    if (!bfnPasoHistDocu (iCaTriBut))
    {
        vDTrazasError(szExeName,"\n\t=> Error en el Paso Historico de Documentos\n",LOG03);
        return FALSE;
    }
    if (!bfnPasoHistClie ())
    {
        vDTrazasLog (szExeName,"\n\t=> Error en el Paso Historico de Cliente\n",LOG03);
        return FALSE;
    }
    if (!bfnPasoHistAbo ())
    {
        vDTrazasLog (szExeName,"\n\t=> Error en el Paso Historico de Abonados\n",LOG03);
        return FALSE;
    }
    if (!bfnPasoHistConc ())
    {
        vDTrazasLog(szExeName,"\n\t=>Error en el Paso Historico de Conceptos\n",LOG03);
        return FALSE;
    }

    return TRUE;
}/**************************** Final bfnPasoHistoricos **********************/

/**********************************************************************************/
/*                             funcion : bfnPasoHistDocu                          */
/**********************************************************************************/
/* static BOOL bfnPasoHistDocu  (int iTipImpositiva, BOOL  bAfecto, BOOL bExento) */
/* se va a generar solo un documento aunque tenga conceptos afectos y afectos     */
/* cdescouv 12/04/2002                                                            */
/**********************************************************************************/
static BOOL bfnPasoHistDocu  (int iTipImpositiva)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char szhIndOrdenTotal[13]; /* EXEC SQL VAR szhIndOrdenTotal IS STRING(13); */ 

    static char szhCodOficina   [3]; /* EXEC SQL VAR szhCodOficina IS STRING(3); */ 

    /* EXEC SQL END DECLARE SECTION  ; */ 


    char    szFecEmision  [15]= "";
    char    szFecVencimi  [15]= "";
    char    szCodOficEmisora[3]="";

    OFICINA pstOficina; /* estructura temporal para obtencion de los datos de oficina */
    OFICINAEMIS pstOfiEmi;   /* estructura temporal para obtencion de los datos de oficina Emisora */

    vDTrazasLog (szExeName, "\n\t\t* Paso a Historico de Documento %s "
                            ,LOG04,(iTipImpositiva == iCODCATRIBUT_AFECTO ? "Afecto":"Exento"));

    memset (&stHistDocu,0,sizeof(HISTDOCU));

    stHistDocu.lCodCliente        = stCliente.lCodCliente       ;
    stHistDocu.lCodVendedorAgente = stProceso.lCodVendedorAgente;
    stHistDocu.lCodVendedor       = stProceso.lCodVendedorAgente;
    stHistDocu.iCodCentrEmi       = stProceso.iCodCentrEmi      ;

    vDTrazasLog (szExeName,"\t\tstProceso.iCodTipDocum(%d)\n",LOG05,stProceso.iCodTipDocum);

    if(stProceso.iCodTipDocum == stDatosGener.iCodNotaCre)  /* 25 = NOTA CREDITO */
    {
        /* stHistDocu.iIndFactur  = stPreFactura.A_PFactura.iIndFactur[1]; */   /* PGG - 150645 - 29-10-2010 - Se comenta porque deja cero cuando es solo un registro */
        stHistDocu.iIndFactur  = 1;         /* PGG - 150645 - 29-10-2010 - Se fuerza el valor a 1 para las notas de credito para que Cobranza lo considere correctamente */
    }
    else
    {
        stHistDocu.iIndFactur  = stCliente.iIndFactur;
    }

    stHistDocu.lNumFolio          = 0                           ;

    strcpy (stHistDocu.szPrefPlaza,"");
    strcpy (stHistDocu.szCodOperadora,szfnTrim(stCliente.szCodOperadora));

    if(stProceso.iCodTipDocum==stDatosGener.iCodContado)
    {
        strcpy(szhCodOficina,stVenta.szCodOficina);
    }
    else if(stProceso.iCodTipDocum==stDatosGener.iCodCompra)
    {
        if (stTransContado.lNumTransaccion > 0)
        {
            strcpy(szhCodOficina,stTransContado.szCodOficina);
        }
        else
        {
            strcpy(szhCodOficina,stVenta.szCodOficina);
        }
    }
    else if( stProceso.iCodTipDocum==stDatosGener.iCodNotaCre ||
             stProceso.iCodTipDocum==stDatosGener.iCodNotaDeb)
    {
        strcpy(stHistDocu.szCodPlaza,szfnTrim(stNota.szCodPlaza));
        strcpy(stHistDocu.szCodOperadora,szfnTrim(stNota.szCodOperadora));
        strcpy(stHistDocu.szCodOficina,stNota.szCodOficina);
        strcpy(szhCodOficina,stNota.szCodOficina);
        strcpy(stProceso.szCodOficina, stHistDocu.szCodOficina);
    }
    else
    {
        strcpy(szhCodOficina,stProceso.szCodOficina);

    }

    alltrim(szhCodOficina);

    /* PGG - 166805 - Beta para salir del paso - 30-03-2011 */
/*    if (strcmp(szhCodOficina, "") == 0)
        strcpy(szhCodOficina,stProceso.szCodOficina); */

    vDTrazasLog (szExeName,"\t\tbfnPasoHistDocu:szhCodOficina(%s)\n",LOG05,szhCodOficina);

    if (!bfnFindOficina (szhCodOficina, &pstOficina ))
    {
        vDTrazasLog (szExeName, "\n\t\t Error Obtener oficina : [%s] \n",LOG01,szhCodOficina);
        return FALSE;
    }

    strcpy(stHistDocu.szCodPlaza,szfnTrim(pstOficina.szCodPlaza));
    vDTrazasLog ("","\t\tbfnPasoHistDocu:QRY GE_CIUDADES.COD_PLAZA ok: szCodPlaza (%s)\n",LOG05,stHistDocu.szCodPlaza);

    strcpy (stHistDocu.szNomUsuarOra,stProceso.szNomUsuarOra);
    strcpy (stHistDocu.szFecCambioMo,szSysDate)              ;

    stHistDocu.iIndSuperTel = stCliente.iIndSuperTel;

    /* Zona Impositiva */
    stHistDocu.iCodZonaImpo = stPreFactura.iCodZonaImpo;
    /* *************** */

    if (!bfnGetTotDocu (&stHistDocu))
         return FALSE;

    /************************************************************************************/
    /*  Rutina bfnGetCodTipDocum interfact.pc : Asignacion el Tipo de Documento segun   */
    /*  Tipo de Movimiento y Tipo de Factura Afecta/Exenta                              */
    /************************************************************************************/
    if (!bfnGetCodTipDocum(&stInterFact, iTipImpositiva))
        return FALSE;
    /************************************************************************************/
    /*  Asignacion del Tipo de Documento para Movimiento de Ciclo                       */
    /************************************************************************************/
    stHistDocu.iCodTipDocum       = stInterFact.iCodTipDocum;
    stHistDocu.iCodModVenta       = stInterFact.iCodModVenta;
    stHistDocu.iNumCuotas         = stInterFact.iNumCuotas  ;
    /************************************************************************************/

    vDTrazasLog(szExeName,"\n\t**** stProceso.iCodTipDocum=[%d] stDatosGener.iCodCiclo=[%d] stHistDocu.iCodTipDocum=[%d]\n"
                            "\t**** stCliente.iIndFactur=[%d] stHistDocu.dTotFactura=[%f] stCliente.iIndSuperTel=[%d]\n"
                            "\t**** stVenta.lNumVenta=[%ld] stVenta.lNumTransaccion=[%ld] stTransContado.lNumTransaccion=[%ld]\n"
                            "\t**** stDatosGener.iCodMiscela=[%d] stHistDocu.iCodModVenta=[%d]\n", LOG05,
                            stProceso.iCodTipDocum, stDatosGener.iCodCiclo, stHistDocu.iCodTipDocum,
                            stCliente.iIndFactur, stHistDocu.dTotFactura, stCliente.iIndSuperTel,
                            stVenta.lNumVenta, stVenta.lNumTransaccion, stTransContado.lNumTransaccion,
                            stDatosGener.iCodMiscela, stHistDocu.iCodModVenta);


    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        if (!bGetLetra (stProceso.iCodTipDocum,stCliente.iCodCatImpos,
                        stHistDocu.szLetra))
            return FALSE;

        if (!bGenNumSecuenciasEmi (stProceso.iCodTipDocum, stHistDocu.szLetra,
                                   stProceso.iCodCentrEmi,&stProceso.lNumSecuAg))
            return FALSE;

        if (!stCliente.iIndFactur  || (round(stHistDocu.dTotFactura) == 0)  || stCliente.iIndSuperTel)
        {
            if (pstParamGener.iTipoFoliacion == 1)
            {
                if (!bfnGetOficinaEmisora (&pstOfiEmi, stProceso.iCodTipDocum))
                {
                    vDTrazasLog  (szExeName,"\n\t** Error En la obtencion de Oficina Emisora**\n",LOG01);
                    return FALSE;
                }

                if (!bfnConsumeFolio (  szCodOficEmisora,
                            stHistDocu.iCodTipDocum      ,
                            szfnTrim(stCliente.szCodOperadora) ,
                            stProceso.lNumProceso        ,
                            szSysDate                    ,
                            &stHistDocu.lNumFolio        ,
                            stHistDocu.szPrefPlaza))
                {
                    vDTrazasLog  (szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    vDTrazasError(szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    return FALSE;
                }

                strcpy(stHistDocu.szCodOficina, szCodOficEmisora);
            }
            else
            {
                if (!bfnConsumeFolio (  stDatosGener.szCodOficCentral,
                            stHistDocu.iCodTipDocum      ,
                            szfnTrim(stCliente.szCodOperadora) ,
                            stProceso.lNumProceso        ,
                            szSysDate                    ,
                            &stHistDocu.lNumFolio        ,
                            stHistDocu.szPrefPlaza))
                {
                    vDTrazasLog  (szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    vDTrazasError(szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    return FALSE;
                }
            }
        }

        stHistDocu.lNumSecuenci = stProceso.lNumSecuAg        ;
        stHistDocu.lCodVendedor = stProceso.lCodVendedorAgente;
    }
    else
    {
        /****************************************************************/
        /* * Documentos No Ciclicos                                   * */
        /****************************************************************/
        stHistDocu.lNumSecuenci   = stProceso.lNumSecuAg;
        strcpy (stHistDocu.szLetra, stProceso.szLetraAg);

        if (stVenta.lNumVenta > 0 && stVenta.lNumTransaccion > 0)
        {
            stHistDocu.lNumVenta       = stVenta.lNumVenta      ;
            stHistDocu.lCodVendedor    = stVenta.lCodVendedor   ;
            stHistDocu.lNumTransaccion = stVenta.lNumTransaccion;
            strcpy(stHistDocu.szCodOficina, stVenta.szCodOficina);

        }
        else
        {
            if (stTransContado.lNumTransaccion > 0)
            {
                stHistDocu.lNumTransaccion = stTransContado.lNumTransaccion   ;
                stHistDocu.lCodVendedor    = stTransContado.lCodVendedorAgente;
            }

            strcpy(stHistDocu.szCodOficina, stProceso.szCodOficina);

        }
        if (stProceso.iCodTipDocum == stDatosGener.iCodMiscela)
        {
            strcpy (stHistDocu.szPrefPlaza,stInterFact.szPrefPlaza);

            stHistDocu.lNumVenta       = stInterFact.lNumVenta;
            if (stHistDocu.iCodModVenta == iCONSIGNACION ||
                stHistDocu.iCodModVenta == iCARGOCUENTA  ||
                stHistDocu.iCodModVenta == iCTDOCONSIG   ||
                stHistDocu.iCodModVenta == iNVOREGALO     )
            {

                if (!bfnConsumeFolio (  stDatosGener.szCodOficCentral,
                        stDatosGener.iCodConsignacion ,
                        szfnTrim(stCliente.szCodOperadora)  ,
                        stProceso.lNumProceso         ,
                        szSysDate                     ,
                        &stHistDocu.lNumFolio         ,
                        stHistDocu.szPrefPlaza))
                {
                    vDTrazasLog  (szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    vDTrazasError(szExeName,"\n\t** Error Consumo de folios **",LOG01);
                    return FALSE;
                }
            }
        }
    }
    if (stDatosGener.szIndOrdenTotal [0] == 0)
    {

        /* EXEC SQL SELECT TO_CHAR (FA_SEQ_IND_ORDENTOTAL.NEXTVAL)
                 INTO   :szhIndOrdenTotal
                 FROM   DUAL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TO_CHAR(FA_SEQ_IND_ORDENTOTAL.nextval ) into :\
b0  from DUAL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhIndOrdenTotal;
        sqlstm.sqhstl[0] = (unsigned long )13;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Fa_Seq_Ind_OrdenTotal",
                     szfnORAerror ());
            return   FALSE           ;
        }

        strcpy (stDatosGener.szIndOrdenTotal, szhIndOrdenTotal);
    }

    strcpy (stHistDocu.szIndOrdenTotal, stDatosGener.szIndOrdenTotal);

    vDTrazasLog(szExeName,"\n\t**** stHistDocu.lNumFolio=[%ld] stHistDocu.lNumSecuenci=[%ld] stHistDocu.lCodVendedor=[%ld]"
                          "\n\t**** stHistDocu.lNumTransaccion=[%ld] stHistDocu.lCodVendedor=[%ld] stHistDocu.szIndOrdenTotal=[%s]\n"
                            ,LOG05,stHistDocu.lNumFolio, stHistDocu.lNumSecuenci, stHistDocu.lCodVendedor,
                            stHistDocu.lNumTransaccion, stHistDocu.lCodVendedor,stHistDocu.szIndOrdenTotal);


    vfnComposicionNumCTC(stHistDocu.szNumCTC);

    stHistDocu.lNumProceso     = stProceso.lNumProceso ;
    stHistDocu.lCodPlanCom     = stCliente.lCodPlanCom ;
    stHistDocu.iCodCatImpos    = stCliente.iCodCatImpos;

    if ((stCiclo.lCodCiclFact > 0) && (stProceso.iCodTipDocum != stDatosGener.iCodBaja))
    {
        strcpy (stHistDocu.szFecEmision ,stCiclo.szFecEmision );
        strcpy (stHistDocu.szFecCaducida,stCiclo.szFecCaducida);
        strcpy (stHistDocu.szFecProxVenc,stCiclo.szFecProxVenc);

        if (!bfnDiasVencimiento(stCliente.lCodCliente,
                                stCliente.lCodCuenta,
                                stProceso.iCodTipDocum,
                                stCiclo.szFecEmision,
                                stCiclo.szFecVencimie,
                                szFecVencimi))
        {
            vDTrazasLog  (szExeName,"\n\t** Error obtencion de la fecha de vencimiento **",LOG01);
            vDTrazasError(szExeName,"\n\t** Error obtencion de la fecha de vencimiento **",LOG01);
            return   FALSE;
        }
        strcpy (stHistDocu.szFecVencimie,szFecVencimi);

        stHistDocu.lCodCiclFact = stCiclo.lCodCiclFact;
    }
    else
    {
        if (strlen(stInterFact.szFecVencimiento))
            strcpy (stHistDocu.szFecVencimie,stInterFact.szFecVencimiento);
        else
        {
            if (!bfnDiasVencimiento(stCliente.lCodCliente,
                                    stCliente.lCodCuenta,
                                    stProceso.iCodTipDocum,
                                    szSysDate,
                                    szSysDate,
                                    szFecVencimi))
            {
                vDTrazasLog  (szExeName,"\n\t** Error obtencion de la fecha de vencimiento **",LOG01);
                vDTrazasError(szExeName,"\n\t** Error obtencion de la fecha de vencimiento **",LOG01);
                return   FALSE;
            }
            strcpy (stHistDocu.szFecVencimie,szFecVencimi);
        }
        strcpy (stHistDocu.szFecEmision ,stInterFact.szFecIngreso);
        strcpy (stHistDocu.szFecCaducida,szSysDate);

        stHistDocu.lCodCiclFact      = ORA_NULL    ;
        stHistDocu.szFecProxVenc [0] = 0           ;
    }
    /**************************************************************************/
    /*   Mauricio Villagra Villalobos   14.05.1999                            */
    /*   Cargar CodCiclFact por Default para Documentos Puntuales    19010101 */
    /**************************************************************************/
    if (stProceso.iCodTipDocum != stDatosGener.iCodCiclo)
    {
        stHistDocu.lCodCiclFact      = stDatosGener.lCodCicloDocPuntual;
    }
    if (stProceso.iCodTipDocum == stDatosGener.iCodNotaCre ||
        stProceso.iCodTipDocum == stDatosGener.iCodNotaDeb )
    {
        strcpy (stHistDocu.szLetraRel, stProceso.szLetraNot)              ;
        stHistDocu.lNumSecuRel           = stProceso.lNumSecuNot          ;
        stHistDocu.iCodTipDocumRel       = stProceso.iCodTipDocNot        ;
        stHistDocu.lCodVendedorAgenteRel = stProceso.lCodVendedorAgenteNot;
        stHistDocu.iCodCentrRel          = stProceso.iCodCentrNot         ;

    }
    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo ||
        stProceso.iCodTipDocum == stDatosGener.iCodBaja  ||
        stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion)
    {
        vDTrazasLog (szExeName, "\n\t\t=> Entro por: %d", LOG03, stProceso.iCodTipDocum);
        if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
            strcpy (szFecEmision,stCiclo.szFecEmision);
        else
            strcpy (szFecEmision,szSysDate);
        vDTrazasLog (szExeName, "\n\t\t=> Fecha de Emision: %s", LOG03, szFecEmision);

        /************************************************************************************/
        /*   Mauricio Villagra    06-03-2000.                                               */
        /*   Recupera Saldo Anterior por Cliente.                                           */
        /*   Si Genera dos documentos Afecto y Exento solo debe incluir en saldo anterior   */
        /*   en el documento exento.                                                        */
        /************************************************************************************/
        if (!bfnGetSaldoAnt (stCliente.lCodCliente,&stHistDocu.dImpSaldoAnt,szFecEmision))
             return FALSE;
        /************************************************************************************/
        /* A pedido de Juan Carlos Godoy, los clientes PAC ahora arrastraran saldo anterior */
        /* if (strcmp(stCliente.szIndDebito, "A") == 0)      Convenio PAC no arrastra saldo */
        /*       stHistDocu.dImpSaldoAnt = 0;                                               */
        /************************************************************************************/
        if (!bConverMoneda  (stDatosGener.szMonedaCobros,
                             stDatosGener.szCodMoneFact ,
                             stHistDocu.szFecEmision    ,
                             &stHistDocu.dImpSaldoAnt   ,
                             stProceso.iCodTipDocum))
             return FALSE;

       if (stCliente.dImpRecargo != 0.0)
            stHistDocu.dImpSaldoAnt -= stCliente.dImpRecargo ;

       if (stHistDocu.dImpSaldoAnt < 0)
           stHistDocu.dTotPagar = (stHistDocu.dTotFactura <
                                   (-1)*stHistDocu.dImpSaldoAnt)?0.0:
                                   stHistDocu.dTotPagar + stHistDocu.dImpSaldoAnt;
       else
           stHistDocu.dTotPagar += stHistDocu.dImpSaldoAnt;
    }
    else
    {
        stHistDocu.dImpSaldoAnt = 0.0;
    }
    stHistDocu.iIndSuperTel = stCliente.iIndSuperTel ;
    stHistDocu.iCodOpRedFija= stCliente.iCodOpRedFija;

    if (stProceso.iCodTipDocum == stDatosGener.iCodContado)
    {
        if (!bfnDBUpdateVenta (&stHistDocu))
             return FALSE;
    }
    if (!bfnInsertHistDocu (&stHistDocu))
         return FALSE;
    return TRUE;
}/***************************** Final bfnPasoHistDocu  ***********************/

/*****************************************************************************/
/*                            funcion : vfnComposicionNumCTC                 */
/* - Posicion 1 (long 1): 8                                                  */
/* - Posicion 2 (long 9): Ind_OrdenTotal                                     */
/* - Posicion 3 (long 1): Digito Verificador                                 */
/*****************************************************************************/
static void vfnComposicionNumCTC (char *szNumCTC)
{
    int i       = 0;
    int j       = 2; /* j tomara los valores de 2 a 7 inclusives */
    int iDigito = 0;
    long lInd_OrdenTotal=0;

    char szAux[2] = "";
    char szCTC[13]= "";

    div_t stRes       ;

    lInd_OrdenTotal=atol(stDatosGener.szIndOrdenTotal);
    sprintf(szCTC, "8%.9ld", lInd_OrdenTotal);

    i = strlen(szCTC)-1;

    while (i >= 0)
    {
       if (j >= 8)
         j  = 2;
       strncpy (szAux, &szCTC [i], 1);
       iDigito += (atoi (szAux) * j);
       j++;
       i--;
    }

    stRes = div (iDigito, 11);

    if( (11-stRes.rem) == 10 )
       sprintf (szNumCTC,"%s%s",szCTC, szDIG10);
    else
       sprintf (szNumCTC,"%s%d",szCTC,((11-stRes.rem)==11)?0:11-stRes.rem);

    vDTrazasLog (szExeName, "\n\t\t=> Numero CTC %s", LOG03, szNumCTC);

}/**************************** Final vfnComposicionNumCTC ********************/

/*****************************************************************************/
/*                            funcion : bfnDBUpdateVenta                     */
/*****************************************************************************/
static BOOL bfnDBUpdateVenta (HISTDOCU *stHis)
{
  char szFuncion [30] = "";

  if (stHis->lNumVenta > 0 )
  {
      vDTrazasLog (szExeName,
                   "\n\t\t* Parametros de Entrada a Update Venta"
                   "\n\t\t=>Num.Venta       [%ld]"
                   "\n\t\t=>Num.Transaccion [%ld]", LOG06,
                   stHis->lNumVenta, stHis->lNumTransaccion);

      strcpy (szFuncion, "Update=>Ga_Ventas");
      if (stHis->lNumTransaccion > 0)
      {
          /* EXEC SQL UPDATE /o+ index (GA_VENTAS PK_GA_VENTAS) o/
                          GA_VENTAS
                   SET    IMP_VENTA = ROUND( :stHis->dTotCargosMe ),
                          COD_MONEDA= :stDatosGener.szCodMoneFact
                   WHERE  NUM_VENTA     = :stHis->lNumVenta
                   AND  NUM_TRANSACCION = :stHis->lNumTransaccion; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 4;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "update  /*+  index (GA_VENTAS PK_GA_VENTAS)  +*/ GA\
_VENTAS  set IMP_VENTA=ROUND(:b0),COD_MONEDA=:b1 where (NUM_VENTA=:b2 and NUM_\
TRANSACCION=:b3)";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )24;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)256;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&(stHis->dTotCargosMe);
          sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)(stDatosGener.szCodMoneFact);
          sqlstm.sqhstl[1] = (unsigned long )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (unsigned char  *)&(stHis->lNumVenta);
          sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[2] = (         int  )0;
          sqlstm.sqindv[2] = (         short *)0;
          sqlstm.sqinds[2] = (         int  )0;
          sqlstm.sqharm[2] = (unsigned long )0;
          sqlstm.sqadto[2] = (unsigned short )0;
          sqlstm.sqtdso[2] = (unsigned short )0;
          sqlstm.sqhstv[3] = (unsigned char  *)&(stHis->lNumTransaccion);
          sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[3] = (         int  )0;
          sqlstm.sqindv[3] = (         short *)0;
          sqlstm.sqinds[3] = (         int  )0;
          sqlstm.sqharm[3] = (unsigned long )0;
          sqlstm.sqadto[3] = (unsigned short )0;
          sqlstm.sqtdso[3] = (unsigned short )0;
          sqlstm.sqphsv = sqlstm.sqhstv;
          sqlstm.sqphsl = sqlstm.sqhstl;
          sqlstm.sqphss = sqlstm.sqhsts;
          sqlstm.sqpind = sqlstm.sqindv;
          sqlstm.sqpins = sqlstm.sqinds;
          sqlstm.sqparm = sqlstm.sqharm;
          sqlstm.sqparc = sqlstm.sqharc;
          sqlstm.sqpadto = sqlstm.sqadto;
          sqlstm.sqptdso = sqlstm.sqtdso;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      }
      else
      {
          /* EXEC SQL UPDATE /o+ index (GA_VENTAS PK_GA_VENTAS) o/
                          GA_VENTAS
                   SET    IMP_VENTA = ROUND( :stHis->dTotCargosMe ),
                          COD_MONEDA= :stDatosGener.szCodMoneFact
                   WHERE  NUM_VENTA = :stHis->lNumVenta; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 4;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "update  /*+  index (GA_VENTAS PK_GA_VENTAS)  +*/ GA\
_VENTAS  set IMP_VENTA=ROUND(:b0),COD_MONEDA=:b1 where NUM_VENTA=:b2";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )55;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)256;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&(stHis->dTotCargosMe);
          sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)(stDatosGener.szCodMoneFact);
          sqlstm.sqhstl[1] = (unsigned long )4;
          sqlstm.sqhsts[1] = (         int  )0;
          sqlstm.sqindv[1] = (         short *)0;
          sqlstm.sqinds[1] = (         int  )0;
          sqlstm.sqharm[1] = (unsigned long )0;
          sqlstm.sqadto[1] = (unsigned short )0;
          sqlstm.sqtdso[1] = (unsigned short )0;
          sqlstm.sqhstv[2] = (unsigned char  *)&(stHis->lNumVenta);
          sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
          sqlstm.sqhsts[2] = (         int  )0;
          sqlstm.sqindv[2] = (         short *)0;
          sqlstm.sqinds[2] = (         int  )0;
          sqlstm.sqharm[2] = (unsigned long )0;
          sqlstm.sqadto[2] = (unsigned short )0;
          sqlstm.sqtdso[2] = (unsigned short )0;
          sqlstm.sqphsv = sqlstm.sqhstv;
          sqlstm.sqphsl = sqlstm.sqhstl;
          sqlstm.sqphss = sqlstm.sqhsts;
          sqlstm.sqpind = sqlstm.sqindv;
          sqlstm.sqpins = sqlstm.sqinds;
          sqlstm.sqparm = sqlstm.sqharm;
          sqlstm.sqparc = sqlstm.sqharc;
          sqlstm.sqpadto = sqlstm.sqadto;
          sqlstm.sqptdso = sqlstm.sqtdso;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


      }
  }
  else
  {
      vDTrazasLog (szExeName,
                   "\n\t\t* Parametros de Entrada a Update Ga_TransContado"
                   "\n\t\t=>Num.Transaccion[%ld]",LOG06,stHis->lNumTransaccion);

      strcpy (szFuncion, "Update=>Ga_TransContado");
      /* EXEC SQL UPDATE /o+ index (GA_TRANSCONTADO PK_GA_TRANSCONTADO) o/
                      GA_TRANSCONTADO
               SET    IMP_VENTA = ROUND ( :stHis->dTotCargosMe ),
                      COD_MONEDA= :stDatosGener.szCodMoneFact
               WHERE  NUM_TRANSACCION = :stHis->lNumTransaccion; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 4;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "update  /*+  index (GA_TRANSCONTADO PK_GA_TRANSCONTADO)\
  +*/ GA_TRANSCONTADO  set IMP_VENTA=ROUND(:b0),COD_MONEDA=:b1 where NUM_TRANS\
ACCION=:b2";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )82;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&(stHis->dTotCargosMe);
      sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)(stDatosGener.szCodMoneFact);
      sqlstm.sqhstl[1] = (unsigned long )4;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&(stHis->lNumTransaccion);
      sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


  }
  if (SQLCODE)
      iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror());

  return (SQLCODE != SQLOK)?FALSE:TRUE;
}/**************************** Fina bfnDBUpdateVenta    **********************/

/*****************************************************************************/
/*                          funcion : bfnGetSaldoAnt                         */
/*****************************************************************************/
static BOOL bfnGetSaldoAnt (long    lCodCliente ,
                            double *dImpSaldoAnt,
                            char   *szFecEmision)
{
   static BOOL   bRes     = TRUE ;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char   szhFecEmision[9];/* EXEC SQL VAR szhFecEmision IS STRING(9); */ 

   static double dhImporte       ;
   static long   lhCodCliente    ;
   /* EXEC SQL END DECLARE SECTION; */ 


    strncpy (szhFecEmision,szFecEmision,8);
    szhFecEmision [8] = '\0'              ;

    lhCodCliente = lCodCliente;

    vDTrazasLog (szExeName,"\n\t\t* Parametros de Entra Saldo Anterior\n"
                           "\t\t=> Cod.Cliente  [%ld]\n"
                           "\t\t=> FecEmision   [%s] \n",LOG05,
                           lCodCliente,szSysDate);

    /* EXEC SQL DECLARE Cur_Cartera CURSOR FOR
         SELECT /o+ index (CO_CARTERA PK_CO_CARTERA) o/
                IMPORTE_DEBE-IMPORTE_HABER
         FROM   CO_CARTERA
         WHERE  COD_CLIENTE       = :lhCodCliente
         AND  FEC_ANTIGUEDAD   <= TO_DATE (:szhFecEmision,'YYYYMMDD')
/o
            AND  FEC_CADUCIDA <= SYSDATE
            AND  IND_FACTURADO    = 1
o/
           AND  ( NUM_CUOTA      = 0 OR   NUM_CUOTA IS NULL)
           AND  COD_TIPDOCUM != 5
           AND  COD_TIPDOCUM != 59
           AND  COD_TIPDOCUM != 60; */ 



    /* EXEC SQL OPEN Cur_Cartera; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )109;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhFecEmision;
    sqlstm.sqhstl[1] = (unsigned long )9;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Co_Cartera",
                szfnORAerror());
        return  (FALSE)         ;
    }
    while (SQLCODE == SQLOK)
    {
        dhImporte = 0.0;

        /* EXEC SQL FETCH Cur_Cartera INTO :dhImporte; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )132;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&dhImporte;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Fetch->Co_Cartera",szfnORAerror ());
            return  (FALSE)                              ;
        }
        if (SQLCODE == SQLOK)
            *dImpSaldoAnt += dhImporte;
        vDTrazasLog ("","\n\t\t=> Importe Saldo Anterior: [%f]\n", LOG05, *dImpSaldoAnt);
    }
    if (SQLCODE == SQLNOTFOUND)
    {
        /* EXEC SQL CLOSE Cur_Cartera; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )151;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close->Co_Cartera",
                     szfnORAerror());
            bRes = FALSE;
        }
        else
            bRes = TRUE;
   }
   return (bRes);
}/****************************** Final bfnGetSaldoAnt ************************/

/*****************************************************************************/
/*                          funcion : bfnGetTotDocu                          */
/*****************************************************************************/
static BOOL bfnGetTotDocu (HISTDOCU *pHis)
{
    int    i        = 0  ;
    for (i=0;i<stPreFactura.iNumRegistros;i++)
    {
        if (stPreFactura.A_PFactura.iCodTipConce[i] != IMPUESTO )
        {
            if (stPreFactura.A_PFactura.iFlagImpues [i] == 1)
                pHis->dAcumNetoGrav   += stPreFactura.A_PFactura.dImpFacturable[i];
            else
                pHis->dAcumNetoNoGrav += stPreFactura.A_PFactura.dImpFacturable[i];
        }
        else  /* IMPUESTO */
        {
           pHis->dAcumIva        += stPreFactura.A_PFactura.dImpFacturable[i];
        }

        if (stPreFactura.A_PFactura.iCodTipConce[i] == DESCUENTO)
           pHis->dTotDescuento   += stPreFactura.A_PFactura.dImpFacturable[i];
    }

    /*********************************************************/
    /* Realizacion de ajuste de IVA en factura (FA_HISTDOCU) */
    /*********************************************************/
    if(stPreFactura.iNumRegistros > 0)
    {
        pHis->dTotCargosMe = pHis->dAcumNetoGrav + pHis->dAcumNetoNoGrav + pHis->dAcumIva;
    }

    pHis->dTotCuotas  = 0;
    pHis->dTotFactura = pHis->dTotCargosMe;
    pHis->dTotPagar   = (pHis->iCodModVenta == iREGALO )?0.0 :pHis->dTotFactura;

   return TRUE;
}/************************** Final bfnGetTotDocu *****************************/


/*****************************************************************************/
/*                        funcion : bfnValCatImpDocu                         */
/*****************************************************************************/
static BOOL bfnValCatImpDocu (long lCodClie, int *bpAfecto , int *bpExento )
{
    int    i = 0     ;
    vDTrazasLog (szExeName,"\n\t\t\t* Validando Categoria Impositiva de Conceptos",LOG03);
    *bpAfecto = (int)  FALSE ;
    *bpExento = (int)  TRUE ;

    if (stPreFactura.iNumRegistros == 0)
    {
        vDTrazasLog   (szExeName,"\n\t\t\t* Cantidad de Conceptos Cero => Cliente [%ld]"
                                 "\n\t\t\t* Se asume Afecto "
                                ,LOG03,lCodClie);
        *bpAfecto = (int) TRUE;
    }

    for (i=0;i<stPreFactura.iNumRegistros;i++)
    {
        if (stPreFactura.A_PFactura.iCodTipConce[i]     != IMPUESTO &&
            stPreFactura.A_PFactura.dImpFacturable[i]   !=  0.0 )
        {
            switch (stPreFactura.A_PFactura.iFlagImpues [i])
            {
                case    iCODCATRIBUT_AFECTO :
                        *bpAfecto = (int) TRUE;
                        break;
                case    iCODCATRIBUT_EXENTO :
                        *bpExento = (int) TRUE;
                        break;
                default                     :
                    return FALSE;
                   /* break; */
            }
        }
    }
    return TRUE;
}/************************** Final bfnValCatImpDocu **************************/

/*****************************************************************************/
/*                            funcion : bfnInsertHistDocu                    */
/*****************************************************************************/
static BOOL bfnInsertHistDocu (HISTDOCU *pHis)
{
  char szCadena  [3000] = "";
  char szNomTable[25]   = "";
  char szFuncion [31]   = "";

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static short i_shFecVencimie         ;
  static short i_shFecCaducida         ;
  static short i_shFecProxVenc         ;
  static short i_shCodCiclFact         ;
  static short i_shNumSecuRel          ;
  static short i_shLetraRel            ;
  static short i_shCodTipDocumRel      ;
  static short i_shCodVendedorAgenteRel;
  static short i_shCodCentrRel         ;
  static short i_shNumVenta            ;
  static short i_shNumTransaccion      ;
  static short i_shCodOpRedFija        ;
  static short i_shCodModVenta         ;
  static short i_shCodOficina          ;
  /* EXEC SQL END DECLARE SECTION; */ 


  i_shFecVencimie           = (strcmp (pHis->szFecVencimie,""))?0:ORA_NULL;
  i_shFecCaducida           = (strcmp (pHis->szFecCaducida,""))?0:ORA_NULL;
  i_shFecProxVenc           = (strcmp (pHis->szFecProxVenc,""))?0:ORA_NULL;
  i_shCodCiclFact           = (pHis->lCodCiclFact    == ORA_NULL||
                               pHis->lCodCiclFact    == 0)?ORA_NULL:0;
  i_shNumSecuRel            = (pHis->lNumSecuRel     == ORA_NULL||
                               pHis->lNumSecuRel     == 0)?ORA_NULL:0;
  i_shLetraRel              = (pHis->szLetraRel[0]   == 0)?ORA_NULL:0;

  i_shCodTipDocumRel        = (pHis->iCodTipDocumRel == ORA_NULL||
                               pHis->iCodTipDocumRel == 0)?ORA_NULL:0;

  i_shCodVendedorAgenteRel  = (pHis->lCodVendedorAgenteRel == ORA_NULL||
                               pHis->lCodVendedorAgenteRel == 0)?ORA_NULL:0;

  i_shCodCentrRel           = (pHis->iCodCentrRel    == ORA_NULL||
                               pHis->iCodCentrRel    == 0)?ORA_NULL:0;
  i_shNumVenta              = (pHis->lNumVenta       == ORA_NULL||
                               pHis->lNumVenta       == 0)?ORA_NULL:0;
  i_shNumTransaccion        = (pHis->lNumTransaccion == ORA_NULL||
                               pHis->lNumTransaccion == 0)?ORA_NULL:0;

  i_shCodModVenta           = (pHis->iCodModVenta    <= 0)?ORA_NULL:0;
  i_shCodOpRedFija          = (pHis->iCodOpRedFija   == 0)?ORA_NULL:0;

  i_shCodOficina            = (strcmp (pHis->szCodOficina,""))?0:ORA_NULL;

  pHis->dTotPagar       = fnCnvDouble (pHis->dTotPagar      ,USOFACT);
  pHis->dTotCargosMe    = fnCnvDouble (pHis->dTotCargosMe   ,USOFACT);
  pHis->dAcumNetoGrav   = fnCnvDouble (pHis->dAcumNetoGrav  ,USOFACT);
  pHis->dAcumIva        = fnCnvDouble (pHis->dAcumIva       ,USOFACT);
  pHis->dImpSaldoAnt    = fnCnvDouble (pHis->dImpSaldoAnt   ,USOFACT);
  pHis->dTotFactura     = fnCnvDouble (pHis->dTotFactura    ,USOFACT);
  pHis->dTotCuotas      = fnCnvDouble (pHis->dTotCuotas     ,USOFACT);
  pHis->dTotDescuento   = fnCnvDouble (pHis->dTotDescuento  ,USOFACT);


  pHis->dAcumIva        = round(pHis->dAcumIva);
  pHis->dTotFactura     = round(pHis->dTotFactura);
  pHis->dAcumNetoNoGrav = round(pHis->dAcumNetoNoGrav);

  pHis->dTotPagar       = round(pHis->dTotPagar);

  pHis->dAcumNetoGrav   = pHis->dTotFactura - (pHis->dAcumNetoNoGrav + pHis->dAcumIva);


  if (stProceso.iCodTipDocum == FACT_CICLO)
  {
      sprintf(szNomTable,"FA_FACTDOCU_%ld",stCiclo.lCodCiclFact);
  }
  else
  {
      strcpy (szNomTable,"FA_FACTDOCU_NOCICLO");
  }
  vfnPrintHistDocu (pHis,szNomTable)               ;
  vfnInitCadenaInsertHistDocu (szCadena,szNomTable);

  /* EXEC SQL PREPARE sql_insert_histdocu FROM :szCadena; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )166;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
  sqlstm.sqhstl[0] = (unsigned long )3000;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


  if (SQLCODE)
  {
      strcpy (szFuncion,"PrePare=>")   ;
      strcat (szFuncion,szNomTable)    ;
      iDError(szExeName,ERR000,vInsertarIncidencia,
              szFuncion,szfnORAerror());
      return FALSE                     ;
  }

  /* EXEC SQL EXECUTE sql_insert_histdocu
           USING   :pHis->lNumSecuenci                                    ,
                   :pHis->iCodTipDocum                                    ,
                   :pHis->lCodVendedorAgente                              ,
                   :pHis->szLetra                                         ,
                   :pHis->iCodCentrEmi                                    ,
                   :pHis->dTotPagar                                       ,
                   :pHis->dTotCargosMe                                    ,
                   :pHis->dTotFactura                                     ,
                   :pHis->dTotCuotas                                      ,
                   :pHis->dTotDescuento                                   ,
                   :pHis->lCodVendedor                                    ,
                   :pHis->lCodCliente                                     ,
                   :pHis->szFecEmision                                    ,
                   :pHis->szFecCambioMo                                   ,
                   :pHis->szNomUsuarOra                                   ,
                   :pHis->dAcumNetoGrav                                   ,
                   :pHis->dAcumNetoNoGrav                                 ,
                   :pHis->dAcumIva                                        ,
                   :pHis->szIndOrdenTotal                                 ,
                   :pHis->iIndFactur                                      ,
                   :pHis->iIndVisada                                      ,
                   :pHis->iIndLibroIva                                    ,
                   :pHis->iIndPasoCobro                                   ,
                   :pHis->iIndSuperTel                                    ,
                   :pHis->iIndAnulada                                     ,
                   :pHis->lNumProceso                                     ,
                   :pHis->lNumFolio                                       ,
                   :pHis->szNumCTC                                        ,
                   :pHis->lCodPlanCom                                     ,
                   :pHis->iCodCatImpos                                    ,
                   :pHis->szFecVencimie        :i_shFecVencimie           ,
                   :pHis->szFecCaducida        :i_shFecCaducida           ,
                   :pHis->szFecProxVenc        :i_shFecProxVenc           ,
                   :pHis->lCodCiclFact         :i_shCodCiclFact           ,
                   :pHis->lNumSecuRel          :i_shNumSecuRel            ,
                   :pHis->szLetraRel           :i_shLetraRel              ,
                   :pHis->iCodTipDocumRel      :i_shCodTipDocumRel        ,
                   :pHis->lCodVendedorAgenteRel:i_shCodVendedorAgenteRel  ,
                   :pHis->iCodCentrRel         :i_shCodCentrRel           ,
                   :pHis->lNumVenta            :i_shNumVenta              ,
                   :pHis->lNumTransaccion      :i_shNumTransaccion        ,
                   :pHis->iCodModVenta         :i_shCodModVenta           ,
                   :pHis->iNumCuotas                                      ,
                   :pHis->dImpSaldoAnt                                    ,
                   :pHis->iCodOpRedFija        :i_shCodOpRedFija          ,
                   :pHis->szCodOficina         :i_shCodOficina            ,
                   :pHis->iCodZonaImpo                                    ,
                   :pHis->szPrefPlaza                                     ,
                   :pHis->szCodOperadora,
                   :pHis->szCodPlaza; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 50;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )185;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&(pHis->lNumSecuenci);
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&(pHis->iCodTipDocum);
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&(pHis->lCodVendedorAgente);
  sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)(pHis->szLetra);
  sqlstm.sqhstl[3] = (unsigned long )2;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&(pHis->iCodCentrEmi);
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&(pHis->dTotPagar);
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&(pHis->dTotCargosMe);
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&(pHis->dTotFactura);
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&(pHis->dTotCuotas);
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&(pHis->dTotDescuento);
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&(pHis->lCodVendedor);
  sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&(pHis->lCodCliente);
  sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)(pHis->szFecEmision);
  sqlstm.sqhstl[12] = (unsigned long )15;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)(pHis->szFecCambioMo);
  sqlstm.sqhstl[13] = (unsigned long )15;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)(pHis->szNomUsuarOra);
  sqlstm.sqhstl[14] = (unsigned long )31;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&(pHis->dAcumNetoGrav);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&(pHis->dAcumNetoNoGrav);
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&(pHis->dAcumIva);
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)(pHis->szIndOrdenTotal);
  sqlstm.sqhstl[18] = (unsigned long )13;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&(pHis->iIndFactur);
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&(pHis->iIndVisada);
  sqlstm.sqhstl[20] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&(pHis->iIndLibroIva);
  sqlstm.sqhstl[21] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&(pHis->iIndPasoCobro);
  sqlstm.sqhstl[22] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&(pHis->iIndSuperTel);
  sqlstm.sqhstl[23] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&(pHis->iIndAnulada);
  sqlstm.sqhstl[24] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&(pHis->lNumProceso);
  sqlstm.sqhstl[25] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&(pHis->lNumFolio);
  sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)(pHis->szNumCTC);
  sqlstm.sqhstl[27] = (unsigned long )13;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&(pHis->lCodPlanCom);
  sqlstm.sqhstl[28] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&(pHis->iCodCatImpos);
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)(pHis->szFecVencimie);
  sqlstm.sqhstl[30] = (unsigned long )15;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&i_shFecVencimie;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)(pHis->szFecCaducida);
  sqlstm.sqhstl[31] = (unsigned long )15;
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&i_shFecCaducida;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)(pHis->szFecProxVenc);
  sqlstm.sqhstl[32] = (unsigned long )15;
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&i_shFecProxVenc;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&(pHis->lCodCiclFact);
  sqlstm.sqhstl[33] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&i_shCodCiclFact;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&(pHis->lNumSecuRel);
  sqlstm.sqhstl[34] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)&i_shNumSecuRel;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)(pHis->szLetraRel);
  sqlstm.sqhstl[35] = (unsigned long )2;
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)&i_shLetraRel;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)&(pHis->iCodTipDocumRel);
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)&i_shCodTipDocumRel;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)&(pHis->lCodVendedorAgenteRel);
  sqlstm.sqhstl[37] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)&i_shCodVendedorAgenteRel;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)&(pHis->iCodCentrRel);
  sqlstm.sqhstl[38] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[38] = (         int  )0;
  sqlstm.sqindv[38] = (         short *)&i_shCodCentrRel;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)&(pHis->lNumVenta);
  sqlstm.sqhstl[39] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[39] = (         int  )0;
  sqlstm.sqindv[39] = (         short *)&i_shNumVenta;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)&(pHis->lNumTransaccion);
  sqlstm.sqhstl[40] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[40] = (         int  )0;
  sqlstm.sqindv[40] = (         short *)&i_shNumTransaccion;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)&(pHis->iCodModVenta);
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )0;
  sqlstm.sqindv[41] = (         short *)&i_shCodModVenta;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)&(pHis->iNumCuotas);
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )0;
  sqlstm.sqindv[42] = (         short *)0;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)&(pHis->dImpSaldoAnt);
  sqlstm.sqhstl[43] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[43] = (         int  )0;
  sqlstm.sqindv[43] = (         short *)0;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
  sqlstm.sqhstv[44] = (unsigned char  *)&(pHis->iCodOpRedFija);
  sqlstm.sqhstl[44] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[44] = (         int  )0;
  sqlstm.sqindv[44] = (         short *)&i_shCodOpRedFija;
  sqlstm.sqinds[44] = (         int  )0;
  sqlstm.sqharm[44] = (unsigned long )0;
  sqlstm.sqadto[44] = (unsigned short )0;
  sqlstm.sqtdso[44] = (unsigned short )0;
  sqlstm.sqhstv[45] = (unsigned char  *)(pHis->szCodOficina);
  sqlstm.sqhstl[45] = (unsigned long )3;
  sqlstm.sqhsts[45] = (         int  )0;
  sqlstm.sqindv[45] = (         short *)&i_shCodOficina;
  sqlstm.sqinds[45] = (         int  )0;
  sqlstm.sqharm[45] = (unsigned long )0;
  sqlstm.sqadto[45] = (unsigned short )0;
  sqlstm.sqtdso[45] = (unsigned short )0;
  sqlstm.sqhstv[46] = (unsigned char  *)&(pHis->iCodZonaImpo);
  sqlstm.sqhstl[46] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[46] = (         int  )0;
  sqlstm.sqindv[46] = (         short *)0;
  sqlstm.sqinds[46] = (         int  )0;
  sqlstm.sqharm[46] = (unsigned long )0;
  sqlstm.sqadto[46] = (unsigned short )0;
  sqlstm.sqtdso[46] = (unsigned short )0;
  sqlstm.sqhstv[47] = (unsigned char  *)(pHis->szPrefPlaza);
  sqlstm.sqhstl[47] = (unsigned long )11;
  sqlstm.sqhsts[47] = (         int  )0;
  sqlstm.sqindv[47] = (         short *)0;
  sqlstm.sqinds[47] = (         int  )0;
  sqlstm.sqharm[47] = (unsigned long )0;
  sqlstm.sqadto[47] = (unsigned short )0;
  sqlstm.sqtdso[47] = (unsigned short )0;
  sqlstm.sqhstv[48] = (unsigned char  *)(pHis->szCodOperadora);
  sqlstm.sqhstl[48] = (unsigned long )6;
  sqlstm.sqhsts[48] = (         int  )0;
  sqlstm.sqindv[48] = (         short *)0;
  sqlstm.sqinds[48] = (         int  )0;
  sqlstm.sqharm[48] = (unsigned long )0;
  sqlstm.sqadto[48] = (unsigned short )0;
  sqlstm.sqtdso[48] = (unsigned short )0;
  sqlstm.sqhstv[49] = (unsigned char  *)(pHis->szCodPlaza);
  sqlstm.sqhstl[49] = (unsigned long )6;
  sqlstm.sqhsts[49] = (         int  )0;
  sqlstm.sqindv[49] = (         short *)0;
  sqlstm.sqinds[49] = (         int  )0;
  sqlstm.sqharm[49] = (unsigned long )0;
  sqlstm.sqadto[49] = (unsigned short )0;
  sqlstm.sqtdso[49] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



  if (SQLCODE)
  {
      strcpy (szFuncion,"Insert=>");
      strcat (szFuncion,szNomTable);
      iDError(szExeName,ERR000,vInsertarIncidencia,szFuncion,
              szfnORAerror())      ;
      return  FALSE                ;
  }
  return TRUE;

}/**************************** Final bfnInsertHistDocu ***********************/

/*****************************************************************************/
/*                            funcion : vfnPrintHistDocu                     */
/*****************************************************************************/
static void vfnPrintHistDocu (HISTDOCU *pHis,char *szTable)
{
   char szNomTabla [21] = "";

   strcpy (szNomTabla,szTable);

   vDTrazasLog ("","\n\t\t=> Insertando en %.*s\n"
                          "\t\t Num.Secuenci   [%ld]\n"
                          "\t\t Cod.TipDocum   [%d] \n"
                          "\t\t Cod.VendedorAg.[%ld]\n"
                          "\t\t Letra          [%s] \n"
                          "\t\t Cod.CentrEmi   [%d] \n"
                          "\t\t Tot.Pagar      [%f] \n"
                          "\t\t Tot.Cargos Mes [%f] \n"
                          "\t\t Tot.Factura    [%f] \n"
                          "\t\t Tot.Cuotas     [%f] \n"
                          "\t\t Cod.Vendedor   [%ld]\n"
                          "\t\t Cod.Cliente    [%ld]\n"
                          "\t\t Fec.Emision    [%s] \n"
                          "\t\t Nom.UsuarOra   [%s] \n"
                          "\t\t Acum.NetoGrav  [%f] \n"
                          "\t\t Acum.NetoNoGrav[%f] \n"
                          "\t\t Acum.Iva       [%f] \n"
                          "\t\t Ind.OrdenTotal [%s] \n"
                          "\t\t Ind.Factur     [%d] \n"
                          "\t\t Ind.SuperTel   [%d] \n"
                          "\t\t Num.Proceso    [%ld]\n"
                          "\t\t Num.CTC        [%s] \n"
                          "\t\t Fec.Vencimie   [%s] \n"
                          "\t\t Fec.ProxVenc   [%s] \n"
                          "\t\t Cod.CiclFact   [%ld]\n"
                          "\t\t Num.SecuRel    [%ld]\n"
                          "\t\t LetraRel       [%s] \n"
                          "\t\t Cod.TipoDocumRe[%d] \n"
                          "\t\t Cod.Vend.AgenRe[%ld]\n"
                          "\t\t Cod.CentrRel   [%d] \n"
                          "\t\t Num.Venta      [%ld]\n"
                          "\t\t Num.Transacc.  [%ld]\n"
                          "\t\t Imp.SaldoAnt   [%f] \n"
                          "\t\t Zona Impositiva[%d] \n"
                          "\t\t Prefijo Plaza  [%s] \n"
                          "\t\t COD_OPERADORA  [%s] \n"
                          "\t\t COD_PLAZA      [%s] \n",
                          LOG05,strlen(szNomTabla),szNomTabla,
                          pHis->lNumSecuenci         ,
                          pHis->iCodTipDocum         ,
                          pHis->lCodVendedorAgente   ,
                          pHis->szLetra              ,
                          pHis->iCodCentrEmi         ,
                          pHis->dTotPagar            ,
                          pHis->dTotCargosMe         ,
                          pHis->dTotFactura          ,
                          pHis->dTotCuotas           ,
                          pHis->lCodVendedor         ,
                          pHis->lCodCliente          ,
                          pHis->szFecEmision         ,
                          pHis->szNomUsuarOra        ,
                          pHis->dAcumNetoGrav        ,
                          pHis->dAcumNetoNoGrav      ,
                          pHis->dAcumIva             ,
                          pHis->szIndOrdenTotal      ,
                          pHis->iIndFactur           ,
                          pHis->iIndSuperTel         ,
                          pHis->lNumProceso          ,
                          pHis->szNumCTC             ,
                          pHis->szFecVencimie        ,
                          pHis->szFecProxVenc        ,
                          pHis->lCodCiclFact         ,
                          pHis->lNumSecuRel          ,
                          pHis->szLetraRel           ,
                          pHis->iCodTipDocumRel      ,
                          pHis->lCodVendedorAgenteRel,
                          pHis->iCodCentrRel         ,
                          pHis->lNumVenta            ,
                          pHis->lNumTransaccion      ,
                          pHis->dImpSaldoAnt         ,
                          pHis->iCodZonaImpo         ,
                          pHis->szPrefPlaza          ,
                          pHis->szCodOperadora       ,
                          pHis->szCodPlaza      );

}/**************************** Final vfnPrintHistDocu ************************/

/*****************************************************************************/
/*                            funcion : vfnInitCadenaInsertHistDocu          */
/*****************************************************************************/
static void vfnInitCadenaInsertHistDocu (char *szCadena,char *szTabla)
{
  int iDiasVencimiento = 0;


  if (stProceso.iCodTipDocum == stDatosGener.iCodNotaDeb)
      iDiasVencimiento = iDIAS_VENCIMIENTO;

  sprintf (szCadena,
           "INSERT INTO %.*s "
           "(NUM_SECUENCI         ,"
           "COD_TIPDOCUM          ,"
           "COD_VENDEDOR_AGENTE   ,"
           "LETRA                 ,"
           "COD_CENTREMI          ,"
           "TOT_PAGAR             ,"
           "TOT_CARGOSME          ,"
           "TOT_FACTURA           ,"
           "TOT_CUOTAS            ,"
           "TOT_DESCUENTO         ,"
           "COD_VENDEDOR          ,"
           "COD_CLIENTE           ,"
           "FEC_EMISION           ,"
           "FEC_CAMBIOMO          ,"
           "NOM_USUARORA          ,"
           "ACUM_NETOGRAV         ,"
           "ACUM_NETONOGRAV       ,"
           "ACUM_IVA              ,"
           "IND_ORDENTOTAL        ,"
           "IND_FACTUR            ,"
           "IND_VISADA            ,"
           "IND_LIBROIVA          ,"
           "IND_PASOCOBRO         ,"
           "IND_SUPERTEL          ,"
           "IND_ANULADA           ,"
           "NUM_PROCESO           ,"
           "NUM_FOLIO             ,"
           "NUM_CTC               ,"
           "COD_PLANCOM           ,"
           "COD_CATIMPOS          ,"
           "FEC_VENCIMIE          ,"
           "FEC_CADUCIDA          ,"
           "FEC_PROXVENC          ,"
           "COD_CICLFACT          ,"
           "NUM_SECUREL           ,"
           "LETRAREL              ,"
           "COD_TIPDOCUMREL       ,"
           "COD_VENDEDOR_AGENTEREL,"
           "COD_CENTRREL          ,"
           "NUM_VENTA             ,"
           "NUM_TRANSACCION       ,"
           "COD_MODVENTA          ,"
           "NUM_CUOTAS            ,"
           "IMP_SALDOANT          ,"
           "COD_OPREDFIJA         ,"
           "COD_OFICINA           ,"
           "COD_ZONAIMPO          ,"
           "PREF_PLAZA            ,"
           "COD_OPERADORA         ,"
           "COD_PLAZA             )"
           "VALUES(:lNumSecuenci         ,"
                  ":iCodTipDocum         ,"
                  ":lCodVendedorAgente   ,"
                  ":szLetra              ,"
                  ":iCodCentrEmi         ,"
                  ":dTotPagar            ,"
                  ":dTotCargosMe         ,"
                  ":dTotFactura          ,"
                  ":dTotCuotas           ,"
                  ":dTotDescuento        ,"
                  ":lCodVendedor         ,"
                  ":lCodCliente          ,"
                  "TO_DATE(:szFecEmision ,'YYYYMMDDHH24MISS'),"
                  "TO_DATE(:szFecCambioMo,'YYYYMMDDHH24MISS'),"
                  ":szNomUsuarOra        ,"
                  ":dAcumNetoGrav        ,"
                  ":dAcumNetoNoGrav      ,"
                  ":dAcumIva             ,"
                  "TO_NUMBER (:szIndOrdenTotal)              ,"
                  ":iIndFactur           ,"
                  ":iIndVisada           ,"
                  ":iIndLibroIva         ,"
                  ":iIndPasoCobro        ,"
                  ":iIndSuperTel         ,"
                  ":iIndAnulada          ,"
                  ":lNumProceso          ,"
                  ":lNumFolio            ,"
                  ":szNumCTC             ,"
                  ":lCodPlanCom          ,"
                  ":iCodCatImpos         ,"
                  "TO_DATE(:szFecVencimie,'YYYYMMDDHH24MISS')+%d,"
                  "TO_DATE(:szFecCaducida,'YYYYMMDDHH24MISS')   ,"
                  "TO_DATE(:szFecProxVenc,'YYYYMMDDHH24MISS')   ,"
                  ":lCodCiclFact         ,"
                  ":lNumSecuRel          ,"
                  ":szLetraRel           ,"
                  ":iCodTipDocumRel      ,"
                  ":lCodVendedorAgenteRel,"
                  ":iCodCentrRel         ,"
                  ":lNumVenta            ,"
                  ":lNumTransaccion      ,"
                  ":iCodModVenta         ,"
                  ":iNumCuotas           ,"
                  ":dImpSaldoAnt         ,"
                  ":iCodOpRedFija        ,"
                  ":szCodOficina         ,"
                  ":iCodZonaImpo          ,"
                  "NVL(:szPrefPlaza,'000'),"
                  "NVL(:szCodOperadora,'00000'),"
                  "NVL(:szCodPlaza,'00000'))",strlen (szTabla),szTabla,iDiasVencimiento);


}/************************ Final vfnInitCadenaInsertHistDocu *****************/

/*****************************************************************************/
/*                            funcion : bfnPasoHistClie                      */
/*****************************************************************************/
static BOOL bfnPasoHistClie ()
{
  COMUNAS  stComuna  ;
  CIUDADES stCiudad  ;

  memset (&stComuna  ,0,sizeof(COMUNAS) );
  memset (&stCiudad  ,0,sizeof(CIUDADES));
  memset (&stHistClie,0,sizeof(HISTCLIE));

  strcpy (stHistClie.szIndOrdenTotal, stDatosGener.szIndOrdenTotal);

  stHistClie.lCodCliente = stCliente.lCodCliente;
  stHistClie.lCodPlanCom = stCliente.lCodPlanCom;

  strcpy (stHistClie.szIndDebito    ,stCliente.szIndDebito)    ;
  strcpy (stHistClie.szNomCliente   ,stCliente.szNomCliente)   ;
  strcpy (stHistClie.szNomApeClien1 ,stCliente.szNomApeClien1) ;
  strcpy (stHistClie.szNomApeClien2 ,stCliente.szNomApeClien2) ;
  strcpy (stHistClie.szTefCliente1  ,stCliente.szTefCliente1)  ;
  strcpy (stHistClie.szTefCliente2  ,stCliente.szTefCliente2)  ;
  strcpy (stHistClie.szCodPais      ,stCliente.szCodPais)      ;
  strcpy (stHistClie.szCodBanco     ,stCliente.szCodBanco)     ;
  strcpy (stHistClie.szCodSucursal  ,stCliente.szCodSucursal)  ;
  strcpy (stHistClie.szIndTipCuenta ,stCliente.szIndTipCuenta) ;
  strcpy (stHistClie.szCodTipTarjeta,stCliente.szCodTipTarjeta);
  strcpy (stHistClie.szNumCtaCorr   ,stCliente.szNumCtaCorr)   ;
  strcpy (stHistClie.szNumTarjeta   ,stCliente.szNumTarjeta)   ;
  strcpy (stHistClie.szFecVenciTarj ,stCliente.szFecVenciTarj) ;
  strcpy (stHistClie.szCodBancoTarj ,stCliente.szCodBancoTarj) ;
  strcpy (stHistClie.szCodTipIdTrib ,stCliente.szCodTipIdTrib) ;
  strcpy (stHistClie.szNumIdentTrib ,stCliente.szNumIdentTrib) ;

  strcpy (stHistClie.szNomCalle,stCliente.szNomCalle);
  strcpy (stHistClie.szNumCalle,stCliente.szNumCalle);
  strcpy (stHistClie.szNumPiso ,stCliente.szNumPiso );

  strcpy (stComuna.szCodRegion   ,stCliente.szCodRegion)   ;
  strcpy (stComuna.szCodProvincia,stCliente.szCodProvincia);
  strcpy (stComuna.szCodComuna   ,stCliente.szCodComuna)   ;

  if (!bfnFindComuna (&stComuna,stProceso.iCodTipDocum))
       return FALSE;

  strcpy (stHistClie.szDesComuna,stComuna.szDesComuna);

  strcpy (stCiudad.szCodRegion   ,stCliente.szCodRegion)   ;
  strcpy (stCiudad.szCodProvincia,stCliente.szCodProvincia);
  strcpy (stCiudad.szCodCiudad   ,stCliente.szCodCiudad)   ;

  if (!bfnFindCiudad (&stCiudad,stProceso.iCodTipDocum))
       return FALSE;

  strcpy (stHistClie.szDesCiudad,stCiudad.szDesCiudad);
  strcpy (stHistClie.szCodPais  ,stCliente.szCodPais );
  strcpy (stHistClie.szNumFax   ,stCliente.szNumFax  );
  strcpy (stHistClie.szCodIdioma,stCliente.szCodIdioma); /* agregado por PHB */
  strcpy (stHistClie.szGlsDirecClie,stCliente.szGls_DirecClie); /* agregado por NCH */

  strcpy (stHistClie.szCodPlaza,szfnTrim(stCiudad.szCodPlaza));
  vDTrazasLog ("","bfnPasoHistClie:COD_PLAZA(%s)\n",LOG05,stHistClie.szCodPlaza);
  stHistClie.dImpStopDebit = stCliente.dImpStopDebit;

  if (stCliente.iCodActividad > 0)
  {
      if (!bfnFindActividad (stCliente.iCodActividad,stHistClie.szDesActividad,
                             stProceso.iCodTipDocum))
           return FALSE;
  }
  if (!bfnInsertHistClie ())
       return FALSE;
  return TRUE;
}/*************************** Final bfnPasoHistClie  *************************/

/*****************************************************************************/
/*                          funcion : bfnFindActividad                       */
/*****************************************************************************/
static BOOL bfnFindActividad (int iCodActividad,char *szDesActividad,
                              int iCodTipDocum)
{
   ACTIVIDADES stkey;
   ACTIVIDADES *pAct = (ACTIVIDADES *)NULL;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char *szhDesActividad;/* EXEC SQL VAR szhDesActividad IS STRING(41); */ 

   /* EXEC SQL END DECLARE SECTION; */ 


   memset (&stkey,0,sizeof(ACTIVIDADES));

   vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ge_Actividades\n"
                          "\t\t=> Cod.Actividad  [%d]\n",LOG06,iCodActividad);

    if (iCodTipDocum == stDatosGener.iCodCiclo)
    {
        stkey.iCodActividad = iCodActividad;

        if ((pAct = (ACTIVIDADES *)bsearch (&stkey,pstActividades,NUM_ACTIVIDADES,
                                           sizeof(ACTIVIDADES),iCmpActividades))
            == (ACTIVIDADES *)NULL)
        {
            iDError (szExeName,ERR021,vInsertarIncidencia,"pstActividades");
            return FALSE;
        }

        strcpy (szDesActividad,pAct->szDesActividad);
    }
    else
    {
        szhDesActividad = szDesActividad;
        /* EXEC SQL SELECT /o+ index (GE_ACTIVIDADES PK_GE_ACTIVIDADES) o/
        DES_ACTIVIDAD
        INTO   :szhDesActividad
        FROM   GE_ACTIVIDADES
        WHERE  COD_ACTIVIDAD = :iCodActividad; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 50;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select  /*+  index (GE_ACTIVIDADES PK_GE_ACTIVIDADES)\
  +*/ DES_ACTIVIDAD into :b0  from GE_ACTIVIDADES where COD_ACTIVIDAD=:b1";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )400;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhDesActividad;
        sqlstm.sqhstl[0] = (unsigned long )41;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&iCodActividad;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                    "Select->Ge_Actividades",szfnORAerror());
            return FALSE;
        }
    }

   return TRUE;
}/*************************** Final bfnFindActividad *************************/

/*****************************************************************************/
/*                            funcion : bfnInsertHistClie                    */
/*****************************************************************************/
static BOOL bfnInsertHistClie (void)
{
    char szCadena  [3000] ="";
    char szNomTabla[21]   ="";
    char szFuncion [31]   ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static short  i_shNomApeClien1    ;
    static short  i_shNomApeClien2    ;
    static short  i_shTefCliente1     ;
    static short  i_shTefCliente2     ;
    static short  i_shDesActividad    ;
    static short  i_shNomCalle        ;
    static short  i_shNumCalle        ;
    static short  i_shNumPiso         ;
    static short  i_shDesComuna       ;
    static short  i_shDesCiudad       ;
    static short  i_shCodPais         ;
    static short  i_shIndDebito       ;
    static short  i_shImpStopDebit    ;
    static short  i_shCodBanco        ;
    static short  i_shCodSucursal     ;
    static short  i_shIndTipCuenta    ;
    static short  i_shCodTipTarjeta   ;
    static short  i_shNumCtaCorr      ;
    static short  i_shNumTarjeta      ;
    static short  i_Fec               ;
    static short  i_shCodBancoTarj    ;
    static short  i_shCodTipIdTrib    ;
    static short  i_shNumIdentTrib    ;
    static short  i_shNumFax          ;
    static short  i_shCodIdioma       ;
    static short  i_shGlsDirecClie    ;
    /* EXEC SQL END DECLARE SECTION; */ 


    if (strcmp (stHistClie.szNomApeClien1,"") == 0)
        i_shNomApeClien1 = ORA_NULL;
    else
        i_shNomApeClien1 = 0       ;

    if (strcmp (stHistClie.szNomApeClien2,"") == 0)
        i_shNomApeClien2 = ORA_NULL;
    else
        i_shNomApeClien2 = 0       ;

    if (strcmp (stHistClie.szTefCliente1 ,"") == 0)
        i_shTefCliente1 = ORA_NULL ;
    else
        i_shTefCliente1 = 0        ;

    if (strcmp (stHistClie.szTefCliente2 ,"") == 0)
        i_shTefCliente2 = ORA_NULL ;
    else
        i_shTefCliente2 = 0        ;

    if (strcmp (stHistClie.szDesActividad,"") == 0)
        i_shDesActividad = ORA_NULL;
    else
        i_shDesActividad = 0       ;

    if (strcmp (stHistClie.szNomCalle,"") == 0)
        i_shNomCalle = ORA_NULL    ;
    else
        i_shNomCalle = 0           ;

    if (strcmp (stHistClie.szNumCalle,"") == 0)
        i_shNumCalle = ORA_NULL    ;
    else
        i_shNumCalle = 0           ;

    if (strcmp (stHistClie.szNumPiso,"") == 0)
        i_shNumPiso = ORA_NULL     ;
    else
        i_shNumPiso = 0            ;

    if (strcmp (stHistClie.szDesComuna,"") == 0)
        i_shDesComuna = ORA_NULL   ;
    else
        i_shDesComuna = 0          ;

    if (strcmp (stHistClie.szDesCiudad,"") == 0)
        i_shDesCiudad = ORA_NULL   ;
    else
        i_shDesCiudad = 0          ;
    if (strcmp (stHistClie.szCodPais,"") == 0)
        i_shCodPais = ORA_NULL   ;
    else
        i_shCodPais = 0          ;

    if (strcmp (stHistClie.szIndDebito,"") == 0)
        i_shIndDebito = ORA_NULL   ;
    else
        i_shIndDebito = 0          ;

    if (strcmp (stHistClie.szCodBanco,"") == 0)
        i_shCodBanco = ORA_NULL    ;
    else
        i_shCodBanco = 0           ;

    if (strcmp (stHistClie.szCodSucursal,"") == 0)
        i_shCodSucursal = ORA_NULL ;
    else
        i_shCodSucursal = 0        ;

    if (strcmp (stHistClie.szIndTipCuenta,"") == 0)
        i_shIndTipCuenta = ORA_NULL;
    else
        i_shIndTipCuenta = 0       ;

    if (strcmp (stHistClie.szCodTipTarjeta,"") == 0)
        i_shCodTipTarjeta = ORA_NULL;
    else
        i_shCodTipTarjeta = 0       ;

    if (strcmp (stHistClie.szNumCtaCorr,"") == 0)
        i_shNumCtaCorr = ORA_NULL   ;
    else
        i_shNumCtaCorr = 0          ;

    if (strcmp (stHistClie.szNumTarjeta,"") == 0)
        i_shNumTarjeta = ORA_NULL   ;
    else
        i_shNumTarjeta = 0          ;
    if (strcmp (stHistClie.szFecVenciTarj,"") == 0)
        i_Fec = ORA_NULL   ;
    else
        i_Fec = 0          ;
    if (strcmp (stHistClie.szCodBancoTarj,"") == 0)
        i_shCodBancoTarj = ORA_NULL ;
    else
        i_shCodBancoTarj = 0        ;

    if (strcmp (stHistClie.szCodTipIdTrib,"") == 0)
        i_shCodTipIdTrib = ORA_NULL ;
    else
        i_shCodTipIdTrib = 0        ;

    if (strcmp (stHistClie.szNumIdentTrib,"") == 0)
        i_shNumIdentTrib = ORA_NULL ;
    else
        i_shNumIdentTrib = 0        ;

    if (strcmp (stHistClie.szNumFax,"") == 0)
        i_shNumFax = ORA_NULL;
    else
        i_shNumFax = 0       ;

    if (strcmp (stHistClie.szCodIdioma,"") == 0)
        i_shCodIdioma = ORA_NULL;
    else
        i_shCodIdioma = 0       ;

    if (strcmp (stHistClie.szGlsDirecClie,"") == 0)
        i_shGlsDirecClie = ORA_NULL;
    else
        i_shGlsDirecClie = 0       ;

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        sprintf (szNomTabla,"FA_FACTCLIE_%ld",stCiclo.lCodCiclFact);
    }
    else
    {
        strcpy  (szNomTabla,"FA_FACTCLIE_NOCICLO");
    }

    vfnInitCadenaInsertHistClie (szCadena,szNomTabla);
    vfnPrintHistClie (&stHistClie,szNomTabla)         ;

    /* EXEC SQL PREPARE sql_insert_histclie FROM :szCadena; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 50;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )423;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
    sqlstm.sqhstl[0] = (unsigned long )3000;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (SQLCODE)
    {
      strcpy (szFuncion,"PrePare=>");
      strcat (szFuncion,szNomTabla) ;

      iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,
               szfnORAerror())      ;
      return FALSE                  ;
    }

    /* EXEC SQL EXECUTE sql_insert_histclie
           USING   :stHistClie.szIndOrdenTotal                   ,
                   :stHistClie.lCodCliente                       ,
                   :stHistClie.szNomCliente                      ,
                   :stHistClie.lCodPlanCom                       ,
                   :stHistClie.szNomApeClien1:i_shNomApeClien1   ,
                   :stHistClie.szNomApeClien2:i_shNomApeClien2   ,
                   :stHistClie.szTefCliente1:i_shTefCliente1     ,
                   :stHistClie.szTefCliente2:i_shTefCliente2     ,
                   :stHistClie.szDesActividad:i_shDesActividad   ,
                   :stHistClie.szNomCalle:i_shNomCalle           ,
                   :stHistClie.szNumCalle:i_shNumCalle           ,
                   :stHistClie.szNumPiso:i_shNumPiso             ,
                   :stHistClie.szDesComuna:i_shDesComuna         ,
                   :stHistClie.szDesCiudad:i_shDesCiudad         ,
                   :stHistClie.szCodPais:i_shCodPais             ,
                   :stHistClie.szIndDebito:i_shIndDebito         ,
                   :stHistClie.dImpStopDebit:i_shImpStopDebit    ,
                   :stHistClie.szCodBanco:i_shCodBanco           ,
                   :stHistClie.szCodSucursal:i_shCodSucursal     ,
                   :stHistClie.szIndTipCuenta:i_shIndTipCuenta   ,
                   :stHistClie.szCodTipTarjeta:i_shCodTipTarjeta ,
                   :stHistClie.szNumCtaCorr:i_shNumCtaCorr       ,
                   :stHistClie.szNumTarjeta:i_shNumTarjeta       ,
                   :stHistClie.szFecVenciTarj:i_Fec              ,
                   :stHistClie.szCodBancoTarj:i_shCodBancoTarj   ,
                   :stHistClie.szCodTipIdTrib:i_shCodTipIdTrib   ,
                   :stHistClie.szNumIdentTrib:i_shNumIdentTrib   ,
                   :stHistClie.szNumFax:i_shNumFax,
                   :stHistClie.szCodIdioma:i_shCodIdioma,
                   :stHistClie.szGlsDirecClie:i_shGlsDirecClie; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 50;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )442;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)(stHistClie.szIndOrdenTotal);
    sqlstm.sqhstl[0] = (unsigned long )13;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(stHistClie.lCodCliente);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(stHistClie.szNomCliente);
    sqlstm.sqhstl[2] = (unsigned long )51;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&(stHistClie.lCodPlanCom);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(stHistClie.szNomApeClien1);
    sqlstm.sqhstl[4] = (unsigned long )21;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)&i_shNomApeClien1;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)(stHistClie.szNomApeClien2);
    sqlstm.sqhstl[5] = (unsigned long )21;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)&i_shNomApeClien2;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(stHistClie.szTefCliente1);
    sqlstm.sqhstl[6] = (unsigned long )16;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)&i_shTefCliente1;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(stHistClie.szTefCliente2);
    sqlstm.sqhstl[7] = (unsigned long )16;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)&i_shTefCliente2;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(stHistClie.szDesActividad);
    sqlstm.sqhstl[8] = (unsigned long )41;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)&i_shDesActividad;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(stHistClie.szNomCalle);
    sqlstm.sqhstl[9] = (unsigned long )51;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)&i_shNomCalle;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(stHistClie.szNumCalle);
    sqlstm.sqhstl[10] = (unsigned long )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)&i_shNumCalle;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)(stHistClie.szNumPiso);
    sqlstm.sqhstl[11] = (unsigned long )11;
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)&i_shNumPiso;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)(stHistClie.szDesComuna);
    sqlstm.sqhstl[12] = (unsigned long )31;
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)&i_shDesComuna;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)(stHistClie.szDesCiudad);
    sqlstm.sqhstl[13] = (unsigned long )31;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)&i_shDesCiudad;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)(stHistClie.szCodPais);
    sqlstm.sqhstl[14] = (unsigned long )4;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)&i_shCodPais;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)(stHistClie.szIndDebito);
    sqlstm.sqhstl[15] = (unsigned long )2;
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)&i_shIndDebito;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)&(stHistClie.dImpStopDebit);
    sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)&i_shImpStopDebit;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)(stHistClie.szCodBanco);
    sqlstm.sqhstl[17] = (unsigned long )16;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         short *)&i_shCodBanco;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)(stHistClie.szCodSucursal);
    sqlstm.sqhstl[18] = (unsigned long )5;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         short *)&i_shCodSucursal;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)(stHistClie.szIndTipCuenta);
    sqlstm.sqhstl[19] = (unsigned long )2;
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         short *)&i_shIndTipCuenta;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)(stHistClie.szCodTipTarjeta);
    sqlstm.sqhstl[20] = (unsigned long )4;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         short *)&i_shCodTipTarjeta;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)(stHistClie.szNumCtaCorr);
    sqlstm.sqhstl[21] = (unsigned long )19;
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         short *)&i_shNumCtaCorr;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)(stHistClie.szNumTarjeta);
    sqlstm.sqhstl[22] = (unsigned long )19;
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         short *)&i_shNumTarjeta;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)(stHistClie.szFecVenciTarj);
    sqlstm.sqhstl[23] = (unsigned long )15;
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         short *)&i_Fec;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)(stHistClie.szCodBancoTarj);
    sqlstm.sqhstl[24] = (unsigned long )16;
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         short *)&i_shCodBancoTarj;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)(stHistClie.szCodTipIdTrib);
    sqlstm.sqhstl[25] = (unsigned long )3;
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         short *)&i_shCodTipIdTrib;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)(stHistClie.szNumIdentTrib);
    sqlstm.sqhstl[26] = (unsigned long )21;
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         short *)&i_shNumIdentTrib;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)(stHistClie.szNumFax);
    sqlstm.sqhstl[27] = (unsigned long )16;
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         short *)&i_shNumFax;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)(stHistClie.szCodIdioma);
    sqlstm.sqhstl[28] = (unsigned long )6;
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         short *)&i_shCodIdioma;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
    sqlstm.sqhstv[29] = (unsigned char  *)(stHistClie.szGlsDirecClie);
    sqlstm.sqhstl[29] = (unsigned long )251;
    sqlstm.sqhsts[29] = (         int  )0;
    sqlstm.sqindv[29] = (         short *)&i_shGlsDirecClie;
    sqlstm.sqinds[29] = (         int  )0;
    sqlstm.sqharm[29] = (unsigned long )0;
    sqlstm.sqadto[29] = (unsigned short )0;
    sqlstm.sqtdso[29] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (SQLCODE)
    {
        strcpy (szFuncion,"Insert=>");
        strcat (szFuncion,szNomTabla);
        iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror());
        return FALSE;
    }
    return TRUE;
}/**************************** Final bfnInsertHistClie ***********************/


/*****************************************************************************/
/*                          funcion : vfnPrintHistClie                       */
/*****************************************************************************/
static void vfnPrintHistClie (HISTCLIE *stHis,char *szTable)
{
  char szNomTabla [21]="";

  strcpy (szNomTabla,szTable);

  vDTrazasLog (szExeName,"\n\t\t=> Insertarndo en  %.*s\n"
                         "\t\t Ind.OrdenTotal [%s] \n"
                         "\t\t Cod.Cliente    [%ld]\n"
                         "\t\t Nom.Cliente    [%s] \n"
                         "\t\t Cod.PlanCom    [%ld]\n"
                         "\t\t Nom.ApeClien1  [%s] \n"
                         "\t\t Nom.ApeClien2  [%s] \n"
                         "\t\t Tef.Cliente1   [%s] \n"
                         "\t\t Tef.Cliente2   [%s] \n"
                         "\t\t Des.Actividad  [%s] \n"
                         "\t\t Nom.Calle      [%s] \n"
                         "\t\t Num.Calle      [%s] \n"
                         "\t\t Num.Piso       [%s] \n"
                         "\t\t Des.Comuna     [%s] \n"
                         "\t\t Des.Ciudad     [%s] \n"
                         "\t\t Cod.Pais       [%s] \n"
                         "\t\t Ind.Debito     [%s] \n"
                         "\t\t Imp.StopDebit  [%f] \n"
                         "\t\t Cod.Banco      [%s] \n"
                         "\t\t Cod.Sucursal   [%s] \n"
                         "\t\t Ind.TipCuenta  [%s] \n"
                         "\t\t Cod.TipTarjeta [%s] \n"
                         "\t\t Num.CtaCorr    [%s] \n"
                         "\t\t Num.NumTarjeta [%s] \n"
                         "\t\t Fec.VenciTarj  [%s] \n"
                         "\t\t Cod.BancoTarj  [%s] \n"
                         "\t\t Cod.TipIdTrib  [%s] \n"
                         "\t\t Num.IdentTrib  [%s] \n"
                         "\t\t Num.Fax        [%s] \n"
                         "\t\t Cod.Idioma     [%s] \n"  /*CH-200606283727 CJG*/
                         "\t\t Gls.DirecClie  [%s] \n", /*CH-200606283727 CJG*/
                         LOG05,strlen (szNomTabla),szNomTabla,
                         stHis->szIndOrdenTotal,
                         stHis->lCodCliente    ,
                         stHis->szNomCliente   ,
                         stHis->lCodPlanCom    ,
                         stHis->szNomApeClien1 ,
                         stHis->szNomApeClien2 ,
                         stHis->szTefCliente1  ,
                         stHis->szTefCliente2  ,
                         stHis->szDesActividad ,
                         stHis->szNomCalle     ,
                         stHis->szNumCalle     ,
                         stHis->szNumPiso      ,
                         stHis->szDesComuna    ,
                         stHis->szDesCiudad    ,
                         stHis->szCodPais      ,
                         stHis->szIndDebito    ,
                         stHis->dImpStopDebit  ,
                         stHis->szCodBanco     ,
                         stHis->szCodSucursal  ,
                         stHis->szIndTipCuenta ,
                         stHis->szCodTipTarjeta,
                         stHis->szNumCtaCorr   ,
                         stHis->szNumTarjeta   ,
                         stHis->szFecVenciTarj ,
                         stHis->szCodBancoTarj ,
                         stHis->szCodTipIdTrib ,
                         stHis->szNumIdentTrib ,
                         stHis->szNumFax       ,
                         stHis->szCodIdioma    ,
                         stHis->szGlsDirecClie );

}/*************************** Final vfnPrintHistClie *************************/

/*****************************************************************************/
/*                          funcion : vfnInitCadenaInsertHistClie            */
/*****************************************************************************/
static void vfnInitCadenaInsertHistClie (char *szCadena,char *szNomTabla)
{
  sprintf (szCadena,
          "INSERT INTO %.*s "
                  "(IND_ORDENTOTAL,"
                  "COD_CLIENTE    ,"
                  "NOM_CLIENTE    ,"
                  "COD_PLANCOM    ,"
                  "NOM_APECLIEN1  ,"
                  "NOM_APECLIEN2  ,"
                  "TEF_CLIENTE1   ,"
                  "TEF_CLIENTE2   ,"
                  "DES_ACTIVIDAD  ,"
                  "NOM_CALLE      ,"
                  "NUM_CALLE      ,"
                  "NUM_PISO       ,"
                  "DES_COMUNA     ,"
                  "DES_CIUDAD     ,"
                  "COD_PAIS       ,"
                  "IND_DEBITO     ,"
                  "IMP_STOPDEBIT  ,"
                  "COD_BANCO      ,"
                  "COD_SUCURSAL   ,"
                  "IND_TIPCUENTA  ,"
                  "COD_TIPTARJETA ,"
                  "NUM_CTACORR    ,"
                  "NUM_TARJETA    ,"
                  "FEC_VENCITARJ  ,"
                  "COD_BANCOTARJ  ,"
                  "COD_TIPIDTRIB  ,"
                  "NUM_IDENTTRIB  ,"
                  "NUM_FAX        ,"
                  "COD_IDIOMA     ,"
                  "GLS_DIRECCLIE )"
          "VALUES (TO_NUMBER (:szIndOrdenTotal),"
                  ":lCodCliente            ,"
                  ":szNomCliente           ,"
                  ":lCodPlanCom            ,"
                  ":szNomApeClien1         ,"
                  ":szNomApeClien2         ,"
                  ":szTefCliente1          ,"
                  ":szTefCliente2          ,"
                  ":szDesActividad         ,"
                  ":szNomCalle             ,"
                  ":szNumCalle             ,"
                  ":szNumPiso              ,"
                  ":szDesComuna            ,"
                  ":szDesCiudad            ,"
                  ":szCodPais              ,"
                  ":szIndDebito            ,"
                  ":dImpStopDebit          ,"
                  ":szCodBanco             ,"
                  ":szCodSucursal          ,"
                  ":szIndTipCuenta         ,"
                  ":szCodTipTarjeta        ,"
                  ":szNumCtaCorr           ,"
                  ":szNumTarjeta           ,"
                  "TO_DATE(:szFecVenciTarj,'YYYYMMDDHH24MISS'),"
                  ":szCodBancoTarj         ,"
                  ":szCodTipIdTrib         ,"
                  ":szNumIdentTrib         ,"
                  ":szNumFax               ,"
                  ":szCodIdioma            ,"
                  ":szGlsDirecClie)",strlen(szNomTabla),szNomTabla);

}/*************************** Final vfnInitCadenaInsertHistClie **************/

/*****************************************************************************/
/*                            funcion : bfnPasoHistAbo                       */
/*****************************************************************************/
static BOOL bfnPasoHistAbo ()
{
  int  i = 0;
  long j = 0;

  /**************************************************************/
  /* Estructuras Globales para que sean vistas por la impresion */
  /**************************************************************/
  memset (&stHistAboCel  ,0,sizeof(HISTABOP));

  for(j=0;j<stAbonoCli.lNumAbonados;j++)
  {
      i = 0;
      if (stAbonoCli.pCicloCli [j].iCodProducto == stDatosGener.iProdCelular)
      {
          if ((stHistAboCel.pAbo =
              (HISTABO *)realloc ( (HISTABO *)stHistAboCel.pAbo,
              (stHistAboCel.iNumReg+1)*sizeof(HISTABO) ))==(HISTABO *)NULL)
          {
               iDError (szExeName,ERR005,vInsertarIncidencia,
                        "stHistAboCel.pAbo");
               return  FALSE                ;
          }
          i = stHistAboCel.iNumReg                         ;
          memset (&stHistAboCel.pAbo[i],0,sizeof (HISTABO));
          strcpy (stHistAboCel.pAbo[i].szIndOrdenTotal,
                  stDatosGener.szIndOrdenTotal)            ;

          strcpy (stHistAboCel.pAbo[i].szCodPlanTarif,
                  stAbonoCli.pCicloCli [j].szCodPlanTarif);

          stHistAboCel.pAbo[i].lCodCliente   =
                                           stAbonoCli.pCicloCli[j].lCodCliente;
          stHistAboCel.pAbo[i].lNumAbonado   =
                                           stAbonoCli.pCicloCli[j].lNumAbonado;
          stHistAboCel.pAbo[i].iCodDetFact   =
                                           stAbonoCli.pCicloCli[j].iIndDetalle;
          strcpy (stHistAboCel.pAbo[i].szNomUsuario  ,
                  stAbonoCli.pCicloCli [j].szNomUsuario)  ;
          strcpy (stHistAboCel.pAbo[i].szNomApellido1,
                  stAbonoCli.pCicloCli [j].szNomApellido1);
          strcpy (stHistAboCel.pAbo[i].szNomApellido2,
                  stAbonoCli.pCicloCli [j].szNomApellido2);
          stHistAboCel.pAbo[i].iCodCredMor   =
                                           stAbonoCli.pCicloCli[j].iCodCredMor;

          strcpy (stHistAboCel.pAbo[i].szNumTerminal,
                  stAbonoCli.pCicloCli[j].szNumTerminal);

          stHistAboCel.pAbo[i].iIndFactur   =
                                          stAbonoCli.pCicloCli[j].iIndFactur  ;
          stHistAboCel.pAbo[i].iIndSuperTel =
                                          stAbonoCli.pCicloCli[j].iIndSuperTel;
          stHistAboCel.pAbo[i].lCodGrupo    =
                                          stAbonoCli.pCicloCli[j].lCodGrupo   ;

          strcpy (stHistAboCel.pAbo[i].szNumTeleFija ,
                  stAbonoCli.pCicloCli[j].szNumTeleFija) ;
          strcpy (stHistAboCel.pAbo[i].szFecFinContra,
                  stAbonoCli.pCicloCli[j].szFecFinContra);

          if (!bfnGetTotCargosMeAbo (&stHistAboCel.pAbo[i]))
               return FALSE;

          if (stHistAboCel.pAbo[i].iCodCredMor > 0)
          {
              if (!bfnGetLimCredito (stHistAboCel.pAbo[i].iCodCredMor    ,
                                     stAbonoCli.pCicloCli[j].iCodProducto,
                                     &stHistAboCel.pAbo[i].dLimCredito   ,
                                     stProceso.iCodTipDocum))
                   return FALSE;
          }

          /* P-TMC-04049: se traspasan fechas periodo */
          strcpy (stHistAboCel.pAbo[i].szFecPeriDesde ,
                  stAbonoCli.pCicloCli[j].szFecPeriDesde) ;
          strcpy (stHistAboCel.pAbo[i].szFecPeriHasta,
                  stAbonoCli.pCicloCli[j].szFecPeriHasta);

          stHistAboCel.iNumReg++;
      }
  }/* fin for */
  if (stHistAboCel.iNumReg > 0)
  {
      if (!bfnInsertHistAbo (&stHistAboCel  ,stDatosGener.iProdCelular))
           return (FALSE);
  }

  return TRUE;
}/************************** Final bfnPasoHistAbo ****************************/


static BOOL fnbChequeaAcumulados()
{
    stAcumulador     * pAcumulador=NULL;

    for (pAcumulador = lstAcumulador; pAcumulador != NULL; pAcumulador = pAcumulador->sgte)
    {
       /* if (pAcumulador->dMonto < 0.000001 && pAcumulador->dMonto > -0.000001) */     /* PGG SOPORTE - 71849 - 16-10-2008 */
       if (pAcumulador->dMonto <= 0.0001 && pAcumulador->dMonto >= -0.0001)                     /* PGG SOPORTE - 71849 - 16-10-2008 */
           pAcumulador->dMonto = (double)0.0;

        if (pAcumulador->dMonto < 0)
        {
            vDTrazasLog(szExeName,"\n\t---FUNCION - fnbChequeaAcumulados ERROR"
                                  "\n\t\tpAcumulador->lAbonado    [%ld]"
                                  "\n\t\tpAcumulador->lCod_ConCobr[%ld]"
                                  "\n\t\tpAcumulador->dMonto      [%.15f]"
                                  ,LOG01, pAcumulador->lAbonado, pAcumulador->lCod_ConCobr,pAcumulador->dMonto);
            pAcumulador->dMonto = 0;
            return (FALSE);
        }
        else
            vDTrazasLog(szExeName,"\n\t---FUNCION - fnbChequeaAcumulados"
                                  "\n\t\tpAcumulador->lAbonado    [%ld]"
                                  "\n\t\tpAcumulador->lCod_ConCobr[%ld]"
                                  "\n\t\tpAcumulador->dMonto      [%.15f]"
                                  ,LOG05, pAcumulador->lAbonado, pAcumulador->lCod_ConCobr,pAcumulador->dMonto);
    }
    return (TRUE);
}

static BOOL bfnLlenaAcumulados(int iCodConCobr, long lNum_Abonado, double dMontoImporte)
{
    stAcumulador     * pAcumulador=NULL;
    int isw = 0;

    vDTrazasLog(szExeName,"\n\t---FUNCION - bfnLlenaAcumulados antes "
                          "\n\t\t lAbonado      [%ld]"
                          "\n\t\t iCod_ConCobr  [%d]"
                          "\n\t\t dMontoImporte [%f]"
                          ,LOG05, lNum_Abonado, iCodConCobr, dMontoImporte);

    if (dMontoImporte > 0.00 || dMontoImporte < 0.00)
    {
        for (pAcumulador = lstAcumulador; pAcumulador != NULL; pAcumulador = pAcumulador->sgte)
        {
            if (pAcumulador->lCod_ConCobr == iCodConCobr &&
                pAcumulador->lAbonado == lNum_Abonado)
            {
                isw = 1;
                pAcumulador->dMonto = pAcumulador->dMonto + fnCnvDouble(dMontoImporte,USOFACT);
                pAcumulador->dMonto = fnCnvDouble(pAcumulador->dMonto,USOFACT);    /* PGG SOPORTE - 71849 - 16-10-2008 */
                break;
            }
        }

        if (isw == 0)
        {
            pAcumulador = (stAcumulador *) malloc(sizeof(stAcumulador));
            pAcumulador->lAbonado       = lNum_Abonado;
            pAcumulador->lCod_ConCobr   = (long)iCodConCobr;
            pAcumulador->dMonto     = fnCnvDouble(dMontoImporte,USOFACT);
            pAcumulador->sgte           = lstAcumulador;
            lstAcumulador               = pAcumulador;
        }

        vDTrazasLog(szExeName,"\t--- Despues ---"
                              "\n\t\t lAbonado         [%ld]"
                              "\n\t\t lCod_ConCobr     [%ld]"
                              "\n\t\t dMonto Acumulado [%f] "
                              ,LOG05, pAcumulador->lAbonado, pAcumulador->lCod_ConCobr,pAcumulador->dMonto);
    }
    return (TRUE);
}



static BOOL bfnComparaEstructuras(int iCod_Concepto, long lNumAbonado, double dImporte)
{
    static int iCodConCobr=0;

    if (!bfnFindFactCobr (iCod_Concepto, iCodConCobr ))
    {
        vDTrazasLog (szExeName, "\n\t\t Error Obtener Concepto Cobro : [%d] \n",LOG01,iCod_Concepto);
        return FALSE;
    }

    if (!bfnLlenaAcumulados(iCodConCobr, lNumAbonado, dImporte))
    {
        vDTrazasLog(szExeName,"\nError en funcion bfnLlenaAcumulados\n",LOG01);
        return (FALSE);
    }

    return (TRUE);

}

static BOOL bfnMuestraAcumulados()
{
    stAcumulador    * pAcumulador=NULL;

    for (pAcumulador = lstAcumulador; pAcumulador != NULL; pAcumulador = pAcumulador->sgte)
    {
        vDTrazasLog(szExeName,"\n\t-----bfnMuestraAcumulados --------"
                              "\n\t\tpAcumulador->lAbonado      [%ld]"
                              "\n\t\tpAcumulador->lCod_ConCobr  [%ld]"
                              "\n\t\tpAcumulador->dMonto        [%f] "
                              , LOG05, pAcumulador->lAbonado, pAcumulador->lCod_ConCobr, pAcumulador->dMonto);
    }

    return (TRUE);
}

static void vLiberaAcumulador()
{
    stAcumulador    * pCabeceraAux=NULL;

    while (lstAcumulador != NULL)
    {
        pCabeceraAux = lstAcumulador->sgte;
        free(lstAcumulador);
        lstAcumulador = pCabeceraAux;
    }

    lstAcumulador = (stAcumulador *)NULL;
}


/*****************************************************************************/
/*                          funcion : bfnGetCargosMeAbo                      */
/*****************************************************************************/
static BOOL bfnGetTotCargosMeAbo (HISTABO *pHis)
{

   int    i        = 0  ;
   double dTotalAbonado = 0.0;

   vLiberaAcumulador();
   for (i=0;i<stPreFactura.iNumRegistros;i++)
   {
        if (stPreFactura.A_PFactura.lNumAbonado [i] == pHis->lNumAbonado)
        {
            pHis->dTotCargosMe += stPreFactura.A_PFactura.dImpFacturable[i];
            if (stPreFactura.A_PFactura.iCodTipConce [i] == ARTICULO)
            {
                pHis->dAcumCargo += stPreFactura.A_PFactura.dImpFacturable[i];
            }
            else if (stPreFactura.A_PFactura.iCodTipConce [i] == IMPUESTO)
            {
                pHis->dAcumIva   += stPreFactura.A_PFactura.dImpFacturable[i];
            }
            else if (stPreFactura.A_PFactura.iCodTipConce [i] == DESCUENTO)
            {
                pHis->dAcumDto   += stPreFactura.A_PFactura.dImpFacturable[i];
            }
            if (!bfnComparaEstructuras(stPreFactura.A_PFactura.iCodConcepto[i], stPreFactura.A_PFactura.lNumAbonado[i], stPreFactura.A_PFactura.dImpFacturable[i]))
            {
                vDTrazasLog(szExeName,"\nError en funcion bfnComparaEstructuras\n",LOG01);
            }
            /*****************************************************************/
            /* En las Facturas de Contado o PVenta no tienen el interface con*/
            /* Ga_InfacCel donde se encuentra el iIndSuperTel a nivel de Abo-*/
            /* nado, por eso necesitamos este control para recuperar la infor*/
            /* macion a este nivel.                                          */
            /*****************************************************************/
            if (stPreFactura.A_PFactura.iIndSuperTel [i] == 1 &&
                pHis->iIndSuperTel                       <  1)
                pHis->iIndSuperTel = 1;

        }

	}
   pHis->dTotCargosMe = fnCnvDouble (pHis->dTotCargosMe,USOFACT);
   pHis->dAcumCargo   = fnCnvDouble (pHis->dAcumCargo  ,USOFACT);
   pHis->dAcumIva     = fnCnvDouble (pHis->dAcumIva    ,USOFACT);
   pHis->dAcumDto     = fnCnvDouble (pHis->dAcumDto    ,USOFACT);

    dTotalAbonado =    pHis->dTotCargosMe + pHis->dAcumCargo + pHis->dAcumIva + pHis->dAcumDto;

   dTotalAbonado = fnCnvDouble(dTotalAbonado,iUSO0);

   vDTrazasLog(szExeName,"\t** TotalAbonado=[%f]\n", LOG05, dTotalAbonado);

   /* 20040812 XC-200408110239 Homologado de PR-200402160376: Se controla condicion de borde por decimales */
   if (dTotalAbonado < 0.001 && dTotalAbonado > -0.001)
    dTotalAbonado = (double)0.0;

   if (dTotalAbonado < 0.0)
   {
       vLiberaAcumulador();
       stStatus.lCodCliActual=pHis->lCodCliente; /* PPV 34216 04/10/2006 : se agrega linea*/
       stAnomProceso.lNumAbonado=pHis->lNumAbonado; /* PPV 34216 04/10/2006 : se agrega linea*/
       iDError(szExeName, ERR063, vInsertarIncidencia,pHis->lCodCliente,pHis->lNumAbonado, dTotalAbonado);  /* PGG SOPORTE - 70685 - 23-09-2008 */
       return FALSE; /* PPV 34216 04/10/2006 : se agrega linea*/
   }

   if (!bfnMuestraAcumulados())
      vDTrazasLog(szExeName,"Error mostrando LISTA ENLAZADA acumulados\n", LOG01);

   if (!fnbChequeaAcumulados())
   {
        stStatus.lCodCliActual=pHis->lCodCliente; /* PPV 34216 04/10/2006 : se agrega linea*/
        stAnomProceso.lNumAbonado=pHis->lNumAbonado; /* PPV 34216 04/10/2006 : se agrega linea*/
        iDError(szExeName, ERR62, vInsertarIncidencia,pHis->lCodCliente,pHis->lNumAbonado);
        vLiberaAcumulador();
        return FALSE; /* PPV 34216 04/10/2006 : se agrega linea*/
   }
   return TRUE;
}/************************** Final bfnGetTotCargosMeAbo **********************/

/*****************************************************************************/
/*                         funcion : bfnGetLimCredito                        */
/*****************************************************************************/
static BOOL bfnGetLimCredito (int     iCodCredito, int iCodProducto,
                              double *dLimCredito, int iTipoFact)
{
  double dImpMorosidad = 0.0;

  LIMCREDITOS stkey                    ;
  LIMCREDITOS *pL = (LIMCREDITOS *)NULL;

  memset (&stkey,0,sizeof(LIMCREDITOS));

  vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Co_LimCreditos\n"
             "\t\t=> Cod.Credito   [%d]\n"
                     "\t\t=> Cod.Producto  [%d]\n",LOG06,
                     iCodCredito,iCodProducto);

    if (iTipoFact == stDatosGener.iCodCiclo)
    {
        stkey.iCodCredMor = iCodCredito ;
        stkey.iCodProducto= iCodProducto;

        if ((pL = (LIMCREDITOS *)bsearch (&stkey,pstLimCreditos,NUM_LIMCREDITOS,
                                             sizeof(LIMCREDITOS),iCmpLimCreditos))
                  ==(LIMCREDITOS *)NULL)
        {
            iDError (szExeName,ERR021,vInsertarIncidencia,"pstLimCreditos");
            return FALSE;

        }
        *dLimCredito = pL->dImpMorosidad;
    }
    else
    {
        /* EXEC SQL SELECT /o+ index (CO_LIMCREDITOS PK_CO_LIMCREDITOS) o/
                      IMP_MOROSIDAD
               INTO   :dImpMorosidad
               FROM   CO_LIMCREDITOS
               WHERE  COD_CREDMOR = :iCodCredito
                 AND  COD_PRODUCTO= :iCodProducto; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 50;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select  /*+  index (CO_LIMCREDITOS PK_CO_LIMCREDITOS)\
  +*/ IMP_MOROSIDAD into :b0  from CO_LIMCREDITOS where (COD_CREDMOR=:b1 and C\
OD_PRODUCTO=:b2)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )577;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&dImpMorosidad;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&iCodCredito;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&iCodProducto;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                   "Select->Co_LimCreditos",szfnORAerror());
            return FALSE;
        }
        *dLimCredito = dImpMorosidad;
    }
    return TRUE;
}/************************* Final bfnGetLimCredito ***************************/

/*****************************************************************************/
/*                          funcion : bInsertHistAbo                         */
/*****************************************************************************/
static BOOL bfnInsertHistAbo (HISTABOP *stHis,int iCodProducto)
{
  char szFuncion [25]  ="\0"    ;
  char szCadena  [1500]="\0"    ;
  char szNomTable[25]  ="\0"    ;

  int  i               = 0    ;
  int  j               = 0    ;
  BOOL bError          = FALSE;
  int  iInd            = 0    ;/* Indice del Reg. donde se Produce Error */

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static long   lhIndOrdenTotal [NREG]    ;  /*  EXEC SQL VAR szhIndOrdenTotal  IS STRING(13); */
  static long   lhNumAbonado    [NREG]    ;
  static long   lhCodCliente    [NREG]    ;
  static double dhTotCargosMe   [NREG]    ;
  static double dhAcumCargo     [NREG]    ;
  static double dhAcumIva       [NREG]    ;
  static double dhAcumDto       [NREG]    ;
  static int    ihCodProducto   [NREG]    ;
  static char   szhCodSituacion [NREG] [4];
                                /* EXEC SQL VAR szhCodSituacion   IS STRING(4) ; */ 

  static char   szhNumTerminal  [NREG] [16];
                                /* EXEC SQL VAR szhNumTerminal    IS STRING(16); */ 

  static char   szhNumBeeper    [NREG] [16];
                                /* EXEC SQL VAR szhNumBeeper      IS STRING(16); */ 

  static int    ihCodDetFact    [NREG]    ;
  static char   szhFecFinContra [NREG][15];
                                /* EXEC SQL VAR szhFecFinContra   IS STRING(15); */ 

  static int    ihIndFactur     [NREG]    ;
  static int    ihCodCredMor    [NREG]    ;
  static char   szhNomApellido1 [NREG][21];
                                /* EXEC SQL VAR szhNomApellido1   IS STRING(21); */ 

  static char   szhNomApellido2 [NREG][21];
                                /* EXEC SQL VAR szhNomApellido2   IS STRING(21); */ 

  static char   szhNomUsuario   [NREG][21];
                                /* EXEC SQL VAR szhNomUsuario     IS STRING(21); */ 

  static double dhLimCredito    [NREG]    ;
  static long   lhCapCode       [NREG]    ;
  static int    ihIndSuperTel   [NREG]    ;
  static int    ihIndPrePago    [NREG]    ;
  static char   szhNumTeleFija  [NREG][16];
                                /* EXEC SQL VAR szhNumTeleFija    IS STRING(16); */ 

  static char   szhFecPeriDesde [NREG][15];
                                /* EXEC SQL VAR szhFecPeriDesde    IS STRING(15); */ 

  static char   szhFecPeriHasta [NREG][15];
                                /* EXEC SQL VAR szhFecPeriHasta    IS STRING(15); */ 

  static short  i_shNumTerminal [NREG]    ;
  static short  i_shCapCode     [NREG]    ;
  static short  i_Fec           [NREG]    ;
  static short  i_shCodCredMor  [NREG]    ;
  static short  i_shNomApellido1[NREG]    ;
  static short  i_shNomApellido2[NREG]    ;
  static short  i_shNomUsuario  [NREG]    ;
  static short  i_shIndSuperTel [NREG]    ;
  static short  i_shIndPrePago  [NREG]    ;
  static short  i_shNumTeleFija [NREG]    ;
  static short  i_shLimCredito  [NREG]    ;
  static short  i_shFecPeriDesde[NREG]    ;
  static short  i_shFecPeriHasta[NREG]    ;
  /* EXEC SQL END DECLARE SECTION; */ 



    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        sprintf(szNomTable,"FA_FACTABON_%ld\0",stCiclo.lCodCiclFact);
    }
    else
    {
        strcpy (szNomTable,"FA_FACTABON_NOCICLO") ;
    }
    vfnInitCadenaInsertHistAbo (szCadena,szNomTable);

    /* EXEC SQL PREPARE sql_insert_histabon FROM :szCadena; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 50;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )604;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
    sqlstm.sqhstl[0] = (unsigned long )1500;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (SQLCODE)
    {
        sprintf (szFuncion,"PrePare=>%s",szNomTable);
        iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror ());
        return (FALSE);
    }

    /************************************************************/

    for (j=0;j<stHis->iNumReg;j++)
    {

        vfnPrintHistAbo (&stHis->pAbo[j],j,bError)     ;
        if (i == NREG)
        {
            /* EXEC SQL FOR :i
                EXECUTE sql_insert_histabon
                USING   :lhIndOrdenTotal                 ,
                        :lhNumAbonado                    ,
                        :lhCodCliente                    ,
                        :ihCodProducto                   ,
                        :szhCodSituacion                 ,
                        :dhTotCargosMe                   ,
                        :dhAcumCargo                     ,
                        :dhAcumDto                       ,
                        :dhAcumIva                       ,
                        :ihCodDetFact                    ,
                        :szhFecFinContra:i_Fec           ,
                        :ihIndFactur                     ,
                        :ihCodCredMor:i_shCodCredMor     ,
                        :szhNomUsuario:i_shNomUsuario    ,
                        :szhNomApellido1:i_shNomApellido1,
                        :szhNomApellido2:i_shNomApellido2,
                        :dhLimCredito:i_shLimCredito     ,
                        :szhNumTerminal:i_shNumTerminal  ,
                        :szhNumBeeper                    ,
                        :lhCapCode:i_shCapCode           ,
                        :ihIndSuperTel                   ,
                        :szhNumTeleFija:i_shNumTeleFija  ,
                        :szhFecPeriDesde:i_shFecPeriDesde,
                        :szhFecPeriHasta:i_shFecPeriHasta; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 50;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )i;
            sqlstm.offset = (unsigned int  )623;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)lhIndOrdenTotal;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )sizeof(long);
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqharc[0] = (unsigned long  *)0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)lhNumAbonado;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )sizeof(long);
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqharc[1] = (unsigned long  *)0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)lhCodCliente;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )sizeof(long);
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqharc[2] = (unsigned long  *)0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)ihCodProducto;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )sizeof(int);
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqharc[3] = (unsigned long  *)0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szhCodSituacion;
            sqlstm.sqhstl[4] = (unsigned long )4;
            sqlstm.sqhsts[4] = (         int  )4;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqharc[4] = (unsigned long  *)0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)dhTotCargosMe;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )sizeof(double);
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqharc[5] = (unsigned long  *)0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)dhAcumCargo;
            sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )sizeof(double);
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqharc[6] = (unsigned long  *)0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)dhAcumDto;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )sizeof(double);
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqharc[7] = (unsigned long  *)0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)dhAcumIva;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )sizeof(double);
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqharc[8] = (unsigned long  *)0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)ihCodDetFact;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )sizeof(int);
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqharc[9] = (unsigned long  *)0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)szhFecFinContra;
            sqlstm.sqhstl[10] = (unsigned long )15;
            sqlstm.sqhsts[10] = (         int  )15;
            sqlstm.sqindv[10] = (         short *)i_Fec;
            sqlstm.sqinds[10] = (         int  )sizeof(short);
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqharc[10] = (unsigned long  *)0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)ihIndFactur;
            sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )sizeof(int);
            sqlstm.sqindv[11] = (         short *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqharc[11] = (unsigned long  *)0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)ihCodCredMor;
            sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[12] = (         int  )sizeof(int);
            sqlstm.sqindv[12] = (         short *)i_shCodCredMor;
            sqlstm.sqinds[12] = (         int  )sizeof(short);
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqharc[12] = (unsigned long  *)0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)szhNomUsuario;
            sqlstm.sqhstl[13] = (unsigned long )21;
            sqlstm.sqhsts[13] = (         int  )21;
            sqlstm.sqindv[13] = (         short *)i_shNomUsuario;
            sqlstm.sqinds[13] = (         int  )sizeof(short);
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqharc[13] = (unsigned long  *)0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (unsigned char  *)szhNomApellido1;
            sqlstm.sqhstl[14] = (unsigned long )21;
            sqlstm.sqhsts[14] = (         int  )21;
            sqlstm.sqindv[14] = (         short *)i_shNomApellido1;
            sqlstm.sqinds[14] = (         int  )sizeof(short);
            sqlstm.sqharm[14] = (unsigned long )0;
            sqlstm.sqharc[14] = (unsigned long  *)0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (unsigned char  *)szhNomApellido2;
            sqlstm.sqhstl[15] = (unsigned long )21;
            sqlstm.sqhsts[15] = (         int  )21;
            sqlstm.sqindv[15] = (         short *)i_shNomApellido2;
            sqlstm.sqinds[15] = (         int  )sizeof(short);
            sqlstm.sqharm[15] = (unsigned long )0;
            sqlstm.sqharc[15] = (unsigned long  *)0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (unsigned char  *)dhLimCredito;
            sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[16] = (         int  )sizeof(double);
            sqlstm.sqindv[16] = (         short *)i_shLimCredito;
            sqlstm.sqinds[16] = (         int  )sizeof(short);
            sqlstm.sqharm[16] = (unsigned long )0;
            sqlstm.sqharc[16] = (unsigned long  *)0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (unsigned char  *)szhNumTerminal;
            sqlstm.sqhstl[17] = (unsigned long )16;
            sqlstm.sqhsts[17] = (         int  )16;
            sqlstm.sqindv[17] = (         short *)i_shNumTerminal;
            sqlstm.sqinds[17] = (         int  )sizeof(short);
            sqlstm.sqharm[17] = (unsigned long )0;
            sqlstm.sqharc[17] = (unsigned long  *)0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (unsigned char  *)szhNumBeeper;
            sqlstm.sqhstl[18] = (unsigned long )16;
            sqlstm.sqhsts[18] = (         int  )16;
            sqlstm.sqindv[18] = (         short *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned long )0;
            sqlstm.sqharc[18] = (unsigned long  *)0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (unsigned char  *)lhCapCode;
            sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[19] = (         int  )sizeof(long);
            sqlstm.sqindv[19] = (         short *)i_shCapCode;
            sqlstm.sqinds[19] = (         int  )sizeof(short);
            sqlstm.sqharm[19] = (unsigned long )0;
            sqlstm.sqharc[19] = (unsigned long  *)0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (unsigned char  *)ihIndSuperTel;
            sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )sizeof(int);
            sqlstm.sqindv[20] = (         short *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned long )0;
            sqlstm.sqharc[20] = (unsigned long  *)0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (unsigned char  *)szhNumTeleFija;
            sqlstm.sqhstl[21] = (unsigned long )16;
            sqlstm.sqhsts[21] = (         int  )16;
            sqlstm.sqindv[21] = (         short *)i_shNumTeleFija;
            sqlstm.sqinds[21] = (         int  )sizeof(short);
            sqlstm.sqharm[21] = (unsigned long )0;
            sqlstm.sqharc[21] = (unsigned long  *)0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (unsigned char  *)szhFecPeriDesde;
            sqlstm.sqhstl[22] = (unsigned long )15;
            sqlstm.sqhsts[22] = (         int  )15;
            sqlstm.sqindv[22] = (         short *)i_shFecPeriDesde;
            sqlstm.sqinds[22] = (         int  )sizeof(short);
            sqlstm.sqharm[22] = (unsigned long )0;
            sqlstm.sqharc[22] = (unsigned long  *)0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (unsigned char  *)szhFecPeriHasta;
            sqlstm.sqhstl[23] = (unsigned long )15;
            sqlstm.sqhsts[23] = (         int  )15;
            sqlstm.sqindv[23] = (         short *)i_shFecPeriHasta;
            sqlstm.sqinds[23] = (         int  )sizeof(short);
            sqlstm.sqharm[23] = (unsigned long )0;
            sqlstm.sqharc[23] = (unsigned long  *)0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            if (SQLCODE)
            {
                sprintf(szFuncion,"bfnInsertHistAbo Insert(1)=>%s",szNomTable);
                iInd  =(sqlca.sqlerrd[2] == SQLOK)?SQLOK:sqlca.sqlerrd[2]-1;
                bError= TRUE                 ;
                iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror())     ;
                return  TRUE;
            }
            else
            {
                i = 0;
            }
        }/* if i == NREG */
        else
        {
            lhIndOrdenTotal [i] = atol(stHis->pAbo[j].szIndOrdenTotal)   ;
            lhNumAbonado    [i] = stHis->pAbo[j].lNumAbonado             ;
            lhCodCliente    [i] = stHis->pAbo[j].lCodCliente             ;
            dhTotCargosMe   [i] = stHis->pAbo[j].dTotCargosMe            ;
            dhAcumCargo     [i] = stHis->pAbo[j].dAcumCargo              ;
            dhAcumIva       [i] = stHis->pAbo[j].dAcumIva                ;
            dhAcumDto       [i] = stHis->pAbo[j].dAcumDto                ;
            ihCodProducto   [i] = iCodProducto                          ;

            strcpy(szhCodSituacion  [i], "ZZZ");
            strcpy(szhNumBeeper     [i], "0")  ;

            ihCodCredMor  [i] = stHis->pAbo[j].iCodCredMor             ;
            i_shCodCredMor[i] = (stHis->pAbo[j].iCodCredMor == ORA_NULL)?ORA_NULL:0;
            ihCodDetFact  [i] = stHis->pAbo[j].iCodDetFact                        ;
            strcpy (szhFecFinContra [i], stHis->pAbo[j].szFecFinContra);
            ihIndFactur   [i] = stHis->pAbo[j].iIndFactur    ;
            strcpy (szhNomUsuario[i], stHis->pAbo[j].szNomUsuario);

            if (strcmp(stHis->pAbo[j].szNumTerminal, "") == 0)
                i_shNumTerminal [i] = ORA_NULL;
            else
            {
                i_shNumTerminal [i] = 0;
                strcpy (szhNumTerminal[i],stHis->pAbo[j].szNumTerminal);
            }

            if (strcmp (stHis->pAbo[j].szFecFinContra,"") == 0)
                i_Fec [i] = ORA_NULL;
            else
                i_Fec [i] = 0       ;

            if (strcmp (stHis->pAbo[j].szNomUsuario,"") == 0)
                i_shNomUsuario [i] = ORA_NULL;
            else
                i_shNomUsuario [i] = 0       ;

            strcpy (szhNomApellido1[i], stHis->pAbo[j].szNomApellido1);

            if (strcmp (stHis->pAbo[j].szNomApellido1,"") == 0)
                i_shNomApellido1 [i] = ORA_NULL;
            else
                i_shNomApellido1 [i] = 0       ;

            strcpy (szhNomApellido2 [i], stHis->pAbo[j].szNomApellido2);
            if (strcmp (stHis->pAbo[j].szNomApellido2,"") == 0)
                i_shNomApellido2 [i] = ORA_NULL;
            else
                i_shNomApellido2 [i] = 0       ;

            dhLimCredito  [i]  = stHis->pAbo[j].dLimCredito ;
            ihIndSuperTel [i]  = stHis->pAbo[j].iIndSuperTel;

            i_shIndSuperTel[i] = (ihIndSuperTel[i] == ORA_NULL)?ORA_NULL:0;
            i_shIndPrePago [i] = (ihIndPrePago [i] == ORA_NULL)?ORA_NULL:0;

            strcpy (szhNumTeleFija [i], stHis->pAbo[j].szNumTeleFija);
            if (strcmp (szhNumTeleFija[i],"") == 0)
                i_shNumTeleFija [i] = ORA_NULL;
            else
                i_shNumTeleFija [i] = 0       ;

            /* TMC-04079: se agrega a la estructura para paso a prefactura */
            strcpy (szhFecPeriDesde [i], stHis->pAbo[j].szFecPeriDesde);
            if (strcmp (stHis->pAbo[j].szFecPeriDesde,"") == 0)
                i_shFecPeriDesde [i] = ORA_NULL;
            else
                i_shFecPeriDesde [i] = 0       ;

            strcpy (szhFecPeriHasta [i], stHis->pAbo[j].szFecPeriHasta);
            if (strcmp (stHis->pAbo[j].szFecPeriHasta,"") == 0)
                i_shFecPeriHasta [i] = ORA_NULL;
            else
                i_shFecPeriHasta [i] = 0       ;

            i++;
        }
    }/* for j ... */

    if (i > 0)
    {
        /* EXEC SQL FOR :i
                 EXECUTE sql_insert_histabon
                 USING   :lhIndOrdenTotal                 ,
                         :lhNumAbonado                    ,
                         :lhCodCliente                    ,
                         :ihCodProducto                   ,
                         :szhCodSituacion                 ,
                         :dhTotCargosMe                   ,
                         :dhAcumCargo                     ,
                         :dhAcumDto                       ,
                         :dhAcumIva                       ,
                         :ihCodDetFact                    ,
                         :szhFecFinContra:i_Fec           ,
                         :ihIndFactur                     ,
                         :ihCodCredMor:i_shCodCredMor     ,
                         :szhNomUsuario:i_shNomUsuario    ,
                         :szhNomApellido1:i_shNomApellido1,
                         :szhNomApellido2:i_shNomApellido2,
                         :dhLimCredito:i_shLimCredito     ,
                         :szhNumTerminal:i_shNumTerminal  ,
                         :szhNumBeeper                    ,
                         :lhCapCode:i_shCapCode           ,
                         :ihIndSuperTel                   ,
                         :szhNumTeleFija:i_shNumTeleFija  ,
                         :szhFecPeriDesde:i_shFecPeriDesde,
                         :szhFecPeriHasta:i_shFecPeriHasta; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 50;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )i;
        sqlstm.offset = (unsigned int  )734;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)lhIndOrdenTotal;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)lhNumAbonado;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )sizeof(long);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)lhCodCliente;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )sizeof(long);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)ihCodProducto;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )sizeof(int);
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhCodSituacion;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )4;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)dhTotCargosMe;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )sizeof(double);
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqharc[5] = (unsigned long  *)0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)dhAcumCargo;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )sizeof(double);
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqharc[6] = (unsigned long  *)0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)dhAcumDto;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )sizeof(double);
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqharc[7] = (unsigned long  *)0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)dhAcumIva;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )sizeof(double);
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqharc[8] = (unsigned long  *)0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)ihCodDetFact;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )sizeof(int);
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqharc[9] = (unsigned long  *)0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)szhFecFinContra;
        sqlstm.sqhstl[10] = (unsigned long )15;
        sqlstm.sqhsts[10] = (         int  )15;
        sqlstm.sqindv[10] = (         short *)i_Fec;
        sqlstm.sqinds[10] = (         int  )sizeof(short);
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqharc[10] = (unsigned long  *)0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)ihIndFactur;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[11] = (         int  )sizeof(int);
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqharc[11] = (unsigned long  *)0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)ihCodCredMor;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )sizeof(int);
        sqlstm.sqindv[12] = (         short *)i_shCodCredMor;
        sqlstm.sqinds[12] = (         int  )sizeof(short);
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqharc[12] = (unsigned long  *)0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)szhNomUsuario;
        sqlstm.sqhstl[13] = (unsigned long )21;
        sqlstm.sqhsts[13] = (         int  )21;
        sqlstm.sqindv[13] = (         short *)i_shNomUsuario;
        sqlstm.sqinds[13] = (         int  )sizeof(short);
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqharc[13] = (unsigned long  *)0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)szhNomApellido1;
        sqlstm.sqhstl[14] = (unsigned long )21;
        sqlstm.sqhsts[14] = (         int  )21;
        sqlstm.sqindv[14] = (         short *)i_shNomApellido1;
        sqlstm.sqinds[14] = (         int  )sizeof(short);
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqharc[14] = (unsigned long  *)0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)szhNomApellido2;
        sqlstm.sqhstl[15] = (unsigned long )21;
        sqlstm.sqhsts[15] = (         int  )21;
        sqlstm.sqindv[15] = (         short *)i_shNomApellido2;
        sqlstm.sqinds[15] = (         int  )sizeof(short);
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqharc[15] = (unsigned long  *)0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)dhLimCredito;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )sizeof(double);
        sqlstm.sqindv[16] = (         short *)i_shLimCredito;
        sqlstm.sqinds[16] = (         int  )sizeof(short);
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqharc[16] = (unsigned long  *)0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)szhNumTerminal;
        sqlstm.sqhstl[17] = (unsigned long )16;
        sqlstm.sqhsts[17] = (         int  )16;
        sqlstm.sqindv[17] = (         short *)i_shNumTerminal;
        sqlstm.sqinds[17] = (         int  )sizeof(short);
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqharc[17] = (unsigned long  *)0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)szhNumBeeper;
        sqlstm.sqhstl[18] = (unsigned long )16;
        sqlstm.sqhsts[18] = (         int  )16;
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqharc[18] = (unsigned long  *)0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)lhCapCode;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[19] = (         int  )sizeof(long);
        sqlstm.sqindv[19] = (         short *)i_shCapCode;
        sqlstm.sqinds[19] = (         int  )sizeof(short);
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqharc[19] = (unsigned long  *)0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)ihIndSuperTel;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[20] = (         int  )sizeof(int);
        sqlstm.sqindv[20] = (         short *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqharc[20] = (unsigned long  *)0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)szhNumTeleFija;
        sqlstm.sqhstl[21] = (unsigned long )16;
        sqlstm.sqhsts[21] = (         int  )16;
        sqlstm.sqindv[21] = (         short *)i_shNumTeleFija;
        sqlstm.sqinds[21] = (         int  )sizeof(short);
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqharc[21] = (unsigned long  *)0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)szhFecPeriDesde;
        sqlstm.sqhstl[22] = (unsigned long )15;
        sqlstm.sqhsts[22] = (         int  )15;
        sqlstm.sqindv[22] = (         short *)i_shFecPeriDesde;
        sqlstm.sqinds[22] = (         int  )sizeof(short);
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqharc[22] = (unsigned long  *)0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)szhFecPeriHasta;
        sqlstm.sqhstl[23] = (unsigned long )15;
        sqlstm.sqhsts[23] = (         int  )15;
        sqlstm.sqindv[23] = (         short *)i_shFecPeriHasta;
        sqlstm.sqinds[23] = (         int  )sizeof(short);
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqharc[23] = (unsigned long  *)0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if (SQLCODE)
        {
            sprintf (szFuncion,"bfnInsertHistAbo Insert(2)=>%s",szNomTable);
            iInd  =(sqlca.sqlerrd[2] == SQLOK)?SQLOK:sqlca.sqlerrd[2]-1;
            bError= (TRUE);
            iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror())     ;
            vfnPrintHistAbo (&stHis->pAbo[iInd],iInd,bError);
            return  (FALSE);
        }
    }
    return TRUE;
}/************************* Final bfnInsertHistAbo ***************************/


/*****************************************************************************/
/*                          funcion : vfnPrintHistAbo                        */
/*****************************************************************************/
static void vfnPrintHistAbo (HISTABO  *stHisAbo,
                             int      j       ,/* Indice del array       */
                             BOOL     bError  )/* Si True => Traza Error */
{
    char szTabla [20] = "";

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
        sprintf(szTabla,"FA_FACTABON_%ld",stCiclo.lCodCiclFact);
    else
        strcpy (szTabla,"FA_FACTABON_NOCICLO");
    if (bError)
    {
        vDTrazasError (szExeName,
                    "\n\t\t=> Insertando en %.*s"
                    "\n\t\t [%d]-Ind.OrdenTotal    [%s] "
                    "\n\t\t [%d]-Num.Abonado       [%ld]"
                    "\n\t\t [%d]-Cod.Cliente       [%ld]"
                    "\n\t\t [%d]-Tot.Cargos Mes    [%f] "
                    "\n\t\t [%d]-Acum.Cargo        [%f] "
                    "\n\t\t [%d]-Acum.Dto          [%f] "
                    "\n\t\t [%d]-Acum.Iva          [%f] "
                    "\n\t\t [%d]-Num.Terminal      [%s] "
                    "\n\t\t [%d]-Cap.Code          [%ld]"
                    "\n\t\t [%d]-Cod.Detalle Fact. [%d] "
                    "\n\t\t [%d]-Fec.Fin Contrato  [%s] "
                    "\n\t\t [%d]-Ind.Factur        [%d] "
                    "\n\t\t [%d]-Cod.CredMor       [%d] "
                    "\n\t\t [%d]-Nom.Usuario       [%s] "
                    "\n\t\t [%d]-Nom.Apellido1     [%s] "
                    "\n\t\t [%d]-Nom.Apellido2     [%s] "
                    "\n\t\t [%d]-Lim.Credito       [%f] "
                    "\n\t\t [%d]-Ind.SuperTel      [%d] "
                    "\n\t\t [%d]-Num.TeleFija      [%s] "
                    "\n\t\t [%d]-Fec. Periodo desde[%s] "
                    "\n\t\t [%d]-Fec. Periodo hasta[%s] ",
                    LOG03,strlen(szTabla),szTabla,
                    j,stHisAbo->szIndOrdenTotal,
                    j,stHisAbo->lNumAbonado    ,
                    j,stHisAbo->lCodCliente    ,
                    j,stHisAbo->dTotCargosMe   ,
                    j,stHisAbo->dAcumCargo     ,
                    j,stHisAbo->dAcumDto       ,
                    j,stHisAbo->dAcumIva       ,
                    j,stHisAbo->szNumTerminal  ,
                    j,stHisAbo->lCapCode       ,
                    j,stHisAbo->iCodDetFact    ,
                    j,stHisAbo->szFecFinContra ,
                    j,stHisAbo->iIndFactur     ,
                    j,stHisAbo->iCodCredMor    ,
                    j,stHisAbo->szNomUsuario   ,
                    j,stHisAbo->szNomApellido1 ,
                    j,stHisAbo->szNomApellido2 ,
                    j,stHisAbo->dLimCredito    ,
                    j,stHisAbo->iIndSuperTel   ,
                    j,stHisAbo->szNumTeleFija  ,
                    j,stHisAbo->szFecPeriDesde ,
                    j,stHisAbo->szFecPeriHasta) ;
    }
    else
    {
        vDTrazasLog   (szExeName,
                    "\n\t\t=> Insertando en %.*s"
                    "\n\t\t [%d]-Ind.OrdenTotal    [%s] "
                    "\n\t\t [%d]-Num.Abonado       [%ld]"
                    "\n\t\t [%d]-Cod.Cliente       [%ld]"
                    "\n\t\t [%d]-Tot.Cargos Mes    [%f] "
                    "\n\t\t [%d]-Acum.Cargo        [%f] "
                    "\n\t\t [%d]-Acum.Dto          [%f] "
                    "\n\t\t [%d]-Acum.Iva          [%f] "
                    "\n\t\t [%d]-Num.Terminal      [%s] "
                    "\n\t\t [%d]-Cap.Code          [%ld]"
                    "\n\t\t [%d]-Cod.Detalle Fact. [%d] "
                    "\n\t\t [%d]-Fec.Fin Contrato  [%s] "
                    "\n\t\t [%d]-Ind.Factur        [%d] "
                    "\n\t\t [%d]-Cod.CredMor       [%d] "
                    "\n\t\t [%d]-Nom.Usuario       [%s] "
                    "\n\t\t [%d]-Nom.Apellido1     [%s] "
                    "\n\t\t [%d]-Nom.Apellido2     [%s] "
                    "\n\t\t [%d]-Lim.Credito       [%f] "
                    "\n\t\t [%d]-Ind.SuperTel      [%d] "
                    "\n\t\t [%d]-Num.TeleFija      [%s] "
                    "\n\t\t [%d]-Fec. Periodo desde[%s] "
                    "\n\t\t [%d]-Fec. Periodo hasta[%s] ",
                    LOG05,strlen(szTabla),szTabla,
                    j,stHisAbo->szIndOrdenTotal,
                    j,stHisAbo->lNumAbonado    ,
                    j,stHisAbo->lCodCliente    ,
                    j,stHisAbo->dTotCargosMe   ,
                    j,stHisAbo->dAcumCargo     ,
                    j,stHisAbo->dAcumDto       ,
                    j,stHisAbo->dAcumIva       ,
                    j,stHisAbo->szNumTerminal  ,
                    j,stHisAbo->lCapCode       ,
                    j,stHisAbo->iCodDetFact    ,
                    j,stHisAbo->szFecFinContra ,
                    j,stHisAbo->iIndFactur     ,
                    j,stHisAbo->iCodCredMor    ,
                    j,stHisAbo->szNomUsuario   ,
                    j,stHisAbo->szNomApellido1 ,
                    j,stHisAbo->szNomApellido2 ,
                    j,stHisAbo->dLimCredito    ,
                    j,stHisAbo->iIndSuperTel   ,
                    j,stHisAbo->szNumTeleFija  ,
                    j,stHisAbo->szFecPeriDesde ,
                    j,stHisAbo->szFecPeriHasta) ;
    }
}/************************** vfnPrintHistAbo *********************************/

/*****************************************************************************/
/*                         funcion : vfnInitCadenaInsertHistAbo              */
/*                      ":szNumTerminal             ,"                       */
/*                      ":szNumTerminal             ,"                       */
/*****************************************************************************/
static void vfnInitCadenaInsertHistAbo (char *szCadena  ,
                                        char *szNomTabla)
{
    sprintf (szCadena,
              "INSERT INTO %.*s ("
              "IND_ORDENTOTAL  ,"
              "NUM_ABONADO     ,"
              "COD_CLIENTE     ,"
              "COD_PRODUCTO    ,"
              "COD_SITUACION   ,"
              "TOT_CARGOSME    ,"
              "ACUM_CARGO      ,"
              "ACUM_DTO        ,"
              "ACUM_IVA        ,"
              "COD_DETFACT     ,"
              "FEC_FINCONTRA   ,"
              "IND_FACTUR      ,"
              "COD_CREDMOR     ,"
              "NOM_USUARIO     ,"
              "NOM_APELLIDO1   ,"
              "NOM_APELLIDO2   ,"
              "LIM_CREDITO     ,"
              "NUM_CELULAR     ,"
              "NUM_BEEPER      ,"
              "CAP_CODE        ,"
              "IND_SUPERTEL    ,"
              "NUM_TELEFIJA    ,"
              "PERIODO_DESDE   ,"
              "PERIODO_HASTA   )"
              "VALUES (:lhIndOrdenTotal           ,"
                      ":lNumAbonado               ,"
                      ":lCodCliente               ,"
                      ":iCodProducto              ,"
                      ":szCodSituacion            ,"
                      ":dTotCargosMe              ,"
                      ":dAcumCargo                ,"
                      ":dAcumDto                  ,"
                      ":dAcumIva                  ,"
                      ":iCodDetFact               ,"
                      "TO_DATE (:szFecFinContra,'YYYYMMDDHH24MISS'),"
                      ":iIndFactur                ,"
                      ":iCodCredMor               ,"
                      ":szNomUsuario              ,"
                      ":szNomApellido1            ,"
                      ":szNomApellido2            ,"
                      ":dLimCredito               ,"
                      ":szNumTerminal             ,"
                      ":szNumTerminal             ,"
                      ":lCapCode                  ,"
                      ":iIndSuperTel              ,"
                      ":szNumTeleFija             ,"
                      "TO_DATE (:szFecPeriDesde,'YYYYMMDDHH24MISS'),"
                      "TO_DATE (:szFecPeriHasta,'YYYYMMDDHH24MISS'))\0",strlen (szNomTabla),szNomTabla);

}/************************* Final vfnInitCadenaInsertHistAbo *****************/


/*****************************************************************************/
/*                            funcion : bfnInsertHistConc                   */
/*****************************************************************************/
static BOOL bfnInsertHistConc()
{
    char  modulo[] = "bfnInsertHistConc";
/* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    szIndOrdenTotal [NREG_CONC_HOSTARRAY][13];
    int     iCodConcepto    [NREG_CONC_HOSTARRAY];
    long    lColumna        [NREG_CONC_HOSTARRAY];
    char    szCodMoneda     [NREG_CONC_HOSTARRAY][4];
    short   iCodProducto    [NREG_CONC_HOSTARRAY];
    int     iCodTipConce    [NREG_CONC_HOSTARRAY];
    char    szFecValor      [NREG_CONC_HOSTARRAY][15];
    char    szFecEfectividad[NREG_CONC_HOSTARRAY][15];
    double  dImpConcepto    [NREG_CONC_HOSTARRAY];
    char    szCodRegion     [NREG_CONC_HOSTARRAY][4];
    char    szCodProvincia  [NREG_CONC_HOSTARRAY][6];
    char    szCodCiudad     [NREG_CONC_HOSTARRAY][6];
    double  dImpMontoBase   [NREG_CONC_HOSTARRAY];
    short   iIndFactur      [NREG_CONC_HOSTARRAY];
    double  dImpFacturable  [NREG_CONC_HOSTARRAY];
    short   iIndSuperTel    [NREG_CONC_HOSTARRAY];
    long    lNumAbonado     [NREG_CONC_HOSTARRAY];
    int     iCodPortador    [NREG_CONC_HOSTARRAY];
    char    szDesConcepto   [NREG_CONC_HOSTARRAY][61];
    long    lSegConsumido   [NREG_CONC_HOSTARRAY];
    long    lSeqCuotas      [NREG_CONC_HOSTARRAY];
    int     iNumCuotas      [NREG_CONC_HOSTARRAY];
    int     iOrdCuota       [NREG_CONC_HOSTARRAY];
    long    lNumUnidades    [NREG_CONC_HOSTARRAY];
    char    szNumSerieMec   [NREG_CONC_HOSTARRAY][26];
    char    szNumSerieLe    [NREG_CONC_HOSTARRAY][26];
    float   fPrcImpuesto    [NREG_CONC_HOSTARRAY];
    double  dValDto         [NREG_CONC_HOSTARRAY];
    short   iTipDto         [NREG_CONC_HOSTARRAY];
    int     iMesGarantia    [NREG_CONC_HOSTARRAY];
    char    szNumGuia       [NREG_CONC_HOSTARRAY][11];
    short   iIndAlta        [NREG_CONC_HOSTARRAY];
    int     iNumPaquete     [NREG_CONC_HOSTARRAY];
    short   iFlagImpues     [NREG_CONC_HOSTARRAY];
    short   iFlagDto        [NREG_CONC_HOSTARRAY];
    int     iCodConceRel    [NREG_CONC_HOSTARRAY];
    long    lColumnaRel     [NREG_CONC_HOSTARRAY];
    char    szCodPlanTarif  [NREG_CONC_HOSTARRAY][4];
    char    szCodCargoBasico[NREG_CONC_HOSTARRAY][4];
    char    szTipPlanTarif  [NREG_CONC_HOSTARRAY][2];
    double  dhMtoReal       [NREG_CONC_HOSTARRAY];
    double  dhMtoDcto       [NREG_CONC_HOSTARRAY];
    long    lhDurReal       [NREG_CONC_HOSTARRAY];
    long    lhDurDcto       [NREG_CONC_HOSTARRAY];
    long    lhCntLlamReal   [NREG_CONC_HOSTARRAY];
    long    lhCntLlamFact   [NREG_CONC_HOSTARRAY];
    long    lhCntLlamDcto   [NREG_CONC_HOSTARRAY];

    char   szCod_Unidad     [NREG_CONC_HOSTARRAY][6] ;
    long   lhNumUniFree     [NREG_CONC_HOSTARRAY]    ;
    int    ihCodOperador    [NREG_CONC_HOSTARRAY]    ;

    int Indx;
 /* EXEC SQL END DECLARE SECTION; */ 


    int i;
    char szCadena  [2500] ="";
    char szNomTabla[50]   ="";
    char szFuncion [99]   ="";
    BOOL bError      = FALSE;

    vDTrazasLog( szExeName,"\t\t* Entrada en %s \n",LOG04,modulo );

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        sprintf(szNomTabla,"FA_FACTCONC_%ld",stCiclo.lCodCiclFact);
    }
    else
    {
        strcpy (szNomTabla,"FA_FACTCONC_NOCICLO");
    }

    strcpy (szFuncion," PrePare=>");
    strcat (szFuncion,szNomTabla) ;

    vfnInitCadenaInsertHistConc (szCadena,szNomTabla);

    /* EXEC SQL PREPARE sql_insert_histconcelu FROM :szCadena; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 50;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )845;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
    sqlstm.sqhstl[0] = (unsigned long )2500;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion, szfnORAerror ())     ;
        return FALSE                  ;
    }

    memset(szIndOrdenTotal ,0,sizeof(szIndOrdenTotal ));
    memset(iCodConcepto    ,0,sizeof(iCodConcepto    ));
    memset(lColumna        ,0,sizeof(lColumna        ));
    memset(szCodMoneda     ,0,sizeof(szCodMoneda     ));
    memset(iCodProducto    ,0,sizeof(iCodProducto    ));
    memset(iCodTipConce    ,0,sizeof(iCodTipConce    ));
    memset(szFecValor      ,0,sizeof(szFecValor      ));
    memset(szFecEfectividad,0,sizeof(szFecEfectividad));
    memset(dImpConcepto    ,0,sizeof(dImpConcepto    ));
    memset(szCodRegion     ,0,sizeof(szCodRegion     ));
    memset(szCodProvincia  ,0,sizeof(szCodProvincia  ));
    memset(szCodCiudad     ,0,sizeof(szCodCiudad     ));
    memset(dImpMontoBase   ,0,sizeof(dImpMontoBase   ));
    memset(iIndFactur      ,0,sizeof(iIndFactur      ));
    memset(dImpFacturable  ,0,sizeof(dImpFacturable  ));
    memset(iIndSuperTel    ,0,sizeof(iIndSuperTel    ));
    memset(lNumAbonado     ,0,sizeof(lNumAbonado     ));
    memset(iCodPortador    ,0,sizeof(iCodPortador    ));
    memset(szDesConcepto   ,0,sizeof(szDesConcepto   ));
    memset(lSegConsumido   ,0,sizeof(lSegConsumido   ));
    memset(lSeqCuotas      ,0,sizeof(lSeqCuotas      ));
    memset(iNumCuotas      ,0,sizeof(iNumCuotas      ));
    memset(iOrdCuota       ,0,sizeof(iOrdCuota       ));
    memset(lNumUnidades    ,0,sizeof(lNumUnidades    ));
    memset(szNumSerieMec   ,0,sizeof(szNumSerieMec   ));
    memset(szNumSerieLe    ,0,sizeof(szNumSerieLe    ));
    memset(fPrcImpuesto    ,0,sizeof(fPrcImpuesto    ));
    memset(dValDto         ,0,sizeof(dValDto         ));
    memset(iTipDto         ,0,sizeof(iTipDto         ));
    memset(iMesGarantia    ,0,sizeof(iMesGarantia    ));
    memset(szNumGuia       ,0,sizeof(szNumGuia       ));
    memset(iIndAlta        ,0,sizeof(iIndAlta        ));
    memset(iNumPaquete     ,0,sizeof(iNumPaquete     ));
    memset(iFlagImpues     ,0,sizeof(iFlagImpues     ));
    memset(iFlagDto        ,0,sizeof(iFlagDto        ));
    memset(iCodConceRel    ,0,sizeof(iCodConceRel    ));
    memset(lColumnaRel     ,0,sizeof(lColumnaRel     ));
    memset(szCodPlanTarif  ,0,sizeof(szCodPlanTarif  ));
    memset(szCodCargoBasico,0,sizeof(szCodCargoBasico));
    memset(szTipPlanTarif  ,0,sizeof(szTipPlanTarif  ));
    memset(dhMtoReal       ,0,sizeof(dhMtoReal       ));
    memset(dhMtoDcto       ,0,sizeof(dhMtoDcto       ));
    memset(lhDurReal       ,0,sizeof(lhDurReal       ));
    memset(lhDurDcto       ,0,sizeof(lhDurDcto       ));
    memset(lhCntLlamReal   ,0,sizeof(lhCntLlamReal   ));
    memset(lhCntLlamFact   ,0,sizeof(lhCntLlamFact   ));
    memset(lhCntLlamDcto   ,0,sizeof(lhCntLlamDcto   ));

    memset(szCod_Unidad     , 0, sizeof(szCod_Unidad             ));
    memset(lhNumUniFree     , 0, sizeof(lhNumUniFree             ));
    memset(ihCodOperador        , 0, sizeof(ihCodOperador            ));

    for(Indx=0,i=0;i<stPreFactura.iNumRegistros;i++)
    {
        vDTrazasLog ( szExeName,"\t\t*Indx: [%d] - stPreFactura.iNumRegistros:[%ld] -  NREG_CONC_HOSTARRAY: [%d] \n"
                        , LOG06
                        , Indx
                        , stPreFactura.iNumRegistros
                        , NREG_CONC_HOSTARRAY);

        if (Indx == NREG_CONC_HOSTARRAY)
        {
            vDTrazasLog ( szExeName,"\t\t* %s voy a insert(1) %d regs\n",LOG04,modulo, Indx);
            /* EXEC SQL FOR :Indx
            EXECUTE  sql_insert_histconcelu
            USING
            :szIndOrdenTotal ,
            :iCodConcepto    ,
            :lColumna        ,
            :szCodMoneda     ,
            :iCodProducto    ,
            :iCodTipConce    ,
            :szFecValor      ,
            :szFecEfectividad,
            :dImpConcepto    ,
            :szCodRegion     ,
            :szCodProvincia  ,
            :szCodCiudad     ,
            :dImpMontoBase   ,
            :iIndFactur      ,
            :dImpFacturable  ,
            :iIndSuperTel    ,
            :lNumAbonado     ,
            :iCodPortador    ,
            :szDesConcepto   ,
            :lSegConsumido   ,
            :lSeqCuotas      ,
            :iNumCuotas      ,
            :iOrdCuota       ,
            :lNumUnidades    ,
            :szNumSerieMec   ,
            :szNumSerieLe    ,
            :fPrcImpuesto    ,
            :dValDto         ,
            :iTipDto         ,
            :iMesGarantia    ,
            :szNumGuia       ,
            :iIndAlta        ,
            :iNumPaquete     ,
            :iFlagImpues     ,
            :iFlagDto        ,
            :iCodConceRel    ,
            :lColumnaRel     ,
            :szCodPlanTarif  ,
            :szCodCargoBasico,
            :szTipPlanTarif  ,
            :dhMtoReal       ,
            :dhMtoDcto       ,
            :lhDurReal       ,
            :lhDurDcto       ,
            :lhCntLlamReal   ,
            :lhCntLlamFact   ,
            :lhCntLlamDcto   ,
            :szCod_Unidad    ,
            :lhNumUniFree    ,
            :ihCodOperador; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 50;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )Indx;
            sqlstm.offset = (unsigned int  )864;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szIndOrdenTotal;
            sqlstm.sqhstl[0] = (unsigned long )13;
            sqlstm.sqhsts[0] = (         int  )13;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqharc[0] = (unsigned long  *)0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)iCodConcepto;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )sizeof(int);
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqharc[1] = (unsigned long  *)0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)lColumna;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )sizeof(long);
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqharc[2] = (unsigned long  *)0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)szCodMoneda;
            sqlstm.sqhstl[3] = (unsigned long )4;
            sqlstm.sqhsts[3] = (         int  )4;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqharc[3] = (unsigned long  *)0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)iCodProducto;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[4] = (         int  )sizeof(short);
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqharc[4] = (unsigned long  *)0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)iCodTipConce;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )sizeof(int);
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqharc[5] = (unsigned long  *)0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szFecValor;
            sqlstm.sqhstl[6] = (unsigned long )15;
            sqlstm.sqhsts[6] = (         int  )15;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqharc[6] = (unsigned long  *)0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szFecEfectividad;
            sqlstm.sqhstl[7] = (unsigned long )15;
            sqlstm.sqhsts[7] = (         int  )15;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqharc[7] = (unsigned long  *)0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)dImpConcepto;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )sizeof(double);
            sqlstm.sqindv[8] = (         short *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqharc[8] = (unsigned long  *)0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)szCodRegion;
            sqlstm.sqhstl[9] = (unsigned long )4;
            sqlstm.sqhsts[9] = (         int  )4;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqharc[9] = (unsigned long  *)0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)szCodProvincia;
            sqlstm.sqhstl[10] = (unsigned long )6;
            sqlstm.sqhsts[10] = (         int  )6;
            sqlstm.sqindv[10] = (         short *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqharc[10] = (unsigned long  *)0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)szCodCiudad;
            sqlstm.sqhstl[11] = (unsigned long )6;
            sqlstm.sqhsts[11] = (         int  )6;
            sqlstm.sqindv[11] = (         short *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqharc[11] = (unsigned long  *)0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)dImpMontoBase;
            sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )sizeof(double);
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqharc[12] = (unsigned long  *)0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)iIndFactur;
            sqlstm.sqhstl[13] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[13] = (         int  )sizeof(short);
            sqlstm.sqindv[13] = (         short *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqharc[13] = (unsigned long  *)0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (unsigned char  *)dImpFacturable;
            sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )sizeof(double);
            sqlstm.sqindv[14] = (         short *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned long )0;
            sqlstm.sqharc[14] = (unsigned long  *)0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (unsigned char  *)iIndSuperTel;
            sqlstm.sqhstl[15] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[15] = (         int  )sizeof(short);
            sqlstm.sqindv[15] = (         short *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned long )0;
            sqlstm.sqharc[15] = (unsigned long  *)0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (unsigned char  *)lNumAbonado;
            sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[16] = (         int  )sizeof(long);
            sqlstm.sqindv[16] = (         short *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned long )0;
            sqlstm.sqharc[16] = (unsigned long  *)0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (unsigned char  *)iCodPortador;
            sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[17] = (         int  )sizeof(int);
            sqlstm.sqindv[17] = (         short *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned long )0;
            sqlstm.sqharc[17] = (unsigned long  *)0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (unsigned char  *)szDesConcepto;
            sqlstm.sqhstl[18] = (unsigned long )61;
            sqlstm.sqhsts[18] = (         int  )61;
            sqlstm.sqindv[18] = (         short *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned long )0;
            sqlstm.sqharc[18] = (unsigned long  *)0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (unsigned char  *)lSegConsumido;
            sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[19] = (         int  )sizeof(long);
            sqlstm.sqindv[19] = (         short *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned long )0;
            sqlstm.sqharc[19] = (unsigned long  *)0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (unsigned char  *)lSeqCuotas;
            sqlstm.sqhstl[20] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[20] = (         int  )sizeof(long);
            sqlstm.sqindv[20] = (         short *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned long )0;
            sqlstm.sqharc[20] = (unsigned long  *)0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (unsigned char  *)iNumCuotas;
            sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[21] = (         int  )sizeof(int);
            sqlstm.sqindv[21] = (         short *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned long )0;
            sqlstm.sqharc[21] = (unsigned long  *)0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (unsigned char  *)iOrdCuota;
            sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )sizeof(int);
            sqlstm.sqindv[22] = (         short *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned long )0;
            sqlstm.sqharc[22] = (unsigned long  *)0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (unsigned char  *)lNumUnidades;
            sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[23] = (         int  )sizeof(long);
            sqlstm.sqindv[23] = (         short *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned long )0;
            sqlstm.sqharc[23] = (unsigned long  *)0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (unsigned char  *)szNumSerieMec;
            sqlstm.sqhstl[24] = (unsigned long )26;
            sqlstm.sqhsts[24] = (         int  )26;
            sqlstm.sqindv[24] = (         short *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned long )0;
            sqlstm.sqharc[24] = (unsigned long  *)0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (unsigned char  *)szNumSerieLe;
            sqlstm.sqhstl[25] = (unsigned long )26;
            sqlstm.sqhsts[25] = (         int  )26;
            sqlstm.sqindv[25] = (         short *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned long )0;
            sqlstm.sqharc[25] = (unsigned long  *)0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (unsigned char  *)fPrcImpuesto;
            sqlstm.sqhstl[26] = (unsigned long )sizeof(float);
            sqlstm.sqhsts[26] = (         int  )sizeof(float);
            sqlstm.sqindv[26] = (         short *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned long )0;
            sqlstm.sqharc[26] = (unsigned long  *)0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (unsigned char  *)dValDto;
            sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )sizeof(double);
            sqlstm.sqindv[27] = (         short *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned long )0;
            sqlstm.sqharc[27] = (unsigned long  *)0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (unsigned char  *)iTipDto;
            sqlstm.sqhstl[28] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[28] = (         int  )sizeof(short);
            sqlstm.sqindv[28] = (         short *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned long )0;
            sqlstm.sqharc[28] = (unsigned long  *)0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (unsigned char  *)iMesGarantia;
            sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[29] = (         int  )sizeof(int);
            sqlstm.sqindv[29] = (         short *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned long )0;
            sqlstm.sqharc[29] = (unsigned long  *)0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (unsigned char  *)szNumGuia;
            sqlstm.sqhstl[30] = (unsigned long )11;
            sqlstm.sqhsts[30] = (         int  )11;
            sqlstm.sqindv[30] = (         short *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned long )0;
            sqlstm.sqharc[30] = (unsigned long  *)0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (unsigned char  *)iIndAlta;
            sqlstm.sqhstl[31] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[31] = (         int  )sizeof(short);
            sqlstm.sqindv[31] = (         short *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned long )0;
            sqlstm.sqharc[31] = (unsigned long  *)0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (unsigned char  *)iNumPaquete;
            sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[32] = (         int  )sizeof(int);
            sqlstm.sqindv[32] = (         short *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned long )0;
            sqlstm.sqharc[32] = (unsigned long  *)0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (unsigned char  *)iFlagImpues;
            sqlstm.sqhstl[33] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[33] = (         int  )sizeof(short);
            sqlstm.sqindv[33] = (         short *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned long )0;
            sqlstm.sqharc[33] = (unsigned long  *)0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (unsigned char  *)iFlagDto;
            sqlstm.sqhstl[34] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[34] = (         int  )sizeof(short);
            sqlstm.sqindv[34] = (         short *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned long )0;
            sqlstm.sqharc[34] = (unsigned long  *)0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (unsigned char  *)iCodConceRel;
            sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[35] = (         int  )sizeof(int);
            sqlstm.sqindv[35] = (         short *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned long )0;
            sqlstm.sqharc[35] = (unsigned long  *)0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (unsigned char  *)lColumnaRel;
            sqlstm.sqhstl[36] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[36] = (         int  )sizeof(long);
            sqlstm.sqindv[36] = (         short *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned long )0;
            sqlstm.sqharc[36] = (unsigned long  *)0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (unsigned char  *)szCodPlanTarif;
            sqlstm.sqhstl[37] = (unsigned long )4;
            sqlstm.sqhsts[37] = (         int  )4;
            sqlstm.sqindv[37] = (         short *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned long )0;
            sqlstm.sqharc[37] = (unsigned long  *)0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (unsigned char  *)szCodCargoBasico;
            sqlstm.sqhstl[38] = (unsigned long )4;
            sqlstm.sqhsts[38] = (         int  )4;
            sqlstm.sqindv[38] = (         short *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned long )0;
            sqlstm.sqharc[38] = (unsigned long  *)0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (unsigned char  *)szTipPlanTarif;
            sqlstm.sqhstl[39] = (unsigned long )2;
            sqlstm.sqhsts[39] = (         int  )2;
            sqlstm.sqindv[39] = (         short *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned long )0;
            sqlstm.sqharc[39] = (unsigned long  *)0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (unsigned char  *)dhMtoReal;
            sqlstm.sqhstl[40] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[40] = (         int  )sizeof(double);
            sqlstm.sqindv[40] = (         short *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned long )0;
            sqlstm.sqharc[40] = (unsigned long  *)0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (unsigned char  *)dhMtoDcto;
            sqlstm.sqhstl[41] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[41] = (         int  )sizeof(double);
            sqlstm.sqindv[41] = (         short *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned long )0;
            sqlstm.sqharc[41] = (unsigned long  *)0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (unsigned char  *)lhDurReal;
            sqlstm.sqhstl[42] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[42] = (         int  )sizeof(long);
            sqlstm.sqindv[42] = (         short *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned long )0;
            sqlstm.sqharc[42] = (unsigned long  *)0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (unsigned char  *)lhDurDcto;
            sqlstm.sqhstl[43] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[43] = (         int  )sizeof(long);
            sqlstm.sqindv[43] = (         short *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned long )0;
            sqlstm.sqharc[43] = (unsigned long  *)0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (unsigned char  *)lhCntLlamReal;
            sqlstm.sqhstl[44] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[44] = (         int  )sizeof(long);
            sqlstm.sqindv[44] = (         short *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned long )0;
            sqlstm.sqharc[44] = (unsigned long  *)0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (unsigned char  *)lhCntLlamFact;
            sqlstm.sqhstl[45] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[45] = (         int  )sizeof(long);
            sqlstm.sqindv[45] = (         short *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned long )0;
            sqlstm.sqharc[45] = (unsigned long  *)0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (unsigned char  *)lhCntLlamDcto;
            sqlstm.sqhstl[46] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[46] = (         int  )sizeof(long);
            sqlstm.sqindv[46] = (         short *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned long )0;
            sqlstm.sqharc[46] = (unsigned long  *)0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (unsigned char  *)szCod_Unidad;
            sqlstm.sqhstl[47] = (unsigned long )6;
            sqlstm.sqhsts[47] = (         int  )6;
            sqlstm.sqindv[47] = (         short *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned long )0;
            sqlstm.sqharc[47] = (unsigned long  *)0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (unsigned char  *)lhNumUniFree;
            sqlstm.sqhstl[48] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[48] = (         int  )sizeof(long);
            sqlstm.sqindv[48] = (         short *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned long )0;
            sqlstm.sqharc[48] = (unsigned long  *)0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (unsigned char  *)ihCodOperador;
            sqlstm.sqhstl[49] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[49] = (         int  )sizeof(int);
            sqlstm.sqindv[49] = (         short *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned long )0;
            sqlstm.sqharc[49] = (unsigned long  *)0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqphsv = sqlstm.sqhstv;
            sqlstm.sqphsl = sqlstm.sqhstl;
            sqlstm.sqphss = sqlstm.sqhsts;
            sqlstm.sqpind = sqlstm.sqindv;
            sqlstm.sqpins = sqlstm.sqinds;
            sqlstm.sqparm = sqlstm.sqharm;
            sqlstm.sqparc = sqlstm.sqharc;
            sqlstm.sqpadto = sqlstm.sqadto;
            sqlstm.sqptdso = sqlstm.sqtdso;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            vDTrazasLog( szExeName,"\t\t*%s 1 Inserte en %s, %d Registros (SQLCODE=%d)\n",LOG04,modulo, szNomTabla, sqlca.sqlerrd[2],SQLCODE);
            if (SQLCODE)
            {
                sprintf(szFuncion,"HistConc(1)=>%s(%d)",szNomTabla,SQLCODE);
                iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror());
                return(FALSE);
            }
            else
            {
                Indx = 0;
                memset(szIndOrdenTotal ,0,sizeof(szIndOrdenTotal ));
                memset(iCodConcepto    ,0,sizeof(iCodConcepto    ));
                memset(lColumna        ,0,sizeof(lColumna        ));
                memset(szCodMoneda     ,0,sizeof(szCodMoneda     ));
                memset(iCodProducto    ,0,sizeof(iCodProducto    ));
                memset(iCodTipConce    ,0,sizeof(iCodTipConce    ));
                memset(szFecValor      ,0,sizeof(szFecValor      ));
                memset(szFecEfectividad,0,sizeof(szFecEfectividad));
                memset(dImpConcepto    ,0,sizeof(dImpConcepto    ));
                memset(szCodRegion     ,0,sizeof(szCodRegion     ));
                memset(szCodProvincia  ,0,sizeof(szCodProvincia  ));
                memset(szCodCiudad     ,0,sizeof(szCodCiudad     ));
                memset(dImpMontoBase   ,0,sizeof(dImpMontoBase   ));
                memset(iIndFactur      ,0,sizeof(iIndFactur      ));
                memset(dImpFacturable  ,0,sizeof(dImpFacturable  ));
                memset(iIndSuperTel    ,0,sizeof(iIndSuperTel    ));
                memset(lNumAbonado     ,0,sizeof(lNumAbonado     ));
                memset(iCodPortador    ,0,sizeof(iCodPortador    ));
                memset(szDesConcepto   ,0,sizeof(szDesConcepto   ));
                memset(lSegConsumido   ,0,sizeof(lSegConsumido   ));
                memset(lSeqCuotas      ,0,sizeof(lSeqCuotas      ));
                memset(iNumCuotas      ,0,sizeof(iNumCuotas      ));
                memset(iOrdCuota       ,0,sizeof(iOrdCuota       ));
                memset(lNumUnidades    ,0,sizeof(lNumUnidades    ));
                memset(szNumSerieMec   ,0,sizeof(szNumSerieMec   ));
                memset(szNumSerieLe    ,0,sizeof(szNumSerieLe    ));
                memset(fPrcImpuesto    ,0,sizeof(fPrcImpuesto    ));
                memset(dValDto         ,0,sizeof(dValDto         ));
                memset(iTipDto         ,0,sizeof(iTipDto         ));
                memset(iMesGarantia    ,0,sizeof(iMesGarantia    ));
                memset(szNumGuia       ,0,sizeof(szNumGuia       ));
                memset(iIndAlta        ,0,sizeof(iIndAlta        ));
                memset(iNumPaquete     ,0,sizeof(iNumPaquete     ));
                memset(iFlagImpues     ,0,sizeof(iFlagImpues     ));
                memset(iFlagDto        ,0,sizeof(iFlagDto        ));
                memset(iCodConceRel    ,0,sizeof(iCodConceRel    ));
                memset(lColumnaRel     ,0,sizeof(lColumnaRel     ));
                memset(szCodPlanTarif  ,0,sizeof(szCodPlanTarif  ));
                memset(szCodCargoBasico,0,sizeof(szCodCargoBasico));
                memset(szTipPlanTarif  ,0,sizeof(szTipPlanTarif  ));
                memset(dhMtoReal       ,0,sizeof(dhMtoReal       ));
                memset(dhMtoDcto       ,0,sizeof(dhMtoDcto       ));
                memset(lhDurReal       ,0,sizeof(lhDurReal       ));
                memset(lhDurDcto       ,0,sizeof(lhDurDcto       ));
                memset(lhCntLlamReal   ,0,sizeof(lhCntLlamReal   ));
                memset(lhCntLlamFact   ,0,sizeof(lhCntLlamFact   ));
                memset(lhCntLlamDcto   ,0,sizeof(lhCntLlamDcto   ));

                memset(szCod_Unidad    ,0,sizeof(szCod_Unidad    ));
                memset(lhNumUniFree    ,0,sizeof(lhNumUniFree    ));
                memset(ihCodOperador   ,0,sizeof(ihCodOperador   ));

            }
        }
        vDTrazasLog( szExeName,"\t* (PPQL) Copiando datos Indx:[%d], i:[%ld]"
                                "\n\t\tPFactura.iCodConcepto        :[%d]"
                                "\n\t\tPFactura.lColumna            :[%ld]"
                                "\n\t\tPFactura.szCodMoneda         :[%s]"
                                "\n\t\tPFactura.iCodProducto        :[%d]"
                                "\n\t\tPFactura.iCodTipConce        :[%d]"
                                "\n\t\tPFactura.szFecValor          :[%s]"
                                "\n\t\tPFactura.szFecEfectividad    :[%s]"
                                "\n\t\tPFactura.dImpConcepto        :[%f]"
                                "\n\t\tPFactura.szCodRegion         :[%s]"
                                "\n\t\tPFactura.szCodProvincia:     :[%s]"
                                "\n\t\tPFactura.szCodCiudad         :[%s]"
                                "\n\t\tPFactura.dImpMontoBase       :[%f]"
                                "\n\t\tPFactura.iIndFactur          :[%d]"
                                "\n\t\tPFactura.dImpFacturable      :[%f]"
                                "\n\t\tPFactura.iIndSuperTel        :[%d]"
                                "\n\t\tPFactura.lNumAbonado         :[%ld]"
                                "\n\t\tPFactura.iCodPortador        :[%d]"
                                "\n\t\tPFactura.szDesConcepto       :[%s]"
                                "\n\t\tPFactura.lSegConsumido       :[%ld]"
                                "\n\t\tPFactura.lSeqCuotas          :[%ld]"
                                "\n\t\tPFactura.iNumCuotas          :[%d]"
                                "\n\t\tPFactura.iOrdCuota           :[%d]"
                                "\n\t\tPFactura.lNumUnidades        :[%ld]"
                                "\n\t\tPFactura.szNumSerieMec       :[%s]"
                                "\n\t\tPFactura.szNumSerieLe        :[%s]"
                                "\n\t\tPFactura.fPrcImpuesto        :[%f]"
                                "\n\t\tPFactura.dValDto             :[%f]"
                                "\n\t\tPFactura.iTipDto             :[%d]"
                                "\n\t\tPFactura.iMesGarantia        :[%d]"
                                "\n\t\tPFactura.szNumGuia           :[%s]"
                                "\n\t\tPFactura.iIndAlta            :[%d]"
                                "\n\t\tPFactura.iNumPaquete         :[%d]"
                                "\n\t\tPFactura.iFlagImpues         :[%d]"
                                "\n\t\tPFactura.iFlagDto            :[%d]"
                                "\n\t\tPFactura.iCodConceRel        :[%d]"
                                "\n\t\tPFactura.lColumnaRel         :[%ld]"
                                "\n\t\tPFactura.szCodPlanTarif      :[%s]"
                                "\n\t\tPFactura.szCodCargoBasico    :[%s]"
                                "\n\t\tPFactura.szTipPlanTarif      :[%s]"
                                "\n\t\tPFactura.dhMtoReal           :[%f]"
                                "\n\t\tPFactura.dhMtoDcto           :[%f]"
                                "\n\t\tPFactura.lhDurReal           :[%ld]"
                                "\n\t\tPFactura.lhDurDcto           :[%ld]"
                                "\n\t\tPFactura.lhCntLlamReal       :[%ld]"
                                "\n\t\tPFactura.lhCntLlamFact       :[%ld]"
                                "\n\t\tPFactura.lhCntLlamDcto       :[%ld]"
                                "\n\t\tPFactura.szCod_Unidad        :[%s]"
                                "\n\t\tPFactura.lhNumUniFree        :[%ld]"
                                "\n\t\tPFactura.ihCodOperador       :[%d]"
                                , LOG06
                                , Indx
                                , i
                                ,stPreFactura.A_PFactura.iCodConcepto[i]
                                ,stPreFactura.A_PFactura.lColumna    [i]
                                ,stPreFactura.A_PFactura.szCodMoneda  [i]
                                ,stPreFactura.A_PFactura.iCodProducto[i]
                                ,stPreFactura.A_PFactura.iCodTipConce[i]
                                ,stPreFactura.A_PFactura.szFecValor[i]
                                ,stPreFactura.A_PFactura.szFecEfectividad [i]
                                ,stPreFactura.A_PFactura.dImpConcepto [i]
                                ,stPreFactura.A_PFactura.szCodRegion [i]
                                ,stPreFactura.A_PFactura.szCodProvincia [i]
                                ,stPreFactura.A_PFactura.szCodCiudad    [i]
                                ,stPreFactura.A_PFactura.dImpMontoBase [i]
                                ,stPreFactura.A_PFactura.iIndFactur    [i]
                                ,stPreFactura.A_PFactura.dImpFacturable[i]
                                ,stPreFactura.A_PFactura.iIndSuperTel[i]
                                ,stPreFactura.A_PFactura.lNumAbonado [i]
                                ,stPreFactura.A_PFactura.iCodPortador[i]
                                ,stPreFactura.A_PFactura.szDesConcepto [i]
                                ,stPreFactura.A_PFactura.lSegConsumido[i]
                                ,stPreFactura.A_PFactura.lSeqCuotas  [i]
                                ,stPreFactura.A_PFactura.iNumCuotas  [i]
                                ,stPreFactura.A_PFactura.iOrdCuota   [i]
                                ,stPreFactura.A_PFactura.lNumUnidades[i]
                                ,stPreFactura.A_PFactura.szNumSerieMec [i]
                                ,stPreFactura.A_PFactura.szNumSerieLe  [i]
                                ,stPreFactura.A_PFactura.fPrcImpuesto [i]
                                ,stPreFactura.A_PFactura.dValDto      [i]
                                ,stPreFactura.A_PFactura.iTipDto      [i]
                                ,stPreFactura.A_PFactura.iMesGarantia [i]
                                ,stPreFactura.A_PFactura.szNumGuia     [i]
                                ,stPreFactura.A_PFactura.iIndAlta     [i]
                                ,stPreFactura.A_PFactura.iNumPaquete  [i]
                                ,stPreFactura.A_PFactura.iFlagImpues  [i]
                                ,stPreFactura.A_PFactura.iFlagDto     [i]
                                ,stPreFactura.A_PFactura.iCodConceRel [i]
                                ,stPreFactura.A_PFactura.lColumnaRel  [i]
                                ,stPreFactura.A_PFactura.szCodPlanTarif     [i]
                                ,stPreFactura.A_PFactura.szCodCargoBasico   [i]
                                ,stPreFactura.A_PFactura.szTipPlanTarif     [i]
                                ,stPreFactura.A_PFactura.dhMtoReal [i]
                                ,stPreFactura.A_PFactura.dhMtoDcto [i]
                                ,stPreFactura.A_PFactura.lhDurReal [i]
                                ,stPreFactura.A_PFactura.lhDurDcto [i]
                                ,stPreFactura.A_PFactura.lhCntLlamReal [i]
                                ,stPreFactura.A_PFactura.lhCntLlamFact [i]
                                ,stPreFactura.A_PFactura.lhCntLlamDcto [i]
                                ,stPreFactura.A_PFactura.szCod_Unidad     [i]
                                ,stPreFactura.A_PFactura.lhNumUniFree [i]
                                ,stPreFactura.A_PFactura.ihCodOperador [i]);

            strcpy(szIndOrdenTotal  [Indx],stDatosGener.szIndOrdenTotal);
            iCodConcepto               [Indx]=stPreFactura.A_PFactura.iCodConcepto[i];
            lColumna                   [Indx]=stPreFactura.A_PFactura.lColumna    [i];
            strcpy(szCodMoneda     [Indx],stPreFactura.A_PFactura.szCodMoneda  [i]);
            iCodProducto               [Indx]=stPreFactura.A_PFactura.iCodProducto[i];
            iCodTipConce               [Indx]=stPreFactura.A_PFactura.iCodTipConce[i];
            strcpy(szFecValor      [Indx],stPreFactura.A_PFactura.szFecValor[i]);
            strcpy(szFecEfectividad [Indx],stPreFactura.A_PFactura.szFecEfectividad [i]);
            dImpConcepto               [Indx]=stPreFactura.A_PFactura.dImpConcepto [i];
            strcpy(szCodRegion     [Indx],stPreFactura.A_PFactura.szCodRegion [i]);
            strcpy(szCodProvincia  [Indx],stPreFactura.A_PFactura.szCodProvincia [i]);
            strcpy(szCodCiudad     [Indx],stPreFactura.A_PFactura.szCodCiudad    [i]);
            dImpMontoBase              [Indx]=stPreFactura.A_PFactura.dImpMontoBase [i];
            iIndFactur                 [Indx]=stPreFactura.A_PFactura.iIndFactur    [i];
            dImpFacturable             [Indx]=stPreFactura.A_PFactura.dImpFacturable[i];
            iIndSuperTel               [Indx]=stPreFactura.A_PFactura.iIndSuperTel[i];
            /*lNumAbonado              [Indx]=stPreFactura.A_PFactura.lNumAbonado [i]; AFGS 73505*/
            lNumAbonado                [Indx] = (stPreFactura.A_PFactura.lNumAbonado [i] == -1)?0:stPreFactura.A_PFactura.lNumAbonado [i];
            iCodPortador               [Indx]=stPreFactura.A_PFactura.iCodPortador[i];
            strcpy(szDesConcepto   [Indx],stPreFactura.A_PFactura.szDesConcepto [i]);
            lSegConsumido              [Indx]=stPreFactura.A_PFactura.lSegConsumido[i];
            lSeqCuotas                 [Indx]=stPreFactura.A_PFactura.lSeqCuotas  [i];
            iNumCuotas                 [Indx]=stPreFactura.A_PFactura.iNumCuotas  [i];
            iOrdCuota                  [Indx]=stPreFactura.A_PFactura.iOrdCuota   [i];
            lNumUnidades               [Indx]=stPreFactura.A_PFactura.lNumUnidades[i];
            strcpy(szNumSerieMec   [Indx],stPreFactura.A_PFactura.szNumSerieMec [i]);
            strcpy(szNumSerieLe    [Indx],stPreFactura.A_PFactura.szNumSerieLe  [i]);
            fPrcImpuesto               [Indx]=stPreFactura.A_PFactura.fPrcImpuesto [i];
            dValDto                    [Indx]=stPreFactura.A_PFactura.dValDto      [i];
            iTipDto                    [Indx]=stPreFactura.A_PFactura.iTipDto      [i];
            iMesGarantia               [Indx]=stPreFactura.A_PFactura.iMesGarantia [i];
            strcpy(szNumGuia       [Indx],stPreFactura.A_PFactura.szNumGuia     [i]);
            iIndAlta                   [Indx]=stPreFactura.A_PFactura.iIndAlta     [i];
            iNumPaquete                [Indx]=stPreFactura.A_PFactura.iNumPaquete  [i];
            iFlagImpues                [Indx]=stPreFactura.A_PFactura.iFlagImpues  [i];
            iFlagDto                   [Indx]=stPreFactura.A_PFactura.iFlagDto     [i];
            iCodConceRel               [Indx]=stPreFactura.A_PFactura.iCodConceRel [i];
            lColumnaRel                [Indx]=stPreFactura.A_PFactura.lColumnaRel  [i];
            strcpy(szCodPlanTarif  [Indx],stPreFactura.A_PFactura.szCodPlanTarif     [i]);
            strcpy(szCodCargoBasico[Indx],stPreFactura.A_PFactura.szCodCargoBasico   [i]);
            strcpy(szTipPlanTarif  [Indx],stPreFactura.A_PFactura.szTipPlanTarif     [i]);
            dhMtoReal                  [Indx]=stPreFactura.A_PFactura.dhMtoReal [i];
            dhMtoDcto                  [Indx]=stPreFactura.A_PFactura.dhMtoDcto [i];
            lhDurReal                  [Indx]=stPreFactura.A_PFactura.lhDurReal [i];
            lhDurDcto                  [Indx]=stPreFactura.A_PFactura.lhDurDcto [i];
            lhCntLlamReal              [Indx]=stPreFactura.A_PFactura.lhCntLlamReal [i];
            lhCntLlamFact              [Indx]=stPreFactura.A_PFactura.lhCntLlamFact [i];
            lhCntLlamDcto              [Indx]=stPreFactura.A_PFactura.lhCntLlamDcto [i];

                        strcpy (szCod_Unidad [Indx] , stPreFactura.A_PFactura.szCod_Unidad     [i]);
                        lhNumUniFree         [Indx] = stPreFactura.A_PFactura.lhNumUniFree [i];
                        ihCodOperador        [Indx] = stPreFactura.A_PFactura.ihCodOperador [i];

            Indx++;

    }
    if (Indx> 0)
    {
        vDTrazasLog ( szExeName,"\t\t* %s  insert(2) %d regs\n",LOG04,modulo, Indx);
        /* EXEC SQL FOR :Indx
        EXECUTE  sql_insert_histconcelu USING
        :szIndOrdenTotal ,
        :iCodConcepto    ,
        :lColumna        ,
        :szCodMoneda     ,
        :iCodProducto    ,
        :iCodTipConce    ,
        :szFecValor      ,
        :szFecEfectividad,
        :dImpConcepto    ,
        :szCodRegion     ,
        :szCodProvincia  ,
        :szCodCiudad     ,
        :dImpMontoBase   ,
        :iIndFactur      ,
        :dImpFacturable  ,
        :iIndSuperTel    ,
        :lNumAbonado     ,
        :iCodPortador    ,
        :szDesConcepto   ,
        :lSegConsumido   ,
        :lSeqCuotas      ,
        :iNumCuotas      ,
        :iOrdCuota       ,
        :lNumUnidades    ,
        :szNumSerieMec   ,
        :szNumSerieLe    ,
        :fPrcImpuesto    ,
        :dValDto         ,
        :iTipDto         ,
        :iMesGarantia    ,
        :szNumGuia       ,
        :iIndAlta        ,
        :iNumPaquete     ,
        :iFlagImpues     ,
        :iFlagDto        ,
        :iCodConceRel    ,
        :lColumnaRel     ,
        :szCodPlanTarif  ,
        :szCodCargoBasico,
        :szTipPlanTarif  ,
        :dhMtoReal       ,
        :dhMtoDcto       ,
        :lhDurReal       ,
        :lhDurDcto       ,
        :lhCntLlamReal   ,
        :lhCntLlamFact   ,
        :lhCntLlamDcto   ,
                :szCod_Unidad    ,
                :lhNumUniFree    ,
                :ihCodOperador; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 50;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )Indx;
        sqlstm.offset = (unsigned int  )1079;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szIndOrdenTotal;
        sqlstm.sqhstl[0] = (unsigned long )13;
        sqlstm.sqhsts[0] = (         int  )13;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)iCodConcepto;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )sizeof(int);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)lColumna;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )sizeof(long);
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szCodMoneda;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )4;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqharc[3] = (unsigned long  *)0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)iCodProducto;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[4] = (         int  )sizeof(short);
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqharc[4] = (unsigned long  *)0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)iCodTipConce;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )sizeof(int);
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqharc[5] = (unsigned long  *)0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szFecValor;
        sqlstm.sqhstl[6] = (unsigned long )15;
        sqlstm.sqhsts[6] = (         int  )15;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqharc[6] = (unsigned long  *)0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)szFecEfectividad;
        sqlstm.sqhstl[7] = (unsigned long )15;
        sqlstm.sqhsts[7] = (         int  )15;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqharc[7] = (unsigned long  *)0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)dImpConcepto;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )sizeof(double);
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqharc[8] = (unsigned long  *)0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)szCodRegion;
        sqlstm.sqhstl[9] = (unsigned long )4;
        sqlstm.sqhsts[9] = (         int  )4;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqharc[9] = (unsigned long  *)0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)szCodProvincia;
        sqlstm.sqhstl[10] = (unsigned long )6;
        sqlstm.sqhsts[10] = (         int  )6;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqharc[10] = (unsigned long  *)0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)szCodCiudad;
        sqlstm.sqhstl[11] = (unsigned long )6;
        sqlstm.sqhsts[11] = (         int  )6;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqharc[11] = (unsigned long  *)0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)dImpMontoBase;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )sizeof(double);
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqharc[12] = (unsigned long  *)0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)iIndFactur;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[13] = (         int  )sizeof(short);
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqharc[13] = (unsigned long  *)0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)dImpFacturable;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )sizeof(double);
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqharc[14] = (unsigned long  *)0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)iIndSuperTel;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[15] = (         int  )sizeof(short);
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqharc[15] = (unsigned long  *)0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)lNumAbonado;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[16] = (         int  )sizeof(long);
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqharc[16] = (unsigned long  *)0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)iCodPortador;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[17] = (         int  )sizeof(int);
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqharc[17] = (unsigned long  *)0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)szDesConcepto;
        sqlstm.sqhstl[18] = (unsigned long )61;
        sqlstm.sqhsts[18] = (         int  )61;
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqharc[18] = (unsigned long  *)0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)lSegConsumido;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[19] = (         int  )sizeof(long);
        sqlstm.sqindv[19] = (         short *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqharc[19] = (unsigned long  *)0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)lSeqCuotas;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[20] = (         int  )sizeof(long);
        sqlstm.sqindv[20] = (         short *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqharc[20] = (unsigned long  *)0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)iNumCuotas;
        sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[21] = (         int  )sizeof(int);
        sqlstm.sqindv[21] = (         short *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqharc[21] = (unsigned long  *)0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)iOrdCuota;
        sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[22] = (         int  )sizeof(int);
        sqlstm.sqindv[22] = (         short *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqharc[22] = (unsigned long  *)0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)lNumUnidades;
        sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[23] = (         int  )sizeof(long);
        sqlstm.sqindv[23] = (         short *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqharc[23] = (unsigned long  *)0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (unsigned char  *)szNumSerieMec;
        sqlstm.sqhstl[24] = (unsigned long )26;
        sqlstm.sqhsts[24] = (         int  )26;
        sqlstm.sqindv[24] = (         short *)0;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned long )0;
        sqlstm.sqharc[24] = (unsigned long  *)0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (unsigned char  *)szNumSerieLe;
        sqlstm.sqhstl[25] = (unsigned long )26;
        sqlstm.sqhsts[25] = (         int  )26;
        sqlstm.sqindv[25] = (         short *)0;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned long )0;
        sqlstm.sqharc[25] = (unsigned long  *)0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (unsigned char  *)fPrcImpuesto;
        sqlstm.sqhstl[26] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[26] = (         int  )sizeof(float);
        sqlstm.sqindv[26] = (         short *)0;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned long )0;
        sqlstm.sqharc[26] = (unsigned long  *)0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (unsigned char  *)dValDto;
        sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[27] = (         int  )sizeof(double);
        sqlstm.sqindv[27] = (         short *)0;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned long )0;
        sqlstm.sqharc[27] = (unsigned long  *)0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (unsigned char  *)iTipDto;
        sqlstm.sqhstl[28] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[28] = (         int  )sizeof(short);
        sqlstm.sqindv[28] = (         short *)0;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned long )0;
        sqlstm.sqharc[28] = (unsigned long  *)0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (unsigned char  *)iMesGarantia;
        sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[29] = (         int  )sizeof(int);
        sqlstm.sqindv[29] = (         short *)0;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned long )0;
        sqlstm.sqharc[29] = (unsigned long  *)0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (unsigned char  *)szNumGuia;
        sqlstm.sqhstl[30] = (unsigned long )11;
        sqlstm.sqhsts[30] = (         int  )11;
        sqlstm.sqindv[30] = (         short *)0;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned long )0;
        sqlstm.sqharc[30] = (unsigned long  *)0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (unsigned char  *)iIndAlta;
        sqlstm.sqhstl[31] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[31] = (         int  )sizeof(short);
        sqlstm.sqindv[31] = (         short *)0;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned long )0;
        sqlstm.sqharc[31] = (unsigned long  *)0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (unsigned char  *)iNumPaquete;
        sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[32] = (         int  )sizeof(int);
        sqlstm.sqindv[32] = (         short *)0;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned long )0;
        sqlstm.sqharc[32] = (unsigned long  *)0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (unsigned char  *)iFlagImpues;
        sqlstm.sqhstl[33] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[33] = (         int  )sizeof(short);
        sqlstm.sqindv[33] = (         short *)0;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned long )0;
        sqlstm.sqharc[33] = (unsigned long  *)0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (unsigned char  *)iFlagDto;
        sqlstm.sqhstl[34] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[34] = (         int  )sizeof(short);
        sqlstm.sqindv[34] = (         short *)0;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned long )0;
        sqlstm.sqharc[34] = (unsigned long  *)0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
        sqlstm.sqhstv[35] = (unsigned char  *)iCodConceRel;
        sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[35] = (         int  )sizeof(int);
        sqlstm.sqindv[35] = (         short *)0;
        sqlstm.sqinds[35] = (         int  )0;
        sqlstm.sqharm[35] = (unsigned long )0;
        sqlstm.sqharc[35] = (unsigned long  *)0;
        sqlstm.sqadto[35] = (unsigned short )0;
        sqlstm.sqtdso[35] = (unsigned short )0;
        sqlstm.sqhstv[36] = (unsigned char  *)lColumnaRel;
        sqlstm.sqhstl[36] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[36] = (         int  )sizeof(long);
        sqlstm.sqindv[36] = (         short *)0;
        sqlstm.sqinds[36] = (         int  )0;
        sqlstm.sqharm[36] = (unsigned long )0;
        sqlstm.sqharc[36] = (unsigned long  *)0;
        sqlstm.sqadto[36] = (unsigned short )0;
        sqlstm.sqtdso[36] = (unsigned short )0;
        sqlstm.sqhstv[37] = (unsigned char  *)szCodPlanTarif;
        sqlstm.sqhstl[37] = (unsigned long )4;
        sqlstm.sqhsts[37] = (         int  )4;
        sqlstm.sqindv[37] = (         short *)0;
        sqlstm.sqinds[37] = (         int  )0;
        sqlstm.sqharm[37] = (unsigned long )0;
        sqlstm.sqharc[37] = (unsigned long  *)0;
        sqlstm.sqadto[37] = (unsigned short )0;
        sqlstm.sqtdso[37] = (unsigned short )0;
        sqlstm.sqhstv[38] = (unsigned char  *)szCodCargoBasico;
        sqlstm.sqhstl[38] = (unsigned long )4;
        sqlstm.sqhsts[38] = (         int  )4;
        sqlstm.sqindv[38] = (         short *)0;
        sqlstm.sqinds[38] = (         int  )0;
        sqlstm.sqharm[38] = (unsigned long )0;
        sqlstm.sqharc[38] = (unsigned long  *)0;
        sqlstm.sqadto[38] = (unsigned short )0;
        sqlstm.sqtdso[38] = (unsigned short )0;
        sqlstm.sqhstv[39] = (unsigned char  *)szTipPlanTarif;
        sqlstm.sqhstl[39] = (unsigned long )2;
        sqlstm.sqhsts[39] = (         int  )2;
        sqlstm.sqindv[39] = (         short *)0;
        sqlstm.sqinds[39] = (         int  )0;
        sqlstm.sqharm[39] = (unsigned long )0;
        sqlstm.sqharc[39] = (unsigned long  *)0;
        sqlstm.sqadto[39] = (unsigned short )0;
        sqlstm.sqtdso[39] = (unsigned short )0;
        sqlstm.sqhstv[40] = (unsigned char  *)dhMtoReal;
        sqlstm.sqhstl[40] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[40] = (         int  )sizeof(double);
        sqlstm.sqindv[40] = (         short *)0;
        sqlstm.sqinds[40] = (         int  )0;
        sqlstm.sqharm[40] = (unsigned long )0;
        sqlstm.sqharc[40] = (unsigned long  *)0;
        sqlstm.sqadto[40] = (unsigned short )0;
        sqlstm.sqtdso[40] = (unsigned short )0;
        sqlstm.sqhstv[41] = (unsigned char  *)dhMtoDcto;
        sqlstm.sqhstl[41] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[41] = (         int  )sizeof(double);
        sqlstm.sqindv[41] = (         short *)0;
        sqlstm.sqinds[41] = (         int  )0;
        sqlstm.sqharm[41] = (unsigned long )0;
        sqlstm.sqharc[41] = (unsigned long  *)0;
        sqlstm.sqadto[41] = (unsigned short )0;
        sqlstm.sqtdso[41] = (unsigned short )0;
        sqlstm.sqhstv[42] = (unsigned char  *)lhDurReal;
        sqlstm.sqhstl[42] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[42] = (         int  )sizeof(long);
        sqlstm.sqindv[42] = (         short *)0;
        sqlstm.sqinds[42] = (         int  )0;
        sqlstm.sqharm[42] = (unsigned long )0;
        sqlstm.sqharc[42] = (unsigned long  *)0;
        sqlstm.sqadto[42] = (unsigned short )0;
        sqlstm.sqtdso[42] = (unsigned short )0;
        sqlstm.sqhstv[43] = (unsigned char  *)lhDurDcto;
        sqlstm.sqhstl[43] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[43] = (         int  )sizeof(long);
        sqlstm.sqindv[43] = (         short *)0;
        sqlstm.sqinds[43] = (         int  )0;
        sqlstm.sqharm[43] = (unsigned long )0;
        sqlstm.sqharc[43] = (unsigned long  *)0;
        sqlstm.sqadto[43] = (unsigned short )0;
        sqlstm.sqtdso[43] = (unsigned short )0;
        sqlstm.sqhstv[44] = (unsigned char  *)lhCntLlamReal;
        sqlstm.sqhstl[44] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[44] = (         int  )sizeof(long);
        sqlstm.sqindv[44] = (         short *)0;
        sqlstm.sqinds[44] = (         int  )0;
        sqlstm.sqharm[44] = (unsigned long )0;
        sqlstm.sqharc[44] = (unsigned long  *)0;
        sqlstm.sqadto[44] = (unsigned short )0;
        sqlstm.sqtdso[44] = (unsigned short )0;
        sqlstm.sqhstv[45] = (unsigned char  *)lhCntLlamFact;
        sqlstm.sqhstl[45] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[45] = (         int  )sizeof(long);
        sqlstm.sqindv[45] = (         short *)0;
        sqlstm.sqinds[45] = (         int  )0;
        sqlstm.sqharm[45] = (unsigned long )0;
        sqlstm.sqharc[45] = (unsigned long  *)0;
        sqlstm.sqadto[45] = (unsigned short )0;
        sqlstm.sqtdso[45] = (unsigned short )0;
        sqlstm.sqhstv[46] = (unsigned char  *)lhCntLlamDcto;
        sqlstm.sqhstl[46] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[46] = (         int  )sizeof(long);
        sqlstm.sqindv[46] = (         short *)0;
        sqlstm.sqinds[46] = (         int  )0;
        sqlstm.sqharm[46] = (unsigned long )0;
        sqlstm.sqharc[46] = (unsigned long  *)0;
        sqlstm.sqadto[46] = (unsigned short )0;
        sqlstm.sqtdso[46] = (unsigned short )0;
        sqlstm.sqhstv[47] = (unsigned char  *)szCod_Unidad;
        sqlstm.sqhstl[47] = (unsigned long )6;
        sqlstm.sqhsts[47] = (         int  )6;
        sqlstm.sqindv[47] = (         short *)0;
        sqlstm.sqinds[47] = (         int  )0;
        sqlstm.sqharm[47] = (unsigned long )0;
        sqlstm.sqharc[47] = (unsigned long  *)0;
        sqlstm.sqadto[47] = (unsigned short )0;
        sqlstm.sqtdso[47] = (unsigned short )0;
        sqlstm.sqhstv[48] = (unsigned char  *)lhNumUniFree;
        sqlstm.sqhstl[48] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[48] = (         int  )sizeof(long);
        sqlstm.sqindv[48] = (         short *)0;
        sqlstm.sqinds[48] = (         int  )0;
        sqlstm.sqharm[48] = (unsigned long )0;
        sqlstm.sqharc[48] = (unsigned long  *)0;
        sqlstm.sqadto[48] = (unsigned short )0;
        sqlstm.sqtdso[48] = (unsigned short )0;
        sqlstm.sqhstv[49] = (unsigned char  *)ihCodOperador;
        sqlstm.sqhstl[49] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[49] = (         int  )sizeof(int);
        sqlstm.sqindv[49] = (         short *)0;
        sqlstm.sqinds[49] = (         int  )0;
        sqlstm.sqharm[49] = (unsigned long )0;
        sqlstm.sqharc[49] = (unsigned long  *)0;
        sqlstm.sqadto[49] = (unsigned short )0;
        sqlstm.sqtdso[49] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



                vDTrazasLog( szExeName,"\t\t*%s Inserte en %s, %d Registros (SQLCODE=%d)\n",LOG04,modulo, szNomTabla, sqlca.sqlerrd[2],SQLCODE);

          if (SQLCODE)
          {
              sprintf(szFuncion,"HistConc(2)=>%s(%d)",szNomTabla,SQLCODE);
              iDError (szExeName,ERR000,vInsertarIncidencia,szFuncion,szfnORAerror());
              return(FALSE);
          }



    }

    vDTrazasLog (szExeName,"\n\t\t*%s Conceptos Procesados [%d]==[%d] del Cliente [%ld]\n",LOG03,modulo,sqlca.sqlerrd[2],i,stCliente.lCodCliente);
    return(TRUE);

}/************************* Final bfnInsertHistConc *************************/

/*****************************************************************************/
/*                              funcion : vInitCadena                        */
/*****************************************************************************/
static void vfnInitCadenaInsertHistConc (char *szCadena,char *szTabla )
{
    vDTrazasLog (szExeName, "\n\t\t=> Compone Insert [%s]", LOG04, szTabla);
    sprintf (szCadena,
                "INSERT INTO %.*s "
                "(IND_ORDENTOTAL,"
                "COD_CONCEPTO   ,"
                "COLUMNA        ,"
                "COD_MONEDA     ,"
                "COD_PRODUCTO   ,"
                "COD_TIPCONCE   ,"
                "FEC_VALOR      ,"
                "FEC_EFECTIVIDAD,"
                "IMP_CONCEPTO   ,"
                "COD_REGION     ,"
                "COD_PROVINCIA  ,"
                "COD_CIUDAD     ,"
                "IMP_MONTOBASE  ,"
                "IND_FACTUR     ,"
                "IMP_FACTURABLE ,"
                "IND_SUPERTEL   ,"
                "NUM_ABONADO    ,"
                "COD_PORTADOR   ,"
                "DES_CONCEPTO   ,"
                "SEG_CONSUMIDO  ,"
                "SEQ_CUOTAS     ,"
                "NUM_CUOTAS     ,"
                "ORD_CUOTA      ,"
                "NUM_UNIDADES   ,"
                "NUM_SERIEMEC   ,"
                "NUM_SERIELE    ,"
                "PRC_IMPUESTO   ,"
                "VAL_DTO        ,"
                "TIP_DTO        ,"
                "MES_GARANTIA   ,"
                "NUM_GUIA       ,"
                "IND_ALTA       ,"
                "NUM_PAQUETE    ,"
                "FLAG_IMPUES    ,"
                "FLAG_DTO       ,"
                "COD_CONCEREL   ,"
                "COLUMNA_REL    ,"
                "COD_PLANTARIF  ,"
                "COD_CARGOBASICO,"
                "TIP_PLANTARIF  ,"
                "IMP_REAL       ,"
                "IMP_DCTO       ,"
                "DUR_REAL       ,"
                "DUR_DCTO       ,"
                "CNT_LLAM_REAL  ,"
                "CNT_LLAM_DCTO  ,"
                "CNT_LLAM_FACT  ,"
                "COD_UNIDAD     ,"
                "MIN_PLANTARIF  ,"
                "COD_OPERADOR   )"
            "VALUES( "
                "TO_NUMBER(:szIndOrdenTotal),"
                ":iCodConcepto   ,"
                ":lColumna       ,"
                ":szCodMoneda    ,"
                ":iCodProducto   ,"
                ":iCodTipConce   ,"
                "TO_DATE(:szFecValor      ,'YYYYMMDDHH24MISS'),"
                "TO_DATE(:szFecEfectividad,'YYYYMMDDHH24MISS'),"
                ":dImpConcepto   ,"
                ":szCodRegion    ,"
                ":szCodProvincia ,"
                ":szCodCiudad    ,"
                ":dImpMontoBase  ,"
                ":iIndFactur     ,"
                ":dImpFacturable ,"
                ":iIndSuperTel   ,"
                ":lNumAbonado    ,"
                ":iCodPortador   ,"
                ":szDesConcepto  ,"
                ":lSegConsumido  ,"
                ":lSeqCuotas     ,"
                ":iNumCuotas     ,"
                ":iOrdCuota      ,"
                ":iNumUnidades   ,"
                ":szNumSerieMec  ,"
                ":szNumSerieLe   ,"
                ":fPrcImpuesto   ,"
                ":dValDto        ,"
                ":iTipDto        ,"
                ":iMesGarantia   ,"
                ":szNumGuia      ,"
                ":iIndAlta       ,"
                ":iNumPaquete    ,"
                ":iFlagImpues    ,"
                ":iFlagDto       ,"
                ":iCodConceRel   ,"
                ":lColumnaRel    ,"
                ":szCodPlanTarif ,"
                ":szCodCargoBasico,"
                ":szTipPlanTarif ,"
                ":dhMtoReal      ,"
                ":dhMtoDcto      ,"
                ":lhDurReal      ,"
                ":lhDurDcto      ,"
                ":lhCntLlamReal  ,"
                ":lhCntLlamFact  ,"
                ":lhCntLlamDcto  ,"
                ":szCod_Unidad   ,"
                ":lhNumUniFree   ,"
                ":ihCodOperador  )"
             ,strlen(szTabla),szTabla);
}/******************************** Final vInitCadena *************************/


/*****************************************************************************/
/*                            funcion : bfnPasoHistConc                      */
/* -Funcion que inserta en Fa_HistConc%  todos los Conceptos Facturables a un*/
/*  Cliente ,sus Descuentos e Impuestos todos ellos guardados en la estruc-  */
/*  tura stPreFactura.                                                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnPasoHistConc ()
{
    if (stPreFactura.iNumRegistros > 0)
    {
        if (!bfnInsertHistConc())
        {
           vDTrazasLog (szExeName,"Error en inserccion en tablas de conceptos  %d\n\t",
                        LOG01,  sqlca.sqlerrd[2])       ;

           iDError (szExeName,ERR000,vInsertarIncidencia,
                    "bfnPasoHistConc Insert=>",szfnORAerror());

           return FALSE;
        }
    }
    vDTrazasLog (szExeName,
                "\t\t* Conceptos Procesados [%ld] del Cliente [%ld]",LOG03,
                stPreFactura.iNumRegistros,stCliente.lCodCliente);
   return TRUE;

}
/****************************** Final bfnPasoHistConc ***********************/

/*****************************************************************************/
/*                              funcion : vfnFreeHistAbo                     */
/*****************************************************************************/
void vfnFreeHistAbo (void)
{
  if (stHistAboCel.pAbo != (HISTABO *)NULL)
  {
      free (stHistAboCel.pAbo)            ;
      stHistAboCel.pAbo  = (HISTABO *)NULL;
  }
  stHistAboCel.iNumReg = 0;

}/***************************** vfnFreeHistAbo *******************************/



/*****************************************************************************/
/*                            funcion : bfnAddHistAboCero                    */
/*****************************************************************************/
static BOOL bfnAddHistAboCero ()
{
    long k = 0;
    long lIndiceAbon = 0;

    k = stAbonoCli.lNumAbonados;

    vDTrazasLog (szExeName,"\n\t\t* (bfnAddHistAboCero)  Valida Generacion de Abonado Cero ",LOG04);

    if (bfnCargosNivCliente(&lIndiceAbon))
    {
        vDTrazasLog (szExeName,"\t\t**(bfnAddHistAboCero)  Crea de Abonado Cero ",LOG04);
        if ((stAbonoCli.pCicloCli = (CICLOCLI *) realloc ((CICLOCLI *)stAbonoCli.pCicloCli,sizeof(CICLOCLI)*(k+1))
             ) == (CICLOCLI *)NULL )
        {
            iDError (szExeName,ERR005,vInsertarIncidencia,"stAbonoCli.pCicloCli");
                      return (FALSE);
        }
        memset(&stAbonoCli.pCicloCli [k],0,sizeof(CICLOCLI))   ;


                stAbonoCli.pCicloCli [k].iCodProducto   = stAbonoCli.pCicloCli [lIndiceAbon].iCodProducto     ;
        strcpy( stAbonoCli.pCicloCli [k].szCodPlanTarif , stAbonoCli.pCicloCli [lIndiceAbon].szCodPlanTarif  );
                stAbonoCli.pCicloCli [k].lCodCliente    = stAbonoCli.pCicloCli [lIndiceAbon].lCodCliente      ;
                stAbonoCli.pCicloCli [k].lNumAbonado    = 0                                         ;
                stAbonoCli.pCicloCli [k].iIndDetalle    = 0                                         ;
        strcpy( stAbonoCli.pCicloCli [k].szNomUsuario   , stAbonoCli.pCicloCli [lIndiceAbon].szNomUsuario    );
        strcpy( stAbonoCli.pCicloCli [k].szNomApellido1 , stAbonoCli.pCicloCli [lIndiceAbon].szNomApellido1  );
        strcpy( stAbonoCli.pCicloCli [k].szNomApellido2 , stAbonoCli.pCicloCli [lIndiceAbon].szNomApellido2  );
                stAbonoCli.pCicloCli [k].iCodCredMor    = stAbonoCli.pCicloCli [lIndiceAbon].iCodCredMor      ;
        strcpy( stAbonoCli.pCicloCli [k].szNumTerminal  , "0"                                                );
                stAbonoCli.pCicloCli [k].iIndFactur     = stAbonoCli.pCicloCli [lIndiceAbon].iIndFactur       ;
                stAbonoCli.pCicloCli [k].iIndSuperTel   = stAbonoCli.pCicloCli [lIndiceAbon].iIndSuperTel     ;
                stAbonoCli.pCicloCli [k].lCodGrupo      = stAbonoCli.pCicloCli [lIndiceAbon].lCodGrupo        ;
        strcpy( stAbonoCli.pCicloCli [k].szNumTeleFija  , stAbonoCli.pCicloCli [lIndiceAbon].szNumTeleFija   );
        strcpy( stAbonoCli.pCicloCli [k].szFecFinContra , stAbonoCli.pCicloCli [lIndiceAbon].szFecFinContra  );
        stAbonoCli.lNumAbonados++;
    }
    return (TRUE);
}


/*****************************************************************************/
/*                            funcion : bfnCargosNivCliente                    */
/*****************************************************************************/
static BOOL bfnCargosNivCliente (long *lpIndiceAbon)
{
    long i                  = 0;
    int  y                  = 0;
    int iProductoAbonCero   = 0;
    BOOL bfnCargo_A_Cliente = FALSE;
    BOOL bfnAbondoCero      = FALSE;

    vDTrazasLog (szExeName,"\t\t\t* (MVV)-(bfnCargosNivCliente)  Verifica Cargos A Nivel de Cliente"
                            "\n\t\t\t=> Cantidad de Abonados  [%d]"
                            ,LOG04
                            ,stAbonoCli.lNumAbonados);
    /************************************************************************/
    iProductoAbonCero = stAbonoCli.pCicloCli [0].iCodProducto;
    *lpIndiceAbon = 0;

    /************************************************************************/
    /*  Analiza Si Existe Abonado Cero para el Cliente                      */
    /************************************************************************/
    for(i=0;i<stAbonoCli.lNumAbonados;i++)
    {
        if (stAbonoCli.pCicloCli [i].lNumAbonado == 0 )
        {
            bfnAbondoCero = TRUE;
            *lpIndiceAbon = i;
            iProductoAbonCero = stAbonoCli.pCicloCli [i].iCodProducto;
            vDTrazasLog (szExeName, "\t\t\t* (MVV) Encuentra Abonado Cero en Posicion [%d] Producto [%d]"
                                    ,LOG04
                                    ,*lpIndiceAbon
                                    ,iProductoAbonCero);
            break;
        }
    }

    /************************************************************************/
    /*  Cliente Sin Abonado Cero y Modifica Conceptos a Abonado Cero        */
    /************************************************************************/

    for (y=0;y<stPreFactura.iNumRegistros;y++)
    {
        /************************************************************************/
        /*  Cargos a Nivel de Cliente o Abonado Cero Cambia el Producto         */
        /************************************************************************/
        if (stPreFactura.A_PFactura.lNumAbonado [y] <= 0)
        {
            stPreFactura.A_PFactura.lNumAbonado [y] = 0;
            stPreFactura.A_PFactura.iCodProducto[y] = (short)(bfnAbondoCero?stDatosGener.iProdGeneral:iProductoAbonCero);
            bfnCargo_A_Cliente = (bfnAbondoCero?FALSE:TRUE);
        }
    }
    return (bfnCargo_A_Cliente);
}



/*****************************************************************************/
/*                             funcion : iCmpOfiEmis                         */
/*****************************************************************************/
int iCmpOfiEmis (const void* cad1, const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((OFICINAEMIS *)cad1)->szCodOperadora,
                     ((OFICINAEMIS *)cad2)->szCodOperadora) ) != 0)?rc:
    ( (rc = strcmp ( ((OFICINAEMIS *)cad1)->szCodOficina,
                     ((OFICINAEMIS *)cad2)->szCodOficina)) != 0)?rc:0;
}/*************************** Final iCmpOfiEmis *****************************/

/*****************************************************************************/
/*                       funcion : bfnGetOficinaEmisora                      */
/*****************************************************************************/
static BOOL bfnGetOficinaEmisora (OFICINAEMIS *pstOficina, int iTipoFact)
{

    OFICINAEMIS stkey                    ;
    OFICINAEMIS *pL = (OFICINAEMIS *)NULL;
    int iRes = 0;

    memset (&stkey,0,sizeof(OFICINAEMIS));

    vDTrazasLog (szExeName, "\n\t\t* Parametros bfnGetOficinaEmisora\n"
                            "\t\t=> Cod.Operadora   [%d]\n"
                            "\t\t=> Cod.Oficina  [%d]\n",LOG06
                            , pstOficina->szCodOperadora, pstOficina->szCodOficina);

    if (iTipoFact == stDatosGener.iCodCiclo)
    {
        if (pstOficinasEmisoras.iNumOfiEmis > 0)
        {
            strcpy (stkey.szCodOperadora, pstOficina->szCodOperadora);
            strcpy (stkey.szCodOficina, pstOficina->szCodOficina);

            if ((pL = (OFICINAEMIS *)bsearch (&stkey,pstOficinasEmisoras.stOfiEmis,pstOficinasEmisoras.iNumOfiEmis,
                                                 sizeof(OFICINAEMIS),iCmpOfiEmis))
                      ==(OFICINAEMIS *)NULL)
            {
                iDError (szExeName,ERR021,vInsertarIncidencia,"pstOficinasEmisoras");
                return FALSE;

            }
            strcpy (pstOficina->szCodOficinaEmis, pL->szCodOficinaEmis);
            iRes = 1;
        }

        if (!iRes)
        {
            if (!bfnObtieneOficinaEmisora(pstOficina->szCodOficina, pstOficina->szCodOperadora, pstOficina->szCodOficinaEmis))
                return (FALSE);

            if ((pstOficinasEmisoras.stOfiEmis =
              (OFICINAEMIS *)realloc ( (OFICINAEMIS *)pstOficinasEmisoras.stOfiEmis,
              (pstOficinasEmisoras.iNumOfiEmis+1)*sizeof(OFICINAEMIS) ))==(OFICINAEMIS *)NULL)
            {
                iDError (szExeName,ERR005,vInsertarIncidencia,
                           "pstOficinasEmisoras.stOfiEmis");
                return  FALSE;
            }
            strcpy (pstOficinasEmisoras.stOfiEmis[pstOficinasEmisoras.iNumOfiEmis].szCodOperadora   , pstOficina->szCodOperadora);
            strcpy (pstOficinasEmisoras.stOfiEmis[pstOficinasEmisoras.iNumOfiEmis].szCodOficina     , pstOficina->szCodOficina);
            strcpy (pstOficinasEmisoras.stOfiEmis[pstOficinasEmisoras.iNumOfiEmis].szCodOficinaEmis , pstOficina->szCodOficinaEmis);
            pstOficinasEmisoras.iNumOfiEmis++;
            qsort (pstOficinasEmisoras.stOfiEmis,pstOficinasEmisoras.iNumOfiEmis,sizeof(OFICINAEMIS),iCmpOfiEmis);
        }

    }
    else
    {
        if (!bfnObtieneOficinaEmisora(pstOficina->szCodOficina, pstOficina->szCodOperadora, pstOficina->szCodOficinaEmis))
            return (FALSE);
    }
    return TRUE;
}/*********************** Final bfnGetOficinaEmisora **************************/

/*****************************************************************************/
/*                  funcion : bfnObtieneOficinaEmisora                       */
/*****************************************************************************/

BOOL bfnObtieneOficinaEmisora(char *Oficina, char *Operadora, char *OficinaRet)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char    szhCod_Oficina[3];
        char    szhCod_OficinaEmis[3];
        char    szhCod_Operadora[5];
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy(szhCod_Oficina,Oficina);
    strcpy(szhCod_Operadora, Operadora);
    strcpy(OficinaRet,"--");

     /* EXEC SQL SELECT A.COD_OFICINA
        INTO :szhCod_OficinaEmis
        FROM  GE_OPERPLAZA_TD A,
              GE_OFICINAS B   ,
              GE_DIRECCIONES C,
              GE_CIUDADES D
       WHERE A.COD_PLAZA = D.COD_PLAZA
         AND B.COD_OFICINA   = :szhCod_Oficina
         AND B.COD_DIRECCION = C.COD_DIRECCION
         AND C.COD_REGION    = D.COD_REGION
         AND C.COD_PROVINCIA = D.COD_PROVINCIA
         AND C.COD_CIUDAD    = D.COD_CIUDAD
         AND A.COD_OPERADORA_SCL =  :szhCod_Operadora ; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 50;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select A.COD_OFICINA into :b0  from GE_OPERPLAZA_TD A ,G\
E_OFICINAS B ,GE_DIRECCIONES C ,GE_CIUDADES D where ((((((A.COD_PLAZA=D.COD_PL\
AZA and B.COD_OFICINA=:b1) and B.COD_DIRECCION=C.COD_DIRECCION) and C.COD_REGI\
ON=D.COD_REGION) and C.COD_PROVINCIA=D.COD_PROVINCIA) and C.COD_CIUDAD=D.COD_C\
IUDAD) and A.COD_OPERADORA_SCL=:b2)";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1294;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)szhCod_OficinaEmis;
     sqlstm.sqhstl[0] = (unsigned long )3;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)szhCod_Oficina;
     sqlstm.sqhstl[1] = (unsigned long )3;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)szhCod_Operadora;
     sqlstm.sqhstl[2] = (unsigned long )5;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(SQLCODE != SQLOK)
    {
        vDTrazasLog(szExeName,"\n\t=>Error en la obtencion de la Oficina Emisora\n"
                              "\n\t=>szhCod_Operadora   [%s]"
                              "\n\t=>szhCod_Oficina     [%s]"
                              "\n\t=>Retorno szhCod_OficinaEmis [%s]\n"
                              ,LOG01, szhCod_Operadora, szhCod_Oficina, szhCod_OficinaEmis);
        return (FALSE);
    }
    else
    {
        strcpy(OficinaRet,szhCod_OficinaEmis);
    }

    return (TRUE);

}/********************** Final bfnObtieneOficinaEmisora *************************/


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
