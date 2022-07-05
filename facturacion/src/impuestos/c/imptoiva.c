
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
           char  filnam[17];
};
static const struct sqlcxp sqlfpn =
{
    16,
    "./pc/imptoiva.pc"
};


static unsigned int sqlctx = 3458531;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
"select  /*+  index (GE_IMPUESTOS PK_GE_IMPUESTOS)  +*/ TO_CHAR(FEC_DESDE,:b0\
) ,COD_CONCGENE ,TO_CHAR(FEC_HASTA,:b0) ,PRC_IMPUESTO  from GE_IMPUESTOS where\
 (((((COD_CATIMPOS=:b2 and COD_ZONAIMPO=:b3) and COD_GRPSERVI=:b4) and FEC_DES\
DE<=TO_DATE(:b5,:b0)) and FEC_HASTA>=TO_DATE(:b5,:b0)) and PRC_IMPUESTO>0.01) \
          ";

 static const char *sq0009 = 
"select COD_CONCORIGEN ,COD_CONCRETEN ,MTO_UNITARIO ,0  from FA_RETCONCEPTOS_\
TD where SYSDATE between FEC_DESDE and FEC_HASTA           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,232,0,260,682,0,0,8,7,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,5,0,0,1,97,0,0,1,5,0,0,
52,0,0,2,232,0,260,720,0,0,8,7,0,1,0,2,3,0,0,1,97,0,0,1,97,0,0,1,97,0,0,1,97,0,
0,1,5,0,0,1,97,0,0,1,5,0,0,
99,0,0,3,263,0,260,824,0,0,11,7,0,1,0,1,5,0,0,1,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,
2,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
158,0,0,4,189,0,260,867,0,0,6,5,0,1,0,2,3,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
1,5,0,0,
197,0,0,5,320,0,265,1138,0,0,9,9,0,1,0,1,5,0,0,1,5,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
248,0,0,5,0,0,269,1149,0,0,4,0,0,1,0,2,5,0,0,2,3,0,0,2,5,0,0,2,4,0,0,
279,0,0,5,0,0,271,1190,0,0,0,0,0,1,0,
294,0,0,6,106,0,262,1278,0,0,4,4,0,1,0,1,3,0,0,1,5,0,0,1,4,0,0,1,3,0,0,
325,0,0,7,70,0,260,1944,0,0,2,1,0,1,0,2,5,0,0,1,3,0,0,
348,0,0,8,116,0,260,1977,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
371,0,0,9,135,0,265,2018,0,0,0,0,0,1,0,
386,0,0,9,0,0,269,2037,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,
417,0,0,9,0,0,271,2062,0,0,0,0,0,1,0,
};


/****************************************************************************/
/*  Fichero    : imptoiva.pc                                                */
/*  Descripcion: funciones PROC para el calculo de impuestos                */
/*  Fecha      : 14-Nov-96                                                  */
/****************************************************************************/
/*  PGonzaleg : Modificacion del tipo de dato de NUMUNIDADES                */
/*  4-03-2002  int ---> long                                                */
/****************************************************************************/

#define _IMPTOIVA_PC_

#include <imptoiva.h>

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


/****************************************************************************/
/*                          Variables globales                              */
/****************************************************************************/
static int    iNImptosT     ;

/****************************************************************************/
/*                           funcion : bImtosIvaClienteGeneral              */
/* -Funcion que Aplica Impuestos a los Conceptos generados en un ciclo para */
/*  un Cliente.                                                             */
/* -Valores Retorno : Error->FALSE, !ERROR->TRUE                            */
/****************************************************************************/
BOOL bImptosIvaClienteGeneral (int iTipoFact)
{
    char modulo[] = "bImptosIvaClienteGeneral";

    int  iNumRegIni    = 0    ;
    int  iInd          = 0    ;
    int  i             = 0    ;
    int  j             = 0    ;
    int  k             = 0    ;
    int  iNImptos      = 0    ;
    int  iNumConceptos = 0    ;
    int  iCodZonaImpos = 0    ;
    int  iCodGrpServi  = 0    ;

    CONCEPTO  stConcepto                     ;
    IMPTOS    stImpto = {0,(IMPUESTOS *)NULL};
    CONCRETEN stConcReten                    ;
    CONCEPTO  stConceptoAux                  ;
    float     fPrcImpuestoAux = 0.0          ;
    double    dImpConceptoAux = 0.0          ;
    double    dImpConcFinal   = 0.0          ;

    /* Acumula el total de los impuestos para el ajuste */
    TOTIMPTOS stTotImptos={0,(TOTIMPTO *)NULL};

    char szFecZonaImpo [15] = "";
    char szFuncion     [15] = "";

    iNImptosT = 0;

    strcpy (stAnomProceso.szDesProceso, "Impuestos");

    switch (iTipoFact)
    {
        case FACT_CICLO      :
             strcpy (szFuncion,"CICLO")      ;
             break                           ;
        case FACT_CONTADO    :
             strcpy (szFuncion,"CONTADO")    ;
             break                           ;
        case FACT_BAJA       :
             strcpy (szFuncion,"BAJA")       ;
             break                           ;
        case FACT_LIQUIDACION:
             strcpy (szFuncion,"LIQUIDACION");
             break                           ;
        case FACT_RENTAPHONE  :
             strcpy (szFuncion,"RENT PHONE") ;
             break                           ;
        case FACT_COMPRA      :
             strcpy (szFuncion,"COMPRA")     ;
             break                           ;
        case FACT_MISCELAN    :
             strcpy (szFuncion,"MISCELAN")   ;
             break                           ;
        case FACT_ROAMINGVIS  :
             strcpy (szFuncion,"ROAMING VISITANTE");
             break                                 ;
        default               :
             break                           ;
    }
    vDTrazasLog (szExeName,"\n\t\t* IMPUESTOS %s\n\t\t=> Cliente [%ld]", LOG03,szFuncion, stCliente.lCodCliente);

    /*********************************************************/
    strcpy (szFecZonaImpo, szGetFecZonaImp(iTipoFact));
    if (strlen (szFecZonaImpo) == 0)
    {
        iDError (modulo,ERR040,vInsertarIncidencia);
        return FALSE;
    }

    if (!bfnEvalZonasImpos (szFecZonaImpo, iTipoFact, &iCodZonaImpos, pstParamGener.iIndZonaImpCic))
    {
        vDTrazasError(modulo,"\n\t** No se pueden evaluar Zonas Impositivas **",LOG01);
        vDTrazasLog  (modulo,"\n\t** No se pueden evaluar Zonas Impositivas **",LOG01);
        return FALSE;
    }
    /* Pasa a la prefactura el valor de la zona impositiva */
    stPreFactura.iCodZonaImpo=iCodZonaImpos;
    /* *************************************************** */

    iNumRegIni = stPreFactura.iNumRegistros;

    for (i=0;i<iNumRegIni;i++)
    {
        if (stPreFactura.A_PFactura.iCodTipConce [i] != IMPUESTO && stPreFactura.A_PFactura.iCodTipConce [i] != CARRIER )
        {
            if (!bGetGrupoServicios (stPreFactura.A_PFactura.iCodConcepto[i],&iCodGrpServi, szFecZonaImpo,iTipoFact))
                return FALSE;
            if (iCodGrpServi == ORA_NULL)
            {
                vDTrazasLog(modulo, "\n\t\t* Concepto [%d] NO tiene Grupo Servicios Asociado",
                                    LOG04,stPreFactura.A_PFactura.iCodConcepto[i]);
                continue;
            }
            if (!bGetImpuestos (stCliente.iCodCatImpos, iCodZonaImpos,iCodGrpServi , szFecZonaImpo,&stImpto, iTipoFact))
                return FALSE;

            vDTrazasLog (modulo, "\n\t\t* Aplica Iva "
                                 "\n\t\t=> Cod.TipConce       [%d]"
                                 "\n\t\t=> Ind.Factur         [%d]"
                                 "\n\t\t=> Zona Impositiva    [%d]"
                                 "\n\t\t=> Grupo Servicios    [%d]"
                                 "\n\t\t=> Numero de Impuestos[%d]"
                                 "\n\t\t=> Concepto           [%d]"
                                ,LOG05
                                ,stPreFactura.A_PFactura.iCodTipConce [i]
                                ,stPreFactura.A_PFactura.iIndFactur   [i]
                                ,iCodGrpServi, stImpto.iNumImpuestos
                                ,stPreFactura.A_PFactura.iCodConcepto[i]);

            for (iInd=0;iInd<stImpto.iNumImpuestos;iInd++)
            {
                iNumConceptos = stPreFactura.iNumRegistros;
                if (stPreFactura.iNumRegistros >= MAX_CONCFACTUR)
                {
                    vDTrazasLog (modulo,"\n\t* MAX_CONCFACTUR %d - %d", LOG03,MAX_CONCFACTUR, stPreFactura.iNumRegistros);
                    iDError (modulo,ERR035,vInsertarIncidencia);
                    return FALSE;
                }
                if (!bCalculaImptos (i,stImpto.pImpuestos[iInd]))
                    return FALSE;

                stPreFactura.A_PFactura.iCodConcepto[iNumConceptos] = stImpto.pImpuestos [iInd].iCodConcGene ;

                memset (&stConcepto,0,sizeof(CONCEPTO))                   ;
                if (!bFindConcepto (stImpto.pImpuestos[iInd].iCodConcGene, &stConcepto))
                    return FALSE;

                strcpy (stPreFactura.A_PFactura.szDesConcepto [iNumConceptos], stConcepto.szDesConcepto);

                if (!bfnAplicaImpto(i, iNumConceptos, iTipoFact))
                {
                    vDTrazasError(modulo,"\n\t** ERROR, en cracion del concepto de Impto. **",LOG01);
                    return (FALSE);
                }

                stPreFactura.A_PFactura.fPrcImpuesto[iNumConceptos] = stImpto.pImpuestos[iInd].fPrcImpuesto;

                /* RAO041102 : Se cambia el MBase X el IFacturable Origen */
                if (!bfnAcumTotImptos (&stTotImptos
                                      ,stPreFactura.A_PFactura.iCodConcepto[i]
                                      ,stPreFactura.A_PFactura.iCodConcepto[iNumConceptos]
                                      ,stPreFactura.A_PFactura.dImpFacturable[i]
                                      ,stPreFactura.A_PFactura.dImpFacturable[iNumConceptos]
                                      ,stPreFactura.A_PFactura.fPrcImpuesto[iNumConceptos]))
                {
                    vDTrazasError(modulo,"\n\t**  Error en acumulacion de Impuestos **",LOG01);
                    return (FALSE);
                }
                iNImptos++;

                if (stPreFactura.A_PFactura.iIndCuota[i] == IND_CUOTA && iTipoFact == FACT_CONTADO)
                {
                    if (stPreFactura.A_PFactura.iCodTipConce[i] == ARTICULO)
                    {
                        if(!bGeneraCuotas(stPreFactura.A_PFactura.lNumCargo      [i],
                                          stPreFactura.A_PFactura.szCodCuota     [i],
                                          stImpto.pImpuestos[iInd].fPrcImpuesto     ,
                                          stPreFactura.A_PFactura.iCodConcepto   [i]))
                            return FALSE;
                    }
                }

                if (stConcepto.sIndTecnologia == 1 && strcmp( stPreFactura.A_PFactura.szCodTecnologia [i],"") != 0)
                {
                    strcpy (stPreFactura.A_PFactura.szCodTecnologia[iNumConceptos],stPreFactura.A_PFactura.szCodTecnologia [i]);
                }
                else
                {
                    strcpy (stPreFactura.A_PFactura.szCodTecnologia[iNumConceptos], stConcepto.szDefTecnologia);
                }
            }/* fin for->iInd */

        vDTrazasLog (modulo,"\n\t\tImpuestos aplicados al concepto %d del cliente %ld\n",
                            LOG04,stPreFactura.A_PFactura.iCodConcepto[i],
                            stPreFactura.A_PFactura.lCodCliente [i]);
        vFreeImpuestos(&stImpto);

        iNImptosT += iNImptos;

        }/* fin if Imptos y Carrier */
    }/* fin for i<iNumRegIni */


    /******************************************************/
    /* Codigo para realizacion de ajuste de IVA.          */
    /******************************************************/
    if(stPreFactura.iNumRegistros > 0)
    {
        if (!bfnAjusteImptos(&stTotImptos))
        {
            vDTrazasError(modulo,"\n\t**  Error en proceso de Ajuste de Impuestos **",LOG01);
            return (FALSE);
        }
    }

    vDTrazasLog (modulo,"\n\t\t# Cliente [%ld] => Impuestos Aplicados [%d]\n",
                        LOG03,stCliente.lCodCliente,iNImptos);

    /*****************************************************************************/
    /* Codigo para realizacion de ajustes a nivel de abonado PPV 04/10/2006 34216*/
    /*****************************************************************************/
    if(stPreFactura.iNumRegistros > 0)
    {
        if (!bfnValidaAbonados)
        {
            vDTrazasError(modulo,"\n\t**  Error en proceso de Validacion de Abonados **",LOG01);
            return (FALSE);
        }
    }
    /*****************************************************************************/

    /******************************************************/
    /* Codigo Aplicar Retenci�n de Impuestos              */
    /* SAAM-20060110, Proyecto P-TMC-05040 RETENCI�N IVA  */
    /******************************************************/

    if (!bfnEvaluaClienteconRetencion(stCliente.lCodCliente))
    {
        vDTrazasLog(modulo,"\n\t\t# Cliente [%ld] => NO Aplica Retenci�n de Impuestos\n",LOG03, stCliente.lCodCliente);
    }
    else
    {
        if (!bfnCargaConceptosConRetencion(&pstConcReten.stConcRetencion, &pstConcReten.iCantConcRetencion))
        {
            vDTrazasError(modulo,"\n\t** Error en Carga de Conceptos con Retenci�n  **",LOG01);
            return (FALSE);
        }
        iNumRegIni = 0;
        iNumRegIni = stPreFactura.iNumRegistros;

        vDTrazasLog(modulo, "\n\t\t* Numero de registros iNumRegIni:[%d]",LOG05, iNumRegIni);
        for (i=0;i<iNumRegIni;i++) /* for de revisi�n de conceptos */
        {
            vDTrazasLog(modulo, "\n\t\t* i ---> [%d]",LOG05, i);
            if (stPreFactura.A_PFactura.iCodTipConce [i] == ARTICULO)
            {
                memset(&stConcReten,0,sizeof(CONCRETEN));
                if(!bfnFindConceptosConRetencion((long)stPreFactura.A_PFactura.iCodConcepto[i],&stConcReten))
                {
                    vDTrazasLog(modulo,"\n\t\t# Concepto [%ld] => NO Aplica Retenci�n de Impuestos\n",LOG03, stPreFactura.A_PFactura.iCodConcepto[i]);
                }
                else
                {
                    dImpConceptoAux = 0.0;
                    fPrcImpuestoAux = 0.0;

                    for (j=0;j<iNumRegIni;j++) /* for de revisi�n de impuestos y descuentos --> antes decia i++... <>--*/
                    {
                        vDTrazasLog(modulo, "\n\t\t* Dentro de for(j)...:"
                                            "\n\t\t  j              : [%d]"
                                            "\n\t\t  stPreFactura.A_PFactura.iCodTipConce [j]: [%d] - IMPUESTO:[%d]"
                                            "\n\t\t  stPreFactura.A_PFactura.iCodConceRel[j] : [%d] - stPreFactura.A_PFactura.iCodConcepto[i]:[%d]"
                                            ,LOG05
                                            ,j
                                            ,stPreFactura.A_PFactura.iCodTipConce [j]
                                            ,IMPUESTO
                                            ,stPreFactura.A_PFactura.iCodConceRel[j]
                                            ,stPreFactura.A_PFactura.iCodConcepto[i]);

                        if (stPreFactura.A_PFactura.iCodTipConce [j] == IMPUESTO &&
                            stPreFactura.A_PFactura.iCodConceRel[j] == stPreFactura.A_PFactura.iCodConcepto[i])
                        {
                            vDTrazasLog(modulo, "\n\t\t* Dentro de if() de IMPUESTO, j:[%d]:",LOG05,j);

                            dImpConceptoAux += stPreFactura.A_PFactura.dImpFacturable[j];
                            fPrcImpuestoAux += stPreFactura.A_PFactura.fPrcImpuesto[j];
                        }

                        if (stPreFactura.A_PFactura.iCodTipConce [j] == DESCUENTO &&
                            stPreFactura.A_PFactura.iCodConceRel[j] == stPreFactura.A_PFactura.iCodConcepto[i])
                        {
                            vDTrazasLog(modulo, "\n\t\t* Dentro de if() de DESCUENTO, j:[%d]:",LOG05,j);
                            for(k=0;k<iNumRegIni;k++)
                            {
                                vDTrazasLog(modulo, "\n\t\t* Dentro de for(k)...:"
                                                    "\n\t\t  k              : [%d]"
                                                    "\n\t\t  stPreFactura.A_PFactura.iCodTipConce [k]: [%d] - IMPUESTO:[%d]"
                                                    "\n\t\t  stPreFactura.A_PFactura.iCodConceRel[k] : [%d] - stPreFactura.A_PFactura.iCodConcepto[j]:[%d]"
                                                    ,LOG05
                                                    ,k
                                                    ,stPreFactura.A_PFactura.iCodTipConce [k]
                                                    ,IMPUESTO
                                                    ,stPreFactura.A_PFactura.iCodConceRel[k]
                                                    ,stPreFactura.A_PFactura.iCodConcepto[j]);

                                if (stPreFactura.A_PFactura.iCodTipConce [k] == IMPUESTO &&
                                    stPreFactura.A_PFactura.iCodConceRel[k] == stPreFactura.A_PFactura.iCodConcepto[j])
                                {
                                    vDTrazasLog(modulo, "\n\t\t* Dentro de if() de IMPUESTO, k:[%d]:",LOG05,k);
                                    dImpConceptoAux += stPreFactura.A_PFactura.dImpFacturable[k];

                                }
                            }
                        }

                    } /* fin for de revisi�n de impuestos */

                    dImpConceptoAux = fnCnvDouble(dImpConceptoAux,USOFACT);

                    vDTrazasLog(modulo, "\n\t\t* Despues de for de revision de impuestos:"
                                        "\n\t\t  i              : [%d]"
                                        "\n\t\t  dImpConceptoAux: [%f]"
                                        "\n\t\t  fPrcImpuestoAux: [%f]"
                                        ,LOG05
                                        ,i
                                        ,dImpConceptoAux
                                        ,fPrcImpuestoAux);

                    stConcReten.dMonto_Total = stConcReten.dMonto_Unitario * (double)stPreFactura.A_PFactura.lNumUnidades[i] / (1+ ((double)fPrcImpuestoAux/(double)100) );

                    stConcReten.dMonto_Total *= ((double)fPrcImpuestoAux/(double)100);

                    stConcReten.dMonto_Total = fnCnvDouble(stConcReten.dMonto_Total,USOFACT);

                    vDTrazasLog(modulo, "\n\t\t* ----------------------"
                                        "\n\t\t  stConcReten.dMonto_Unitario            : [%f]"
                                        "\n\t\t  stPreFactura.A_PFactura.lNumUnidades[i]: [%ld]"
                                        "\n\t\t  stConcReten.dMonto_Total               : [%f]"
                                        ,LOG05
                                        ,stConcReten.dMonto_Unitario
                                        ,stPreFactura.A_PFactura.lNumUnidades[i]
                                        ,stConcReten.dMonto_Total);

                    dImpConcFinal = stConcReten.dMonto_Total - dImpConceptoAux;

                    if( dImpConcFinal >= 1.0 )
                    {


                        iNumConceptos = stPreFactura.iNumRegistros;
                        stPreFactura.iNumRegistros++;

                        if (stPreFactura.iNumRegistros >= MAX_CONCFACTUR)
                        {
                            vDTrazasLog (modulo,"\n\t* MAX_CONCFACTUR [%d] - [%d]", LOG03,
                                                MAX_CONCFACTUR, stPreFactura.iNumRegistros);
                            iDError (modulo,ERR035,vInsertarIncidencia);
                            return FALSE;
                        }

                        stPreFactura.A_PFactura.iCodConcepto[iNumConceptos] = stConcReten.lConcepto_Reten;

                        memset (&stConceptoAux,0,sizeof(CONCEPTO));
                        if (!bFindConcepto (stConcReten.lConcepto_Reten,&stConceptoAux))
                            return FALSE;

                        strcpy(stPreFactura.A_PFactura.szDesConcepto[iNumConceptos],stConceptoAux.szDesConcepto);

                        stPreFactura.A_PFactura.dImpConcepto  [iNumConceptos] = dImpConcFinal;

                        stPreFactura.A_PFactura.dImpMontoBase [iNumConceptos] = 0.0;
                        stPreFactura.A_PFactura.dImpFacturable[iNumConceptos] = stPreFactura.A_PFactura.dImpConcepto [iNumConceptos];

                        if (!bConverMoneda (stPreFactura.A_PFactura.szCodMoneda [i],
                                            stDatosGener.szCodMoneFact             ,
                                            szSysDate                              ,
                                            &stPreFactura.A_PFactura.dImpFacturable[iNumConceptos],
                                            stProceso.iCodTipDocum))
                            return FALSE;

                        stPreFactura.A_PFactura.dImpFacturable[iNumConceptos] = fnCnvDouble (stPreFactura.A_PFactura.dImpFacturable[iNumConceptos],USOFACT);

                        if (!bfnAplicaRetencion(i, iNumConceptos, iTipoFact))
                        {
                            vDTrazasError(modulo,"\n\t** ERROR, en creacion del concepto de Retencion. **",LOG01);
                            return (FALSE);
                        }

                        strcpy(stPreFactura.A_PFactura.szFecValor [iNumConceptos], stPreFactura.A_PFactura.szFecValor [i]);
                        strcpy(stPreFactura.A_PFactura.szFecEfectividad[iNumConceptos], stPreFactura.A_PFactura.szFecValor [i]);
                    }
                    else
                    {
                        vDTrazasLog(modulo, "\n\t\t* ATENCION: Valor de retencion < 1.0 ...[%f]",LOG05,dImpConcFinal);
                    }
                }
            }
        } /* FIN for de revisi�n de conceptos */
    }

    return TRUE;
}/************************** Final bImptosCliente ****************************/

/*****************************************************************************/
/*                             funcion : bImptosIvaNotas                     */
/* -Funcion que Aplica Impuestos (recogidos en la tabla Fa_HistConc que son  */
/*  en este caso los conceptos Impuestos que se aplicaron a los Conceptos de */
/*  la factura modificada por la Nota que Emitimos. Todos estos Conceptos Im-*/
/*  puestos estan recogidos en la estructura stNota.A_HistConc y los Concep- */
/*  tos sobre los que se aplican se recogen en stPreFactura.A_PFactura.      */
/* -Observacion :                                                            */
/*            * Dos formas de Aplicar Impuestos :                            */
/*              1.- Apartir del fPrcImpuesto de stNota.A_HistConc            */
/*              2.- Apartir de la Categoria Impositiva del Cliente           */
/*            * Hay que tener encuenta que el Concepto no sea una Cuota a la */
/*              cual no se le aplican Impuestos, y ademas que el Concepto so-*/
/*              bre el cual se aplica el Impuesto, en el momento de generar  */
/*              la factura que se modifica con la nota se le aplicaron im-   */
/*              puesto (esto viene indicado por el Campo FlagImpuesto = 1).  */
/*                                                                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bImptosIvaNotas (int iTipoFact)
{
char  modulo[] = "bImptosIvaNotas";

  int  iNumRegIni    = 0    ;
  int  iInd          = 0    ;
  int  i             = 0    ;
  int  iNumConceptos = 0    ;
  int  iNImptos      = 0    ;
  int  iCodZonaImpos = 0    ;
  int  iCodGrpServi  = 0    ;

  IMPTOS   stImpto = {0,(IMPUESTOS *)NULL};
  char     szFecZonaImpo [15]=""          ;
  CONCEPTO stConcepto                     ;

    /* Acumula el total de los impuestos para el ajuste */
    TOTIMPTOS stTotImptos={0,(TOTIMPTO *)NULL};

    if (iTipoFact == FACT_NOTACRED)
        vDTrazasLog (szExeName,"\n\t\t* IMPUESTOS NOTA CREDITO\n"
                               "\t\t=> Cliente [%ld]\n",LOG03,
                               stCliente.lCodCliente);
    else if (iTipoFact == FACT_NOTADEBI)
        vDTrazasLog (szExeName,"\n\t\t* IMPUESTOS NOTA DEBITO \n"
                               "\t\t=> Cliente [%ld]\n",LOG03,
                               stCliente.lCodCliente);

    vDTrazasLog(szExeName,"\n\t\t* Categoria Impositiva del Cliente [%d]",
              			  LOG05,stCliente.iCodCatImpos);

    strcpy (szFecZonaImpo,stNota.szFecEmision);
    iCodZonaImpos= stNota.iCodZonaImpo;
    stPreFactura.iCodZonaImpo=iCodZonaImpos;

    vDTrazasLog (modulo,"\t\t* Zona Impositiva [%d] "
                        "\n\t\t* Fecha Zona Impositiva [%s] "
                        ,LOG06, iCodZonaImpos, szFecZonaImpo);

    iNumRegIni = stPreFactura.iNumRegistros;

    for (i=0;i<iNumRegIni;i++)
    {
        if (stPreFactura.A_PFactura.iFlagImpues  [i] == 1         &&
            stPreFactura.A_PFactura.iCodTipConce [i] != IMPUESTO &&
            stPreFactura.A_PFactura.iIndCuota    [i] <= 0        )
        {

            if (!bGetGrupoServicios (stPreFactura.A_PFactura.iCodConcepto[i],
                                     &iCodGrpServi,szFecZonaImpo,iTipoFact))
                 return FALSE;

            if (iCodGrpServi == ORA_NULL)
            {
                vDTrazasLog (modulo,
                      "\n\t\t* Concepto [%d] NO tiene Grupo Servicios Asociado",
                      LOG03,stPreFactura.A_PFactura.iCodConcepto[i]);
                continue;
            }


            if (!bGetImpuestos (stCliente.iCodCatImpos, iCodZonaImpos,iCodGrpServi,
                                szFecZonaImpo,&stImpto, iTipoFact))
                return FALSE;
            vDTrazasLog (modulo,"\n\t\t* Grupo Servicios [%d]"
                                "\n\t\t* Numero de Impuestos = [%d]",LOG06
                                ,iCodGrpServi,stImpto.iNumImpuestos);

            for (iInd=0;iInd<stImpto.iNumImpuestos;iInd++)
            {
                iNumConceptos = stPreFactura.iNumRegistros;
                if (stPreFactura.iNumRegistros >= MAX_CONCFACTUR)
                {
                    iDError (modulo,ERR035,vInsertarIncidencia);
                    return FALSE;
                }
                if (!bCalculaImptos (i,stImpto.pImpuestos[iInd]))
                     return FALSE;

                stPreFactura.A_PFactura.iCodConcepto[iNumConceptos] =
                                   stImpto.pImpuestos[iInd].iCodConcGene  ;
                memset (&stConcepto,0,sizeof(CONCEPTO))                   ;
                if (!bFindConcepto (stImpto.pImpuestos[iInd].iCodConcGene,
                                    &stConcepto))
                     return FALSE;
                strcpy(stPreFactura.A_PFactura.szDesConcepto[iNumConceptos],
                       stConcepto.szDesConcepto);

                if (!bGetMaxColPreFa
                     (stPreFactura.A_PFactura.iCodConcepto[iNumConceptos],
                      &stPreFactura.A_PFactura.lColumna [iNumConceptos]))
                     return FALSE;

                if (!bfnAplicaImpto(i, iNumConceptos, iTipoFact))
                {
                    vDTrazasError(modulo,"\n\t** ERROR, en cracion del concepto de Impto. **",LOG01);
                    return (FALSE);
                }

                strcpy(stPreFactura.A_PFactura.szFecValor [iNumConceptos],
                       stPreFactura.A_PFactura.szFecValor [i]);

                strcpy(stPreFactura.A_PFactura.szFecEfectividad[iNumConceptos],
                       stPreFactura.A_PFactura.szFecValor [i]);

                stPreFactura.A_PFactura.fPrcImpuesto[iNumConceptos] = stImpto.pImpuestos[iInd].fPrcImpuesto;

                if (!bfnAcumTotImptos (&stTotImptos
                            ,stPreFactura.A_PFactura.iCodConcepto[i]
                            ,stPreFactura.A_PFactura.iCodConcepto[iNumConceptos]
                            ,stPreFactura.A_PFactura.dImpFacturable[i]
                            ,stPreFactura.A_PFactura.dImpFacturable[iNumConceptos]
                            ,stPreFactura.A_PFactura.fPrcImpuesto[iNumConceptos]))
                {
                    vDTrazasError(modulo
                                ,"\n\t**  Error en acumulacion de Impuestos **"
                                ,LOG01);
                    return (FALSE);
                }
                iNImptos++                  ;
            }/* fin for->iInd */
        } /* fin if Condiciones ... */
/*      } */ /* fin for j ... */

        vDTrazasLog (modulo,"\n\t\t[%d]Impuestos aplicados al concepto %d del cliente %ld\n",
                    LOG06,iNImptos,stPreFactura.A_PFactura.iCodConcepto[i],
                    stPreFactura.A_PFactura.lCodCliente [i]);
        vFreeImpuestos(&stImpto);
        iNImptosT += iNImptos;

    }/* fin for i<iNumRegIni */
/******************************************************/
/* Codigo para realizacion de ajuste de IVA.          */
/******************************************************/
    if(stPreFactura.iNumRegistros > 0)
    {
        if (!bfnAjusteImptos(&stTotImptos))
        {
            vDTrazasError(modulo,"\n\t**  Error en proceso de Ajuste de Impuestos **",LOG01);
            return (FALSE);
        }
    }
/******************************************************/

/*****************************************************************************/
/* Codigo para realizacion de ajustes a nivel de abonado PPV 04/10/2006 34216*/
/*****************************************************************************/
if(stPreFactura.iNumRegistros > 0)
{
    if (!bfnValidaAbonados)
    {
        vDTrazasError(modulo,"\n\t**  Error en proceso de Validacion de Abonados **",LOG01);
        return (FALSE);
    }
}
/*****************************************************************************/

    vDTrazasLog (szExeName,"\n\t\t* Cliente [%ld] => Impuestos Aplicados [%d]\n",
               LOG03,stCliente.lCodCliente,iNImptosT);
    return TRUE;
}/**************************** Final bImptosIvaNotas *************************/

/*****************************************************************************/
/*                           funcion : szGetFecZonaImp                       */
/* - Devuelve un puntero a la fecha con la que hay que buscar la zona imposi.*/
/* - Utilizacion de stCiclo estructura global                                */
/*****************************************************************************/
static char *szGetFecZonaImp(int iTipoFact)
{
char *szTmp = "";

    switch(iTipoFact)
    {
        case FACT_NOTACRED   :
        case FACT_NOTADEBI   :
            szTmp = stNota.szFecEmision;
            break;
        case FACT_CICLO      :
            szTmp = stCiclo.szFecEmision;
            break;
        case FACT_RENTAPHONE :
        case FACT_BAJA       :
        case FACT_LIQUIDACION:
        case FACT_ROAMINGVIS :
        case FACT_COMPRA     :
        case FACT_MISCELAN   :
        case FACT_CONTADO    :
            szTmp = szSysDate;
            /* rao : verificar la fecha de FACT_CONTADO */
            break;
        default:
            szTmp = (char *)NULL;
            iDError (szExeName,ERR023,vInsertarIncidencia,iTipoFact);
            return  (char *)NULL;
  }
  vDTrazasLog (szExeName,
               "\t\t* Fecha para la Zona Impositiva [%s]\n",LOG05,szTmp);
  return (char *)(szTmp);
}/*************************** Final szGetFecZonaImp **************************/


/*****************************************************************************/
/*                          funcion : bGetZonaImpositiva                     */
/* -Busca la Zona Impositiva (iCodZonaimpo) en memoria (ZONACIUDAD *),que es */
/*  cargada en el modulo con los reg. de la tabla GE_ZONACIUDAD              */
/* -Entrada szCodMunicipio, piCodZonaimpo, szFecZonaimpo                     */
/* -Salida Error->FALSE, !Error->TRUE                                        */
/*****************************************************************************/
BOOL bGetZonaImpositiva (char *szCodRegion   ,
                                char *szCodProvincia,
                                char *szCodCiudad   ,
                                int  *piCodZonaImpo ,
                                char *szFecZonaImpo ,
                                int   iTipoFact)
{
   ZONACIUDAD stZonaCiudad;
   BOOL bRes = TRUE       ;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static char  szhCodRegion    [4]; /* EXEC SQL VAR szhCodRegion    IS STRING(4) ; */ 

   static char  szhCodProvincia [6]; /* EXEC SQL VAR szhCodProvincia IS STRING(6) ; */ 

   static char  szhCodCiudad    [6]; /* EXEC SQL VAR szhCodCiudad    IS STRING(6) ; */ 

   static char  szhFecDesde     [15]; /* EXEC SQL VAR szhFecDesde    IS STRING(15); */ 

   static char  szhFecHasta     [15]; /* EXEC SQL VAR szhFecHasta    IS STRING(15); */ 

   static int    ihCodZonaImpo  ;
   static char szFormatoFec[17];   /* EXEC SQL VAR szFormatoFec    IS STRING(17) ; */ 

   /* EXEC SQL END DECLARE SECTION  ; */ 


    strcpy(szFormatoFec,"YYYYMMDDHH24MISS");


   memset (&stZonaCiudad,0,sizeof(ZONACIUDAD));

   vDTrazasLog (szExeName,"\n\t\t* Parametros Entrada bGetZonaImpositiva\n"
                          "\t\t=>Cod.Region   [%s]\n"
                          "\t\t=>Cod.Provincia[%s]\n"
                          "\t\t=>Cod.Ciudad   [%s]\n"
                          "\t\t=>Fecha        [%s]\n",
                LOG05,szCodRegion,szCodProvincia,szCodCiudad,szFecZonaImpo);

   if (iTipoFact == FACT_CICLO)
   {
       strcpy (stZonaCiudad.szCodRegion   ,szCodRegion)   ;
       strcpy (stZonaCiudad.szCodProvincia,szCodProvincia);
       strcpy (stZonaCiudad.szCodCiudad   ,szCodCiudad)   ;

       if (!bFindZonaCiudad (szCodRegion,szCodProvincia,
                             szCodCiudad,szFecZonaImpo,piCodZonaImpo))
       {

            /* Si no lo encontramos en memoria buscamos en tabla */
            /* EXEC SQL SELECT /o+ index (GE_ZONACIUDAD PK_GE_ZONACIUDAD) o/
                            COD_ZONAIMPO
                     INTO   :ihCodZonaImpo
                     FROM   GE_ZONACIUDAD
                     WHERE  COD_REGION    = :szCodRegion
                       AND  COD_PROVINCIA = :szCodProvincia
                       AND  COD_CIUDAD    = :szCodCiudad
                       AND  FEC_DESDE <=
                                     TO_DATE(:szFecZonaImpo,:szFormatoFec)
                       AND  FEC_HASTA >=
                                     TO_DATE(:szFecZonaImpo,:szFormatoFec); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 8;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select  /*+  index (GE_ZONACIUDAD PK_GE_ZONACIUDA\
D)  +*/ COD_ZONAIMPO into :b0  from GE_ZONACIUDAD where ((((COD_REGION=:b1 and\
 COD_PROVINCIA=:b2) and COD_CIUDAD=:b3) and FEC_DESDE<=TO_DATE(:b4,:b5)) and F\
EC_HASTA>=TO_DATE(:b4,:b5))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )5;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&ihCodZonaImpo;
            sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szCodRegion;
            sqlstm.sqhstl[1] = (unsigned long )0;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)szCodProvincia;
            sqlstm.sqhstl[2] = (unsigned long )0;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)szCodCiudad;
            sqlstm.sqhstl[3] = (unsigned long )0;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)szFecZonaImpo;
            sqlstm.sqhstl[4] = (unsigned long )0;
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
            sqlstm.sqhstv[6] = (unsigned char  *)szFecZonaImpo;
            sqlstm.sqhstl[6] = (unsigned long )0;
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


            if (SQLCODE)
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,"Ge_ZonaCiudad",
                         szfnORAerror())               ;
                strncpy (stAnomProceso.szObsAnomalia,
                         "No se encontraron Datos en"\
                         " Ge_ZonaCiudad ",sizeof(stAnomProceso.szObsAnomalia));
                bRes = FALSE;
            }
            else
            {
	            strcpy (stZonaCiudad.szFecDesde     , szhFecDesde    );
	            strcpy (stZonaCiudad.szFecHasta     , szhFecHasta    );
	            strcpy (stZonaCiudad.szCodRegion    ,szhCodRegion    );
	            strcpy (stZonaCiudad.szCodProvincia , szhCodProvincia);
	            strcpy (stZonaCiudad.szCodCiudad    ,szhCodCiudad    );

                *piCodZonaImpo = ihCodZonaImpo           ;
                stZonaCiudad.iCodZonaImpo = ihCodZonaImpo;

                if (!bAddZonaCiudad (&stZonaCiudad))
                     bRes = FALSE;
            }
        }
    }
    else
    {
        /* EXEC SQL SELECT /o+ index (GE_ZONACIUDAD PK_GE_ZONACIUDAD) o/
                        COD_ZONAIMPO
                   INTO :ihCodZonaImpo
                   FROM GE_ZONACIUDAD
                  WHERE COD_REGION    = :szCodRegion
                    AND COD_PROVINCIA = :szCodProvincia
                    AND COD_CIUDAD    = :szCodCiudad
                    AND FEC_DESDE <=TO_DATE(:szFecZonaImpo,:szFormatoFec)
                    AND FEC_HASTA >=TO_DATE(:szFecZonaImpo,:szFormatoFec); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select  /*+  index (GE_ZONACIUDAD PK_GE_ZONACIUDAD)  \
+*/ COD_ZONAIMPO into :b0  from GE_ZONACIUDAD where ((((COD_REGION=:b1 and COD\
_PROVINCIA=:b2) and COD_CIUDAD=:b3) and FEC_DESDE<=TO_DATE(:b4,:b5)) and FEC_H\
ASTA>=TO_DATE(:b4,:b5))";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )52;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodZonaImpo;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)szCodRegion;
        sqlstm.sqhstl[1] = (unsigned long )0;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szCodProvincia;
        sqlstm.sqhstl[2] = (unsigned long )0;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szCodCiudad;
        sqlstm.sqhstl[3] = (unsigned long )0;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szFecZonaImpo;
        sqlstm.sqhstl[4] = (unsigned long )0;
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
        sqlstm.sqhstv[6] = (unsigned char  *)szFecZonaImpo;
        sqlstm.sqhstl[6] = (unsigned long )0;
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


        if (SQLCODE)
        {
            iDError (szExeName,ERR000,vInsertarIncidencia,"Ge_ZonaCiudad",
                     szfnORAerror())               ;
            strncpy (stAnomProceso.szObsAnomalia,
                         "No se encontraron Datos en"\
                         " Ge_ZonaCiudad ",sizeof(stAnomProceso.szObsAnomalia));
            bRes = FALSE;
        }
        else
        {
            *piCodZonaImpo = ihCodZonaImpo;
        }
   }
   return (bRes);
}/************************** Final bGetZonaImpositiva ************************/

/*****************************************************************************/
/*                           funcion : bAddZonaCiudad                        */
/* -Funcion que inserta en memoria (ZONACIUDAD* pstZonaCiudad)reg. y aumenta */
/*  en uno el numero de reg. cargados de GE_ZONACIUDAD en (NUM_ZONACIUDAD+1) */
/*  ambos datos son globales al modulo                                       */
/* -Salida Error->FALSE, !Error->TRUE                                        */
/*****************************************************************************/
static BOOL bAddZonaCiudad (ZONACIUDAD* pZona)
{
  BOOL bRes = TRUE;

  if (NUM_ZONACIUDAD >= MAX_ZONACIUDAD)
  {
      vDTrazasLog (szExeName,"\n\t*** Imposible Anadir reg. en pstZonaCiudad"\
                   "=>Desbordamiento (Dimension Actual %d) ***",LOG01,
                   MAX_ZONACIUDAD);
      bRes = FALSE;
  }
  else
  {
      pstZonaCiudad[NUM_ZONACIUDAD].iCodZonaImpo = pZona->iCodZonaImpo      ;

      strcpy (pstZonaCiudad [NUM_ZONACIUDAD].szCodRegion,pZona->szCodRegion);
      strcpy (pstZonaCiudad [NUM_ZONACIUDAD].szCodProvincia,
                                                      pZona->szCodProvincia);
      strcpy (pstZonaCiudad [NUM_ZONACIUDAD].szCodCiudad,pZona->szCodCiudad);
      strcpy (pstZonaCiudad [NUM_ZONACIUDAD].szFecDesde, pZona->szFecDesde) ;
      strcpy (pstZonaCiudad [NUM_ZONACIUDAD].szFecHasta, pZona->szFecHasta) ;

      NUM_ZONACIUDAD += 1;

      qsort (pstZonaCiudad,sizeof(ZONACIUDAD),NUM_ZONACIUDAD,iCmpZonaCiudad);
  }
  return (bRes);

}/************************* Final bAddZonaCiudad *****************************/


/*****************************************************************************/
/*                          funcion : bGetGrupoServicios                     */
/* -Funcion que devuelve el Grupo de Servicios (iCodGrpServi), a partir del  */
/*  concepto (long iCodConcepto) y la Fecha (szFecGrp)                       */
/* -Salida Error->FALSE, !Error->TRUE                                        */
/*****************************************************************************/
static BOOL bGetGrupoServicios (int iCodConcepto,
                                int* piCodGrpServi,char *szFecGrp,
                                int  iTipoFact)
{
  GRPSERCONC stGrpSerConc;
  BOOL       bRes = TRUE ;

  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static char*  szhFecDesde  ; /* EXEC SQL VAR szhFecDesde   IS STRING(15); */ 

  static int    ihCodConcepto;
  static char*  szhFecHasta  ; /* EXEC SQL VAR szhFecHasta   IS STRING(15); */ 

  static char*  szhSysDate   ; /* EXEC SQL VAR szhSysDate    IS STRING(15); */ 

  static int    ihCodGrpServi;
  static char szFormatoFec[17];   /* EXEC SQL VAR szFormatoFec    IS STRING(17) ; */ 

  /* EXEC SQL END DECLARE SECTION  ; */ 


  strcpy(szFormatoFec,"YYYYMMDDHH24MISS");

    szhSysDate    = szFecGrp    ;
    ihCodConcepto = iCodConcepto;

    vDTrazasLog (szExeName, "\n\t\t* Parametros Entrada Grupo Servicios\n"
                            "\t\t=> Cod.Concepto  [%d]\n"
                            "\t\t=> Tipo Factura  [%d]\n"
                            "\t\t=> Fecha         [%s]\n",LOG05,
                            iCodConcepto,iTipoFact,szFecGrp);
    if (iTipoFact == FACT_CICLO)
    {
        if (!bFindGrpSerConc (iCodConcepto,szFecGrp,&stGrpSerConc))
        {
            szhFecDesde= stGrpSerConc.szFecDesde;
            szhFecHasta= stGrpSerConc.szFecHasta;

            /* No se encuentran en memoria se buscan en la tabla */
            /* EXEC SQL SELECT /o+ index (FA_GRPSERCONC PK_FA_GRPSERCONC) o/
                            COD_CONCEPTO                          ,
                            TO_CHAR (FEC_DESDE,:szFormatoFec),
                            COD_GRPSERVI                          ,
                            TO_CHAR (FEC_HASTA,:szFormatoFec)
                     INTO   :ihCodConcepto,
                            :szhFecDesde  ,
                            :ihCodGrpServi,
                            :szhFecHasta
                     FROM   FA_GRPSERCONC
                     WHERE  COD_CONCEPTO = :ihCodConcepto
                       AND  FEC_DESDE <=TO_DATE (:szhSysDate,:szFormatoFec)
                       AND  FEC_HASTA >=TO_DATE (:szhSysDate,:szFormatoFec); */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 11;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select  /*+  index (FA_GRPSERCONC PK_FA_GRPSERCON\
C)  +*/ COD_CONCEPTO ,TO_CHAR(FEC_DESDE,:b0) ,COD_GRPSERVI ,TO_CHAR(FEC_HASTA,\
:b0) into :b2,:b3,:b4,:b5  from FA_GRPSERCONC where ((COD_CONCEPTO=:b2 and FEC\
_DESDE<=TO_DATE(:b7,:b0)) and FEC_HASTA>=TO_DATE(:b7,:b0))";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )99;
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
            sqlstm.sqhstv[1] = (unsigned char  *)szFormatoFec;
            sqlstm.sqhstl[1] = (unsigned long )17;
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
            sqlstm.sqhstv[3] = (unsigned char  *)szhFecDesde;
            sqlstm.sqhstl[3] = (unsigned long )15;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&ihCodGrpServi;
            sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)szhFecHasta;
            sqlstm.sqhstl[5] = (unsigned long )15;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&ihCodConcepto;
            sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)szhSysDate;
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
            sqlstm.sqhstv[9] = (unsigned char  *)szhSysDate;
            sqlstm.sqhstl[9] = (unsigned long )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)szFormatoFec;
            sqlstm.sqhstl[10] = (unsigned long )17;
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



            if (SQLCODE != SQLOK && SQLCODE != SQLNOTFOUND)
            {
                    iDError (szExeName,ERR000,vInsertarIncidencia,
                /*"Select->Fa_GrpSerConc",szfnORAerror()); */ /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */
                "1 Select->Fa_GrpSerConc",szfnORAerror());    /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */
                    bRes = FALSE;
            }
            else
            {
                    if (SQLCODE == SQLOK)
                    {
                        stGrpSerConc.iCodConcepto = ihCodConcepto;
                        stGrpSerConc.iCodGrpServi = ihCodGrpServi;

                        if (!bAddGrpSerConc (&stGrpSerConc))
                            bRes = FALSE;
                    }
                    else
                    {
                        stGrpSerConc.iCodGrpServi = ORA_NULL;
                        /* 20040812 XC-200408110239 Se comenta mensaje confuso */
                /* iDError (szExeName,ERR000,vInsertarIncidencia,"2 Select->Fa_GrpSerConc",szfnORAerror());  */
                        bRes = FALSE;
                    }
            }
        }
    }
    else
    {
        /* EXEC SQL SELECT /o+ index (FA_GRPSERCONC PK_FA_GRPSERCONC) o/
                        COD_GRPSERVI
                   INTO :ihCodGrpServi
                   FROM FA_GRPSERCONC
                  WHERE COD_CONCEPTO = :ihCodConcepto
                    AND FEC_DESDE <=TO_DATE (:szhSysDate,:szFormatoFec)
                    AND FEC_HASTA >=TO_DATE (:szhSysDate,:szFormatoFec); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select  /*+  index (FA_GRPSERCONC PK_FA_GRPSERCONC)  \
+*/ COD_GRPSERVI into :b0  from FA_GRPSERCONC where ((COD_CONCEPTO=:b1 and FEC\
_DESDE<=TO_DATE(:b2,:b3)) and FEC_HASTA>=TO_DATE(:b2,:b3))";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&ihCodGrpServi;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        sqlstm.sqhstv[2] = (unsigned char  *)szhSysDate;
        sqlstm.sqhstl[2] = (unsigned long )15;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szFormatoFec;
        sqlstm.sqhstl[3] = (unsigned long )17;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)szhSysDate;
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
            iDError (szExeName,ERR000,vInsertarIncidencia
                                     ,"Select->Fa_GrpSerConc",szfnORAerror());
            bRes = FALSE;
        }
        stGrpSerConc.iCodGrpServi = ihCodGrpServi;
    }
    if (bRes)
        *piCodGrpServi = stGrpSerConc.iCodGrpServi;
    else
        *piCodGrpServi = ORA_NULL                 ;

    return (bRes);

}/************************ Final bGetGrupoServicios **************************/


/*****************************************************************************/
/*                         funcion : bAddGrpSerConc                          */
/* -Entrada es un reg. de la tabla FA_GRPSERCONC que introducimos en memoria */
/*  en una estructura global (GRPSERCONC* pstGrpSerConc) y aumentamos el con-*/
/*  tador de reg. (NUM_GRPSERCONC) global al modulo.                         */
/* -Salida Error->FALSE, !Error->TRUE                                        */
/*****************************************************************************/
static BOOL bAddGrpSerConc (GRPSERCONC *pGrp)
{
  BOOL bRes = TRUE;

  if (NUM_GRPSERCONC >= MAX_GRPSERCONC)
  {
      vDTrazasLog (szExeName,"\n\t*** Imposible Anadir reg. en pstGrpSerConc"\
                   "=>Desbordamiento (Dimension Actual %d) ***",LOG01,
                   MAX_GRPSERCONC);
      bRes = FALSE;
  }
  else
  {
      pstGrpSerConc [NUM_GRPSERCONC].iCodConcepto = pGrp->iCodConcepto    ;
      pstGrpSerConc [NUM_GRPSERCONC].iCodGrpServi = pGrp->iCodGrpServi    ;

      strcpy (pstGrpSerConc [NUM_GRPSERCONC].szFecDesde, pGrp->szFecDesde);
      strcpy (pstGrpSerConc [NUM_GRPSERCONC].szFecHasta, pGrp->szFecHasta);

      NUM_GRPSERCONC += 1;

      qsort (pstGrpSerConc,NUM_GRPSERCONC,sizeof(GRPSERCONC),iCmpGrpSerConc);
  }
  return (bRes);
}/************************ Final bAddGrpSerConc ******************************/

/*****************************************************************************/
/*                  funcion : bTipoConceptoValido                            */
/* - El concepto no sera valido si se da alguna de las sig. condiciones:     */
/*       Indice Activo    = 0 - Error Concepto pendite de revisar factura    */
/*       tipo de Concepto = Impuesto - Error grave                           */
/*       tipo de Concepto = Descuento y Importe > 0 - Error grave            */
/*       tipo de Concepto = Otro y Importe < 0 - Error grave                 */
/*****************************************************************************/
static BOOL bTipoConceptoValido (int iInd)
{
  CONCEPTO stConcepto;
  BOOL bRes = TRUE   ;


  if (!bFindConcepto (stPreFactura.A_PFactura.iCodConcepto[iInd], &stConcepto))
  {
       iDError (szExeName,ERR021,vInsertarIncidencia,
                "pstConceptos (Fa_Conceptos)");
       strncpy (stAnomProceso.szObsAnomalia,"No se encuentra Concepto",
                strlen (stAnomProceso.szObsAnomalia));
       stAnomProceso.iCodConcepto = stPreFactura.A_PFactura.iCodConcepto[iInd];
       bRes = FALSE;
  }
  else
  {
      if (stConcepto.iIndActivo == 0)
      {
          iDError (szExeName,ERR001,vInsertarIncidencia,
                   stPreFactura.A_PFactura.iCodConcepto[iInd],
                   stConcepto.iIndActivo,stConcepto.iCodTipConce,
                   stPreFactura.A_PFactura.dImpConcepto[iInd]);
          strncpy (stAnomProceso.szObsAnomalia,
                   "Concepto No Valido: Indice activo == 0",
          strlen(stAnomProceso.szObsAnomalia));
          bRes = FALSE;
       }
       else
       {
          if (stConcepto.iCodTipConce == IMPUESTO)
          {
              iDError (szExeName,ERR001,vInsertarIncidencia,
                       stPreFactura.A_PFactura.iCodConcepto[iInd],
                       stConcepto.iIndActivo,stConcepto.iCodTipConce,
                       stPreFactura.A_PFactura.dImpConcepto[iInd]);

              strncpy (stAnomProceso.szObsAnomalia,
                       "Concepto No Valido: Tipo concepto Impuesto",
                       strlen(stAnomProceso.szObsAnomalia))           ;
              stAnomProceso.iCodConcepto =
                       stPreFactura.A_PFactura.iCodConcepto[iInd]     ;
              bRes = FALSE                                            ;
          }
       }
  }/* fin else Find... */
  if (!bRes)
  {
      strcpy (stAnomProceso.szDesProceso,"Impuestos")  ;
      stAnomProceso.lNumProceso = stStatus.IdPro       ;
      stAnomProceso.lNumAbonado = stPreFactura.A_PFactura.lNumAbonado [iInd];
      stAnomProceso.iCodProducto= stPreFactura.A_PFactura.iCodProducto[iInd];
      stAnomProceso.lCodCliente = stCliente.lCodCliente;
  }
  return (bRes);
}/*********************** Final bTipoConceptoValidoGeneral *******************/


/*****************************************************************************/
/*                         funcion : bCalculaImptos                          */
/* -Funcion que Calcula el Impuesto Aplicado a un Conceptos cargado en la es-*/
/*  tructura stPreFactura.A_PFactura.%[iInd], donde iInd el orden del regis- */
/*  al cual se le aplica el Impuesto.                                        */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCalculaImptos (int        iInd,/* Reg sobre el que Aplico Impto*/
                            IMPUESTOS pImpuesto)
{
    int  iNumReg = 0   ;
    BOOL bRes    = TRUE;

    iNumReg = stPreFactura.iNumRegistros;

    if (!bTipoConceptoValido (iInd))
        return FALSE;

    stPreFactura.A_PFactura.dImpConcepto [iNumReg] = (((double)pImpuesto.fPrcImpuesto * stPreFactura.A_PFactura.dImpConcepto[iInd])/100);
    stPreFactura.A_PFactura.dImpMontoBase[iNumReg] = stPreFactura.A_PFactura.dImpConcepto[iInd];
    stPreFactura.A_PFactura.dImpFacturable [iNumReg] = fnCnvDouble(stPreFactura.A_PFactura.dImpConcepto [iNumReg], USOFACT);  /*CH-3451*/

  	vDTrazasLog (szExeName,"\n\t\t IMPORTE CONCEPTO   [%f]"
  						   "\n\t\t IMPORTE FACTURABLE [%f]"
  						   , LOG05, stPreFactura.A_PFactura.dImpConcepto [iNumReg]
  						   , stPreFactura.A_PFactura.dImpFacturable [iNumReg]);

    vDTrazasLog (szExeName,"\n\t\t* Calculo del IVA:\n"
                           "\t\t=> iNumReg        [%d]\n"
                           "\t\t=> iInd           [%d]\n"
                           "\t\t=> Impto. IVA     [%f]\n"
                           "\t\t=> Valor IVA      [%f]\n"
                           "\t\t=> Monto Neto     [%f]\n", LOG05,
                           iNumReg, iInd, pImpuesto.fPrcImpuesto/100,
                           stPreFactura.A_PFactura.dImpConcepto [iNumReg],
                           stPreFactura.A_PFactura.dImpConcepto[iInd]);

    if (!bConverMoneda (stPreFactura.A_PFactura.szCodMoneda    [iInd]   ,
                        stDatosGener.szCodMoneFact                      ,
                        szSysDate                                       ,
                        &stPreFactura.A_PFactura.dImpFacturable[iNumReg],
                        stProceso.iCodTipDocum))
        return FALSE;
    stPreFactura.A_PFactura.dImpFacturable[iNumReg] = fnCnvDouble (stPreFactura.A_PFactura.dImpFacturable[iNumReg],USOFACT);

    vDTrazasLog (szExeName,"\n\t\t* Importes despues del redondeo:\n"
                           "\t\t=> Monto Base:    [%f]\n"
                           "\t\t=> Valor IVA :    [%f]\n", LOG05,
                           stPreFactura.A_PFactura.dImpMontoBase[iNumReg],
                           stPreFactura.A_PFactura.dImpConcepto[iNumReg]);
    return (bRes);
}/**************************  Final bCalculaImptos ***************************/


/*****************************************************************************/
/*                           funcion : bGetImpuestos                         */
/* -Busca en memoria pstImpuesto  (global al modulo) los impuestos para una  */
/*  un mismo iCodCatImpos, iCodZonaimpos, iCodGrpServi, Fecha                */
/*  y los carga en IMPTOS                                                    */
/* -Valores de Retorno : Error->FALSE, !Error->TRUE                          */
/*****************************************************************************/
BOOL bGetImpuestos (int iCodCatImpos, int  iCodZonaImpo,
                    int iCodGrpServi, char *szFecVenc ,
                    IMPTOS* pImpto  , int  iTipoFact)
{
   int  iCount    = 0   ;
   int  iNumImpto = 0   ;
   BOOL bRes      = TRUE;

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   static int   ihCodCatImpos  ;
   static int   ihCodZonaImpo  ;
   static int   ihCodTipImpues ;
   static int   ihCodGrpServi  ;
   static char  szhFecDesde[15]; /* EXEC SQL VAR szhFecDesde    IS STRING(15); */ 

   static char  szhFecHasta[15]; /* EXEC SQL VAR szhFecHasta    IS STRING(15); */ 

   static char* szhFecVencimie ; /* EXEC SQL VAR szhFecVencimie IS STRING(15); */ 

   static int   ihCodConcGene  ;
   static float fhPrcImpuesto  ;
   static char szFormatoFec[17];   /* EXEC SQL VAR szFormatoFec    IS STRING(17) ; */ 

   /* EXEC SQL END DECLARE SECTION  ; */ 


    strcpy(szFormatoFec,"YYYYMMDDHH24MISS");


   vDTrazasLog (szExeName,"\n\t\t* Parametros entrada Ge_Impuestos\n"
                          "\t\t=> Cod.CatImpos   [%d]\n"
                          "\t\t=> Cod.ZonaImpos  [%d]\n"
                          "\t\t=> Cod.Grupo Sev. [%d]\n"
                          "\t\t=> Fec.Vencimie.  [%s]\n",LOG05,
                          iCodCatImpos,iCodZonaImpo,iCodGrpServi,szFecVenc);

   if (iTipoFact == FACT_CICLO)
   {
       while (bRes && iCount<NUM_IMPUESTOS)
       {
            if (pstImpuestos[iCount].iCodCatImpos == iCodCatImpos        &&
                pstImpuestos[iCount].iCodGrpServi == iCodGrpServi        &&
                pstImpuestos[iCount].iCodZonaImpo == iCodZonaImpo        &&
                (strcmp (pstImpuestos[iCount].szFecDesde,szFecVenc)<= 0) &&
                (strcmp (pstImpuestos[iCount].szFecHasta,szFecVenc)>= 0) &&
                pstImpuestos[iCount].fPrcImpuesto >= 0.01)
            {
                if ((pImpto->pImpuestos =
                    (IMPUESTOS*)realloc((IMPUESTOS*)pImpto->pImpuestos,
                    (iNumImpto+1)*sizeof(IMPUESTOS)))==(IMPUESTOS*)NULL)
                {
                    iDError (szExeName,ERR005,vInsertarIncidencia,
                             "bGetImpuesto->pImpto")             ;
                    strncpy (stAnomProceso.szObsAnomalia,
                             "No se ha podido reservar Memoria",
                             strlen(stAnomProceso.szObsAnomalia));
                    bRes = FALSE;
                }
                else
                {
                    memcpy (&pImpto->pImpuestos[iNumImpto],
                            &pstImpuestos[iCount],sizeof(IMPUESTOS));
                    iNumImpto++;
                }
            }
            if (bRes)
                iCount++;
        }/* fin While NUM_IMPUESTOS */
    }
    else
    {
        ihCodCatImpos = iCodCatImpos ;
        ihCodZonaImpo = iCodZonaImpo ;
        ihCodGrpServi = iCodGrpServi ;
        szhFecVencimie= szFecVenc    ;

       /* EXEC SQL DECLARE Cur_Impuestos CURSOR FOR
            SELECT /o+ index (GE_IMPUESTOS PK_GE_IMPUESTOS) o/
                   TO_CHAR (FEC_DESDE,:szFormatoFec),
                   COD_CONCGENE                          ,
                   TO_CHAR (FEC_HASTA,:szFormatoFec),
                   PRC_IMPUESTO
            FROM   GE_IMPUESTOS
            WHERE  COD_CATIMPOS = :ihCodCatImpos
              AND  COD_ZONAIMPO = :ihCodZonaImpo
              AND  COD_GRPSERVI = :ihCodGrpServi
              AND  FEC_DESDE   <= TO_DATE (:szhFecVencimie,:szFormatoFec)
              AND  FEC_HASTA   >= TO_DATE (:szhFecVencimie,:szFormatoFec)
              AND  PRC_IMPUESTO > 0.01; */ 


      /* EXEC SQL OPEN Cur_Impuestos; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 11;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.stmt = sq0005;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )197;
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
      sqlstm.sqhstv[2] = (unsigned char  *)&ihCodCatImpos;
      sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)&ihCodZonaImpo;
      sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqhstv[4] = (unsigned char  *)&ihCodGrpServi;
      sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[4] = (         int  )0;
      sqlstm.sqindv[4] = (         short *)0;
      sqlstm.sqinds[4] = (         int  )0;
      sqlstm.sqharm[4] = (unsigned long )0;
      sqlstm.sqadto[4] = (unsigned short )0;
      sqlstm.sqtdso[4] = (unsigned short )0;
      sqlstm.sqhstv[5] = (unsigned char  *)szhFecVencimie;
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
      sqlstm.sqhstv[7] = (unsigned char  *)szhFecVencimie;
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



      if (SQLCODE != SQLOK)
      {
          iDError (szExeName,ERR000,vInsertarIncidencia,"Open->Ge_Impuestos",
                   szfnORAerror());
          bRes = FALSE;
      }
      iNumImpto = 0;
      while (bRes && SQLCODE == SQLOK)
      {
             /* EXEC SQL FETCH Cur_Impuestos INTO :szhFecDesde  ,
                                               :ihCodConcGene,
                                               :szhFecHasta  ,
                                               :fhPrcImpuesto; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 11;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )248;
             sqlstm.selerr = (unsigned short)1;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)256;
             sqlstm.occurs = (unsigned int  )0;
             sqlstm.sqfoff = (         int )0;
             sqlstm.sqfmod = (unsigned int )2;
             sqlstm.sqhstv[0] = (unsigned char  *)szhFecDesde;
             sqlstm.sqhstl[0] = (unsigned long )15;
             sqlstm.sqhsts[0] = (         int  )0;
             sqlstm.sqindv[0] = (         short *)0;
             sqlstm.sqinds[0] = (         int  )0;
             sqlstm.sqharm[0] = (unsigned long )0;
             sqlstm.sqadto[0] = (unsigned short )0;
             sqlstm.sqtdso[0] = (unsigned short )0;
             sqlstm.sqhstv[1] = (unsigned char  *)&ihCodConcGene;
             sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
             sqlstm.sqhsts[1] = (         int  )0;
             sqlstm.sqindv[1] = (         short *)0;
             sqlstm.sqinds[1] = (         int  )0;
             sqlstm.sqharm[1] = (unsigned long )0;
             sqlstm.sqadto[1] = (unsigned short )0;
             sqlstm.sqtdso[1] = (unsigned short )0;
             sqlstm.sqhstv[2] = (unsigned char  *)szhFecHasta;
             sqlstm.sqhstl[2] = (unsigned long )15;
             sqlstm.sqhsts[2] = (         int  )0;
             sqlstm.sqindv[2] = (         short *)0;
             sqlstm.sqinds[2] = (         int  )0;
             sqlstm.sqharm[2] = (unsigned long )0;
             sqlstm.sqadto[2] = (unsigned short )0;
             sqlstm.sqtdso[2] = (unsigned short )0;
             sqlstm.sqhstv[3] = (unsigned char  *)&fhPrcImpuesto;
             sqlstm.sqhstl[3] = (unsigned long )sizeof(float);
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
                 iDError (szExeName,ERR000,vInsertarIncidencia,
                          "Fetch->Ge_Impuestos",szfnORAerror());
             if (SQLCODE == SQLOK)
             {
                 if ((pImpto->pImpuestos =
                    (IMPUESTOS *)realloc( (IMPUESTOS *)pImpto->pImpuestos,
                    (iNumImpto+1)*sizeof(IMPUESTOS) ) ) == (IMPUESTOS *)NULL)
                 {
                     iDError (szExeName,ERR005,vInsertarIncidencia,
                              "bGetImpuesto->pImpto")             ;
                     strncpy (stAnomProceso.szObsAnomalia,
                              "No se ha podido reservar Memoria",
                              strlen(stAnomProceso.szObsAnomalia));
                     bRes = FALSE;
                  }
                  else
                  {
                     pImpto->pImpuestos[iNumImpto].iCodConcGene =ihCodConcGene;
                     pImpto->pImpuestos[iNumImpto].iCodCatImpos =ihCodCatImpos;
                     pImpto->pImpuestos[iNumImpto].iCodZonaImpo =ihCodZonaImpo;
                     pImpto->pImpuestos[iNumImpto].iCodTipImpues=ihCodTipImpues;
                     pImpto->pImpuestos[iNumImpto].fPrcImpuesto =fhPrcImpuesto;
                     pImpto->pImpuestos[iNumImpto].iCodGrpServi =ihCodGrpServi;

                     strcpy (pImpto->pImpuestos[iNumImpto].szFecDesde,
                             szhFecDesde);
                     strcpy (pImpto->pImpuestos[iNumImpto].szFecHasta,
                             szhFecHasta);
                     iNumImpto++;
                  }
             }
      }/* While sqlcode == sqlok */
      if (bRes && SQLCODE != SQLNOTFOUND)
          bRes = FALSE;
      else
      {
         /* EXEC SQL CLOSE Cur_Impuestos; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 11;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )279;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)256;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


         if (SQLCODE)
         {
             iDError (szExeName,ERR000,vInsertarIncidencia,
                      "Close->Ge_Impuestos",szfnORAerror());
             bRes = FALSE;
         }
      }
   }
   if (bRes)
   {
       pImpto->iNumImpuestos = iNumImpto;
       vPrintImpuestos (pImpto)         ;
   }
   return (bRes);
}/************************** Final bGetImpuestos *****************************/

/*****************************************************************************/
/*                          funcion : vPrintImpuestos                        */
/*****************************************************************************/
void vPrintImpuestos (IMPTOS* pImpto)
{
  int i = 0;

  vDTrazasLog (szExeName,"\n\t\t*** Impuestos ***\n",LOG05);

    for (i=0;i<pImpto->iNumImpuestos;i++)
    {
        vDTrazasLog (szExeName,"\n\t\tCodCatimpos [%d]"
                               "\n\t\tFec.Desde   [%s]"
                               "\n\t\tFec.Hasta   [%s]"
                               "\n\t\tCodZonaimp. [%d]"
                               "\n\t\tCodTipimpues[%d]"
                               "\n\t\tCodGrpServi [%d]"
                               "\n\t\tCodConcGene [%d]"
                               "\n\t\tPrcImpuesto [%f]",LOG05        ,
                               pImpto->pImpuestos[i].iCodCatImpos ,
                               pImpto->pImpuestos[i].szFecDesde   ,
                               pImpto->pImpuestos[i].szFecHasta   ,
                               pImpto->pImpuestos[i].iCodZonaImpo ,
                               pImpto->pImpuestos[i].iCodTipImpues,
                               pImpto->pImpuestos[i].iCodGrpServi ,
                               pImpto->pImpuestos[i].iCodConcGene ,
                               pImpto->pImpuestos[i].fPrcImpuesto) ;
    }/* fin for i */
}/************************** Final vPrintImpuestos ***************************/


/*****************************************************************************/
/*                           funcion : vFreeImpuestos                        */
/* -Libera memoria de la estructura stImptos                                 */
/*****************************************************************************/
void vFreeImpuestos (IMPTOS* pImpto)
{
  if (pImpto->iNumImpuestos != 0)
  {
      pImpto->iNumImpuestos = 0             ;
      free (pImpto->pImpuestos)             ;
      pImpto->pImpuestos = (IMPUESTOS *)NULL;
  }
}/************************** Final vFreeImpuestos ****************************/

/*****************************************************************************/
/*                     funcion : bGeneraCuotas                               */
/* -Funcion que llama al package fa_pac_cuota.p_main_cuota                   */
/* -Valores Retorno : Error->FALSE,!Error->TRUE                              */
/*****************************************************************************/
static BOOL bGeneraCuotas (long  lNumCargo , char *szCodCuota,
                           float fPrcImpues, int   iCodConcepto)
{
  /* EXEC SQL BEGIN DECLARE SECTION; */ 

  static long  lhNumCargo      ;
  static char* szhCodCuota     ; /* EXEC SQL VAR szhCodCuota IS STRING (3); */ 

  static float fhPrcImpuesto   ;
  static int   ihCodConcepto   ;
  /* EXEC SQL END DECLARE SECTION; */ 


  lhNumCargo       = lNumCargo      ;
  szhCodCuota      = szCodCuota     ;
  fhPrcImpuesto    = fPrcImpues     ;
  ihCodConcepto    = iCodConcepto   ;

  vDTrazasLog (szExeName,"\n\t\t*** Generando Cuotas ***\n"
               "\t\tNum.Cargo     [%ld]\n"
               "\t\tCod.Cuota     [%s]\n"
               "\t\tPrc.Impuesto  [%f]\n"
               "\t\tCod.Concepto  [%d]\n",LOG04,
               lhNumCargo,szCodCuota,fPrcImpues,ihCodConcepto);
  /* EXEC SQL EXECUTE
  BEGIN
      fa_pac_cuota.p_main_cuota(:lhNumCargo   ,:szhCodCuota,
                                :fhPrcImpuesto,:ihCodConcepto);
  END;
  END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin fa_pac_cuota . p_main_cuota ( :lhNumCargo , :szhCodCu\
ota , :fhPrcImpuesto , :ihCodConcepto ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )294;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&lhNumCargo;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)szhCodCuota;
  sqlstm.sqhstl[1] = (unsigned long )3;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&fhPrcImpuesto;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&ihCodConcepto;
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
      iDError (szExeName,ERR000,vInsertarIncidencia,
               "\t\tCod.Cuota     [%s]\n"
               "\t\tPrc.Impuesto  [%f]\n"
               "\t\tCod.Concepto  [%d]\n",LOG04,
               szCodCuota,fPrcImpues,ihCodConcepto);

  return (SQLCODE != 0)?FALSE:TRUE;
}/********************** Final bGeneraCuotas *********************************/


static BOOL bfnAcumTotImptos (  TOTIMPTOS *pstTotImptos ,
                                int     iCodConcBase    ,
                                int     iCodConcepto    ,
                                double  dImpMontoBase   ,
                                double  dImpConcepto    ,
                                float   fPrcImpuesto)
{
    int i;
    BOOL bExist=FALSE;

    vDTrazasLog (szExeName, "\n\t\t*** Entrada en %s ***\n"
                            "\t\tiCodConcepto  [%d]\n"
                            "\t\tdImpMontoBase [%f]\n"
                            "\t\tdImpConcepto  [%f]\n"
                            "\t\tfPrcImpuesto  [%f]\n",LOG04, "bfnAcumTotImptos",
                            iCodConcepto,dImpMontoBase,dImpConcepto ,fPrcImpuesto);


    for (i=0;i<MAX_FACTCARRIERS;i++) /* Busqueda del concepto en los conceptos de carrier */
    {
        if (pstFactCarriers[i].iCodConcFact == iCodConcBase )
        {
            vDTrazasLog (szExeName, "\n\t\t* Concepto de Carrier %d no se acumula para el ajuste * "
                        ,LOG05, iCodConcepto);
            return (TRUE);
        }
    }

    for (i=0;i<pstTotImptos->iNumTotImptos;i++)
    {
        if (pstTotImptos->stTotImptos[i].iCodImpto == iCodConcepto &&
            pstTotImptos->stTotImptos[i].fPorcent == fPrcImpuesto )
        {
            bExist = TRUE;
            break;
        }
    }

    if (bExist)
    {
        vDTrazasLog (szExeName, "\n\t\t=>[%d] += dImpMontoBase [%f]"
                                "\n\t\t=>[%d] += dImpConcepto  [%f]", LOG05
                                ,i,dImpMontoBase, i, dImpConcepto);
        pstTotImptos->stTotImptos[i].dTotMBase+=dImpMontoBase;
        pstTotImptos->stTotImptos[i].dTotImpto+=dImpConcepto;
    }
    else
    {
        vDTrazasLog (szExeName, "\n\t\t=>** Se crea nuevo registro de Tot.impuestos **"
                                "\n\t\t=>[%d] += iCodImpto [%d]"
                                "\n\t\t=>[%d] += fPorcent  [%f]"
                                "\n\t\t=>[%d] += dTotMBase [%f]"
                                "\n\t\t=>[%d] += dTotImpto [%f]"
                                , LOG05,i,iCodConcepto
                                ,i,fPrcImpuesto,i,dImpMontoBase, i, dImpConcepto);

        if ((pstTotImptos->stTotImptos =
            (TOTIMPTO*)realloc((TOTIMPTO*)pstTotImptos->stTotImptos,
                               (pstTotImptos->iNumTotImptos+1)*sizeof(TOTIMPTO)))
            ==(TOTIMPTO*)NULL)
        {
            iDError (szExeName,ERR005,vInsertarIncidencia,
                             "pstTotImptos->stTotImptos");
        }

        pstTotImptos->stTotImptos[pstTotImptos->iNumTotImptos].iCodImpto=   iCodConcepto;
        pstTotImptos->stTotImptos[pstTotImptos->iNumTotImptos].fPorcent =   fPrcImpuesto;
        pstTotImptos->stTotImptos[pstTotImptos->iNumTotImptos].dTotMBase=   dImpMontoBase;
        pstTotImptos->stTotImptos[pstTotImptos->iNumTotImptos].dTotImpto=   dImpConcepto;
        pstTotImptos->iNumTotImptos++;

    }
    return (TRUE);
}/****************************** Fin bfnAcumTotImptos ****************************/



static BOOL bfnAjusteImptos (TOTIMPTOS *pstTotImptos)
{
  /* Estuctura para acumular los totales por abonado */
  TOTABON   stTotalesAbon;
    int   	i,x;
    double  dMontoAjuste=0.0;
    int     iCont=0;
  	int     iFlagAjuste =0;
    double  dIvaAcumBase= .0    ;
    BOOL    bExiste=FALSE       ;
    double  dAcuFacturable = 0;
    double  dAcuConceptos  = 0;

    vDTrazasLog (szExeName,"\n\t\t*** Entrada en %s ***\n",LOG04, "bfnAjusteImptos");

    /*****************************************************************************/
    /*  Rutina para calcular los saldos X abonado para realizar el ajuste        */
    /*****************************************************************************/
    memset (&stTotalesAbon,0,sizeof (TOTABON));
    iCont = stPreFactura.iNumRegistros - 1;

    for (i =0; i<=iCont; i++)
    {
        dAcuFacturable  = fnCnvDouble(dAcuFacturable + stPreFactura.A_PFactura.dImpFacturable[i],USOFACT);
        dAcuConceptos   = fnCnvDouble(dAcuConceptos + stPreFactura.A_PFactura.dImpConcepto[i],USOFACT); /* PGG SOPORTE 42917 6-080-2007 */
    }

    if (fnCnvDouble(dAcuConceptos, USOFACT) == fnCnvDouble(dAcuFacturable,USOFACT)) return (TRUE);

    if (stTotalesAbon.iNumAbonados > NUM_ABONADOS_CLIENTE)
    {
        vDTrazasError(szExeName,"\n\t**  Sobrepasado NUM_ABONADOS_CLIENTE **",LOG01);
        vDTrazasLog  (szExeName,"\n\t**  Sobrepasado NUM_ABONADOS_CLIENTE **",LOG01);
        return (FALSE);
    }
    for (i=0;i<=iCont;i++)
    {
        bExiste=FALSE;
        for (x=0;x<stTotalesAbon.iNumAbonados;x++)
        {
            if (stTotalesAbon.stAbon[x].lNumAbonado == stPreFactura.A_PFactura.lNumAbonado[i])
            {
                stTotalesAbon.stAbon[x].dTotFactur  += fnCnvDouble(stPreFactura.A_PFactura.dImpFacturable[i],USOFACT);
                bExiste=TRUE;
                break;
            }
        }
        if (!bExiste)
        {
            x =stTotalesAbon.iNumAbonados;
            stTotalesAbon.stAbon[x].lNumAbonado  = stPreFactura.A_PFactura.lNumAbonado[i];
            stTotalesAbon.stAbon[x].dTotFactur  += fnCnvDouble(stPreFactura.A_PFactura.dImpFacturable[i],USOFACT);
            stTotalesAbon.iNumAbonados++;
        }
    }

    /****************************************************************************/
    for (i=0;i<pstTotImptos->iNumTotImptos;i++) /* Recorre los impuestos */
    {
        dIvaAcumBase = fnCnvDouble(pstTotImptos->stTotImptos[i].dTotMBase * (double)pstTotImptos->stTotImptos[i].fPorcent / 100,USOFACT) ;
        dIvaAcumBase = fnCnvDouble(dIvaAcumBase,USOFACT);
        dMontoAjuste = fnCnvDouble(dIvaAcumBase - pstTotImptos->stTotImptos[i].dTotImpto,USOFACT);

        vDTrazasLog (szExeName, "\n\t\t* MONTO DEL AJUSTE [%f]", LOG04, dMontoAjuste);

        if (dMontoAjuste != 0.0 && (abs(dMontoAjuste) >= pstParamGener.iMtoMinAjuste))
        {
            iFlagAjuste=0;

            vDTrazasLog (szExeName, "\n\t\t* AJUSTE DE IVA "
                                    "\n\t\t=> iCont            : [%d]"
                                    "\n\t\t=> Num. Registros   : [%d]"
                                    "\n\t\t=> Num. Impuestos   : [%d]"
                                    "\n\t\t=> Total Ajuste     : [%f]",
                                    LOG03, iCont, stPreFactura.iNumRegistros, iNImptosT, dMontoAjuste);

            while((iCont >= 0) && (iFlagAjuste != 1))
            {
                if ((stPreFactura.A_PFactura.iCodConcepto[iCont] == pstTotImptos->stTotImptos[i].iCodImpto)  &&
                    (stPreFactura.A_PFactura.fPrcImpuesto[iCont] == pstTotImptos->stTotImptos[i].fPorcent )  &&
                    (stPreFactura.A_PFactura.dImpConcepto[iCont] != 0.0                                  )  &&
                    ((stPreFactura.A_PFactura.dImpFacturable[iCont] > 0 && dMontoAjuste < 0 && fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iCont] + dMontoAjuste),USOFACT) >= 0 ) ||
                    (stPreFactura.A_PFactura.dImpFacturable[iCont] < 0 && dMontoAjuste > 0 && fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iCont] + dMontoAjuste),USOFACT) <= 0 ) ||
                    (stPreFactura.A_PFactura.dImpFacturable[iCont] > 0 && dMontoAjuste > 0 ) ||
                    (stPreFactura.A_PFactura.dImpFacturable[iCont] < 0 && dMontoAjuste < 0 )))
                {
                    if(stPreFactura.A_PFactura.iCodConceRel[iCont] != stDatosGener.iCodAbonoCel)
                    {
                        vDTrazasLog (szExeName, "\n\t\t* Haciendo ajuste del IVA "
                                                "\n\t\t=> Registro            : [%d]"
                                                "\n\t\t=> Concepto            : [%d]"
                                                "\n\t\t=> Descrip. Concepto   : [%s]"
                                                "\n\t\t=> Producto            : [%d]"
                                                "\n\t\t=> Importe Concepto    : [%f]"
                                                "\n\t\t=> Concepto Relacion.  : [%d]"
                                                "\n\t\t=> Importe Facturable  : [%f]",
                                                LOG05,iCont,
                                                stPreFactura.A_PFactura.iCodConcepto  [iCont],
                                                stPreFactura.A_PFactura.szDesConcepto [iCont],
                                                stPreFactura.A_PFactura.iCodProducto  [iCont],
                                                stPreFactura.A_PFactura.dImpConcepto  [iCont],
                                                stPreFactura.A_PFactura.iCodConceRel  [iCont],
                                                stPreFactura.A_PFactura.dImpFacturable[iCont]);

                        /*** Valida que el total del abonado sea >0 */
                        for (x=0;x<stTotalesAbon.iNumAbonados;x++)
                        {
                            if (stTotalesAbon.stAbon[x].lNumAbonado == stPreFactura.A_PFactura.lNumAbonado[iCont]) break;
                        }

                        if (fnCnvDouble(stTotalesAbon.stAbon[x].dTotFactur + dMontoAjuste,USOFACT) >= 0 ) /* CH-200607243796 PPV 21/08/2006 */
                        {
                            vDTrazasLog (szExeName,"\n\t\t* Abonado [%ld] total [%f] ajuste [%f]"
                                                    ,LOG05,stTotalesAbon.stAbon[x].lNumAbonado
                                                    ,stTotalesAbon.stAbon[x].dTotFactur, dMontoAjuste);
                            stPreFactura.A_PFactura.dImpFacturable[iCont] += fnCnvDouble(dMontoAjuste,USOFACT);
                            iFlagAjuste = 1;

                            vDTrazasLog (szExeName, "\n\t\t* Monto del ajuste        : [%f]"
                                                    "\n\t\t* Nuevo importe Concepto  : [%f]"
                                                    "\n\t\t* Nuevo importe Facturable: [%f]",
                                                    LOG05, dMontoAjuste,
                                                    stPreFactura.A_PFactura.dImpConcepto[iCont],
                                                    stPreFactura.A_PFactura.dImpFacturable[iCont]);
                        }
                        else
                        {
                            /* Se aplica como ajuste el remanente de saldo del abonado */
                            stPreFactura.A_PFactura.dImpFacturable[iCont] += fnCnvDouble(((stTotalesAbon.stAbon[x].dTotFactur>0)?stTotalesAbon.stAbon[x].dTotFactur:0),USOFACT);
                            dMontoAjuste -= fnCnvDouble(((stTotalesAbon.stAbon[x].dTotFactur>0)?stTotalesAbon.stAbon[x].dTotFactur:0),USOFACT);

                            vDTrazasLog (szExeName, "\n\t\t*** Ajuste Especial, Total Factura < Ajuste ****"
                                                    "\n\t\t* Total Abonado           : [%f]"
                                                    "\n\t\t* Nuevo importe Concepto  : [%f]"
                                                    "\n\t\t* Nuevo importe facturable: [%f]"
                                                    "\n\t\t* Remanente Ajuste        : [%f]", LOG03,
                                                    stTotalesAbon.stAbon[x].dTotFactur,
                                                    stPreFactura.A_PFactura.dImpFacturable[iCont],
                                                    stPreFactura.A_PFactura.dImpFacturable[iCont],
                                                    dMontoAjuste);
                        }
                    }
                    else    /* El concepto es de cargo basico */
                    {
                        iCont--;
                    }
                } /* Fin if concepto = concepto Impto */
                if(iFlagAjuste != 1) iCont--;
            }   /* Fin while */
            if(iFlagAjuste !=1)
            {
              vDTrazasLog (szExeName, "\n\t\t* No se hizo ajuste de IVA\n", LOG03);
            }
        }   /* Fin if(dMontoAjuste...) */
    } /* Fin For pstTotImptos->iNumTotImptos */

    return(TRUE);

}/************************* Final bfnAjusteImptos ****************************/

/*****************************************************************************/
/*                           funcion : bfnAplicaImpto                        */
/*  Aplica los campos al nuevo concepto de impuesto                          */
/*****************************************************************************/
BOOL bfnAplicaImpto (int iIdxOri, int iIdxFin,int iTipoFact)
{

    stPreFactura.A_PFactura.bOptImpuesto[iIdxFin] = TRUE;

    stPreFactura.A_PFactura.lNumProceso [iIdxFin] =
                    stPreFactura.A_PFactura.lNumProceso [iIdxOri];
    stPreFactura.A_PFactura.lCodCliente [iIdxFin] =
                    stPreFactura.A_PFactura.lCodCliente [iIdxOri];

    if (!bGetMaxColPreFa
            (stPreFactura.A_PFactura.iCodConcepto[iIdxFin],
            &stPreFactura.A_PFactura.lColumna [iIdxFin]))
        return FALSE;

    stPreFactura.A_PFactura.iCodProducto[iIdxFin] =
                    stPreFactura.A_PFactura.iCodProducto [iIdxOri];
    strcpy(stPreFactura.A_PFactura.szCodMoneda [iIdxFin],
                    stPreFactura.A_PFactura.szCodMoneda[iIdxOri]) ;

    switch (iTipoFact)
    {
        case FACT_CICLO      :
        case FACT_BAJA       :
            strcpy (stPreFactura.A_PFactura.szFecValor [iIdxFin],
                    stCiclo.szFecEmision);
            break;
        case FACT_CONTADO    :
        case FACT_COMPRA     :
        case FACT_MISCELAN   :
        case FACT_LIQUIDACION:
        case FACT_RENTAPHONE :
        case FACT_ROAMINGVIS :
            strcpy (stPreFactura.A_PFactura.szFecValor[iIdxFin],
                    szSysDate);
            break;
        default              :
            break;
    }

    strcpy(stPreFactura.A_PFactura.szFecEfectividad[iIdxFin],
                    szSysDate);
    strcpy(stPreFactura.A_PFactura.szCodRegion [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodRegion   [iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodProvincia[iIdxFin],
                    stPreFactura.A_PFactura.szCodProvincia[iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodCiudad [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodCiudad   [iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodModulo [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodModulo   [iIdxOri]);
    stPreFactura.A_PFactura.lCodPlanCom [iIdxFin] =
                    stPreFactura.A_PFactura.lCodPlanCom [iIdxOri];
    stPreFactura.A_PFactura.iIndFactur  [iIdxFin] =
                    stPreFactura.A_PFactura.iIndFactur  [iIdxOri];   /* FACTURABLE;  */
    stPreFactura.A_PFactura.iCodCatImpos[iIdxFin] =
                    stPreFactura.A_PFactura.iCodCatImpos[iIdxOri];
    stPreFactura.A_PFactura.iIndEstado  [iIdxFin] = EST_NORMAL;
    stPreFactura.A_PFactura.iIndEstado  [iIdxOri] = EST_IMPTO ;
    stPreFactura.A_PFactura.iCodTipConce[iIdxFin] = IMPUESTO  ;
    stPreFactura.A_PFactura.lNumUnidades[iIdxFin] =
                    stPreFactura.A_PFactura.lNumUnidades[iIdxOri];  /* Incorporado por PGonzaleg  4-03-2002 */
    stPreFactura.A_PFactura.lCodCiclFact[iIdxFin] = stCiclo.lCodCiclFact;
    stPreFactura.A_Ind.i_lCodCiclFact   [iIdxFin] =
                    (stCiclo.lCodCiclFact == ORA_NULL)?ORA_NULL:SQLOK;
    stPreFactura.A_PFactura.iCodConceRel[iIdxFin] =
                    stPreFactura.A_PFactura.iCodConcepto[iIdxOri];
    stPreFactura.A_PFactura.lColumnaRel [iIdxFin] =
                    stPreFactura.A_PFactura.lColumna    [iIdxOri];
    stPreFactura.A_PFactura.lNumAbonado [iIdxFin] =
                    stPreFactura.A_PFactura.lNumAbonado [iIdxOri];
    stPreFactura.A_Ind.i_lNumAbonado    [iIdxFin] =
                    (stPreFactura.A_PFactura.lNumAbonado[iIdxOri] == ORA_NULL)?-1:0   ;
    strcpy(stPreFactura.A_PFactura.szNumTerminal [iIdxFin],
                    stPreFactura.A_PFactura.szNumTerminal [iIdxOri]);
    stPreFactura.A_Ind.i_szNumTerminal  [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumTerminal[iIdxOri],"")==0)?-1:0;
    stPreFactura.A_PFactura.lCapCode    [iIdxFin] =
                    stPreFactura.A_PFactura.lCapCode   [iIdxOri];
    stPreFactura.A_Ind.i_lCapCode       [iIdxFin] =
                    (stPreFactura.A_PFactura.lCapCode   [iIdxOri]== ORA_NULL)?-1:0    ;
    strcpy(stPreFactura.A_PFactura.szNumSerieMec [iIdxFin],
                    stPreFactura.A_PFactura.szNumSerieMec [iIdxOri]);
    stPreFactura.A_Ind.i_szNumSerieMec           [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumSerieMec[iIdxOri],"")==0)?-1:0;
    strcpy(stPreFactura.A_PFactura.szNumSerieLe  [iIdxFin],
                    stPreFactura.A_PFactura.szNumSerieLe  [iIdxOri]);
    stPreFactura.A_Ind.i_szNumSerieLe            [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumSerieLe [iIdxOri],"")==0)?-1:0;
    stPreFactura.A_PFactura.iFlagImpues  [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.iFlagImpues  [iIdxOri] = 1  ;
    stPreFactura.A_PFactura.iFlagDto     [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.iFlagDto     [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.dValDto      [iIdxFin] = -1 ;
    stPreFactura.A_Ind.i_dValDto         [iIdxFin] = -1 ;
    stPreFactura.A_PFactura.iTipDto      [iIdxFin] = -1 ;
    stPreFactura.A_Ind.i_iTipDto         [iIdxFin] = -1 ;
    stPreFactura.A_PFactura.lNumVenta    [iIdxFin] =
                    stPreFactura.A_PFactura.lNumVenta [iIdxOri];
    stPreFactura.A_Ind.i_lNumVenta       [iIdxFin] =
    (stPreFactura.A_PFactura.lNumVenta   [iIdxOri] == ORA_NULL)?-1:0;

    stPreFactura.A_PFactura.lNumTransaccion[iIdxFin] =
                    stPreFactura.A_PFactura.lNumTransaccion [iIdxOri];
    stPreFactura.A_Ind.i_lNumTransaccion   [iIdxFin] =
                    (stPreFactura.A_PFactura.lNumTransaccion[iIdxOri]==ORA_NULL)?-1:0;
    stPreFactura.A_PFactura.iMesGarantia [iIdxFin] = 0;
    stPreFactura.A_PFactura.iIndAlta     [iIdxFin] = 1;
    stPreFactura.A_PFactura.iIndSuperTel [iIdxFin] = 0;
    stPreFactura.A_PFactura.iNumPaquete  [iIdxFin] =-1;
    stPreFactura.A_Ind.i_iNumPaquete     [iIdxFin] =-1;
    stPreFactura.A_PFactura.iIndCuota    [iIdxFin] = 0;
    stPreFactura.A_PFactura.iNumCuotas   [iIdxFin] = 0;
    stPreFactura.A_PFactura.iOrdCuota    [iIdxFin] = 0;

    stPreFactura.iNumRegistros++;

    return(TRUE);
}


BOOL bfnAplicaRetencion (int iIdxOri, int iIdxFin,int iTipoFact)
{
    stPreFactura.A_PFactura.bOptImpuesto[iIdxFin] = TRUE;

    stPreFactura.A_PFactura.lNumProceso [iIdxFin] =
                    stPreFactura.A_PFactura.lNumProceso [iIdxOri];
    stPreFactura.A_PFactura.lCodCliente [iIdxFin] =
                    stPreFactura.A_PFactura.lCodCliente [iIdxOri];

    if (!bGetMaxColPreFa
            (stPreFactura.A_PFactura.iCodConcepto[iIdxFin],
            &stPreFactura.A_PFactura.lColumna [iIdxFin]))
        return FALSE;

    stPreFactura.A_PFactura.iCodProducto[iIdxFin] =
                    stPreFactura.A_PFactura.iCodProducto [iIdxOri];
    strcpy(stPreFactura.A_PFactura.szCodMoneda [iIdxFin],
                    stPreFactura.A_PFactura.szCodMoneda[iIdxOri]) ;

    switch (iTipoFact)
    {
        case FACT_CICLO      :
        case FACT_BAJA       :
            strcpy (stPreFactura.A_PFactura.szFecValor [iIdxFin],
                    stCiclo.szFecEmision);
            break;
        case FACT_CONTADO    :
        case FACT_COMPRA     :
        case FACT_MISCELAN   :
        case FACT_LIQUIDACION:
        case FACT_RENTAPHONE :
        case FACT_ROAMINGVIS :
            strcpy (stPreFactura.A_PFactura.szFecValor[iIdxFin],
                    szSysDate);
            break;
        default              :
            break;
    }

    strcpy(stPreFactura.A_PFactura.szFecEfectividad[iIdxFin],
                    szSysDate);
    strcpy(stPreFactura.A_PFactura.szCodRegion [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodRegion   [iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodProvincia[iIdxFin],
                    stPreFactura.A_PFactura.szCodProvincia[iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodCiudad [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodCiudad   [iIdxOri]);
    strcpy(stPreFactura.A_PFactura.szCodModulo [iIdxFin]  ,
                    stPreFactura.A_PFactura.szCodModulo   [iIdxOri]);
    stPreFactura.A_PFactura.lCodPlanCom [iIdxFin] =
                    stPreFactura.A_PFactura.lCodPlanCom [iIdxOri];
    stPreFactura.A_PFactura.iIndFactur  [iIdxFin] =
                    stPreFactura.A_PFactura.iIndFactur  [iIdxOri];   /* FACTURABLE;  */
    stPreFactura.A_PFactura.iCodCatImpos[iIdxFin] =
                    stPreFactura.A_PFactura.iCodCatImpos[iIdxOri];
    stPreFactura.A_PFactura.iIndEstado  [iIdxFin] = EST_NORMAL;
    stPreFactura.A_PFactura.iIndEstado  [iIdxOri] = EST_IMPTO ;
    stPreFactura.A_PFactura.iCodTipConce[iIdxFin] = ARTICULO  ;
    stPreFactura.A_PFactura.lNumUnidades[iIdxFin] =
                    stPreFactura.A_PFactura.lNumUnidades[iIdxOri];  /* Incorporado por PGonzaleg  4-03-2002 */
    stPreFactura.A_PFactura.lCodCiclFact[iIdxFin] = stCiclo.lCodCiclFact;
    stPreFactura.A_Ind.i_lCodCiclFact   [iIdxFin] =
                    (stCiclo.lCodCiclFact == ORA_NULL)?ORA_NULL:SQLOK;
    stPreFactura.A_PFactura.iCodConceRel[iIdxFin] =
                    stPreFactura.A_PFactura.iCodConcepto[iIdxOri];
    stPreFactura.A_PFactura.lColumnaRel [iIdxFin] =
                    stPreFactura.A_PFactura.lColumna    [iIdxOri];
    stPreFactura.A_PFactura.lNumAbonado [iIdxFin] =
                    stPreFactura.A_PFactura.lNumAbonado [iIdxOri];
    stPreFactura.A_Ind.i_lNumAbonado    [iIdxFin] =
                    (stPreFactura.A_PFactura.lNumAbonado[iIdxOri] == ORA_NULL)?-1:0   ;
    strcpy(stPreFactura.A_PFactura.szNumTerminal [iIdxFin],
                    stPreFactura.A_PFactura.szNumTerminal [iIdxOri]);
    stPreFactura.A_Ind.i_szNumTerminal  [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumTerminal[iIdxOri],"")==0)?-1:0;
    stPreFactura.A_PFactura.lCapCode    [iIdxFin] =
                    stPreFactura.A_PFactura.lCapCode   [iIdxOri];
    stPreFactura.A_Ind.i_lCapCode       [iIdxFin] =
                    (stPreFactura.A_PFactura.lCapCode   [iIdxOri]== ORA_NULL)?-1:0    ;
    strcpy(stPreFactura.A_PFactura.szNumSerieMec [iIdxFin],
                    stPreFactura.A_PFactura.szNumSerieMec [iIdxOri]);
    stPreFactura.A_Ind.i_szNumSerieMec           [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumSerieMec[iIdxOri],"")==0)?-1:0;
    strcpy(stPreFactura.A_PFactura.szNumSerieLe  [iIdxFin],
                    stPreFactura.A_PFactura.szNumSerieLe  [iIdxOri]);
    stPreFactura.A_Ind.i_szNumSerieLe            [iIdxFin] =
                    (strcmp(stPreFactura.A_PFactura.szNumSerieLe [iIdxOri],"")==0)?-1:0;
    stPreFactura.A_PFactura.iFlagImpues  [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.iFlagImpues  [iIdxOri] = 1  ;
    stPreFactura.A_PFactura.iFlagDto     [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.iFlagDto     [iIdxFin] = 0  ;
    stPreFactura.A_PFactura.dValDto      [iIdxFin] = -1 ;
    stPreFactura.A_Ind.i_dValDto         [iIdxFin] = -1 ;
    stPreFactura.A_PFactura.iTipDto      [iIdxFin] = -1 ;
    stPreFactura.A_Ind.i_iTipDto         [iIdxFin] = -1 ;
    stPreFactura.A_PFactura.lNumVenta    [iIdxFin] =
                    stPreFactura.A_PFactura.lNumVenta [iIdxOri];
    stPreFactura.A_Ind.i_lNumVenta       [iIdxFin] =
    (stPreFactura.A_PFactura.lNumVenta   [iIdxOri] == ORA_NULL)?-1:0;

    stPreFactura.A_PFactura.lNumTransaccion[iIdxFin] =
                    stPreFactura.A_PFactura.lNumTransaccion [iIdxOri];
    stPreFactura.A_Ind.i_lNumTransaccion   [iIdxFin] =
                    (stPreFactura.A_PFactura.lNumTransaccion[iIdxOri]==ORA_NULL)?-1:0;
    stPreFactura.A_PFactura.iMesGarantia [iIdxFin] = 0;
    stPreFactura.A_PFactura.iIndAlta     [iIdxFin] = 1;
    stPreFactura.A_PFactura.iIndSuperTel [iIdxFin] = 0;
    stPreFactura.A_PFactura.iNumPaquete  [iIdxFin] =-1;
    stPreFactura.A_Ind.i_iNumPaquete     [iIdxFin] =-1;
    stPreFactura.A_PFactura.iIndCuota    [iIdxFin] = 0;
    stPreFactura.A_PFactura.iNumCuotas   [iIdxFin] = 0;
    stPreFactura.A_PFactura.iOrdCuota    [iIdxFin] = 0;

    stPreFactura.iNumRegistros++;

    return(TRUE);
}

/*****************************************************************************/
/*                           funcion : bfnEvalZonasImpos                     */
/*    Evalua las zonas impositivas del cliente y la oficina si estas son     */
/*    diferentes se asume la parametrizada en la tabla GED_PARAMETROS con    */
/*    el codigo 5.                                                           */
/*****************************************************************************/
BOOL bfnEvalZonasImpos (char *pszFecZonaImpo, int piTipoFact, int *iCodZonaImpo,
                        int piIndZonaImpCic)
{
    char  szCodRegion    [4]="";
    char  szCodProvincia [6]="";
    char  szCodCiudad    [6]="";
    int   iCodZonaImpoCli;
    int   iCodZonaImpoOfi;
    char  modulo[] = "bfnEvalZonasImpos";
    char  pszCodOficina  [3]="";

    vDTrazasLog  (modulo,"\n\t** stProceso.szCodOficina [%s] **"
                         "\n\t** Tipo documento [%d] **"
                        ,LOG03,stProceso.szCodOficina, piTipoFact);


    if (piTipoFact == FACT_CICLO && piIndZonaImpCic == ZICXOFICLIE)
    {
        strcpy(pszCodOficina,stCliente.szCodOficina);
        strcpy(stProceso.szCodOficina,pszCodOficina);
        if (bfnGetDirOficina (pszCodOficina, szCodRegion, szCodProvincia, szCodCiudad))
        {
            if (bGetZonaImpositiva(szCodRegion   ,
                                   szCodProvincia,
                                   szCodCiudad   ,
                                   &iCodZonaImpoCli, pszFecZonaImpo, piTipoFact))
            {
                *iCodZonaImpo = iCodZonaImpoCli;
            }
            else
            {
                vDTrazasError(modulo,"\n\t** En Zona impositiva del cliente  **",LOG01);
                vDTrazasLog  (modulo,"\n\t** En Zona impositiva del cliente  **",LOG01);
                return FALSE;
            }
        }
        else
        {
            vDTrazasError(modulo,"\n\t** En direccion de la oficina **",LOG01);
            vDTrazasLog  (modulo,"\n\t** En direccion de la oficina **",LOG01);
            return FALSE;
        }
        vDTrazasLog  (modulo,"\n\t** => Codigo de oficina [%s] **"
                             "\n\t** => Zona Impositiva   [%d] **"
                             ,LOG05,pszCodOficina,*iCodZonaImpo);
    }
    else
    {
        if (piTipoFact == FACT_MISCELAN)
        {
            if (!bfnGetDirOfiVend (stProceso.lCodVendedorAgente, pszCodOficina))
            {
                vDTrazasError(modulo,"\n\t** ERROR, al obtener la oficina del vendedor **",LOG01);
                vDTrazasLog  (modulo,"\n\t** ERROR, al obtener la oficina del vendedor **",LOG01);
                return FALSE;
            }
        }
        else
        {
            strcpy(pszCodOficina,stProceso.szCodOficina);
        }

        strcpy(stProceso.szCodOficina,pszCodOficina);

        vDTrazasLog  (modulo,"\n\t** Codigo de oficina [%s] **", LOG05, pszCodOficina);

        if (bfnGetDirOficina (pszCodOficina, szCodRegion, szCodProvincia, szCodCiudad))
        {
            vDTrazasLog  (modulo,"\n\t** => stProceso.szCodOficina [%s], szCodRegion [%s], szCodProvincia [%s], szCodCiudad [%s]**"
                                ,LOG05,stProceso.szCodOficina, szCodRegion, szCodProvincia, szCodCiudad);
            if (bGetZonaImpositiva(szCodRegion   , szCodProvincia, szCodCiudad ,
                                   &iCodZonaImpoOfi, pszFecZonaImpo, piTipoFact))
            {
                if (piTipoFact == FACT_MISCELAN)
                /* TM-200403170575. Si es MISCELANEA entonces se considera la zona impositiva de la oficina del vendedor*/
                {
                  *iCodZonaImpo = iCodZonaImpoOfi;
                }
                else
                {
                    if (bGetZonaImpositiva(stCliente.szCodRegion   ,
                                           stCliente.szCodProvincia,
                                           stCliente.szCodCiudad   ,
                                           &iCodZonaImpoCli, pszFecZonaImpo, piTipoFact))
                    {
                        vDTrazasLog  (modulo,"\n\t** => iCodZonaImpoCli [%d] **",LOG05,iCodZonaImpoCli);
                        if (iCodZonaImpoCli != iCodZonaImpoOfi)
                        {
                            vDTrazasLog  (modulo,"\n\t** diferentes Zonas impositivas se toma la por defento [%d]**"
                                         ,LOG04,pstParamGener.iZonaImpoDefec);
                            *iCodZonaImpo = pstParamGener.iZonaImpoDefec;
                        }
                        else
                        {
                            *iCodZonaImpo = iCodZonaImpoCli;
                        }
                    }
                    else
                    {
                        vDTrazasError(modulo,"\n\t** En Zona impositiva del cliente  **",LOG01);
                        vDTrazasLog  (modulo,"\n\t** En Zona impositiva del cliente  **",LOG01);
                        return FALSE;
                    }
                }
            }
            else
            {
                vDTrazasError(modulo,"\n\t** En Zona impositiva de la oficina **",LOG01);
                vDTrazasLog  (modulo,"\n\t** En Zona impositiva de la oficina **",LOG01);
                return FALSE;
            }
        }
        else
        {
            vDTrazasError(modulo,"\n\t** En direccion de la oficina **",LOG01);
            vDTrazasLog  (modulo,"\n\t** En direccion de la oficina **",LOG01);
            return FALSE;
        }
    }
    return TRUE;
}/*************************** Final bfnEvalZonasImpos ************************/

/*****************************************************************************/
/*                           funcion : bfnGetOficina                         */
/*    Obtiene la region, provinci y ciudad de la oficina pasada              */
/*****************************************************************************/
BOOL bfnGetDirOficina (char *pszCodOficina, char *szCodRegion, char *szCodProvincia, char *szCodCiudad    )
{
char   modulo[] = "bfnGetOficina";

    OFICINA pstOficina;

    vDTrazasLog (modulo, "\n\t\t Cod Oficina: [%s] \n",LOG05,pszCodOficina);


    if (!bfnFindOficina (pszCodOficina, &pstOficina ))
    {
        vDTrazasLog (modulo, "\n\t\t Error Obtener oficina : [%s] \n",LOG01,pszCodOficina);
        return FALSE;
    }

    strcpy(szCodRegion   , pstOficina.szCodRegion);
    strcpy(szCodProvincia, pstOficina.szCodProvincia);
    strcpy(szCodCiudad   , pstOficina.szCodCiudad);


    return (TRUE);


}/*************************** Final bfnGetOficina ****************************/

/*****************************************************************************/
/*                           funcion : bfnGetDirOfiVend                      */
/*    Obtiene la region, provinci y ciudad de la oficina pasada              */
/*****************************************************************************/
BOOL bfnGetDirOfiVend (long lCodVendedor, char *szCodOficina )
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        static long  lhCodVendedor;
        static char  szhCodOficina   [3]; /* EXEC SQL VAR szhCodOficina   IS STRING(3) ; */ 

    /* EXEC SQL END DECLARE SECTION; */ 


    lhCodVendedor=lCodVendedor;

    /* EXEC SQL
        SELECT  COD_OFICINA
          INTO  :szhCodOficina
          FROM  VE_VENDEDORES
         WHERE  COD_VENDEDOR = :lhCodVendedor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_OFICINA into :b0  from VE_VENDEDORES where COD\
_VENDEDOR=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )325;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szhCodOficina;
    sqlstm.sqhstl[0] = (unsigned long )3;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodVendedor;
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
        return FALSE;

    strcpy(szCodOficina,szhCodOficina);

    return (TRUE);

}/************************** Final bfnGetDirOfiVend **************************/


/*****************************************************************************/
/*                    funcion : bfnEvaluaClienteconRetencion                 */
/*****************************************************************************/
BOOL bfnEvaluaClienteconRetencion (long lCodCliente)
{
    char   modulo[] = "bfnEvaluaClienteconRetencion";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int  iCant;
    long lhCodCliente;
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog  (modulo,"\n\t** Entrada en %s  **",LOG04, modulo);

    iCant = 0;
    lhCodCliente = lCodCliente;

    /* EXEC SQL
    SELECT COUNT(1)
      INTO :iCant
     FROM FA_RETCLIENTES_TD
    WHERE COD_CLIENTE = :lhCodCliente
      AND SYSDATE BETWEEN FEC_DESDE AND FEC_HASTA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(1) into :b0  from FA_RETCLIENTES_TD where (C\
OD_CLIENTE=:b1 and SYSDATE between FEC_DESDE and FEC_HASTA)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )348;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&iCant;
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



    if(SQLCODE != SQLOK)
    {
        vDTrazasError(szExeName,"\n\t=> Si el Cliente Aplica Retenci�n [%ld]",LOG01,lhCodCliente);
        return FALSE;
    }

    if (iCant > 0)
        return TRUE;
    else
        return FALSE;
}/*************************** Final bfnEvaluaClienteconRetencion *************************/


static int iOpenConceptosConReten  (void)
{
    char   modulo[] = "iOpenConceptosConReten";

    vDTrazasLog  (modulo,"\n\t** Entrada en [%s]  **",LOG04, modulo);


    /* EXEC SQL DECLARE Cur_ConcReten CURSOR FOR
    SELECT COD_CONCORIGEN,
           COD_CONCRETEN ,
           MTO_UNITARIO  ,
           0
    FROM FA_RETCONCEPTOS_TD
    WHERE SYSDATE BETWEEN FEC_DESDE AND FEC_HASTA; */ 


    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (modulo,"\n\t\t* DECLARE=> FA_RETCONCEPTOS_TD [%d]",LOG05, SQLCODE);
        return(SQLCODE);
    }

    /* EXEC SQL OPEN Cur_ConcReten; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0009;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )371;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (modulo,"\n\t\t* OPEN=> FA_RETCONCEPTOS_TD [%d]",LOG05, SQLCODE);
       return(SQLCODE);
    }
    return SQLCODE;
}/***************************** Final iOpenConceptosConReten  **********************/

static int iFetchConceptosConReten (CONCRETEN_HOSTS *pstHost,int *piNumFilas)
{

    char   *modulo = "iFetchConceptosConReten";

    vDTrazasLog  (modulo,"\n\t** Entrada en [%s]  **",LOG04, modulo);


    *piNumFilas = 0;

    /* EXEC SQL FETCH Cur_ConcReten
    INTO :pstHost->lConcepto_Origen,
         :pstHost->lConcepto_Reten ,
         :pstHost->dMonto_Unitario ,
         :pstHost->dMonto_Total    ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )20000;
    sqlstm.offset = (unsigned int  )386;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)(pstHost->lConcepto_Origen);
    sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[0] = (         int  )sizeof(long);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)(pstHost->lConcepto_Reten);
    sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
    sqlstm.sqhsts[1] = (         int  )sizeof(long);
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)(pstHost->dMonto_Unitario);
    sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[2] = (         int  )sizeof(double);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)(pstHost->dMonto_Total);
    sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[3] = (         int  )sizeof(double);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
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



    if (SQLCODE==SQLOK)
        *piNumFilas = TAM_HOSTS;
    else
        if (SQLCODE==SQLNOTFOUND)
            *piNumFilas = sqlca.sqlerrd[2] % TAM_HOSTS;

    return SQLCODE;
}/***************************** Final iFetchConceptosConReten ****************/

int ifnCmpConceptosConReten(const void *cad1,const void *cad2)
{
        return ( ((CONCRETEN *)cad1)->lConcepto_Origen -  ((CONCRETEN *)cad2)->lConcepto_Origen );

}/***************************** Final ifnCmpConceptosConReten ****************/

int ifnCloseConceptosConReten (void)
{
    char   modulo[] = "ifnCloseConceptosConReten";

    /* EXEC SQL CLOSE Cur_ConcReten; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )417;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(SQLCODE != SQLOK)
    {
        vDTrazasLog  (modulo,"\n\t\t* CLOSE=> FA_RETCONCEPTOS_TD [%d]",LOG05, SQLCODE);
        return SQLCODE;
    }

    return SQLCODE;
}/**************************** Final ifnCloseConceptosConReten ******************/

/*****************************************************************************/
/*                    funcion : bfnCargaConceptosConRetencion                 */
/*****************************************************************************/
BOOL bfnCargaConceptosConRetencion (CONCRETEN **pstConc, int *iCantConcRetencion)
{
    char      modulo[] = "bfnCargaConceptosConRetencion";
    int       rc=0;
    int       iNumFilas=0;
    static    CONCRETEN_HOSTS stConcRetenHost;
    CONCRETEN *pstConcRetenTemp;
    long      lCont;

    vDTrazasLog  (modulo,"\n\t** Entrada en [%s]  **",LOG04, modulo);

    *iCantConcRetencion = 0;
    *pstConc = NULL;

    if (iOpenConceptosConReten ())
    {
        vDTrazasLog  (modulo,"\n\t** En funcion iOpenConceptosConReten() .**",LOG01);
        return FALSE;
    }


    while (rc != SQLNOTFOUND)
    {
        rc = iFetchConceptosConReten (&stConcRetenHost,&iNumFilas);

        vDTrazasLog  (modulo,"\n\t** iNumFilas [%d] SQLOK [%d] SQLNOTFOUND [%d] RC [%ld]**",LOG06,iNumFilas, SQLOK,SQLNOTFOUND, rc);

        if (rc != SQLOK  && rc != SQLNOTFOUND)
            return FALSE;

        vDTrazasLog  (modulo,"\n\t** Secuencia de Fetch [%d]**",LOG06,iNumFilas);

        if (!iNumFilas)
            break;

        *pstConc =(CONCRETEN*) realloc(*pstConc,(((*iCantConcRetencion)+iNumFilas)*sizeof(CONCRETEN)));

        if (!*pstConc)
        {
            vDTrazasLog  (modulo,"\n\t** En realloc para estructura de Conceptos de retencion.**",LOG01);
            return FALSE;
        }

        pstConcRetenTemp = &(*pstConc)[(*iCantConcRetencion)];
        memset(pstConcRetenTemp, 0, sizeof(CONCRETEN)*iNumFilas);
        for (lCont = 0 ; lCont < iNumFilas ; lCont++)
        {
            pstConcRetenTemp[lCont].lConcepto_Origen = stConcRetenHost.lConcepto_Origen[lCont];
            pstConcRetenTemp[lCont].lConcepto_Reten  = stConcRetenHost.lConcepto_Reten [lCont];
            pstConcRetenTemp[lCont].dMonto_Unitario  = stConcRetenHost.dMonto_Unitario [lCont];
            pstConcRetenTemp[lCont].dMonto_Total     = stConcRetenHost.dMonto_Total    [lCont];
        }
        (*iCantConcRetencion) += iNumFilas;
    }/* fin while */

    vDTrazasLog  (modulo,"\n\t** Cantidad de Conceptos con Retencion Cargados :[%d]  **",LOG06, *iCantConcRetencion);

    rc = ifnCloseConceptosConReten();
    if (rc != SQLOK)
    {
        vDTrazasLog  (modulo,"\n\t** En funcion iOpenConceptosConReten() .**",LOG01);
        return FALSE;
    }

    qsort((void*)*pstConc, *iCantConcRetencion, sizeof(CONCRETEN),ifnCmpConceptosConReten);

    vDTrazasLog  (modulo,"\n\t** Cantidad de Conceptos con Retencion Cargados :[%d] - Ordenados **",LOG06, *iCantConcRetencion);
    return TRUE;
}/************************** Final bfnCargaConceptosConRetencion ****************************/


/*****************************************************************************/
/*                    funcion : bfnFindConceptosConRetencion                 */
/*****************************************************************************/
BOOL bfnFindConceptosConRetencion (long lCodConcepto, CONCRETEN *stConcRetenPaso)
{
    char       modulo[] = "bfnFindConceptosConRetencion";
    CONCRETEN  stkey;
    CONCRETEN  *pstAux = (CONCRETEN *)NULL;

    vDTrazasLog  (modulo,"\n\t** Entrada en [%s]  **",LOG04, modulo);

    stkey.lConcepto_Origen = lCodConcepto;

    if ( (pstAux = (CONCRETEN *)bsearch(&stkey, pstConcReten.stConcRetencion, pstConcReten.iCantConcRetencion,
                                    sizeof (CONCRETEN),ifnCmpConceptosConReten )) == (CONCRETEN *)NULL)
    {
        vDTrazasLog  (modulo,"\n\t** bfnFindConceptosConRetencion - No se encuentra Concepto: [%ld]  **",LOG05, stkey.lConcepto_Origen);
        return(FALSE);
    }
    memcpy (stConcRetenPaso, pstAux, sizeof(CONCRETEN));
    return(TRUE);
}/************************** Final bfnFindConceptosConRetencion ****************************/

/* PPV 34216 05/10/2006 : Nueva rutina (bfnValidaAbonados) para validar a nivel de abonados saldos negativos generados en calculo del iva */
static BOOL bfnValidaAbonados()
{

  /* Estuctura para acumular los totales por abonado */
  TOTABON stTotalesAbon;
    int  i,x;
    long  iCont=0;
    double  dAcuImpFact=0.0;
    double  dAcuImpConc=0.0;
    double  dAcuImpFactC=0.0;
    double  dAcuImpConcC=0.0;
    double  dAcuImpFactI=0.0;
    double  dAcuImpConcI=0.0;

    vDTrazasLog (szExeName,"\n\t\t*** Entrada en %s ***\n",LOG04, "bfnValidaAbonados");

    /***********************************************/
    /*  Rutina para calcular los saldos X abonado  */
    /***********************************************/
    memset (&stTotalesAbon,0,sizeof (TOTABON));
    iCont = stPreFactura.iNumRegistros - 1;

    /* Llenar array con abonados de la factura*/

    for (x=0;x<stTotalesAbon.iNumAbonados;x++)  /* Recorre abonados*/
    {
      for (i=0;i<=iCont;i++) /* Recorre la factura*/
        {
            if (stTotalesAbon.stAbon[x].lNumAbonado == stPreFactura.A_PFactura.lNumAbonado[i])
            {
                dAcuImpFact += stPreFactura.A_PFactura.dImpFacturable[i];
                dAcuImpConc += stPreFactura.A_PFactura.dImpConcepto[i];
                if (stPreFactura.A_PFactura.iCodTipConce[i] != IMPUESTO )
                {
                    dAcuImpFactC += stPreFactura.A_PFactura.dImpFacturable[i];
                  dAcuImpConcC += stPreFactura.A_PFactura.dImpConcepto[i];
                }
                else
                {
                  dAcuImpFactI += stPreFactura.A_PFactura.dImpFacturable[i];
                  dAcuImpConcI += stPreFactura.A_PFactura.dImpConcepto[i];
                }
            }
        } /* Fin for recorre la factura */

        /* Si el monto es negativo, solo por 1 peso, y exclusivamente en el IVA, o sea los cargos afectos son cero,
           entonces el facturador debe ajustar dicho IVA directamente y dejarlo en cero para corregir el problema de redondeo. */
        if ( (dAcuImpFact>=-1) && (dAcuImpFact<0) && (dAcuImpFactC = 0))
        {
        /* Ajusta el iva a 0 */
        for (i=0;i<=iCont;i++)  /* Recorre la factura*/
          {
              if ((stTotalesAbon.stAbon[x].lNumAbonado == stPreFactura.A_PFactura.lNumAbonado[i]) && (stPreFactura.A_PFactura.iCodTipConce[i] == IMPUESTO))
              {
                vDTrazasLog (szExeName,"\n\t* Ajuste Realizado al abonado [%l] , Concepto [%i] por un valor de [%d] *\n"
                                         ,LOG03, stPreFactura.A_PFactura.lNumAbonado[i], stPreFactura.A_PFactura.iCodConcepto[i], stPreFactura.A_PFactura.dImpFacturable[i]*-1 );
                stPreFactura.A_PFactura.dImpFacturable[i] = 0.0;
            }
        }  /* Fin for recorre la factura */
        }
    } /* Fin for recorre abonados */

    return(TRUE);

}/************************* Final bfnValidaAbonados ****************************/

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
