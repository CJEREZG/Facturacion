
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
           char  filnam[14];
};
static const struct sqlcxp sqlfpn =
{
    13,
    "./pc/GenFA.pc"
};


static unsigned int sqlctx = 430979;


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
   unsigned char  *sqhstv[45];
   unsigned long  sqhstl[45];
            int   sqhsts[45];
            short *sqindv[45];
            int   sqinds[45];
   unsigned long  sqharm[45];
   unsigned long  *sqharc[45];
   unsigned short  sqadto[45];
   unsigned short  sqtdso[45];
} sqlstm = {12,45};

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

 static const char *sq0012 = 
"select NOM_PARAMETRO ,COD_MODULO ,COD_PRODUCTO ,VAL_PARAMETRO  from GED_PARA\
METROS where COD_MODULO=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,66,0,260,80,0,0,5,4,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,2,97,0,0,
40,0,0,2,63,0,260,117,0,0,1,0,0,1,0,2,5,0,0,
59,0,0,3,50,0,260,143,0,0,1,0,0,1,0,2,3,0,0,
78,0,0,4,711,0,260,239,0,0,29,1,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,5,0,0,1,3,0,0,
209,0,0,5,693,0,260,425,0,0,27,1,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,
0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,1,3,0,0,
332,0,0,6,139,0,260,542,0,0,4,1,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,1,3,0,0,
363,0,0,7,134,0,260,591,0,0,5,1,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,3,0,0,
398,0,0,8,78,0,261,637,0,0,2,2,0,1,0,1,3,0,0,1,5,0,0,
421,0,0,9,921,0,260,720,0,0,26,1,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,1,3,0,0,
540,0,0,10,757,0,260,1001,0,0,38,0,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,4,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,
2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
707,0,0,11,528,0,260,1128,0,0,23,0,0,1,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,
814,0,0,12,114,0,265,1232,0,0,1,1,0,1,0,1,5,0,0,
833,0,0,12,0,0,269,1242,0,0,4,0,0,1,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,
864,0,0,12,0,0,271,1271,0,0,0,0,0,1,0,
879,0,0,13,200,0,260,1496,0,0,9,8,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
930,0,0,14,0,0,273,1538,0,0,1,1,0,1,0,1,97,0,0,
949,0,0,14,0,0,301,1564,0,0,0,0,0,1,0,
964,0,0,14,0,0,269,1576,0,0,1,0,0,1,0,2,3,0,0,
983,0,0,14,0,0,271,1588,0,0,0,0,0,1,0,
998,0,0,15,491,0,260,1820,0,0,12,2,0,1,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,
0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,1,97,0,0,1,3,0,0,
1061,0,0,16,211,0,260,1931,0,0,4,3,0,1,0,2,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1092,0,0,17,211,0,260,1940,0,0,4,3,0,1,0,2,4,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1123,0,0,18,275,0,260,2329,0,0,5,3,0,1,0,2,3,0,0,2,5,0,0,1,3,0,0,1,5,0,0,1,5,0,
0,
1158,0,0,19,170,0,260,2382,0,0,4,3,0,1,0,2,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,
1189,0,0,20,106,0,261,2454,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
1212,0,0,21,127,0,261,2463,0,0,3,3,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,
1239,0,0,22,464,0,260,2635,0,0,16,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,1,3,0,0,
1318,0,0,23,380,0,259,2810,0,0,15,15,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,
1393,0,0,24,125,0,260,2931,0,0,3,2,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,
1420,0,0,25,155,0,260,3034,0,0,3,2,0,1,0,2,3,0,0,1,5,0,0,1,3,0,0,
1447,0,0,26,49,0,260,3198,0,0,1,0,0,1,0,2,3,0,0,
1466,0,0,27,51,0,260,3203,0,0,1,0,0,1,0,2,3,0,0,
1485,0,0,28,54,0,260,3208,0,0,1,0,0,1,0,2,3,0,0,
1504,0,0,29,48,0,260,3213,0,0,1,0,0,1,0,2,3,0,0,
1523,0,0,30,51,0,260,3218,0,0,1,0,0,1,0,2,3,0,0,
1542,0,0,31,50,0,260,3223,0,0,1,0,0,1,0,2,3,0,0,
1561,0,0,32,55,0,260,3228,0,0,1,0,0,1,0,2,3,0,0,
1580,0,0,33,54,0,260,3233,0,0,1,0,0,1,0,2,3,0,0,
1599,0,0,34,48,0,260,3238,0,0,1,0,0,1,0,2,3,0,0,
1618,0,0,35,77,0,260,3300,0,0,3,2,0,1,0,1,5,0,0,1,5,0,0,2,3,0,0,
1645,0,0,36,178,0,260,3598,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
1672,0,0,37,158,0,260,3620,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,
1699,0,0,38,924,0,259,3876,0,0,45,45,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,97,0,0,1,97,0,0,1,97,
0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,4,0,
0,1,4,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,
1894,0,0,39,128,0,260,4021,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
1917,0,0,40,130,0,260,4030,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
1940,0,0,41,132,0,260,4039,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
1963,0,0,42,130,0,260,4048,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
1986,0,0,43,286,0,260,4097,0,0,7,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,1,3,0,0,
2029,0,0,44,701,0,260,4324,0,0,27,1,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,
5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
2,5,0,0,2,5,0,0,1,3,0,0,
2152,0,0,45,321,0,260,4555,0,0,9,2,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,1,3,0,0,1,3,0,0,
2203,0,0,46,198,0,260,4838,0,0,7,1,0,1,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,5,0,0,1,3,0,0,
2246,0,0,47,199,0,260,4852,0,0,7,1,0,1,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,5,0,0,1,3,0,0,
2289,0,0,48,125,0,260,4865,0,0,7,1,0,1,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,5,0,0,1,3,0,0,
2332,0,0,49,172,0,260,4885,0,0,6,1,0,1,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,1,3,0,0,
2371,0,0,50,0,0,273,4981,0,0,1,1,0,1,0,1,9,0,0,
2390,0,0,50,0,0,301,4995,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
2413,0,0,50,0,0,269,5005,0,0,8,0,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,
2,5,0,0,2,3,0,0,2,5,0,0,
2460,0,0,50,0,0,269,5017,0,0,6,0,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,
2,5,0,0,
2499,0,0,50,0,0,271,5063,0,0,0,0,0,1,0,
2514,0,0,51,154,0,260,5091,0,0,4,1,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,1,3,0,0,
2545,0,0,52,0,0,273,5171,0,0,1,1,0,1,0,1,97,0,0,
2564,0,0,52,0,0,277,5178,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,0,
0,
2599,0,0,53,160,0,261,5188,0,0,5,5,0,1,0,1,3,0,0,1,3,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,
2634,0,0,54,924,0,260,5277,0,0,27,2,0,1,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,
0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,
5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,1,3,0,0,1,3,0,0,
2757,0,0,55,138,0,260,5404,0,0,6,5,0,1,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,1,5,0,
0,2,5,0,0,
2796,0,0,56,63,0,260,5526,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
2819,0,0,57,90,0,260,5623,0,0,3,2,0,1,0,2,5,0,0,1,3,0,0,1,3,0,0,
2846,0,0,58,69,0,260,5695,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
2869,0,0,59,301,0,260,5764,0,0,5,1,0,1,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,1,5,0,
0,
2904,0,0,60,92,0,260,5890,0,0,3,1,0,1,0,2,5,0,0,2,3,0,0,1,3,0,0,
2931,0,0,61,363,0,260,5976,0,0,10,2,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,97,0,0,2,3,0,0,2,4,0,0,1,97,0,0,1,97,0,0,
};


/*****************************************************************************/
/* Fichero:      GenFa.pc                                                    */
/* Descripcion:  Funciones generales del Modulo de Facturacion.              */
/* Fecha:        30/01/96                                                    */
/* Autor:        Javier Garcia Paredes                                       */

/******************************************************************************/
/*****************************************************************************/
/*  -PGonzaleg 26-02-2002                                                    */
/*      Modificacion referente al cambio en el tipo de dato                  */
/*      del campo NumUnidades.   int ---> long                               */
/*****************************************************************************/
/*  -PGonzaleg 14-03-2002                                                    */
/*      Incorporacion del campo szhCodIdioma para el                         */
/*      manejo de multi idiomas                                              */
/*****************************************************************************/
/*  -PGonzaleg 8-04-2002                                                     */
/*      Incorporacion de una nueva funcion (bfnGetDir_Formato) para          */
/*      el manejo del formato de direcciones ademas de la funcion            */
/*      fnQuitaBlancos para la eliminacion de caracteres blancos             */
/*****************************************************************************/
/*  -PGonzaleg 1-08-2002                                                     */
/*      Modificacion del largo del los campos "Codigo de Banco"              */
/*****************************************************************************/
#define _GENFA_PC_

#include <GenFA.h>

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


/*****************************************************************************/
/* Se quitan los blancos de la derecha                                       */
/*****************************************************************************/

char * fnQuitaBlancos(char s[])
{
        int i,indice=0;

        for (i=0;i<strlen(s) && s[i]!='\0';i++)
        {
                if (s[i] != ' ')
                        indice = i;
        }
        s[indice+1] = '\0';
        return s;
}/************************* Final  alm_trim **********************************/

/* ------------------------------------------------------------------------------------ */
/*   bfnGetDir_Formato (char*)                                                      */
/*      Valor Entrada (P/E): "4:PALACIO ;5:RIESCO::4005;6:.;3:;2:13339;1:1312;0:131;"   */
/*      Valor Retorno:(P/E): "PALACIO ;RIESCO 4005;.;;13339;1312;131;"              */
/*      Llamada            : strcpy(prueba, (char *)bfnGetDir_Formato(2003,1,1,2)); */
/* ------------------------------------------------------------------------------------ */
BOOL bfnGetDir_Formato (long  lCodCliente, int iCodTipSujeto, int iCodTipDireccion, int iCodDisplay, char * Imprime)
{
    char    modulo[20];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long    lhCodCliente;       /* Cod Cliente */
        int     ihCodTipSujeto;     /* Tipo del sujeto (cliente o usuario) En erste caso = 1 */
        int     ihCodTipDireccion;  /* Tipo de direccion - de Facturacion, de Correspondencia, de ...*/
        int     ihCodDisplay;       /* 1 o 2   En este caso = 2*/
        char    szhRetorno[250];
    /* EXEC SQL END DECLARE SECTION; */ 



    vDTrazasLog  ( modulo , "\n\t\t* -----------------------------------------------"
                            "\n\t\t* bfnGetDir_Formato  "
                            "\n\t\t* Cliente         :  [%d]"
                            "\n\t\t* Tip sujeto      :  [%d]"
                            "\n\t\t* Tip direccion   :  [%d]"
                            "\n\t\t* Cod Display     :  [%d]"
                            ,LOG05,lCodCliente,iCodTipSujeto,iCodTipDireccion,iCodDisplay);

    lhCodCliente = lCodCliente;
    ihCodTipSujeto = iCodTipSujeto;
    ihCodTipDireccion = iCodTipDireccion;
    ihCodDisplay = iCodDisplay;

    /* EXEC SQL SELECT GE_FN_OBTIENE_DIRCLIE (:lhCodCliente,:ihCodTipSujeto,:ihCodTipDireccion,:ihCodDisplay)
         INTO :szhRetorno
         FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select GE_FN_OBTIENE_DIRCLIE(:b0,:b1,:b2,:b3) into :b4  f\
rom DUAL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&ihCodTipSujeto;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihCodTipDireccion;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCodDisplay;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhRetorno;
    sqlstm.sqhstl[4] = (unsigned long )250;
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




    vDTrazasLog  ( modulo , "\n\t\t* Retorno Query  :  [%d]\n",LOG05,sqlca.sqlcode);

    if (SQLCODE)
    {
        vDTrazasLog  ( modulo , "\n\t\t* Error Query    :  [%d]\n",LOG03,sqlca.sqlcode);

        fprintf ( stderr, "Error al ejecutar Procedimiento almacenado [%d]\n", sqlca.sqlcode);
        strcpy(Imprime, "\0");
        return (FALSE);
    }
    else
    {
     strcpy(Imprime,szhRetorno);
     return TRUE;
    }


}/************************* Final  bfnGetDir_Formato********************************/


/* -------------------------------------------------------------------------- */
/*   bGetSysDate (char*)                                                      */
/*      Valores Retorno: FALSE - Error                                        */
/*                       TRUE  - Ningun Error                                 */
/* -------------------------------------------------------------------------- */
BOOL bGetSysDate (char* szFecSysDate)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

       char* pszhFecSysDate; /* EXEC SQL VAR pszhFecSysDate IS STRING (15); */ 

  /* EXEC SQL END DECLARE SECTION; */ 


  pszhFecSysDate = szFecSysDate;
  /* EXEC SQL SELECT TO_CHAR(SYSDATE,'yyyymmddhh24miss')
           INTO :pszhFecSysDate
           FROM DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select TO_CHAR(SYSDATE,'yyyymmddhh24miss') into :b0  from D\
UAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )40;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)pszhFecSysDate;
  sqlstm.sqhstl[0] = (unsigned long )15;
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
     iDError(szExeName,ERR000,vInsertarIncidencia,
             "SysDate-Dual",szfnORAerror());
     return FALSE;
  }
  return TRUE;
}/************************* Final bGetSysDate ********************************/

/* -------------------------------------------------------------------------- */
/*   bGetNumProceso (long*)                                                   */
/*      Devuelve en iNumPresupuesto el numero de presupuesto tomado           */
/*      de la secuencia FA_NUMPRESUPUESTO                                     */
/*      Valores retorno: FALSE  Error Oracle                                  */
/*                       TRUE   Ningun error                                  */
/* -------------------------------------------------------------------------- */
BOOL bGetNumProceso (long* lNumProceso)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

       static long lhNumProceso;
  /* EXEC SQL END DECLARE SECTION; */ 



  /* EXEC SQL SELECT FA_SEQ_NUMPRO.NEXTVAL INTO :lhNumProceso
          FROM DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select FA_SEQ_NUMPRO.nextval  into :b0  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
     iDError (szExeName,ERR000,vInsertarIncidencia,
          "Secuencia->Fa_Seq_NumPro",szfnORAerror());
     return FALSE;
  }
  vDTrazasLog (szExeName,"\n\t\t* Valor de numero de proceso......[%ld]",
           LOG06,lhNumProceso);
  *lNumProceso = lhNumProceso;
  return TRUE;
}/************************** Final bGetNumProceso ****************************/


/*****************************************************************************/
/*                         funcion : bGetVenta                               */
/* -Funcion que recupera un reg. de la table Ga_Ventas con lNumVenta         */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
BOOL bGetVenta (VENTAS *pVenta)
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static char* szhRowid           ;/* EXEC SQL VAR szhRowid          IS STRING(19); */ 

 static long  lhNumVenta         ;
 static short shCodProducto      ;
 static char* szhCodOficina      ;/* EXEC SQL VAR szhCodOficina     IS STRING(3) ; */ 

 static long  lhCodVendedor      ;
 static long  lhCodVendedorAgente;
 static int   ihNumUnidades      ;
 static char* szhFecVenta        ;/* EXEC SQL VAR szhFecVenta       IS STRING(15); */ 

 static char* szhCodRegion       ;/* EXEC SQL VAR szhCodRegion      IS STRING(4) ; */ 

 static char* szhCodProvincia    ;/* EXEC SQL VAR szhCodProvincia   IS STRING(6) ; */ 

 static char* szhCodCiudad       ;/* EXEC SQL VAR szhCodCiudad      IS STRING(6) ; */ 

 static char* szhIndEstVenta     ;/* EXEC SQL VAR szhIndEstVenta    IS STRING(2) ; */ 

 static char* szhCodTipContrato  ;/* EXEC SQL VAR szhCodTipContrato IS STRING(4) ; */ 

 static short shIndTipVenta      ;
 static long  lhCodCliente       ;
 static int   ihCodModVenta      ;
 static int   ihTipValor         ;
 static long  lhNumTransaccion   ;
 static char* szhCodCuota        ;/* EXEC SQL VAR szhCodCuota       IS STRING(3) ; */ 

 static char* szhCodTipTarjeta   ;/* EXEC SQL VAR szhCodTipTarjeta  IS STRING(4) ; */ 

 static char* szhNumTarjeta      ;/* EXEC SQL VAR szhNumTarjeta     IS STRING(19); */ 

 static char* szhCodAutTarj      ;/* EXEC SQL VAR szhCodAutTarj     IS STRING(21); */ 

 static char* szhFecVenciTarj    ;/* EXEC SQL VAR szhFecVenciTarj   IS STRING(15); */ 


 static char* szhCodBancoTarj    ;/* EXEC SQL VAR szhCodBancoTarj   IS STRING(16) ; */ 


 static char* szhNumCtaCorr      ;/* EXEC SQL VAR szhNumCtaCorr     IS STRING(19); */ 

 static char* szhNumCheque       ;/* EXEC SQL VAR szhNumCheque      IS STRING(21); */ 


 static char* szhCodBanco        ;/* EXEC SQL VAR szhCodBanco       IS STRING(16) ; */ 


 static char* szhCodSucursal     ;/* EXEC SQL VAR szhCodSucursal    IS STRING(5) ; */ 

 static short i_shCodTipContrato ;
 static short i_shIndTipVenta    ;
 static short i_shCodCliente     ;
 static short i_shCodModVenta    ;
 static short i_shTipValor       ;
 static short i_shCodCuota       ;
 static short i_shCodTipTarjeta  ;
 static short i_shCodAutTarj     ;
 static short i_shNumTarjeta     ;
 static short i_shFecVenciTarj   ;
 static short i_shCodBancoTarj   ;
 static short i_shNumCtaCorr     ;
 static short i_shNumCheque      ;
 static short i_shCodBanco       ;
 static short i_shCodSucursal    ;
 /* EXEC SQL END DECLARE SECTION    ; */ 


 lhNumVenta       = pVenta->lNumVenta       ;
 szhRowid         = pVenta->szRowid         ;
 szhCodOficina    = pVenta->szCodOficina    ;
 szhFecVenta      = pVenta->szFecVenta      ;
 szhCodRegion     = pVenta->szCodRegion     ;
 szhCodProvincia  = pVenta->szCodProvincia  ;
 szhCodCiudad     = pVenta->szCodCiudad     ;
 szhIndEstVenta   = pVenta->szIndEstVenta   ;
 szhCodTipContrato= pVenta->szCodTipContrato;
 szhCodCuota      = pVenta->szCodCuota      ;
 szhCodTipTarjeta = pVenta->szCodTipTarjeta ;
 szhNumTarjeta    = pVenta->szNumTarjeta    ;
 szhCodAutTarj    = pVenta->szCodAutTarj    ;
 szhFecVenciTarj  = pVenta->szFecVenciTarj  ;
 szhCodBancoTarj  = pVenta->szCodBancoTarj  ;
 szhNumCtaCorr    = pVenta->szNumCtaCorr    ;
 szhNumCheque     = pVenta->szNumCheque     ;
 szhCodBanco      = pVenta->szCodBanco      ;
 szhCodSucursal   = pVenta->szCodSucursal   ;

 vDTrazasLog (szExeName,"\n\t\t* Parametro Ga_Ventas\n"
                        "\t\t* NumVenta [%ld]\n",LOG05,lhNumVenta);


 /* EXEC SQL SELECT /o+ index (GA_VENTAS PK_GA_VENTAS) o/
                 ROWID                                     ,
                 NUM_VENTA                                 ,
                 NUM_TRANSACCION                           ,
                 COD_PRODUCTO                              ,
                 COD_OFICINA                               ,
                 COD_VENDEDOR                              ,
                 COD_VENDEDOR_AGENTE                       ,
                 NUM_UNIDADES                              ,
                 TO_CHAR (FEC_VENTA,'YYYYMMDDHH24MISS')    ,
                 COD_REGION                                ,
                 COD_PROVINCIA                             ,
                 COD_CIUDAD                                ,
                 IND_ESTVENTA                              ,
                 COD_TIPCONTRATO                           ,
                 IND_TIPVENTA                              ,
                 COD_CLIENTE                               ,
                 COD_MODVENTA                              ,
                 TIP_VALOR                                 ,
                 COD_CUOTA                                 ,
                 COD_TIPTARJETA                            ,
                 NUM_TARJETA                               ,
                 COD_AUTTARJ                               ,
                 TO_CHAR (FEC_VENCITARJ,'YYYYMMDDHH24MISS'),
                 COD_BANCOTARJ                             ,
                 NUM_CTACORR                               ,
                 NUM_CHEQUE                                ,
                 COD_BANCO                                 ,
                 COD_SUCURSAL
           INTO  :szhRowid                                 ,
                 :lhNumVenta                               ,
                 :lhNumTransaccion                         ,
                 :shCodProducto                            ,
                 :szhCodOficina                            ,
                 :lhCodVendedor                            ,
                 :lhCodVendedorAgente                      ,
                 :ihNumUnidades                            ,
                 :szhFecVenta                              ,
                 :szhCodRegion                             ,
                 :szhCodProvincia                          ,
                 :szhCodCiudad                             ,
                 :szhIndEstVenta                           ,
                 :szhCodTipContrato:i_shCodTipContrato     ,
                 :shIndTipVenta:i_shIndTipVenta            ,
                 :lhCodCliente:i_shCodCliente              ,
                 :ihCodModVenta:i_shCodModVenta            ,
                 :ihTipValor:i_shTipValor                  ,
                 :szhCodCuota:i_shCodCuota                 ,
                 :szhCodTipTarjeta:i_shCodTipTarjeta       ,
                 :szhNumTarjeta:i_shNumTarjeta             ,
                 :szhCodAutTarj:i_shCodAutTarj             ,
                 :szhFecVenciTarj:i_shFecVenciTarj         ,
                 :szhCodBancoTarj:i_shCodBancoTarj         ,
                 :szhNumCtaCorr:i_shNumCtaCorr             ,
                 :szhNumCheque:i_shNumCheque               ,
                 :szhCodBanco:i_shCodBanco                 ,
                 :szhCodSucursal:i_shCodSucursal
           FROM  GA_VENTAS
           WHERE NUM_VENTA = :lhNumVenta; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select  /*+  index (GA_VENTAS PK_GA_VENTAS)  +*/ ROWID ,NUM_\
VENTA ,NUM_TRANSACCION ,COD_PRODUCTO ,COD_OFICINA ,COD_VENDEDOR ,COD_VENDEDOR_\
AGENTE ,NUM_UNIDADES ,TO_CHAR(FEC_VENTA,'YYYYMMDDHH24MISS') ,COD_REGION ,COD_P\
ROVINCIA ,COD_CIUDAD ,IND_ESTVENTA ,COD_TIPCONTRATO ,IND_TIPVENTA ,COD_CLIENTE\
 ,COD_MODVENTA ,TIP_VALOR ,COD_CUOTA ,COD_TIPTARJETA ,NUM_TARJETA ,COD_AUTTARJ\
 ,TO_CHAR(FEC_VENCITARJ,'YYYYMMDDHH24MISS') ,COD_BANCOTARJ ,NUM_CTACORR ,NUM_C\
HEQUE ,COD_BANCO ,COD_SUCURSAL into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b\
10,:b11,:b12,:b13:b14,:b15:b16,:b17:b18,:b19:b20,:b21:b22,:b23:b24,:b25:b26,:b\
27:b28,:b29:b30,:b31:b32,:b33:b34,:b35:b36,:b37:b38,:b39:b40,:b41:b42  from GA\
_VENTAS where NUM_VENTA=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )78;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&lhNumVenta;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&lhNumTransaccion;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
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
 sqlstm.sqhstv[4] = (unsigned char  *)szhCodOficina;
 sqlstm.sqhstl[4] = (unsigned long )3;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&lhCodVendedor;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&lhCodVendedorAgente;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&ihNumUnidades;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)szhFecVenta;
 sqlstm.sqhstl[8] = (unsigned long )15;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)szhCodRegion;
 sqlstm.sqhstl[9] = (unsigned long )4;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)szhCodProvincia;
 sqlstm.sqhstl[10] = (unsigned long )6;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)szhCodCiudad;
 sqlstm.sqhstl[11] = (unsigned long )6;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)szhIndEstVenta;
 sqlstm.sqhstl[12] = (unsigned long )2;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)szhCodTipContrato;
 sqlstm.sqhstl[13] = (unsigned long )4;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&i_shCodTipContrato;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&shIndTipVenta;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&i_shIndTipVenta;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&lhCodCliente;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&i_shCodCliente;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&ihCodModVenta;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&i_shCodModVenta;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&ihTipValor;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&i_shTipValor;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)szhCodCuota;
 sqlstm.sqhstl[18] = (unsigned long )3;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&i_shCodCuota;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)szhCodTipTarjeta;
 sqlstm.sqhstl[19] = (unsigned long )4;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&i_shCodTipTarjeta;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)szhNumTarjeta;
 sqlstm.sqhstl[20] = (unsigned long )19;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&i_shNumTarjeta;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)szhCodAutTarj;
 sqlstm.sqhstl[21] = (unsigned long )21;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&i_shCodAutTarj;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)szhFecVenciTarj;
 sqlstm.sqhstl[22] = (unsigned long )15;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&i_shFecVenciTarj;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)szhCodBancoTarj;
 sqlstm.sqhstl[23] = (unsigned long )16;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&i_shCodBancoTarj;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)szhNumCtaCorr;
 sqlstm.sqhstl[24] = (unsigned long )19;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&i_shNumCtaCorr;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)szhNumCheque;
 sqlstm.sqhstl[25] = (unsigned long )21;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&i_shNumCheque;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)szhCodBanco;
 sqlstm.sqhstl[26] = (unsigned long )16;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&i_shCodBanco;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)szhCodSucursal;
 sqlstm.sqhstl[27] = (unsigned long )5;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&i_shCodSucursal;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&lhNumVenta;
 sqlstm.sqhstl[28] = (unsigned long )sizeof(long);
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


    if (SQLCODE)
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ga_Ventas",
                 szfnORAerror());

    if (SQLCODE == 0)
    {
        pVenta->lNumVenta         = lhNumVenta         ;
        pVenta->lNumTransaccion   = lhNumTransaccion   ;
        pVenta->iCodProducto      = shCodProducto      ;
        pVenta->lCodVendedor      = lhCodVendedor      ;
        pVenta->lCodVendedorAgente= lhCodVendedorAgente;
        pVenta->iNumUnidades      = ihNumUnidades      ;
        if (i_shCodTipContrato == ORA_NULL)
            pVenta->szCodTipContrato[0] = 0;
        pVenta->iIndTipVenta = (i_shIndTipVenta == ORA_NULL)?-1:shIndTipVenta;
        pVenta->lCodCliente  = (i_shCodCliente  == ORA_NULL)?-1:lhCodCliente ;
        pVenta->iCodModVenta = (i_shCodModVenta == ORA_NULL)?-1:ihCodModVenta;
        pVenta->iTipValor    = (i_shTipValor    == ORA_NULL)?-1:ihTipValor   ;
        if (i_shCodCuota == ORA_NULL)
            pVenta->szCodCuota[0] = 0;
        if (i_shCodTipTarjeta== ORA_NULL)
            pVenta->szCodTipTarjeta[0] = 0;
        if (i_shNumTarjeta == ORA_NULL)
            pVenta->szNumTarjeta[0] = 0;
        if (i_shCodAutTarj == ORA_NULL)
            pVenta->szCodAutTarj[0] = 0;
        if (i_shFecVenciTarj== ORA_NULL)
            pVenta->szFecVenciTarj[0] = 0;
        if (i_shCodBancoTarj == ORA_NULL)
            pVenta->szCodBancoTarj[0] = 0;
        if (i_shNumCtaCorr == ORA_NULL)
            pVenta->szNumCtaCorr[0] = 0;
        if (i_shNumCheque == ORA_NULL)
            pVenta->szNumCheque[0] = 0;
        if (i_shCodBanco == ORA_NULL)
            pVenta->szCodBanco[0] = 0;
        if (i_shCodSucursal == ORA_NULL)
            pVenta->szCodSucursal[0] = 0;

    }
    return (SQLCODE != 0)?FALSE:TRUE;
}/************************* Final vGetVenta **********************************/


/*****************************************************************************/
/*                         funcion : bGetTransContado                        */
/* -Funcion que recupera un reg. de la table Ga_TransContado con lNumTrans   */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
BOOL bGetTransContado (TRANSCONTADO *pTranC)
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static char*  szhRowid           ;/* EXEC SQL VAR szhRowid          IS STRING(19); */ 

 static long   lhNumTransaccion   ;
 static long   lhCodVendedorAgente;
 static short  shCodProducto      ;
 static char*  szhCodOficina      ;/* EXEC SQL VAR szhCodOficina     IS STRING(3) ; */ 

 static int    ihNumUnidades      ;
 static char*  szhFecTransaccion  ;/* EXEC SQL VAR szhFecTransaccion IS STRING(15); */ 

 static char*  szhCodRegion       ;/* EXEC SQL VAR szhCodRegion      IS STRING(4) ; */ 

 static char*  szhCodProvincia    ;/* EXEC SQL VAR szhCodProvincia   IS STRING(6) ; */ 

 static char*  szhCodCiudad       ;/* EXEC SQL VAR szhCodCiudad      IS STRING(6) ; */ 

 static double dhImpVenta         ;
 static char*  szhCodMoneda       ;/* EXEC SQL VAR szhCodMoneda      IS STRING(4) ; */ 

 static short  shIndPasoCob       ;
 static char*  szhNomUsuarOra     ;/* EXEC SQL VAR szhNomUsuarOra    IS STRING(31); */ 

 static long   lhCodCliente       ;
 static int    ihTipValor         ;
 static char*  szhCodCuota        ;/* EXEC SQL VAR szhCodCuota       IS STRING(3) ; */ 

 static char*  szhCodTipTarjeta   ;/* EXEC SQL VAR szhCodTipTarjeta  IS STRING(4) ; */ 

 static char*  szhNumTarjeta      ;/* EXEC SQL VAR szhNumTarjeta     IS STRING(19); */ 

 static char*  szhCodAutTarj      ;/* EXEC SQL VAR szhCodAutTarj     IS STRING(21); */ 

 static char*  szhFecVenciTarj    ;/* EXEC SQL VAR szhFecVenciTarj   IS STRING(15); */ 


 /* Desde Aqui. Modificacion Incorporada por PGonzaleg 1-08-2002    */
 /*static char*  szhCodBancoTarj    ;EXEC SQL VAR szhCodBancoTarj   IS STRING(4) ;*/
 static char*  szhCodBancoTarj    ;/* EXEC SQL VAR szhCodBancoTarj   IS STRING(16) ; */ 

 /* Hasta Aqui. Modificacion Incorporada por PGonzaleg 1-08-2002    */

 static char*  szhNumCtaCorr      ;/* EXEC SQL VAR szhNumCtaCorr     IS STRING(19); */ 

 static char*  szhNumCheque       ;/* EXEC SQL VAR szhNumCheque      IS STRING(21); */ 


 /* Desde Aqui. Modificacion Incorporada por PGonzaleg 1-08-2002    */
 /*static char*  szhCodBanco        ;EXEC SQL VAR szhCodBanco       IS STRING(4) ;*/
 static char*  szhCodBanco        ;/* EXEC SQL VAR szhCodBanco       IS STRING(16) ; */ 

 /* Hasta Aqui. Modificacion Incorporada por PGonzaleg 1-08-2002    */

 static char*  szhCodSucursal     ;/* EXEC SQL VAR szhCodSucursal    IS STRING(5) ; */ 

 static short  i_shCodCliente     ;
 static short  i_shTipValor       ;
 static short  i_shCodCuota       ;
 static short  i_shCodTipTarjeta  ;
 static short  i_shCodAutTarj     ;
 static short  i_shNumTarjeta     ;
 static short  i_shFecVenciTarj   ;
 static short  i_shCodBancoTarj   ;
 static short  i_shNumCtaCorr     ;
 static short  i_shNumCheque      ;
 static short  i_shCodBanco       ;
 static short  i_shCodSucursal    ;
 static short  i_shImpVenta       ;
 static short  i_shCodMoneda      ;
 /* EXEC SQL END DECLARE SECTION    ; */ 


 lhNumTransaccion = pTranC->lNumTransaccion ;
 szhRowid         = pTranC->szRowid         ;
 szhCodOficina    = pTranC->szCodOficina    ;
 szhFecTransaccion= pTranC->szFecTransaccion;
 szhCodRegion     = pTranC->szCodRegion     ;
 szhCodProvincia  = pTranC->szCodProvincia  ;
 szhCodCiudad     = pTranC->szCodCiudad     ;
 szhCodCuota      = pTranC->szCodCuota      ;
 szhCodTipTarjeta = pTranC->szCodTipTarjeta ;
 szhNumTarjeta    = pTranC->szNumTarjeta    ;
 szhCodAutTarj    = pTranC->szCodAutTarj    ;
 szhFecVenciTarj  = pTranC->szFecVenciTarj  ;
 szhCodBancoTarj  = pTranC->szCodBancoTarj  ;
 szhNumCtaCorr    = pTranC->szNumCtaCorr    ;
 szhNumCheque     = pTranC->szNumCheque     ;
 szhCodBanco      = pTranC->szCodBanco      ;
 szhCodSucursal   = pTranC->szCodSucursal   ;
 szhCodMoneda     = pTranC->szCodMoneda     ;

 vDTrazasLog (szExeName,"\n\t\t* Parametro Ga_TransContado\n"
                        "\t\t* NumTransaccion [%ld]\n",LOG05,lhNumTransaccion);


 /* EXEC SQL SELECT /o+ index (GA_TRANSCONTADO PK_GA_TRANSCONTADO) o/
                 ROWID                                       ,
                 NUM_TRANSACCION                             ,
                 COD_PRODUCTO                                ,
                 COD_OFICINA                                 ,
                 COD_VENDEDOR_AGENTE                         ,
                 NUM_UNIDADES                                ,
                 TO_CHAR (FEC_TRANSACCION,'YYYYMMDDHH24MISS'),
                 COD_REGION                                  ,
                 COD_PROVINCIA                               ,
                 COD_CIUDAD                                  ,
                 IMP_VENTA                                   ,
                 COD_MONEDA                                  ,
                 IND_PASOCOB                                 ,
                 NOM_USUARORA                                ,
                 COD_CLIENTE                                 ,
                 TIP_VALOR                                   ,
                 COD_CUOTA                                   ,
                 COD_TIPTARJETA                              ,
                 NUM_TARJETA                                 ,
                 COD_AUTTARJ                                 ,
                 TO_CHAR (FEC_VENCITARJ,'YYYYMMDDHH24MISS')  ,
                 COD_BANCOTARJ                               ,
                 NUM_CTACORR                                 ,
                 NUM_CHEQUE                                  ,
                 COD_BANCO                                   ,
                 COD_SUCURSAL
           INTO  :szhRowid                                 ,
                 :lhNumTransaccion                         ,
                 :shCodProducto                            ,
                 :szhCodOficina                            ,
                 :lhCodVendedorAgente                      ,
                 :ihNumUnidades                            ,
                 :szhFecTransaccion                        ,
                 :szhCodRegion                             ,
                 :szhCodProvincia                          ,
                 :szhCodCiudad                             ,
                 :dhImpVenta:i_shImpVenta                  ,
                 :szhCodMoneda:i_shCodMoneda               ,
                 :shIndPasoCob                             ,
                 :szhNomUsuarOra                           ,
                 :lhCodCliente:i_shCodCliente              ,
                 :ihTipValor:i_shTipValor                  ,
                 :szhCodCuota:i_shCodCuota                 ,
                 :szhCodTipTarjeta:i_shCodTipTarjeta       ,
                 :szhNumTarjeta:i_shNumTarjeta             ,
                 :szhCodAutTarj:i_shCodAutTarj             ,
                 :szhFecVenciTarj:i_shFecVenciTarj         ,
                 :szhCodBancoTarj:i_shCodBancoTarj         ,
                 :szhNumCtaCorr:i_shNumCtaCorr             ,
                 :szhNumCheque:i_shNumCheque               ,
                 :szhCodBanco:i_shCodBanco                 ,
                 :szhCodSucursal:i_shCodSucursal
           FROM  GA_TRANSCONTADO
           WHERE NUM_TRANSACCION = :lhNumTransaccion; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 29;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select  /*+  index (GA_TRANSCONTADO PK_GA_TRANSCONTADO)  +*/\
 ROWID ,NUM_TRANSACCION ,COD_PRODUCTO ,COD_OFICINA ,COD_VENDEDOR_AGENTE ,NUM_U\
NIDADES ,TO_CHAR(FEC_TRANSACCION,'YYYYMMDDHH24MISS') ,COD_REGION ,COD_PROVINCI\
A ,COD_CIUDAD ,IMP_VENTA ,COD_MONEDA ,IND_PASOCOB ,NOM_USUARORA ,COD_CLIENTE ,\
TIP_VALOR ,COD_CUOTA ,COD_TIPTARJETA ,NUM_TARJETA ,COD_AUTTARJ ,TO_CHAR(FEC_VE\
NCITARJ,'YYYYMMDDHH24MISS') ,COD_BANCOTARJ ,NUM_CTACORR ,NUM_CHEQUE ,COD_BANCO\
 ,COD_SUCURSAL into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10:b11,:b12:b13,\
:b14,:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:b26:b27,:b28:b29,:b30:\
b31,:b32:b33,:b34:b35,:b36:b37,:b38:b39  from GA_TRANSCONTADO where NUM_TRANSA\
CCION=:b1";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )209;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&lhNumTransaccion;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&shCodProducto;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szhCodOficina;
 sqlstm.sqhstl[3] = (unsigned long )3;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&lhCodVendedorAgente;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&ihNumUnidades;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)szhFecTransaccion;
 sqlstm.sqhstl[6] = (unsigned long )15;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)szhCodRegion;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)szhCodProvincia;
 sqlstm.sqhstl[8] = (unsigned long )6;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)szhCodCiudad;
 sqlstm.sqhstl[9] = (unsigned long )6;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&dhImpVenta;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&i_shImpVenta;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)szhCodMoneda;
 sqlstm.sqhstl[11] = (unsigned long )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&i_shCodMoneda;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&shIndPasoCob;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)szhNomUsuarOra;
 sqlstm.sqhstl[13] = (unsigned long )31;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)0;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&lhCodCliente;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&i_shCodCliente;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&ihTipValor;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&i_shTipValor;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)szhCodCuota;
 sqlstm.sqhstl[16] = (unsigned long )3;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&i_shCodCuota;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)szhCodTipTarjeta;
 sqlstm.sqhstl[17] = (unsigned long )4;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&i_shCodTipTarjeta;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)szhNumTarjeta;
 sqlstm.sqhstl[18] = (unsigned long )19;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&i_shNumTarjeta;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)szhCodAutTarj;
 sqlstm.sqhstl[19] = (unsigned long )21;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&i_shCodAutTarj;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)szhFecVenciTarj;
 sqlstm.sqhstl[20] = (unsigned long )15;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&i_shFecVenciTarj;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)szhCodBancoTarj;
 sqlstm.sqhstl[21] = (unsigned long )16;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&i_shCodBancoTarj;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)szhNumCtaCorr;
 sqlstm.sqhstl[22] = (unsigned long )19;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&i_shNumCtaCorr;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)szhNumCheque;
 sqlstm.sqhstl[23] = (unsigned long )21;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&i_shNumCheque;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)szhCodBanco;
 sqlstm.sqhstl[24] = (unsigned long )16;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&i_shCodBanco;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)szhCodSucursal;
 sqlstm.sqhstl[25] = (unsigned long )5;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&i_shCodSucursal;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&lhNumTransaccion;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
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


    if (SQLCODE)
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ga_TransContado",
                 szfnORAerror());

    if (SQLCODE == 0)
    {
        pTranC->iCodProducto      = shCodProducto      ;
        pTranC->lCodVendedorAgente= lhCodVendedorAgente;
        pTranC->iNumUnidades      = ihNumUnidades      ;
        pTranC->lCodCliente  = (i_shCodCliente  == ORA_NULL)?-1:lhCodCliente ;
        pTranC->iTipValor    = (i_shTipValor    == ORA_NULL)?-1:ihTipValor   ;

        if (i_shCodCuota == ORA_NULL)
            pTranC->szCodCuota[0] = 0;
        if (i_shCodTipTarjeta== ORA_NULL)
            pTranC->szCodTipTarjeta[0] = 0;
        if (i_shNumTarjeta == ORA_NULL)
            pTranC->szNumTarjeta[0] = 0;
        if (i_shCodAutTarj == ORA_NULL)
            pTranC->szCodAutTarj[0] = 0;
        if (i_shFecVenciTarj== ORA_NULL)
            pTranC->szFecVenciTarj[0] = 0;
        if (i_shCodBancoTarj == ORA_NULL)
            pTranC->szCodBancoTarj[0] = 0;
        if (i_shNumCtaCorr == ORA_NULL)
            pTranC->szNumCtaCorr[0] = 0;
        if (i_shNumCheque == ORA_NULL)
            pTranC->szNumCheque[0] = 0;
        if (i_shCodBanco == ORA_NULL)
            pTranC->szCodBanco[0] = 0;
        if (i_shCodSucursal == ORA_NULL)
            pTranC->szCodSucursal[0] = 0;
        if (i_shCodMoneda   == ORA_NULL)
            pTranC->szCodMoneda[0] = 0;
        if (i_shImpVenta    == ORA_NULL)
           pTranC->dImpVenta = -1;

    }
    return (SQLCODE != 0)?FALSE:TRUE;
}/************************* Final vGetTransContado ***************************/


/*****************************************************************************/
/*                        funcion : iGetLocalizacionVentas                   */
/* -Funcion que carga la localizacion de NumVenta (Ga_Ventas)                */
/* -Valores Retorno :Error->FALSE, !Error->TRUE                              */
/*****************************************************************************/
int iGetLocalizacionVenta (long lNumVenta, char *szCodCiudad,
                           char *szCodRegion, char *szCodProvincia)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static long  lhNumVenta     ;
  static char* szhCodCiudad   ; /* EXEC SQL VAR szhCodCiudad    IS STRING(6); */ 

  static char* szhCodRegion   ; /* EXEC SQL VAR szhCodRegion    IS STRING(4); */ 

  static char* szhCodProvincia; /* EXEC SQL VAR szhCodProvincia IS STRING(6); */ 

  /* EXEC SQL END DECLARE SECTION  ; */ 


  lhNumVenta      = lNumVenta     ;
  szhCodCiudad    = szCodCiudad   ;
  szhCodRegion    = szCodRegion   ;
  szhCodProvincia = szCodProvincia;

  /* EXEC SQL SELECT /o+ index (GA_VENTAS PK_GA_VENTAS) o/
                  COD_CIUDAD,COD_REGION,COD_PROVINCIA
           INTO   :szhCodCiudad, :szhCodRegion, :szhCodProvincia
           FROM   GA_VENTAS
           WHERE  NUM_VENTA = :lhNumVenta; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index (GA_VENTAS PK_GA_VENTAS)  +*/ COD_CIUDAD\
 ,COD_REGION ,COD_PROVINCIA into :b0,:b1,:b2  from GA_VENTAS where NUM_VENTA=:\
b3";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )332;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhCodCiudad;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhCodRegion;
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhCodProvincia;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&lhNumVenta;
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


  if (SQLCODE != 0)
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ga_Ventas",
               szfnORAerror());

  return SQLCODE;
}/************************** Final iGetLocalizacionVenta *********************/

/*****************************************************************************/
/*                         funcion : iCmpCiclFact                            */
/* -Funcion de comparcion                                                    */
/*****************************************************************************/
int iCmpCiclFact (const void* cad1, const void* cad2)
{
  int rc = 0;

  if ( ((CICLO *)cad1)->lCodCiclFact < ((CICLO *)cad2)->lCodCiclFact)
         rc = -1;
  else if ( ((CICLO *)cad1)->lCodCiclFact > ((CICLO *)cad2)->lCodCiclFact)
         rc =  1;
  else if ( ((CICLO *)cad1)->lCodCiclFact ==((CICLO *)cad2)->lCodCiclFact)
         rc =  0;
  return rc;
}/************************ Final iCmpCiclFact ********************************/

/*****************************************************************************/
/*                          funcion : bfnDBGetCiclo                          */
/*****************************************************************************/
BOOL bfnDBGetCiclo (CICLO *pstCiclo)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char *szhRowid  ; /* EXEC SQL VAR szhRowid IS STRING (19); */ 

  static int   ihCodCiclo;
  static int   ihDigC    ;
  static int   ihDigD    ;
  static int   ihDigSec  ;
  /* EXEC SQL END DECLARE SECTION  ; */ 


  vDTrazasLog (szExeName, "\n\t\t* Select => Fa_Ciclo"
                          "\n\t\t=> Cod.Ciclo [%d]   ", LOG05,
                          pstCiclo->iCodCiclo);

  szhRowid   = pstCiclo->szRowidCiclo;
  ihCodCiclo = pstCiclo->iCodCiclo   ;

  /* EXEC SQL SELECT /o+ index (FA_CICLOS PK_FA_CICLOS) o/
                  ROWID  ,
                  DIG_C  ,
                  DIG_D  ,
                  DIG_SEC
             INTO :szhRowid,
                  :ihDigC  ,
                  :ihDigD  ,
                  :ihDigSec
             FROM FA_CICLOS
            WHERE COD_CICLO = :ihCodCiclo; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 29;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index (FA_CICLOS PK_FA_CICLOS)  +*/ ROWID ,DIG\
_C ,DIG_D ,DIG_SEC into :b0,:b1,:b2,:b3  from FA_CICLOS where COD_CICLO=:b4";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )363;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&ihDigC;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&ihDigD;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&ihDigSec;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&ihCodCiclo;
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



 if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
 {
     iDError (szExeName,ERR000,vInsertarIncidencia,"Select=> Fa_Ciclos",
              szfnORAerror ());
     return  (FALSE)          ;
 }
 else
 {
    pstCiclo->iDigC   = ihDigC     ;
    pstCiclo->iDigD   = ihDigD     ;
    pstCiclo->iDigSec = ihDigSec +1;
 }
 return TRUE;
}/************************* Final bfnDBGetCiclo ******************************/

/*****************************************************************************/
/*                         funcion : bfnDBUpdateCiclo                        */
/* - Update de la Secuencia de Num.CTC                                       */
/*****************************************************************************/
BOOL bfnDBUpdateCiclo (char *szRowid, int iDigSec)
{
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char szhRowid [19];/* EXEC SQL VAR szhRowid IS STRING (19); */ 

   static int  ihDigSec     ;
   /* EXEC SQL END DECLARE SECTION  ; */ 


   strcpy (szhRowid, szRowid);

   ihDigSec = iDigSec        ;

   vDTrazasLog (szExeName, "\n\t\t* Update Fa_Ciclos (Secuencia NumCTC)"
                           "\n\t\t=> Digito Secuencia : [%d]", LOG05,
                           iDigSec);

   /* EXEC SQL UPDATE /o+ Rowid (FA_CICLOS) o/
                   FA_CICLOS SET DIG_SEC = :ihDigSec
             WHERE ROWID = :szhRowid; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 29;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "update  /*+  Rowid (FA_CICLOS)  +*/ FA_CICLOS  set DIG_SEC\
=:b0 where ROWID=:b1";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )398;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&ihDigSec;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
       iDError (szExeName,ERR000,vInsertarIncidencia,"Update=> Fa_Ciclos",
                szfnORAerror ());

   return (SQLCODE)?FALSE:TRUE;
}/************************* Final bfnDBUpdateCiclo ***************************/

/*****************************************************************************/
/*                          funcion : bFindCiclFact                          */
/* -Funcion que busca en pstCiclFact un reg.                                 */
/* -Valores de Retorno : Error->FALSE, !Error->TRUE                          */
/*****************************************************************************/
BOOL bFindCiclFact (CICLO* pCiclo)
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

static char* szhRowid          ;/* EXEC SQL VAR szhRowid           IS STRING(15) ; */ 

static int   ihCodCiclo        ;
static int   ihAno             ;
static long  lhCodCiclFact     ;
static char* szhFecEmision     ;/* EXEC SQL VAR szhFecEmision      IS STRING(15) ; */ 

static char* szhFecVencimie    ;/* EXEC SQL VAR szhFecVencimie     IS STRING(15) ; */ 

static char* szhFecProxVenc    ;/* EXEC SQL VAR szhFecProxVenc     IS STRING(15) ; */ 

static char* szhFecCaducida    ;/* EXEC SQL VAR szhFecCaducida     IS STRING(15) ; */ 

static char* szhFecDesdeLlan   ;/* EXEC SQL VAR szhFecDesdeLlan    IS STRING(15) ; */ 

static char* szhFecHastaLlam   ;/* EXEC SQL VAR szhFecHastaLlam    IS STRING(15) ; */ 

static char* szhFecDesdeCFijos ;/* EXEC SQL VAR szhFecDesdeCFijos  IS STRING(15) ; */ 

static char* szhFecHastaCFijos ;/* EXEC SQL VAR szhFecHastaCFijos  IS STRING(15) ; */ 

static char* szhFecDesdeOCargos;/* EXEC SQL VAR szhFecDesdeOCargos IS STRING(15) ; */ 

static char* szhFecHastaOCargos;/* EXEC SQL VAR szhFecHastaOCargos IS STRING(15) ; */ 

static char* szhFecDesdeRoa    ;/* EXEC SQL VAR szhFecDesdeRoa     IS STRING(15) ; */ 

static char* szhFecHastaRoa    ;/* EXEC SQL VAR szhFecHastaRoa     IS STRING(15) ; */ 

static char* szhFecHMenos      ;/* EXEC SQL VAR szhFecHMenos       IS STRING(15) ; */ 

static char* szhDirLogs        ;/* EXEC SQL VAR szhDirLogs         IS STRING(101); */ 

static char* szhDirSpool       ;/* EXEC SQL VAR szhDirSpool        IS STRING(101); */ 

static char* szhDesLeyen1      ;/* EXEC SQL VAR szhDesLeyen1       IS STRING(81) ; */ 

static char* szhDesLeyen2      ;/* EXEC SQL VAR szhDesLeyen2       IS STRING(81) ; */ 

static char* szhDesLeyen3      ;/* EXEC SQL VAR szhDesLeyen3       IS STRING(81) ; */ 

static char* szhDesLeyen4      ;/* EXEC SQL VAR szhDesLeyen4       IS STRING(81) ; */ 

static char* szhDesLeyen5      ;/* EXEC SQL VAR szhDesLeyen5       IS STRING(81) ; */ 

static short shIndFacturacion  ;
static int   ihDiaPeriodo      ;
static short i_shDesLeyen1     ;
static short i_shDesLeyen2     ;
static short i_shDesLeyen3     ;
static short i_shDesLeyen4     ;
static short i_shDesLeyen5     ;
/* EXEC SQL END DECLARE SECTION; */ 


  if (pCiclo->lCodCiclFact == -1)
  {
      memset (pCiclo,ORA_NULL,sizeof(CICLO));
  }
  else
  {
     vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada a Fa_CiclFact\n"
                            "\t\t=> Cod.CiclFact [%ld]\n",LOG06,
                            pCiclo->lCodCiclFact);
     szhRowid          = pCiclo->szRowid          ;
     szhFecEmision     = pCiclo->szFecEmision     ;
     szhFecVencimie    = pCiclo->szFecVencimie    ;
     szhFecCaducida    = pCiclo->szFecCaducida    ;
     szhFecProxVenc    = pCiclo->szFecProxVenc    ;
     szhFecDesdeLlan   = pCiclo->szFecDesdeLlam   ;
     szhFecHastaLlam   = pCiclo->szFecHastaLlam   ;
     szhFecDesdeCFijos = pCiclo->szFecDesdeCFijos ;
     szhFecHastaCFijos = pCiclo->szFecHastaCFijos ;
     szhFecDesdeOCargos= pCiclo->szFecDesdeOCargos;
     szhFecHastaOCargos= pCiclo->szFecHastaOCargos;
     szhFecDesdeRoa    = pCiclo->szFecDesdeRoa    ;
     szhFecHastaRoa    = pCiclo->szFecHastaRoa    ;
     szhFecHMenos      = pCiclo->szFecHMenos      ;
     szhDirLogs        = pCiclo->szDirLogs        ;
     szhDirSpool       = pCiclo->szDirSpool       ;
     szhDesLeyen1      = pCiclo->szDesLeyen1      ;
     szhDesLeyen2      = pCiclo->szDesLeyen2      ;
     szhDesLeyen3      = pCiclo->szDesLeyen3      ;
     szhDesLeyen4      = pCiclo->szDesLeyen4      ;
     szhDesLeyen5      = pCiclo->szDesLeyen5      ;
     lhCodCiclFact     = pCiclo->lCodCiclFact     ;
     /* EXEC SQL SELECT
            ROWID                                                ,
            COD_CICLO                                            ,
            ANO                                                  ,
            TO_CHAR(FEC_VENCIMIE,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_EMISION ,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_CADUCIDA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_PROXVENC,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_DESDELLAM,'YYYYMMDDHH24MISS')            ,
            TO_CHAR(FEC_HASTALLAM,'YYYYMMDDHH24MISS')            ,
            TO_CHAR(FEC_DESDECFIJOS,'YYYYMMDDHH24MISS')          ,
            TO_CHAR(FEC_HASTACFIJOS,'YYYYMMDDHH24MISS')          ,
            TO_CHAR(FEC_DESDEOCARGOS,'YYYYMMDDHH24MISS')         ,
            TO_CHAR(FEC_HASTAOCARGOS,'YYYYMMDDHH24MISS')         ,
            TO_CHAR(FEC_DESDEROA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_HASTAROA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR((FEC_DESDECFIJOS-1/86400),'YYYYMMDDHH24MISS'),
            IND_FACTURACION                                      ,
            DIR_LOGS                                             ,
            DIR_SPOOL                                            ,
            DIA_PERIODO                                          ,
            DES_LEYEN1                                           ,
            DES_LEYEN2                                           ,
            DES_LEYEN3                                           ,
            DES_LEYEN4                                           ,
            DES_LEYEN5
       INTO :szhRowid                  ,
            :ihCodCiclo                ,
            :ihAno                     ,
            :szhFecVencimie            ,
            :szhFecEmision             ,
            :szhFecCaducida            ,
            :szhFecProxVenc            ,
            :szhFecDesdeLlan           ,
            :szhFecHastaLlam           ,
            :szhFecDesdeCFijos         ,
            :szhFecHastaCFijos         ,
            :szhFecDesdeOCargos        ,
            :szhFecHastaOCargos        ,
            :szhFecDesdeRoa            ,
            :szhFecHastaRoa            ,
            :szhFecHMenos              ,
            :shIndFacturacion          ,
            :szhDirLogs                ,
            :szhDirSpool               ,
            :ihDiaPeriodo              ,
            :szhDesLeyen1:i_shDesLeyen1,
            :szhDesLeyen2:i_shDesLeyen2,
            :szhDesLeyen3:i_shDesLeyen3,
            :szhDesLeyen4:i_shDesLeyen4,
            :szhDesLeyen5:i_shDesLeyen5
      FROM  FA_CICLFACT
      WHERE COD_CICLFACT    = :lhCodCiclFact
        AND IND_FACTURACION < 2; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 29;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select ROWID ,COD_CICLO ,ANO ,TO_CHAR(FEC_VENCIMIE,'YYYY\
MMDDHH24MISS') ,TO_CHAR(FEC_EMISION,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_CADUCIDA,\
'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_PROXVENC,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_DES\
DELLAM,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTALLAM,'YYYYMMDDHH24MISS') ,TO_CHAR\
(FEC_DESDECFIJOS,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTACFIJOS,'YYYYMMDDHH24MIS\
S') ,TO_CHAR(FEC_DESDEOCARGOS,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTAOCARGOS,'Y\
YYYMMDDHH24MISS') ,TO_CHAR(FEC_DESDEROA,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTA\
ROA,'YYYYMMDDHH24MISS') ,TO_CHAR((FEC_DESDECFIJOS-(1/86400)),'YYYYMMDDHH24MISS\
') ,IND_FACTURACION ,DIR_LOGS ,DIR_SPOOL ,DIA_PERIODO ,DES_LEYEN1 ,DES_LEYEN2 \
,DES_LEYEN3 ,DES_LEYEN4 ,DES_LEYEN5 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:\
b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20:b21,:b22:b23,:b24:b2\
5,:b26:b27,:b28:b29  from FA_CICLFACT where (COD_CICLFACT=:b30 and IND_FACTURA\
CION<2)";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )421;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
     sqlstm.sqhstl[0] = (unsigned long )15;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&ihCodCiclo;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&ihAno;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)szhFecVencimie;
     sqlstm.sqhstl[3] = (unsigned long )15;
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
     sqlstm.sqhstv[5] = (unsigned char  *)szhFecCaducida;
     sqlstm.sqhstl[5] = (unsigned long )15;
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)0;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)szhFecProxVenc;
     sqlstm.sqhstl[6] = (unsigned long )15;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)0;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)szhFecDesdeLlan;
     sqlstm.sqhstl[7] = (unsigned long )15;
     sqlstm.sqhsts[7] = (         int  )0;
     sqlstm.sqindv[7] = (         short *)0;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)szhFecHastaLlam;
     sqlstm.sqhstl[8] = (unsigned long )15;
     sqlstm.sqhsts[8] = (         int  )0;
     sqlstm.sqindv[8] = (         short *)0;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
     sqlstm.sqadto[8] = (unsigned short )0;
     sqlstm.sqtdso[8] = (unsigned short )0;
     sqlstm.sqhstv[9] = (unsigned char  *)szhFecDesdeCFijos;
     sqlstm.sqhstl[9] = (unsigned long )15;
     sqlstm.sqhsts[9] = (         int  )0;
     sqlstm.sqindv[9] = (         short *)0;
     sqlstm.sqinds[9] = (         int  )0;
     sqlstm.sqharm[9] = (unsigned long )0;
     sqlstm.sqadto[9] = (unsigned short )0;
     sqlstm.sqtdso[9] = (unsigned short )0;
     sqlstm.sqhstv[10] = (unsigned char  *)szhFecHastaCFijos;
     sqlstm.sqhstl[10] = (unsigned long )15;
     sqlstm.sqhsts[10] = (         int  )0;
     sqlstm.sqindv[10] = (         short *)0;
     sqlstm.sqinds[10] = (         int  )0;
     sqlstm.sqharm[10] = (unsigned long )0;
     sqlstm.sqadto[10] = (unsigned short )0;
     sqlstm.sqtdso[10] = (unsigned short )0;
     sqlstm.sqhstv[11] = (unsigned char  *)szhFecDesdeOCargos;
     sqlstm.sqhstl[11] = (unsigned long )15;
     sqlstm.sqhsts[11] = (         int  )0;
     sqlstm.sqindv[11] = (         short *)0;
     sqlstm.sqinds[11] = (         int  )0;
     sqlstm.sqharm[11] = (unsigned long )0;
     sqlstm.sqadto[11] = (unsigned short )0;
     sqlstm.sqtdso[11] = (unsigned short )0;
     sqlstm.sqhstv[12] = (unsigned char  *)szhFecHastaOCargos;
     sqlstm.sqhstl[12] = (unsigned long )15;
     sqlstm.sqhsts[12] = (         int  )0;
     sqlstm.sqindv[12] = (         short *)0;
     sqlstm.sqinds[12] = (         int  )0;
     sqlstm.sqharm[12] = (unsigned long )0;
     sqlstm.sqadto[12] = (unsigned short )0;
     sqlstm.sqtdso[12] = (unsigned short )0;
     sqlstm.sqhstv[13] = (unsigned char  *)szhFecDesdeRoa;
     sqlstm.sqhstl[13] = (unsigned long )15;
     sqlstm.sqhsts[13] = (         int  )0;
     sqlstm.sqindv[13] = (         short *)0;
     sqlstm.sqinds[13] = (         int  )0;
     sqlstm.sqharm[13] = (unsigned long )0;
     sqlstm.sqadto[13] = (unsigned short )0;
     sqlstm.sqtdso[13] = (unsigned short )0;
     sqlstm.sqhstv[14] = (unsigned char  *)szhFecHastaRoa;
     sqlstm.sqhstl[14] = (unsigned long )15;
     sqlstm.sqhsts[14] = (         int  )0;
     sqlstm.sqindv[14] = (         short *)0;
     sqlstm.sqinds[14] = (         int  )0;
     sqlstm.sqharm[14] = (unsigned long )0;
     sqlstm.sqadto[14] = (unsigned short )0;
     sqlstm.sqtdso[14] = (unsigned short )0;
     sqlstm.sqhstv[15] = (unsigned char  *)szhFecHMenos;
     sqlstm.sqhstl[15] = (unsigned long )15;
     sqlstm.sqhsts[15] = (         int  )0;
     sqlstm.sqindv[15] = (         short *)0;
     sqlstm.sqinds[15] = (         int  )0;
     sqlstm.sqharm[15] = (unsigned long )0;
     sqlstm.sqadto[15] = (unsigned short )0;
     sqlstm.sqtdso[15] = (unsigned short )0;
     sqlstm.sqhstv[16] = (unsigned char  *)&shIndFacturacion;
     sqlstm.sqhstl[16] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[16] = (         int  )0;
     sqlstm.sqindv[16] = (         short *)0;
     sqlstm.sqinds[16] = (         int  )0;
     sqlstm.sqharm[16] = (unsigned long )0;
     sqlstm.sqadto[16] = (unsigned short )0;
     sqlstm.sqtdso[16] = (unsigned short )0;
     sqlstm.sqhstv[17] = (unsigned char  *)szhDirLogs;
     sqlstm.sqhstl[17] = (unsigned long )101;
     sqlstm.sqhsts[17] = (         int  )0;
     sqlstm.sqindv[17] = (         short *)0;
     sqlstm.sqinds[17] = (         int  )0;
     sqlstm.sqharm[17] = (unsigned long )0;
     sqlstm.sqadto[17] = (unsigned short )0;
     sqlstm.sqtdso[17] = (unsigned short )0;
     sqlstm.sqhstv[18] = (unsigned char  *)szhDirSpool;
     sqlstm.sqhstl[18] = (unsigned long )101;
     sqlstm.sqhsts[18] = (         int  )0;
     sqlstm.sqindv[18] = (         short *)0;
     sqlstm.sqinds[18] = (         int  )0;
     sqlstm.sqharm[18] = (unsigned long )0;
     sqlstm.sqadto[18] = (unsigned short )0;
     sqlstm.sqtdso[18] = (unsigned short )0;
     sqlstm.sqhstv[19] = (unsigned char  *)&ihDiaPeriodo;
     sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[19] = (         int  )0;
     sqlstm.sqindv[19] = (         short *)0;
     sqlstm.sqinds[19] = (         int  )0;
     sqlstm.sqharm[19] = (unsigned long )0;
     sqlstm.sqadto[19] = (unsigned short )0;
     sqlstm.sqtdso[19] = (unsigned short )0;
     sqlstm.sqhstv[20] = (unsigned char  *)szhDesLeyen1;
     sqlstm.sqhstl[20] = (unsigned long )81;
     sqlstm.sqhsts[20] = (         int  )0;
     sqlstm.sqindv[20] = (         short *)&i_shDesLeyen1;
     sqlstm.sqinds[20] = (         int  )0;
     sqlstm.sqharm[20] = (unsigned long )0;
     sqlstm.sqadto[20] = (unsigned short )0;
     sqlstm.sqtdso[20] = (unsigned short )0;
     sqlstm.sqhstv[21] = (unsigned char  *)szhDesLeyen2;
     sqlstm.sqhstl[21] = (unsigned long )81;
     sqlstm.sqhsts[21] = (         int  )0;
     sqlstm.sqindv[21] = (         short *)&i_shDesLeyen2;
     sqlstm.sqinds[21] = (         int  )0;
     sqlstm.sqharm[21] = (unsigned long )0;
     sqlstm.sqadto[21] = (unsigned short )0;
     sqlstm.sqtdso[21] = (unsigned short )0;
     sqlstm.sqhstv[22] = (unsigned char  *)szhDesLeyen3;
     sqlstm.sqhstl[22] = (unsigned long )81;
     sqlstm.sqhsts[22] = (         int  )0;
     sqlstm.sqindv[22] = (         short *)&i_shDesLeyen3;
     sqlstm.sqinds[22] = (         int  )0;
     sqlstm.sqharm[22] = (unsigned long )0;
     sqlstm.sqadto[22] = (unsigned short )0;
     sqlstm.sqtdso[22] = (unsigned short )0;
     sqlstm.sqhstv[23] = (unsigned char  *)szhDesLeyen4;
     sqlstm.sqhstl[23] = (unsigned long )81;
     sqlstm.sqhsts[23] = (         int  )0;
     sqlstm.sqindv[23] = (         short *)&i_shDesLeyen4;
     sqlstm.sqinds[23] = (         int  )0;
     sqlstm.sqharm[23] = (unsigned long )0;
     sqlstm.sqadto[23] = (unsigned short )0;
     sqlstm.sqtdso[23] = (unsigned short )0;
     sqlstm.sqhstv[24] = (unsigned char  *)szhDesLeyen5;
     sqlstm.sqhstl[24] = (unsigned long )81;
     sqlstm.sqhsts[24] = (         int  )0;
     sqlstm.sqindv[24] = (         short *)&i_shDesLeyen5;
     sqlstm.sqinds[24] = (         int  )0;
     sqlstm.sqharm[24] = (unsigned long )0;
     sqlstm.sqadto[24] = (unsigned short )0;
     sqlstm.sqtdso[24] = (unsigned short )0;
     sqlstm.sqhstv[25] = (unsigned char  *)&lhCodCiclFact;
     sqlstm.sqhstl[25] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[25] = (         int  )0;
     sqlstm.sqindv[25] = (         short *)0;
     sqlstm.sqinds[25] = (         int  )0;
     sqlstm.sqharm[25] = (unsigned long )0;
     sqlstm.sqadto[25] = (unsigned short )0;
     sqlstm.sqtdso[25] = (unsigned short )0;
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
   if (SQLCODE != SQLOK)
   {
       iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_CiclFact",
                szfnORAerror());
       return FALSE;
   }
   if (SQLCODE == 0)
   {
       pCiclo->iAno            = ihAno           ;
       pCiclo->iCodCiclo       = ihCodCiclo      ;
       pCiclo->lCodCiclFact    = lhCodCiclFact   ;
       pCiclo->iIndFacturacion = shIndFacturacion;
       pCiclo->iDiaPeriodo     = ihDiaPeriodo    ;

       if (i_shDesLeyen1 == ORA_NULL)
           pCiclo->szDesLeyen1 [0] = 0;
       if (i_shDesLeyen2 == ORA_NULL)
           pCiclo->szDesLeyen2 [0] = 0;
       if (i_shDesLeyen3 == ORA_NULL)
           pCiclo->szDesLeyen3 [0] = 0;
       if (i_shDesLeyen4 == ORA_NULL)
           pCiclo->szDesLeyen4 [0] = 0;
       if (i_shDesLeyen5 == ORA_NULL)
           pCiclo->szDesLeyen5 [0] = 0;

       if (!bfnDBGetCiclo (pCiclo))
            return FALSE;
   }
   return TRUE;
}/************************* bFindCiclFact ************************************/


/*****************************************************************************/
/*                         funcion : vPrintCiclFact                          */
/*****************************************************************************/
void vPrintCiclFact (CICLO* pCiclo,int iNumCiclFact)
{
    int iInd = 0;
    if (stStatus.LogNivel >= LOG06)
    {
        for (iInd=0;iInd<NUM_CICLFACT;iInd++)
        {
            vDTrazasLog (szExeName, "\n\t-------------------------------------------"
                                  "\n\t\t\t   - Datos Ciclo Facturacion -     "
                                  "\n\t- Ciclo Facturacion:............. %ld"
                                  "\n\t- Ciclo.......................... %d"
                                  "\n\t- Fecha Emision.................. '%s'"
                                  "\n\t- Fecha Caducidad................ '%s'"
                                  "\n\t- Fecha Desde LLamadas........... '%s'"
                                  "\n\t- Fecha Hasta LLamadas........... '%s'"
                                  "\n\t- Fecha Desde Cargos Fijos....... '%s'"
                                  "\n\t- Fecha Hasta Cargos Fijos....... '%s'"
                                  "\n\t- Fecha Desde Roaming............ '%s'"
                                  "\n\t- Fecha Hasta Roaming............ '%s'"
                                  "\n\t- Fecha Desde Otros Cargos....... '%s'"
                                  "\n\t- Fecha Hasta Otros Cargos....... '%s'\n"
                                  ,LOG06,pCiclo->lCodCiclFact
                                  ,pCiclo->iCodCiclo
                                  ,pCiclo->szFecEmision
                                  ,pCiclo->szFecCaducida
                                  ,pCiclo->szFecDesdeLlam
                                  ,pCiclo->szFecHastaLlam
                                  ,pCiclo->szFecDesdeCFijos
                                  ,pCiclo->szFecHastaCFijos
                                  ,pCiclo->szFecDesdeRoa
                                  ,pCiclo->szFecHastaRoa
                                  ,pCiclo->szFecDesdeOCargos
                                  ,pCiclo->szFecHastaOCargos);


            vDTrazasLog (szExeName, "\n\t-------------------------------------------"
                                  "\n\t- Fecha Desde Cargos Fijos Ant... '%s'"
                                  "\n\t- Fecha Hasta Cargos Fijos Ant... '%s'"
                                  "\n\t- Indicativo de Facturacion ..... '%d'"
                                  "\n\t- Path de Logs .................. '%s'"
                                  "\n\t- Path de Spool ................. '%s'"
                                  "\n\t- Leyenda 1 ..................... '%s'"
                                  "\n\t- Leyenda 2 ..................... '%s'"
                                  "\n\t- Leyenda 3 ..................... '%s'"
                                  "\n\t- Leyenda 4 ..................... '%s'"
                                  "\n\t- Leyenda 5 ..................... '%s'"
                                  ,LOG06,pCiclo->szFecDCFijosAnt
                                  ,pCiclo->szFecHCFijosAnt
                                  ,pCiclo->iIndFacturacion
                                  ,pCiclo->szDirLogs
                                  ,pCiclo->szDirSpool
                                  ,pCiclo->szDesLeyen1
                                  ,pCiclo->szDesLeyen2
                                  ,pCiclo->szDesLeyen3
                                  ,pCiclo->szDesLeyen4
                                  ,pCiclo->szDesLeyen5);

            pCiclo++;
        }
    }
}/*********************** Final vPrintCiclFact *******************************/


/*****************************************************************************/
/*                          funcion : bGetFecCFAnt                           */
/* -Funcion que recupera el max de la FecCFAnteriores                        */
/*****************************************************************************/
void vGetFecCFAnt (CICLO* pCiclo)
{
  int iInd = 0;
  char szFecDesde [15]="";
  char szFecHasta [15]="";



  for (iInd=0;iInd<NUM_CICLFACT;iInd++)
  {
       if (pstCiclFact[iInd].iCodCiclo    == pCiclo->iCodCiclo &&
           pstCiclFact[iInd].lCodCiclFact <  pCiclo->lCodCiclFact)
       {
           if (iInd == 0)
           {
               strcpy (szFecDesde,pstCiclFact[iInd].szFecDesdeCFijos);
               strcpy (szFecHasta,pstCiclFact[iInd].szFecHastaCFijos);
           }
           if (strcmp (szFecDesde,pstCiclFact[iInd].szFecDesdeCFijos)<0)
               strcpy (szFecDesde,pstCiclFact[iInd].szFecDesdeCFijos);

           if (strcmp (szFecHasta,pstCiclFact[iInd].szFecHastaCFijos)<0)
               strcpy (szFecHasta,pstCiclFact[iInd].szFecHastaCFijos);
       }/* if iCodCiclo ... */
  }
  if (!strlen (szFecDesde))
  {
       strcpy (pCiclo->szFecDCFijosAnt,"19800101235959")   ;
       strcpy (pCiclo->szFecHCFijosAnt,pCiclo->szFecHMenos);
  }
  else
  {
      strcpy (pCiclo->szFecDCFijosAnt,szFecDesde);
      strcpy (pCiclo->szFecHCFijosAnt,szFecHasta);
  }
}/************************* Final bGetFecCFAnt *******************************/

/* -------------------------------------------------------------------------- */
/*   bGetDatosGener (DATOSGENER*)                                             */
/*      Valores Retorno: FALSE - Error                                        */
/*                       TRUE  - Ningun Error                                 */
/* -------------------------------------------------------------------------- */
BOOL bGetDatosGener (DATOSGENER* pDatosGener,char *szFecSysDate)
{
  /* EXEC SQL BEGIN DECLARE SECTION    ; */ 

  static long  lhCodAgenteStartel   ;
  static char* szhCodDollar         ; /* EXEC SQL VAR szhCodDollar     IS STRING(4)  ; */ 

  static char* szhCodUf             ; /* EXEC SQL VAR szhCodUf         IS STRING(4)  ; */ 

  static char* szhCodPeso           ; /* EXEC SQL VAR szhCodPeso       IS STRING(4)  ; */ 

  static long  lhCodClienteStartel  ;
  static int   ihCodIva             ;
  static float fhPctIva             ;
  static char* szhCodMoneFact       ; /* EXEC SQL VAR szhCodMoneFact   IS STRING(4)  ; */ 

  static char* szhPathBin           ; /* EXEC SQL VAR szhPathBin       IS STRING(256); */ 

  static char* szhDirReports        ; /* EXEC SQL VAR szhDirReports    IS STRING(51) ; */ 

  static char* szhDirLogs           ; /* EXEC SQL VAR szhDirLogs       IS STRING(256); */ 

  static char* szhDirSpool          ; /* EXEC SQL VAR szhDirSpool      IS STRING(101); */ 

  static short shCodEmpresa         ;
  static char* szhDesEmpresa        ; /* EXEC SQL VAR szhDesEmpresa    IS STRING(31) ; */ 

  static int   ihCodCatImpos        ;
  static char* szhRut               ;
  static short shProdCelular        ;
  static short shProdBeeper         ;
  static short shProdTrek           ;
  static short shProdTrunk          ;
  static short shProdGeneral        ;
  static int   ihCodCatImposDef     ;
  static char* szhNomUsuaDBA        ; /* EXEC SQL VAR szhNomUsuaDBA    IS STRING(31) ; */ 

  static char* szhSysDate           ; /* EXEC SQL VAR szhSysDate       IS STRING(15) ; */ 

  static char* szhCodOficCentral    ; /* EXEC SQL VAR szhCodOficCentral IS STRING(3) ; */ 

  static int   ihCodAbonoCel        ;
  static int   ihCodAbonoBeep       ;
  static int   ihCodAbonoTrek       ;
  static int   ihCodAbonoTrunk      ;
  static int   ihCodAbonoFinCel     ;
  static int   ihCodAbonoFinBeep    ;
  static int   ihCodAbonoFinTrek    ;
  static int   ihCodAbonoFinTrunk   ;
  static int   ihCodRecargo         ;
  static int   ihCodContado         ;
  static int   ihCodCiclo           ;
  static int   ihCodNotaCre         ;
  static int   ihCodNotaDeb         ;
  static int   ihCodMiscela         ;
  static int   ihCodCompra          ;
  static int   ihCodBaja            ;
  static int   ihCodLiquidacion     ;
  static int   ihCodFactura         ;
  static int   ihCodConcIva         ;
  static int   ihCodRoamingVis      ;
  static int   ihCodRentaPhone      ;
  static char *szhMonedaCobros      ; /* EXEC SQL VAR szhMonedaCobros   IS STRING(4) ; */ 

  static char *szhOficinaPago       ; /* EXEC SQL VAR szhOficinaPago    IS STRING(3) ; */ 

  static char *szhCodPlanTarif      ; /* EXEC SQL VAR szhCodPlanTarif   IS STRING(4) ; */ 

  static char *szhLetraCobros       ; /* EXEC SQL VAR szhLetraCobros    IS STRING(2) ; */ 

  static long  lhAgenteInterno      ;
  static int   ihDocRegalo          ;
  static int   ihDocStaff           ;
  static int   ihSisPagoRegalo      ;
  static int   ihCauPagoRegalo      ;
  static int   ihOriPagoRegalo      ;
  static short i_shCodPlanTarif     ;
  static int   ihNumDiasBaja        ;
  static long  lhCodCicloDocPuntual ;
  static int   ihCodFacturaExen     ;
  static int   ihCodBoleta          ;
  static int   ihCodBoletaExen      ;
  /* EXEC SQL END DECLARE SECTION      ; */ 


  szhCodDollar     = pDatosGener->szCodDollar     ;
  szhCodUf         = pDatosGener->szCodUf         ;
  szhCodPeso       = pDatosGener->szCodPeso       ;
  szhPathBin       = pDatosGener->szPathBin       ;
  szhDirReports    = pDatosGener->szDirReports    ;
  szhDirSpool      = pDatosGener->szDirSpool      ;
  szhDirLogs       = pDatosGener->szDirLogs       ;
  szhCodMoneFact   = pDatosGener->szCodMoneFact   ;
  szhSysDate       = szFecSysDate                 ;
  szhMonedaCobros  = pDatosGener->szMonedaCobros  ;
  szhCodOficCentral= pDatosGener->szCodOficCentral;
  szhCodPlanTarif  = pDatosGener->szCodPlanTarif  ;
  szhOficinaPago   = pDatosGener->szOficinaPago   ;
  szhLetraCobros   = pDatosGener->szLetraCobros   ;

  /* EXEC SQL SELECT
                  COD_DOLLAR        ,
                  COD_UF            ,
                  COD_PESO          ,
                  COD_IVA           ,
                  PCT_IVA           ,
                  COD_MONEFACT      ,
                  PATHBIN           ,
                  DIR_REPORTS       ,
                  DIR_SPOOL         ,
                  DIR_LOGS          ,
                  COD_ABONOCEL      ,
                  COD_ABONOBEEP     ,
                  COD_ABONOTREK     ,
                  COD_ABONOTRUNK    ,
                  COD_ABONOFINCEL   ,
                  COD_ABONOFINBEEP  ,
                  COD_ABONOFINTREK  ,
                  COD_ABONOFINTRUNK ,
                  COD_RECARGO       ,
                  COD_CONTADO       ,
                  COD_CICLO         ,
                  COD_BAJA          ,
                  COD_NOTACRE       ,
                  COD_NOTADEB       ,
                  COD_MISCELA       ,
                  COD_COMPRA        ,
                  COD_LIQUIDACION   ,
                  COD_RENTAPHONE    ,
                  COD_ROAMINGVIS    ,
                  COD_FACTURA       ,
                  COD_CONCIVA       ,
                  COD_PLANTARIF     ,
                  NUM_DIASBAJA      ,
                  COD_CICLODOCPUNTUAL,
                  TO_CHAR(SYSDATE,'YYYYMMDDHH24MISS'),
                  COD_FACTURAEXEN   ,
                  COD_BOLETA        ,
                  COD_BOLETAEXEN
           INTO
                  :szhCodDollar      ,
                  :szhCodUf          ,
                  :szhCodPeso        ,
                  :ihCodIva          ,
                  :fhPctIva          ,
                  :szhCodMoneFact    ,
                  :szhPathBin        ,
                  :szhDirReports     ,
                  :szhDirSpool       ,
                  :szhDirLogs        ,
                  :ihCodAbonoCel     ,
                  :ihCodAbonoBeep    ,
                  :ihCodAbonoTrek    ,
                  :ihCodAbonoTrunk   ,
                  :ihCodAbonoFinCel  ,
                  :ihCodAbonoFinBeep ,
                  :ihCodAbonoFinTrek ,
                  :ihCodAbonoFinTrunk,
                  :ihCodRecargo      ,
                  :ihCodContado      ,
                  :ihCodCiclo        ,
                  :ihCodBaja         ,
                  :ihCodNotaCre      ,
                  :ihCodNotaDeb      ,
                  :ihCodMiscela      ,
                  :ihCodCompra       ,
                  :ihCodLiquidacion  ,
                  :ihCodRentaPhone   ,
                  :ihCodRoamingVis   ,
                  :ihCodFactura      ,
                  :ihCodConcIva      ,
                  :szhCodPlanTarif:i_shCodPlanTarif ,
                  :ihNumDiasBaja     ,
                  :lhCodCicloDocPuntual,
                  :szhSysDate,
                  :ihCodFacturaExen,
                  :ihCodBoleta,
                  :ihCodBoletaExen
           FROM   FA_DATOSGENER; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select COD_DOLLAR ,COD_UF ,COD_PESO ,COD_IVA ,PCT_IVA ,COD_\
MONEFACT ,PATHBIN ,DIR_REPORTS ,DIR_SPOOL ,DIR_LOGS ,COD_ABONOCEL ,COD_ABONOBE\
EP ,COD_ABONOTREK ,COD_ABONOTRUNK ,COD_ABONOFINCEL ,COD_ABONOFINBEEP ,COD_ABON\
OFINTREK ,COD_ABONOFINTRUNK ,COD_RECARGO ,COD_CONTADO ,COD_CICLO ,COD_BAJA ,CO\
D_NOTACRE ,COD_NOTADEB ,COD_MISCELA ,COD_COMPRA ,COD_LIQUIDACION ,COD_RENTAPHO\
NE ,COD_ROAMINGVIS ,COD_FACTURA ,COD_CONCIVA ,COD_PLANTARIF ,NUM_DIASBAJA ,COD\
_CICLODOCPUNTUAL ,TO_CHAR(SYSDATE,'YYYYMMDDHH24MISS') ,COD_FACTURAEXEN ,COD_BO\
LETA ,COD_BOLETAEXEN into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b\
12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22,:b23,:b24,:b25,:b26,:b27,\
:b28,:b29,:b30,:b31:b32,:b33,:b34,:b35,:b36,:b37,:b38  from FA_DATOSGENER ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )540;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhCodDollar;
  sqlstm.sqhstl[0] = (unsigned long )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhCodUf;
  sqlstm.sqhstl[1] = (unsigned long )4;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhCodPeso;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&ihCodIva;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&fhPctIva;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(float);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)szhCodMoneFact;
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)szhPathBin;
  sqlstm.sqhstl[6] = (unsigned long )256;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)szhDirReports;
  sqlstm.sqhstl[7] = (unsigned long )51;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)szhDirSpool;
  sqlstm.sqhstl[8] = (unsigned long )101;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)szhDirLogs;
  sqlstm.sqhstl[9] = (unsigned long )256;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&ihCodAbonoCel;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&ihCodAbonoBeep;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&ihCodAbonoTrek;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&ihCodAbonoTrunk;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&ihCodAbonoFinCel;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&ihCodAbonoFinBeep;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&ihCodAbonoFinTrek;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)0;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&ihCodAbonoFinTrunk;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)0;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&ihCodRecargo;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)0;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&ihCodContado;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)0;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&ihCodCiclo;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)0;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&ihCodBaja;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)0;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&ihCodNotaCre;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)0;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&ihCodNotaDeb;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)0;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&ihCodMiscela;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)0;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&ihCodCompra;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)0;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&ihCodLiquidacion;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)0;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&ihCodRentaPhone;
  sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)0;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&ihCodRoamingVis;
  sqlstm.sqhstl[28] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)0;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&ihCodFactura;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)0;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&ihCodConcIva;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)0;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)szhCodPlanTarif;
  sqlstm.sqhstl[31] = (unsigned long )4;
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&i_shCodPlanTarif;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&ihNumDiasBaja;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)0;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&lhCodCicloDocPuntual;
  sqlstm.sqhstl[33] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)0;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)szhSysDate;
  sqlstm.sqhstl[34] = (unsigned long )15;
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)0;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&ihCodFacturaExen;
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)0;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)&ihCodBoleta;
  sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)0;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)&ihCodBoletaExen;
  sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)0;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
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
      printf ("\nError Oracle (Fa_DatosGener) : %s\n",szfnORAerror());
      return FALSE;
  }
  if (SQLCODE == 0)
  {
      pDatosGener->iCodIva        = ihCodIva       ;
      pDatosGener->iCodConcIva    = ihCodConcIva   ;
      pDatosGener->fPctIva        = fhPctIva       ;

      pDatosGener->iCodAbonoCel   = ihCodAbonoCel  ;
      pDatosGener->iCodAbonoBeep  = ihCodAbonoBeep ;
      pDatosGener->iCodAbonoTrek  = ihCodAbonoTrek ;
      pDatosGener->iCodAbonoTrunk = ihCodAbonoTrunk;

      pDatosGener->iCodAbonoFinCel   = ihCodAbonoFinCel  ;
      pDatosGener->iCodAbonoFinBeep  = ihCodAbonoFinBeep ;
      pDatosGener->iCodAbonoFinTrek  = ihCodAbonoFinTrek ;
      pDatosGener->iCodAbonoFinTrunk = ihCodAbonoFinTrunk;

      pDatosGener->iCodRecargo    = ihCodRecargo    ;
      pDatosGener->iCodContado    = ihCodContado    ;
      pDatosGener->iCodCiclo      = ihCodCiclo      ;
      pDatosGener->iCodBaja       = ihCodBaja       ;
      pDatosGener->iCodNotaCre    = ihCodNotaCre    ;
      pDatosGener->iCodNotaDeb    = ihCodNotaDeb    ;
      pDatosGener->iCodMiscela    = ihCodMiscela    ;
      pDatosGener->iCodCompra     = ihCodCompra     ;
      pDatosGener->iCodLiquidacion= ihCodLiquidacion;
      pDatosGener->iCodRentaPhone = ihCodRentaPhone ;
      pDatosGener->iCodRoamingVis = ihCodRoamingVis ;
      pDatosGener->iCodFactura    = ihCodFactura    ;

      pDatosGener->iCodFacturaExen = ihCodFacturaExen ;
      pDatosGener->iCodBoleta      = ihCodBoleta      ;
      pDatosGener->iCodBoletaExen  = ihCodBoletaExen  ;

      pDatosGener->iNumDiasBaja       = ihNumDiasBaja       ;
      pDatosGener->lCodCicloDocPuntual=lhCodCicloDocPuntual ;

      if (i_shCodPlanTarif == -1)
          pDatosGener->szCodPlanTarif [0] = '\0'   ;

      szhDesEmpresa = pDatosGener->szDesEmpresa    ;
      szhRut        = pDatosGener->szRut           ;
      szhNomUsuaDBA = pDatosGener->szNomUsuaDBA    ;

      /* EXEC SQL SELECT A.COD_EMPRESA       ,
                      A.COD_CLIENTESTARTEL,
                      A.DES_EMPRESA       ,
                      A.COD_AGENTESTARTEL ,
                      A.COD_CATIMPOS      ,
                      A.NUM_IDENT          ,
                      A.PROD_CELULAR      ,
                      A.PROD_BEEPER       ,
                      A.PROD_TREK         ,
                      A.PROD_TRUNK        ,
                      A.PROD_GENERAL      ,
                      A.COD_CATIMPOSDEF   ,
                      A.NOM_USUADBA       ,
                      A.COD_OFICCENTRAL   ,
                      B.OFICINA_PAG       ,
                      B.DOC_VREGALO       ,
                      B.DOC_STAFF         ,
                      B.LETRA_COBROS      ,
                      B.AGENTE_INTERNO    ,
                      B.SISPAGO_REGALO    ,
                      B.CAUPAGO_REGALO    ,
                      B.ORIPAGO_REGALO    ,
                      B.MONEDA_COBROS
               INTO   :shCodEmpresa       ,
                      :lhCodClienteStartel,
                      :szhDesEmpresa      ,
                      :lhCodAgenteStartel ,
                      :ihCodCatImpos      ,
                      :szhRut             ,
                      :shProdCelular      ,
                      :shProdBeeper       ,
                      :shProdTrek         ,
                      :shProdTrunk        ,
                      :shProdGeneral      ,
                      :ihCodCatImposDef   ,
                      :szhNomUsuaDBA      ,
                      :szhCodOficCentral  ,
                      :szhOficinaPago     ,
                      :ihDocRegalo        ,
                      :ihDocStaff         ,
                      :szhLetraCobros     ,
                      :lhAgenteInterno    ,
                      :ihSisPagoRegalo    ,
                      :ihCauPagoRegalo    ,
                      :ihOriPagoRegalo    ,
                      :szhMonedaCobros
               FROM   GE_DATOSGENER A, CO_DATGEN B; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select A.COD_EMPRESA ,A.COD_CLIENTESTARTEL ,A.DES_EMPRE\
SA ,A.COD_AGENTESTARTEL ,A.COD_CATIMPOS ,A.NUM_IDENT ,A.PROD_CELULAR ,A.PROD_B\
EEPER ,A.PROD_TREK ,A.PROD_TRUNK ,A.PROD_GENERAL ,A.COD_CATIMPOSDEF ,A.NOM_USU\
ADBA ,A.COD_OFICCENTRAL ,B.OFICINA_PAG ,B.DOC_VREGALO ,B.DOC_STAFF ,B.LETRA_CO\
BROS ,B.AGENTE_INTERNO ,B.SISPAGO_REGALO ,B.CAUPAGO_REGALO ,B.ORIPAGO_REGALO ,\
B.MONEDA_COBROS into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:b9,:b10,:b11,:b12,:b\
13,:b14,:b15,:b16,:b17,:b18,:b19,:b20,:b21,:b22  from GE_DATOSGENER A ,CO_DATG\
EN B ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )707;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&shCodEmpresa;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lhCodClienteStartel;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)szhDesEmpresa;
      sqlstm.sqhstl[2] = (unsigned long )31;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&lhCodAgenteStartel;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&ihCodCatImpos;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)szhRut;
      sqlstm.sqhstl[5] = (unsigned long )0;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&shProdCelular;
      sqlstm.sqhstl[6] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)0;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)&shProdBeeper;
      sqlstm.sqhstl[7] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)0;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&shProdTrek;
      sqlstm.sqhstl[8] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)&shProdTrunk;
      sqlstm.sqhstl[9] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)&shProdGeneral;
      sqlstm.sqhstl[10] = (unsigned long )sizeof(short);
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&ihCodCatImposDef;
      sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
      sqlstm.sqhstv[12] = (unsigned char  *)szhNomUsuaDBA;
      sqlstm.sqhstl[12] = (unsigned long )31;
      sqlstm.sqhsts[12] = (         int  )0;
      sqlstm.sqindv[12] = (         short *)0;
      sqlstm.sqinds[12] = (         int  )0;
      sqlstm.sqharm[12] = (unsigned long )0;
      sqlstm.sqadto[12] = (unsigned short )0;
      sqlstm.sqtdso[12] = (unsigned short )0;
      sqlstm.sqhstv[13] = (unsigned char  *)szhCodOficCentral;
      sqlstm.sqhstl[13] = (unsigned long )3;
      sqlstm.sqhsts[13] = (         int  )0;
      sqlstm.sqindv[13] = (         short *)0;
      sqlstm.sqinds[13] = (         int  )0;
      sqlstm.sqharm[13] = (unsigned long )0;
      sqlstm.sqadto[13] = (unsigned short )0;
      sqlstm.sqtdso[13] = (unsigned short )0;
      sqlstm.sqhstv[14] = (unsigned char  *)szhOficinaPago;
      sqlstm.sqhstl[14] = (unsigned long )3;
      sqlstm.sqhsts[14] = (         int  )0;
      sqlstm.sqindv[14] = (         short *)0;
      sqlstm.sqinds[14] = (         int  )0;
      sqlstm.sqharm[14] = (unsigned long )0;
      sqlstm.sqadto[14] = (unsigned short )0;
      sqlstm.sqtdso[14] = (unsigned short )0;
      sqlstm.sqhstv[15] = (unsigned char  *)&ihDocRegalo;
      sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[15] = (         int  )0;
      sqlstm.sqindv[15] = (         short *)0;
      sqlstm.sqinds[15] = (         int  )0;
      sqlstm.sqharm[15] = (unsigned long )0;
      sqlstm.sqadto[15] = (unsigned short )0;
      sqlstm.sqtdso[15] = (unsigned short )0;
      sqlstm.sqhstv[16] = (unsigned char  *)&ihDocStaff;
      sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[16] = (         int  )0;
      sqlstm.sqindv[16] = (         short *)0;
      sqlstm.sqinds[16] = (         int  )0;
      sqlstm.sqharm[16] = (unsigned long )0;
      sqlstm.sqadto[16] = (unsigned short )0;
      sqlstm.sqtdso[16] = (unsigned short )0;
      sqlstm.sqhstv[17] = (unsigned char  *)szhLetraCobros;
      sqlstm.sqhstl[17] = (unsigned long )2;
      sqlstm.sqhsts[17] = (         int  )0;
      sqlstm.sqindv[17] = (         short *)0;
      sqlstm.sqinds[17] = (         int  )0;
      sqlstm.sqharm[17] = (unsigned long )0;
      sqlstm.sqadto[17] = (unsigned short )0;
      sqlstm.sqtdso[17] = (unsigned short )0;
      sqlstm.sqhstv[18] = (unsigned char  *)&lhAgenteInterno;
      sqlstm.sqhstl[18] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[18] = (         int  )0;
      sqlstm.sqindv[18] = (         short *)0;
      sqlstm.sqinds[18] = (         int  )0;
      sqlstm.sqharm[18] = (unsigned long )0;
      sqlstm.sqadto[18] = (unsigned short )0;
      sqlstm.sqtdso[18] = (unsigned short )0;
      sqlstm.sqhstv[19] = (unsigned char  *)&ihSisPagoRegalo;
      sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[19] = (         int  )0;
      sqlstm.sqindv[19] = (         short *)0;
      sqlstm.sqinds[19] = (         int  )0;
      sqlstm.sqharm[19] = (unsigned long )0;
      sqlstm.sqadto[19] = (unsigned short )0;
      sqlstm.sqtdso[19] = (unsigned short )0;
      sqlstm.sqhstv[20] = (unsigned char  *)&ihCauPagoRegalo;
      sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[20] = (         int  )0;
      sqlstm.sqindv[20] = (         short *)0;
      sqlstm.sqinds[20] = (         int  )0;
      sqlstm.sqharm[20] = (unsigned long )0;
      sqlstm.sqadto[20] = (unsigned short )0;
      sqlstm.sqtdso[20] = (unsigned short )0;
      sqlstm.sqhstv[21] = (unsigned char  *)&ihOriPagoRegalo;
      sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[21] = (         int  )0;
      sqlstm.sqindv[21] = (         short *)0;
      sqlstm.sqinds[21] = (         int  )0;
      sqlstm.sqharm[21] = (unsigned long )0;
      sqlstm.sqadto[21] = (unsigned short )0;
      sqlstm.sqtdso[21] = (unsigned short )0;
      sqlstm.sqhstv[22] = (unsigned char  *)szhMonedaCobros;
      sqlstm.sqhstl[22] = (unsigned long )4;
      sqlstm.sqhsts[22] = (         int  )0;
      sqlstm.sqindv[22] = (         short *)0;
      sqlstm.sqinds[22] = (         int  )0;
      sqlstm.sqharm[22] = (unsigned long )0;
      sqlstm.sqadto[22] = (unsigned short )0;
      sqlstm.sqtdso[22] = (unsigned short )0;
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


      if (SQLCODE != 0)
      {
          printf ("\nError Oracle (Ge_DatosGener, Co_DatGen) : %s\n",
                  szfnORAerror());
          return FALSE;
      }
      if (SQLCODE == 0)
      {
          pDatosGener->lCodClienteStartel = lhCodClienteStartel;
          pDatosGener->lCodAgenteStartel  = lhCodAgenteStartel ;
          pDatosGener->iCodEmpresa        = shCodEmpresa       ;
          pDatosGener->iProdCelular       = shProdCelular      ;
          pDatosGener->iProdBeeper        = shProdBeeper       ;
          pDatosGener->iProdTrek          = shProdTrek         ;
          pDatosGener->iProdTrunk         = shProdTrunk        ;
          pDatosGener->iProdGeneral       = shProdGeneral      ;
          pDatosGener->iCodCatImposDef    = ihCodCatImposDef   ;
          pDatosGener->iDocRegalo         = ihDocRegalo        ;
          pDatosGener->iDocStaff          = ihDocStaff         ;
          pDatosGener->lAgenteInterno     = lhAgenteInterno    ;
          pDatosGener->iSisPagoRegalo     = ihSisPagoRegalo    ;
          pDatosGener->iCauPagoRegalo     = ihCauPagoRegalo    ;
          pDatosGener->iOriPagoRegalo     = ihOriPagoRegalo    ;
      }
      if (!bGetParamGener (pDatosGener))
        return (FALSE);

  }
  return TRUE;
}/**************************** bGetDatosGener ********************************/



/* -------------------------------------------------------------------------- */
/*   bGetParamGener (DATOSGENER*)                                             */
/*      Valores Retorno: FALSE - Error                                        */
/*                       TRUE  - Ningun Error                                 */
/* -------------------------------------------------------------------------- */
BOOL bGetParamGener (DATOSGENER* pstDatosGener)
{
    /* EXEC SQL BEGIN DECLARE SECTION  ; */ 

    static char  szhNomParametro[21]; /* EXEC SQL VAR szhNomParametro  IS STRING(3); */ 

    static char  szhModuloSiscel[3] ; /* EXEC SQL VAR szhModuloSiscel  IS STRING(3); */ 

    static int   ihCodProducto      ;
    static char  szhValParametro[7] ; /* EXEC SQL VAR szhValParametro  IS STRING(3); */ 

    /* EXEC SQL END   DECLARE SECTION  ; */ 


    sprintf(szhModuloSiscel,"FA\0");

    /* EXEC SQL DECLARE Cur_Ger_Parametros CURSOR FOR
        SELECT  NOM_PARAMETRO   ,
                COD_MODULO      ,
                COD_PRODUCTO    ,
                VAL_PARAMETRO
        FROM   GED_PARAMETROS
        WHERE  COD_MODULO = :szhModuloSiscel; */ 


   /* EXEC SQL OPEN Cur_Ger_Parametros; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 38;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0012;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )814;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)szhModuloSiscel;
   sqlstm.sqhstl[0] = (unsigned long )3;
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
       iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ged_Parametros",
                szfnORAerror());
       return  (FALSE)         ;
   }
   while (SQLCODE == SQLOK)
   {

        /* EXEC SQL
            FETCH Cur_Ger_Parametros
            INTO    :szhNomParametro    ,
                    :szhModuloSiscel    ,
                    :ihCodProducto      ,
                    :szhValParametro    ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )833;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)szhNomParametro;
        sqlstm.sqhstl[0] = (unsigned long )3;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhModuloSiscel;
        sqlstm.sqhstl[1] = (unsigned long )3;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&ihCodProducto;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhValParametro;
        sqlstm.sqhstl[3] = (unsigned long )3;
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
                       "Fetch->Ged_Parametros",szfnORAerror ());
            return  (FALSE)                              ;
        }
        if (SQLCODE == SQLOK)
        {
            switch(atoi(szhNomParametro))
            {
                case    szGED_CODCONSIGNACION   :
                        pstDatosGener->iCodConsignacion = atoi(szhValParametro);
                    break;
                case    szGED_CODCONSIGNACION_NC:
                        pstDatosGener->iNCredConsignacion = atoi(szhValParametro);
                    break;
                default                         :
                    break;
            }
        }
    }
    if (SQLCODE == SQLNOTFOUND)
    {
        /* EXEC SQL CLOSE Cur_Ger_Parametros; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )864;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Close->Ged_Parametros",
                     szfnORAerror());
            return (FALSE);
        }
    }
    return (TRUE);
}/**************************** bGetParamGener ********************************/



/*****************************************************************************/
/*                          funcion : vPrintDatosGener                       */
/*****************************************************************************/
void vPrintDatosGener (void)
{
  vDTrazasLog (szExeName,"\n\t *** Datos Generales ***\n"
              "\n\t-- Agente Startel...... %ld"
              "\n\t-- Codigo Dollar........ %s"
              "\n\t-- Codigo UF............ %s"
              "\n\t-- Codigo Peso.......... %s"
              "\n\t-- Cliente Startel..... %ld"
              "\n\t-- Codigo Iva........... %d"
              "\n\t-- Path Bin ............ %s"
              "\n\t-- Direc.Reports ....... %s"
              "\n\t-- Directorio Log ...... %s"
              "\n\t-- Cod.Abono Celular.... %d"
              "\n\t-- Cod.Abono Beeper..... %d"
              "\n\t-- Cod.Abono Trek....... %d"
              "\n\t-- Cod.Abono Trunk...... %d"
              "\n\t-- Cod.Moneda Facturac.. %s"
              "\n\t-- Cod.Moneda Cobros.... %s"
              "\n\t-- Prod.Celular......... %d"
              "\n\t-- Prod.Beeper ......... %d"
              "\n\t-- Prod.Trek   ......... %d"
              "\n\t-- Prod.Trunk  ......... %d"
              "\n\t-- SisPago.Regalo ...... %d"
              "\n\t-- CauPago.Regalo ...... %d"
              "\n\t-- OriPago.Regalo ...... %d"
              ,LOG06,stDatosGener.lCodAgenteStartel
              ,stDatosGener.szCodDollar         ,stDatosGener.szCodUf
              ,stDatosGener.szCodPeso           ,stDatosGener.lCodClienteStartel
              ,stDatosGener.iCodIva             ,stDatosGener.szPathBin
              ,stDatosGener.szDirReports        ,stDatosGener.szDirLogs
              ,stDatosGener.iCodAbonoCel        ,stDatosGener.iCodAbonoBeep
              ,stDatosGener.iCodAbonoTrek       ,stDatosGener.iCodAbonoTrunk
              ,stDatosGener.szCodMoneFact       ,stDatosGener.szMonedaCobros
              ,stDatosGener.iProdCelular        ,stDatosGener.iProdBeeper
              ,stDatosGener.iProdTrek           ,stDatosGener.iProdTrunk
              ,stDatosGener.iSisPagoRegalo      ,stDatosGener.iCauPagoRegalo
              ,stDatosGener.iOriPagoRegalo);


}/*********************** Final vPrintDatosGener *****************************/

/* ---------------------------------------------------------------------------------*/
/* Nombre : bfnCargaParamError (Void)                                               */
/* Fecha Creación : 22-12-2005 - Roberto Fica Domke                                 */
/* Parametros:                                                  */
/* Descripción: Función que carga valores inciales a la estructura stStatus.        */
/*                                                                                  */
/* Modificación :                                                                   */
/* ---------------------------------------------------------------------------------*/
BOOL bfnCargaParamError(void)
{
int     iRes;
char    szTipParametro [33] ="";
char    szValParametro [512]="";
char    szmodulo[256] = "bfnCargaParamError";

    /*Carga de Tasa de exito minimo requerido*/

    iRes = ifnGetParametro(201,szTipParametro,szValParametro ) ;

    if (iRes != SQLNOTFOUND && iRes != SQLOK)
    {
        vDTrazasError(szmodulo,"\n\t** ERROR, al recuperar Tasa de exito minimo req. iRes [%d] SQLNOTFOUND [%d]**",LOG01,iRes, SQLNOTFOUND);
        return (FALSE);
    }

    stStatus.hTasaExitoMinReq = atoi (szValParametro);
    vDTrazasLog(szmodulo, "\nTasa de Exito Mínima Requerida:[%d]\n", LOG02, stStatus.hTasaExitoMinReq );


    /*Cantidad minima de Clientes para evaluación de tasa de exito*/

    iRes = ifnGetParametro(202,szTipParametro,szValParametro ) ;

    if (iRes != SQLNOTFOUND && iRes != SQLOK)
    {
        vDTrazasError(szmodulo,"\n\t** ERROR, Al recuperar Cant. minima de Clientes para eval. de tasa de exito iRes [%d] SQLNOTFOUND [%d]**",LOG01,iRes, SQLNOTFOUND);
        return (FALSE);
    }

    stStatus.lCantCliMinEval = atol (szValParametro);
    vDTrazasLog(szmodulo, "\nUniverso Mínimo para evaluación de Tasa de Exito Requerida:[%d]\n", LOG02, stStatus.lCantCliMinEval );


    /*Maximo de clientes consecutivos con error*/

    iRes = ifnGetParametro(203,szTipParametro,szValParametro ) ;

    if (iRes != SQLNOTFOUND && iRes != SQLOK)
    {
        vDTrazasError(szmodulo,"\n\t** ERROR, Al recuperar Cant. minima de Clientes para eval. de tasa de exito iRes [%d] SQLNOTFOUND [%d]**",LOG01,iRes, SQLNOTFOUND);
        return (FALSE);
    }

    stStatus.lMaxCliConsError = atol (szValParametro);
    vDTrazasLog(szmodulo, "\nCantidad máxima de Errores Consecutivos Permitada:[%d]\n", LOG02, stStatus.lMaxCliConsError );

    /*Seteo de Variable de registro*/
    stStatus.lCodCliErr = -1;
    stStatus.hTasaObservada = 0;
    stStatus.lConCliCons = 0;
    stStatus.lErrorReg = 0;

    return(TRUE);
}
/* -------------------------------------------------------------------------- */
/*   bActualizaIndFacCiclo (long,int,int)                                     */
/*   BOOL bActualizaIndFacCiclo(long lCodCiclFact,int iFrom, int iTo)         */
/* -------------------------------------------------------------------------- */

BOOL bActualizaIndFacCiclo(long lCodCiclFact,int iIndicador, char *szHostId, int iExisteRngClie, long lClieIni, long lClieFin)
{
    char szSysDate[20]="";
    char    szCadena [512]="";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCiclFact = lCodCiclFact;
    long lhNumFacturas      ;
    long lhCodCliente = 0   ;
    int  ihCero = 0;
    int  ihUno = 1;
    int  ihNega = -9999 ;
    int  ihExisteRngClie = iExisteRngClie;
    long lhClieIni = lClieIni;
    long lhClieFin  = lClieFin;
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (szExeName ,"\n\t* bActualizaIndFacCiclo: Parametros de entrada:"
                            "\n\t  lCodCiclFact     :[%ld]"
                            "\n\t  iIndicador       :[%d]"
                            "\n\t  szHostId         :[%s]"
                            "\n\t  iExisteRngClie   :[%d]"
                            "\n\t  lClieIni         :[%ld]"
                            "\n\t  lClieFin         :[%ld]"
                           ,LOG06
                           ,lCodCiclFact
                           ,iIndicador
                           ,szHostId
                           ,iExisteRngClie
                           ,lClieIni
                           ,lClieFin);

    if (lCodCiclFact == -1)
        return TRUE;

/**/
/**/

    memset(&stTrazaProc     ,0,sizeof(TRAZAPROC));

    if (strcmp (szHostId, ""))
    {
        vDTrazasLog (szExeName,"\n\t* Verifica con Host_ID (bfnSelectTrazaProcHost) [%s]",LOG06,szHostId);
        if (!bfnSelectTrazaProcHost ( stCiclo.lCodCiclFact,iPROC_FACTURACION,&stTrazaProc,szHostId))
        {
             iDError (szExeName,ERR000,vInsertarIncidencia,
                        "bfnSelectTrazaProcHost","Proceso no se puede lanzar");
             return  (FALSE);
        }
    }
    else
    {
        vDTrazasLog (szExeName,"\n\t* Verifica sin Host_ID (bfnSelectTrazaProc)",LOG06);
        if (!bfnSelectTrazaProc ( stCiclo.lCodCiclFact,iPROC_FACTURACION,&stTrazaProc))
        {
             iDError (szExeName,ERR000,vInsertarIncidencia,
                        "bfnSelectTrazaProc","Proceso no se puede lanzar");
             return  (FALSE);
        }
    }

    bPrintTrazaProc(stTrazaProc);

/**/

    if (iIndicador == 1)
    {
        if (strcmp (szHostId, ""))
        {
            vDTrazasLog (szExeName,"\n\t* Verifica con Host_ID [%s](bfnValidaTrazaProcHost)",LOG06,szHostId);
            if (!bfnValidaTrazaProcHost(stCiclo.lCodCiclFact,iPROC_FACTURACION,iIND_FACT_ENPROCESO, szHostId))
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,
                        "bfnValidaTrazaProcHost","Proceso no se puede lanzar");
                return  (FALSE);
            }
        }
        else
        {
            vDTrazasLog (szExeName,"\n\t* Verifica sin Host_ID (bfnValidaTrazaProc)",LOG06);
            if (!bfnValidaTrazaProc(stCiclo.lCodCiclFact,iPROC_FACTURACION,iIND_FACT_ENPROCESO))
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,
                        "bfnValidaTrazaProc","Proceso no se puede lanzar");
                return  (FALSE);
            }
        }
        return (TRUE);
    }

/**/


    vDTrazasLog (szExeName,"\n\t* Verifica Actualizacion Indice de Facturacion",LOG03);

    ihCero = 0;
    ihUno = 1;
    ihNega = -9999 ;

    /* EXEC SQL    SELECT  COD_CLIENTE
                INTO    :lhCodCliente
                FROM    FA_CICLOCLI
                WHERE   COD_CICLO    = :stCiclo.iCodCiclo
                AND     IND_MASCARA  = :ihUno
                AND     NUM_PROCESO <= :ihCero
                AND     NUM_PROCESO >= :ihNega
                AND     ROWNUM       = :ihUno
                AND     ( (COD_CLIENTE BETWEEN :lhClieIni AND :lhClieFin) OR (1 <> :ihExisteRngClie) ); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 38;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_CLIENTE into :b0  from FA_CICLOCLI where (((((\
COD_CICLO=:b1 and IND_MASCARA=:b2) and NUM_PROCESO<=:b3) and NUM_PROCESO>=:b4)\
 and ROWNUM=:b2) and (COD_CLIENTE between :b6 and :b7 or 1<>:b8))";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )879;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCliente;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&(stCiclo.iCodCiclo);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCero;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)&ihNega;
    sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihUno;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )0;
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)&lhClieIni;
    sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[6] = (         int  )0;
    sqlstm.sqindv[6] = (         short *)0;
    sqlstm.sqinds[6] = (         int  )0;
    sqlstm.sqharm[6] = (unsigned long )0;
    sqlstm.sqadto[6] = (unsigned short )0;
    sqlstm.sqtdso[6] = (unsigned short )0;
    sqlstm.sqhstv[7] = (unsigned char  *)&lhClieFin;
    sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[7] = (         int  )0;
    sqlstm.sqindv[7] = (         short *)0;
    sqlstm.sqinds[7] = (         int  )0;
    sqlstm.sqharm[7] = (unsigned long )0;
    sqlstm.sqadto[7] = (unsigned short )0;
    sqlstm.sqtdso[7] = (unsigned short )0;
    sqlstm.sqhstv[8] = (unsigned char  *)&ihExisteRngClie;
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



    if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
    {
          iDError ("bActualizaIndFacCiclo", ERR000, vInsertarIncidencia,
                   "Select=> Fa_CicloCli (bValidaFinCiclo)", szfnORAerror ());
          return  (FALSE);
    }

  /*if (SQLCODE == SQLOK && SQLROWS > 0 && lhCodCliente > 0) */
    if (SQLCODE == SQLOK)
    {
        vDTrazasLog (szExeName,"\n\t* (%s), Linea (%d) bActualizaIndFacCiclo(): SQLCODE == SQLOK",LOG03, __FILE__, __LINE__);
        return TRUE;
     }

    vDTrazasLog (szExeName,"\n\t* Verifica (bfnSelectSysDate)",LOG06);

    if (!bfnSelectSysDate(szSysDate))
    {
        vDTrazasLog(szExeName,"\n\t*** Error en bfnSelectSysDate (bActualizaIndFacCiclo) ***\n",LOG01);
        iDError ("bActualizaIndFacCiclo",ERR000,vInsertarIncidencia,"bfnSelectSysDate",szfnORAerror ());
        return FALSE;
    }
    else
    {

        vDTrazasLog (szExeName,"\n\t* Verifica SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",LOG06,lhCodCiclFact);

        sprintf(szCadena,"SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",lhCodCiclFact);

        vDTrazasLog (szExeName,"\n\t* Cuenta Cantidad de facturas ",LOG05);
        vDTrazasLog (szExeName,"\n\t* Query Cuenta [%s] ",LOG03,szCadena);

        /* EXEC SQL PREPARE sql_count_facturas FROM :szCadena; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )930;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
        sqlstm.sqhstl[0] = (unsigned long )512;
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
            vDTrazasError(szExeName,"\n\t**  Error en SQL-PREPARE sql_count_facturas **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            iDError ("bActualizaIndFacCiclo", ERR000, vInsertarIncidencia,
                     "Select=> Count Fa_FactDocu (bValidaFinCiclo)", szfnORAerror ());
            return  (FALSE);

        }

        vDTrazasLog (szExeName,"\n\t* Verifica DECLARE SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",LOG06,lhCodCiclFact);

        /* EXEC SQL DECLARE cur_count_facturas CURSOR FOR sql_count_facturas; */ 

        if (SQLCODE)
        {
            vDTrazasError(szExeName,"\n\t**  Error en SQL-DECLARE sql_count_facturas **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            iDError ("bActualizaIndFacCiclo", ERR000, vInsertarIncidencia,
                     "Select=> Count Fa_FactDocu (bValidaFinCiclo)", szfnORAerror ());
            return  (FALSE);

        }

        vDTrazasLog (szExeName,"\n\t* Verifica OPEN SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",LOG06,lhCodCiclFact);

        /* EXEC SQL OPEN cur_count_facturas; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )949;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        if (SQLCODE)
        {
            vDTrazasError(szExeName,"\n\t**  Error en SQL-OPEN CURSOR sql_count_facturas **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            iDError ("bActualizaIndFacCiclo", ERR000, vInsertarIncidencia,
                     "Select=> Count Fa_FactDocu (bValidaFinCiclo)", szfnORAerror ());
            return  (FALSE);
        }

        vDTrazasLog (szExeName,"\n\t* Verifica FETCH SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",LOG06,lhCodCiclFact);

        /* EXEC SQL FETCH cur_count_facturas  INTO :lhNumFacturas; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )964;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhNumFacturas;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
            vDTrazasError(szExeName,"\n\t**  Error en SQL-FETCH sql_count_facturas **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
            iDError ("bActualizaIndFacCiclo", ERR000, vInsertarIncidencia,
                     "Select=> Count Fa_FactDocu (bValidaFinCiclo)", szfnORAerror ());
            return  (FALSE);
        }

        vDTrazasLog (szExeName,"\n\t* Verifica CLOSE SELECT COUNT(COD_CLIENTE) FROM FA_FACTDOCU_%ld ",LOG06,lhCodCiclFact);

        /* EXEC SQL CLOSE cur_count_facturas; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 38;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )983;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        vDTrazasLog (szExeName,"\n\t* Actualiza Traza de Proceso ",LOG03);

        stTrazaProc.lCodCiclFact       = lCodCiclFact                           ;
        stTrazaProc.iCodProceso        = iPROC_FACTURACION                      ;
        stTrazaProc.iCodEstaProc       = iPROC_EST_OK                           ;
        strcpy(stTrazaProc.szFecTermino,szSysDate)                              ;
        strcpy(stTrazaProc.szGlsProceso,"Proceso de Facturacion de Ciclo Terminado OK");
        stTrazaProc.lCodCliente        = 0                                      ;
        stTrazaProc.lNumAbonado        = 0                                      ;
        stTrazaProc.lNumRegistros      = lhNumFacturas                          ;
        bPrintTrazaProc(stTrazaProc)                                            ;


        if (strcmp (szHostId, ""))
        {

                vDTrazasLog (szExeName,"\n\t* Actualiza Traza Proceso con Host Id. [%s]",LOG06, szHostId);

            if (!bfnUpdateTrazaProcHost(stTrazaProc, szHostId))
            {
                iDError ("bActualizaIndFacCiclo",ERR000,vInsertarIncidencia,
                    "bfnUpdateTrazaProcHost",szfnORAerror ());
                return FALSE;
            }
        }
        else
        {

                vDTrazasLog (szExeName,"\n\t* Actualiza Traza Proceso sin Host Id.",LOG06);

            if (!bfnUpdateTrazaProc(stTrazaProc))
            {
                iDError ("bActualizaIndFacCiclo",ERR000,vInsertarIncidencia,
                    "bfnUpdateTrazaProc",szfnORAerror ());
                return FALSE;
            }
        }

    }
    return TRUE;
}/**************************** Final bActualizaIndFacCiclo *******************/


/*****************************************************************************/
/*                          funcion : iCmpConceptos_mi                       */
/*     -Funcion de Comparacion                                               */
/*     CDescouv 27-03-2002                                                   */
/*****************************************************************************/
int iCmpConceptos_mi (const void* cad1, const void* cad2)
{
    int rc = 0;

    return
    ( (rc = ((CONCEPTO_MI *)cad1)->iCodConcepto-
            ((CONCEPTO_MI *)cad2)->iCodConcepto) != 0)?rc:0;
}/************************** Final iCmpConceptos_mi **************************/

/*****************************************************************************/
/*                           funcion : bFindConcepto_mi                      */
/* -Funcion que busca en memoria                                             */
/* (CONCEPTO_MI* pstConceptos_mi->global) un reg.                            */
/* -Entrada iCodConcepto_mi,  CONCEPTO_MI*                                         */
/* -Salida  Error->FALSE, !Error->TRUE                                       */
/*  Creado para soportar la funcionalidad del Multiidioma                    */
/*  CDescouv 28-03-2002                                                      */
/*****************************************************************************/
BOOL bFindConcepto_mi (int iCodConcepto_mi,char* szCodIdioma_mi,CONCEPTO_MI *pstConcepto_mi)
{
  int  j    = 0    ;
  int  i    = 0    ;
  BOOL bEnc = FALSE;

  vDTrazasLog (szExeName,"\n\t\t* Parametro de Entrada Fa_Conceptos_mi"
                         "\n\t\t=>Cod.Concepto [%d]", LOG05, iCodConcepto_mi);

  while (!bEnc && j<stIndConcepto_mi.lNumRangos)
  {
    vDTrazasLog(szExeName,"\n\tRango inicial....[%d] "
                          "\n\tRango Final......[%d] "
                          "\n\tIndice Inicial...[%ld] "
                          "\n\tIndice Final.....[%ld] "
                          "\n\tNum Rangos.......[%ld]\n "
                           ,LOG06, stIndConcepto_mi.pRangoConcepto [j].iCodConcIni,
                                   stIndConcepto_mi.pRangoConcepto [j].iCodConcFin,
                                   stIndConcepto_mi.pRangoConcepto [j].lIndInicial,
                                   stIndConcepto_mi.pRangoConcepto [j].lIndFinal,
                                   stIndConcepto_mi.lNumRangos);


    if (stIndConcepto_mi.pRangoConcepto [j].iCodConcIni <= iCodConcepto_mi &&
        stIndConcepto_mi.pRangoConcepto [j].iCodConcFin >= iCodConcepto_mi)
    {
        bEnc = 1;
        vDTrazasLog (szExeName,"\n\n\t** Encontro rango GE_MULTIIDIOMA **\n",LOG06);
    }
    else
    {
       j++;
       vDTrazasLog (szExeName,"\n\n\t** No Encontro rango GE_MULTIIDIOMA **\n",LOG06);

    }

      if (bEnc)
      {
          bEnc = FALSE;

          for (i = stIndConcepto_mi.pRangoConcepto [j].lIndInicial;
               i<= stIndConcepto_mi.pRangoConcepto [j].lIndFinal  ;i++)
          {
            vDTrazasLog(szExeName,"\n\tConcepto ii...[%ld] "
                                  "\n\tConcepto_mi...[%ld] "
                                  "\n\tIdioma ii ....[%s] "
                                  "\n\tIdioma_mi.....[%s]\n "
                                ,LOG06,pstConceptos_mi [i].iCodConcepto,iCodConcepto_mi,
                                 pstConceptos_mi [i].szCodIdioma,szCodIdioma_mi );

              if (pstConceptos_mi [i].iCodConcepto == iCodConcepto_mi &&
                  strcmp(pstConceptos_mi [i].szCodIdioma,szCodIdioma_mi) == 0)
              {
                  memcpy (pstConcepto_mi,&pstConceptos_mi [i],sizeof(CONCEPTO_MI));
                  bEnc = 1;
                  break;
              }
          }
          j++; /* PGG SOPORTE - 134138 - 14-05-2210 - COPIANDO SOLUCION DE MEX */
      }
    } /* PGG SOPORTE - 134138 - 14-05-2210 - COPIANDO SOLUCION DE MEX */
  vDTrazasLog (szExeName,"\n\t Finalizo bFindConcepto_mi ",LOG05);
  return(bEnc);
}/************************* Final bFindConcepto_mi ***************************/

/*****************************************************************************/
/*                           funcion : bFindConcepto                         */
/* -Funcion que busca en memoria (CONCEPTO* pstConceptos->global) un reg.    */
/* -Entrada iCodConcepto, iCodProducto, CONCEPTO*                            */
/* -Salida  Error->FALSE, !Error->TRUE                                       */
/* Modificacion de Funcion agregando funcionalidad de Multiidioma            */
/* se agrega funcion bFindConcepto_mi para las glosas multiidioma            */
/* CDescouv 28-08-2002                                                       */
/*****************************************************************************/
BOOL bFindConcepto (int iCodConcepto,CONCEPTO *pstConcepto)
{
  BOOL bEnc = FALSE;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  int   ihCodProducto   ;
  int   ihCodTipConce   ;
  int   ihIndActivo     ;
  char *pszhCodMoneda   ;/* EXEC SQL VAR pszhCodMoneda   IS STRING (4) ; */ 

  int   ihCodConcOrig   ;
  char *pszhDesConcepto ;/* EXEC SQL VAR pszhDesConcepto IS STRING (61); */ 

  char *pszhCodModulo   ;/* EXEC SQL VAR pszhCodModulo   IS STRING (3) ; */ 

  char *pszhCodTipDescu ;/* EXEC SQL VAR pszhCodTipDescu IS STRING (2) ; */ 

  int   ihCodConcepto   ;
  short i_shCodConcOrig ;
  short i_shCodTipDescu ;
  int   ihIndTecnologia ;
  char *pszhDefTecnologia ;/* EXEC SQL VAR pszhDefTecnologia IS STRING (8) ; */ 

  /* EXEC SQL END DECLARE SECTION  ; */ 


  CONCEPTO_MI stConceptoTemp;
  memset (&stConceptoTemp,0,sizeof(CONCEPTO_MI));


    vDTrazasLog (szExeName,"\n\t\t* Parametro de Entrada Fa_Conceptos"
                           "\n\t\t=>Cod.Concepto [%d]"
                           "\n\t\t=>Cod.Idioma   [%s]"
                           , LOG05, iCodConcepto,stCliente.szCodIdioma);

    bEnc = FALSE;
    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        if (pstConceptos[iCodConcepto].iFlagExiste ==  1)
        {
        	vDTrazasLog(szExeName,"\n\t\tFlag Existe ..........[%d]"
		                          "\n\t\tCod.Concepto..........[%d]"
		                          "\n\t\tCod.Producto..........[%d]"
		                          "\n\t\tDes.Concepto..........[%s]"
		                          "\n\t\tCod.Tipo de Concepto..[%d]"
		                          "\n\t\tCod.Modulo............[%s]"
		                          "\n\t\tCod.Moneda..... ......[%s]"
		                          "\n\t\tInd.Activo............[%d]"
		                          "\n\t\tCod.ConCobr...........[%d]"
		                          "\n\t\tCod.Idioma............[%s]"
		                          ,LOG06
		                          ,pstConceptos[iCodConcepto].iFlagExiste
		                          ,iCodConcepto
		                          ,pstConceptos[iCodConcepto].iCodProducto
		                          ,pstConceptos[iCodConcepto].szDesConcepto
		                          ,pstConceptos[iCodConcepto].iCodTipConce
		                          ,pstConceptos[iCodConcepto].szCodModulo
		                          ,pstConceptos[iCodConcepto].szCodMoneda
		                          ,pstConceptos[iCodConcepto].iIndActivo
		                          ,pstConceptos[iCodConcepto].iCodConCobr
		                          ,pstParamGener.szCodIdioma);

            
            memcpy (pstConcepto,&pstConceptos[iCodConcepto],sizeof(CONCEPTO));
            /* Inc 166196 PPV 20/03/2011 Se quita mientras se encuentra problema */
            /*
            if (strcmp(stCliente.szCodIdioma,pstParamGener.szCodIdioma)!=0)
            {
                vDTrazasLog (szExeName,"\n\t distintos idiomas ",LOG06);

                if (bFindConcepto_mi (iCodConcepto,stCliente.szCodIdioma,&stConceptoTemp))
                {
                    strcpy(pstConcepto->szDesConcepto, stConceptoTemp.szDesConcepto);
                    bEnc = TRUE;
                }
                else
                {
                    iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos_mi");
                    bEnc =FALSE;
                }
            }
            else
            {*/
                bEnc = TRUE;
            /*}*/
        }
    }
    else
    {
      ihCodConcepto     = iCodConcepto              ;
      pszhDesConcepto   = pstConcepto->szDesConcepto;
      pszhCodModulo     = pstConcepto->szCodModulo  ;
      pszhCodTipDescu   = pstConcepto->szCodTipDescu;
      pszhCodMoneda     = pstConcepto->szCodMoneda  ;
      pszhDefTecnologia = pstConcepto->szDefTecnologia;

      /* EXEC SQL SELECT /o+ index (FA_CONCEPTOS PK_FA_CONCEPTOS) o/
                      A.COD_PRODUCTO,
                      B.DES_CONCEPTO,
                      A.COD_TIPCONCE,
                      A.COD_MODULO  ,
                      A.IND_ACTIVO  ,
                      A.COD_MONEDA  ,
                      A.COD_CONCORIG,
                      A.COD_TIPDESCU,
                      A.IND_TECNOLOGIA,
                      A.DEF_TECNOLOGIA
                 INTO :ihCodProducto  ,
                      :pszhDesConcepto,
                      :ihCodTipConce  ,
                      :pszhCodModulo  ,
                      :ihIndActivo    ,
                      :pszhCodMoneda  ,
                      :ihCodConcOrig  :i_shCodConcOrig,
                      :pszhCodTipDescu:i_shCodTipDescu,
                      :ihIndTecnologia,
                      :pszhDefTecnologia
                  FROM FA_CONCEPTOS a,GE_MULTIIDIOMA b
                 WHERE b.NOM_TABLA = 'FA_CONCEPTOS'
                   and b.NOM_CAMPO = 'COD_CONCEPTO'
                   AND a.COD_CONCEPTO = b.COD_CONCEPTO
                   AND a.COD_PRODUCTO = b.COD_PRODUCTO
                   AND b.COD_IDIOMA = :stCliente.szCodIdioma
                   and a.COD_CONCEPTO = :ihCodConcepto; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select  /*+  index (FA_CONCEPTOS PK_FA_CONCEPTOS)  +*/ \
A.COD_PRODUCTO ,B.DES_CONCEPTO ,A.COD_TIPCONCE ,A.COD_MODULO ,A.IND_ACTIVO ,A.\
COD_MONEDA ,A.COD_CONCORIG ,A.COD_TIPDESCU ,A.IND_TECNOLOGIA ,A.DEF_TECNOLOGIA\
 into :b0,:b1,:b2,:b3,:b4,:b5,:b6:b7,:b8:b9,:b10,:b11  from FA_CONCEPTOS a ,GE\
_MULTIIDIOMA b where (((((b.NOM_TABLA='FA_CONCEPTOS' and b.NOM_CAMPO='COD_CONC\
EPTO') and a.COD_CONCEPTO=b.COD_CONCEPTO) and a.COD_PRODUCTO=b.COD_PRODUCTO) a\
nd b.COD_IDIOMA=:b12) and a.COD_CONCEPTO=:b13)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )998;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&ihCodProducto;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)pszhDesConcepto;
      sqlstm.sqhstl[1] = (unsigned long )61;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)&ihCodTipConce;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)pszhCodModulo;
      sqlstm.sqhstl[3] = (unsigned long )3;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&ihIndActivo;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)pszhCodMoneda;
      sqlstm.sqhstl[5] = (unsigned long )4;
      sqlstm.sqhsts[5] = (         int  )0;
      sqlstm.sqindv[5] = (         short *)0;
      sqlstm.sqinds[5] = (         int  )0;
      sqlstm.sqharm[5] = (unsigned long )0;
      sqlstm.sqadto[5] = (unsigned short )0;
      sqlstm.sqtdso[5] = (unsigned short )0;
      sqlstm.sqhstv[6] = (unsigned char  *)&ihCodConcOrig;
      sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[6] = (         int  )0;
      sqlstm.sqindv[6] = (         short *)&i_shCodConcOrig;
      sqlstm.sqinds[6] = (         int  )0;
      sqlstm.sqharm[6] = (unsigned long )0;
      sqlstm.sqadto[6] = (unsigned short )0;
      sqlstm.sqtdso[6] = (unsigned short )0;
      sqlstm.sqhstv[7] = (unsigned char  *)pszhCodTipDescu;
      sqlstm.sqhstl[7] = (unsigned long )2;
      sqlstm.sqhsts[7] = (         int  )0;
      sqlstm.sqindv[7] = (         short *)&i_shCodTipDescu;
      sqlstm.sqinds[7] = (         int  )0;
      sqlstm.sqharm[7] = (unsigned long )0;
      sqlstm.sqadto[7] = (unsigned short )0;
      sqlstm.sqtdso[7] = (unsigned short )0;
      sqlstm.sqhstv[8] = (unsigned char  *)&ihIndTecnologia;
      sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[8] = (         int  )0;
      sqlstm.sqindv[8] = (         short *)0;
      sqlstm.sqinds[8] = (         int  )0;
      sqlstm.sqharm[8] = (unsigned long )0;
      sqlstm.sqadto[8] = (unsigned short )0;
      sqlstm.sqtdso[8] = (unsigned short )0;
      sqlstm.sqhstv[9] = (unsigned char  *)pszhDefTecnologia;
      sqlstm.sqhstl[9] = (unsigned long )8;
      sqlstm.sqhsts[9] = (         int  )0;
      sqlstm.sqindv[9] = (         short *)0;
      sqlstm.sqinds[9] = (         int  )0;
      sqlstm.sqharm[9] = (unsigned long )0;
      sqlstm.sqadto[9] = (unsigned short )0;
      sqlstm.sqtdso[9] = (unsigned short )0;
      sqlstm.sqhstv[10] = (unsigned char  *)(stCliente.szCodIdioma);
      sqlstm.sqhstl[10] = (unsigned long )6;
      sqlstm.sqhsts[10] = (         int  )0;
      sqlstm.sqindv[10] = (         short *)0;
      sqlstm.sqinds[10] = (         int  )0;
      sqlstm.sqharm[10] = (unsigned long )0;
      sqlstm.sqadto[10] = (unsigned short )0;
      sqlstm.sqtdso[10] = (unsigned short )0;
      sqlstm.sqhstv[11] = (unsigned char  *)&ihCodConcepto;
      sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[11] = (         int  )0;
      sqlstm.sqindv[11] = (         short *)0;
      sqlstm.sqinds[11] = (         int  )0;
      sqlstm.sqharm[11] = (unsigned long )0;
      sqlstm.sqadto[11] = (unsigned short )0;
      sqlstm.sqtdso[11] = (unsigned short )0;
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
          bEnc = FALSE;
      }
      else
      {
          bEnc = TRUE ;
          pstConcepto->iFlagExiste  = 1  ;

          pstConcepto->iCodProducto = ihCodProducto ;
          pstConcepto->iCodTipConce = ihCodTipConce ;
          pstConcepto->iIndActivo   = ihIndActivo   ;

          pstConcepto->iCodConcOrig =(i_shCodConcOrig == -1)?-1:ihCodConcOrig ;

          if ( i_shCodTipDescu  == -1)
               pstConcepto->szCodTipDescu [0] = 0;

          pstConcepto->sIndTecnologia = ihIndTecnologia;
      }
  }
  if (!bEnc)
  {
      stAnomProceso.iCodConcepto = iCodConcepto;

      if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
          iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos");
      else
          iDError (szExeName,ERR000,vInsertarIncidencia,"Select=> Fa_Conceptos",
                   szfnORAerror ());
  }
  vDTrazasLog (szExeName,"\n\t Finalizo bFindConcepto ",LOG05);
  return (bEnc);
}/************************* Final bFindConcepto ******************************/

/*****************************************************************************/
/*                       funcion : bConverMoneda                             */
/* -Funcion que aplica el cambio vigente segun max(fec_valor) sobre el cod.  */
/*  moneda que pasa por parametro                                            */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
BOOL bConverMoneda (char   *szCodMonedaO,
                    char   *szCodMonedaD,
                    char   *szFecha     ,
                    double *dImporte    ,
                    int    iCodTipDocum)
{
  BOOL bRes = TRUE;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char   *szhFecha     ;/* EXEC SQL VAR szhFecha      IS STRING(15); */ 

  static char   *szhCodMonedaO;/* EXEC SQL VAR szhCodMonedaO IS STRING(4) ; */ 

  static char   *szhCodMonedaD;/* EXEC SQL VAR szhCodMonedaD IS STRING(4) ; */ 

  static double  dhCambioO    ;
  static double  dhCambioD    ;
  /* EXEC SQL END DECLARE SECTION; */ 


  dhCambioD = 0.0;
  dhCambioO = 0.0;

  if (strcmp (szCodMonedaO,szCodMonedaD)!= 0)
  {
      vDTrazasLog (szExeName,"\n\t\t* Parametros para Conversion Moneda\n"
                             "\t\t* Moneda Origen  [%s]\n"
                             "\t\t* Moneda Destino [%s]\n"
                             "\t\t* Fecha Valor    [%s]\n"
                             "\t\t* Valor Origen   [%10.4f]\n"
                             "\t\t* Tipo Documento [%d]\n"
                             ,LOG04,
                             szCodMonedaO,szCodMonedaD,szFecha,*dImporte,iCodTipDocum);
      if (iCodTipDocum == stDatosGener.iCodCiclo)
      {
          if (!bFindConversion (szCodMonedaO,szFecha,&dhCambioO))
               bRes = FALSE;
          if (!bFindConversion (szCodMonedaD,szFecha,&dhCambioD))
               bRes = FALSE;
      }
      else
      {
         szhFecha      = szFecha     ;
         szhCodMonedaO = szCodMonedaO;
         szhCodMonedaD = szCodMonedaD;

         /* EXEC SQL SELECT /o+ index (GE_CONVERSION PK_GE_CONVERSION) o/
                         CAMBIO
                  INTO   :dhCambioO
                  FROM   GE_CONVERSION
                  WHERE  COD_MONEDA = :szhCodMonedaO
                    AND  FEC_DESDE <= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS')
                    AND  FEC_HASTA >= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS'); */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 38;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select  /*+  index (GE_CONVERSION PK_GE_CONVERSION) \
 +*/ CAMBIO into :b0  from GE_CONVERSION where ((COD_MONEDA=:b1 and FEC_DESDE<\
=TO_DATE(:b2,'YYYYMMDDHH24MISS')) and FEC_HASTA>=TO_DATE(:b2,'YYYYMMDDHH24MISS\
'))";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1061;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)256;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&dhCambioO;
         sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)szhCodMonedaO;
         sqlstm.sqhstl[1] = (unsigned long )4;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)szhFecha;
         sqlstm.sqhstl[2] = (unsigned long )15;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)szhFecha;
         sqlstm.sqhstl[3] = (unsigned long )15;
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


         if (SQLCODE == SQLOK)
         {
             /* EXEC SQL SELECT /o+ index (GE_CONVERSION PK_GE_CONVERSION) o/
                             CAMBIO
                      INTO   :dhCambioD
                      FROM   GE_CONVERSION
                      WHERE  COD_MONEDA = :szhCodMonedaD
                        AND  FEC_DESDE <= TO_DATE(:szhFecha,'YYYYMMDDHH24MISS')
                        AND  FEC_HASTA >= TO_DATE(:szhFecha,'YYYYMMDDHH24MISS'); */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 38;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.stmt = "select  /*+  index (GE_CONVERSION PK_GE_CONVERSI\
ON)  +*/ CAMBIO into :b0  from GE_CONVERSION where ((COD_MONEDA=:b1 and FEC_DE\
SDE<=TO_DATE(:b2,'YYYYMMDDHH24MISS')) and FEC_HASTA>=TO_DATE(:b2,'YYYYMMDDHH24\
MISS'))";
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )1092;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)256;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqhstv[0] = (unsigned char  *)&dhCambioD;
             sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         short *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned long )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (unsigned char  *)szhCodMonedaD;
             sqlstm.sqhstl[1] = (unsigned long )4;
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         short *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned long )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (unsigned char  *)szhFecha;
             sqlstm.sqhstl[2] = (unsigned long )15;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         short *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned long )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (unsigned char  *)szhFecha;
             sqlstm.sqhstl[3] = (unsigned long )15;
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
         if (SQLCODE != SQLOK)
             bRes = FALSE;
      }

      if (bRes)
          *dImporte *= (double)dhCambioO/dhCambioD;
      else
      {
          if (SQLCODE != SQLOK)
              iDError (szExeName,ERR000,vInsertarIncidencia,
                       "Select->(Ge_Conversion)",szfnORAerror());
      }
  }
  vDTrazasLog (szExeName,"\n\t\t* Valor Convertido en bConverMoneda  [%10.4f]\n", LOG04,*dImporte);
  return (bRes);
}/********************** Final bConverMoneda *********************************/


/*****************************************************************************/
/*                          funcion : iCmpZonaCiudad                         */
/* -Funcion de Comparacion                                                   */
/*****************************************************************************/
int iCmpZonaCiudad (const void* cad1, const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((ZONACIUDAD *)cad1)->szCodRegion,
                    ((ZONACIUDAD *)cad2)->szCodRegion ))    != 0)?rc:
   ( (rc = strcmp ( ((ZONACIUDAD *)cad1)->szCodProvincia,
                    ((ZONACIUDAD *)cad2)->szCodProvincia )) != 0)?rc:
   ( (rc = strcmp ( ((ZONACIUDAD *)cad1)->szCodCiudad,
                    ((ZONACIUDAD *)cad2)->szCodCiudad ))    != 0)?rc:
   ( (rc = strcmp ( ((ZONACIUDAD *)cad1)->szFecDesde,
                    ((ZONACIUDAD *)cad2)->szFecDesde )) < 0)?rc:0;

}/************************* Final iCmpZonaCiudad *****************************/

/*****************************************************************************/
/*                        funcion : bFindZonaCiudad                          */
/*****************************************************************************/
BOOL bFindZonaCiudad(char *szCodRegion  ,char *szCodProvincia,char *szCodCiudad,
                     char *szFecZonaImpo,int  *piCodZonaImpo)
{
  ZONACIUDAD stkey;
  ZONACIUDAD *pZona = (ZONACIUDAD *)NULL;
  BOOL bRes = TRUE;

  strcpy (stkey.szCodRegion   ,szCodRegion   );
  strcpy (stkey.szCodProvincia,szCodProvincia);
  strcpy (stkey.szCodCiudad   ,szCodCiudad   );
  strcpy (stkey.szFecDesde    ,szFecZonaImpo );

  if ( (pZona = (ZONACIUDAD *)bsearch(&stkey,pstZonaCiudad,NUM_ZONACIUDAD,
                 sizeof(ZONACIUDAD),iCmpZonaCiudad) )==(ZONACIUDAD *)NULL)
  {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstZonaCiudad");
        bRes = FALSE;
  }
  else
     *piCodZonaImpo = pZona->iCodZonaImpo;

  return (bRes);

}/************************ Final bFindZonaCiudad *****************************/

/*****************************************************************************/
/*                         funcion : iCmpGrpSerConc                          */
/* -Funcion de Comparacion                                                   */
/*****************************************************************************/
int iCmpGrpSerConc (const void* cad1, const void* cad2)
{
  int rc = 0;

  return
       ( (rc = ((GRPSERCONC *)cad1)->iCodConcepto-
               ((GRPSERCONC *)cad2)->iCodConcepto) != 0)?rc:
       ( (rc = strcmp (((GRPSERCONC *)cad1)->szFecDesde,
                       ((GRPSERCONC *)cad2)->szFecDesde)) < 0)?rc:
       ( (rc = strcmp (((GRPSERCONC *)cad1)->szFecHasta,
                       ((GRPSERCONC *)cad2)->szFecHasta)) > 0)?rc:0;
}/*********************** Final iCmpGrpSerConc *******************************/

/*****************************************************************************/
/*                        funcion : vPrintGrpSerConc                         */
/*****************************************************************************/
void vPrintGrpSerConc (GRPSERCONC *pGrp,int iNumGrp)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {

      vDTrazasLog (szExeName,"\n\t*** Tabla FA_GRPSERCONC ***",LOG06);

      for (iInd=0;iInd<NUM_GRPSERCONC;iInd++)
      {
           vDTrazasLog (szExeName, "\t[%d]-Cod.Concepto [%d]\tFec.Desde [%s]\tCod.Grupo Servicio [%d]\tFec.Hasta [%s]"
                                   ,LOG06,iInd,pGrp->iCodConcepto,pGrp->szFecDesde
                                   ,pGrp->iCodGrpServi, pGrp->szFecHasta);

           pGrp++;
      }
    }
}/************************ Final vPrintGrpSerConc ****************************/


/*****************************************************************************/
/*                         funcion : bFindGrpSerConc                         */
/*****************************************************************************/
BOOL bFindGrpSerConc (int iCodConcepto, char *szFecGrp, GRPSERCONC *pGrpS)
{
  GRPSERCONC stkey                     ;
  GRPSERCONC *pGrp = (GRPSERCONC *)NULL;
  BOOL bRes = TRUE;

  stkey.iCodConcepto = iCodConcepto ;
  strcpy (stkey.szFecDesde,szFecGrp);
  strcpy (stkey.szFecHasta,szFecGrp);

  if ((pGrp = (GRPSERCONC *)bsearch (&stkey,pstGrpSerConc,NUM_GRPSERCONC,
               sizeof(GRPSERCONC),iCmpGrpSerConc)) == (GRPSERCONC *)NULL)
  {
       stAnomProceso.iCodConcepto = iCodConcepto;
       iDError (szExeName,ERR021,vInsertarIncidencia, "pstGrpSerConc (Fa_GrpSerConc)");
       bRes = FALSE;
  }
  else
  {
     pGrpS->iCodConcepto = pGrp->iCodConcepto;
     strcpy (pGrpS->szFecDesde , pGrp->szFecDesde);
     strcpy (pGrpS->szFecHasta , pGrp->szFecHasta);
     pGrpS->iCodGrpServi = pGrp->iCodGrpServi;
  }
  return (bRes);
}/************************* bFindGrpSerConc **********************************/

/*****************************************************************************/
/*                          funcion : iCmpConversion                         */
/*****************************************************************************/
int iCmpConversion (const void* cad1, const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((CONVERSION *)cad1)->szCodMoneda,
                    ((CONVERSION *)cad2)->szCodMoneda) )!= 0)?rc:
   ( (rc = strcmp ( ((CONVERSION *)cad1)->szFecDesde,
                    ((CONVERSION *)cad2)->szFecDesde ) ) < 0)?rc:
   ( (rc = strcmp ( ((CONVERSION *)cad1)->szFecHasta ,
                    ((CONVERSION *)cad2)->szFecHasta ) ) > 0)?rc:0;
}/************************ iCmpConversion ************************************/

/*****************************************************************************/
/*                         funcion : bFindConversion                         */
/*****************************************************************************/
BOOL bFindConversion (char *szCodMoneda,char *szFecha,double *dCambio)
{
  CONVERSION stkey;
  CONVERSION *pConv = (CONVERSION *)NULL;


  memset (&stkey,0,sizeof(CONVERSION));

  strcpy (stkey.szCodMoneda,szCodMoneda);
  strcpy (stkey.szFecDesde ,szFecha    );
  strcpy (stkey.szFecHasta ,szFecha    );

  if ((pConv = (CONVERSION *)bsearch (&stkey,pstConversion,NUM_CONVERSION,
                sizeof(CONVERSION),iCmpConversion))==(CONVERSION *)NULL)
  {
       iDError (szExeName,ERR021,vInsertarIncidencia,"pstConversion");
       return FALSE;
  }
  *dCambio = pConv->dCambio;
  return TRUE;

}/************************* bFindConversion **********************************/

/*****************************************************************************/
/*                        funcion : vPrintConversion                         */
/*****************************************************************************/
void vPrintConversion (CONVERSION *pConver,int iInd)
{
  int i = 0;

    if (stStatus.LogNivel >= LOG06)
    {
      vDTrazasLog (szExeName,"\n\t*** Tabla GE_CONVERSION ***\n",LOG06);

      for (i=0;i<iInd;i++)
      {
        vDTrazasLog (szExeName, "\t[%d]-Cod.Moneda [%s]\tFec.Desde [%s]\tFec.Hasta [%s]\tCambio [%lf]"
                                ,LOG06,i,pConver->szCodMoneda
                                ,pConver->szFecDesde
                                ,pConver->szFecHasta
                                ,pConver->dCambio);
        }
    }
}/************************ Final vPrintConversion ****************************/


/*****************************************************************************/
/*                        funcion : iCmpTarifas                              */
/*****************************************************************************/
int iCmpTarifas (const void* cad1, const void* cad2)
{
   int rc = 0;

   return
/*    ( (rc = ((TARIFAS *)cad1)->iCodProducto-
            ((TARIFAS *)cad2)->iCodProducto ) != 0)?rc:
    ( (rc = strcmp ( ((TARIFAS *)cad1)->szCodActAbo,
                     ((TARIFAS *)cad2)->szCodActAbo ) )!= 0)?rc:*/
    ( (rc = strcmp ( ((TARIFAS *)cad1)->szCodTipServ,
                     ((TARIFAS *)cad2)->szCodTipServ) )!= 0)?rc:
    ( (rc = strcmp ( ((TARIFAS *)cad1)->szCodServicio,
                     ((TARIFAS *)cad2)->szCodServicio))!= 0)?rc:
    ( (rc = strcmp ( ((TARIFAS *)cad1)->szCodPlanServ,
                     ((TARIFAS *)cad2)->szCodPlanServ))!= 0)?rc:
    ( (rc = strcmp ( ((TARIFAS *)cad1)->szFecDesde,
                     ((TARIFAS *)cad2)->szFecDesde)  ) < 0 )?rc:0;
}/*********************** Final iCmpTarifas **********************************/

/*****************************************************************************/
/*                       funcion : vPrintTarifas                             */
/*****************************************************************************/
void vPrintTarifas (TARIFAS *pTar,int iNumTar)
{
   int i = 0;

    if (stStatus.LogNivel >= LOG06)
    {
       vDTrazasLog (szExeName,"\n\t*** Carga de GA_TARIFAS ***",LOG06);

       for (i=0;i<iNumTar;i++)
       {
            vDTrazasLog (szExeName,"\n\t[%d]-Cod.TipServ.....[%s]"
                                   "\n\t[%d]-Cod.Servicio....[%s]"
                                   "\n\t[%d]-Fec.Desde.......[%s]"
                                   "\n\t[%d]-Imp.Tarifa......[%f]"
                                   "\n\t[%d]-Cod.Moneda......[%s]"
                                   "\n\t[%d]-Ind.Periodico...[%s]"
                                   "\n\t[%d]-Fec.Hasta.......[%s]"
                                   ,LOG06
                                   ,i,pTar[i].szCodTipServ
                                   ,i,pTar[i].szCodPlanServ
                                   ,i,pTar[i].szFecDesde
                                   ,i,pTar[i].dImpTarifa
                                   ,i,pTar[i].szCodMoneda
                                   ,i,pTar[i].szIndPeriodico
                                   ,i,pTar[i].szFecHasta);

        }
    }
}/********************** Final vPrintTarifas *********************************/

/*****************************************************************************/
/*                      funcion : iCmpCuadCtoPlan                            */
/*****************************************************************************/
int iCmpCuadCtoPlan (const void* cad1,const void* cad2)
{
  return
   ( ((CUADCTOPLAN *)cad1)->lCodCtoPlan <
     ((CUADCTOPLAN *)cad2)->lCodCtoPlan )?-1:
   ( ((CUADCTOPLAN *)cad1)->lCodCtoPlan >
     ((CUADCTOPLAN *)cad2)->lCodCtoPlan )? 1:
   ( ((CUADCTOPLAN *)cad1)->dImpUmbDesde<
     ((CUADCTOPLAN *)cad2)->dImpUmbDesde)?-1:0;

}/*********************** iCmpCuadCtoPlan ************************************/

/*****************************************************************************/
/*                       funcion : bFindCuadCtoPlan                          */
/* -Funcion que busca un registro en pstCuadCtoPlan (Ve_CuadCtoPlan) con el  */
/*  el parametro de busqueda lCodCtoPlan                                     */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bFindCuadCtoPlan (long lCodCtoPlan, double dImporte,CUADCTOPLAN *pCuad)
{
  CUADCTOPLAN stkey;
  BOOL bRes = TRUE;
  CUADCTOPLAN *pCuad_Aux = (CUADCTOPLAN *)NULL;


  stkey.lCodCtoPlan = lCodCtoPlan;
  stkey.dImpUmbDesde= dImporte   ;

  vDTrazasLog (szExeName, "\n\t *  Busca Registro en pstCuadCtoPlan "
                          "\n\t\t=>  Cod_CtoPlan          [%d]"
                          "\n\t\t=>  Umbral Desde         [%.f]"
                          "\n\t\t=>  Total de Registros   [%d]",
                          LOG05,
                          stkey.lCodCtoPlan,
                          stkey.dImpUmbDesde,
                          NUM_CUADCTOPLAN);

  if ( (pCuad_Aux = (CUADCTOPLAN *)bsearch(&stkey,pstCuadCtoPlan,NUM_CUADCTOPLAN,
                 sizeof(CUADCTOPLAN),iCmpCuadCtoPlan))==(CUADCTOPLAN *)NULL)
  {
        iDError (szExeName,ERR021,vInsertarIncidencia,
                 "pstCuadCtoPlan=>(Ve_CuadCtoPlan)");
        bRes = FALSE;
  }
  pCuad->lCodCtoPlan  = pCuad_Aux->lCodCtoPlan  ;
  pCuad->dImpUmbDesde = pCuad_Aux->dImpUmbDesde ;
  pCuad->dImpUmbHasta = pCuad_Aux->dImpUmbHasta ;
  pCuad->dImpDescuento= pCuad_Aux->dImpDescuento;
  pCuad->iCodTipoDto  = pCuad_Aux->iCodTipoDto  ;

  return bRes;
}/************************** Final bFinaCuadCtoPlan **************************/

/*****************************************************************************/
/*                          funcion : bGetMaxColPreFa                        */
/* -Funcion que gestiona Max(Columna) en memoria, es a nivel de cliente, si  */
/*  el concepto no esta en memoria, se inserta y Columna = 1, si esta se le  */
/*  suma uno a la columna.                                                   */
/*****************************************************************************/
BOOL bGetMaxColPreFa (int iCodConcepto,long *lColumna)
{
    if (pstMaxColPreFa[iCodConcepto].iFlagExiste ==  1)
    {
        pstMaxColPreFa[iCodConcepto].lColumna ++;
    }
    else
    {
       pstMaxColPreFa[iCodConcepto].iFlagExiste = 1;
       pstMaxColPreFa[iCodConcepto].lColumna    = 1;
    }

    *lColumna = pstMaxColPreFa[iCodConcepto].lColumna;

      return TRUE;

}/************************ Final bGetMaxColPreFa *****************************/

/*****************************************************************************/
/*                         funcion : vFreeMaxColPreFa                        */
/*****************************************************************************/
void vFreeMaxColPreFa (void)
{
    int iInd;

    for (iInd=0;iInd<MAX_CONCEPTOS;iInd++)
    {
         pstMaxColPreFa[iInd].iFlagExiste   = 0;
         pstMaxColPreFa[iInd].lColumna      = 0;
    }

}/*********************** Final vFreeMaxColPreFa *****************************/

/*****************************************************************************/
/*                      funcion : bGetCatImpCliente                          */
/* -Funcion que devuelve la categoria impositiva del cliente,dependiendo de  */
/*  la fecha.                                                                */
/* -Fecha: CONTADO=>Sysdate                                                  */
/*         CREDITO=>Fecha de Emision del mes en curso al generar el cargo    */
/* -Valores Retorno: Error->FALSE,!Error->TRUE                               */
/*****************************************************************************/
BOOL bGetCatImpCliente (long  lCodCliente,
                        int  *iCodCatImp ,
                        char *szFecha    ,
                        int   iTipFact)
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static long  lhCodCliente    ;
 static char* szhFecha        ; /* EXEC SQL VAR szhFecha         IS STRING(15); */ 

 static int   ihCodCatImpos   ;
 static char* szhIndOrdenTotal; /* EXEC SQL VAR szhIndOrdenTotal IS STRING(13); */ 

 /* EXEC SQL END DECLARE SECTION; */ 



 lhCodCliente     = lCodCliente                 ;
 szhFecha         = szFecha                     ;
 szhIndOrdenTotal = stDatosGener.szIndOrdenTotal;

 vDTrazasLog (szExeName,"\n\t\t* Entrada Categoria Impositiva"
                        "\n\t\t=> Cliente   [%ld]"
                        "\n\t\t=> Fecha     [%s] ",LOG05,lCodCliente,szFecha);

 /* EXEC SQL SELECT /o+ index (GE_CATIMPCLIENTES PK_GE_CATIMPCLIENTES) o/
                 COD_CATIMPOS  ,
                 TO_CHAR (FA_SEQ_IND_ORDENTOTAL.NEXTVAL)
          INTO   :ihCodCatImpos,
                 :szhIndOrdenTotal
          FROM   GE_CATIMPCLIENTES
          WHERE  COD_CLIENTE = :lhCodCliente
            AND  FEC_DESDE <= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS')
            AND  FEC_HASTA >= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 38;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select  /*+  index (GE_CATIMPCLIENTES PK_GE_CATIMPCLIENTES) \
 +*/ COD_CATIMPOS ,TO_CHAR(FA_SEQ_IND_ORDENTOTAL.nextval ) into :b0,:b1  from \
GE_CATIMPCLIENTES where ((COD_CLIENTE=:b2 and FEC_DESDE<=TO_DATE(:b3,'YYYYMMDD\
HH24MISS')) and FEC_HASTA>=TO_DATE(:b3,'YYYYMMDDHH24MISS'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1123;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&ihCodCatImpos;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)szhIndOrdenTotal;
 sqlstm.sqhstl[1] = (unsigned long )13;
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
 sqlstm.sqhstv[3] = (unsigned char  *)szhFecha;
 sqlstm.sqhstl[3] = (unsigned long )15;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)szhFecha;
 sqlstm.sqhstl[4] = (unsigned long )15;
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



 vDTrazasLog (szExeName,
              "\n\t\t* SQLCODE [%ld]\n",LOG05,SQLCODE);
 fprintf (stderr,"SQLCODE [%d]\n",SQLCODE);

 if (SQLCODE != SQLOK)
 {
     iDError (szExeName,ERR000,vInsertarIncidencia,
              "Select->Ge_CatImpClientes (Fa_Seq_Ind_OrdenTotal)",
              szfnORAerror());
     return FALSE;
 }
 *iCodCatImp = ihCodCatImpos;

 return TRUE;
}/************************** bGetCatImpCliente ******************************/


/*****************************************************************************/
/*                      funcion : bGetCatTribCliente                         */
/* -Funcion que devuelve la categoria tributaria del cliente,dependiendo de  */
/*  la fecha.                                                                */
/* -Fecha: CONTADO=>Sysdate                                                  */
/*         CICLO  =>Fecha Emision                                            */
/* -Valores Retorno: Error->FALSE,!Error->TRUE                               */
/*****************************************************************************/
BOOL bGetCatTribCliente(long  lCodCliente,
                        char *szCodCatTribut,
                        char *szFecha    )
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static long  lhCodCliente       ;
 static char  szhFecha       [20]; /* EXEC SQL VAR szhFecha         IS STRING(20); */ 

 static char  szhCodCatTribut[2] ; /* EXEC SQL VAR szhCodCatTribut  IS STRING(2); */ 

 /* EXEC SQL END DECLARE SECTION; */ 



 lhCodCliente = lCodCliente;
 strcpy(szhFecha,szFecha);

 vDTrazasLog (szExeName,"\n\t\t* Entrada Categoria Tributaria"
                        "\n\t\t=> Cliente   [%ld]"
                        "\n\t\t=> Fecha     [%s] ",LOG05,lCodCliente,szFecha);

 /* EXEC SQL SELECT COD_CATRIBUT
          INTO   :szhCodCatTribut
          FROM   GA_CATRIBUTCLIE
          WHERE  COD_CLIENTE = :lhCodCliente
            AND  FEC_DESDE <= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS')
            AND  FEC_HASTA >= TO_DATE (:szhFecha,'YYYYMMDDHH24MISS'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 38;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COD_CATRIBUT into :b0  from GA_CATRIBUTCLIE where ((C\
OD_CLIENTE=:b1 and FEC_DESDE<=TO_DATE(:b2,'YYYYMMDDHH24MISS')) and FEC_HASTA>=\
TO_DATE(:b2,'YYYYMMDDHH24MISS'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1158;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szhCodCatTribut;
 sqlstm.sqhstl[0] = (unsigned long )2;
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
 sqlstm.sqhstv[2] = (unsigned char  *)szhFecha;
 sqlstm.sqhstl[2] = (unsigned long )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szhFecha;
 sqlstm.sqhstl[3] = (unsigned long )20;
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



 if (SQLCODE != SQLOK)
 {
     iDError (szExeName,ERR021,vInsertarIncidencia,
              "Ga_CaTributClie (Factura/Boleta)");
     return FALSE;
 }
 strcpy(szCodCatTribut,szhCodCatTribut);

 return TRUE;
}/************************** bGetCatTribClientes ******************************/



/*****************************************************************************/
/*                         funcion : iCmpCatImpCliente                       */
/*****************************************************************************/
int iCmpCatImpCliente (const void* cad1, const void* cad2)
{
    int rc = 0;

    return
        ( (rc=((CATIMPCLIENTES *)cad1)->lCodCliente -
              ((CATIMPCLIENTES *)cad2)->lCodCliente) != 0)?rc:
        ( (rc = strcmp (((CATIMPCLIENTES *)cad1)->szFecDesde,
                        ((CATIMPCLIENTES *)cad2)->szFecDesde) ) != 0)?rc:0;

}/************************* Final iCmpCatImpCliente **************************/

/*****************************************************************************/
/*                         funcion : vPrintCatImpCliente                     */
/*****************************************************************************/
void vPrintCatImpCliente (CATIMPCLIENTES *pCat,int iNumCat)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {
        vDTrazasLog (szExeName,"\n\t\t*** Tabla GE_CATIMPCLIENTES ***\n",LOG06);

        for (iInd=0;iInd<NUM_CATIMPCLIENTES;iInd++)
        {
            vDTrazasLog (szExeName,"\t[%d]-Cod.Cliente................[%ld]"
                                  "\t[%d]-Fec.Desde..................[%s] "
                                  "\t[%d]-Fec.Hasta..................[%s] "
                                  "\t[%d]-Cod.Categoria Impositiva...[%d]\n"
                                  ,LOG06
                                  ,iInd,pCat->lCodCliente
                                  ,iInd,pCat->szFecDesde
                                  ,iInd,pCat->szFecHasta
                                  ,iInd,pCat->iCodCatImpos);

            pCat++;
        }
    }
}/************************ Final vPrintCatImpCliente *************************/

/* --------------------------------------------------------------------------*/
/*   bChangeIndEstadoPro (long,int,int)                                      */
/*      Cambia el estado del proceso de iFrom a iTo                          */
/*      Valores Retorno: FALSE - Error                                       */
/*                       TRUE  - Ningun Error                                */
/* --------------------------------------------------------------------------*/
BOOL bChangeIndEstadoPro (long lNumProceso,int iFrom, int iTo)
{

  /* EXEC SQL UPDATE /o+ index (FA_PROCESOS PK_FA_PROCESOS) o/
                  FA_PROCESOS
              SET IND_ESTADO   = :iTo
            WHERE NUM_PROCESO  = :lNumProceso; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "update  /*+  index (FA_PROCESOS PK_FA_PROCESOS)  +*/ FA_PRO\
CESOS  set IND_ESTADO=:b0 where NUM_PROCESO=:b1";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1189;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&iTo;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&lNumProceso;
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


/*              AND IND_ESTADO   = :iFrom;    */

  if (SQLCODE == SQLOK && stCliente.iModVenta == 2)
  {

       /* EXEC SQL UPDATE /o+ index (FA_PROCESOS PK_FA_PROCESOS) o/
                       FA_PROCESOS
                   SET IND_ESTADO   = :iTo
                 WHERE NUM_PROCESO  = :stStatus.IdPro2
                   AND IND_ESTADO   = :iFrom; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 38;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "update  /*+  index (FA_PROCESOS PK_FA_PROCESOS)  +*/ F\
A_PROCESOS  set IND_ESTADO=:b0 where (NUM_PROCESO=:b1 and IND_ESTADO=:b2)";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )1212;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)256;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&iTo;
       sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&(stStatus.IdPro2);
       sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&iFrom;
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
  if (SQLCODE != 0 && SQLCODE != SQLNOTFOUND)
      iDError (szExeName,ERR000,vInsertarIncidencia,
               "Update->Fa_Procesos",szfnORAerror());


  return (SQLCODE != 0 && SQLCODE != SQLNOTFOUND)?FALSE:TRUE;

}/*----------------------- Final bChangeIndEstadoPro -------------------------*/

/*****************************************************************************/
/*                          funcion : bSetNumFactura                         */
/* -Funcion que inserta un reg. en Fa_Procesos .                             */
/*  La estructura stProceso se inicializa en factura.c con parametros de en- */
/*  trada (Usuario,Proceso,TipoFact)                                         */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
BOOL bSetNumFactura (int   iTipoFact     ,
                     TRANSCONTADO *pTranC, VENTAS *pVenta)
{

 vDTrazasLog (szExeName,
              "\n\t\t* Num Proceso [%ld]\n",LOG03,stStatus.IdPro);

 stProceso.lNumProceso  = stStatus.IdPro;

 switch (iTipoFact)
 {
     case FACT_CONTADO:
          stProceso.iCodTipDocum = stDatosGener.iCodContado;
          stProceso.lCodCiclFact = ORA_NULL                ;

          if (pVenta->lNumVenta       != ORA_NULL &&
              pTranC->lNumTransaccion != ORA_NULL)
          {
              if (!bGetVenta (pVenta))
                   return FALSE;
              strcpy (stProceso.szCodOficina,pVenta->szCodOficina)     ;
              stProceso.lCodVendedorAgente = pVenta->lCodVendedorAgente;
          }
          if (pVenta->lNumVenta       == ORA_NULL &&
              pTranC->lNumTransaccion != ORA_NULL)
          {
              if (!bGetTransContado (pTranC))
                   return FALSE;
              strcpy (stProceso.szCodOficina,pTranC->szCodOficina)     ;
              stProceso.lCodVendedorAgente = pTranC->lCodVendedorAgente;
          }
          if (!bGetCentrEmi (stProceso.szCodOficina ,
                             stProceso.iCodTipDocum ,
                             &stProceso.iCodCentrEmi))
               return FALSE;
          if (!bGetLetra (stProceso.iCodTipDocum,
                          stCliente.iCodCatImpos,
                          stProceso.szLetraAg   ))
               return FALSE;
          if (!bGenNumSecuenciasEmi (stProceso.iCodTipDocum,
                                     stProceso.szLetraAg   ,
                                     stProceso.iCodCentrEmi,
                                     &stProceso.lNumSecuAg))
               return FALSE;
          break;
     case FACT_CICLO:
          stProceso.iCodTipDocum = stDatosGener.iCodCiclo              ;
          stProceso.lCodCiclFact = stCiclo.lCodCiclFact                ;
          stProceso.lCodVendedorAgente = stDatosGener.lCodAgenteStartel;
          if (!bGetCentrEmi (stProceso.szCodOficina ,
                             stProceso.iCodTipDocum ,
                             &stProceso.iCodCentrEmi))
               return FALSE;
          break;
     case FACT_BAJA       :
     case FACT_LIQUIDACION:
     case FACT_RENTAPHONE :
     case FACT_ROAMINGVIS :
          switch (iTipoFact)
          {
              case FACT_BAJA       :
                   stProceso.iCodTipDocum = stDatosGener.iCodBaja       ;
                   break                                                ;
              case FACT_RENTAPHONE :
                   stProceso.iCodTipDocum = stDatosGener.iCodRentaPhone ;
                   break                                                ;
              case FACT_LIQUIDACION:
                   stProceso.iCodTipDocum = stDatosGener.iCodLiquidacion;
                   break                                                ;
              case FACT_ROAMINGVIS :
                   stProceso.iCodTipDocum = stDatosGener.iCodRoamingVis ;
                   break                                                ;
          }
          stProceso.lCodCiclFact = stCiclo.lCodCiclFact;

          stProceso.lCodVendedorAgente = stDatosGener.lCodAgenteStartel;

          strcpy (stProceso.szCodOficina,stCliente.szCodOficina);

          if (!bGetCentrEmi (stProceso.szCodOficina ,
                             stProceso.iCodTipDocum ,
                             &stProceso.iCodCentrEmi))
               return FALSE;

          if (!bGetLetra (stProceso.iCodTipDocum,
                          stCliente.iCodCatImpos,
                          stProceso.szLetraAg   ))
               return FALSE;
          if (!bGenNumSecuenciasEmi (stProceso.iCodTipDocum,
                                     stProceso.szLetraAg   ,
                                     stProceso.iCodCentrEmi,
                                     &stProceso.lNumSecuAg))
               return FALSE;
          break;
      default: break;
 }/* fin del switch */
 if (iTipoFact != FACT_NOTACRED && iTipoFact != FACT_NOTADEBI)
 {
     strcpy (stProceso.szFecEfectividad,szSysDate);
     if (!bInsertaProceso (stProceso))
          return FALSE;
 }
 return TRUE;
}/************************* Final bSetNumFactura *****************************/

/*****************************************************************************/
/*                        funcion : bfnGetProceso                            */
/*****************************************************************************/
BOOL bfnGetProceso (PROCESO *pP)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int   ihCodTipDocum            ;
  static long  lhCodVendedorAgente      ;
  static int   ihCodCentrEmi            ;
  static char  szhFecEfectividad    [15];
                                 /* EXEC SQL VAR szhFecEfectividad IS STRING(15); */ 

  static char  szhNomUsuarOra       [31];
                                 /* EXEC SQL VAR szhNomUsuarOra    IS STRING(31); */ 

  static char  szhLetraAg            [2];
                                 /* EXEC SQL VAR szhLetraAg        IS STRING(2) ; */ 

  static long  lhNumSecuAg              ;
  static int   ihCodTipDocNot           ;
  static long  lhCodVendedorAgenteNot   ;
  static char  szhLetraNot           [2];
                                 /* EXEC SQL VAR szhLetraNot       IS STRING(2) ; */ 

  static int   ihCodCentrNot            ;
  static long  lhNumSecuNot             ;
  static int   ihIndEstado              ;
  static long  lhCodCiclFact            ;
  static int   ihIndNotaCredC           ;
  static short i_shCodTipDocum          ;
  static short i_shCodVendedorAgente    ;
  static short i_shCodCentrEmi          ;
  static short i_shFecEfectividad       ;
  static short i_shNomUsuarOra          ;
  static short i_shLetraAg              ;
  static short i_shNumSecuAg            ;
  static short i_shCodTipDocNot         ;
  static short i_shCodVendedorAgenteNot ;
  static short i_shLetraNot             ;
  static short i_shCodCentrNot          ;
  static short i_shNumSecuNot           ;
  static short i_shIndEstado            ;
  static short i_shCodCiclFact          ;
  /* EXEC SQL END DECLARE SECTION; */ 


  vDTrazasLog (szExeName,"\n\t\t* Parametro de Proceso a Select Fa_Procesos"
                         "\n\t\t=>Num.Proceso [%ld]", LOG04, pP->lNumProceso);

  /* EXEC SQL SELECT /o+ index (FA_PROCESOS PK_FA_PROCESOS) o/
                  COD_TIPDOCUM          ,
                  COD_VENDEDOR_AGENTE   ,
                  COD_CENTREMI          ,
                  TO_CHAR (FEC_EFECTIVIDAD,'YYYYMMDDHH24MISS'),
                  NOM_USUARORA          ,
                  LETRAAG               ,
                  NUM_SECUAG            ,
                  COD_TIPDOCNOT         ,
                  COD_VENDEDOR_AGENTENOT,
                  LETRANOT              ,
                  COD_CENTRNOT          ,
                  NUM_SECUNOT           ,
                  IND_ESTADO            ,
                  IND_NOTACREDC         ,
                  COD_CICLFACT
            INTO  :ihCodTipDocum         :i_shCodTipDocum         ,
                  :lhCodVendedorAgente   :i_shCodVendedorAgente   ,
                  :ihCodCentrEmi         :i_shCodCentrEmi         ,
                  :szhFecEfectividad     :i_shFecEfectividad      ,
                  :szhNomUsuarOra        :i_shNomUsuarOra         ,
                  :szhLetraAg            :i_shLetraAg             ,
                  :lhNumSecuAg           :i_shNumSecuAg           ,
                  :ihCodTipDocNot        :i_shCodTipDocNot        ,
                  :lhCodVendedorAgenteNot:i_shCodVendedorAgenteNot,
                  :szhLetraNot           :i_shLetraNot            ,
                  :ihCodCentrNot         :i_shCodCentrNot         ,
                  :lhNumSecuNot          :i_shNumSecuNot          ,
                  :ihIndEstado           :i_shIndEstado           ,
                  :ihIndNotaCredC                                 ,
                  :lhCodCiclFact         :i_shCodCiclFact
           FROM   FA_PROCESOS
           WHERE  NUM_PROCESO = :pP->lNumProceso; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index (FA_PROCESOS PK_FA_PROCESOS)  +*/ COD_TI\
PDOCUM ,COD_VENDEDOR_AGENTE ,COD_CENTREMI ,TO_CHAR(FEC_EFECTIVIDAD,'YYYYMMDDHH\
24MISS') ,NOM_USUARORA ,LETRAAG ,NUM_SECUAG ,COD_TIPDOCNOT ,COD_VENDEDOR_AGENT\
ENOT ,LETRANOT ,COD_CENTRNOT ,NUM_SECUNOT ,IND_ESTADO ,IND_NOTACREDC ,COD_CICL\
FACT into :b0:b1,:b2:b3,:b4:b5,:b6:b7,:b8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b\
17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:b26,:b27:b28  from FA_PROCESOS where N\
UM_PROCESO=:b29";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1239;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&ihCodTipDocum;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&i_shCodTipDocum;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&lhCodVendedorAgente;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&i_shCodVendedorAgente;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&ihCodCentrEmi;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&i_shCodCentrEmi;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)szhFecEfectividad;
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&i_shFecEfectividad;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)szhNomUsuarOra;
  sqlstm.sqhstl[4] = (unsigned long )31;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&i_shNomUsuarOra;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)szhLetraAg;
  sqlstm.sqhstl[5] = (unsigned long )2;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&i_shLetraAg;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&lhNumSecuAg;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&i_shNumSecuAg;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&ihCodTipDocNot;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&i_shCodTipDocNot;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&lhCodVendedorAgenteNot;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&i_shCodVendedorAgenteNot;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)szhLetraNot;
  sqlstm.sqhstl[9] = (unsigned long )2;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&i_shLetraNot;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&ihCodCentrNot;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&i_shCodCentrNot;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&lhNumSecuNot;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&i_shNumSecuNot;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&ihIndEstado;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&i_shIndEstado;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&ihIndNotaCredC;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&lhCodCiclFact;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&i_shCodCiclFact;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&(pP->lNumProceso);
  sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
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


   if (SQLCODE)
   {
       iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_Procesos",
                szfnORAerror());
       return FALSE;
   }
   if (SQLCODE == SQLOK)
   {
       pP->iCodTipDocum      = (i_shCodTipDocum          == ORA_NULL)?ORA_NULL:
                                ihCodTipDocum         ;
       pP->lCodVendedorAgente= (i_shCodVendedorAgente    == ORA_NULL)?ORA_NULL:
                                lhCodVendedorAgente   ;
       pP->iCodCentrEmi      = (i_shCodCentrEmi          == ORA_NULL)?ORA_NULL:
                                ihCodCentrEmi         ;
       pP->lNumSecuAg        = (i_shNumSecuAg            == ORA_NULL)?ORA_NULL:
                                lhNumSecuAg           ;
       pP->iCodTipDocNot     = (i_shCodTipDocNot         == ORA_NULL)?ORA_NULL:
                                ihCodTipDocNot        ;
       pP->lCodVendedorAgenteNot
                             = (i_shCodVendedorAgenteNot == ORA_NULL)?ORA_NULL:
                                lhCodVendedorAgenteNot;
       pP->iCodCentrNot      = (i_shCodCentrNot          == ORA_NULL)?ORA_NULL:
                                ihCodCentrNot         ;
       pP->lNumSecuNot       = (i_shNumSecuNot           == ORA_NULL)?ORA_NULL:
                                lhNumSecuNot          ;
       pP->iIndEstado        = (i_shIndEstado            == ORA_NULL)?ORA_NULL:
                                ihIndEstado           ;
       pP->lCodCiclFact      = (i_shCodCiclFact          == ORA_NULL)?ORA_NULL:
                                lhCodCiclFact         ;

       pP->iIndNotaCredC     = ihIndNotaCredC         ;

       if (i_shFecEfectividad != ORA_NULL)
           strcpy (pP->szFecEfectividad,szhFecEfectividad);
       else
           pP->szFecEfectividad[0] = 0;

       if (i_shNomUsuarOra    != ORA_NULL)
           strcpy (pP->szNomUsuarOra,szhNomUsuarOra);
       else
           pP->szNomUsuarOra[0] = 0;

       if (i_shLetraAg != ORA_NULL)
           strcpy (pP->szLetraAg,szhLetraAg);
       else
           pP->szLetraAg[0] = 0;

       if (i_shLetraNot != ORA_NULL)
           strcpy (pP->szLetraNot,szhLetraNot);
       else
           pP->szLetraNot[0] = 0;
   }
   return TRUE;
}/************************* Final bfnGetProceso ******************************/

/*****************************************************************************/
/*                             funcion : bInsertaProceso                     */
/*****************************************************************************/
BOOL bInsertaProceso (PROCESO stProc)
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static long  lhNumProceso       ;
 static int   ihCodTipDocum      ;
 static long  lhCodVendedorAgente;
 static int   ihCodCentrEmi      ;
 static char* szhFecEfectividad  ;/* EXEC SQL VAR szhFecEfectividad IS STRING(15); */ 

 static char* szhNomUsuarOra     ;/* EXEC SQL VAR szhNomUsuarOra    IS STRING(31); */ 

 static char* szhLetraAg         ;/* EXEC SQL VAR szhLetraAg        IS STRING(2) ; */ 

 static long  lhNumSecuAg        ;
 static int   ihCodTipDocNot     ;
 static long  lhCodVendedorAgenteNot;
 static char* szhLetraNot        ;/* EXEC SQL VAR szhLetraNot       IS STRING(2) ; */ 

 static int   ihCodCentrNot      ;
 static long  lhNumSecuNot       ;
 static short shIndEstado        ;
 static long  lhCodCiclFact      ;
 static short i_shCodTipDocum    ;
 static short i_shCodVendedorAgente;
 static short i_shCodCentrEmi    ;
 static short i_shNomUsuarOra    ;
 static short i_shLetraAg        ;
 static short i_shNumSecuAg      ;
 static short i_shCodTipDocNot   ;
 static short i_shCodVendedorAgenteNot;
 static short i_shLetraNot       ;
 static short i_shNumSecuNot     ;
 static short i_shIndEstado      ;
 static short i_shCodCiclFact    ;
 /* EXEC SQL END DECLARE SECTION; */ 


 lhNumProceso           = stProc.lNumProceso          ;
 ihCodTipDocum          = stProc.iCodTipDocum         ;
 lhCodVendedorAgente    = stProc.lCodVendedorAgente   ;
 ihCodCentrEmi          = stProc.iCodCentrEmi         ;
 szhFecEfectividad      = stProc.szFecEfectividad     ;
 szhNomUsuarOra         = stProc.szNomUsuarOra        ;
 szhLetraAg             = stProc.szLetraAg            ;
 lhNumSecuAg            = stProc.lNumSecuAg           ;
 ihCodTipDocNot         = stProc.iCodTipDocNot        ;
 lhCodVendedorAgenteNot = stProc.lCodVendedorAgenteNot;
 szhLetraNot            = stProc.szLetraNot           ;
 ihCodCentrNot          = stProc.iCodCentrNot         ;
 lhNumSecuNot           = stProc.lNumSecuNot          ;
 shIndEstado            = stProc.iIndEstado           ;
 lhCodCiclFact          = stProc.lCodCiclFact         ;

 i_shCodTipDocum       = (ihCodTipDocum       == ORA_NULL)?ORA_NULL:0;
 i_shCodVendedorAgente = (lhCodVendedorAgente == ORA_NULL)?ORA_NULL:0;
 i_shCodCentrEmi       = (ihCodCentrEmi       == ORA_NULL)?ORA_NULL:0;
 i_shNumSecuAg         = (lhNumSecuAg         == ORA_NULL)?ORA_NULL:0;
 i_shCodTipDocNot      = (ihCodTipDocNot      == ORA_NULL)?ORA_NULL:0;
 i_shNumSecuNot        = (lhNumSecuNot        == ORA_NULL)?ORA_NULL:0;
 i_shIndEstado         = (shIndEstado         == ORA_NULL)?ORA_NULL:0;
 i_shCodCiclFact       = (lhCodCiclFact       == ORA_NULL)?ORA_NULL:0;

 i_shNomUsuarOra    = ( strlen (szhNomUsuarOra   ) == 0)?ORA_NULL:0;
 i_shLetraAg        = ( strlen (szhLetraAg       ) == 0)?ORA_NULL:0;
 i_shLetraNot       = ( strlen (szhLetraNot      ) == 0)?ORA_NULL:0;

 i_shCodVendedorAgenteNot = (lhCodVendedorAgente == ORA_NULL)?ORA_NULL:0;

 vDTrazasLog (szExeName,"\n\t\t* Inserta en Fa_Procesos"
                        "\n\t\t=>Num.Proceso    [%ld]"
                        "\n\t\t=>Cod.TipDocum   [%d] "
                        "\n\t\t=>Cod.VendedorAg.[%ld]"
                        "\n\t\t=>Cod.CentrEmi   [%d] "
                        "\n\t\t=>Num.SecuAg     [%ld]"
                        "\n\t\t=>Cod.TipDocNot  [%d] "
                        "\n\t\t=>Cod.CentrNot   [%d] "
                        "\n\t\t=>Num.SecuNot    [%ld]"
                        "\n\t\t=>Ind.Estado     [%d] "
                        "\n\t\t=>Cod.CiclFact   [%ld]"
                        "\n\t\t=>Fec.Efectivid. [%s] "
                        "\n\t\t=>Nom.UsuarOra   [%s] "
                        "\n\t\t=>LetraNot       [%s] "
                        "\n\t\t=>Cod.VendAgNot  [%ld]",LOG05,
                        lhNumProceso , ihCodTipDocum    , lhCodVendedorAgente,
                        ihCodCentrEmi, lhNumSecuAg      , ihCodTipDocNot     ,
                        ihCodCentrNot, lhNumSecuNot     , shIndEstado        ,
                        lhCodCiclFact, szhFecEfectividad, szhNomUsuarOra     ,
                        szhLetraNot  , lhCodVendedorAgenteNot);

 /* EXEC SQL INSERT INTO FA_PROCESOS
                 (NUM_PROCESO           ,
                  COD_TIPDOCUM          ,
                  COD_VENDEDOR_AGENTE   ,
                  COD_CENTREMI          ,
                  FEC_EFECTIVIDAD       ,
                  NOM_USUARORA          ,
                  LETRAAG               ,
                  NUM_SECUAG            ,
                  COD_TIPDOCNOT         ,
                  COD_VENDEDOR_AGENTENOT,
                  LETRANOT              ,
                  COD_CENTRNOT          ,
                  NUM_SECUNOT           ,
                  IND_ESTADO            ,
                  COD_CICLFACT)
          VALUES (:lhNumProceso                                   ,
                  :ihCodTipDocum:i_shCodTipDocum                  ,
                  :lhCodVendedorAgente:i_shCodVendedorAgente      ,
                  :ihCodCentrEmi:i_shCodCentrEmi                  ,
                  TO_DATE(:szhFecEfectividad,'YYYYMMDDHH24MISS')  ,
                  :szhNomUsuarOra:i_shNomUsuarOra                 ,
                  :szhLetraAg:i_shLetraAg                         ,
                  :lhNumSecuAg:i_shNumSecuAg                      ,
                  :ihCodTipDocNot:i_shCodTipDocNot                ,
                  :lhCodVendedorAgenteNot:i_shCodVendedorAgenteNot,
                  :szhLetraNot:i_shLetraNot                       ,
                  :ihCodCentrNot:i_shCodCentrEmi                  ,
                  :lhNumSecuNot:i_shNumSecuNot                    ,
                  :shIndEstado:i_shIndEstado                      ,
                  :lhCodCiclFact:i_shCodCiclFact); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 38;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into FA_PROCESOS (NUM_PROCESO,COD_TIPDOCUM,COD_VENDED\
OR_AGENTE,COD_CENTREMI,FEC_EFECTIVIDAD,NOM_USUARORA,LETRAAG,NUM_SECUAG,COD_TIP\
DOCNOT,COD_VENDEDOR_AGENTENOT,LETRANOT,COD_CENTRNOT,NUM_SECUNOT,IND_ESTADO,COD\
_CICLFACT) values (:b0,:b1:b2,:b3:b4,:b5:b6,TO_DATE(:b7,'YYYYMMDDHH24MISS'),:b\
8:b9,:b10:b11,:b12:b13,:b14:b15,:b16:b17,:b18:b19,:b20:b21,:b22:b23,:b24:b25,:\
b26:b27)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1318;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&ihCodTipDocum;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&i_shCodTipDocum;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&lhCodVendedorAgente;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&i_shCodVendedorAgente;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&ihCodCentrEmi;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&i_shCodCentrEmi;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)szhFecEfectividad;
 sqlstm.sqhstl[4] = (unsigned long )15;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)szhNomUsuarOra;
 sqlstm.sqhstl[5] = (unsigned long )31;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&i_shNomUsuarOra;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)szhLetraAg;
 sqlstm.sqhstl[6] = (unsigned long )2;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&i_shLetraAg;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&lhNumSecuAg;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&i_shNumSecuAg;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&ihCodTipDocNot;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&i_shCodTipDocNot;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&lhCodVendedorAgenteNot;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&i_shCodVendedorAgenteNot;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)szhLetraNot;
 sqlstm.sqhstl[10] = (unsigned long )2;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&i_shLetraNot;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&ihCodCentrNot;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&i_shCodCentrEmi;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&lhNumSecuNot;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&i_shNumSecuNot;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&shIndEstado;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&i_shIndEstado;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&lhCodCiclFact;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&i_shCodCiclFact;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
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



   if (SQLCODE != SQLOK && SQLCODE != ORA_NULL)
       iDError (szExeName,ERR000,vInsertarIncidencia,"Insert->Fa_Procesos",
                szfnORAerror());

   return (SQLCODE != SQLOK && SQLCODE != ORA_NULL)?FALSE:TRUE;
}/************************* Final bInsertaProceso ***************************/

/****************************************************************************/
/*                          funcion : iCmpLetras                            */
/****************************************************************************/
int iCmpLetras (const void* cad1, const void* cad2)
{
  int rc = 0;

  return
   ( (rc = ((LETRAS *)cad1)->iCodTipDocum-
           ((LETRAS *)cad2)->iCodTipDocum ) != 0)?rc:
   ( (rc = ((LETRAS *)cad1)->iCodCatImpos-
           ((LETRAS *)cad2)->iCodCatImpos ) != 0)?rc:0;

}/************************* Final iCmpLetras ********************************/

/*****************************************************************************/
/*                          funcion : vPrintLetras                           */
/*****************************************************************************/
void vPrintLetras (LETRAS *pLetras,int iNumLetra)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {
      vDTrazasLog (szExeName,"\n\t*** Tabla GE_LETRAS ***\n",LOG06);

      for (iInd=0;iInd<iNumLetra;iInd++)
      {
           vDTrazasLog (szExeName,
                        "\t[%d]-Cod.Tipo Documento.........[%d]\n"
                        "\t[%d]-Cod.Categoria Impositiva...[%d]\n"
                        "\t[%d]-Letra......................[%s]\n"
                        ,LOG06
                        ,iInd,pLetras->iCodTipDocum
                        ,iInd,pLetras->iCodCatImpos
                        ,iInd,pLetras->szLetra);
           pLetras++;
      }
    }
}/************************ Final iPrintLetras ********************************/

/*****************************************************************************/
/*                         funcion : bFindLetras                             */
/*****************************************************************************/
BOOL bGetLetra (int iCodTipDocum,int iCodCatImpos,char *szLetra)

{
  LETRAS  stkey                  ;
  LETRAS *pLetra = (LETRAS *)NULL;
  BOOL    bRes   = TRUE          ;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int   ihCodTipDocum;
  static int   ihCodCatImpos;
  static char* szhLetra     ; /* EXEC SQL VAR szhLetra IS STRING(2); */ 

  /* EXEC SQL END DECLARE SECTION  ; */ 


  vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada Ge_Letras\n"
                         "\t\t* CodTipDocum [%d]\n"
                         "\t\t* CodCatImpos [%d]\n",LOG05,
                         iCodTipDocum,iCodCatImpos);

  if (iCodTipDocum == stDatosGener.iCodCiclo)
  {
      stkey.iCodTipDocum = iCodTipDocum;
      stkey.iCodCatImpos = iCodCatImpos;

      if ( (pLetra = (LETRAS *)bsearch (&stkey,pstLetras,NUM_LETRAS,
            sizeof(LETRAS),iCmpLetras)) == (LETRAS *)NULL)
      {
            iDError (szExeName,ERR021,vInsertarIncidencia,
                     "pstLetras (Ge_Letras)");
            bRes = FALSE;
      }
      if (bRes)
          strcpy (szLetra,pLetra->szLetra);
  }
  else
  {
     ihCodTipDocum = iCodTipDocum;
     ihCodCatImpos = iCodCatImpos;
     szhLetra      = szLetra     ;
     /* EXEC SQL SELECT /o+ index (GE_LETRAS PK_GE_LETRAS) o/
                     LETRA
              INTO   :szhLetra
              FROM   GE_LETRAS
              WHERE  COD_TIPDOCUM = :ihCodTipDocum
                AND  COD_CATIMPOS = :ihCodCatImpos; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 38;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select  /*+  index (GE_LETRAS PK_GE_LETRAS)  +*/ LETRA i\
nto :b0  from GE_LETRAS where (COD_TIPDOCUM=:b1 and COD_CATIMPOS=:b2)";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1393;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)szhLetra;
     sqlstm.sqhstl[0] = (unsigned long )2;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&ihCodTipDocum;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&ihCodCatImpos;
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


     if (SQLCODE != SQLOK)
     {
         iDError (szExeName,ERR000,vInsertarIncidencia,
                  "Select->Ge_Letras",szfnORAerror());
         return FALSE;
     }
  }

  return (bRes);
}/*********************** Final bGetLetra ************************************/

/*****************************************************************************/
/*                         funcion : iCmpDocumSucursal                       */
/*****************************************************************************/
int iCmpDocumSucursal (const void *cad1,const void *cad2)
{
   int rc = 0;

   return
    ( (rc = strcmp ( ((DOCUMSUCURSAL *)cad1)->szCodOficina,
                     ((DOCUMSUCURSAL *)cad2)->szCodOficina) ) != 0)?rc:
    ( (rc = ((DOCUMSUCURSAL *)cad1)->iCodTipDocum-
            ((DOCUMSUCURSAL *)cad2)->iCodTipDocum) != 0)?rc:0;

}/************************ Final iCmpDocumSucursal **************************/

/****************************************************************************/
/*                         funcion : vPrintDocumSucursal                    */
/****************************************************************************/
void vPrintDocumSucursal (DOCUMSUCURSAL *pDoc,int iNumDoc)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {
      vDTrazasLog (szExeName,"\n\t*** Tabla AL_DOCUM_SUCURSAL ***\n",LOG06);

      for (iInd=0;iInd<iNumDoc;iInd++)
      {
           vDTrazasLog (szExeName,
                        "\t[%d]-Cod.Oficina [%s]\tCod.Tipo Documento [%d]\tCod.Centro Emisor [%d]\n"
                        ,LOG06,iInd,pDoc->szCodOficina
                        ,pDoc->iCodTipDocum
                        ,pDoc->iCodCentrEmi);
           pDoc++;
      }
    }
}/************************ Final vPrintDocumSucursal ************************/

/****************************************************************************/
/*                         funcion : bGetCentrEmi                           */
/****************************************************************************/
BOOL bGetCentrEmi (char *szCodOficina,
                   int   iCodTipDocum,
                   int  *iCodCentrEmi)
{
  BOOL bRes = FALSE;
  int  iInd = 0    ;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char* szhCodOficina ; /* EXEC SQL VAR szhCodOficina IS STRING(3); */ 

  static int   ihCodTipDocum ;
  static int   ihCodCentrEmi ;
  /* EXEC SQL END DECLARE SECTION  ; */ 


  if (iCodTipDocum == stDatosGener.iCodCiclo)
  {
      vDTrazasLog (szExeName,"\n\t\t* Parametros entra Al_Docum_Sucursal\n"
                             "\t\t=> Cod.TipDocum [%d]\n",LOG05,iCodTipDocum);

      while (!bRes && iInd<NUM_DOCUMSUCURSAL)
      {
             if (pstDocumSucursal[iInd].iCodTipDocum == iCodTipDocum)
                 bRes = TRUE;
             else
                iInd++;
      }

      if (bRes)
      {
          *iCodCentrEmi = pstDocumSucursal[iInd].iCodCentrEmi      ;
          strcpy (szCodOficina,pstDocumSucursal[iInd].szCodOficina);
      }
      else
      {
         iDError (szExeName,ERR021,vInsertarIncidencia,"pstDocumSucursal");
      }
  }
  else
  {
     vDTrazasLog (szExeName,"\n\t\t* Parametros entra Al_Docum_Sucursal\n"
                            "\t\t=> Cod.Oficina  [%s]\n"
                            "\t\t=> Cod.TipDocum [%d]\n",LOG05,
                            szCodOficina,iCodTipDocum);

     szhCodOficina = szCodOficina;
     ihCodTipDocum = iCodTipDocum;
     /* EXEC SQL SELECT /o+ index (AL_DOCUM_SUCURSAL PK_AL_DOCUM_SUCURSAL) o/
                     COD_CENTREMI
              INTO   :ihCodCentrEmi
              FROM   AL_DOCUM_SUCURSAL
              WHERE  COD_OFICINA = :szhCodOficina
                AND  COD_TIPDOCUM= :ihCodTipDocum; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 38;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select  /*+  index (AL_DOCUM_SUCURSAL PK_AL_DOCUM_SUCURS\
AL)  +*/ COD_CENTREMI into :b0  from AL_DOCUM_SUCURSAL where (COD_OFICINA=:b1 \
and COD_TIPDOCUM=:b2)";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )1420;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&ihCodCentrEmi;
     sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)szhCodOficina;
     sqlstm.sqhstl[1] = (unsigned long )3;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&ihCodTipDocum;
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


     if (SQLCODE != SQLOK)
     {
         iDError (szExeName,ERR000,vInsertarIncidencia,
                  "Select->Al_Docum_Sucursal",szfnORAerror());
         bRes = FALSE;
     }
     else
     {
         *iCodCentrEmi = ihCodCentrEmi;
         bRes = TRUE;
     }
  }
  return (bRes);

}/************************ Final bGetCentrEmi *******************************/


/*****************************************************************************/
/*                       funcion : bGetConcOrig                              */
/* -Entrada CodConcepto, CodConcorig (->salida)                              */
/* -Salida  Error->FALSE, !Error->TRUE                                       */
/*****************************************************************************/
BOOL bGetConcOrig (int   iCodConcepto ,
                   char *szCodMoneda  ,
                   char *szDesConcepto,
                   int  *iCodConcOrig)
{
   CONCEPTO pConc;
   memset (&pConc,0,sizeof(CONCEPTO));
   int       iRes  = 0               ;

    vDTrazasLog (szExeName,
                "\n\t* Busqueda de Concepto Origen en Tabla Dinamica pstConceptos "
                "\n\t\t\t  ==> Numero de Conceptos  : [ %d ]  "
                "\n\t\t\t  ==> Concepto             : [ %d ]  ",
                LOG05,
                NUM_CONCEPTOS,
                iCodConcepto ) ;


   if (!bFindConcepto (iCodConcepto,&pConc))
   {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstConceptos");
        iRes  = ERR021;
   }

   if ( iRes == 0 && pConc.iCodConcOrig == ORA_NULL)
   {
        iDError (szExeName,ERR005,vInsertarIncidencia,iCodConcepto);
        stAnomProceso.iCodConcepto = iCodConcepto                  ;
        iRes = ERR005                                              ;
   }
   if ( iRes == 0 && strcmp (szCodMoneda,pConc.szCodMoneda) != 0)
   {
        iDError (szExeName,ERR004,vInsertarIncidencia,iCodConcepto,
                 pConc.iCodConcOrig);
        iRes = ERR004                ;
   }
   if ( iRes == 0 && (pConc.iIndActivo   == 0 ||
                      pConc.iCodTipConce != DESCUENTO) )
   {
        iDError (szExeName,ERR001,vInsertarIncidencia,
                 pConc.iIndActivo  ,
                 pConc.iCodTipConce,0);
        iRes = ERR001;
   }
   else
   {
        strcpy (szDesConcepto,pConc.szDesConcepto);
        *iCodConcOrig = pConc.iCodConcOrig        ;
   }
   if (iRes == 0)
   {
    vDTrazasLog (szExeName,
                "\n\t* Concepto Origen [%d] Para el Concepto con Descuento [%d]\n",
                LOG05,
                pConc.iCodConcOrig,
                iCodConcepto ) ;
    }
    return (iRes == 0)?TRUE:FALSE;
}/************************** Final bGetConcOrig ******************************/

/* ------------------------------------------------------------------------- */
/*                         funcion vInitAnomProceso                          */
/* ------------------------------------------------------------------------- */
void vInitAnomProceso (ANOMPROCESO *pAnomProceso)
{
  pAnomProceso->lNumProceso  = 0;
  pAnomProceso->lCodCliente  = 0;
  pAnomProceso->lNumAbonado  = 0;
  pAnomProceso->iCodConcepto = 0;
  pAnomProceso->iCodProducto = 0;
  pAnomProceso->lCodCiclFact = 0;
  strcpy (pAnomProceso->szDesProceso,"") ;
  strcpy (pAnomProceso->szObsAnomalia,"");
}/************************ Final vInitAnomProceso ****************************/

/*****************************************************************************/
/*                         funcion : vPrintGeImpuestos                       */
/*****************************************************************************/
void vPrintGeImpuestos (IMPUESTOS *pImp,int iNumImp)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {
      vDTrazasLog (szExeName,"\n\t*** Tabla GE_IMPUESTOS ***\n",LOG06);

      for (iInd=0;iInd<NUM_IMPUESTOS;iInd++)
      {
           vDTrazasLog (szExeName, "\n\t[%d]-Cod.CatImpos.........[%d]"
                                   "\n\t[%d]-Cod.ZonaImpos........[%d]"
                                   "\n\t[%d]-Cod.Tipo Impuesto....[%d]"
                                   "\n\t[%d]-Cod.GrupServi........[%d]"
                                   "\n\t[%d]-Fec.Desde............[%s]"
                                   "\n\t[%d]-Cod.ConcGene.........[%d]"
                                   "\n\t[%d]-Fec.Hasta............[%s]"
                                   "\n\t[%d]-Porcentaje Impuesto..[%f]"
                                   ,LOG06,iInd,pImp->iCodCatImpos
                                   ,iInd,pImp->iCodZonaImpo ,iInd,pImp->iCodTipImpues
                                   ,iInd,pImp->iCodGrpServi ,iInd,pImp->szFecDesde
                                   ,iInd,pImp->iCodConcGene ,iInd,pImp->szFecHasta
                                   ,iInd,pImp->fPrcImpuesto );

           pImp++;
      }
    }
}/************************ Final vPrintImpuestos *****************************/

/* ------------------------------------------------------------------------- */
/*   bGetNumSecuenciaEmi (int,char*,int,long*)                               */
/*      Valores Retorno: FALSE - Error                                       */
/*                       TRUE  - Ningun Error                                */
/* ------------------------------------------------------------------------- */
BOOL bGenNumSecuenciasEmi (int iCodTipDocum, char* szLetra,
                           int iCodCentrEmi, long* lNumSecuEmi)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int   ihCodTipDocum    ;
  static int   ihCodCentrEmi    ;
  static char* szhLetra         ; /* EXEC SQL VAR szhLetra IS STRING (2) ; */ 

  static long  lhNumSecuenci    ;
  /* EXEC SQL END DECLARE SECTION; */ 


  szhLetra      = szLetra     ;
  ihCodTipDocum = iCodTipDocum;
  ihCodCentrEmi = iCodCentrEmi;

  vDTrazasLog (szExeName,"\n\t\t* Parametros entrada Ge_SecuenciasEmi\n"
                         "\t\t=> Tipo De Documento [%d]\n"
                         "\t\t=> Cod. CentrEmi     [%d]\n"
                         "\t\t=> Letra             [%s]\n",LOG05,
                         ihCodTipDocum,ihCodCentrEmi,szhLetra);

  vDTrazasLog (szExeName,"\n\t\t* Tipo Documento stProceso [%d]\n", LOG05,stProceso.iCodTipDocum );

  if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
  {
      /* EXEC SQL SELECT FA_SEQ_CICLO.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_CICLO.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1447;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodContado)
  {
      /* EXEC SQL SELECT FA_SEQ_CONTADO.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_CONTADO.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1466;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodMiscela)
  {
      /* EXEC SQL SELECT FA_SEQ_MISCELANEA.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_MISCELANEA.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1485;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodBaja)
  {
      /* EXEC SQL SELECT FA_SEQ_BAJA.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_BAJA.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1504;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodNotaCre)
  {
      /* EXEC SQL SELECT FA_SEQ_CREDITO.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_CREDITO.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1523;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodNotaDeb)
  {
      /* EXEC SQL SELECT FA_SEQ_DEBITO.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_DEBITO.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1542;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodLiquidacion)
  {
      /* EXEC SQL SELECT FA_SEQ_LIQUIDACION.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_LIQUIDACION.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1561;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (stProceso.iCodTipDocum == stDatosGener.iCodRoamingVis)
  {
      /* EXEC SQL SELECT FA_SEQ_ROAMINGVIS.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select FA_SEQ_ROAMINGVIS.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1580;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }
  else if (iCodTipDocum == stDatosGener.iDocStaff)
  {
      /* EXEC SQL SELECT CO_SEQ_PAGO.NEXTVAL INTO :lhNumSecuenci
                 FROM DUAL; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 38;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select CO_SEQ_PAGO.nextval  into :b0  from DUAL ";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1599;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhNumSecuenci;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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


  }

  if (SQLCODE)
  {
      iDError (szExeName,ERR000,vInsertarIncidencia,
               "=> Secuencias Emision", szfnORAerror ());
      return FALSE;
  }
  *lNumSecuEmi = lhNumSecuenci;

  return TRUE;
}/*********************** Final bGenSecuenciasEmi ****************************/


/*****************************************************************************/
/*                       funcion : bGenProcesoII                             */
/* -Funcion que genera nuevo registro en Fa_Procesos para el caso de una ven-*/
/*  ta contado tenga dos modalidades una de Contado y otra de Credito        */
/* -Utilizamos variables globales como :                                     */
/*      * stCliente.iModVenta si es 2 => Contado y Credito                   */
/*      * si stCliente.iModVenta = 2  => Abremos recuperado stStatus.IdPro2  */
/*        el nuevo proceso a insertar.                                       */
/*      * stProceso que estara rellena por la informacion introducida en la  */
/*        tabla Fa_Procesos (solo cambia NumProceso y NumSecuAg              */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bGenProcesoII (void)
{
  if (stCliente.iModVenta == 2)
  {
      if (!bGenNumSecuenciasEmi (stProceso.iCodTipDocum,stProceso.szLetraAg,
                                 stProceso.iCodCentrEmi,&stProceso.lNumSecuAg))
           return FALSE;

      stProceso.lNumProceso = stStatus.IdPro2;
      if (!bInsertaProceso (stProceso))
          return FALSE;
  }
  return TRUE;
}/************************** Final bGenProcesoII *****************************/

/*****************************************************************************/
/*                      funcion : bRestaFechas                               */
/* -Funcion que resta Fecha1 y Fecha2                                        */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bRestaFechas (char *szFecha1,char *szFecha2,int *iNumDias)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int  ihNumDias   ;
  static char szhFecha1[9]; /* EXEC SQL VAR szhFecha1 IS STRING(9); */ 

  static char szhFecha2[9]; /* EXEC SQL VAR szhFecha2 IS STRING(9); */ 

  /* EXEC SQL END DECLARE SECTION  ; */ 


  strncpy (szhFecha1,szFecha1,8);
  strncpy (szhFecha2,szFecha2,8);

  vDTrazasLog (szExeName,"\n\t\t* Resta Fechas : %s - %s \n",LOG06,
               szhFecha1,szhFecha2);

  /* EXEC SQL SELECT TO_DATE (:szhFecha1,'YYYYMMDD') - TO_DATE (:szhFecha2,'YYYYMMDD')
           INTO :ihNumDias
           FROM   DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select (TO_DATE(:b0,'YYYYMMDD')-TO_DATE(:b1,'YYYYMMDD')) in\
to :b2  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1618;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhFecha1;
  sqlstm.sqhstl[0] = (unsigned long )9;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhFecha2;
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&ihNumDias;
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
      iDError (szExeName,ERR000,vInsertarIncidencia,
               "Select Dual (bRestaFecha)->",szfnORAerror());
  if (SQLCODE == SQLOK)
      *iNumDias = (ihNumDias <= 0)?(-1*ihNumDias):(ihNumDias+1);

  return (SQLCODE != 0)?FALSE:TRUE;
}/************************ Final bRestaFechas ********************************/



/*****************************************************************************/
/*                        funcion : vRestaFechas                             */
/*****************************************************************************/
void vRestaFechas (char *szFecha1, char *szFecha2, int *iNumDias)
{
   char szAnoI [5] = "";
   char szAnoF [5] = "";
   char szMesI [3] = "";
   char szMesF [3] = "";
   char szDiaI [3] = "";
   char szDiaF [3] = "";
   int  iAnoI, iAnoF, iMesI, iMesF, iDiaI, iDiaF;
   int  iDifDias = 0, iDifMes = 0, iDifAno = 0;

   if (strncmp (szFecha1,szFecha2,8) > 0)
   {
       strncpy (szAnoI,szFecha2,4);
       szAnoI [4] = '\0';
       iAnoI = atoi (szAnoI);
       strncpy (szAnoF,szFecha1,4);
       szAnoF [4] = '\0';
       iAnoF = atoi (szAnoF);
       strncpy (szMesI,szFecha2+4,2);
       szMesI [2] = '\0';
       iMesI = atoi (szMesI);
       strncpy (szMesF,szFecha1+4,2);
       szMesF [2] = '\0';
       iMesF = atoi (szMesF);
       strncpy (szDiaI,szFecha2+6,2);
       szDiaI [2] = '\0';
       iDiaI = atoi (szDiaI);
       strncpy (szDiaF,szFecha1+6,2);
       szDiaF [2] = '\0';
       iDiaF = atoi (szDiaF);

   }
   else
   {
       strncpy (szAnoI,szFecha1,4);
       szAnoI [4] = '\0';
       iAnoI = atoi (szAnoI);
       strncpy (szAnoF,szFecha2,4);
       szAnoF [4] = '\0';
       iAnoF = atoi (szAnoF);
       strncpy (szMesI,szFecha1+4,2);
       szMesI [2] = '\0';
       iMesI = atoi (szMesI);
       strncpy (szMesF,szFecha2+4,2);
       szMesF [2] = '\0';
       iMesF = atoi (szMesF);
       strncpy (szDiaI,szFecha1+6,2);
       szDiaI [2] = '\0';
       iDiaI = atoi (szDiaI);
       strncpy (szDiaF,szFecha2+6,2);
       szDiaF [2] = '\0';
       iDiaF = atoi (szDiaF);
   }

}/********************** Final vRestaFechas **********************************/

/*****************************************************************************/
/*                       funcion : bAnoBisiesto                              */
/* -Funcion que comprueba que un ano es bisiesto o no.                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bAnoBisiesto (int iAno)
{
   /* if (iAno % 400 == 0)
       return TRUE;
   if (iAno % 4   == 0)
       return TRUE;
   if (iAno % 100 == 0)
       return FALSE;
    */

    /* rao: se mejora */
   if ((iAno % 400 == 0) || (iAno % 4   == 0))
       return TRUE;

   return FALSE;

}/****************************** Final bAnoBisiesto **************************/

/*****************************************************************************/
/*                               funcion : vDiasMes                          */
/* -Funcion que calcula los Dias del Mes de un Ano determinado               */
/*****************************************************************************/
void vDiasMes (int iAno, int iMes, int *iDiasMes)
{
   switch (iMes)
   {
       case 1 : /* Enero */
                *iDiasMes = 31;
                break;
       case 2 : /* Febrero */
/*
                *iDiasMes = (bBisiesto (iAno))?29:28; */
                break;
       case 3 : /* Marzo */
                *iDiasMes = 31;
                break;
       case 4 : /* Abril */
                *iDiasMes = 30;
                break;
       case 5 : /* Mayo */
                *iDiasMes = 31;
                break;
       case 6 : /* Junio */
                *iDiasMes = 30;
                break;
       case 7 : /* Julio */
                *iDiasMes = 31;
                break;
       case 8 : /* Agosto */
                *iDiasMes = 31;
                break;
       case 9 : /* Septiembre */
                *iDiasMes = 30;
                break;
       case 10: /* Octubre */
                *iDiasMes = 31;
                break;
       case 11: /* Noviembre */
                *iDiasMes = 30;
                break;
       case 12: /* Diciembre */
                *iDiasMes = 31;
                break;
   }

}/****************************** Final vDiasMes ******************************/

/*****************************************************************************/
/*                        funcion : iCmpGrupoCob                             */
/*****************************************************************************/
int iCmpGrupoCob (const void* cad1,const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((GRUPOCOB *)cad1)->szCodGrupo,
                    ((GRUPOCOB *)cad2)->szCodGrupo ) ) != 0)?rc:
   ( (rc = ((GRUPOCOB *)cad1)->iCodProducto-
           ((GRUPOCOB *)cad2)->iCodProducto) != 0)?rc:
   ( (rc = ((GRUPOCOB *)cad1)->iCodConcepto-
           ((GRUPOCOB *)cad2)->iCodConcepto) != 0)?rc:
   ( (rc = ((GRUPOCOB *)cad1)->iCodCiclo-
           ((GRUPOCOB *)cad2)->iCodCiclo) != 0)?rc:0;

}/********************** Final iCmpGrupoCob **********************************/


/*****************************************************************************/
/*                       funcion : vPrintGrupoCob                            */
/*****************************************************************************/
void vPrintGrupoCob (GRUPOCOB *pGrp,int iNumGrp)
{
  int iInd = 0;

    if (stStatus.LogNivel >= LOG06)
    {
      vDTrazasLog (szExeName,"\n\t*** Tabla FA_GRUPOCOB ***\n",LOG06);

      for (iInd=0;iInd<iNumGrp;iInd++)
      {
           vDTrazasLog (szExeName,"\n\t[%d]-Cod.Producto....[%d]"
                                  "\n\t[%d]-Cod.Concepto....[%d]"
                                  "\n\t[%d]-Cod.Grupo.......[%s]"
                                  "\n\t[%d]-Cod.Ciclo.......[%d]"
                                  "\n\t[%d]-Tip.Cobro.......[%d]"
                                  "\n\t[%d]-Tip.Cobro Ant...[%d]"
                                  "\n\t[%d]-Fec.Desde.......[%s]"
                                  "\n\t[%d]-Fec.Hasta.......[%s]"
                                  ,LOG06,iInd,pGrp->iCodProducto
                                  ,iInd,pGrp->iCodConcepto ,iInd,pGrp->szCodGrupo
                                  ,iInd,pGrp->iCodCiclo    ,iInd,pGrp->iTipCobro
                                  ,iInd,pGrp->iTipCobroAnt ,iInd,pGrp->szFecDesde
                                  ,iInd,pGrp->szFecHasta);
           pGrp++;
      }
    }
}/********************** Final vPrintGrupoCob ********************************/

/*****************************************************************************/
/*                           funcion : vEligeDirLogs                         */
/*****************************************************************************/
void vEligeDirLogs (char* szLog, char* szErr,int iTipoFact)
{
  char szName [15] = "";

  switch (iTipoFact)
  {
      case FACT_CONTADO    :
           strcpy (szName,"Contado")    ;
           break                        ;
      case FACT_LIQUIDACION:
           strcpy (szName,"Liquidacion");
           break                        ;
      case FACT_RENTAPHONE :
           strcpy (szName,"RentPhone")  ;
           break                        ;
      case FACT_BAJA       :
           strcpy (szName,"Baja")       ;
           break                        ;
      case FACT_ROAMINGVIS :
           strcpy (szName,"Roaming")    ;
           break                        ;
      case FACT_CICLO      :
           strcpy (szName,"Ciclo")      ;
           break                        ;
      case FACT_NOTADEBI   :
           strcpy (szName,"Nota_Debito") ;
           break                         ;
      case FACT_NOTACRED   :
           strcpy (szName,"Nota_Credito");
           break                         ;
      case FACT_COMPRA     :
           strcpy (szName,"Compra")      ;
            break                        ;
      case FACT_MISCELAN    :
           strcpy (szName,"Miscela")     ;
            break                        ;
      default:
           break;
  }
  if (iTipoFact == FACT_CONTADO   || iTipoFact == FACT_LIQUIDACION ||
      iTipoFact == FACT_RENTAPHONE|| iTipoFact == FACT_BAJA        ||
      iTipoFact == FACT_ROAMINGVIS|| iTipoFact == FACT_NOTADEBI    ||
      iTipoFact == FACT_NOTACRED  || iTipoFact == FACT_COMPRA      ||
      iTipoFact == FACT_MISCELAN)
  {
      sprintf (szLog,"%s%8.8s/Factura_%s_%ld_%6.6s.log",stDatosGener.szDirLogs,
               szSysDate,szName,stStatus.IdPro, (szSysDate+7));
      sprintf (szErr,"%s%8.8s/Factura_%s_%ld_%6.6s.err",stDatosGener.szDirLogs,
               szSysDate, szName,stStatus.IdPro, (szSysDate+7));
  }
  else
  {
      if (stCliente.lCodCliente == ORA_NULL)
          sprintf (szLog,"%s%8.8s/Factura_%s_%ld_%d_%s.log",
                   stCiclo.szDirLogs,szSysDate, szName,
                   stCiclo.lCodCiclFact,0, szSysDate);

      sprintf (szLog,"%s%8.8s/Factura_%s_%ld_%ld_%s.log",stCiclo.szDirLogs,
               szSysDate, szName,
               stCiclo.lCodCiclFact,stCliente.lCodCliente, szSysDate)   ;
      sprintf (szErr,"%s%8.8s/Factura_%s_%ld_%s.err",
               stCiclo.szDirLogs, szSysDate, szName,stCiclo.lCodCiclFact,
               szSysDate);
  }
}/************************ Final vEligeDirLogs *******************************/


/*****************************************************************************/
/*                         funcion : bGetUltimoCliPro                        */
/* -Funcion que recupera el ultimo Cliente procesado en caso de haber y sino */
/*  devuelve 0 a stCliente.lCodCliente.                                      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bGetUltimoCliPro (int iCodCiclo, long lCodCiclFact, int iTipoFactura, long *lCodCliente, long *lNumProceso)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int  ihCodTipDocum;
  static int  ihCodCiclo  ;
  static long lhCodCiclFact;

  static long lhCodCliente;
  static short i_hCodCliente;
  static long lhNumProceso;

  /* EXEC SQL END DECLARE SECTION  ; */ 


  ihCodCiclo    = iCodCiclo;
  lhCodCiclFact = lCodCiclFact;
  ihCodTipDocum = iTipoFactura ;

  lhNumProceso = 0;

  vDTrazasLog (szExeName, "\n\t**   InitInstance   **"
                          "\n\t\t   Codigo de Ciclo         [%d]"
                          "\n\t\t   Codigo de Ciclo Fact    [%ld]"
                          "\n\t\t   Tipo de Factura         [%d]",
                          LOG03,iCodCiclo,lCodCiclFact,iTipoFactura);

  /* EXEC SQL SELECT /o+ index_desc (FA_PROCESOS PK_FA_PROCESOS ) o/
                    NUM_PROCESO
           INTO     :lhNumProceso
           FROM     FA_PROCESOS
           WHERE    NUM_PROCESO > 0
           AND      COD_TIPDOCUM   = :ihCodTipDocum
           AND      COD_CICLFACT   = :lhCodCiclFact
           AND      ROWNUM      = 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index_desc (FA_PROCESOS PK_FA_PROCESOS )  +*/ \
NUM_PROCESO into :b0  from FA_PROCESOS where (((NUM_PROCESO>0 and COD_TIPDOCUM\
=:b1) and COD_CICLFACT=:b2) and ROWNUM=1)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1645;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&lhNumProceso;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&ihCodTipDocum;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select Num_Proceso para Factura de Ciclo",
               szfnORAerror());
      return FALSE;
  }

  if (lhNumProceso == 0)
  {
      *lCodCliente = 0;
      *lNumProceso = 0;
      return (TRUE);
  }

  /* EXEC SQL SELECT /o+ index_desc (FA_CICLOCLI UK_FA_CICLOCLI_CICL_CICLOO) o/
                  max(COD_CLIENTE)
           INTO   :lhCodCliente:i_hCodCliente
           FROM   FA_CICLOCLI
           WHERE  COD_CICLO   = :ihCodCiclo
             AND  NUM_PROCESO = :lhNumProceso; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 38;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index_desc (FA_CICLOCLI UK_FA_CICLOCLI_CICL_CI\
CLOO)  +*/ max(COD_CLIENTE) into :b0:b1  from FA_CICLOCLI where (COD_CICLO=:b2\
 and NUM_PROCESO=:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1672;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&lhCodCliente;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&i_hCodCliente;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&ihCodCiclo;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&lhNumProceso;
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



  if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND && i_hCodCliente != ORA_NULL)
  {
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select Ultimo Cliente del Ciclo de Fa_CicloCli",
               szfnORAerror());
      return FALSE;
  }
  if (SQLCODE == SQLOK)
  {
      *lCodCliente = lhCodCliente;
      *lNumProceso = lhNumProceso;
  }
  if (SQLCODE == SQLNOTFOUND || i_hCodCliente == ORA_NULL)
  {
      *lCodCliente = 0;
      *lNumProceso = lhNumProceso;
  }
  return (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)?FALSE:TRUE;
}/************************ Final bGetUltimoCliPro ****************************/


/*****************************************************************************/
/*                        funcion : vPrintRegInsert                          */
/*****************************************************************************/
void vPrintRegInsert (int i,char *szFuncion,BOOL bError)
{
    char szFunc [20] = "";

    strcpy (szFunc,szFuncion);
    if (!bError)
    {
            if (stStatus.LogNivel >= LOG06)
            {
                vDTrazasLog (szExeName,
                 "\n\t\t==>Insertando Registro en FA_PRESUPUESTO (%s):\n\n"
                 "\t\tNumProceso   [%ld]\n"
                 "\t\tCliente      [%ld]\n"
                 "\t\tCod.Concepto [%d] \n"
                 "\t\tColumna      [%ld]\n"
                 "\t\tProducto     [%d] \n"
                 "\t\tCod.Moneda   [%s] \n"
                 "\t\tFec.Valor    [%s] \n"
                 "\t\tFec.Efectiv. [%s] \n"
                 "\t\tImp.Concepto [%lf]\n"
                 "\t\tImp.Factura  [%lf]\n"
                 "\t\tImp.MontoBase[%lf]\n"
                 "\t\tRegion       [%s] \n"
                 "\t\tProvincia    [%s] \n"
                 "\t\tCiudad       [%s] \n"
                 "\t\tModulo       [%s] \n"
                 "\t\tPlan.Comerc. [%d] \n"
                 "\t\tInd. Factur  [%d] \n"
                 "\t\tCod.CatImpos [%d] \n"
                 "\t\tInd.Estado   [%d] \n"
                 "\t\tTipo Concep. [%d] \n"
                 "\t\tNum.Unidades [%d] \n"
                 "\t\tCiclo Fact.  [%ld]\n"
                 "\t\tConcepto Rel.[%d] \n"
                 "\t\tColumna Rel. [%ld]\n"
                 "\t\tNum. Abonado [%ld]\n"
                 "\t\tNum. Terminal[%s] \n"
                 "\t\tCap. Code    [%ld]\n"
                 "\t\tNum. SerieMec[%s] \n"
                 "\t\tNum. SerieLe [%s] \n"
                 "\t\tFla. Impues  [%d] \n"
                 "\t\tFla. Dto.    [%d] \n"
                 "\t\tPrc. Impues. [%f] \n"
                 "\t\tVal. Dto.    [%f] \n"
                 "\t\tTip. Dto.    [%d] \n"
                 "\t\tNum. Venta   [%ld]\n"
                 "\t\tNum. Transac.[%ld]\n"
                 "\t\tMes  Garantia[%d] \n"
                 "\t\tNum. Guia    [%s] \n"
                 "\t\tInd. Alta    [%d] \n"
                 "\t\tInd. SuperTel[%d] \n"
                 "\t\tNum. Paquete [%d] \n"
                 "\t\tInd. Cuota   [%d] \n"
                 "\t\tNum. Cuotas  [%d] \n"
                 "\t\tOrd. Cuota   [%d] \n",LOG06,szFunc    ,
                 stPreFactura.A_PFactura.lNumProceso     [i],
                 stPreFactura.A_PFactura.lCodCliente     [i],
                 stPreFactura.A_PFactura.iCodConcepto    [i],
                 stPreFactura.A_PFactura.lColumna        [i],
                 stPreFactura.A_PFactura.iCodProducto    [i],
                 stPreFactura.A_PFactura.szCodMoneda     [i],
                 stPreFactura.A_PFactura.szFecValor      [i],
                 stPreFactura.A_PFactura.szFecEfectividad[i],
                 stPreFactura.A_PFactura.dImpConcepto    [i],
                 stPreFactura.A_PFactura.dImpFacturable  [i],
                 stPreFactura.A_PFactura.dImpMontoBase   [i],
                 stPreFactura.A_PFactura.szCodRegion     [i],
                 stPreFactura.A_PFactura.szCodProvincia  [i],
                 stPreFactura.A_PFactura.szCodCiudad     [i],
                 stPreFactura.A_PFactura.szCodModulo     [i],
                 stPreFactura.A_PFactura.lCodPlanCom     [i],
                 stPreFactura.A_PFactura.iIndFactur      [i],
                 stPreFactura.A_PFactura.iCodCatImpos    [i],
                 stPreFactura.A_PFactura.iIndEstado      [i],
                 stPreFactura.A_PFactura.iCodTipConce    [i],
                 stPreFactura.A_PFactura.lNumUnidades    [i],       /* Incorporado por PGonzaleg 26-02-2002 */
                 stPreFactura.A_PFactura.lCodCiclFact    [i],
                 stPreFactura.A_PFactura.iCodConceRel    [i],
                 stPreFactura.A_PFactura.lColumnaRel     [i],
                 stPreFactura.A_PFactura.lNumAbonado     [i],
                 stPreFactura.A_PFactura.szNumTerminal   [i],
                 stPreFactura.A_PFactura.lCapCode        [i],
                 stPreFactura.A_PFactura.szNumSerieMec   [i],
                 stPreFactura.A_PFactura.szNumSerieLe    [i],
                 stPreFactura.A_PFactura.iFlagImpues     [i],
                 stPreFactura.A_PFactura.iFlagDto        [i],
                 stPreFactura.A_PFactura.fPrcImpuesto    [i],
                 stPreFactura.A_PFactura.dValDto         [i],
                 stPreFactura.A_PFactura.iTipDto         [i],
                 stPreFactura.A_PFactura.lNumVenta       [i],
                 stPreFactura.A_PFactura.lNumTransaccion [i],
                 stPreFactura.A_PFactura.iMesGarantia    [i],
                 stPreFactura.A_PFactura.szNumGuia       [i],
                 stPreFactura.A_PFactura.iIndAlta        [i],
                 stPreFactura.A_PFactura.iIndSuperTel    [i],
                 stPreFactura.A_PFactura.iNumPaquete     [i],
                 stPreFactura.A_PFactura.iIndCuota       [i],
                 stPreFactura.A_PFactura.iNumCuotas      [i],
                 stPreFactura.A_PFactura.iOrdCuota       [i]);
            }
   }
   else
   {
        vDTrazasError (szExeName,
                 "\n\t\t==>Insertando Registro en FA_PRESUPUESTO (%s):\n\n"
                 "\t\tNumProceso   [%ld]\n"
                 "\t\tCliente      [%ld]\n"
                 "\t\tCod.Concepto [%d] \n"
                 "\t\tColumna      [%ld]\n"
                 "\t\tProducto     [%d] \n"
                 "\t\tCod.Moneda   [%s] \n"
                 "\t\tFec.Valor    [%s] \n"
                 "\t\tFec.Efectiv. [%s] \n"
                 "\t\tImp.Concepto [%lf]\n"
                 "\t\tImp.Factura  [%lf]\n"
                 "\t\tImp.MontoBase[%lf]\n"
                 "\t\tRegion       [%s] \n"
                 "\t\tProvincia    [%s] \n"
                 "\t\tCiudad       [%s] \n"
                 "\t\tModulo       [%s] \n"
                 "\t\tPlan.Comerc. [%d] \n"
                 "\t\tInd. Factur  [%d] \n"
                 "\t\tCod.CatImpos [%d] \n"
                 "\t\tInd.Estado   [%d] \n"
                 "\t\tTipo Concep. [%d] \n"
                 "\t\tNum.Unidades [%d] \n"
                 "\t\tCiclo Fact.  [%ld]\n"
                 "\t\tConcepto Rel.[%d] \n"
                 "\t\tColumna Rel. [%ld]\n"
                 "\t\tNum. Abonado [%ld]\n"
                 "\t\tNum. Terminal[%s] \n"
                 "\t\tCap. Code    [%ld]\n"
                 "\t\tNum. SerieMec[%s] \n"
                 "\t\tNum. SerieLe [%s] \n"
                 "\t\tFla. Impues  [%d] \n"
                 "\t\tFla. Dto.    [%d] \n"
                 "\t\tPrc. Impues. [%f] \n"
                 "\t\tVal. Dto.    [%f] \n"
                 "\t\tTip. Dto.    [%d] \n"
                 "\t\tNum. Venta   [%ld]\n"
                 "\t\tNum. Transac.[%ld]\n"
                 "\t\tMes  Garantia[%d] \n"
                 "\t\tNum. Guia    [%s] \n"
                 "\t\tInd. Alta    [%d] \n"
                 "\t\tInd. SuperTel[%d] \n"
                 "\t\tNum. Paquete [%d] \n"
                 "\t\tInd. Cuota   [%d] \n"
                 "\t\tNum. Cuotas  [%d] \n"
                 "\t\tOrd. Cuota   [%d] \n",LOG03,szFunc    ,
                 stPreFactura.A_PFactura.lNumProceso     [i],
                 stPreFactura.A_PFactura.lCodCliente     [i],
                 stPreFactura.A_PFactura.iCodConcepto    [i],
                 stPreFactura.A_PFactura.lColumna        [i],
                 stPreFactura.A_PFactura.iCodProducto    [i],
                 stPreFactura.A_PFactura.szCodMoneda     [i],
                 stPreFactura.A_PFactura.szFecValor      [i],
                 stPreFactura.A_PFactura.szFecEfectividad[i],
                 stPreFactura.A_PFactura.dImpConcepto    [i],
                 stPreFactura.A_PFactura.dImpFacturable  [i],
                 stPreFactura.A_PFactura.dImpMontoBase   [i],
                 stPreFactura.A_PFactura.szCodRegion     [i],
                 stPreFactura.A_PFactura.szCodProvincia  [i],
                 stPreFactura.A_PFactura.szCodCiudad     [i],
                 stPreFactura.A_PFactura.szCodModulo     [i],
                 stPreFactura.A_PFactura.lCodPlanCom     [i],
                 stPreFactura.A_PFactura.iIndFactur      [i],
                 stPreFactura.A_PFactura.iCodCatImpos    [i],
                 stPreFactura.A_PFactura.iIndEstado      [i],
                 stPreFactura.A_PFactura.iCodTipConce    [i],
                 stPreFactura.A_PFactura.lNumUnidades    [i], /* Incorporado por PGonzaleg 26-02-2002 */
                 stPreFactura.A_PFactura.lCodCiclFact    [i],
                 stPreFactura.A_PFactura.iCodConceRel    [i],
                 stPreFactura.A_PFactura.lColumnaRel     [i],
                 stPreFactura.A_PFactura.lNumAbonado     [i],
                 stPreFactura.A_PFactura.szNumTerminal   [i],
                 stPreFactura.A_PFactura.lCapCode        [i],
                 stPreFactura.A_PFactura.szNumSerieMec   [i],
                 stPreFactura.A_PFactura.szNumSerieLe    [i],
                 stPreFactura.A_PFactura.iFlagImpues     [i],
                 stPreFactura.A_PFactura.iFlagDto        [i],
                 stPreFactura.A_PFactura.fPrcImpuesto    [i],
                 stPreFactura.A_PFactura.dValDto         [i],
                 stPreFactura.A_PFactura.iTipDto         [i],
                 stPreFactura.A_PFactura.lNumVenta       [i],
                 stPreFactura.A_PFactura.lNumTransaccion [i],
                 stPreFactura.A_PFactura.iMesGarantia    [i],
                 stPreFactura.A_PFactura.szNumGuia       [i],
                 stPreFactura.A_PFactura.iIndAlta        [i],
                 stPreFactura.A_PFactura.iIndSuperTel    [i],
                 stPreFactura.A_PFactura.iNumPaquete     [i],
                 stPreFactura.A_PFactura.iIndCuota       [i],
                 stPreFactura.A_PFactura.iNumCuotas      [i],
                 stPreFactura.A_PFactura.iOrdCuota       [i]);
   }
}/************************* Final vPrintRegInsert ****************************/


/*****************************************************************************/
/*                         funcion : bInsertPreFactura                       */
/* -Funcion que inserta en Fa_PreFactura todos los Conceptos Facturables a un*/
/*  Cliente ,sus Descuentos e Impuestos todos ellos guardados en la estruc-  */
/*  tura stPreFactura.                                                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bInsertPreFactura (void)
{
   int  iInd    = 0   ;
   int  i       = 0   ;
   BOOL bError = FALSE;

   char szFuncion [20]="";

 for (i=0;i<stPreFactura.iNumRegistros;i++)
 {
      stPreFactura.A_PFactura.dImpConcepto   [i] =
                     stPreFactura.A_PFactura.dImpConcepto   [i];
      stPreFactura.A_PFactura.dImpFacturable [i] =
        fnCnvDouble (stPreFactura.A_PFactura.dImpFacturable [i], USOFACT);
      stPreFactura.A_PFactura.dValDto        [i] =
        fnCnvDouble (stPreFactura.A_PFactura.dValDto        [i], USOFACT);
      stPreFactura.A_PFactura.fPrcImpuesto   [i] =
        fnCnvDouble (stPreFactura.A_PFactura.fPrcImpuesto   [i], USOFACT);

 }
 if (stPreFactura.iNumRegistros > 0)
 {
     /* EXEC SQL FOR :stPreFactura.iNumRegistros
     INSERT INTO FA_PRESUPUESTO
             (NUM_PROCESO      ,
              COD_CLIENTE      ,
              COD_CONCEPTO     ,
              COLUMNA          ,
              COD_PRODUCTO     ,
              COD_MONEDA       ,
              FEC_VALOR        ,
              FEC_EFECTIVIDAD  ,
              IMP_CONCEPTO     ,
              IMP_MONTOBASE    ,
              IMP_FACTURABLE   ,
              COD_REGION       ,
              COD_PROVINCIA    ,
              COD_CIUDAD       ,
              COD_MODULO       ,
              COD_PLANCOM      ,
              IND_FACTUR       ,
              FEC_VENTA        ,
              COD_CATIMPOS     ,
              COD_PORTADOR     ,
              IND_ESTADO       ,
              COD_TIPCONCE     ,
              NUM_UNIDADES     ,
              COD_CICLFACT     ,
              COD_CONCEREL     ,
              COLUMNA_REL      ,
              NUM_ABONADO      ,
              NUM_TERMINAL     ,
              CAP_CODE         ,
              NUM_SERIEMEC     ,
              NUM_SERIELE      ,
              FLAG_IMPUES      ,
              FLAG_DTO         ,
              PRC_IMPUESTO     ,
              VAL_DTO          ,
              TIP_DTO          ,
              NUM_VENTA        ,
              NUM_TRANSACCION  ,
              MES_GARANTIA     ,
              NUM_GUIA         ,
              IND_ALTA         ,
              IND_SUPERTEL     ,
              NUM_PAQUETE      ,
              IND_CUOTA        ,
              NUM_CUOTAS       ,
              ORD_CUOTA)
VALUES(
  :stPreFactura.A_PFactura.lNumProceso         ,
  :stPreFactura.A_PFactura.lCodCliente         ,
  :stPreFactura.A_PFactura.iCodConcepto        ,
  :stPreFactura.A_PFactura.lColumna            ,
  :stPreFactura.A_PFactura.iCodProducto        ,
  :stPreFactura.A_PFactura.szCodMoneda         ,
  TO_DATE (:stPreFactura.A_PFactura.szFecValor ,
           'YYYYMMDDHH24MISS')                 ,
  TO_DATE (:stPreFactura.A_PFactura.szFecEfectividad,
           'YYYYMMDDHH24MISS')                 ,
  :stPreFactura.A_PFactura.dImpConcepto        ,
  :stPreFactura.A_PFactura.dImpMontoBase       ,
  :stPreFactura.A_PFactura.dImpFacturable      ,
  :stPreFactura.A_PFactura.szCodRegion         ,
  :stPreFactura.A_PFactura.szCodProvincia      ,
  :stPreFactura.A_PFactura.szCodCiudad         ,
  :stPreFactura.A_PFactura.szCodModulo         ,
  :stPreFactura.A_PFactura.lCodPlanCom         ,
  :stPreFactura.A_PFactura.iIndFactur          ,
  SYSDATE                                      ,
  :stPreFactura.A_PFactura.iCodCatImpos        ,
  :stPreFactura.A_PFactura.iCodPortador        ,
  :stPreFactura.A_PFactura.iIndEstado          ,
  :stPreFactura.A_PFactura.iCodTipConce        ,
  :stPreFactura.A_PFactura.lNumUnidades        ,                /o Incorporado por PGonzaleg 26-02-2002 o/
  :stPreFactura.A_PFactura.lCodCiclFact:stPreFactura.A_Ind.i_lCodCiclFact  ,
  :stPreFactura.A_PFactura.iCodConceRel                                    ,
  :stPreFactura.A_PFactura.lColumnaRel                                     ,
  :stPreFactura.A_PFactura.lNumAbonado:stPreFactura.A_Ind.i_lNumAbonado    ,
  :stPreFactura.A_PFactura.szNumTerminal:stPreFactura.A_Ind.i_szNumTerminal,
  :stPreFactura.A_PFactura.lCapCode:stPreFactura.A_Ind.i_lCapCode          ,
  :stPreFactura.A_PFactura.szNumSerieMec:stPreFactura.A_Ind.i_szNumSerieMec,
  :stPreFactura.A_PFactura.szNumSerieLe:stPreFactura.A_Ind.i_szNumSerieLe  ,
  :stPreFactura.A_PFactura.iFlagImpues                                     ,
  :stPreFactura.A_PFactura.iFlagDto                                        ,
  :stPreFactura.A_PFactura.fPrcImpuesto:stPreFactura.A_Ind.i_fPrcImpuesto  ,
  :stPreFactura.A_PFactura.dValDto:stPreFactura.A_Ind.i_dValDto            ,
  :stPreFactura.A_PFactura.iTipDto:stPreFactura.A_Ind.i_iTipDto            ,
  :stPreFactura.A_PFactura.lNumVenta:stPreFactura.A_Ind.i_lNumVenta        ,
  :stPreFactura.A_PFactura.lNumTransaccion:stPreFactura.A_Ind.i_lNumTransaccion,
  :stPreFactura.A_PFactura.iMesGarantia:stPreFactura.A_Ind.i_iMesGarantia  ,
  TO_NUMBER(:stPreFactura.A_PFactura.szNumGuia:stPreFactura.A_Ind.i_szNumGuia) ,
  :stPreFactura.A_PFactura.iIndAlta                                        ,
  :stPreFactura.A_PFactura.iIndSuperTel                                    ,
  :stPreFactura.A_PFactura.iNumPaquete:stPreFactura.A_Ind.i_iNumPaquete    ,
  :stPreFactura.A_PFactura.iIndCuota                                       ,
  :stPreFactura.A_PFactura.iNumCuotas                                      ,
  :stPreFactura.A_PFactura.iOrdCuota); */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 45;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "insert into FA_PRESUPUESTO (NUM_PROCESO,COD_CLIENTE,COD_\
CONCEPTO,COLUMNA,COD_PRODUCTO,COD_MONEDA,FEC_VALOR,FEC_EFECTIVIDAD,IMP_CONCEPT\
O,IMP_MONTOBASE,IMP_FACTURABLE,COD_REGION,COD_PROVINCIA,COD_CIUDAD,COD_MODULO,\
COD_PLANCOM,IND_FACTUR,FEC_VENTA,COD_CATIMPOS,COD_PORTADOR,IND_ESTADO,COD_TIPC\
ONCE,NUM_UNIDADES,COD_CICLFACT,COD_CONCEREL,COLUMNA_REL,NUM_ABONADO,NUM_TERMIN\
AL,CAP_CODE,NUM_SERIEMEC,NUM_SERIELE,FLAG_IMPUES,FLAG_DTO,PRC_IMPUESTO,VAL_DTO\
,TIP_DTO,NUM_VENTA,NUM_TRANSACCION,MES_GARANTIA,NUM_GUIA,IND_ALTA,IND_SUPERTEL\
,NUM_PAQUETE,IND_CUOTA,NUM_CUOTAS,ORD_CUOTA) values (:b1,:b2,:b3,:b4,:b5,:b6,T\
O_DATE(:b7,'YYYYMMDDHH24MISS'),TO_DATE(:b8,'YYYYMMDDHH24MISS'),:b9,:b10,:b11,:\
b12,:b13,:b14,:b15,:b16,:b17,SYSDATE,:b18,:b19,:b20,:b21,:b22,:b23:b24,:b25,:b\
26,:b27:b28,:b29:b30,:b31:b32,:b33:b34,:b35:b36,:b37,:b38,:b39:b40,:b41:b42,:b\
43:b44,:b45:b46,:b47:b48,:b49:b50,TO_NUMBER(:b51:b52),:b53,:b54,:b55:b56,:b57,\
:b58,:b59)";
     sqlstm.iters = (unsigned int  )(stPreFactura.iNumRegistros);
     sqlstm.offset = (unsigned int  )1699;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)((stPreFactura.A_PFactura).lNumProceso);
     sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[0] = (         int  )sizeof(long);
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqharc[0] = (unsigned long  *)0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)((stPreFactura.A_PFactura).lCodCliente);
     sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[1] = (         int  )sizeof(long);
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqharc[1] = (unsigned long  *)0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)((stPreFactura.A_PFactura).iCodConcepto);
     sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[2] = (         int  )sizeof(int);
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqharc[2] = (unsigned long  *)0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)((stPreFactura.A_PFactura).lColumna);
     sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[3] = (         int  )sizeof(long);
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqharc[3] = (unsigned long  *)0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)((stPreFactura.A_PFactura).iCodProducto);
     sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[4] = (         int  )sizeof(short);
     sqlstm.sqindv[4] = (         short *)0;
     sqlstm.sqinds[4] = (         int  )0;
     sqlstm.sqharm[4] = (unsigned long )0;
     sqlstm.sqharc[4] = (unsigned long  *)0;
     sqlstm.sqadto[4] = (unsigned short )0;
     sqlstm.sqtdso[4] = (unsigned short )0;
     sqlstm.sqhstv[5] = (unsigned char  *)((stPreFactura.A_PFactura).szCodMoneda);
     sqlstm.sqhstl[5] = (unsigned long )4;
     sqlstm.sqhsts[5] = (         int  )4;
     sqlstm.sqindv[5] = (         short *)0;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqharc[5] = (unsigned long  *)0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)((stPreFactura.A_PFactura).szFecValor);
     sqlstm.sqhstl[6] = (unsigned long )15;
     sqlstm.sqhsts[6] = (         int  )15;
     sqlstm.sqindv[6] = (         short *)0;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqharc[6] = (unsigned long  *)0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)((stPreFactura.A_PFactura).szFecEfectividad);
     sqlstm.sqhstl[7] = (unsigned long )15;
     sqlstm.sqhsts[7] = (         int  )15;
     sqlstm.sqindv[7] = (         short *)0;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqharc[7] = (unsigned long  *)0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)((stPreFactura.A_PFactura).dImpConcepto);
     sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[8] = (         int  )sizeof(double);
     sqlstm.sqindv[8] = (         short *)0;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
     sqlstm.sqharc[8] = (unsigned long  *)0;
     sqlstm.sqadto[8] = (unsigned short )0;
     sqlstm.sqtdso[8] = (unsigned short )0;
     sqlstm.sqhstv[9] = (unsigned char  *)((stPreFactura.A_PFactura).dImpMontoBase);
     sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[9] = (         int  )sizeof(double);
     sqlstm.sqindv[9] = (         short *)0;
     sqlstm.sqinds[9] = (         int  )0;
     sqlstm.sqharm[9] = (unsigned long )0;
     sqlstm.sqharc[9] = (unsigned long  *)0;
     sqlstm.sqadto[9] = (unsigned short )0;
     sqlstm.sqtdso[9] = (unsigned short )0;
     sqlstm.sqhstv[10] = (unsigned char  *)((stPreFactura.A_PFactura).dImpFacturable);
     sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[10] = (         int  )sizeof(double);
     sqlstm.sqindv[10] = (         short *)0;
     sqlstm.sqinds[10] = (         int  )0;
     sqlstm.sqharm[10] = (unsigned long )0;
     sqlstm.sqharc[10] = (unsigned long  *)0;
     sqlstm.sqadto[10] = (unsigned short )0;
     sqlstm.sqtdso[10] = (unsigned short )0;
     sqlstm.sqhstv[11] = (unsigned char  *)((stPreFactura.A_PFactura).szCodRegion);
     sqlstm.sqhstl[11] = (unsigned long )4;
     sqlstm.sqhsts[11] = (         int  )4;
     sqlstm.sqindv[11] = (         short *)0;
     sqlstm.sqinds[11] = (         int  )0;
     sqlstm.sqharm[11] = (unsigned long )0;
     sqlstm.sqharc[11] = (unsigned long  *)0;
     sqlstm.sqadto[11] = (unsigned short )0;
     sqlstm.sqtdso[11] = (unsigned short )0;
     sqlstm.sqhstv[12] = (unsigned char  *)((stPreFactura.A_PFactura).szCodProvincia);
     sqlstm.sqhstl[12] = (unsigned long )6;
     sqlstm.sqhsts[12] = (         int  )6;
     sqlstm.sqindv[12] = (         short *)0;
     sqlstm.sqinds[12] = (         int  )0;
     sqlstm.sqharm[12] = (unsigned long )0;
     sqlstm.sqharc[12] = (unsigned long  *)0;
     sqlstm.sqadto[12] = (unsigned short )0;
     sqlstm.sqtdso[12] = (unsigned short )0;
     sqlstm.sqhstv[13] = (unsigned char  *)((stPreFactura.A_PFactura).szCodCiudad);
     sqlstm.sqhstl[13] = (unsigned long )6;
     sqlstm.sqhsts[13] = (         int  )6;
     sqlstm.sqindv[13] = (         short *)0;
     sqlstm.sqinds[13] = (         int  )0;
     sqlstm.sqharm[13] = (unsigned long )0;
     sqlstm.sqharc[13] = (unsigned long  *)0;
     sqlstm.sqadto[13] = (unsigned short )0;
     sqlstm.sqtdso[13] = (unsigned short )0;
     sqlstm.sqhstv[14] = (unsigned char  *)((stPreFactura.A_PFactura).szCodModulo);
     sqlstm.sqhstl[14] = (unsigned long )3;
     sqlstm.sqhsts[14] = (         int  )3;
     sqlstm.sqindv[14] = (         short *)0;
     sqlstm.sqinds[14] = (         int  )0;
     sqlstm.sqharm[14] = (unsigned long )0;
     sqlstm.sqharc[14] = (unsigned long  *)0;
     sqlstm.sqadto[14] = (unsigned short )0;
     sqlstm.sqtdso[14] = (unsigned short )0;
     sqlstm.sqhstv[15] = (unsigned char  *)((stPreFactura.A_PFactura).lCodPlanCom);
     sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[15] = (         int  )sizeof(long);
     sqlstm.sqindv[15] = (         short *)0;
     sqlstm.sqinds[15] = (         int  )0;
     sqlstm.sqharm[15] = (unsigned long )0;
     sqlstm.sqharc[15] = (unsigned long  *)0;
     sqlstm.sqadto[15] = (unsigned short )0;
     sqlstm.sqtdso[15] = (unsigned short )0;
     sqlstm.sqhstv[16] = (unsigned char  *)((stPreFactura.A_PFactura).iIndFactur);
     sqlstm.sqhstl[16] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[16] = (         int  )sizeof(short);
     sqlstm.sqindv[16] = (         short *)0;
     sqlstm.sqinds[16] = (         int  )0;
     sqlstm.sqharm[16] = (unsigned long )0;
     sqlstm.sqharc[16] = (unsigned long  *)0;
     sqlstm.sqadto[16] = (unsigned short )0;
     sqlstm.sqtdso[16] = (unsigned short )0;
     sqlstm.sqhstv[17] = (unsigned char  *)((stPreFactura.A_PFactura).iCodCatImpos);
     sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[17] = (         int  )sizeof(int);
     sqlstm.sqindv[17] = (         short *)0;
     sqlstm.sqinds[17] = (         int  )0;
     sqlstm.sqharm[17] = (unsigned long )0;
     sqlstm.sqharc[17] = (unsigned long  *)0;
     sqlstm.sqadto[17] = (unsigned short )0;
     sqlstm.sqtdso[17] = (unsigned short )0;
     sqlstm.sqhstv[18] = (unsigned char  *)((stPreFactura.A_PFactura).iCodPortador);
     sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[18] = (         int  )sizeof(int);
     sqlstm.sqindv[18] = (         short *)0;
     sqlstm.sqinds[18] = (         int  )0;
     sqlstm.sqharm[18] = (unsigned long )0;
     sqlstm.sqharc[18] = (unsigned long  *)0;
     sqlstm.sqadto[18] = (unsigned short )0;
     sqlstm.sqtdso[18] = (unsigned short )0;
     sqlstm.sqhstv[19] = (unsigned char  *)((stPreFactura.A_PFactura).iIndEstado);
     sqlstm.sqhstl[19] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[19] = (         int  )sizeof(short);
     sqlstm.sqindv[19] = (         short *)0;
     sqlstm.sqinds[19] = (         int  )0;
     sqlstm.sqharm[19] = (unsigned long )0;
     sqlstm.sqharc[19] = (unsigned long  *)0;
     sqlstm.sqadto[19] = (unsigned short )0;
     sqlstm.sqtdso[19] = (unsigned short )0;
     sqlstm.sqhstv[20] = (unsigned char  *)((stPreFactura.A_PFactura).iCodTipConce);
     sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[20] = (         int  )sizeof(int);
     sqlstm.sqindv[20] = (         short *)0;
     sqlstm.sqinds[20] = (         int  )0;
     sqlstm.sqharm[20] = (unsigned long )0;
     sqlstm.sqharc[20] = (unsigned long  *)0;
     sqlstm.sqadto[20] = (unsigned short )0;
     sqlstm.sqtdso[20] = (unsigned short )0;
     sqlstm.sqhstv[21] = (unsigned char  *)((stPreFactura.A_PFactura).lNumUnidades);
     sqlstm.sqhstl[21] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[21] = (         int  )sizeof(long);
     sqlstm.sqindv[21] = (         short *)0;
     sqlstm.sqinds[21] = (         int  )0;
     sqlstm.sqharm[21] = (unsigned long )0;
     sqlstm.sqharc[21] = (unsigned long  *)0;
     sqlstm.sqadto[21] = (unsigned short )0;
     sqlstm.sqtdso[21] = (unsigned short )0;
     sqlstm.sqhstv[22] = (unsigned char  *)((stPreFactura.A_PFactura).lCodCiclFact);
     sqlstm.sqhstl[22] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[22] = (         int  )sizeof(long);
     sqlstm.sqindv[22] = (         short *)((stPreFactura.A_Ind).i_lCodCiclFact);
     sqlstm.sqinds[22] = (         int  )sizeof(short);
     sqlstm.sqharm[22] = (unsigned long )0;
     sqlstm.sqharc[22] = (unsigned long  *)0;
     sqlstm.sqadto[22] = (unsigned short )0;
     sqlstm.sqtdso[22] = (unsigned short )0;
     sqlstm.sqhstv[23] = (unsigned char  *)((stPreFactura.A_PFactura).iCodConceRel);
     sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[23] = (         int  )sizeof(int);
     sqlstm.sqindv[23] = (         short *)0;
     sqlstm.sqinds[23] = (         int  )0;
     sqlstm.sqharm[23] = (unsigned long )0;
     sqlstm.sqharc[23] = (unsigned long  *)0;
     sqlstm.sqadto[23] = (unsigned short )0;
     sqlstm.sqtdso[23] = (unsigned short )0;
     sqlstm.sqhstv[24] = (unsigned char  *)((stPreFactura.A_PFactura).lColumnaRel);
     sqlstm.sqhstl[24] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[24] = (         int  )sizeof(long);
     sqlstm.sqindv[24] = (         short *)0;
     sqlstm.sqinds[24] = (         int  )0;
     sqlstm.sqharm[24] = (unsigned long )0;
     sqlstm.sqharc[24] = (unsigned long  *)0;
     sqlstm.sqadto[24] = (unsigned short )0;
     sqlstm.sqtdso[24] = (unsigned short )0;
     sqlstm.sqhstv[25] = (unsigned char  *)((stPreFactura.A_PFactura).lNumAbonado);
     sqlstm.sqhstl[25] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[25] = (         int  )sizeof(long);
     sqlstm.sqindv[25] = (         short *)((stPreFactura.A_Ind).i_lNumAbonado);
     sqlstm.sqinds[25] = (         int  )sizeof(short);
     sqlstm.sqharm[25] = (unsigned long )0;
     sqlstm.sqharc[25] = (unsigned long  *)0;
     sqlstm.sqadto[25] = (unsigned short )0;
     sqlstm.sqtdso[25] = (unsigned short )0;
     sqlstm.sqhstv[26] = (unsigned char  *)((stPreFactura.A_PFactura).szNumTerminal);
     sqlstm.sqhstl[26] = (unsigned long )16;
     sqlstm.sqhsts[26] = (         int  )16;
     sqlstm.sqindv[26] = (         short *)((stPreFactura.A_Ind).i_szNumTerminal);
     sqlstm.sqinds[26] = (         int  )sizeof(short);
     sqlstm.sqharm[26] = (unsigned long )0;
     sqlstm.sqharc[26] = (unsigned long  *)0;
     sqlstm.sqadto[26] = (unsigned short )0;
     sqlstm.sqtdso[26] = (unsigned short )0;
     sqlstm.sqhstv[27] = (unsigned char  *)((stPreFactura.A_PFactura).lCapCode);
     sqlstm.sqhstl[27] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[27] = (         int  )sizeof(long);
     sqlstm.sqindv[27] = (         short *)((stPreFactura.A_Ind).i_lCapCode);
     sqlstm.sqinds[27] = (         int  )sizeof(short);
     sqlstm.sqharm[27] = (unsigned long )0;
     sqlstm.sqharc[27] = (unsigned long  *)0;
     sqlstm.sqadto[27] = (unsigned short )0;
     sqlstm.sqtdso[27] = (unsigned short )0;
     sqlstm.sqhstv[28] = (unsigned char  *)((stPreFactura.A_PFactura).szNumSerieMec);
     sqlstm.sqhstl[28] = (unsigned long )26;
     sqlstm.sqhsts[28] = (         int  )26;
     sqlstm.sqindv[28] = (         short *)((stPreFactura.A_Ind).i_szNumSerieMec);
     sqlstm.sqinds[28] = (         int  )sizeof(short);
     sqlstm.sqharm[28] = (unsigned long )0;
     sqlstm.sqharc[28] = (unsigned long  *)0;
     sqlstm.sqadto[28] = (unsigned short )0;
     sqlstm.sqtdso[28] = (unsigned short )0;
     sqlstm.sqhstv[29] = (unsigned char  *)((stPreFactura.A_PFactura).szNumSerieLe);
     sqlstm.sqhstl[29] = (unsigned long )26;
     sqlstm.sqhsts[29] = (         int  )26;
     sqlstm.sqindv[29] = (         short *)((stPreFactura.A_Ind).i_szNumSerieLe);
     sqlstm.sqinds[29] = (         int  )sizeof(short);
     sqlstm.sqharm[29] = (unsigned long )0;
     sqlstm.sqharc[29] = (unsigned long  *)0;
     sqlstm.sqadto[29] = (unsigned short )0;
     sqlstm.sqtdso[29] = (unsigned short )0;
     sqlstm.sqhstv[30] = (unsigned char  *)((stPreFactura.A_PFactura).iFlagImpues);
     sqlstm.sqhstl[30] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[30] = (         int  )sizeof(short);
     sqlstm.sqindv[30] = (         short *)0;
     sqlstm.sqinds[30] = (         int  )0;
     sqlstm.sqharm[30] = (unsigned long )0;
     sqlstm.sqharc[30] = (unsigned long  *)0;
     sqlstm.sqadto[30] = (unsigned short )0;
     sqlstm.sqtdso[30] = (unsigned short )0;
     sqlstm.sqhstv[31] = (unsigned char  *)((stPreFactura.A_PFactura).iFlagDto);
     sqlstm.sqhstl[31] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[31] = (         int  )sizeof(short);
     sqlstm.sqindv[31] = (         short *)0;
     sqlstm.sqinds[31] = (         int  )0;
     sqlstm.sqharm[31] = (unsigned long )0;
     sqlstm.sqharc[31] = (unsigned long  *)0;
     sqlstm.sqadto[31] = (unsigned short )0;
     sqlstm.sqtdso[31] = (unsigned short )0;
     sqlstm.sqhstv[32] = (unsigned char  *)((stPreFactura.A_PFactura).fPrcImpuesto);
     sqlstm.sqhstl[32] = (unsigned long )sizeof(float);
     sqlstm.sqhsts[32] = (         int  )sizeof(float);
     sqlstm.sqindv[32] = (         short *)((stPreFactura.A_Ind).i_fPrcImpuesto);
     sqlstm.sqinds[32] = (         int  )sizeof(short);
     sqlstm.sqharm[32] = (unsigned long )0;
     sqlstm.sqharc[32] = (unsigned long  *)0;
     sqlstm.sqadto[32] = (unsigned short )0;
     sqlstm.sqtdso[32] = (unsigned short )0;
     sqlstm.sqhstv[33] = (unsigned char  *)((stPreFactura.A_PFactura).dValDto);
     sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[33] = (         int  )sizeof(double);
     sqlstm.sqindv[33] = (         short *)((stPreFactura.A_Ind).i_dValDto);
     sqlstm.sqinds[33] = (         int  )sizeof(short);
     sqlstm.sqharm[33] = (unsigned long )0;
     sqlstm.sqharc[33] = (unsigned long  *)0;
     sqlstm.sqadto[33] = (unsigned short )0;
     sqlstm.sqtdso[33] = (unsigned short )0;
     sqlstm.sqhstv[34] = (unsigned char  *)((stPreFactura.A_PFactura).iTipDto);
     sqlstm.sqhstl[34] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[34] = (         int  )sizeof(short);
     sqlstm.sqindv[34] = (         short *)((stPreFactura.A_Ind).i_iTipDto);
     sqlstm.sqinds[34] = (         int  )sizeof(short);
     sqlstm.sqharm[34] = (unsigned long )0;
     sqlstm.sqharc[34] = (unsigned long  *)0;
     sqlstm.sqadto[34] = (unsigned short )0;
     sqlstm.sqtdso[34] = (unsigned short )0;
     sqlstm.sqhstv[35] = (unsigned char  *)((stPreFactura.A_PFactura).lNumVenta);
     sqlstm.sqhstl[35] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[35] = (         int  )sizeof(long);
     sqlstm.sqindv[35] = (         short *)((stPreFactura.A_Ind).i_lNumVenta);
     sqlstm.sqinds[35] = (         int  )sizeof(short);
     sqlstm.sqharm[35] = (unsigned long )0;
     sqlstm.sqharc[35] = (unsigned long  *)0;
     sqlstm.sqadto[35] = (unsigned short )0;
     sqlstm.sqtdso[35] = (unsigned short )0;
     sqlstm.sqhstv[36] = (unsigned char  *)((stPreFactura.A_PFactura).lNumTransaccion);
     sqlstm.sqhstl[36] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[36] = (         int  )sizeof(long);
     sqlstm.sqindv[36] = (         short *)((stPreFactura.A_Ind).i_lNumTransaccion);
     sqlstm.sqinds[36] = (         int  )sizeof(short);
     sqlstm.sqharm[36] = (unsigned long )0;
     sqlstm.sqharc[36] = (unsigned long  *)0;
     sqlstm.sqadto[36] = (unsigned short )0;
     sqlstm.sqtdso[36] = (unsigned short )0;
     sqlstm.sqhstv[37] = (unsigned char  *)((stPreFactura.A_PFactura).iMesGarantia);
     sqlstm.sqhstl[37] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[37] = (         int  )sizeof(int);
     sqlstm.sqindv[37] = (         short *)((stPreFactura.A_Ind).i_iMesGarantia);
     sqlstm.sqinds[37] = (         int  )sizeof(short);
     sqlstm.sqharm[37] = (unsigned long )0;
     sqlstm.sqharc[37] = (unsigned long  *)0;
     sqlstm.sqadto[37] = (unsigned short )0;
     sqlstm.sqtdso[37] = (unsigned short )0;
     sqlstm.sqhstv[38] = (unsigned char  *)((stPreFactura.A_PFactura).szNumGuia);
     sqlstm.sqhstl[38] = (unsigned long )11;
     sqlstm.sqhsts[38] = (         int  )11;
     sqlstm.sqindv[38] = (         short *)((stPreFactura.A_Ind).i_szNumGuia);
     sqlstm.sqinds[38] = (         int  )sizeof(short);
     sqlstm.sqharm[38] = (unsigned long )0;
     sqlstm.sqharc[38] = (unsigned long  *)0;
     sqlstm.sqadto[38] = (unsigned short )0;
     sqlstm.sqtdso[38] = (unsigned short )0;
     sqlstm.sqhstv[39] = (unsigned char  *)((stPreFactura.A_PFactura).iIndAlta);
     sqlstm.sqhstl[39] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[39] = (         int  )sizeof(short);
     sqlstm.sqindv[39] = (         short *)0;
     sqlstm.sqinds[39] = (         int  )0;
     sqlstm.sqharm[39] = (unsigned long )0;
     sqlstm.sqharc[39] = (unsigned long  *)0;
     sqlstm.sqadto[39] = (unsigned short )0;
     sqlstm.sqtdso[39] = (unsigned short )0;
     sqlstm.sqhstv[40] = (unsigned char  *)((stPreFactura.A_PFactura).iIndSuperTel);
     sqlstm.sqhstl[40] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[40] = (         int  )sizeof(short);
     sqlstm.sqindv[40] = (         short *)0;
     sqlstm.sqinds[40] = (         int  )0;
     sqlstm.sqharm[40] = (unsigned long )0;
     sqlstm.sqharc[40] = (unsigned long  *)0;
     sqlstm.sqadto[40] = (unsigned short )0;
     sqlstm.sqtdso[40] = (unsigned short )0;
     sqlstm.sqhstv[41] = (unsigned char  *)((stPreFactura.A_PFactura).iNumPaquete);
     sqlstm.sqhstl[41] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[41] = (         int  )sizeof(int);
     sqlstm.sqindv[41] = (         short *)((stPreFactura.A_Ind).i_iNumPaquete);
     sqlstm.sqinds[41] = (         int  )sizeof(short);
     sqlstm.sqharm[41] = (unsigned long )0;
     sqlstm.sqharc[41] = (unsigned long  *)0;
     sqlstm.sqadto[41] = (unsigned short )0;
     sqlstm.sqtdso[41] = (unsigned short )0;
     sqlstm.sqhstv[42] = (unsigned char  *)((stPreFactura.A_PFactura).iIndCuota);
     sqlstm.sqhstl[42] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[42] = (         int  )sizeof(short);
     sqlstm.sqindv[42] = (         short *)0;
     sqlstm.sqinds[42] = (         int  )0;
     sqlstm.sqharm[42] = (unsigned long )0;
     sqlstm.sqharc[42] = (unsigned long  *)0;
     sqlstm.sqadto[42] = (unsigned short )0;
     sqlstm.sqtdso[42] = (unsigned short )0;
     sqlstm.sqhstv[43] = (unsigned char  *)((stPreFactura.A_PFactura).iNumCuotas);
     sqlstm.sqhstl[43] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[43] = (         int  )sizeof(int);
     sqlstm.sqindv[43] = (         short *)0;
     sqlstm.sqinds[43] = (         int  )0;
     sqlstm.sqharm[43] = (unsigned long )0;
     sqlstm.sqharc[43] = (unsigned long  *)0;
     sqlstm.sqadto[43] = (unsigned short )0;
     sqlstm.sqtdso[43] = (unsigned short )0;
     sqlstm.sqhstv[44] = (unsigned char  *)((stPreFactura.A_PFactura).iOrdCuota);
     sqlstm.sqhstl[44] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[44] = (         int  )sizeof(int);
     sqlstm.sqindv[44] = (         short *)0;
     sqlstm.sqinds[44] = (         int  )0;
     sqlstm.sqharm[44] = (unsigned long )0;
     sqlstm.sqharc[44] = (unsigned long  *)0;
     sqlstm.sqadto[44] = (unsigned short )0;
     sqlstm.sqtdso[44] = (unsigned short )0;
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
      iInd = (sqlca.sqlerrd[2] == SQLOK)?0:sqlca.sqlerrd[2]-1;
      if (stPreFactura.A_PFactura.bOptCargos[iInd])
          strcpy (szFuncion,"Cargos");
      if (stPreFactura.A_PFactura.bOptPenaliza[iInd])
          strcpy (szFuncion,"Penalizaciones");
      if (stPreFactura.A_PFactura.bOptServicios[iInd])
          strcpy (szFuncion,"Servicios");
      if (stPreFactura.A_PFactura.bOptAbonos[iInd])
          strcpy (szFuncion,"Abonos");
      if (stPreFactura.A_PFactura.bOptTrafico[iInd])
          strcpy (szFuncion,"Trafico");
      if (stPreFactura.A_PFactura.bOptCuotas[iInd])
          strcpy (szFuncion,"Cuotas");
      if (stPreFactura.A_PFactura.bOptDescuento[iInd])
          strcpy (szFuncion,"Descuentos");
      if (stPreFactura.A_PFactura.bOptImpuesto[iInd])
          strcpy (szFuncion,"Impuestos");
      if (stPreFactura.A_PFactura.bOptArriendo[iInd])
          strcpy (szFuncion,"Arriendos");

      vDTrazasLog (szExeName,"Insert de FA_PRESUPUESTO Registro %d\n\t",
                   LOG01, sqlca.sqlerrd[2])  ;
      bError = TRUE                          ;
      vPrintRegInsert (iInd,szFuncion,bError);
      iDError (szExeName,ERR000,vInsertarIncidencia,
               "Insert->Fa_PreSupuesto",szfnORAerror());
      return FALSE;
   }

 }
 vDTrazasLog (szExeName,
              "\n\t\t* Conceptos Procesados [%d] del Cliente [%ld]\n",LOG03,
              stPreFactura.iNumRegistros,stCliente.lCodCliente);
 return TRUE;
}/****************************** Final bInsertPreFactura *********************/

/*****************************************************************************/
/*                             funcion : bGetCodPlanCom                      */
/*****************************************************************************/
BOOL bGetCodPlanCom (long lCodCliente,int iCodProducto,long *lCodPlanCom)
{
  static long lhCodPlanCom;

  if (stDatosGener.iProdCelular == iCodProducto)
  {
      /* EXEC SQL SELECT /o+ index (GA_INTARCEL PK_GA_INTARCEL) o/
                      COD_PLANCOM
               INTO   :lhCodPlanCom
               FROM   GA_INTARCEL
               WHERE  COD_CLIENTE = :lCodCliente
                 AND  ROWNUM      = 1; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 45;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select  /*+  index (GA_INTARCEL PK_GA_INTARCEL)  +*/ CO\
D_PLANCOM into :b0  from GA_INTARCEL where (COD_CLIENTE=:b1 and ROWNUM=1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1894;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhCodPlanCom;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lCodCliente;
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


  }
  else if (stDatosGener.iProdBeeper == iCodProducto)
  {
      /* EXEC SQL SELECT /o+ index (GA_INTARBEEP PK_GA_INTARBEEP) o/
                      COD_PLANCOM
               INTO   :lhCodPlanCom
               FROM   GA_INTARCEL
               WHERE  COD_CLIENTE = :lCodCliente
                 AND  ROWNUM      = 1; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 45;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select  /*+  index (GA_INTARBEEP PK_GA_INTARBEEP)  +*/ \
COD_PLANCOM into :b0  from GA_INTARCEL where (COD_CLIENTE=:b1 and ROWNUM=1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1917;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhCodPlanCom;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lCodCliente;
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


  }
  else if (stDatosGener.iProdTrunk == iCodProducto)
  {
      /* EXEC SQL SELECT /o+ index (GA_INTARTRUNK PK_GA_INTARTRUNK) o/
                      COD_PLANCOM
               INTO   :lhCodPlanCom
               FROM   GA_INTARCEL
               WHERE  COD_CLIENTE = :lCodCliente
                 AND  ROWNUM      = 1; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 45;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select  /*+  index (GA_INTARTRUNK PK_GA_INTARTRUNK)  +*\
/ COD_PLANCOM into :b0  from GA_INTARCEL where (COD_CLIENTE=:b1 and ROWNUM=1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1940;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhCodPlanCom;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lCodCliente;
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


  }
  else if (stDatosGener.iProdTrek == iCodProducto)
  {
      /* EXEC SQL SELECT /o+ index (GA_INTARTREK PK_GA_INTARTREK) o/
                      COD_PLANCOM
               INTO   :lhCodPlanCom
               FROM   GA_INTARCEL
               WHERE  COD_CLIENTE = :lCodCliente
                 AND  ROWNUM      = 1; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 45;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = "select  /*+  index (GA_INTARTREK PK_GA_INTARTREK)  +*/ \
COD_PLANCOM into :b0  from GA_INTARCEL where (COD_CLIENTE=:b1 and ROWNUM=1)";
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )1963;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)256;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqhstv[0] = (unsigned char  *)&lhCodPlanCom;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&lCodCliente;
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


  }

  if (SQLCODE)
  {
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select->CodPlanCom\n",
               szfnORAerror());
      return FALSE;
  }
  if (SQLCODE == SQLOK)
  {
      *lCodPlanCom = lhCodPlanCom;
  }
  return TRUE;
}/******************** bGetCodPlanCom ***************************************/

/*****************************************************************************/
/*                          funcion : bGetIndCliente                         */
/* -Funcion que recupera reg. de la tabla Fa_FactCli que nos informa sobre : */
/*      * Si Existe Penalizaciones a nivel de Cliente                        */
/*      * Si Existe Cargos a nivel de Cliente                                */
/*      * Si Existe Pagares a nivel de Cliente                               */
/*****************************************************************************/
BOOL bfnGetIndCliente (FACTCLI *pFactCli)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static short  shIndPenaliza    ;
  static short  shIndPagare      ;
  static short  shIndCargos      ;
  static long   lhCodCliente     ;
  static char*  szhFecUltPagare  ;/* EXEC SQL VAR szhFecUltPagare   IS STRING(15); */ 

  static char*  szhFecUltCargos  ;/* EXEC SQL VAR szhFecUltCargos   IS STRING(15); */ 

  static char*  szhFecUltPenaliza;/* EXEC SQL VAR szhFecUltPenaliza IS STRING(15); */ 

  /* EXEC SQL END DECLARE SECTION; */ 


  lhCodCliente = stCliente.lCodCliente;

  vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada a Fa_FactCli\n"
                         "\t\t=> Cliente [%ld]\n",LOG04,lhCodCliente);

  szhFecUltPagare   = pFactCli->szFecUltPagare  ;
  szhFecUltCargos   = pFactCli->szFecUltCargos  ;
  szhFecUltPenaliza = pFactCli->szFecUltPenaliza;

  /* EXEC SQL SELECT /o+ index (FA_FACTCLI PK_FA_FACTCLI) o/
                  IND_PENALIZA,
                  IND_PAGARE  ,
                  IND_CARGOS  ,
                  TO_CHAR (FEC_ULTPAGARE  ,'YYYYMMDDHH24MISS'),
                  TO_CHAR (FEC_ULTPENALIZA,'YYYYMMDDHH24MISS'),
                  TO_CHAR (FEC_ULTCARGOS  ,'YYYYMMDDHH24MISS')
            INTO  :shIndPenaliza    ,
                  :shIndPagare      ,
                  :shIndCargos      ,
                  :szhFecUltPagare  ,
                  :szhFecUltPenaliza,
                  :szhFecUltCargos
            FROM  FA_FACTCLI
            WHERE COD_CLIENTE = :lhCodCliente; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 45;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index (FA_FACTCLI PK_FA_FACTCLI)  +*/ IND_PENA\
LIZA ,IND_PAGARE ,IND_CARGOS ,TO_CHAR(FEC_ULTPAGARE,'YYYYMMDDHH24MISS') ,TO_CH\
AR(FEC_ULTPENALIZA,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_ULTCARGOS,'YYYYMMDDHH24MIS\
S') into :b0,:b1,:b2,:b3,:b4,:b5  from FA_FACTCLI where COD_CLIENTE=:b6";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1986;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&shIndPenaliza;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&shIndPagare;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&shIndCargos;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)szhFecUltPagare;
  sqlstm.sqhstl[3] = (unsigned long )15;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)szhFecUltPenaliza;
  sqlstm.sqhstl[4] = (unsigned long )15;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)szhFecUltCargos;
  sqlstm.sqhstl[5] = (unsigned long )15;
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
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_FactCli",
               szfnORAerror());
  if (SQLCODE == SQLOK)
  {
      pFactCli->iIndPagare   = shIndPagare  ;
      pFactCli->iIndPenaliza = shIndPenaliza;
      pFactCli->iIndCargos   = shIndCargos  ;
  }
  return (SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK)?FALSE:TRUE;
}/*************************** Final bGetIndCliente ***************************/

/*****************************************************************************/
/*                           funcion : bRedondeoMoneda                       */
/* -Funcion que redondea un importe en la moneda de facturacion y luego la   */
/*  pasa a la moneda Origen.                                                 */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bRedondeoMoneda (char *szMonedaO,char *szFecha,double *dImporte,
                      int iTipoFact)
{
  if (!bConverMoneda (szMonedaO,stDatosGener.szCodMoneFact,szFecha,dImporte,
                      iTipoFact))
       return FALSE;
  /* rao031008 : se elimina ya que no se redondea a menor prescision
    *dImporte = fnCnvDouble (*dImporte,USOFACT);
  */

  if (!bConverMoneda (stDatosGener.szCodMoneFact,szMonedaO,szFecha,dImporte,
                      iTipoFact))
       return FALSE;
  *dImporte = fnCnvDouble (*dImporte,USOFACT);

 return TRUE;
}/************************* Final vRedondeoMoneda ****************************/

/*****************************************************************************/
/*                         funcion : iCmpCiudades                            */
/*****************************************************************************/
int iCmpCiudades (const void* cad1,const void* cad2)
{
  return ( ((CIUDADES *)cad1)->iAntiguedad-((CIUDADES *)cad2)->iAntiguedad );
}/************************* Final iCmpCiudades *******************************/

/*****************************************************************************/
/*                         funcion : iCmpComunas                             */
/*****************************************************************************/
int iCmpComunas  (const void* cad1,const void* cad2)
{
  return ( ((COMUNAS  *)cad1)->iAntiguedad-((COMUNAS  *)cad2)->iAntiguedad );
}/************************* Final iCmpComunas  *******************************/

/*****************************************************************************/
/*                          funcion : iCmpProvincias                         */
/*****************************************************************************/
int iCmpProvincias (const void* cad1,const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((PROVINCIAS *)cad1)->szCodRegion,
                    ((PROVINCIAS *)cad2)->szCodRegion    ) )!= 0 )?rc:
   ( (rc = strcmp ( ((PROVINCIAS *)cad1)->szCodProvincia,
                    ((PROVINCIAS *)cad2)->szCodProvincia ) )!= 0 )?rc:0;

}/************************** Final iCmpProvincias ****************************/

/*****************************************************************************/
/*                          funcion : bFindProvincias                        */
/*****************************************************************************/
BOOL bFindProvincias (PROVINCIAS *pPr)
{
   PROVINCIAS stkey;
   PROVINCIAS *pP = (PROVINCIAS *)NULL;

   memset (&stkey,0,sizeof(PROVINCIAS));

   strcpy (stkey.szCodRegion   ,pPr->szCodRegion   );
   strcpy (stkey.szCodProvincia,pPr->szCodProvincia);
   if ((pP = (PROVINCIAS *)bsearch (&stkey,pstProvincias,NUM_PROVINCIAS,
             sizeof(PROVINCIAS),iCmpProvincias))==(PROVINCIAS *)NULL)
   {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstProvincias");
        return FALSE;
   }

   strcpy (pPr->szDesProvincia,pP->szDesProvincia);
   return TRUE;
}/**************************** Funcion : bFindProvincia ***********************/


/*****************************************************************************/
/*                          funcion : bFindRegiones                          */
/*****************************************************************************/
BOOL bFindRegiones (REGIONES *pReg)
{
   REGIONES stkey;
   REGIONES *pR = (REGIONES *)NULL;

   strcpy (stkey.szCodRegion   ,pR->szCodRegion);

   if ((pReg = (REGIONES *)bsearch (&stkey,pstRegiones,NUM_REGIONES,
                           sizeof(REGIONES),iCmpRegiones))==(REGIONES *)NULL)
   {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstRegiones");
        return FALSE;
   }

   strcpy (pReg->szDesRegion,pR->szDesRegion);
   return TRUE;
}/**************************** Funcion : bFindRegiones ***********************/


/*****************************************************************************/
/*                          funcion : iCmpRegiones                           */
/*****************************************************************************/
int iCmpRegiones (const void* cad1,const void* cad2)
{
  int rc = 0;

  return
   ( (rc = strcmp ( ((REGIONES *)cad1)->szCodRegion,
                    ((REGIONES *)cad2)->szCodRegion) )  != 0 )?rc:0;

}/************************** Final iCmpRegiones   ****************************/

/*****************************************************************************/
/*                          funcion : iCmpRangoTabla                         */
/*****************************************************************************/
int iCmpRangoTabla (const void* cad1,const void* cad2)
{
  int rc = 0;

  return
   ( (rc =  ((RANGOTABLA *)cad1)->lCodCiclFact-
            ((RANGOTABLA *)cad2)->lCodCiclFact )!= 0)?rc:
   ( (rc =  ((RANGOTABLA *)cad1)->lRangoIni-
            ((RANGOTABLA *)cad1)->lRangoIni    )!= 0)?rc:
   ( (rc =  strcmp ( ((RANGOTABLA *)cad1)->szNomTabla,
                      ((RANGOTABLA *)cad2)->szNomTabla )) != 0)?rc:0 ;
}/************************** Final iCmpRangoTabla ****************************/

/*****************************************************************************/
/*                          funcion : bfnGetDatosCliente                     */
/*****************************************************************************/
BOOL bfnGetDatosCliente (long lCodCliente)
{
 /* EXEC SQL BEGIN DECLARE SECTION; */ 

 static long   lhCodCliente        ;
 static long   lhCodCuenta         ;
 static char   szhNomCliente   [51];/* EXEC SQL VAR szhNomCliente    IS STRING(51); */ 

 static char   szhNomApeClien1 [21];/* EXEC SQL VAR szhNomApeClien1  IS STRING(21); */ 

 static char   szhNomApeClien2 [21];/* EXEC SQL VAR szhNomApeClien2  IS STRING(21); */ 

/* INICIO CH-200606283727 CJG*/
/* static char   szhTefCliente1  [13];EXEC SQL VAR szhTefCliente1   IS STRING(13);
 static char   szhTefCliente2  [13];EXEC SQL VAR szhTefCliente2   IS STRING(13);*/
 static char   szhTefCliente1  [15+1];/* EXEC SQL VAR szhTefCliente1   IS STRING(16); */ 

 static char   szhTefCliente2  [15+1];/* EXEC SQL VAR szhTefCliente2   IS STRING(16); */ 

/* FIN CH-200606283727 CJG*/

 static char   szhCodPais       [4];/* EXEC SQL VAR szhCodPais       IS STRING(4) ; */ 

 static char   szhIndDebito     [2];/* EXEC SQL VAR szhIndDebito     IS STRING(2) ; */ 

 static double dhImpStopDebit      ;
 static char   szhCodBanco     [16];/* EXEC SQL VAR szhCodBanco      IS STRING(16) ; */ 


 static char   szhCodSucursal   [5];/* EXEC SQL VAR szhCodSucursal   IS STRING(5) ; */ 

 static char   szhIndTipCuenta  [2];/* EXEC SQL VAR szhIndTipCuenta  IS STRING(2) ; */ 

 static char   szhNumCtaCorr   [19];/* EXEC SQL VAR szhNumCtaCorr    IS STRING(19); */ 

 static char   szhNumTarjeta   [19];/* EXEC SQL VAR szhNumTarjeta    IS STRING(19); */ 

 static char   szhFecVenciTarj [15];/* EXEC SQL VAR szhFecVenciTarj  IS STRING(15); */ 


 static char   szhCodBancoTarj [16];/* EXEC SQL VAR szhCodBancoTarj  IS STRING(16) ; */ 


 static char   szhCodTipIdTrib  [3];/* EXEC SQL VAR szhCodTipIdTrib  IS STRING(3) ; */ 

 static char   szhNumIdentTrib [21];/* EXEC SQL VAR szhNumIdentTrib  IS STRING(21); */ 

 static char   szhCodTipTarjeta [4];/* EXEC SQL VAR szhCodTipTarjeta IS STRING(4) ; */ 

 static char   szhCodOficina    [3];/* EXEC SQL VAR szhCodOficina    IS STRING(3) ; */ 

 static char   szhNumFax       [16];/* EXEC SQL VAR szhNumFax        IS STRING(16); */ 

 static char   szhFecAlta      [15];/* EXEC SQL VAR szhFecAlta       IS STRING(15); */ 

 static char   szhCodIdioma    [6] ;/* EXEC SQL VAR szhCodIdioma     IS STRING(6); */ 

 static int    ihCodActividad      ;
 static int    ihIndFactur         ;
 static char   szhCodOperadora  [6];/* EXEC SQL VAR szhCodOperadora     IS STRING(6); */ 

 static short  i_shCodOficina      ;
 static short  i_shNomApeClien1    ;
 static short  i_shNomApeClien2    ;
 static short  i_shTefCliente1     ;
 static short  i_shTefCliente2     ;
 static short  i_shCodPais         ;
 static short  i_shIndDebito       ;
 static short  i_shCodTipTarjeta   ;
 static short  i_shImpStopDebit    ;
 static short  i_shCodBanco        ;
 static short  i_shCodSucursal     ;
 static short  i_shIndTipCuenta    ;
 static short  i_shNumCtaCorr      ;
 static short  i_shNumTarjeta      ;
 static short  i_shFecVenciTarj    ;
 static short  i_shCodBancoTarj    ;
 static short  i_shCodTipIdTrib    ;
 static short  i_shNumIdentTrib    ;
 static short  i_shCodActividad    ;
 static short  i_shNumFax          ;
 static short  i_shCodOperadora    ;
 /* EXEC SQL END DECLARE SECTION; */ 


 vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ge_Clientes\n"
                        "\t\t=> Cod.Cliente  [%ld]\n",LOG05,lCodCliente);

 lhCodCliente = lCodCliente;

 /* EXEC SQL SELECT /o+ index (GE_CLIENTES PK_GE_CLIENTES) o/
                  NOM_CLIENTE           ,
                  NOM_APECLIEN1         ,
                  NOM_APECLIEN2         ,
                  TEF_CLIENTE1          ,
                  TEF_CLIENTE2          ,
                  COD_PAIS              ,
                  IND_DEBITO            ,
                  IMP_STOPDEBIT         ,
                  COD_BANCO             ,
                  COD_SUCURSAL          ,
                  IND_TIPCUENTA         ,
                  COD_TIPTARJETA        ,
                  NUM_CTACORR           ,
                  NUM_TARJETA           ,
                  TO_CHAR (FEC_VENCITARJ,'YYYYMMDDHH24MISS'),
                  COD_BANCOTARJ         ,
                  COD_TIPIDTRIB         ,
                  NUM_IDENT             ,
                  COD_ACTIVIDAD         ,
                  COD_OFICINA           ,
                  IND_FACTUR            ,
                  NUM_FAX               ,
                  TO_CHAR (FEC_ALTA,'YYYYMMDDHH24MISS'),
                  COD_CUENTA            ,
                  COD_IDIOMA            ,
                  COD_OPERADORA
           INTO
                  :szhNomCliente       ,
                  :szhNomApeClien1:i_shNomApeClien1    ,
                  :szhNomApeClien2:i_shNomApeClien2    ,
                  :szhTefCliente1:i_shTefCliente1      ,
                  :szhTefCliente2:i_shTefCliente2      ,
                  :szhCodPais:i_shCodPais              ,
                  :szhIndDebito:i_shIndDebito          ,
                  :dhImpStopDebit:i_shImpStopDebit     ,
                  :szhCodBanco:i_shCodBanco            ,
                  :szhCodSucursal:i_shCodSucursal      ,
                  :szhIndTipCuenta:i_shIndTipCuenta    ,
                  :szhCodTipTarjeta:i_shCodTipTarjeta  ,
                  :szhNumCtaCorr:i_shNumCtaCorr        ,
                  :szhNumTarjeta:i_shNumTarjeta        ,
                  :szhFecVenciTarj:i_shFecVenciTarj    ,
                  :szhCodBancoTarj:i_shCodBancoTarj    ,
                  :szhCodTipIdTrib:i_shCodTipIdTrib    ,
                  :szhNumIdentTrib:i_shNumIdentTrib    ,
                  :ihCodActividad:i_shCodActividad     ,
                  :szhCodOficina:i_shCodOficina        ,
                  :ihIndFactur                         ,
                  :szhNumFax:i_shNumFax                ,
                  :szhFecAlta                          ,
                  :lhCodCuenta                         ,
                  :szhCodIdioma                        ,
                  :szhCodOperadora:i_shCodOperadora
           FROM   GE_CLIENTES
           WHERE  COD_CLIENTE = :lhCodCliente; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 45;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select  /*+  index (GE_CLIENTES PK_GE_CLIENTES)  +*/ NOM_CLI\
ENTE ,NOM_APECLIEN1 ,NOM_APECLIEN2 ,TEF_CLIENTE1 ,TEF_CLIENTE2 ,COD_PAIS ,IND_\
DEBITO ,IMP_STOPDEBIT ,COD_BANCO ,COD_SUCURSAL ,IND_TIPCUENTA ,COD_TIPTARJETA \
,NUM_CTACORR ,NUM_TARJETA ,TO_CHAR(FEC_VENCITARJ,'YYYYMMDDHH24MISS') ,COD_BANC\
OTARJ ,COD_TIPIDTRIB ,NUM_IDENT ,COD_ACTIVIDAD ,COD_OFICINA ,IND_FACTUR ,NUM_F\
AX ,TO_CHAR(FEC_ALTA,'YYYYMMDDHH24MISS') ,COD_CUENTA ,COD_IDIOMA ,COD_OPERADOR\
A into :b0,:b1:b2,:b3:b4,:b5:b6,:b7:b8,:b9:b10,:b11:b12,:b13:b14,:b15:b16,:b17\
:b18,:b19:b20,:b21:b22,:b23:b24,:b25:b26,:b27:b28,:b29:b30,:b31:b32,:b33:b34,:\
b35:b36,:b37:b38,:b39,:b40:b41,:b42,:b43,:b44,:b45:b46  from GE_CLIENTES where\
 COD_CLIENTE=:b47";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2029;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)szhNomCliente;
 sqlstm.sqhstl[0] = (unsigned long )51;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)szhNomApeClien1;
 sqlstm.sqhstl[1] = (unsigned long )21;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&i_shNomApeClien1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)szhNomApeClien2;
 sqlstm.sqhstl[2] = (unsigned long )21;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&i_shNomApeClien2;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)szhTefCliente1;
 sqlstm.sqhstl[3] = (unsigned long )16;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&i_shTefCliente1;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)szhTefCliente2;
 sqlstm.sqhstl[4] = (unsigned long )16;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&i_shTefCliente2;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)szhCodPais;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&i_shCodPais;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)szhIndDebito;
 sqlstm.sqhstl[6] = (unsigned long )2;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&i_shIndDebito;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&dhImpStopDebit;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&i_shImpStopDebit;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)szhCodBanco;
 sqlstm.sqhstl[8] = (unsigned long )16;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&i_shCodBanco;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)szhCodSucursal;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&i_shCodSucursal;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)szhIndTipCuenta;
 sqlstm.sqhstl[10] = (unsigned long )2;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&i_shIndTipCuenta;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)szhCodTipTarjeta;
 sqlstm.sqhstl[11] = (unsigned long )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&i_shCodTipTarjeta;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)szhNumCtaCorr;
 sqlstm.sqhstl[12] = (unsigned long )19;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&i_shNumCtaCorr;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)szhNumTarjeta;
 sqlstm.sqhstl[13] = (unsigned long )19;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&i_shNumTarjeta;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)szhFecVenciTarj;
 sqlstm.sqhstl[14] = (unsigned long )15;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&i_shFecVenciTarj;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)szhCodBancoTarj;
 sqlstm.sqhstl[15] = (unsigned long )16;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&i_shCodBancoTarj;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)szhCodTipIdTrib;
 sqlstm.sqhstl[16] = (unsigned long )3;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&i_shCodTipIdTrib;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)szhNumIdentTrib;
 sqlstm.sqhstl[17] = (unsigned long )21;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&i_shNumIdentTrib;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&ihCodActividad;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&i_shCodActividad;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)szhCodOficina;
 sqlstm.sqhstl[19] = (unsigned long )3;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&i_shCodOficina;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&ihIndFactur;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)0;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)szhNumFax;
 sqlstm.sqhstl[21] = (unsigned long )16;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&i_shNumFax;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)szhFecAlta;
 sqlstm.sqhstl[22] = (unsigned long )15;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)0;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&lhCodCuenta;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)0;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)szhCodIdioma;
 sqlstm.sqhstl[24] = (unsigned long )6;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)0;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)szhCodOperadora;
 sqlstm.sqhstl[25] = (unsigned long )6;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&i_shCodOperadora;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&lhCodCliente;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(long);
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



    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ge_Clientes",
                 szfnORAerror());
        return FALSE;
    }
    if (SQLCODE == SQLOK)
    {
        strcpy (stCliente.szCodIdioma, szhCodIdioma);
        strcpy (stCliente.szNomCliente,szhNomCliente);

        if (i_shNomApeClien1 == ORA_NULL)
            stCliente.szNomApeClien1 [0] = 0;
        else
            strcpy (stCliente.szNomApeClien1,szhNomApeClien1);
        if (i_shNomApeClien2 == ORA_NULL)
            stCliente.szNomApeClien2 [0] = 0;
        else
            strcpy (stCliente.szNomApeClien2,szhNomApeClien2);
        if (i_shTefCliente1 == ORA_NULL)
            stCliente.szTefCliente1 [0] = 0;
        else
            strcpy (stCliente.szTefCliente1,szhTefCliente1);
        if (i_shTefCliente2 == ORA_NULL)
            stCliente.szTefCliente1 [0] = 0;
        else
            strcpy (stCliente.szTefCliente1,szhTefCliente2);

        if (i_shCodPais == ORA_NULL)
            stCliente.szCodPais [0] = 0;
        else
           strcpy (stCliente.szCodPais,szhCodPais);

        if (i_shIndDebito == ORA_NULL)
            stCliente.szIndDebito [0] = 0;
        else
            strcpy (stCliente.szIndDebito,szhIndDebito);

        stCliente.dImpStopDebit = (i_shImpStopDebit== ORA_NULL)?0.0:
                                   dhImpStopDebit;
        if (i_shCodBanco == ORA_NULL)
            stCliente.szCodBanco [0] = 0;
        else
            strcpy (stCliente.szCodBanco,szhCodBanco);
        if (i_shCodSucursal == ORA_NULL)
            stCliente.szCodSucursal [0] = 0;
        else
            strcpy (stCliente.szCodSucursal,szhCodSucursal);

        if (i_shIndTipCuenta == ORA_NULL)
            stCliente.szIndTipCuenta [0] = 0;
        else
            strcpy (stCliente.szIndTipCuenta,szhIndTipCuenta);

        if (i_shCodTipTarjeta == ORA_NULL)
            stCliente.szCodTipTarjeta [0] = 0;
        else
            strcpy (stCliente.szCodTipTarjeta,szhCodTipTarjeta);

        if (i_shNumCtaCorr == ORA_NULL)
            stCliente.szNumCtaCorr [0] = 0;
        else
            strcpy (stCliente.szNumCtaCorr,szhNumCtaCorr);

        if (i_shNumTarjeta == ORA_NULL)
            stCliente.szNumTarjeta [0] = 0;
        else
            strcpy (stCliente.szNumTarjeta,szhNumTarjeta);

        if (i_shFecVenciTarj == ORA_NULL)
            stCliente.szFecVenciTarj [0] = 0;
        else
            strcpy (stCliente.szFecVenciTarj,szhFecVenciTarj);

        if (i_shCodBancoTarj == ORA_NULL)
            stCliente.szCodBancoTarj [0] = 0;
        else
            strcpy (stCliente.szCodBancoTarj,szhCodBancoTarj);

        if (i_shCodTipIdTrib == ORA_NULL)
            stCliente.szCodTipIdTrib [0] = 0;
        else
            strcpy (stCliente.szCodTipIdTrib,szhCodTipIdTrib);

        if (i_shNumIdentTrib == ORA_NULL)
            stCliente.szNumIdentTrib [0] = 0    ;
        else
            strcpy (stCliente.szNumIdentTrib,szhNumIdentTrib);

        stCliente.iCodActividad = (i_shCodActividad == ORA_NULL)?ORA_NULL:
                                 ihCodActividad;

        if (i_shCodOficina == ORA_NULL)
            stCliente.szCodOficina [0] = 0      ;
        else
            strcpy (stCliente.szCodOficina,szhCodOficina);

        if (i_shNumFax == ORA_NULL)
            stCliente.szNumFax [0] = 0           ;
        else
            strcpy (stCliente.szNumFax,szhNumFax);

        strcpy (stCliente.szFecAlta, szhFecAlta);
        stCliente.iIndFactur = ihIndFactur;
        stCliente.lCodCuenta = lhCodCuenta;

        if (i_shCodOperadora == ORA_NULL)
            stCliente.szNumFax [0] = 0           ;
        else
          strcpy (stCliente.szCodOperadora,szhCodOperadora);

   }
   return TRUE;
}/************************* Final bfnGetDatosCliente *************************/

/*****************************************************************************/
/*                            funcion bGetDirecCli                           */
/* -Funcion que recupera la Direccion de un Cliente                          */
/* -Valores Entrada : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bfnGetDirecCli (long lCodCliente, int iTipDireccion)
{
  COMUNAS  stComuna;
  CIUDADES stCiudad;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static long  lhCodCliente     ;
  static char* szhCodRegion     ; /* EXEC SQL VAR szhCodRegion     IS STRING(4) ; */ 

  static char* szhCodProvincia  ; /* EXEC SQL VAR szhCodProvincia  IS STRING(6) ; */ 

  static char* szhCodCiudad     ; /* EXEC SQL VAR szhCodCiudad     IS STRING(6) ; */ 

  static char* szhCodComuna     ; /* EXEC SQL VAR szhCodComuna     IS STRING(6) ; */ 

  static char* szhNomCalle      ; /* EXEC SQL VAR szhNomCalle      IS STRING(51); */ 

  static char* szhNumCalle      ; /* EXEC SQL VAR szhNumCalle      IS STRING(11); */ 

  static char* szhNumPiso       ; /* EXEC SQL VAR szhNumPiso       IS STRING(11); */ 

  static short ihCodTipDireccion;
  static short i_shNomCalle     ;
  static short i_shNumPiso      ;
  static short i_shNumCalle     ;

  /* EXEC SQL END DECLARE SECTION  ; */ 


  lhCodCliente  = lCodCliente   ;

  if (iTipDireccion == TIPDIRECCION_FACTURA)
  {
      ihCodTipDireccion = TIPDIRECCION_FACTURA    ;
      szhCodRegion      = stCliente.szCodRegion   ;
      szhCodProvincia   = stCliente.szCodProvincia;
      szhCodCiudad      = stCliente.szCodCiudad   ;
      szhCodComuna      = stCliente.szCodComuna   ;
      szhNomCalle       = stCliente.szNomCalle    ;
      szhNumCalle       = stCliente.szNumCalle    ;
      szhNumPiso        = stCliente.szNumPiso     ;
  }
  else
  {
      memset (&stComuna, 0, sizeof (COMUNAS) );
      memset (&stCiudad, 0, sizeof (CIUDADES));

      ihCodTipDireccion = iTIP_CORRESPONDENCIA   ;
      szhCodRegion      = stCorreo.szCodRegion   ;
      szhCodProvincia   = stCorreo.szCodProvincia;
      szhCodCiudad      = stCorreo.szCodCiudad   ;
      szhCodComuna      = stCorreo.szCodComuna   ;
      szhNomCalle       = stCorreo.szNomCalle    ;
      szhNumCalle       = stCorreo.szNumCalle    ;
      szhNumPiso        = stCorreo.szNumPiso     ;
  }

    strcpy(stCliente.szGls_DirecClie,"X");

  vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada Ga_DirecCli\n"
                         "\t\t=> Cod.Cliente  [%ld]\n",LOG05,lCodCliente);

  /* EXEC SQL SELECT /o+ index (GA_DIRECCLI PK_GA_DIRECCLI) o/
                  A.COD_REGION   ,
                  A.COD_PROVINCIA,
                  A.COD_CIUDAD   ,
                  A.COD_COMUNA   ,
                  A.NOM_CALLE    ,
                  A.NUM_CALLE    ,
                  A.NUM_PISO
           INTO   :szhCodRegion             ,
                  :szhCodProvincia          ,
                  :szhCodCiudad             ,
                  :szhCodComuna             ,
                  :szhNomCalle :i_shNomCalle,
                  :szhNumCalle :i_shNumCalle,
                  :szhNumPiso  :i_shNumPiso
           FROM   GE_DIRECCIONES A, GA_DIRECCLI B
           WHERE  B.COD_CLIENTE      = :lhCodCliente
             AND  B.COD_TIPDIRECCION = :ihCodTipDireccion
             AND  B.COD_DIRECCION    = A.COD_DIRECCION; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 45;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select  /*+  index (GA_DIRECCLI PK_GA_DIRECCLI)  +*/ A.COD_\
REGION ,A.COD_PROVINCIA ,A.COD_CIUDAD ,A.COD_COMUNA ,A.NOM_CALLE ,A.NUM_CALLE \
,A.NUM_PISO into :b0,:b1,:b2,:b3,:b4:b5,:b6:b7,:b8:b9  from GE_DIRECCIONES A ,\
GA_DIRECCLI B where ((B.COD_CLIENTE=:b10 and B.COD_TIPDIRECCION=:b11) and B.CO\
D_DIRECCION=A.COD_DIRECCION)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2152;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)szhCodRegion;
  sqlstm.sqhstl[0] = (unsigned long )4;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhCodProvincia;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)szhCodCiudad;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)szhCodComuna;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)szhNomCalle;
  sqlstm.sqhstl[4] = (unsigned long )51;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&i_shNomCalle;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)szhNumCalle;
  sqlstm.sqhstl[5] = (unsigned long )11;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&i_shNumCalle;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)szhNumPiso;
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&i_shNumPiso;
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
  sqlstm.sqhstv[8] = (unsigned char  *)&ihCodTipDireccion;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(short);
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



  if (SQLCODE != SQLOK)
      iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ga_DirecCli\n\t",
               szfnORAerror());
  if (SQLCODE == SQLOK)
  {
      if (TIPDIRECCION_FACTURA == ihCodTipDireccion)
      {
          if (i_shNumPiso == ORA_NULL)
              stCliente.szNumPiso [0] = 0;
          if (i_shNumCalle== ORA_NULL)
              stCliente.szNumCalle[0] = 0;
          if (i_shNomCalle== ORA_NULL)
              stCliente.szNomCalle[0] = 0;
      }
      vDTrazasLog (szExeName,"\n\t\t * Direccion del Cliente [%ld]\n"
                             "\t\t=> Cod.Region       [%s]\n"
                             "\t\t=> Cod.Provincia    [%s]\n"
                             "\t\t=> Cod.Ciudad       [%s]\n",LOG05,
                   stCliente.lCodCliente   ,stCliente.szCodRegion,
                   stCliente.szCodProvincia,stCliente.szCodCiudad);

      if (ihCodTipDireccion == iTIP_CORRESPONDENCIA)
      {
          strcpy (stComuna.szCodRegion   ,stCorreo.szCodRegion)   ;
          strcpy (stComuna.szCodProvincia,stCorreo.szCodProvincia);
          strcpy (stComuna.szCodComuna   ,stCorreo.szCodComuna)   ;

          if (i_shNumCalle == -1)
              stCorreo.szNumCalle [0] = 0;
          if (i_shNumPiso  == -1)
              stCorreo.szNumPiso  [0] = 0;
          if (i_shNumPiso  == -1)
              stCorreo.szNomCalle [0] = 0;

          if (!bfnFindComuna (&stComuna,stProceso.iCodTipDocum))
               return FALSE;

          strcpy (stCorreo.szDesComuna,stComuna.szDesComuna);

          strcpy (stCiudad.szCodRegion   ,stCorreo.szCodRegion)   ;
          strcpy (stCiudad.szCodProvincia,stCorreo.szCodProvincia);
          strcpy (stCiudad.szCodCiudad   ,stCorreo.szCodCiudad)   ;

          if (!bfnFindCiudad (&stCiudad,stProceso.iCodTipDocum))
               return FALSE;

          strcpy (stCorreo.szDesCiudad,stCiudad.szDesCiudad);

      }
  }
  return (SQLCODE != SQLOK)?FALSE:TRUE;

}/************************* Final bGetDirecCli *******************************/


/* -------------------------------------------------------------------------- */
/*   vInitEstructuras (void)                                                  */
/* -------------------------------------------------------------------------- */
void vInitEstructuras (void)
{
   stCliente.pAbonados    = (ABONTAR*)NULL   ;
   stCliente.iNumAbonados = 0;
   stCliente.pPenaliza    = (PENALIZA*)NULL  ;
   stCliente.iNumPenaliza = 0;
   stCliente.pServAbo     = (SERVABO*)NULL   ;
   stCliente.iNumServAbo  = 0;
   stCliente.pAbonos      = (ABONOS*)NULL    ;
   stCliente.iNumAbonos   = 0;
   stCliente.pCargos      = (CARGOS*)NULL    ;
   stCliente.iNumCargos   = 0;
   stCliente.pCabCuotas   = (CABCUOTAS *)NULL;
   stCliente.iNumCabCuotas= 0;
   stCliente.pAboRent     = (ABORENT *)NULL  ;
   stCliente.pAboRoaVis   = (ABOROAVIS *)NULL;
}/****************************** vInitEstructuras ****************************/

/* -------------------------------------------------------------------------- */
/*   vPreparacionSenales (void)                                               */
/* -------------------------------------------------------------------------- */
void vPreparacionSenales (void)
{
   /* Ignora la terminacion del proceso por liberacion de terminal */
   if(signal(SIGHUP,SIG_IGN)==SIG_ERR)
   {
      fprintf(stderr,"signal SIGUP SIG_IGN");
      exit(-1);
   }
   /* Procesa la senal de fin de maquina activa y pre shutdown     */
   if(signal(SIGTERM,SIG_IGN)==SIG_ERR)
   {
      fprintf(stderr,"signal SIGTERM SIG_IGN");
      exit(-1);
   }
}/************************* Final vPreparacionSenales   **********************/

/* -------------------------------------------------------------------------- */
/*   vfDatosInicialesTiempo (void)                                             */
/* -------------------------------------------------------------------------- */
void vDatosInicialesTiempo (void)
{
   cpu_ini=clock(); /* Tiempo inicial de cpu */
   time(&real_ini); /* Tiempo inicial real   */
}

/* ------------------------------------------------------------------------- */
/*   vDatosFinTiempo (void)                                                  */
/*      Valores Retorno: FALSE - Error                                       */
/*                       TRUE  - Ningun Error                                */
/* ------------------------------------------------------------------------- */
void vDatosFinTiempo (void)
{
   times(&tms)    ;
   cpu_fin=clock();
   time(&real_fin);

   real=(real_fin-real_ini)                 ;
   cpu =(float)cpu_fin/(float)CLOCKS_PER_SEC;

}/**************************** Final vDatosFinTiempo *************************/

/*****************************************************************************/
/*                            funcion : bfnCargaAbonoCli                     */
/* -Funcion que Carga en la estructura stAbonoCli los Abonados a Facturar ,  */
/*  esta funcion se utiliza en Notas y Contado sin hacer acceso a la Tabla   */
/*  Fa_CicloCli.                                                             */
/*****************************************************************************/
BOOL bfnCargaAbonoCli (ENLACEHIST stEnlaceHist, BOOL bOptProc)
{
   int  i = 0;
   long j = 0;


   for (i=0;i<stPreFactura.iNumRegistros;i++)
   {
        if((!bfnEncAbonadoCicloCli (stPreFactura.A_PFactura.lNumAbonado [i]))&&
              stPreFactura.A_PFactura.lNumAbonado [i] > 0 )
        {
            if ((stAbonoCli.pCicloCli =
                (CICLOCLI *)realloc ( (CICLOCLI *)stAbonoCli.pCicloCli,
                (int) (sizeof (CICLOCLI) * (stAbonoCli.lNumAbonados+1)) ))
                == (CICLOCLI *)NULL)
            {
                iDError (szExeName,ERR005,vInsertarIncidencia,
                         "stAbonoCli.pCicloCli");
                return FALSE;
            }

            j = stAbonoCli.lNumAbonados;
            memset (&stAbonoCli.pCicloCli [j],0,sizeof(CICLOCLI));

            stAbonoCli.pCicloCli [j].lCodCliente = stCliente.lCodCliente;
            stAbonoCli.pCicloCli [j].lNumAbonado =
                                 stPreFactura.A_PFactura.lNumAbonado [i];
            stAbonoCli.pCicloCli [j].iCodProducto=
                                 stPreFactura.A_PFactura.iCodProducto[i];
            strcpy (stAbonoCli.pCicloCli [j].szNumTerminal,
                    stPreFactura.A_PFactura.szNumTerminal[i]);

            stAbonoCli.pCicloCli [j].iIndDetalle = 0;
            if (!bfnTotCargosMe (stAbonoCli.pCicloCli [j].lCodCliente,
                                 stAbonoCli.pCicloCli [j].lNumAbonado,
                                 &stAbonoCli.pCicloCli[j].dTotCargosMe))
                 return FALSE;
            if (stAbonoCli.pCicloCli[j].iCodProducto !=
                stDatosGener.iProdGeneral)
            {
                if (!bfnGetDatosAbo(&stAbonoCli.pCicloCli[j], stEnlaceHist, bOptProc))
                     return FALSE;
            }
            stAbonoCli.lNumAbonados++;
        }
   }/* fin for i ... */
   return TRUE;
}/*************************** Final bfnCargaAbonoCli *************************/

/*****************************************************************************/
/*                          funcion : bfnEncAbonadoCicloCli                  */
/*****************************************************************************/
BOOL bfnEncAbonadoCicloCli (long lNumAbonado)
{
  static long j = 0;

  for (j=0;j<stAbonoCli.lNumAbonados;j++)
  {
       if (stAbonoCli.pCicloCli [j].lNumAbonado == lNumAbonado)
           return TRUE;
  }
  return FALSE;
}/*************************** Final bfnEncAbonadoCicloCli ********************/

/*****************************************************************************/
/*                          funcion : bfnTotCargosMe                         */
/*****************************************************************************/
BOOL bfnTotCargosMe (long    lCodCliente,
                     long    lNumAbonado,
                     double *dTotCargosMe)
{
  int i = 0;
  double dImporte = 0.0;

  for (i=0;i<stPreFactura.iNumRegistros;i++)
  {
       if (stPreFactura.A_PFactura.lCodCliente [i] == lCodCliente &&
           stPreFactura.A_PFactura.lNumAbonado [i] == lNumAbonado)
       {
           dImporte = stPreFactura.A_PFactura.dImpConcepto[i];

           if (!bConverMoneda (stPreFactura.A_PFactura.szCodMoneda [i],
                               stDatosGener.szCodMoneFact             ,
                               stPreFactura.A_PFactura.szFecValor  [i],
                               &dImporte,stProceso.iCodTipDocum))
                 return FALSE;
           *dTotCargosMe += dImporte;
       }
  }
  return TRUE;
}/************************* Final bfnTotCargosMe *****************************/

/*****************************************************************************/
/*                          funcion : bfnGetDatosAbo                         */
/*****************************************************************************/
BOOL bfnGetDatosAbo (CICLOCLI *pCicloCli, ENLACEHIST stEnlace, BOOL bOpt)
{
   static char szFuncion [25] = "";
   static char szNomTabla[30] = "";

   char *pszAux;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   long  lhNumAbonado;
   long  lhIndOrdenTotal;
   static long  lhCodUsuario       ;
   char  szhNomUsuario  [21];/* EXEC SQL VAR szhNomUsuario   IS STRING(21); */ 

   char  szhNomApellido1[21];/* EXEC SQL VAR szhNomApellido1 IS STRING(21); */ 

   char  szhNomApellido2[21];/* EXEC SQL VAR szhNomApellido2 IS STRING(21); */ 

   short i_shNomUsuario   ;
   short i_shNomApellido1   ;
   short i_shNomApellido2   ;
   static char  szhFecFinContra[15];/* EXEC SQL VAR szhFecFinContra IS STRING(15); */ 

   static short shIndFactur        ;
   static int   ihCodCredMor       ;
   static short shIndSuperTel      ;
   static char  szhNumTeleFija [16];/* EXEC SQL VAR szhNumTeleFija  IS STRING(16); */ 

   static long  lhCapCode          ;
   short i_shIndFactur   ;
   static short i_shCodCredMor     ;
   short i_shIndSuperTel = ORA_NULL   ;
   static short i_shNumTeleFija = ORA_NULL   ;
   static short i_shFecFinContra   ;
   static short i_shCapCode        ;
   /* VARCHAR sqlstmt[512]; */ 
struct { unsigned short len; unsigned char arr[512]; } sqlstmt;

   /* EXEC SQL END DECLARE SECTION; */ 


    pszAux = (char *)sqlstmt.arr;
    lhIndOrdenTotal = atol(stNota.szIndOrdenTotal);
    lhNumAbonado = pCicloCli->lNumAbonado;

    vDTrazasLog(szExeName,"\n\t\t* Entrada a funcion bfnGetDatosAbo"
                          "\n\t\t=> Num_Abonado:    [%d]", LOG03, lhNumAbonado);

    if(stDatosGener.iProdCelular == pCicloCli->iCodProducto)
    {
        strcpy (szFuncion,"Select=>Ga_AboCel");
        /* EXEC SQL SELECT COD_USUARIO, TO_CHAR(FEC_FINCONTRA,'YYYYMMDDHH24MISS'),
                         IND_FACTUR, COD_CREDMOR, IND_SUPERTEL, NUM_TELEFIJA
                   INTO  :lhCodUsuario                    ,
                         :szhFecFinContra:i_shFecFinContra,
                         :shIndFactur:i_shIndFactur       ,
                         :ihCodCredMor:i_shCodCredMor     ,
                         :shIndSuperTel:i_shIndSuperTel   ,
                         :szhNumTeleFija:i_shNumTeleFija
                   FROM  GA_ABOCEL
                  WHERE  NUM_ABONADO = :lhNumAbonado; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_USUARIO ,TO_CHAR(FEC_FINCONTRA,'YYYYMMDDHH\
24MISS') ,IND_FACTUR ,COD_CREDMOR ,IND_SUPERTEL ,NUM_TELEFIJA into :b0,:b1:b2,\
:b3:b4,:b5:b6,:b7:b8,:b9:b10  from GA_ABOCEL where NUM_ABONADO=:b11";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2203;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhCodUsuario;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhFecFinContra;
        sqlstm.sqhstl[1] = (unsigned long )15;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&i_shFecFinContra;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&shIndFactur;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&i_shIndFactur;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCodCredMor;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&i_shCodCredMor;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&shIndSuperTel;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&i_shIndSuperTel;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szhNumTeleFija;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&i_shNumTeleFija;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&lhNumAbonado;
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



        if(SQLCODE)
        {
            strcpy (szFuncion,"Select=>Ga_HaboCel");
            /* EXEC SQL SELECT COD_USUARIO, TO_CHAR(FEC_FINCONTRA,'YYYYMMDDHH24MISS'),
                            IND_FACTUR, COD_CREDMOR, IND_SUPERTEL, NUM_TELEFIJA
                    INTO    :lhCodUsuario                    ,
                            :szhFecFinContra:i_shFecFinContra,
                            :shIndFactur:i_shIndFactur       ,
                            :ihCodCredMor:i_shCodCredMor     ,
                            :shIndSuperTel:i_shIndSuperTel   ,
                            :szhNumTeleFija:i_shNumTeleFija
                    FROM    GA_HABOCEL
                    WHERE   NUM_ABONADO = :lhNumAbonado; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 45;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select COD_USUARIO ,TO_CHAR(FEC_FINCONTRA,'YYYYMM\
DDHH24MISS') ,IND_FACTUR ,COD_CREDMOR ,IND_SUPERTEL ,NUM_TELEFIJA into :b0,:b1\
:b2,:b3:b4,:b5:b6,:b7:b8,:b9:b10  from GA_HABOCEL where NUM_ABONADO=:b11";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2246;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&lhCodUsuario;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhFecFinContra;
            sqlstm.sqhstl[1] = (unsigned long )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&i_shFecFinContra;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&shIndFactur;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&i_shIndFactur;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&ihCodCredMor;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&i_shCodCredMor;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&shIndSuperTel;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&i_shIndSuperTel;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhNumTeleFija;
            sqlstm.sqhstl[5] = (unsigned long )16;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&i_shNumTeleFija;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&lhNumAbonado;
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


            if(SQLCODE)
            {
                strcpy (szFuncion,"Select=>Ga_AboAmist");
                /* EXEC SQL SELECT 0   ,
                                NULL,
                                1   ,
                                NULL,
                                NULL,
                                NULL
                    INTO        :lhCodUsuario                    ,
                                :szhFecFinContra:i_shFecFinContra,
                                :shIndFactur:i_shIndFactur       ,
                                :ihCodCredMor:i_shCodCredMor     ,
                                :shIndSuperTel:i_shIndSuperTel   ,
                                :szhNumTeleFija:i_shNumTeleFija
                    FROM   GA_ABOAMIST
                    WHERE  NUM_ABONADO = :lhNumAbonado; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 45;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "select 0 ,null  ,1 ,null  ,null  ,null  into \
:b0,:b1:b2,:b3:b4,:b5:b6,:b7:b8,:b9:b10  from GA_ABOAMIST where NUM_ABONADO=:b\
11";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )2289;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)256;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&lhCodUsuario;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)szhFecFinContra;
                sqlstm.sqhstl[1] = (unsigned long )15;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&i_shFecFinContra;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&shIndFactur;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&i_shIndFactur;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&ihCodCredMor;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&i_shCodCredMor;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&shIndSuperTel;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&i_shIndSuperTel;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)szhNumTeleFija;
                sqlstm.sqhstl[5] = (unsigned long )16;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&i_shNumTeleFija;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&lhNumAbonado;
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
        }
    }
    else if(stDatosGener.iProdBeeper == pCicloCli->iCodProducto)
    {
        strcpy (szFuncion,"Select=>Ga_AboBeep");
        /* EXEC SQL SELECT COD_USUARIO, TO_CHAR(FEC_FINCONTRA, 'YYYYMMDDHH24MISS'),
                        IND_FACTUR, COD_CREDMOR, CAP_CODE
                  INTO  :lhCodUsuario                    ,
                        :szhFecFinContra:i_shFecFinContra,
                        :shIndFactur:i_shIndFactur       ,
                        :ihCodCredMor:i_shCodCredMor     ,
                        :lhCapCode:i_shCapCode
                 FROM   GA_ABOBEEP
                 WHERE  NUM_ABONADO = :lhNumAbonado; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_USUARIO ,TO_CHAR(FEC_FINCONTRA,'YYYYMMDDHH\
24MISS') ,IND_FACTUR ,COD_CREDMOR ,CAP_CODE into :b0,:b1:b2,:b3:b4,:b5:b6,:b7:\
b8  from GA_ABOBEEP where NUM_ABONADO=:b9";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2332;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhCodUsuario;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhFecFinContra;
        sqlstm.sqhstl[1] = (unsigned long )15;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&i_shFecFinContra;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&shIndFactur;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&i_shIndFactur;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCodCredMor;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&i_shCodCredMor;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&lhCapCode;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&i_shCapCode;
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

    if(sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND)
    {
        iDError(szExeName, ERR000, vInsertarIncidencia, "bfnGetDatosAbo", szfnORAerror());
        return(FALSE);
    }

    if(sqlca.sqlcode == SQLOK)
    {
        if(i_shFecFinContra == ORA_NULL)
            strcpy(pCicloCli->szFecFinContra,"");
        else
            strcpy(pCicloCli->szFecFinContra,szhFecFinContra);

        pCicloCli->iCodCredMor  = (i_shCodCredMor == ORA_NULL)?ORA_NULL:ihCodCredMor ;
        pCicloCli->iIndSuperTel = (i_shIndSuperTel== ORA_NULL)?ORA_NULL:shIndSuperTel;

        if(i_shNumTeleFija == ORA_NULL)
            strcpy(pCicloCli->szNumTeleFija,"");
        else
            strcpy(pCicloCli->szNumTeleFija, szhNumTeleFija);

        pCicloCli->lCapCode = (i_shCapCode == ORA_NULL)?ORA_NULL:lhCapCode;

        if( (lhCodUsuario > 0) &&
            (!bfnGetDatosUsuario( lhCodUsuario,
                                  pCicloCli->szNomUsuario,
                                  pCicloCli->szNomApellido1,
                                  pCicloCli->szNomApellido2)))
        {
            return(FALSE);
        }
        return(TRUE);
    }
    else
    {
        vDTrazasLog(szExeName,"\n\t\t* Entrada a funcion bfnGetDatosAbo"
                          "\n\t\t=> bOptProceso:    [%s]"
                          "\n\t\t=> szDetAbocel:    [%s]"
                          "\n\t\t=> szDetAbobep:    [%s]"
                          "\n\t\t=> Ind_OrdenTotal: [%s]", LOG05,
                          (bOpt?"En Proceso":"En Historicas"), stEnlace.szDetAboCel,
                          stEnlace.szDetAboBep, stNota.szIndOrdenTotal);

        if(bOpt == TRUE)
        {
            strcpy(szNomTabla, "FA_FACTABON_NOCICLO");
            if(pCicloCli->iCodProducto == stDatosGener.iProdCelular)
            {
                sprintf(pszAux, "SELECT NOM_USUARIO, NOM_APELLIDO1, NOM_APELLIDO2, IND_FACTUR, COD_CREDMOR, ");
                sprintf(&pszAux[strlen(pszAux)], "TO_CHAR(FEC_FINCONTRA, 'YYYYMMDDHH24MISS'), ");
                sprintf(&pszAux[strlen(pszAux)], "IND_SUPERTEL, NUM_TELEFIJA ");
            }
            else if(pCicloCli->iCodProducto == stDatosGener.iProdBeeper)
            {
                sprintf(pszAux, "SELECT NOM_USUARIO, NOM_APELLIDO1, NOM_APELLIDO2, IND_FACTUR, COD_CREDMOR, ");
                sprintf(&pszAux[strlen(pszAux)], "TO_CHAR(FEC_FINCONTRA, 'YYYYMMDDHH24MISS') ");
            }
        }
        else
        {
            if(pCicloCli->iCodProducto == stDatosGener.iProdCelular)
            {
                strcpy(szNomTabla, stEnlace.szDetAboCel);
                sprintf(pszAux, "SELECT NOM_USUARIO, NOM_APELLIDO1, NOM_APELLIDO2, IND_FACTUR, COD_CREDMOR, ");
                    sprintf(&pszAux[strlen(pszAux)], "TO_CHAR(FEC_FINCONTRA, 'YYYYMMDDHH24MISS'), ");
                    sprintf(&pszAux[strlen(pszAux)], "IND_SUPERTEL, NUM_TELEFIJA ");
            }
            else if(pCicloCli->iCodProducto == stDatosGener.iProdBeeper)
            {
                strcpy(szNomTabla, stEnlace.szDetAboBep);
                sprintf(pszAux, "SELECT NOM_USUARIO, NOM_APELLIDO1, NOM_APELLIDO2, IND_FACTUR, COD_CREDMOR, ");
                    sprintf(&pszAux[strlen(pszAux)], "TO_CHAR(FEC_FINCONTRA, 'YYYYMMDDHH24MISS') ");
            }
        }

        vDTrazasLog (szExeName,"\n\t\t*  Parametros de entrada a %s"
                               "\n\t\t=> Num.Abonado    [%ld]"
                               "\n\t\t=> Ind_OrdenTotal [%s]", LOG04, szNomTabla,
                               pCicloCli->lNumAbonado, stNota.szIndOrdenTotal);

        sprintf(&pszAux[strlen(pszAux)], "FROM %s ", szNomTabla);
        sprintf(&pszAux[strlen(pszAux)], "WHERE IND_ORDENTOTAL = :v1 AND NUM_ABONADO = :v2");

        sqlstmt.len = (short)strlen((char *)sqlstmt.arr);

        /* EXEC SQL PREPARE q_factabo FROM :sqlstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2371;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&sqlstmt;
        sqlstm.sqhstl[0] = (unsigned long )514;
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


        if(sqlca.sqlcode != 0)
        {
            vDTrazasError(szExeName,"\n\t\t**  Error en SQL-PREPARE **"
                                    "\n\t\t=> Error : [%d]  [%s] ", LOG01, SQLCODE, SQLERRM);
            return(FALSE);
        }
        /* EXEC SQL DECLARE CurAbon CURSOR FOR q_factabo; */ 

        if(sqlca.sqlcode != 0)
        {
            vDTrazasError(szExeName,"\n\t\t**  Error en SQL-DECLARE **"
                                    "\n\t\t=> Error : [%d]  [%s] ", LOG01, SQLCODE, SQLERRM);
            return(FALSE);
        }
        /* EXEC SQL OPEN CurAbon USING :lhIndOrdenTotal, :lhNumAbonado; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2390;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&lhIndOrdenTotal;
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


        if(sqlca.sqlcode != 0)
        {
            vDTrazasError(szExeName,"\n\t\t**  Error en SQL-OPEN **"
                                    "\n\t\t=> Error : [%d]  [%s] ", LOG01, SQLCODE, SQLERRM);
            return(FALSE);
        }

        if(pCicloCli->iCodProducto == stDatosGener.iProdCelular)
        {
            /* EXEC SQL FETCH CurAbon
                INTO :szhNomUsuario:i_shNomUsuario,
                     :szhNomApellido1:i_shNomApellido1,
                     :szhNomApellido2:i_shNomApellido2,
                     :shIndFactur:i_shIndFactur,
                     :ihCodCredMor:i_shCodCredMor,
                     :szhFecFinContra:i_shFecFinContra,
                     :shIndSuperTel:i_shIndSuperTel,
                     :szhNumTeleFija:i_shNumTeleFija; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 45;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2413;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhNomUsuario;
            sqlstm.sqhstl[0] = (unsigned long )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)&i_shNomUsuario;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhNomApellido1;
            sqlstm.sqhstl[1] = (unsigned long )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&i_shNomApellido1;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)szhNomApellido2;
            sqlstm.sqhstl[2] = (unsigned long )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&i_shNomApellido2;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&shIndFactur;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&i_shIndFactur;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihCodCredMor;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&i_shCodCredMor;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhFecFinContra;
            sqlstm.sqhstl[5] = (unsigned long )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&i_shFecFinContra;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&shIndSuperTel;
            sqlstm.sqhstl[6] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&i_shIndSuperTel;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhNumTeleFija;
            sqlstm.sqhstl[7] = (unsigned long )16;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)&i_shNumTeleFija;
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
        else if(pCicloCli->iCodProducto == stDatosGener.iProdBeeper)
        {
            /* EXEC SQL FETCH CurAbon
                INTO :szhNomUsuario:i_shNomUsuario,
                     :szhNomApellido1:i_shNomApellido1,
                     :szhNomApellido2:i_shNomApellido2,
                     :shIndFactur:i_shIndFactur,
                     :ihCodCredMor:i_shCodCredMor,
                     :szhFecFinContra:i_shFecFinContra; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 45;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2460;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (         int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (unsigned char  *)szhNomUsuario;
            sqlstm.sqhstl[0] = (unsigned long )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)&i_shNomUsuario;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhNomApellido1;
            sqlstm.sqhstl[1] = (unsigned long )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&i_shNomApellido1;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)szhNomApellido2;
            sqlstm.sqhstl[2] = (unsigned long )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&i_shNomApellido2;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&shIndFactur;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&i_shIndFactur;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihCodCredMor;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&i_shCodCredMor;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhFecFinContra;
            sqlstm.sqhstl[5] = (unsigned long )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&i_shFecFinContra;
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

        if(sqlca.sqlcode != SQLOK)
        {
            iDError(szExeName, ERR000, vInsertarIncidencia, "bfnGetDatosAbo", szfnORAerror());
            return(FALSE);
        }

        if(sqlca.sqlcode == SQLOK)
        {
            if(i_shFecFinContra == ORA_NULL)
                pCicloCli->szFecFinContra[0] = 0;
            else
                strcpy(pCicloCli->szFecFinContra, szhFecFinContra);

            pCicloCli->iCodCredMor  = (i_shCodCredMor == ORA_NULL)?ORA_NULL:ihCodCredMor ;
            pCicloCli->iIndSuperTel = (i_shIndSuperTel== ORA_NULL)?ORA_NULL:shIndSuperTel;
            pCicloCli->lCapCode = ORA_NULL;

            if(i_shNomUsuario == ORA_NULL)
                pCicloCli->szNomUsuario[0] = 0;
            else
                strcpy(pCicloCli->szNomUsuario, szhNomUsuario);

            if(i_shNumTeleFija == ORA_NULL)
                pCicloCli->szNumTeleFija[0] = 0;
            else
                strcpy (pCicloCli->szNumTeleFija,szhNumTeleFija);

            if(i_shNomApellido1 == ORA_NULL)
                pCicloCli->szNomApellido1[0] = 0;
            else
                strcpy(pCicloCli->szNomApellido1, szhNomApellido1);

            if(i_shNomApellido2 == ORA_NULL)
                pCicloCli->szNomApellido2[0] = 0;
            else
                strcpy(pCicloCli->szNomApellido2, szhNomApellido2);

            /* EXEC SQL CLOSE CurAbon; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 45;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2499;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



            return(TRUE);
        }
    }
   return(TRUE);
}/************************** Final bfnGetDatosAbo ****************************/

/*****************************************************************************/
/*                          funcion : bfnGetDatosUsuario                     */
/*****************************************************************************/
BOOL bfnGetDatosUsuario (long  lCodUsuario   ,
                         char *szNomUsuario  ,
                         char *szNomApellido1,
                         char *szNomApellido2)
{
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char  szhNomUsuario  [21];/* EXEC SQL VAR szhNomUsuario   IS STRING(21); */ 

   static char  szhNomApellido1[21];/* EXEC SQL VAR szhNomApellido1 IS STRING(21); */ 

   static char  szhNomApellido2[21];/* EXEC SQL VAR szhNomApellido2 IS STRING(21); */ 

   static short i_shNomApellido2   ;
   /* EXEC SQL END DECLARE SECTION; */ 


   vDTrazasLog (szExeName,"\n\t\t* Parametros de Entrada Ga_Usuarios"
                          "\n\t\t=> Cod.Usuario  [%ld]",LOG04,lCodUsuario);

    if (stProceso.iCodTipDocum != stDatosGener.iCodNotaCre)
    {
       /* EXEC SQL SELECT /o+ index (GA_USUARIOS PK_GA_USUARIOS) o/
                   NOM_USUARIO  ,
                   NOM_APELLIDO1,
                   NOM_APELLIDO2
            INTO   :szhNomUsuario                   ,
                   :szhNomApellido1                 ,
                   :szhNomApellido2:i_shNomApellido2
            FROM   GA_USUARIOS
            WHERE  COD_USUARIO = :lCodUsuario; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 45;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "select  /*+  index (GA_USUARIOS PK_GA_USUARIOS)  +*/ N\
OM_USUARIO ,NOM_APELLIDO1 ,NOM_APELLIDO2 into :b0,:b1,:b2:b3  from GA_USUARIOS\
 where COD_USUARIO=:b4";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )2514;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)256;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqhstv[0] = (unsigned char  *)szhNomUsuario;
       sqlstm.sqhstl[0] = (unsigned long )21;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)szhNomApellido1;
       sqlstm.sqhstl[1] = (unsigned long )21;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)szhNomApellido2;
       sqlstm.sqhstl[2] = (unsigned long )21;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)&i_shNomApellido2;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&lCodUsuario;
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


       if (SQLCODE)
       {
           iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Ga_Usuarios",
                    szfnORAerror());
           return FALSE;
       }
    }
    else
    {
        SQLCODE = SQLOK ;
    }

    if (SQLCODE == SQLOK)
    {
       strcpy (szNomUsuario  ,szhNomUsuario  );
       strcpy (szNomApellido1,szhNomApellido1);

       if (i_shNomApellido2 == ORA_NULL)
           strcpy (szNomApellido2,"");
       else
           strcpy (szNomApellido1,szhNomApellido2);
   }
   return TRUE;
}/************************* Final bfnGetDatosUsuario *************************/

/*****************************************************************************/
/*                          funcion : vfnFreeCicloCli                        */
/*****************************************************************************/
void vfnFreeCicloCli (void)
{
  if (stAbonoCli.pCicloCli != (CICLOCLI *)NULL)
  {
      free (stAbonoCli.pCicloCli)            ;
      stAbonoCli.pCicloCli = (CICLOCLI *)NULL;
  }
  stAbonoCli.lNumAbonados = 0;
}/************************** Final vfnFreeCicloCli ***************************/

/*****************************************************************************/
/*                         funcion : bfnDBUpdateIndImpresa                   */
/* -Funcion que Updatea el Ind_Impresa = 0 en el caso que la Impresion haya  */
/*  sido Erronea, por defecto el valor del campo es 1.                       */
/* -Valores Retorno : Error->FALSE, !Error->TRUE.                            */
/*****************************************************************************/
BOOL bfnDBUpdateIndImpresa (HISTDOCU stHis,
                            int      iTipoFact)
{
    char szFuncion [40]    ="";
    char    szCadena [1024]="";

    vDTrazasLog (szExeName, "\n\t\t* Entrada a Update Ind_Impresa a 0"
                            "\n\t\t=>Num.Secuenci        [%ld]"
                            "\n\t\t=>Cod.TipDocum        [%d] "
                            "\n\t\t=>Cod.Vendedor Agente [%ld]"
                            "\n\t\t=>Letra               [%s] "
                            "\n\t\t=>Cod.CentrEmi        [%d] ",LOG05,
                            stHis.lNumSecuenci      , stHis.iCodTipDocum,
                            stHis.lCodVendedorAgente, stHis.szLetra     ,
                            stHis.iCodCentrEmi);

    if (iTipoFact == FACT_CICLO)
    {
        strcpy (szFuncion,"Update=>Fa_FactDocu_Ciclo");
        sprintf(szCadena, "UPDATE FA_FACTDOCU_%ld"
                          "SET    IND_IMPRESA = 0 "
                          "WHERE  NUM_SECUENCI        = :stHis.lNumSecuenci "
                          "AND    COD_TIPDOCUM        = :stHis.iCodTipDocum  "
                          "AND    COD_VENDEDOR_AGENTE = :stHis.lCodVendedorAgente "
                          "AND    LETRA               = :stHis.szLetra "
                          "AND    COD_CENTREMI        = :stHis.iCodCentrEmi ",stCiclo.lCodCiclFact);

        /* EXEC SQL PREPARE sql_update_facturas FROM :szCadena; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2545;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szCadena;
        sqlstm.sqhstl[0] = (unsigned long )1024;
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
            vDTrazasError(szExeName,"\n\t**  Error en SQL-PREPARE sql_update_facturas **"
                                    "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);

        }
        /* EXEC SQL EXECUTE sql_update_facturas USING  :stHis.lNumSecuenci         ,
                                                    :stHis.iCodTipDocum         ,
                                                    :stHis.lCodVendedorAgente   ,
                                                    :stHis.szLetra              ,
                                                    :stHis.iCodCentrEmi; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2564;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&(stHis.lNumSecuenci);
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&(stHis.iCodTipDocum);
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&(stHis.lCodVendedorAgente);
        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)(stHis.szLetra);
        sqlstm.sqhstl[3] = (unsigned long )2;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&(stHis.iCodCentrEmi);
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
    else
    {
        strcpy (szFuncion, "Update=>Fa_HistDocu_NoCiclo");
            /* EXEC SQL
                UPDATE  FA_FACTDOCU_NOCICLO
                SET     IND_IMPRESA = 0
                WHERE   NUM_SECUENCI        = :stHis.lNumSecuenci
                AND     COD_TIPDOCUM        = :stHis.iCodTipDocum
                AND     COD_VENDEDOR_AGENTE = :stHis.lCodVendedorAgente
                AND     LETRA               = :stHis.szLetra
                AND     COD_CENTREMI        = :stHis.iCodCentrEmi; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 45;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "update FA_FACTDOCU_NOCICLO  set IND_IMPRESA=0 whe\
re ((((NUM_SECUENCI=:b0 and COD_TIPDOCUM=:b1) and COD_VENDEDOR_AGENTE=:b2) and\
 LETRA=:b3) and COD_CENTREMI=:b4)";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2599;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&(stHis.lNumSecuenci);
            sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&(stHis.iCodTipDocum);
            sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&(stHis.lCodVendedorAgente);
            sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)(stHis.szLetra);
            sqlstm.sqhstl[3] = (unsigned long )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&(stHis.iCodCentrEmi);
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
    if (SQLCODE)
    {
        iDError (szExeName,ERR000,vInsertarIncidencia, szFuncion,szfnORAerror());
    }
    return (SQLCODE != SQLOK)?FALSE:TRUE;
}/************************** Final bfnDBUpdateIndImpresa *********************/

/*****************************************************************************/
/*                          funcion : bfnDBGetCiclFact                       */
/*****************************************************************************/
BOOL bfnDBGetCiclFact (CICLO *pCiclo)
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

static char* szhRowid          ;/* EXEC SQL VAR szhRowid           IS STRING(15) ; */ 

static int   ihCodCiclo        ;
static int   ihAno             ;
static long  lhCodCiclFact     ;
static char* szhFecEmision     ;/* EXEC SQL VAR szhFecEmision      IS STRING(15) ; */ 

static char* szhFecVencimie    ;/* EXEC SQL VAR szhFecVencimie     IS STRING(15) ; */ 

static char* szhFecProxVenc    ;/* EXEC SQL VAR szhFecProxVenc     IS STRING(15) ; */ 

static char* szhFecCaducida    ;/* EXEC SQL VAR szhFecCaducida     IS STRING(15) ; */ 

static char* szhFecDesdeLlan   ;/* EXEC SQL VAR szhFecDesdeLlan    IS STRING(15) ; */ 

static char* szhFecHastaLlam   ;/* EXEC SQL VAR szhFecHastaLlam    IS STRING(15) ; */ 

static char* szhFecDesdeCFijos ;/* EXEC SQL VAR szhFecDesdeCFijos  IS STRING(15) ; */ 

static char* szhFecHastaCFijos ;/* EXEC SQL VAR szhFecHastaCFijos  IS STRING(15) ; */ 

static char* szhFecDesdeOCargos;/* EXEC SQL VAR szhFecDesdeOCargos IS STRING(15) ; */ 

static char* szhFecHastaOCargos;/* EXEC SQL VAR szhFecHastaOCargos IS STRING(15) ; */ 

static char* szhFecDesdeRoa    ;/* EXEC SQL VAR szhFecDesdeRoa     IS STRING(15) ; */ 

static char* szhFecHastaRoa    ;/* EXEC SQL VAR szhFecHastaRoa     IS STRING(15) ; */ 

static char* szhFecHMenos      ;/* EXEC SQL VAR szhFecHMenos       IS STRING(15) ; */ 

static char* szhDirLogs        ;/* EXEC SQL VAR szhDirLogs         IS STRING(101); */ 

static char* szhDirSpool       ;/* EXEC SQL VAR szhDirSpool        IS STRING(101); */ 

static char* szhDesLeyen1      ;/* EXEC SQL VAR szhDesLeyen1       IS STRING(81) ; */ 

static char* szhDesLeyen2      ;/* EXEC SQL VAR szhDesLeyen2       IS STRING(81) ; */ 

static char* szhDesLeyen3      ;/* EXEC SQL VAR szhDesLeyen3       IS STRING(81) ; */ 

static char* szhDesLeyen4      ;/* EXEC SQL VAR szhDesLeyen4       IS STRING(81) ; */ 

static char* szhDesLeyen5      ;/* EXEC SQL VAR szhDesLeyen5       IS STRING(81) ; */ 

static short shIndFacturacion  ;
static int   ihDiaPeriodo      ;
static short i_shDesLeyen1     ;
static short i_shDesLeyen2     ;
static short i_shDesLeyen3     ;
static short i_shDesLeyen4     ;
static short i_shDesLeyen5     ;
/* EXEC SQL END DECLARE SECTION; */ 


  if (pCiclo->lCodCiclFact == -1)
  {
      memset (pCiclo,ORA_NULL,sizeof(CICLO));
  }
  else
  {
     vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada a Fa_CiclFact\n"
                            "\t\t=> Cod.CiclFact [%ld]\n",LOG06,
                            pCiclo->lCodCiclFact);
     szhRowid          = pCiclo->szRowid          ;
     szhFecEmision     = pCiclo->szFecEmision     ;
     szhFecVencimie    = pCiclo->szFecVencimie    ;
     szhFecCaducida    = pCiclo->szFecCaducida    ;
     szhFecProxVenc    = pCiclo->szFecProxVenc    ;
     szhFecDesdeLlan   = pCiclo->szFecDesdeLlam   ;
     szhFecHastaLlam   = pCiclo->szFecHastaLlam   ;
     szhFecDesdeCFijos = pCiclo->szFecDesdeCFijos ;
     szhFecHastaCFijos = pCiclo->szFecHastaCFijos ;
     szhFecDesdeOCargos= pCiclo->szFecDesdeOCargos;
     szhFecHastaOCargos= pCiclo->szFecHastaOCargos;
     szhFecDesdeRoa    = pCiclo->szFecDesdeRoa    ;
     szhFecHastaRoa    = pCiclo->szFecHastaRoa    ;
     szhFecHMenos      = pCiclo->szFecHMenos      ;
     szhDirLogs        = pCiclo->szDirLogs        ;
     szhDirSpool       = pCiclo->szDirSpool       ;
     szhDesLeyen1      = pCiclo->szDesLeyen1      ;
     szhDesLeyen2      = pCiclo->szDesLeyen2      ;
     szhDesLeyen3      = pCiclo->szDesLeyen3      ;
     szhDesLeyen4      = pCiclo->szDesLeyen4      ;
     szhDesLeyen5      = pCiclo->szDesLeyen5      ;

     shIndFacturacion  = pCiclo->iIndFacturacion  ;
     lhCodCiclFact     = pCiclo->lCodCiclFact     ;

     /* EXEC SQL SELECT
            ROWID                                                ,
            COD_CICLO                                            ,
            ANO                                                  ,
            TO_CHAR(FEC_VENCIMIE,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_EMISION ,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_CADUCIDA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_PROXVENC,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_DESDELLAM,'YYYYMMDDHH24MISS')            ,
            TO_CHAR(FEC_HASTALLAM,'YYYYMMDDHH24MISS')            ,
            TO_CHAR(FEC_DESDECFIJOS,'YYYYMMDDHH24MISS')          ,
            TO_CHAR(FEC_HASTACFIJOS,'YYYYMMDDHH24MISS')          ,
            TO_CHAR(FEC_DESDEOCARGOS,'YYYYMMDDHH24MISS')         ,
            TO_CHAR(FEC_HASTAOCARGOS,'YYYYMMDDHH24MISS')         ,
            TO_CHAR(FEC_DESDEROA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR(FEC_HASTAROA,'YYYYMMDDHH24MISS')             ,
            TO_CHAR((FEC_DESDECFIJOS-1/86400),'YYYYMMDDHH24MISS'),
            IND_FACTURACION                                      ,
            DIR_LOGS                                             ,
            DIR_SPOOL                                            ,
            DIA_PERIODO                                          ,
            DES_LEYEN1                                           ,
            DES_LEYEN2                                           ,
            DES_LEYEN3                                           ,
            DES_LEYEN4                                           ,
            DES_LEYEN5
       INTO :szhRowid                  ,
            :ihCodCiclo                ,
            :ihAno                     ,
            :szhFecVencimie            ,
            :szhFecEmision             ,
            :szhFecCaducida            ,
            :szhFecProxVenc            ,
            :szhFecDesdeLlan           ,
            :szhFecHastaLlam           ,
            :szhFecDesdeCFijos         ,
            :szhFecHastaCFijos         ,
            :szhFecDesdeOCargos        ,
            :szhFecHastaOCargos        ,
            :szhFecDesdeRoa            ,
            :szhFecHastaRoa            ,
            :szhFecHMenos              ,
            :shIndFacturacion          ,
            :szhDirLogs                ,
            :szhDirSpool               ,
            :ihDiaPeriodo              ,
            :szhDesLeyen1:i_shDesLeyen1,
            :szhDesLeyen2:i_shDesLeyen2,
            :szhDesLeyen3:i_shDesLeyen3,
            :szhDesLeyen4:i_shDesLeyen4,
            :szhDesLeyen5:i_shDesLeyen5
      FROM  FA_CICLFACT
      WHERE COD_CICLFACT    = :lhCodCiclFact
        AND IND_FACTURACION = :shIndFacturacion; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 45;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "select ROWID ,COD_CICLO ,ANO ,TO_CHAR(FEC_VENCIMIE,'YYYY\
MMDDHH24MISS') ,TO_CHAR(FEC_EMISION,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_CADUCIDA,\
'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_PROXVENC,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_DES\
DELLAM,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTALLAM,'YYYYMMDDHH24MISS') ,TO_CHAR\
(FEC_DESDECFIJOS,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTACFIJOS,'YYYYMMDDHH24MIS\
S') ,TO_CHAR(FEC_DESDEOCARGOS,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTAOCARGOS,'Y\
YYYMMDDHH24MISS') ,TO_CHAR(FEC_DESDEROA,'YYYYMMDDHH24MISS') ,TO_CHAR(FEC_HASTA\
ROA,'YYYYMMDDHH24MISS') ,TO_CHAR((FEC_DESDECFIJOS-(1/86400)),'YYYYMMDDHH24MISS\
') ,IND_FACTURACION ,DIR_LOGS ,DIR_SPOOL ,DIA_PERIODO ,DES_LEYEN1 ,DES_LEYEN2 \
,DES_LEYEN3 ,DES_LEYEN4 ,DES_LEYEN5 into :b0,:b1,:b2,:b3,:b4,:b5,:b6,:b7,:b8,:\
b9,:b10,:b11,:b12,:b13,:b14,:b15,:b16,:b17,:b18,:b19,:b20:b21,:b22:b23,:b24:b2\
5,:b26:b27,:b28:b29  from FA_CICLFACT where (COD_CICLFACT=:b30 and IND_FACTURA\
CION=:b16)";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )2634;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)256;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqhstv[0] = (unsigned char  *)szhRowid;
     sqlstm.sqhstl[0] = (unsigned long )15;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&ihCodCiclo;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&ihAno;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)szhFecVencimie;
     sqlstm.sqhstl[3] = (unsigned long )15;
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
     sqlstm.sqhstv[5] = (unsigned char  *)szhFecCaducida;
     sqlstm.sqhstl[5] = (unsigned long )15;
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)0;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)szhFecProxVenc;
     sqlstm.sqhstl[6] = (unsigned long )15;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)0;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)szhFecDesdeLlan;
     sqlstm.sqhstl[7] = (unsigned long )15;
     sqlstm.sqhsts[7] = (         int  )0;
     sqlstm.sqindv[7] = (         short *)0;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)szhFecHastaLlam;
     sqlstm.sqhstl[8] = (unsigned long )15;
     sqlstm.sqhsts[8] = (         int  )0;
     sqlstm.sqindv[8] = (         short *)0;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
     sqlstm.sqadto[8] = (unsigned short )0;
     sqlstm.sqtdso[8] = (unsigned short )0;
     sqlstm.sqhstv[9] = (unsigned char  *)szhFecDesdeCFijos;
     sqlstm.sqhstl[9] = (unsigned long )15;
     sqlstm.sqhsts[9] = (         int  )0;
     sqlstm.sqindv[9] = (         short *)0;
     sqlstm.sqinds[9] = (         int  )0;
     sqlstm.sqharm[9] = (unsigned long )0;
     sqlstm.sqadto[9] = (unsigned short )0;
     sqlstm.sqtdso[9] = (unsigned short )0;
     sqlstm.sqhstv[10] = (unsigned char  *)szhFecHastaCFijos;
     sqlstm.sqhstl[10] = (unsigned long )15;
     sqlstm.sqhsts[10] = (         int  )0;
     sqlstm.sqindv[10] = (         short *)0;
     sqlstm.sqinds[10] = (         int  )0;
     sqlstm.sqharm[10] = (unsigned long )0;
     sqlstm.sqadto[10] = (unsigned short )0;
     sqlstm.sqtdso[10] = (unsigned short )0;
     sqlstm.sqhstv[11] = (unsigned char  *)szhFecDesdeOCargos;
     sqlstm.sqhstl[11] = (unsigned long )15;
     sqlstm.sqhsts[11] = (         int  )0;
     sqlstm.sqindv[11] = (         short *)0;
     sqlstm.sqinds[11] = (         int  )0;
     sqlstm.sqharm[11] = (unsigned long )0;
     sqlstm.sqadto[11] = (unsigned short )0;
     sqlstm.sqtdso[11] = (unsigned short )0;
     sqlstm.sqhstv[12] = (unsigned char  *)szhFecHastaOCargos;
     sqlstm.sqhstl[12] = (unsigned long )15;
     sqlstm.sqhsts[12] = (         int  )0;
     sqlstm.sqindv[12] = (         short *)0;
     sqlstm.sqinds[12] = (         int  )0;
     sqlstm.sqharm[12] = (unsigned long )0;
     sqlstm.sqadto[12] = (unsigned short )0;
     sqlstm.sqtdso[12] = (unsigned short )0;
     sqlstm.sqhstv[13] = (unsigned char  *)szhFecDesdeRoa;
     sqlstm.sqhstl[13] = (unsigned long )15;
     sqlstm.sqhsts[13] = (         int  )0;
     sqlstm.sqindv[13] = (         short *)0;
     sqlstm.sqinds[13] = (         int  )0;
     sqlstm.sqharm[13] = (unsigned long )0;
     sqlstm.sqadto[13] = (unsigned short )0;
     sqlstm.sqtdso[13] = (unsigned short )0;
     sqlstm.sqhstv[14] = (unsigned char  *)szhFecHastaRoa;
     sqlstm.sqhstl[14] = (unsigned long )15;
     sqlstm.sqhsts[14] = (         int  )0;
     sqlstm.sqindv[14] = (         short *)0;
     sqlstm.sqinds[14] = (         int  )0;
     sqlstm.sqharm[14] = (unsigned long )0;
     sqlstm.sqadto[14] = (unsigned short )0;
     sqlstm.sqtdso[14] = (unsigned short )0;
     sqlstm.sqhstv[15] = (unsigned char  *)szhFecHMenos;
     sqlstm.sqhstl[15] = (unsigned long )15;
     sqlstm.sqhsts[15] = (         int  )0;
     sqlstm.sqindv[15] = (         short *)0;
     sqlstm.sqinds[15] = (         int  )0;
     sqlstm.sqharm[15] = (unsigned long )0;
     sqlstm.sqadto[15] = (unsigned short )0;
     sqlstm.sqtdso[15] = (unsigned short )0;
     sqlstm.sqhstv[16] = (unsigned char  *)&shIndFacturacion;
     sqlstm.sqhstl[16] = (unsigned long )sizeof(short);
     sqlstm.sqhsts[16] = (         int  )0;
     sqlstm.sqindv[16] = (         short *)0;
     sqlstm.sqinds[16] = (         int  )0;
     sqlstm.sqharm[16] = (unsigned long )0;
     sqlstm.sqadto[16] = (unsigned short )0;
     sqlstm.sqtdso[16] = (unsigned short )0;
     sqlstm.sqhstv[17] = (unsigned char  *)szhDirLogs;
     sqlstm.sqhstl[17] = (unsigned long )101;
     sqlstm.sqhsts[17] = (         int  )0;
     sqlstm.sqindv[17] = (         short *)0;
     sqlstm.sqinds[17] = (         int  )0;
     sqlstm.sqharm[17] = (unsigned long )0;
     sqlstm.sqadto[17] = (unsigned short )0;
     sqlstm.sqtdso[17] = (unsigned short )0;
     sqlstm.sqhstv[18] = (unsigned char  *)szhDirSpool;
     sqlstm.sqhstl[18] = (unsigned long )101;
     sqlstm.sqhsts[18] = (         int  )0;
     sqlstm.sqindv[18] = (         short *)0;
     sqlstm.sqinds[18] = (         int  )0;
     sqlstm.sqharm[18] = (unsigned long )0;
     sqlstm.sqadto[18] = (unsigned short )0;
     sqlstm.sqtdso[18] = (unsigned short )0;
     sqlstm.sqhstv[19] = (unsigned char  *)&ihDiaPeriodo;
     sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[19] = (         int  )0;
     sqlstm.sqindv[19] = (         short *)0;
     sqlstm.sqinds[19] = (         int  )0;
     sqlstm.sqharm[19] = (unsigned long )0;
     sqlstm.sqadto[19] = (unsigned short )0;
     sqlstm.sqtdso[19] = (unsigned short )0;
     sqlstm.sqhstv[20] = (unsigned char  *)szhDesLeyen1;
     sqlstm.sqhstl[20] = (unsigned long )81;
     sqlstm.sqhsts[20] = (         int  )0;
     sqlstm.sqindv[20] = (         short *)&i_shDesLeyen1;
     sqlstm.sqinds[20] = (         int  )0;
     sqlstm.sqharm[20] = (unsigned long )0;
     sqlstm.sqadto[20] = (unsigned short )0;
     sqlstm.sqtdso[20] = (unsigned short )0;
     sqlstm.sqhstv[21] = (unsigned char  *)szhDesLeyen2;
     sqlstm.sqhstl[21] = (unsigned long )81;
     sqlstm.sqhsts[21] = (         int  )0;
     sqlstm.sqindv[21] = (         short *)&i_shDesLeyen2;
     sqlstm.sqinds[21] = (         int  )0;
     sqlstm.sqharm[21] = (unsigned long )0;
     sqlstm.sqadto[21] = (unsigned short )0;
     sqlstm.sqtdso[21] = (unsigned short )0;
     sqlstm.sqhstv[22] = (unsigned char  *)szhDesLeyen3;
     sqlstm.sqhstl[22] = (unsigned long )81;
     sqlstm.sqhsts[22] = (         int  )0;
     sqlstm.sqindv[22] = (         short *)&i_shDesLeyen3;
     sqlstm.sqinds[22] = (         int  )0;
     sqlstm.sqharm[22] = (unsigned long )0;
     sqlstm.sqadto[22] = (unsigned short )0;
     sqlstm.sqtdso[22] = (unsigned short )0;
     sqlstm.sqhstv[23] = (unsigned char  *)szhDesLeyen4;
     sqlstm.sqhstl[23] = (unsigned long )81;
     sqlstm.sqhsts[23] = (         int  )0;
     sqlstm.sqindv[23] = (         short *)&i_shDesLeyen4;
     sqlstm.sqinds[23] = (         int  )0;
     sqlstm.sqharm[23] = (unsigned long )0;
     sqlstm.sqadto[23] = (unsigned short )0;
     sqlstm.sqtdso[23] = (unsigned short )0;
     sqlstm.sqhstv[24] = (unsigned char  *)szhDesLeyen5;
     sqlstm.sqhstl[24] = (unsigned long )81;
     sqlstm.sqhsts[24] = (         int  )0;
     sqlstm.sqindv[24] = (         short *)&i_shDesLeyen5;
     sqlstm.sqinds[24] = (         int  )0;
     sqlstm.sqharm[24] = (unsigned long )0;
     sqlstm.sqadto[24] = (unsigned short )0;
     sqlstm.sqtdso[24] = (unsigned short )0;
     sqlstm.sqhstv[25] = (unsigned char  *)&lhCodCiclFact;
     sqlstm.sqhstl[25] = (unsigned long )sizeof(long);
     sqlstm.sqhsts[25] = (         int  )0;
     sqlstm.sqindv[25] = (         short *)0;
     sqlstm.sqinds[25] = (         int  )0;
     sqlstm.sqharm[25] = (unsigned long )0;
     sqlstm.sqadto[25] = (unsigned short )0;
     sqlstm.sqtdso[25] = (unsigned short )0;
     sqlstm.sqhstv[26] = (unsigned char  *)&shIndFacturacion;
     sqlstm.sqhstl[26] = (unsigned long )sizeof(short);
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


   }
   if (SQLCODE != SQLOK)
   {
       iDError (szExeName,ERR000,vInsertarIncidencia,"Select->Fa_CiclFact",
                szfnORAerror());
       return FALSE;
   }
   if (SQLCODE == 0)
   {
       pCiclo->iAno            = ihAno           ;
       pCiclo->iCodCiclo       = ihCodCiclo      ;
       pCiclo->lCodCiclFact    = lhCodCiclFact   ;
       pCiclo->iIndFacturacion = shIndFacturacion;
       pCiclo->iDiaPeriodo     = ihDiaPeriodo    ;

       if (i_shDesLeyen1 == ORA_NULL)
           pCiclo->szDesLeyen1 [0] = 0;
       if (i_shDesLeyen2 == ORA_NULL)
           pCiclo->szDesLeyen2 [0] = 0;
       if (i_shDesLeyen3 == ORA_NULL)
           pCiclo->szDesLeyen3 [0] = 0;
       if (i_shDesLeyen4 == ORA_NULL)
           pCiclo->szDesLeyen4 [0] = 0;
       if (i_shDesLeyen5 == ORA_NULL)
           pCiclo->szDesLeyen5 [0] = 0;

       if (!bfnDBGetCiclo (pCiclo))
            return FALSE;
   }
   return TRUE;
}/*************************** Final bfnDBGetCiclFact ************************/


/*****************************************************************************/
/*                        funcion : bfnConsumeFolio                          */
/*****************************************************************************/
BOOL bfnConsumeFolio (char *szCodOficina,
                      int   iCodTipDocum,
                      char *szCodOperadora ,
                      long lNumProceso,
                      char *szFechaFol,
                      long *plNumFolio,
                      char *szPrefPlaza)
{
  char  modulo[] = "bfnConsumeFolio";
  char  cSeparador          =';';
  int   iNumParametros  = 0 ;
  char  *szArregloParametros[5];

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static int    ihCodTipDocum    ;
  static char   szhResultado [256] ; /* EXEC SQL VAR szhResultado IS STRING (256); */ 

  static char   szhCodOficina   [3]  ; /* EXEC SQL VAR szhCodOficina IS STRING (3); */ 

  static char   szhCodOperadora [6]; /* EXEC SQL VAR szhCodOperadora IS STRING (6); */ 

  static char   szhFecha       [15]; /* EXEC SQL VAR szhFecha IS STRING (15); */ 

  static long   lhNumProceso   ;
  /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (szExeName,"\n\t\t* Entrada en %s"
                           "\n\t\t=>Cod.Oficina     [%s]"
                           "\n\t\t=>Cod.Tip.Docum   [%d]"
                           "\n\t\t=>Cod.Operadora   [%s]"
                           "\n\t\t=>Num.Proceso     [%ld]"
                           "\n\t\t=>Fec.Foliacion   [%s]"
                           , LOG05, modulo, szCodOficina, iCodTipDocum
                           , szCodOperadora, lNumProceso, szFechaFol );

    strcpy (szhCodOficina,szCodOficina);
    strcpy (szhCodOperadora,szCodOperadora);
    ihCodTipDocum = iCodTipDocum;
    lhNumProceso = lNumProceso;
    strcpy(szhFecha, szFechaFol);

    /* EXEC SQL
        SELECT FA_FOLIACION_PG.FA_CONSUME_FOLIO_CICLO_FN( :ihCodTipDocum
                                                    ,NULL
                                                    ,:szhCodOficina
                                                    ,:szhCodOperadora
                                                    ,NULL
                                                    ,NULL
                                                    ,:lhNumProceso
                                                    ,TO_DATE(:szhFecha,'YYYYMMDDHH24MISS')
                                                    ,1)
        INTO :szhResultado
        FROM DUAL; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 45;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select FA_FOLIACION_PG.FA_CONSUME_FOLIO_CICLO_FN(:b0,null\
 ,:b1,:b2,null ,null ,:b3,TO_DATE(:b4,'YYYYMMDDHH24MISS'),1) into :b5  from DU\
AL ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2757;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&ihCodTipDocum;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szhCodOficina;
    sqlstm.sqhstl[1] = (unsigned long )3;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szhCodOperadora;
    sqlstm.sqhstl[2] = (unsigned long )6;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&lhNumProceso;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecha;
    sqlstm.sqhstl[4] = (unsigned long )15;
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         short *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)szhResultado;
    sqlstm.sqhstl[5] = (unsigned long )256;
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
        vDTrazasLog  (modulo,"\n\t**  Error en ejecucion de FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        vDTrazasError(modulo,"\n\t**  Error en ejecucion de FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                                "\n\t\t=> Error : [%d]  [%s] ",LOG01,SQLCODE,SQLERRM);
        return  FALSE;
    }

    iNumParametros = 3;
    RecupParam(&iNumParametros,szArregloParametros,szhResultado,cSeparador);

    if(iNumParametros!=3)
    {
        vDTrazasLog  (modulo,"\n\t** Numero de parametros retornados incorrecto para  FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                            ,LOG01);
        vDTrazasError(modulo,"\n\t** Numero de parametros retornados incorrecto para  FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                            ,LOG01);
        return  FALSE;
    }

    if (strcmp(szArregloParametros[0],"2") != 0 )
    {
        vDTrazasLog  (modulo,"\n\t** Error, retorno de la funcion FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                             "\n\t=> Error : [%d]  [%s] "
                            ,LOG01, szArregloParametros[0],SQLCODE,SQLERRM);
        vDTrazasError(modulo,"\n\t** Error, retorno de la funcion FA_FOLIACION_PG.FA_CONSUME_FOLIO_FN **"
                             "\n\t=> Retorno proceso = [%s]"
                             "\n\t=> Error : [%d]  [%s] "
                            ,LOG01, szArregloParametros[0],SQLCODE,SQLERRM);
        return (FALSE);
    }

    *plNumFolio = atol(szArregloParametros[2]);
    strcpy(szPrefPlaza, szArregloParametros[1]);

  return TRUE;
}/*************************** Final bfnConsumeFolio **************************/

/*****************************************************************************/
/*                          funcion : vfnHandlerFile                         */
/*****************************************************************************/
void vfnHandlerFile (int iSig)
{
  if (stStatus.LogFile != (FILE *)NULL)
  {
       fclose (stStatus.LogFile);
       fclose (stStatus.ErrFile);
       exit   (-1)              ;
 }
}/************************* Final vfnHandlerFile *****************************/


/*****************************************************************************/
/*                            funcion : szfnDigVerificador                   */
/* Parametro : La cadena a Tratar                                            */
/* Return    : El Caracter de control                                        */
/*****************************************************************************/
char *szfnDigVerificador (char *szNum)
{
    int i       = 0;
    int j       = 2; /* j tomara los valores de 2 a 7 inclusives */
    int iDigito = 0;

    char szAux[2]   = "";
    char szNumSal[2]= "";

    div_t stRes         ;


        i = strlen(szNum)-1;

        while (i >= 0)
        {
          if (j >= 8)
              j  = 2;

          strncpy (szAux, &szNum [i], 1);

          iDigito += (atoi (szAux) * j);

          j++;
          i--;
        }

        stRes = div (iDigito, 11);

        if ( (11-stRes.rem) == 10)
            sprintf (szNumSal, "%s", szDIG10);
        else
            sprintf (szNumSal, "%d", ((11-stRes.rem)==11)?0:11-stRes.rem);


return (char *)szNumSal;
}/**************************** Final szfnDigVerificador **********************/

BOOL bfnGetBcoUniPac (long lCodCliente, char *szCodBanco )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long  lhCodCliente    ;
        char  szhCodBco   [16] ;/* EXEC SQL VAR szhCodBco IS STRING (16); */ 

    /* EXEC SQL END DECLARE SECTION  ; */ 


    vDTrazasLog (szExeName,
               "\n\t\t* Recuperacion Codigo de Banco de cliente Pac (bfnGetBcoUniPac)"
               "\n\t\t=> Cod.Cliente [%ld]", LOG05,lCodCliente);

    lhCodCliente = lCodCliente;

    /* EXEC SQL
        SELECT COD_BANCO
          INTO :szhCodBco
          FROM CO_UNIPAC
         WHERE COD_CLIENTE = :lhCodCliente ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 45;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_BANCO into :b0  from CO_UNIPAC where COD_CLIEN\
TE=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2796;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodBco;
    sqlstm.sqhstl[0] = (unsigned long )16;
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



    if (SQLCODE != SQLNOTFOUND)
    {
        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                       "Select=>CO_UNIPAC",szfnORAerror ());
            return  (FALSE)                                       ;
        }
        else
        {
            strcpy(szCodBanco,szhCodBco);
       }
    }
    return TRUE;

}/************************ Final bfnGetBcoUniPac ***************************/

/*****************************************************************************/
/*                          Funcion   RecupParam                             */
/* funcion que entrega en el arreglo los distintos parametros de la cadena   */
/* que se encuentran se parados por el delimitador                           */
/*****************************************************************************/
BOOL RecupParam( int *iNumParam, char *argv[], char *szCadena,int chr)
{
    char    modulo[] = "RecupParam";
    char    *p, *pant, c;
    int     cont;

    cont = 0;
    *iNumParam = 0;
    pant = p = szCadena;

    while(1)
    {
      p=strchr(pant,chr);
      if(p==NULL)
      {
        break;
      }
      else
      {
           c = *p;
           *p = 0;
           if ( ( argv[cont]  = malloc(strlen(pant)+1) ) == NULL )
           {
                vDTrazasError(modulo,"\n\t\t*** Error, No se puede reservar memoria ",LOG01);
                return (FALSE);
           }
           strcpy(argv[cont],pant) ;
           pant = p  + 1;
           *p = c;
           cont++;
        }
   }
   if(p==NULL)
   {
      if(strlen(pant)>0){
           if ( ( argv[cont]  = malloc(strlen(pant)+1) ) == NULL ){
                vDTrazasError(modulo,"\n\t\t*** Error, No se puede reservar memoria ",LOG01);
                return (FALSE);
           }
           strcpy(argv[cont],pant) ;
           cont++;
      }

   }

   *iNumParam=cont;
   return (TRUE);
}/************************ Final RecupParam ***************************/


/*****************************************************************************/
/* bfnGetTecnoAbo                                                            */
/*****************************************************************************/
BOOL bfnGetTecnoAbo (long lNumAbonado, char *szCodTecno )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        long  lhNumAbonado    ;
        char  szhCodTecno   [8] ;/* EXEC SQL VAR szhCodTecno IS STRING (8); */ 

        long  lhCodCliente    ;
    /* EXEC SQL END DECLARE SECTION  ; */ 


    vDTrazasLog (szExeName,"\n\t\t* Recuperacion Codigo de Tecnologia del Abonado"
                           "\n\t\t=> Num.Abonado [%ld]", LOG05,lNumAbonado);

    lhNumAbonado = lNumAbonado;
    lhCodCliente = stCliente.lCodCliente;
    strcpy(szhCodTecno,"");


    /* EXEC SQL
        SELECT COD_TECNOLOGIA
          INTO :szhCodTecno
          FROM GA_ABOCEL
         WHERE NUM_ABONADO = :lhNumAbonado
           AND COD_CLIENTE = :lhCodCliente; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 45;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_TECNOLOGIA into :b0  from GA_ABOCEL where (NUM\
_ABONADO=:b1 and COD_CLIENTE=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2819;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodTecno;
    sqlstm.sqhstl[0] = (unsigned long )8;
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
    sqlstm.sqhstv[2] = (unsigned char  *)&lhCodCliente;
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



    if (SQLCODE != SQLNOTFOUND)
    {
        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,
                       "Select=>CO_UNIPAC",szfnORAerror ());
            return  (FALSE)                                       ;
        }
        else
        {
            strcpy(szCodTecno,szhCodTecno);
        }
    }
    vDTrazasLog (szExeName,"\n\t\t=> Tecnologia encontrada [%s]", LOG05,szCodTecno);

    return 1;

}/************************ Final bfnGetTecnoAbo ***************************/

/******************************************************************************
Funcion         :       ifnCmpFactCobr
*******************************************************************************/
/*int ifnCmpFactCobr(const void *cad1,const void *cad2)
{
    return ((FACTCOBR *)cad1)->iCodConcFact -
         ((FACTCOBR *)cad2)->iCodConcFact;

}*/

/*****************************************************************************/
/*                             funcion : bfnFindFactCobr                   */
/*****************************************************************************/
BOOL bfnFindFactCobr (int iCodConcFact, int iFactCobr )
{
    /*FACTCOBR  stkey;*/
    /*FACTCOBR  *pstAux = (FACTCOBR *)NULL;*/

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        static int   ihCodConcFact;
        static int   ihCodConCobr ;
    /* EXEC SQL END DECLARE SECTION; */ 


    /*memset (&stkey,0, sizeof(FACTCOBR));*/
    vDTrazasLog (szExeName,"\n\t\t* Busca Concepto Cobro "
                            "\n\t\t=> Concepto Fact.   [%d]"
                            , LOG05,iCodConcFact);


    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {
        if ( pstConceptos[iCodConcFact].iFlagExiste == 1 )
        {
            iFactCobr = pstConceptos[iCodConcFact].iCodConCobr;
            vDTrazasLog(szExeName, "Concepto Cobr. [%d] encontrado", LOG04, iFactCobr);
        }else
        {
                    vDTrazasLog(szExeName, "Concepto Fact. [%d] no encontrada ...", LOG01, iCodConcFact);
                        return FALSE;
        }

    }
    else
    {
        ihCodConcFact= iCodConcFact;

        /* EXEC SQL
            SELECT COD_CONCCOBR
              INTO :ihCodConCobr
              FROM FA_FACTCOBR
             WHERE COD_CONCFACT = :ihCodConcFact; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_CONCCOBR into :b0  from FA_FACTCOBR where \
COD_CONCFACT=:b1";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2846;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodConCobr;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&ihCodConcFact;
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
           iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Fa_FactCobr",
                     szfnORAerror ());
           return FALSE;
        }
        else
        {
            iFactCobr = ihCodConCobr;
        }
    }
    return TRUE;
}/**************************** Final bfnFindFactCobr *********************/

/******************************************************************************
Funcion         :       ifnCmpOficinas
*******************************************************************************/
int ifnCmpOficinas(const void *cad1,const void *cad2)
{
    return ( strcmp (((OFICINA  *)cad1)->szCodOficina,((OFICINA  *)cad2)->szCodOficina) );

}

/*****************************************************************************/
/*                             funcion : bfnFindOficina                   */
/*****************************************************************************/
BOOL bfnFindOficina (char *szCodOficina, OFICINA *pstOficina )
{
    OFICINA  stkey;
    OFICINA  *pstAux = (OFICINA *)NULL;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char szhCodOficina  [3];/* EXEC SQL VAR szhCodOficina  IS STRING(3); */ 

        char szhCodRegion   [4];/* EXEC SQL VAR szhCodRegion       IS STRING(4); */ 

        char szhCodProvincia [6];/* EXEC SQL VAR szhCodProvincia   IS STRING(6); */ 

        char szhCodCiudad   [6];/* EXEC SQL VAR szhCodCiudad   IS STRING(6); */ 

        char szhCodPlaza    [6];/* EXEC SQL VAR szhCodPlaza        IS STRING(6); */ 

    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (szExeName,"\n\t\t* Busca Oficina "
                            "\n\t\t=> Cod.Oficina   [%s]"
                            "\n\t\t=> Num.Oficina   [%d]"
                            "\n\t\t=> Tipo Documento[%d]"
                            "\n\t\t=> stDatosGener.iCodCiclo [%d]"
                            , LOG05,szCodOficina, pstOficinas.iNumOficinas, stProceso.iCodTipDocum,stDatosGener.iCodCiclo);


    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {

        strcpy (stkey.szCodOficina,fnQuitaBlancos(szCodOficina));

        if ( (pstAux = (OFICINA *)bsearch (&stkey, pstOficinas.stOficina, pstOficinas.iNumOficinas,
                                       sizeof (OFICINA),ifnCmpOficinas ))== (OFICINA *)NULL)
        {
            vDTrazasLog(szExeName, "Oficina [%s] no encontrada ...", LOG01, szCodOficina);
            return  (FALSE)                                                   ;
        }
        memcpy (pstOficina, pstAux, sizeof(OFICINA));
    }
    else
    {
        strcpy (szhCodOficina, szCodOficina);
        /* EXEC SQL
            SELECT B.COD_REGION, B.COD_PROVINCIA, B.COD_CIUDAD, C.COD_PLAZA
              INTO :szhCodRegion, :szhCodProvincia,:szhCodCiudad,:szhCodPlaza
              FROM GE_OFICINAS    A,
                   GE_DIRECCIONES B,
                   GE_CIUDADES    C
             WHERE A.COD_OFICINA    = :szhCodOficina
               AND A.COD_DIRECCION  = B.COD_DIRECCION
               AND B.COD_REGION     = C.COD_REGION
               AND B.COD_PROVINCIA  = C.COD_PROVINCIA
               AND B.COD_CIUDAD     = C.COD_CIUDAD; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select B.COD_REGION ,B.COD_PROVINCIA ,B.COD_CIUDAD ,C\
.COD_PLAZA into :b0,:b1,:b2,:b3  from GE_OFICINAS A ,GE_DIRECCIONES B ,GE_CIUD\
ADES C where ((((A.COD_OFICINA=:b4 and A.COD_DIRECCION=B.COD_DIRECCION) and B.\
COD_REGION=C.COD_REGION) and B.COD_PROVINCIA=C.COD_PROVINCIA) and B.COD_CIUDAD\
=C.COD_CIUDAD)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2869;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhCodRegion;
        sqlstm.sqhstl[0] = (unsigned long )4;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhCodProvincia;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szhCodCiudad;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szhCodPlaza;
        sqlstm.sqhstl[3] = (unsigned long )6;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhCodOficina;
        sqlstm.sqhstl[4] = (unsigned long )3;
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



        if (SQLCODE)
        {
           iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> Oficinas",
                     szfnORAerror ());
           return FALSE;
        }
        else
        {
            strcpy (pstOficina->szCodOficina    , szhCodOficina );
            strcpy (pstOficina->szCodRegion     , szhCodRegion  );
            strcpy (pstOficina->szCodProvincia  , szhCodProvincia);
            strcpy (pstOficina->szCodCiudad     , szhCodCiudad  );
            strcpy (pstOficina->szCodPlaza      , szhCodPlaza   );
        }

    }
    return 1;
}/**************************** Final bfnFindFaCiclFact *********************/

/*****************************************************************************/
/*                         funcion : iCmpPlanTarif                           */
/*****************************************************************************/
int iCmpPlanTarif2 (const void* cad1,const void* cad2)
{
   int rc = 0;

   return
    ( (rc = ((PLANTARIF *)cad1)->iCodProducto-
            ((PLANTARIF *)cad2)->iCodProducto ) != 0)?rc:
    ( (rc = strcmp ( ((PLANTARIF *)cad1)->szCodPlanTarif,
                     ((PLANTARIF *)cad2)->szCodPlanTarif) ) != 0)?rc:0;
}/************************* Final iCmpPlanTarif ******************************/


/*****************************************************************************/
/*                        funcion : bFindPlanTarif                          */
/*****************************************************************************/
BOOL bFindPlanTarif (int   iCodProducto, char *pszCodPlanTarif, PLANTARIF  *lstPlanTarif)
{
  PLANTARIF stkey;
  PLANTARIF *pPlanT = (PLANTARIF *)NULL;
  BOOL bRes = 1;

  stkey.iCodProducto = iCodProducto ;
  strcpy (stkey.szCodPlanTarif ,pszCodPlanTarif);

  if ( (pPlanT = (PLANTARIF *)bsearch(&stkey,pstPlanTarif,NUM_PLANTARIF,
                 sizeof(PLANTARIF),iCmpPlanTarif2) )==(PLANTARIF *)NULL)
  {
        iDError (szExeName,ERR021,vInsertarIncidencia,"pstPlanTarif");
        bRes = FALSE;
  }
  else
     *lstPlanTarif = *pPlanT;

    vDTrazasLog (szExeName,"GENFA:lstPlanTarif.szCod_Unidad [%s]"
                           "GENFA:lstPlanTarif.lNumUnidades [%ld]"
                           , LOG05,lstPlanTarif->szCod_Unidad,lstPlanTarif->lNumUnidades);

  return (bRes);

}/************************ Final bFindPlanTarif *****************************/

/******************************************************************************
Funcion         :       ifnCmpOperServEsp
*******************************************************************************/
int ifnCmpOperServEsp(const void *cad1,const void *cad2)
{
    return ( ((OPERSERVESP  *)cad1)->iCodOperEspe - ((OPERSERVESP  *)cad2)->iCodOperEspe );

}

/*****************************************************************************/
/*                             funcion : bfnFindOperServEsp                   */
/*****************************************************************************/
BOOL bfnFindOperServEsp (int iOperServEsp, OPERSERVESP *pstOperServEsp )
{
    OPERSERVESP  stkey;
    OPERSERVESP  *pstAux = (OPERSERVESP *)NULL;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int  ihCodOperEspe  ;
        char szhCodUnidad [6];/* EXEC SQL VAR szhCodUnidad     IS STRING(6); */ 

        int  ihNumFactor    ;
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (szExeName,"\n\t\t* Busca Operador Serv. Especiales "
                            "\n\t\t=> Cod.Operador   [%d]"
                            "\n\t\t=> Num.Operadores [%d]"
                            "\n\t\t=> Tipo Documento[%d]"
                            "\n\t\t=> stDatosGener.iCodCiclo [%d]"
                            , LOG05, iOperServEsp, pstOperServEspec.iNumOperSerEsp
                            , stProceso.iCodTipDocum,stDatosGener.iCodCiclo);

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {

    if(  pstOperServEspec.stOperServEspec == NULL)
            return  (FALSE)                                                   ;

        stkey.iCodOperEspe = iOperServEsp;

        if ( (pstAux = (OPERSERVESP *)bsearch (&stkey, pstOperServEspec.stOperServEspec, pstOperServEspec.iNumOperSerEsp,
                                       sizeof (OPERSERVESP),ifnCmpOperServEsp ))== (OPERSERVESP *)NULL)
        {
            vDTrazasLog(szExeName, "Operador no encontrado [%d] no encontrada ...", LOG01, iOperServEsp);
            return  (FALSE)                                                   ;
        }
        memcpy (pstOperServEsp, pstAux, sizeof(OPERSERVESP));
    }
    else
    {
        ihCodOperEspe = iOperServEsp;

        /* EXEC SQL
            SELECT COD_UNIDAD, NUM_FACTOR
              INTO :szhCodUnidad, :ihNumFactor
              FROM TA_OPER_SERVESPE_TD
             WHERE COD_OPER_ESPE = :ihCodOperEspe; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COD_UNIDAD ,NUM_FACTOR into :b0,:b1  from TA_O\
PER_SERVESPE_TD where COD_OPER_ESPE=:b2";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2904;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhCodUnidad;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&ihNumFactor;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&ihCodOperEspe;
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
           iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> TA_OPER_SERVESPE_TD",
                     szfnORAerror ());
           return FALSE;
        }
        else
        {
            strcpy (pstOperServEsp->szCodUnidad , szhCodUnidad  );
            pstOperServEsp->iNumFactor = ihNumFactor;
        }

    }
    return 1;
}/**************************** Final bfnFindOperServEsp *********************/



/******************************************************************************
Funcion         :       ifnCmpDetPlanDesc
*******************************************************************************/
int ifnCmpDetPlanDesc(const void *cad1,const void *cad2)
{
    return ( strcmp( ((DETPLANDESC  *)cad1)->szCodPlan, ((DETPLANDESC  *)cad2)->szCodPlan ));

}

/*****************************************************************************/
/*                             funcion : bfnFindDetPlanDesc                   */
/*****************************************************************************/
BOOL bfnFindDetPlanDesc (char *pszCodPlanDesc, DETPLANDESC *pstDetPlanDesc )
{
    DETPLANDESC  stkey;
    DETPLANDESC  *pstAux = (DETPLANDESC *)NULL;
     char    modulo[] = "bfnFindDetPlanDesc";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        char  szhCod_Plan          [6] ;
        char  szhFecParam          [15];
        char  szhCod_Tipeval       [2] ;
        char  szhCod_Tipapli       [2] ;
        int   ihCod_Grupoeval          ;
        int   ihCod_Grupoapli          ;
        int   ihNum_Cuadrante          ;
        char  szhTip_Unidad        [3] ;
        int   ihCod_Concdesc           ;
        double dhMto_Minfact           ;
        short i_shCod_Grupoeval        ;
        short i_shCod_Grupoapli        ;
        short i_shNum_Cuadrante        ;
        short i_shCod_Concdesc         ;
        short i_shMto_Minfact          ;
        char  szhFmtFecha    [15];/* EXEC SQL VAR szhFmtFecha IS STRING(15); */ 

    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (szExeName,"\n\t\t* Busca Detalle de Plan de Descuento "
                            "\n\t\t=> Cod.Plan Desc. [%s]"
                            , LOG05, pszCodPlanDesc);

    if (stProceso.iCodTipDocum == stDatosGener.iCodCiclo)
    {

        if(  pstDetPlanDescs.stDetPlanDesc == NULL)
                return  (FALSE);

        strcpy (stkey.szCodPlan, pszCodPlanDesc);

        if ( (pstAux = (DETPLANDESC *)bsearch (&stkey, pstDetPlanDescs.stDetPlanDesc, pstDetPlanDescs.iNumRegs,
                                       sizeof (DETPLANDESC),ifnCmpDetPlanDesc ))== (DETPLANDESC *)NULL)
        {
            vDTrazasLog(szExeName, "Plan de Descuento no encontrado [%s] no encontrada ...", LOG01, pszCodPlanDesc);
            return  (FALSE)                                                   ;
        }
        memcpy (pstDetPlanDesc, pstAux, sizeof(DETPLANDESC));
    }
    else
    {
        strcpy (szhCod_Plan, pszCodPlanDesc);
        strcpy (szhFmtFecha, "yyyymmddhh24miss");

        /* EXEC SQL
            SELECT  C.COD_TIPEVAL      ,
                    C.COD_TIPAPLI      ,
                    C.COD_GRUPOEVAL    ,
                    C.COD_GRUPOAPLI    ,
                    C.NUM_CUADRANTE    ,
                    C.TIP_UNIDAD       ,
                    C.COD_CONCDESC     ,
                    C.MTO_MINFACT
                    INTO  
                    :szhCod_Tipeval    ,
                    :szhCod_Tipapli    ,
                    :ihCod_Grupoeval :i_shCod_Grupoeval,
                    :ihCod_Grupoapli :i_shCod_Grupoapli  ,
                    :ihNum_Cuadrante :i_shNum_Cuadrante  ,
                    :szhTip_Unidad     ,
                    :ihCod_Concdesc :i_shCod_Concdesc,
                    :dhMto_Minfact  :i_shMto_Minfact
              FROM  FAD_PLANDESC B,  FAD_DETPLANDESC C
             WHERE  B.COD_PLANDESC = C.COD_PLANDESC
               AND    TO_DATE(:szhFecParam,'yyyymmddhh24miss') BETWEEN C.FEC_DESDE AND C.FEC_HASTA
               AND    B.COD_PLANDESC = :szhCod_Plan; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 45;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select C.COD_TIPEVAL ,C.COD_TIPAPLI ,C.COD_GRUPOEVAL \
,C.COD_GRUPOAPLI ,C.NUM_CUADRANTE ,C.TIP_UNIDAD ,C.COD_CONCDESC ,C.MTO_MINFACT\
 into :b0,:b1,:b2:b3,:b4:b5,:b6:b7,:b8,:b9:b10,:b11:b12  from FAD_PLANDESC B ,\
FAD_DETPLANDESC C where ((B.COD_PLANDESC=C.COD_PLANDESC and TO_DATE(:b13,'yyyy\
mmddhh24miss') between C.FEC_DESDE and C.FEC_HASTA) and B.COD_PLANDESC=:b14)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2931;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)szhCod_Tipeval;
        sqlstm.sqhstl[0] = (unsigned long )2;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szhCod_Tipapli;
        sqlstm.sqhstl[1] = (unsigned long )2;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&ihCod_Grupoeval;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&i_shCod_Grupoeval;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&ihCod_Grupoapli;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&i_shCod_Grupoapli;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&ihNum_Cuadrante;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&i_shNum_Cuadrante;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)szhTip_Unidad;
        sqlstm.sqhstl[5] = (unsigned long )3;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&ihCod_Concdesc;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&i_shCod_Concdesc;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&dhMto_Minfact;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&i_shMto_Minfact;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)szhFecParam;
        sqlstm.sqhstl[8] = (unsigned long )15;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)szhCod_Plan;
        sqlstm.sqhstl[9] = (unsigned long )6;
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



        if (SQLCODE)
        {
           iDError (szExeName,ERR000,vInsertarIncidencia,"Open=> TA_OPER_SERVESPE_TD",
                     szfnORAerror ());
           return FALSE;
        }
        else
        {
            vDTrazasLog (modulo,"\n\t\t* Cliente Con Plan de Descuento [%s]",LOG04,szhCod_Plan);
            strcpy(pstDetPlanDesc->szCodTipeval      , szhCod_Tipeval);
            strcpy(pstDetPlanDesc->szCodTipapli      , szhCod_Tipapli);
            strcpy(pstDetPlanDesc->szTipUnidad       , szhTip_Unidad);

            if( i_shCod_Grupoeval == ORA_NULL )
                pstDetPlanDesc->iCodGrupoeval = ORA_NULL;
            else
                pstDetPlanDesc->iCodGrupoeval = ihCod_Grupoeval;

            if( i_shCod_Grupoapli == ORA_NULL )
                pstDetPlanDesc->iCodGrupoapli = ORA_NULL;
            else
                pstDetPlanDesc->iCodGrupoapli = ihCod_Grupoapli;

            if( i_shNum_Cuadrante == ORA_NULL )
                pstDetPlanDesc->iNumCuadrante = ORA_NULL;
            else
                pstDetPlanDesc->iNumCuadrante = ihNum_Cuadrante;

            if( i_shCod_Concdesc == ORA_NULL )
                pstDetPlanDesc->iCodConcdesc  = ORA_NULL;
            else
                pstDetPlanDesc->iCodConcdesc  = ihCod_Concdesc;

            if( i_shMto_Minfact == ORA_NULL )
                pstDetPlanDesc->dMtoMinfact   = ORA_NULL;
            else
                pstDetPlanDesc->dMtoMinfact   = dhMto_Minfact;

        }

    }
    return 1;
}/**************************** Final bfnFindDetPlanDesc *********************/

