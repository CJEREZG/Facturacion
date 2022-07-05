
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "./pc/checktraza.pc"
};


static unsigned long sqlctx = 13780195;


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
            void  *sqhstv[9];
   unsigned int   sqhstl[9];
            int   sqhsts[9];
            void  *sqindv[9];
            int   sqinds[9];
   unsigned int   sqharm[9];
   unsigned int   *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {10,9};

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

 static char *sq0002 = 
"select COD_PROCPREC  from FA_PROCFACTPREC where COD_PROCESO=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4130,0,0,0,
5,0,0,1,69,0,4,46,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
28,0,0,2,74,0,9,76,0,0,1,1,0,1,0,1,3,0,0,
47,0,0,2,0,0,13,90,0,0,1,0,0,1,0,2,3,0,0,
66,0,0,2,0,0,15,96,0,0,0,0,0,1,0,
81,0,0,3,92,0,4,122,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
108,0,0,4,170,0,3,164,0,0,7,7,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
151,0,0,5,71,0,2,186,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
174,0,0,6,284,0,4,215,0,0,9,2,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,1,3,0,0,1,3,0,0,
225,0,0,7,172,0,5,273,0,0,7,7,0,1,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
};


#line 1 "./pc/checktraza.pc"
/***************************************************************************/
/* Modulo donde se definen las funciones y procedimientos relacionados con */
/* el manejo de las tablas de trazas de facturacion de ciclo.              */
/*                                                                         */
/* Autor: William Sepulveda V.                                             */
/*-------------------------------------------------------------------------*/
/* Version 1 - Revision 00  ("checktraza.pc")                              */
/* Miercoles 17 de mayo del 2000.                                          */
/***************************************************************************/
#define _CHECKTRAZA_PC_

#include <stdio.h>
#include <stdlib.h>
#include "checktraza.h"


/*---------------------------------------------------------------------------*/
/* Inclusion de biblioteca para manejo de interaccion con Oracle.            */
/*---------------------------------------------------------------------------*/
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

#line 21 "./pc/checktraza.pc"

/*---------------------------------------------------------------------------*/
/* Variables globales del modulo, visibles para Oracle.                      */
/*---------------------------------------------------------------------------*/
/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 25 "./pc/checktraza.pc"

int	ihCodProcPrec[MAX_PRECEDENTES];
/* EXEC SQL END DECLARE SECTION; */ 
#line 27 "./pc/checktraza.pc"


/*---------------------------------------------------------------------------*/
/* Variables globales del modulo.                                            */
/*---------------------------------------------------------------------------*/
int	iNumProcPrec;

/*****************************************************************************/
/*  Funcion que recupera el indicador de reproceso de la tabla FA_PROCFACT.  */
/*****************************************************************************/
int	iGetIndReproceso (int iCodProceso, int *iIndReproceso)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 39 "./pc/checktraza.pc"

	int	ihCodProceso;
	int	ihIndReproceso;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 42 "./pc/checktraza.pc"


	ihCodProceso = iCodProceso;
	
	/* EXEC SQL SELECT IND_REPROCESO
	INTO :ihIndReproceso
	FROM FA_PROCFACT
	WHERE COD_PROCESO = :ihCodProceso; */ 
#line 49 "./pc/checktraza.pc"

{
#line 46 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 46 "./pc/checktraza.pc"
 sqlstm.arrsiz = 2;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 46 "./pc/checktraza.pc"
 sqlstm.stmt = "select IND_REPROCESO into :b0  from FA_PROCFACT where COD_PR\
OCESO=:b1";
#line 46 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 46 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )5;
#line 46 "./pc/checktraza.pc"
 sqlstm.selerr = (unsigned short)1;
#line 46 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 46 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihIndReproceso;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)&ihCodProceso;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
#line 46 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 46 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 46 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 46 "./pc/checktraza.pc"
}

#line 49 "./pc/checktraza.pc"

	
	if(sqlca.sqlcode == SQLOK)
	{
		*iIndReproceso = ihIndReproceso;
	}

	return(sqlca.sqlcode);
}


/*****************************************************************************/
/*  Funcion que recupera los procesos precedentes en tabla FA_PROCFACTPREC.  */
/*****************************************************************************/
int	iGetProcPrecedentes (int iCodProceso)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 65 "./pc/checktraza.pc"

	int	ihCodProceso;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 67 "./pc/checktraza.pc"

	
	ihCodProceso = iCodProceso;
	
	/* EXEC SQL DECLARE Cursor_ProcFactPrec CURSOR FOR
   SELECT COD_PROCPREC
   FROM FA_PROCFACTPREC 
   WHERE COD_PROCESO = :ihCodProceso; */ 
#line 74 "./pc/checktraza.pc"

	
	/* EXEC SQL OPEN Cursor_ProcFactPrec; */ 
#line 76 "./pc/checktraza.pc"

{
#line 76 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 76 "./pc/checktraza.pc"
 sqlstm.arrsiz = 2;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 76 "./pc/checktraza.pc"
 sqlstm.stmt = sq0002;
#line 76 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 76 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )28;
#line 76 "./pc/checktraza.pc"
 sqlstm.selerr = (unsigned short)1;
#line 76 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 76 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodProceso;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 76 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 76 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 76 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 76 "./pc/checktraza.pc"
}

#line 76 "./pc/checktraza.pc"

	
	if(sqlca.sqlcode != SQLOK)
	{
		return(sqlca.sqlcode);
	}
	
	while(1)
   {
		if(sqlca.sqlcode < SQLOK)
		{
			return(sqlca.sqlcode);
		}
		
		/* EXEC SQL FETCH Cursor_ProcFactPrec
      INTO :ihCodProcPrec; */ 
#line 91 "./pc/checktraza.pc"

{
#line 90 "./pc/checktraza.pc"
  struct sqlexd sqlstm;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqlvsn = 10;
#line 90 "./pc/checktraza.pc"
  sqlstm.arrsiz = 2;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqladtp = &sqladt;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqltdsp = &sqltds;
#line 90 "./pc/checktraza.pc"
  sqlstm.iters = (unsigned int  )30;
#line 90 "./pc/checktraza.pc"
  sqlstm.offset = (unsigned int  )47;
#line 90 "./pc/checktraza.pc"
  sqlstm.cud = sqlcud0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 90 "./pc/checktraza.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqhstv[0] = (         void  *)ihCodProcPrec;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 90 "./pc/checktraza.pc"
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
#line 90 "./pc/checktraza.pc"
  sqlstm.sqindv[0] = (         void  *)0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqharm[0] = (unsigned int  )0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqharc[0] = (unsigned int   *)0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 90 "./pc/checktraza.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 90 "./pc/checktraza.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 90 "./pc/checktraza.pc"
}

#line 91 "./pc/checktraza.pc"


		if(sqlca.sqlcode == SQLNOTFOUND) break;
	}
	
	/* EXEC SQL CLOSE Cursor_ProcFactPrec; */ 
#line 96 "./pc/checktraza.pc"

{
#line 96 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 96 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 96 "./pc/checktraza.pc"
 sqlstm.arrsiz = 2;
#line 96 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 96 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 96 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 96 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )66;
#line 96 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 96 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 96 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 96 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 96 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 96 "./pc/checktraza.pc"
}

#line 96 "./pc/checktraza.pc"

	if(sqlca.sqlcode != SQLOK)
	{
		return(sqlca.sqlcode);
	}

	iNumProcPrec = sqlca.sqlerrd[2];
	return(sqlca.sqlcode);
}


/*****************************************************************************/
/* Funcion que recupera el estado del proceso en la tabla de trazas de       */
/* facturacion (FA_TRAZAPROC).                                               */
/*****************************************************************************/
int	iGetEstadoProc (int iCodProceso, int iCodCiclFact, int *iCodEstado)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 113 "./pc/checktraza.pc"

	int	ihCodProceso;
	int	ihCodCiclFact;
	int	ihCodEstaProc;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 117 "./pc/checktraza.pc"

	
	ihCodProceso  = iCodProceso;
	ihCodCiclFact = iCodCiclFact;
	
	/* EXEC SQL SELECT COD_ESTAPROC
	INTO :ihCodEstaProc
   FROM FA_TRAZAPROC
   WHERE COD_PROCESO  = :ihCodProceso
   AND   COD_CICLFACT = :ihCodCiclFact; */ 
#line 126 "./pc/checktraza.pc"

{
#line 122 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 122 "./pc/checktraza.pc"
 sqlstm.arrsiz = 3;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 122 "./pc/checktraza.pc"
 sqlstm.stmt = "select COD_ESTAPROC into :b0  from FA_TRAZAPROC where (COD_P\
ROCESO=:b1 and COD_CICLFACT=:b2)";
#line 122 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 122 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )81;
#line 122 "./pc/checktraza.pc"
 sqlstm.selerr = (unsigned short)1;
#line 122 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 122 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodEstaProc;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)&ihCodProceso;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstv[2] = (         void  *)&ihCodCiclFact;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
#line 122 "./pc/checktraza.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqindv[2] = (         void  *)0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqharm[2] = (unsigned int  )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 122 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 122 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 122 "./pc/checktraza.pc"
}

#line 126 "./pc/checktraza.pc"

   
   if(sqlca.sqlcode != SQLOK)
   {
   	return(sqlca.sqlcode);
   }
   
   *iCodEstado  = ihCodEstaProc;
   return(sqlca.sqlcode);
}

/*****************************************************************************/
/* Funcion encargada de insertar un registro en la tabla de trazas de        */
/* facturacion de ciclo. Utiliza la estructura global stTrazaProcCheck para       */
/* obtener los valores que deben ser insertados, de manera que la            */
/* responsabilidad de llenar dicha estructura es de la aplicacion o funcion  */
/* llamante.                                                                 */
/*****************************************************************************/
int	iInsertTrazaProc ( void )
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 146 "./pc/checktraza.pc"

	int 	ihCodCiclFact;
	int	ihCodProceso;
	int	ihCodEstaProc;
	char 	szhGlsProceso[51];
	int 	ihCodCliente;
	int 	ihNumAbonado;
	int	ihNumRegistros;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 154 "./pc/checktraza.pc"

	
	ihCodCiclFact  = stTrazaProcCheck.iCodCiclFact      ;
	ihCodProceso   = stTrazaProcCheck.iCodProceso       ;
	ihCodEstaProc  = iPROC_EST_RUN                 ;
	ihCodCliente   = stTrazaProcCheck.lCodCliente       ;
	ihNumAbonado   = stTrazaProcCheck.lNumAbonado       ;
	ihNumRegistros = stTrazaProcCheck.iNumRegistros     ;
	strcpy(szhGlsProceso, stTrazaProcCheck.szGlsProceso);
	
	/* EXEC SQL INSERT INTO FA_TRAZAPROC
	(COD_CICLFACT, COD_PROCESO, COD_ESTAPROC, FEC_INICIO, GLS_PROCESO, COD_CLIENTE, NUM_ABONADO, NUM_REGISTROS) 
	VALUES (:ihCodCiclFact, :ihCodProceso, :ihCodEstaProc, sysdate, :szhGlsProceso, :ihCodCliente,
	        :ihNumAbonado, :ihNumRegistros); */ 
#line 167 "./pc/checktraza.pc"

{
#line 164 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 164 "./pc/checktraza.pc"
 sqlstm.arrsiz = 7;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 164 "./pc/checktraza.pc"
 sqlstm.stmt = "insert into FA_TRAZAPROC (COD_CICLFACT,COD_PROCESO,COD_ESTAP\
ROC,FEC_INICIO,GLS_PROCESO,COD_CLIENTE,NUM_ABONADO,NUM_REGISTROS) values (:b0,\
:b1,:b2,sysdate,:b3,:b4,:b5,:b6)";
#line 164 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 164 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )108;
#line 164 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 164 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodCiclFact;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)&ihCodProceso;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[2] = (         void  *)&ihCodEstaProc;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[2] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[2] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[3] = (         void  *)szhGlsProceso;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[3] = (unsigned int  )51;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[3] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[3] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[4] = (         void  *)&ihCodCliente;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[4] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[4] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[5] = (         void  *)&ihNumAbonado;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[5] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[5] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstv[6] = (         void  *)&ihNumRegistros;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
#line 164 "./pc/checktraza.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqindv[6] = (         void  *)0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqharm[6] = (unsigned int  )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 164 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 164 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 164 "./pc/checktraza.pc"
}

#line 167 "./pc/checktraza.pc"


   return(sqlca.sqlcode);
}


/*****************************************************************************/
/* Funcion que borra un registro de la tabla FA_TRAZAPROC.                   */
/*****************************************************************************/
int	iDeleteTrazaProc (int iCodProceso, int iCodCiclFact)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 178 "./pc/checktraza.pc"

	int	ihCodProceso;
	int	ihCodCiclFact;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 181 "./pc/checktraza.pc"

	
	ihCodProceso  = iCodProceso;
	ihCodCiclFact = iCodCiclFact;
	
	/* EXEC SQL DELETE FROM FA_TRAZAPROC
	WHERE COD_PROCESO = :ihCodProceso
	AND  COD_CICLFACT = :ihCodCiclFact; */ 
#line 188 "./pc/checktraza.pc"

{
#line 186 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 186 "./pc/checktraza.pc"
 sqlstm.arrsiz = 7;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 186 "./pc/checktraza.pc"
 sqlstm.stmt = "delete  from FA_TRAZAPROC  where (COD_PROCESO=:b0 and COD_CI\
CLFACT=:b1)";
#line 186 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 186 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )151;
#line 186 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 186 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodProceso;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)&ihCodCiclFact;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
#line 186 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 186 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 186 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 186 "./pc/checktraza.pc"
}

#line 188 "./pc/checktraza.pc"

	
	return(sqlca.sqlcode);
}


/*****************************************************************************/
/* Funcion que selecciona un registro desde la tabla FA_TRAZAPROC.           */
/*****************************************************************************/
int	iGetTrazaProc (int iCodProceso, int iCodCiclFact)
{	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 199 "./pc/checktraza.pc"

	int 	ihCodCiclFact;
	int	ihCodProceso;
	int	ihCodEstaProc;
	char 	szhFecInicio[15];
	char 	szhFecTermino[15];
	char 	szhGlsProceso[51];
	int 	ihCodCliente;
	int 	ihNumAbonado;
	int	ihNumRegistros;
	short	ihIndFecTermino;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 210 "./pc/checktraza.pc"

	
	ihCodProceso  = iCodProceso;
	ihCodCiclFact = iCodCiclFact;
	
	/* EXEC SQL SELECT COD_ESTAPROC, TO_CHAR(FEC_INICIO, 'yyyymmddhh24miss'), TO_CHAR(FEC_TERMINO, 'yyyymmddhh24miss'),  
	                NVL(GLS_PROCESO, ' '), NVL(COD_CLIENTE, 0), NVL(NUM_ABONADO, 0), NVL(NUM_REGISTROS, 0)	                
	INTO :ihCodEstaProc, :szhFecInicio, :szhFecTermino:ihIndFecTermino, :szhGlsProceso, :ihCodCliente,
	     :ihNumAbonado, :ihNumRegistros
	FROM FA_TRAZAPROC
	WHERE COD_PROCESO = :ihCodProceso
	AND  COD_CICLFACT = :ihCodCiclFact; */ 
#line 221 "./pc/checktraza.pc"

{
#line 215 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 215 "./pc/checktraza.pc"
 sqlstm.arrsiz = 9;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 215 "./pc/checktraza.pc"
 sqlstm.stmt = "select COD_ESTAPROC ,TO_CHAR(FEC_INICIO,'yyyymmddhh24miss') \
,TO_CHAR(FEC_TERMINO,'yyyymmddhh24miss') ,NVL(GLS_PROCESO,' ') ,NVL(COD_CLIENT\
E,0) ,NVL(NUM_ABONADO,0) ,NVL(NUM_REGISTROS,0) into :b0,:b1,:b2:b3,:b4,:b5,:b6\
,:b7  from FA_TRAZAPROC where (COD_PROCESO=:b8 and COD_CICLFACT=:b9)";
#line 215 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 215 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )174;
#line 215 "./pc/checktraza.pc"
 sqlstm.selerr = (unsigned short)1;
#line 215 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 215 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodEstaProc;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)szhFecInicio;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )15;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[2] = (         void  *)szhFecTermino;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[2] = (unsigned int  )15;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[2] = (         void  *)&ihIndFecTermino;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[2] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[3] = (         void  *)szhGlsProceso;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[3] = (unsigned int  )51;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[3] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[3] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[4] = (         void  *)&ihCodCliente;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[4] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[4] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[5] = (         void  *)&ihNumAbonado;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[5] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[5] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[6] = (         void  *)&ihNumRegistros;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[6] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[6] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[7] = (         void  *)&ihCodProceso;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[7] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[7] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[7] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[7] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[7] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[7] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstv[8] = (         void  *)&ihCodCiclFact;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
#line 215 "./pc/checktraza.pc"
 sqlstm.sqhsts[8] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqindv[8] = (         void  *)0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqinds[8] = (         int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqharm[8] = (unsigned int  )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqadto[8] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqtdso[8] = (unsigned short )0;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 215 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 215 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 215 "./pc/checktraza.pc"
}

#line 221 "./pc/checktraza.pc"

	     
	if(sqlca.sqlcode != SQLOK)
	{
		return(sqlca.sqlcode);
	}
	
	stTrazaProcCheck.iCodProceso  = ihCodProceso;
	stTrazaProcCheck.iCodCiclFact = ihCodCiclFact;
	stTrazaProcCheck.iCodEstaProc = ihCodEstaProc;
	strcpy(stTrazaProcCheck.szFecInicio, szhFecInicio); 
	strcpy(stTrazaProcCheck.szGlsProceso, szhGlsProceso);
	stTrazaProcCheck.lCodCliente = ihCodCliente;
	stTrazaProcCheck.lNumAbonado = ihNumAbonado;
	stTrazaProcCheck.iNumRegistros = ihNumRegistros;
	
	if(ihIndFecTermino == -1)
	{
		strcpy(stTrazaProcCheck.szFecTermino, "");
	}
	else
	{
		strcpy(stTrazaProcCheck.szFecTermino, szhFecTermino);
	}
	return(sqlca.sqlcode);
}


/*****************************************************************************/
/* Funcion que actualiza un registro en la tabla de traza de facturacion.    */
/*****************************************************************************/
int	iUpdateTrazaProc ( void )
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 254 "./pc/checktraza.pc"

	int	ihCodProceso;
	int	ihCodCiclFact;
	int	ihCodEstaProc;
	char 	szhFecTermino[15];
	char 	szhGlsProceso[51];
	int 	ihCodCliente;
	int 	ihNumAbonado;
	int	ihNumRegistros;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 263 "./pc/checktraza.pc"

	
	ihCodProceso   = stTrazaProcCheck.iCodProceso       ;
	ihCodCiclFact  = stTrazaProcCheck.iCodCiclFact      ;
	ihCodEstaProc  = stTrazaProcCheck.iCodEstaProc      ;
	ihCodCliente   = stTrazaProcCheck.lCodCliente       ;
	ihNumAbonado   = stTrazaProcCheck.lNumAbonado       ;
	ihNumRegistros = stTrazaProcCheck.iNumRegistros     ;
	strcpy(szhGlsProceso, stTrazaProcCheck.szGlsProceso);
	
	/* EXEC SQL UPDATE FA_TRAZAPROC
	SET COD_ESTAPROC = :ihCodEstaProc, FEC_TERMINO = sysdate, GLS_PROCESO = :szhGlsProceso,
	    COD_CLIENTE = :ihCodCliente, NUM_ABONADO = :ihNumAbonado, NUM_REGISTROS = :ihNumRegistros 
	WHERE COD_PROCESO = :ihCodProceso
	AND  COD_CICLFACT = :ihCodCiclFact; */ 
#line 277 "./pc/checktraza.pc"

{
#line 273 "./pc/checktraza.pc"
 struct sqlexd sqlstm;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqlvsn = 10;
#line 273 "./pc/checktraza.pc"
 sqlstm.arrsiz = 9;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqladtp = &sqladt;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqltdsp = &sqltds;
#line 273 "./pc/checktraza.pc"
 sqlstm.stmt = "update FA_TRAZAPROC  set COD_ESTAPROC=:b0,FEC_TERMINO=sysdat\
e,GLS_PROCESO=:b1,COD_CLIENTE=:b2,NUM_ABONADO=:b3,NUM_REGISTROS=:b4 where (COD\
_PROCESO=:b5 and COD_CICLFACT=:b6)";
#line 273 "./pc/checktraza.pc"
 sqlstm.iters = (unsigned int  )1;
#line 273 "./pc/checktraza.pc"
 sqlstm.offset = (unsigned int  )225;
#line 273 "./pc/checktraza.pc"
 sqlstm.cud = sqlcud0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 273 "./pc/checktraza.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCodEstaProc;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[1] = (         void  *)szhGlsProceso;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[1] = (unsigned int  )51;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[1] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[1] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[1] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[1] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[1] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[1] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[2] = (         void  *)&ihCodCliente;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[2] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[2] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[2] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[2] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[2] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[2] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[3] = (         void  *)&ihNumAbonado;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[3] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[3] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[3] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[3] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[3] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[3] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[4] = (         void  *)&ihNumRegistros;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[4] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[4] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[4] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[4] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[4] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[4] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[5] = (         void  *)&ihCodProceso;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[5] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[5] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[5] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[5] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[5] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[5] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstv[6] = (         void  *)&ihCodCiclFact;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
#line 273 "./pc/checktraza.pc"
 sqlstm.sqhsts[6] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqindv[6] = (         void  *)0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqinds[6] = (         int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqharm[6] = (unsigned int  )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqadto[6] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqtdso[6] = (unsigned short )0;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 273 "./pc/checktraza.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 273 "./pc/checktraza.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 273 "./pc/checktraza.pc"
}

#line 277 "./pc/checktraza.pc"


	return(sqlca.sqlcode);
}

/*****************************************************************************/
/* Funcion que revisa el estado de cada uno de los procesos precedentes en   */
/* la tabla de trazas de facturacion de ciclo (FA_TRAZAPROC), comparandolo   */
/* con el que deberia tener, de acuerdo a la tabla de precedentes.           */
/*****************************************************************************/
int	iValidaTrazaProc (int *iCodRetorno)
{
	int	iIndRepro = 0;
	int	iNum      = 0;
	int	iEstadoProc, iEstadoProcPrec;
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 293 "./pc/checktraza.pc"

	int	ihCodProceso;
	int	ihCodCiclFact;
	/* EXEC SQL END DECLARE SECTION; */ 
#line 296 "./pc/checktraza.pc"

	
	ihCodCiclFact = stTrazaProcCheck.iCodCiclFact;
	ihCodProceso  = stTrazaProcCheck.iCodProceso ;
	
	/*---------------------------------------------------------------------------*/
	/* Recuperacion del indicativo de reproceso desde la tabla de procesos de    */
	/* facturacion de ciclo.                                                     */
	/*---------------------------------------------------------------------------*/
	if(iGetIndReproceso(ihCodProceso, &iIndRepro) != SQLOK)
	{
		*iCodRetorno = FAIL_GETIND_REPROCESO;
		return(sqlca.sqlcode);
	}
	
	/*---------------------------------------------------------------------------*/
	/* Recuperacion de todos los procesos precedentes, es decir, los que deben   */
	/* haber terminado OK, para que se pueda ejecutar el proceso actual.         */
	/*---------------------------------------------------------------------------*/
	if(iGetProcPrecedentes(ihCodProceso) != SQLOK)
	{
		*iCodRetorno = FAIL_GETPROC_PREC;
		return(sqlca.sqlcode);
	}
	
	/*---------------------------------------------------------------------------*/
	/* Recuperacion del estado registrado en la tabla de trazas, FA_TRAZAPROC,   */
	/* para cada uno de los procesos precedentes.                                */
	/*---------------------------------------------------------------------------*/
	for(iNum=0; iNum < iNumProcPrec; iNum++)
	{	
		/*---------------------------------------------------------------------------*/
		/* Si no se recupera registro, o bien, si hay algun error Oracle en la       */
		/* recuperacion del registro, o bien, si el estado recuperado es distinto de */
		/* OK, entonces el proceso actual no puede ser ejecutado.                    */
		/*---------------------------------------------------------------------------*/
		if(iGetEstadoProc(ihCodProcPrec[iNum], ihCodCiclFact, &iEstadoProcPrec) != SQLOK)
		{
			*iCodRetorno = FAIL_GETESTADO_PROC;
			return(sqlca.sqlcode);
		}
		if(iEstadoProcPrec != iPROC_EST_OK)
		{
			*iCodRetorno = FAIL_VALIDA_ESTPROC;
			return(FAILURE);
		}
	}
	
	/*---------------------------------------------------------------------------*/
	/* Se revisa si existe registro para el proceso y ciclo actuales, en la      */
	/* tabla FA_TRAZAPROC y, en caso de existir, se evalua cual es el estado que */
	/* se indica.                                                                */
	/*---------------------------------------------------------------------------*/
	switch(iGetEstadoProc(ihCodProceso, ihCodCiclFact, &iEstadoProc))
	{
		case SQLOK:
				/*-------------------------------------------------------------------------*/
				/* Se encontro que ya hay un registro en la tabla FA_TRAZAPROC, para el    */
				/* proceso y periodo especificados. Por ello, se evalua cual es el estado  */
				/* indicado por ese registro.                                              */
				/* No se puede permitir la ejecucion del proceso si ya existe otro que se  */
				/* encuentre en curso.                                                     */
				/*-------------------------------------------------------------------------*/
				if(iEstadoProc == iPROC_EST_RUN)
				{
					*iCodRetorno = FAIL_PROC_EJECUCION;
					return(FAILURE);
				}
				/*-------------------------------------------------------------------------*/
				/* El proceso en particular no admite posibilidad de reproceso.            */
				/*-------------------------------------------------------------------------*/
				if(iIndRepro != IND_REPROCESO)
				{
					*iCodRetorno = FAIL_PROC_REPROCESO;
					return(FAILURE);
				}
				/*-------------------------------------------------------------------------*/
				/* El proceso en particular es reprocesable, por lo que se elimina el      */
				/* registro existente en la traza y se inserta uno nuevo.                  */
				/*-------------------------------------------------------------------------*/
				if(iDeleteTrazaProc(ihCodProceso, ihCodCiclFact) != SQLOK)
				{
					*iCodRetorno = FAIL_DELETE_TRAZAPROC;
					return(sqlca.sqlcode);
				}
				if(iInsertTrazaProc() != SQLOK)
				{
					*iCodRetorno = FAIL_INSERT_TRAZAPROC;
					return(sqlca.sqlcode);
				}
				*iCodRetorno = RET_OK;
				break;
				
		case SQLNOTFOUND:
				/*---------------------------------------------------------------------------*/
				/* No se encontro registro en la tabla de trazas, para el proceso actual, de */
				/* modo que se trata de la primera ejecucion. Entonces, se inserta un nuevo  */
				/* registro, con los valores contenidos en la estructura global stTrazaProcCheck. */
				/*---------------------------------------------------------------------------*/
				if(iInsertTrazaProc() != SQLOK)
				{
					*iCodRetorno = FAIL_INSERT_TRAZAPROC;
					return(sqlca.sqlcode);
				}
				*iCodRetorno = RET_OK;
				break;
				
		default:
				/*---------------------------------------------------------------------------*/
				/* Se produjo un error Oracle al intentar recuperar registros desde la tabla */
				/* FA_TRAZAPROC. El proceso debe ser cancelado.                              */
				/*---------------------------------------------------------------------------*/
				*iCodRetorno = FAIL_GETESTADO_PROC;
				return(sqlca.sqlcode);
	}
	
	return(SQLOK);
}


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

