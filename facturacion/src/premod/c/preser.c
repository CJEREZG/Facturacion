
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
    "./pc/preser.pc"
};


static unsigned int sqlctx = 866075;


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
   unsigned char  *sqhstv[29];
   unsigned long  sqhstl[29];
            int   sqhsts[29];
            short *sqindv[29];
            int   sqinds[29];
   unsigned long  sqharm[29];
   unsigned long  *sqharc[29];
   unsigned short  sqadto[29];
   unsigned short  sqtdso[29];
} sqlstm = {12,29};

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
"select B.COD_SERVICIO ,B.COD_CONCEPTO ,A.IMP_TARIFA ,A.COD_MONEDA  from GA_T\
ARIFAS A ,GA_ACTUASERV B where (((((((((A.COD_PRODUCTO=:b0 and A.COD_ACTABO=:b\
1) and A.COD_TIPSERV=:b2) and A.COD_SERVICIO=B.COD_SERVICIO) and A.COD_PLANSER\
V=:b3) and A.FEC_DESDE<=TO_DATE(:b4,:b5)) and (A.FEC_HASTA>=TO_DATE(:b4,:b5) o\
r A.FEC_HASTA is null )) and B.COD_PRODUCTO=:b0) and B.COD_ACTABO=:b1) and B.C\
OD_TIPSERV=:b2)           ";

 static const char *sq0001 = 
"select  /*+   index (A, PK_GA_SERVSUPLABO)  +*/ A.COD_CONCEPTO ,TO_CHAR(A.FE\
C_ALTACEN,:b0) ,TO_CHAR(A.FEC_BAJABD,:b0) ,TO_CHAR(A.FEC_ALTABD,:b0) ,TO_CHAR(\
A.FEC_BAJACEN,:b0) ,B.IND_PRO ,A.COD_SERVICIO ,C.COD_MONEDA ,C.IMP_TARIFA  fro\
m GA_SERVSUPLABO A ,GA_SERVSUPL B ,GA_TARIFAS C where ((((((((((((((((A.NUM_AB\
ONADO=:b4 and A.COD_PRODUCTO=:b5) and A.IND_ESTADO<>:b6) and B.COD_PRODUCTO=A.\
COD_PRODUCTO) and B.COD_SERVICIO=A.COD_SERVICIO) and A.COD_CONCEPTO is  not nu\
ll ) and DECODE(A.FEC_ALTACEN,null ,TO_DATE(:b7,:b0),A.FEC_ALTACEN)<=TO_DATE(:\
b7,:b0)) and NVL(A.FEC_BAJABD,NVL(A.FEC_BAJACEN,TO_DATE('30001201000000',:b0))\
)>=TO_DATE(:b12,:b0)) and DECODE(A.FEC_ALTACEN,null ,TO_DATE(:b14,:b0),A.FEC_A\
LTACEN)<=TO_DATE(:b14,:b0)) and C.COD_ACTABO=:b18) and C.COD_PRODUCTO=:b5) and\
 C.COD_SERVICIO=A.COD_SERVICIO) and C.COD_TIPSERV=:b20) and C.COD_PLANSERV=:b2\
1) and C.FEC_DESDE<=TO_DATE(:b14,:b0)) and NVL(C.FEC_HASTA,TO_DATE('3000120100\
0000','yyyymmddhh24miss'))>=TO_DATE(:b14,:b0)) and C.IMP_TARIFA<>:b26)        \
   ";

 static const char *sq0008 = 
"select ROWID ,TO_CHAR(FEC_DESDE,:b0) ,TO_CHAR(FEC_HASTA,:b0) ,COD_CARGOBASIC\
O ,COD_PLANSERV ,COD_PLANCOM ,TO_CHAR(NUM_CELULAR) ,COD_GRPSERV ,TIP_PLANTARIF\
 ,COD_PLANTARIF ,COD_GRUPO  from GA_INTARCEL where (((((COD_CLIENTE=:b2 and NU\
M_ABONADO=:b3) and IND_NUMERO=:b4) and FEC_DESDE<TO_DATE(:b5,:b0)) and COD_CIC\
LO=:b7) and FEC_HASTA>=TO_DATE(:b8,:b0)) order by FEC_DESDE desc   for update ";

 static const char *sq0018 = 
"select COD_CRITERIO ,VAL_CRITERIO  from FA_CRITSERV where ((COD_SERVICIO=:b0\
 and COD_PRODUCTO=:b1) and COD_CRITERIO=:b2)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,2,554,0,260,242,0,0,29,10,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,
0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
136,0,0,3,64,0,260,536,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
159,0,0,4,414,0,265,594,0,0,11,11,0,1,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
218,0,0,4,0,0,269,603,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,4,0,0,2,5,0,0,
249,0,0,4,0,0,271,666,0,0,0,0,0,1,0,
264,0,0,1,1015,0,265,953,0,0,27,27,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,
5,0,0,1,5,0,0,1,4,0,0,
387,0,0,1,0,0,269,962,0,0,9,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,
438,0,0,1,0,0,271,1123,0,0,0,0,0,1,0,
453,0,0,5,147,0,260,1190,0,0,6,4,0,1,0,2,3,0,0,2,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
492,0,0,6,55,0,261,1754,0,0,2,2,0,1,0,1,3,0,0,1,5,0,0,
515,0,0,7,105,0,261,1876,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
542,0,0,8,388,0,265,2327,0,0,10,10,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,97,0,0,1,5,0,0,1,3,0,0,1,97,0,0,1,5,0,0,
597,0,0,8,0,0,269,2377,0,0,11,0,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
656,0,0,8,0,0,271,2407,0,0,0,0,0,1,0,
671,0,0,9,132,0,260,2871,0,0,5,4,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
706,0,0,10,180,0,260,2884,0,0,8,7,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,5,0,0,1,3,0,0,1,5,0,0,
753,0,0,11,173,0,260,2893,0,0,7,6,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,
0,1,3,0,0,1,5,0,0,
796,0,0,12,152,0,260,3007,0,0,6,4,0,1,0,2,4,0,0,2,5,0,0,1,3,0,0,1,5,0,0,1,97,0,
0,1,5,0,0,
835,0,0,13,147,0,260,3207,0,0,6,5,0,1,0,1,3,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,1,3,0,0,
874,0,0,14,128,0,260,3256,0,0,5,4,0,1,0,1,3,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,
909,0,0,15,182,0,260,3287,0,0,5,4,0,1,0,1,3,0,0,2,4,0,0,1,3,0,0,1,3,0,0,1,97,0,
0,
944,0,0,16,163,0,260,3629,0,0,5,4,0,1,0,1,3,0,0,2,3,0,0,1,3,0,0,1,5,0,0,1,3,0,
0,
979,0,0,17,111,0,260,4051,0,0,4,2,0,1,0,2,3,0,0,2,3,0,0,1,5,0,0,1,3,0,0,
1010,0,0,18,131,0,265,4099,0,0,3,3,0,1,0,1,5,0,0,1,3,0,0,1,3,0,0,
1037,0,0,18,0,0,269,4108,0,0,2,0,0,1,0,2,3,0,0,2,5,0,0,
1060,0,0,18,0,0,269,4119,0,0,2,0,0,1,0,2,3,0,0,2,5,0,0,
1083,0,0,18,0,0,271,4130,0,0,0,0,0,1,0,
};


/*****************************************************************************/
/* Funcion     : preser.pc                                                   */
/* Descripcion : Declaracion de funciones para PreBilling Servicios          */
/* Autor       : Javier Garcia Paredes                                       */
/* Fecha       : 03-03-1997                                                  */
/*****************************************************************************/
/* 09-12-1999  : Modificacion de Llamada a rutina que carga servicios        */
/*               suplementarios, ya que aquellos abonados de Baja no carga   */
/*               correctamente los servicios, cargando nuevamente un serv.   */
/*               para el abonado anteriormente facturado                     */
/*****************************************************************************/
/* 22-02-2002  : Incorporacion de rutina bfnProrrateoStandar, rutina generica*/
/*       de prorrateo de cargos                      */
/* Nelson Contreras Helena                           */
/*****************************************************************************/
/* 13-01-2003  : Incorporacion desiscoón entre Tasacion Clasica o Tasacion on*/
/*       line                                    */
/* Sebastian Acuña Mejía                             */
/*****************************************************************************/

#define _PRESER_PC_
#include <sys/timeb.h>
#include "preser.h"


extern char * alltrim(char *s);

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


char    szFecUltFact [15];

/* 20040826 CH-200408222076 Se declara Fecha de Baja GA_INFACCEL */
/* EXEC SQL BEGIN DECLARE SECTION; */ 

    char  szFecBaja_Infaccel    [15];/* EXEC SQL VAR szFecBaja_Infaccel IS STRING(15); */ 

    char  szFecDesdeOCargos     [15];/* EXEC SQL VAR szFecDesdeOCargos  IS STRING(15); */ 

    char  szpFormatoFec			[17];/* EXEC SQL VAR szpFormatoFec       IS STRING(17); */ 

    long  lhpNumAbonado;
    int   ihpCodProducto;
    int   ihpSeis;
    char  szpFecEmision         [15];/* EXEC SQL VAR szpFecEmision IS STRING(15); */ 

    char  szhpFecDesdeCFijos		[15];/* EXEC SQL VAR szhpFecDesdeCFijos       IS STRING(15); */ 

    char  szhpFecHastaCFijos		[15];/* EXEC SQL VAR szhpFecHastaCFijos       IS STRING(15); */ 

    double dhpImpCero               ;
    char  szpCodActabo    [3] ;/* EXEC SQL VAR szpCodActabo  IS STRING(3); */ 

    char  szpCodTipServ   [2] ;/* EXEC SQL VAR szpCodTipServ IS STRING(2); */ 

    char  szpCodPlanServ  [4] ;/* EXEC SQL VAR szpCodPlanServ IS STRING(4); */ 
    
/* EXEC SQL END DECLARE SECTION  ; */ 



/* EXEC SQL DECLARE Cur_ServSupl CURSOR for
    SELECT  /o+  index (A, PK_GA_SERVSUPLABO) o/
            A.COD_CONCEPTO,
            TO_CHAR (A.FEC_ALTACEN,:szpFormatoFec),
            TO_CHAR (A.FEC_BAJABD ,:szpFormatoFec),
            TO_CHAR (A.FEC_ALTABD ,:szpFormatoFec),
            TO_CHAR (A.FEC_BAJACEN,:szpFormatoFec),
            B.IND_PRO,
            A.COD_SERVICIO,
            C.COD_MONEDA,
            C.IMP_TARIFA
       FROM GA_SERVSUPLABO A,
            GA_SERVSUPL B,
            GA_TARIFAS C
      WHERE A.NUM_ABONADO   = :lhpNumAbonado
        AND A.COD_PRODUCTO  = :ihpCodProducto
        AND A.IND_ESTADO   <> :ihpSeis
        AND B.COD_PRODUCTO  = A.COD_PRODUCTO
        AND B.COD_SERVICIO  = A.COD_SERVICIO
        AND A.COD_CONCEPTO  IS NOT NULL
/o        AND A.FEC_ALTACEN   IS NOT NULLo/
/o        AND A.FEC_ALTACEN  <= TO_DATE(:szhpFecHastaCFijos, :szpFormatoFec)o/
        AND DECODE (A.FEC_ALTACEN, NULL, TO_DATE(:szhpFecHastaCFijos, :szpFormatoFec), A.FEC_ALTACEN)  <= TO_DATE(:szhpFecHastaCFijos, :szpFormatoFec)
        AND NVL(A.FEC_BAJABD, NVL(A.FEC_BAJACEN,TO_DATE('30001201000000',:szpFormatoFec)))   >= TO_DATE(:szhpFecDesdeCFijos,:szpFormatoFec)
/o        AND A.FEC_ALTACEN  <=  TO_DATE(:szpFecEmision,:szpFormatoFec)o/
        AND DECODE (A.FEC_ALTACEN, NULL, TO_DATE(:szpFecEmision,:szpFormatoFec), A.FEC_ALTACEN)  <=  TO_DATE(:szpFecEmision,:szpFormatoFec)
        AND C.COD_ACTABO   = :szpCodActabo
        AND C.COD_PRODUCTO = :ihpCodProducto
        AND C.COD_SERVICIO = A.COD_SERVICIO
        AND C.COD_TIPSERV  = :szpCodTipServ
        AND C.COD_PLANSERV = :szpCodPlanServ
        AND C.FEC_DESDE   <= TO_DATE(:szpFecEmision,:szpFormatoFec)
        AND NVL(C.FEC_HASTA,TO_DATE('30001201000000','yyyymmddhh24miss')) >= TO_DATE(:szpFecEmision,:szpFormatoFec)
        AND C.IMP_TARIFA  <> :dhpImpCero; */ 


/*	  WHERE A.NUM_ABONADO   = :lhpNumAbonado   MEJORA CJG
		AND A.COD_PRODUCTO  = :ihpCodProducto
		AND A.IND_ESTADO   <> :ihpSeis
		AND ((A.FEC_ALTABD <= TO_DATE(:szhpFecHastaCFijos, :szpFormatoFec)) 
		AND (A.FEC_BAJABD >= TO_DATE(:szhpFecDesdeCFijos, :szpFormatoFec) OR A.FEC_BAJABD IS NULL))
		AND B.COD_PRODUCTO  = A.COD_PRODUCTO
		AND B.COD_SERVICIO  = A.COD_SERVICIO
		AND A.COD_CONCEPTO  IS NOT NULL
        AND C.COD_ACTABO   = :szpCodActabo
        AND C.COD_PRODUCTO = :ihpCodProducto
        AND C.COD_SERVICIO = A.COD_SERVICIO
        AND C.COD_TIPSERV  = :szpCodTipServ
        AND C.COD_PLANSERV = :szpCodPlanServ
        AND C.FEC_DESDE   <= TO_DATE(:szpFecEmision,:szpFormatoFec)
        AND NVL(C.FEC_HASTA,TO_DATE('30001201000000','yyyymmddhh24miss')) >= TO_DATE(:szpFecEmision,:szpFormatoFec)
        AND C.IMP_TARIFA  <> :dhpImpCero;	*/


/*
	SELECT  +  index (A, PK_GA_SERVSUPLABO) 
	        A.COD_CONCEPTO,
	        TO_CHAR (A.FEC_ALTACEN,:szpFormatoFec),
	        TO_CHAR (A.FEC_BAJABD ,:szpFormatoFec),
	        TO_CHAR (A.FEC_ALTABD ,:szpFormatoFec),
	        TO_CHAR (A.FEC_BAJACEN,:szpFormatoFec),
	        B.IND_PRO,
	        A.COD_SERVICIO
	   FROM GA_SERVSUPLABO A,
	        GA_SERVSUPL B
	  WHERE A.NUM_ABONADO   = :lhpNumAbonado
		AND A.COD_PRODUCTO  = :ihpCodProducto
		AND A.IND_ESTADO   <> :ihpSeis
		AND ((A.FEC_ALTABD <= to_date(:szhpFecHastaCFijos, :szpFormatoFec)) 
		AND (A.FEC_BAJABD >= to_date(:szhpFecDesdeCFijos, :szpFormatoFec) OR A.FEC_BAJABD IS NULL))
		AND B.COD_PRODUCTO  = A.COD_PRODUCTO
		AND B.COD_SERVICIO  = A.COD_SERVICIO
		AND A.COD_CONCEPTO  IS NOT NULL;*/

/*****************************************************************************/
/*                        funcion : bIFAbonos                                */
/* -Funcion que carga los Abonados activos cuyos servicios van a ser factura-*/
/*  dos.                                                                     */
/*  En stAbonoCli tendremos los Abonados del Cliente (stCliente.lCodCliente),*/
/*  en la tabla Fa_CicloCli                                                  */
/* -Carga infomacion para los Abonados del cliente sobre las Ga_Infa% (infor-*/
/*  macion sobre el alta del Abonado).                                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bIFAbonos (ABONOCLI stAboCli,int iTipoFact)
{
    long lInd = 0   ;
    BOOL bRes = 1;
    struct timeb      tpi;
    struct timeb      tpt;
    

    ftime(&tpi);    
    vDTrazasLog (szExeName,"\n[PGG] INICIO bIFAbonos = %ld.%d\n",LOG03,tpi.time,tpi.millitm);
    
    vDTrazasLog (szExeName,"\n\t\t* Cargando ABONOS ",LOG03);

    strncpy (stAnomProceso.szDesProceso,"Carga Abonos", sizeof (stAnomProceso.szDesProceso));

    memset (&stEstAbonos,0,sizeof(ESTADIST));
    memset (&stEstCargos,0,sizeof(ESTADIST));

    while (bRes && lInd < stAboCli.lNumAbonados)
    {
        strcpy(szFecUltFact,stAboCli.pCicloCli[lInd].szFecUltFact);

        bRes = bCargaAbonosCelular (&stAboCli.pCicloCli[lInd],iTipoFact);
        vfnEstadisticas (stAboCli.pCicloCli[lInd].lNumAbonado);
        if (bRes)
            lInd++;
    }/* fin del While */

    vfnPrintCBasico ();

    stCliente.iIndFactur = ifnClienteFacturable ();
    
    ftime(&tpi);    
    vDTrazasLog (szExeName,"\n[PGG] FIN bIFAbonos = %ld.%d\n",LOG03,tpi.time,tpi.millitm);

    return (bRes);
}/************************* Final bIFAbonos   ********************************/

/*****************************************************************************/
/*                        funcion : bCargaAbonosCelular                      */
/* -Funcion que guarda informacion sobre Ga_InfacCel en la estructura global */
/*  stCliente.pAbonados                                                      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaAbonosCelular (CICLOCLI *pCicloCli,int iTipoFact)
{
    int  iNumAbo         = 0    ;

    char szFecDesde [15] = "";
    char szFecHasta [15] = "";
		struct timeb      tpi;
    struct timeb      tpt;


    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char  szhRowid      [19];/* EXEC SQL VAR szhRowid          IS STRING(19); */ 

    static long  lhNumAbonado      ;
    static long  lhCodCliente      ;
    static int   ihIndActuac       ;
    static short shIndCargos       ;
    static short shIndAlta         ;
    static short shIndDetalle      ;
    static short shIndPenaliza     ;
    static short shIndArriendo     ;
    static short shIndCuotas       ;
    static short shIndSuperTel     ;
    static long  lhCodCiclFact     ;
    static char  szhNumTerminal[16];/* EXEC SQL VAR szhNumTerminal    IS STRING(16); */ 

    static char  szhFecAlta    [15];/* EXEC SQL VAR szhFecAlta        IS STRING(15); */ 

    static char  szhFecBaja    [15];/* EXEC SQL VAR szhFecBaja        IS STRING(15); */ 

    static char  szhFecFinContrato[15];
                                    /* EXEC SQL VAR szhFecFinContrato IS STRING(15); */ 

    static char  szhNumTeleFija[16];/* EXEC SQL VAR szhNumTeleFija    IS STRING(16); */ 

    static int   ihCodSuperTel     ;
    static int   ihIndCargoPro     ;
    static int   ihIndFactur       ;
    static int   ihIndBloqueo      ;
    static int   ihIndCuentaCtl    ;
    static short i_shCodSuperTel   ;
    static short i_shNumTeleFija   ;
    
    static int   iUno=1;
    static int   iDos=2;
    static int   iTres=3; 
    static int   iCinco=5;
    
    /* EXEC SQL END DECLARE SECTION  ; */ 


    ftime(&tpi);    
		vDTrazasLog (szExeName,"\n[PGG] INICIO bCargaAbonosCelular = %ld.%d\n",LOG04,tpi.time,tpi.millitm);


		
    lhCodCliente = pCicloCli->lCodCliente;
    lhNumAbonado = pCicloCli->lNumAbonado;
    lhCodCiclFact= stCiclo.lCodCiclFact  ;

    vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada Ga_Infaccel\n"
                 "\t\t => Cod.Cliente   [%ld]\n"
                 "\t\t => Num.Abonado   [%ld]\n"
                 "\t\t => Cod.CiclFact  [%ld]\n",LOG04, lhCodCliente,lhNumAbonado,lhCodCiclFact);

    if (iTipoFact == FACT_CICLO)
    {
    /********************************************************************/
    /* IndActuac : Normal (1), Baja (2), Traspaso (3), Liquidacion (4), */
    /*             Rechazo(5).                                          */
    /********************************************************************/
    strcpy(szpFormatoFec,"YYYYMMDDHH24MISS");
    /* EXEC SQL SELECT ROWID                                     ,
                    TO_CHAR (FEC_ALTA,:szpFormatoFec)     ,
                    TO_CHAR (FEC_BAJA,:szpFormatoFec)     ,
                    IND_ALTA                                  ,
                    IND_DETALLE                               ,
                    IND_ACTUAC                                ,
                    IND_CARGOS                                ,
                    IND_PENALIZA                              ,
                    IND_ARRIENDO                              ,
                    IND_CUOTAS                                ,
                    TO_CHAR (FEC_FINCONTRA,:szpFormatoFec),
                    TO_CHAR (NUM_CELULAR)                     ,
                    IND_SUPERTEL                              ,
                    NUM_TELEFIJA                              ,
                    IND_CARGOPRO                              ,
                    IND_FACTUR                                ,
                    IND_BLOQUEO                               ,
                    IND_CUENCONTROLADA                        ,
                    COD_SUPERTEL
             INTO   :szhRowid         ,
                    :szhFecAlta       ,
                    :szhFecBaja       ,
                    :shIndAlta        ,
                    :shIndDetalle     ,
                    :ihIndActuac      ,
                    :shIndCargos      ,
                    :shIndPenaliza    ,
                    :shIndArriendo    ,
                    :shIndCuotas      ,
                    :szhFecFinContrato,
                    :szhNumTerminal   ,
                    :shIndSuperTel    ,
                    :szhNumTeleFija   :i_shNumTeleFija,
                    :ihIndCargoPro    ,
                    :ihIndFactur      ,
                    :ihIndBloqueo     ,
                    :ihIndCuentaCtl   ,
                    :ihCodSuperTel    :i_shCodSuperTel
             FROM   GA_INFACCEL
             WHERE  COD_CLIENTE = :lhCodCliente
               AND  NUM_ABONADO = :lhNumAbonado
               AND  COD_CICLFACT= :lhCodCiclFact
               AND  IND_ACTUAC  IN ( :iUno, :iDos ,:iTres, :iCinco ) /o  1: Normal  2:Baja  3:Traspaso  5:Rechazo  o/
            FOR UPDATE OF COD_CLIENTE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select ROWID ,TO_CHAR(FEC_ALTA,:b0) ,TO_CHAR(FEC_BAJA,:b0\
) ,IND_ALTA ,IND_DETALLE ,IND_ACTUAC ,IND_CARGOS ,IND_PENALIZA ,IND_ARRIENDO ,\
IND_CUOTAS ,TO_CHAR(FEC_FINCONTRA,:b0) ,TO_CHAR(NUM_CELULAR) ,IND_SUPERTEL ,NU\
M_TELEFIJA ,IND_CARGOPRO ,IND_FACTUR ,IND_BLOQUEO ,IND_CUENCONTROLADA ,COD_SUP\
ERTEL into :b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16:b17,\
:b18,:b19,:b20,:b21,:b22:b23  from GA_INFACCEL where (((COD_CLIENTE=:b24 and N\
UM_ABONADO=:b25) and COD_CICLFACT=:b26) and IND_ACTUAC in (:b27,:b28,:b29,:b30\
)) for update of COD_CLIENTE ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szpFormatoFec;
    sqlstm.sqhstl[0] = (unsigned long )17;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szpFormatoFec;
    sqlstm.sqhstl[1] = (unsigned long )17;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szpFormatoFec;
    sqlstm.sqhstl[2] = (unsigned long )17;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhRowid;
    sqlstm.sqhstl[3] = (unsigned long )19;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecAlta;
    sqlstm.sqhstl[4] = (unsigned long )15;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhFecBaja;
    sqlstm.sqhstl[5] = (unsigned long )15;
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&shIndAlta;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&shIndDetalle;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihIndActuac;
    sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)&shIndCargos;
    sqlstm.sqhstl[9] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&shIndPenaliza;
    sqlstm.sqhstl[10] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)0;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
    sqlstm.sqhstv[11] = (unsigned char  *)&shIndArriendo;
    sqlstm.sqhstl[11] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[11] = (         int  )0;
    sqlstm.sqindv[11] = (         short *)0;
    sqlstm.sqinds[11] = (         int  )0;
    sqlstm.sqharm[11] = (unsigned long )0;
    sqlstm.sqadto[11] = (unsigned short )0;
    sqlstm.sqtdso[11] = (unsigned short )0;
    sqlstm.sqhstv[12] = (unsigned char  *)&shIndCuotas;
    sqlstm.sqhstl[12] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[12] = (         int  )0;
    sqlstm.sqindv[12] = (         short *)0;
    sqlstm.sqinds[12] = (         int  )0;
    sqlstm.sqharm[12] = (unsigned long )0;
    sqlstm.sqadto[12] = (unsigned short )0;
    sqlstm.sqtdso[12] = (unsigned short )0;
    sqlstm.sqhstv[13] = (unsigned char  *)szhFecFinContrato;
    sqlstm.sqhstl[13] = (unsigned long )15;
    sqlstm.sqhsts[13] = (         int  )0;
    sqlstm.sqindv[13] = (         short *)0;
    sqlstm.sqinds[13] = (         int  )0;
    sqlstm.sqharm[13] = (unsigned long )0;
    sqlstm.sqadto[13] = (unsigned short )0;
    sqlstm.sqtdso[13] = (unsigned short )0;
    sqlstm.sqhstv[14] = (unsigned char  *)szhNumTerminal;
    sqlstm.sqhstl[14] = (unsigned long )16;
    sqlstm.sqhsts[14] = (         int  )0;
    sqlstm.sqindv[14] = (         short *)0;
    sqlstm.sqinds[14] = (         int  )0;
    sqlstm.sqharm[14] = (unsigned long )0;
    sqlstm.sqadto[14] = (unsigned short )0;
    sqlstm.sqtdso[14] = (unsigned short )0;
    sqlstm.sqhstv[15] = (unsigned char  *)&shIndSuperTel;
    sqlstm.sqhstl[15] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[15] = (         int  )0;
    sqlstm.sqindv[15] = (         short *)0;
    sqlstm.sqinds[15] = (         int  )0;
    sqlstm.sqharm[15] = (unsigned long )0;
    sqlstm.sqadto[15] = (unsigned short )0;
    sqlstm.sqtdso[15] = (unsigned short )0;
    sqlstm.sqhstv[16] = (unsigned char  *)szhNumTeleFija;
    sqlstm.sqhstl[16] = (unsigned long )16;
    sqlstm.sqhsts[16] = (         int  )0;
    sqlstm.sqindv[16] = (         short *)&i_shNumTeleFija;
    sqlstm.sqinds[16] = (         int  )0;
    sqlstm.sqharm[16] = (unsigned long )0;
    sqlstm.sqadto[16] = (unsigned short )0;
    sqlstm.sqtdso[16] = (unsigned short )0;
    sqlstm.sqhstv[17] = (unsigned char  *)&ihIndCargoPro;
    sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[17] = (         int  )0;
    sqlstm.sqindv[17] = (         short *)0;
    sqlstm.sqinds[17] = (         int  )0;
    sqlstm.sqharm[17] = (unsigned long )0;
    sqlstm.sqadto[17] = (unsigned short )0;
    sqlstm.sqtdso[17] = (unsigned short )0;
    sqlstm.sqhstv[18] = (unsigned char  *)&ihIndFactur;
    sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[18] = (         int  )0;
    sqlstm.sqindv[18] = (         short *)0;
    sqlstm.sqinds[18] = (         int  )0;
    sqlstm.sqharm[18] = (unsigned long )0;
    sqlstm.sqadto[18] = (unsigned short )0;
    sqlstm.sqtdso[18] = (unsigned short )0;
    sqlstm.sqhstv[19] = (unsigned char  *)&ihIndBloqueo;
    sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[19] = (         int  )0;
    sqlstm.sqindv[19] = (         short *)0;
    sqlstm.sqinds[19] = (         int  )0;
    sqlstm.sqharm[19] = (unsigned long )0;
    sqlstm.sqadto[19] = (unsigned short )0;
    sqlstm.sqtdso[19] = (unsigned short )0;
    sqlstm.sqhstv[20] = (unsigned char  *)&ihIndCuentaCtl;
    sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[20] = (         int  )0;
    sqlstm.sqindv[20] = (         short *)0;
    sqlstm.sqinds[20] = (         int  )0;
    sqlstm.sqharm[20] = (unsigned long )0;
    sqlstm.sqadto[20] = (unsigned short )0;
    sqlstm.sqtdso[20] = (unsigned short )0;
    sqlstm.sqhstv[21] = (unsigned char  *)&ihCodSuperTel;
    sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[21] = (         int  )0;
    sqlstm.sqindv[21] = (         short *)&i_shCodSuperTel;
    sqlstm.sqinds[21] = (         int  )0;
    sqlstm.sqharm[21] = (unsigned long )0;
    sqlstm.sqadto[21] = (unsigned short )0;
    sqlstm.sqtdso[21] = (unsigned short )0;
    sqlstm.sqhstv[22] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[22] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[22] = (         int  )0;
    sqlstm.sqindv[22] = (         short *)0;
    sqlstm.sqinds[22] = (         int  )0;
    sqlstm.sqharm[22] = (unsigned long )0;
    sqlstm.sqadto[22] = (unsigned short )0;
    sqlstm.sqtdso[22] = (unsigned short )0;
    sqlstm.sqhstv[23] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[23] = (         int  )0;
    sqlstm.sqindv[23] = (         short *)0;
    sqlstm.sqinds[23] = (         int  )0;
    sqlstm.sqharm[23] = (unsigned long )0;
    sqlstm.sqadto[23] = (unsigned short )0;
    sqlstm.sqtdso[23] = (unsigned short )0;
    sqlstm.sqhstv[24] = (unsigned char  *)&lhCodCiclFact;
    sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[24] = (         int  )0;
    sqlstm.sqindv[24] = (         short *)0;
    sqlstm.sqinds[24] = (         int  )0;
    sqlstm.sqharm[24] = (unsigned long )0;
    sqlstm.sqadto[24] = (unsigned short )0;
    sqlstm.sqtdso[24] = (unsigned short )0;
    sqlstm.sqhstv[25] = (unsigned char  *)&iUno;
    sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[25] = (         int  )0;
    sqlstm.sqindv[25] = (         short *)0;
    sqlstm.sqinds[25] = (         int  )0;
    sqlstm.sqharm[25] = (unsigned long )0;
    sqlstm.sqadto[25] = (unsigned short )0;
    sqlstm.sqtdso[25] = (unsigned short )0;
    sqlstm.sqhstv[26] = (unsigned char  *)&iDos;
    sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[26] = (         int  )0;
    sqlstm.sqindv[26] = (         short *)0;
    sqlstm.sqinds[26] = (         int  )0;
    sqlstm.sqharm[26] = (unsigned long )0;
    sqlstm.sqadto[26] = (unsigned short )0;
    sqlstm.sqtdso[26] = (unsigned short )0;
    sqlstm.sqhstv[27] = (unsigned char  *)&iTres;
    sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[27] = (         int  )0;
    sqlstm.sqindv[27] = (         short *)0;
    sqlstm.sqinds[27] = (         int  )0;
    sqlstm.sqharm[27] = (unsigned long )0;
    sqlstm.sqadto[27] = (unsigned short )0;
    sqlstm.sqtdso[27] = (unsigned short )0;
    sqlstm.sqhstv[28] = (unsigned char  *)&iCinco;
    sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[28] = (         int  )0;
    sqlstm.sqindv[28] = (         short *)0;
    sqlstm.sqinds[28] = (         int  )0;
    sqlstm.sqharm[28] = (unsigned long )0;
    sqlstm.sqadto[28] = (unsigned short )0;
    sqlstm.sqtdso[28] = (unsigned short )0;
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

    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select Ga_InfacCel->", szfnORAerror());
        return FALSE;
    }
    if (SQLCODE == SQLOK)
    {
        if ( (stCliente.pAbonos =
             (ABONOS *)realloc( (ABONOS *)stCliente.pAbonos,
             (stCliente.iNumAbonos+1)*sizeof(ABONOS) ))==(ABONOS *)NULL)
        {
            iDError (szExeName,ERR005,vInsertarIncidencia,"stCliente.pAbonos");
            return FALSE;
        }
        else
        {
            memset (&stCliente.pAbonos[stCliente.iNumAbonos],0,sizeof(ABONOS))  ;

            stCliente.pAbonos[stCliente.iNumAbonos].lNumAbonado  = lhNumAbonado ;
            stCliente.pAbonos[stCliente.iNumAbonos].iCodProducto = stDatosGener.iProdCelular   ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndActuacOld= ihIndActuac  ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndCargos   = shIndCargos  ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndAlta     = shIndAlta    ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndPenaliza = shIndPenaliza;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndArriendo = shIndArriendo;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndCuotas   = shIndCuotas  ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndCargoPro = ihIndCargoPro;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndFactur   = ihIndFactur  ;
            stCliente.pAbonos[stCliente.iNumAbonos].iIndBloqueo  = ihIndBloqueo ;

            stCliente.pAbonos[stCliente.iNumAbonos].iIndCuenControlada  = ihIndCuentaCtl;

            strcpy (stCliente.pAbonos[stCliente.iNumAbonos].szRowid  ,szhRowid)  ;
            strcpy (stCliente.pAbonos[stCliente.iNumAbonos].szFecAlta,szhFecAlta);
            strcpy (stCliente.pAbonos[stCliente.iNumAbonos].szFecBaja,szhFecBaja);

            /* 20040824 HD-200409061838, HD-200409061839, HD-200409061840  Se publica fecha de baja FA_INFACCEL*/
            strcpy (szFecBaja_Infaccel,szhFecBaja);
            /* 20040824 HD-200409061838, HD-200409061839, HD-200409061840  Se carga fecha Desde Otros Cargos de FA_CICLFACT */
            strcpy (szFecDesdeOCargos, stCiclo.szFecDesdeOCargos);

            strcpy (stCliente.pAbonos[stCliente.iNumAbonos].szFecFinContrato, szhFecFinContrato);
            strcpy (stCliente.pAbonos[stCliente.iNumAbonos].szNumTerminal, szhNumTerminal);

            stCliente.pAbonos[stCliente.iNumAbonos].pstCBasico  =(CARGOFIJO*)NULL;
            stCliente.pAbonos[stCliente.iNumAbonos].iNumCBasicos= 0              ;

            pCicloCli->iIndDetalle = shIndDetalle ;
            pCicloCli->iIndSuperTel= shIndSuperTel;
            pCicloCli->iIndFactur  = ihIndFactur  ;

            if (stCliente.iIndSuperTel < 1 && shIndSuperTel == 1)
                stCliente.iIndSuperTel = shIndSuperTel;

            if (i_shNumTeleFija == ORA_NULL)
                pCicloCli->szNumTeleFija [0] = 0;
            else
                strcpy (pCicloCli->szNumTeleFija,szhNumTeleFija);

            if (stCliente.iCodOpRedFija <= 0 && i_shCodSuperTel != -1)
                stCliente.iCodOpRedFija = ihCodSuperTel;

            strcpy (pCicloCli->szNumTerminal ,szhNumTerminal)   ;
            strcpy (pCicloCli->szFecFinContra,szhFecFinContrato);
            /***************************************************************/
            /*                     Abonados a Tasar                        */
            /***************************************************************/
            if ( (stCliente.pAbonados =
                 (ABONTAR *)realloc ( (ABONTAR *)stCliente.pAbonados,
                  sizeof (ABONTAR) * (stCliente.iNumAbonados + 1)))
                                      == (ABONTAR *)NULL)
            {
                 iDError (szExeName,ERR005,vInsertarIncidencia, "stCliente.pAbonados",szfnORAerror());
                 return FALSE;
            }
            memset(&stCliente.pAbonados[stCliente.iNumAbonados],0,sizeof(ABONTAR));

            strcpy (stCliente.pAbonados[stCliente.iNumAbonados].szRowid, szhRowid);

            stCliente.pAbonados[stCliente.iNumAbonados].lNumAbonado =lhNumAbonado ;
            stCliente.pAbonados[stCliente.iNumAbonados].iCodProducto= stDatosGener.iProdCelular ;
            stCliente.pAbonados[stCliente.iNumAbonados].iIndFactur  = ihIndFactur ;
            stCliente.pAbonados[stCliente.iNumAbonados].iNumConcTar = 0           ;
            stCliente.pAbonados[stCliente.iNumAbonados].pConcTar    = (CONCTAR *)NULL;

            strcpy (szFecDesde, stCiclo.szFecDesdeCFijos);

            strcpy (szFecHasta, (iTipoFact == FACT_CICLO)?stCiclo.szFecHastaCFijos:szSysDate);

            iNumAbo = stCliente.iNumAbonos;

            if(!bfnObtImpCargoBasico(&stCliente.pAbonos[iNumAbo], szFecDesde, szFecHasta, 0, iTipoFact, pCicloCli))
                return FALSE;

            /* Plan Tarifario Vigente */
            if (pCicloCli->szCodPlanTarif [0] == 0)
                strcpy (pCicloCli->szCodPlanTarif, stCliente.pAbonos[iNumAbo].szCodPlanTarif);
            if (pCicloCli->lCodGrupo <= 0)
                pCicloCli->lCodGrupo  =
               (stCliente.pAbonos [iNumAbo].iNumCBasicos)?
                stCliente.pAbonos [iNumAbo].pstCBasico [0].lCodGrupo: 0;

            vDTrazasLog (szExeName,"\n\t\t* Numero de Cargos Basicos [%d] \n",
                                    LOG04,stCliente.pAbonos [iNumAbo].iNumCBasicos);

            if (pCicloCli->szNumTerminal [0] == 0)
                strcpy (pCicloCli->szNumTerminal,
                        stCliente.pAbonos [iNumAbo].szNumTerminal);

/*20040924 HD-200409061838*/
            vDTrazasLog (szExeName, "\n\t\t* Tipo de Plan [%s]\n"
                                    ,LOG04,stCliente.pAbonos[iNumAbo].szTipPlanTarif );

            if (!strcmp (stCliente.pAbonos[iNumAbo].szTipPlanTarif, szINDIVIDUAL))
/*             !strcmp (stCliente.pAbonos[iNumAbo].szTipPlanTarif,'\0')           )  */
            {
                /****************************************************************/
                /*   El Plan Comercial es a nivel de Cliente por lo tanto todos */
                /*los Abonados de un Cliente deberian tener todos el mismo Plan */
                /*Comercial.Inicialmente lo inicializamos a ORA_NULL(PreBilling)*/
                /****************************************************************/
                if (stCliente.lCodPlanCom <= 0)
                    stCliente.lCodPlanCom =
                              stCliente.pAbonos[iNumAbo].lCodPlanCom;
                if (stCliente.pAbonos[iNumAbo].iIndCargos)
                {
                  if (!bCargaServGenerales(stCliente.pAbonos[iNumAbo], iTipoFact))
                       return FALSE;
                }
                if (stCliente.pAbonos[iNumAbo].iIndPenaliza)
                {
                    if (!bIFSac (iTipoFact, ihIndFactur, lhNumAbonado, -1))
                         return FALSE;
                }
                if (stCliente.pAbonos[iNumAbo].iIndCuotas)
                {
                    iNumAbo = stCliente.iNumAbonos;
                    if (!bIFCuotas( stCliente.lCodCliente,
                                    stCliente.pAbonos[stCliente.iNumAbonos].lNumAbonado, /*20040924 HD-200409061838*/
                                    ihIndFactur, iTipoFact))
                        return FALSE;
                }
                if (stCliente.pAbonos[iNumAbo].iIndArriendo == 1 && stCliente.pAbonos [iNumAbo].iNumCBasicos > 0)
                {
                    /************************************************************/
                    /* Introduce los arriendos en la estructura de Abonos,(puede*/
                    /* insertar varios) y los prorratea en el caso de ser nece- */
                    /* sario.                                                   */
                    /************************************************************/
                    if (!bCargaArriendos(stCliente.lCodCliente                  ,
                                         stCliente.pAbonos[iNumAbo].lNumAbonado ,
                                         stCliente.pAbonos[iNumAbo].iCodProducto,
                                         stCliente.pAbonos[iNumAbo].szCodGrpServ))
                        return FALSE;
                }

            }/* fin del if TipPlanTarif == 'I' (Individual) */

            if ((!strcmp (stCliente.pAbonos[iNumAbo].szTipPlanTarif,szEMPRESA)) ||
                (!strcmp (stCliente.pAbonos[iNumAbo].szTipPlanTarif,szHOLDING)))
            {

                if (stCliente.pAbonos[iNumAbo].iIndCargos)
                {
                  if (!bCargaServGenerales(stCliente.pAbonos[iNumAbo], iTipoFact))
                       return FALSE;
                }
            }

            vDTrazasLog (szExeName,"\n\t\t* Numero de Cargos Basicos [%d] \n",
                                    LOG04,stCliente.pAbonos [iNumAbo].iNumCBasicos);

            if (stCliente.iNumServAbo > 0 && stCliente.pAbonos [iNumAbo].iNumCBasicos > 0)
            {
                if (!bfnGetServicios (  stCliente.iNumServAbo-1               ,
                                        stCliente.pAbonos[iNumAbo].iIndFactur ,
                                        stCliente.pAbonos[iNumAbo].iIndBloqueo,
                                        iTipoFact))
                    return FALSE;
            }
            stCliente.iNumAbonos++  ;
            stCliente.iNumAbonados++;

        }/* fin else */
    }
    
    ftime(&tpi);    
		vDTrazasLog (szExeName,"\n[PGG] FIN bCargaAbonosCelular = %ld.%d\n",LOG04,tpi.time,tpi.millitm);
		
    return 1;
}/************************ Final bCargaAbonosCelular *************************/



/*****************************************************************************/
/*                         funcion : bCargaServOcasionales                   */
/* -Funcion que Carga Servicios Ocasionales para un producto                 */
/* -Utilizamos pstActuaServ (Ga_ActuaServ), pstTarifas (Ga_Tarifas) array's  */
/*  donde se cargan las tablas (variables globales al modulo                 */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaServOcasionales (int iServAbo,int iIndFactur)
{
int iNumAct = 0, iNumTar = 0 , iNumServ = 0, i = 0;
char szFecEmision [15] = "";
int  iEncontrado=0;
BOOL CriterioPlanOK = FALSE;

/* EXEC SQL BEGIN DECLARE SECTION; */ 

    static int    ihCodProducto     ;
    static char   szhCodActAbo  [3] ;/* EXEC SQL VAR szhCodActAbo   IS STRING(3) ; */ 

    static char   szhCodTipServ [2] ;/* EXEC SQL VAR szhCodTipServ  IS STRING(2) ; */ 

    static char   szhCodServicio[4] ;/* EXEC SQL VAR szhCodServicio IS STRING(4) ; */ 

    static char   szhCodPlanServ[4] ;/* EXEC SQL VAR szhCodPlanServ IS STRING(4) ; */ 

    static char   szhFecEmision [15];/* EXEC SQL VAR szhFecEmision  IS STRING(15); */ 

    static int    ihCodConcepto     ;
    static double dhImpTarifa       ;
    static char   szhCodMoneda  [4] ;/* EXEC SQL VAR szhCodMoneda   IS STRING(4) ; */ 

    static char   szhTipCuenta  [2] ;/* EXEC SQL VAR szhTipCuenta   IS STRING(2) ; */ 

    static long   lhCodCuenta;
/* EXEC SQL END DECLARE SECTION; */ 


    if (stCliente.pServAbo == (SERVABO *)NULL)
        return 1;

    iNumServ = stCliente.pServAbo[iServAbo].iNumServicios;

    vDTrazasLog (szExeName, "\n\t\t* Carga Servicios Ocasionales\n"
                            "\t\t=> Cliente     [%ld]\n"
                            "\t\t=> Num.Abonado [%ld]\n"
                            "\t\t=> iServAbo    [%ld]\n"
                            "\t\t=> Num.Servic. [%d] \n"
                            ,LOG04, stCliente.lCodCliente
                            ,stCliente.pServAbo[iServAbo].lNumAbonado
                            ,iServAbo, iNumServ);

/* 20040924 HD-200409061838 Se filtra bajas */
    vDTrazasLog (szExeName,"\n\t\t*** Se cargan Servicios Ocasionales ***\n"
                 "\n\t\t*** SI %s >= %s ***\n", LOG05, szFecBaja_Infaccel, szFecDesdeOCargos);
    if( strcmp(szFecBaja_Infaccel, szFecDesdeOCargos)  < 0 )
    {
        vDTrazasLog (szExeName,"\n\t\t*** De Baja, NO se cargan Servicios Ocasionales ***\n", LOG04);
        return(1);
    }

 /* Nuevo codigo 2002-09-06 ncontrer */
    lhCodCuenta = stCliente.lCodCuenta;

    /* EXEC SQL
        SELECT TIP_CUENTA
          INTO :szhTipCuenta
          FROM GA_CUENTAS
         WHERE COD_CUENTA  = :lhCodCuenta; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select TIP_CUENTA into :b0  from GA_CUENTAS where COD_CUE\
NTA=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )136;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhTipCuenta;
    sqlstm.sqhstl[0] = (unsigned long )2;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCuenta;
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




    if (SQLCODE != SQLOK)
    {
        vDTrazasLog (szExeName,"\n\t\t Error al recuperar GA_CUENTAS de cliente %d  \n"
                                  ,LOG05,stCliente.lCodCliente);
        return FALSE;
    }

 /***************************************/

    if (stProceso.iCodTipDocum == stDatosGener.iCodBaja)
    {
        strcpy(szpFormatoFec,"YYYYMMDDHH24MISS");
        
        /* EXEC SQL DECLARE Cur_Tarifas CURSOR FOR
             SELECT B.COD_SERVICIO,
                    B.COD_CONCEPTO,
                    A.IMP_TARIFA  ,
                    A.COD_MONEDA
              FROM  GA_TARIFAS A, GA_ACTUASERV B
             WHERE  A.COD_PRODUCTO = :ihCodProducto
               AND  A.COD_ACTABO   = :szhCodActAbo
               AND  A.COD_TIPSERV  = :szhCodTipServ
               AND  A.COD_SERVICIO = B.COD_SERVICIO
               AND  A.COD_PLANSERV = :szhCodPlanServ
               AND  A.FEC_DESDE   <= TO_DATE(:szhFecEmision,:szpFormatoFec)
               AND (A.FEC_HASTA   >= TO_DATE(:szhFecEmision,:szpFormatoFec)
               OR   A.FEC_HASTA   IS NULL)
               AND  B.COD_PRODUCTO = :ihCodProducto
               AND  B.COD_ACTABO   = :szhCodActAbo
               AND  B.COD_TIPSERV  = :szhCodTipServ; */ 


        if (strcmp (stCliente.pServAbo[iServAbo].szFecDesde,szSysDate) < 0)
        {
            stCliente.pServAbo[iServAbo].iIndAlta = 1;
            strcpy (stCliente.pServAbo[iServAbo].szFecValor,szSysDate);
        }
        else
        {
            stCliente.pServAbo[iServAbo].iIndAlta = 1;
            strcpy (stCliente.pServAbo[iServAbo].szFecValor,
                    stCliente.pServAbo[iServAbo].szFecDesde);
        }
        stCliente.pServAbo [iServAbo].iIndFactur =  iIndFactur            ;

        strcpy (szhFecEmision,szSysDate)                                  ;
        strcpy (szhCodPlanServ,stCliente.pServAbo[iServAbo].szCodPlanServ);
        ihCodProducto = stCliente.pServAbo[iServAbo].iCodProducto         ;

        strcpy (szhCodTipServ ,SERV_OCASIONAL) ;
        strcpy (szhCodActAbo  ,MOD_FACTURACION);

        /* EXEC SQL OPEN Cur_Tarifas; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodProducto;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhCodActAbo;
        sqlstm.sqhstl[1] = (unsigned long )3;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodTipServ;
        sqlstm.sqhstl[2] = (unsigned long )2;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhCodPlanServ;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhFecEmision;
        sqlstm.sqhstl[4] = (unsigned long )15;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[5] = (unsigned long )17;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szhFecEmision;
        sqlstm.sqhstl[6] = (unsigned long )15;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[7] = (unsigned long )17;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&ihCodProducto;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)szhCodActAbo;
        sqlstm.sqhstl[9] = (unsigned long )3;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)szhCodTipServ;
        sqlstm.sqhstl[10] = (unsigned long )2;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
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
                   "Open->Ga_Tarifas A, Ga_ActuaServ B",szfnORAerror());
            return FALSE;
        }
        while (!SQLCODE )
        {
            /* EXEC SQL FETCH Cur_Tarifas INTO :szhCodServicio,
                                            :ihCodConcepto,
                                            :dhImpTarifa  ,
                                            :szhCodMoneda; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )218;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhCodServicio;
            sqlstm.sqhstl[0] = (unsigned long )4;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&ihCodConcepto;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&dhImpTarifa;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)szhCodMoneda;
            sqlstm.sqhstl[3] = (unsigned long )4;
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


            if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,
                        "Fetch->Ga_Tarifas A, Ga_ActuaServ" ,szfnORAerror());
            }
            if (SQLCODE == SQLOK)
            {
                if ( (stCliente.pServAbo[iServAbo].pServicios =(SERVICIOS *)
                      realloc((SERVICIOS*)stCliente.pServAbo[iServAbo].pServicios,
                     (iNumServ+1)*sizeof(SERVICIOS))) == (SERVICIOS *)NULL )
                {
                    iDError (szExeName,ERR005,vInsertarIncidencia,
                             "pServAbo->pServicios");
                    return FALSE;
                }

                /* Codigo para funcionalidad de criterios para servicios ocasionales */

                vDTrazasLog (szExeName, "\n\t\t BfnObtieneValorCrit_PlanTarif (Baja)\n"
                                        "\t\t Servicio   : %s \n"
                                        "\t\t Producto  : %d \n"
                                        "\t\t Tipo Cuenta : %s \n"
                                        ,LOG05,
                                        pstActuaServ[iNumAct].szCodServicio,
                                        stCliente.pServAbo[iServAbo].iCodProducto,
                                        szhTipCuenta);

                CriterioPlanOK = BfnObtieneValorCrit_PlanTarif( szhCodServicio,
                                                                ihCodProducto,
                                                                szhTipCuenta,
                                                                stCliente.pServAbo[iServAbo].lNumAbonado);
                if ( CriterioPlanOK )
                {

                    memset (&stCliente.pServAbo[iServAbo].pServicios[iNumServ],0,
                    sizeof (SERVICIOS));

                    stCliente.pServAbo[iServAbo].pServicios[iNumServ].dImpPeriodo = fnCnvDouble(dhImpTarifa, USOFACT);
                    stCliente.pServAbo[iServAbo].pServicios[iNumServ].dImpConcepto= fnCnvDouble(dhImpTarifa, USOFACT);
                    strcpy(stCliente.pServAbo[iServAbo].pServicios[iNumServ].szCodMoneda, szhCodMoneda);
                    strcpy(stCliente.pServAbo[iServAbo].pServicios[iNumServ].szFecAltaCen, "");
                    strcpy(stCliente.pServAbo[iServAbo].pServicios[iNumServ].szFecBajaBD,"");
                    stCliente.pServAbo[iServAbo].pServicios[iNumServ].iCodConcepto= ihCodConcepto;
                    i = iServAbo;
                    if (!bValidacionServicio(&stCliente.pServAbo[i].pServicios[iNumServ]))
                           return FALSE;
                    iNumServ++;
                }
                else
                {
                    vDTrazasLog (szExeName ,"\n\t\t Servicio [%s] No cumple criterio  \n"
                                       ,LOG05,szhCodServicio);
                }

            }
        }/* fin While ... */

        if (SQLCODE == SQLNOTFOUND)
        {
            /* EXEC SQL CLOSE Cur_Tarifas; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )249;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


            if (SQLCODE)
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,
                        "Close->Ga_Tarifas A, Ga_ActuaServ" ,szfnORAerror());
            }
        }
        return (SQLCODE != SQLOK)?FALSE:TRUE;
    }

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {

        if (strcmp (stCliente.pServAbo[iServAbo].szFecDesde,
                    stCiclo.szFecDesdeOCargos) < 0)
        {
            stCliente.pServAbo[iServAbo].iIndAlta = 1;
            /* strcpy (stCliente.pServAbo[iServAbo].szFecValor,
                    stCiclo.szFecDesdeOCargos); */
        }
        else
        {
            stCliente.pServAbo[iServAbo].iIndAlta = 1;
            /* strcpy (stCliente.pServAbo[iServAbo].szFecValor,
                    stCliente.pServAbo[iServAbo].szFecDesde); */
            vDTrazasLog (szExeName, "\t\t# SERVICIOS OCASIONALES\n"
                                    "\t\t* pServAbo.szFecDesde [%s]\n"
                                    "\t\t* pServAbo.szFecValor [%s]\n"
                                    "\t\t* pServAbo.iNumServicios [%d]\n"
                                    "\t\t* pServAbo.szCodPlanServ [%s]\n",LOG05,
                                    stCliente.pServAbo[iServAbo].szFecDesde,
                                    stCliente.pServAbo[iServAbo].szFecValor,
                                    stCliente.pServAbo[iServAbo].iNumServicios,
                                    stCliente.pServAbo[iServAbo].szCodPlanServ);
        }
        stCliente.pServAbo [iServAbo].iIndFactur=iIndFactur;

        strcpy (szFecEmision,stCiclo.szFecEmision);
        /* RAO20021216: se Reemplazan las sentencias de arriba por la siguiente */
        strcpy (stCliente.pServAbo[iServAbo].szFecValor,szFecEmision);


        for(iNumAct=0;iNumAct<NUM_ACTUASERV;iNumAct++)
        {
            iEncontrado = 0;

            if (strcmp (pstActuaServ[iNumAct].szCodTipServ,SERV_OCASIONAL)==0 &&
                pstActuaServ[iNumAct].iCodConcepto!= ORA_NULL)
            {
                for(iNumTar=0;iNumTar<NUM_TARIFAS && iEncontrado == 0 ;iNumTar++)
                {
                    if (strcmp (pstTarifas  [iNumTar].szCodTipServ,SERV_OCASIONAL)==0 &&
                        strcmp (pstTarifas  [iNumTar].szCodServicio,pstActuaServ[iNumAct].szCodServicio)   == 0      &&
                        strcmp (pstTarifas  [iNumTar].szCodPlanServ,stCliente.pServAbo[iServAbo].szCodPlanServ) == 0 &&
                        strcmp (pstTarifas[iNumTar].szFecDesde, szFecEmision)    <= 0    &&
                        (strcmp (pstTarifas[iNumTar].szFecHasta, szFecEmision)    >= 0    ||
                        strcmp (pstTarifas[iNumTar].szFecHasta,"")                == 0)  )
                    {
                        if ( (stCliente.pServAbo[iServAbo].pServicios =(SERVICIOS *)
                            realloc((SERVICIOS*)stCliente.pServAbo[iServAbo].pServicios,
                            (iNumServ+1)*sizeof(SERVICIOS))) == (SERVICIOS *)NULL )
                        {
                            iDError (szExeName,ERR005,vInsertarIncidencia,
                                    "pServAbo->pServicios");
                            return FALSE;
                        }

                        /* Codigo para funcionalidad de criterios para servicios ocasionales */

                        vDTrazasLog (szExeName, "\n\t\t BfnObtieneValorCrit_PlanTarif (Ciclo) \n"
                                                "\t\t Servicio    : %s \n"
                                                "\t\t Producto    : %d \n"
                                                "\t\t Tipo Cuenta : %s \n"
                                                ,LOG05,
                                                pstActuaServ[iNumAct].szCodServicio,
                                                stCliente.pServAbo[iServAbo].iCodProducto,
                                                szhTipCuenta);

                        CriterioPlanOK = BfnObtieneValorCrit_PlanTarif(pstActuaServ[iNumAct].szCodServicio,
                                                                     stCliente.pServAbo[iServAbo].iCodProducto,
                                                                     szhTipCuenta,
                                                                     stCliente.pServAbo[iServAbo].lNumAbonado);

                        if ( CriterioPlanOK )
                        {
                            memset (&stCliente.pServAbo[iServAbo].pServicios[iNumServ],0,sizeof (SERVICIOS));

                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].dImpPeriodo =
                                                fnCnvDouble(pstTarifas[iNumTar].dImpTarifa, USOFACT);

                            vDTrazasLog (szExeName, "\t\t Importe servicio : [%f] \n",
                                        LOG05,
                                        stCliente.pServAbo[iServAbo].pServicios[iNumServ].dImpPeriodo );

                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].dImpConcepto=
                                                pstTarifas[iNumTar].dImpTarifa;

                            strcpy(stCliente.pServAbo[iServAbo].pServicios[iNumServ].szCodMoneda,
                                                pstTarifas[iNumTar].szCodMoneda);
                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].szFecAltaCen[0]=0;
                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].szFecBajaBD [0]=0;

                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].iCodConcepto=
                                                pstActuaServ[iNumAct].iCodConcepto;
                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].lColumna    = 0   ;
                            stCliente.pServAbo[iServAbo].pServicios[iNumServ].bIndCargo   =FALSE;

                            i = iServAbo;
                            if (!bValidacionServicio(&stCliente.pServAbo[i].pServicios[iNumServ]))
                                return FALSE;
                            iNumServ++;
                        }
                        else
                        {
                            vDTrazasLog (szExeName,"\n\t\t Servicio [%s] No cumple criterio\n"
                                                  ,LOG05,pstActuaServ[iNumAct].szCodServicio);
                        }
                        iEncontrado = 1;
                    }
                }/* fin for iNumTar ... */
            }/* fin IF */
        }
    }/* fin if FACT_CICLO ... */

    stCliente.pServAbo[iServAbo].iNumServicios = iNumServ;

    vDTrazasLog (szExeName,"\t\t# Num.Servicios Ocasionales [%d]\n",LOG04,
                           stCliente.pServAbo[iServAbo].iNumServicios);
    return 1;
}/************************* Final bCargaServOcasionales **********************/


/*****************************************************************************/
/*                          funcion : bCargaServGenerales                    */
/* -Funcion que carga los Servicios Generales para un Abonado                */
/* -Utilizamos pstCargos (Ge_Cargos) array que contiene los reg. de la tabla */
/*  Ge_Cargos (variable global al modulo). Cargamos en stCliente.pCargos     */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaServGenerales (ABONOS stAbono,int iTipoFact)
{
  int iInd = 0;

  vDTrazasLog (szExeName,"\n\t\t* Servicios Generales (Cargos)\n"
                         "\t\t* => Cliente     [%ld]\n"
                         "\t\t* => Num.Abonado [%ld]\n"
                         "\t\t* => Cod.Producto[%d] \n"
                         "\t\t* => Num. Cargos [%d] \n"
                         "\t\t* => Ind. Factur [%d] \n",LOG04,
               stCliente.lCodCliente,stAbono.lNumAbonado,stAbono.iCodProducto,NUM_CARGOS,stCliente.iIndFactur );

  for (iInd=0;iInd<NUM_CARGOS;iInd++)
  {
       if (pstCargos[iInd].lCodCliente     == stCliente.lCodCliente          &&
           pstCargos[iInd].lNumAbonado     == stAbono.lNumAbonado            &&
           pstCargos[iInd].iCodProducto    == stAbono.iCodProducto           &&
           pstCargos[iInd].lNumTransaccion == 0                              &&
           pstCargos[iInd].lNumFactura     <= 0                              &&
           (iTipoFact == FACT_CICLO))

    /****************************************************************************************/
    /*   No considerar fecha de alta del cargo para validar el cargo en el periodo          */
    /*   Solicitado por Evelyn para los clientes cuenta controlada                          */
    /*                                                                                      */
    /*           (iTipoFact == FACT_CICLO                                          &&       */
    /*           strcmp (pstCargos[iInd].szFecAlta,stCiclo.szFecDesdeOCargos) >=0  &&       */
    /*           strcmp (pstCargos[iInd].szFecAlta,stCiclo.szFecHastaOCargos) <=0)          */
    /****************************************************************************************/
       {
           if ( (stCliente.pCargos =
                (CARGOS *)realloc ( (CARGOS *)stCliente.pCargos,
                (stCliente.iNumCargos+1)*sizeof (CARGOS) ))== (CARGOS *)NULL)
           {
                 iDError (szExeName,ERR005,vInsertarIncidencia,
                          "stCliente.pCargos");
                 return FALSE;
           }
           memset (&stCliente.pCargos[stCliente.iNumCargos],0,sizeof(CARGOS));
           memcpy (&stCliente.pCargos[stCliente.iNumCargos],&pstCargos[iInd],
                   sizeof (CARGOS));

           pstCargos[iInd].lNumFactura = stProceso.lNumProceso;
           stCliente.pCargos[stCliente.iNumCargos].iIndFactur =  stCliente.iIndFactur ;

           if (!bValidacionCargo (stCliente.iNumCargos))
                return FALSE;
           strcpy (stCliente.pCargos[stCliente.iNumCargos].szCodRegion   ,
                   stCliente.szCodRegion)   ;
           strcpy (stCliente.pCargos[stCliente.iNumCargos].szCodProvincia,
                   stCliente.szCodProvincia);
           strcpy (stCliente.pCargos[stCliente.iNumCargos].szCodCiudad   ,
                   stCliente.szCodCiudad)   ;
           stCliente.pCargos[stCliente.iNumCargos].lNumProceso = stStatus.IdPro;
           stCliente.iNumCargos++;

       }
  }
  return 1;
}/************************* Final bCargaServGenerales ************************/


/*****************************************************************************/
/*                          funcion : bCargaServSuplementarios               */
/* -Funcion que carga los Servicios Suplementarios de un Abonado             */
/*  Utiliza la carga en memoria de la Tabla Ga_Tarifas (pstTarifas)          */
/*  IndEstado => Alta BD (1), Alta Central (2), Baja BD (3), Baja Central (4)*/
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaServSuplementarios (int iNumServAbo, int iIndFactur , int iTipoFact)
{
  int      iIndTar    = 0            ;
  int      i          = 0            ;
  long 	   plNumFilas = 0L			 ;
  long 	   lCont      = 0L			 ;
  SERVABO *pTmpSerA = (SERVABO *)NULL;
  int 	piSqlCodeLocal = 0;
  PASOPRORRATEO stPasoProrrateo;
  GRUPOCOB stGrupoCob;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

	  static char  szhCodServicio [TAM_HOSTS_PEQ][4];
	  static int   ihCodConcepto  [TAM_HOSTS_PEQ];
	  static char  szhFecAltaCen  [TAM_HOSTS_PEQ][15];
	  static char  szhFecBajaBD   [TAM_HOSTS_PEQ][15];
	  static char  szhFecAltaBD   [TAM_HOSTS_PEQ][15];
	  static char  szhFecBajaCen  [TAM_HOSTS_PEQ][15];
	  static int   ihIndPro		  [TAM_HOSTS_PEQ];

    	static double dhImpTarifa    [TAM_HOSTS_PEQ]   ;
    	static char   szhCodMoneda   [TAM_HOSTS_PEQ][4];
	  
	  static short i_shFecAltaCen [TAM_HOSTS_PEQ];
	  static short i_shFecBajaBD  [TAM_HOSTS_PEQ];
	  static short i_shFecAltaBD  [TAM_HOSTS_PEQ];
	  static short i_shFecBajaCen [TAM_HOSTS_PEQ];
	  static short i_shCodConcepto[TAM_HOSTS_PEQ];
  /* EXEC SQL END DECLARE SECTION  ; */ 


    memset (&stGrupoCob,0,sizeof (GRUPOCOB));

    if (pTmpSerA != (SERVABO *)NULL)
    {
        free (pTmpSerA);
        pTmpSerA = (SERVABO *)NULL;
    }

    pTmpSerA = (SERVABO *)&stCliente.pServAbo[iNumServAbo];

    vDTrazasLog (szExeName, "\n\t\t*  Carga Servicios Suplementarios"
                            "\n\t\t=> Num.Abonado  [%ld]"
                            "\n\t\t=> Cod.TipServ  [%s] "
                            "\n\t\t=> Cod.PlanServ [%s] "
                            "\n\t\t=> pTmpSerA->szFecDesde     [%s] "
                            "\n\t\t=> stCiclo.szFecDesdeCFijos [%s] "
                            ,LOG05,
                            pTmpSerA->lNumAbonado, SERV_SUPLEMENTARIO,
                            pTmpSerA->szCodPlanServ,pTmpSerA->szFecDesde,stCiclo.szFecDesdeCFijos);
    if (strcmp (pTmpSerA->szFecDesde,stCiclo.szFecDesdeCFijos) < 0)
    {
        pTmpSerA->iIndAlta = 0;
        /* strcpy (pTmpSerA->szFecValor, stCiclo.szFecDesdeCFijos); */
    }
    else
    {
        pTmpSerA->iIndAlta = 1;
        /* strcpy (pTmpSerA->szFecValor, pTmpSerA->szFecDesde); */
    }

    strcpy (pTmpSerA->szFecValor, stCiclo.szFecEmision);
    pTmpSerA->iIndFactur = iIndFactur;

	/* variables bind del cursor */
    strcpy(szpFormatoFec,"YYYYMMDDHH24MISS");
    lhpNumAbonado  = pTmpSerA->lNumAbonado;
    ihpCodProducto = 1;
    ihpSeis        = 6;
    strcpy (szhpFecDesdeCFijos, stCiclo.szFecDesdeCFijos);
    strcpy (szhpFecHastaCFijos, stCiclo.szFecHastaCFijos);
    strcpy(szpFecEmision, stCiclo.szFecEmision);
    
    strcpy(szpCodActabo, "FA");
    strcpy(szpCodTipServ, SERV_SUPLEMENTARIO);
    strcpy(szpCodPlanServ, pTmpSerA->szCodPlanServ);
    dhpImpCero = 0.0;
    
	/* variables bind del cursor */

	/* EXEC SQL OPEN Cur_ServSupl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )264;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&lhpNumAbonado;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&ihpCodProducto;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&ihpSeis;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)szhpFecHastaCFijos;
 sqlstm.sqhstl[7] = (unsigned long )15;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[8] = (unsigned long )17;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)szhpFecHastaCFijos;
 sqlstm.sqhstl[9] = (unsigned long )15;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[10] = (unsigned long )17;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[11] = (unsigned long )17;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)szhpFecDesdeCFijos;
 sqlstm.sqhstl[12] = (unsigned long )15;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[13] = (unsigned long )17;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)szpFecEmision;
 sqlstm.sqhstl[14] = (unsigned long )15;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)0;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[15] = (unsigned long )17;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)0;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)szpFecEmision;
 sqlstm.sqhstl[16] = (unsigned long )15;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)0;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[17] = (unsigned long )17;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)0;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)szpCodActabo;
 sqlstm.sqhstl[18] = (unsigned long )3;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)0;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&ihpCodProducto;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)0;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)szpCodTipServ;
 sqlstm.sqhstl[20] = (unsigned long )2;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)szpCodPlanServ;
 sqlstm.sqhstl[21] = (unsigned long )4;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)0;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)szpFecEmision;
 sqlstm.sqhstl[22] = (unsigned long )15;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[23] = (unsigned long )17;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)szpFecEmision;
 sqlstm.sqhstl[24] = (unsigned long )15;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)szpFormatoFec;
 sqlstm.sqhstl[25] = (unsigned long )17;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)0;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&dhpImpCero;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)0;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
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



    if( SQLCODE )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open => GA_SERVSUPLABO",szfnORAerror ());
        
	piSqlCodeLocal = SQLCODE;

	while (!piSqlCodeLocal)
	{
		/* EXEC SQL FETCH Cur_ServSupl 
            INTO :ihCodConcepto :i_shCodConcepto,
                 :szhFecAltaCen :i_shFecAltaCen,
                 :szhFecBajaBD  :i_shFecBajaBD,
                 :szhFecAltaBD  :i_shFecAltaBD,
                 :szhFecBajaCen :i_shFecBajaCen,
                 :ihIndPro      ,
                 :szhCodServicio,
                 :szhCodMoneda  ,
                 :dhImpTarifa   ; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )2000;
  sqlstm.offset = (unsigned int  )387;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)ihCodConcepto;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(int);
  sqlstm.sqindv[0] = (         short *)i_shCodConcepto;
  sqlstm.sqinds[0] = (         int  )sizeof(short);
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqharc[0] = (unsigned long  *)0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhFecAltaCen;
  sqlstm.sqhstl[1] = (unsigned long )15;
  sqlstm.sqhsts[1] = (         int  )15;
  sqlstm.sqindv[1] = (         short *)i_shFecAltaCen;
  sqlstm.sqinds[1] = (         int  )sizeof(short);
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqharc[1] = (unsigned long  *)0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhFecBajaBD;
  sqlstm.sqhstl[2] = (unsigned long )15;
  sqlstm.sqhsts[2] = (         int  )15;
  sqlstm.sqindv[2] = (         short *)i_shFecBajaBD;
  sqlstm.sqinds[2] = (         int  )sizeof(short);
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqharc[2] = (unsigned long  *)0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)szhFecAltaBD;
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )15;
  sqlstm.sqindv[3] = (         short *)i_shFecAltaBD;
  sqlstm.sqinds[3] = (         int  )sizeof(short);
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqharc[3] = (unsigned long  *)0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)szhFecBajaCen;
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )15;
  sqlstm.sqindv[4] = (         short *)i_shFecBajaCen;
  sqlstm.sqinds[4] = (         int  )sizeof(short);
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqharc[4] = (unsigned long  *)0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)ihIndPro;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(int);
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqharc[5] = (unsigned long  *)0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)szhCodServicio;
  sqlstm.sqhstl[6] = (unsigned long )4;
  sqlstm.sqhsts[6] = (         int  )4;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqharc[6] = (unsigned long  *)0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)szhCodMoneda;
  sqlstm.sqhstl[7] = (unsigned long )4;
  sqlstm.sqhsts[7] = (         int  )4;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqharc[7] = (unsigned long  *)0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)dhImpTarifa;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )sizeof(double);
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqharc[8] = (unsigned long  *)0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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



		if (SQLCODE==SQLOK)
			plNumFilas = TAM_HOSTS_PEQ;
		else
		{
			if (SQLCODE==SQLNOTFOUND)
				plNumFilas = sqlca.sqlerrd[2];
			else 
			{
				iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> GA_SERVSUPLABO",szfnORAerror ());
				return (FALSE);
	      	}
		}
		
		piSqlCodeLocal = SQLCODE;
		
		if (!plNumFilas)
		break;

		vDTrazasLog (szExeName, "\n\t\t* serv. supl [%ld]  ", LOG06, plNumFilas);
		
		if ( (pTmpSerA->pServicios=(SERVICIOS *)realloc ( (SERVICIOS *)pTmpSerA->pServicios,
		   (pTmpSerA->iNumServicios+plNumFilas)*sizeof(SERVICIOS) ))== (SERVICIOS *)NULL)
		{
	       iDError (szExeName,ERR005,vInsertarIncidencia,
	       "pServAbo->pServicios");
	       return FALSE;
		}
        memset (&pTmpSerA->pServicios[pTmpSerA->iNumServicios],0,sizeof (SERVICIOS)*plNumFilas);
		
		for (lCont = 0 ; lCont < plNumFilas ; lCont++)
		{
		            vDTrazasLog (szExeName, "\n\t\t* Informacion de GA_SERVSUPLABO recuperados "
		                                    "\n\t\t=> COD_CONCEPTO [%d] "
		                                    "\n\t\t=> IND PRO [%d] "
		                                    "\n\t\t=> FEC_ALTACEN [%s] "
		                                    "\n\t\t=> FEC_BAJABD [%s] "
		                                    "\n\t\t=> FEC_ALTABD [%s] "
		                                    "\n\t\t=> dImpTarifa     [%f] "
		                                    ,LOG05, ihCodConcepto[lCont], ihIndPro[lCont]
		                                    , szhFecAltaCen [lCont], szhFecBajaBD [lCont]
		                                    , szhFecAltaBD  [lCont], szhFecBajaCen[lCont]
		                                    , dhImpTarifa[lCont]);

					        pTmpSerA->pServicios[pTmpSerA->iNumServicios].iCodConcepto =ihCodConcepto [lCont];
	
	                if(i_shFecAltaCen [lCont] == ORA_NULL)
	                {
	                    pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecAltaCen[0] = 0;
	                    if( i_shFecAltaBD [lCont] != ORA_NULL )
	                    {
	                        strcpy(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecAltaCen, szhFecAltaBD[lCont]);
	                    }
	                }
	                else
	                {
	                    strcpy(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecAltaCen, szhFecAltaCen[lCont]);
	                }
	                if (i_shFecBajaBD [lCont] == ORA_NULL)
	                {
	                    pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecBajaBD[0]=0;
		                if( i_shFecBajaCen [lCont] != ORA_NULL )
	                    {
	                        strcpy(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecBajaBD, szhFecBajaCen[lCont]);
	                    }
	                }
	                else
	                {
	                    strcpy(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecBajaBD, szhFecBajaBD[lCont]);
	                }
	
	                strcpy(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szCodMoneda, szhCodMoneda[lCont]);
	                pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpPeriodo  =  dhImpTarifa[lCont]  ;
	                pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpConcepto = dhImpTarifa[lCont]  ;
	
	                i = pTmpSerA->iNumServicios;
	
	                stGrupoCob.iCodConcepto = ihCodConcepto[lCont];
	                stGrupoCob.iCodProducto = ihpCodProducto      ;
	                stGrupoCob.iCodCiclo    = stCiclo.iCodCiclo   ;

	                if (!bValidacionServicio (&pTmpSerA->pServicios[pTmpSerA->iNumServicios]))
	                {
	                    /* 20040602 CH-200404061800 Se agrega Log */
	                    vDTrazasLog (szExeName, "\n\t\t*Servicio Suplementario %s NO Valido !", LOG05, szhCodServicio[lCont]);
	                        return FALSE;
	                }
	
	                vDTrazasLog (szExeName,"\n\t\t* Valor Convertido al Salir de Validacion de Servicio [%10.4f]"
	                                       "\n\t\t* Valor Convertido En La Estructura de Cliente-Abonado-Servicio [%10.4f]"
	                                       , LOG04,pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpConcepto
	                                       , stCliente.pServAbo[iNumServAbo].pServicios[i].iCodConcepto);

	                vDTrazasLog (szExeName,"\n\t\t* Valor antes de entrar al Prorrateo de Servicio [%f]"
	                                       "\n\t\t* pTmpSerA->iNumServicios [%d]"
	                                       ,LOG04,pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpConcepto
	                                       ,pTmpSerA->iNumServicios);
	
	               /****************************** Nuevo Codigo *********************************/
	                strcpy (stGrupoCob.szCodGrupo,pTmpSerA->szCodGrpServ);
	                if ( !bFindGrupoCob(&stGrupoCob))
	                {
	                    vDTrazasLog (szExeName, "\n\t\t* NO Encontro grupo de Cobro %s", LOG05,stGrupoCob.szCodGrupo);
	                        return FALSE;
	                }
	
	                switch (stGrupoCob.iTipCobro)
	                {
	                    case VENCIDO    : pTmpSerA->pServicios[pTmpSerA->iNumServicios].iNumPeriodos = 0;
	                              break;
	                    case ANTICIPADO : pTmpSerA->pServicios[pTmpSerA->iNumServicios].iNumPeriodos = 1;
	                              break;
	                    default     : iDError(szExeName,ERR032,vInsertarIncidencia,stGrupoCob.iTipCobro);
	                              return(FALSE);
	                }
	
	                memset ( &stPasoProrrateo, 0, sizeof(PASOPRORRATEO));
	
	                if (strcmp(pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecAltaCen, szFecUltFact) >0 )
	                {
	                    stPasoProrrateo.sIndAlta = 1;
	                }
	                else
	                {
	                    stPasoProrrateo.sIndAlta = 0;
	                }
	
	                strcpy (stPasoProrrateo.szFecInicio , pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecAltaCen);
	                strcpy (stPasoProrrateo.szFecTermino, pTmpSerA->pServicios[pTmpSerA->iNumServicios].szFecBajaBD);
	                stPasoProrrateo.dImpServicio = pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpPeriodo;
	                stPasoProrrateo.sIndTipoCobro= stGrupoCob.iTipCobro;
	                stPasoProrrateo.sIndProrrateo= ihIndPro[lCont];
	
	                if(!bfnProrrateoStandar(&stPasoProrrateo))
	                {
	            /* 20040602 CH-200404061800 Se agrega Log */
	                    vDTrazasLog (szExeName, "\n\t\t* NO se Prorrate-o el Importe Servicio Suplementario %s", LOG05,szhCodServicio);
	                    return FALSE;
	                }
	
	                pTmpSerA->pServicios[pTmpSerA->iNumServicios].iNumDiasPro = stPasoProrrateo.sDiasAbono;
	                pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpConcepto= fnCnvDouble(stPasoProrrateo.dImpConcepto, USOFACT);
	
	                vDTrazasLog (szExeName, "\n\t\t* Importe Servicio Suplementario Prorrateado [%f]", LOG05,
	                                        pTmpSerA->pServicios[pTmpSerA->iNumServicios].dImpConcepto);
	
	                pTmpSerA->iNumServicios++;
		                                    
		}
	}

    /* EXEC SQL CLOSE Cur_ServSupl; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )438;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE)
				iDError (szExeName,ERR000,vInsertarIncidencia,"Close=> pServicios",szfnORAerror ());

    vDTrazasLog (szExeName,"\n\t\t# Num.Servicios Suplementarios [%d]",LOG04,
                 pTmpSerA->iNumServicios - 1);

    return 1;
}/************************* Final bCargaServSuplementarios *******************/


/*****************************************************************************/
/*                         funcion : bFindGrupoCob                           */
/* -Funcion que busca reg. en Fa_GrupoCob (pstGrupoCob array global), el cri-*/
/*  terio de busqueda es la PK (CodGrupo,CodProducto,CodConcepto,CodCiclo) . */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bFindGrupoCob (GRUPOCOB *pGrpCob)
{
  GRUPOCOB stkey;
  GRUPOCOB *pGrp = (GRUPOCOB *)NULL;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char  szhCodGrupo [3];/* EXEC SQL VAR szhCodGrupo IS STRING(3); */ 

  static int   ihCodProducto  ;
  static int   ihCodConcepto  ;
  static int   ihCodCiclo     ;
  static int   ihTipCobro     ;
  static int   ihTipCobroAnt  ;
  /* EXEC SQL END DECLARE SECTION; */ 


  if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
  {
      strcpy (stkey.szCodGrupo,pGrpCob->szCodGrupo);
      stkey.iCodProducto = pGrpCob->iCodProducto   ;
      stkey.iCodConcepto = pGrpCob->iCodConcepto   ;
      stkey.iCodCiclo    = pGrpCob->iCodCiclo      ;
  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodBaja)
  {
      strcpy (szhCodGrupo,pGrpCob->szCodGrupo);
      ihCodProducto = pGrpCob->iCodProducto   ;
      ihCodConcepto = pGrpCob->iCodConcepto   ;
      ihCodCiclo    = pGrpCob->iCodCiclo      ;
  }
  vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada para Grupo Cobros\n"
                         "\t\t=> Cod.Grupo     [%s]\n"
                         "\t\t=> Cod.Producto  [%d]\n"
                         "\t\t=> Cod.Concepto  [%d]\n"
                         "\t\t=> Cod.Ciclo     [%d]\n",LOG04,
                         pGrpCob->szCodGrupo,pGrpCob->iCodProducto,pGrpCob->iCodConcepto,
                         pGrpCob->iCodCiclo);

  if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
  {
      if ( (pGrp = (GRUPOCOB *)bsearch (&stkey,pstGrupoCob,NUM_GRUPOCOB,
                    sizeof(GRUPOCOB),iCmpGrupoCob)) == (GRUPOCOB *)NULL)
      {
            iDError (szExeName,ERR021,vInsertarIncidencia,"pstGrupoCob");
            return FALSE;
      }
      pGrpCob->iTipCobro    = pGrp->iTipCobro   ;
      pGrpCob->iTipCobroAnt = pGrp->iTipCobroAnt;
  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodBaja)
  {
      /* EXEC SQL SELECT
                      TIP_COBRO   ,
                      TIP_COBROANT
               INTO   :ihTipCobro   ,
                      :ihTipCobroAnt
               FROM   FA_GRUPOCOB
               WHERE  COD_GRUPO    = :szhCodGrupo
                 AND  COD_PRODUCTO = :ihCodProducto
                 AND  COD_CONCEPTO = :ihCodConcepto
                 AND  COD_CICLO    = :ihCodCiclo; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 29;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select TIP_COBRO ,TIP_COBROANT into :b0,:b1  from FA_GR\
UPOCOB where (((COD_GRUPO=:b2 and COD_PRODUCTO=:b3) and COD_CONCEPTO=:b4) and \
COD_CICLO=:b5)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )453;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&ihTipCobro;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&ihTipCobroAnt;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)szhCodGrupo;
      sqlstm.sqhstl[2] = (unsigned long )3;
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
      sqlstm.sqhstv[4] = (unsigned char  *)&ihCodConcepto;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)&ihCodCiclo;
      sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
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
          iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_GrupoCob",
                   szfnORAerror())            ;
          return FALSE;
      }
      else
      {
         pGrpCob->iTipCobro    = ihTipCobro   ;
         pGrpCob->iTipCobroAnt = ihTipCobroAnt;
      }
  }
  return 1;
}/************************ Final bFindGrupoCob *******************************/


/*****************************************************************************/
/*                         funcion : bInsertaCargosBasicos                   */
/* -Funcion que pasa a Fa_PreFactura los Abonos de Ga_Infac% ie:             */
/*          * stCliente.pAbonos (Cargos Basicos: Ga_Intar%-> Ta_CargosBasico)*/
/*****************************************************************************/
static BOOL bInsertaCargosBasicos (void)
{
  static int i = 0, iInd = 0, j = 0, iNumRegAbono = 0, k = 0;

  static int    iCodConcepto      = 0    ;
  static double dImpConcepto      = 0.0  ;
  static char   szCodMoneda   [4] = ""   ;
  static char   szDesConcepto[61] = ""   ;
  static BOOL   bError            = FALSE;

  /*--- Inserto Cargos Basicos (stCliente.pAbonos) ---*/
   vDTrazasLog (szExeName,"\n\t\t* Paso a PreFactura CARGOS BASICOS ***\n"
                          "\t\t=> Cod.Cliente        [%ld]\n"
                          "\t\t=> Cod.CiclFact       [%ld]\n"
                          "\t\t=> Num.Cargos Basicos [%d] \n",
                LOG04,stCliente.lCodCliente,stCiclo.lCodCiclFact,
                stCliente.iNumAbonos);

   i = stPreFactura.iNumRegistros;

   for (iInd=0;iInd<stCliente.iNumAbonos;iInd++)
   {
      for (k=0; k<stCliente.pAbonos[iInd].iNumCBasicos; k++)
      {
        /***************************************************************/
        /* En el mismo Registro  puede venir tanto el CodAbono como el */
        /* CodAbonoFin.                                                */
        /***************************************************************/
        if (stCliente.pAbonos[iInd].pstCBasico [k].iNumDiasFin > 0)
            iNumRegAbono = 2;
        else
            iNumRegAbono = 1;
        for (j=0;j<iNumRegAbono;j++)
        {
          if (j==0)
          {
              dImpConcepto = fnCnvDouble(stCliente.pAbonos[iInd].pstCBasico[k].dImpConcepto, USOFACT);
              iCodConcepto = stCliente.pAbonos[iInd].pstCBasico[k].iCodAbono   ;

              strcpy (szCodMoneda  ,
                      stCliente.pAbonos[iInd].pstCBasico[k].szCodMoneda);
              strcpy (szDesConcepto,
                      stCliente.pAbonos[iInd].pstCBasico[k].szDesAbono );
          }
          else
          {
              dImpConcepto =
                     fnCnvDouble(stCliente.pAbonos[iInd].pstCBasico[k].dImpFinContrato, USOFACT);
              iCodConcepto =
                     stCliente.pAbonos[iInd].pstCBasico[k].iCodAbonoFin   ;

              strcpy (szDesConcepto,
                      stCliente.pAbonos[iInd].pstCBasico[k].szDesAbonoFin );
              strcpy (szCodMoneda  ,
                      stCliente.pAbonos[iInd].pstCBasico[k].szCodMonedaFin);
          }
            if (stPreFactura.iNumRegistros >= MAX_CONCFACTUR)
            {
                iDError (szExeName,ERR035,vInsertarIncidencia);
                return FALSE;
            }
            stPreFactura.A_PFactura.bOptAbonos   [i] = 1                     ;
            stPreFactura.A_PFactura.lNumProceso  [i] = stStatus.IdPro        ;
            stPreFactura.A_PFactura.lCodCliente  [i] = stCliente.lCodCliente ;
            stPreFactura.A_PFactura.dImpMontoBase[i] = 0.0                   ;
            stPreFactura.A_PFactura.lNumUnidades [i] = 1                     ;
            stPreFactura.A_PFactura.iIndEstado   [i] = EST_NORMAL            ;
            stPreFactura.A_PFactura.iCodTipConce [i] = ARTICULO              ;
            stPreFactura.A_PFactura.lCodPlanCom  [i] = stCliente.lCodPlanCom ;
            stPreFactura.A_PFactura.iCodCatImpos [i] = stCliente.iCodCatImpos;
            stPreFactura.A_PFactura.iCodConceRel [i] = 0                     ;
            stPreFactura.A_PFactura.lColumnaRel  [i] = 0                     ;
            stPreFactura.A_PFactura.iFlagImpues  [i] = 0                     ;
            stPreFactura.A_PFactura.fPrcImpuesto [i] = 0.0                   ;
            stPreFactura.A_PFactura.iFlagDto     [i] = 0                     ;
            stPreFactura.A_PFactura.iIndFactur   [i] =
                    stCliente.pAbonos[iInd].iIndFactur                       ;

            strcpy (stPreFactura.A_PFactura.szFecEfectividad[i], szSysDate)  ;
            strcpy (stPreFactura.A_PFactura.szCodRegion     [i],
                    stCliente.szCodRegion   );
            strcpy (stPreFactura.A_PFactura.szCodProvincia  [i],
                    stCliente.szCodProvincia);
            strcpy (stPreFactura.A_PFactura.szCodCiudad     [i],
                    stCliente.szCodCiudad   );
            strcpy (stPreFactura.A_PFactura.szCodModulo     [i],
                    stCliente.pAbonos[iInd].pstCBasico [k].szCodModulo);

            strcpy (stPreFactura.A_PFactura.szDesConcepto   [i],
                    szDesConcepto           );


            stPreFactura.A_PFactura.iCodProducto [i] =
           (stCliente.pAbonos[iInd].lNumAbonado==0)?stDatosGener.iProdGeneral:
                                         stCliente.pAbonos[iInd].iCodProducto;

            stPreFactura.A_PFactura.iCodConcepto [i] = iCodConcepto          ;


            if (!bGetMaxColPreFa(stPreFactura.A_PFactura.iCodConcepto[i],
                                 &stPreFactura.A_PFactura.lColumna[i]))
                 return FALSE;
            strcpy (stPreFactura.A_PFactura.szCodMoneda[i],szCodMoneda);

            strcpy (stPreFactura.A_PFactura.szFecValor [i],
                    stCiclo.szFecEmision);
                    /* stCiclo.szFecDesdeCFijos); */

            stCliente.pAbonos[iInd].lColumna =
                                         stPreFactura.A_PFactura.lColumna [i];

            stPreFactura.A_PFactura.dImpConcepto [i] = dImpConcepto ;

            if (!bConverMoneda (szCodMoneda               ,
                                stDatosGener.szCodMoneFact,
                                stCiclo.szFecDesdeCFijos  ,
                                &dImpConcepto             ,
                                stProceso.iCodTipDocum))
                 return FALSE;

            stPreFactura.A_PFactura.dImpFacturable[i] =
                                        fnCnvDouble(dImpConcepto, USOFACT);

            strcpy (stPreFactura.A_PFactura.szNumTerminal[i],
                    stCliente.pAbonos[iInd].szNumTerminal);

            stPreFactura.A_PFactura.lNumAbonado  [i] =
           (stCliente.pAbonos [iInd].lNumAbonado == 0)?-1:
                                        stCliente.pAbonos[iInd].lNumAbonado  ;
            stPreFactura.A_PFactura.iIndAlta       [i] =
                                        stCliente.pAbonos[iInd].iIndAlta     ;

            stPreFactura.A_PFactura.szNumSerieMec[i][0] = 0;
            stPreFactura.A_PFactura.szNumSerieLe [i][0] = 0;

            stPreFactura.A_PFactura.lCapCode       [i] = ORA_NULL;
            stPreFactura.A_PFactura.iFlagImpues    [i] = 0       ;
            stPreFactura.A_PFactura.iFlagDto       [i] = 0       ;
            stPreFactura.A_PFactura.fPrcImpuesto   [i] = 0.0     ;
            stPreFactura.A_PFactura.dValDto        [i] = 0.0     ;
            stPreFactura.A_PFactura.iTipDto        [i] = 0       ;
            stPreFactura.A_PFactura.lNumVenta      [i] = 0       ;
            stPreFactura.A_PFactura.lNumTransaccion[i] = 0       ;
            stPreFactura.A_PFactura.iMesGarantia   [i] = 0       ;
            stPreFactura.A_PFactura.iIndSuperTel   [i] = 0       ;
            stPreFactura.A_PFactura.iNumPaquete    [i] = 0       ;
            stPreFactura.A_PFactura.iIndCuota      [i] = 0       ;
            stPreFactura.A_PFactura.iNumCuotas     [i] = 0       ;
            stPreFactura.A_PFactura.iOrdCuota      [i] = 0       ;

            strcpy (stPreFactura.A_PFactura.szCodPlanTarif   [i],
                    stCliente.pAbonos[iInd].pstCBasico [k].szCodPlanTarif);
            strcpy (stPreFactura.A_PFactura.szCodCargoBasico [i],
                    stCliente.pAbonos[iInd].pstCBasico [k].szCodCargoBasico);
            strcpy (stPreFactura.A_PFactura.szTipPlanTarif   [i],
                    stCliente.pAbonos[iInd].pstCBasico [k].szTipPlanTarif);


            if (!bfnGetSegCBasico (stPreFactura.A_PFactura.lNumAbonado    [i]
                                  ,stPreFactura.A_PFactura.szCodPlanTarif [i]
                                  ,stCiclo.lCodCiclFact
                                  ,&stPreFactura.A_PFactura.lSegConsumido [i]))
            {
                return (FALSE);
            }

            /* TMC-04079: se agrega a la estructura para paso a prefactura */
            stPreFactura.A_PFactura.lhNumUniFree[i] = stCliente.pAbonos[iInd].pstCBasico[k].lNumUniFree;
            
            strcpy (stPreFactura.A_PFactura.szCod_Unidad   [i],
                    stCliente.pAbonos[iInd].pstCBasico [k].szCod_Unidad);

			    vDTrazasLog (szExeName,"stPreFactura.A_PFactura.szCod_Unidad   [i] [%s]", LOG05,stPreFactura.A_PFactura.szCod_Unidad   [i]);
			    vDTrazasLog (szExeName,"stPreFactura.A_PFactura.lhNumUniFree[i] [%ld]", LOG05,stPreFactura.A_PFactura.lhNumUniFree[i]);
            vPrintRegInsert (i,"Abonos",bError);
            i++                                ;

         }/* fin for iNumRegistros */

     }/* fin for k ... */

   }/* fin for iInd ... */

   stPreFactura.iNumRegistros = i;

   return 1;
}/************************ Final bInsertaCargosBasicos ***********************/

/*****************************************************************************/
/*                         funcion : bEMAbonos                               */
/* -Funcion que pasa a Fa_PreFactura Ge_Cargos y Ta_CargosBasico             */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bEMAbonos (void)
{
     vDTrazasLog (szExeName,
                  "\n\t\t* Paso a PreFactura ABONOS "
          "\n\t\t=> Cliente [%ld]\n",LOG04,stCliente.lCodCliente);

     strcpy (stAnomProceso.szDesProceso,"Paso a PreFactura Abonos")     ;

     if (!bInsertaCargosBasicos ())
          return FALSE;
     if (!bEMArriendos ())
          return FALSE;
     if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
     {
         if (!bUpdateIndInfas ())
                return FALSE;
     }
     return 1;
}/************************* Final bEMAbonos **********************************/


/*****************************************************************************/
/*                        funcion : bEMServicios                             */
/* -Funcion que pasa a Fa_PreFactura los Servicios Suplementarios y Ocasiona-*/
/*  les de un cliente acumulados en stCliente.pServAbo :                     */
/*          * Serv.Suplementario => Ga_ServSuplAbo y Ga_Tarifas              */
/*          * Serv.Ocasional     => Ga_ActuaServ   y Ga_Tarifas              */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bEMServicios (void)
{
int  iInd1  = 0    ;
int  iInd2  = 0    ;
int  i      = 0    ;
BOOL bError = FALSE;

vDTrazasLog (szExeName,"\n\t\t* Paso a PreFactura de Servicios"
                       "\n\t\t=>Cod.Cliente [%ld]",LOG04,stCliente.lCodCliente);

    if (stPreFactura.iNumRegistros > MAX_CONCFACTUR)
    {
        iDError (szExeName,ERR035,vInsertarIncidencia);
        return FALSE;
    }

    i = stPreFactura.iNumRegistros;
    for (iInd1=0;iInd1<stCliente.iNumServAbo;iInd1++)
    {
        for (iInd2=0;iInd2<stCliente.pServAbo[iInd1].iNumServicios;iInd2++)
        {
            if (stCliente.pServAbo[iInd1].pServicios[iInd2].dImpConcepto>=0.01)
            {
                stPreFactura.A_PFactura.bOptServicios[i]= 1                    ;
                stPreFactura.A_PFactura.lNumProceso  [i]= stStatus.IdPro       ;
                stPreFactura.A_PFactura.lCodCliente  [i]= stCliente.lCodCliente;
                stPreFactura.A_PFactura.lCodCiclFact [i]= stCiclo.lCodCiclFact ;
                stPreFactura.A_PFactura.iIndEstado   [i]= EST_NORMAL           ;
                stPreFactura.A_PFactura.iCodTipConce [i]= ARTICULO             ;
                stPreFactura.A_PFactura.iIndFactur   [i]=
                        stCliente.pServAbo[iInd1].iIndFactur                   ;

                strcpy (stPreFactura.A_PFactura.szFecEfectividad[i],szSysDate) ;
                strcpy (stPreFactura.A_PFactura.szCodRegion     [i],
                    stCliente.szCodRegion)   ;
                strcpy (stPreFactura.A_PFactura.szCodProvincia  [i],
                    stCliente.szCodProvincia);
                strcpy (stPreFactura.A_PFactura.szCodCiudad     [i],
                    stCliente.szCodCiudad)   ;
                strcpy (stPreFactura.A_PFactura.szCodModulo     [i], "SE");

                stPreFactura.A_PFactura.lNumAbonado  [i] =
                 stCliente.pServAbo[iInd1].lNumAbonado ;
                stPreFactura.A_PFactura.iCodProducto [i] =
                 stCliente.pServAbo[iInd1].iCodProducto;
                stPreFactura.A_PFactura.iIndAlta     [i] =
                 stCliente.pServAbo[iInd1].iIndAlta    ;
                stPreFactura.A_PFactura.lCapCode     [i] =
                         stCliente.pServAbo[iInd1].lCapCode    ;
                stPreFactura.A_PFactura.lCodPlanCom  [i] =
                         stCliente.pServAbo[iInd1].lCodPlanCom ;
                stPreFactura.A_PFactura.iCodCatImpos [i] =
                             stCliente.iCodCatImpos                ;

                strcpy (stPreFactura.A_PFactura.szFecValor   [i],
                        stCiclo.szFecEmision);
                     /* stCliente.pServAbo[iInd1].szFecValor)   ; */
                strcpy (stPreFactura.A_PFactura.szNumTerminal[i],
                        stCliente.pServAbo[iInd1].szNumTerminal);
                strcpy (stPreFactura.A_PFactura.szDesConcepto[i],
                        stCliente.pServAbo[iInd1].pServicios[iInd2].szDesConcepto);
                stPreFactura.A_PFactura.iCodConcepto[i] =
                        stCliente.pServAbo[iInd1].pServicios[iInd2].iCodConcepto  ;

                if (!bGetMaxColPreFa (stPreFactura.A_PFactura.iCodConcepto[i],
                                     &stPreFactura.A_PFactura.lColumna[i]))
                     return FALSE;

                stCliente.pServAbo[iInd1].pServicios[iInd2].lColumna =
                                           stPreFactura.A_PFactura.lColumna [i];

                stPreFactura.A_PFactura.iCodConceRel  [i] = 0;
                stPreFactura.A_PFactura.lColumnaRel   [i] = 0;
                strcpy(stPreFactura.A_PFactura.szCodMoneda [i],
                       stCliente.pServAbo[iInd1].pServicios[iInd2].szCodMoneda);

                stPreFactura.A_PFactura.dImpConcepto  [i] =
                       stCliente.pServAbo[iInd1].pServicios[iInd2].dImpConcepto;
                stPreFactura.A_PFactura.dImpFacturable[i] =
                       stCliente.pServAbo[iInd1].pServicios[iInd2].dImpConcepto;

                if (!bConverMoneda (stPreFactura.A_PFactura.szCodMoneda    [i],
                                    stDatosGener.szCodMoneFact                ,
                                    stCiclo.szFecDesdeCFijos                  ,
                                   &stPreFactura.A_PFactura.dImpFacturable[i] ,
                                    stProceso.iCodTipDocum))
                     return FALSE;

                stPreFactura.A_PFactura.dImpFacturable[i] =
                            fnCnvDouble( stPreFactura.A_PFactura.dImpFacturable[i],
                                        USOFACT);

                stPreFactura.A_PFactura.dImpMontoBase[i]    = 0;

                stPreFactura.A_PFactura.szNumSerieMec[i][0] = 0;
                stPreFactura.A_PFactura.szNumSerieLe [i][0] = 0;

                stPreFactura.A_PFactura.lCapCode       [i] = ORA_NULL;
                stPreFactura.A_PFactura.iFlagImpues    [i] = 0       ;
                stPreFactura.A_PFactura.iFlagDto       [i] = 0       ;
                stPreFactura.A_PFactura.fPrcImpuesto   [i] = 0.0     ;
                stPreFactura.A_PFactura.dValDto        [i] = 0.0     ;
                stPreFactura.A_PFactura.iTipDto        [i] = 0       ;
                stPreFactura.A_PFactura.lNumVenta      [i] = 0       ;
                stPreFactura.A_PFactura.lNumTransaccion[i] = 0       ;
                stPreFactura.A_PFactura.iMesGarantia   [i] = 0       ;
                stPreFactura.A_PFactura.lNumUnidades   [i] = 1       ;
                stPreFactura.A_PFactura.iIndSuperTel   [i] = 0       ;
                stPreFactura.A_PFactura.iNumPaquete    [i] = 0       ;
                stPreFactura.A_PFactura.iIndCuota      [i] = 0       ;
                stPreFactura.A_PFactura.iNumCuotas     [i] = 0       ;
                stPreFactura.A_PFactura.iOrdCuota      [i] = 0       ;

                vPrintRegInsert (i,"Servicios",bError);
                i++;
            }/* fin if dImpConcepto */
        }/* fin for iInd2 */
    }/* fin for iInd1 */

    stPreFactura.iNumRegistros = i;

    return 1;
}/************************** Final bEMServicios ******************************/

/*****************************************************************************/
/*                          funcion : bValidacionAbono                       */
/* -Funcion que valida que el CodAbono (Concepto) sea valido ie:             */
/*              * IndActivo = 1 y CodTipConce = 3 y ImpConcepto >= 0.01      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bValidacionAbono (int iCodProducto, long lNumAbonado,
                              CARGOFIJO *pAbo)
{
  int    iRes         = 0    ;
  int    iCodConcepto = 0    ;
  double dImpConcepto = 0.0  ;
  BOOL   bFin         = FALSE;
  BOOL   bPrimeraVez  = 1 ;

 CONCEPTO stConcepto;

    while (!bFin && iRes == 0)
    {
        if (bPrimeraVez)
        {
            dImpConcepto = fnCnvDouble(pAbo->dImpConcepto, USOFACT);
            iCodConcepto = pAbo->iCodAbono   ;
            if (pAbo->iNumDiasFin == 0)
                bFin = 1;
        }
        else
        {
            dImpConcepto= fnCnvDouble(pAbo->dImpConcepto, USOFACT);
            iCodConcepto= pAbo->iCodAbonoFin;
            bFin        = 1              ;
        }
        memset (&stConcepto,0,sizeof(CONCEPTO));
        if (!bFindConcepto (iCodConcepto,&stConcepto))
        {
            iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos");
            iRes = ERR021                                                ;
        }
        if (iRes == 0)
        {
            if (bPrimeraVez)
            {
                strcpy (pAbo->szCodMoneda,stConcepto.szCodMoneda  );
                strcpy (pAbo->szDesAbono ,stConcepto.szDesConcepto);
                bPrimeraVez = FALSE;
                vDTrazasLog (szExeName,"\t\t* Cod_Moneda: [%s]  [%s]\n",
                                       LOG05,stConcepto.szCodMoneda,
                                       pAbo->szCodMoneda);
            }
            else
            {
                strcpy (pAbo->szCodMonedaFin,stConcepto.szCodMoneda  );
                strcpy (pAbo->szDesAbonoFin ,stConcepto.szDesConcepto);
            }
            strcpy (pAbo->szCodModulo,stConcepto.szCodModulo);
        }

        if (iRes == 0 && stConcepto.iIndActivo == 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d","Ind.Activo Cero",
                    stConcepto.iIndActivo);
            iRes = ERR001;
        }

        if (iRes == 0 && dImpConcepto < 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,
                    "%s %f","Importe menor que Cero",
                    dImpConcepto);
            iRes = ERR001;
        }

        if  (iRes == 0 &&
            (stConcepto.iCodTipConce == IMPUESTO ||
             stConcepto.iCodTipConce == DESCUENTO) )
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d",
                        "Tipo de Concepto (Descuento o Impuesto)",
                        stConcepto.iCodTipConce);
            iRes = ERR001;
        }

        if (iRes != 0)
        {
            stAnomProceso.iCodConcepto = pAbo->iCodAbono                   ;
            stAnomProceso.iCodProducto = iCodProducto                      ;
            strcpy (stAnomProceso.szDesProceso,"PreBilling Cargos Basicos");
            stAnomProceso.lNumAbonado  = lNumAbonado                       ;

            stEstAbonos.iNumAnomalias++;
            stEstAbonos.dImpAnomalias += dImpConcepto;
            if (iRes == ERR001)
            {
                iDError (szExeName,ERR001,vInsertarIncidencia,
                            stAnomProceso.iCodConcepto,
                            stConcepto.iIndActivo  ,
                            stConcepto.iCodTipConce,
                            dImpConcepto);
            }
        }
        else
        {
            stEstAbonos.iNumCorrectos++;
        }
        stEstAbonos.iNumProcesad++;
    }
    return (iRes == 0)?TRUE:FALSE;
}/***************************** Final bValidacionAbono ***********************/

/*****************************************************************************/
/*                            funcion : vfnEstadistica                       */
/*****************************************************************************/
static void vfnEstadisticas (long lNumAbonado)
{
    vDTrazasLog (szExeName, "\n\t\t* ESTADISTICAS - Cliente[%ld] - Abonado[%ld]"
                            "\n\t\t* Numero de Cargos.................[%d] "
                            "\n\t\t* Numero de Cargos Procesados......[%d] "
                            "\n\t\t* Numero de Cargos Correctos.......[%d] "
                            "\n\t\t* Numero de Anomalias..............[%d] "
                            "\n\t\t* Numero Cargos Basicos Procesados.[%d] "
                            "\n\t\t* Numero Cargos Basicos Correctos..[%d] "
                            "\n\t\t* Numero Cargos Basicos Anomalos...[%d] "
                            ,LOG05, stCliente.lCodCliente
                            ,lNumAbonado
                            ,stCliente.iNumCargos
                            ,stEstCargos.iNumProcesad
                            ,stEstCargos.iNumCorrectos
                            ,stEstCargos.iNumAnomalias
                            ,stEstAbonos.iNumProcesad
                            ,stEstAbonos.iNumCorrectos
                            ,stEstAbonos.iNumAnomalias);
 }/***************************** Final vfnEstadistica *************************/

/*****************************************************************************/
/*                         funcion : bUpdateIndInfas                         */
/* -Funcion que updatea los IndAlta e IndActuac de las tablas Ga_Infac% ie:  */
/*        * Si IndActuacOld == NORMAL => IndAlta = 0                         */
/*        * Si IndActuacOld == RECHAZO=> IndActuac == BAJA                   */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bUpdateIndInfas (void)
{
  char szMsg[50]=""    ;
  int  iInd     = 0    ;
  BOOL bRes     = 1 ;
  BOOL bUpdate  = FALSE;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char*  szhRowid    ; /* EXEC SQL VAR szhRowid      IS STRING (19); */ 

  static short  shIndAlta   ;
  static short  shIndBloqueo;
  /* EXEC SQL END DECLARE SECTION  ; */ 


    while (bRes && iInd<stCliente.iNumAbonos)
    {
        shIndAlta    = 0;
        shIndBloqueo = 0;

        szhRowid = stCliente.pAbonos[iInd].szRowid;
        /********************************************************************/
        /* Los Registros con Rowid a Null son los de Arriendo               */
        /********************************************************************/
        if (strlen (szhRowid) != 0)
        {
            /*******************************************************/
            /* Si esta bloqueado la linea permanece con el ind_alta*/
            /* a 1, y el estado de bloqueado. Si estamos en bloqueo*/
            /* el NumCBasicos == 0, por lo tanto no Update es False*/
            /*******************************************************/
            shIndAlta = (stCliente.pAbonos[iInd].iIndAlta     ==0)?0       :
                        (stCliente.pAbonos[iInd].iIndBloqueo  ==iBLOQUEADO &&
                        stCliente.pAbonos[iInd].iNumCBasicos == 0)?1:0;

            shIndBloqueo =
                        (stCliente.pAbonos[iInd].iIndBloqueo==iBLOQUEADO ||
                         stCliente.pAbonos[iInd].iIndBloqueo==iDESBLOQUEO)?iBLOQUEO_FACTUR:
                         stCliente.pAbonos[iInd].iIndBloqueo;

            bUpdate= (shIndAlta   !=stCliente.pAbonos[iInd].iIndAlta ||
                   shIndBloqueo!=stCliente.pAbonos[iInd].iIndBloqueo)?TRUE:FALSE;

            if (bUpdate)
            {
                strcpy (szMsg,"Update->Ga_InfacCel");
                vDTrazasLog (szExeName, "\n\t\t* Update Ga_Infaccel \n"
                                        "\t\t => Rowid    [%s]\n"
                                        "\t\t => IndAlta  [%d]\n",LOG05, szhRowid, shIndAlta);
                /* EXEC SQL
                    UPDATE GA_INFACCEL
                       SET IND_BLOQUEO = :shIndBloqueo
                     WHERE ROWID       = :szhRowid; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 29;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "update GA_INFACCEL  set IND_BLOQUEO=:b0 where\
 ROWID=:b1";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )492;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&shIndBloqueo;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)szhRowid;
                sqlstm.sqhstl[1] = (unsigned long )19;
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
                    iDError (szExeName,ERR000,vInsertarIncidencia,szMsg, szfnORAerror());
                    bRes = FALSE;
                }
            }/* fin if Update */
        }
        else
        {
            bRes = FALSE          ;
            iDError (szExeName,ERR000,vInsertarIncidencia,"Update Ga_Infac%", "Rowid null");
        }
        if (bRes)
            iInd++;

    }
    return (bRes);
}/**************************** Final bUpdateIndInfas *************************/

/*****************************************************************************/
/*                             funcion : vFreeAbonos                         */
/*****************************************************************************/
void vFreeAbonos (void)
{
    int i = 0;

    vDTrazasLog (szExeName, "\t\t=> stCliente.iNumAbonos:[%d]   i:[%d]\n", LOG05, stCliente.iNumAbonos, i);
    for (i=0; i<stCliente.iNumAbonos;i++)
    {
        if (stCliente.pAbonos[i].pstCBasico != (CARGOFIJO *)NULL)
        {
            free (stCliente.pAbonos[i].pstCBasico)             ;
            stCliente.pAbonos[i].pstCBasico = (CARGOFIJO *)NULL;
        }
    }
    if (stCliente.pAbonos != (ABONOS *)NULL)
    {
        free (stCliente.pAbonos)          ;
        stCliente.pAbonos = (ABONOS *)NULL;
   }
   stCliente.iNumAbonos = 0;
}/*************************** Final vFreeAbonos ******************************/

/*****************************************************************************/
/*                             funcion : vFreeServicios                      */
/*****************************************************************************/
void vFreeServicios (void)
{
 int iInd = 0;

 if (stCliente.pServAbo != (SERVABO *)NULL)
 {
     for (iInd=0;iInd<stCliente.iNumServAbo;iInd++)
     {
          free (stCliente.pServAbo[iInd].pServicios);
          stCliente.pServAbo[iInd].pServicios = (SERVICIOS *)NULL;
          stCliente.pServAbo[iInd].iNumServicios = 0;
     }
     free (stCliente.pServAbo);
     stCliente.pServAbo = (SERVABO *)NULL;
 }
 stCliente.iNumServAbo = 0;
}/*************************** Final vFreeServicios ***************************/

/*****************************************************************************/
/*                         funcion : bCargaArriendos                         */
/* -Funcion que carga los Arriendos de un Abonado a Facturar en ciclo        */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaArriendos(long  lCodCliente ,
                            long  lNumAbonado ,
                            int   iCodProducto,
                            char *szCodGrpServ)

{

    GRUPOCOB      stGrpCob;
    PASOPRORRATEO stPasoProrrateo;

    int iInd = 0, iNum = 0;

    vDTrazasLog (szExeName,"\n\t\t* Cargando Arriendos\n"
                           "\t\t=> Cod.Cliente    [%ld]\n"
                           "\t\t=> Num.Abonado    [%ld]\n"
                           "\t\t=> Cod.Producto   [%d] \n",LOG05,
                           lCodCliente,lNumAbonado,iCodProducto);

    for (iInd=0;iInd<NUM_ARRIENDOS;iInd++)
    {
        if ( (pstArriendo[iInd].lCodCliente == lCodCliente) &&
             (pstArriendo[iInd].lNumAbonado == lNumAbonado) &&
             (pstArriendo[iInd].iCodProducto== iCodProducto) )
        {
            if ((stCliente.pArriendo =
                (ARRIENDO *)realloc ( (ARRIENDO *)stCliente.pArriendo,
                 sizeof (ARRIENDO)*(stCliente.iNumArriendos+1) ) )==(ARRIENDO *)NULL)
            {
                iDError (szExeName,ERR005,vInsertarIncidencia,"stCliente.pArriendo");
                return FALSE;
            }
            memset (&stCliente.pArriendo[stCliente.iNumArriendos],0,sizeof (ARRIENDO));
            memcpy (&stCliente.pArriendo[stCliente.iNumArriendos],&pstArriendo [iInd],sizeof (ARRIENDO));

            strcpy (stCliente.pArriendo[stCliente.iNumArriendos].szCodGrpServ,szCodGrpServ);

            if (strcmp (pstArriendo[iInd].szFecHasta,stCiclo.szFecHastaCFijos) <= 0)
            {
                /*************************************************************/
                /* Si se cumple la Condicion es el ultimo arriendo que se le */
                /* factura, se modifica en la Ga_Infac% el indicativo        */
                /*************************************************************/
                vDTrazasLog (szExeName,
                            "\n\t\t* Parametros Update Ga_InfacCel (IndArriendo = 0)\n"
                            "\t\t=> Cod.Cliente   [%ld]\n"
                            "\t\t=> Num.Abonado   [%ld]\n"
                            "\t\t=> Cod.CiclFact  [%ld]\n",LOG04,
                            lCodCliente,lNumAbonado,stCiclo.lCodCiclFact);

                /* EXEC SQL
                    UPDATE  GA_INFACCEL
                    SET     IND_ARRIENDO  = 0
                    WHERE   COD_CLIENTE   = :lCodCliente
                    AND     NUM_ABONADO   = :lNumAbonado
                    AND     COD_CICLFACT  = :stCiclo.lCodCiclFact; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 29;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "update GA_INFACCEL  set IND_ARRIENDO=0 where \
((COD_CLIENTE=:b0 and NUM_ABONADO=:b1) and COD_CICLFACT=:b2)";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )515;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&lCodCliente;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&lNumAbonado;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&(stCiclo.lCodCiclFact);
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



                if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
                {
                    iDError (szExeName,ERR000,vInsertarIncidencia, szfnORAerror());
                    return FALSE;
                }

            }
            iNum = stCliente.iNumArriendos;
            /*****************************************************************/
            /* Esto no deberia ocurrir porque el arriendo deberia estar ce-  */
            /* rrado y el IndArriendo == 0                                   */
            /*****************************************************************/
            if (strcmp (stCliente.pArriendo[iNum].szFecHasta,
                        stCiclo.szFecDesdeCFijos) < 0)
                stCliente.pArriendo[iNum].dImpConcepto = 0.0;
            else
            {

            /****************************** Nuevo Codigo *********************************/

                memset (&stGrpCob,0,sizeof(GRUPOCOB));

                stGrpCob.iCodConcepto  = pstArriendo[iNum].iCodConcepto;
                stGrpCob.iCodProducto  = pstArriendo[iNum].iCodProducto;
                stGrpCob.iCodCiclo     = stCiclo.iCodCiclo;
                strcpy(stGrpCob.szCodGrupo,pstArriendo[iNum].szCodGrpServ);

            if ( !bFindGrupoCob(&stGrpCob))
                return FALSE;


            memset ( &stPasoProrrateo, 0, sizeof(PASOPRORRATEO));

            strcpy (stPasoProrrateo.szFecInicio,stCliente.pArriendo[iNum].szFecDesde);
            strcpy (stPasoProrrateo.szFecTermino,stCliente.pArriendo[iNum].szFecHasta);
            stPasoProrrateo.dImpServicio = stCliente.pArriendo[iNum].dPrecioMes ;
            stPasoProrrateo.sIndTipoCobro= stGrpCob.iTipCobro;
            stPasoProrrateo.sIndProrrateo= 1;

            if(!bfnProrrateoStandar(&stPasoProrrateo))
                return FALSE;

             stCliente.pArriendo[iNum].dImpConcepto     = stPasoProrrateo.sDiasAbono;
             stCliente.pArriendo[iNum].iNumDiasArriendo = stPasoProrrateo.dImpConcepto;

            vDTrazasLog (szExeName, "\n\t\t* Importe Arriendo [%f]", LOG05,
                         stCliente.pArriendo[iNum].dImpConcepto);

            }
            if (!bValidacionArriendo (&stCliente.pArriendo[iNum]))
                return FALSE;

            stCliente.iNumArriendos++;
        }

    }/* fin for ... */

    return 1;
}/************************* Final bCargaArriendos ****************************/


/*****************************************************************************/
/*                        funcion : bEMArriendos                             */
/* -Funcion que guarda en stPreFactura los Conceptos de Arriendo que tenga el*/
/*  Cliente a procesar.                                                      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bEMArriendos (void)
{
    int  i      = 0    ;
    int  iInd   = 0    ;
    BOOL bError = FALSE;

    for (iInd=0;iInd<stCliente.iNumArriendos;iInd++)
    {
        if (stCliente.pArriendo[i].dImpConcepto >= 0.01)
        {
            if (stPreFactura.iNumRegistros > MAX_CONCFACTUR)
            {
                iDError (szExeName,ERR035,vInsertarIncidencia);
                return FALSE;
            }
            i = stPreFactura.iNumRegistros;

            stPreFactura.A_PFactura.bOptArriendo[i]= 1                    ;
            stPreFactura.A_PFactura.lNumProceso [i]= stStatus.IdPro       ;
            stPreFactura.A_PFactura.lCodCliente [i]= stCliente.lCodCliente;
            stPreFactura.A_PFactura.lCodCiclFact[i]= stCiclo.lCodCiclFact ;
            stPreFactura.A_PFactura.iIndFactur  [i]= FACTURABLE           ;
            stPreFactura.A_PFactura.iIndEstado  [i]= EST_NORMAL           ;
            stPreFactura.A_PFactura.iCodTipConce[i]= ARTICULO             ;

            strcpy (stPreFactura.A_PFactura.szFecEfectividad[i],szSysDate);
            strcpy (stPreFactura.A_PFactura.szCodRegion     [i],
                    stCliente.szCodRegion)   ;
            strcpy (stPreFactura.A_PFactura.szCodProvincia  [i],
                    stCliente.szCodProvincia);
            strcpy (stPreFactura.A_PFactura.szCodCiudad     [i],
                    stCliente.szCodCiudad)   ;
            strcpy (stPreFactura.A_PFactura.szCodModulo     [i],
                    stCliente.pArriendo[iInd].szCodModulo);

            stPreFactura.A_PFactura.lNumAbonado  [i] =
                                       stCliente.pArriendo[iInd].lNumAbonado ;
            stPreFactura.A_PFactura.iCodProducto [i] =
                                       stCliente.pArriendo[iInd].iCodProducto;

            stPreFactura.A_PFactura.iIndAlta     [i] = 0;

            stPreFactura.A_PFactura.lCodPlanCom  [i] = stCliente.lCodPlanCom ;
            stPreFactura.A_PFactura.iCodCatImpos [i] = stCliente.iCodCatImpos;

            /*************************************************************/
            /* La fecha Valor del Arriendo sera la del Mes en Cursor del */
            /* Arriendo en su caso FecDesdeCFijos.                       */
            /*************************************************************/
            strcpy (stPreFactura.A_PFactura.szFecValor   [i],
                    stCiclo.szFecEmision);
                    /* stCiclo.szFecDesdeCFijos                   ); */
            stPreFactura.A_PFactura.szNumTerminal[i][0] = 0     ;

            strcpy (stPreFactura.A_PFactura.szDesConcepto[i],
                    stCliente.pArriendo [iInd].szDesConcepto   );

            stPreFactura.A_PFactura.iCodConcepto[i] =
                                       stCliente.pArriendo[iInd].iCodConcepto;
            if (!bGetMaxColPreFa (stPreFactura.A_PFactura.iCodConcepto[i],
                                  &stPreFactura.A_PFactura.lColumna[i]))
                return FALSE;


            stPreFactura.A_PFactura.iCodConceRel  [i] = 0;
            stPreFactura.A_PFactura.lColumnaRel   [i] = 0;
            strcpy(stPreFactura.A_PFactura.szCodMoneda [i],
                   stCliente.pArriendo[iInd].szCodMoneda);

            stPreFactura.A_PFactura.dImpConcepto  [i] =
                           stCliente.pArriendo[iInd].dImpConcepto;
            stPreFactura.A_PFactura.dImpFacturable[i] =
                           stCliente.pArriendo[iInd].dImpConcepto;

            if (!bConverMoneda (stPreFactura.A_PFactura.szCodMoneda    [i],
                                stDatosGener.szCodMoneFact                ,
                                stCiclo.szFecDesdeCFijos                  ,
                                &stPreFactura.A_PFactura.dImpFacturable[i],
                                stProceso.iCodTipDocum))
                return FALSE;

            stPreFactura.A_PFactura.dImpFacturable[i] =
                         fnCnvDouble( stPreFactura.A_PFactura.dImpFacturable[i],
                                      USOFACT);


            stPreFactura.A_PFactura.dImpMontoBase[i]    = 0;

            stPreFactura.A_PFactura.szNumSerieMec[i][0] = 0;
            stPreFactura.A_PFactura.szNumSerieLe [i][0] = 0;

            stPreFactura.A_PFactura.lCapCode       [i] = ORA_NULL;
            stPreFactura.A_PFactura.iFlagImpues    [i] = 0       ;
            stPreFactura.A_PFactura.iFlagDto       [i] = 0       ;
            stPreFactura.A_PFactura.fPrcImpuesto   [i] = 0.0     ;
            stPreFactura.A_PFactura.dValDto        [i] = 0.0     ;
            stPreFactura.A_PFactura.iTipDto        [i] = 0       ;
            stPreFactura.A_PFactura.lNumVenta      [i] = 0       ;
            stPreFactura.A_PFactura.lNumTransaccion[i] = 0       ;

            stPreFactura.A_PFactura.lNumTransaccion[i] = 0       ;
            stPreFactura.A_PFactura.iMesGarantia   [i] = 0       ;
            stPreFactura.A_PFactura.iIndAlta       [i] = 0       ;
            stPreFactura.A_PFactura.iIndSuperTel   [i] = 0       ;
            stPreFactura.A_PFactura.iNumPaquete    [i] = 0       ;
            stPreFactura.A_PFactura.iIndCuota      [i] = 0       ;
            stPreFactura.A_PFactura.iNumCuotas     [i] = 0       ;
            stPreFactura.A_PFactura.iOrdCuota      [i] = 0       ;

            vPrintRegInsert (i,"Arriendos",bError);
            stPreFactura.iNumRegistros++          ;
        }
    }
    return 1;
}/********************************* Final bEMArriendos ***********************/

/*****************************************************************************/
/*                          funcion : bValidacionArriendo                    */
/* -Funcion que valida que el CodConcepto(Concepto) sea valido ie:           */
/*              * IndActivo = 1 y CodTipConce = 3 y ImpConcepto >= 0.01      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bValidacionArriendo (ARRIENDO *pArr)
{
    int iRes = 0;

    CONCEPTO stConcepto;

    memset (&stConcepto,0,sizeof(CONCEPTO));

    if (!bFindConcepto (pArr->iCodConcepto,&stConcepto))
    {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos");
        iRes = ERR021;
    }
    else
    {
        strcpy (pArr->szDesConcepto,stConcepto.szDesConcepto);
        strcpy (pArr->szCodModulo  ,stConcepto.szCodModulo  );
        if (stConcepto.iIndActivo == 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d","Ind.Activo Cero",
                     stConcepto.iIndActivo);
            iRes = ERR001;
        }
        else if (pArr->dImpConcepto < 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,
                     "%s %f","Importe menor que Cero",
                      pArr->dImpConcepto);
            iRes = ERR001;
        }
        else if  (stConcepto.iCodTipConce == IMPUESTO ||
                  stConcepto.iCodTipConce == DESCUENTO)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d",
                      "Tipo de Concepto (Descuento o Impuesto)",
                      stConcepto.iCodTipConce);
            iRes = ERR001;

        }
        else if ( strcmp (pArr->szCodMoneda,stConcepto.szCodMoneda) != 0 )
        {
            if (!bConverMoneda (pArr->szCodMoneda,
                                stConcepto.szCodMoneda,
                                stCiclo.szFecDesdeCFijos,
                                &pArr->dImpConcepto,
                                stProceso.iCodTipDocum))
                iRes = -1;
            else
                strcpy (pArr->szCodMoneda,stConcepto.szCodMoneda);
        }
    }
    if (iRes != 0)
    {
        stAnomProceso.iCodConcepto = pArr->iCodConcepto          ;
        stAnomProceso.iCodProducto = pArr->iCodProducto          ;
        strcpy (stAnomProceso.szDesProceso,"PreBilling Arriendo");
        stAnomProceso.lNumAbonado  = pArr->lNumAbonado           ;
        if (iRes == ERR001)
        {
            iDError (szExeName,ERR001,vInsertarIncidencia,
                     stAnomProceso.iCodConcepto,
                     stConcepto.iIndActivo  ,
                     stConcepto.iCodTipConce,
                     pArr->dImpConcepto);
        }
    }
    return (iRes == 0)?TRUE:FALSE;
}/**************************** Final bValidacionArriendo ********************/

/* ***************************************************************************/
/*                          funcion : bValidacionServicio                    */
/* -Funcion que valida que el CodConcepto(Concepto) sea valido ie:           */
/*              * IndActivo = 1 y CodTipConce = 3 y ImpConcepto >= 0.01      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bValidacionServicio (SERVICIOS *pSer)
{
    int iRes = 0;
    CONCEPTO stConcepto;
    static double dhImpConcepto      = 0.0  ;

    memset (&stConcepto,0,sizeof(CONCEPTO));

    vDTrazasLog (szExeName, "\n\t\t* Validacion de Servicios"
                            "\n\t\t=> Codigo Concepto     [%d]"
                            "\n\t\t=> Importe Concepto    [%f]"
                            ,LOG05,
                            pSer->iCodConcepto,
                            pSer->dImpConcepto );

    stAnomProceso.iCodConcepto = pSer->iCodConcepto;

    if (!bFindConcepto (pSer->iCodConcepto,&stConcepto))
    {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstConcepto");
        iRes = ERR021;
    }
    else
    {
        strcpy (pSer->szDesConcepto, stConcepto.szDesConcepto);
        if (stConcepto.iIndActivo == 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d","Ind.Activo Cero",
                     stConcepto.iIndActivo);
            iRes = ERR001;
        }
        else if (pSer->dImpConcepto < 0)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %f","Importe menor que Cero",
                     pSer->dImpConcepto);
            iRes = ERR001;
        }
        else if (stConcepto.iCodTipConce == IMPUESTO ||
                stConcepto.iCodTipConce == DESCUENTO)
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d",
                     "Tipo de Concepto (Descuento o Impuesto)",
                     stConcepto.iCodTipConce);
            iRes = ERR001;

        }
        else if ( strcmp (pSer->szCodMoneda,stConcepto.szCodMoneda) != 0 )
        {
            dhImpConcepto = pSer->dImpConcepto  ;

            if (!bConverMoneda (pSer->szCodMoneda       ,
                                stConcepto.szCodMoneda  ,
                                stCiclo.szFecDesdeCFijos,
                                &dhImpConcepto          ,
                                stProceso.iCodTipDocum  ))
                iRes = -1;
            else
            {
                vDTrazasLog (szExeName, "\n\t\t* Valor Convertido en ValidacionServicio [%f]",
                                        LOG05,dhImpConcepto);
                strcpy (pSer->szCodMoneda,stConcepto.szCodMoneda);
                pSer->dImpConcepto = fnCnvDouble(dhImpConcepto, USOFACT);
                pSer->dImpPeriodo  = fnCnvDouble(dhImpConcepto, USOFACT);
            }
        }
    }

    if (iRes != 0)
    {
        stAnomProceso.iCodConcepto = pSer->iCodConcepto           ;
        stAnomProceso.iCodProducto = stConcepto.iCodProducto      ;
        strcpy (stAnomProceso.szDesProceso,"PreBilling Servicios");

        if (iRes == ERR001)
        {
            iDError (   szExeName,ERR001       ,
                        vInsertarIncidencia    ,
                        stAnomProceso.iCodConcepto,
                        stConcepto.iIndActivo  ,
                        stConcepto.iCodTipConce,
                        pSer->dImpConcepto);
        }
    }
    return (iRes == 0)?TRUE:FALSE;
}/***************************** Final bValidacionServicio ********************/

/*****************************************************************************/
/*                        funcion : bfnGetServicios                          */
/* - Carga de Servicios Suplementarios y Servicios Ocasionales               */
/*****************************************************************************/
static BOOL bfnGetServicios (int iNumServs  ,
                             int iIndFactur ,
                             int iIndBloqueo,
                             int iTipoFact)
{
    int iRes = 1;

    vDTrazasLog (szExeName, "\n\t\t*** Generacion de Servicios ***"
                            "\n\t\t=> Servicios Ocasionales   "
                            "\n\t\t=> Servicios Suplementarios", LOG04);

    if (bCargaServOcasionales (iNumServs, iIndFactur))
    {
        if (iIndBloqueo == iBLOQUEO_NORMAL || iIndBloqueo == iDESBLOQUEO)
        {
            if (!bCargaServSuplementarios (iNumServs, iIndFactur, iTipoFact))
                iRes = 0;
        }
    }
    return (iRes)?TRUE:FALSE;
}/************************ Final bfnGetServicios *****************************/

/*****************************************************************************/
/*                        funcion : ifnDBOpenIntar                           */
/*****************************************************************************/
static int ifnDBOpenIntar (long  lCodCliente ,
                           char *pszFecDesde ,
                           char *pszFecHasta ,
                           long  lNumAbonado ,
                           int   iCodProducto,
                           int   iCodCiclo  )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long  lhNumAbonado      ;
    long  lhCodCliente      ;
    int   ihCodCiclo        ;
    int   iCero=0;
    /* EXEC SQL END DECLARE SECTION  ; */ 

    char szCaso [25]="";

    lhCodCliente    = lCodCliente ;
    lhNumAbonado    = lNumAbonado ;
    ihCodCiclo      = iCodCiclo ;

    if (iCodProducto != stDatosGener.iProdCelular )
    {
        vDTrazasError (szExeName,"\n\t\t=> Producto Desconocido [%d]",
                                 LOG04, iCodProducto);
        return -1                          ;
    }

    strcpy(szpFormatoFec,"YYYYMMDDHH24MISS");
    /* EXEC SQL DECLARE Cur_IntarCel CURSOR FOR
        SELECT
                ROWID                                 ,
                TO_CHAR (FEC_DESDE,:szpFormatoFec),
                TO_CHAR (FEC_HASTA,:szpFormatoFec),
                COD_CARGOBASICO                       ,
                COD_PLANSERV                          ,
                COD_PLANCOM                           ,
                TO_CHAR (NUM_CELULAR)                 ,
                COD_GRPSERV                           ,
                TIP_PLANTARIF                         ,
                COD_PLANTARIF                         ,
                COD_GRUPO
        FROM    GA_INTARCEL
        WHERE   COD_CLIENTE   = :lhCodCliente
        AND     NUM_ABONADO   = :lhNumAbonado
        AND     IND_NUMERO    = :iCero
        AND     FEC_DESDE     < TO_DATE (:pszFecHasta, :szpFormatoFec)
        AND     COD_CICLO     = :ihCodCiclo
/o 20040924 HD-200409061838 Se vuelve a version Original o/
        /oAND     FEC_HASTA    >= ADD_MONTHS(TO_DATE (:pszFecDesde, 'YYYYMMDDHH24MISS'), -1) o/
        AND     FEC_HASTA    >= TO_DATE (:pszFecDesde, :szpFormatoFec)
       ORDER BY FEC_DESDE DESC
       FOR UPDATE; */ 



        strcpy (szCaso, "Open=> Ga_IntarCel");

        vDTrazasLog (szExeName,"\n\t\t* Open=> Ga_IntarCel"
                     "\n\t\t=> Cod.Cliente [%ld]"
                     "\n\t\t=> Num.Abonado [%ld]"
                     "\n\t\t=> Cod.Producto[%d] "
                     "\n\t\t=> Cod.Ciclo   [%d] "
                     "\n\t\t=> pszFecHasta [%s] "
                     "\n\t\t=> pszFecDesde [%s] ",LOG05,
                     lCodCliente , lNumAbonado,
                     iCodProducto, iCodCiclo  , pszFecHasta,pszFecDesde);

        /* EXEC SQL OPEN Cur_IntarCel; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )542;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)pszFecHasta;
        sqlstm.sqhstl[5] = (unsigned long )0;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[6] = (unsigned long )17;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&ihCodCiclo;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)pszFecDesde;
        sqlstm.sqhstl[8] = (unsigned long )0;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)szpFormatoFec;
        sqlstm.sqhstl[9] = (unsigned long )17;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
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




    if( SQLCODE )
        iDError (szExeName,ERR000,vInsertarIncidencia,szCaso,szfnORAerror ());

    return(SQLCODE);


}/************************ Final ifnDBOpenIntar ******************************/

/*****************************************************************************/
/*                        funcion : ifnDBFetchIntar                          */
/*****************************************************************************/
static int ifnDBFetchIntar (CARGOFIJO *pstAbo, int iCodProducto)
{
    char szCaso [35]="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    /* EXEC SQL VAR pstAbo->szRowid          IS STRING (19); */ 

    /* EXEC SQL VAR pstAbo->szFecDesde       IS STRING (15); */ 

    /* EXEC SQL VAR pstAbo->szFecHasta       IS STRING (15); */ 

    /* EXEC SQL VAR pstAbo->szCodCargoBasico IS STRING (4) ; */ 

    /* EXEC SQL VAR pstAbo->szCodPlanServ    IS STRING (4) ; */ 

    /* EXEC SQL VAR pstAbo->szCodGrpServ     IS STRING (3) ; */ 

    /* EXEC SQL VAR pstAbo->szNumTerminal    IS STRING (16); */ 

    /* EXEC SQL VAR pstAbo->szTipPlanTarif   IS STRING (2) ; */ 

    /* EXEC SQL VAR pstAbo->szCodPlanTarif   IS STRING (4) ; */ 

    static short i_shCodGrupo                           ;
    /* EXEC SQL END DECLARE SECTION  ; */ 


strcpy (szCaso,
            (iCodProducto == stDatosGener.iProdCelular)?"Fetch=> Ga_IntarCel ":
            (iCodProducto == stDatosGener.iProdBeeper )?"Fetch=> Ga_IntarBeep":
            (iCodProducto == stDatosGener.iProdTrek   )?"Fetch=> Ga_IntarTrek":
            (iCodProducto == stDatosGener.iProdTrunk  )?"Fetch=>Ga_IntarTrunk":"");

    strcpy (szCaso,"Fetch=> Ga_IntarCel ");

    vDTrazasLog (szExeName,"\n\t\t* %s"
                           "\n\t\t=> Cod.Producto [%d]",
                           LOG05, szCaso, iCodProducto);

    if (iCodProducto != stDatosGener.iProdCelular)
    {
        vDTrazasError (szExeName,"\n\t\t=> Producto Desconocido [%d]",LOG04, iCodProducto);
       return -1                          ;
    }
    strcpy (szCaso, "Fetch=> Ga_IntarCel");

    /* EXEC SQL FETCH Cur_IntarCel INTO :pstAbo->szRowid                 ,
                                     :pstAbo->szFecDesde              ,
                                     :pstAbo->szFecHasta              ,
                                     :pstAbo->szCodCargoBasico        ,
                                     :pstAbo->szCodPlanServ           ,
                                     :pstAbo->lCodPlanCom             ,
                                     :pstAbo->szNumTerminal           ,
                                     :pstAbo->szCodGrpServ            ,
                                     :pstAbo->szTipPlanTarif          ,
                                     :pstAbo->szCodPlanTarif          ,
                                     :pstAbo->lCodGrupo :i_shCodGrupo ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )597;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstAbo->szRowid);
    sqlstm.sqhstl[0] = (unsigned long )19;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstAbo->szFecDesde);
    sqlstm.sqhstl[1] = (unsigned long )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstAbo->szFecHasta);
    sqlstm.sqhstl[2] = (unsigned long )15;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstAbo->szCodCargoBasico);
    sqlstm.sqhstl[3] = (unsigned long )4;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)(pstAbo->szCodPlanServ);
    sqlstm.sqhstl[4] = (unsigned long )4;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&(pstAbo->lCodPlanCom);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)(pstAbo->szNumTerminal);
    sqlstm.sqhstl[6] = (unsigned long )16;
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)(pstAbo->szCodGrpServ);
    sqlstm.sqhstl[7] = (unsigned long )3;
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)(pstAbo->szTipPlanTarif);
    sqlstm.sqhstl[8] = (unsigned long )2;
    sqlstm.sqhsts[8] = (         int  )0;
    sqlstm.sqindv[8] = (         short *)0;
    sqlstm.sqinds[8] = (         int  )0;
    sqlstm.sqharm[8] = (unsigned long )0;
    sqlstm.sqadto[8] = (unsigned short )0;
    sqlstm.sqtdso[8] = (unsigned short )0;
    sqlstm.sqhstv[9] = (unsigned char  *)(pstAbo->szCodPlanTarif);
    sqlstm.sqhstl[9] = (unsigned long )4;
    sqlstm.sqhsts[9] = (         int  )0;
    sqlstm.sqindv[9] = (         short *)0;
    sqlstm.sqinds[9] = (         int  )0;
    sqlstm.sqharm[9] = (unsigned long )0;
    sqlstm.sqadto[9] = (unsigned short )0;
    sqlstm.sqtdso[9] = (unsigned short )0;
    sqlstm.sqhstv[10] = (unsigned char  *)&(pstAbo->lCodGrupo);
    sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[10] = (         int  )0;
    sqlstm.sqindv[10] = (         short *)&i_shCodGrupo;
    sqlstm.sqinds[10] = (         int  )0;
    sqlstm.sqharm[10] = (unsigned long )0;
    sqlstm.sqadto[10] = (unsigned short )0;
    sqlstm.sqtdso[10] = (unsigned short )0;
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
    /* if (SQLCODE != SQLOK) */
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,szCaso,szfnORAerror());
    }
    return (SQLCODE);
}/*********************** Final ifnDBFetchIntar ******************************/

/*****************************************************************************/
/*                       funcion : ifnDBCloseIntar                           */
/*****************************************************************************/
static int ifnDBCloseIntar (int iCodProducto)
{
    char szCaso [25] = "";

    strcpy (szCaso, "Close=> Ga_IntarCel");

    vDTrazasLog (szExeName,"\n\t\t* Close=> Ga_IntarCel", LOG05, iCodProducto);
    /* EXEC SQL CLOSE Cur_IntarCel; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )656;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if (SQLCODE)
        iDError (szExeName,ERR000,vInsertarIncidencia,szCaso,szfnORAerror ());

    return (SQLCODE);
}/************************** Final ifnDBCloseIntar ***************************/

/*****************************************************************************/
/*                          funcion : bfnCargaCargoBasico                    */
/* - Funcion que recupera los Cargos Basicos de un Cliente-Abonado.          */
/* - En el proceso de Ciclo, se podran recuperar varios registros, debido al */
/*   posible cambio de plan tarifario que sufran los abonados pertenecientes */
/*   al mismo cliente. Estos tendran una forma distinta de calcular su impor-*/
/*   te, dependiendo si es el que esta en vigencia, o es un plan antiguo.    */
/*****************************************************************************/
static BOOL bfnCargaCargoBasico (ABONOS *pstAbo    ,
                                 char   *szFecDesde,
                                 char   *szFecHasta,
                                 int     iBloqueo  ,
                                 int     iTipoFact)
{

    int  rc              = 0 ;
    int  iServicios      = 1 ;
    int j, flag=0;
    int m=0;
    static int iNumDias = 0;
    static int iTotDias = 0;

    char    fec_desde_aux[9];
    char    fec_hasta_aux[9];

    CARGOFIJO stCBasico;

    vDTrazasLog (szExeName, "\n\t\t* Carga Cargos Basicos"
                            "\n\t\t=> Cod.Cliente [%ld]"
                            "\n\t\t=> Num.Abonado [%ld]"
                            "\n\t\t=> Cod.Producto[%ld]"
                            "\n\t\t=> Fec.DesdeCF [%s] "
                            "\n\t\t=> Fec.HastaCF [%s] "
                            "\n\t\t=> Factura Blk.[%d] "
                            "\n\t\t=> Tipo Fact.  [%d] ", LOG04,
                            stCliente.lCodCliente, pstAbo->lNumAbonado,
                            pstAbo->iCodProducto , szFecDesde         ,
                            szFecHasta, iBloqueo , iTipoFact);

    if (ifnDBOpenIntar (stCliente.lCodCliente, szFecDesde, szFecHasta, pstAbo->lNumAbonado ,
                        pstAbo->iCodProducto , stCiclo.iCodCiclo))
        return FALSE;

    while (rc == 0)
    {
        memset (&stCBasico, 0, sizeof (CARGOFIJO));

        rc = ifnDBFetchIntar (&stCBasico, pstAbo->iCodProducto);


        switch (rc)
        {
            case SQLOK      :
                /*stCBasico.iCodAbono =pstAbo->iCodProducto==stDatosGener.iProdCelular;*/
                stCBasico.iCodAbono =stDatosGener.iCodAbonoCel;
                /*stCBasico.iCodAbonoFin =pstAbo->iCodProducto==stDatosGener.iProdCelular;*/
                stCBasico.iCodAbonoFin =stDatosGener.iCodAbonoFinCel;
/* 20040924 200408222076 Hace 1 solo registro de tecnologia, si hay mas de 1 */
                if(pstAbo->iNumCBasicos > 0)
                {
/* 20040924 200408222076 Si son iguales los planes al cargo basico anterior, solo para los contiguos */
                    vDTrazasLog (szExeName, "\n\t\t* Comprobacion de planes con cambio de tecnologia [%s] vs [%s]", LOG05,stCBasico.szCodCargoBasico, pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szCodCargoBasico);
                    if(!strcmp(stCBasico.szCodCargoBasico, pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szCodCargoBasico))
                    {
                        memset(fec_hasta_aux,0,sizeof(fec_hasta_aux));
                        strncpy(fec_hasta_aux,stCBasico.szFecHasta,8);

                        memset(fec_desde_aux,0,sizeof(fec_desde_aux));
                        strncpy(fec_desde_aux,pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecDesde,8);

/* 20040924 200408222076 Si las fechas no son iguales, Hay laguna, restamos del fecdesde la cantidad de dias de la laguna */
                        vDTrazasLog (szExeName, "\n\t\t* Hay lagunas entre [%s] vs [%s]", LOG05,fec_desde_aux, fec_hasta_aux);
                        if(strcmp(fec_desde_aux, fec_hasta_aux) != 0)
                        {
/* 20040924 200408222076 Se sacan los dias de laguna */
                            if(bRestaFechas( pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecDesde, stCBasico.szFecHasta, &iNumDias))
                            {
/* 20040924 200408222076 Los dias de laguna se restan al fechasta, se hace negativo */
                                iNumDias *= -1;
                                vDTrazasLog (szExeName, "\n\t\t* Fecha Hasta [%s] se restan [%d] dias", LOG05,pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecHasta,iNumDias);
                                if(!bSumaDias(pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecHasta, pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecHasta,iNumDias))
                                {
                                    vDTrazasLog(szExeName, "\n\t\t* Problemas al restar %d dia a [%s]\n", LOG02, iNumDias, pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecHasta);
                                }
                                vDTrazasLog (szExeName, "\n\t\t* Nueva Fecha Hasta [%s].", LOG05,pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecHasta);
                            }
                        }
/* 20040924 200408222076 Copiamos la fecha desde del cargo al que se esta haciendo uno solo */
                        vDTrazasLog (szExeName, "\n\t\t* Fecha desde [%s] se reemplaza por [%s]", LOG05,pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecDesde, stCBasico.szFecDesde);
                        strcpy(pstAbo->pstCBasico[pstAbo->iNumCBasicos-1].szFecDesde, stCBasico.szFecDesde);
/* 20040924 200408222076 Seguimos con el siguiente cargo basico */
                        continue;
                    }
                }

                if (stCliente.szTipPlanTarif [0] == 0)
                      strcpy (stCliente.szTipPlanTarif, stCBasico.szTipPlanTarif);

                if (pstAbo->szCodPlanTarif [0] == 0)
                      strcpy (pstAbo->szCodPlanTarif, stCBasico.szCodPlanTarif);

                if (pstAbo->lCodGrupo <= 0)
                      pstAbo->lCodGrupo = stCBasico.lCodGrupo;

                strcpy (pstAbo->szNumTerminal, stCBasico.szNumTerminal);

                if ((pstAbo->pstCBasico =
                      (CARGOFIJO *)realloc ( (CARGOFIJO *)pstAbo->pstCBasico,
                      (pstAbo->iNumCBasicos + 1) * sizeof (CARGOFIJO)))
                                          == (CARGOFIJO *)NULL)
                {
                    iDError (szExeName,ERR005,vInsertarIncidencia, "pstAbo->pstCBasico");
                        return  (FALSE) ;
                }
                memcpy (&pstAbo->pstCBasico [pstAbo->iNumCBasicos], &stCBasico, sizeof (CARGOFIJO));
                pstAbo->iNumCBasicos++ ;

                if (iServicios)
                {
                    /*********************************************************/
                    /*  Los Cargos Basicos agrupados, tendran las misma infor*/
                    /* macion, para los servicios. CodGrpServ, CodPlanServ,..*/
                    /*  Por ese motivo solo se efectua una vez.              */
                    /*********************************************************/
                    if (!bfnInfServicios (pstAbo, stCBasico))
                        return FALSE ;

                    iServicios = 0;

                }
                if (!iBloqueo)
                {
                    vDTrazasLog (szExeName, "\n\t\t=> Cargo Basico : (Control Fechas [<=]:fin)"
                                            "\n\t\t=> FecDesde (Cargo Basico) [%s]"
                                            "\n\t\t=> FecDesde (Ciclo)        [%s]", LOG05,
                                            stCBasico.szFecDesde, szFecDesde);
                    rc=(strcmp (stCBasico.szFecDesde, szFecDesde)>=0)? rc : SQLNOTFOUND;
                }
                break;
            case SQLNOTFOUND:
                break;
            default         :
                return FALSE;
        }/* fin switch */
    }/* fin while */

    m=pstAbo->iNumCBasicos-1;

    if (pstAbo->iNumCBasicos > 1)   /* Tiene mas de 1 registro en GA_INTARCEL ==> Se analiza si */
    {

        /* 20040901 CH-200408222076  Se reemplazan dias traslapados de fec_desde actual vs fec_hasta anterior */
        j=m;
        while( j>0 )
        {
            vDTrazasLog (szExeName, "\n\t\t* Comprobacion traslape de dias Entrada FecDesde [%s] vs FecHasta[%s]", LOG04,pstAbo->pstCBasico[j-1].szFecDesde, pstAbo->pstCBasico[j].szFecHasta);

            memset(fec_desde_aux,0,sizeof(fec_desde_aux));
            strncpy(fec_desde_aux,pstAbo->pstCBasico[j-1].szFecDesde,8);

            memset(fec_hasta_aux,0,sizeof(fec_hasta_aux));
            strncpy(fec_hasta_aux,pstAbo->pstCBasico[j].szFecHasta,8);

            vDTrazasLog (szExeName, "\t\t* Comparando [%s] vs [%s]", LOG05,fec_desde_aux, fec_hasta_aux);
            if( strcmp(fec_desde_aux, fec_hasta_aux) == 0 )
            {
                if( !bSumaDias(pstAbo->pstCBasico[j].szFecHasta,pstAbo->pstCBasico[j].szFecHasta,-1) )
                {
                    vDTrazasLog(szExeName, "\n\t\t* Problemas al restar 1 dia a [%s]\n", LOG02, pstAbo->pstCBasico[j].szFecHasta);
                }
                else
                {
                    memset(fec_hasta_aux,0,sizeof(fec_hasta_aux));
                    strncpy(fec_hasta_aux,pstAbo->pstCBasico[j].szFecHasta,8);
                    sprintf(pstAbo->pstCBasico[j].szFecHasta,  "%ld235959", atol(fec_hasta_aux));
                    sprintf(pstAbo->pstCBasico[j-1].szFecDesde,"%ld000000", atol(fec_desde_aux));
                }
            }
            vDTrazasLog (szExeName, "\t\t* Comprobacion traslape de dias Salida  FecDesde [%s] vs FecHasta[%s]\n", LOG05,pstAbo->pstCBasico[j-1].szFecDesde, pstAbo->pstCBasico[j].szFecHasta);
            j--;
        }
        /* existe al menos 1 cambio de plan con vigencia inmediata  */
        j=m;
        flag=0;

        while((strcmp(pstAbo->pstCBasico[j].szCodCargoBasico, pstAbo->pstCBasico[j-1].szCodCargoBasico)==0) && (j>0))
        {
            j--;
        }
        if(j==0)
        {
            flag=0;                  /* No tiene cambios de plan con vigencia inmediata */
        }
        else
        {
            flag=1;                  /* Existe al menos 1 cambio de plan con vigencia inmediata */
        }

/*         if (flag == 0) {                                                                       */
/*             j=m;                                                                               */
/*             while (j>0) {                                                                      */
/*                 strcpy(pstAbo->pstCBasico[j-1].szFecDesde, pstAbo->pstCBasico[j].szFecDesde);  */
/*                 j--;                                                                           */
/*             }                                                                                  */
/*         }                                                                                      */
    }

    /*************************************************************************/
    /*    No Tiene Registros Para el Periodo  ( Baja o Traspaso )            */
    /*************************************************************************/

    vDTrazasLog (szExeName, "\n\t\t* Nro Abonados Ga_Intarcel [%d]\n", LOG04, pstAbo->iNumCBasicos);

    if (pstAbo->iNumCBasicos == 0)
    {
        vDTrazasLog (szExeName, "\n\t\t* Abonado Sin  Periodo Vigente en Ga_Intar.....", LOG04);
        return 1;
    }

    vDTrazasLog (szExeName, "\n\t\t* Cambios de Plan Inmediato: %s"
                            "\n\t\t* Numero de Registros (M): %d"
                            "\n\t\t* Fecha Desde Antes: %s"
                            "\n\t\t* Fecha Hasta Antes: %s"
                            "\n\t\t* Fecha Desde CFijo : %s"
                            "\n\t\t* Fecha Hasta CFijo : %s"
                            ,LOG05
                            ,(flag==1?"SI":"NO")
                            ,m+1
                            ,pstAbo->pstCBasico[0].szFecDesde
                            ,pstAbo->pstCBasico[0].szFecHasta
                            ,szFecDesde
                            ,szFecHasta);

    if((flag==0) && (m > 0))/* Mas de un cargo en GA_INTARCEL */
    {
/*
         if (strcmp(pstAbo->pstCBasico[0].szFecHasta,szFecHasta) > 0 )
             strcpy(pstAbo->pstCBasico[0].szFecHasta,szFecHasta);

         pstAbo->iNumCBasicos=1;
         if (!bRestaFechas ( pstAbo->pstCBasico[j].szFecHasta,
                             pstAbo->pstCBasico[j].szFecDesde,
                             &iNumDias))
             vDTrazasLog(szExeName,  "\n\t\t* Fecha Desde Despues: %s"
                                     "\n\t\t* Fecha Hasta Despues: %s"
                                     "\n\t\t* Numero de Dias     : %d"
                                     , LOG05,pstAbo->pstCBasico[0].szFecDesde
                                     , pstAbo->pstCBasico[0].szFecHasta,iNumDias);
*/
        /********************************************************************/
        /*   Busca Periodos con fechas dentro del periodo de Facturacion    */
        /********************************************************************/
        iTotDias=0;
        for(j=0;j<pstAbo->iNumCBasicos;j++)
        {
/* 20040901 CH-200408222076  Se incicializa en 1  */
            iNumDias = 1;
            /*        ALTA       DCF         HCF       BAJA          */
            /*.....|.---|----------|----------|----------|---........*/
            /*.....................|<-------->|......................*/
            if(strcmp(pstAbo->pstCBasico[j].szFecDesde,szFecDesde) <= 0 &&
               strcmp(pstAbo->pstCBasico[j].szFecHasta,szFecHasta) >= 0)
            {
                iNumDias = stCiclo.iDiaPeriodo;
                vDTrazasLog(szExeName,  "\n\t\t* Busca Periodos"
                            "\n\t\t* Caso 1: Alta y baja fuera del periodo."
                            "\n\t\t* Numero de dias: [%d]", LOG05, iNumDias);
            }
            /*        ALTA       DCF        BAJA       HCF           */
            /*.....|.---|----------|----------|----------|---........*/
            /*....................|<-------->|.......................*/
            else if(strcmp(pstAbo->pstCBasico[j].szFecDesde,szFecDesde) <= 0 &&
                    strcmp(pstAbo->pstCBasico[j].szFecHasta,szFecDesde) >= 0 &&
                    strcmp(pstAbo->pstCBasico[j].szFecHasta,szFecHasta) <= 0)
            {
                vDTrazasLog(szExeName,  "\n\t\t=>bfnCargaCargoBasico bRestaFechas CASO 2"
                            "\n\t\t=> pstAbo->pstCBasico[j].szFecHasta : [%s]"
                            "\n\t\t=> szFecDesde : [%s]",LOG05, pstAbo->pstCBasico[j].szFecHasta, szFecDesde);
                if(!bRestaFechas ( pstAbo->pstCBasico[j].szFecHasta, szFecDesde, &iNumDias))
                {
                    iNumDias = 1;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=>bfnCargaCargoBasico Dias Calculados [%d]",LOG05, iNumDias);
                }

                vDTrazasLog(szExeName, "\n\t\t* Busca Periodos" "\n\t\t* Caso 2: Alta fuera y baja dentro."
                            "\n\t\t* Numero de dias: [%d]", LOG05, iNumDias);

            }
            /*        DCF       ALTA        BAJA       HCF           */
            /*......---|----------|----------|----------|---.........*/
            /*....................|<-------->|.......................*/
            else if(strcmp(pstAbo->pstCBasico[j].szFecDesde,szFecDesde) >= 0 &&
                    strcmp(pstAbo->pstCBasico[j].szFecHasta,szFecHasta) <= 0)
            {
                vDTrazasLog(szExeName,  "\n\t\t=>bfnCargaCargoBasico bRestaFechas CASO 3"
                            "\n\t\t=> pstAbo->pstCBasico[j].szFecHasta : [%s]"
                            "\n\t\t=> pstAbo->pstCBasico[j].szFecDesde : [%s]",LOG05,
                            pstAbo->pstCBasico[j].szFecHasta, pstAbo->pstCBasico[j].szFecDesde);

                if(!bRestaFechas ( pstAbo->pstCBasico[j].szFecHasta, pstAbo->pstCBasico[j].szFecDesde, &iNumDias))
                {
                    iNumDias = 1;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=>bfnCargaCargoBasico Dias Calculados [%d]",LOG05, iNumDias);
                }

                vDTrazasLog(szExeName, "\n\t\t* Busca Periodos" "\n\t\t* Caso 3: Alta y baja dentro."
                            "\n\t\t* Numero de dias: [%d]", LOG05, iNumDias);
            }
            /*        DCF       ALTA        HCF       BAJA          */
            /*......---|----------|----------|----------|---........*/
            /*....................|<-------->|......................*/
            else if(strcmp(pstAbo->pstCBasico[j].szFecDesde,szFecDesde) >= 0 &&
                    strcmp(pstAbo->pstCBasico[j].szFecDesde,szFecHasta) <= 0 &&
                    strcmp(pstAbo->pstCBasico[j].szFecHasta,szFecHasta) >= 0)
            {
                vDTrazasLog(szExeName,  "\n\t\t=>bfnCargaCargoBasico bRestaFechas CASO 4"
                            "\n\t\t=> szFecHasta                       : [%s]"
                            "\n\t\t=> pstAbo->pstCBasico[j].szFecDesde : [%s]",LOG05,
                            szFecHasta, pstAbo->pstCBasico[j].szFecDesde);

                if(!bRestaFechas ( szFecHasta, pstAbo->pstCBasico[j].szFecDesde, &iNumDias))
                {
                    iNumDias = 1;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=>bfnCargaCargoBasico Dias Calculados [%d]",LOG05, iNumDias);
                }

                vDTrazasLog(szExeName, "\n\t\t* Busca Periodos" "\n\t\t* Caso 4: Alta dentro y baja fuera."
                            "\n\t\t* Numero de dias: [%d]", LOG05, iNumDias);
            }

            if(iNumDias == 0)
            {
                iNumDias=1;
            }

            vDTrazasLog(szExeName, "\n\t\t* Sumando Total de dias: [%d] + [%d]\n", LOG05, iTotDias, iNumDias);

/*             iTotDias += --iNumDias;  */
            iTotDias += iNumDias;
        }

        iTotDias--;
/*         iTotDias++;  */

        vDTrazasLog(szExeName, "\n\t\t* Total de dias: [%d]\n", LOG05, iTotDias);
        if(iTotDias > stCiclo.iDiaPeriodo)
        {
            iTotDias = stCiclo.iDiaPeriodo;
            vDTrazasLog(szExeName, "\n\t\t* Total de dias Corregidos: [%d]\n", LOG05, iTotDias);
        }

        pstAbo->iNumCBasicos=1;
        vDTrazasLog(szExeName, "\n\t\t* Sobreescribo FecDesde [%s] por [%s]\n", LOG05, pstAbo->pstCBasico[0].szFecDesde, szFecDesde);
        strcpy(pstAbo->pstCBasico[0].szFecDesde, szFecDesde);

        if(!bSumaDias(pstAbo->pstCBasico[0].szFecHasta,szFecDesde,iTotDias))
        {
            vDTrazasLog(szExeName, "\n\t\t* Sobreescribo FecHasta [%s] por [%s]\n", LOG05, pstAbo->pstCBasico[0].szFecHasta , szFecDesde);
            strcpy(pstAbo->pstCBasico[0].szFecHasta, szFecDesde);
        }
        else
        {
            vDTrazasLog(szExeName, "\n\t\t* Sobreescribo FecHasta [%s] por [%s]\n", LOG05, pstAbo->pstCBasico[0].szFecHasta , szFecDesde);
        }

        /* strcpy(pstAbo->pstCBasico[0].szFecDesde, pstAbo->pstCBasico[m].szFecDesde);   */
        vDTrazasLog(szExeName,  "\n\t\t* Fecha Desde Despues: %s"
                    "\n\t\t* Fecha Hasta Despues: %s"
                    "\n\t\t* Numero de Dias     : %d", LOG05,
                    pstAbo->pstCBasico[0].szFecDesde, pstAbo->pstCBasico[0].szFecHasta,
                    iTotDias);
    }
    else
    {
        vDTrazasLog (szExeName, "\n\t\t* Logica especial para Cambio de Plan Inmediato\n", LOG05);
    }

    if (rc == SQLNOTFOUND)
    {
        if (ifnDBCloseIntar (pstAbo->iCodProducto))
            return FALSE;
    }
    return 1;
}/************************** Final bfnCargaCargoBasico ***********************/


/*****************************************************************************/
/*                         funcion : bfnObtImpCargoBasico                    */
/* - En el caso del Abonado 0, el tipo de plan tarifario sera H o E, y sera  */
/*   al abonado 0, al que se le facturara el cargo basico, por lo tanto este */
/*   ira a nivel de Cliente.                                                 */
/*****************************************************************************/
static BOOL bfnObtImpCargoBasico (ABONOS *pstAbo    ,
                                  char   *szFecDesde,
                                  char   *szFecHasta,
                                  int     iBloqueo  ,
                                  int     iTipoFact ,
                                  CICLOCLI *pCicloCli)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long  lhCodCliente       ;
    long  lhNumAbonado       ;
    long  lhCodCiclFact      ;
    long  lhIndActEspec      ;
    int   ihIndActuac_CicloAnt;
    int   iSeis=6;
    int   szCero=0;
    int   iMenosUno=-1;
    static char szDDMMYY[7];/* EXEC SQL VAR szDDMMYY   IS STRING(7) ; */ 

    
    static double   dhImporte_CB;
    static char     szhCodMoneda  [4] ;/* EXEC SQL VAR szhCodMoneda   IS STRING(4) ; */ 

    /* EXEC SQL END DECLARE SECTION; */ 


    BOOL bEnc    = 1;
    int  iIndCar = 0;
    int  i       = 0;

    strcpy(szpFormatoFec,"YYYYMMDDHH24MISS");
    strcpy(szDDMMYY,"DDMMYY");
    
    if (!bfnCargaCargoBasico (pstAbo,szFecDesde,szFecHasta, iBloqueo, iTipoFact))
        return FALSE;

    for(i=0;i<pstAbo->iNumCBasicos; i++)
    {
        if (i > 0 &&
            strcmp(pstAbo->pstCBasico[i-1].szTipPlanTarif, pstAbo->pstCBasico[i].szTipPlanTarif) != 0)
        {
            iDError (szExeName,ERR056,vInsertarIncidencia);
            return  (FALSE)                               ;
        }
        /********************************************************************/
        /*  El Importe del Cargo Basico sera 0, en los siguientes casos:    */
        /*     1. IndCuentaControlada  <> 0 y <> 1                          */
        /*     2. IndBloqueo = DesBloqueo or Bloqueo_Normal                 */
        /*     3. TipPlanTarif = 'H' or 'E' && pstAbo->lNumAbonado > 0      */
        /********************************************************************/

        ihIndActuac_CicloAnt = 0; /* 20040204 CH-200401261638, INICIALIZAMOS VARIABLE */
        /* 20040128 CH-200401261638 Si esta de Baja o Traspasado se busca Indicativo de Actuacion ciclo anterior  */
        if(pstAbo->iIndActuacOld == 2 || pstAbo->iIndActuacOld == 3) /* 20040204 CH-200401261638, Correjimos Condicion */
        {
                lhCodCliente = stCliente.lCodCliente;
                lhNumAbonado = pstAbo->lNumAbonado;
                lhCodCiclFact= stCiclo.lCodCiclFact  ;

                /* EXEC SQL SELECT IND_ACTUAC
                         INTO   :lhIndActEspec
                         FROM   GA_INFACCEL
                         WHERE  COD_CLIENTE = :lhCodCliente
                           AND  NUM_ABONADO = :lhNumAbonado
                           AND  COD_CICLFACT= :lhCodCiclFact
                           AND  IND_ACTUAC  = :iSeis; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 29;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "select IND_ACTUAC into :b0  from GA_INFACCEL \
where (((COD_CLIENTE=:b1 and NUM_ABONADO=:b2) and COD_CICLFACT=:b3) and IND_AC\
TUAC=:b4)";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )671;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&lhIndActEspec;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&lhNumAbonado;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclFact;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&iSeis;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)0;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
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



                if (SQLCODE) {
                    lhIndActEspec = 0;
                   }

                if (lhCodCiclFact <= 99999) { /* 20040204 CH-200401261638, CodCiclFact tiene 5 digitos solamente, se debe anteponer un '0' */
                    /* EXEC SQL
                    SELECT IND_ACTUAC
                        INTO :ihIndActuac_CicloAnt
                        FROM    GA_INFACCEL
                        WHERE   COD_CLIENTE = :lhCodCliente
                        AND     NUM_ABONADO = :lhNumAbonado
                        AND     COD_CICLFACT= to_number(to_char(add_months(to_date(:szCero || to_char(:lhCodCiclFact),:szDDMMYY),:iMenosUno),:szDDMMYY)); */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 29;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.stmt = "select IND_ACTUAC into :b0  from GA_INFAC\
CEL where ((COD_CLIENTE=:b1 and NUM_ABONADO=:b2) and COD_CICLFACT=to_number(to\
_char(add_months(to_date((:b3||to_char(:b4)),:b5),:b6),:b5)))";
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )706;
                    sqlstm.selerr = (unsigned short)1;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)256;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqhstv[0] = (unsigned char  *)&ihIndActuac_CicloAnt;
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
                    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumAbonado;
                    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                    sqlstm.sqhsts[2] = (         int  )0;
                    sqlstm.sqindv[2] = (         short *)0;
                    sqlstm.sqinds[2] = (         int  )0;
                    sqlstm.sqharm[2] = (unsigned long )0;
                    sqlstm.sqadto[2] = (unsigned short )0;
                    sqlstm.sqtdso[2] = (unsigned short )0;
                    sqlstm.sqhstv[3] = (unsigned char  *)&szCero;
                    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[3] = (         int  )0;
                    sqlstm.sqindv[3] = (         short *)0;
                    sqlstm.sqinds[3] = (         int  )0;
                    sqlstm.sqharm[3] = (unsigned long )0;
                    sqlstm.sqadto[3] = (unsigned short )0;
                    sqlstm.sqtdso[3] = (unsigned short )0;
                    sqlstm.sqhstv[4] = (unsigned char  *)&lhCodCiclFact;
                    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
                    sqlstm.sqhsts[4] = (         int  )0;
                    sqlstm.sqindv[4] = (         short *)0;
                    sqlstm.sqinds[4] = (         int  )0;
                    sqlstm.sqharm[4] = (unsigned long )0;
                    sqlstm.sqadto[4] = (unsigned short )0;
                    sqlstm.sqtdso[4] = (unsigned short )0;
                    sqlstm.sqhstv[5] = (unsigned char  *)szDDMMYY;
                    sqlstm.sqhstl[5] = (unsigned long )7;
                    sqlstm.sqhsts[5] = (         int  )0;
                    sqlstm.sqindv[5] = (         short *)0;
                    sqlstm.sqinds[5] = (         int  )0;
                    sqlstm.sqharm[5] = (unsigned long )0;
                    sqlstm.sqadto[5] = (unsigned short )0;
                    sqlstm.sqtdso[5] = (unsigned short )0;
                    sqlstm.sqhstv[6] = (unsigned char  *)&iMenosUno;
                    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[6] = (         int  )0;
                    sqlstm.sqindv[6] = (         short *)0;
                    sqlstm.sqinds[6] = (         int  )0;
                    sqlstm.sqharm[6] = (unsigned long )0;
                    sqlstm.sqadto[6] = (unsigned short )0;
                    sqlstm.sqtdso[6] = (unsigned short )0;
                    sqlstm.sqhstv[7] = (unsigned char  *)szDDMMYY;
                    sqlstm.sqhstl[7] = (unsigned long )7;
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


                   }
                else {
                    /* EXEC SQL
                    SELECT IND_ACTUAC
                        INTO :ihIndActuac_CicloAnt
                        FROM    GA_INFACCEL
                        WHERE   COD_CLIENTE = :lhCodCliente
                        AND     NUM_ABONADO = :lhNumAbonado
                        AND     COD_CICLFACT= to_number(to_char(add_months(to_date(to_char(:lhCodCiclFact),:szDDMMYY),:iMenosUno),:szDDMMYY)); */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 29;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.stmt = "select IND_ACTUAC into :b0  from GA_INFAC\
CEL where ((COD_CLIENTE=:b1 and NUM_ABONADO=:b2) and COD_CICLFACT=to_number(to\
_char(add_months(to_date(to_char(:b3),:b4),:b5),:b4)))";
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )753;
                    sqlstm.selerr = (unsigned short)1;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)256;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqhstv[0] = (unsigned char  *)&ihIndActuac_CicloAnt;
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
                    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumAbonado;
                    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                    sqlstm.sqhsts[2] = (         int  )0;
                    sqlstm.sqindv[2] = (         short *)0;
                    sqlstm.sqinds[2] = (         int  )0;
                    sqlstm.sqharm[2] = (unsigned long )0;
                    sqlstm.sqadto[2] = (unsigned short )0;
                    sqlstm.sqtdso[2] = (unsigned short )0;
                    sqlstm.sqhstv[3] = (unsigned char  *)&lhCodCiclFact;
                    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
                    sqlstm.sqhsts[3] = (         int  )0;
                    sqlstm.sqindv[3] = (         short *)0;
                    sqlstm.sqinds[3] = (         int  )0;
                    sqlstm.sqharm[3] = (unsigned long )0;
                    sqlstm.sqadto[3] = (unsigned short )0;
                    sqlstm.sqtdso[3] = (unsigned short )0;
                    sqlstm.sqhstv[4] = (unsigned char  *)szDDMMYY;
                    sqlstm.sqhstl[4] = (unsigned long )7;
                    sqlstm.sqhsts[4] = (         int  )0;
                    sqlstm.sqindv[4] = (         short *)0;
                    sqlstm.sqinds[4] = (         int  )0;
                    sqlstm.sqharm[4] = (unsigned long )0;
                    sqlstm.sqadto[4] = (unsigned short )0;
                    sqlstm.sqtdso[4] = (unsigned short )0;
                    sqlstm.sqhstv[5] = (unsigned char  *)&iMenosUno;
                    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                    sqlstm.sqhsts[5] = (         int  )0;
                    sqlstm.sqindv[5] = (         short *)0;
                    sqlstm.sqinds[5] = (         int  )0;
                    sqlstm.sqharm[5] = (unsigned long )0;
                    sqlstm.sqadto[5] = (unsigned short )0;
                    sqlstm.sqtdso[5] = (unsigned short )0;
                    sqlstm.sqhstv[6] = (unsigned char  *)szDDMMYY;
                    sqlstm.sqhstl[6] = (unsigned long )7;
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
                {
                    ihIndActuac_CicloAnt=0;
                }

                vDTrazasLog (szExeName,"\t\t* Obtencion de IndActuac Ciclo Anterior"
                                       "\n\t\t=> COD_CLIENTE          [%ld]"
                                       "\n\t\t=> NUM_ABONADO          [%ld]"
                                       "\n\t\t=> COD_CICLFACT         [%ld]"
                                       "\n\t\t=> IND_CUENCONTROLADA   [%d]"
                                       "\n\t\t=> IND_ACTUAC           [%d]"
                                       "\n\t\t=> IND_ACTUAC CICLO ANT [%d]\n"
                                        ,LOG05, lhCodCliente, lhNumAbonado, lhCodCiclFact
                                        ,pstAbo->iIndCuenControlada, pstAbo->iIndActuacOld, ihIndActuac_CicloAnt
                            );
        }

                vDTrazasLog (szExeName,"\t\t* ANTES IF "
                                       "\n\t\t=> pstAbo->pstCBasico[i].szTipPlanTarif [%s]"
                                       "\n\t\t=> pstAbo->lNumAbonado				          [%ld]"
                                       "\n\t\t=> pstAbo->iIndBloqueo         [%d]"
                                       "\n\t\t=> pstAbo->iIndCuenControlada  [%d]"
                                       "\n\t\t=> pstAbo->iIndActuacOld           [%d]"
                                       "\n\t\t=> IihIndActuac_CicloAnt [%d]\n"
                                        ,LOG05, pstAbo->pstCBasico[i].szTipPlanTarif
                                        , pstAbo->lNumAbonado
                                        , pstAbo->iIndBloqueo
                                        , pstAbo->iIndCuenControlada
                                        , pstAbo->iIndActuacOld
                                        , ihIndActuac_CicloAnt );


        if ((!strcmp(pstAbo->pstCBasico[i].szTipPlanTarif,szINDIVIDUAL) || pstAbo->lNumAbonado == 0) &&
             (pstAbo->iIndBloqueo == iBLOQUEO_NORMAL || pstAbo->iIndBloqueo == iDESBLOQUEO) &&
             ((pstAbo->iIndCuenControlada  == 0 || (pstAbo->iIndCuenControlada == 1 && pstAbo->iIndActuacOld != 2 && pstAbo->iIndActuacOld != 3)) ||
             (lhIndActEspec == 6 && ihIndActuac_CicloAnt == 2) ||
             /* 20040128 CH-200401261638 Si esta de Baja o Traspasado compara que Indicativo de Actuacion ciclo anterior sea NORMAL (Se agrega el
                                         caso que prorratee si no tiene ciclo anterior) */
             (pstAbo->iIndCuenControlada == 1 && ((pstAbo->iIndActuacOld == 2 || pstAbo->iIndActuacOld == 3) &&
                                                  (ihIndActuac_CicloAnt == 0  || ihIndActuac_CicloAnt == 1) ) ) ) )
        {
            vDTrazasLog (szExeName, "\n\t\t* Obtencion del Importe del Cargo Basico"
                                    "\n\t\t=> Cod.Producto      [%d]"
                                    "\n\t\t=> Cod.CargoBasico   [%s]"
                                    "\n\t\t=> Fec.Desde Abonado [%s]"
                                    "\n\t\t=> Fec.Hasta Abonado [%s]"
                                    "\n\t\t=> Fec.Desde CF      [%s]"
                                    "\n\t\t=> Fec.Hasta CF      [%s]"
                                    "\n\t\t=> NUM_CARGOSBASICO  [%d]"       ,
                                    LOG05                                   ,
                                    pstAbo->iCodProducto                    ,
                                    pstAbo->pstCBasico[i].szCodCargoBasico  ,
                                    pstAbo->pstCBasico[i].szFecDesde        ,
                                    pstAbo->pstCBasico[i].szFecHasta        ,
                                    szFecDesde                              ,
                                    szFecHasta                              ,
                                    NUM_CARGOSBASICO);

/* 20040128 CH-200401261638 Si esta de Baja o Traspasado se informa en el LOG  */
            bEnc = FALSE;
            if(pstAbo->iIndActuacOld == 2 || pstAbo->iIndActuacOld == 3)
            {
                vDTrazasLog (szExeName,"\n\t\t* Cliente con Plan Total dado de Baja Prorrateado\n", LOG05);
            }

            iIndCar=0;
            bEnc = FALSE;
            if (iTipoFact == FACT_CICLO)
            {
                while (!bEnc && iIndCar < NUM_CARGOSBASICO)
                {
                    if (pstCargosBasico[iIndCar].iCodProducto == pstAbo->iCodProducto   &&
                        strcmp (pstCargosBasico[iIndCar].szCodCargoBasico,
                                pstAbo->pstCBasico [i].szCodCargoBasico)== 0            &&
                      strcmp (pstCargosBasico[iIndCar].szFecDesde, szFecHasta) <= 0 )
                    {
                        bEnc = 1;
                        pstAbo->pstCBasico[i].dImpPeriodo= pstCargosBasico[iIndCar].dImpCargoBasico;
                        vDTrazasLog (szExeName,"\n\t\t=> IndCar [%d]\n", LOG05, iIndCar);


                        if (!bConverMoneda (pstCargosBasico[iIndCar].szCodMoneda,
                                            stDatosGener.szCodMoneFact          ,
                                            stCiclo.szFecEmision                ,
                                            &pstAbo->pstCBasico[i].dImpPeriodo  ,
                                            stProceso.iCodTipDocum))
                            return FALSE;

                        vDTrazasLog (szExeName, "\n\t\t**(MVV)\t1 Importe Cargo Basico [%f]"
                                                "\n\t\t\t       Moneda               [%s]"
                                                "\n\t\t\t       Fecha                [%s]"
                                                "\n\t\t\t       Valor Convertido     [%f]"
                                                ,LOG04
                                                ,pstCargosBasico[iIndCar].dImpCargoBasico
                                                ,pstCargosBasico[iIndCar].szCodMoneda
                                                ,stCiclo.szFecDesdeCFijos
                                                ,pstAbo->pstCBasico[i].dImpPeriodo      );

                    }
                    else
                        iIndCar++;
                }
            }
            else
            {
                /* EXEC SQL
                    SELECT  IMP_CARGOBASICO, COD_MONEDA
                    INTO    :dhImporte_CB ,
                            :szhCodMoneda
                    FROM    TA_CARGOSBASICO
                    WHERE   COD_PRODUCTO   = :pstAbo->iCodProducto
                    AND     COD_CARGOBASICO  = :pstAbo->pstCBasico[i].szCodCargoBasico
                    AND     FEC_DESDE       <= TO_DATE (:szFecHasta,:szpFormatoFec); */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 29;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "select IMP_CARGOBASICO ,COD_MONEDA into :b0,:\
b1  from TA_CARGOSBASICO where ((COD_PRODUCTO=:b2 and COD_CARGOBASICO=:b3) and\
 FEC_DESDE<=TO_DATE(:b4,:b5))";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )796;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&dhImporte_CB;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)szhCodMoneda;
                sqlstm.sqhstl[1] = (unsigned long )4;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&(pstAbo->iCodProducto);
                sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)((pstAbo->pstCBasico)[i].szCodCargoBasico);
                sqlstm.sqhstl[3] = (unsigned long )4;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)szFecHasta;
                sqlstm.sqhstl[4] = (unsigned long )0;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)0;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)szpFormatoFec;
                sqlstm.sqhstl[5] = (unsigned long )17;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)0;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
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
                    iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ta_CargosBasico",szfnORAerror());
                    bEnc = FALSE;
                }
                else
                {
                    pstAbo->pstCBasico[i].dImpPeriodo  = dhImporte_CB;

                    if (!bConverMoneda (szhCodMoneda                        ,
                                        stDatosGener.szCodMoneFact          ,
                                        stCiclo.szFecEmision                ,
                                        &pstAbo->pstCBasico[i].dImpPeriodo  ,
                                        stProceso.iCodTipDocum))
                        return FALSE;

                    vDTrazasLog (szExeName, "\n\t\t**(MVV)\t2 Importe Cargo Basico [%f]"
                                            "\n\t\t\t       Moneda               [%s]"
                                            "\n\t\t\t       Fecha                [%s]"
                                            "\n\t\t\t       Valor Convertido     [%f]"
                                            ,LOG04
                                            ,dhImporte_CB
                                            ,pstCargosBasico[iIndCar].szCodMoneda
                                            ,stCiclo.szFecDesdeCFijos
                                            ,pstAbo->pstCBasico[i].dImpPeriodo      );

                    bEnc = 1;
                }
            }
            if (!bEnc)
            {
                iDError (szExeName,ERR017,vInsertarIncidencia,"Cargo Basico",pstAbo->lNumAbonado);
            }
        }
        else
        {
            pstAbo->pstCBasico[i].dImpPeriodo = 0.0 ;
            bEnc                              = 1;
        }
    }/* fin for ... */
    /*************************************************/
    /* Todos tendran el mismo Tipo de Plan Tarifario */
    /* el mismo Grupo de Servicios, y el mismo Plan  */
    /* comercial.                                    */
    /*************************************************/
    if (pstAbo->iNumCBasicos > 0)
    {
        strcpy (pstAbo->szCodGrpServ  , pstAbo->pstCBasico[0].szCodGrpServ  );
        strcpy (pstAbo->szTipPlanTarif, pstAbo->pstCBasico[0].szTipPlanTarif);

        pstAbo->lCodPlanCom = pstAbo->pstCBasico [0].lCodPlanCom;
    }
    else
    {
        /************************************************************************/
        /*   Fuerza a que el registro de Tipo de Plan Tarifario sea Indivdual   */
        /*   para que considere la rutina de Facturacion de Cargos en           */
        /*   bCargaAbonosCelular.                                               */
        /************************************************************************/
        strcpy (pstAbo->szTipPlanTarif, "I\0");
    }

    if (!bfnTrataCBasico (pstAbo, pCicloCli))
        bEnc = FALSE;

    vDTrazasLog (szExeName,"\n\t\t=> bfnObtImpCargoBasico ==>  %s <== \n", LOG05, (bEnc?"TRUE":"FALSE"));
    return (bEnc);
}/************************** Final bfnObtImpCargoBasico **********************/

/*****************************************************************************/
/*                          funcion : vfnPrintCBasico                        */
/*****************************************************************************/
static void vfnPrintCBasico (void)
{
    int i = 0, j = 0;

    for (j=0;j<stCliente.iNumAbonos;j++)
    {
        vDTrazasLog (szExeName, "\n\t\t* Cargo Basicos del Abonado [%ld]", LOG05,
                                stCliente.pAbonos[j].lNumAbonado);

        for (i=0;i<stCliente.pAbonos [j].iNumCBasicos;i++)
        {
            vDTrazasLog (szExeName,
                         "\n\t\t[%d] - Cod.CBasico     [%d]"
                         "\n\t\t[%d] - Des.CBasico     [%s]"
                         "\n\t\t[%d] - Imp.Periodo     [%f]"
                         "\n\t\t[%d] - Cod.CBasico Fin [%d]"
                         "\n\t\t[%d] - Des.CBasico Fin [%s]"
                         "\n\t\t[%d] - Imp.FinContrato [%f]"
                         "\n\t\t[%d] - Imp.Concepto    [%f]"
                         "\n\t\t[%d] - Num.Dias CBasico[%d]"
                         "\n\t\t[%d] - Num.Dias Fin    [%d]"
                         "\n\t\t[%d] - Tip.PlanTarif   [%s]"
                         "\n\t\t[%d] - Cod.PlanTarif   [%s]"
                         "\n\t\t[%d] - Cod.CargoBasico [%s]", LOG05,
                         i, stCliente.pAbonos[j].pstCBasico [i].iCodAbono      ,
                         i, stCliente.pAbonos[j].pstCBasico [i].szDesAbono     ,
                         i, stCliente.pAbonos[j].pstCBasico [i].dImpPeriodo    ,
                         i, stCliente.pAbonos[j].pstCBasico [i].iCodAbonoFin   ,
                         i, stCliente.pAbonos[j].pstCBasico [i].szDesAbonoFin  ,
                         i, stCliente.pAbonos[j].pstCBasico [i].dImpFinContrato,
                         i, stCliente.pAbonos[j].pstCBasico [i].dImpConcepto   ,
                         i, stCliente.pAbonos[j].pstCBasico [i].iNumDiasAbono  ,
                         i, stCliente.pAbonos[j].pstCBasico [i].iNumDiasFin    ,
                         i, stCliente.pAbonos[j].pstCBasico [i].szTipPlanTarif ,
                         i, stCliente.pAbonos[j].pstCBasico [i].szCodPlanTarif ,
                         i, stCliente.pAbonos[j].pstCBasico [i].szCodCargoBasico);
        }
    }

}/************************** Final vfnPrintCBasico ***************************/

/*****************************************************************************/
/*                          funcion : bfnDBGetMinFree                        */
/*****************************************************************************/
static BOOL bfnDBGetMinFree (int   iCodProducto   ,
                             char *pszCodPlanTarif,
                             long *plNumUnidades,
                             char *pszCod_Unidad)
{
    PLANTARIF  lstPlanTarif;

    vDTrazasLog (szExeName, "\n\t\t* Select (Minutos Libres)=> Ta_PlanTarif"
                            "\n\t\t=> Cod.Producto [%d] "
                            "\n\t\t=> Cod.PlanTarif[%s] "
                            "\n\t\t=> Num.Unidades [%ld]", LOG05,
                            iCodProducto, pszCodPlanTarif, *plNumUnidades);

    if (!bFindPlanTarif (iCodProducto, pszCodPlanTarif, &lstPlanTarif))
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select=> Ta_PlanTarif",
                 szfnORAerror ());
        return (FALSE);
    }

    *plNumUnidades =  lstPlanTarif.lNumUnidades;
    strcpy (pszCod_Unidad, lstPlanTarif.szCod_Unidad);

    return (1);

}/************************** Final bfnDBGetMinFree ***************************/

/*****************************************************************************/
/*                          funcion : dfnDBGetMinConFree                     */
/*****************************************************************************/
static double dfnDBGetMinConFree (long  lCodCliente   ,
                                  long  lNumAbonado   ,
                                  int   iCodProducto  ,
                                  long  lCodCiclFact  ,
                                  long  lCodGrupo     ,
                                  char *szTipPlanTarif,
                                  char *szCodPlanTarif)
{
    
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int   iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 



    static char szCaso [25] = ""   ;
    static BOOL bEnc        = FALSE;

    static double dhSegGratuitos = 0.0;

    vDTrazasLog (szExeName, "\n\t\t* Minutos Consumidos Libres"
                            "\n\t\t=> Cod.Cliente [%ld]"
                            "\n\t\t=> Num.Abonado [%ld]"
                            "\n\t\t=> Cod.Producto[%d] "
                            "\n\t\t=> Cod.CiclFact[%ld]"
                            "\n\t\t=> Cod.Grupo   [%ld]"
                            "\n\t\t=> Tip.PlanTar.[%s] "
                            "\n\t\t=> Cod.PlanTar.[%s] ", LOG05,
                            lCodCliente , lNumAbonado, iCodProducto  ,
                            lCodCiclFact, lCodGrupo  , szTipPlanTarif,
                            szCodPlanTarif);

    if (iCodProducto != stDatosGener.iProdCelular )
    {
        vDTrazasError (szExeName,"\n\t\t=> Cod.Producto [%d] Incorrecto", LOG04,iCodProducto);
        return (double)-1;
    }

    if (!strcmp  (szTipPlanTarif, szINDIVIDUAL))
    {
        bEnc = 1;
/* SAAM-2003011  Se incluye decision para obtencion de minutos libres TOL */
        if (stCiclo.iInd_Tasacion != TIPO_TASA_ON_LINE)
        {
            strcpy (szCaso,"Select=> Ta_AcumAire");

            /* EXEC SQL
                SELECT  NVL(SEG_GRATUITOS,:iCero)
                  INTO  :dhSegGratuitos
                  FROM  TA_ACUMAIRE
                 WHERE  NUM_ABONADO  = :lNumAbonado
                   AND  COD_CICLFACT = :lCodCiclFact
                   AND  COD_PLANTARIF= :szCodPlanTarif
                   AND  COD_CLIENTE  = :lCodCliente; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(SEG_GRATUITOS,:b0) into :b1  from TA_A\
CUMAIRE where (((NUM_ABONADO=:b2 and COD_CICLFACT=:b3) and COD_PLANTARIF=:b4) \
and COD_CLIENTE=:b5)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )835;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&dhSegGratuitos;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lNumAbonado;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lCodCiclFact;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szCodPlanTarif;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&lCodCliente;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
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
            strcpy (szCaso,"Select=> Tol_Acumoper");
/*CH-200505172872 FPH INICIO
            EXEC SQL
                SELECT  NVL(SUM(DUR_DCTO),0)
                  INTO  :dhSegGratuitos
                  FROM  TOL_ACUMOPER_TO
                 WHERE  NUM_ABONADO  = :lNumAbonado
                   AND  COD_CICLFACT = :lCodCiclFact
                   AND  COD_PLAN     = :szCodPlanTarif
                   AND  COD_CLIENTE  = :lCodCliente
                   AND  TIP_DCTO     = 'ML'
                   AND  COD_GRUPO    = 0;
  CH-200505172872 FPH FIN*/
        }
    }
    else if((strcmp(szTipPlanTarif, szEMPRESA) == 0) && (lNumAbonado != 0))
    {
        vDTrazasLog(szExeName,  "\n\t\t*  Cliente Empresa (Abonado distinto de 0): "
                                "\n\t\t=> Cod. Empresa  [%ld]"
                                "\n\t\t=> Cod. CiclFact [%ld]"
                                "\n\t\t=> Cod. PlanTarif [%s]", LOG05,
                                lCodGrupo, lCodCiclFact, szCodPlanTarif);
        bEnc = 1;
        return(0.0);
    }
    else if((strcmp(szTipPlanTarif, szEMPRESA) == 0) && (lNumAbonado == 0))
    {
        vDTrazasLog(szExeName,  "\n\t\t*  Cliente Empresa: "
                                "\n\t\t=> Cod. Empresa  [%ld]"
                                "\n\t\t=> Cod. CiclFact [%ld]"
                                "\n\t\t=> Cod. PlanTarif [%s]", LOG05,
                                lCodGrupo, lCodCiclFact, szCodPlanTarif);
        bEnc = 1;

        if (stCiclo.iInd_Tasacion != TIPO_TASA_ON_LINE)
        {
            strcpy(szCaso,"Select => Ta_AcumAireEmp");

            /* EXEC SQL
                SELECT  NVL(SEG_CONSUMIDO, :iCero)
                  INTO  :dhSegGratuitos
                  FROM  TA_ACUMAIREEMP
                 WHERE  COD_EMPRESA   = :lCodGrupo
                   AND  COD_CICLFACT  = :lCodCiclFact
                   AND  COD_PLANTARIF = :szCodPlanTarif; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select NVL(SEG_CONSUMIDO,:b0) into :b1  from TA_A\
CUMAIREEMP where ((COD_EMPRESA=:b2 and COD_CICLFACT=:b3) and COD_PLANTARIF=:b4\
)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )874;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&iCero;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&dhSegGratuitos;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lCodGrupo;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lCodCiclFact;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szCodPlanTarif;
            sqlstm.sqhstl[4] = (unsigned long )0;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
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
            strcpy (szCaso,"Select=> Tol_Acumoper");

/*CH-200505172872 FPH INICIO
            EXEC SQL
                SELECT  NVL(SUM(NVL(DUR_DCTO,0)),0)
                  INTO  :dhSegGratuitos
                  FROM  TOL_ACUMOPER_TO
                 WHERE  COD_CICLFACT = :lCodCiclFact
                   AND  COD_PLAN     = :szCodPlanTarif
                   AND  TIP_DCTO     = 'ML'
                   AND  COD_GRUPO    = :lCodGrupo;
CH-200505172872 FPH FIN*/
        }

    }
    else if (!strcmp (szTipPlanTarif, szHOLDING))
    {
        bEnc = 1;

        strcpy (szCaso,"Select=> Ta_AcumAireHold");

        /* EXEC SQL
            SELECT /o+ index(TA_ACUMAIREHOLD PK_TA_ACUMAIREHOLD) o/
                    NVL(SEG_CONSUMIDO,:iCero)
              INTO  :dhSegGratuitos
              FROM  TA_ACUMAIREHOLD
             WHERE  COD_HOLDING  = :lCodGrupo
               AND  COD_CICLFACT = :lCodCiclFact
               AND  COD_PLANTARIF= :szCodPlanTarif; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select  /*+  index(TA_ACUMAIREHOLD PK_TA_ACUMAIREHOLD\
)  +*/ NVL(SEG_CONSUMIDO,:b0) into :b1  from TA_ACUMAIREHOLD where ((COD_HOLDI\
NG=:b2 and COD_CICLFACT=:b3) and COD_PLANTARIF=:b4)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )909;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&dhSegGratuitos;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lCodGrupo;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lCodCiclFact;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szCodPlanTarif;
        sqlstm.sqhstl[4] = (unsigned long )0;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
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

    if (!bEnc)
    {
        vDTrazasError (szExeName,"\n\t\t=>Tipo Plan Tarifario[%s] Desconocido",LOG04, szTipPlanTarif);
        return (double)-1;
    }

    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
        iDError (szExeName,ERR000,vInsertarIncidencia,szCaso,szfnORAerror ());

    vDTrazasLog(szExeName, "\n\t\t* Segundos libres consumidos: [%d]  - Minutos: [%f]",
                           LOG05, dhSegGratuitos,(double)dhSegGratuitos/60.00);

    return (SQLCODE == SQLOK)?(double)dhSegGratuitos/60.00:(SQLCODE == SQLNOTFOUND)?0:-1;

}/************************* Final dfnDBGetMinConsumidos **********************/

/*****************************************************************************/
/*                         funcion : bfnTrataCBasico                         */
/*****************************************************************************/
static BOOL bfnTrataCBasico (ABONOS *pstAbo, CICLOCLI *pCicloCli)
{
    int    i           = 0;
    long   lMinFree    = 0; /* Minutos Libres del Plan   */
    double dMinConFree = 0; /* Minutos Libres Consumidos */
    double dTotMinFree = 0; /* Minutos Libres Consumidos */
    int    iIndFecIni  = 0; /* Flag fecha desde */

    PASOPRORRATEO stPasoProrrateo;
    GRUPOCOB      stGrupoCobro;

    memset ( &stPasoProrrateo, 0, sizeof(PASOPRORRATEO));
    memset ( &stGrupoCobro,0,sizeof(GRUPOCOB));

    vDTrazasLog (szExeName, "\n\t\t* Trata Cargo Basico [%d]", LOG05, pstAbo->iNumCBasicos);

    if (pstAbo->iNumCBasicos == 1)    /* Tiene solo 1 CB para el periodo */
    {
        vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]", LOG05, pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
        strcpy(pstAbo->szFecAlta, pstAbo->pstCBasico[0].szFecDesde);
        strcpy(pstAbo->szFecBaja, pstAbo->pstCBasico[0].szFecHasta);

        /* Nuevo codigo  TEMA PRORRATEOS  */

        stGrupoCobro.iCodConcepto = pstAbo->pstCBasico[i].iCodAbono;
        stGrupoCobro.iCodProducto = pstAbo->iCodProducto;
        stGrupoCobro.iCodCiclo    = stCiclo.iCodCiclo;
        strcpy(stGrupoCobro.szCodGrupo,pstAbo->szCodGrpServ);

        if ( !bFindGrupoCob(&stGrupoCobro))
            return FALSE;

        strcpy (stPasoProrrateo.szFecInicio,pstAbo->szFecAlta);
        strcpy (stPasoProrrateo.szFecTermino,pstAbo->szFecBaja);
        stPasoProrrateo.dImpServicio = pstAbo->pstCBasico[i].dImpPeriodo;
        stPasoProrrateo.sIndTipoCobro= stGrupoCobro.iTipCobro;
        stPasoProrrateo.sIndProrrateo= pstAbo->iIndCargoPro;

        stPasoProrrateo.sIndAlta = pstAbo->iIndAlta ;

        vDTrazasLog (szExeName, "\n\t\t* 1 pstCBasico: [%f]"
                                "\n\t\t* Ind Alta [%d]"
                                "\n\t\t* Importe Periodo/Servicio antes de Prorratear [%f]==[%f]"
                                "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]"
                                , LOG05, pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.sIndAlta
                                , pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.dImpServicio
                                , pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);

        if(!bfnProrrateoStandar(&stPasoProrrateo))
            return FALSE;

        pstAbo->pstCBasico[i].iNumDiasAbono = stPasoProrrateo.sDiasAbono;
        pstAbo->pstCBasico[i].dImpConcepto  = stPasoProrrateo.dImpConcepto;

        vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico Prorrateado [%f] para [%d] dias", LOG05,
                                pstAbo->pstCBasico[i].dImpConcepto,pstAbo->pstCBasico[i].iNumDiasAbono);

        /******************* Fin Nuevo Codigo ****************/

        if (!bValidacionAbono (pstAbo->iCodProducto, pstAbo->lNumAbonado , &pstAbo->pstCBasico [i]))
            return FALSE;

        /* P-TMC-04049: se traspasan fechas periodo */
        strcpy (pCicloCli->szFecPeriDesde, stPasoProrrateo.szFecInicio);
        strcpy (pCicloCli->szFecPeriHasta, stPasoProrrateo.szFecTermino);
    }
    else               /* Tiene al menos 1 Cambio de plan con vigencia inmediata */
    {
        for (i=0; i<pstAbo->iNumCBasicos; i++)
        {
            vDTrazasLog (szExeName, "\n\t\t* 2 pstCBasico: [%f]", LOG05, pstAbo->pstCBasico[i].dImpPeriodo);
            strcpy(pstAbo->szFecAlta, pstAbo->pstCBasico[i].szFecDesde);
            strcpy(pstAbo->szFecBaja, pstAbo->pstCBasico[i].szFecHasta);

            /* Nuevo codigo de prueba TEMA PRORRATEOS NCONTRERAS */

            memset ( &stGrupoCobro,0,sizeof(GRUPOCOB));

            stGrupoCobro.iCodConcepto = pstAbo->pstCBasico[i].iCodAbono;
            stGrupoCobro.iCodProducto = pstAbo->iCodProducto;
            stGrupoCobro.iCodCiclo    = stCiclo.iCodCiclo;
            strcpy(stGrupoCobro.szCodGrupo,pstAbo->szCodGrpServ);

            if ( !bFindGrupoCob(&stGrupoCobro))
                return FALSE;

            memset ( &stPasoProrrateo, 0, sizeof(PASOPRORRATEO));

            strcpy (stPasoProrrateo.szFecInicio,pstAbo->szFecAlta);
            strcpy (stPasoProrrateo.szFecTermino,pstAbo->szFecBaja);
            stPasoProrrateo.dImpServicio = pstAbo->pstCBasico[i].dImpPeriodo;
            stPasoProrrateo.sIndTipoCobro= stGrupoCobro.iTipCobro;
            stPasoProrrateo.sIndProrrateo= pstAbo->iIndCargoPro;

            stPasoProrrateo.sIndAlta = pstAbo->iIndAlta ;

            /* P-TMC-04049: se traspasan fechas periodo */
            if (!iIndFecIni)
            {
                strcpy (pCicloCli->szFecPeriDesde, stPasoProrrateo.szFecInicio);
                strcpy (pCicloCli->szFecPeriHasta, stPasoProrrateo.szFecTermino);
            }
            else
            {
                if (stPasoProrrateo.szFecInicio < pCicloCli->szFecPeriDesde )
                    strcpy (pCicloCli->szFecPeriDesde, stPasoProrrateo.szFecInicio);
                if (stPasoProrrateo.szFecTermino < pCicloCli->szFecPeriHasta )
                    strcpy (pCicloCli->szFecPeriHasta, stPasoProrrateo.szFecTermino);
            }

           /******************* Fin Nuevo Codigo ****************/

            if (i == 0)
            {
                /* Nuevo codigo de prueba TEMA PRORRATEOS NCONTRERAS */

                vDTrazasLog (szExeName, "\n\t\t* Importe Periodo/Servicio antes de Prorratear [%f]==[%f]"
                                        "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]"
                                        , LOG05, pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.dImpServicio
                                        , pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
                if(!bfnProrrateoStandar(&stPasoProrrateo))
                return FALSE;

                pstAbo->pstCBasico[i].iNumDiasAbono = stPasoProrrateo.sDiasAbono;
                pstAbo->pstCBasico[i].dImpConcepto  = stPasoProrrateo.dImpConcepto;

                vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico Prorrateado [%f] para [%d] dias", LOG05,
                             pstAbo->pstCBasico[i].dImpConcepto,pstAbo->pstCBasico[i].iNumDiasAbono);

            }
            else
            {
                /*************************************************************/
                /* El Cargo Basico en vigencia, se factura con prorrateo en  */
                /* caso que sea prorrateable, y el resto se factura la parte */
                /* proporcional sobre los minutos libres consumidos.         */
                /* Por la forma que tenemos de recoger el C.Basico el primero*/
                /* sera el de vigencia.                                      */
                /*************************************************************/
                if (!bfnDBGetMinFree (  pstAbo->iCodProducto,
                                        pstAbo->pstCBasico [i].szCodPlanTarif,
                                        &lMinFree,
                                        pstAbo->pstCBasico[i].szCod_Unidad))
                    return FALSE;

                vDTrazasLog(szExeName, "\n\t\t=> Minutos Free [%ld] - Plan Tarif [%s]",
                             LOG05,lMinFree,pstAbo->pstCBasico[i].szCodPlanTarif);
                if (lMinFree == 0)
                {
                    /* TMC-04079: se agrega a la estructura para paso a prefactura */
                    pstAbo->pstCBasico[i].lNumUniFree = lMinFree;
                    /* Nuevo codigo de prueba TEMA PRORRATEOS NCONTRERAS */

                    vDTrazasLog (szExeName, "\n\t\t* Importe Periodo/Servicio antes de Prorratear [%f]==[%f]"
                                            "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]"
                                            , LOG05, pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.dImpServicio
                                            , pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
                    if(!bfnProrrateoStandar(&stPasoProrrateo))
                    return FALSE;

                    pstAbo->pstCBasico[i].iNumDiasAbono = stPasoProrrateo.sDiasAbono;
                    pstAbo->pstCBasico[i].dImpConcepto  = stPasoProrrateo.dImpConcepto;

                    vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico Prorrateado [%f] para [%d] dias", LOG05,
                                 pstAbo->pstCBasico[i].dImpConcepto,pstAbo->pstCBasico[i].iNumDiasAbono);

                }
                else
                {
                    dMinConFree = (double) dfnDBGetMinConFree (stCliente.lCodCliente,
                                        pstAbo->lNumAbonado                         ,
                                        pstAbo->iCodProducto                        ,
                                        stCiclo.lCodCiclFact                        ,
                                        pstAbo->pstCBasico [i].lCodGrupo            ,
                                        pstAbo->pstCBasico [i].szTipPlanTarif       ,
                                        pstAbo->pstCBasico [i].szCodPlanTarif)      ;

                    vDTrazasLog (szExeName, "\n\t\t=> Minutos Free Consumidos [%f]"
                                            "\n\t\t* Importe Cargo Basico [%f]==[%f]"
                                            , LOG05, dMinConFree, pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
                    if (dMinConFree < 0)
                        return FALSE;
                    if (dMinConFree == 0)
                    {
                        vDTrazasLog (szExeName, "\n\t\t* Importe Periodo/Servicio antes de Prorratear [%f]==[%f]"
                                                "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]"
                                                , LOG05, pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.dImpServicio
                                                , pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
                        if(!bfnProrrateoStandar(&stPasoProrrateo))
                        return FALSE;

                        pstAbo->pstCBasico[i].iNumDiasAbono = stPasoProrrateo.sDiasAbono;
                        pstAbo->pstCBasico[i].dImpConcepto  = stPasoProrrateo.dImpConcepto;

                        vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico Prorrateado [%f] para [%d] dias", LOG05,
                                     pstAbo->pstCBasico[i].dImpConcepto,pstAbo->pstCBasico[i].iNumDiasAbono);

                    }
                    else
                    {
                        vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico antes de Prorratear [%f]==[%f]", LOG05, pstAbo->pstCBasico[i].dImpConcepto, stPasoProrrateo.dImpConcepto);
                        dTotMinFree  = pstAbo->pstCBasico [i].dImpPeriodo  * ((double)dMinConFree/lMinFree);
                        vDTrazasLog (szExeName, "\t\t* Valor Periodo antes de calcular Minutos Libres [%f] * ([%f]/[%ld]) = [%f]\n", LOG05, pstAbo->pstCBasico [i].dImpPeriodo,dMinConFree,lMinFree,dTotMinFree);

                        stPasoProrrateo.dImpServicio = pstAbo->pstCBasico[i].dImpPeriodo;
                        vDTrazasLog (szExeName, "\n\t\t* Importe Periodo/Servicio antes de Prorratear [%f]==[%f]"
                                                "\n\t\t* Prorratee [%f] = [%f]  Pero si [%f] < [%f] "
                                                , LOG05, pstAbo->pstCBasico[i].dImpPeriodo, stPasoProrrateo.dImpServicio
                                                , pstAbo->pstCBasico[i].dImpPeriodo,stPasoProrrateo.dImpConcepto
                                                , stPasoProrrateo.dImpConcepto, dTotMinFree);

                        stPasoProrrateo.dImpConcepto=dTotMinFree;

                        pstAbo->pstCBasico[i].iNumDiasAbono = stPasoProrrateo.sDiasAbono;
                        pstAbo->pstCBasico[i].dImpConcepto  = stPasoProrrateo.dImpConcepto;

                        vDTrazasLog (szExeName, "\n\t\t* Importe Cargo Basico Prorrateado = [%f] para [%d] dias", LOG05,
                                     pstAbo->pstCBasico[i].dImpConcepto,pstAbo->pstCBasico[i].iNumDiasAbono);
                    }
                }
            }    /* fin else i == 0            */
            if (!bValidacionAbono (pstAbo->iCodProducto, pstAbo->lNumAbonado , &pstAbo->pstCBasico [i]))
                return FALSE;
        }       /* fin for                    */
    }   /* fin else iNumCBasicos == 1 */
    return 1;
}/************************* Final bfnTrataCBasico ****************************/

/*****************************************************************************/
/*                         funcion : bfnInfServicios                         */
/* - Informacion para la recuperacion de Servicios Suplementarios            */
/*   y Cargos Ocasionales, se recoge sobre la variable global:               */
/*   stCliente.pServAbo                                                      */
/*****************************************************************************/
static BOOL bfnInfServicios (ABONOS *stAbo, CARGOFIJO stCBasico)
{

    if ( (stCliente.pServAbo =
            (SERVABO *)realloc ( (SERVABO *)stCliente.pServAbo,
                (stCliente.iNumServAbo+1)*sizeof(SERVABO) ))==(SERVABO *)NULL)
    {
        iDError (szExeName,ERR005,vInsertarIncidencia,"stCliente.pServAbo");
            return  (FALSE)               ;
    }
    else
    {
        memset (&stCliente.pServAbo[stCliente.iNumServAbo],0,sizeof(SERVABO));

        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szRowid,
                stCBasico.szRowid);

        stCliente.pServAbo[stCliente.iNumServAbo].lNumAbonado =
                                                  stAbo->lNumAbonado    ;
        stCliente.pServAbo[stCliente.iNumServAbo].iCodProducto=
                                                  stAbo->iCodProducto   ;
        stCliente.pServAbo[stCliente.iNumServAbo].lCodPlanCom =
                                                  stCBasico.lCodPlanCom;
        stCliente.pServAbo[stCliente.iNumServAbo].lCapCode    =
                                                  stCBasico.lCapCode   ;

        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szFecDesde,
                stCBasico.szFecDesde)   ;
        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szFecHasta,
                stCBasico.szFecHasta)   ;
        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szCodPlanServ,
                stCBasico.szCodPlanServ);
        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szCodGrpServ,
                stCBasico.szCodGrpServ );
        strcpy (stCliente.pServAbo[stCliente.iNumServAbo].szNumTerminal,
                stCBasico.szNumTerminal);

        stCliente.pServAbo[stCliente.iNumServAbo].iNumServicios=  0           ;
        stCliente.pServAbo[stCliente.iNumServAbo].pServicios=(SERVICIOS *)NULL;
        stCliente.iNumServAbo++;
    }
    return 1;

}/************************* Final bfnInfServicios ****************************/


/****************************************************************************/
/*                           Funcion : ifnClienteFacturable                 */
/****************************************************************************/
static int ifnClienteFacturable ()
{
    int i = 0;

    for (i=0;i<stCliente.iNumAbonos;i++)
    {
        if (stCliente.pAbonos [i].iIndFactur == 1)
            break;
    }
    return (i>=stCliente.iNumAbonados)?0:1;

}/************************** Final ifnClienteFacturable *********************/

static BOOL bfnGetSegCBasico ( long lNumAbonado
                             , char *szCodPlantarif
                             , long lCodCiclFact
                             , long *lSegundosFree)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long lhNumAbonado           ;
        char szhCodPlantarif  [4]   ; /* EXEC SQL VAR szhCodPlantarif IS STRING(4); */ 

        long lhCodCiclFact          ;
        long lhSegundosFree         ;
        int  iCero=0;
    /* EXEC SQL END   DECLARE SECTION; */ 


    lhNumAbonado    =   lNumAbonado   ;
    strcpy (szhCodPlantarif,szCodPlantarif);
    lhCodCiclFact   =   lCodCiclFact  ;

    /* EXEC SQL
        SELECT NVL(SUM(SEG_GRATUITOS + SEG_FFENTRANTES + SEG_PROMCONS), :iCero)
          INTO :lhSegundosFree
          FROM TA_ACUMAIRE
         WHERE NUM_ABONADO  = :lhNumAbonado
           AND COD_PLANTARIF= :szhCodPlantarif
           AND COD_CICLFACT = :lhCodCiclFact; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(sum(((SEG_GRATUITOS+SEG_FFENTRANTES)+SEG_PROMC\
ONS)),:b0) into :b1  from TA_ACUMAIRE where ((NUM_ABONADO=:b2 and COD_PLANTARI\
F=:b3) and COD_CICLFACT=:b4)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )944;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&iCero;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhSegundosFree;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhCodPlantarif;
    sqlstm.sqhstl[3] = (unsigned long )4;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&lhCodCiclFact;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
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



    if(sqlca.sqlcode < SQLOK)
    {
        return (FALSE);
    }

    *lSegundosFree=lhSegundosFree;
    return (1);

}

/****************************************************************************************/
/*                        funcion : bfnProrrateoStandar                                 */
/* -Funcion generica  que realiza el prorrateo de cargos recurrentes                    */
/* - Recibe como entrada los siguientes estructura de parametros :                      */
/*  Fec Inicio : Fecha de Inicio del servicio YYYYMMDD                                  */
/*  Fec Termino: Fecha de Termino del servicio YYYYMMDD                                 */
/*  Importe Servicio : Importe del servicio para un periodo compleo                     */
/*  Tipo de cobro    : VENCIDO o ANTICIPADO                                             */
/*  Indicador de Alta: Indicador de alta del servicio                                   */
/*  Indicador de Prorrateo : Indicador si el servicio es prorrateable 1:SI 0:NO         */
/*  Importe Concepto : Importe prorrateado. Resultado del calculo                       */
/*  Dias Prorrateo   : Numero dias en q se prorrateo el importe                         */
/*                                                                                      */
/* Si todo OK retorna TRUE , en caso contrario retorna FALSE                            */
/****************************************************************************************/
/* Modificación: Ya no pregunta si es anticipado o vencido, es más generico que el ant. */
/* se respalda proceso real como preser_real.pc                                         */
/* Fabian aEdo Ramírez Agosto 28, del 2002.                                             */
/****************************************************************************************/
static BOOL bfnProrrateoStandar(PASOPRORRATEO *pCargo)
{
    int iDiasAlta ;
    iDiasAlta = stCiclo.iDiaPeriodo;

    vDTrazasLog(szExeName,  "\n\t\t* bfnProrrateoStandar\n"
                            "\t\t=> Fec Inicio      : [%s]\n"
                            "\t\t=> Fec Termino     : [%s]\n"
                            "\t\t=> Importe Servicio: [%f]\n"
                            "\t\t=> Tipo de cobro   : [%d]\n"
                            "\t\t=> Ind Alta        : [%d]\n"
                            "\t\t=> Dias Alta       : [%d]\n",LOG05,
                            pCargo->szFecInicio,
                            pCargo->szFecTermino,
                            pCargo->dImpServicio,
                            pCargo->sIndTipoCobro,
                            pCargo->sIndAlta,
                            iDiasAlta);

    if(alltrim(pCargo->szFecInicio)==NULL)
    {
        vDTrazasLog(szExeName, "\n\t\t=> Fecha Inicio Nula, dias alta por omision dias periodo [%d]",LOG05, iDiasAlta);
    }
    alltrim(pCargo->szFecTermino);

    if( pCargo->sIndProrrateo ) /* Si servicio es prorrateable */
    {
        /* CASO 4 :Alta anterior al inicio del ciclo y baja posterior al termino del ciclo */
        if( strcmp(pCargo->szFecInicio, stCiclo.szFecDesdeCFijos ) <=0 &&
        ( strcmp(pCargo->szFecTermino,stCiclo.szFecHastaCFijos ) > 0 ||
        strcmp(pCargo->szFecTermino,"" ) == 0 ) )
        {
            /* Primera vez que se factura... va hacia atras... */
            if( pCargo->sIndAlta == 1 )
            {
                vDTrazasLog(szExeName, "\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 4"
                                        "\n\t\t=> stCiclo.szFecHastaCFijos : [%s]"
                                        "\n\t\t=> pCargo->szFecInicio : [%s]",LOG05,
                                        stCiclo.szFecHastaCFijos,
                                        pCargo->szFecInicio);
                if( pCargo->szFecInicio[0]==0 )
                    iDiasAlta = stCiclo.iDiaPeriodo;
                else if( !bRestaFechas ( stCiclo.szFecHastaCFijos,pCargo->szFecInicio,&iDiasAlta) )
                {
                    vDTrazasError (szExeName, "\n\t\t=> Problema en bRestaFechas CASO 4"
                    "\n\t\t=> Fecha 1 : [%s]"
                    "\n\t\t=> Fecha 2 : [%s]",LOG02,
                    stCiclo.szFecHastaCFijos,
                    pCargo->szFecInicio);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                     return FALSE;  */
/*             }    */
/*             else */
/*             {    */
                    iDiasAlta = stCiclo.iDiaPeriodo;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
                }
            }
/* 20050124 CH-200501182613 Se controla exceso de cobro por diferencia de dias  */
            if(iDiasAlta > stCiclo.iDiaPeriodo)
            {
                iDiasAlta = stCiclo.iDiaPeriodo;
            }
            if( iDiasAlta == 0 ) iDiasAlta = 1;

            pCargo->dImpConcepto = fnCnvDouble((pCargo->dImpServicio * (iDiasAlta/stCiclo.iDiaPeriodo)), USOFACT);
            
            
            pCargo->sDiasAbono   = iDiasAlta;
            vDTrazasLog(szExeName,  "\n\t\t Dias Alta = %d  Calculo : (%f) * %d / %d = (%f) \n", LOG05, iDiasAlta, pCargo->dImpServicio, iDiasAlta,stCiclo.iDiaPeriodo,pCargo->dImpConcepto);

            vDTrazasLog(szExeName,  "\n\t\t CASO 4 :(A anterior y B posterior)\n"
            "\t\t=> Ind Prorrateo   : [%d]\n"
            "\t\t=> Dias Abono      : [%d]\n"
            "\t\t=> Importe Concepto: [%f]\n",LOG05,
            pCargo->sIndProrrateo,
            pCargo->sDiasAbono,
            pCargo->dImpConcepto);
        }
        /* CASO 1 :Alta y Baja dentro del ciclo en proceso */
        else if( strcmp(pCargo->szFecInicio,stCiclo.szFecDesdeCFijos)  >  0 &&
        strcmp(pCargo->szFecTermino,stCiclo.szFecHastaCFijos) <= 0 &&
        strcmp(pCargo->szFecTermino,"" ) != 0 )
        {
            vDTrazasLog(szExeName,"\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 1"
            "\n\t\t=> pCargo->szFecTermino : [%s]"
            "\n\t\t=> pCargo->szFecInicio  : [%s]",LOG05,
            pCargo->szFecTermino,
            pCargo->szFecInicio );
            if( pCargo->szFecInicio[0]==0 )
                iDiasAlta = stCiclo.iDiaPeriodo;
            else if( !bRestaFechas ( pCargo->szFecTermino,pCargo->szFecInicio,&iDiasAlta) )
            {
                vDTrazasError (szExeName,"\n\t\t=> Problema en bRestaFechas CASO 1"
                "\n\t\t=> Fecha 1 : [%s]"
                "\n\t\t=> Fecha 2 : [%s]",LOG02,
                pCargo->szFecTermino,
                pCargo->szFecInicio);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                 return FALSE;  */
                iDiasAlta = stCiclo.iDiaPeriodo;
            }
            else
            {
                vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
            }

/* 20050124 CH-200501182613 Se controla exceso de cobro por diferencia de dias  */
            if(iDiasAlta > stCiclo.iDiaPeriodo)
            {
                iDiasAlta = stCiclo.iDiaPeriodo;
            }
            if( iDiasAlta == 0 ) iDiasAlta = 1;

            pCargo->dImpConcepto = fnCnvDouble((pCargo->dImpServicio * iDiasAlta/stCiclo.iDiaPeriodo), USOFACT);
            pCargo->sDiasAbono   = iDiasAlta;
            vDTrazasLog(szExeName,  "\n\t\t Dias Alta = %d  Calculo : (%f) * %d / %d = %f \n"
                                    "\n\t\t CASO 1 :(A y B dentro del Periodo)\n"
                                    "\t\t=> Ind Prorrateo   : [%d]\n"
                                    "\t\t=> Dias Abono      : [%d]\n"
                                    "\t\t=> Importe Concepto: [%f]\n",LOG05
                                    , iDiasAlta, pCargo->dImpServicio, iDiasAlta,stCiclo.iDiaPeriodo,pCargo->dImpConcepto,
                                    pCargo->sIndProrrateo,
                                    pCargo->sDiasAbono,
                                    pCargo->dImpConcepto);
        }
        /* CASO 2 :Alta dentro del ciclo y baja posterior */
        else if( strcmp(pCargo->szFecInicio, stCiclo.szFecDesdeCFijos) > 0 &&
        strcmp(pCargo->szFecInicio, stCiclo.szFecHastaCFijos) <=0 &&
        (strcmp(pCargo->szFecTermino,stCiclo.szFecHastaCFijos) > 0 ||
        strcmp(pCargo->szFecTermino,"" ) == 0 ) )
        {

            vDTrazasLog(szExeName,  "\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 2"
                                    "\n\t\t=> stCiclo.szFecHastaCFijos : [%s]"
                                    "\n\t\t=> pCargo->szFecInicio : [%s]",LOG05,
                                    stCiclo.szFecHastaCFijos,
                                    pCargo->szFecInicio);
            if( pCargo->szFecInicio[0]==0 )
                iDiasAlta = stCiclo.iDiaPeriodo;
            else if( !bRestaFechas ( stCiclo.szFecHastaCFijos,pCargo->szFecInicio,&iDiasAlta) )
            {
                vDTrazasError (szExeName,   "\n\t\t=> Problema en bRestaFechas CASO 2"
                "\n\t\t=> Fecha 1 : [%s]"
                "\n\t\t=> Fecha 2 : [%s]",LOG02,
                stCiclo.szFecHastaCFijos,
                pCargo->szFecInicio);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                 return FALSE;  */
                iDiasAlta = stCiclo.iDiaPeriodo;
            }
            else
            {
                vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
            }

/* 20050124 CH-200501182613 Se controla exceso de cobro por diferencia de dias  */
            if(iDiasAlta > stCiclo.iDiaPeriodo)
            {
                iDiasAlta = stCiclo.iDiaPeriodo;
            }

            if( iDiasAlta == 0 ) iDiasAlta = 1;

            pCargo->dImpConcepto = fnCnvDouble((pCargo->dImpServicio * iDiasAlta/stCiclo.iDiaPeriodo), USOFACT);
            pCargo->sDiasAbono   = iDiasAlta;
            vDTrazasLog(szExeName,  "\n\t\t Dias Alta = %d  Calculo : (%f) * %d / %d = %f \n"
                                    "\n\t\t CASO 2 :(A dentro y B posterior)\n"
                                    "\t\t=> Ind Prorrateo   : [%d]\n"
                                    "\t\t=> Dias Abono      : [%d]\n"
                                    "\t\t=> Importe Concepto: [%f]\n",LOG05
                                    , iDiasAlta, pCargo->dImpServicio, iDiasAlta,stCiclo.iDiaPeriodo,pCargo->dImpConcepto,
                                    pCargo->sIndProrrateo,
                                    pCargo->sDiasAbono,
                                    pCargo->dImpConcepto);

        }
        /* CASO 3 :Alta anterior al inicio de ciclo y baja dentro de ciclo */
        else if( strcmp(pCargo->szFecInicio,stCiclo.szFecDesdeCFijos) <= 0 &&
        strcmp(pCargo->szFecTermino,stCiclo.szFecDesdeCFijos) >= 0 &&
        strcmp(pCargo->szFecTermino,stCiclo.szFecHastaCFijos) <= 0 &&
        strcmp(pCargo->szFecTermino,"" ) != 0 )
        {
            /* Primera vez que se factura... va hacia atras... */
            if( pCargo->sIndAlta == 1 )
            {
                vDTrazasLog(szExeName,  "\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 3.1"
                                        "\n\t\t=> pCargo->szFecTermino : [%s]"
                                        "\n\t\t=> pCargo->szFecInicio : [%s]",LOG05,
                                        pCargo->szFecTermino,
                                        pCargo->szFecInicio);
                if( pCargo->szFecInicio[0]==0 )
                    iDiasAlta = stCiclo.iDiaPeriodo;
                else if( !bRestaFechas ( pCargo->szFecTermino,pCargo->szFecInicio,&iDiasAlta) )
                {
                    vDTrazasError (szExeName,   "\n\t\t=> Problemas en bRestaFechas CASO 3.1"
                                                "\n\t\t=> Fecha 1 : [%s]"
                                                "\n\t\t=> Fecha 2 : [%s]",LOG02,
                                                pCargo->szFecTermino,
                                                pCargo->szFecInicio);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                     return FALSE;  */
                    iDiasAlta = stCiclo.iDiaPeriodo;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
                }
            }
            else
            {
                vDTrazasLog(szExeName,  "\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 3.2"
                                        "\n\t\t=> pCargo->szFecTermino     : [%s]"
                                        "\n\t\t=> stCiclo.szFecDesdeCFijos : [%s]",LOG05,
                                        pCargo->szFecTermino,
                                        stCiclo.szFecDesdeCFijos);
                if( !bRestaFechas ( pCargo->szFecTermino,stCiclo.szFecDesdeCFijos,&iDiasAlta) )
                {
                    vDTrazasError (szExeName,   "\n\t\t=> Error bRestaFechas CASO 3.2"
                                                "\n\t\t=> Fecha 1 : [%s]"
                                                "\n\t\t=> Fecha 2 : [%s]",LOG02,
                                                pCargo->szFecTermino,
                                                stCiclo.szFecDesdeCFijos);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                          return FALSE;  */
                    iDiasAlta = stCiclo.iDiaPeriodo;
                }
                else
                {
                    vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
                }
            }
/* 20050124 CH-200501182613 Se controla exceso de cobro por diferencia de dias  */
            if(iDiasAlta > stCiclo.iDiaPeriodo)
            {
                iDiasAlta = stCiclo.iDiaPeriodo;
            }

            if( iDiasAlta == 0 ) iDiasAlta = 1;


            pCargo->dImpConcepto = fnCnvDouble((pCargo->dImpServicio * iDiasAlta/stCiclo.iDiaPeriodo), USOFACT);
            pCargo->sDiasAbono   = iDiasAlta;
            vDTrazasLog(szExeName,  "\n\t\t Dias Alta = %d  Calculo : (%f) * %d / %d = %f \n"
                                    "\n\t\t CASO 3 :(A anterior y B dentro del ciclo)\n"
                                    "\t\t=> Ind Prorrateo   : [%d]\n"
                                    "\t\t=> Dias Abono      : [%d]\n"
                                    "\t\t=> Importe Concepto: [%f]\n",LOG05
                                    , iDiasAlta, pCargo->dImpServicio, iDiasAlta,stCiclo.iDiaPeriodo,pCargo->dImpConcepto,
                                    pCargo->sIndProrrateo,
                                    pCargo->sDiasAbono,
                                    pCargo->dImpConcepto);

        }
        /* CASO 5 :Alta y Baja anterior al ciclo en proceso */
        else if( strcmp(pCargo->szFecInicio,stCiclo.szFecDesdeCFijos)  < 0 &&
        strcmp(pCargo->szFecTermino,stCiclo.szFecDesdeCFijos) < 0 &&
        strcmp(pCargo->szFecTermino,"" ) != 0 )
        {
            vDTrazasLog(szExeName,  "\n\t\t=> bfnProrrateoStandar bRestaFechas CASO 5"
                                    "\n\t\t=> pCargo->szFecTermino : [%s]"
                                    "\n\t\t=> pCargo->szFecInicio  : [%s]",LOG05,
                                    pCargo->szFecTermino,
                                    pCargo->szFecInicio);
            if( pCargo->szFecInicio[0]==0 )
                iDiasAlta = stCiclo.iDiaPeriodo;
            else if( !bRestaFechas ( pCargo->szFecTermino,pCargo->szFecInicio,&iDiasAlta) )
            {
                vDTrazasError (szExeName,   "\n\t\t=> Error bRestaFechas CASO 5"
                                            "\n\t\t=> Fecha 1 : [%s]"
                                            "\n\t\t=> Fecha 2 : [%s]",LOG02,
                                            pCargo->szFecTermino,
                                            pCargo->szFecInicio);
/* 20040722 XP-200407210113 Se modifica para que continue el prorrateo con la cantidad de dias del ciclo */
/*                 return FALSE;  */
                iDiasAlta = stCiclo.iDiaPeriodo;
            }
            else
            {
                vDTrazasLog(szExeName, "\n\t\t=> Dias Alta calculado [%d]",LOG05, iDiasAlta);
            }

            vDTrazasLog(szExeName, "\n\t\t=> pCargo->sIndAlta[%d]",LOG05, pCargo->sIndAlta);

            if( pCargo->sIndAlta == 1 )
            {
/* 20050124 CH-200501182613 Se controla exceso de cobro por diferencia de dias  */
                if(iDiasAlta > stCiclo.iDiaPeriodo)
                {
                    iDiasAlta = stCiclo.iDiaPeriodo;
                }
                if( iDiasAlta == 0 ) iDiasAlta = 1;

                pCargo->dImpConcepto = fnCnvDouble((pCargo->dImpServicio * iDiasAlta/stCiclo.iDiaPeriodo), USOFACT);
                pCargo->sDiasAbono   = iDiasAlta;
                vDTrazasLog(szExeName,  "\n\t\t Dias Alta = %d  Calculo : (%f) * %d / %d = %f \n"
                                        "\n\t\t CASO 5 :(A y B anterior al Periodo)\n"
                                        "\t\t=> Ind Prorrateo   : [%d]\n"
                                        "\t\t=> Dias Abono      : [%d]\n"
                                        "\t\t=> Importe Concepto: [%f]\n",LOG05
                                        , iDiasAlta, pCargo->dImpServicio, iDiasAlta,stCiclo.iDiaPeriodo,pCargo->dImpConcepto,
                                        pCargo->sIndProrrateo,
                                        pCargo->sDiasAbono,
                                        pCargo->dImpConcepto);
            }
            else
            {
                vDTrazasLog(szExeName,  "\n\t\t CASO 5 :(A y B anterior al Periodo) Cargo Basico Facturado Previamente (No se Prorraeta)...\n"
                                        "\t\t=> Ind Prorrateo   : [%d]\n"
                                        "\t\t=> Dias Abono      : [%d]\n"
                                        "\t\t=> Importe Concepto: [%f]\n",LOG05,
                                        pCargo->sIndProrrateo,
                                        pCargo->sDiasAbono,
                                        pCargo->dImpConcepto);
            }
        }
        /* CASO 6 :Alta y Baja posterior al ciclo en proceso */
        else if( strcmp(pCargo->szFecInicio,stCiclo.szFecHastaCFijos)  > 0 &&
        (strcmp(pCargo->szFecTermino,stCiclo.szFecHastaCFijos) > 0 ||
        strcmp(pCargo->szFecTermino,"" ) == 0 ) )
        {
            vDTrazasLog(szExeName,  "\n\t\t CASO 6 : A y B  posterior -->Error\n"
                                    "\t\t=> Fecha Alta   : [%s]\n"
                                    "\t\t=> Fecha Baja   : [%s]\n",LOG02,
                                    pCargo->szFecInicio,
                                    pCargo->szFecTermino);

            vDTrazasError(szExeName,"\n\t\t=> Error Prorrateo (A y B posterior) CASO 6"
                                    "\n\t\t=> Fecha Alta : [%s]"
                                    "\n\t\t=> Fecha Baja : [%s]",LOG05,
                                    pCargo->szFecInicio,
                                    pCargo->szFecTermino);

            /* iDError (szExeName,ERR060,vInsertarIncidencia); */
            /* return FALSE; */
            pCargo->dImpConcepto = 0.0;
            pCargo->sDiasAbono   = 0;
        }

    }
    else
    { /* Servicio no es prorrateable */

        vDTrazasLog(szExeName,  "\n\t\t Servicio NO prorrateable \n"
        "\t\t Importe Concepto : [%f]\n",LOG05,
        pCargo->dImpServicio);

        pCargo->dImpConcepto = fnCnvDouble(pCargo->dImpServicio, USOFACT);
        pCargo->sDiasAbono   = stCiclo.iDiaPeriodo;
    }

    return(1);
}
/**************************** Fin bfnProrrateoStandar ***************************************/



/****************************************************************************************/
/*                        funcion : BfnObtieneValorCrit_PlanTarif           */
/* Funcion que verifica si servicio cumple con criterios                */
/* Si todo OK retorna TRUE , en caso contrario FALSE                    */
/* Desarrollado por Nelson Contreras Helena                     */
/****************************************************************************************/
BOOL BfnObtieneValorCrit_PlanTarif(char* szCodServicio, int iCodProducto ,
                                   char* szTipCuenta, long lNumAbonado)
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

static char   szhCodServicio  [3] ;/* EXEC SQL VAR szhCodServicio   IS STRING(3) ; */ 

static int    iIndCriterio = 0    ;
static int    iIndAbonadoCero=0   ;
static int    iAuxCriterio;
static char   szAuxValCriterio[3] ;/* EXEC SQL VAR szAuxValCriterio IS STRING(3) ; */ 

static int    iAuxCodProducto;

/* EXEC SQL END DECLARE SECTION; */ 



    strcpy(szhCodServicio,szCodServicio);
    iAuxCodProducto = iCodProducto;
    iAuxCriterio    = CRIT_PLANTARIF;

    /* EXEC SQL
    SELECT IND_CRITERIO,
           IND_ABONADO0
    INTO   :iIndCriterio,
           :iIndAbonadoCero
    FROM FA_PARAMSERV
    WHERE COD_SERVICIO = :szhCodServicio AND
          COD_PRODUCTO = :iAuxCodProducto; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 29;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select IND_CRITERIO ,IND_ABONADO0 into :b0,:b1  from FA_P\
ARAMSERV where (COD_SERVICIO=:b2 and COD_PRODUCTO=:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )979;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&iIndCriterio;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&iIndAbonadoCero;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhCodServicio;
    sqlstm.sqhstl[2] = (unsigned long )3;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iAuxCodProducto;
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



    vDTrazasLog(szExeName,  "\n\t\t Select en FA_PARAMSERV \n"
                            "\t\t=> CodServicio     : [%s]\n"
                            "\t\t=> CodProducto     : [%d]\n"
                            "\t\t=> Tip Cuenta      : [%s]\n"
                            "\t\t=> Ind Criterio    : [%d]\n"
                            "\t\t=> Ind Abonado Cero: [%d]\n"
                            "\t\t=> SQLCODE      : [%d]\n",LOG05,
                            szCodServicio,
                            iCodProducto,
                            szTipCuenta,
                            iIndCriterio,
                            iIndAbonadoCero,
                            SQLCODE);


    if(SQLCODE == SQLOK || SQLCODE == SQLNOTFOUND)
    {

        if ( iIndCriterio == 0 || SQLCODE == SQLNOTFOUND )
                    return 1;

        if ( iIndAbonadoCero == 0 && lNumAbonado == 0 )
                    return FALSE;


        /* EXEC SQL DECLARE Cursor_Criterios CURSOR FOR
        SELECT COD_CRITERIO,
               VAL_CRITERIO
        FROM FA_CRITSERV
        WHERE COD_SERVICIO = :szhCodServicio  AND
              COD_PRODUCTO = :iAuxCodProducto AND
              COD_CRITERIO = :iAuxCriterio ; */ 


        if ( SQLCODE != SQLOK )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Declare Cursor_Criterios->", szfnORAerror());
            return FALSE;
        }

        /* EXEC SQL OPEN Cursor_Criterios ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0018;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1010;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhCodServicio;
        sqlstm.sqhstl[0] = (unsigned long )3;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&iAuxCodProducto;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&iAuxCriterio;
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



        if ( SQLCODE != SQLOK )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Open Cursor_Criterios->", szfnORAerror());
            return FALSE;
        }


        /* EXEC SQL FETCH Cursor_Criterios INTO
             :iAuxCriterio,
             :szAuxValCriterio; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1037;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&iAuxCriterio;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szAuxValCriterio;
        sqlstm.sqhstl[1] = (unsigned long )3;
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



        if ( SQLCODE == SQLNOTFOUND )    return  1;

        while ( SQLCODE == SQLOK  )
        {
            if ( !strcmp(szAuxValCriterio,szTipCuenta) )
                return 1;

            /* EXEC SQL FETCH Cursor_Criterios INTO
             :iAuxCriterio,
             :szAuxValCriterio; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 29;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1060;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&iAuxCriterio;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szAuxValCriterio;
            sqlstm.sqhstl[1] = (unsigned long )3;
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



             if ( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
             {
                  iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch Cursor_Criterios->", szfnORAerror());
                  return FALSE;
             }
        }

        /* EXEC SQL CLOSE Cursor_Criterios; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1083;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if ( SQLCODE != SQLOK )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close Cursor_Criterios->", szfnORAerror());
            return FALSE;
        }

        return FALSE;
    }
    else
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select fa_paramserv->", szfnORAerror());
        return FALSE;
    }

}/************************* Fin bfnObtieneValorCriterios *********************************/


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

