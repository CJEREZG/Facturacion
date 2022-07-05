
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
    "./pc/CheckInter.pc"
};


static unsigned long sqlctx = 13778939;


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
            void  *sqhstv[11];
   unsigned int   sqhstl[11];
            int   sqhsts[11];
            void  *sqindv[11];
            int   sqinds[11];
   unsigned int   sqharm[11];
   unsigned int   *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {10,11};

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

 static char *sq0001 = 
"select A.COD_ESTPROC ,A.NUM_PROCESO ,B.IND_ORDENTOTAL ,B.COD_TIPDOCUM ,C.COD\
_TIPDOCUM COD_TIPDOCUMALM ,NVL(B.PREF_PLAZA,'0000000000') ,NVL(B.NUM_FOLIO,0) \
,NVL(B.COD_VENDEDOR,0) ,NVL(B.COD_OFICINA,' ') ,B.COD_MODVENTA ,B.TOT_FACTURA \
 from FA_INTERFACT A ,FA_FACTDOCU_NOCICLO B ,FA_TIPDOCUMEN C where (((A.COD_AP\
LIC='FAC' and A.COD_ESTADOC=:b0) and A.NUM_PROCESO=B.NUM_PROCESO) and B.COD_TI\
PDOCUM=C.COD_TIPDOCUMMOV)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{10,4130,0,0,0,
5,0,0,1,424,0,9,791,0,0,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,838,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,
83,0,0,1,0,0,15,910,0,0,0,0,0,1,0,
98,0,0,2,119,0,4,948,0,0,7,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,
3,0,0,2,97,0,0,
141,0,0,3,108,0,4,975,0,0,7,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,97,0,0,
1,3,0,0,2,97,0,0,
184,0,0,4,83,0,4,1016,0,0,1,0,0,1,0,2,3,0,0,
203,0,0,5,0,0,17,1070,0,0,1,1,0,1,0,1,97,0,0,
222,0,0,5,0,0,21,1082,0,0,1,1,0,1,0,1,3,0,0,
241,0,0,6,0,0,17,1193,0,0,1,1,0,1,0,1,97,0,0,
260,0,0,6,0,0,21,1205,0,0,1,1,0,1,0,1,3,0,0,
279,0,0,7,0,0,17,1240,0,0,1,1,0,1,0,1,97,0,0,
298,0,0,7,0,0,21,1252,0,0,1,1,0,1,0,1,3,0,0,
317,0,0,8,0,0,17,1372,0,0,1,1,0,1,0,1,97,0,0,
336,0,0,8,0,0,21,1384,0,0,1,1,0,1,0,1,3,0,0,
355,0,0,9,0,0,17,1397,0,0,1,1,0,1,0,1,97,0,0,
374,0,0,9,0,0,21,1409,0,0,1,1,0,1,0,1,3,0,0,
393,0,0,10,0,0,17,1524,0,0,1,1,0,1,0,1,97,0,0,
412,0,0,10,0,0,21,1536,0,0,1,1,0,1,0,1,3,0,0,
431,0,0,11,0,0,17,1549,0,0,1,1,0,1,0,1,97,0,0,
450,0,0,11,0,0,21,1561,0,0,1,1,0,1,0,1,3,0,0,
469,0,0,5,0,0,17,1664,0,0,1,1,0,1,0,1,97,0,0,
488,0,0,5,0,0,21,1676,0,0,1,1,0,1,0,1,3,0,0,
507,0,0,12,0,0,17,1688,0,0,1,1,0,1,0,1,97,0,0,
526,0,0,12,0,0,21,1700,0,0,1,1,0,1,0,1,3,0,0,
545,0,0,12,0,0,17,1813,0,0,1,1,0,1,0,1,97,0,0,
564,0,0,12,0,0,21,1825,0,0,1,1,0,1,0,1,3,0,0,
583,0,0,10,0,0,17,1880,0,0,1,1,0,1,0,1,97,0,0,
602,0,0,10,0,0,21,1892,0,0,1,1,0,1,0,1,3,0,0,
621,0,0,11,0,0,17,1905,0,0,1,1,0,1,0,1,97,0,0,
640,0,0,11,0,0,21,1917,0,0,1,1,0,1,0,1,3,0,0,
};


#line 1 "./pc/CheckInter.pc"
/* *********************************************************************** */
/* *  Fichero : CheckInter.pc                                            * */
/* *********************************************************************** */
/* *********************************************************************** */
/* *********************************************************************** */
/* *********************************************************************** */
/***************************************************************************/

#define _CHECKINTER_PC_

#include "CheckInter.h"

/****************************************************************************/
/*           Variables de Retorno de Oracle-Pro-C                           */
/****************************************************************************/
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

#line 17 "./pc/CheckInter.pc"
long pid=0;
/****************************************************************************/
/*  Funcion :   main                                                        */
/****************************************************************************/
int main(int argc, char *argv[])
{
	char modulo[]="main";

	pid =getpid();

	fprintf( stdout, "\n\t******  CheckInter   *******\n"
			 "\t**%s**\n\t**** pid : [ %8ld ] ****"
	                 "\n\t****************************\n",
	         		 cfnGetTime(1),pid );


    memset(&stLineaComandoCheck,0,sizeof(LINEACOMANDOCHECK));
    memset(&stStatus,'\0',sizeof(STATUS));
    
    strcpy(szSysDate,cfnGetTime(2));
    
    if (!bfnValidaParametros(argc,argv,&stLineaComandoCheck)) return 1;


    if(!bfnConnectORA(stLineaComandoCheck.szOraAccount,stLineaComandoCheck.szOraPasswd))
    {
        vDTrazasError(modulo, "<< Usuario/Password Invalido >>", LOG01);
        return 2;
    }

	if (!bfnValidaOperadora())								return 3;

    if (!bfnAbreArchivos(&stLineaComandoCheck,szSysDate))
     	return 4;

	if (!bGetDatosGener (&stDatosGener, szSysDate))			return 5;

    if(!bfnRevisaInterfaz())
    {
        vDTrazasError(modulo, " \n\t------------------------------------"
                              " \n\tProceso Terminado de Forma Irregular"
                              " \n\t------------------------------------"
                              ,LOG01);
        vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tProceso Terminado de Forma Irregular"
                              " \n\t------------------------------------"
                              ,LOG01);
        return 6;
    }
    else
    {
        vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tProceso Terminado Correctamente"
                              " \n\t------------------------------------"
                              ,LOG04);

        if (!bfnOraCommit())
        {

            vDTrazasLog  (modulo, " \n\t------------------------------------"
                                  " \n\tFallo en el Commit"
                                  " \n\t------------------------------------"
                                  ,LOG01);
            vDTrazasError(modulo, " \n\t------------------------------------"
                                  " \n\tFallo en el Commit"
                                  " \n\t------------------------------------"
                                  ,LOG01);
            return 7;
        }
    }

    if(bfnDisconnectORA(0))
    {
      vDTrazasLog  (modulo, "\n\t--------------------------------------------"
                            "\n\tDesconectado de  ORACLE"
                            "\n\t--------------------------------------------"
                            ,LOG04);
	}

    fclose(stStatus.LogFile);
    fclose(stStatus.ErrFile);

    return 0;

} /* Main */


/* ************************************************************************* */
/* * Funcion bfnValidaParametros                                           * */
/* ************************************************************************* */
/* * Realiza la validacion de los Parametros de Entrada                    * */
/* ************************************************************************* */
BOOL bfnValidaParametros( int argc, char *argv[], LINEACOMANDOCHECK *pstLineaCom )
{

	       char modulo[]="bfnValidaParametros";

	extern char *optarg;
	extern  int opterr, optopt;

	       char opt[] = ":u:l:";
	        int iOpt=0;

  	       char *psztmp = "";

	        int Userflag=FALSE;
 	        int Logflag=FALSE;

    vDTrazasLog (modulo , "\n\t*** Entrada en %s ***",LOG04,modulo);

	opterr=0;

	if(argc == 1)
	{
		fprintf (stderr,"\n\t<< Error : Parametros insuficientes >>\n%s\n",szUsageCheck);
		return FALSE;
	}

	while ( (iOpt = getopt(argc, argv, opt) ) != EOF)
	{
		switch(iOpt)
		{
			case 'u':
				if(Userflag==FALSE)
				{
	                strcpy(pstLineaCom->szUsuarioOra, optarg);
    	            Userflag=TRUE;
       	            vDTrazasLog (modulo, " -u %s ", LOG03, pstLineaCom->szUsuarioOra);
				}
				else
				{
					fprintf (stderr,"\n\t<< Error : opcion '-%c' duplicada >>\n%s\n",optopt,szUsageCheck);
					return FALSE;
				}
				break;

			case 'l':
				if(Logflag==FALSE)
				{
                    stStatus.LogNivel = (atoi(optarg) > 0)? atoi(optarg):iLOGNIVEL_DEF ;
                    Logflag=TRUE;
				}
				else
				{
					fprintf (stderr,"\n\t<< Error : opcion '-%c' duplicada >>\n%s\n",optopt,szUsageCheck);
					return FALSE;
				}
				break;

			case '?':
				fprintf (stderr,"\n\t<< Error : opcion '-%c' es desconocida >>\n%s\n",optopt,szUsageCheck);
				return FALSE;

			case ':':
				fprintf (stderr,"\n\t<< Error : Falta parametro para opcion '-%c' >>\n%s\n",optopt,szUsageCheck);
				return FALSE;

		}

	}


	if(Logflag==FALSE)
	{
       stStatus.LogNivel = iLOGNIVEL_DEF ; /* asume nivel de log por defecto */
       vDTrazasLog ( modulo, "Log : -l %d (default)", LOG03, stStatus.LogNivel );
	}

    pstLineaCom->iNivLog=stStatus.LogNivel ;

	if(Userflag==TRUE)
	{
        if ( (psztmp=(char *)strstr(pstLineaCom->szUsuarioOra,"/"))==(char *)NULL)
		{
			fprintf (stderr,"\n\t<< Error : Usuario Oracle no valido. Requiere '/' >>\n%s\n",szUsageCheck);
			return FALSE;
		}
		else
		{
            strncpy (pstLineaCom->szOraAccount,pstLineaCom->szUsuarioOra,psztmp-pstLineaCom->szUsuarioOra);
            strcpy  (pstLineaCom->szOraPasswd, psztmp+1)                 ;
		}
	}


	return TRUE;

} /* bfnValidaParamatros */



/* ************************************************************************* */
/* * Funcion bfnAbreArchivos                                               * */
/* ************************************************************************* */
/* * Realiza la apertura de archivos de Logs, Errores y Datos              * */
/* ************************************************************************* */
BOOL bfnAbreArchivos(LINEACOMANDOCHECK *pstLineaCom, char *szDate)
{
 	char modulo[]="bfnAbreArchivos";

    char    *szDirLogs               ;
    char    *szNomArchivo            ;
    char    szComando[1024] = ""     ;

    /*vDTrazasLog ( modulo, "\n\t*** Entrada en %s ***", LOG04, modulo); */

    szDirLogs    = (char *)malloc(1024);
    szNomArchivo = (char *)malloc(128);


    if ((szDirLogs = szGetEnv("XPF_LOG")) == (char *)NULL) return FALSE;

   	sprintf (pstLineaCom->szDirLogs,"%s/CheckInter",szDirLogs);
    sprintf (szComando, "/usr/bin/mkdir -p %s",pstLineaCom->szDirLogs );

   	fprintf (stdout, "\n\tCrea Directorio Log  : %s\n", pstLineaCom->szDirLogs);

    if (system (szComando))
    {
        vDTrazasError(modulo,"*** Fallo mkdir de Directorio Logs : %s",LOG01,szComando);
        return FALSE;
    }


   	sprintf (pstLineaCom->szDirLogs,"%s/%s",pstLineaCom->szDirLogs,cfnGetTime(2));
    sprintf (szComando, "/usr/bin/mkdir -p %s",pstLineaCom->szDirLogs );

   	fprintf (stdout, "\n\tCrea Directorio Log  : %s\n", pstLineaCom->szDirLogs);

    if (system (szComando))
    {
        vDTrazasError(modulo,"*** Fallo mkdir de Directorio Logs : %s",LOG01,szComando);
        return FALSE;
    }

	fprintf(stdout, "\n\tCrea Archivo Log/Err : CheckInter_%s\n\n", szDate );

    sprintf(szNomArchivo,"%s/CheckInter_%s",pstLineaCom->szDirLogs,
    					/*pstLineaCom->szDirLogs*/szDate);


    sprintf(stStatus.ErrName,"%s.err",szNomArchivo);
    if( (stStatus.ErrFile = fopen(stStatus.ErrName,"a")) == (FILE*)NULL )
    {
        vDTrazasError(modulo,"*** No puede abrirse el fichero de error %s",LOG01, stStatus.ErrName);
        return FALSE;
    }

    sprintf(stStatus.LogName, "%s.log",szNomArchivo);
    if ((stStatus.LogFile = fopen(stStatus.LogName,"a")) == (FILE*)NULL)
    {
        vDTrazasError(modulo,"*** No puede abrirse el fichero de log %s",LOG01, stStatus.LogName);
        fclose(stStatus.ErrFile);
        return FALSE;
    }


    vDTrazasLog  (modulo,"\n\t*************************************"
                         "\n\t****        Log   CheckInter       **"
                         "\n\t*************************************"
                         ,LOG03);

    vDTrazasLog(modulo, "\n\t***  Parametro de Entrada CheckInter  ***"
                        "\n\t=> Usuario               [%s]"
                        "\n\t=> Password              [************]"
                        "\n\t=> Niv.Log               [%d]"
                        ,LOG05
                        ,pstLineaCom->szOraAccount
                        ,pstLineaCom->iNivLog);

    return TRUE;

} /* bfnAbreArchivos */



/* ************************************************************************* */
/* * Funcion bfnRevisaInterfaz                                            * */
/* ************************************************************************* */
BOOL bfnRevisaInterfaz ( void )
{
	char modulo[]="bfnRevisaInterfaz";

    vDTrazasLog ( modulo, "\n\t*** Entrada en %s ***", LOG04, modulo);

    if (!bfnCheck800())
	{
        vDTrazasError(modulo, " Al procesar Documentos 800 " ,LOG01);
        vDTrazasLog  (modulo, " Al procesar Documentos 800 " ,LOG01);
		return FALSE;
	}
    if (!bfnCheck900())
	{
        vDTrazasError(modulo, " Al procesar Documentos 900 " ,LOG01);
        vDTrazasLog  (modulo, " Al procesar Documentos 900 " ,LOG01);
		return FALSE;
	}
    if (!bfnCheck920())
	{
        vDTrazasError(modulo, " Al procesar Documentos 920 " ,LOG01);
        vDTrazasLog  (modulo, " Al procesar Documentos 920 " ,LOG01);
		return FALSE;
	}
    if (!bfnCheck600())
	{
        vDTrazasError(modulo, " Al procesar Documentos 600 " ,LOG01);
        vDTrazasLog  (modulo, " Al procesar Documentos 600 " ,LOG01);
		return FALSE;
	}
	return TRUE;
}
 
/* ************************************************************************* */
/* * Funcion bfnCheck800                                            * */
/* ************************************************************************* */
BOOL bfnCheck800 ( void )
{
	char modulo[]="bfnCheck800";
	int  iCodEstado=800;
	int  i =0;
	int  iCont=0;
	
    vDTrazasLog (modulo,"\n\t*** Entrada en %s ***" ,LOG04,modulo);


    if (!bfnOpenInterfaz(iCodEstado))
	{
        vDTrazasError(modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
        vDTrazasLog  (modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
		return FALSE;
	}

	memset(&stRegDocum,0,sizeof(REGDOCUM));
    
    if(!ifnFetchInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }
    

    if(!bfnCloseInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }

	for (i=0;i<stRegDocum.iNumReg;i++)
	{
		if ( stRegDocum.stDocum[i].iCodTipDocum == 1  ||
			 stRegDocum.stDocum[i].iCodTipDocum == 35 ||
			 stRegDocum.stDocum[i].iCodTipDocum == 38 )
		{
			if (abs(stRegDocum.stDocum[i].dTotFactura)>0.0) /* Se valida el monto */
			{
	       		vDTrazasLog  (modulo, "El documento tiene un monto <> 0  : %ld"
	       					, LOG03, stRegDocum.stDocum[i].lNumProceso);
	       		vDTrazasError(modulo, "El documento tiene un monto <> 0  : %ld"
	       					, LOG03, stRegDocum.stDocum[i].lNumProceso);
			}
			else 
			{
				
				if (!bfnValidaFolio(i))
					return FALSE;
                                  
				if (!bfnDBPasarHistFactura (stRegDocum.stDocum[i].lIndOrdenTotal))
        			return FALSE;

			    if (!bfnDBPasarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
			        return FALSE;

/* rao: SE comenta para la version de Aranjuez */
/* 				if (!bfnDBPasarHistTecno   (stRegDocum.stDocum[i].lIndOrdenTotal)) */
/* 			        return FALSE; */

				if  (!bfnBorrarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
			        return FALSE;
			
			    if (!bfnDBPasarHistCliente (stRegDocum.stDocum[i].lIndOrdenTotal))
			        return FALSE;
			
			    if (!bfnDBPasarHistAbonado (stRegDocum.stDocum[i].lIndOrdenTotal))
			        return FALSE;
			
			    if (!bfnDBEliminarFactura  (stRegDocum.stDocum[i].lIndOrdenTotal))
			        return FALSE;
			
			    if( !bfnDBPasarHistInterfact(stRegDocum.stDocum[i].lNumProceso))
			    	return FALSE;

	       		vDTrazasLog  (modulo, "El documento fue traspasado a historicos  : %ld"
	       					, LOG03, stRegDocum.stDocum[i].lNumProceso);
	       		iCont++;
			}
		}
		else 
		{
			vDTrazasLog  (modulo, "El documento no se procesa  : %ld"
	       				, LOG03, stRegDocum.stDocum[i].lNumProceso);
	       	vDTrazasError(modulo, "El documento no se procesa  : %ld"
	       				, LOG03, stRegDocum.stDocum[i].lNumProceso);
			
		}

	}

	vDTrazasLog  (modulo, "\t\t** Documentos procesados : %d", LOG03, iCont);

	if (!bfnOraCommit())
    {

    	vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        vDTrazasError(modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        return 7;
    }

	return TRUE;

}/* bfnCheck800 */

/* ************************************************************************* */
/* * Funcion bfnCheck900                                            * */
/* ************************************************************************* */
BOOL bfnCheck900 (  )
{
	char modulo[]="bfnCheck900";
	int  iCodEstado=900;
	int  i =0;
	int  iCont=0;
	
    vDTrazasLog (modulo,"\n\t*** Entrada en %s ***" ,LOG04,modulo);

    if (!bfnOpenInterfaz(iCodEstado))
	{
        vDTrazasError(modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
        vDTrazasLog  (modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
		return FALSE;
	}

	memset(&stRegDocum,0,sizeof(REGDOCUM));
    
    if(!ifnFetchInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }
    

    if(!bfnCloseInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }

	for (i=0;i<stRegDocum.iNumReg;i++)
	{
		if (!bfnValidaFolio(i))
			return FALSE;
                                  
		if (!bfnDBPasarHistFactura (stRegDocum.stDocum[i].lIndOrdenTotal))
        	return FALSE;

	    if (!bfnDBPasarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
	        return FALSE;

/* rao: SE comenta para la version de Aranjuez */
/*		if (!bfnDBPasarHistTecno   (stRegDocum.stDocum[i].lIndOrdenTotal)) */
/* 	        return FALSE;*/

		if  (!bfnBorrarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
	        return FALSE;
		
		if (!bfnDBPasarHistCliente (stRegDocum.stDocum[i].lIndOrdenTotal))
		    return FALSE;
		
		if (!bfnDBPasarHistAbonado (stRegDocum.stDocum[i].lIndOrdenTotal))
		    return FALSE;
		
		if (!bfnDBEliminarFactura  (stRegDocum.stDocum[i].lIndOrdenTotal))
		    return FALSE;
		
		if( !bfnDBPasarHistInterfact(stRegDocum.stDocum[i].lNumProceso))
			return FALSE;

	    vDTrazasLog  (modulo, "El documento fue traspasado a historicos  : %ld"
	    			, LOG03, stRegDocum.stDocum[i].lNumProceso);
	    iCont++;

	}
	vDTrazasLog  (modulo, "\t\t** Documentos procesados : %d", LOG03, iCont);

	if (!bfnOraCommit())
    {

    	vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        vDTrazasError(modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        return 7;
    }

	return TRUE;

}/* bfnCheck900 */

/* ************************************************************************* */
/* * Funcion bfnCheck920                          		                   * */
/* ************************************************************************* */
BOOL bfnCheck920 (  )
{
	char modulo[]="bfnCheck920";
	int  iCodEstado=920;
	int  i =0;
	int  iCont=0;
	
    vDTrazasLog (modulo,"\n\t*** Entrada en %s ***" ,LOG04,modulo);

    if (!bfnOpenInterfaz(iCodEstado))
	{
        vDTrazasError(modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
        vDTrazasLog  (modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
		return FALSE;
	}

	memset(&stRegDocum,0,sizeof(REGDOCUM));
    
    if(!ifnFetchInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }
    

    if(!bfnCloseInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }

	for (i=0;i<stRegDocum.iNumReg;i++)
	{
		if (   stRegDocum.stDocum[i].iCodTipDocum == 1
			|| stRegDocum.stDocum[i].iCodTipDocum == 35)
		{	
			if (!bfnValidaFolio(i))
				return FALSE;
	                                  
			if (!bfnDBPasarHistFactura (stRegDocum.stDocum[i].lIndOrdenTotal))
	        	return FALSE;
	
		    if (!bfnDBPasarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
		        return FALSE;

/* rao: SE comenta para la version de Aranjuez */
/*			if (!bfnDBPasarHistTecno   (stRegDocum.stDocum[i].lIndOrdenTotal))*/
/*		        return FALSE;*/

			if  (!bfnBorrarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
		        return FALSE;
			
			if (!bfnDBPasarHistCliente (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			
			if (!bfnDBPasarHistAbonado (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			
			if (!bfnDBEliminarFactura  (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			
			if( !bfnDBPasarHistInterfact(stRegDocum.stDocum[i].lNumProceso))
				return FALSE;
		    vDTrazasLog  (modulo, "El documento fue traspasado a historicos  : %ld"
		    			, LOG03, stRegDocum.stDocum[i].lNumProceso);
		    iCont++;
		}
		else if (stRegDocum.stDocum[i].iCodTipDocum == 52)
		{
			if (!bfnDBEliminarFactura  (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			if( !bfnDBPasarHistInterfact(stRegDocum.stDocum[i].lNumProceso))
				return FALSE;

		    vDTrazasLog  (modulo, "El documento 52 se borro y paso a Hist. de interfaz  : %ld"
    			, LOG03, stRegDocum.stDocum[i].lNumProceso);
		    iCont++;
		}
	}

	vDTrazasLog  (modulo, "\t\t** Documentos procesados : %d", LOG03, iCont);

	if (!bfnOraCommit())
    {

    	vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        vDTrazasError(modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        return 7;
    }

	return TRUE;

}/* bfnCheck920 */

/* ************************************************************************* */
/* * Funcion bfnCheck600                                            * */
/* ************************************************************************* */
BOOL bfnCheck600 (  )
{
	char modulo[]="bfnCheck600";
	int  iCodEstado=600;
	int  i =0;
	int  iCont=0;
	
    vDTrazasLog (modulo,"\n\t*** Entrada en %s ***" ,LOG04,modulo);

    if (!bfnOpenInterfaz(iCodEstado))
	{
        vDTrazasError(modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
        vDTrazasLog  (modulo, " Al abrir cursor sobre la interfaz " ,LOG01);
		return FALSE;
	}

	memset(&stRegDocum,0,sizeof(REGDOCUM));
    
    if(!ifnFetchInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }
    

    if(!bfnCloseInterfaz())
    {
       vDTrazasLog  (modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       vDTrazasError(modulo, "Al cerrar el Cursor Cur_Interfaz : %s", LOG01, SQLERRM);
       return FALSE;
    }

	for (i=0;i<stRegDocum.iNumReg;i++)
	{
		if  (  stRegDocum.stDocum[i].iCodTipDocum == 35
		    && !(abs(stRegDocum.stDocum[i].dTotFactura)>0.0) 
			&& stRegDocum.stDocum[i].iCodModVenta== 5	
			&& stRegDocum.stDocum[i].iCodEstProc== 3)    
		{
				
			if (!bfnValidaFolio(i))
				return FALSE;
                                  
			if (!bfnDBPasarHistFactura (stRegDocum.stDocum[i].lIndOrdenTotal))
        		return FALSE;

		    if (!bfnDBPasarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
		        return FALSE;

/* rao: SE comenta para la version de Aranjuez */
/*			if (!bfnDBPasarHistTecno   (stRegDocum.stDocum[i].lIndOrdenTotal))*/
/*		        return FALSE;*/

			if  (!bfnBorrarHistDetalle (stRegDocum.stDocum[i].lIndOrdenTotal))
		        return FALSE;
			
			if (!bfnDBPasarHistCliente (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			
			if (!bfnDBPasarHistAbonado (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
				
			if (!bfnDBEliminarFactura  (stRegDocum.stDocum[i].lIndOrdenTotal))
			    return FALSE;
			
			if( !bfnDBPasarHistInterfact(stRegDocum.stDocum[i].lNumProceso))
				return FALSE;

	       	vDTrazasLog  (modulo, "El documento fue traspasado a historicos  : %ld"
	       				, LOG03, stRegDocum.stDocum[i].lNumProceso);
	       				
	       	iCont++;
		}

	}

	vDTrazasLog  (modulo, "\t\t** Documentos procesados : %d", LOG03, iCont);

	if (!bfnOraCommit())
    {

    	vDTrazasLog  (modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        vDTrazasError(modulo, " \n\t------------------------------------"
                              " \n\tFallo en el Commit"
                              " \n\t------------------------------------"
                              ,LOG01);
        return 7;
    }

	return TRUE;

}/* bfnCheck600 */


/* ************************************************************************* */
/* * Funcion bfnOpenInterfaz                                               * */
/* ************************************************************************* */
/* * Crea y Abre un Cursor sobre los documentos a Foliar de FA_INTERFACT   * */
/* ************************************************************************* */
BOOL bfnOpenInterfaz(int iCodEstProc)
{
    char modulo[]="bfnOpenInterfaz";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 752 "./pc/CheckInter.pc"

    	 int ihCodEstado       =0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 754 "./pc/CheckInter.pc"


    vDTrazasLog (modulo,"\t\t*** Entrada en %s ***" ,LOG04,modulo);

	ihCodEstado    =iCodEstProc;


	vDTrazasLog (modulo,"\t\t%s [%ld] Preparando Cursor sobre FA_INTERFACT "
	            ,LOG03, cfnGetTime(1),pid);
	/* EXEC SQL DECLARE  Cur_Interfaz  CURSOR for
	        SELECT A.COD_ESTPROC,
	        	   A.NUM_PROCESO, 
	        	   B.IND_ORDENTOTAL, 
	        	   B.COD_TIPDOCUM, 
	        	   C.COD_TIPDOCUM COD_TIPDOCUMALM,
	        	   /oNVL(B.PREF_PLAZA,'000'), o/	/o Comentado   por PGonzalez 15-03-2004 o/
	        	   NVL(B.PREF_PLAZA,'0000000000'),	/o Incorporado por PGonzalez 15-03-2004 o/
	        	   NVL(B.NUM_FOLIO ,0),
	        	   NVL(B.COD_VENDEDOR ,0),
	        	   NVL(B.COD_OFICINA,' '),
	        	   B.COD_MODVENTA ,
	        	   B.TOT_FACTURA
              FROM FA_INTERFACT A, FA_FACTDOCU_NOCICLO B,  FA_TIPDOCUMEN C
			 WHERE A.COD_APLIC='FAC' 
			   AND A.COD_ESTADOC  = :ihCodEstado
			   AND A.NUM_PROCESO =B.NUM_PROCESO
			   AND B.COD_TIPDOCUM =C.COD_TIPDOCUMMOV; */ 
#line 780 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasLog  (modulo , "\n\t** En SQL-DECLARE Cur_Interfaz **"
                               "\n\t\t=> Detalle : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(modulo , "\n\t**  En SQL-DECLARE Cur_Interfaz **"
                               "\n\t\t=> Detalle : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return FALSE;
    }

    /* EXEC SQL OPEN Cur_Interfaz ; */ 
#line 791 "./pc/CheckInter.pc"

{
#line 791 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 791 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 1;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 791 "./pc/CheckInter.pc"
    sqlstm.stmt = sq0001;
#line 791 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 791 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )5;
#line 791 "./pc/CheckInter.pc"
    sqlstm.selerr = (unsigned short)1;
#line 791 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 791 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&ihCodEstado;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 791 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 791 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 791 "./pc/CheckInter.pc"
}

#line 791 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasLog  (modulo,"**  En SQL-OPEN CURSOR Cur_Interfaz **"
                             "\n\t\t=> Detalle : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(modulo,"**  En SQL-OPEN CURSOR Cur_Interfaz **"
                             "\n\t\t=> Detale : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return FALSE;
    }

    return TRUE;

}/* bfnOpenInterfaz */


/* ************************************************************************* */
/* * Funcion ifnFetchInterfaz                                             * */
/* ************************************************************************* */
/* * Lee Un Registro de los documentos a Foliar                            * */
/* ************************************************************************* */
int ifnFetchInterfaz(void)
{
	char modulo[]="ifnFetchInterfaz";
	BOOL bFinCursor=FALSE;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 817 "./pc/CheckInter.pc"

    	int		ihCodEstProc	;
    	long    lhNumProceso    ;
    	long 	lhIndOrdenTotal ;
    	int 	ihCodTipDocum	;
    	int 	ihCodTipDocumAlm;
    	/*char	szhPrefPlaza [4]; */ 	/* Comentado   por PGonzalez 15-03-2004 */
    	char	szhPrefPlaza [11]; 	/* Incorporado por PGonzalez 15-03-2004 */
    	long 	lhNumFolio		;
    	long 	lhCodVendedor	;
    	char	szhCodOficina [3];
    	int 	ihCodModVenta	;
    	double  dhTotFactura    ;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 830 "./pc/CheckInter.pc"


	stRegDocum.iNumReg = 0 ;
	
    vDTrazasLog (modulo , "\t\t*** Entrada en %s ***",LOG04,modulo);
    
    do
    {
		/* EXEC SQL FETCH Cur_Interfaz INTO
						:ihCodEstProc ,
	    			    :lhNumProceso ,
	    			    :lhIndOrdenTotal,
	    			    :ihCodTipDocum,
	    			    :ihCodTipDocumAlm,
	    			    :szhPrefPlaza,
	    			    :lhNumFolio,
	    			    :lhCodVendedor,
	    			    :szhCodOficina,
	    			    :ihCodModVenta,
	    			    :dhTotFactura ; */ 
#line 849 "./pc/CheckInter.pc"

{
#line 838 "./pc/CheckInter.pc"
  struct sqlexd sqlstm;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqlvsn = 10;
#line 838 "./pc/CheckInter.pc"
  sqlstm.arrsiz = 11;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqladtp = &sqladt;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqltdsp = &sqltds;
#line 838 "./pc/CheckInter.pc"
  sqlstm.iters = (unsigned int  )1;
#line 838 "./pc/CheckInter.pc"
  sqlstm.offset = (unsigned int  )24;
#line 838 "./pc/CheckInter.pc"
  sqlstm.cud = sqlcud0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 838 "./pc/CheckInter.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[0] = (         void  *)&ihCodEstProc;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[0] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[0] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[1] = (         void  *)&lhNumProceso;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(long);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[1] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[1] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[2] = (         void  *)&lhIndOrdenTotal;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(long);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[2] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[2] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[3] = (         void  *)&ihCodTipDocum;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[3] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[3] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[3] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[3] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[3] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[3] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[4] = (         void  *)&ihCodTipDocumAlm;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[4] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[4] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[4] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[4] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[4] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[4] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[5] = (         void  *)szhPrefPlaza;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[5] = (unsigned int  )11;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[5] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[5] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[5] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[5] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[5] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[5] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[6] = (         void  *)&lhNumFolio;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(long);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[6] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[6] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[6] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[6] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[6] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[6] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[7] = (         void  *)&lhCodVendedor;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(long);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[7] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[7] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[7] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[7] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[7] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[7] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[8] = (         void  *)szhCodOficina;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[8] = (unsigned int  )3;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[8] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[8] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[8] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[8] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[8] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[8] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[9] = (         void  *)&ihCodModVenta;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[9] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[9] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[9] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[9] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[9] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[9] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstv[10] = (         void  *)&dhTotFactura;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqhsts[10] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqindv[10] = (         void  *)0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqinds[10] = (         int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqharm[10] = (unsigned int  )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqadto[10] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqtdso[10] = (unsigned short )0;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 838 "./pc/CheckInter.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 838 "./pc/CheckInter.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 838 "./pc/CheckInter.pc"
}

#line 849 "./pc/CheckInter.pc"

	
	    if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
	    {
	        vDTrazasLog  (modulo,  "En FETCH sobre CURSOR Cur_Interfaz [%s]",LOG01,SQLERRM);
	        vDTrazasError(modulo,  "En FETCH sobre CURSOR Cur_Interfaz [%s]",LOG01,SQLERRM);
	        return SQLCODE ;
	    }
	
	    if( SQLCODE == SQLNOTFOUND )
	    {
	        vDTrazasLog  (modulo, "\t\t** No Existen Mas Documentos en CURSOR Cur_Interfaz ",LOG03);
	        bFinCursor = TRUE ;
	    }
	    else
	    {
			if( (stRegDocum.stDocum=
			    (REGINTER *)realloc((REGINTER *)stRegDocum.stDocum,
	                        		 sizeof(REGINTER)*(stRegDocum.iNumReg+1) ))
	             ==(REGINTER *)NULL )
	        {
	        	iDError (szExeName,ERR005,vInsertarIncidencia,
	            		"stRegDocum.stDocum");
	            return(FALSE);
			}
			memset(&stRegDocum.stDocum[stRegDocum.iNumReg],0,sizeof(REGINTER));
			
	    	stRegDocum.stDocum[stRegDocum.iNumReg].iCodEstProc	= ihCodEstProc	;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].lNumProceso	= lhNumProceso	;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].lIndOrdenTotal= lhIndOrdenTotal;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].iCodTipDocum	= ihCodTipDocum	;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].iCodTipDocumAlm= ihCodTipDocumAlm;
	    	strcpy (stRegDocum.stDocum[stRegDocum.iNumReg].szPrefPlaza, szhPrefPlaza);
	    	stRegDocum.stDocum[stRegDocum.iNumReg].lNumFolio= lhNumFolio;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].lCodVendedor= lhCodVendedor	;
	    	strcpy (stRegDocum.stDocum[stRegDocum.iNumReg].szCodOficina, szhCodOficina);
	    	stRegDocum.stDocum[stRegDocum.iNumReg].iCodModVenta	= ihCodModVenta	;
	    	stRegDocum.stDocum[stRegDocum.iNumReg].dTotFactura	= dhTotFactura	;
	    	
	    	stRegDocum.iNumReg ++;
	    }
    
	} while (!bFinCursor);

    vDTrazasLog  (modulo, "\t\tTotal de Registros obtenidos : %d ", LOG03, stRegDocum.iNumReg);

    return SQLCODE ;
} /* ifnFetchInterfaz */



/* ************************************************************************* */
/* * Funcion bfnCloseInterfaz                                              * */
/* ************************************************************************* */
/* * Cierra el Cursor de documentos a Foliar                               * */
/* ************************************************************************* */
BOOL bfnCloseInterfaz()
{
	char modulo[]="bfnCloseInterfaz";
    vDTrazasLog  (modulo, "\t\t** Entrada en %s",LOG03,modulo);

    /* EXEC SQL CLOSE Cur_Interfaz; */ 
#line 910 "./pc/CheckInter.pc"

{
#line 910 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 910 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 910 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 910 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 910 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 910 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 910 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )83;
#line 910 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 910 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 910 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 910 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 910 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 910 "./pc/CheckInter.pc"
}

#line 910 "./pc/CheckInter.pc"


    if (SQLCODE != SQLOK)
        return FALSE;

    return TRUE;
}

/* ************************************************************************* */
/* * Funcion bfnValidaFolio                                              * */
/* ************************************************************************* */
BOOL bfnValidaFolio(int i)
{
	char 	modulo[]="bfnValidaFolio";
	char    *szArregloParametros[5];
	int     iEstadoFolio;
	int 	iNumParametros=0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 928 "./pc/CheckInter.pc"

    	int 	ihCodTipDocumAlm;
    	/*char	szhPrefPlaza [4]; */	/* Comentado   por PGonzalez 15-03-2004 */
    	char	szhPrefPlaza [11];	/* Incorporado por PGonzalez 15-03-2004 */
    	long 	lhNumFolio		;
    	long 	lhCodVendedor	;
    	char	szhCodOficina [3];
   	    char  	szhRetorno[250] ;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 936 "./pc/CheckInter.pc"


    vDTrazasLog  (modulo, "\t\t** Entrada en %s",LOG03,modulo);
	
	if (stRegDocum.stDocum[i].lNumFolio > 0)
	{
		ihCodTipDocumAlm=stRegDocum.stDocum[i].iCodTipDocumAlm;
		lhCodVendedor 	=stRegDocum.stDocum[i].lCodVendedor	;
		strcpy (szhCodOficina, stRegDocum.stDocum[i].szCodOficina);
		strcpy (szhPrefPlaza ,stRegDocum.stDocum[i].szPrefPlaza);
		lhNumFolio 		= stRegDocum.stDocum[i].lNumFolio;
		
		/* EXEC SQL 
			SELECT fa_foliacion_pg.FA_CONSULTA_FOLIO_FN(
						:ihCodTipDocumAlm, 
						decode(:lhCodVendedor,0,NULL,:lhCodVendedor) , 
						:szhCodOficina,
                        'TMC', 
                        :szhPrefPlaza,
                        :lhNumFolio,
                        NULL , 
                        1 )
                        
			  INTO :szhRetorno
          	  FROM DUAL; */ 
#line 960 "./pc/CheckInter.pc"

{
#line 948 "./pc/CheckInter.pc"
  struct sqlexd sqlstm;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqlvsn = 10;
#line 948 "./pc/CheckInter.pc"
  sqlstm.arrsiz = 11;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqladtp = &sqladt;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqltdsp = &sqltds;
#line 948 "./pc/CheckInter.pc"
  sqlstm.stmt = "select fa_foliacion_pg.FA_CONSULTA_FOLIO_FN(:b0,decode(:b1,\
0,null ,:b1),:b3,'TMC',:b4,:b5,null ,1) into :b6  from DUAL ";
#line 948 "./pc/CheckInter.pc"
  sqlstm.iters = (unsigned int  )1;
#line 948 "./pc/CheckInter.pc"
  sqlstm.offset = (unsigned int  )98;
#line 948 "./pc/CheckInter.pc"
  sqlstm.selerr = (unsigned short)1;
#line 948 "./pc/CheckInter.pc"
  sqlstm.cud = sqlcud0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqlety = (unsigned short)256;
#line 948 "./pc/CheckInter.pc"
  sqlstm.occurs = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[0] = (         void  *)&ihCodTipDocumAlm;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[0] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[0] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[0] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[0] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[0] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[0] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[1] = (         void  *)&lhCodVendedor;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(long);
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[1] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[1] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[1] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[1] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[1] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[1] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[2] = (         void  *)&lhCodVendedor;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(long);
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[2] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[2] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[2] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[2] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[2] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[2] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[3] = (         void  *)szhCodOficina;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[3] = (unsigned int  )3;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[3] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[3] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[3] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[3] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[3] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[3] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[4] = (         void  *)szhPrefPlaza;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[4] = (unsigned int  )11;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[4] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[4] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[4] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[4] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[4] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[4] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[5] = (         void  *)&lhNumFolio;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(long);
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[5] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[5] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[5] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[5] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[5] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[5] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstv[6] = (         void  *)szhRetorno;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhstl[6] = (unsigned int  )250;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqhsts[6] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqindv[6] = (         void  *)0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqinds[6] = (         int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqharm[6] = (unsigned int  )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqadto[6] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqtdso[6] = (unsigned short )0;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqphsv = sqlstm.sqhstv;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqphsl = sqlstm.sqhstl;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqphss = sqlstm.sqhsts;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqpind = sqlstm.sqindv;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqpins = sqlstm.sqinds;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqparm = sqlstm.sqharm;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqparc = sqlstm.sqharc;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqpadto = sqlstm.sqadto;
#line 948 "./pc/CheckInter.pc"
  sqlstm.sqptdso = sqlstm.sqtdso;
#line 948 "./pc/CheckInter.pc"
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 948 "./pc/CheckInter.pc"
}

#line 960 "./pc/CheckInter.pc"


	    if (SQLCODE != SQLOK)
	        return FALSE;
	
	  	/* Recupera Parametros de szhRetorno función y setea iNumParametros = 3 */
	    RecupParam(&iNumParametros,szArregloParametros,szhRetorno,cSEPARADOR_COMA);
		
		iEstadoFolio=atoi(szArregloParametros[0]);
		if (iEstadoFolio == G_NESTADO_CONSUMIDO )
		{
	       	vDTrazasLog(modulo , "\t\tDocumento con folio consumido N° Proceso [%ld]"
	       				,LOG03,stRegDocum.stDocum[i].lNumProceso);
	       				
			/* Si el folio se encuentra consumido se anula */
	      	/* EXEC SQL 
	      		SELECT FA_FOLIACION_PG.FA_ANULA_FOLIO_FN(
	      					:ihCodTipDocumAlm, 
							decode(:lhCodVendedor,0,NULL,:lhCodVendedor) , 
							:szhCodOficina,
	                        'TMC', 
	                        :szhPrefPlaza,
	                        :lhNumFolio)
	          	 INTO :szhRetorno
	          	FROM DUAL; */ 
#line 984 "./pc/CheckInter.pc"

{
#line 975 "./pc/CheckInter.pc"
        struct sqlexd sqlstm;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqlvsn = 10;
#line 975 "./pc/CheckInter.pc"
        sqlstm.arrsiz = 11;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqladtp = &sqladt;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqltdsp = &sqltds;
#line 975 "./pc/CheckInter.pc"
        sqlstm.stmt = "select FA_FOLIACION_PG.FA_ANULA_FOLIO_FN(:b0,decode(:\
b1,0,null ,:b1),:b3,'TMC',:b4,:b5) into :b6  from DUAL ";
#line 975 "./pc/CheckInter.pc"
        sqlstm.iters = (unsigned int  )1;
#line 975 "./pc/CheckInter.pc"
        sqlstm.offset = (unsigned int  )141;
#line 975 "./pc/CheckInter.pc"
        sqlstm.selerr = (unsigned short)1;
#line 975 "./pc/CheckInter.pc"
        sqlstm.cud = sqlcud0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqlety = (unsigned short)256;
#line 975 "./pc/CheckInter.pc"
        sqlstm.occurs = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[0] = (         void  *)&ihCodTipDocumAlm;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[0] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[0] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[0] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[0] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[0] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[0] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[1] = (         void  *)&lhCodVendedor;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(long);
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[1] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[1] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[1] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[1] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[1] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[1] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[2] = (         void  *)&lhCodVendedor;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(long);
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[2] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[2] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[2] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[2] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[2] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[2] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[3] = (         void  *)szhCodOficina;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[3] = (unsigned int  )3;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[3] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[3] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[3] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[3] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[3] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[3] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[4] = (         void  *)szhPrefPlaza;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[4] = (unsigned int  )11;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[4] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[4] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[4] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[4] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[4] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[4] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[5] = (         void  *)&lhNumFolio;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[5] = (unsigned int  )sizeof(long);
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[5] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[5] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[5] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[5] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[5] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[5] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstv[6] = (         void  *)szhRetorno;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhstl[6] = (unsigned int  )250;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqhsts[6] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqindv[6] = (         void  *)0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqinds[6] = (         int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqharm[6] = (unsigned int  )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqadto[6] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqtdso[6] = (unsigned short )0;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqphsv = sqlstm.sqhstv;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqphsl = sqlstm.sqhstl;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqphss = sqlstm.sqhsts;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqpind = sqlstm.sqindv;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqpins = sqlstm.sqinds;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqparm = sqlstm.sqharm;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqparc = sqlstm.sqharc;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqpadto = sqlstm.sqadto;
#line 975 "./pc/CheckInter.pc"
        sqlstm.sqptdso = sqlstm.sqtdso;
#line 975 "./pc/CheckInter.pc"
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 975 "./pc/CheckInter.pc"
}

#line 984 "./pc/CheckInter.pc"

	        if (SQLCODE != SQLOK)
	        {
	        	vDTrazasLog(modulo , "en la Anulacion del folio Docto N° Proceso [%ld]:(%d|%s)"
	        				,LOG01,stRegDocum.stDocum[i].lNumProceso, SQLCODE,SQLERRM);
	        	return FALSE;
	        	
	        }
	       	vDTrazasLog(modulo , "Se anulo el folio del documento N° Proceso  [%ld]"
	       				,LOG03,stRegDocum.stDocum[i].lNumProceso);
	        
	     }
	}     	
    return TRUE;
}


/* ************************************************************************* */
/* * Funcion bfnValidaOperadora                                            * */
/* ************************************************************************* */
/* * VALIDA QUE LA OPERADORA EN LA QUE SE EJECUTA LA APLICACION SEA TMC    * */
/* ************************************************************************* */
BOOL bfnValidaOperadora(void)
{
    char modulo[]="bfnValidaOperadora";

	/* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1010 "./pc/CheckInter.pc"

    	 int ihCuenta=0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1012 "./pc/CheckInter.pc"


    vDTrazasLog (modulo,"\n\t*** Entrada en %s ***" ,LOG04,modulo);

	/* EXEC SQL 
	        SELECT COUNT(1)
	        INTO :ihCuenta
 			FROM GE_OPERADORA_SCL_LOCAL
 			WHERE COD_OPERADORA_SCL='TMC'; */ 
#line 1020 "./pc/CheckInter.pc"

{
#line 1016 "./pc/CheckInter.pc"
 struct sqlexd sqlstm;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqlvsn = 10;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.arrsiz = 11;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqladtp = &sqladt;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqltdsp = &sqltds;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.stmt = "select count(1) into :b0  from GE_OPERADORA_SCL_LOCAL where \
COD_OPERADORA_SCL='TMC'";
#line 1016 "./pc/CheckInter.pc"
 sqlstm.iters = (unsigned int  )1;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.offset = (unsigned int  )184;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.selerr = (unsigned short)1;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.cud = sqlcud0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqlety = (unsigned short)256;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.occurs = (unsigned int  )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqhstv[0] = (         void  *)&ihCuenta;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqhsts[0] = (         int  )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqindv[0] = (         void  *)0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqinds[0] = (         int  )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqharm[0] = (unsigned int  )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqadto[0] = (unsigned short )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqtdso[0] = (unsigned short )0;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqphsv = sqlstm.sqhstv;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqphsl = sqlstm.sqhstl;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqphss = sqlstm.sqhsts;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqpind = sqlstm.sqindv;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqpins = sqlstm.sqinds;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqparm = sqlstm.sqharm;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqparc = sqlstm.sqharc;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqpadto = sqlstm.sqadto;
#line 1016 "./pc/CheckInter.pc"
 sqlstm.sqptdso = sqlstm.sqtdso;
#line 1016 "./pc/CheckInter.pc"
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1016 "./pc/CheckInter.pc"
}

#line 1020 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasLog  (modulo , "\n\t** En Validacion de operadora TMC **"
                               "\n\t\t=> Detalle : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(modulo , "\n\t** En Validacion de operadora TMC **"
                               "\n\t\t=> Detalle : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return FALSE;
    }

    if (ihCuenta != 1)
    {
        vDTrazasLog  (modulo,"**  La operadora no es valida para ejecutar el programa  **",LOG01);
        vDTrazasError(modulo,"**  La operadora no es valida para ejecutar el programa  **",LOG01);
        return FALSE;
    }

    return TRUE;

}/* bfnValidaOperadora */




/* *************************************** */
/*                  HISTORICOS			   */
/* *************************************** */

/* ************************************************************************* */
/* * Funcion bfnDBPasarHistFactura( ),                                     * */
/* * Pasamos a Historicas Facturas                                         * */
/* ************************************************************************* */
BOOL bfnDBPasarHistFactura(long lIndOrdenTotal)
{
    char modulo[]="bfnDBPasarHistFactura";
    char    szCadenaInsert[4096] ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1058 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1060 "./pc/CheckInter.pc"


	lhIndOrdenTotal = lIndOrdenTotal ;
	
    vDTrazasLog  (modulo,"\t\t**  Paso Historico de Facturas **"
    					 "\n\t\t==> Ind.OrdenTotal   [%ld]"
                         ,LOG05,lIndOrdenTotal);

    vfnInitCadenaInsertFactura (szCadenaInsert);

    /* EXEC SQL PREPARE sql_insert_factura FROM :szCadenaInsert; */ 
#line 1070 "./pc/CheckInter.pc"

{
#line 1070 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1070 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )203;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )4096;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1070 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1070 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1070 "./pc/CheckInter.pc"
}

#line 1070 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_factura USING :lhIndOrdenTotal; */ 
#line 1082 "./pc/CheckInter.pc"

{
#line 1082 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1082 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )222;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1082 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1082 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1082 "./pc/CheckInter.pc"
}

#line 1082 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }


    return (TRUE);
}

/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertFactura()                                  * */
/* * Inicilaiza Sql para Insertar Facturas                                 * */
/* ************************************************************************* */
void vfnInitCadenaInsertFactura(char *szCadena)
{
    sprintf(szCadena,
            "INSERT INTO FA_HISTDOCU ( "
                    "NUM_SECUENCI              , COD_TIPDOCUM              ,"
                    "COD_VENDEDOR_AGENTE       , LETRA                     ,"
                    "COD_CENTREMI              , TOT_PAGAR                 ,"
                    "TOT_CARGOSME              , COD_VENDEDOR              ,"
                    "COD_CLIENTE               , FEC_EMISION               ,"
                    "FEC_CAMBIOMO              , NOM_USUARORA              ,"
                    "ACUM_NETOGRAV             , ACUM_NETONOGRAV           ,"
                    "ACUM_IVA                  , IND_ORDENTOTAL            ,"
                    "IND_VISADA                , IND_LIBROIVA              ,"
                    "IND_PASOCOBRO             , IND_SUPERTEL              ,"
                    "IND_ANULADA               , NUM_PROCESO               ,"
                    "NUM_FOLIO                 , COD_PLANCOM               ,"
                    "COD_CATIMPOS              , FEC_VENCIMIE              ,"
                    "FEC_CADUCIDA              , FEC_PROXVENC              ,"
                    "COD_CICLFACT              , NUM_SECUREL               ,"
                    "LETRAREL                  , COD_TIPDOCUMREL           ,"
                    "COD_VENDEDOR_AGENTEREL    , COD_CENTRREL              ,"
                    "NUM_VENTA                 , NUM_TRANSACCION           ,"
                    "IMP_SALDOANT              , IND_IMPRESA               ,"
                    "SEQ_FORCOB                , SEQ_PAC                   ,"
                    "SEQ_SUPERTFN              , SEQ_FORFAC                ,"
                    "COD_OPREDFIJA             , NUM_CTC                   ,"
                    "COD_MODVENTA              , TOT_FACTURA               ,"
                    "TOT_CUOTAS                , TOT_DESCUENTO             ,"
                    "COD_BARRAS                , IND_FACTUR                ,"
                    "COD_DESPACHO			   , IND_RECUPIVA              ,"
                    "NUM_CUOTAS                , NUM_PROCPASOCOBRO         ,"
                    "COD_OFICINA               , PREF_PLAZA				   ,"
                    "COD_OPERADORA			   , COD_ZONAIMPO			   ,"
                    "COD_PLAZA											   )"
            "SELECT "
                    "NUM_SECUENCI              , COD_TIPDOCUM              ,"
                    "COD_VENDEDOR_AGENTE       , LETRA                     ,"
                    "COD_CENTREMI              , TOT_PAGAR                 ,"
                    "TOT_CARGOSME              , COD_VENDEDOR              ,"
                    "COD_CLIENTE               , FEC_EMISION               ,"
                    "FEC_CAMBIOMO              , NOM_USUARORA              ,"
                    "ACUM_NETOGRAV             , ACUM_NETONOGRAV           ,"
                    "ACUM_IVA                  , IND_ORDENTOTAL            ,"
                    "IND_VISADA                , IND_LIBROIVA              ,"
                    "IND_PASOCOBRO             , IND_SUPERTEL              ,"
                    "IND_ANULADA               , NUM_PROCESO               ,"
                    "NUM_FOLIO                 , COD_PLANCOM               ,"
                    "COD_CATIMPOS              , FEC_VENCIMIE              ,"
                    "FEC_CADUCIDA              , FEC_PROXVENC              ,"
                    "COD_CICLFACT              , NUM_SECUREL               ,"
                    "LETRAREL                  , COD_TIPDOCUMREL           ,"
                    "COD_VENDEDOR_AGENTEREL    , COD_CENTRREL              ,"
                    "NUM_VENTA                 , NUM_TRANSACCION           ,"
                    "IMP_SALDOANT              , IND_IMPRESA               ,"
                    "SEQ_FORCOB                , SEQ_PAC                   ,"
                    "SEQ_SUPERTFN              , SEQ_FORFAC                ,"
                    "COD_OPREDFIJA             , NUM_CTC                   ,"
                    "COD_MODVENTA              , TOT_FACTURA               ,"
                    "TOT_CUOTAS                , TOT_DESCUENTO             ,"
                    "COD_BARRAS                , IND_FACTUR                ,"
                    "COD_DESPACHO			   , IND_RECUPIVA              ,"
                    "NUM_CUOTAS                , NUM_PROCPASOCOBRO         ,"
                    "COD_OFICINA               , PREF_PLAZA 			   ,"
                    "COD_OPERADORA			   , COD_ZONAIMPO			   ,"
                    "COD_PLAZA												"
            "FROM   FA_FACTDOCU_NOCICLO "
            "WHERE  IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}

/*-----------------------------------------------------------------------------------------------------*/
/* ************************************************************************* */
/* * Funcion bfnDBPasarHistDetalle( ),                                     * */
/* * Pasamos a Historicas Detalle de Facturas                              * */
/* ************************************************************************* */
BOOL bfnDBPasarHistDetalle(long lIndOrdenTotal)
{
 	char  modulo[]="bfnDBPasarHistDetalle";
    char    szCadenaInsert[2048] ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1181 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1183 "./pc/CheckInter.pc"

	
	lhIndOrdenTotal = lIndOrdenTotal;
	
    vDTrazasLog  (modulo, "\t\t**  Paso Historico Detalle Factura **"
    					  "\n\t\t==> Ind.OrdenTotal   [%ld]"
                          ,LOG05,lIndOrdenTotal);

    vfnInitCadenaInsertDetalle(szCadenaInsert);

    /* EXEC SQL PREPARE sql_insert_detalle FROM :szCadenaInsert; */ 
#line 1193 "./pc/CheckInter.pc"

{
#line 1193 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1193 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )241;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )2048;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1193 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1193 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1193 "./pc/CheckInter.pc"
}

#line 1193 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Detalle **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Detalle **"
                               "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_detalle USING :lhIndOrdenTotal; */ 
#line 1205 "./pc/CheckInter.pc"

{
#line 1205 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1205 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )260;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1205 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1205 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1205 "./pc/CheckInter.pc"
}

#line 1205 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }


    return (TRUE);
}


/* ************************************************************************* */
/* * Funcion bfnBorrarHistDetalle( ),                                      * */
/* * Borramos a Historicas Detalle de Facturas                             * */
/* ************************************************************************* */
BOOL bfnBorrarHistDetalle(long lIndOrdenTotal)
{
 	char  modulo[]="bfnBorrarHistDetalle";
    char  szCadenaDelete[512]  ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1230 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1232 "./pc/CheckInter.pc"


	lhIndOrdenTotal = lIndOrdenTotal;
    vDTrazasLog  (modulo, "\t\t**  Borrado del Historico Detalle Factura **"
    					  "\n\t\t==> Ind.OrdenTotal   [%ld]"
                          ,LOG05,lIndOrdenTotal);

   vfnInitCadenaDeleteDetalle(szCadenaDelete);
   /* EXEC SQL PREPARE sql_delete_detalle FROM :szCadenaDelete; */ 
#line 1240 "./pc/CheckInter.pc"

{
#line 1240 "./pc/CheckInter.pc"
   struct sqlexd sqlstm;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqlvsn = 10;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.arrsiz = 11;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqladtp = &sqladt;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqltdsp = &sqltds;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.stmt = "";
#line 1240 "./pc/CheckInter.pc"
   sqlstm.iters = (unsigned int  )1;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.offset = (unsigned int  )279;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.cud = sqlcud0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqlety = (unsigned short)256;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.occurs = (unsigned int  )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqhsts[0] = (         int  )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqindv[0] = (         void  *)0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqinds[0] = (         int  )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqharm[0] = (unsigned int  )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqadto[0] = (unsigned short )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqtdso[0] = (unsigned short )0;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqphsv = sqlstm.sqhstv;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqphsl = sqlstm.sqhstl;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqphss = sqlstm.sqhsts;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqpind = sqlstm.sqindv;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqpins = sqlstm.sqinds;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqparm = sqlstm.sqharm;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqparc = sqlstm.sqharc;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqpadto = sqlstm.sqadto;
#line 1240 "./pc/CheckInter.pc"
   sqlstm.sqptdso = sqlstm.sqtdso;
#line 1240 "./pc/CheckInter.pc"
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1240 "./pc/CheckInter.pc"
}

#line 1240 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_detalle USING  :lhIndOrdenTotal; */ 
#line 1252 "./pc/CheckInter.pc"

{
#line 1252 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1252 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )298;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1252 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1252 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1252 "./pc/CheckInter.pc"
}

#line 1252 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Detalle **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    return (TRUE);
}/* ******************* * End bfnBorrarHistDetalle * ******************* */


/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertDetalle ()                                 * */
/* * Inicilaiza Sql para Insertar Detalle de Facturas                      * */
/* ************************************************************************* */
void vfnInitCadenaInsertDetalle(char *szCadena)
{
    sprintf(szCadena,
            "INSERT INTO FA_HISTCONC_19010102 ( "
                    "IND_ORDENTOTAL  , COD_CONCEPTO    , "
                    "COLUMNA         , COD_MONEDA      , "
                    "COD_PRODUCTO    , COD_TIPCONCE    , "
                    "FEC_VALOR       , FEC_EFECTIVIDAD , "
                    "IMP_CONCEPTO    , COD_REGION      , "
                    "COD_PROVINCIA   , COD_CIUDAD      , "
                    "IMP_MONTOBASE   , IND_FACTUR      , "
                    "IMP_FACTURABLE  , IND_SUPERTEL    , "
                    "NUM_ABONADO     , COD_PORTADOR    , "
                    "DES_CONCEPTO    , SEG_CONSUMIDO   , "
                    "NUM_CUOTAS      , ORD_CUOTA       , "
                    "NUM_UNIDADES    , NUM_SERIEMEC    , "
                    "NUM_SERIELE     , PRC_IMPUESTO    , "
                    "VAL_DTO         , TIP_DTO         , "
                    "MES_GARANTIA    , NUM_GUIA        , "
                    "IND_ALTA        , NUM_PAQUETE     , "
                    "FLAG_IMPUES     , FLAG_DTO        , "
                    "COD_CONCEREL    , COLUMNA_REL     , "
                    "SEQ_CUOTAS      , COD_CARGOBASICO , "
                    "TIP_PLANTARIF	 , IMP_DCTO		   , "
                    "IMP_REAL		 , DUR_DCTO		   , "
                    "DUR_REAL		 , CNT_LLAM_REAL   , "
                    "CNT_LLAM_DCTO	 , CNT_LLAM_FACT   , "
                    "MIN_PLANTARIF	 , COD_OPERADOR	   , "
                    "COD_UNIDAD ) "
            "SELECT "
                    "IND_ORDENTOTAL  , COD_CONCEPTO    , "
                    "COLUMNA         , COD_MONEDA      , "
                    "COD_PRODUCTO    , COD_TIPCONCE    , "
                    "FEC_VALOR       , FEC_EFECTIVIDAD , "
                    "IMP_CONCEPTO    , COD_REGION      , "
                    "COD_PROVINCIA   , COD_CIUDAD      , "
                    "IMP_MONTOBASE   , IND_FACTUR      , "
                    "IMP_FACTURABLE  , IND_SUPERTEL    , "
                    "NUM_ABONADO     , COD_PORTADOR    , "
                    "DES_CONCEPTO    , SEG_CONSUMIDO   , "
                    "NUM_CUOTAS      , ORD_CUOTA       , "
                    "NUM_UNIDADES    , NUM_SERIEMEC    , "
                    "NUM_SERIELE     , PRC_IMPUESTO    , "
                    "VAL_DTO         , TIP_DTO         , "
                    "MES_GARANTIA    , NUM_GUIA        , "
                    "IND_ALTA        , NUM_PAQUETE     , "
                    "FLAG_IMPUES     , FLAG_DTO        , "
                    "COD_CONCEREL    , COLUMNA_REL     , "
                    "SEQ_CUOTAS      , COD_CARGOBASICO , "
                    "TIP_PLANTARIF	 , IMP_DCTO		   , "
                    "IMP_REAL		 , DUR_DCTO		   , "
                    "DUR_REAL		 , CNT_LLAM_REAL   , "
                    "CNT_LLAM_DCTO	 , CNT_LLAM_FACT   , "
                    "MIN_PLANTARIF	 , COD_OPERADOR	   , "
                    "COD_UNIDAD "
            "FROM   FA_FACTCONC_NOCICLO "
            "WHERE  IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}

/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteDetalle ()                                 * */
/* * Inicilaiza Sql para Deletear Detalle de Facturas                      * */
/* ************************************************************************* */
void vfnInitCadenaDeleteDetalle (char *szCadena)
{
    sprintf(szCadena,
        "DELETE "
        "FROM    FA_FACTCONC_NOCICLO "
        "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}


/*-----------------------------------------------------------------------------------------------------*/
/* ************************************************************************* */
/* * Funcion bfnDBPasarHistCliente ( ),                                    * */
/* * Pasamos a Historicas de Clientes Facturados                           * */
/* ************************************************************************* */
BOOL bfnDBPasarHistCliente(long lIndOrdenTotal)
{
	char modulo[]="bfnDBPasarHistCliente";

    char    szCadenaInsert[2048] ="";
    char    szCadenaDelete[512]  ="";

    long    lFilasInsert=0          ;
    long    lFilasDelete=0          ;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1360 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1362 "./pc/CheckInter.pc"

    
    lhIndOrdenTotal = lIndOrdenTotal;
    vDTrazasLog  (modulo, "\t\t**  Paso Historico Cliente Factura **"
    					  "\n\t\t==> Ind.OrdenTotal   [%ld]"
                          ,LOG05,lIndOrdenTotal);

    vfnInitCadenaInsertCliente(szCadenaInsert);
    vfnInitCadenaDeleteCliente(szCadenaDelete);

    /* EXEC SQL PREPARE sql_insert_cliente FROM :szCadenaInsert; */ 
#line 1372 "./pc/CheckInter.pc"

{
#line 1372 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1372 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )317;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )2048;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1372 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1372 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1372 "./pc/CheckInter.pc"
}

#line 1372 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_cliente USING :lhIndOrdenTotal; */ 
#line 1384 "./pc/CheckInter.pc"

{
#line 1384 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1384 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )336;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1384 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1384 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1384 "./pc/CheckInter.pc"
}

#line 1384 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasInsert=(SQLROWS>0?SQLROWS:0);

    /* EXEC SQL PREPARE sql_delete_cliente FROM :szCadenaDelete; */ 
#line 1397 "./pc/CheckInter.pc"

{
#line 1397 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1397 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )355;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1397 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1397 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1397 "./pc/CheckInter.pc"
}

#line 1397 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_cliente USING  :lhIndOrdenTotal; */ 
#line 1409 "./pc/CheckInter.pc"

{
#line 1409 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1409 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )374;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1409 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1409 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1409 "./pc/CheckInter.pc"
}

#line 1409 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Cliente **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasDelete=(SQLROWS>0?SQLROWS:0);

    if (lFilasInsert != lFilasDelete)
    {
        vDTrazasLog  (modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        vDTrazasError(modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        return (FALSE);
    }
    return (TRUE);
}



/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertCliente ()                                 * */
/* * Inicilaiza Sql para Insertar Clientes de Facturas                     * */
/* ************************************************************************* */
void vfnInitCadenaInsertCliente(char *szCadena)
{
    sprintf(szCadena,
            "INSERT INTO FA_HISTCLIE_19010102 ( "
                    "IND_ORDENTOTAL , COD_CLIENTE    , "
                    "NOM_CLIENTE    , COD_PLANCOM    , "
                    "NOM_APECLIEN1  , NOM_APECLIEN2  , "
                    "TEF_CLIENTE1   , TEF_CLIENTE2   , "
                    "DES_ACTIVIDAD  , NOM_CALLE      , "
                    "NUM_CALLE      , NUM_PISO       , "
                    "DES_COMUNA     , DES_CIUDAD     , "
                    "COD_PAIS       , COD_RUTADESP   , "
                    "IND_DEBITO     , IMP_STOPDEBIT  , "
                    "COD_BANCO      , COD_SUCURSAL   , "
                    "IND_TIPCUENTA  , COD_TIPTARJETA , "
                    "NUM_CTACORR    , NUM_TARJETA    , "
                    "FEC_VENCITARJ  , COD_BANCOTARJ  , "
                    "COD_TIPIDTRIB  , NUM_IDENTTRIB  , "
                    "NUM_FAX        , COD_IDIOMA     , "
	            	"GLS_DIRECCLIE)"
            "SELECT "
                    "IND_ORDENTOTAL , COD_CLIENTE    , "
                    "NOM_CLIENTE    , COD_PLANCOM    , "
                    "NOM_APECLIEN1  , NOM_APECLIEN2  , "
                    "TEF_CLIENTE1   , TEF_CLIENTE2   , "
                    "DES_ACTIVIDAD  , NOM_CALLE      , "
                    "NUM_CALLE      , NUM_PISO       , "
                    "DES_COMUNA     , DES_CIUDAD     , "
                    "COD_PAIS       , COD_RUTADESP   , "
                    "IND_DEBITO     , IMP_STOPDEBIT  , "
                    "COD_BANCO      , COD_SUCURSAL   , "
                    "IND_TIPCUENTA  , COD_TIPTARJETA , "
                    "NUM_CTACORR    , NUM_TARJETA    , "
                    "FEC_VENCITARJ  , COD_BANCOTARJ  , "
                    "COD_TIPIDTRIB  , NUM_IDENTTRIB  , "
                    "NUM_FAX        , COD_IDIOMA     , "
	            	"GLS_DIRECCLIE "
            "FROM   FA_FACTCLIE_NOCICLO "
            "WHERE  IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
    
}



/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteCliente ()                                 * */
/* * Inicilaiza Sql para Deletear Detalle de Facturas                      * */
/* ************************************************************************* */
void vfnInitCadenaDeleteCliente (char *szCadena)
{
    sprintf(szCadena,
        "DELETE "
        "FROM    FA_FACTCLIE_NOCICLO  "
        "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}



/*-----------------------------------------------------------------------------------------------------*/
/* ************************************************************************* */
/* * Funcion bfnDBPasarHistAbonado( ),                                     * */
/* * Pasamos a Historicas Abonados Facturados                              * */
/* ************************************************************************* */
BOOL bfnDBPasarHistAbonado(long lIndOrdenTotal)
{
	char modulo[]="bfnDBPasarHistAbonado";

    char    szCadenaInsert[2048] ="";
    char    szCadenaDelete[512]  ="";

    long    lFilasInsert=0          ;
    long    lFilasDelete=0          ;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1512 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1514 "./pc/CheckInter.pc"


	lhIndOrdenTotal = lIndOrdenTotal;
    vDTrazasLog  (modulo,"\t\t**  Paso Historico Abonados de Factura **"
    					 "\n\t\t==> Ind.OrdenTotal   [%ld]"
                         ,LOG05,lhIndOrdenTotal);

    vfnInitCadenaInsertAbonado (szCadenaInsert);
    vfnInitCadenaDeleteAbonado (szCadenaDelete);

    /* EXEC SQL PREPARE sql_insert_abonado FROM :szCadenaInsert; */ 
#line 1524 "./pc/CheckInter.pc"

{
#line 1524 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1524 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )393;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )2048;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1524 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1524 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1524 "./pc/CheckInter.pc"
}

#line 1524 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_abonado USING :lhIndOrdenTotal; */ 
#line 1536 "./pc/CheckInter.pc"

{
#line 1536 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1536 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )412;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1536 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1536 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1536 "./pc/CheckInter.pc"
}

#line 1536 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasInsert=(SQLROWS>0?SQLROWS:0);

    /* EXEC SQL PREPARE sql_delete_abonado FROM :szCadenaDelete; */ 
#line 1549 "./pc/CheckInter.pc"

{
#line 1549 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1549 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )431;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1549 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1549 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1549 "./pc/CheckInter.pc"
}

#line 1549 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_abonado USING  :lhIndOrdenTotal; */ 
#line 1561 "./pc/CheckInter.pc"

{
#line 1561 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1561 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )450;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1561 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1561 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1561 "./pc/CheckInter.pc"
}

#line 1561 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Abonados **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasDelete=(SQLROWS>0?SQLROWS:0);

    if (lFilasInsert != lFilasDelete)
    {
        vDTrazasLog  (modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        vDTrazasError(modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        return (FALSE);
    }
    return (TRUE);
}




/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertAbonado ()                                 * */
/* * Inicilaiza Sql para Insertar Abonados de Facturas                     * */
/* ************************************************************************* */
void vfnInitCadenaInsertAbonado(char *szCadena)
{
    sprintf(szCadena,
            "INSERT INTO FA_HISTABON_19010102 ( "
                    "IND_ORDENTOTAL   , COD_CLIENTE      , "
                    "NUM_ABONADO      , COD_PRODUCTO     , "
                    "COD_SITUACION    , TOT_CARGOSME     , "
                    "ACUM_CARGO       , ACUM_DTO         , "
                    "ACUM_IVA         , COD_DETFACT      , "
                    "FEC_FINCONTRA    , IND_FACTUR       , "
                    "COD_CREDMOR      , NOM_USUARIO      , "
                    "NOM_APELLIDO1    , NOM_APELLIDO2    , "
                    "LIM_CREDITO      , NUM_CELULAR      , "
                    "NUM_BEEPER       , CAP_CODE         , "
                    "IND_SUPERTEL     , NUM_TELEFIJA     , "
                    "COD_BARRAS       )"
            "SELECT "
                    "IND_ORDENTOTAL   , COD_CLIENTE      , "
                    "NUM_ABONADO      , COD_PRODUCTO     , "
                    "COD_SITUACION    , TOT_CARGOSME     , "
                    "ACUM_CARGO       , ACUM_DTO         , "
                    "ACUM_IVA         , COD_DETFACT      , "
                    "FEC_FINCONTRA    , IND_FACTUR       , "
                    "COD_CREDMOR      , NOM_USUARIO      , "
                    "NOM_APELLIDO1    , NOM_APELLIDO2    , "
                    "LIM_CREDITO      , NUM_CELULAR      , "
                    "NUM_BEEPER       , CAP_CODE         , "
                    "IND_SUPERTEL     , NUM_TELEFIJA     , "
                    "COD_BARRAS       "
            "FROM   FA_FACTABON_NOCICLO "
            "WHERE  IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}



/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteAbonado ()                                 * */
/* * Inicilaiza Sql para Deletear Abonados de Facturas                     * */
/* ************************************************************************* */
void vfnInitCadenaDeleteAbonado (char *szCadena)
{
    sprintf(szCadena,
        "DELETE "
        "FROM    FA_FACTABON_NOCICLO  "
        "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}

/*-----------------------------------------------------------------------------------------------------*/

/* ************************************************************************* */
/* * Funcion bfnDBPasarHistInterfact( ),                                   * */
/* * Pasamos a Historicas Interfaz                                         * */
/* ************************************************************************* */
BOOL bfnDBPasarHistInterfact(long lNumProceso)
{
    char modulo[]="bfnDBPasarHistInterfact";

    char    szCadenaInsert[4096] ="";
    char    szCadenaDelete[512]  ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1652 "./pc/CheckInter.pc"

    	 int lhNumProceso	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1654 "./pc/CheckInter.pc"


	lhNumProceso = lNumProceso;
    vDTrazasLog  (modulo,"\t\t**  Paso Historico de InterFaz **"
    					 "\n\t\t ==> Num.Proceso   [%ld]"
                         ,LOG05,lhNumProceso);

    vfnInitCadenaInsertInterfaz (szCadenaInsert);
    vfnInitCadenaDeleteInterfaz (szCadenaDelete);

    /* EXEC SQL PREPARE sql_insert_factura FROM :szCadenaInsert; */ 
#line 1664 "./pc/CheckInter.pc"

{
#line 1664 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1664 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )469;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )4096;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1664 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1664 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1664 "./pc/CheckInter.pc"
}

#line 1664 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_factura USING :lhNumProceso; */ 
#line 1676 "./pc/CheckInter.pc"

{
#line 1676 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1676 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )488;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhNumProceso;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1676 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1676 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1676 "./pc/CheckInter.pc"
}

#line 1676 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }


    /* EXEC SQL PREPARE sql_delete_factura FROM :szCadenaDelete; */ 
#line 1688 "./pc/CheckInter.pc"

{
#line 1688 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1688 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )507;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1688 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1688 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1688 "./pc/CheckInter.pc"
}

#line 1688 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_factura USING  :lhNumProceso; */ 
#line 1700 "./pc/CheckInter.pc"

{
#line 1700 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1700 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )526;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhNumProceso;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1700 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1700 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1700 "./pc/CheckInter.pc"
}

#line 1700 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Interfaz **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    return (TRUE);
}

/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertInterfaz()                                 * */
/* * Inicilaiza Sql para Insertar Interfaz                                 * */
/* ************************************************************************* */
void vfnInitCadenaInsertInterfaz(char *szCadena)
{
    sprintf(szCadena,
            "INSERT INTO FA_HISTINTERFACT ( "
						"NUM_PROCESO       ,"
						"NUM_VENTA         ,"
						"COD_MODGENER      ,"
						"COD_ESTADOC       ,"
						"COD_ESTPROC       ,"
						"COD_TIPMOVIMIEN   ,"
						"COD_CATRIBUT      ,"
						"COD_CATIMPOSITIVA ,"
						"COD_TIPDOCUM      ,"
						"NUM_FOLIO         ,"
						"NUM_FOLIOREL      ,"
						"FEC_INGRESO       ,"
						"FEC_FACTURACION   ,"
						"FEC_IMPRESION     ,"
						"FEC_FOLIACION     ,"
						"FEC_VISACION      ,"
						"FEC_PASOCOBRO     ,"
						"FEC_CIERRE        ,"
						"FEC_VENCIMIENTO   ,"
						"NUM_CUOTAS        ,"
						"COD_MODVENTA      ,"
						"PREF_PLAZA)"
            "SELECT "
						"NUM_PROCESO       ,"
						"NUM_VENTA         ,"
						"COD_MODGENER      ,"
						"COD_ESTADOC       ,"
						"COD_ESTPROC       ,"
						"COD_TIPMOVIMIEN   ,"
						"COD_CATRIBUT      ,"
						"COD_CATIMPOSITIVA ,"
						"COD_TIPDOCUM      ,"
						"NUM_FOLIO         ,"
						"NUM_FOLIOREL      ,"
						"FEC_INGRESO       ,"
						"FEC_FACTURACION   ,"
						"FEC_IMPRESION     ,"
						"FEC_FOLIACION     ,"
						"FEC_VISACION      ,"
						"FEC_PASOCOBRO     ,"
						"FEC_CIERRE        ,"
						"FEC_VENCIMIENTO   ,"
						"NUM_CUOTAS        ,"
						"COD_MODVENTA      ,"
						"PREF_PLAZA		    "
            "FROM   FA_INTERFACT "
            "WHERE  NUM_PROCESO = :lhNumProceso "
            "AND COD_APLIC = 'FAC' "); /* Incorporado por PGonzaleg 31-01-2002 */
    return;
}


/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteInterfaz ()                                 * */
/* * Inicilaiza Sql para Deletear Interfaz                                 * */
/* ************************************************************************* */
void vfnInitCadenaDeleteInterfaz  (char *szCadena)
{
    sprintf(szCadena,
        "DELETE "
        "FROM    FA_INTERFACT  "
        "WHERE   NUM_PROCESO = :lhNumProceso "
        "AND COD_APLIC = 'FAC' "); /* Incorporado por PGonzaleg 31-01-2002 */
    return;
}


/*---------------------------------------------------------------------------------------------*/

/* ************************************************************************* */
/* * Funcion bfnDBEliminarFactura( ),                                      * */
/* * Eliminamos Facturas ya pasadas a Historicas                           * */
/* ************************************************************************* */
BOOL bfnDBEliminarFactura(long lIndOrdenTotal)
{
    char modulo[]="bfnDBEliminarFactura";

    char    szCadenaDelete[512]  ="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1801 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1803 "./pc/CheckInter.pc"


	lhIndOrdenTotal = lIndOrdenTotal;
	
    vDTrazasLog  (modulo, "\t\t**  Paso Eliminar Facturas **"
    					  "\n\t\t==> Ind.OrdenTotal   [%ld]"
                          ,LOG05,lIndOrdenTotal);

    vfnInitCadenaDeleteFactura (szCadenaDelete);

    /* EXEC SQL PREPARE sql_delete_factura FROM :szCadenaDelete; */ 
#line 1813 "./pc/CheckInter.pc"

{
#line 1813 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1813 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )545;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1813 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1813 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1813 "./pc/CheckInter.pc"
}

#line 1813 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_factura USING  :lhIndOrdenTotal; */ 
#line 1825 "./pc/CheckInter.pc"

{
#line 1825 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1825 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )564;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1825 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1825 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1825 "./pc/CheckInter.pc"
}

#line 1825 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Facturas **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    return (TRUE);
}

/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteFactura ()                                 * */
/* * Inicilaiza Sql para Deletear Facturas                                 * */
/* ************************************************************************* */
void vfnInitCadenaDeleteFactura  (char *szCadena)
{

    sprintf(szCadena,
        "DELETE "
        "FROM    FA_FACTDOCU_NOCICLO  "
        "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}

/* ************************************************************************* */
/* * Funcion bfnDBPasarHistTecno( ),                                     * */
/* * Pasamos a Historicas Abonados Facturados                              * */
/* ************************************************************************* */
BOOL bfnDBPasarHistTecno(long lIndOrdenTotal)
{
	char modulo[]="bfnDBPasarHistTecno";

    char    szCadenaInsert[2048] ="";
    char    szCadenaDelete[512]  ="";

    long    lFilasInsert=0          ;
    long    lFilasDelete=0          ;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 
#line 1867 "./pc/CheckInter.pc"

    	 int lhIndOrdenTotal	= 0;
    /* EXEC SQL END DECLARE SECTION; */ 
#line 1869 "./pc/CheckInter.pc"


	lhIndOrdenTotal =lIndOrdenTotal ;
	
    vDTrazasLog  (modulo,"\t\t**  Paso Historico Tenologia de Factura **"
    					 "\n\t\t==> Ind.OrdenTotal   [%ld]"
                         ,LOG05,lIndOrdenTotal);

    vfnInitCadenaInsertTecno (szCadenaInsert);
    vfnInitCadenaDeleteTecno (szCadenaDelete);

    /* EXEC SQL PREPARE sql_insert_abonado FROM :szCadenaInsert; */ 
#line 1880 "./pc/CheckInter.pc"

{
#line 1880 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1880 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )583;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaInsert;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )2048;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1880 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1880 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1880 "./pc/CheckInter.pc"
}

#line 1880 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Insert Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Insert Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_insert_abonado USING :lhIndOrdenTotal; */ 
#line 1892 "./pc/CheckInter.pc"

{
#line 1892 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1892 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )602;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1892 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1892 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1892 "./pc/CheckInter.pc"
}

#line 1892 "./pc/CheckInter.pc"


    if ( SQLCODE )
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Insert Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Insert Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasInsert=(SQLROWS>0?SQLROWS:0);

    /* EXEC SQL PREPARE sql_delete_abonado FROM :szCadenaDelete; */ 
#line 1905 "./pc/CheckInter.pc"

{
#line 1905 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1905 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )621;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)szCadenaDelete;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )512;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1905 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1905 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1905 "./pc/CheckInter.pc"
}

#line 1905 "./pc/CheckInter.pc"


    if (SQLCODE)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-PREPARE Delete Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-PREPARE Delete Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return (FALSE);
    }


    /* EXEC SQL EXECUTE sql_delete_abonado USING  :lhIndOrdenTotal; */ 
#line 1917 "./pc/CheckInter.pc"

{
#line 1917 "./pc/CheckInter.pc"
    struct sqlexd sqlstm;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqlvsn = 10;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.arrsiz = 11;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqladtp = &sqladt;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqltdsp = &sqltds;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.stmt = "";
#line 1917 "./pc/CheckInter.pc"
    sqlstm.iters = (unsigned int  )1;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.offset = (unsigned int  )640;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.cud = sqlcud0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqlest = (unsigned char  *)&sqlca;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqlety = (unsigned short)256;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.occurs = (unsigned int  )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqhstv[0] = (         void  *)&lhIndOrdenTotal;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqhsts[0] = (         int  )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqindv[0] = (         void  *)0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqinds[0] = (         int  )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqharm[0] = (unsigned int  )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqadto[0] = (unsigned short )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqtdso[0] = (unsigned short )0;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqphsv = sqlstm.sqhstv;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqphsl = sqlstm.sqhstl;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqphss = sqlstm.sqhsts;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqpind = sqlstm.sqindv;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqpins = sqlstm.sqinds;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqparm = sqlstm.sqharm;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqparc = sqlstm.sqharc;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqpadto = sqlstm.sqadto;
#line 1917 "./pc/CheckInter.pc"
    sqlstm.sqptdso = sqlstm.sqtdso;
#line 1917 "./pc/CheckInter.pc"
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
#line 1917 "./pc/CheckInter.pc"
}

#line 1917 "./pc/CheckInter.pc"


    if (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)
    {
        vDTrazasError(modulo,  "\n\t**  Error en SQL-EXECUTE Delete Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasLog  (modulo,  "\n\t**  Error en SQL-EXECUTE Delete Tenologia **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    lFilasDelete=(SQLROWS>0?SQLROWS:0);

    if (lFilasInsert != lFilasDelete)
    {
        vDTrazasLog  (modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        vDTrazasError(modulo,   "\n\t**  Error Filas Insertadas != Filas Deletadas **",LOG01);
        return (FALSE);
    }
    return (TRUE);
}


/* ************************************************************************* */
/* * Funcion vfnInitCadenaInsertAbonado ()                                 * */
/* * Inicilaiza Sql para Insertar Abonados de Facturas                     * */
/* ************************************************************************* */
void vfnInitCadenaInsertTecno(char *szCadena)
{

    sprintf(szCadena,
            "INSERT INTO FA_HISTECNO_TH_19010102 ( "
                    "IND_ORDENTOTAL   , COD_CONCEPTO , "
                    "COLUMNA      , COD_TECNOLOGIA   , "
                    "PRC_TECNOLOGIA ) "
            "SELECT "
                    "IND_ORDENTOTAL   , COD_CONCEPTO , "
                    "COLUMNA      , COD_TECNOLOGIA   , "
                    "PRC_TECNOLOGIA    "
            "FROM   FA_FACTECNO_TO_NOCICLO "
            "WHERE  IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
}

/* ************************************************************************* */
/* * Funcion vfnInitCadenaDeleteTecno ()                                 * */
/* * Inicilaiza Sql para Deletear Abonados de Facturas                     * */
/* ************************************************************************* */
void vfnInitCadenaDeleteTecno (char *szCadena )
{

    sprintf(szCadena,
        "DELETE "
        "FROM    FA_FACTECNO_TO_NOCICLO  "
        "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal ");
    return;
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
