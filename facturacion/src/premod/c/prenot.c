
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
    "./pc/prenot.pc"
};


static unsigned int sqlctx = 866091;


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
   unsigned char  *sqhstv[43];
   unsigned long  sqhstl[43];
            int   sqhsts[43];
            short *sqindv[43];
            int   sqinds[43];
   unsigned long  sqharm[43];
   unsigned long  *sqharc[43];
   unsigned short  sqadto[43];
   unsigned short  sqtdso[43];
} sqlstm = {12,43};

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

 static const char *sq0004 = 
"select  /*+  index (FA_PREFACTURA FK_FA_PREFACTURA)  +*/ NUM_PROCESO ,COD_CL\
IENTE ,COD_CONCEPTO ,COLUMNA ,COD_PRODUCTO ,COD_MONEDA ,TO_CHAR(FEC_VALOR,:b0)\
 ,TO_CHAR(FEC_EFECTIVIDAD,:b0) ,IMP_CONCEPTO ,IMP_MONTOBASE ,IMP_FACTURABLE ,C\
OD_REGION ,COD_PROVINCIA ,COD_CIUDAD ,COD_MODULO ,COD_PLANCOM ,IND_FACTUR ,COD\
_CATIMPOS ,IND_ESTADO ,COD_TIPCONCE ,NUM_UNIDADES ,COD_CICLFACT ,COD_CONCEREL \
,COLUMNA_REL ,NUM_ABONADO ,NUM_TERMINAL ,CAP_CODE ,NUM_SERIEMEC ,NUM_SERIELE ,\
FLAG_IMPUES ,FLAG_DTO ,PRC_IMPUESTO ,VAL_DTO ,TIP_DTO ,NUM_VENTA ,NUM_TRANSACC\
ION ,MES_GARANTIA ,IND_ALTA ,IND_SUPERTEL ,NUM_PAQUETE ,IND_CUOTA ,NUM_CUOTAS \
,ORD_CUOTA  from FA_PREFACTURA where NUM_PROCESO=:b2           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,485,0,260,86,0,0,24,7,0,1,0,1,5,0,0,1,97,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
116,0,0,2,493,0,260,144,0,0,24,7,0,1,0,1,5,0,0,1,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
227,0,0,3,0,0,273,372,0,0,1,1,0,1,0,1,97,0,0,
246,0,0,3,0,0,301,390,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
277,0,0,3,0,0,269,401,0,0,35,0,0,1,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,
5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,
0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,
432,0,0,3,0,0,271,509,0,0,0,0,0,1,0,
447,0,0,4,685,0,265,677,0,0,3,3,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,
474,0,0,4,0,0,269,681,0,0,43,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
661,0,0,4,0,0,271,728,0,0,0,0,0,1,0,
676,0,0,4,0,0,269,864,0,0,43,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
863,0,0,5,216,0,261,968,0,0,7,7,0,1,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,
906,0,0,6,216,0,261,983,0,0,7,7,0,1,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,
};


/*****************************************************************************/
/* Funcion    : prenot.pc                                                    */
/* Descripcion: Funciones que recoge de Fa_HistDocu y Fa_HistConc tanto la   */
/*              cabecera, como los detalles de Conceptos del Documento (Fac- */
/*              tura) a modificar (CodTipConce del Tipo Descuento y del Tipo */
/*              Impuesto) para aplicarlos sobre los Conceptos ya modificados */
/*              existentes en Fa_Presupuesto.                                */
/* Fecha      : 23-04-1997                                                   */
/* Autor      : Javier Garcia Paredes                                        */
/*****************************************************************************/

#define _PRENOT_PC_

#include <prenot.h>

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

/* EXEC SQL BEGIN DECLARE SECTION; */ 

     static char   szFormatoFec[17];    /* EXEC SQL VAR szFormatoFec          IS STRING(17) ; */ 

/* EXEC SQL END DECLARE SECTION  ; */ 

	

/*---------------------------------------------------------------------------*/
/* QUITA LOS ESPACIOS EN BLANCO AL INICIO Y AL FINAL DE UNA CADENA DE 	     */
/* CARACTERES					                             */
/*---------------------------------------------------------------------------*/
char * szfnTrim2(char * strin)
{
	int  i= 0,l=0;
	char strtmps[8192];
  
	memset(strtmps, 0, 256);
	
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

/*****************************************************************************/
/*                         funcion : bIFNotas                                */
/* -Funcion que carga la Informacion del Documento (Factura) a modificar, so-*/
/*  lo se recogen los Conceptos de Tipo Impuesto y Descuento.                */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bfnIFNotas (void)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 


    static char   szhLetra          [2];    /* EXEC SQL VAR szhLetra          IS STRING(2) ; */ 

    static char   szhIndOrdenTotal [13];    /* EXEC SQL VAR szhIndOrdenTotal  IS STRING(13); */ 

    static char   szhFecEmision    [15];    /* EXEC SQL VAR szhFecEmision     IS STRING(15); */ 

    static char   sz10Ceros        [11];    /* EXEC SQL VAR sz10Ceros         IS STRING(11); */ 
      
    /* EXEC SQL END DECLARE SECTION  ; */ 


    static BOOL         bOptProceso = FALSE ;
    static ENLACEHIST   stEnlaceHist        ;

    memset(&stEnlaceHist,0,sizeof(ENLACEHIST));


    vDTrazasLog (szExeName,
               "\n\t\t* Cargando Impuestos y Descuentos para NOTA"
               "\n\t\t=> Num.Secuenci   [%ld]"
               "\n\t\t=> Letra          [%s] "
               "\n\t\t=> Cod.TipDocum   [%d] "
               "\n\t\t=> Cod.VendedorAg.[%ld]"
               "\n\t\t=> Cod.CentrEmi   [%ld]",LOG03,
               stProceso.lNumSecuNot  , stProceso.szLetraNot           ,
               stProceso.iCodTipDocNot, stProceso.lCodVendedorAgenteNot,
               stProceso.iCodCentrNot);


    /* EXEC SQL SELECT index (FA_HISTDOCU PK_FA_HISTDOCU)  */
    strcpy(szFormatoFec,"YYYYMMDDHH24MISS");
    vDTrazasLog ("","NMV:se buscaran datos en FA_HISTDOCU\n",LOG05); 
    /* EXEC SQL SELECT NUM_SECUENCI                            ,
                    LETRA                                   ,
                    COD_TIPDOCUM                            ,
                    COD_VENDEDOR_AGENTE                     ,
                    COD_CENTREMI                            ,
                    TO_CHAR (IND_ORDENTOTAL)                ,
                    TO_CHAR (FEC_EMISION,:szFormatoFec),
                    COD_CLIENTE                             ,
                    PREF_PLAZA                              ,
                    NUM_FOLIO                               ,
                    COD_CATIMPOS                            ,
                    COD_PLANCOM                             ,
                    COD_CICLFACT			    ,
                    COD_ZONAIMPO 			    ,
                    COD_PLAZA				    ,
                    COD_OPERADORA 			    ,
                    nvl(COD_OFICINA,:stDatosGener.szCodOficCentral) /o Homologado por PGG 23-06-2003 12:56hrs. CH-160520030732 o/
            INTO    :stNota.lNumSecuenci      	,
                    :szhLetra                 	,
                    :stNota.iCodTipDocum      	,
                    :stNota.lCodVendedorAgente	,
                    :stNota.iCodCentrEmi      	,
                    :szhIndOrdenTotal         	,
                    :szhFecEmision            	,
                    :stNota.lCodCliente       	,
                    :stNota.szPrefPlaza         ,
                    :stNota.lNumFolio         	,
                    :stNota.iCodCatImpos      	,
                    :stNota.lCodPlanCom       	,
                    :stNota.lCodCiclFact		,
                    :stNota.iCodZonaImpo	,
                    :stNota.szCodPlaza		,
                    :stNota.szCodOperadora	,
                    :stNota.szCodOficina
            FROM    FA_HISTDOCU
            WHERE   NUM_SECUENCI        = :stProceso.lNumSecuNot
            AND     LETRA               = :stProceso.szLetraNot
            AND     COD_TIPDOCUM        = :stProceso.iCodTipDocNot
            AND     COD_VENDEDOR_AGENTE = :stProceso.lCodVendedorAgenteNot
            AND     COD_CENTREMI        = :stProceso.iCodCentrNot; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NUM_SECUENCI ,LETRA ,COD_TIPDOCUM ,COD_VENDEDOR_AG\
ENTE ,COD_CENTREMI ,TO_CHAR(IND_ORDENTOTAL) ,TO_CHAR(FEC_EMISION,:b0) ,COD_CLI\
ENTE ,PREF_PLAZA ,NUM_FOLIO ,COD_CATIMPOS ,COD_PLANCOM ,COD_CICLFACT ,COD_ZONA\
IMPO ,COD_PLAZA ,COD_OPERADORA ,nvl(COD_OFICINA,:b1) into :b2,:b3,:b4,:b5,:b6,\
:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18  from FA_HISTDOCU whe\
re ((((NUM_SECUENCI=:b19 and LETRA=:b20) and COD_TIPDOCUM=:b21) and COD_VENDED\
OR_AGENTE=:b22) and COD_CENTREMI=:b23)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szFormatoFec;
    sqlstm.sqhstl[0] = (unsigned long )17;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(stDatosGener.szCodOficCentral);
    sqlstm.sqhstl[1] = (unsigned long )3;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&(stNota.lNumSecuenci);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhLetra;
    sqlstm.sqhstl[3] = (unsigned long )2;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&(stNota.iCodTipDocum);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&(stNota.lCodVendedorAgente);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&(stNota.iCodCentrEmi);
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)szhIndOrdenTotal;
    sqlstm.sqhstl[7] = (unsigned long )13;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)szhFecEmision;
    sqlstm.sqhstl[8] = (unsigned long )15;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&(stNota.lCodCliente);
    sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)(stNota.szPrefPlaza);
    sqlstm.sqhstl[10] = (unsigned long )11;
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&(stNota.lNumFolio);
    sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&(stNota.iCodCatImpos);
    sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)&(stNota.lCodPlanCom);
    sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)&(stNota.lCodCiclFact);
    sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&(stNota.iCodZonaImpo);
    sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)(stNota.szCodPlaza);
    sqlstm.sqhstl[16] = (unsigned long )6;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)0;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)(stNota.szCodOperadora);
    sqlstm.sqhstl[17] = (unsigned long )6;
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)(stNota.szCodOficina);
    sqlstm.sqhstl[18] = (unsigned long )3;
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&(stProceso.lNumSecuNot);
    sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)(stProceso.szLetraNot);
    sqlstm.sqhstl[20] = (unsigned long )2;
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)&(stProceso.iCodTipDocNot);
    sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         short *)0;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)&(stProceso.lCodVendedorAgenteNot);
    sqlstm.sqhstl[22] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)&(stProceso.iCodCentrNot);
    sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
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


	
    strcpy(stNota.szCodOperadora, szfnTrim2(stNota.szCodOperadora));
    strcpy(stNota.szPrefPlaza	, szfnTrim2(stNota.szPrefPlaza));
    
    vDTrazasLog ("","PGG:stNota.szCodOperadora[%s]\n", LOG05, stNota.szCodOperadora);

    if ((SQLCODE != SQLOK) && (SQLCODE != SQLNOTFOUND))
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_HistDocu\n",szfnORAerror ());
        return FALSE;
    }
    if (SQLCODE == SQLNOTFOUND)
    {

        strcpy(szFormatoFec,"YYYYMMDDHH24MISS");
        strcpy(sz10Ceros,"0000000000");
        
        vDTrazasLog ("","NMV:se buscaran datos en FA_FACTDOCU_NOCICLO\n",LOG05);
        /* EXEC SQL SELECT NUM_SECUENCI                            ,
                        LETRA                                   ,
                        COD_TIPDOCUM                            ,
                        COD_VENDEDOR_AGENTE                     ,
                        COD_CENTREMI                            ,
                        TO_CHAR (IND_ORDENTOTAL)                ,
                        TO_CHAR (FEC_EMISION,:szFormatoFec),
                        COD_CLIENTE                             ,
                        NVL(PREF_PLAZA,:sz10Ceros)   		,
                        NUM_FOLIO                               ,
                        COD_CATIMPOS                            ,
                        COD_PLANCOM                             ,
                        COD_CICLFACT				,
                        COD_ZONAIMPO				,
                        COD_PLAZA				,
                        COD_OPERADORA				,
                        COD_OFICINA
                INTO    :stNota.lNumSecuenci      ,
                        :szhLetra                 ,
                        :stNota.iCodTipDocum      ,
                        :stNota.lCodVendedorAgente,
                        :stNota.iCodCentrEmi      ,
                        :szhIndOrdenTotal         ,
                        :szhFecEmision            ,
                        :stNota.lCodCliente       ,
                        :stNota.szPrefPlaza       ,
                        :stNota.lNumFolio         ,
                        :stNota.iCodCatImpos      ,
                        :stNota.lCodPlanCom       ,
                        :stNota.lCodCiclFact	  ,
                        :stNota.iCodZonaImpo,
                        :stNota.szCodPlaza,
                        :stNota.szCodOperadora,
                        :stNota.szCodOficina
                FROM    FA_FACTDOCU_NOCICLO
                WHERE   NUM_SECUENCI        = :stProceso.lNumSecuNot
                AND     LETRA               = :stProceso.szLetraNot
                AND     COD_TIPDOCUM        = :stProceso.iCodTipDocNot
                AND     COD_VENDEDOR_AGENTE = :stProceso.lCodVendedorAgenteNot
                AND     COD_CENTREMI        = :stProceso.iCodCentrNot; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 24;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NUM_SECUENCI ,LETRA ,COD_TIPDOCUM ,COD_VENDEDO\
R_AGENTE ,COD_CENTREMI ,TO_CHAR(IND_ORDENTOTAL) ,TO_CHAR(FEC_EMISION,:b0) ,COD\
_CLIENTE ,NVL(PREF_PLAZA,:b1) ,NUM_FOLIO ,COD_CATIMPOS ,COD_PLANCOM ,COD_CICLF\
ACT ,COD_ZONAIMPO ,COD_PLAZA ,COD_OPERADORA ,COD_OFICINA into :b2,:b3,:b4,:b5,\
:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18  from FA_FACTDOCU\
_NOCICLO where ((((NUM_SECUENCI=:b19 and LETRA=:b20) and COD_TIPDOCUM=:b21) an\
d COD_VENDEDOR_AGENTE=:b22) and COD_CENTREMI=:b23)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )116;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szFormatoFec;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)sz10Ceros;
        sqlstm.sqhstl[1] = (unsigned long )11;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&(stNota.lNumSecuenci);
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhLetra;
        sqlstm.sqhstl[3] = (unsigned long )2;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&(stNota.iCodTipDocum);
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&(stNota.lCodVendedorAgente);
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&(stNota.iCodCentrEmi);
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)szhIndOrdenTotal;
        sqlstm.sqhstl[7] = (unsigned long )13;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)szhFecEmision;
        sqlstm.sqhstl[8] = (unsigned long )15;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&(stNota.lCodCliente);
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)(stNota.szPrefPlaza);
        sqlstm.sqhstl[10] = (unsigned long )11;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&(stNota.lNumFolio);
        sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&(stNota.iCodCatImpos);
        sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&(stNota.lCodPlanCom);
        sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&(stNota.lCodCiclFact);
        sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&(stNota.iCodZonaImpo);
        sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)(stNota.szCodPlaza);
        sqlstm.sqhstl[16] = (unsigned long )6;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)(stNota.szCodOperadora);
        sqlstm.sqhstl[17] = (unsigned long )6;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)(stNota.szCodOficina);
        sqlstm.sqhstl[18] = (unsigned long )3;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&(stProceso.lNumSecuNot);
        sqlstm.sqhstl[19] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)0;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)(stProceso.szLetraNot);
        sqlstm.sqhstl[20] = (unsigned long )2;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)0;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&(stProceso.iCodTipDocNot);
        sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)0;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&(stProceso.lCodVendedorAgenteNot);
        sqlstm.sqhstl[22] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)0;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)&(stProceso.iCodCentrNot);
        sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         short *)0;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
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



	strcpy(stNota.szCodOperadora	, szfnTrim2(stNota.szCodOperadora));
	strcpy(stNota.szPrefPlaza	, szfnTrim2(stNota.szPrefPlaza));

        if(SQLCODE!=SQLOK){
            vDTrazasLog ("","NMV:ERROR:QRY FA_FACTDOCU_NOCICLO\n",LOG05);
            iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_FactDocu_NoCiclo\n",szfnORAerror ());
            return FALSE;
        }
        vDTrazasLog ("","PGG:stNota.szCodOperadora[%s]\n", LOG05, stNota.szCodOperadora);
        vDTrazasLog ("","NMV:FOUNDED:QRY FA_FACTDOCU_NOCICLO(%s|%s|%s)\n",LOG05,stNota.szCodPlaza,stNota.szCodOperadora,stNota.szCodOficina);
        
        
        
        vDTrazasLog ("","PGG -  stNota.szPrefPlaza	[%s]\n",LOG05, stNota.szPrefPlaza);
        
        
        
        bOptProceso = TRUE;
    }
    vDTrazasLog ("","NMV:FOUNDED:QRY FA_HISTDOCU(%s|%s|%s)\n",LOG05,stNota.szCodPlaza,stNota.szCodOperadora,stNota.szCodOficina);

    stEnlaceHist.lCodCiclFact = stNota.lCodCiclFact;
    if (!bOptProceso) 
        if (!bGetEnlaceHist(&stEnlaceHist))
            return FALSE;

    if (SQLCODE == SQLOK)
    {
        stCliente.lCodCliente = stNota.lCodCliente ;
        stCliente.lCodPlanCom = stNota.lCodPlanCom ;
        stCliente.iCodCatImpos= stNota.iCodCatImpos;

        strcpy (stNota.szIndOrdenTotal, szhIndOrdenTotal);
        strcpy (stNota.szLetra        , szhLetra        );
        strcpy (stNota.szFecEmision   , szhFecEmision   );

        /* Carga Los Impuestos y Descuentos */
        if (stProceso.iIndNotaCredC == 0)
        {
            if (!bfnDBCargaHistConc (stNota.szIndOrdenTotal, &stNota, stEnlaceHist, bOptProceso))
                 return FALSE;

            vDTrazasLog (szExeName,
                     "\n\t\t* Numero de Conceptos Descuentos e Impuestos [%d]",
                     LOG03,stNota.iNumConceptos);
        }
        if (!bfnCargaConceptosNotas ())
             return FALSE;
        vDTrazasLog (szExeName,"\n\t\t* Fin Carga Conceptos Notas", LOG04);

        if (!bfnCargaAbonoCli (stEnlaceHist, bOptProceso))
             return FALSE;
    }
    return TRUE;
}/**************************** Final bIFNotas ********************************/

/*****************************************************************************/
/*                           funcion : bfnDBCargaHistConc                    */
/*****************************************************************************/
static BOOL bfnDBCargaHistConc (char        *szIndOrdenTotal,
                                NOTACD      *pstNota,
                                ENLACEHIST  pstEnHist,
                                BOOL        pbOptProc)
{
  static    int     i = 0           ;
  static    char    szSql[4096]=""  ;
  static    long    lhIndOrdenTotal ;
  static    char    szNomTabla[50]  ;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char   szhIndOrdenTotal [13];  /* EXEC SQL VAR szhIndOrdenTotal  IS STRING(13); */ 

  static int    ihCodConcepto        ;
  static long   lhColumna            ;
  static char   szhCodMoneda      [4];  /* EXEC SQL VAR szhCodMoneda      IS STRING(4) ; */ 

  static int    ihCodProducto        ;
  static int    ihCodTipConce        ;
  static char   szhFecValor      [15];  /* EXEC SQL VAR szhFecValor       IS STRING(15); */ 

  static char   szhFecEfectividad[15];  /* EXEC SQL VAR szhFecEfectividad IS STRING(15); */ 

  static double dhImpConcepto        ;
  static char   szhCodRegion      [4];  /* EXEC SQL VAR szhCodRegion      IS STRING(4) ; */ 

  static char   szhCodProvincia   [6];  /* EXEC SQL VAR szhCodProvincia   IS STRING(6) ; */ 

  static char   szhCodCiudad      [6];  /* EXEC SQL VAR szhCodCiudad      IS STRING(6) ; */ 

  static double dhImpMontoBase       ;
  static short  shIndFactur          ;
  static double dhImpFacturable      ;
  static short  shIndSuperTel        ;
  static long   lhNumAbonado         ;
  static int    ihCodPortador        ;
  static char   szhDesConcepto   [61];  /* EXEC SQL VAR szhDesConcepto    IS STRING(61); */ 

  static int    ihNumCuotas          ;
  static int    ihOrdCuota           ;
  static long   lhNumUnidades        ; /* Incorporado por PGonzaleg 4-03-2002 */
  static char   szhNumSerieMec   [26];  /* EXEC SQL VAR szhNumSerieMec    IS STRING(26); */ 

  static char   szhNumSerieLe    [26];  /* EXEC SQL VAR szhNumSerieLe     IS STRING(26); */ 

  static float  fhPrcImpuesto        ;
  static double dhValDto             ;
  static int    ihTipDto             ;
  static int    ihMesGarantia        ;
  static char   szhNumGuia       [11];  /* EXEC SQL VAR szhNumGuia        IS STRING(11); */ 

  static short  shIndAlta            ;
  static int    ihNumPaquete         ;
  static short  shFlagImpues         ;
  static short  shFlagDto            ;
  static int    ihCodConceRel        ;
  static long   lhColumnaRel         ;
  static long   lhSeqCuotas          ;

  static short  i_shNumCuotas        ;
  static short  i_shOrdCuota         ;
  static short  i_shNumUnidades      ;
  static short  i_shNumSerieMec      ;
  static short  i_shNumSerieLe       ;
  static short  i_shPrcImpuesto      ;
  static short  i_shValDto           ;
  static short  i_shTipDto           ;
  static short  i_shMesGarantia      ;
  static short  i_shNumGuia          ;
  static short  i_shIndAlta          ;
  static short  i_shNumPaquete       ;
  static short  i_shFlagImpues       ;
  static short  i_shFlagDto          ;
  static short  i_shCodConceRel      ;
  static short  i_shColumnaRel       ;
  static short  i_shSeqCuotas        ;
  
  static int    iTres=3;
  /* EXEC SQL END DECLARE SECTION  ; */ 


    lhIndOrdenTotal = atol(szIndOrdenTotal);

    vDTrazasLog (szExeName, "\n\t\t* Parametro de Entrada a Fa_HistConc"
                            "\n\t\t=>Ind.OrdenTotal  [%ld]"
                            "\n\t\t=>En Proceso      [%s]"
                            ,LOG03,lhIndOrdenTotal,(pbOptProc?"NO":"SI"));

    if (!pbOptProc)
    {
        strcpy(szNomTabla,pstEnHist.szDetConceptos);
    }
    else
    {
        strcpy(szNomTabla,"FA_FACTCONC_NOCICLO");
    }

    strcpy(szFormatoFec,"YYYYMMDDHH24MISS");
    
    sprintf(szSql,
        "SELECT COD_CONCEPTO     , "
                "COLUMNA         , "
                "COD_MONEDA      , "
                "COD_PRODUCTO    , "
                "COD_TIPCONCE    , "
                "TO_CHAR (FEC_VALOR      , :szFormatoFec ), "
                "TO_CHAR (FEC_EFECTIVIDAD, :szFormatoFec ), "
                "IMP_CONCEPTO    , "
                "COD_REGION      , "
                "COD_PROVINCIA   , "
                "COD_CIUDAD      , "
                "IMP_MONTOBASE   , "
                "IND_FACTUR      , "
                "IMP_FACTURABLE  , "
                "IND_SUPERTEL    , "
                "NUM_ABONADO     , "
                "COD_PORTADOR    , "
                "DES_CONCEPTO    , "
                "NUM_CUOTAS      , "
                "ORD_CUOTA       , "
                "NUM_UNIDADES    , "
                "NUM_SERIEMEC    , "
                "NUM_SERIELE     , "
                "PRC_IMPUESTO    , "
                "VAL_DTO         , "
                "TIP_DTO         , "
                "MES_GARANTIA    , "
                "NUM_GUIA        , "
                "IND_ALTA        , "
                "NUM_PAQUETE     , "
                "FLAG_IMPUES     , "
                "FLAG_DTO        , "
                "COD_CONCEREL    , "
                "COLUMNA_REL     , "
                "SEQ_CUOTAS        "
       "FROM    %s "
       "WHERE   IND_ORDENTOTAL = :lhIndOrdenTotal "
       "AND     COD_TIPCONCE   < :iTres "             /* Descuentos e Impuestos */
       ,szNomTabla);

    /* EXEC SQL PREPARE sql_detfact_not FROM :szSql; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )227;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szSql;
    sqlstm.sqhstl[0] = (unsigned long )4096;
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
        iDError (szExeName,ERR000,vInsertarIncidencia,"PREPARE sql_detfact_not",szfnORAerror ());
        vDTrazasError(szExeName,"\n\t**  Error en SQL-PREPARE sql_detfact_not **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    /* EXEC SQL DECLARE Cur_HistConc CURSOR FOR sql_detfact_not; */ 

    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"DECLARE Cur_HistConc",szfnORAerror ());
        vDTrazasError(szExeName,"\n\t**  Error en SQL-DECLARE Cur_HistConc **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    /* EXEC SQL OPEN Cur_HistConc USING :szFormatoFec, :szFormatoFec, :lhIndOrdenTotal, :iTres ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )246;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szFormatoFec;
    sqlstm.sqhstl[0] = (unsigned long )17;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szFormatoFec;
    sqlstm.sqhstl[1] = (unsigned long )17;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhIndOrdenTotal;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iTres;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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


    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"OPEN Cur_HistConc",szfnORAerror ());
        vDTrazasError(szExeName,"\n\t**  Error en SQL-OPEN CURSOR Cur_HistConc **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  (FALSE);
    }

    while (SQLCODE == SQLOK)
    {
        /* EXEC SQL FETCH Cur_HistConc INTO  :ihCodConcepto                 ,
                                          :lhColumna                     ,
                                          :szhCodMoneda                  ,
                                          :ihCodProducto                 ,
                                          :ihCodTipConce                 ,
                                          :szhFecValor                   ,
                                          :szhFecEfectividad             ,
                                          :dhImpConcepto                 ,
                                          :szhCodRegion                  ,
                                          :szhCodProvincia               ,
                                          :szhCodCiudad                  ,
                                          :dhImpMontoBase                ,
                                          :shIndFactur                   ,
                                          :dhImpFacturable               ,
                                          :shIndSuperTel                 ,
                                          :lhNumAbonado                  ,
                                          :ihCodPortador                 ,
                                          :szhDesConcepto                ,
                                          :ihNumCuotas   :i_shNumCuotas  ,
                                          :ihOrdCuota    :i_shOrdCuota   ,
                                          :lhNumUnidades :i_shNumUnidades, /o Incorporado por PGonzaleg 4-03-2002 o/
                                          :szhNumSerieMec:i_shNumSerieMec,
                                          :szhNumSerieLe :i_shNumSerieLe ,
                                          :fhPrcImpuesto :i_shPrcImpuesto,
                                          :dhValDto      :i_shValDto     ,
                                          :ihTipDto      :i_shTipDto     ,
                                          :ihMesGarantia :i_shMesGarantia,
                                          :szhNumGuia    :i_shNumGuia    ,
                                          :shIndAlta     :i_shIndAlta    ,
                                          :ihNumPaquete  :i_shNumPaquete ,
                                          :shFlagImpues  :i_shFlagImpues ,
                                          :shFlagDto     :i_shFlagDto    ,
                                          :ihCodConceRel :i_shCodConceRel,
                                          :lhColumnaRel  :i_shColumnaRel ,
                                          :lhSeqCuotas   :i_shSeqCuotas  ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )277;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodConcepto;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhColumna;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodMoneda;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCodProducto;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&ihCodTipConce;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szhFecValor;
        sqlstm.sqhstl[5] = (unsigned long )15;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szhFecEfectividad;
        sqlstm.sqhstl[6] = (unsigned long )15;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&dhImpConcepto;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)szhCodRegion;
        sqlstm.sqhstl[8] = (unsigned long )4;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)szhCodProvincia;
        sqlstm.sqhstl[9] = (unsigned long )6;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)szhCodCiudad;
        sqlstm.sqhstl[10] = (unsigned long )6;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&dhImpMontoBase;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&shIndFactur;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&dhImpFacturable;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&shIndSuperTel;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&ihCodPortador;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)szhDesConcepto;
        sqlstm.sqhstl[17] = (unsigned long )61;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&ihNumCuotas;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&i_shNumCuotas;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&ihOrdCuota;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&i_shOrdCuota;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&lhNumUnidades;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&i_shNumUnidades;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)szhNumSerieMec;
        sqlstm.sqhstl[21] = (unsigned long )26;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&i_shNumSerieMec;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)szhNumSerieLe;
        sqlstm.sqhstl[22] = (unsigned long )26;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)&i_shNumSerieLe;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)&fhPrcImpuesto;
        sqlstm.sqhstl[23] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         short *)&i_shPrcImpuesto;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (unsigned char  *)&dhValDto;
        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         short *)&i_shValDto;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned long )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (unsigned char  *)&ihTipDto;
        sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         short *)&i_shTipDto;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned long )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (unsigned char  *)&ihMesGarantia;
        sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         short *)&i_shMesGarantia;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned long )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (unsigned char  *)szhNumGuia;
        sqlstm.sqhstl[27] = (unsigned long )11;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         short *)&i_shNumGuia;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned long )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (unsigned char  *)&shIndAlta;
        sqlstm.sqhstl[28] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         short *)&i_shIndAlta;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned long )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (unsigned char  *)&ihNumPaquete;
        sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         short *)&i_shNumPaquete;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned long )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (unsigned char  *)&shFlagImpues;
        sqlstm.sqhstl[30] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         short *)&i_shFlagImpues;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned long )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (unsigned char  *)&shFlagDto;
        sqlstm.sqhstl[31] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         short *)&i_shFlagDto;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned long )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (unsigned char  *)&ihCodConceRel;
        sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         short *)&i_shCodConceRel;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned long )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (unsigned char  *)&lhColumnaRel;
        sqlstm.sqhstl[33] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         short *)&i_shColumnaRel;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned long )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (unsigned char  *)&lhSeqCuotas;
        sqlstm.sqhstl[34] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         short *)&i_shSeqCuotas;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned long )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
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
            iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=>Fa_HistConc", szfnORAerror ());
        }
        if (SQLCODE == SQLOK)
        {
            if (pstNota->iNumConceptos >= MAX_CONCFACTUR)
            {
                iDError (szExeName,ERR035,vInsertarIncidencia);
                return   FALSE                                ;
            }
            else
            {
                i = pstNota->iNumConceptos;

                pstNota->A_HistConc.iCodConcepto [i] = ihCodConcepto;
                pstNota->A_HistConc.lColumna     [i] = lhColumna    ;
                pstNota->A_HistConc.iCodProducto [i] = ihCodProducto;
                pstNota->A_HistConc.iCodTipConce [i] = ihCodTipConce;
                pstNota->A_HistConc.dImpConcepto [i] = dhImpConcepto;

                strcpy (pstNota->A_HistConc.szCodMoneda      [i], szhCodMoneda);
                strcpy (pstNota->A_HistConc.szFecValor       [i], szhFecValor) ;
                strcpy (pstNota->A_HistConc.szFecEfectividad [i], szhFecEfectividad);

                strcpy (pstNota->A_HistConc.szCodRegion   [i], szhCodRegion)   ;
                strcpy (pstNota->A_HistConc.szCodProvincia[i], szhCodProvincia);
                strcpy (pstNota->A_HistConc.szCodCiudad   [i], szhCodCiudad)   ;

                pstNota->A_HistConc.dImpMontoBase [i] = dhImpMontoBase ;
                pstNota->A_HistConc.iIndFactur    [i] = shIndFactur    ;
                pstNota->A_HistConc.dImpFacturable[i] = dhImpFacturable;

                pstNota->A_HistConc.dImpFacturable[i] =
                        fnCnvDouble( pstNota->A_HistConc.dImpFacturable[i],USOFACT);

                pstNota->A_HistConc.iIndSuperTel  [i] = shIndSuperTel  ;
                pstNota->A_HistConc.lNumAbonado   [i] = lhNumAbonado   ;
                pstNota->A_HistConc.iCodPortador  [i] = ihCodPortador  ;

                strcpy (pstNota->A_HistConc.szDesConcepto [i], szhDesConcepto);

                pstNota->A_HistConc.iNumCuotas    [i] = (i_shNumCuotas  == -1)?-1:ihNumCuotas;
                pstNota->A_HistConc.iOrdCuota     [i] = (i_shOrdCuota   == -1)?-1:ihOrdCuota ;
                pstNota->A_HistConc.lNumUnidades  [i] = (i_shNumUnidades== -1)?-1:lhNumUnidades; /* Incorporado por PGonzaleg 4-03-2002 */

                strcpy (pstNota->A_HistConc.szNumSerieMec[i],(i_shNumSerieMec == -1)?"":szhNumSerieMec);
                strcpy (pstNota->A_HistConc.szNumSerieLe [i],(i_shNumSerieLe  == -1)?"":szhNumSerieLe );

                pstNota->A_HistConc.fPrcImpuesto  [i] = (i_shPrcImpuesto == -1)?-1:fhPrcImpuesto;
                pstNota->A_HistConc.dValDto       [i] = (i_shValDto      == -1)?-1:dhValDto     ;
                pstNota->A_HistConc.iTipDto       [i] = (i_shTipDto      == -1)?-1:ihTipDto     ;
                pstNota->A_HistConc.iMesGarantia  [i] = (i_shMesGarantia == -1)?-1:ihMesGarantia;

                strcpy (pstNota->A_HistConc.szNumGuia [i],(i_shNumGuia == -1)?"":szhNumGuia);

                pstNota->A_HistConc.iIndAlta      [i] =   (i_shIndAlta == -1)?-1:shIndAlta       ;
                pstNota->A_HistConc.iNumPaquete   [i] =   (i_shNumPaquete == -1)?-1:ihNumPaquete ;
                pstNota->A_HistConc.iFlagImpues   [i] =   (i_shFlagImpues == -1)?-1:shFlagImpues ;
                pstNota->A_HistConc.iFlagDto      [i] =   (i_shFlagDto    == -1)?-1:shFlagDto    ;
                pstNota->A_HistConc.iCodConceRel  [i] =   (i_shCodConceRel== -1)?-1:ihCodConceRel;
                pstNota->A_HistConc.lColumnaRel   [i] =   (i_shColumnaRel == -1)?-1:lhColumnaRel ;
                pstNota->A_HistConc.lSeqCuotas    [i] =   (i_shSeqCuotas  == -1)?-1:lhSeqCuotas  ;

                pstNota->iNumConceptos++;

            }/* fin else MAX_CONCFACTUR */
        }/* fin if sqlcode == sqlok */
    }/* fin while ... */

    if (SQLCODE == SQLNOTFOUND)
    {
        /* EXEC SQL CLOSE Cur_HistConc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )432;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close=>Fa_HistConc",szfnORAerror ());
    }
    return (SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnDBCargaHistConc ************************/


/*****************************************************************************/
/*                            funcion : bCargaConceptosNotas                 */
/* -Funcion que carga los Conceptos modificados de una factura que se encuen-*/
/*  tran en Fa_Presupuesto, con el fin de Aplicarle los Impuestos y Descuen- */
/*  tos. Solo aplicamos Impuestos o Descuentos a aquellos Conceptos que en su*/
/*  factura Origen (Documento Modificado) se les hayan aplicado, esto nos    */
/*  viene marcado por FlagImpues y FlagDto respectivamente. Para ello utili- */
/*  zamos ls estructura stPreFactura                                         */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bfnCargaConceptosNotas (void)
{
	static   int  i = 0  ;
	CONCEPTO stConcepto  ;

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		static long   lhNumProceso         ;
		static long   lhCodCliente         ;
		static int    ihCodConcepto        ;
		static long   lhColumna            ;
		static char   szhCodMoneda      [4];
		                         /* EXEC SQL VAR szhCodMoneda      IS STRING(4) ; */ 

		static int    ihCodProducto        ;
		static int    ihCodTipConce        ;
		static char   szhFecValor      [15];
		                         /* EXEC SQL VAR szhFecValor       IS STRING(15); */ 

		static char   szhFecEfectividad[15];
		                         /* EXEC SQL VAR szhFecEfectividad IS STRING(15); */ 

		static double dhImpConcepto        ;
		static char   szhCodRegion      [4];
		                         /* EXEC SQL VAR szhCodRegion      IS STRING(4) ; */ 

		static char   szhCodProvincia   [6];
		                         /* EXEC SQL VAR szhCodProvincia   IS STRING(6) ; */ 

		static char   szhCodCiudad      [6];
		                         /* EXEC SQL VAR szhCodCiudad      IS STRING(6) ; */ 

		static double dhImpMontoBase       ;
		static short  shIndFactur          ;
		static double dhImpFacturable      ;
		static char   szhCodModulo      [3];
		                         /* EXEC SQL VAR szhCodModulo      IS STRING(3) ; */ 

		static long   lhCodPlanCom         ;
		static int    ihCodCatImpos        ;
		static short  shIndEstado          ;
		static short  shIndSuperTel        ;
		static long   lhNumAbonado         ;
		static int    ihCodPortador        ;
		static char   szhDesConcepto   [61];
		                         /* EXEC SQL VAR szhDesConcepto    IS STRING(61); */ 

		static long   lhCodCiclFact        ;
		static char   szhNumTerminal   [16];
		                         /* EXEC SQL VAR szhNumTerminal    IS STRING(16); */ 

		static long   lhCapCode            ;
		static int    ihNumCuotas          ;
		static int    ihOrdCuota           ;
		static long   lhNumUnidades        ; /* Incorporado por PGonzaleg 4-03-2002 */
		static char   szhNumSerieMec   [26];
		                         /* EXEC SQL VAR szhNumSerieMec    IS STRING(26); */ 

		static char   szhNumSerieLe    [26];
		                         /* EXEC SQL VAR szhNumSerieLe     IS STRING(26); */ 

		static float  fhPrcImpuesto        ;
		static double dhValDto             ;
		static int    shTipDto             ;
		static int    ihMesGarantia        ;
		static char   szhNumGuia       [11];
		                         /* EXEC SQL VAR szhNumGuia        IS STRING(11); */ 

		static long   lhNumVenta           ;
		static long   lhNumTransaccion     ;
		static short  shIndAlta            ;
		static int    ihNumPaquete         ;
		static short  shFlagImpues         ;
		static short  shFlagDto            ;
		static int    ihCodConceRel        ;
		static long   lhColumnaRel         ;
		static short  shIndCuota           ;
		static short  i_shIndCuota         ;
		static short  i_shNumCuotas        ;
		static short  i_shOrdCuota         ;
		static short  i_shNumUnidades      ;
		static short  i_shNumSerieMec      ;
		static short  i_shNumSerieLe       ;
		static short  i_shPrcImpuesto      ;
		static short  i_shValDto           ;
		static short  i_shTipDto           ;
		static short  i_shMesGarantia      ;
		static short  i_shNumGuia          ;
		static short  i_shIndAlta          ;
		static short  i_shNumPaquete       ;
		static short  i_shFlagImpues       ;
		static short  i_shFlagDto          ;
		static short  i_shCodConceRel      ;
		static short  i_shColumnaRel       ;
		static short  i_shSeqCuotas        ;
		static short  i_shIndEstado        ;
		static short  i_shCodTipConce      ;
		static short  i_shCodModulo        ;
		static short  i_shCodCiclFact      ;
		static short  i_shNumTerminal      ;
		static short  i_shCapCode          ;
		static short  i_shCodPlanCom       ;
		static short  i_shCodCatImpos      ;
		static short  i_shNumVenta         ;
		static short  i_shNumTransaccion   ;
		static short  i_shNumAbonado       ;
		static short  i_shIndSuperTel      ;
	/* EXEC SQL END DECLARE SECTION  ; */ 


	vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada Carga Conceptos Notas"
                         "\n\t\t=> Num.Proceso [%ld]",LOG03,
                         stProceso.lNumProceso);

	strcpy(szFormatoFec,"YYYYMMDDHH24MISS");
	    
	/* EXEC SQL DECLARE Cur_PreFactura CURSOR FOR
		SELECT /o+ index (FA_PREFACTURA FK_FA_PREFACTURA) o/
			NUM_PROCESO    ,
			COD_CLIENTE    ,
			COD_CONCEPTO   ,
			COLUMNA        ,
			COD_PRODUCTO   ,
			COD_MONEDA     ,
			TO_CHAR (FEC_VALOR,:szFormatoFec)      ,
			TO_CHAR (FEC_EFECTIVIDAD,:szFormatoFec),
			IMP_CONCEPTO   ,
			IMP_MONTOBASE  ,
			IMP_FACTURABLE ,
			COD_REGION     ,
			COD_PROVINCIA  ,
			COD_CIUDAD     ,
			COD_MODULO     ,
			COD_PLANCOM    ,
			IND_FACTUR     ,
			COD_CATIMPOS   ,
			IND_ESTADO     ,
			COD_TIPCONCE   ,
			NUM_UNIDADES   ,
			COD_CICLFACT   ,
			COD_CONCEREL   ,
			COLUMNA_REL    ,
			NUM_ABONADO    ,
			NUM_TERMINAL   ,
			CAP_CODE       ,
			NUM_SERIEMEC   ,
			NUM_SERIELE    ,
			FLAG_IMPUES    ,
			FLAG_DTO       ,
			PRC_IMPUESTO   ,
			VAL_DTO        ,
			TIP_DTO        ,
			NUM_VENTA      ,
			NUM_TRANSACCION,
			MES_GARANTIA   ,
			IND_ALTA       ,
			IND_SUPERTEL   ,
			NUM_PAQUETE    ,
			IND_CUOTA      ,
			NUM_CUOTAS     ,
			ORD_CUOTA
		FROM  FA_PREFACTURA
		WHERE NUM_PROCESO = :stProceso.lNumProceso; */ 


	/* EXEC SQL OPEN Cur_PreFactura; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )447;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szFormatoFec;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)szFormatoFec;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&(stProceso.lNumProceso);
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


	if (SQLCODE)
		iDError (szExeName,ERR000,vInsertarIncidencia,"Open=>Fa_PreFactura",szfnORAerror ());

	/* EXEC SQL FETCH Cur_PreFactura
		INTO :lhNumProceso     ,
		    :lhCodCliente     ,
		    :ihCodConcepto    ,
		    :lhColumna        ,
		    :ihCodProducto    ,
		    :szhCodMoneda     ,
		    :szhFecValor      ,
		    :szhFecEfectividad,
		    :dhImpConcepto    ,
		    :dhImpMontoBase   ,
		    :dhImpFacturable  ,
		    :szhCodRegion     ,
		    :szhCodProvincia  ,
		    :szhCodCiudad     ,
		    :szhCodModulo     ,
		    :lhCodPlanCom     ,
		    :shIndFactur      ,
		    :ihCodCatImpos    ,
		    :shIndEstado      :i_shIndEstado     ,
		    :ihCodTipConce    :i_shCodTipConce   ,
		    :lhNumUnidades    :i_shNumUnidades   , /o Incorporado por PGonzaleg 4-03-2002 o/
		    :lhCodCiclFact    :i_shCodCiclFact   ,
		    :ihCodConceRel    :i_shCodConceRel   ,
		    :lhColumnaRel     :i_shColumnaRel    ,
		    :lhNumAbonado     :i_shNumAbonado    ,
		    :szhNumTerminal   :i_shNumTerminal   ,
		    :lhCapCode        :i_shCapCode       ,
		    :szhNumSerieMec   :i_shNumSerieMec   ,
		    :szhNumSerieLe    :i_shNumSerieLe    ,
		    :shFlagImpues     :i_shFlagImpues    ,
		    :shFlagDto        :i_shFlagDto       ,
		    :fhPrcImpuesto    :i_shPrcImpuesto   ,
		    :dhValDto         :i_shValDto        ,
		    :shTipDto         :i_shTipDto        ,
		    :lhNumVenta       :i_shNumVenta      ,
		    :lhNumTransaccion :i_shNumTransaccion,
		    :ihMesGarantia    :i_shMesGarantia   ,
		    :shIndAlta        :i_shIndAlta       ,
		    :shIndSuperTel    :i_shIndSuperTel   ,
		    :ihNumPaquete     :i_shNumPaquete    ,
		    :shIndCuota       :i_shIndCuota      ,
		    :ihNumCuotas      :i_shNumCuotas     ,
		    :ihOrdCuota       :i_shOrdCuota      ; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 43;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )474;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
 sqlstm.sqhstv[2] = (unsigned char  *)&ihCodConcepto;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&lhColumna;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&ihCodProducto;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)szhCodMoneda;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)szhFecValor;
 sqlstm.sqhstl[6] = (unsigned long )15;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)szhFecEfectividad;
 sqlstm.sqhstl[7] = (unsigned long )15;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&dhImpConcepto;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&dhImpMontoBase;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&dhImpFacturable;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)szhCodRegion;
 sqlstm.sqhstl[11] = (unsigned long )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)szhCodProvincia;
 sqlstm.sqhstl[12] = (unsigned long )6;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)szhCodCiudad;
 sqlstm.sqhstl[13] = (unsigned long )6;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)szhCodModulo;
 sqlstm.sqhstl[14] = (unsigned long )3;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&lhCodPlanCom;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&shIndFactur;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&ihCodCatImpos;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&shIndEstado;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&i_shIndEstado;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&ihCodTipConce;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&i_shCodTipConce;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&lhNumUnidades;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&i_shNumUnidades;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&lhCodCiclFact;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&i_shCodCiclFact;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&ihCodConceRel;
 sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&i_shCodConceRel;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&lhColumnaRel;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&i_shColumnaRel;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&lhNumAbonado;
 sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&i_shNumAbonado;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)szhNumTerminal;
 sqlstm.sqhstl[25] = (unsigned long )16;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&i_shNumTerminal;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&lhCapCode;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&i_shCapCode;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)szhNumSerieMec;
 sqlstm.sqhstl[27] = (unsigned long )26;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&i_shNumSerieMec;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)szhNumSerieLe;
 sqlstm.sqhstl[28] = (unsigned long )26;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&i_shNumSerieLe;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&shFlagImpues;
 sqlstm.sqhstl[29] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&i_shFlagImpues;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&shFlagDto;
 sqlstm.sqhstl[30] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&i_shFlagDto;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&fhPrcImpuesto;
 sqlstm.sqhstl[31] = (unsigned long )sizeof(float);
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&i_shPrcImpuesto;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&dhValDto;
 sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&i_shValDto;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
 sqlstm.sqhstv[33] = (unsigned char  *)&shTipDto;
 sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[33] = (         int  )0;
 sqlstm.sqindv[33] = (         short *)&i_shTipDto;
 sqlstm.sqinds[33] = (         int  )0;
 sqlstm.sqharm[33] = (unsigned long )0;
 sqlstm.sqadto[33] = (unsigned short )0;
 sqlstm.sqtdso[33] = (unsigned short )0;
 sqlstm.sqhstv[34] = (unsigned char  *)&lhNumVenta;
 sqlstm.sqhstl[34] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[34] = (         int  )0;
 sqlstm.sqindv[34] = (         short *)&i_shNumVenta;
 sqlstm.sqinds[34] = (         int  )0;
 sqlstm.sqharm[34] = (unsigned long )0;
 sqlstm.sqadto[34] = (unsigned short )0;
 sqlstm.sqtdso[34] = (unsigned short )0;
 sqlstm.sqhstv[35] = (unsigned char  *)&lhNumTransaccion;
 sqlstm.sqhstl[35] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[35] = (         int  )0;
 sqlstm.sqindv[35] = (         short *)&i_shNumTransaccion;
 sqlstm.sqinds[35] = (         int  )0;
 sqlstm.sqharm[35] = (unsigned long )0;
 sqlstm.sqadto[35] = (unsigned short )0;
 sqlstm.sqtdso[35] = (unsigned short )0;
 sqlstm.sqhstv[36] = (unsigned char  *)&ihMesGarantia;
 sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[36] = (         int  )0;
 sqlstm.sqindv[36] = (         short *)&i_shMesGarantia;
 sqlstm.sqinds[36] = (         int  )0;
 sqlstm.sqharm[36] = (unsigned long )0;
 sqlstm.sqadto[36] = (unsigned short )0;
 sqlstm.sqtdso[36] = (unsigned short )0;
 sqlstm.sqhstv[37] = (unsigned char  *)&shIndAlta;
 sqlstm.sqhstl[37] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[37] = (         int  )0;
 sqlstm.sqindv[37] = (         short *)&i_shIndAlta;
 sqlstm.sqinds[37] = (         int  )0;
 sqlstm.sqharm[37] = (unsigned long )0;
 sqlstm.sqadto[37] = (unsigned short )0;
 sqlstm.sqtdso[37] = (unsigned short )0;
 sqlstm.sqhstv[38] = (unsigned char  *)&shIndSuperTel;
 sqlstm.sqhstl[38] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[38] = (         int  )0;
 sqlstm.sqindv[38] = (         short *)&i_shIndSuperTel;
 sqlstm.sqinds[38] = (         int  )0;
 sqlstm.sqharm[38] = (unsigned long )0;
 sqlstm.sqadto[38] = (unsigned short )0;
 sqlstm.sqtdso[38] = (unsigned short )0;
 sqlstm.sqhstv[39] = (unsigned char  *)&ihNumPaquete;
 sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[39] = (         int  )0;
 sqlstm.sqindv[39] = (         short *)&i_shNumPaquete;
 sqlstm.sqinds[39] = (         int  )0;
 sqlstm.sqharm[39] = (unsigned long )0;
 sqlstm.sqadto[39] = (unsigned short )0;
 sqlstm.sqtdso[39] = (unsigned short )0;
 sqlstm.sqhstv[40] = (unsigned char  *)&shIndCuota;
 sqlstm.sqhstl[40] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[40] = (         int  )0;
 sqlstm.sqindv[40] = (         short *)&i_shIndCuota;
 sqlstm.sqinds[40] = (         int  )0;
 sqlstm.sqharm[40] = (unsigned long )0;
 sqlstm.sqadto[40] = (unsigned short )0;
 sqlstm.sqtdso[40] = (unsigned short )0;
 sqlstm.sqhstv[41] = (unsigned char  *)&ihNumCuotas;
 sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[41] = (         int  )0;
 sqlstm.sqindv[41] = (         short *)&i_shNumCuotas;
 sqlstm.sqinds[41] = (         int  )0;
 sqlstm.sqharm[41] = (unsigned long )0;
 sqlstm.sqadto[41] = (unsigned short )0;
 sqlstm.sqtdso[41] = (unsigned short )0;
 sqlstm.sqhstv[42] = (unsigned char  *)&ihOrdCuota;
 sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[42] = (         int  )0;
 sqlstm.sqindv[42] = (         short *)&i_shOrdCuota;
 sqlstm.sqinds[42] = (         int  )0;
 sqlstm.sqharm[42] = (unsigned long )0;
 sqlstm.sqadto[42] = (unsigned short )0;
 sqlstm.sqtdso[42] = (unsigned short )0;
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


	
	if (SQLCODE == SQLNOTFOUND)
	{
		/* EXEC SQL CLOSE Cur_PreFactura; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 43;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )661;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

       
		iDError (szExeName,ERR000,vInsertarIncidencia,"Close=>Fa_PreFactura",szfnORAerror ());
		return (FALSE);
	}
	
	if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
		iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=>Fa_PreFactura",szfnORAerror ());

	while (SQLCODE == SQLOK)
	{ 	
		i = stPreFactura.iNumRegistros;
		
		stPreFactura.A_PFactura.lNumProceso [i] = lhNumProceso ;
		stPreFactura.A_PFactura.lCodCliente [i] = lhCodCliente ;
		stPreFactura.A_PFactura.iCodConcepto[i] = ihCodConcepto;
		stPreFactura.A_PFactura.lColumna    [i] = lhColumna    ;
		stPreFactura.A_PFactura.iCodProducto[i] = ihCodProducto;
		
			 /* if (stCliente.lCodCliente <= 0)
		{
		stCliente.lCodCliente = lhCodCliente;
		if (!bfnGetDatosCliente (stCliente.lCodCliente))  Modificacion hecha por Cdescouv 11/04/2002
		{
		 return FALSE;
		}
		}*/
		memset (&stConcepto, 0, sizeof (CONCEPTO));
		if (!bFindConcepto (ihCodConcepto, &stConcepto))
		return FALSE;
		
		strcpy (stPreFactura.A_PFactura.szDesConcepto   [i],
		 stConcepto.szDesConcepto);
		strcpy (stPreFactura.A_PFactura.szCodMoneda     [i],
		 szhCodMoneda)            ;
		strcpy (stPreFactura.A_PFactura.szFecValor      [i],
		 szhFecValor )            ;
		strcpy (stPreFactura.A_PFactura.szFecEfectividad[i],
		 szhFecEfectividad)       ;
		
		stPreFactura.A_PFactura.dImpConcepto  [i] = dhImpConcepto  ;
		stPreFactura.A_PFactura.dImpFacturable[i] = dhImpFacturable;
		stPreFactura.A_PFactura.dImpMontoBase [i] = dhImpMontoBase ;
		
		stPreFactura.A_PFactura.dImpFacturable[i] =
		 fnCnvDouble( stPreFactura.A_PFactura.dImpFacturable[i],
		                           USOFACT);
		
		strcpy (stPreFactura.A_PFactura.szCodRegion   [i],
		 szhCodRegion   );
		strcpy (stPreFactura.A_PFactura.szCodProvincia[i],
		 szhCodProvincia);
		strcpy (stPreFactura.A_PFactura.szCodCiudad   [i],
		 szhCodCiudad   );
		strcpy (stPreFactura.A_PFactura.szCodModulo   [i],
		 szhCodModulo   );
		
		stPreFactura.A_PFactura.lCodPlanCom [i]   = lhCodPlanCom ;
		stPreFactura.A_PFactura.iIndFactur  [i]   = shIndFactur  ;
		stPreFactura.A_PFactura.iCodCatImpos[i]   = ihCodCatImpos;
		stPreFactura.A_PFactura.iCodPortador[i]   = ihCodPortador;
		stPreFactura.A_PFactura.iIndEstado  [i]   =
		           (i_shIndEstado  == -1)?-1:shIndEstado  ;
		stPreFactura.A_PFactura.iCodTipConce[i]   =
		           (i_shCodTipConce== -1)?-1:ihCodTipConce;
		stPreFactura.A_PFactura.lNumUnidades[i]   =
		           (i_shNumUnidades== -1)?-1:lhNumUnidades; /* Incorporado por PGonzaleg 4-03-2002 */
		stPreFactura.A_PFactura.lCodCiclFact[i]   =
		           (i_shCodCiclFact== -1)?-1:lhCodCiclFact;
		stPreFactura.A_PFactura.iCodConceRel[i]   =
		           (i_shCodConceRel== -1)?-1:ihCodConceRel;
		stPreFactura.A_PFactura.lColumnaRel [i]   =
		           (i_shColumnaRel == -1)?-1:lhColumnaRel ;
		stPreFactura.A_PFactura.lNumAbonado [i]   =
		           (i_shNumAbonado == -1)?-1:lhNumAbonado ;
		
		strcpy (stPreFactura.A_PFactura.szNumTerminal[i] ,
		 (i_shNumTerminal == -1)?"":szhNumTerminal);
		
		stPreFactura.A_PFactura.lCapCode [i]      =
		 (i_shCapCode    == -1)?-1:lhCapCode       ;
		
		strcpy (stPreFactura.A_PFactura.szNumSerieMec[i] ,
		 (i_shNumSerieMec == -1)?"":szhNumSerieMec);
		strcpy (stPreFactura.A_PFactura.szNumSerieLe [i] ,
		 (i_shNumSerieLe  == -1)?"":szhNumSerieLe );
		
		stPreFactura.A_PFactura.iFlagImpues [i]   =
		 (i_shFlagImpues == -1)?-1:shFlagImpues    ;
		stPreFactura.A_PFactura.iFlagDto    [i]   =
		 (i_shFlagDto    == -1)?-1:shFlagDto       ;
		stPreFactura.A_PFactura.fPrcImpuesto[i]   =
		 (i_shPrcImpuesto== -1)?-1:fhPrcImpuesto   ;
		stPreFactura.A_PFactura.dValDto     [i]   =
		 (i_shValDto     == -1)?-1:dhValDto        ;
		stPreFactura.A_PFactura.iTipDto     [i]   =
		 (i_shTipDto     == -1)?-1:shTipDto        ;
		stPreFactura.A_PFactura.lNumVenta   [i]   =
		 (i_shNumVenta   == -1)?-1:lhNumVenta      ;
		
		stPreFactura.A_PFactura.lNumTransaccion[i]=
		 (i_shNumTransaccion == -1)?-1:lhNumTransaccion;
		
		stPreFactura.A_PFactura.iMesGarantia [i]  =
		 (i_shMesGarantia== -1)?-1:ihMesGarantia   ;
		
		strcpy (stPreFactura.A_PFactura.szNumGuia[i] ,
		 (i_shNumGuia == -1)?"":szhNumGuia)        ;
		
		stPreFactura.A_PFactura.iIndAlta     [i]  =
		 (i_shIndAlta == -1)?-1:shIndAlta          ;
		stPreFactura.A_PFactura.iIndSuperTel [i]  =
		 (i_shIndSuperTel == -1)?-1:shIndSuperTel  ;
		stPreFactura.A_PFactura.iNumPaquete  [i]  =
		 (i_shNumPaquete  == -1)?-1:ihNumPaquete   ;
		stPreFactura.A_PFactura.iIndCuota    [i]  =
		 (i_shIndCuota    == -1)?-1:shIndCuota     ;
		stPreFactura.A_PFactura.iNumCuotas   [i]  =
		 (i_shNumCuotas   == -1)?-1:ihNumCuotas    ;
		stPreFactura.A_PFactura.iOrdCuota    [i]  =
		 (i_shOrdCuota    == -1)?-1:ihOrdCuota     ;
		
		/**********************************************************/
		/* Recogemos Informacion para la Cabecera del Documento   */
		/**********************************************************/
		if (stPreFactura.A_PFactura.iIndSuperTel [i] == 1 &&
		stCliente.iIndSuperTel                   <  1 )
		{
		stCliente.iIndSuperTel = 1;
		}
		if (stPreFactura.A_PFactura.iIndCuota [i] == 1 &&
		stCliente.iIndCredito                 <  1)
		{
		stCliente.iIndCredito = 1;
		}
		stPreFactura.iNumRegistros++;
        
		/* EXEC SQL FETCH Cur_PreFactura
		       INTO :lhNumProceso     ,
		            :lhCodCliente     ,
		            :ihCodConcepto    ,
		            :lhColumna        ,
		            :ihCodProducto    ,
		            :szhCodMoneda     ,
		            :szhFecValor      ,
		            :szhFecEfectividad,
		            :dhImpConcepto    ,
		            :dhImpMontoBase   ,
		            :dhImpFacturable  ,
		            :szhCodRegion     ,
		            :szhCodProvincia  ,
		            :szhCodCiudad     ,
		            :szhCodModulo     ,
		            :lhCodPlanCom     ,
		            :shIndFactur      ,
		            :ihCodCatImpos    ,
		            :shIndEstado      :i_shIndEstado     ,
		            :ihCodTipConce    :i_shCodTipConce   ,
		            :lhNumUnidades    :i_shNumUnidades   , /o Incorporado por PGonzaleg 4-03-2002 o/
		            :lhCodCiclFact    :i_shCodCiclFact   ,
		            :ihCodConceRel    :i_shCodConceRel   ,
		            :lhColumnaRel     :i_shColumnaRel    ,
		            :lhNumAbonado     :i_shNumAbonado    ,
		            :szhNumTerminal   :i_shNumTerminal   ,
		            :lhCapCode        :i_shCapCode       ,
		            :szhNumSerieMec   :i_shNumSerieMec   ,
		            :szhNumSerieLe    :i_shNumSerieLe    ,
		            :shFlagImpues     :i_shFlagImpues    ,
		            :shFlagDto        :i_shFlagDto       ,
		            :fhPrcImpuesto    :i_shPrcImpuesto   ,
		            :dhValDto         :i_shValDto        ,
		            :shTipDto         :i_shTipDto        ,
		            :lhNumVenta       :i_shNumVenta      ,
		            :lhNumTransaccion :i_shNumTransaccion,
		            :ihMesGarantia    :i_shMesGarantia   ,
		            :shIndAlta        :i_shIndAlta       ,
		            :shIndSuperTel    :i_shIndSuperTel   ,
		            :ihNumPaquete     :i_shNumPaquete    ,
		            :shIndCuota       :i_shIndCuota      ,
		            :ihNumCuotas      :i_shNumCuotas     ,
		            :ihOrdCuota       :i_shOrdCuota      ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 43;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )676;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
  sqlstm.sqhstv[2] = (unsigned char  *)&ihCodConcepto;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&lhColumna;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&ihCodProducto;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)szhCodMoneda;
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)szhFecValor;
  sqlstm.sqhstl[6] = (unsigned long )15;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)szhFecEfectividad;
  sqlstm.sqhstl[7] = (unsigned long )15;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&dhImpConcepto;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&dhImpMontoBase;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&dhImpFacturable;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)szhCodRegion;
  sqlstm.sqhstl[11] = (unsigned long )4;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)szhCodProvincia;
  sqlstm.sqhstl[12] = (unsigned long )6;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)szhCodCiudad;
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)szhCodModulo;
  sqlstm.sqhstl[14] = (unsigned long )3;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&lhCodPlanCom;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&shIndFactur;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&ihCodCatImpos;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&shIndEstado;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&i_shIndEstado;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&ihCodTipConce;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&i_shCodTipConce;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&lhNumUnidades;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&i_shNumUnidades;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&lhCodCiclFact;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&i_shCodCiclFact;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&ihCodConceRel;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&i_shCodConceRel;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&lhColumnaRel;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&i_shColumnaRel;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&lhNumAbonado;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&i_shNumAbonado;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)szhNumTerminal;
  sqlstm.sqhstl[25] = (unsigned long )16;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&i_shNumTerminal;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&lhCapCode;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&i_shCapCode;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)szhNumSerieMec;
  sqlstm.sqhstl[27] = (unsigned long )26;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&i_shNumSerieMec;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)szhNumSerieLe;
  sqlstm.sqhstl[28] = (unsigned long )26;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&i_shNumSerieLe;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&shFlagImpues;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&i_shFlagImpues;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&shFlagDto;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&i_shFlagDto;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&fhPrcImpuesto;
  sqlstm.sqhstl[31] = (unsigned long )sizeof(float);
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&i_shPrcImpuesto;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&dhValDto;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&i_shValDto;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&shTipDto;
  sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&i_shTipDto;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&lhNumVenta;
  sqlstm.sqhstl[34] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)&i_shNumVenta;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&lhNumTransaccion;
  sqlstm.sqhstl[35] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)&i_shNumTransaccion;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)&ihMesGarantia;
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)&i_shMesGarantia;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)&shIndAlta;
  sqlstm.sqhstl[37] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)&i_shIndAlta;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)&shIndSuperTel;
  sqlstm.sqhstl[38] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[38] = (         int  )0;
  sqlstm.sqindv[38] = (         short *)&i_shIndSuperTel;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)&ihNumPaquete;
  sqlstm.sqhstl[39] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[39] = (         int  )0;
  sqlstm.sqindv[39] = (         short *)&i_shNumPaquete;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)&shIndCuota;
  sqlstm.sqhstl[40] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[40] = (         int  )0;
  sqlstm.sqindv[40] = (         short *)&i_shIndCuota;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)&ihNumCuotas;
  sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[41] = (         int  )0;
  sqlstm.sqindv[41] = (         short *)&i_shNumCuotas;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)&ihOrdCuota;
  sqlstm.sqhstl[42] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[42] = (         int  )0;
  sqlstm.sqindv[42] = (         short *)&i_shOrdCuota;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
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
			iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=>Fa_PreFactura",szfnORAerror ());

	}/* fin while ... */
	
	vDTrazasLog (szExeName,"\n\t\t* Conceptos de la Factura Modificados [%d]",LOG03, stPreFactura.iNumRegistros);
	return (TRUE);
}/*************************** Final bCargaConceptosNotas *********************/

/*****************************************************************************/
/*                        funcion : bfnDBUpdateAjustes                       */
/* -stNota (tiene cargado el registro de Fa_HistDocu sobre el cual emitimos  */
/*  la Nota Credito o Debito.                                                */
/* -stHistDocu es el registro a Insertar en Fa_HistDocu correspondiente a la */
/*  Nota Credito o Debito que emitimos sobre la Factura de stNota .          */
/* # Ambas estructura son globales y estan definidas en GenFa.h              */
/*****************************************************************************/
BOOL bfnDBUpdateAjustes (void)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char   szhPrefPlaza[10+1];
    static long   lhNumFolio      ;
    static long   lhCodCliente    ;
    static long   ihCodTipDocum   ;
    static double dhAcumNetoNoGrav;
    static double dhAcumNetoGrav  ;
    static double dhAcumIva       ;
    /* EXEC SQL END DECLARE SECTION  ; */ 


    strcpy(szhPrefPlaza,stNota.szPrefPlaza);
    lhNumFolio       = stNota.lNumFolio          ;
    lhCodCliente     = stNota.lCodCliente        ;
    ihCodTipDocum    = stNota.iCodTipDocum       ;
    dhAcumNetoNoGrav = stHistDocu.dAcumNetoNoGrav;
    dhAcumNetoGrav   = stHistDocu.dAcumNetoGrav  ;
    dhAcumIva        = stHistDocu.dAcumIva       ;


   vDTrazasLog (szExeName, "\n\t\t* Mas Parametros de Entrada a Update Fa_Ajustes"
    			    "\n\t\t=> stNota.szPrefPlaza [%s] "                     
                            ,LOG03, stNota.szPrefPlaza);

	
    vDTrazasLog (szExeName, "\n\t\t* Parametros de Entrada a Update Fa_Ajustes"
    			    "\n\t\t=> Pref. Plaza [%s] "
                            "\n\t\t=> Num.Folio   [%ld]"
                            "\n\t\t=> Cod.Cliente [%ld]"
                            "\n\t\t=> Cod.TipDocum[%d] "                            
                            ,LOG03, szhPrefPlaza, lhNumFolio, lhCodCliente, ihCodTipDocum);

    vDTrazasLog (szExeName, "\n\t\t* Valores de los if.... "
                            "\n\t\t=> stProceso.iCodTipDocum	[%ld]"
                            "\n\t\t=> stDatosGener.iCodNotaCre 	[%ld]"
                            "\n\t\t=> stDatosGener.iCodNotaDeb	[%ld] "                            
                            ,LOG03, stProceso.iCodTipDocum, stDatosGener.iCodNotaCre, stDatosGener.iCodNotaDeb);


    if (stProceso.iCodTipDocum == stDatosGener.iCodNotaCre)
    {
        /* EXEC SQL UPDATE
                        FA_AJUSTES
                 SET    ACUM_NETOGRAVNC   =
                        ACUM_NETOGRAVNC   + :dhAcumNetoGrav  ,
                        ACUM_NETONOGRAVNC =
                        ACUM_NETONOGRAVNC + :dhAcumNetoNoGrav,
                        ACUM_IVANC        =
                        ACUM_IVANC        + :dhAcumIva
        WHERE  PREF_PLAZA    = :szhPrefPlaza
        AND NUM_FOLIO    = :lhNumFolio
        AND    COD_CLIENTE  = :lhCodCliente
        AND    COD_TIPDOCUM = :ihCodTipDocum; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 43;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update FA_AJUSTES  set ACUM_NETOGRAVNC=(ACUM_NETOGRAV\
NC+:b0),ACUM_NETONOGRAVNC=(ACUM_NETONOGRAVNC+:b1),ACUM_IVANC=(ACUM_IVANC+:b2) \
where (((PREF_PLAZA=:b3 and NUM_FOLIO=:b4) and COD_CLIENTE=:b5) and COD_TIPDOC\
UM=:b6)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )863;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&dhAcumNetoGrav;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&dhAcumNetoNoGrav;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&dhAcumIva;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhPrefPlaza;
        sqlstm.sqhstl[3] = (unsigned long )11;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhNumFolio;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&ihCodTipDocum;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
    else if (stProceso.iCodTipDocum == stDatosGener.iCodNotaDeb)
    {
        /* EXEC SQL UPDATE
                        FA_AJUSTES
                 SET    ACUM_NETOGRAVND   =
                        ACUM_NETOGRAVND   + :dhAcumNetoGrav  ,
                        ACUM_NETONOGRAVND =
                        ACUM_NETONOGRAVND + :dhAcumNetoNoGrav,
                        ACUM_IVAND        =
                        ACUM_IVAND        + :dhAcumIva
        WHERE
        	PREF_PLAZA    = :szhPrefPlaza
        AND	NUM_FOLIO    = :lhNumFolio
        AND    COD_CLIENTE  = :lhCodCliente
        AND    COD_TIPDOCUM = :ihCodTipDocum; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 43;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update FA_AJUSTES  set ACUM_NETOGRAVND=(ACUM_NETOGRAV\
ND+:b0),ACUM_NETONOGRAVND=(ACUM_NETONOGRAVND+:b1),ACUM_IVAND=(ACUM_IVAND+:b2) \
where (((PREF_PLAZA=:b3 and NUM_FOLIO=:b4) and COD_CLIENTE=:b5) and COD_TIPDOC\
UM=:b6)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )906;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&dhAcumNetoGrav;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&dhAcumNetoNoGrav;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&dhAcumIva;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhPrefPlaza;
        sqlstm.sqhstl[3] = (unsigned long )11;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhNumFolio;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&ihCodTipDocum;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        iDError (szExeName,ERR000,vInsertarIncidencia,"Update=>Fa_Ajustes",
                 szfnORAerror ());

    return (SQLCODE != SQLOK)?FALSE:TRUE;
}/************************* Final bfnDBUpdateAjustes *************************/
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
