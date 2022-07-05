
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
           char  filnam[19];
};
static const struct sqlcxp sqlfpn =
{
    18,
    "./pc/prebilling.pc"
};


static unsigned int sqlctx = 13851603;


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
   unsigned char  *sqhstv[14];
   unsigned long  sqhstl[14];
            int   sqhsts[14];
            short *sqindv[14];
            int   sqinds[14];
   unsigned long  sqharm[14];
   unsigned long  *sqharc[14];
   unsigned short  sqadto[14];
   unsigned short  sqtdso[14];
} sqlstm = {12,14};

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

 static const char *sq0002 = 
"select A.COD_CICLFACT  from FA_CICLFACT A where (exists (select 'X'  from FA\
_CICLOS B where (B.DIG_C>0 and A.COD_CICLO=B.COD_CICLO)) and A.IND_FACTURACION\
 in (1,2)) order by A.FEC_DESDECFIJOS desc             ";

 static const char *sq0006 = 
"select  /*+  index (FA_CICLOCLI UK_FA_CICLOCLI_CICLO)  +*/ ROWID ,COD_CLIENT\
E ,COD_PRODUCTO ,NUM_ABONADO ,COD_CALCLIEN ,IND_CAMBIO ,NOM_USUARIO ,NOM_APELL\
IDO1 ,NOM_APELLIDO2 ,COD_CREDMOR ,IND_DEBITO ,COD_CICLONUE ,TO_CHAR(FEC_ALTA,'\
YYYYMMDDHH24MISS') ,nvl(TO_CHAR(FEC_ULTFACT,'YYYYMMDDHH24MISS'),' ')  from FA_\
CICLOCLI where ((((COD_CICLO=:b0 and COD_CLIENTE>:b1) and COD_CLIENTE<=:b2) an\
d NUM_PROCESO=0) and IND_MASCARA=1) order by COD_CLIENTE,NUM_ABONADO asc      \
       ";

 static const char *sq0007 = 
"select  /*+  index (FA_CICLOCLI UK_FA_CICLOCLI_CICLO)  +*/ ROWID ,COD_CLIENT\
E ,COD_PRODUCTO ,NUM_ABONADO ,COD_CALCLIEN ,IND_CAMBIO ,NOM_USUARIO ,NOM_APELL\
IDO1 ,NOM_APELLIDO2 ,COD_CREDMOR ,IND_DEBITO ,COD_CICLONUE ,TO_CHAR(FEC_ALTA,'\
YYYYMMDDHH24MISS') ,nvl(TO_CHAR(FEC_ULTFACT,'YYYYMMDDHH24MISS'),' ')  from FA_\
CICLOCLI where ((COD_CICLO=:b0 and NUM_PROCESO=0) and COD_CLIENTE=:b1) order b\
y NUM_ABONADO asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,82,0,260,47,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
28,0,0,2,209,0,265,90,0,0,0,0,0,1,0,
43,0,0,2,0,0,269,100,0,0,1,0,0,1,0,2,3,0,0,
62,0,0,2,0,0,271,114,0,0,0,0,0,1,0,
77,0,0,3,90,0,261,706,0,0,2,2,0,1,0,1,5,0,0,1,3,0,0,
100,0,0,4,222,0,260,753,0,0,8,5,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,1,3,0,0,1,5,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,
147,0,0,5,230,0,260,771,0,0,8,5,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,1,3,0,0,1,5,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,
194,0,0,6,473,0,265,1367,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
221,0,0,7,418,0,265,1369,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
244,0,0,6,0,0,269,1386,0,0,14,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
315,0,0,7,0,0,269,1402,0,0,14,0,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
386,0,0,6,0,0,271,1477,0,0,0,0,0,1,0,
401,0,0,7,0,0,271,1479,0,0,0,0,0,1,0,
416,0,0,8,0,0,285,1665,0,0,0,0,0,1,0,
};


/*****************************************************************************/
/* Fichero    : prebilling.pc                                                */
/* Descripcion:                                                              */
/* Fecha      : 14-Ene-97                                                    */
/* Autor      : Javier Garcia Paredes                                        */
/*****************************************************************************/
/* 	-PGonzaleg 1-08-2002						     */
/*		Modificacion del largo del campo "Codigo de Banco"	     */
/* MLC-SAAM Inclusion TOL                                                    */
/*****************************************************************************/

#define _PREBILLING_PC_

#include "prebilling.h"

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


/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

    FAC_CLIENTES *pstCliente = NULL;
    FAC_CICLO *pstAbonado = NULL;
    FAC_PID myPid;
    BOOL MemSharedGb=FALSE;

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/


int Obtiene_Ind_Tasador(long lCodCiclF) /* SAAM-2003016 Prototipo de funci�n */
{

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static long  lhcod_ciclfact   ;
    static int   ihind_tasador    ;
    /* EXEC SQL END DECLARE SECTION  ; */ 


    lhcod_ciclfact = lCodCiclF;
    ihind_tasador  = 0        ;

    vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Busqueda de Ind_Tasador\n"
                 "\n\t\t=> Cod. Ciclo Fact   [%d]\n",LOG04,
                 lhcod_ciclfact);

    /* EXEC SQL
    SELECT  UNIQUE NVL(IND_TASADOR,0)
    INTO    :ihind_tasador
    FROM    FA_CICLFACT
    WHERE   COD_CICLFACT        = :lhcod_ciclfact; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select unique NVL(IND_TASADOR,0) into :b0  from FA_CICLFA\
CT where COD_CICLFACT=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihind_tasador;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhcod_ciclfact;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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




    if ( (SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND) )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select=>FA_CICLFACT"
        		,szfnORAerror ());
        return(0);
    }

    vDTrazasLog (szExeName,"\n\t\t* Para ciclo [%d] tiene Tasador [%d]\n",LOG04
    			, lhcod_ciclfact, ihind_tasador);

    return(ihind_tasador);
}

BOOL bCarga_FaCiclFact ()
{
   int i=0;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   int ihCiclo;
   /* EXEC SQL END DECLARE SECTION; */ 


   vDTrazasLog(szExeName, "\n\t\t*Carga de tabla FA_CICLFACT en memoria", LOG05);

   /* EXEC SQL DECLARE CurFaCiclFact CURSOR FOR
/o   SELECT COD_CICLFACT
   	 FROM FA_CICLFACT
    WHERE COD_CICLO IN (SELECT COD_CICLO FROM FA_CICLOS WHERE DIG_C > 0)
      AND IND_FACTURACION IN (1, 2)
    ORDER BY FEC_DESDECFIJOS DESC;o/
   SELECT A.COD_CICLFACT
   	 FROM FA_CICLFACT A
    WHERE EXISTS  (SELECT 'X' FROM FA_CICLOS B WHERE B.DIG_C > 0 AND A.COD_CICLO = B.COD_CICLO )
      AND A.IND_FACTURACION IN (1, 2)
    ORDER BY A.FEC_DESDECFIJOS DESC; */ 



   /* EXEC SQL OPEN CurFaCiclFact; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0002;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )28;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   while(1)
   {
      if(sqlca.sqlcode < 0)
      {
         iDError(szExeName, ERR000, vInsertarIncidencia, "Fetch->Fa_CiclFact", szfnORAerror());
         return(FALSE);
      }

      /* EXEC SQL FETCH CurFaCiclFact
      INTO :ihCiclo; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 2;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )43;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (         int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (unsigned char  *)&ihCiclo;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


      iArrCiclo[i] = ihCiclo;
      if(sqlca.sqlcode == SQLNOTFOUND) break;
      i++;
   }

   NUM_IARRCICLO = i;

   for(i=0; i<=NUM_IARRCICLO; i++)
   {
      vDTrazasLog(szExeName, "\t\tiArrCiclo[%.3d]: %d", LOG05, i, iArrCiclo[i]);
   }

   /* EXEC SQL CLOSE CurFaCiclFact; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )62;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   return(TRUE);
}
/* ------------------------------------------------------------------------- */
/* BOOL vfnManejaError                                                */
/* ------------------------------------------------------------------------- */
static void vfnManejaError(int iTipoFact, TRANSCONTADO *pstTran, VENTAS *pstVenta)
{
	
	if(stStatus.ExitApp == TRUE) /* ERROR GRAVE - SALIR DE LA APLICACION */
	{
		vfnPrintFin        ();
		vfnFinErrorCliente (iTipoFact, pstTran,pstVenta);
		vFreeModulos     ();
	}
    else /* ERROR LEVE - SKIP RECORD se asume if(stStatus.SkipRec == TRUE)*/
    {
		if (!bfnSkipBadRecord(  iTipoFact,pstTran,pstVenta))
		{
			vfnPrintFin      ();
			vfnFinErrorCliente (iTipoFact,pstTran,pstVenta);
			vFreeModulos     ();
			stStatus.ExitApp = TRUE;
		}
	}
}
/* ------------------------------------------------------------------------- */
/*                         funcion bPreBilling                               */
/*     Valores Retorno: FALSE - Error                                        */
/*                      TRUE  - Ningun Error                                 */
/* ------------------------------------------------------------------------- */
BOOL bfnPreBilling(int   iTipoFact         ,
                   long  lCodCliente       ,
                   long  lNumAbonado       ,
                   int   iCodProducto      ,
                   long  lNumAlquiler      ,
                   long  lNumEstaDia       ,
                   long  lCodCiclFact      ,
                   long  lNumProceso       ,
                   long  lNumVenta         ,
                   long  lNumTransaccion   ,
                   long  lClienteIni       ,
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
		 		/*long  lClienteFin	   )*/
		   		   long  lClienteFin	   ,
		   		   BOOL  MemSharedL	   )
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
{
	int  iInd = 0;

	BOOL bFinPro= FALSE        ;
	BOOL bRes   = TRUE         ;
	BOOL bUnico = FALSE        ;/*Indica si la Fact.Ciclo es a un Unico Cliente */
	char szFecCategoria[15]="" ;

	VENTAS       stVenta       ;
	TRANSCONTADO stTransContado;
	GABONOCLI    stGAbo        ;

	long lNumReg= 0            ;
	long lRango = 0            ;

	char szCodBco  [16]   =""   ;
	char    szHostID  [21]="";
    long    plClienteIni=0;
    long    plClienteFin=0;
    int     iIndicadorRango = 0;

	stGAbo.lNumReg = 0;

	memset (&stCliente     ,0,sizeof(CLIENTE))     ;
	memset (&stVenta       ,0,sizeof(VENTAS))      ;
	memset (&stTransContado,0,sizeof(TRANSCONTADO));
	memset (&stGAbo        ,0,sizeof(GABONOCLI));

	stCliente.lCodCliente          = lCodCliente    ;
	stCiclo.lCodCiclFact           = lCodCiclFact   ;
	stCiclo.iInd_Tasacion          = Obtiene_Ind_Tasador(lCodCiclFact); /* SAAM-20030116 Obtiene Tipo de Tasaci on */

	vDTrazasLog(szExeName, "\n******** TARIFICADOR %s **********\n\n",LOG03, ((stCiclo.iInd_Tasacion)?"TOL":"TAS") );

	stVenta.lNumVenta              = lNumVenta      ;
	stTransContado.lNumTransaccion = lNumTransaccion;
	stCliente.iIndFactur           = 1              ;

	vInitAnomProceso (&stAnomProceso);


	/* MLC-20030116 Se inicializan la carga de promociones y descuentos cuando el indicador de tasaci�n es correspondiente a TOL */
	if ( stCiclo.iInd_Tasacion==TIPO_TASA_ON_LINE )
	{
    /*
        bCarga_TOLPromociones();
        bCarga_TOLDescuentos();
        bCarga_TOLDescripciones();
     */    
	}


	/* Carga de Tablas en memoria */
	if(iTipoFact == FACT_CICLO)
	{
		
		if (!bfnCargaParamError())
		{
        	vDTrazasLog(szExeName, "Error cargando Valores de Control de Errores\n", LOG01);
        	vDTrazasError(szExeName, "Error cargando Valores de Control de Errores\n", LOG01);
        	vFreeModulos();
        	return(FALSE);
        }
		
		if (!bfnCargaFaCiclFact(iArrCiclo, &NUM_IARRCICLO))
		{
        	vDTrazasLog(szExeName, "Error cargando Tablas Generales en memoria\n", LOG01);
        	vDTrazasError(szExeName, "Error cargando Tablas Generales en memoria\n", LOG01);
        	vFreeModulos();
        	return(FALSE);
        }
	}

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

	if (MemSharedL==TRUE && iTipoFact == FACT_CICLO)
	{
		myPid.iPID=getpid();
		MemSharedGb=MemSharedL;
		if(!bCargaGeneralPreBilling_MC (iTipoFact,lNumAbonado))
		{
			vDTrazasLog   (szExeName,"Error cargando Tablas Generales en memoria\n",LOG01);
			vDTrazasError (szExeName,"Error cargando Tablas Generales en memoria\n",LOG01);
			vFreeModulos ();
			return FALSE   ;
		}
	}
	else
	{
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

		if (!bCargaGeneralPreBilling (iTipoFact,lNumAbonado))
		{
			vDTrazasLog   (szExeName,"Error cargando Tablas Generales en memoria\n",LOG01);
			vDTrazasError (szExeName,"Error cargando Tablas Generales en memoria\n",LOG01);
			vFreeModulos ();
			return FALSE   ;
		}
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
	}
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

	if (iTipoFact == FACT_BAJA        ||
        iTipoFact == FACT_LIQUIDACION ||
        iTipoFact == FACT_ROAMINGVIS  ||
        iTipoFact == FACT_RENTAPHONE  )
	{
		if (!bfnGetDatosCliente (stCliente.lCodCliente))
			return FALSE;
		if (!bfnGetBcoUniPac (stCliente.lCodCliente, szCodBco ))
			return FALSE;
        if (strcmp(szCodBco, "") != 0)
		{
			strcpy(stCliente.szIndDebito,"A");
		}
		else
		{
			strcpy(stCliente.szIndDebito,"M");
		}
	}
    
	if (iTipoFact == FACT_NOTACRED ||
        iTipoFact == FACT_NOTADEBI ||
        iTipoFact == FACT_COMPRA   ||
        iTipoFact == FACT_MISCELAN)
	{
		stProceso.lNumProceso = lNumProceso;
		if (!bfnGetProceso (&stProceso))
			return FALSE;
	}
    
	if (!bGetFecCategoria (iTipoFact,szFecCategoria))
	{
		vFreeModulos ();
		return FALSE   ;
	}
    
	if (bRes                         &&
       (iTipoFact == FACT_CONTADO    ||
        iTipoFact == FACT_BAJA       ||
        iTipoFact == FACT_LIQUIDACION||
        iTipoFact == FACT_RENTAPHONE ||
        iTipoFact == FACT_ROAMINGVIS ||
        iTipoFact == FACT_NOTACRED   ||
        iTipoFact == FACT_NOTADEBI))
	{
		if(strlen(szFecCategoria))
		{
			/* Recuperamos la secuencia fa_seq_ind_ordentotal */
			if(!bGetCatImpCliente ( stCliente.lCodCliente  ,&stCliente.iCodCatImpos,szFecCategoria,iTipoFact))
			{
				vFreeModulos ();
				return FALSE   ;
			}
		}/* fin strlen (szFecCategoria) */
		else
		{
			vDTrazasError (szExeName,"\n\t* Fecha Categoria de Cliente [%s]\n",LOG01,szFecCategoria);
			vFreeModulos ()                              ;
			return FALSE                                 ;
		}
	}/* TipoFactura */
	
	if (iTipoFact != FACT_NOTACRED &&
        iTipoFact != FACT_NOTADEBI &&
        iTipoFact != FACT_COMPRA   &&
        iTipoFact != FACT_MISCELAN)
	{
		/* Graba Proceso en Fa_Procesos */
		if(!bSetNumFactura (iTipoFact, &stTransContado, &stVenta))
		{
			bRes = FALSE;
		}
	}
	
	if (bRes)
	{
		switch(iTipoFact)
		{
			case FACT_CONTADO:
				if (!bCargaPreBillingContado(iTipoFact, stTransContado.lNumTransaccion, stVenta.lNumVenta))
				{
					vDTrazasLog (szExeName,"Error cargando Tablas Generales(Prebilling) en memoria\n",LOG02);
					bChangeIndEstadoPro (stStatus.IdPro,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_ERROR);
					vFreeModulos ();
					return FALSE   ;
				}
				bRes = bPreBillingClienteContado (stStatus.IdPro, stVenta, stTransContado,iTipoFact);
				break;
            
			case FACT_NOTACRED:
			case FACT_NOTADEBI:
				if (!bfnInitInterFact(iPROCESO_INT_FACTURACION,stStatus.IdPro,iTipoFact))
					bRes = FALSE;
				if (bRes)
				{
					bRes = bfnPreBillingClienteNotas (stStatus.IdPro,iTipoFact);
					if (bRes)
					{
						bRes = bfnGetBcoUniPac (stCliente.lCodCliente, szCodBco );
						if (bRes && strcmp(szCodBco, "") != 0)
						{
						    strcpy(stCliente.szIndDebito,"A");
						}
						else
						{
							strcpy(stCliente.szIndDebito,"M");
						}
					}
				}
             	break;
            
			case FACT_BAJA       :
			case FACT_RENTAPHONE :
			case FACT_LIQUIDACION:
			case FACT_ROAMINGVIS :
				if (!bfnGetDirecCli (stCliente.lCodCliente, TIPDIRECCION_FACTURA ))
					bRes = FALSE;
				if ( bRes && iTipoFact == FACT_BAJA )
				{
					if (!bfnGetDirecCli (stCliente.lCodCliente, iTIP_CORRESPONDENCIA))
						bRes = FALSE;
				}
				stStatus.lNumReg = 1;
				if (bRes)
				{
					bRes = bfnPreBillingClienteBajaAbo (stCliente.lCodCliente, 
														stCiclo.iCodCiclo    , 
														lNumAbonado          , 
														iCodProducto         ,
                                                        lNumAlquiler         ,
                                                        lNumEstaDia          ,
                                                        iTipoFact);
					if (bRes)
					{
						if (iTipoFact == FACT_BAJA && !bfnUpdateCicloCli (stAbonoCli, stAbonoCli.lNumAbonados, stStatus.IdPro))
						{
							stStatus.lNumRegErr = 1;
							bRes = FALSE           ;
						}
						else
						{
							stStatus.lNumRegOk = 1;
							bRes = TRUE           ;
						}
					}
				}
				break;
			case FACT_CICLO:
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
				vDTrazasLog (szExeName,"\n\t\t=> Validando ejecucion por Host",LOG03);
                if (!ifnGetHostId (szHostID))
                {
                    if (!iGetRangosHost (szHostID, stCiclo.lCodCiclFact, &plClienteIni, &plClienteFin))
                    {
                        lClienteIni = plClienteIni;
                        lClienteFin = plClienteFin;
						iIndicadorRango = 1; /* Existe rango de clientes */
                    }
                }
				
				if(MemSharedL==TRUE)
				{
					
					bUnico = TRUE;
					lRango=1;
					lNumReg=lRango;
					vInitRegCliente ();
					stCliente.lCodPlanCom = ORA_NULL;
					vDTrazasLog (szExeName,"\n\t\t=> Rango de Clientes [%ld]",LOG05, lRango);
					vfnFreeGAbonoCli (&stGAbo);
					int iSemId;
					vDTrazasLog (szExeName,"\n\t\tIntenta crear semaforo para Instancias de Facturaci�n",LOG00);
					if (!(iSemId=bfnCreaSemaforo()))
                    {
						vDTrazasLog (szExeName,"\n\t\t=> Imposible crear semaforo",LOG00);
						return FALSE;
					}
					vDTrazasLog (szExeName,"\n\t\t=>Sem�foro Creado Exitosamente:[%d]",LOG00, iSemId);

					while ((bfnProcesarClientes(&pstCliente,pstAbonados,&NUM_ABONADOS,NUM_FAC_CICLO, iSemId)) && (!stStatus.ExitApp))
					{
						ifnRangoClientes_MC (&stGAbo,lRango,stCiclo.iCodCiclo,myPid.iPID);
				        vfnPrintRangoCliente (stGAbo);

				        for (lNumReg=0; (lNumReg<stGAbo.lNumReg &&!stStatus.ExitApp);lNumReg++)
				        {
				        	stStatus.lNumReg++;
							stStatus.lCodCliActual = stGAbo.pstAbonoCli [lNumReg].pCicloCli[0].lCodCliente;
				            
				            if (!bfnInicioCiclo_MC (   szFecCategoria, iTipoFact,stGAbo.pstAbonoCli [lNumReg]))
							{
								vfnManejaError(iTipoFact,&stTransContado,&stVenta);
								if (!bUnico)
									stCliente.lCodCliente = -1;
								continue;
							}
		
							if (!bPreBillingClienteCiclo (stStatus.IdPro, iTipoFact))
							{
								
								vfnManejaError(iTipoFact,&stTransContado,&stVenta);
								if (!bUnico)
									stCliente.lCodCliente = -1;
								continue;
							}
							else
							{
								if (!bfnUpdateCicloCli (stAbonoCli,stAbonoCli.lNumAbonados,stStatus.IdPro))
								{
									vfnManejaError(iTipoFact,&stTransContado,&stVenta);
									continue;
								}

								if (!bfnFinOkCliente ())
								{
									vfnManejaError(iTipoFact,&stTransContado,&stVenta);
									continue;
								}
								stStatus.lConCliCons = 0;
								stCiclo.iDigSec++;
								if (!bUnico)
									stCliente.lCodCliente = -1;

							}
						}/*for (lNumReg=0; (lNumReg<stGAbo.lNumReg &&!stStatus.ExitApp);lNumReg++)*/
						vfnFreeGAbonoCli (&stGAbo);
					} /*while ((bfnProcesarClientes(&pstCliente,pstAbonados,&NUM_ABONADOS,NUM_FAC_CICLO)) && (bRes && !stStatus.ExitApp))*/
		
					iInd =  (bRes)?1:2; 
					if (!bActualizaIndFacCiclo (stCiclo.lCodCiclFact, iInd, szHostID, iIndicadorRango, lClienteIni, lClienteFin))
					{
						if (!bfnOraRollBack ())
						{
							iDError (szExeName,ERR000,vInsertarIncidencia,"RollBack Work Error en bActualizaIndFacCiclo" ,szfnORAerror ());
						}
						return FALSE;
					 }
					 else
					 {
						if (!bfnOraCommit ())
						{
							iDError (szExeName,ERR000,vInsertarIncidencia,"Commit Work", szfnORAerror ());
							return  (FALSE)                         ;
						}
					}
				}
				else /*if(MemSharedL==TRUE)*/
				{
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
					
					if (stCliente.lCodCliente > 0)
						bUnico = TRUE;
					lRango  = (bUnico)?1:lRANGO_CICLOCLI;
					lNumReg = lRango;
					while (bRes && !stStatus.ExitApp)
					{
						vInitRegCliente ();
						stCliente.lCodPlanCom = ORA_NULL;
						vDTrazasLog (szExeName,"\n\t\t=> Rango de Clientes [%ld]",LOG05, lRango);
						vfnFreeGAbonoCli (&stGAbo);
						switch ( ifnRangoClientes ( &stGAbo, lRango      ,
													stCliente.lCodCliente,
													stCiclo.iCodCiclo    ,
													lClienteIni          ,
													lClienteFin ) )
						{
							case SQLNOTFOUND :
								bFinPro = TRUE ;
								bRes    = FALSE;
								break          ;
							case SQLOK       :
								if (bUnico)
									bRes = FALSE ;
								bFinPro  = bUnico;
								break            ;
							default          :
								vfnPrintFin ();
								return FALSE  ;
						}
						vfnPrintRangoCliente (stGAbo);
						
						for (lNumReg=0; (lNumReg<stGAbo.lNumReg &&!stStatus.ExitApp);lNumReg++)
						{
							stStatus.lNumReg++;
							stStatus.lCodCliActual = stGAbo.pstAbonoCli [lNumReg].pCicloCli[0].lCodCliente;
							vDTrazasLog(szExeName,"\n\n\t*** stStatus.lCodCliActual:[%ld] ***\n",LOG03, stStatus.lCodCliActual);
							if (!bfnInicioCiclo (   szFecCategoria, iTipoFact, stGAbo.pstAbonoCli [lNumReg]))
							{
								vfnManejaError(iTipoFact,&stTransContado,&stVenta);
								if (!bUnico)
									stCliente.lCodCliente = -1;
								continue;
							}

							vDTrazasLog(szExeName,"\n\n\t*** stStatus.lCodCliActual 1 :[%ld] ***\n",LOG03, stStatus.lCodCliActual);
							
							
							if (!bPreBillingClienteCiclo (stStatus.IdPro, iTipoFact))
							{
								/********************************************************************************/
								/*    22-11-2000  Mauricio Villagra                                             */
								/*   Mejorar Rutina que realiza Skip de registros cuando la Gravedad del Error  */
								/*   es mayo a 1 y debe continuar procesadno el ciclo                           */
								/********************************************************************************/
								vfnManejaError(iTipoFact,&stTransContado,&stVenta);
								if (!bUnico)
									stCliente.lCodCliente = -1;
								continue;
							}
							else
							{
							vDTrazasLog(szExeName,"\n\n\t*** stStatus.lCodCliActual 2 :[%ld] ***\n",LOG03, stStatus.lCodCliActual);
								if (!bfnUpdateCicloCli (stAbonoCli, stAbonoCli.lNumAbonados, stStatus.IdPro))
								{
									vfnManejaError(iTipoFact,&stTransContado,&stVenta);
									continue;
								}
							vDTrazasLog(szExeName,"\n\n\t*** stStatus.lCodCliActual 3 :[%ld] ***\n",LOG03, stStatus.lCodCliActual);
								if (!bfnFinOkCliente ())
								{
									vfnManejaError(iTipoFact,&stTransContado,&stVenta);
									continue;
								}

								stStatus.lConCliCons = 0;
								stCiclo.iDigSec++;
								if (!bUnico)
									stCliente.lCodCliente = -1;
							}

						}/* fin for lNumReg ... */
						vfnFreeGAbonoCli (&stGAbo);
						if (bFinPro)
						{

							iInd =  (bUnico)?1:(bRes)?1:2;
							if (!bActualizaIndFacCiclo (stCiclo.lCodCiclFact, iInd, szHostID, iIndicadorRango, lClienteIni, lClienteFin))
							{
								if (!bfnOraRollBack ())
								{
									iDError (szExeName,ERR000,vInsertarIncidencia, "RollBack Work" ,szfnORAerror ());
								}
								return FALSE;
							}
							else
							{
								if (!bfnOraCommit ())
								{
									iDError (szExeName,ERR000,vInsertarIncidencia, "Commit Work", szfnORAerror ());
									return  (FALSE)                         ;
								}
							}
						}
					}/* fin While ... */
/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
				}
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
				break;
			case FACT_MISCELAN:
			case FACT_COMPRA  :
				if (!bfnInitInterFact(iPROCESO_INT_FACTURACION,stStatus.IdPro,iTipoFact))
					bRes = FALSE;
				if (bRes)
				{
					if (!bPreBillingExt (iTipoFact))
						bRes = FALSE;
					else
						bRes = TRUE ;
					if (!bfnGetBcoUniPac (stCliente.lCodCliente, szCodBco ))
						bRes = FALSE;
					if (bRes && strcmp(szCodBco, "") != 0)
					{
						strcpy(stCliente.szIndDebito,"A");
					}
					else
					{
						strcpy(stCliente.szIndDebito,"M");
					}
				}
				break;
			default :
				break;
		}/* fin switch */
	}
	/***************************************************************/
	/*         - Factura Contado         - Factura Miscelanea      */
	/*         - Factura Compra          - Factura Baja            */
	/*         - Factura Liquidacion     - Factura Renta Phone     */
	/*         - Factura Nota Credito    - Factura Nota Debito     */
	/***************************************************************/
	if (iTipoFact != FACT_CICLO)
	{
		if (!bRes)
		{
			vfnFinErrorCliente (iTipoFact, &stTransContado, &stVenta);
			vFreeModulos       ();
			return (FALSE)       ;
		}
		bChangeCodEstaProcInterfaz(stStatus.IdPro,iESTAPROC_TERMINADO_OK);
	}/* fin de if iTipoFact ... */

	bChangeIndEstadoPro (stStatus.IdPro,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_OK);
	bfnOraCommit ();

	vDTrazasLog(szExeName,"\n\n\t*** Proceso Prebilling finalizado ***\n",LOG03);
	return TRUE;
}
/**************************** Final bPrebilling *****************************/


/* -------------------------------------------------------------------------- */
/*   bSetFechaEmision (char*,char*)                                           */
/*      Valores Retorno: FALSE - Error                                        */
/*                       TRUE  - Ningun Error                                 */
/* -------------------------------------------------------------------------- */
BOOL bSetFechaEmision (long lCicloFact, char* szFecha)
{
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char*  pszhFecha   ;     /* EXEC SQL VAR pszhFecha IS STRING(15); */ 

   static long*  plhCicloFact;
   /* EXEC SQL END DECLARE SECTION; */ 


   pszhFecha    = szFecha;
   plhCicloFact = &lCicloFact;
   /* EXEC SQL UPDATE FA_CICLFACT
		   	   SET FEC_EMISION = TO_DATE(:pszhFecha,'YYYYMMDDHH24MISS')
	     	 WHERE COD_CICLFACT = :plhCicloFact; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 2;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "update FA_CICLFACT  set FEC_EMISION=TO_DATE(:b0,'YYYYMMDDH\
H24MISS') where COD_CICLFACT=:b1";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )77;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)pszhFecha;
   sqlstm.sqhstl[0] = (unsigned long )15;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)plhCicloFact;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
                "Fa_CiclFact",szfnORAerror());
       return FALSE;
   }
   vDTrazasLog (szExeName,
   "\n\t* Fecha de Emision Ciclo actualizada : '%s'\n",LOG04,szFecha);
   return TRUE;
}/*************************** Final bSetFechaEmision *************************/

/*****************************************************************************/
/*                         funcion : bGetFecEmFactNotas                      */
/*****************************************************************************/
static BOOL bGetFecEmFactNotas (PROCESO  stPro,
                                char    *szFecEmFactNota)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static long  lhCodCliente     ;
  static long  lhCodPlanCom     ;
  static char* szhFecEmFactNota ; /* EXEC SQL VAR szhFecEmFactNota IS STRING(15); */ 

  static int   ihCodTipDocNot   ;
  static int   ihCodCentrNot    ;
  static long  lhNumSecNot      ;
  static long  lhCodAgenteNot   ;
  static char* szhLetraNot      ; /* EXEC SQL VAR szhLetraNot      IS STRING(2) ; */ 

  /* EXEC SQL END DECLARE SECTION; */ 


  szhFecEmFactNota = szFecEmFactNota            ;
  ihCodTipDocNot   = stPro.iCodTipDocNot        ;
  szhLetraNot      = stPro.szLetraNot           ;
  lhCodAgenteNot   = stPro.lCodVendedorAgenteNot;
  ihCodCentrNot    = stPro.iCodCentrNot         ;
  lhNumSecNot      = stPro.lNumSecuNot          ;

  vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada a Fa_HistDocu\n"
                         "\n\t\t=> Cod.TipDocum   [%d]"
                         "\n\t\t=> Letra          [%s]"
                         "\n\t\t=> Cod.Vendedor   [%d]"
                         "\n\t\t=> Cod.CentrEmi   [%d]"
                         "\n\t\t=> Num.Secuenci   [%d]",LOG04,
                         ihCodTipDocNot, szhLetraNot, lhCodAgenteNot,
                         ihCodCentrNot , lhNumSecNot);

    /* EXEC SQL
        SELECT  TO_CHAR (FEC_EMISION,'YYYYMMDDHH24MISS'),
                COD_CLIENTE                             ,
                COD_PLANCOM
        INTO    :szhFecEmFactNota, :lhCodCliente, :lhCodPlanCom
        FROM    FA_HISTDOCU
        WHERE   COD_TIPDOCUM        = :ihCodTipDocNot
        AND     LETRA               = :szhLetraNot
        AND     COD_VENDEDOR_AGENTE = :lhCodAgenteNot
        AND     COD_CENTREMI        = :ihCodCentrNot
        AND     NUM_SECUENCI        = :lhNumSecNot; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TO_CHAR(FEC_EMISION,'YYYYMMDDHH24MISS') ,COD_CLIEN\
TE ,COD_PLANCOM into :b0,:b1,:b2  from FA_HISTDOCU where ((((COD_TIPDOCUM=:b3 \
and LETRA=:b4) and COD_VENDEDOR_AGENTE=:b5) and COD_CENTREMI=:b6) and NUM_SECU\
ENCI=:b7)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )100;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhFecEmFactNota;
    sqlstm.sqhstl[0] = (unsigned long )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodPlanCom;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipDocNot;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhLetraNot;
    sqlstm.sqhstl[4] = (unsigned long )2;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&lhCodAgenteNot;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&ihCodCentrNot;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&lhNumSecNot;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
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


    if ((SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND))
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select=>Fa_HistDocu",szfnORAerror ());
        return FALSE                                   ;
    }
    if (SQLCODE == SQLNOTFOUND)
    {
        /* EXEC SQL
            SELECT  TO_CHAR (FEC_EMISION,'YYYYMMDDHH24MISS'),
                    COD_CLIENTE                             ,
                    COD_PLANCOM
            INTO    :szhFecEmFactNota, :lhCodCliente, :lhCodPlanCom
            FROM    FA_FACTDOCU_NOCICLO
            WHERE   COD_TIPDOCUM        = :ihCodTipDocNot
            AND     LETRA               = :szhLetraNot
            AND     COD_VENDEDOR_AGENTE = :lhCodAgenteNot
            AND     COD_CENTREMI        = :ihCodCentrNot
            AND     NUM_SECUENCI        = :lhNumSecNot; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TO_CHAR(FEC_EMISION,'YYYYMMDDHH24MISS') ,COD_C\
LIENTE ,COD_PLANCOM into :b0,:b1,:b2  from FA_FACTDOCU_NOCICLO where ((((COD_T\
IPDOCUM=:b3 and LETRA=:b4) and COD_VENDEDOR_AGENTE=:b5) and COD_CENTREMI=:b6) \
and NUM_SECUENCI=:b7)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )147;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhFecEmFactNota;
        sqlstm.sqhstl[0] = (unsigned long )15;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodPlanCom;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCodTipDocNot;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhLetraNot;
        sqlstm.sqhstl[4] = (unsigned long )2;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhCodAgenteNot;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&ihCodCentrNot;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&lhNumSecNot;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
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



        if (SQLCODE != SQLOK)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_FactDocu_NoCiclo\n",szfnORAerror ());
            return FALSE;
        }

    }
    if (SQLCODE == SQLOK)
    {
        stCliente.lCodPlanCom = lhCodPlanCom;
        stCliente.lCodCliente = lhCodCliente;
    }
    return TRUE;
}/************************** Final bGetFecEmFactNotas ************************/

/*****************************************************************************/
/*                           funcion : bCargaGeneralPrebilling               */
/* -Funcion de carga de tablas en memoria, para la gestion de Prebilling en  */
/*  sus distintos casos.                                                     */
/* -Valores de Retorno : Error->FALSE, !Error->TRUE                          */
/*****************************************************************************/

BOOL bCargaGeneralPreBilling (int  iTipoFact,  long lNumAbonado)
{

	/* Carga datos en estructura para el manejo de decimales */
   	if (!bGetParamDecimales ())
        return FALSE;

	vDTrazasLog (szExeName, "\n\t* pstParamGener.iNumDecimal      [%d]"
							"\n\t* pstParamGener.szSepMilesMonto  [%s]"
							"\n\t* pstParamGener.szSepDecMontos   [%s]"
							"\n\t* pstParamGener.szSepDecOracle   [%s]"
							"\n\t* pstParamGener.iNumDecimalFact  [%d]"
							"\n\t* pstParamGener.iTipoFoliacion   [%d]"
							"\n\t* pstParamGener.iConsConcTrafico [%d]"
							"\n\t* pstParamGener.iIndZonaImpCic   [%d]"
							"\n\t* pstParamGener.iMtoMinAjuste    [%d]"
							"\n\t* pstParamGener.iZonaImpoDefec   [%d]"
						,LOG03            
						,pstParamGener.iNumDecimal
						,pstParamGener.szSepMilesMonto
						,pstParamGener.szSepDecMontos
						,pstParamGener.szSepDecOracle
						,pstParamGener.iNumDecimalFact
						,pstParamGener.iTipoFoliacion 
						,pstParamGener.iConsConcTrafico
						,pstParamGener.iIndZonaImpCic
						,pstParamGener.iMtoMinAjuste
						,pstParamGener.iZonaImpoDefec);

   	if (iTipoFact != FACT_CONTADO &&
    	iTipoFact != FACT_NOTACRED&&
       	iTipoFact != FACT_NOTADEBI&&
       	iTipoFact != FACT_MISCELAN&&
       	iTipoFact != FACT_COMPRA)
   	{
    	if (!bCargaPenalizaciones (pstPenalizaciones,&NUM_PENALIZACIONES,
                                  iTipoFact,stCliente.lCodCliente))
        	return FALSE;
   	}
   	if (iTipoFact == FACT_BAJA || iTipoFact == FACT_CICLO)
   	{
       	if (iTipoFact == FACT_BAJA)
       	{
           	if (!bCargaCargos(pstCargos,&NUM_CARGOS,iTipoFact,ORA_NULL,ORA_NULL))
                	return FALSE;
       	}
       	if (!bCargaCabCuotas (pstCabCuotas,&NUM_CABCUOTAS,
                             iTipoFact   ,stCliente.lCodCliente,lNumAbonado))
            return FALSE;
   	}
   	if (iTipoFact == FACT_CICLO      || iTipoFact == FACT_BAJA      ||
        iTipoFact == FACT_LIQUIDACION|| iTipoFact == FACT_RENTAPHONE||
        iTipoFact == FACT_ROAMINGVIS)
    {
    	if (!bCargaTaConcepFact (pstTaConcepFact,&NUM_TACONCEPFACT))
            return FALSE;
   	}
   	if (iTipoFact == FACT_CICLO)
   	{
       	
    	  if (!bCargaConceptos_mi (pstConceptos_mi,&NUM_CONCEPTOS_MI))
        	  return FALSE;
       	if (!bfnCargaRangoTabla  (pstRangoTabla,&NUM_RANGOTABLA))
            return FALSE;
        if (!bfnCargaLimCreditos (pstLimCreditos,&NUM_LIMCREDITOS))
             return FALSE;
        if (!bCargaActividades   (pstActividades,&NUM_ACTIVIDADES))
             return FALSE;
        if (!bCargaProvincias    (pstProvincias,&NUM_PROVINCIAS))
             return FALSE;
        if (!bCargaRegiones      (pstRegiones,&NUM_REGIONES))
             return FALSE;
        if (!bCargaCatImpositiva (pstCatImpositiva,&NUM_CATIMPOSITIVA))
            return FALSE;
        if (!bCargaZonaCiudad    (pstZonaCiudad, &NUM_ZONACIUDAD))
            return FALSE;
        if (!bCargaImpuestos     (pstImpuestos, &NUM_IMPUESTOS))
            return FALSE;
        if (!bCargaTipImpues     (pstTipImpues,&NUM_TIPIMPUES))
            return FALSE;
        if (!bCargaGrpSerConc    (pstGrpSerConc,&NUM_GRPSERCONC))
            return FALSE;
        if (!bCargaConversion    (pstConversion,&NUM_CONVERSION,
                                  szMenorFecDesdeCiclo(),stCiclo.szFecEmision))
             return FALSE;
        if (!bCargaDocumSucursal (pstDocumSucursal,&NUM_DOCUMSUCURSAL))
             return FALSE;
        if (!bCargaLetras        (pstLetras,     &NUM_LETRAS))
            return FALSE;
        if (!bCargaGrupoCob      (pstGrupoCob,   &NUM_GRUPOCOB))
             return FALSE;
        if (!bCargaTarifas       (pstTarifas,    &NUM_TARIFAS))
             return FALSE;
        if (!bCargaActuaServ     (pstActuaServ,  &NUM_ACTUASERV))
             return FALSE;
        if (!bCargaCuotas        (pstCuotas,     &NUM_CUOTAS,iTipoFact,ORA_NULL))
             return FALSE;
        if (!bCargaFactCarriers  (pstFactCarriers,&NUM_FACTCARRIERS))
             return FALSE;
        if (!bCargaCuadCtoPlan   (pstCuadCtoPlan,&NUM_CUADCTOPLAN))
             return FALSE;
        if (!bCargaCtoPlan       (pstCtoPlan,    &NUM_CTOPLAN))
             return FALSE;
        if (!bCargaPlanCtoPlan   (pstPlanCtoPlan,&NUM_PLANCTOPLAN))
             return FALSE;
        if (!bCargaArriendo      (pstArriendo,   &NUM_ARRIENDOS))
             return FALSE;
        if (!bCargaCargosBasico  (pstCargosBasico,&NUM_CARGOSBASICO))
             return FALSE;
        if (!bfnCargaOptimo      (pstOptimo,     &NUM_OPTIMO))
             return FALSE;
        if (!bfnCargaFeriados    (pstFeriados,   &NUM_FERIADOS))
             return FALSE;
        if (!bCargaPlanTarif     (pstPlanTarif,  &NUM_PLANTARIF))
             return FALSE;
        /* rao piloto TMM */   
        if (!bfnCargaOficinas 	 (&pstOficinas.stOficina, &pstOficinas.iNumOficinas))
             return FALSE;
        /*if (!bfnCargaFactCobr    (&pstFactCobros.stFactCobr, &pstFactCobros.iNumFactCobros))
             return FALSE;*/
        if (!bfnCargaOperServEsp (&pstOperServEspec.stOperServEspec, &pstOperServEspec.iNumOperSerEsp))
             return FALSE;
/*
		if (!bfnCargaDetPlanDesc (&pstDetPlanDescs.stDetPlanDesc, &pstDetPlanDescs.iNumRegs, stCiclo.szFecEmision))
             return FALSE;
*/
      	if (!bfnCargaDescPuntual (&pstDescPuntual.stDetCargPunt,&pstDescPuntual.iNumDetCargPunt))
          return FALSE;
    	  if (!bCargaConceptos (&pstConceptos,&NUM_CONCEPTOS))
        	  return FALSE;
       	if (NUM_CONCEPTOS == 0)
       	{
        	vDTrazasLog (szExeName,"\n\t* No Hay Conceptos a Facturar Fa_Conceptos\n",LOG03);
           	iDError (szExeName,ERR039,vInsertarIncidencia);
           	return FALSE;
       	}

   }
	return TRUE;
}/*************************** Final bCargaGeneralPrebilling ******************/

/*****************************************************************************/
/*                   funcion :bCargaPreBillingContado                         */
/* -Funcion de carga tablas en memoria considerando los distintos casos a    */
/*  partir del Tipo de Facturacion ie: PVENTA,CONTADO,CICLO,...              */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
BOOL bCargaPreBillingContado(int iTipoFact,long lNumTransaccion,long lNumVenta)
{
  if (!bCargaCargos(pstCargos,&NUM_CARGOS,iTipoFact,lNumTransaccion,lNumVenta))
       return FALSE;
  else
       return TRUE;
}/************************ Final bCargaPrebillingContado *********************/


/*****************************************************************************/
/*                      funcion : bGetFecCategoria                           */
/* -Funcion devuelve la Fecha con la que se halla la Categoria Impositiva del*/
/*  Cliente.                                                                 */
/* -Valores Retorno :Error->FALSE,!Error->TRUE                               */
/*****************************************************************************/
static BOOL bGetFecCategoria (int iTipoFact,
                              char *szFecCat)
{
  BOOL bRes = TRUE;

  switch (iTipoFact)
  {
      case FACT_CONTADO:
           strcpy (szFecCat, szSysDate);
           break;
      case FACT_CICLO:
           strcpy (szFecCat, stCiclo.szFecEmision);
           strcpy (szFecCat, szSysDate);
           break;
      case FACT_BAJA       :
      case FACT_LIQUIDACION:
      case FACT_RENTAPHONE :
      case FACT_ROAMINGVIS :
           strcpy (szFecCat, szSysDate);
           break;
      case FACT_NOTACRED:
      case FACT_NOTADEBI:
            if (!bGetFecEmFactNotas (stProceso,szFecCat))
                 bRes = FALSE;
            break;
      default:
            break;

  }
  return bRes;
}/********************** Final bGetFecCategoria ******************************/

/*****************************************************************************/
/*                       funcion : bGestionLog                               */
/* -Funcion que gestiona los ficheros de trazas, configurable su tamano me-  */
/*  diante el parametro stStatus.iSizeFileLog (medida en k's)                */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bGestionLog (void)
{
  struct stat stbuf;

  if ( stat (stStatus.LogName,&stbuf) == -1)
  {
      iDError (szExeName,ERR026,vInsertarIncidencia,stStatus.LogName);
      return FALSE;
  }
  if (stbuf.st_size > stStatus.iSizeFileLog*1024)
  {
      if (!bCloseLog ())
           return FALSE;
      vEligeDirLogs (stStatus.LogName,stStatus.ErrName,FACT_CICLO);
      if (!bOpenLog (stStatus.LogName))
           return FALSE;
      vDTrazasLog (szExeName,
      "\n    *****************************************************************"
      "*****"\
      "\n    *                           PREBILLING                           "
      "    *"\
      "\n    *****************************************************************"
      "*****",LOG03);

  }
  return TRUE;

}/********************** Final bGestionLog ***********************************/

/*****************************************************************************/
/*                        funcion : vFreeAbonoCli                            */
/* -Funcion que libera la memoria stAbonoCli                                 */
/*****************************************************************************/
static void vfnFreeAbonoCli (ABONOCLI *pstAbonoCli)
{
  if (pstAbonoCli->pCicloCli != (CICLOCLI *)NULL)
  {
      free (pstAbonoCli->pCicloCli);
      pstAbonoCli->pCicloCli = (CICLOCLI *)NULL;
  }
  pstAbonoCli->lNumAbonados = 0;
}/**************************** Final vFreeAbonoCli ***************************/


/*****************************************************************************/
/*                      funcion : vfnFreeGAbonoCli                           */
/*****************************************************************************/
static void vfnFreeGAbonoCli (GABONOCLI *pstGAbo)
{
  long l = 0;
  for (l=pstGAbo->lNumReg-1;l>=0;l--)
  {
       vfnFreeAbonoCli (&pstGAbo->pstAbonoCli [l]);
  }
  if (pstGAbo->pstAbonoCli != (ABONOCLI *)NULL)
  {
      free (pstGAbo->pstAbonoCli);
      pstGAbo->pstAbonoCli = (ABONOCLI *)NULL;
  }
  pstGAbo->lNumReg = 0;
}/*************************** Final vfnFreeGAbonoCli *************************/


/* -------------------------------------------------------------------------- */
/*   vFreeModulos (void)                                                      */
/* -------------------------------------------------------------------------- */
void vFreeModulos (void)
{

  /**** TARIFICACION ****/
  vfnFreeTarificacion();

  /**** SAC          ****/
  vFreeSac ()          ;

  /**** SERVICIOS    ****/
  vFreeServicios()     ;

  /**** ABONOS       ****/
  vFreeAbonos()        ;

  /**** CARGOS       ****/
  vFreeCargos ()       ;

  /**** CUOTAS       ****/
  vfnFreeCuotas ()     ;

  vFreeMaxColPreFa ()  ;

  vFreeFactCli ()      ;

  vfnFreeAbonoCli (&stAbonoCli);

  /**** RENT PHONE   ****/
  vfnFreeAboRent ()    ;

  /**** COMPOSICION  ****/
  vfnFreeHistAbo ()    ;

  memset (&stCliente,0,sizeof(CLIENTE));

}/*************************** Final vFreeModulos *****************************/


/*****************************************************************************/
/*                         funcion : vInitRegCliente                         */
/* -Funcion que inicializa la estructura stPreFactura para cada Cliente,esta */
/*  estructura va a contener todos los conceptos facturables de un cliente,  */
/*  que seran insertados en Fa_PreFactura.                                   */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static void vInitRegCliente (void)
{
   int i = 0;

   for (i=0;i<MAX_CONCFACTUR;i++)
   {
        stPreFactura.A_PFactura.lNumProceso   [i] = ORA_NULL;
        stPreFactura.A_PFactura.lCodCliente   [i] = ORA_NULL;
        stPreFactura.A_PFactura.iCodConcepto  [i] = ORA_NULL;
        stPreFactura.A_PFactura.lColumna      [i] = ORA_NULL;
        stPreFactura.A_PFactura.iCodProducto  [i] = ORA_NULL;

        stPreFactura.A_PFactura.szCodMoneda     [i][0] = 0;
        stPreFactura.A_PFactura.szFecValor      [i][0] = 0;
        stPreFactura.A_PFactura.szFecEfectividad[i][0] = 0;

        stPreFactura.A_PFactura.dImpConcepto  [i] = 0.0;
        stPreFactura.A_PFactura.dImpMontoBase [i] = 0.0;
        stPreFactura.A_PFactura.dImpFacturable[i] = 0.0;
        stPreFactura.A_PFactura.lSegConsumido [i] = 0  ;

        stPreFactura.A_PFactura.szCodRegion   [i][0] = 0;
        stPreFactura.A_PFactura.szCodProvincia[i][0] = 0;
        stPreFactura.A_PFactura.szCodCiudad   [i][0] = 0;
        stPreFactura.A_PFactura.szCodModulo   [i][0] = 0;

        stPreFactura.A_PFactura.lCodPlanCom  [i]  = ORA_NULL;
        stPreFactura.A_PFactura.iCodCatImpos [i]  = ORA_NULL;
        stPreFactura.A_PFactura.iCodPortador [i]  = 0       ;
        stPreFactura.A_PFactura.iIndFactur   [i]  = ORA_NULL;
        stPreFactura.A_PFactura.lNumUnidades [i]  = ORA_NULL;
        stPreFactura.A_PFactura.iIndEstado   [i]  = ORA_NULL;
        stPreFactura.A_PFactura.iCodTipConce [i]  = ORA_NULL;
        stPreFactura.A_PFactura.lCodCiclFact [i]  = ORA_NULL;
        stPreFactura.A_PFactura.iCodConceRel [i]  = ORA_NULL;
        stPreFactura.A_PFactura.lColumnaRel  [i]  = ORA_NULL;
        stPreFactura.A_PFactura.lNumAbonado  [i]  = ORA_NULL;

        stPreFactura.A_PFactura.szNumTerminal[i][0] = 0       ;
        stPreFactura.A_PFactura.lCapCode     [i]    = ORA_NULL;
        stPreFactura.A_PFactura.szNumSerieMec[i][0] = 0       ;
        stPreFactura.A_PFactura.szNumSerieLe [i][0] = 0       ;
        stPreFactura.A_PFactura.szNumGuia    [i][0] = 0       ;
        stPreFactura.A_PFactura.iIndFactur   [i]    = 1       ;

        stPreFactura.A_PFactura.iFlagImpues    [i]= 0       ;
        stPreFactura.A_PFactura.iFlagDto       [i]= 0       ;
        stPreFactura.A_PFactura.fPrcImpuesto   [i]= 0.0     ;
        stPreFactura.A_PFactura.dValDto        [i]= 0.0     ;
        stPreFactura.A_PFactura.iTipDto        [i]= ORA_NULL;
        stPreFactura.A_PFactura.lNumVenta      [i]= ORA_NULL;
        stPreFactura.A_PFactura.lNumTransaccion[i]= ORA_NULL;
        stPreFactura.A_PFactura.iMesGarantia   [i]= ORA_NULL;
        stPreFactura.A_PFactura.iIndAlta       [i]= ORA_NULL;
        stPreFactura.A_PFactura.iIndSuperTel   [i]= ORA_NULL;
        stPreFactura.A_PFactura.iNumPaquete    [i]= ORA_NULL;
        stPreFactura.A_PFactura.iIndCuota      [i]= ORA_NULL;
        stPreFactura.A_PFactura.lSeqCuotas     [i]= ORA_NULL;
        stPreFactura.A_PFactura.iNumCuotas     [i]= ORA_NULL;
        stPreFactura.A_PFactura.iOrdCuota      [i]= ORA_NULL;
        stPreFactura.A_PFactura.lNumCargo      [i]= ORA_NULL;

        strcpy (stPreFactura.A_PFactura.szCodCuota[i],"");

        stPreFactura.A_PFactura.bOptPenaliza [i]= FALSE;
        stPreFactura.A_PFactura.bOptCargos   [i]= FALSE;
        stPreFactura.A_PFactura.bOptServicios[i]= FALSE;
        stPreFactura.A_PFactura.bOptAbonos   [i]= FALSE;
        stPreFactura.A_PFactura.bOptTrafico  [i]= FALSE;
        stPreFactura.A_PFactura.bOptCuotas   [i]= FALSE;
        stPreFactura.A_PFactura.bOptDescuento[i]= FALSE;
        stPreFactura.A_PFactura.bOptImpuesto [i]= FALSE;

        stPreFactura.A_PFactura.szFecVenta      [i][0] = 0;
        stPreFactura.A_PFactura.szCodPlanTarif  [i][0] = 0;
        stPreFactura.A_PFactura.szCodCargoBasico[i][0] = 0;
        stPreFactura.A_PFactura.szTipPlanTarif  [i][0] = 0;

        stPreFactura.A_PFactura.bOptArriendo [i]= FALSE;
        
        stPreFactura.A_PFactura.szCodRegi  [i][0] = 0;

        stPreFactura.A_PFactura.lhCodGrupo         [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhCodCliente       [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhCodCiclFact      [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhNumProceso       [i]= ORA_NULL;

    	stPreFactura.A_PFactura.szIndExcedente  [i][0] = 0;
        stPreFactura.A_PFactura.szCodPlan       [i][0] = 0;
        stPreFactura.A_PFactura.szIndBillete    [i][0] = 0;
        stPreFactura.A_PFactura.szTipDcto       [i][0] = 0;
        stPreFactura.A_PFactura.szCodDcto       [i][0] = 0;
        stPreFactura.A_PFactura.szCodItem       [i][0] = 0;
        stPreFactura.A_PFactura.szIndUnidad     [i][0] = 0;

        stPreFactura.A_PFactura.dhCntAux        [i]= 0.0     ;
        stPreFactura.A_PFactura.dhMtoReal       [i]= 0.0     ;
        stPreFactura.A_PFactura.dhMtoDcto       [i]= 0.0     ;
        stPreFactura.A_PFactura.lhDurReal       [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhDurDcto       [i]= ORA_NULL;

        stPreFactura.A_PFactura.szDesPlan       [i][0] = 0;

        stPreFactura.A_PFactura.lhCntLlamReal       [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhCntLlamFact       [i]= ORA_NULL;
        stPreFactura.A_PFactura.lhCntLlamDcto       [i]= ORA_NULL;

        stPreFactura.A_PFactura.szCod_Unidad       [i][0] = 0;
        stPreFactura.A_PFactura.lhNumUniFree        [i]= ORA_NULL;
        stPreFactura.A_PFactura.ihCodOperador		[i]= ORA_NULL;
   }
   stPreFactura.iNumRegistros = 0;
}/****************************** vInitRegCliente *****************************/

/*****************************************************************************/
/*                           funcion : szMenorFecDesdeCiclo                  */
/* -Funcion que devuelve la menor de las Fechas Desde del Fa_CiclFact        */
/*****************************************************************************/
static char *szMenorFecDesdeCiclo (void)
{
  char szFecMenor [15] = "";

  strcpy (szFecMenor,stCiclo.szFecDesdeLlam);

  if (strcmp (szFecMenor,stCiclo.szFecDesdeCFijos)  <= 0)
      strcpy (szFecMenor,stCiclo.szFecDesdeCFijos);
  if (strcmp (szFecMenor,stCiclo.szFecDesdeOCargos) <= 0)
      strcpy (szFecMenor,stCiclo.szFecDesdeOCargos);
  if (strcmp (szFecMenor,stCiclo.szFecDesdeRoa)     <= 0)
      strcpy (szFecMenor,stCiclo.szFecDesdeRoa);

  return (char *)szFecMenor;
}/************************** Final szMenorFecDesdeCiclo **********************/

/*****************************************************************************/
/*                          funcion : iRangosClientes                        */
/* - Esta funcion carga los clientes y sus respectivos abonados por rangos,  */
/*   segun parametro. El fin es no penalizar el segmento de RollBack donde   */
/*   se carga la salida del cursor, que posteriormente se updatea, con el    */
/*   consiguiente referesco del espacio de RollBack, y por lo tanto, penali- */
/*   za la ejecucion del cursor.                                             */
/*****************************************************************************/
static int ifnRangoClientes (GABONOCLI *pstGAbo    ,
                             long       lNumReg    ,
                             long       lCodCliente,
                             int        iCodCiclo  ,
                             long       lClienteIni,
                             long       lClienteFin )
{
	int    iRes = 0      ;
	
	static CICLOCLI stAux;
	
	static short i_shNomApellido2;
	static short i_shCodCredMor  ;
	static short i_shIndDebito   ;
	static short i_shCodCicloNue ;
	
	char szFecDesde [15] = "";
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	    static int  ihCodCiclo  ;
	    static long lhCodCliente;
	    static long lhClienteIni;
	    static long lhClienteFin;
	    static long lhNumReg    ;
	    /* EXEC SQL VAR stAux.szRowid        IS STRING (19); */ 

	    /* EXEC SQL VAR stAux.szNomUsuario   IS STRING (21); */ 

	    /* EXEC SQL VAR stAux.szNomApellido1 IS STRING (21); */ 

	    /* EXEC SQL VAR stAux.szNomApellido2 IS STRING (21); */ 

	    /* EXEC SQL VAR stAux.szCodCalClien  IS STRING (3) ; */ 

	    /* EXEC SQL VAR stAux.szIndDebito    IS STRING (2) ; */ 

	    /* EXEC SQL VAR stAux.szFecAlta      IS STRING (15); */ 

	    /* EXEC SQL VAR stAux.szFecUltFact   IS STRING (15); */ 

	/* EXEC SQL END DECLARE SECTION  ; */ 

	
	long l1, l2      = 0    ;
	long lAuxCliente = 0    ;
	long lNumAbonados= 0    ;
	
	ihCodCiclo   = iCodCiclo  ;
	lhCodCliente = lCodCliente;
	lhNumReg     = lNumReg    ;
	lhClienteIni = lClienteIni;
	lhClienteFin = lClienteFin;
	
	if (lCodCliente <= 0)
	{
	     /* EXEC SQL DECLARE Cur_Ciclo CURSOR FOR
	     SELECT /o+ index (FA_CICLOCLI UK_FA_CICLOCLI_CICLO) o/
	            ROWID        ,
	            COD_CLIENTE  ,
	            COD_PRODUCTO ,
	            NUM_ABONADO  ,
	            COD_CALCLIEN ,
	            IND_CAMBIO   ,
	            NOM_USUARIO  ,
	            NOM_APELLIDO1,
	            NOM_APELLIDO2,
	            COD_CREDMOR  ,
	            IND_DEBITO   ,
	            COD_CICLONUE ,
	            TO_CHAR (FEC_ALTA, 'YYYYMMDDHH24MISS'),
	            nvl(TO_CHAR (FEC_ULTFACT, 'YYYYMMDDHH24MISS'), ' ')
	       FROM FA_CICLOCLI
	      WHERE COD_CICLO    = :ihCodCiclo
	        AND COD_CLIENTE >  :lhClienteIni
	        AND COD_CLIENTE <= :lhClienteFin
	        AND NUM_PROCESO  = 0
	    	AND IND_MASCARA  = 1
	    	ORDER BY COD_CLIENTE,NUM_ABONADO ASC; */ 
/*86701 CJG*/
	     /*ORDER BY COD_CLIENTE;86701 CJG*/
	}
	else
	{
	     /* EXEC SQL DECLARE Cur_CicloUnico CURSOR FOR
	     SELECT /o+ index (FA_CICLOCLI UK_FA_CICLOCLI_CICLO) o/
	            ROWID        ,
	            COD_CLIENTE  ,
	            COD_PRODUCTO ,
	            NUM_ABONADO  ,
	            COD_CALCLIEN ,
	            IND_CAMBIO   ,
	            NOM_USUARIO  ,
	            NOM_APELLIDO1,
	            NOM_APELLIDO2,
	            COD_CREDMOR  ,
	            IND_DEBITO   ,
	            COD_CICLONUE ,
	            TO_CHAR (FEC_ALTA, 'YYYYMMDDHH24MISS'),
	            nvl(TO_CHAR (FEC_ULTFACT, 'YYYYMMDDHH24MISS'), ' ')
	       FROM FA_CICLOCLI
	      WHERE COD_CICLO   = :ihCodCiclo
	        AND NUM_PROCESO = 0
	        AND COD_CLIENTE = :lhCodCliente
	        ORDER BY NUM_ABONADO ASC; */ 
/*86701 CJG*/
	}
	vDTrazasLog (szExeName, "\n\t\t=> Clientes a Facturar "
	                        "\n\t\t=> Ciclo       [%d] "
	                        "\n\t\t=> Cod.Cliente [%ld]"
	                        "\n\t\t=> Rangos      [%ld]"
	                        "\n\t\t=> Cliente Ini.[%ld]"
	                        "\n\t\t=> Cliente Fin.[%ld]"
	                        "\n\t\t=> Fecha Inicio del Periodo [%s]"
	                        "\n\t\t=> Fecha Final  del Periodo [%s]", LOG05,
	                        ihCodCiclo  , lhCodCliente, lhNumReg,
	                        lhClienteIni, lhClienteFin,
	                        stCiclo.szFecDesdeLlam,
	                        stCiclo.szFecHastaLlam );
	
	if (lCodCliente == -1)
	    /* EXEC SQL OPEN Cur_Ciclo   ; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 8;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0006;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )194;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&ihCodCiclo;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&lhClienteIni;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&lhClienteFin;
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


	else
	    /* EXEC SQL OPEN Cur_CicloUnico; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 8;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0007;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )221;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&ihCodCiclo;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCliente;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
	    iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Fa_CicloCli",
	             szfnORAerror ());
	    return  (SQLCODE)        ;
	}
	
	strcpy (szFecDesde, szMenorFecDesdeCiclo ());
	
	while (SQLCODE == SQLOK)
	{
	       memset (&stAux, 0, sizeof (CICLOCLI));
	
	       if (lCodCliente == -1)
	           /* EXEC SQL FETCH Cur_Ciclo
	                INTO :stAux.szRowid                         ,
	                     :stAux.lCodCliente                     ,
	                     :stAux.iCodProducto                    ,
	                     :stAux.lNumAbonado                     ,
	                     :stAux.szCodCalClien                   ,
	                     :stAux.iIndCambio                      ,
	                     :stAux.szNomUsuario                    ,
	                     :stAux.szNomApellido1                  ,
	                     :stAux.szNomApellido2 :i_shNomApellido2,
	                     :stAux.iCodCredMor    :i_shCodCredMor  ,
	                     :stAux.szIndDebito    :i_shIndDebito   ,
	                     :stAux.iCodCicloNue   :i_shCodCicloNue ,
	                     :stAux.szFecAlta,
	                     :stAux.szFecUltFact; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )244;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)(stAux.szRowid);
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&(stAux.lCodCliente);
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&(stAux.iCodProducto);
            sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&(stAux.lNumAbonado);
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)(stAux.szCodCalClien);
            sqlstm.sqhstl[4] = (unsigned long )3;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&(stAux.iIndCambio);
            sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)(stAux.szNomUsuario);
            sqlstm.sqhstl[6] = (unsigned long )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)(stAux.szNomApellido1);
            sqlstm.sqhstl[7] = (unsigned long )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)(stAux.szNomApellido2);
            sqlstm.sqhstl[8] = (unsigned long )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&i_shNomApellido2;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&(stAux.iCodCredMor);
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)&i_shCodCredMor;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)(stAux.szIndDebito);
            sqlstm.sqhstl[10] = (unsigned long )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)&i_shIndDebito;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)&(stAux.iCodCicloNue);
            sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         short *)&i_shCodCicloNue;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)(stAux.szFecAlta);
            sqlstm.sqhstl[12] = (unsigned long )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)(stAux.szFecUltFact);
            sqlstm.sqhstl[13] = (unsigned long )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         short *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
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


	        else
	           /* EXEC SQL FETCH Cur_CicloUnico
	                INTO :stAux.szRowid                         ,
	                     :stAux.lCodCliente                     ,
	                     :stAux.iCodProducto                    ,
	                     :stAux.lNumAbonado                     ,
	                     :stAux.szCodCalClien                   ,
	                     :stAux.iIndCambio                      ,
	                     :stAux.szNomUsuario                    ,
	                     :stAux.szNomApellido1                  ,
	                     :stAux.szNomApellido2 :i_shNomApellido2,
	                     :stAux.iCodCredMor    :i_shCodCredMor  ,
	                     :stAux.szIndDebito    :i_shIndDebito   ,
	                     :stAux.iCodCicloNue   :i_shCodCicloNue ,
	                     :stAux.szFecAlta,
	                     :stAux.szFecUltFact; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 14;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )315;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)(stAux.szRowid);
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&(stAux.lCodCliente);
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&(stAux.iCodProducto);
            sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&(stAux.lNumAbonado);
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)(stAux.szCodCalClien);
            sqlstm.sqhstl[4] = (unsigned long )3;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&(stAux.iIndCambio);
            sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)(stAux.szNomUsuario);
            sqlstm.sqhstl[6] = (unsigned long )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)(stAux.szNomApellido1);
            sqlstm.sqhstl[7] = (unsigned long )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)(stAux.szNomApellido2);
            sqlstm.sqhstl[8] = (unsigned long )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&i_shNomApellido2;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&(stAux.iCodCredMor);
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)&i_shCodCredMor;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)(stAux.szIndDebito);
            sqlstm.sqhstl[10] = (unsigned long )2;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)&i_shIndDebito;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)&(stAux.iCodCicloNue);
            sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         short *)&i_shCodCicloNue;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned long )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (unsigned char  *)(stAux.szFecAlta);
            sqlstm.sqhstl[12] = (unsigned long )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         short *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned long )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (unsigned char  *)(stAux.szFecUltFact);
            sqlstm.sqhstl[13] = (unsigned long )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         short *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned long )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
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


	
	      switch (SQLCODE)
	      {
	          case SQLOK      :
	
	          if (strcmp (stAux.szFecAlta, stCiclo.szFecHastaLlam) <= 0)
	          {
	            lNumAbonados++;
	            if (lAuxCliente != stAux.lCodCliente)
	            {
	
	               lAuxCliente = stAux.lCodCliente;
	
	               if ( (pstGAbo->pstAbonoCli =
	                    (ABONOCLI*)realloc((ABONOCLI *)pstGAbo->pstAbonoCli,
	                     (int)sizeof (GABONOCLI)*(pstGAbo->lNumReg+1)))
	                                          ==(ABONOCLI *)NULL)
	               {
	                     iDError (szExeName,ERR005,vInsertarIncidencia,
	                              "pstGAbo->pstAbonoCli");
	                     return  (-1)                    ;
	               }
	               memset (&pstGAbo->pstAbonoCli [pstGAbo->lNumReg], 0,
	                        sizeof (ABONOCLI));
	
	               pstGAbo->lNumReg++         ;
	            }
	            if (lAuxCliente == stAux.lCodCliente)
	            {
	
	                l1 = pstGAbo->lNumReg - 1                  ;
	                l2 = pstGAbo->pstAbonoCli [l1].lNumAbonados;
	
	                if ( (pstGAbo->pstAbonoCli[l1].pCicloCli = (CICLOCLI *)
	                   realloc((CICLOCLI*)pstGAbo->pstAbonoCli[l1].pCicloCli,
	                   (int)(l2 + 1) * sizeof (CICLOCLI))) == (CICLOCLI *)NULL)
	                {
	                    iDError (szExeName,ERR005,vInsertarIncidencia,
	                             "pstGAbo->pstAbonoCli[%ld].pCicloCli[%ld]",
	                             l1, l2);
	                    return  (-1)    ;
	                }
	                memcpy (&pstGAbo->pstAbonoCli [l1].pCicloCli [l2],
	                        &stAux, sizeof (CICLOCLI))      ;
	                pstGAbo->pstAbonoCli [l1].lNumAbonados++;
	            }
	          }
	          break;
	          case SQLNOTFOUND:
	               iRes = SQLNOTFOUND;
	               break;
	          default         :
	               iDError (szExeName,ERR000,vInsertarIncidencia,
	                        "Fetch=>Fa_CicloCli ",szfnORAerror ());
	               return  (SQLCODE)                             ;
	
	     }/* fin switch */
	
	}/* fin while ... */
	if (lCodCliente == -1)
	    /* EXEC SQL CLOSE Cur_Ciclo; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )386;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	else
	    /* EXEC SQL CLOSE Cur_CicloUnico; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 14;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )401;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	
	if (SQLCODE)
	{
	    iDError (szExeName,ERR000,vInsertarIncidencia,"Close=>Fa_CicloCli",
	             szfnORAerror ());
	    return  (SQLCODE)        ;
	}
	
	vDTrazasLog (szExeName,"\n\t\t=> Clientes Cargados [%ld]", LOG05,
	                       pstGAbo->lNumReg);
	
	return (iRes == SQLNOTFOUND)?SQLNOTFOUND:0;

}/***************************** Final ifnRangoClientes ************************/


/******************************************************************************/
/*                        funcion : vfnPrintFin                               */
/******************************************************************************/
static void vfnPrintFin (void)
{
       vDTrazasLog (szExeName,
                    "\n\t*******************************************"
                    "\n\t*           FIN PROCESO CICLO             *"
                    "\n\t       # CLIENTES PROCESADOS [%ld]         "
                    "\n\t       # CLIENTES CORRECTOS  [%ld]         "
                    "\n\t       # CLIENTES ERRONEOS   [%ld]         "
                    "\n\t*******************************************", LOG03,
                    stStatus.lNumReg, stStatus.lNumRegOk, stStatus.lNumRegErr);

}/*************************** Final vfnPrintFin *******************************/

/******************************************************************************/
/*                           funcion : bfnInicioCiclo                         */
/******************************************************************************/
static BOOL bfnInicioCiclo (char     *szFecCategoria,
                            int      iTipoFact      ,
                            ABONOCLI stAbo)
{
	char szCodBco  [16]   =""   ;

    stCliente.lCodCliente = stAbo.pCicloCli[0].lCodCliente;
    stCliente.iIndFactur  = 1                             ;

    vInitRegCliente ();

    vDTrazasLog (szExeName,
                    "\n\t\t************* FACTURA CICLO *************"
                    "\n\t\t            # Cod.Cliente   [%ld]        "
                    "\n\t\t*****************************************",
                    LOG03,stCliente.lCodCliente);
    vDTrazasError(szExeName,
                     "\n\t\t************* FACTURA CICLO *************"
                     "\n\t\t            # Cod.Cliente   [%ld]        "
                     "\n\t\t*****************************************",
                     LOG03,stCliente.lCodCliente);

    if (!bCargaCargos(pstCargos,&NUM_CARGOS,iTipoFact,ORA_NULL,ORA_NULL))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bCargaCargos", szfnORAerror());
		return FALSE;
    }

    if (szFecCategoria [0] != 0)
    {
    	if (!bGetCatImpCliente (stCliente.lCodCliente ,
                                &stCliente.iCodCatImpos,
                                szFecCategoria        , iTipoFact))
        {
			iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bGetCatImpCliente", szfnORAerror());
			return FALSE;
        }
  	}
    else
    {
    	vDTrazasError (szExeName,
                       "\n\t\t=> Fecha Categoria de Cliente [%s]",
                       LOG01, szFecCategoria);
		iDError (szExeName,ERR000,vInsertarIncidencia, "Fecha Categoria de Cliente NULA.", szFecCategoria);
		return FALSE;
    }
    if (!bGestionLog ())
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bGestionLog", szfnORAerror());
		return FALSE;
    }
    if (!bfnGetDirecCli (stCliente.lCodCliente, TIPDIRECCION_FACTURA ))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnGetDirecCli-TIPDIRECCION_FACTURA", szfnORAerror());
		return FALSE;
    }
    if (!bfnGetDirecCli (stCliente.lCodCliente,iTIP_CORRESPONDENCIA))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnGetDirecCli-iTIP_CORRESPONDENCIA", szfnORAerror());
		return FALSE;
    }

    if (!bfnGetDatosCliente (stCliente.lCodCliente))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnGetDatosCliente", szfnORAerror());
		return FALSE;
    }

    if (!bfnGetBcoUniPac (stCliente.lCodCliente, szCodBco ))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnGetBcoUniPac", szfnORAerror());
		return FALSE;
    }

    if (strcmp(szCodBco, "") != 0)
    {
        strcpy(stCliente.szIndDebito,"A");
    }else{
        strcpy(stCliente.szIndDebito,"M");
    }

    if ( (stAbonoCli.pCicloCli =
         (CICLOCLI *)malloc ( stAbo.lNumAbonados * sizeof(CICLOCLI)))
                               == (CICLOCLI *)NULL)
    {
          iDError (szExeName,ERR005,vInsertarIncidencia,
                   "stAbonoCli.pCicloCli");
          return  (FALSE)                 ;
    }
    memcpy (stAbonoCli.pCicloCli, stAbo.pCicloCli,
            sizeof (CICLOCLI)*stAbo.lNumAbonados);


    stAbonoCli.lNumAbonados = stAbo.lNumAbonados;

    return TRUE;

}/**************************** Final bfnInicioCiclo ***************************/

/******************************************************************************/
/*                            funcion : vfnFinErrorCliente                    */
/******************************************************************************/
static void vfnFinErrorCliente (int iTipoFact        ,
                                TRANSCONTADO *pstTran,
                                VENTAS       *pstVenta)
{

    if(!bfnOraRollBack())
    {
        iDError(szExeName,ERR000,vInsertarIncidencia,"RollBackWork - vfnFinErrorCliente",szfnORAerror());
        bChangeIndEstadoPro(stStatus.IdPro   ,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_ERROR);
        if ( iTipoFact != FACT_CICLO )
            bChangeCodEstaProcInterfaz(stStatus.IdPro,iESTAPROC_TERMINADO_ERROR);
    }
    if ( iTipoFact == FACT_CICLO )
        bfnUpdateCicloCli (stAbonoCli,stAbonoCli.lNumAbonados,-1);
	/*2005-12-27 faar/ ESTABILIZACI�N DE LA FACTURACI�N TMC... */
    /*if(!bInsertaAnomProceso (&stAnomProceso) || !bSetNumFactura (iTipoFact,pstTran  ,pstVenta))*/
    if(!bSetNumFactura (iTipoFact, pstTran, pstVenta))
    {
        if(!bfnOraRollBack ())
        {
            iDError(szExeName,ERR000,vInsertarIncidencia,"RollBackWork 2 - vfnFinErrorCliente",szfnORAerror());
            bChangeIndEstadoPro(stStatus.IdPro,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_ERROR);
            if ( iTipoFact != FACT_CICLO )
                bChangeCodEstaProcInterfaz(stStatus.IdPro,iESTAPROC_TERMINADO_ERROR);
        }
    }/* fin if !bSetNumFactura ... */
    else
    {
        bChangeIndEstadoPro (stStatus.IdPro   ,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_ERROR);
        if ( iTipoFact != FACT_CICLO ) 
        	bChangeCodEstaProcInterfaz(stStatus.IdPro,iESTAPROC_TERMINADO_ERROR);
        if(!bfnOraCommit())
        {
            iDError(szExeName,ERR000,vInsertarIncidencia,"CommitWork- vfnFinErrorCliente",szfnORAerror());
            bChangeIndEstadoPro(stStatus.IdPro,PROC_EJECUTANDOSE,iESTAPROC_TERMINADO_ERROR) ;
            if ( iTipoFact != FACT_CICLO )
                bChangeCodEstaProcInterfaz(stStatus.IdPro,iESTAPROC_TERMINADO_ERROR);
        }
    }
    stCliente.lCodCliente = ORA_NULL;
}/**************************** Final vfnFinErrorCliente **********************/


BOOL bfnOraCommitPGG(void)
{
  /* EXEC SQL WHENEVER SQLERROR      CONTINUE; */ 

  /* EXEC SQL WHENEVER SQLWARNING    CONTINUE; */ 

  /* EXEC SQL WHENEVER NOT FOUND     CONTINUE; */ 

  /* EXEC SQL COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )416;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	
	vDTrazasLog ("bfnOraCommitPGG","\t\tPGG BETA01 sqlca.sqlcode despues del COMMIT [%ld]\n",LOG05, sqlca.sqlcode ); /* PGG SOPORTE 42970  7/08/2007 */
	
  if(sqlca.sqlcode != 0) /* PGG SOPORTE 42970  SE CAMBIA < 0  POR <> 0 7/08/2007 */
  		return FALSE;
  		
  return TRUE;
}


/*****************************************************************************/
/*                            funcion : bfnFinOkCliente                      */
/*****************************************************************************/
static BOOL bfnFinOkCliente (void)
{
       /*if (!bfnOraCommit()) */
       if (!bfnOraCommitPGG())
       {
            iDError(szExeName,ERR000,vInsertarIncidencia,
                    "CommitWork",szfnORAerror());
	       vFreeModulos ();
            return (FALSE)                      ;
       }
       else
       {
            vDTrazasLog (szExeName,
                         "\n\t\t****************************************"
                         "\n\t\t  # Cod.Cliente          [%ld]          "
                         "\n\t\t  # Conceptos Facturados [%d]           "
                         "\n\t\t****************************************"
                         ,LOG03,stCliente.lCodCliente,
                               stPreFactura.iNumRegistros);
            stStatus.lNumRegOk++;
           vFreeModulos ();
	        return (TRUE)       ;
      }


}/**************************** Final bfnFinOkCliente *************************/

/*****************************************************************************/
/*                         funcion : vfnPrintRangoCliente                    */
/*****************************************************************************/
void vfnPrintRangoCliente (GABONOCLI stGAbo)
{
  long l1 = 0, l2 = 0;

  vDTrazasLog (szExeName, "\n\t\t# Rango Cargado [%ld]", LOG05,stGAbo.lNumReg);

  for (l1=0;l1<stGAbo.lNumReg;l1++)
  {
       for (l2=0;l2<stGAbo.pstAbonoCli[l1].lNumAbonados;l2++)
       {
            vDTrazasLog (szExeName,
                         "\n\t\t[%ld]- Cod.Cliente [%ld]"
                         "\n\t\t[%ld]- Num.Abonado [%ld]"
                         "\n\t\t[%ld]- Rowid       [%s] ",
                         LOG05,
                         l2, stGAbo.pstAbonoCli[l1].pCicloCli[l2].lCodCliente,
                         l2, stGAbo.pstAbonoCli[l1].pCicloCli[l2].lNumAbonado,
                         l2, stGAbo.pstAbonoCli[l1].pCicloCli[l2].szRowid);
       }
  }
}/************************* Final vfnPrintRangoCliente ***********************/

/*****************************************************************************/
/*                         funcion : bfnSkipBadRecord                    */
/*****************************************************************************/
static BOOL bfnSkipBadRecord(int iTipoFact, TRANSCONTADO *pstTransContado, VENTAS *pstVenta)
{

    vDTrazasLog  (szExeName, "\n\t\t# Actualiza Fa_CicloCli Con error y Continua Facturando", LOG02);
    vDTrazasError(szExeName, "\n\t\t# Actualiza Fa_CicloCli Con error y Continua Facturando", LOG02);

    vfnFinErrorCliente (iTipoFact, pstTransContado, pstVenta);
    if (!bfnOraCommit())
    {
        iDError(szExeName,ERR000,vInsertarIncidencia, "CommitWork - bfnSkipBadRecord", szfnORAerror());
        return (FALSE)                      ;
    }
    return  TRUE;
}/************************* Final bfnSkipBadRecord ***********************/


/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

BOOL bCargaGeneralPreBilling_MC (int  iTipoFact,long lNumAbonado)
{
 	int  i             = 0;
    BOOL bFlagSalida   = FALSE;

   	if (!bGetParamDecimales ())
        	return FALSE;

	vDTrazasLog (szExeName, "\n\t* pstParamGener.iNumDecimal      [%d]"
							"\n\t* pstParamGener.szSepMilesMonto  [%s]"
							"\n\t* pstParamGener.szSepDecMontos   [%s]"
							"\n\t* pstParamGener.szSepDecOracle   [%s]"
							"\n\t* pstParamGener.iNumDecimalFact  [%d]"
							"\n\t* pstParamGener.iTipoFoliacion   [%d]"
							"\n\t* pstParamGener.iConsConcTrafico [%d]"
							"\n\t* pstParamGener.iIndZonaImpCic   [%d]"
							"\n\t* pstParamGener.iMtoMinAjuste    [%d]"
							"\n\t* pstParamGener.iZonaImpoDefec   [%d]"
						,LOG03            
						,pstParamGener.iNumDecimal
						,pstParamGener.szSepMilesMonto
						,pstParamGener.szSepDecMontos
						,pstParamGener.szSepDecOracle
						,pstParamGener.iNumDecimalFact
						,pstParamGener.iTipoFoliacion 
						,pstParamGener.iConsConcTrafico
						,pstParamGener.iIndZonaImpCic
						,pstParamGener.iMtoMinAjuste
						,pstParamGener.iZonaImpoDefec);		
						
	if(!attach_shared_ciclo(
		pstTipImpues,&NUM_TIPIMPUES,
		pstImpuestos,&NUM_IMPUESTOS,
		pstCabCuotas,&NUM_CABCUOTAS,
		pstTaConcepFact,&NUM_TACONCEPFACT,
		&pstConceptos,&NUM_CONCEPTOS,
		pstConceptos_mi,&NUM_CONCEPTOS_MI,
		pstActividades,&NUM_ACTIVIDADES,
		pstRangoTabla,&NUM_RANGOTABLA,
		pstLimCreditos,&NUM_LIMCREDITOS,
		pstProvincias,&NUM_PROVINCIAS,
		pstRegiones,&NUM_REGIONES,
		pstCatImpositiva,&NUM_CATIMPOSITIVA,
		pstZonaCiudad,&NUM_ZONACIUDAD,
		pstGrpSerConc,&NUM_GRPSERCONC,
		pstConversion,&NUM_CONVERSION,
		pstDocumSucursal,&NUM_DOCUMSUCURSAL,
		pstLetras,&NUM_LETRAS,
		pstGrupoCob,&NUM_GRUPOCOB,
		pstTarifas,&NUM_TARIFAS,
		pstActuaServ,&NUM_ACTUASERV,
		pstCuotas,&NUM_CUOTAS,
		pstFactCarriers,&NUM_FACTCARRIERS,
		pstCuadCtoPlan,&NUM_CUADCTOPLAN,
		pstCtoPlan,&NUM_CTOPLAN,
		pstPlanCtoPlan,&NUM_PLANCTOPLAN,
		pstArriendo,&NUM_ARRIENDOS,
		pstCargosBasico,&NUM_CARGOSBASICO,
		pstOptimo,&NUM_OPTIMO,
		pstFeriados,&NUM_FERIADOS,
		pstPlanTarif,&NUM_PLANTARIF,
		pstPenalizaciones,&NUM_PENALIZACIONES,
		&pstOficinas.stOficina,&pstOficinas.iNumOficinas,
        &pstFactCobros.stFactCobr,&pstFactCobros.iNumFactCobros,
/*              &pstDetPlanDescs.stDetPlanDesc,&pstDetPlanDescs.iNumRegs,  */
		&pstDescPuntual.stDetCargPunt,&pstDescPuntual.iNumDetCargPunt,
		&NUM_FAC_CICLO))
	{
		return FALSE;
	}


	vDTrazasLog (szExeName,"\tConceptos obtenidos [%ld]\n" ,LOG01, NUM_CONCEPTOS );  


    i=0;
    bFlagSalida = FALSE;
    
    while(!bFlagSalida)
    {
        stIndConcepto_mi.lNumRangos = i;
        if ((stIndConcepto_mi.pRangoConcepto = (RANGO_CONCEPTO *)
            realloc((RANGO_CONCEPTO *)stIndConcepto_mi.pRangoConcepto,(i+1)*sizeof(RANGO_CONCEPTO)))==(RANGO_CONCEPTO *)NULL)
        {
            iDError (szExeName,ERR021,vInsertarIncidencia,"stIndConcepto.pRangoConcepto");
            return FALSE;
        }

        if (i==0)
            stIndConcepto_mi.pRangoConcepto[i].lIndInicial = i;
        else
            stIndConcepto_mi.pRangoConcepto[i].lIndInicial = i * iRANGO_CONCEPTO + 1;

        stIndConcepto_mi.pRangoConcepto[i].lIndFinal   = (i+1) * iRANGO_CONCEPTO;
        if (stIndConcepto_mi.pRangoConcepto[i].lIndFinal > NUM_CONCEPTOS_MI)
        {
            stIndConcepto_mi.pRangoConcepto[i].lIndFinal =  NUM_CONCEPTOS_MI - 1;
            bFlagSalida = TRUE;
        }
        /* PPV 14/05/2010 */
	if (i==0)
	{
	      stIndConcepto_mi.pRangoConcepto[i].iCodConcIni = 1;
       	}
       	else
       	{
       		stIndConcepto_mi.pRangoConcepto[i].iCodConcIni = pstConceptos_mi[stIndConcepto_mi.pRangoConcepto[i].lIndInicial].iCodConcepto;
        }
		stIndConcepto_mi.pRangoConcepto[i].iCodConcFin = pstConceptos_mi[stIndConcepto_mi.pRangoConcepto[i].lIndFinal].iCodConcepto;

		vDTrazasLog (szExeName,"\n**** ASIGNACION DE RANGOS DE CONCEPTOS MUTI-IDIOMAS"
							   "\n\tindice:[%d]"
							   "\n\tlNumRangos:[%ld]"
							   "\n\tConcepto Inicial:[%d]"
							   "\n\tConcepto Final:  [%d]"
							   "\n\tIndice Inicial:  [%ld]"
							   "\n\tIndice Final:    [%ld]",
							   LOG03, i, stIndConcepto_mi.lNumRangos,
							   stIndConcepto_mi.pRangoConcepto[i].iCodConcIni,
							   stIndConcepto_mi.pRangoConcepto[i].iCodConcFin,
							   stIndConcepto_mi.pRangoConcepto[i].lIndInicial,
							   stIndConcepto_mi.pRangoConcepto[i].lIndFinal);



        i++;
    }
    stIndConcepto_mi.lNumRangos++;

	vDTrazasLog (szExeName,"\tlNumRangos = [%ld] [%ld]\n" ,LOG03, stIndConcepto_mi.lNumRangos, i );  

    if (stStatus.LogNivel >= LOG06)
    {
        for (i=0; i<stIndConcepto_mi.lNumRangos; i++)
        {
            vDTrazasLog (szExeName,"\n\t***************CONSTRUCCION DE RANGOS DE CONCEPTOS MUTI-IDIOMAS"
                                   "\t\nRango de Conceptos_MI:      [%d]"
                                   "\n\tConcepto Inicial:           [%d]"
                                   "\n\tConcepto Final:             [%d]"
                                   "\n\tIndice Inicial:             [%ld]"
                                   "\n\tIndice Final:               [%ld]",
                                   LOG06, i,
                                   stIndConcepto_mi.pRangoConcepto[i].iCodConcIni,
                                   stIndConcepto_mi.pRangoConcepto[i].iCodConcFin,
                                   stIndConcepto_mi.pRangoConcepto[i].lIndInicial,
                                   stIndConcepto_mi.pRangoConcepto[i].lIndFinal);
            fflush(stStatus.LogFile);
            fflush(stderr);
        }
    }
    return TRUE;
}

/*************************** Final bCargaGeneralPrebilling_MC ********************/

/*******************************************************************************
 Funcion      : ifnRangoClientes_MC
 Descripcion  :
 Retornos     :
*******************************************************************************/

static int ifnRangoClientes_MC (GABONOCLI *pstGAbo,long lNumReg,int iCodCiclo,long mypid)
{
	long lCont=0;
	long l1, l2      = 0    ;
	long lAuxCliente = 0    ;
	long lNumAbonados= 0    ;
	char szFecDesde [15] = "";

	strcpy (szFecDesde, szMenorFecDesdeCiclo ());

	for(lCont=0;lCont<NUM_ABONADOS;lCont++)
	{
	/*	printf ("facturaC %d: Cliente en proceso: [%ld] - Abonado en proceso: [%ld]...\n",mypid,pstAbonados[lCont].lCodCliente,pstAbonados[lCont].lNumAbonado);	*/

		if (strcmp (pstAbonados[lCont].szFecAlta, stCiclo.szFecHastaLlam) <= 0)
		{
			lNumAbonados++;

		    if (lAuxCliente != pstAbonados[lCont].lCodCliente)
		    {
				lAuxCliente = pstAbonados[lCont].lCodCliente;

		        if ( (pstGAbo->pstAbonoCli = (ABONOCLI*)realloc((ABONOCLI *)pstGAbo->pstAbonoCli,sizeof (ABONOCLI)*(pstGAbo->lNumReg+1)))==(ABONOCLI *)NULL) 
		        {
		        	iDError (szExeName,ERR005,vInsertarIncidencia,"pstGAbo->pstAbonoCli");
		            	return  (-1)                    ;
		        }
		        memset (&pstGAbo->pstAbonoCli [pstGAbo->lNumReg], 0, sizeof (ABONOCLI));
		        pstGAbo->lNumReg++         ;
		    }

		    if (lAuxCliente == pstAbonados[lCont].lCodCliente)
		    {
				l1 = pstGAbo->lNumReg - 1                  ;
		    		l2 = pstGAbo->pstAbonoCli [l1].lNumAbonados;

		        if ( (pstGAbo->pstAbonoCli[l1].pCicloCli = (CICLOCLI *)realloc((CICLOCLI*)pstGAbo->pstAbonoCli[l1].pCicloCli,(l2 + 1) * sizeof (CICLOCLI))) == (CICLOCLI *)NULL)
		        {
		        	iDError (szExeName,ERR005,vInsertarIncidencia,"pstGAbo->pstAbonoCli[%ld].pCicloCli[%ld]",l1, l2);
		        	return  (-1)    ;
		        }
		        memcpy (&pstGAbo->pstAbonoCli [l1].pCicloCli [l2],&pstAbonados[lCont], sizeof (CICLOCLI))      ;
		        pstGAbo->pstAbonoCli [l1].lNumAbonados++;
		    }
		}
	}

	return 0;
}

/*************************** Final ifnRangoClientes_MC ********************/

/*******************************************************************************
 Funcion      : bfnInicioCiclo_MC
 Descripcion  :
 Retornos     :
*******************************************************************************/

static BOOL bfnInicioCiclo_MC (char *szFecCategoria, int iTipoFact, ABONOCLI stAbo)
{
    COMUNAS  stComuna;
  	CIUDADES stCiudad;
	char szCodBco[16]="";

	stCliente.lCodCliente=stAbo.pCicloCli[0].lCodCliente;
	stCliente.iIndFactur=1                             ;

	vInitRegCliente();

	vDTrazasLog (szExeName,
			"\n\t\t************* FACTURA CICLO *************"
			"\n\t\t            # Cod.Cliente   [%ld]        "
			"\n\t\t*****************************************",LOG03,stCliente.lCodCliente);
	vDTrazasError(szExeName,
			"\n\t\t************* FACTURA CICLO *************"
			"\n\t\t            # Cod.Cliente   [%ld]        "
			"\n\t\t*****************************************",LOG03,stCliente.lCodCliente);

	if (!bCargaCargos_MC(pstCargos,&NUM_CARGOS,iTipoFact,ORA_NULL,ORA_NULL,pstCliente->lCodCliente,pstCliente->lCargos))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bCargaCargos_MC", szfnORAerror());
		return FALSE;
    }

	/*	INI CATEGORIA IMPOSITIVA	*/
	if (szFecCategoria[0]!= 0)
	{
		vDTrazasLog (szExeName,"\n\t\t* Entrada Categoria Impositiva"
                        "\n\t\t=> Cliente   [%ld]"
                        "\n\t\t=> Fecha     [%s] ",LOG05,pstCliente->lCodCliente,szFecCategoria);	

		if(pstCliente->iCodCatImpos!=-1)
		{
			strcpy(stDatosGener.szIndOrdenTotal,pstCliente->szIndOrdenTotal);
			stCliente.iCodCatImpos=pstCliente->iCodCatImpos;
		}
        else
        {
        	iDError (szExeName,ERR000,vInsertarIncidencia, "Error en Categoria Impositiva del Cliente." , "Not if(pstCliente->iCodCatImpos!=-1) " );
            vFreeModulos (); 
            return FALSE   ;
        }        	
	}
	else
	{
        iDError (szExeName,ERR000,vInsertarIncidencia, "\n\t\t=> Fecha Categoria de Cliente Nula", "(szFecCategoria[0]!= 0)");
		vDTrazasError (szExeName,"\n\t\t=> Fecha Categoria de Cliente [%s]",LOG01,szFecCategoria);
		vFreeModulos(); 
		return FALSE;
	}
        /*	FIN CATEGORIA IMPOSITIVA	*/

	if (!bGestionLog ())
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bGestionLog", szfnORAerror());
		return FALSE;
    }

	strcpy(stCliente.szGls_DirecClie,"X");

	vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ga_DirecCli\n"
                         "\t\t=> Cod.Cliente  [%ld]\n",LOG05,pstCliente->lCodCliente);

	strcpy(stCliente.szCodRegion,pstCliente->szCodRegion_1);
	strcpy(stCliente.szCodProvincia,pstCliente->szCodProvincia_1);
	strcpy(stCliente.szCodCiudad,pstCliente->szCodCiudad_1);
	strcpy(stCliente.szCodComuna,pstCliente->szCodComuna_1);
	strcpy(stCliente.szNomCalle,pstCliente->szNomCalle_1);
	strcpy(stCliente.szNumCalle,pstCliente->szNumCalle_1);
	strcpy(stCliente.szNumPiso,pstCliente->szNumPiso_1);

	vDTrazasLog (szExeName,"\n\t\t * Direccion del Cliente [%ld]\n"
			"\t\t=> Cod.Region       [%s]\n"
			"\t\t=> Cod.Provincia    [%s]\n"
			"\t\t=> Cod.Ciudad       [%s]\n",
			LOG05,
			stCliente.lCodCliente,
			stCliente.szCodRegion,
			stCliente.szCodProvincia,
			stCliente.szCodCiudad);
	strcpy(stCliente.szGls_DirecClie,"X");

	vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ga_DirecCli\n"
                         "\t\t=> Cod.Cliente  [%ld]\n",LOG05,pstCliente->lCodCliente);

	memset (&stComuna, 0, sizeof (COMUNAS) );
      	memset (&stCiudad, 0, sizeof (CIUDADES));

	strcpy(stCorreo.szCodRegion,pstCliente->szCodRegion_3);
	strcpy(stCorreo.szCodProvincia,pstCliente->szCodProvincia_3);
	strcpy(stCorreo.szCodCiudad,pstCliente->szCodCiudad_3);
	strcpy(stCorreo.szCodComuna,pstCliente->szCodComuna_3);
	strcpy(stCorreo.szNomCalle,pstCliente->szNomCalle_3);
	strcpy(stCorreo.szNumCalle,pstCliente->szNumCalle_3);
	strcpy(stCorreo.szNumPiso,pstCliente->szNumPiso_3);

	vDTrazasLog (szExeName,"\n\t\t * Direccion del Cliente [%ld]\n"
			"\t\t=> Cod.Region       [%s]\n"
			"\t\t=> Cod.Provincia    [%s]\n"
			"\t\t=> Cod.Ciudad       [%s]\n",
			LOG05,
			stCliente.lCodCliente,
			stCliente.szCodRegion,
			stCliente.szCodProvincia,
			stCliente.szCodCiudad);

	strcpy (stComuna.szCodRegion,stCorreo.szCodRegion)   ;
	strcpy (stComuna.szCodProvincia,stCorreo.szCodProvincia);
	strcpy (stComuna.szCodComuna,stCorreo.szCodComuna)   ;

	if (!bfnFindComuna (&stComuna,stProceso.iCodTipDocum))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnFindComuna", szfnORAerror());
		return FALSE;
    }

	strcpy (stCorreo.szDesComuna,stComuna.szDesComuna);
	strcpy (stCiudad.szCodRegion   ,stCorreo.szCodRegion)   ;
	strcpy (stCiudad.szCodProvincia,stCorreo.szCodProvincia);
	strcpy (stCiudad.szCodCiudad   ,stCorreo.szCodCiudad)   ;

	if (!bfnFindCiudad (&stCiudad,stProceso.iCodTipDocum))
    {
		iDError (szExeName,ERR000,vInsertarIncidencia, "Error en funci�n bfnFindCiudad", szfnORAerror());
		return FALSE;
    }

	strcpy (stCorreo.szDesCiudad,stCiudad.szDesCiudad);
	/*	FIN DIRECCION: iTIP_CORRESPONDENCIA	*/

	/*	INI DATOS CLIENTE	*/
	vDTrazasLog(szExeName,"\n\t\t* Parametros Entrada Ge_Clientes\n"
                        "\t\t=> Cod.Cliente  [%ld]\n",LOG05,pstCliente->lCodCliente);

        strcpy(stCliente.szCodIdioma,pstCliente->szCodIdioma);
        strcpy(stCliente.szNomCliente,pstCliente->szNomCliente);
        strcpy(stCliente.szNomApeClien1,pstCliente->szNomApeClien1);
        strcpy(stCliente.szNomApeClien2,pstCliente->szNomApeClien2);
        strcpy(stCliente.szTefCliente1,pstCliente->szTefCliente1);
        strcpy(stCliente.szTefCliente1,pstCliente->szTefCliente2);
        strcpy(stCliente.szCodPais,pstCliente->szCodPais);
        strcpy(stCliente.szIndDebito,pstCliente->szIndDebito);
        stCliente.dImpStopDebit=pstCliente->dImpStopDebit;
        strcpy(stCliente.szCodBanco,pstCliente->szCodBanco);
        strcpy(stCliente.szCodSucursal,pstCliente->szCodSucursal);
        strcpy(stCliente.szIndTipCuenta,pstCliente->szIndTipCuenta);
        strcpy(stCliente.szCodTipTarjeta,pstCliente->szCodTipTarjeta);
        strcpy(stCliente.szNumCtaCorr,pstCliente->szNumCtaCorr);
        strcpy(stCliente.szNumTarjeta,pstCliente->szNumTarjeta);
        strcpy(stCliente.szFecVenciTarj,pstCliente->szFecVenciTarj);
        strcpy(stCliente.szCodBancoTarj,pstCliente->szCodBancoTarj);
        strcpy(stCliente.szCodTipIdTrib,pstCliente->szCodTipIdTrib);
        strcpy(stCliente.szNumIdentTrib,pstCliente->szNumIdentTrib);
        stCliente.iCodActividad=pstCliente->iCodActividad;
        strcpy(stCliente.szCodOficina,pstCliente->szCodOficina);
        strcpy(stCliente.szNumFax,pstCliente->szNumFax);
        strcpy(stCliente.szFecAlta,pstCliente->szFecAlta);
        stCliente.iIndFactur=pstCliente->iIndFactur;
        stCliente.lCodCuenta=pstCliente->lCodCuenta;
        strcpy(stCliente.szCodOperadora,pstCliente->szCodOperadora);
	/*	FIN DATOS CLIENTE	*/

	/*	INI BCO UNIPAC	*/
	vDTrazasLog(szExeName,
               "\n\t\t* Recuperacion Codigo de Banco de cliente Pac (Prebilling)"
               "\n\t\t=> Cod.Cliente [%ld]", LOG05,pstCliente->lCodCliente);
	strcpy(szCodBco,pstCliente->szCodBancoUniPac);
	if(strcmp(szCodBco,"")!=0)
	{
		strcpy(stCliente.szIndDebito,"A");
	}
	else
	{
		strcpy(stCliente.szIndDebito,"M");
	}
	/*	FIN BCO UNIPAC	*/

	if ( (stAbonoCli.pCicloCli =
		(CICLOCLI *)malloc ((int) (stAbo.lNumAbonados * sizeof(CICLOCLI))))
				== (CICLOCLI *)NULL)
	{
		iDError (szExeName,ERR005,vInsertarIncidencia,
			"stAbonoCli.pCicloCli");
		return  (FALSE)                 ;
	}
	memcpy (stAbonoCli.pCicloCli, stAbo.pCicloCli,
		(int)(sizeof (CICLOCLI)*stAbo.lNumAbonados));


	stAbonoCli.lNumAbonados = stAbo.lNumAbonados;

	return TRUE;
}

/*************************** Final bfnInicioCiclo_MC ********************/

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

/******************************************************************************************/
/** Informaci�n de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisi�n                                            : */
/**  %PR% */
/** Autor de la Revisi�n                                : */
/**  %AUTHOR% */
/** Estado de la Revisi�n ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creaci�n de la Revisi�n                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/

