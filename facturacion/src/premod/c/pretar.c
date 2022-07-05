
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
    "./pc/pretar.pc"
};


static unsigned int sqlctx = 866043;


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
   unsigned char  *sqhstv[19];
   unsigned long  sqhstl[19];
            int   sqhsts[19];
            short *sqindv[19];
            int   sqinds[19];
   unsigned long  sqharm[19];
   unsigned long  *sqharc[19];
   unsigned short  sqadto[19];
   unsigned short  sqtdso[19];
} sqlstm = {12,19};

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

 static const char *sq0001 = 
"select ROWID ,COD_PERIODO ,IMP_CONSUMIDO  from FA_ACUMFORADI where ((((((NUM\
_ABONADO=:b0 and IND_ALQUILER=:b1) and COD_PERIODO>:b2) and COD_OPERADOR=:b3) \
and COD_TIPCONCE=:b4) and COD_CLIENTE=:b5) and NUM_PROCESO=:b2)           ";

 static const char *sq0003 = 
"select ROWID ,COD_PERIODO ,IMP_CONSUMIDO ,SEG_CONSUMIDO  from FA_ACUMFORTAS \
where ((((((NUM_ABONADO=:b0 and IND_ALQUILER=:b1) and COD_PERIODO>:b2) and COD\
_OPERADOR=:b3) and COD_TIPCONCE=:b4) and COD_CLIENTE=:b5) and NUM_PROCESO=:b2)\
           ";

 static const char *sq0005 = 
"select  /*+  index (TA_ACUMOPERALQ PK_TA_ACUMOPERALQ)  +*/ IMP_CONSUMIDO ,SE\
G_CONSUMIDO ,NUM_PULSOS  from TA_ACUMOPERALQ where ((((NUM_ABONADO=:b0 and NUM\
_ALQUILER=:b1) and COD_OPERADOR=:b2) and COD_CLIENTE=:b3) and NUM_PROCESO=:b4)\
           ";

 static const char *sq0006 = 
"select  /*+  index (TA_ACUMAIREFRASOCALQ PK_TA_ACUMAIREFRASOCALQ)  +*/ IMP_C\
ONSUMIDO ,SEG_CONSUMIDO  from TA_ACUMAIREFRASOCALQ where (((((NUM_ABONADO=:b0 \
and NUM_ALQUILER=:b1) and COD_FRANHORASOC=:b2) and IND_ENTSAL=:b3) and COD_CLI\
ENTE=:b4) and NUM_PROCESO=:b5)           ";

 static const char *sq0008 = 
"select IMP_CONSUMIDO ,SEG_CONSUMIDO ,IND_ENTSAL ,IND_DESTINO ,COD_FRANHORASO\
C ,A.COD_SERVICIO ,B.COD_PLANTARIF ,A.COD_OPERADOR  from TA_ACUMAIREFRASOC A ,\
GAD_SERVSUP_PLAN B where (((((NUM_ABONADO=:b0 and COD_CLIENTE=:b1) and NUM_PRO\
CESO=:b2) and B.COD_PRODUCTO(+)=:b3) and B.COD_SERVICIO(+)=A.COD_SERVICIO) and\
 B.TIP_RELACION(+)=:b4)           ";

 static const char *sq0007 = 
"select A.rowid  ,COD_CICLFACT ,IMP_CONSUMIDO ,SEG_CONSUMIDO ,IND_ENTSAL ,IND\
_DESTINO ,COD_FRANHORASOC ,A.COD_SERVICIO ,B.COD_PLANTARIF ,A.COD_OPERADOR  fr\
om TA_ACUMAIREFRASOC A ,GAD_SERVSUP_PLAN B where ((((((NUM_ABONADO=:b0 and COD\
_CICLFACT>:b1) and COD_CLIENTE=:b2) and NUM_PROCESO=:b1) and B.COD_PRODUCTO(+)\
=:b4) and B.COD_SERVICIO(+)=A.COD_SERVICIO) and B.TIP_RELACION(+)=:b5)        \
   ";

 static const char *sq0010 = 
"select  /*+  index (TA_ACUMOPER PK_TA_ACUMOPER)  +*/ IMP_CONSUMIDO ,SEG_CONS\
UMIDO ,NUM_PULSOS ,COD_OPERADOR ,trim(COD_PLANTARIF)  from TA_ACUMOPER where (\
(NUM_ABONADO=:b0 and COD_CLIENTE=:b1) and NUM_PROCESO=:b2)           ";

 static const char *sq0011 = 
"select  /*+  index (TA_ACUMOPER PK_TA_ACUMOPER)  +*/ ROWID ,COD_CICLFACT ,IM\
P_CONSUMIDO ,DECODE(SEG_ADICIONALES,0,SEG_CONSUMIDO,SEG_ADICIONALES) SEG_CONSU\
MIDO ,NUM_PULSOS ,COD_OPERADOR ,trim(COD_PLANTARIF)  from TA_ACUMOPER where ((\
(NUM_ABONADO=:b0 and COD_CICLFACT>:b1) and COD_CLIENTE=:b2) and NUM_PROCESO=:b\
1)           ";

 static const char *sq0014 = 
"select  /*+  index (TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA)  +*/ IMP_CONSU\
MIDO ,SEG_CONSUMIDO ,COD_OPERADOR  from TA_ACUMLLAMADASROA where ((NUM_ABONADO\
=:b0 and COD_CLIENTE=:b1) and NUM_PROCESO=:b2)           ";

 static const char *sq0013 = 
"select ROWID ,COD_CICLFACT ,IMP_CONSUMIDO ,SEG_CONSUMIDO ,COD_OPERADOR  from\
 TA_ACUMLLAMADASROA where (((NUM_ABONADO=:b0 and COD_CICLFACT>:b1) and COD_CLI\
ENTE=:b2) and NUM_PROCESO=:b1)           ";

 static const char *sq0016 = 
"select  /*+  index (TA_ACUMROAMING PK_TA_ACUMROAMING)  +*/ IMP_CONSAIRE ,IMP\
_CONSOPER ,SEG_CONSAIRE ,SEG_CONSOPER  from TA_ACUMROAMING where ((NUM_ABONADO\
=:b0 and NUM_ESTADIA=:b1) and NUM_PROCESO=0)           ";

 static const char *sq0017 = 
"t COD_CICLFACT  from FA_CICLFACT where (FEC_EMISION<=(select FEC_EMISION  fr\
om FA_CICLFACT where COD_CICLFACT=:b2) and IND_FACTURACION>:b6))) and COD_CLIE\
NTE=:b0) and NUM_PROCESO=:b6))))           ";

 static const char *sq0018 = 
"select  /*+  index (GA_INFACCEL PK_GA_INFACCEL)  +*/ ROWID ,NUM_ABONADO  fro\
m GA_INFACCEL where ((((COD_CLIENTE=:b0 and NUM_ABONADO=:b1) and COD_CICLFACT=\
:b2) and IND_FACTUR=:b3) and ((exists (select  /*+  index (TA_ACUMAIREFRASOC P\
K_TA_ACUMAIREFRASOC) +*/ NUM_ABONADO  from TA_ACUMAIREFRASOC where (((NUM_ABON\
ADO=:b1 and COD_CICLFACT=:b2) and COD_CLIENTE=:b0) and NUM_PROCESO=:b7)) or ex\
ists (select  /*+  index(TA_ACUMOPER PK_TA_ACUMOPER)  +*/ NUM_ABONADO  from TA\
_ACUMOPER where (((NUM_ABONADO=:b1 and COD_CICLFACT=:b2) and COD_CLIENTE=:b0) \
and NUM_PROCESO=:b7))) or exists (select  /*+  index(TA_ACUMLLAMADASROA PK_TA_\
ACUMLLAMADASROA) +*/ NUM_ABONADO  from TA_ACUMLLAMADASROA where (((COD_CICLFAC\
T=:b2 and NUM_ABONADO=:b1) and COD_CLIENTE=:b0) and NUM_PROCESO=:b7))))       \
    ";

 static const char *sq0019 = 
"select  /*+  index (GA_INFACCEL PK_GA_INFACCEL)  +*/ ROWID ,NUM_ABONADO  fro\
m GA_INFACCEL where ((((COD_CLIENTE=:b0 and NUM_ABONADO=:b1) and FEC_BAJA<=TO_\
DATE(:b2,'YYYYMMDDHH24MISS')) and IND_FACTUR=:b3) and ((exists (select  /*+  i\
ndex (TA_ACUMAIREFRASOC PK_TA_ACUMAIREFRASOC) +*/ NUM_ABONADO  from TA_ACUMAIR\
EFRASOC where ((NUM_ABONADO=:b1 and COD_CLIENTE=:b0) and NUM_PROCESO=:b6)) or \
exists (select  /*+  index(TA_ACUMOPER PK_TA_ACUMOPER)  +*/ NUM_ABONADO  from \
TA_ACUMOPER where ((NUM_ABONADO=:b1 and COD_CLIENTE=:b0) and NUM_PROCESO=:b6))\
) or exists (select  /*+  index(TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA) +*/ \
NUM_ABONADO  from TA_ACUMLLAMADASROA where ((NUM_ABONADO=:b1 and COD_CLIENTE=:\
b0) and NUM_PROCESO=:b6))))           ";

 static const char *sq0020 = 
"select COD_PRODUCTO ,COD_CONCEPTO ,NVL(DES_CONCEPTO,:b0)  from GE_MULTIIDIOM\
A where ((NOM_TABLA=:b1 and NOM_CAMPO=:b2) and COD_IDIOMA=:b3)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,228,0,265,494,0,0,7,7,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
48,0,0,1,0,0,269,506,0,0,3,0,0,1,0,2,97,0,0,2,3,0,0,2,4,0,0,
75,0,0,2,57,0,261,516,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
98,0,0,1,0,0,271,524,0,0,0,0,0,1,0,
113,0,0,3,243,0,265,582,0,0,7,7,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,
156,0,0,3,0,0,269,595,0,0,4,0,0,1,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
187,0,0,4,57,0,261,607,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
210,0,0,3,0,0,271,615,0,0,0,0,0,1,0,
225,0,0,5,243,0,265,666,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
260,0,0,5,0,0,269,680,0,0,3,0,0,1,0,2,4,0,0,2,3,0,0,2,3,0,0,
287,0,0,5,0,0,271,696,0,0,0,0,0,1,0,
302,0,0,6,273,0,265,746,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
341,0,0,6,0,0,269,759,0,0,2,0,0,1,0,2,4,0,0,2,3,0,0,
364,0,0,6,0,0,271,773,0,0,0,0,0,1,0,
379,0,0,8,344,0,265,1068,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,
414,0,0,7,391,0,265,1070,0,0,6,6,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,5,0,0,
453,0,0,8,0,0,269,1094,0,0,8,0,0,1,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
5,0,0,2,5,0,0,2,3,0,0,
500,0,0,7,0,0,269,1103,0,0,10,0,0,1,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
555,0,0,9,61,0,261,1139,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
578,0,0,8,0,0,271,1153,0,0,0,0,0,1,0,
593,0,0,7,0,0,271,1157,0,0,0,0,0,1,0,
608,0,0,10,223,0,265,1233,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
635,0,0,11,323,0,265,1237,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
666,0,0,10,0,0,269,1249,0,0,5,0,0,1,0,2,4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
701,0,0,11,0,0,269,1255,0,0,7,0,0,1,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,5,0,0,
744,0,0,12,55,0,261,1295,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
767,0,0,10,0,0,271,1310,0,0,0,0,0,1,0,
782,0,0,11,0,0,271,1314,0,0,0,0,0,1,0,
797,0,0,14,211,0,265,1375,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
824,0,0,13,195,0,265,1379,0,0,4,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
855,0,0,14,0,0,269,1391,0,0,3,0,0,1,0,2,4,0,0,2,3,0,0,2,3,0,0,
882,0,0,13,0,0,269,1398,0,0,5,0,0,1,0,2,97,0,0,2,3,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
917,0,0,15,62,0,261,1426,0,0,2,2,0,1,0,1,3,0,0,1,97,0,0,
940,0,0,14,0,0,271,1444,0,0,0,0,0,1,0,
955,0,0,13,0,0,271,1448,0,0,0,0,0,1,0,
970,0,0,16,209,0,265,1502,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
993,0,0,16,0,0,269,1516,0,0,4,0,0,1,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
1024,0,0,16,0,0,271,1557,0,0,0,0,0,1,0,
1039,0,0,17,1221,0,265,2087,0,0,19,19,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1130,0,0,18,782,0,265,2091,0,0,16,16,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,
1209,0,0,19,738,0,265,2095,0,0,13,13,0,1,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1276,0,0,17,0,0,269,2119,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
1299,0,0,18,0,0,269,2121,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
1322,0,0,19,0,0,269,2123,0,0,2,0,0,1,0,2,5,0,0,2,3,0,0,
1345,0,0,17,0,0,271,2152,0,0,0,0,0,1,0,
1360,0,0,18,0,0,271,2154,0,0,0,0,0,1,0,
1375,0,0,19,0,0,271,2156,0,0,0,0,0,1,0,
1390,0,0,20,149,0,265,2705,0,0,4,4,0,1,0,1,5,0,0,1,5,0,0,1,5,0,0,1,97,0,0,
1421,0,0,20,0,0,269,2716,0,0,3,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,
1448,0,0,20,0,0,271,2750,0,0,0,0,0,1,0,
1463,0,0,21,388,0,260,2803,0,0,9,8,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1514,0,0,22,179,0,260,2855,0,0,8,7,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,
1561,0,0,23,287,0,260,2869,0,0,10,9,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
1616,0,0,24,264,0,260,2892,0,0,9,8,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,
0,1,5,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
1667,0,0,25,257,0,260,2913,0,0,7,6,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,
1710,0,0,26,163,0,260,2966,0,0,3,2,0,1,0,2,5,0,0,1,5,0,0,1,5,0,0,
};


/******************************************************************************
 Fichero    : pretar.pc
 Descripcion:
 Fecha      : 23-01-97
 Autor      : Javier Garcia Paredes
*******************************************************************************/

#define _PRETAR_PC_

#include <pretar.h>


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


/*----------------------------------------------------------------------------*/
/* Funcion de busqueda en arreglo de ciclos facturados.                       */
/*----------------------------------------------------------------------------*/
BOOL bBusca_Ciclo (long lCodCiclFact)
{
    int i=0;

    while( (lCodCiclFact != (long)iArrCiclo[i]) && (i <= NUM_IARRCICLO) )
    {
        i++;
    }
    if( i > NUM_IARRCICLO )   /* Periodo no encontrado en arreglo */
    {
        vDTrazasLog(szExeName, "Periodo [%ld] no encontrado ...", LOG05, lCodCiclFact);
        return(FALSE);
    }
    return(1);
}


/* -------------------------------------------------------------------------- */
/*   bIFTarificacion (long)                                                   */
/*      Valores Retorno: FALSE - Error                                        */
/*                       TRUE  - Ningun Error                                 */
/* -------------------------------------------------------------------------- */
BOOL bfnIFTarificacion (int iTipoFact)
{
    BOOL bRes  = 1;
    int  iCont = 0;
    int  iIndAlquiler;

    if( iTipoFact == FACT_CICLO )
        memset (&stPlanOptimo, 0, sizeof (EST));

    vDTrazasLog (szExeName,"\n\t\t* Cargando TARIFICACION ",LOG04);

    strncpy (stAnomProceso.szDesProceso,"PreBilling Tarificacion (Carga)",
             sizeof(stAnomProceso.szDesProceso));

    switch( iTipoFact )
    {
        case FACT_RENTAPHONE:
            if( !bfnLeeConceptosRentPhone (stCliente.pAboRent) )
                bRes = FALSE;
            break;
        case FACT_ROAMINGVIS:
            if( stCiclo.iInd_Tasacion==TIPO_TASA_ON_LINE)
            {
                if( !bfnLeeConceptosRoamingVis (stCliente.pAboRoaVis) )
                     bRes = FALSE;
            }
            break;
        case FACT_CICLO      :
        case FACT_BAJA       :
        case FACT_LIQUIDACION:
            if( iTipoFact == FACT_LIQUIDACION )
            {
/*
                if( stCiclo.iInd_Tasacion==TIPO_TASA_ON_LINE)
                {
                    if( !bfnLeeAbonadosTOL(iTipoFact) )
                        return(FALSE);
                }
                else
*/
                {
                    if( !bfnLeeAbonados (iTipoFact) )
                        return(FALSE);
                }
            }
            /*****************************************************************/
            /*  Los Abonados a Tasar, se carga en el interface's de Servicios*/
            /*****************************************************************/
            while( iCont < stCliente.iNumAbonados && bRes )
            {
/*
                if( stCiclo.iInd_Tasacion==TIPO_TASA_ON_LINE)
                {
                    if( !bfnLee_TOL_Acumper(&(stCliente.pAbonados[iCont])) )
                        bRes = FALSE;
                }
                else
*/
                {
                    if( !bfnLeeConceptos(&(stCliente.pAbonados[iCont])) )
                        bRes = FALSE;
                }
                if( bRes )
                {
                    iIndAlquiler = 0;

                    if( !bfnLeeConceptosCarriers (&stCliente.pAbonados[iCont],
                     stCliente.pAboRent,  iIndAlquiler) )
                        bRes = FALSE;
                    else
                        iCont++;
                }
            }

            break;
    }/* fin switch */

    if( bRes )
    {
        vfnPrintConcTarificacion ();
    }
    return(bRes);
}/************************ Final bIFTarificacion *****************************/

/*****************************************************************************/
/*                          funcion : bfnLeeAbonados                         */
/* -Funcion que carga los NumAbono de Ga_Infa% que cumplen las condiciones,de*/
/*  estar en las tablas de Ta_Acum%, dependiendo del producto iremos a unas  */
/*  tablas o a otras.                                                        */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnLeeAbonados(int iTipoFact)
{
    BOOL bRes = TRUE ;
    long lInd = 0    ;

    stCliente.pAbonados = (ABONTAR *)NULL;

    if( iTipoFact == FACT_BAJA||iTipoFact == FACT_LIQUIDACION )
    {
     /*******************************************************************/
     /* La estructura stAbonoCli solo tendra un abono-producto, que es  */
     /* el cual se da de baja o se liquida, es la unica diferencia.     */
     /*******************************************************************/
        if( !bfnCargaAbonadosCliente (&stAbonoCli.pCicloCli[0],iTipoFact) )
            return(FALSE);
    }
    else if( iTipoFact == FACT_CICLO )
    {
        while( lInd < stAbonoCli.lNumAbonados && bRes )
        {
            if( !bfnCargaAbonadosCliente(&stAbonoCli.pCicloCli[lInd],FACT_CICLO) )
                bRes = FALSE;
            else
                lInd++;
        }/* fin While lInd ... */
    }
    return(bRes);
}/*************************** Funcion bfnLeeAbonados *************************/

/*****************************************************************************/
/* -Funcion que carga los conceptos para un abonado (Ta_ConcepFact)          */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
static BOOL bfnLeeConceptos(ABONTAR* pAbon)
{
    int  iCont1= 0     ;

    int  iCodProducto=0;
    long lNumAbonado =0;

    /* CONCEPTO stConcepto; */
    EST      stEstProc ;
	CONCEP   stConcep;

    vDTrazasLog (szExeName,"\n\t\t* Entrada en bfnLeeConceptos", LOG05);

	/* rao: se reemplaza por estructura dinamica stConcep2
	    memset (&stConcep  ,0,sizeof(CONCEP)) ; */
	/* memset (&stConcepto,0,sizeof(CONCEPTO));  */
	
	/* estructura dinamica para cargo de conceptode trafico */

    memset (&stEstProc ,0,sizeof(EST))     ;
    memset (&stConcep ,0,sizeof(stConcep))     ;

    lNumAbonado = pAbon->lNumAbonado ;
    iCodProducto= pAbon->iCodProducto;

    if( !bfnLeeAcumFraSoc(&stConcep, lNumAbonado, iCodProducto) )
    {
        iDError (szExeName,ERR005,vInsertarIncidencia,"bfnLeeAcumFraSoc");
        return(FALSE);

    }
    if( !bfnLeeAcumOper (&stConcep, lNumAbonado) )
    {
        iDError (szExeName,ERR005,vInsertarIncidencia,"bfnLeeAcumOper");
        return(FALSE);

    }
    if( !bfnLeeAcumLlamadasRoa(&stConcep, lNumAbonado) )
    {
        iDError (szExeName,ERR005,vInsertarIncidencia,"bfnLeeAcumLlamadasRoa");
        return(FALSE);

    }

    iCont1= 0;
    while( iCont1<stConcep.iNumConc )
    {
        if( stConcep.stConcTar[iCont1].iCodProducto == pAbon->iCodProducto &&
            (stConcep.stConcTar[iCont1].iIndTabla == ROAMING  ||
             stConcep.stConcTar[iCont1].iIndTabla == ACUMOPER ||
             stConcep.stConcTar[iCont1].iIndTabla == FRASOC) )
        {
            /* --Validacion del Concepto -- */
            /* El concepto se imprime si :                                  */
            /* dImpConsumido >= 0.01                                        */
            /* OR                                                           */
            /* stParConcTrafico.iConsConcTrafico == 1 && lSegConsumido > 60 */
            /* FAR. 20020827 */
            if( (stConcep.stConcTar[iCont1].dImpConsumido >= 0.01) ||
                (pstParamGener.iConsConcTrafico == 1) )
            {
                if( !bfnValidacionConcTar (&stConcep.stConcTar[iCont1]) ) return(FALSE);
                if( (pAbon->pConcTar=
                     (CONCTAR *)realloc ( (CONCTAR *)pAbon->pConcTar,
                                          sizeof(CONCTAR)*(pAbon->iNumConcTar+1) ))==(CONCTAR *)NULL )
                {
                    iDError (szExeName,ERR005,vInsertarIncidencia,
                             "pAbon->pConcTar");
                    return(FALSE);
                }

                memcpy (&pAbon->pConcTar[pAbon->iNumConcTar],&stConcep.stConcTar[iCont1],
                        sizeof (CONCTAR));

                switch( stConcep.stConcTar[iCont1].iIndTabla )
                {
                    case FRASOC   : if( stConcep.stConcTar[iCont1].iIndEntSal == iENTRANTE )
                        {
                            stEstProc.iNumConcLocalEnt++     ;
                            stEstProc.dTotImpLocalEnt +=
                            stConcep.stConcTar[iCont1].dImpConsumido;
                        }
                        if( stConcep.stConcTar[iCont1].iIndEntSal == iSALIENTE )
                        {
                            stEstProc.iNumConcLocalSal++     ;
                            stEstProc.dTotImpLocalSal +=
                            stConcep.stConcTar[iCont1].dImpConsumido;
                        }
                        stEstProc.lSegTotLocal +=
                        stConcep.stConcTar[iCont1].lSegConsumido;
                        break;
                    case ACUMOPER : stEstProc.iNumConcOper++         ;
                        stEstProc.dTotImpOper   +=
                        stConcep.stConcTar[iCont1].dImpConsumido;
                        break                            ;
                    case ROAMING  : stEstProc.iNumConcRoaming++      ;
                        stEstProc.dTotImpRoaming+=
                        stConcep.stConcTar[iCont1].dImpConsumido;
                        break                            ;
                }/* fin switch */
                pAbon->iNumConcTar++;
            }/* fin if >= 0.0 .. */
        }/* if CodProducto ... */
        iCont1++;

    }/* fin while */
    vDTrazasLog (szExeName,
                 "\n\t\t* Estadisticas de Trafico para el Abonado :   [%ld]"
                 "\n\t\t=>Conceptos Trafico Local Entrante            [%d]"
                 "\n\t\t=>Importe Total Trafico Local Entrante (Pesos)[%.f]"
                 "\n\t\t=>Conceptos Trafico Local Saliente            [%d]"
                 "\n\t\t=>Importe Total Trafico Local Saliente (Pesos)[%.f]"
                 "\n\t\t=>Conceptos Trafico Larga Distancia           [%d]"
                 "\n\t\t=>Importe Total Trafico Larga Distancia(Pesos)[%.f]"
                 "\n\t\t=>Conceptos Trafico Roaming                   [%d]"
                 "\n\t\t=>Importe Total Trafico Roaming (Dolares)     [%.f]"
                 ,LOG04,pAbon->lNumAbonado, stEstProc.iNumConcLocalEnt,
                 stEstProc.dTotImpLocalEnt, stEstProc.iNumConcLocalSal,
                 stEstProc.dTotImpLocalSal, stEstProc.iNumConcOper    ,
                 stEstProc.dTotImpOper    , stEstProc.iNumConcRoaming ,
                 stEstProc.dTotImpRoaming);

    if( stProceso.iCodTipDocum == stDatosGener.iCodCiclo )
    {
        stPlanOptimo.lSegTotLocal += stEstProc.lSegTotLocal;
    }

	bLiberaEstrConc(&stConcep);
	
    return(1);
}/************************** Final bfnLeeConceptos ***************************/

/*****************************************************************************/
/*                          funcion : bfnLeeConceptosCarriers                */
/* -Funcion que carga los conceptos para un abonado (Fa_FactCarriers)        */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
static BOOL bfnLeeConceptosCarriers (ABONTAR* pAbon ,
                                     ABORENT* pARent,
                                     int      iIndAlquiler)
{
    int  iCont   = 0 ;
    int  iRepite = 0 ;
    int  iCasos  = 1 ;
    int  iFortas = 0 ;
    int  iForadi = 0 ;

    CONCTAR  stConcTar    ;
    CONCTAR  stConcForadi ;
    CONCTAR  stConcFortas ;
    CONCEPTO stConcepto   ;
    EST      stEstProc    ;

    memset (&stConcTar ,0,sizeof(CONCTAR)) ;
    memset (&stConcepto,0,sizeof(CONCEPTO));
    memset (&stEstProc ,0,sizeof(EST))     ;

    if( iIndAlquiler == 1 )
    {
        stConcTar.lNumAbonado = pARent->lNumAbonado      ;
        stConcTar.iCodProducto= stDatosGener.iProdCelular;
    }
    else
    {
        stConcTar.lNumAbonado = pAbon->lNumAbonado ;
        stConcTar.iCodProducto= pAbon->iCodProducto;
    }

    while( iCont<NUM_FACTCARRIERS )
    {
        stConcTar.iCodFacturacion = pstFactCarriers [iCont].iCodConcFact   ;
        stConcTar.dImpConsumido   = 0                                      ;
        stConcTar.lSegConsumido   = 0                                      ;
        stConcTar.lNumPulsos      = 0                                      ;
        stConcTar.lNumProceso     = stStatus.IdPro                         ;
        stConcTar.iCodOperador    = pstFactCarriers [iCont].iCodConcCarrier;
        stConcTar.iCodFranHoraSoc = 0                                      ;
        stConcTar.iIndEntSal      = 0                                      ;
        stConcTar.iIndTabla       = 0                                      ;
        stConcTar.iCarrier        = 0                                      ;

        if( !bFindConcepto (stConcTar.iCodFacturacion, &stConcepto) )
            return(FALSE);

        memcpy (&stConcFortas, &stConcTar, sizeof (CONCTAR));

        stConcFortas.iCarrier = iFORTAS;

        if( !bfnDBLeeAcumFortas (&stConcFortas,
                                 pstFactCarriers [iCont].iCodConcCarrier,
                                 stConcepto.iCodTipConce) )
            return(FALSE);

        memcpy (&stConcForadi, &stConcTar, sizeof (CONCTAR));
        stConcForadi.iCarrier = iFORADI;

        if( !bfnDBLeeAcumForadi (&stConcForadi,
                                 pstFactCarriers [iCont].iCodConcCarrier,
                                 stConcepto.iCodTipConce) )
            return(FALSE);

        iRepite = 0;

        iFortas = (stConcFortas.dImpConsumido >= 0.01)?1:0;
        iForadi = (stConcForadi.dImpConsumido >= 0.01)?1:0;

        iCasos  = (iFortas && iForadi)?2:
                  (iFortas || iForadi)?1:0;

        while( iRepite < iCasos )
        {
            switch( iCasos )
            {
                case 1 :
                    if( iFortas )
                        memcpy (&stConcTar, &stConcFortas, sizeof (CONCTAR));
                    if( iForadi )
                        memcpy (&stConcTar, &stConcForadi, sizeof (CONCTAR));
                    break;
                case 2 :
                    if( iRepite == 0 )
                        memcpy (&stConcTar, &stConcFortas, sizeof (CONCTAR));
                    else
                        memcpy (&stConcTar, &stConcForadi, sizeof (CONCTAR));
                    break;
                default :
                    break;
            }
             /* --Validacion del Concepto -- */
            if( stConcTar.dImpConsumido >= 0.01 )
            {
                if( !bfnValidacionCarrier (&stConcTar, stConcepto) )
                    return(FALSE);
                if( iIndAlquiler == 0 )
                {
                    if( (pAbon->pConcTar=
                         (CONCTAR *)realloc((CONCTAR *)pAbon->pConcTar,
                                            sizeof(CONCTAR)*(pAbon->iNumConcTar+1) ))
                        ==(CONCTAR *)NULL )
                    {
                        iDError (szExeName,ERR005,vInsertarIncidencia,
                                 "pAbon->pConcTar");
                        return(FALSE);
                    }
                    memcpy (&pAbon->pConcTar[pAbon->iNumConcTar],&stConcTar,
                            sizeof (CONCTAR));
                    pAbon->iNumConcTar++;

                }
                else
                {
                    if( (pARent->pConcTar =
                         (CONCTAR *)realloc ((CONCTAR *)pARent->pConcTar,
                                             sizeof(CONCTAR)*(pARent->iNumConcTar+1)))
                        ==(CONCTAR*)NULL )
                    {
                        iDError (szExeName,ERR005,vInsertarIncidencia,
                                 "pARent->pConcTar");
                        return(FALSE                );
                    }
                    memcpy (&pARent->pConcTar[pARent->iNumConcTar],
                            &stConcTar,sizeof(CONCTAR));
                    pARent->iNumConcTar++;
                }
                stEstProc.dTotImpCarriers  += stConcTar.dImpConsumido;
                stEstProc.iNumConcCarriers += 1                      ;

            }/* fin if dImpConsumido >= 0.01 */
            iRepite++;

        }/* fin while iRepite ... */
        iCont++;

    }/* fin while */
    vDTrazasLog (szExeName,
                 "\n\t\t=>Conceptos Trafico Carriers                  [%d]"
                 "\n\t\t=>Importe Total Trafico Carriers              [%f]",LOG04,
                 stEstProc.iNumConcCarriers, stEstProc.dTotImpCarriers);

    return(1);
}/************************** Final bfnLeeConceptosCarriers *******************/

/*****************************************************************************/
/*                         funcion : bfnDBLeeAcumForadi                      */
/*****************************************************************************/
static BOOL bfnDBLeeAcumForadi (CONCTAR *pstConcTar  ,
                                int      iCodOperador,
                                int      iCodTipConce)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhRowid[19];
    static long   lhCodPeriodo    ;
    int   iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 


    static double dImpConsumido = 0.0;
    static short  shIndAlquiler      ;

    /* EXEC SQL DECLARE Cur_AcumForadi CURSOR FOR
    SELECT ROWID, COD_PERIODO, IMP_CONSUMIDO
    FROM   FA_ACUMFORADI
    WHERE  NUM_ABONADO = :pstConcTar->lNumAbonado
                         AND  IND_ALQUILER= :shIndAlquiler
                         AND  COD_PERIODO > :iCero
                         AND  COD_OPERADOR= :iCodOperador
                         AND  COD_TIPCONCE= :iCodTipConce
                         AND  COD_CLIENTE = :stCliente.lCodCliente
                         AND  NUM_PROCESO = :iCero; */ 


    if( pstConcTar->lNumAlquiler > 0 )
    {
        shIndAlquiler = 1                       ;
        lhCodPeriodo   = pstConcTar->lNumAlquiler;
    }
    else
    {
        shIndAlquiler = 0                       ;
      /* lhCodPeriodo   = stCiclo.lCodCiclFact    ; */
    }

    vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada en Fa_AcumForadi"
                           "\n\t\t=>Num.Abonado  [%ld]"
                           "\n\t\t=>Cod.Operador [%d] "
                           "\n\t\t=>Cod.Cliente  [%ld]"
                           "\n\t\t=>Ind.Alquiler [%d] ", LOG04,
                           pstConcTar->lNumAbonado, iCodOperador,
                           stCliente.lCodCliente  , shIndAlquiler);

    pstConcTar->iCodOperador = iCodOperador;

    /* EXEC SQL OPEN Cur_AcumForadi; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pstConcTar->lNumAbonado);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&shIndAlquiler;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&iCero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iCodOperador;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&iCodTipConce;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&(stCliente.lCodCliente);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&iCero;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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



    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=>Fa_AcumForadi",
                 szfnORAerror ());
        return(FALSE           );
    }
    while( SQLCODE == SQLOK )
    {
        dImpConsumido = 0.0;

        /* EXEC SQL FETCH Cur_AcumForadi INTO :szhRowid, :lhCodPeriodo, :dImpConsumido; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )48;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodPeriodo;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&dImpConsumido;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
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



        if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Fetch=>Fa_AcumForadi", szfnORAerror ());
        if( SQLCODE == SQLOK )
        {
            if( bBusca_Ciclo(lhCodPeriodo))
            {
                pstConcTar->dImpConsumido += dImpConsumido;
                /* EXEC SQL UPDATE FA_ACUMFORADI
                SET NUM_PROCESO = :stStatus.IdPro
                                  WHERE ROWID = :szhRowid; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "update FA_ACUMFORADI  set NUM_PROCESO=:b0 whe\
re ROWID=:b1";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )75;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&(stStatus.IdPro);
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


            }
        }
    }
    if( SQLCODE == SQLNOTFOUND )
    {
        /* EXEC SQL CLOSE Cur_AcumForadi; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )98;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if( SQLCODE )
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close=>Fa_AcumForadi",
                     szfnORAerror ());
    }
    return(SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnDBLeeAcumForadi ************************/

/*****************************************************************************/
/*                         funcion : bfnDBLeeAcumFortas                      */
/*****************************************************************************/
static BOOL bfnDBLeeAcumFortas (CONCTAR *pstConcTar  ,
                                int      iCodOperador,
                                int      iCodTipConce)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhRowid[19];
    static long   lhCodPeriodo    ;
    int  iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 


    static double dImpConsumido = 0.0;
    static long   lSegConsumido = 0  ;
    static short  shIndAlquiler      ;

    /* EXEC SQL DECLARE Cur_AcumFortas CURSOR FOR
        SELECT ROWID, COD_PERIODO,  IMP_CONSUMIDO, SEG_CONSUMIDO
        FROM   FA_ACUMFORTAS
        WHERE  NUM_ABONADO = :pstConcTar->lNumAbonado
                             AND  IND_ALQUILER= :shIndAlquiler
                             AND  COD_PERIODO > :iCero
                             AND  COD_OPERADOR= :iCodOperador
                             AND  COD_TIPCONCE= :iCodTipConce
                             AND  COD_CLIENTE = :stCliente.lCodCliente
                             AND  NUM_PROCESO = :iCero; */ 


    if( pstConcTar->lNumAlquiler > 0 )
    {
        shIndAlquiler = 1                       ;
        lhCodPeriodo   = pstConcTar->lNumAlquiler;
    }
    else
    {
        shIndAlquiler = 0                       ;
      /* lhCodPeriodo   = stCiclo.lCodCiclFact    ; */
    }
    vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada en Fa_AcumFortas"
                           "\n\t\t=>Num.Abonado  [%ld]"
                           "\n\t\t=>Cod.Operador [%d] "
                           "\n\t\t=>Cod.TipConce [%d] "
                           "\n\t\t=>Cod.Cliente  [%ld]"
                           "\n\t\t=>Ind.Alquiler [%d] ", LOG04,
                           pstConcTar->lNumAbonado, iCodOperador, iCodTipConce,
                           stCliente.lCodCliente, shIndAlquiler);

    pstConcTar->iCodOperador = iCodOperador;


    /* EXEC SQL OPEN Cur_AcumFortas; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0003;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )113;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pstConcTar->lNumAbonado);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&shIndAlquiler;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&iCero;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&iCodOperador;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&iCodTipConce;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&(stCliente.lCodCliente);
    sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&iCero;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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



    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open=>Fa_AcumFortas",
                 szfnORAerror ());
        return(FALSE           );
    }
    while( SQLCODE == SQLOK )
    {
        dImpConsumido = 0.0;
        lSegConsumido = 0  ;

        /* EXEC SQL FETCH Cur_AcumFortas INTO :szhRowid, :lhCodPeriodo,
        :dImpConsumido, :lSegConsumido; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )156;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhCodPeriodo;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&dImpConsumido;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lSegConsumido;
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



        if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Fetch=>Fa_AcumFortas", szfnORAerror ());
        if( SQLCODE == SQLOK )
        {
            if( bBusca_Ciclo(lhCodPeriodo))
            {
                pstConcTar->dImpConsumido += dImpConsumido;
                pstConcTar->lSegConsumido += lSegConsumido;
                /* EXEC SQL UPDATE FA_ACUMFORTAS
                SET NUM_PROCESO = :stStatus.IdPro
                                  WHERE ROWID = :szhRowid; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "update FA_ACUMFORTAS  set NUM_PROCESO=:b0 whe\
re ROWID=:b1";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )187;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&(stStatus.IdPro);
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


            }
        }
    }
    if( SQLCODE == SQLNOTFOUND )
    {
        /* EXEC SQL CLOSE Cur_AcumFortas; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )210;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if( SQLCODE )
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close=>Fa_AcumFortas",
                     szfnORAerror ());
    }
    return(SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnDBLeeAcumFortas ************************/


/*****************************************************************************/
/*                        funcion : bfnLeeAcumOperAlq                        */
/* -Funcion que carga la informacion de consumos del Abonado y periodo en la */
/*  la tabla Ta_AcumOperAlq      .                                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnLeeAcumOperAlq (CONCTAR *pConcTar,
                               int      iCodTarificacion)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

         int  iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    static double dImpConsumido = 0.0;
    static long   lSegConsumido = 0  ;
    static long   lNumPulsos    = 0  ;

    /* EXEC SQL DECLARE Cur_AcumOperAlq CURSOR FOR
    SELECT /o+ index (TA_ACUMOPERALQ PK_TA_ACUMOPERALQ) o/
    IMP_CONSUMIDO,
    SEG_CONSUMIDO,
    NUM_PULSOS
    FROM   TA_ACUMOPERALQ
    WHERE  NUM_ABONADO     = :pConcTar->lNumAbonado
                             AND  NUM_ALQUILER    = :pConcTar->lNumAlquiler
                             AND  COD_OPERADOR    = :iCodTarificacion
                             AND  COD_CLIENTE     = :stCliente.lCodCliente
                             AND  NUM_PROCESO     = :iCero; */ 


    vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ta_AcumOperAlq\n"
                 "\t\t=> Num.Abonado      [%ld]\n"
                 "\t\t=> Cod.Cliente      [%ld]\n"
                 "\t\t=> Num.Alquiler     [%ld]\n"
                 "\t\t=> Cod.Tarificacion [%d] \n",LOG04,
                 pConcTar->lNumAbonado ,
                 stCliente.lCodCliente ,
                 pConcTar->lNumAlquiler,
                 iCodTarificacion);

    pConcTar->iCodOperador = iCodTarificacion;

    /* EXEC SQL OPEN Cur_AcumOperAlq; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0005;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )225;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pConcTar->lNumAbonado);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(pConcTar->lNumAlquiler);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&iCodTarificacion;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&(stCliente.lCodCliente);
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



    if( SQLCODE != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Open->Ta_AcumOperAlq",szfnORAerror());
        return(FALSE);
    }
    while( SQLCODE == SQLOK )
    {
        dImpConsumido = 0.0;
        lSegConsumido = 0  ;
        lNumPulsos    = 0  ;

        /* EXEC SQL FETCH Cur_AcumOperAlq INTO :dImpConsumido,
        :lSegConsumido,
        :lNumPulsos; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )260;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&dImpConsumido;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lSegConsumido;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lNumPulsos;
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


        if( SQLCODE == SQLOK )
        {
            pConcTar->dImpConsumido += dImpConsumido;
            pConcTar->lSegConsumido += lSegConsumido;
            pConcTar->lNumPulsos    += lNumPulsos   ;
        }
    }
    if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Fetch->Ta_AcumOperAlq",szfnORAerror());
        return(FALSE);
    }
    /* EXEC SQL CLOSE Cur_AcumOperAlq; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )287;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Close->Ta_AcumOperAlq",szfnORAerror());

    return(SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnAcumOperAlq ***************************/

/*****************************************************************************/
/*                    funcion : bfnLeeAcumAireFraSocAlq                      */
/* -Funcion que carga la informacion de consumos del Abonado y periodo en la */
/*  la tabla Ta_AcumAireFraSocAlq.                                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnLeeAcumAireFraSocAlq (CONCTAR *pConcTar,
                                     int      iCodTarificacion)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

         int  iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    static double dImpConsumido = 0.0;
    static long   lSegConsumido = 0  ;

    /* EXEC SQL DECLARE Cur_AcumAireAlq CURSOR FOR
    SELECT /o+ index (TA_ACUMAIREFRASOCALQ PK_TA_ACUMAIREFRASOCALQ) o/
    IMP_CONSUMIDO,
    SEG_CONSUMIDO
    FROM   TA_ACUMAIREFRASOCALQ
    WHERE  NUM_ABONADO     = :pConcTar->lNumAbonado
                             AND  NUM_ALQUILER    = :pConcTar->lNumAlquiler
                             AND  COD_FRANHORASOC = :iCodTarificacion
                             AND  IND_ENTSAL      = :pConcTar->iIndEntSal
                             AND  COD_CLIENTE     = :stCliente.lCodCliente
                             AND  NUM_PROCESO     = :iCero; */ 


    vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ta_AcumAireFraSocAlq\n"
                 "\t\t=> Num.Abonado      [%ld]\n"
                 "\t\t=> Cod.Cliente      [%ld]\n"
                 "\t\t=> Num.Alquiler     [%ld]\n"
                 "\t\t=> Ind.EntSal       [%d] \n"
                 "\t\t=> Cod.Tarificacion [%d] \n",LOG04,
                 pConcTar->lNumAbonado ,
                 stCliente.lCodCliente ,
                 pConcTar->lNumAlquiler,
                 pConcTar->iIndEntSal  ,
                 iCodTarificacion);

    pConcTar->iCodFranHoraSoc = iCodTarificacion;

    /* EXEC SQL OPEN Cur_AcumAireAlq; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0006;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )302;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&(pConcTar->lNumAbonado);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(pConcTar->lNumAlquiler);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&iCodTarificacion;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&(pConcTar->iIndEntSal);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&(stCliente.lCodCliente);
    sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&iCero;
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



    if( SQLCODE != SQLOK )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Open->Ta_AcumAireFraSocAlq",szfnORAerror());
        return(FALSE);
    }
    while( SQLCODE == SQLOK )
    {
        dImpConsumido = 0.0;
        lSegConsumido = 0  ;

        /* EXEC SQL FETCH Cur_AcumAireAlq INTO :dImpConsumido,
        :lSegConsumido; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )341;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&dImpConsumido;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lSegConsumido;
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


        if( SQLCODE == SQLOK )
        {
            pConcTar->dImpConsumido += dImpConsumido;
            pConcTar->lSegConsumido += lSegConsumido;
        }
    }
    if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Fetch->Ta_AcumAireFraSocAlq",szfnORAerror());
        return(FALSE);
    }
    /* EXEC SQL CLOSE Cur_AcumAireAlq; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )364;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if( SQLCODE != SQLOK )
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Close->Ta_AcumAireFraSocAlq",szfnORAerror());

    return(SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnAcumAireFraSocAlq **********************/

/*****************************************************************************/
/*                        funcion : bfnLeeConceptoRentPhone                  */
/* -Funcion que carga los Conceptos de Tarificacion para un Abonado          */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnLeeConceptosRentPhone (ABORENT *pAboRent)
{
    int  iCont = 0    ;

    BOOL bRes  = TRUE ;

    CONCTAR stConcTar ;
    CONCTAR stConcTar2;
    EST     stEstProc ;

    memset (&stEstProc ,0,sizeof(EST))    ;

    while( iCont<NUM_TACONCEPFACT && bRes )
    {
        if( pstTaConcepFact[iCont].iCodProducto==stDatosGener.iProdCelular &&
            (pstTaConcepFact[iCont].iIndTabla   == FRASOC                   ||
             pstTaConcepFact[iCont].iIndTabla   == ACUMOPER) )
        {
            memset (&stConcTar2,0,sizeof(CONCTAR));
            memset (&stConcTar ,0,sizeof(CONCTAR));

            stConcTar.iCodProducto    = stDatosGener.iProdCelular             ;
            stConcTar.lNumAbonado     = pAboRent->lNumAbonado                 ;
            stConcTar.lNumAlquiler    = pAboRent->lNumAlquiler                ;
            stConcTar.iCodFacturacion = pstTaConcepFact[iCont].iCodFacturacion;
            stConcTar.lNumProceso     = stStatus.IdPro                        ;
            stConcTar.iIndTabla       = pstTaConcepFact[iCont].iIndTabla      ;
            stConcTar.iIndEntSal      = pstTaConcepFact[iCont].iIndEntSal     ;

            switch( pstTaConcepFact [iCont].iIndTabla )
            {
                case FRASOC  :
                    bRes = bfnLeeAcumAireFraSocAlq (&stConcTar,
                                                    pstTaConcepFact[iCont].iCodTarificacion);
                    break;
                case ACUMOPER:
                    bRes = bfnLeeAcumOperAlq   (&stConcTar,
                                                pstTaConcepFact[iCont].iCodTarificacion);
                    break;
                default :
                    iDError (szExeName,ERR030,vInsertarIncidencia,
                             pstTaConcepFact [iCont].iIndTabla);
                    bRes = FALSE;
                    break       ;
            }
            if( bRes && stConcTar.dImpConsumido >= 0.01 )
            {
                if( !bfnValidacionConcTar (&stConcTar) )
                    bRes = FALSE;
                else
                {
                    if( (pAboRent->pConcTar =
                         (CONCTAR *)realloc ( (CONCTAR *)pAboRent->pConcTar,
                                              sizeof(CONCTAR)*(pAboRent->iNumConcTar+1) ))
                        == (CONCTAR *)NULL )
                    {
                        iDError (szExeName,ERR005,vInsertarIncidencia,
                                 "pAboRent->pConcTar");
                        return(FALSE                  );
                    }
                    memcpy (&pAboRent->pConcTar[pAboRent->iNumConcTar],
                            &stConcTar,sizeof(CONCTAR));
                    switch( pstTaConcepFact [iCont].iIndTabla )
                    {
                        case FRASOC  :
                            if( stConcTar.iIndEntSal == iENTRANTE )
                            {
                                stEstProc.iNumConcLocalEnt++     ;
                                stEstProc.dTotImpLocalEnt +=
                                stConcTar.dImpConsumido;
                            }
                            else if( stConcTar.iIndEntSal == iSALIENTE )
                            {
                                stEstProc.iNumConcLocalSal++     ;
                                stEstProc.dTotImpLocalSal +=
                                stConcTar.dImpConsumido;
                            }
                            break;
                        case ACUMOPER:
                            stEstProc.iNumConcOper++         ;
                            stEstProc.dTotImpOper +=
                            stConcTar.dImpConsumido;
                            break;
                    }
                    pAboRent->iNumConcTar++;

                }/* fin else Validacion ... */

            }/* fin if bRes ... */

        }/* fin if Producto ... */
        iCont++;

    }/* fin While ... */
    vDTrazasLog (szExeName,
                 "\n\t\t* Estadisticas de Trafico para el Abonado :   [%ld]"
                 "\n\t\t=>Conceptos Trafico Local Entrante            [%d]"
                 "\n\t\t=>Importe Total Trafico Local Entrante(Pesos) [%f]"
                 "\n\t\t=>Conceptos Trafico Local Saliente            [%d]"
                 "\n\t\t=>Importe Total Trafico Local Saliente(Pesos) [%f]"
                 "\n\t\t=>Conceptos Trafico Larga Distancia           [%d]"
                 "\n\t\t=>Importe Total Trafico Larga Distancia(Pesos)[%f]",LOG04,
                 pAboRent->lNumAbonado    , stEstProc.iNumConcLocalEnt,
                 stEstProc.dTotImpLocalEnt, stEstProc.iNumConcLocalSal,
                 stEstProc.dTotImpLocalSal, stEstProc.iNumConcOper    ,
                 stEstProc.dTotImpOper);

    return(bRes);
}/*********************** Final bfnLeeConceptosRentPhone *********************/

/*****************************************************************************/
/*                       funcion : bfnLeeConceptsRoamingVis                  */
/*****************************************************************************/
static BOOL bfnLeeConceptosRoamingVis (ABOROAVIS *pRoa)
{
    CONCTAR stConcTar;
    EST     stEstProc;

    BOOL bRes = TRUE ;
    int  iCont= 0    ;

    memset (&stEstProc,0,sizeof(EST));

    while( iCont<NUM_TACONCEPFACT && bRes )
    {
        if( pstTaConcepFact[iCont].iCodProducto     ==
            stDatosGener.iProdCelular                     &&
            pstTaConcepFact[iCont].iIndTabla        == 4  &&
            (pstTaConcepFact[iCont].iCodTarificacion == 0  ||
             pstTaConcepFact[iCont].iCodTarificacion == 1) )
        {
            memset (&stConcTar,0,sizeof(CONCTAR));

            stConcTar.iCodProducto    = stDatosGener.iProdCelular             ;
            stConcTar.lNumAbonado     = pRoa->lNumAbonado                     ;
            stConcTar.lNumEstaDia     = pRoa->lNumEstaDia                     ;
            stConcTar.iCodFacturacion = pstTaConcepFact[iCont].iCodFacturacion;
            stConcTar.lNumProceso     = stStatus.IdPro                        ;
            stConcTar.iIndTabla       = pstTaConcepFact[iCont].iIndTabla      ;

            bRes = bfnLeeAcumRoaming (&stConcTar,
                                      pstTaConcepFact[iCont].iCodTarificacion);

            if( bRes && stConcTar.dImpConsumido >= 0.01 )
            {
                if( !bfnValidacionConcTar (&stConcTar) )
                    bRes = FALSE;
                else
                {
                    if( (pRoa->pConcTar =
                         (CONCTAR *)realloc ( (CONCTAR *)pRoa->pConcTar,
                                              sizeof(CONCTAR)*(pRoa->iNumConcTar+1) ))
                        == (CONCTAR *)NULL )
                    {
                        iDError (szExeName,ERR005,vInsertarIncidencia,
                                 "pAboRent->pConcTar");
                        return(FALSE                  );
                    }
                    memcpy (&pRoa->pConcTar[pRoa->iNumConcTar],
                            &stConcTar,sizeof(CONCTAR));
                    stEstProc.iNumConcRoaming++        ;
                    stEstProc.dTotImpRoaming +=
                    stConcTar.dImpConsumido  ;
                    pRoa->iNumConcTar++                ;
                }

            }/* fin if bRes ... */

        }/* fin if Producto ... */
        iCont++;

    }/* fin While ... */
    vDTrazasLog (szExeName,
                 "\n\t\t* Estadisticas de Trafico para el Abonado :  [%ld]"
                 "\n\t\t=>Conceptos Trafico Roaming                  [%d] "
                 "\n\t\t=>Importe Total Trafico Roaming              [%f] ",LOG04,
                 pRoa->lNumAbonado     ,stEstProc.iNumConcRoaming  ,
                 stEstProc.dTotImpRoaming);
    if( stEstProc.dTotImpRoaming <= 0.0 )
    {
        bRes = FALSE;

        vDTrazasLog (szExeName,"\n\t* No Hay Conceptos a Facturar\n",LOG03);
        iDError (szExeName,ERR039,vInsertarIncidencia);
    }
    return(bRes);
}/************************ Final bfnLeeConceptosRoamingVis *******************/


/*****************************************************************************/
/*                         funcion : bLeeAcumFraSoc                          */
/* -Funcion que carga la informacion de consumo de la tabla Ta_Acum%FraSoc   */
/*  (Tarifas Locales).                                                       */
/* -Valores Retorno: Error->FALSE, !Error->TRUE                              */
/*****************************************************************************/
static BOOL bfnLeeAcumFraSoc( CONCEP *pstConcep, long lNumAbonado,int iCodProducto)
{
    BOOL   bRes           = FALSE;
    char   szNomTabla [20]= ""   ;
    char   szOperaOra [40]= ""   ;

    PLANTARIF  lstPlanTarif; /* estructura para info planes tarif */
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhRowid[19];
    static long   lhCodCliente  =0 ;
    static long   lhNumAbonado  =0 ;
    static long   lhCodCiclFact    ;
    static int    ihCodTarificacion;
    static double dhImpConsumido   ;
    static long   lhSegConsumido   ;
    static short  shIndEntSal      ;
    static short  shIndDestino     ;
    char   szCodServicio[6]        ;/* EXEC SQL VAR szCodServicio     IS STRING(6); */ 

    char   szhCodPlanTarif[4]      ;/* EXEC SQL VAR szhCodPlanTarif   IS STRING(4); */ 

    char   szhCodTipRelacion[6]    ;/* EXEC SQL VAR szhCodTipRelacion IS STRING(6); */ 

    static short  shCodProducto    ;
    static short  shValorCero      ;
    static short  i_szhCodPlanTarif;
    static int    ihCodOperador =0 ;
    /* EXEC SQL END DECLARE SECTION; */ 


	memset (&lstPlanTarif, 0, sizeof(PLANTARIF));

    /* valores por defecto */
    sprintf (szhCodTipRelacion, "%s\0", "4");
    shCodProducto = 1;
    shValorCero   = 0;
	lhNumAbonado = lNumAbonado;
    vDTrazasLog (szExeName,
                 "\n\t\t* Parametros de Entrada Acumulados Trafico Local\n"
                 "\n\t\t=> Cod.Cliente     [%ld]"
                 "\n\t\t=> Num.Abonado     [%ld]"
                 , LOG05, stCliente.lCodCliente, lhNumAbonado);

   /*- Cursor para la suma de importes y segundos con las mismas condiciones -*/
   /*  nuevo campo a leer COD_SERVICIO NCONTRER 26-04-2002            */
    /* EXEC SQL DECLARE Cur_AcumAire CURSOR FOR
        SELECT  A.ROWID            ,
                COD_CICLFACT     ,
                IMP_CONSUMIDO    ,
                SEG_CONSUMIDO    ,
                IND_ENTSAL       ,
                IND_DESTINO      ,
                COD_FRANHORASOC  ,
                A.COD_SERVICIO   ,
                B.COD_PLANTARIF  ,
                A.COD_OPERADOR   
          FROM  TA_ACUMAIREFRASOC  A, GAD_SERVSUP_PLAN B
         WHERE  NUM_ABONADO     = :lhNumAbonado
           AND  COD_CICLFACT    > :shValorCero
           AND  COD_CLIENTE     = :lhCodCliente
           AND  NUM_PROCESO     = :shValorCero
           AND  B.COD_PRODUCTO  (+)= :shCodProducto
           AND  B.COD_SERVICIO  (+)= A.COD_SERVICIO
           AND  B.TIP_RELACION  (+)= :szhCodTipRelacion; */ 


    /* EXEC SQL DECLARE Cur_AcumAireLiq CURSOR FOR
        SELECT  IMP_CONSUMIDO    ,
                SEG_CONSUMIDO    ,
                IND_ENTSAL       ,
                IND_DESTINO      ,
                COD_FRANHORASOC  ,
                A.COD_SERVICIO   ,
                B.COD_PLANTARIF  ,
                A.COD_OPERADOR   
          FROM  TA_ACUMAIREFRASOC  A, GAD_SERVSUP_PLAN B
         WHERE  NUM_ABONADO     = :lhNumAbonado
           AND  COD_CLIENTE     = :lhCodCliente
           AND  NUM_PROCESO     = :shValorCero
           AND  B.COD_PRODUCTO  (+)= :shCodProducto
           AND  B.COD_SERVICIO  (+)= A.COD_SERVICIO
           AND  B.TIP_RELACION  (+)= :szhCodTipRelacion; */ 


    lhCodCliente      = stCliente.lCodCliente;
    lhNumAbonado      = lNumAbonado          ;
    lhCodCiclFact     = 0                    ;
    dhImpConsumido    = 0.0                  ;
    lhSegConsumido    = 0                    ;

    sprintf (szOperaOra, "Open->");

    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
        /* EXEC SQL OPEN Cur_AcumAireLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )379;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&shValorCero;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&shCodProducto;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhCodTipRelacion;
        sqlstm.sqhstl[4] = (unsigned long )6;
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


    else
        /* EXEC SQL OPEN Cur_AcumAire; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )414;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&shValorCero;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
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
        sqlstm.sqhstv[3] = (unsigned char  *)&shValorCero;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&shCodProducto;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szhCodTipRelacion;
        sqlstm.sqhstl[5] = (unsigned long )6;
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



    strcpy (szNomTabla,"Ta_AcumAireFraSoc");
    bRes = TRUE;

    if( !bRes )
    {
        iDError (szExeName,ERR003,vInsertarIncidencia,
                 iCodProducto);
        return(FALSE);
    }
    if( SQLCODE )
    {
        strcat (szOperaOra,szNomTabla);
        iDError (szExeName,ERR000,vInsertarIncidencia,szOperaOra,
                 szfnORAerror());
        return(FALSE);
    }
    strcpy (szOperaOra,"Fetch->") ;
    strcat (szOperaOra,szNomTabla);

    while( SQLCODE == SQLOK )
    {
        if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
            /* EXEC SQL FETCH Cur_AcumAireLiq INTO :dhImpConsumido ,
            :lhSegConsumido ,
            :shIndEntSal    ,
            :shIndDestino   ,
            :ihCodTarificacion,
            :szCodServicio  ,
            :szhCodPlanTarif :i_szhCodPlanTarif,
            :ihCodOperador; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 8;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )453;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&shIndEntSal;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&shIndDestino;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihCodTarificacion;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szCodServicio;
            sqlstm.sqhstl[5] = (unsigned long )6;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhCodPlanTarif;
            sqlstm.sqhstl[6] = (unsigned long )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&i_szhCodPlanTarif;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&ihCodOperador;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
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


        else
            /* EXEC SQL FETCH Cur_AcumAire INTO :szhRowid      ,    :lhCodCiclFact,
            :dhImpConsumido,    :lhSegConsumido,
            :shIndEntSal   ,    :shIndDestino,
            :ihCodTarificacion, :szCodServicio,
            :szhCodPlanTarif :i_szhCodPlanTarif,
            :ihCodOperador; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )500;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclFact;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&shIndEntSal;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&shIndDestino;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&ihCodTarificacion;
            sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szCodServicio;
            sqlstm.sqhstl[7] = (unsigned long )6;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)szhCodPlanTarif;
            sqlstm.sqhstl[8] = (unsigned long )4;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&i_szhCodPlanTarif;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&ihCodOperador;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
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



        if( SQLCODE == SQLOK )
        {
            if( bBusca_Ciclo(lhCodCiclFact))
            {
			    vDTrazasLog (szExeName,"szhCodPlanTarif [%s]", LOG05,szhCodPlanTarif);
            	if (i_szhCodPlanTarif == ORA_NULL ||(strcmp (szhCodPlanTarif, " ")==0))
            	{
					vDTrazasLog (szExeName,"no viene Plan tarif", LOG05);

            		if (!bBuscaPlanTarifAbon (lNumAbonado,szhCodPlanTarif))
            		{
            			iDError (szExeName,ERR000,vInsertarIncidencia,"Busca Plan Tarif Abonado",
                             szfnORAerror ());
                    	return (FALSE);
            		}
            	}
            	
                if (!bFindPlanTarif (1, szhCodPlanTarif, &lstPlanTarif))
                {
                    iDError (szExeName,ERR000,vInsertarIncidencia,"Select=> Ta_PlanTarif",
                             szfnORAerror ());
                    return (FALSE);
                }

                /* Busca codigo de tarificacion */
                if( bfnBuscaAcumCodTarif(pstConcep, lNumAbonado, ihCodTarificacion,
                                         lhSegConsumido, dhImpConsumido, 0, shIndEntSal,shIndDestino, 1,
                                         szCodServicio, szhCodPlanTarif, lstPlanTarif.szCod_Unidad, lstPlanTarif.lNumUnidades,ihCodOperador) )
                {
                    /* EXEC SQL UPDATE TA_ACUMAIREFRASOC
                    SET NUM_PROCESO = :stStatus.IdPro
                                      WHERE ROWID = :szhRowid; */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 10;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.stmt = "update TA_ACUMAIREFRASOC  set NUM_PROCESO\
=:b0 where ROWID=:b1";
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )555;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)256;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqhstv[0] = (unsigned char  *)&(stStatus.IdPro);
                    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


                }
            }
        }
    }/* fin while */
    if( SQLCODE != 0 && SQLCODE != SQLNOTFOUND )
    {
        iDError(szExeName,ERR000,vInsertarIncidencia,szOperaOra,szfnORAerror());
        return(FALSE);
    }
    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
    {
        /* EXEC SQL CLOSE Cur_AcumAireLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )578;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    else
    {
        /* EXEC SQL CLOSE Cur_AcumAire; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )593;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    strcpy (szOperaOra,szNomTabla);

    if( SQLCODE != 0 )
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 szOperaOra,szfnORAerror());
    return(SQLCODE != 0)?FALSE:TRUE;
}/************************* Final bLeeAcumFraSoc *****************************/

/*****************************************************************************/
/*                        funcion : bLeeAcumOper                             */
/* -Funcion que carga los importes , segundos y pulsos de las llamadas de    */
/*  larga distancia (Ta_AcumOper).                                           */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
static BOOL bfnLeeAcumOper (CONCEP *pstConcep, long lNumAbonado)
{
    PLANTARIF  lstPlanTarif; /* estructura para info planes tarif */
    char          szCodServicio[6] ;
    OPERSERVESP lstOperServEsp ; /* estructura para info Operadores Esp. */
    char          szCodUnidad[6] ;
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhRowid[19];
    static long   lhCodCliente     ;
    static long   lhNumAbonado     ;
    static long   lhCodCiclFact    ;
    static double dhImpConsumido   ;
    static long   lhSegConsumido   ;
    static long   lhNumPulsos      ;
    static int    ihCodOperador    ;
    char          szhCodPlanTarif[4] ;/* EXEC SQL VAR szhCodPlanTarif IS STRING(4); */ 

    static short  i_szhCodPlanTarif;
    static long   lhValorCero	   ;
    /* EXEC SQL END DECLARE SECTION; */ 


	memset (&lstPlanTarif, 0, sizeof(PLANTARIF));
	
    vDTrazasLog (szExeName,
                 "\n\t\t* Parametros de Entrada Acumulados Larga Distancia"
                 "\n\t\t=> Cod.Cliente     [%ld]"
                 "\n\t\t=> Num.Abonado     [%ld]"
                 ,LOG05,stCliente.lCodCliente, lNumAbonado);

    strcpy(szCodServicio, " ");

    /* EXEC SQL DECLARE Cur_AcumOperLiq CURSOR FOR
        SELECT /o+ index (TA_ACUMOPER PK_TA_ACUMOPER) o/
                IMP_CONSUMIDO, SEG_CONSUMIDO, NUM_PULSOS, COD_OPERADOR, TRIM(COD_PLANTARIF)
          FROM  TA_ACUMOPER
         WHERE  NUM_ABONADO   = :lhNumAbonado
           AND  COD_CLIENTE   = :lhCodCliente
           AND  NUM_PROCESO   = :lhValorCero; */ 


    /*- Cursor para la suma de importes,segundos y pulsos -*/
    /* EXEC SQL DECLARE Cur_AcumOper CURSOR FOR
        SELECT /o+ index (TA_ACUMOPER PK_TA_ACUMOPER) o/
                /oROWID, COD_CICLFACT, IMP_CONSUMIDO, SEG_CONSUMIDO, AFGS - 79605o/
                ROWID, COD_CICLFACT, IMP_CONSUMIDO, DECODE(SEG_ADICIONALES,0, SEG_CONSUMIDO, SEG_ADICIONALES) AS SEG_CONSUMIDO,
                NUM_PULSOS, COD_OPERADOR, TRIM(COD_PLANTARIF)
          FROM  TA_ACUMOPER
         WHERE  NUM_ABONADO   = :lhNumAbonado
           AND  COD_CICLFACT  > :lhValorCero
           AND  COD_CLIENTE   = :lhCodCliente
           AND  NUM_PROCESO   = :lhValorCero; */ 




    lhCodCliente      = stCliente.lCodCliente;
    lhNumAbonado      = lNumAbonado          ;
    dhImpConsumido    = 0.0                  ;
    lhSegConsumido    = 0                    ;
    lhNumPulsos       = 0                    ;
	lhValorCero		  = 0					 ;
    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
    {
        /* EXEC SQL OPEN Cur_AcumOperLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )608;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&lhValorCero;
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
    else
    {
        /* EXEC SQL OPEN Cur_AcumOper   ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0011;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )635;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhValorCero;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
        sqlstm.sqhstv[3] = (unsigned char  *)&lhValorCero;
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
    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ta_AcumOper",
                 szfnORAerror());
        return(FALSE);
    }
    while( SQLCODE == 0 )
    {
        if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
        {
            /* EXEC SQL FETCH Cur_AcumOperLiq
            INTO :dhImpConsumido, :lhSegConsumido,
                 :lhNumPulsos   , :ihCodOperador, :szhCodPlanTarif :i_szhCodPlanTarif; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )666;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhNumPulsos;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&ihCodOperador;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szhCodPlanTarif;
            sqlstm.sqhstl[4] = (unsigned long )4;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&i_szhCodPlanTarif;
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
            /* EXEC SQL FETCH Cur_AcumOper
            INTO :szhRowid, :lhCodCiclFact, :dhImpConsumido,
                 :lhSegConsumido, :lhNumPulsos  , :ihCodOperador, :szhCodPlanTarif :i_szhCodPlanTarif; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )701;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclFact;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&lhNumPulsos;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&ihCodOperador;
            sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)szhCodPlanTarif;
            sqlstm.sqhstl[6] = (unsigned long )4;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&i_szhCodPlanTarif;
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
        if( SQLCODE == 0 )
        {
            if( bBusca_Ciclo(lhCodCiclFact))
            {
			    vDTrazasLog (szExeName,"szhCodPlanTarif [%s]", LOG05,szhCodPlanTarif);
            	if (i_szhCodPlanTarif == ORA_NULL ||(strcmp (szhCodPlanTarif, " ")==0))
            	{
            		if (!bBuscaPlanTarifAbon (lNumAbonado,szhCodPlanTarif))
            		{
            			iDError (szExeName,ERR000,vInsertarIncidencia,"Busca Plan Tarif Abonado",
                             szfnORAerror ());
                    	return (FALSE);
            		}
            	}
                if (!bfnFindOperServEsp (ihCodOperador, &lstOperServEsp))
                {
                	sprintf (szCodUnidad, "T"); /* default es voz */
                }
                else 
                {
        			strcpy (szCodUnidad, lstOperServEsp.szCodUnidad);
				}

                if (!bFindPlanTarif (1, szhCodPlanTarif, &lstPlanTarif))
                {
                    iDError (szExeName,ERR000,vInsertarIncidencia,"Select=> Ta_PlanTarif",
                             szfnORAerror ());
                    return (FALSE);
                }

                if (bfnBuscaAcumCodTarif (pstConcep, lNumAbonado, ihCodOperador
                                      	, lhSegConsumido, dhImpConsumido
                                      	, lhNumPulsos, 0, 0, 2, szCodServicio
                                      	, szhCodPlanTarif, szCodUnidad
                                      	, lstPlanTarif.lNumUnidades, ihCodOperador))
				{
	                /* EXEC SQL UPDATE TA_ACUMOPER
    	            SET NUM_PROCESO = :stStatus.IdPro
        	        WHERE ROWID       = :szhRowid; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 10;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.stmt = "update TA_ACUMOPER  set NUM_PROCESO=:b0 wher\
e ROWID=:b1";
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )744;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)256;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqhstv[0] = (unsigned char  *)&(stStatus.IdPro);
                 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


				}
            }
        }
    }/* fin while */
    if( SQLCODE != 0 && SQLCODE != SQLNOTFOUND )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch->Ta_AcumOper",
                 szfnORAerror());
        return(FALSE);
    }
    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
    {
        /* EXEC SQL CLOSE Cur_AcumOperLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )767;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    else
    {
        /* EXEC SQL CLOSE Cur_AcumOper   ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )782;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    if( SQLCODE != 0 )
        iDError (szExeName,ERR000,vInsertarIncidencia,"Close->Ta_AcumOper",
                 szfnORAerror());
    return(SQLCODE != 0)?FALSE:TRUE;
}/*********************** Final bLeeAcumOper *********************************/

/*****************************************************************************/
/*                      funcion : bLeeAcumLlamadasRoa                        */
/* -Funcion que carga importes y segundos de la tabla Ta_AcumLlamadasRoa     */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
static BOOL bfnLeeAcumLlamadasRoa (CONCEP *pstConcep, long lNumAbonado)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhRowid[19];
    static long   lhCodCliente     ;
    static long   lhNumAbonado     ;
    static long   lhCodCiclFact    ;
    static int    ihCodTarificacion;
    static double dhImpConsumido   ;
    static long   lhSegConsumido   ;
    static long   lhValorCero	   ;
    /* EXEC SQL END DECLARE SECTION; */ 

    char    szCodServicio[6]       ;

    static double dImpConsumido   = 0.0 ;
	strcpy(szCodServicio, " "); /* se fuerza el codigo de servicio = " "*/

    vDTrazasLog (szExeName,
                 "\n\t\t* Parametros de Entrada Ta_AcumLlamadasRoa\n"
                 "\n\t\t=> Cod.Cliente [%ld]"
                 "\n\t\t=> Num.Abonado [%ld]",LOG05,
                 stCliente.lCodCliente, lNumAbonado);

   /*- Cursor para la suma de importes,segundos y pulsos -*/
    /* EXEC SQL DECLARE Cur_AcumLlamadas CURSOR FOR
    	SELECT ROWID, COD_CICLFACT, IMP_CONSUMIDO, SEG_CONSUMIDO, COD_OPERADOR
    	  FROM TA_ACUMLLAMADASROA
    	 WHERE NUM_ABONADO   = :lhNumAbonado
           AND COD_CICLFACT  > :lhValorCero
           AND COD_CLIENTE   = :lhCodCliente
           AND NUM_PROCESO   = :lhValorCero; */ 


    /* EXEC SQL DECLARE Cur_AcumLlamadasLiq CURSOR FOR
     	SELECT /o+ index (TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA) o/
    			IMP_CONSUMIDO,SEG_CONSUMIDO, COD_OPERADOR
    	  FROM TA_ACUMLLAMADASROA
    	 WHERE NUM_ABONADO   = :lhNumAbonado
           AND COD_CLIENTE   = :lhCodCliente
           AND NUM_PROCESO   = :lhValorCero; */ 


    lhCodCliente      = stCliente.lCodCliente;
    lhNumAbonado      = lNumAbonado;
    dhImpConsumido    = 0.0                  ;
    lhSegConsumido    = 0                    ;
	lhValorCero 	  = 0					 ;

    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
    {
        /* EXEC SQL OPEN Cur_AcumLlamadasLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0014;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )797;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&lhValorCero;
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
    else
    {
        /* EXEC SQL OPEN Cur_AcumLlamadas   ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0013;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )824;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&lhValorCero;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
        sqlstm.sqhstv[3] = (unsigned char  *)&lhValorCero;
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
    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ta_AcumLlamadasRoa",
                 szfnORAerror());
        return(FALSE);
    }
    while( SQLCODE == 0 )
    {
        if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
        {
            /* EXEC SQL FETCH Cur_AcumLlamadasLiq
            INTO :dhImpConsumido,
            :lhSegConsumido,
            :ihCodTarificacion; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )855;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&ihCodTarificacion;
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


        }
        else
        {
            /* EXEC SQL FETCH Cur_AcumLlamadas
            INTO :szhRowid, :lhCodCiclFact,
            :dhImpConsumido, :lhSegConsumido,
            :ihCodTarificacion; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )882;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclFact;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&dhImpConsumido;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&lhSegConsumido;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihCodTarificacion;
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


        }
        if( SQLCODE == 0 )
        {
            /*  Conversion de Dolar a Peso de Llamadas Roaming */
            /***************************************************/
            dImpConsumido = 0.0;
            if( dhImpConsumido > 0.0 )                /*  Tiene Trafico Roaming  */
            {
                if( !bConverMoneda (stDatosGener.szCodDollar   ,
                                    stDatosGener.szCodMoneFact ,
                                    stCiclo.szFecEmision       ,
                                    &dhImpConsumido             ,
                                    stProceso.iCodTipDocum) )

                    return(FALSE);

                dImpConsumido = fnCnvDouble( dhImpConsumido , USOFACT);
            }
            if( bBusca_Ciclo(lhCodCiclFact))
            {
                if( bfnBuscaAcumCodTarif(pstConcep, lNumAbonado,
                                         ihCodTarificacion, lhSegConsumido,
                                         dImpConsumido, 0, 0, 0,3,szCodServicio, " ", " ", 0,ihCodTarificacion) )
                {
                    /* EXEC SQL UPDATE TA_ACUMLLAMADASROA
                    SET NUM_PROCESO = :stStatus.IdPro
                                      WHERE ROWID = :szhRowid; */ 

{
                    struct sqlexd sqlstm;
                    sqlstm.sqlvsn = 12;
                    sqlstm.arrsiz = 10;
                    sqlstm.sqladtp = &sqladt;
                    sqlstm.sqltdsp = &sqltds;
                    sqlstm.stmt = "update TA_ACUMLLAMADASROA  set NUM_PROCES\
O=:b0 where ROWID=:b1";
                    sqlstm.iters = (unsigned int  )1;
                    sqlstm.offset = (unsigned int  )917;
                    sqlstm.cud = sqlcud0;
                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                    sqlstm.sqlety = (unsigned short)256;
                    sqlstm.occurs = (unsigned int  )0;
                    sqlstm.sqhstv[0] = (unsigned char  *)&(stStatus.IdPro);
                    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


                }
            }
        }
    }/* fin while */

    if( SQLCODE != 0 && SQLCODE != SQLNOTFOUND )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Fetch->Ta_AcumLlamadasRoa",szfnORAerror());
        return(FALSE);
    }


    if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion )
    {
        /* EXEC SQL CLOSE Cur_AcumLlamadasLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )940;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    else
    {
        /* EXEC SQL CLOSE Cur_AcumLlamadas   ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )955;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    }
    if( SQLCODE != 0 )
        iDError (szExeName,ERR000,vInsertarIncidencia,
                 "Close->Ta_AcumLlamadasRoa",szfnORAerror());

    vDTrazasLog (szExeName,
                 "\n\t\t* Salida de bfnLeeAcumLlamadasRoa\n"
                 "\n\t\t=> Cod.Cliente [%ld]"
                 "\n\t\t=> Cod.CiclFact[%ld]"
                 "\n\t\t=> Num.Abonado [%ld]"
                 ,LOG05, stCliente.lCodCliente
                 ,stCiclo.lCodCiclFact, lNumAbonado );

    return(SQLCODE != 0)?FALSE:TRUE;
}/**************************** bfnLeeAcumLlamadasRoa *************************/

/*****************************************************************************/
/*                      funcion : bfnLeeAcumRoaming                          */
/* -Funcion que acumula los Importes (Local y Larga Distancia) y segundos de */
/*  Roaming Visitante.                                                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static int bfnLeeAcumRoaming (CONCTAR *pConcTar,
                          int      iCodTarificacion)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static long   lhNumAbonado ;
    static long   lhNumEstaDia ;
    static long   lhSegConsAire;
    static long   lhSegConsOper;
    static double dhImpConsAire;
    static double dhImpConsOper;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL DECLARE Cur_Roa CURSOR FOR
    SELECT /o+ index (TA_ACUMROAMING PK_TA_ACUMROAMING) o/
    IMP_CONSAIRE,
    IMP_CONSOPER,
    SEG_CONSAIRE,
    SEG_CONSOPER
    FROM   TA_ACUMROAMING
    WHERE  NUM_ABONADO = :lhNumAbonado
                         AND  NUM_ESTADIA = :lhNumEstaDia
                         AND  NUM_PROCESO = 0; */ 


    vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada Ta_AcumRoaming"
                 "\n\t\t=> Num.Abonado      [%ld]"
                 "\n\t\t=> Num.EstaDia      [%ld]",LOG05,
                 pConcTar->lNumAbonado,pConcTar->lNumEstaDia);

    lhNumAbonado = pConcTar->lNumAbonado;
    lhNumEstaDia = pConcTar->lNumEstaDia;

    /* EXEC SQL OPEN Cur_Roa; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0016;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )970;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhNumAbonado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhNumEstaDia;
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


    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ta_AcumRoaming",
                 szfnORAerror());
        return(FALSE          );
    }
    while( SQLCODE == SQLOK )
    {
        dhImpConsAire = 0.0;
        dhImpConsOper = 0.0;
        lhSegConsAire = 0  ;
        lhSegConsOper = 0  ;

        /* EXEC SQL FETCH Cur_Roa INTO :dhImpConsAire,
        :dhImpConsOper,
        :lhSegConsAire,
        :lhSegConsOper; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )993;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&dhImpConsAire;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&dhImpConsOper;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhSegConsAire;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&lhSegConsOper;
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


        if( SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Fetch->Ta_AcumRoaming",szfnORAerror());
            return(FALSE                                   );
        }
        else
        {
            if( SQLCODE == SQLOK )
            {
                /* Llamadas Locales */
                if( iCodTarificacion == 0 )
                {
                    pConcTar->dImpConsumido += dhImpConsAire;
                    pConcTar->lSegConsumido += lhSegConsAire;
                }
                /* Llamadas Larga Distancia */
                else if( iCodTarificacion == 1 )
                {
                    pConcTar->dImpConsumido += dhImpConsOper;
                    pConcTar->lSegConsumido += lhSegConsOper;
                }

            }
        }
    }/* fin while */

    if( SQLCODE == SQLNOTFOUND )
    {
        if( !bConverMoneda (stDatosGener.szCodDollar   ,
                            stDatosGener.szCodMoneFact ,
                            stCiclo.szFecEmision       ,
                            &pConcTar->dImpConsumido   ,
                            stProceso.iCodTipDocum) )
            return(FALSE);

        pConcTar->dImpConsumido = fnCnvDouble( pConcTar->dImpConsumido,USOFACT);
        /* EXEC SQL CLOSE Cur_Roa; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1024;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if( SQLCODE )
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                     "Close->Fa_AcumRoaming",szfnORAerror());
            return(FALSE                                  );
        }
    }
    return(1);
}/************************ Final bfnLeeAcumRoaming ***************************/

/*****************************************************************************/
/*                        funcion : bEscribeAnoTar                           */
/*****************************************************************************/
static BOOL bfnEscribeAnoTar(CONCTAR *pReg)
{
    stAnomProceso.lNumProceso  = stStatus.IdPro        ;
    stAnomProceso.lCodCliente  = stCliente.lCodCliente ;
    stAnomProceso.iCodConcepto =  pReg->iCodFacturacion;
    stAnomProceso.lCodCiclFact = stCiclo.lCodCiclFact  ;
    stAnomProceso.iCodProducto = pReg->iCodProducto    ;

    strcpy (stAnomProceso.szDesProceso,"PreBilling de Tarificacion");

    return(1);
}/************************* Final bEscribeAnoTar ****************************/

/*-------------------------------------------------------------------------- */
/*  bEMTarificacion (void)                                                   */
/*     Observacion    : La aplicacion de Plan Optimo solo ocurre en la Factu-*/
/*         racion de Ciclo y solo si el Plan Tarifario del Abonado coincide  */
/*         con el Plan Tarifario (Optimo) de Fa_DatosGener, ademas de depen- */
/*         de los minutos  Consumidos.                                       */
/*     Valores Retorno: FALSE - Error                                        */
/*                      TRUE  - Ningun Error                                 */
/*-------------------------------------------------------------------------- */
BOOL bfnEMTarificacion (int iTipoFact)
{
    int    iInd1         = 0    ;
    int    iInd2         = 0    ;
    int    i             = 0    ;
    int    iCarrier      = 0    ;
    int    iNumAbonados  = 0    ;
    int    iNumConcTar   = 0    ;
    BOOL   bError        = FALSE;
    double dTotMinLocales= 0    ; /* Minutos Consumidos en Llamadas Locales */

    ABORENT   *pTmpAboRent   = (ABORENT   *)NULL;
    ABONTAR   *pTmpAbon      = (ABONTAR   *)NULL;
    ABOROAVIS *pTmpAboRoaVis = (ABOROAVIS *)NULL;
    CONCTAR   *pTmpConcTar   = (CONCTAR   *)NULL;

    if( iTipoFact != FACT_ROAMINGVIS && iTipoFact != FACT_RENTAPHONE )
    {
        vDTrazasLog (szExeName,
                     "\n\t\t* Paso a Prefactura TARIFICACION \n"
                     "\t\t=> Cliente        [%ld]\n"
                     "\t\t=> Ciclo Factura  [%ld]\n"
                     "\t\t=> Numero Abonados[%d] \n",LOG05,stCliente.lCodCliente,
                     stCiclo.lCodCiclFact,stCliente.iNumAbonados);
        iNumAbonados = stCliente.iNumAbonados;

        if( iTipoFact == FACT_CICLO && (!strcmp (stCliente.szTipPlanTarif,"E") ||
                                        !strcmp (stCliente.szTipPlanTarif,"H") ) )
            dTotMinLocales = (double)stPlanOptimo.lSegTotLocal/60;
    }
    else if( iTipoFact == FACT_RENTAPHONE )
    {
        vDTrazasLog (szExeName,
                     "\n\t\t* Paso a PreFactura TRAFICO Local y Larga Distancia"
                     "\n\t\t=> Cod.Cliente [%ld]"
                     "\n\t\t=> Num.Abonado [%ld]"
                     "\n\t\t=> Num.Alquiler[%ld]",LOG05,
                     stCliente.lCodCliente             ,
                     stCliente.pAboRent[0].lNumAbonado ,
                     stCliente.pAboRent[0].lNumAlquiler);
        iNumAbonados = 1;
    }
    else if( iTipoFact == FACT_ROAMINGVIS )
    {
        vDTrazasLog (szExeName,
                     "\n\t\t* Paso a PreFactura TRAFICO Roaming Visitante"
                     "\n\t\t=> Cod.Cliente [%ld]"
                     "\n\t\t=> Num.Abonado [%ld]"
                     "\n\t\t=> Num.EstaDia [%ld]",LOG05,
                     stCliente.lCodCliente             ,
                     stCliente.pAboRoaVis->lNumAbonado ,
                     stCliente.pAboRoaVis->lNumEstaDia);
        iNumAbonados = 1;
    }
    i = stPreFactura.iNumRegistros;

    for( iInd1=0;iInd1<iNumAbonados;iInd1++ )
    {
        if( iTipoFact != FACT_ROAMINGVIS && iTipoFact != FACT_RENTAPHONE )
        {
            pTmpAbon    = (ABONTAR *)&stCliente.pAbonados[iInd1];
            iNumConcTar = stCliente.pAbonados[iInd1].iNumConcTar;

            if( !strcmp (stCliente.szTipPlanTarif, "I") )
                dTotMinLocales =
                (double)dfnTotMinutosLocales (&stCliente.pAbonados[iInd1]);

            vDTrazasLog (szExeName,"\t\t* Abonado          : [%ld]\n"
                         "\t\t* Conceptos Tarif. : [%d] \n",LOG04,
                         pTmpAbon->lNumAbonado,pTmpAbon->iNumConcTar);
        }
        else if( iTipoFact == FACT_RENTAPHONE )
        {
            pTmpAboRent = (ABORENT *)stCliente.pAboRent     ;
            iNumConcTar =  stCliente.pAboRent[0].iNumConcTar;
            vDTrazasLog (szExeName,"\n\t\t* Abonado          : [%ld]"
                                   "\n\t\t* Conceptos Tarif. : [%d] ",LOG04,
                                   stCliente.pAboRent[0].lNumAbonado ,
                                   iNumConcTar);
        }
        else if( iTipoFact == FACT_ROAMINGVIS )
        {
            pTmpAboRoaVis = (ABOROAVIS *)stCliente.pAboRoaVis;
            iNumConcTar   = stCliente.pAboRoaVis->iNumConcTar;

            vDTrazasLog (szExeName,"\n\t\t* Abonado          : [%ld]"
                                   "\n\t\t* Conceptos Tarif. : [%d] ",LOG04,
                                   stCliente.pAboRoaVis->lNumAbonado ,
                                   iNumConcTar);

        }

        for( iInd2=0;iInd2<iNumConcTar;iInd2++ )
        {
            pTmpConcTar =
                (iTipoFact == FACT_RENTAPHONE)?
                (CONCTAR *)&pTmpAboRent->pConcTar  [iInd2]:
                (iTipoFact == FACT_ROAMINGVIS)?
                (CONCTAR *)&pTmpAboRoaVis->pConcTar[iInd2]:
                (CONCTAR *)&pTmpAbon->pConcTar[iInd2]     ;

            vDTrazasLog (szExeName,"\t\t* Concepto  [%d]\n",LOG06,
                         pTmpConcTar->iCodFacturacion);

            if( (pTmpConcTar->dImpConsumido >= 0.01) || (pstParamGener.iConsConcTrafico == 1) )
            {
                if( stPreFactura.iNumRegistros >= MAX_CONCFACTUR )
                {
                    iDError (szExeName,ERR035,vInsertarIncidencia);
                    return(FALSE);
                }
                stPreFactura.A_PFactura.bOptTrafico [i] = TRUE                 ;
                stPreFactura.A_PFactura.lNumProceso [i] = stStatus.IdPro       ;
                stPreFactura.A_PFactura.lCodCliente [i] = stCliente.lCodCliente;
                stPreFactura.A_PFactura.iCodConcepto[i] = pTmpConcTar->iCodFacturacion;

                strcpy (stPreFactura.A_PFactura.szDesConcepto [i], pTmpConcTar->szDesConcepto);

                if( !bGetMaxColPreFa (stPreFactura.A_PFactura.iCodConcepto[i],
                                      &stPreFactura.A_PFactura.lColumna[i]) )
                    return(FALSE);

                stPreFactura.A_PFactura.iCodProducto[i] = pTmpConcTar->iCodProducto   ;

                strcpy (stPreFactura.A_PFactura.szFecEfectividad [i], szSysDate);

                if( stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion||
                    stProceso.iCodTipDocum == stDatosGener.iCodRentaPhone ||
                    stProceso.iCodTipDocum == stDatosGener.iCodRoamingVis )
                    strcpy (stPreFactura.A_PFactura.szFecValor [i],
                            szSysDate);
                else
                    strcpy (stPreFactura.A_PFactura.szFecValor [i],
                            stCiclo.szFecHastaLlam);
                            /* stCiclo.szFecEmision); */

                if( iTipoFact == FACT_CICLO && pTmpConcTar->iIndTabla == FRASOC )
                {
                    vfnAplicaPlanOptimo (pTmpConcTar, dTotMinLocales);
                }

                stPreFactura.A_PFactura.dImpConcepto  [i] =
                pTmpConcTar->dImpConsumido;

                stPreFactura.A_PFactura.dImpFacturable[i] =
                fnCnvDouble(stPreFactura.A_PFactura.dImpConcepto [i], USOFACT) ;

                stPreFactura.A_PFactura.dImpMontoBase [i] = 0.0       ;
                stPreFactura.A_PFactura.lSegConsumido [i] =
                pTmpConcTar->lSegConsumido;

                stPreFactura.A_PFactura.lCodPlanCom   [i] =
                stCliente.lCodPlanCom  ;
                stPreFactura.A_PFactura.iIndFactur    [i] =
                pTmpAbon->iIndFactur   ;
                stPreFactura.A_PFactura.iCodCatImpos  [i] =
                stCliente.iCodCatImpos ;
                stPreFactura.A_PFactura.iCodPortador  [i] =
                pTmpConcTar->iCodOperador;
                stPreFactura.A_PFactura.iIndEstado    [i] = EST_NORMAL;
                stPreFactura.A_PFactura.lNumUnidades  [i] = 1         ;
                stPreFactura.A_PFactura.iCodTipConce  [i] =
                pTmpConcTar->iCodTipConce;

                stPreFactura.A_PFactura.lCodCiclFact  [i] =
                stCiclo.lCodCiclFact   ;
                stPreFactura.A_PFactura.iCodConceRel  [i] = 0         ;
                stPreFactura.A_PFactura.lColumnaRel   [i] = 0         ;
                stPreFactura.A_PFactura.lNumAbonado   [i] =
                pTmpConcTar->lNumAbonado;

                strcpy (stPreFactura.A_PFactura.szCodRegion   [i],
                        stCliente.szCodRegion   );
                strcpy (stPreFactura.A_PFactura.szCodProvincia[i],
                        stCliente.szCodProvincia);
                strcpy (stPreFactura.A_PFactura.szCodCiudad   [i],
                        stCliente.szCodCiudad   );
                strcpy (stPreFactura.A_PFactura.szCodModulo   [i], "TA");
                strcpy (stPreFactura.A_PFactura.szCodMoneda   [i],
                        pTmpConcTar->szCodMoneda);

                stPreFactura.A_PFactura.szNumTerminal[i][0] = 0;
                stPreFactura.A_PFactura.szNumSerieMec[i][0] = 0;
                stPreFactura.A_PFactura.szNumSerieLe [i][0] = 0;

                stPreFactura.A_PFactura.lCapCode       [i] = ORA_NULL;
                stPreFactura.A_PFactura.iFlagImpues    [i] = 0       ;
                stPreFactura.A_PFactura.iFlagDto       [i] =
                (stPreFactura.A_PFactura.iCodTipConce[i] ==CARRIER)?0:1;

                if( !iCarrier &&
                    stPreFactura.A_PFactura.iCodTipConce [i] == CARRIER )
                    iCarrier = 1;

                stPreFactura.A_PFactura.fPrcImpuesto   [i] =
                (stPreFactura.A_PFactura.iCodTipConce[i] ==IMPUESTO)?
                stDatosGener.fPctIva:0.0                          ;

                stPreFactura.A_PFactura.dValDto        [i] = 0.0     ;
                stPreFactura.A_PFactura.iTipDto        [i] = 0       ;
                stPreFactura.A_PFactura.lNumVenta      [i] = 0       ;
                stPreFactura.A_PFactura.lNumTransaccion[i] = 0       ;
                stPreFactura.A_PFactura.iMesGarantia   [i] = 0       ;
                stPreFactura.A_PFactura.iIndAlta       [i] = 0       ;
                stPreFactura.A_PFactura.iIndSuperTel   [i] = 0       ;
                stPreFactura.A_PFactura.iNumPaquete    [i] = 0       ;
                stPreFactura.A_PFactura.iIndCuota      [i] = 0       ;
                stPreFactura.A_PFactura.iNumCuotas     [i] = 0       ;
                stPreFactura.A_PFactura.iOrdCuota      [i] = 0       ;

                /* TMC-04079 */
                strcpy( stPreFactura.A_PFactura.szCodPlanTarif [i], pTmpConcTar->szCodPlanTarif );
                strcpy( stPreFactura.A_PFactura.szCod_Unidad   [i], pTmpConcTar->szCod_Unidad  );
                stPreFactura.A_PFactura.lhNumUniFree    [i] =   pTmpConcTar->lhNumUniFree   ;

                stPreFactura.A_PFactura.ihCodOperador   [i] = pTmpConcTar->iCodOperador ;

                vPrintRegInsert (i,"Trafico",bError);
                i++                                 ;

            }/* fin if CodAnomalia ... */
            else
            {
                if( !bfnEscribeAnoTar (pTmpConcTar) )
                    return(FALSE);
            }

        }/* fin for iInd2 ... */

    }/* fin for iInd1 ... */

    stPreFactura.iNumRegistros = i;

    if( iCarrier )
        vfnRelacionCarrier ();

    return(1);
}/*********************** Final bEMTarificacion ******************************/

/*****************************************************************************/
/*                            funcion : vfnRelacionCarrier                   */
/*****************************************************************************/
static void vfnRelacionCarrier ()
{
    int i = 0, j = 0;

    for( i=0;i<stPreFactura.iNumRegistros;i++ )
    {
        if( stPreFactura.A_PFactura.iFlagImpues [i] == 0     &&
            stPreFactura.A_PFactura.iCodTipConce[i] == CARRIER )
        {
            for( j=0;j<stPreFactura.iNumRegistros;j++ )
            {
                if( stPreFactura.A_PFactura.iCodTipConce[j] == IMPUESTO &&
                    stPreFactura.A_PFactura.lNumAbonado [i] ==
                    stPreFactura.A_PFactura.lNumAbonado [j]             &&
                    stPreFactura.A_PFactura.iCodPortador[i] ==
                    stPreFactura.A_PFactura.iCodPortador[j] )
                {
                    stPreFactura.A_PFactura.iFlagImpues [i] =          1;
                    stPreFactura.A_PFactura.iCodConceRel[j] =
                    stPreFactura.A_PFactura.iCodConcepto[i];
                    stPreFactura.A_PFactura.lColumnaRel [j] =
                    stPreFactura.A_PFactura.lColumna    [i];
                    break;
                }
            }
        }
    }
}/***************************** Final vfnRelacionCarrier *********************/

/*****************************************************************************/
/*                            funcion : vFreeTarificacion                    */
/* -Funcion que libera la memoria de stCliente.pAbonados                     */
/*****************************************************************************/
void vfnFreeTarificacion(int iTipoFact)
{
    int iCont;

    if( iTipoFact == FACT_RENTAPHONE )
    {
        if( stCliente.pAboRent             != (ABORENT *)NULL &&
            stCliente.pAboRent[0].pConcTar != (CONCTAR *)NULL )
        {
            free (stCliente.pAboRent[0].pConcTar)              ;
            stCliente.pAboRent[0].pConcTar    = (CONCTAR *)NULL;
            stCliente.pAboRent[0].iNumConcTar = 0              ;
        }
        free (stCliente.pAboRent);
    }
    if( stCliente.pAbonados != (ABONTAR *)NULL )
    {
        for( iCont = 0;iCont < stCliente.iNumAbonados;iCont++ )
        {
            if( stCliente.pAbonados[iCont].pConcTar != (CONCTAR *)NULL )
            {
                free (stCliente.pAbonados[iCont].pConcTar)              ;
                stCliente.pAbonados[iCont].pConcTar    = (CONCTAR *)NULL;
                stCliente.pAbonados[iCont].iNumConcTar = 0              ;
            }
        }
        free(stCliente.pAbonados);
        stCliente.pAbonados = (ABONTAR *)NULL;
    }
    stCliente.iNumAbonados = 0;
}/************************ Final vFreeTarificacion ***************************/


/*****************************************************************************/
/*                        funcion : bfnCargaAbonadosCliente                    */
/* -Funcion que carga los abonados que estan en la tabla Ga_Infa%    que es- */
/*  tan en las distintas tablas de tarificacion .                            */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnCargaAbonadosCliente (CICLOCLI *pCicloCli,int iTipoFact)
{
    BOOL bRes = 1;

    vDTrazasLog (szExeName,"\n\t\t* Carga de Abonados con Trafico",LOG04);

    if( pCicloCli->iCodProducto == stDatosGener.iProdCelular )
        bRes =bfnCargaAbonadosCelular(pCicloCli,iTipoFact) ;
    else
    {
        vDTrazasLog (szExeName,
                     "\n\t\t* Productos en Proceso[%d] "
                     "\n\t\t* Productos Celular   [%d] ",LOG04,
                     pCicloCli->iCodProducto , stDatosGener.iProdCelular);

        iDError (szExeName,ERR003,vInsertarIncidencia,
                 pCicloCli->iCodProducto);
        bRes = FALSE;
    }
    return(bRes);
}/*********************** Final bfnCargaAbonadosCliente **********************/


/*****************************************************************************/
/*                        funcion : bfnCargaAbonadosCelular                  */
/* -Funcion que carga los abonados de Ga_InfacCel que esten en Ta_Acum% y que*/
/*  verifican las restricciones.                                             */
/* -Valores Retorno : SQLCODE                                                */
/*****************************************************************************/
static BOOL bfnCargaAbonadosCelular (CICLOCLI *pCicloCli,int iTipoFact)
{
    BOOL bRes = TRUE;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    static char* szhRowid         ; /* EXEC SQL VAR szhRowid          IS STRING(19); */ 

    static long  lhCodCliente     ;
    static long  lhNumAbonado     ;
    static long  lhCodCiclFact    ;
    int    iUno=1;
    int    iCero=0;
    /* EXEC SQL END DECLARE SECTION; */ 


    if( iTipoFact == FACT_CICLO )
    {
        /* EXEC SQL DECLARE Cur_InfacCel CURSOR FOR
        SELECT /o+ index (GA_INFACCEL PK_GA_INFACCEL) o/
        ROWID, NUM_ABONADO
        FROM   GA_INFACCEL
        WHERE COD_CLIENTE   = :lhCodCliente
        AND NUM_ABONADO   = :lhNumAbonado
        AND COD_CICLFACT <= :lhCodCiclFact
        AND IND_FACTUR    = :iUno
        AND (EXISTS
           (SELECT /o+ index (TA_ACUMAIREFRASOC PK_TA_ACUMAIREFRASOC)o/
            NUM_ABONADO
            FROM   TA_ACUMAIREFRASOC
            WHERE  NUM_ABONADO   = :lhNumAbonado
            /oAND  COD_CICLFACT <= :lhCodCiclFacto/
	    AND COD_CICLFACT IN (SELECT COD_CICLFACT FROM FA_CICLFACT /oAFGS - 33926o/
	                         WHERE FEC_EMISION <=(SELECT FEC_EMISION
				                      FROM FA_CICLFACT
				                      WHERE COD_CICLFACT = :lhCodCiclFact)
                                 AND IND_FACTURACION > :iCero)
            AND  COD_CLIENTE   = :lhCodCliente
            AND  NUM_PROCESO   = :iCero)
           OR
           EXISTS
           (SELECT /o+ index(TA_ACUMOPER PK_TA_ACUMOPER) o/
            NUM_ABONADO
            FROM   TA_ACUMOPER
            WHERE  NUM_ABONADO   = :lhNumAbonado
            /oAND  COD_CICLFACT <= :lhCodCiclFacto/
	    AND COD_CICLFACT IN (SELECT COD_CICLFACT FROM FA_CICLFACT /oAFGS - 33926o/
	                         WHERE FEC_EMISION <=(SELECT FEC_EMISION
				                      FROM FA_CICLFACT
				                      WHERE COD_CICLFACT = :lhCodCiclFact)
                                 AND IND_FACTURACION > :iCero)
            AND  COD_CLIENTE   = :lhCodCliente
            AND  NUM_PROCESO   = :iCero)
           OR
           EXISTS
           (SELECT /o+ index(TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA)o/
            NUM_ABONADO
            FROM   TA_ACUMLLAMADASROA
            WHERE  NUM_ABONADO   = :lhNumAbonado
            /oAND  COD_CICLFACT <= :lhCodCiclFacto/
	    AND COD_CICLFACT IN (SELECT COD_CICLFACT FROM FA_CICLFACT /oAFGS - 33926o/
	                         WHERE FEC_EMISION <=(SELECT FEC_EMISION
				                      FROM FA_CICLFACT
				                      WHERE COD_CICLFACT = :lhCodCiclFact)
                                 AND IND_FACTURACION > :iCero)
            AND  COD_CLIENTE   = :lhCodCliente
            AND  NUM_PROCESO   = :iCero) ); */ 

    }
    else if( iTipoFact == FACT_BAJA )
    {
        /* EXEC SQL DECLARE Cur_InfacCelBaja CURSOR FOR
        SELECT /o+ index (GA_INFACCEL PK_GA_INFACCEL) o/
        ROWID, NUM_ABONADO
        FROM   GA_INFACCEL
        WHERE COD_CLIENTE = :lhCodCliente
        AND NUM_ABONADO = :lhNumAbonado
        AND COD_CICLFACT= :lhCodCiclFact
        AND IND_FACTUR  = :iUno
        AND (EXISTS
             (SELECT /o+ index (TA_ACUMAIREFRASOC PK_TA_ACUMAIREFRASOC)o/
              NUM_ABONADO
              FROM   TA_ACUMAIREFRASOC
              WHERE  NUM_ABONADO   = :lhNumAbonado
              AND  COD_CICLFACT  = :lhCodCiclFact
              AND  COD_CLIENTE   = :lhCodCliente
              AND  NUM_PROCESO   = :iCero)
             OR
             EXISTS
             (SELECT /o+ index(TA_ACUMOPER PK_TA_ACUMOPER) o/
              NUM_ABONADO
              FROM   TA_ACUMOPER
              WHERE  NUM_ABONADO   = :lhNumAbonado
              AND  COD_CICLFACT  = :lhCodCiclFact
              AND  COD_CLIENTE   = :lhCodCliente
              AND  NUM_PROCESO   = :iCero)
             OR
             EXISTS
             (SELECT /o+ index(TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA)o/
              NUM_ABONADO
              FROM   TA_ACUMLLAMADASROA
              WHERE  COD_CICLFACT  = :lhCodCiclFact
              AND  NUM_ABONADO   = :lhNumAbonado
              AND  COD_CLIENTE   = :lhCodCliente
              AND  NUM_PROCESO   = :iCero) ); */ 

    }
    else if( iTipoFact == FACT_LIQUIDACION )
    {
        /* EXEC SQL DECLARE Cur_InfacCelLiq CURSOR FOR
        SELECT /o+ index (GA_INFACCEL PK_GA_INFACCEL) o/
        ROWID, NUM_ABONADO
        FROM   GA_INFACCEL
        WHERE COD_CLIENTE = :lhCodCliente
        AND NUM_ABONADO = :lhNumAbonado
        AND FEC_BAJA   <= TO_DATE (:szSysDate,'YYYYMMDDHH24MISS')
        AND IND_FACTUR  = :iUno
        AND (EXISTS
           (SELECT /o+ index (TA_ACUMAIREFRASOC PK_TA_ACUMAIREFRASOC)o/
            NUM_ABONADO
            FROM   TA_ACUMAIREFRASOC
            WHERE  NUM_ABONADO   = :lhNumAbonado
            AND  COD_CLIENTE   = :lhCodCliente
            AND  NUM_PROCESO   = :iCero)
           OR
           EXISTS
           (SELECT /o+ index(TA_ACUMOPER PK_TA_ACUMOPER) o/
            NUM_ABONADO
            FROM   TA_ACUMOPER
            WHERE  NUM_ABONADO  = :lhNumAbonado
            AND  COD_CLIENTE  = :lhCodCliente
            AND  NUM_PROCESO  = :iCero)
           OR
           EXISTS
           (SELECT /o+ index(TA_ACUMLLAMADASROA PK_TA_ACUMLLAMADASROA)o/
            NUM_ABONADO
            FROM   TA_ACUMLLAMADASROA
            WHERE  NUM_ABONADO  = :lhNumAbonado
            AND  COD_CLIENTE  = :lhCodCliente
            AND  NUM_PROCESO  = :iCero) ); */ 

    }

    vDTrazasLog (szExeName,
                 "\n\t\t* Parametros de Entrada Carga Abonados Celular con Trafico "
                 "\n\t\t=> Cliente     [%ld]"
                 "\n\t\t=> Num.Abonado [%ld]"
                 "\n\t\t=> Cod.CiclFact[%ld]",LOG04,
                 stCliente.lCodCliente,pCicloCli->lNumAbonado,
                 stCiclo.lCodCiclFact);

    lhCodCiclFact = stCiclo.lCodCiclFact  ;
    lhCodCliente  = stCliente.lCodCliente ;
    lhNumAbonado  = pCicloCli->lNumAbonado;

    if( iTipoFact == FACT_CICLO )
    {
        /* EXEC SQL OPEN Cur_InfacCel; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0, 
          "select  /*+  index (GA_INFACCEL PK_GA_INFACCEL)  +*/ ROWID ,NUM_A\
BONADO  from GA_INFACCEL where ((((COD_CLIENTE=:b0 and NUM_ABONADO=:b1) and \
COD_CICLFACT<=:b2) and IND_FACTUR=:b3) and ((exists (select  /*+  index (TA_\
ACUMAIREFRASOC PK_TA_ACUMAIREFRASOC) +*/ NUM_ABONADO  from TA_ACUMAIREFRASOC\
 where (((NUM_ABONADO=:b1 and COD_CICLFACT in (select COD_CICLFACT  from FA_\
CICLFACT where (FEC_EMISION<=(select FEC_EMISION  from FA_CICLFACT where COD\
_CICLFACT=:b2) and IND_FACTURACION>:b6))) and COD_CLIENTE=:b0) and NUM_PROCE\
SO=:b6)) or exists (select  /*+  index(TA_ACUMOPER PK_TA_ACUMOPER)  +*/ NUM_\
ABONADO  from TA_ACUMOPER where (((NUM_ABONADO=:b1 and COD_CICLFACT in (sele\
ct COD_CICLFACT  from FA_CICLFACT where (FEC_EMISION<=(select FEC_EMISION  f\
rom FA_CICLFACT where COD_CICLFACT=:b2) and IND_FACTURACION>:b6))) and COD_C\
LIENTE=:b0) and NUM_PROCESO=:b6))) or exists (select  /*+  index(TA_ACUMLLAM\
ADASROA PK_TA_ACUMLLAMADASROA) +*/ NUM_ABONADO  from TA_ACUMLLAMADASROA wher\
e (((NUM_ABONADO=:b1 and COD_CICLFACT in (selec");
        sqlstm.stmt = sq0017;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1039;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&iUno;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)0;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)0;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)0;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
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
    else if( iTipoFact == FACT_BAJA )
    {
        /* EXEC SQL OPEN Cur_InfacCelBaja; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0018;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1130;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&iUno;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&lhCodCiclFact;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)0;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)0;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)0;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
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
    else if( iTipoFact == FACT_LIQUIDACION )
    {
        /* EXEC SQL OPEN Cur_InfacCelLiq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0019;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1209;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szSysDate;
        sqlstm.sqhstl[2] = (unsigned long )15;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&iUno;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhNumAbonado;
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
        sqlstm.sqhstv[6] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&lhNumAbonado;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&lhCodCliente;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
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

    if( SQLCODE )
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ga_InfacCel",
                 szfnORAerror());
        return(FALSE);
    }
    while( bRes )
    {
        if( (stCliente.pAbonados =
             (ABONTAR *)realloc ((ABONTAR *)stCliente.pAbonados,
                                 sizeof(ABONTAR)*(stCliente.iNumAbonados+1)))==(ABONTAR *)NULL )
        {
            iDError (szExeName,ERR005,vInsertarIncidencia,
                     "stCliente.pAbonados",szfnORAerror());
            return(FALSE);
        }
        memset(&stCliente.pAbonados[stCliente.iNumAbonados],0,sizeof(ABONTAR));

        szhRowid = stCliente.pAbonados[stCliente.iNumAbonados].szRowid;

        if( iTipoFact == FACT_CICLO )
            /* EXEC SQL FETCH Cur_InfacCel INTO :szhRowid, :lhNumAbonado; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1276;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
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


        else if( iTipoFact == FACT_BAJA )
            /* EXEC SQL FETCH Cur_InfacCelBaja INTO :szhRowid, :lhNumAbonado; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1299;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
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


        else if( iTipoFact == FACT_LIQUIDACION )
            /* EXEC SQL FETCH Cur_InfacCelLiq INTO :szhRowid, :lhNumAbonado; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1322;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
            sqlstm.sqhstl[0] = (unsigned long )19;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&lhNumAbonado;
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



        switch( SQLCODE )
        {
            case SQLOK :
                stCliente.pAbonados[stCliente.iNumAbonados].lNumAbonado =
                lhNumAbonado   ;
                stCliente.pAbonados[stCliente.iNumAbonados].iCodProducto=
                pCicloCli->iCodProducto;
                stCliente.pAbonados[stCliente.iNumAbonados].iNumConcTar = 0;

                stCliente.pAbonados[stCliente.iNumAbonados].pConcTar =
                (CONCTAR *)NULL;
                stCliente.iNumAbonados++;

                break;
            case SQLNOTFOUND:
                bRes = FALSE;
                break;
            default:
                iDError (szExeName,ERR000,vInsertarIncidencia,
                         "Fetch->Ga_InfacCel",szfnORAerror());
                bRes = FALSE;
                break;
        }
    }/* fin while */
    if( SQLCODE == SQLNOTFOUND )
    {
        if( iTipoFact == FACT_CICLO )
            /* EXEC SQL CLOSE Cur_InfacCel; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1345;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        else if( iTipoFact == FACT_BAJA )
            /* EXEC SQL CLOSE Cur_InfacCelBaja; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1360;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        else if( iTipoFact == FACT_LIQUIDACION )
            /* EXEC SQL CLOSE Cur_InfacCelLiq; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1375;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if( SQLCODE )
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close->Ga_InfacCel",
                     szfnORAerror());
    }
    vDTrazasLog (szExeName,"\n\t\t* Abonados Cargados Celular [%d]",LOG04,
                 stCliente.iNumAbonados);
    return(SQLCODE == SQLOK)?TRUE:FALSE;
}/************************ Final bfnCargaAbonadosCelular *********************/




/*****************************************************************************/
/*                           funcion : vPrintConcTar                         */
/*****************************************************************************/
static void vfnPrintConcTarificacion (void)
{
    int  iCon1 = 0;
    int  iCon2 = 0;
    int  iNumConcTar  = 0;

    vDTrazasLog (szExeName,"\n\t\t* Conceptos de Tarificacion Cargados ",
                 LOG05);
    for( iCon1=0;iCon1<stCliente.iNumAbonados;iCon1++ )
    {
        iNumConcTar = stCliente.pAbonados[iCon1].iNumConcTar;
        vDTrazasLog (szExeName,"\t\t=>Abonado [%ld] Numero Conceptos Tarif.[%d]",LOG05,
                                stCliente.pAbonados[iCon1].lNumAbonado,
                                stCliente.pAbonados[iCon1].iNumConcTar);
        for( iCon2=0;iCon2<iNumConcTar;iCon2++ )
        {
            vDTrazasLog (szExeName,"\n\t\t[%d]-Cod.Facturacion.............[%d] "
                                   "\n\t\t[%d]-Ind.Tabla...................[%d] "
                                   "\n\t\t[%d]-Imp.Consumido...............[%lf]"
                                   "\n\t\t[%d]-Segundos Consumidos.........[%ld]"
                                   "\n\t\t[%d]-Numero de Pulsos............[%ld]"
                                   "\n\t\t[%d]-Cod.FranHoraSoc.............[%d] "
                                   "\n\t\t[%d]-Cod.Operador................[%d] "
                                   ,LOG05
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].iCodFacturacion
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].iIndTabla
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].dImpConsumido
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].lSegConsumido
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].lNumPulsos
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].iCodFranHoraSoc
                                   ,iCon2,stCliente.pAbonados[iCon1].pConcTar[iCon2].iCodOperador)   ;
        }/* fin for iCon2 */
    }/* fin for iCon1 */
}
/*************************** Final vPrintConcTar ****************************/


/*****************************************************************************/
/*                          funcion : bValidacionConcTar                     */
/*****************************************************************************/
static BOOL bfnValidacionConcTar (CONCTAR *pConcTar)
{
    int iRes = 0;

    CONCEPTO stConcepto;

    memset (&stConcepto,0,sizeof(CONCEPTO));

    if( !bFindConcepto (pConcTar->iCodFacturacion, &stConcepto) )
    {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstConcepto");
        iRes = ERR021;
    }
    if( iRes == 0 )
    {
        strcpy (pConcTar->szCodMoneda  ,stConcepto.szCodMoneda  );
        strcpy (pConcTar->szDesConcepto,stConcepto.szDesConcepto);
        pConcTar->iCodTipConce  = stConcepto.iCodTipConce        ;
    }
    if( iRes == 0 && (stConcepto.iCodTipConce == IMPUESTO ||
                      stConcepto.iCodTipConce == DESCUENTO  ) )
    {
        sprintf (stAnomProceso.szObsAnomalia,"Tipo de Concepto erroneo %d",
                 stConcepto.iCodTipConce);
        iRes = ERR001;
    }
    if( iRes == 0 && stConcepto.iIndActivo == 0 )
    {
        strcpy (stAnomProceso.szObsAnomalia,"Indice Activo = 0");
        iRes = ERR001;
    }
    if( iRes == 0 && pConcTar->dImpConsumido < 0 )
    {
        sprintf (stAnomProceso.szObsAnomalia,"Importe del concepto = %f",
                 pConcTar->dImpConsumido);
        iRes = ERR001;
    }
    if( iRes )
    {
        stAnomProceso.lNumProceso  = stStatus.IdPro           ;
        stAnomProceso.lCodCliente  = stCliente.lCodCliente    ;
        stAnomProceso.iCodConcepto = pConcTar->iCodFacturacion;
        stAnomProceso.iCodProducto = pConcTar->iCodProducto   ;
        stAnomProceso.lCodCiclFact = stCiclo.lCodCiclFact     ;

        strncpy (stAnomProceso.szDesProceso,"PreBilling-Tarificacion",
                 sizeof (stAnomProceso.szDesProceso));

        if( iRes == ERR001 )
        {
            iDError (szExeName,ERR001,vInsertarIncidencia,
                     stAnomProceso.iCodConcepto,
                     stConcepto.iIndActivo     ,
                     stConcepto.iCodTipConce   ,
                     pConcTar->dImpConsumido);
        }
    }
    return(iRes == 0)?TRUE:FALSE;
}/*************************** Final bValidacionConcTar ***********************/

/*****************************************************************************/
/*                          funcion : bfnValidacionCarrier                   */
/*****************************************************************************/
static BOOL bfnValidacionCarrier (CONCTAR *pConcTar, CONCEPTO stConcepto)
{
    int iRes = 0;

    strcpy (pConcTar->szCodMoneda  ,stConcepto.szCodMoneda  );
    strcpy (pConcTar->szDesConcepto,stConcepto.szDesConcepto);

    pConcTar->iCodTipConce = stConcepto.iCodTipConce;

    if( stConcepto.iCodTipConce == DESCUENTO )
    {
        sprintf (stAnomProceso.szObsAnomalia,"Tipo de Concepto erroneo %d",
                 stConcepto.iCodTipConce);
        iRes = ERR001;
    }
    if( iRes == 0 && stConcepto.iIndActivo == 0 )
    {
        strcpy (stAnomProceso.szObsAnomalia,"Indice Activo = 0");
        iRes = ERR001;
    }
    if( iRes == 0 && pConcTar->dImpConsumido <= 0 )
    {
        sprintf (stAnomProceso.szObsAnomalia,"Importe del concepto = %f",
                 pConcTar->dImpConsumido);
        iRes = ERR001;
    }
    if( iRes )
    {
        stAnomProceso.lNumProceso  = stStatus.IdPro           ;
        stAnomProceso.lCodCliente  = stCliente.lCodCliente    ;
        stAnomProceso.iCodConcepto = pConcTar->iCodFacturacion;
        stAnomProceso.iCodProducto = pConcTar->iCodProducto   ;
        stAnomProceso.lCodCiclFact = stCiclo.lCodCiclFact     ;

        strncpy (stAnomProceso.szDesProceso,"Tasacion-Carrier",
                 sizeof (stAnomProceso.szDesProceso));

        if( iRes == ERR001 )
        {
            iDError (szExeName,ERR001,vInsertarIncidencia,
                     stAnomProceso.iCodConcepto,
                     stConcepto.iIndActivo     ,
                     stConcepto.iCodTipConce   ,
                     pConcTar->dImpConsumido);
        }
    }
    return(iRes == 0)?TRUE:FALSE;
}/*************************** Final bfnValidacionCarrier *********************/

/*****************************************************************************/
/*                           funcion : vfnAplicaPlanOptimo                   */
/*****************************************************************************/
static void vfnAplicaPlanOptimo (CONCTAR *pConcTar   ,
                                 double   dMinTotal)
{
    int  i           = 0    ;
    int  j           = 0    ;
    int  k           = 0    ;


  /*********************************************************************/
  /* En caso de ser H o E, el cargo basico, estara asociado al cliente */
  /* y por tanto el NumAbonado sera 0.                                 */
  /*********************************************************************/
    vDTrazasLog (szExeName,"\n\t\t* Aplicacion Plan Optimo"
                 "\n\t\t=> Tip.PlanTarif     [%s]"
                 "\n\t\t=> Tot.Minutos Local [%f]", LOG05,
                 stCliente.szTipPlanTarif, dMinTotal);

    while( i<NUM_OPTIMO )
    {
        j = 0;

        while( j<stCliente.iNumAbonos )
        {
      /******************************************************************/
      /*  El Abonado 0 identifica los Cargos Basicos a Nivel de Cliente */
      /* de los Clientes Holding o Empresa.                             */
      /******************************************************************/

            if( stCliente.pAbonos [j].lNumAbonado == pConcTar->lNumAbonado ||
                ( stCliente.pAbonos [j].lNumAbonado == 0 &&
                  !stCliente.pAbonos [j].bPlanOptimo ) )
            {

                for( k=0;k<stCliente.pAbonos[j].iNumCBasicos;k++ )
                {
                    if( !strcmp(stCliente.pAbonos[j].pstCBasico[k].szCodPlanTarif,
                                pstOptimo [i].szCodPlanTarif) &&
                        pstOptimo [i].lMinDesde <= dMinTotal &&
                        ( pstOptimo [i].lMinHasta >= dMinTotal ||
                          pstOptimo [i].lMinHasta == -1) )
                    {
                        vDTrazasLog (szExeName,
                                     "\n\t\t* Importes Antes del Descuento"
                                     "\n\t\t=> Cod.FranHoraSoc   [%d]"
                                     "\n\t\t=> Prc.Bajo          [%f]"
                                     "\n\t\t=> Prc.Normal        [%f]"
                                     "\n\t\t=> Prc.Abono         [%f]"
                                     "\n\t\t=> Importe Consumido [%f]"
                                     "\n\t\t=> Importe CBasico   [%f]", LOG05,
                                     pConcTar->iCodFranHoraSoc,
                                     pstOptimo [i].fPrcBajo   ,
                                     pstOptimo [i].fPrcNormal ,
                                     pstOptimo [i].fPrcAbono  ,
                                     pConcTar->dImpConsumido  ,
                                     stCliente.pAbonos[j].pstCBasico[k].dImpConcepto);

                        if( pConcTar->iCodFranHoraSoc == iFRANBAJA )
                            pConcTar->dImpConsumido   -=
                            (double)(pConcTar->dImpConsumido *
                                     pstOptimo [i].fPrcBajo)/100  ;
                        else if( pConcTar->iCodFranHoraSoc == iFRANNORMAL )
                            pConcTar->dImpConsumido   -=
                            (double)(pConcTar->dImpConsumido *
                                     pstOptimo [i].fPrcNormal)/100;

                        if( !stCliente.pAbonos[j].bPlanOptimo )
                        {
                            stCliente.pAbonos[j].pstCBasico[k].dImpConcepto -=
                            (double)(stCliente.pAbonos[j].pstCBasico[k].dImpConcepto *
                                     pstOptimo [i].fPrcAbono)/100       ;
                            stCliente.pAbonos[j].bPlanOptimo = TRUE;
                        }
                        vDTrazasLog (szExeName,
                                     "\n\t\t* Importes Despues del Descuento"
                                     "\n\t\t=> Importe Consumido [%f]"
                                     "\n\t\t=> Importe CBasico   [%f]", LOG05,
                                     pConcTar->dImpConsumido,
                                     stCliente.pAbonos[j].pstCBasico[k].dImpConcepto);
                    }

                }/* fin for k ... */
            }
            j++;

        }/* fin while bPlan ... */
        i++;

    }/* fin iNumOptimo */

}/************************** Final vfnAplicaPlanOptimo ***********************/

/*****************************************************************************/
/*                         funcion : dfnTotMinutosLocales                    */
/*****************************************************************************/
static double dfnTotMinutosLocales (ABONTAR *stAbonTar)
{
    int    i      = 0;
    double dTotal = 0;

    for( i=0;i<stAbonTar->iNumConcTar;i++ )
    {
        if( stAbonTar->pConcTar [i].iIndTabla == FRASOC )
            dTotal += stAbonTar->pConcTar [i].lSegConsumido;

        vDTrazasLog (szExeName,
                     "\n\t\t* Cconcepto de Trafico [%d]"
                     "\n\t\t=> Ind Tabla      [%d]"
                     "\n\t\t=> lSegConsumido  [%ld]"
                     "\n\t\t=> Acumulado      [%f]"
                     ,LOG05, i,stAbonTar->pConcTar [i].iIndTabla,stAbonTar->pConcTar [i].lSegConsumido, dTotal);
    }
    vDTrazasLog (szExeName,"\n\t\t* Total Trafico Local Adicional [%ld]",LOG05, dTotal);
    return(double)dTotal/60;
}/*************************** Final dfnTotMinutosLocales *********************/


/*****************************************************************************/
/*                          funcion : bfnBuscaAcumCodTarif                   */
/* - Busca el codigo de tarificacion en pstTaConcepFact y acumula en pConcTar*/
/*   los segundos e importe                                                  */
/*****************************************************************************/

static BOOL bfnBuscaAcumCodTarif(CONCEP *pstConcep    , long lNumAbonado
                                 ,int iCodTarificacion, long lSegConsumido
                                 ,double dImpConsumido, long lNumPulsos
                                 ,int sIndEntSal      , int  sIndDestino
                                 ,int iIndTabla       , char *szCodServicioOrig
                                 ,char *szCodPlanTarif, char *szCod_Unidad
                                 ,long lhNumUniFree	  , int  iCodOperador)
{
    int i=0;
    BOOL bFound=FALSE;

	char szCodServicio [6];
	
	strcpy (szCodServicio," ");
	
    vDTrazasLog (szExeName,
                 "\n\t\t* Parametros de Entrada bfnBuscaAcumCodTarif"
                 "\n\t\t=> Codigo Tarificacion      :[%d]"
                 "\n\t\t=> Cant. Segundos consumidos:[%ld]"
                 "\n\t\t=> Importe                  :[%f]"
                 "\n\t\t=> Numero de Pulsos         :[%ld]"
                 "\n\t\t=> Indicador de Tabla       :[%d]"
                 "\n\t\t=> Codigo Servicio          :[%s]"
                 "\n\t\t=> Codigo Plan Tarifario    :[%s]"
                 "\n\t\t=> Codigo Unidad            :[%s]"
                 "\n\t\t=> Minutos Libres           :[%ld]"
                 , LOG05,
                 iCodTarificacion,lSegConsumido, dImpConsumido,lNumPulsos,iIndTabla,
                 szCodServicioOrig, szCodPlanTarif, szCod_Unidad, lhNumUniFree);


    for( i=0;i<pstConcep->iNumConc;i++ )
    {
		if(pstConcep->stConcTar[i].iCodTarificacion == iCodTarificacion)
		{
            if( iIndTabla!=1 ) /* Ta_AcumOper */
            {
                if( !strcmp(pstConcep->stConcTar[i].szCodPlanTarif,szCodPlanTarif) )
                {
                    bFound=TRUE;
                    break;
                }
            }
            else if( pstConcep->stConcTar[i].iIndDestino== sIndDestino &&
                     pstConcep->stConcTar[i].iIndEntSal== sIndEntSal   &&
                     !strcmp(pstConcep->stConcTar[i].szCodServicioOrig,szCodServicioOrig) &&
                     !strcmp(pstConcep->stConcTar[i].szCodPlanTarif,szCodPlanTarif) )
            {
                bFound=TRUE;
                break;
            }
		}
	}
	
    if( bFound )
    {
        pstConcep->stConcTar[i].lSegConsumido  += lSegConsumido ;
        pstConcep->stConcTar[i].dImpConsumido  += dImpConsumido ;

	}
 	else 
 	{
 		/* rao: si es != "" obtiene cod.Serv. Generico para bolsas */
 		if (strcmp(szCodServicioOrig," ")!=0 && (!bGetCodServGenerico(szCodServicio)))
		{
 				strcpy (szCodServicio, szCodServicioOrig);
		}
		
	    for( i=0;i<=NUM_TACONCEPFACT;i++ )
	    {   /* rao: busca con  cod.Serv. Generico para bolsas */
	        if( pstTaConcepFact[i].iCodTarificacion== iCodTarificacion )
	        {
	            if( iIndTabla!=1 ) /* Ta_AcumOper */
	            {
	                if( !strcmp(pstTaConcepFact[i].szCodServicio,szCodServicio) )
	                {
	                    bFound=TRUE;
	                    break;
	                }
	            }
	            else if( pstTaConcepFact[i].iIndDestino== sIndDestino &&
	                     pstTaConcepFact[i].iIndEntSal== sIndEntSal   &&
	                     !strcmp(pstTaConcepFact[i].szCodServicio,szCodServicio) )
	            {
	                bFound=TRUE;
	                break;
	            }
	        }
	    }
	    if( bFound )
	    {
	    	if( (pstConcep->stConcTar = (CONCTAR *)realloc ((CONCTAR *)pstConcep->stConcTar,sizeof(CONCTAR)*(pstConcep->iNumConc+1)))==(CONCTAR *)NULL )
	        {
	            iDError(szExeName,ERR005,vInsertarIncidencia,"bfnBuscaAcumCodTarif: pstConcep->stConcTar",szfnORAerror());
	            return(FALSE);
	        }
	        memset(&pstConcep->stConcTar[pstConcep->iNumConc],0,sizeof(CONCTAR));

	        pstConcep->stConcTar[pstConcep->iNumConc].lNumAbonado     = lNumAbonado                       ;
	        pstConcep->stConcTar[pstConcep->iNumConc].iCodProducto    = pstTaConcepFact[i].iCodProducto   ;
	        pstConcep->stConcTar[pstConcep->iNumConc].iCodFacturacion = pstTaConcepFact[i].iCodFacturacion;
	        pstConcep->stConcTar[pstConcep->iNumConc].iIndTabla       = pstTaConcepFact[i].iIndTabla      ;
	        pstConcep->stConcTar[pstConcep->iNumConc].iIndDestino     = pstTaConcepFact[i].iIndDestino    ;
	
	        if( pstConcep->stConcTar[pstConcep->iNumConc].iIndTabla == FRASOC )
	        {
	            pstConcep->stConcTar[pstConcep->iNumConc].iCodFranHoraSoc = iCodTarificacion			  ;
		        pstConcep->stConcTar[pstConcep->iNumConc].iCodOperador    = iCodOperador                  ;
		    }
	        else
	            pstConcep->stConcTar[pstConcep->iNumConc].iCodOperador    = iCodTarificacion;
	
	        pstConcep->stConcTar[pstConcep->iNumConc].lNumPulsos      = lNumPulsos                        ;
	        pstConcep->stConcTar[pstConcep->iNumConc].lNumProceso     = stStatus.IdPro                    ;
	        pstConcep->stConcTar[pstConcep->iNumConc].iIndEntSal      = sIndEntSal                        ;
	        pstConcep->stConcTar[pstConcep->iNumConc].iCarrier        = 0                                 ;
	
	        pstConcep->stConcTar[pstConcep->iNumConc].lSegConsumido  += lSegConsumido                     ;
	        pstConcep->stConcTar[pstConcep->iNumConc].dImpConsumido  += dImpConsumido                     ;
	
	        strcpy (pstConcep->stConcTar[pstConcep->iNumConc].szCodPlanTarif, szCodPlanTarif)             ;
	        strcpy (pstConcep->stConcTar[pstConcep->iNumConc].szCod_Unidad, szCod_Unidad)             	  ;
	        pstConcep->stConcTar[pstConcep->iNumConc].lhNumUniFree    = lhNumUniFree                      ;
	        
	        pstConcep->stConcTar[pstConcep->iNumConc].iCodTarificacion= iCodTarificacion                  ;
	        strcpy (pstConcep->stConcTar[pstConcep->iNumConc].szCodServicioOrig, szCodServicioOrig)       ;
	        
	        pstConcep->iNumConc++;
	    }
    }


    return(bFound);
}/************************* Final bfnBuscaAcumCodTarif ***********************/


/****************************************************************************
        TOL functions
 Descripcion: Funciones cargas del Nuevo Tarificador Online
 Fecha : 20-12-2002 - 16-01-2003
 Autor : Mauricio Labra C.
****************************************************************************/


#ifndef isnull
    #define isnull(name) (name==(char )NULL )
#endif
#ifndef strnull
    #define strnull(name) (name==(char *)NULL || name[0]==(char)NULL)
#endif

char *ltrim(char *s)
{
    char *p=s;
    if( strnull(s) ) return(NULL);
    while( *p<=32 && *p>1 ) p++;
    strcpy(s,p);
    return(s);
}

char *rtrim(char *s)
{
    char *p=NULL;
    if( strnull(s) ) return(NULL);
    p=(s+strlen(s)-1);
    while( *p<=32 && *p>1 )  p--;
    *(++p)=0;
    return(s);
}

char *alltrim(char *s)
{
    return(ltrim(rtrim(s)));
}


int bfnBusca_Promo(char *szTipDcto, char *szCodDcto)
{
    int i;

    for( i=0; i<stTOL_DCTO.iNumTolDcto; i++ )
    {
        if( !strcmp(szTipDcto,stTOL_DCTO.asTolDcto[i].szTipDcto)
            && (!strcmp(szCodDcto,stTOL_DCTO.asTolDcto[i].szCodDcto)) )
        {
            return(i+1);
        }
    }
    return(FALSE);
}


int bfnBusca_UnidadPromo(char *szUnidad)
{
    int i;

    for( i=0; i<stTOL_PROMO.iNumTolPromo; i++ )
    {
        if( !strcmp(szUnidad,stTOL_PROMO.asTolPromo[i].szUnidadPromo) )
        {
            return(i+1);
        }
    }
    return(FALSE);
}



int bfnBusca_Desc(char *szTipDcto)
{
    int i;

    for( i=0; i<stTOL_DESC.iNumTolDesc; i++ )
    {
        if( !strcmp(szTipDcto,stTOL_DESC.asTolDesc[i].szTipDcto) )
        {
            return(i+1);
        }
    }
    return(FALSE);
}

/* MultiIdioma  */
BOOL bCarga_TOLDescuentosMI()
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        static char szAster[4];     /* EXEC SQL VAR szAster IS STRING(4); */ 

        static char szNomTabla[17]; /* EXEC SQL VAR szNomTabla IS STRING(17); */ 

        static char szNomCampo[9];  /* EXEC SQL VAR szNomCampo IS STRING(9); */ 

    /* EXEC SQL END DECLARE SECTION; */ 

    
    int j;
    int iCodProducto;
    char szCodConcepto[13];
    char szDesConcepto[256];


    strcpy(szAster,"***");
    strcpy(szNomTabla,"TOL_DESCUENTO_TD");
    strcpy(szNomCampo,"TIP_DCTO"); 
   
    if( strcmp(stCliente.szCodIdioma,pstParamGener.szCodIdioma) )
    {
        int  i        = 0   ;

        /* EXEC SQL DECLARE Cur_TOL_Descuentos_MI CURSOR FOR
        SELECT  COD_PRODUCTO,
        COD_CONCEPTO,
        NVL(DES_CONCEPTO,:szAster)
        FROM GE_MULTIIDIOMA
        WHERE NOM_TABLA = :szNomTabla
        AND NOM_CAMPO = :szNomCampo
        AND COD_IDIOMA = :stCliente.szCodIdioma
        ; */ 


        /* EXEC SQL OPEN Cur_TOL_Descuentos_MI; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0020;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1390;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szAster;
        sqlstm.sqhstl[0] = (unsigned long )4;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szNomTabla;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szNomCampo;
        sqlstm.sqhstl[2] = (unsigned long )9;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)(stCliente.szCodIdioma);
        sqlstm.sqhstl[3] = (unsigned long )6;
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



        if( SQLCODE )
        {
            iDError(szExeName,ERR000,vInsertarIncidencia,"Open->GE_MULTIIDIOMA",szfnORAerror());
            return(FALSE);
        }

        i=j=0;
        while( SQLCODE == 0 )
        {
            /* EXEC SQL FETCH Cur_TOL_Descuentos_MI
            INTO :iCodProducto,
            :szCodConcepto,
            :szDesConcepto
            ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 19;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1421;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)&iCodProducto;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szCodConcepto;
            sqlstm.sqhstl[1] = (unsigned long )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)szDesConcepto;
            sqlstm.sqhstl[2] = (unsigned long )256;
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



            alltrim(szCodConcepto);
            alltrim(szDesConcepto);

            for( i=0; i<stTOL_DCTO.iNumTolDcto; i++ )
            {
                if( stTOL_DCTO.asTolDcto[i].iNTipDcto == iCodProducto
                    && !strcmp( stTOL_DCTO.asTolDcto[i].szTipDcto,szCodConcepto) )
                {
                    strcpy(stTOL_DCTO.asTolDcto[i].szGlsDcto, szDesConcepto);
                }
            }
            stTOL_PROMODCTO_MI.asTolPromoDcto_MI[j].iCodProducto=iCodProducto;
            strcpy(stTOL_PROMODCTO_MI.asTolPromoDcto_MI[j].szCodConcepto,szCodConcepto);
            strcpy(stTOL_PROMODCTO_MI.asTolPromoDcto_MI[j].szCodIdioma,stCliente.szCodIdioma);
            strcpy(stTOL_PROMODCTO_MI.asTolPromoDcto_MI[j].szDesConcepto,szDesConcepto);

            j++;
        }/* fin while */

        stTOL_PROMODCTO_MI.iNumTolPromoDcto=j-1;
        vDTrazasLog(szExeName, "\n\t\t*  bCarga_TOLDescuentosMI leidos [%d]\n",LOG05, stTOL_PROMODCTO_MI.iNumTolPromoDcto);

        if( SQLCODE != 0 && SQLCODE != SQLNOTFOUND )
        {
            iDError(szExeName,ERR000,vInsertarIncidencia,"Fetch->GE_MULTIIDIOMA", szfnORAerror());
            return(FALSE);
        }

        /* EXEC SQL CLOSE Cur_TOL_Descuentos_MI; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1448;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        if( SQLCODE )
        {
            iDError(szExeName,ERR000,vInsertarIncidencia,"Close->GE_MULTIIDIOMA", szfnORAerror());
        }
    }
    return(1);
}


#define zero(m) memset(m,0,sizeof(m))


/*----------------------------------------------------------------------------*/
/* Funcion de busqueda en arreglo de ciclos facturados.                       */
/*----------------------------------------------------------------------------*/
BOOL bBuscaPlanTarifAbon (long lNumAbonado,char *szCodPlanTarif)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCliente ;
    long lhNumAbonado;
    char pszFecDesde [15];/* EXEC SQL VAR pszFecDesde  IS STRING(15); */ 

    char pszFecHasta [15];/* EXEC SQL VAR pszFecHasta  IS STRING(15); */ 

    char pszCodPlanTarif [4];/* EXEC SQL VAR pszCodPlanTarif  IS STRING(4); */ 

    static char szFormatoFec [17];/* EXEC SQL VAR szFormatoFec  IS STRING(17); */ 

    int   iCero=0;
    int   iDos=2;
    /* EXEC SQL END DECLARE SECTION; */ 


    int i=0;

     strcpy(szFormatoFec,"YYYYMMDDHH24MISS");
     
	vDTrazasLog ("bBuscaPlanTarifAbon","Plan tarif [%s]", LOG03,szCodPlanTarif);

    while( (lNumAbonado != stCliente.pAbonos[i].lNumAbonado) && (i <= stCliente.iNumAbonos) )
    {
        i++;
    }

	
    if( i > stCliente.iNumAbonos )   /* Periodo no encontrado en arreglo */
    {
        vDTrazasLog(szExeName, "Abonado [%d] no encontrado ...", LOG05, lNumAbonado);
        return(FALSE);
    }
    else 
    { 
					strcpy(pszFecDesde,stCiclo.szFecDesdeCFijos);
					strcpy(pszFecHasta,stCiclo.szFecHastaCFijos);
					lhCodCliente=stCliente.lCodCliente;
					lhNumAbonado=lNumAbonado;
					/* EXEC SQL
								SELECT PLANTARIF 
								INTO :pszCodPlanTarif
								FROM (
								SELECT A.FEC_DESDE,
								       A.FEC_HASTA,
									   A.COD_PLANTARIF PLANTARIF,
									   B.COD_TIPLAN
								FROM GA_INTARCEL A, TA_PLANTARIF B
								WHERE A.COD_CLIENTE   = :lhCodCliente
								AND A.NUM_ABONADO   = :lhNumAbonado
								AND A.IND_NUMERO    = :iCero
								AND B.COD_TIPLAN = :iDos
								AND B.COD_PLANTARIF = A.COD_PLANTARIF
								AND A.FEC_DESDE     < TO_DATE (:pszFecHasta, :szFormatoFec)
								AND A.FEC_HASTA    >= TO_DATE (:pszFecDesde, :szFormatoFec)
								ORDER BY A.FEC_HASTA DESC)
								WHERE ROWNUM = 1; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 19;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select PLANTARIF into :b0  from (select A.FEC_DESDE ,A.F\
EC_HASTA ,A.COD_PLANTARIF PLANTARIF ,B.COD_TIPLAN  from GA_INTARCEL A ,TA_PLAN\
TARIF B where ((((((A.COD_CLIENTE=:b1 and A.NUM_ABONADO=:b2) and A.IND_NUMERO=\
:b3) and B.COD_TIPLAN=:b4) and B.COD_PLANTARIF=A.COD_PLANTARIF) and A.FEC_DESD\
E<TO_DATE(:b5,:b6)) and A.FEC_HASTA>=TO_DATE(:b7,:b6)) order by A.FEC_HASTA de\
sc  ) where ROWNUM=1";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1463;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)pszCodPlanTarif;
     sqlstm.sqhstl[0] = (unsigned long )4;
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
     sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
     sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)&iDos;
     sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[4] = (         int  )0;
     sqlstm.sqindv[4] = (         short *)0;
     sqlstm.sqinds[4] = (         int  )0;
     sqlstm.sqharm[4] = (unsigned long )0;
     sqlstm.sqadto[4] = (unsigned short )0;
     sqlstm.sqtdso[4] = (unsigned short )0;
     sqlstm.sqhstv[5] = (unsigned char  *)pszFecHasta;
     sqlstm.sqhstl[5] = (unsigned long )15;
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)0;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)szFormatoFec;
     sqlstm.sqhstl[6] = (unsigned long )17;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)0;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)pszFecDesde;
     sqlstm.sqhstl[7] = (unsigned long )15;
     sqlstm.sqhsts[7] = (         int  )0;
     sqlstm.sqindv[7] = (         short *)0;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)szFormatoFec;
     sqlstm.sqhstl[8] = (unsigned long )17;
     sqlstm.sqhsts[8] = (         int  )0;
     sqlstm.sqindv[8] = (         short *)0;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
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



		    
		    if( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
		    {
		        vDTrazasLog ("bBuscaPlanTarifAbon","\n\t\tError en Select de Plan Tarifario del Cliente/Abonado ==>[%ld/%ld]",LOG03,lhCodCliente,lhNumAbonado);
		        iDError (szExeName,ERR000,vInsertarIncidencia,"Select de Plan Tarifario del Cliente/Abonado", szfnORAerror());
		        return(FALSE);
		    }
		
		    if( SQLCODE == SQLNOTFOUND )
		        vDTrazasLog ("bBuscaPlanTarifAbon","\n\t\t* Plan Tarifario del Cliente/Abonado PPQL ",LOG03);
		    
		    if( SQLCODE == SQLOK )
		        vDTrazasLog ("bBuscaPlanTarifAbon","\n\t\t* Plan Tarifario del Cliente/Abonado [%s]",LOG03,pszCodPlanTarif);
		



       if (strcmp(pszCodPlanTarif,"")!=0)/* ||strcmp(pszCodPlanTarif," ")!=0)PPQL*/
       {
    		   strcpy(szCodPlanTarif,pszCodPlanTarif);
    		   vDTrazasLog ("bBuscaPlanTarifAbon","Plan tarifPPQL2 [%s]", LOG05,szCodPlanTarif);    	
		   }
		   else 
	   	 {
					strcpy(pszFecDesde,stCiclo.szFecDesdeCFijos);
					strcpy(pszFecHasta,stCiclo.szFecHastaCFijos);
					lhCodCliente=stCliente.lCodCliente;
					lhNumAbonado=lNumAbonado;
					vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon  lhCodCliente [%ld]", LOG03,lhCodCliente);
					vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon  lhNumAbonado [%ld]", LOG03,lhNumAbonado);
					vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon  pszFecDesde  [%s]" , LOG03,pszFecDesde);
					vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon  pszFecHasta  [%s]", LOG03,pszFecHasta);
					
					/* EXEC SQL
					SELECT COD_PLANTARIF
					  INTO :pszCodPlanTarif
					  FROM GA_INTARCEL
		        	 WHERE COD_CLIENTE   = :lhCodCliente
		        	   AND NUM_ABONADO   = :lhNumAbonado
		        	   AND IND_NUMERO    = :iCero
		        	   AND FEC_DESDE     < TO_DATE (:pszFecHasta, :szFormatoFec)
		        	   AND FEC_HASTA    >= TO_DATE (:pszFecDesde, :szFormatoFec); */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 19;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select COD_PLANTARIF into :b0  from GA_INTARCEL where ((\
((COD_CLIENTE=:b1 and NUM_ABONADO=:b2) and IND_NUMERO=:b3) and FEC_DESDE<TO_DA\
TE(:b4,:b5)) and FEC_HASTA>=TO_DATE(:b6,:b5))";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1514;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)pszCodPlanTarif;
     sqlstm.sqhstl[0] = (unsigned long )4;
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
     sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
     sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)pszFecHasta;
     sqlstm.sqhstl[4] = (unsigned long )15;
     sqlstm.sqhsts[4] = (         int  )0;
     sqlstm.sqindv[4] = (         short *)0;
     sqlstm.sqinds[4] = (         int  )0;
     sqlstm.sqharm[4] = (unsigned long )0;
     sqlstm.sqadto[4] = (unsigned short )0;
     sqlstm.sqtdso[4] = (unsigned short )0;
     sqlstm.sqhstv[5] = (unsigned char  *)szFormatoFec;
     sqlstm.sqhstl[5] = (unsigned long )17;
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)0;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)pszFecDesde;
     sqlstm.sqhstl[6] = (unsigned long )15;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)0;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)szFormatoFec;
     sqlstm.sqhstl[7] = (unsigned long )17;
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


		
								vDTrazasLog ("bBuscaPlanTarifAbon","** pszCodPlanTarif [%s] **", LOG04,pszCodPlanTarif);
						
					if (SQLCODE) /*(1)*/
					{
						/* EXEC SQL
						SELECT A.COD_PLANTARIF
						  INTO :pszCodPlanTarif
						  FROM GA_INTARCEL A, TA_PLANTARIF B
			        	 WHERE A.COD_CLIENTE   = :lhCodCliente
			        	   AND A.NUM_ABONADO   = :lhNumAbonado
			        	   AND A.IND_NUMERO    = :iCero
			        	   AND B.cod_tiplan = :iDos AND
			        	   B.COD_PLANTARIF = A.COD_PLANTARIF
			        	   AND A.FEC_DESDE     < TO_DATE (:pszFecHasta, :szFormatoFec)
			        	   AND A.FEC_HASTA    >= TO_DATE (:pszFecDesde, :szFormatoFec)
			        	   AND ROWNUM < :iDos; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 19;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select A.COD_PLANTARIF into :b0  from GA_INTARCEL A ,TA\
_PLANTARIF B where (((((((A.COD_CLIENTE=:b1 and A.NUM_ABONADO=:b2) and A.IND_N\
UMERO=:b3) and B.cod_tiplan=:b4) and B.COD_PLANTARIF=A.COD_PLANTARIF) and A.FE\
C_DESDE<TO_DATE(:b5,:b6)) and A.FEC_HASTA>=TO_DATE(:b7,:b6)) and ROWNUM<:b4)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1561;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)pszCodPlanTarif;
      sqlstm.sqhstl[0] = (unsigned long )4;
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
      sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&iDos;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)pszFecHasta;
      sqlstm.sqhstl[5] = (unsigned long )15;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)szFormatoFec;
      sqlstm.sqhstl[6] = (unsigned long )17;
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)pszFecDesde;
      sqlstm.sqhstl[7] = (unsigned long )15;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)szFormatoFec;
      sqlstm.sqhstl[8] = (unsigned long )17;
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&iDos;
      sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
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


			        	   
										vDTrazasLog ("bBuscaPlanTarifAbon","DATOS DE (SQLCODE) /*(%d)*/",LOG04,1);
										vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 1  lhCodCliente [%ld]", LOG04,lhCodCliente);
										vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 1 lhNumAbonado [%ld]", LOG04,lhNumAbonado);
										vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 1 pszFecDesde  [%s]" , LOG04,pszFecDesde);
										vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 1 pszFecHasta  [%s]", LOG04,pszFecHasta);
										vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 1 pszCodPlanTarif [%s]", LOG04,pszCodPlanTarif);
						
							if (SQLCODE) /*(2)*/
							{
								
								/* EXEC SQL
								SELECT A.COD_PLANTARIF
								  INTO :pszCodPlanTarif
								  FROM GA_INTARCEL A, TA_PLANTARIF B
					        	 WHERE A.COD_CLIENTE   = :lhCodCliente
					        	   AND A.NUM_ABONADO   = :lhNumAbonado
					        	   AND A.IND_NUMERO    = :iCero
					        	   AND B.COD_PLANTARIF = A.COD_PLANTARIF
					        	   AND A.FEC_DESDE     < TO_DATE (:pszFecHasta, :szFormatoFec)
					        	   AND A.FEC_HASTA    >= TO_DATE (:pszFecDesde, :szFormatoFec)
					        	   AND ROWNUM < :iDos; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select A.COD_PLANTARIF into :b0  from GA_INTARCEL A ,\
TA_PLANTARIF B where ((((((A.COD_CLIENTE=:b1 and A.NUM_ABONADO=:b2) and A.IND_\
NUMERO=:b3) and B.COD_PLANTARIF=A.COD_PLANTARIF) and A.FEC_DESDE<TO_DATE(:b4,:\
b5)) and A.FEC_HASTA>=TO_DATE(:b6,:b5)) and ROWNUM<:b8)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1616;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)pszCodPlanTarif;
        sqlstm.sqhstl[0] = (unsigned long )4;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)pszFecHasta;
        sqlstm.sqhstl[4] = (unsigned long )15;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szFormatoFec;
        sqlstm.sqhstl[5] = (unsigned long )17;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)pszFecDesde;
        sqlstm.sqhstl[6] = (unsigned long )15;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)szFormatoFec;
        sqlstm.sqhstl[7] = (unsigned long )17;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&iDos;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
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


					        	   
						        	  vDTrazasLog ("bBuscaPlanTarifAbon","DATOS DE (SQLCODE) /*(%d)*/",LOG04,2);
												vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 2 lhCodCliente [%ld]", LOG04,lhCodCliente);
												vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 2 lhNumAbonado [%ld]", LOG04,lhNumAbonado);
												vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 2 pszFecDesde  [%s]" , LOG04,pszFecDesde);
												vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 2 pszFecHasta  [%s]", LOG04,pszFecHasta);
												vDTrazasLog ("bBuscaPlanTarifAbon","pszCodPlanTarif [%s]", LOG04,pszCodPlanTarif);
			
												if (SQLCODE) /*(3)*/
												{
												  /* EXEC SQL
												  SELECT A.COD_PLANTARIF
														INTO :pszCodPlanTarif
												  FROM GA_INTARCEL A
									          	 WHERE A.COD_CLIENTE   = :lhCodCliente
									        	   AND A.NUM_ABONADO   = :lhNumAbonado
									        	   AND A.IND_NUMERO    = :iCero
									        	   AND A.FEC_DESDE      = ( select max(B.fec_desde)  
									                                FROM GA_INTARCEL B
									                           	 WHERE B.COD_CLIENTE   = :lhCodCliente
									                           	   AND B.NUM_ABONADO   = :lhNumAbonado
									                          	   AND B.IND_NUMERO    = :iCero); */ 

{
              struct sqlexd sqlstm;
              sqlstm.sqlvsn = 12;
              sqlstm.arrsiz = 19;
              sqlstm.sqladtp = &sqladt;
              sqlstm.sqltdsp = &sqltds;
              sqlstm.stmt = "select A.COD_PLANTARIF into :b0  from GA_INTARC\
EL A where (((A.COD_CLIENTE=:b1 and A.NUM_ABONADO=:b2) and A.IND_NUMERO=:b3) a\
nd A.FEC_DESDE=(select max(B.fec_desde)  from GA_INTARCEL B where ((B.COD_CLIE\
NTE=:b1 and B.NUM_ABONADO=:b2) and B.IND_NUMERO=:b3)))";
              sqlstm.iters = (unsigned int  )1;
              sqlstm.offset = (unsigned int  )1667;
              sqlstm.selerr = (unsigned short)1;
              sqlstm.cud = sqlcud0;
              sqlstm.sqlest = (unsigned char  *)&sqlca;
              sqlstm.sqlety = (unsigned short)256;
              sqlstm.occurs = (unsigned int  )0;
              sqlstm.sqhstv[0] = (unsigned char  *)pszCodPlanTarif;
              sqlstm.sqhstl[0] = (unsigned long )4;
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
              sqlstm.sqhstv[3] = (unsigned char  *)&iCero;
              sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
              sqlstm.sqhsts[3] = (         int  )0;
              sqlstm.sqindv[3] = (         short *)0;
              sqlstm.sqinds[3] = (         int  )0;
              sqlstm.sqharm[3] = (unsigned long )0;
              sqlstm.sqadto[3] = (unsigned short )0;
              sqlstm.sqtdso[3] = (unsigned short )0;
              sqlstm.sqhstv[4] = (unsigned char  *)&lhCodCliente;
              sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
              sqlstm.sqhsts[4] = (         int  )0;
              sqlstm.sqindv[4] = (         short *)0;
              sqlstm.sqinds[4] = (         int  )0;
              sqlstm.sqharm[4] = (unsigned long )0;
              sqlstm.sqadto[4] = (unsigned short )0;
              sqlstm.sqtdso[4] = (unsigned short )0;
              sqlstm.sqhstv[5] = (unsigned char  *)&lhNumAbonado;
              sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
              sqlstm.sqhsts[5] = (         int  )0;
              sqlstm.sqindv[5] = (         short *)0;
              sqlstm.sqinds[5] = (         int  )0;
              sqlstm.sqharm[5] = (unsigned long )0;
              sqlstm.sqadto[5] = (unsigned short )0;
              sqlstm.sqtdso[5] = (unsigned short )0;
              sqlstm.sqhstv[6] = (unsigned char  *)&iCero;
              sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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


			
									        	  vDTrazasLog ("bBuscaPlanTarifAbon","DATOS DE (SQLCODE) /*(%d)*/",LOG04,3);
															vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 3 lhCodCliente [%ld]", LOG04,lhCodCliente);
															vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 3 lhNumAbonado [%ld]", LOG04,lhNumAbonado);
															vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 3 pszFecDesde  [%s]" , LOG04,pszFecDesde);
															vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon 3 pszFecHasta  [%s]", LOG04,pszFecHasta);
															vDTrazasLog ("bBuscaPlanTarifAbon","bBuscaPlanTarifAbon [%s]", LOG04,pszCodPlanTarif);
			
														if (SQLCODE)
														{
															vDTrazasLog ("bBuscaPlanTarifAbon","Error lhNumAbonado [%ld]", LOG01,lhNumAbonado);
															return (FALSE);
														}
												}
			        }
		      }
				vDTrazasLog ("bBuscaPlanTarifAbon","Plan tarif1 [%s]", LOG05,pszCodPlanTarif);
				strcpy(szCodPlanTarif,pszCodPlanTarif);
				vDTrazasLog ("bBuscaPlanTarifAbon","Plan tarif2 [%s]", LOG05,szCodPlanTarif);
		 }
    }

    return(1);
}

BOOL bGetCodServGenerico(char *szCodServicio)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char szhCodServicio [21];/* EXEC SQL VAR szhCodServicio  IS STRING(21); */ 

    char szhNomParametro[21];/* EXEC SQL VAR szhNomParametro IS STRING(21); */ 

    char szhCodModulo	[3] ;/* EXEC SQL VAR szhCodModulo    IS STRING(3); */ 

    /* EXEC SQL END DECLARE SECTION; */ 

	int iRes=0;

	vDTrazasLog(szExeName, "rao gszCodServicioGene [%s]", LOG05, gszCodServicioGene);
	
	if (bIndCodServicioGene == 0)
	{
		strcpy(szhNomParametro,"TIPO_PLAN_SERVICIO");
		strcpy(szhCodModulo	  ,"TA");
		
		/* EXEC SQL
			SELECT COD_SERVICIO 
			  INTO :szhCodServicio
			  FROM GAD_SERVSUP_PLAN
			 WHERE COD_PLANTARIF IN 
					(SELECT VAL_PARAMETRO 
					   FROM GED_PARAMETROS
					  WHERE COD_MODULO    = :szhCodModulo
						AND NOM_PARAMETRO = :szhNomParametro); */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 19;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select COD_SERVICIO into :b0  from GAD_SERVSUP_PLAN where C\
OD_PLANTARIF in (select VAL_PARAMETRO  from GED_PARAMETROS where (COD_MODULO=:\
b1 and NOM_PARAMETRO=:b2))";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1710;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhCodServicio;
  sqlstm.sqhstl[0] = (unsigned long )21;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhCodModulo;
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhNomParametro;
  sqlstm.sqhstl[2] = (unsigned long )21;
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
			strcpy (szCodServicio,szhCodServicio);
			strcpy (gszCodServicioGene,szhCodServicio);
			bIndCodServicioGene=1;
		}
		iRes=SQLCODE;
	}	
	else 
		strcpy (szCodServicio,gszCodServicioGene);
	
	return(iRes);
}

BOOL bLiberaEstrConc(CONCEP *stConcep)
{
	int i;
	
	for( i=0;i<stConcep->iNumConc;i++ )
		memset (&stConcep->stConcTar[i], 0, sizeof (CONCTAR));	

	return (1);
	
}

/******************************************************************************************/
/** Informacin de Versionado *************************************************************/
/******************************************************************************************/
/** Pieza                                               : */
/**  %ARCHIVE% */
/** Identificador en PVCS                               : */
/**  %PID% */
/** Producto                                            : */
/**  %PP% */
/** Revisin                                            : */
/**  %PR% */
/** Autor de la Revisin                                : */
/**  %AUTHOR% */
/** Estado de la Revisin ($TO_BE_DEFINED es Check-Out) : */
/**  %PS% */
/** Fecha de Creacin de la Revisin                    : */
/**  %DATE% */
/** Worksets ******************************************************************************/
/** %PIRW% */
/** Historia ******************************************************************************/
/** %PL% */
/******************************************************************************************/

