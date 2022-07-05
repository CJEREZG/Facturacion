
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
    "./pc/PlanDcto.pc"
};


static unsigned int sqlctx = 3459763;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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
"select NUM_SECUENCIA ,NVL(NUM_ABONADO,0) ,COD_PLANDESC ,TIP_ENTIDAD  from GA\
T_PLANDESCABO where (COD_CLIENTE=:b0 and (COD_CICLFACT=:b1 or COD_CICLFACT=0))\
 order by NUM_ABONADO            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,2,69,0,261,522,0,0,2,2,0,1,0,1,4,0,0,1,3,0,0,
28,0,0,3,69,0,261,557,0,0,2,2,0,1,0,1,4,0,0,1,3,0,0,
51,0,0,4,79,0,261,591,0,0,3,3,0,1,0,1,97,0,0,1,4,0,0,1,97,0,0,
78,0,0,1,187,0,265,693,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
101,0,0,1,0,0,269,710,0,0,4,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
132,0,0,1,0,0,271,774,0,0,0,0,0,1,0,
147,0,0,5,363,0,260,813,0,0,10,2,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,4,0,0,1,97,0,0,1,97,0,0,
202,0,0,6,173,0,260,1015,0,0,5,2,0,1,0,2,3,0,0,2,9,0,0,2,4,0,0,1,3,0,0,1,5,0,0,
237,0,0,7,156,0,260,1101,0,0,4,2,0,1,0,2,3,0,0,2,3,0,0,1,3,0,0,1,5,0,0,
268,0,0,8,216,0,260,1189,0,0,7,2,0,1,0,2,4,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
1,3,0,0,1,5,0,0,
311,0,0,9,100,0,260,1510,0,0,3,2,0,1,0,1,97,0,0,1,97,0,0,2,3,0,0,
338,0,0,10,108,0,261,2586,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
361,0,0,11,100,0,260,2944,0,0,3,2,0,1,0,1,97,0,0,1,97,0,0,2,3,0,0,
};


/****************************************************************************/
/*  Fichero     : PlanDcto.pc                                               */
/*  Descripcion : Planes de Descuento                                       */
/*  Autor       : Guido Antio Cares                                         */
/****************************************************************************/
/*  Modif       : RAO031001                                                 */
/*                Se habilta el proceso de planes de Dcto por abonados      */
/****************************************************************************/
/*  Modif       : RAO050102                                                 */
/*                Se habilta el proceso de planes de Dcto por Grupo         */
/****************************************************************************/
/*  Modif   : PGonzaleg 4-03-2002                                           */
/*        Cambio del tipo de datos para el campo NumUnidades                */
/*        int ---> long                                                     */
/****************************************************************************/
/*  Modif   : PGonzaleg 26-09-2002                                          */
/*        Cambio del campo dImpFacturable a dImpConcepto en funcion         */
/*        bAplicacionConceptosCliente                                       */
/****************************************************************************/
/****************************************************************************/
/*  Modif   : Ncontreras 5-08-2003                                          */
/*        Cambio en rutina bfnDescporConceptoAbonado                        */
/*        Se corrigen condiciones de aplicacion de descuentos               */
/****************************************************************************/

#define _DESCUENTOS_PC_

#include "PlanDcto.h"

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

    long     lhCodCliente                    ;
    long     lhCodCiclFact                   ;


/* EXEC SQL END DECLARE SECTION  ; */ 


/* EXEC SQL DECLARE Cur_GatPlanDesc CURSOR for
    SELECT NUM_SECUENCIA       ,
           NVL(NUM_ABONADO,0)  ,
           COD_PLANDESC        ,
           TIP_ENTIDAD
      FROM GAT_PLANDESCABO
     WHERE COD_CLIENTE  = :lhCodCliente
       AND (COD_CICLFACT = :lhCodCiclFact OR COD_CICLFACT = 0)
     ORDER BY NUM_ABONADO; */ 


char szEntidad[9];
long lgAbonado;
double dMontoEvalDcto_aux=0;

/*****************************************************************************/
/*  Funcion : bfnDescuentos                                                  */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
access BOOL bfnDescuentos (long lCliente, char *szFecParam)
{
    char   modulo[]             = "bfnDescuentos" ;
    double dTotalMontoPrefactura= 0.0 ;
    int    ind_Abo, ind_Plan, x;

    int     i, j;           /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    lConceptoCargo;         /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    lColumnaCargo ;         /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    dImporteCargo ;         /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    dAjuste;                /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    dMtoDesc;               /* PGG SOPORTE 21-10-2005 CH-200510173170 */
    long    sw;                     /* PGG SOPORTE 21-10-2005 CH-200510173170 */

    vDTrazasLog (modulo,"\n\t\t*--> Plan de Descuento : Version %s Fecha Version %s.<---- *****"
                 ,LOG05,NUM_VERSION,FECHA_VERSION);

    stAnomProceso.lNumProceso  = stStatus.IdPro       ;
    stAnomProceso.lCodCliente  = stCliente.lCodCliente;
    stAnomProceso.lCodCiclFact = stCiclo.lCodCiclFact ;
    stAnomProceso.iCodConcepto = -1                   ;
    strcpy (stAnomProceso.szDesProceso ,"Descuentos") ;
    strcpy (stAnomProceso.szObsAnomalia,"")           ;
    indGrupo=0; /* INDICADOR DE PLANES GRUPALES */

    memset (&stPlanesDesc   ,0,sizeof (REGPLANES));
    memset (&stValDesc      ,0,sizeof (DESCUENTOS));
    memset (&stPlanesGrupo  ,0,sizeof (PLANESGRUPALES));

    if( !bfnCargaPlanDesc(lCliente) )
    {
        vDTrazasLog(modulo,"*** No se cargo Plan de Descuento para cliente [%ld] ***",LOG05,lCliente);
        return(FALSE);
    }


    idxDesc =0; /* INDICE DE LA ESTRUCTURA DE DESCUENTOS */

    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
        vDTrazasLog (modulo,"\n\t\t*--> Abonado [%ld] con [%d] Planes de Descuento.<---- *****"
                     ,LOG04,stPlanesDesc.stAbonado[ind_Abo].lNumAbonado,stPlanesDesc.stAbonado[ind_Abo].iNumPlanes);

        for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
        {
            if( !bfnCargaDatosPlan  ( szFecParam
                                      , &stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD
                                      , stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szCod_Plandesc ) )
            {
                vDTrazasLog(modulo,"*** No se cargaron datos de Plan de Descuento %s para cliente %ld ***",LOG05,stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szCod_Plandesc,lCliente);
                return(FALSE);
            }
            else
            {
                /* Incidencia CH-1403 : Correccion a la marcacion de estado de la BPT_BENEFICIO a estado 'EJE' para los
                                        descuentos de tipo 'A' y 'C'. */
                vDTrazasLog (modulo,"\n\t\t ModifBeneficios Entidad A o C Cli[%ld] Sec [%ld], Entidad[%s] ",LOG05,
                             stCliente.lCodCliente,
                             stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.lNumSecuencia,
                             stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad);

                if( !bModifBeneficios ( stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.lNumSecuencia) )
                {
                    vDTrazasLog (modulo,"\n\t\t ModifBeneficios Entidad A o C RETURN FALSE. ",LOG03);
                    return(FALSE);
                }
            }


            if( strlen(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szCod_Plandesc)==0 )  /*  Clientes Sin Plan de Descuento  */
                return(TRUE);

            /*rutina para mostrar registros de evaluacion*/
            vPrintPlanDcto (&stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD);

        }
    }

    /*Validar monto */
    dTotalMontoPrefactura = dValidaMontoMinimo();
    /* y actualiza remanentes de cargo */
    dTotalMontoPrefacDesc = dActualizaDescuentos();

    vDTrazasLog (modulo,"\t\tTotal Monto Prefactura por [%f] ",LOG05,dTotalMontoPrefactura);


    if( indGrupo == 1 )/* Procesa Planes Grupales si existen */
    {
        vDTrazasLog (modulo,"\t\t** Planes Grupales **",LOG04);

        if( !bfnCargaPlanesGrupo () ) /* Carga a la estructura los Planes Grupo */
        {
            vDTrazasLog(modulo,"*** No se cargaron Planes de Descuento por Grupo para cliente [%ld] ***",LOG05,lCliente);
            return(FALSE);
        }

        if( !bfnDescporGrupo ( szFecParam, dTotalMontoPrefactura ) )
        {
            vDTrazasLog(modulo,"*** No se realizo Descuentos por Grupo para cliente [%ld] ***",LOG05,lCliente);
            return(FALSE);
        }

    }


    /* DESCUENTOS X CONCEPTO ABONADO*/
    vDTrazasLog(modulo,"DESCUENTOS X CONCEPTO ABONADO cliente [%d] con [%d] Abonados",LOG05,lCliente, stPlanesDesc.iNumAbonados);

    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
        if( stPlanesDesc.stAbonado[ind_Abo].lNumAbonado > -1 )
        {
            lgAbonado=stPlanesDesc.stAbonado[ind_Abo].lNumAbonado;
            for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
            {
                if( strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.szCod_Tipapli,PORCONCEPTO)== 0
                    && strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad,TIPOENTABONA)     == 0 )
                {
                    strcpy( szEntidad,stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad);
                    if( !bfnDescporConceptoAbonado  (stPlanesDesc.stAbonado[ind_Abo].lNumAbonado
                                                     ,&stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD
                                                     ,szFecParam, dTotalMontoPrefactura) )
                    {
                        vDTrazasLog(modulo,"*** No se realizaron Descuentos por Concepto/Abonado cliente %ld ***",LOG05,lCliente);
                        return(FALSE);
                    }
                }
            }
        }
    }


    /* DESCUENTOS X FACTURA ABONADO*/
    vDTrazasLog(modulo,"DESCUENTOS X FACTURA ABONADO cliente [%d] con [%d] Abonados",LOG05,lCliente, stPlanesDesc.iNumAbonados);
    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
		vDTrazasLog(modulo,"PASO EL FOR INDICADOR ABONADO [%d]",LOG05,stPlanesDesc.stAbonado);
       	if( stPlanesDesc.stAbonado[ind_Abo].lNumAbonado > -1)
        {
         	vDTrazasLog(modulo,"PASO EL IF para evaluar abonado -1",LOG05);
            lgAbonado=stPlanesDesc.stAbonado[ind_Abo].lNumAbonado;
            for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
            {
            	vDTrazasLog(modulo,"PASO EL FOR INDICADOR DEL PLAN",LOG05);
                if( strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.szCod_Tipeval,PORFACTURA) == 0
                    && strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad, TIPOENTABONA)    == 0 )
                {
                	vDTrazasLog(modulo,"PASO EL IF INDICADOR DEL PLANDESC del abonado",LOG05);

                    strcpy( szEntidad,stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad);
                    if( !bfnDescporConceptoAbonado  (stPlanesDesc.stAbonado[ind_Abo].lNumAbonado
                                                     ,&stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD
                                                     ,szFecParam, dTotalMontoPrefactura) )
                    {
                        vDTrazasLog(modulo,"*** No se realizaron Descuentos por Factura/Abonado cliente [%ld] ***",LOG03,lCliente);
                        return(FALSE);
                    }
                }
            }
        }
    }

    /* DESCUENTOS X CONCEPTO CLIENTE*/
    vDTrazasLog(modulo,"DESCUENTOS X CONCEPTO CLIENTE cliente [%d] con [%d] Abonados",LOG05,lCliente, stPlanesDesc.iNumAbonados);
    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
        if( stPlanesDesc.stAbonado[ind_Abo].lNumAbonado == -1
            || stPlanesDesc.stAbonado[ind_Abo].lNumAbonado == 0 )
        {
            lgAbonado=stPlanesDesc.stAbonado[ind_Abo].lNumAbonado;
            for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
            {
                if( strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.szCod_Tipapli,PORCONCEPTO)==0
                    && strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad, TIPOENTCLIEN)    == 0 )

                {
                    strcpy( szEntidad,stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad);
                    if( !bfnDescporConceptoCliente  (stPlanesDesc.stAbonado[ind_Abo].lNumAbonado
                                                     ,&stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD
                                                     ,szFecParam, dTotalMontoPrefactura) )
                    {
                        vDTrazasLog(modulo,"*** No se realizaron Descuentos por Concepto/Cliente [%ld] ***",LOG05,lCliente);
                        return(FALSE);
                    }
                }
            }
        }
    }

    vDTrazasLog (modulo,"\n\t4 Nro Descuentos [%ld]",LOG04, stValDesc.iNumDescuentos);
    /* DESCUENTOS X FACTURA CLIENTE */
    vDTrazasLog(modulo,"DESCUENTOS X FACTURA CLIENTE cliente [%d] con [%d] Abonados",LOG05,lCliente, stPlanesDesc.iNumAbonados);
    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
        lgAbonado=stPlanesDesc.stAbonado[ind_Abo].lNumAbonado;
        for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
        {
            if( strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.szCod_Tipeval,PORFACTURA) == 0
                && strcmp(stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad, TIPOENTCLIEN)    == 0 )
            {
                strcpy( szEntidad,stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].szTipEntidad);
                if( !bfnDescporFacturaCliente (stPlanesDesc.stAbonado[ind_Abo].lNumAbonado
                                               ,&stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD
                                               ,szFecParam, dTotalMontoPrefactura) )
                {
                    vDTrazasLog(modulo,"*** No se realizaron Descuentos por Factura/Cliente [%ld] ***",LOG05,lCliente);
                    return(FALSE);
                }
            }
        }
    }



    /* Aplica Dctos. a stPrefactura */
    vDTrazasLog (modulo,"\n\tNro Descuentos [%ld]",LOG04, stValDesc.iNumDescuentos);

    for( x=0;x < stValDesc.iNumDescuentos;x++ )
    {
        vDTrazasLog (modulo,"\n\t Descuentos #[%d]=[%c%.02lf] [%lf] [%d] [%s]",LOG05, x,
					         (stValDesc.stDescuentos[x].szTip_Descuento[0]=='P'?'%':'$'),
					         stValDesc.stDescuentos[x].dVal_Descuento,
					         stValDesc.stDescuentos[x].dValor_Monto,
					         stValDesc.stDescuentos[x].iCod_Concepto,
					         stValDesc.stDescuentos[x].szDescConcepto);
        if( !bCargaPreFactura ( stPreFactura.iNumRegistros, &stValDesc.stDescuentos[x]) )
        {
            vDTrazasLog(modulo,"*** No se Cargo prefactura cliente [%ld] ***",LOG05,lCliente);
            return(FALSE);
        }
    }



    for (i=0; i < stPreFactura.iNumRegistros; i++)
    {
        if ((stPreFactura.A_PFactura.iCodTipConce[i] != 1) &&   /* 1 = IMPUESTOS */
            (stPreFactura.A_PFactura.iCodTipConce[i] != 2))     /* 2 = DESCUENTOS */

        {
            lConceptoCargo  = stPreFactura.A_PFactura.iCodConcepto  [i];
            lColumnaCargo   = stPreFactura.A_PFactura.lColumna      [i];
            dImporteCargo   = stPreFactura.A_PFactura.dImpConcepto  [i];

            dMtoDesc = 0;
            sw = 0;
            for(j = 0; j < stPreFactura.iNumRegistros; j++)
            {
                if (stPreFactura.A_PFactura.iCodTipConce[j] == 2)   /* 2 = DESCUENTOS */
                {
                    if ((lConceptoCargo == stPreFactura.A_PFactura.iCodConceRel[j]  ) &&
                        (lColumnaCargo  == stPreFactura.A_PFactura.lColumnaRel [j]  ))
                    {

                        if (sw == 1)
                        {
                            stPreFactura.A_PFactura.dImpConcepto    [j] = 0;
                            stPreFactura.A_PFactura.dImpMontoBase   [j] = 0;
                            stPreFactura.A_PFactura.dImpFacturable  [j] = 0;
                        }
                        else
                        {
                            dMtoDesc += stPreFactura.A_PFactura.dImpConcepto  [j];
                            if (dImporteCargo <= (dMtoDesc * -1))
                            {
                                dAjuste = (dMtoDesc * -1) - dImporteCargo;
                                stPreFactura.A_PFactura.dImpConcepto    [j] +=  dAjuste;
                                stPreFactura.A_PFactura.dImpMontoBase   [j] +=  dAjuste;
                                stPreFactura.A_PFactura.dImpFacturable  [j] +=  dAjuste;
                                sw = 1;
                            }
                        }
                    }
                }
            }
        }
    }

/* PGG SOPORTE 21-10-2005 CH-200510173170 HASTA */

    /* Actualiza estado de ejecucion de Dctos en tabla de Beneficios */
    for( ind_Abo=0;ind_Abo < stPlanesDesc.iNumAbonados;ind_Abo++ )
    {
        for( ind_Plan=0;ind_Plan < stPlanesDesc.stAbonado[ind_Abo].iNumPlanes;ind_Plan++ )
        {
            if( stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.iCodEstado == 1 ) /* Dcto. aplicado */
            {
                vDTrazasLog (modulo,"\n\t\t ModifBeneficios [%ld] ",LOG05, stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.lNumSecuencia);
                if( !bModifBeneficios ( stPlanesDesc.stAbonado[ind_Abo].stPlanDes[ind_Plan].stPD.lNumSecuencia) )
                {
                    vDTrazasLog (modulo,"\n\t\t ModifBeneficios RETURN FALSE. ",LOG03);
                    return(FALSE);
                }
            }
        }
    }

    vDTrazasLog  (modulo,"\t***** Fin a la Funcion Plan de Descuentos *****", LOG04);
    return(TRUE);
}

/* busca abonado en la estructura de abonados facturables del ciclo */
/*BOOL bfnBuscaAbonadoFact (long lNumAbonado)
{
	int i=0;
	char   modulo[] = "bfnBuscaAbonadoFact" ;
	
 	for (i=0; i<NUM_ABONADOS;i++ )
 	{
		if (pstAbonados[i].lNumAbonado == lNumAbonado)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}*/


/*****************************************************************************/
/*  Funcion : bfnDescPuntuales                                               */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
access BOOL bfnDescPuntuales (long lCliente)
{
    char modulo[]= "bfnDescPuntuales";
    int iRes = 0;
    long lCodCliente;
    double dTotMontoPrefactura= 0.0 ;
    long lNumConceptos = 0L;
    long lIndPref;

    DETCARG_PUNTUALES pstDesPuntTemp;

    if (!bfnFindDescPuntual(lCliente,&pstDesPuntTemp))
    {
        vDTrazasLog (modulo,"\t\t\t El cliente que se esta procesando no se encuentra en la estructura de descuentos a aplicar ", LOG05);
		return TRUE; /* no es error */
    }

  	if ( pstDesPuntTemp.iCodTipDescu == 1 )  /* devolucion */
  	{
  		/*if (!bfnBuscaAbonadoFact(pstDesPuntTemp.lNumAbonado))
  		{
	        vDTrazasLog (modulo,"\t\t\t El abonado no se encuentra en la estructura de abonados facturables del ciclo", LOG05);
			return TRUE;  no es error 
  		}*/
  		
	    	/*Validar monto */
	        dTotMontoPrefactura = dValidaMontoMinimo();
	
	        lNumConceptos = stPreFactura.iNumRegistros;
	
	        for( lIndPref=0; lIndPref < lNumConceptos ; lIndPref++ )
	        {
	            if( stPreFactura.A_PFactura.lNumAbonado[lIndPref]  == pstDesPuntTemp.lNumAbonado && 
	                stPreFactura.A_PFactura.iCodConcepto[lIndPref] == pstDesPuntTemp.lCodConcCargo && 
	                stPreFactura.A_PFactura.dImpConcDescApli[lIndPref] > 0  &&         // tiene disponible el cargo para descontar 
	                pstDesPuntTemp.dMtoDcto >  pstDesPuntTemp.dMtoAplicado )  // tiene disponible el descuento 
	            {
	                vDTrazasLog (modulo,"\t\t\tAplicando descuento puntual [%ld]",
	                                    LOG04,pstDesPuntTemp.lCodConcDesc);	
	
			        /* Aplica Dctos. a stPrefactura */
			        if( !bCargaDescPuntPreFactura ( lIndPref, &pstDesPuntTemp) )
			        {
			                vDTrazasLog(modulo,"*** No se genero descuento en prefactura cliente [%ld] ***",LOG05,lCliente);
			                return(FALSE);
			        }
			        
			        /* Actualiza campo indicador */
			        if( !bModifCampInd (lCliente, &pstDesPuntTemp))
			        {
			          	vDTrazasLog(modulo,"*** No se pudo actualizar el campo indicador para el cliente [%ld] ***",LOG05,lCliente);
			                return(FALSE);
			        }
			        
	  	    }
	  	    
	  	    if ( pstDesPuntTemp.dMtoDcto ==  pstDesPuntTemp.dMtoAplicado )
		    {
				/* Actualiza campo mto_aplicado */
				if( !bModifMtoAplicado (lCliente, &pstDesPuntTemp))
			        {
			        	vDTrazasLog(modulo,"*** No se pudo actualizar el campo mto_aplicado para el cliente [%ld] ***",LOG05,lCliente);
			               	return(FALSE);
			        }		
		    }
		}
	}
	else if ( pstDesPuntTemp.iCodTipDescu == 2 ) //   Indemnizacion
	{
		/*Validar monto */
	        dTotMontoPrefactura = dValidaMontoMinimo();
	
	        lNumConceptos = stPreFactura.iNumRegistros;
	        
	        for( lIndPref=0; lIndPref < lNumConceptos ; lIndPref++ )
        	{
	    		if( stPreFactura.A_PFactura.dImpConcDescApli[lIndPref] > 0  &&         // tiene disponible el cargo para descontar 
	                    pstDesPuntTemp.dMtoDcto >  pstDesPuntTemp.dMtoAplicado )  // tiene disponible el descuento 
	    		{
	        			vDTrazasLog (modulo,"\t\t\tAplicando descuento puntual [%ld]",
	                        LOG04,pstDesPuntTemp.lCodConcDesc);
	
			          /* Aplica Dctos. a stPrefactura */
			        	if( !bCargaDescPuntPreFactura ( lIndPref, &pstDesPuntTemp) )
			        	{
			        		
			                vDTrazasLog(modulo,"*** No se genero descuento en prefactura cliente [%ld] ***",LOG05,lCliente);
			                return(FALSE);
			        	}
			        
			        	/* Actualiza campo mto_aplicado */
			        	if( !bModifCampInd (lCliente, &pstDesPuntTemp))
			        	{
			          		vDTrazasLog(modulo,"*** No se pudo actualizar el campo indicador para el cliente [%ld] ***",LOG05,lCliente);
			                	return(FALSE);
			        	}
			        	       
			}
			
			if ( pstDesPuntTemp.dMtoDcto ==  pstDesPuntTemp.dMtoAplicado )
			{
				/* Actualiza campo mto_aplicado */
				if( !bModifMtoAplicado (lCliente, &pstDesPuntTemp))
			        {
			        	vDTrazasLog(modulo,"*** No se pudo actualizar el campo mto_aplicado para el cliente [%ld] ***",LOG05,lCliente);
			               	return(FALSE);
			        }		
			}
		}		
	}
	
    /* Actualiza la tabla FA_DESC_PUNTUALES_TO */
    if( !bModifDescPuntuales (&pstDesPuntTemp))
    {
            vDTrazasLog(modulo,"*** No se pudo actualizar la tabla FA_DESC_PUNTUALES_TO ***",LOG05);
            return(FALSE);
    }		
	
    vDTrazasLog  (modulo,"\t***** Fin a la Funcion Plan de Descuentos Puntuales *****", LOG04);
        return(TRUE);
}

/*****************************************************************************/
/*                      Funcion : bModifCampInd                              */
/*****************************************************************************/
static BOOL bModifCampInd (long lCliente, DETCARG_PUNTUALES *pstDescPuntual)
{
    char modulo[] = "bfnDescPuntuales";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCliente ;
    int  ihCero = 0;
    int  ihUNO  = 1;
    double dMtoAplicado;
    /* EXEC SQL END DECLARE SECTION; */ 


    lhCodCliente = lCliente;
    dMtoAplicado = pstDescPuntual->dMtoAplicado;	

    vDTrazasLog (modulo,"\n\t\t***** Function bModifCampInd *****",LOG05);

    vDTrazasLog (modulo,"\n\t\t\tCliente        [%ld]",LOG05, lhCodCliente);
    
    /* EXEC SQL
    UPDATE FA_DESC_PUNTUAL_TO
    SET MTO_APLICADO = :dMtoAplicado
    WHERE COD_CLIENTE = :lhCodCliente; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_DESC_PUNTUAL_TO  set MTO_APLICADO=:b0 where COD\
_CLIENTE=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dMtoAplicado;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
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



        vDTrazasLog (modulo,"\n\t\t\tREG ACTUALIZADOS [%ld]",LOG05,sqlca.sqlerrd[2]);

        if( sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND )
        {
            vDTrazasLog (modulo,"\n\t\tError Update de FA_DESC_PUNTUAL_TO",LOG01);
            iDError (szExeName,ERR000,vInsertarIncidencia,"update FA_DESC_PUNTUAL_TO Plan Dcto.", szfnORAerror());
            return(FALSE);
        }

    return(TRUE);
}

/*****************************************************************************/
/*                      Funcion : bModifMtoAplicado                          */
/*****************************************************************************/
static BOOL bModifMtoAplicado (long lCliente, DETCARG_PUNTUALES *pstDescPuntual)
{
    char modulo[] = "bfnDescPuntuales";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhCodCliente ;
    double dMtoDescuento;
    /* EXEC SQL END DECLARE SECTION; */ 


    lhCodCliente = lCliente;
    dMtoDescuento = pstDescPuntual->dMtoAplicado;	

    vDTrazasLog (modulo,"\n\t\t***** Function bModifMtoAplicado *****",LOG05);
    vDTrazasLog (modulo,"\n\t\t\tCliente        [%ld]",LOG05, lhCodCliente);
    
    /* EXEC SQL
    UPDATE FA_DESC_PUNTUAL_TO
    SET MTO_APLICADO = :dMtoDescuento
    WHERE COD_CLIENTE = :lhCodCliente; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_DESC_PUNTUAL_TO  set MTO_APLICADO=:b0 where COD\
_CLIENTE=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )28;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&dMtoDescuento;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
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



        vDTrazasLog (modulo,"\n\t\t\tREG ACTUALIZADOS [%ld]",LOG05,sqlca.sqlerrd[2]);

        if( sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND )
        {
            vDTrazasLog (modulo,"\n\t\tError Update de FA_DESC_PUNTUAL_TO",LOG01);
            iDError (szExeName,ERR000,vInsertarIncidencia,"update FA_DESC_PUNTUAL_TO Plan Dcto.", szfnORAerror());
            return(FALSE);
        }

    return(TRUE);
}

/*****************************************************************************/
/*                      Funcion : bModifDescPuntuales                        */
/*****************************************************************************/
static BOOL bModifDescPuntuales (DETCARG_PUNTUALES *pstDescPuntual)
{
    char modulo[] = "bfnDescPuntuales";
    
    char szIndOrdenTotal [18];
    char szRowid [20];
    double dMtoSaldo;
    
    vDTrazasLog (modulo,"\n\t\t***** Function bModifDescPuntuales *****",LOG05);
    
    strcpy(szIndOrdenTotal,stDatosGener.szIndOrdenTotal);
    strcpy(szRowid,pstDescPuntual->szRowid);
    dMtoSaldo=pstDescPuntual->dMtoDcto - pstDescPuntual->dMtoAplicado;
    
    /* EXEC SQL
    UPDATE FA_DESC_PUNTUAL_TO
    SET IND_ORDENTOTAL = :szIndOrdenTotal , MTO_SALDO = :dMtoSaldo
    WHERE ROWID = :szRowid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update FA_DESC_PUNTUAL_TO  set IND_ORDENTOTAL=:b0,MTO_SAL\
DO=:b1 where ROWID=:b2";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )51;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)szIndOrdenTotal;
    sqlstm.sqhstl[0] = (unsigned long )18;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&dMtoSaldo;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szRowid;
    sqlstm.sqhstl[2] = (unsigned long )20;
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



        vDTrazasLog (modulo,"\n\t\t\tREG ACTUALIZADOS [%ld]",LOG05,sqlca.sqlerrd[2]);

        if( sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND )
        {
            vDTrazasLog (modulo,"\n\t\tError Update de FA_DESC_PUNTUAL_TO",LOG01);
            iDError (szExeName,ERR000,vInsertarIncidencia,"update FA_DESC_PUNTUAL_TO Plan Dcto.", szfnORAerror());
            return(FALSE);
        }
        
    return(TRUE);
}

/*****************************************************************************/
/*                      Funcion : iCmpDescPuntuales                          */
/*****************************************************************************/
int iCmpDescPuntuales (const void* cad1,const void* cad2)
{
 return ( ((DETCARG_PUNTUALES *)cad1)->lCodCliente-((DETCARG_PUNTUALES *)cad2)->lCodCliente );
}
/*********************** iCmpDescPuntuales ************************************/

/*****************************************************************************/
/*                      Funcion : iCmpAbonocli                          */
/*****************************************************************************/
int iCmpAbonocli (const void* cad1,const void* cad2)
{
  return ( ((ABONOCLI *)cad1)->lNumAbonados -((ABONOCLI *)cad2)->lNumAbonados );
}
/*********************** iCmpAbonocli ************************************/

/*****************************************************************************/
/*                       Funcion : bfnFindDescPuntual                        */
/* -Funcion que busca un registro en pstDescPuntual con el                   */
/*  parametro de busqueda lCliente                                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bfnFindDescPuntual (long lCliente, DETCARG_PUNTUALES *pstDescPuntuales)
{
  DETCARG_PUNTUALES stkey;
  DETCARG_PUNTUALES *pstDescPuntuales_Aux = (DETCARG_PUNTUALES *)NULL;
  ABONOCLI *pstAbonoCli_Aux = (ABONOCLI *)NULL;
  ABONOCLI stKeys;
  BOOL bRes = TRUE;

  stkey.lCodCliente = lCliente;

  vDTrazasLog (szExeName, "\n\t *  Busca Registro en pstDescPuntual "
                          "\n\t\t=>  lCodCliente          [%ld]"
                          "\n\t\t=>  Total de Registros   [%d]",
                          LOG05,
                          stkey.lCodCliente,
                          pstDescPuntual.iNumDetCargPunt);

  	if ( (pstDescPuntuales_Aux = (DETCARG_PUNTUALES *)bsearch(&stkey,pstDescPuntual.stDetCargPunt,pstDescPuntual.iNumDetCargPunt,
                 sizeof(DETCARG_PUNTUALES),iCmpDescPuntuales))==(DETCARG_PUNTUALES *)NULL)
  	{
        	bRes = FALSE;
  	}
  	else 
  	{
		pstDescPuntuales->lCodCliente     = pstDescPuntuales_Aux->lCodCliente   ;
		pstDescPuntuales->lNumAbonado     = pstDescPuntuales_Aux->lNumAbonado   ;
		pstDescPuntuales->iCodTipDescu    = pstDescPuntuales_Aux->iCodTipDescu  ;
		pstDescPuntuales->lCodConcCargo   = pstDescPuntuales_Aux->lCodConcCargo ; 
		pstDescPuntuales->lCodConcDesc    = pstDescPuntuales_Aux->lCodConcDesc  ;
		pstDescPuntuales->dMtoDcto        = pstDescPuntuales_Aux->dMtoDcto      ;
		pstDescPuntuales->dMtoAplicado    = pstDescPuntuales_Aux->dMtoAplicado  ;
		strcpy (pstDescPuntuales->szRowid,  pstDescPuntuales_Aux->szRowid);
    }
  return bRes;
}
/************************** Final bFinaCuadCtoPlan **************************/

/*****************************************************************************/
/*  Funcion : bfnCargaPlanDesc                                               */
/*****************************************************************************/
static BOOL bfnCargaPlanDesc (long       lCliente)
{
    char modulo[]   = "bfnCargaPlanDesc";
    long     plNumFilas = 0L           ;
    long     plNumFilas_Ant = 0L           ;
    int  i = 0, ind_Abon =0, ind_Plan =0;
    long lpNumAbonado;
    int     piSqlCodeLocal = 0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    long     lahNumSecuencia [MAX_PLANES * NUM_ABONADOS_CLIENTE]    ;
	    long     lahNumAbonado   [MAX_PLANES * NUM_ABONADOS_CLIENTE]    ;
	    /* VARCHAR  szahCod_Plandesc[MAX_PLANES * NUM_ABONADOS_CLIENTE][6] ; */ 
struct { unsigned short len; unsigned char arr[6]; } szahCod_Plandesc[60000];

	    /* VARCHAR  szahTipEntidad  [MAX_PLANES * NUM_ABONADOS_CLIENTE][6] ; */ 
struct { unsigned short len; unsigned char arr[6]; } szahTipEntidad[60000];

    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (modulo,"\n\t\t* Funcion bfnCargaPlanDesc ",LOG05);

    lhCodCliente = lCliente;
    lhCodCiclFact = stCiclo.lCodCiclFact;

    /* EXEC SQL OPEN Cur_GatPlanDesc; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
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
    sqlstm.sqhstv[1] = (unsigned char  *)&lhCodCiclFact;
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
        iDError (szExeName,ERR000,vInsertarIncidencia,"Open => GAT_PLANDESCABO",szfnORAerror ());
    }
    piSqlCodeLocal = SQLCODE;

    lpNumAbonado=lahNumAbonado[0];
    ind_Abon = 0;
    ind_Plan = 0;
    stPlanesDesc.iNumAbonados=1;

    piSqlCodeLocal=SQLCODE;
    plNumFilas_Ant = 0;
  	while (!piSqlCodeLocal)
    {
        /* EXEC SQL 
        	FETCH Cur_GatPlanDesc
             INTO :lahNumSecuencia    ,
                  :lahNumAbonado      ,
                  :szahCod_Plandesc   ,
                  :szahTipEntidad     ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )60000;
        sqlstm.offset = (unsigned int  )101;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)lahNumSecuencia;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )sizeof(long);
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqharc[0] = (unsigned long  *)0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)lahNumAbonado;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )sizeof(long);
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqharc[1] = (unsigned long  *)0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)szahCod_Plandesc;
        sqlstm.sqhstl[2] = (unsigned long )8;
        sqlstm.sqhsts[2] = (         int  )8;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqharc[2] = (unsigned long  *)0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)szahTipEntidad;
        sqlstm.sqhstl[3] = (unsigned long )8;
        sqlstm.sqhsts[3] = (         int  )8;
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



        if (SQLCODE==SQLOK){
            /*plNumFilas = (MAX_PLANES * NUM_ABONADOS_CLIENTE)    ;*/
            plNumFilas = sqlca.sqlerrd[2] - plNumFilas_Ant;
            plNumFilas_Ant = sqlca.sqlerrd[2];
        }
        else
        {
            if (SQLCODE==SQLNOTFOUND){
                plNumFilas = sqlca.sqlerrd[2] - plNumFilas_Ant;
            }
            else
            {
                iDError (szExeName,ERR000,vInsertarIncidencia,"Fetch=> GAT_PLANDESCABO",szfnORAerror ());
                return (FALSE);
		    }
		}

        piSqlCodeLocal = SQLCODE;

        if (!plNumFilas)
	        break;

         vDTrazasLog (szExeName, "\n\t\t* Planes de Descuento [%ld] del Cliente [%ld]  ", LOG06, plNumFilas,lhCodCliente);


        for( i=0;i<plNumFilas;i++ )
        {
            if( lpNumAbonado!=lahNumAbonado[i] )
            {
                ind_Abon++;
                stPlanesDesc.iNumAbonados++;
                ind_Plan=0;
            }
            stPlanesDesc.stAbonado[ind_Abon].lNumAbonado = lahNumAbonado[i];
            stPlanesDesc.stAbonado[ind_Abon].iNumPlanes++;
            sprintf(stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].szCod_Plandesc,"%.*s\0",szahCod_Plandesc[i].len, szahCod_Plandesc[i].arr);
            stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].stPD.lNumSecuencia=lahNumSecuencia[i];
            sprintf(stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].szTipEntidad,"%.*s\0",szahTipEntidad[i].len, szahTipEntidad[i].arr);

            if( strcmp(stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].szTipEntidad, TIPOENTGRUPO) == 0 )
            {   /* HABILITA INDICADOR DE PLANES DE GRUPO */
                indGrupo = 1;
            }

            vDTrazasLog (modulo,"\t\t\t=> Num. Abonado        : [%ld]**"
                         "\n\t\t\t=> Cod. Plan Descuento : [%s]**"
                         "\n\t\t\t=> Num. Secuencia      : [%ld]**"
                         "\n\t\t\t=> Tipo Entidad        : [%s]**"
                         ,LOG05,stPlanesDesc.stAbonado[ind_Abon].lNumAbonado
                         ,stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].szCod_Plandesc
                         ,stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].stPD.lNumSecuencia
                         ,stPlanesDesc.stAbonado[ind_Abon].stPlanDes[ind_Plan].szTipEntidad);

            ind_Plan++;
            lpNumAbonado=lahNumAbonado[i];
        }
    }
    /* EXEC SQL CLOSE Cur_GatPlanDesc; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )132;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    return(TRUE);
}


/*****************************************************************************/
/*  Funcion : bfnCargaDatosPlan                                              */
/*****************************************************************************/
static BOOL bfnCargaDatosPlan (char *szFecParam, PLANDCTO *pstPD, char *szCod_Plandesc )
{
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
    /* EXEC SQL END DECLARE SECTION; */ 


    char modulo[]   = "bfnCargaDatosPlan";

    vDTrazasLog (modulo,"\n\t\t* Funcion bfnCargaDatosPlan "
                 "\n\t\t=> Fecha Parametro   [%s]"
                 "\n\t\t=> Cod.  Plan Desc.  [%s]",
                 LOG04, szFecParam, szCod_Plandesc);

    strcpy(szhCod_Plan,szCod_Plandesc);
    strcpy(szhFecParam,szFecParam);

    /* EXEC SQL
    SELECT C.COD_TIPEVAL      ,
           C.COD_TIPAPLI      ,
           C.COD_GRUPOEVAL    ,
           C.COD_GRUPOAPLI    ,
           C.NUM_CUADRANTE    ,
           C.TIP_UNIDAD       ,
           C.COD_CONCDESC     ,
           C.MTO_MINFACT
      INTO :szhCod_Tipeval    ,
           :szhCod_Tipapli    ,
           :ihCod_Grupoeval :i_shCod_Grupoeval,
           :ihCod_Grupoapli :i_shCod_Grupoapli  ,
           :ihNum_Cuadrante :i_shNum_Cuadrante  ,
           :szhTip_Unidad     ,
           :ihCod_Concdesc :i_shCod_Concdesc,
           :dhMto_Minfact  :i_shMto_Minfact
      FROM FAD_PLANDESC B,  FAD_DETPLANDESC C
     WHERE B.COD_PLANDESC = C.COD_PLANDESC
       AND TO_DATE(:szhFecParam,'yyyymmddhh24miss') BETWEEN C.FEC_DESDE AND C.FEC_HASTA
       AND B.COD_PLANDESC = :szhCod_Plan; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select C.COD_TIPEVAL ,C.COD_TIPAPLI ,C.COD_GRUPOEVAL ,C.C\
OD_GRUPOAPLI ,C.NUM_CUADRANTE ,C.TIP_UNIDAD ,C.COD_CONCDESC ,C.MTO_MINFACT int\
o :b0,:b1,:b2:b3,:b4:b5,:b6:b7,:b8,:b9:b10,:b11:b12  from FAD_PLANDESC B ,FAD_\
DETPLANDESC C where ((B.COD_PLANDESC=C.COD_PLANDESC and TO_DATE(:b13,'yyyymmdd\
hh24miss') between C.FEC_DESDE and C.FEC_HASTA) and B.COD_PLANDESC=:b14)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )147;
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



    if( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
    {
        vDTrazasLog (modulo,"\n\t\tError en Select de Plan Descuento del Cliente",LOG03);
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select de Plan Descuento del Cliente", szfnORAerror());
        return(FALSE);
    }

    if( SQLCODE == SQLNOTFOUND )
        vDTrazasLog (modulo,"\n\t\t* Plan de Descuento No-Vigente [%s]",LOG03,szhCod_Plan);


    if( SQLCODE == SQLOK )
    {
        vDTrazasLog (modulo,"\n\t\t* Cliente Con Plan de Descuento [%s]",LOG04,szhCod_Plan);
        strcpy(pstPD->szCod_Tipeval      , szhCod_Tipeval);
        strcpy(pstPD->szCod_Tipapli      , szhCod_Tipapli);
        strcpy(pstPD->szTip_Unidad       , szhTip_Unidad);

        if( i_shCod_Grupoeval == ORA_NULL )
            pstPD->iCod_Grupoeval = ORA_NULL;
        else
            pstPD->iCod_Grupoeval = ihCod_Grupoeval;

        if( i_shCod_Grupoapli == ORA_NULL )
            pstPD->iCod_Grupoapli = ORA_NULL;
        else
            pstPD->iCod_Grupoapli = ihCod_Grupoapli;

        if( i_shNum_Cuadrante == ORA_NULL )
            pstPD->iNum_Cuadrante = ORA_NULL;
        else
            pstPD->iNum_Cuadrante = ihNum_Cuadrante;

        if( i_shCod_Concdesc == ORA_NULL )
            pstPD->iCod_Concdesc  = ORA_NULL;
        else
            pstPD->iCod_Concdesc  = ihCod_Concdesc;

        if( i_shMto_Minfact == ORA_NULL )
            pstPD->dMto_Minfact   = ORA_NULL;
        else
            pstPD->dMto_Minfact   = dhMto_Minfact;

    }
    return(TRUE);
}

/*****************************************************************************/
/*****************************************************************************/

static BOOL bfnDescporConceptoAbonado (long lNumAbonado, PLANDCTO *stPD ,char *szFecParam, double dTotalMontoPrefactura)
{
    char   modulo[]         = "bfnDescporConceptoAbonado";
    double dTotalfac        = 0.0;

    GRUPOCONCEVAL  stEval   ;
    GRUPOCONAPLI   stApli   ;
    GRUPOCUADRANTE stCuadra ;
    VALORDESCUENTO stDescPaso;

    vDTrazasLog (modulo,"\n\t\t*** Entrada en bfnDescporConceptoAbonado "
                        "\n\t\t=> Nro. Abonado : [%ld]", LOG04, lNumAbonado);

    memset (&stEval     ,0,sizeof (GRUPOCONCEVAL));
    memset (&stApli     ,0,sizeof (GRUPOCONAPLI));
    memset (&stCuadra   ,0,sizeof (GRUPOCUADRANTE));
    memset (&stDescPaso ,0,sizeof (VALORDESCUENTO));

    if( dTotalMontoPrefacDesc <= stPD->dMto_Minfact )
    {
        vDTrazasLog (modulo,"\n\t**Monto a Facturar es Menor que el Monto Minimo Permitido"
                     "\n\t**Monto a Facturar [%f] **Monto Minimo Permitido [%f]"
                     ,LOG04,dTotalMontoPrefacDesc,stPD->dMto_Minfact);
        return(TRUE);
    }

    /*Carga Concepto de Evaluacion */
    if( strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0 )
    {
        if( !bCargaConceptoEvalua (stPD->iCod_Grupoeval,szFecParam,&stEval) )
        {
            vDTrazasLog(modulo,"*** No cargaron Conceptos de Evaluacion grupo [%d] ***",LOG05,stPD->iCod_Grupoeval);
            return(FALSE);
        }
    }

    /*Contar cantidad de evaluaciones*/
    if( !bEvaluaciondeConceptos (stPD,&stEval, &dTotalfac, szFecParam,dTotalMontoPrefactura) )
    {
        vDTrazasLog(modulo,"*** No se Evaluaron Conceptos en grupo [%d] ***",LOG05,stPD->iCod_Grupoeval);
        return(FALSE);
    }

    vDTrazasLog  (modulo,"\n\t***** Total a Facturar por Evaluacion [%f]", LOG04,dTotalfac);

    /*calculo de descuentos */
    if( dTotalfac > 0 )
    {
        if( strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0 )
            /*carga Concepto de Aplicacion*/
            if( !bCargaConceptoAplica (stPD->iCod_Grupoapli,szFecParam,&stApli) )
            {
                vDTrazasLog(modulo,"*** No cargaron Conceptos de Aplicacion grupo [%d] ***",LOG05,stPD->iCod_Grupoapli);
                return(FALSE);
            }

        if( (stApli.iNumAplica > 0 && strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0) || /* NCH Incidencia CH-310720031154 */
            strcmp(stPD->szCod_Tipeval,PORFACTURA)==0 )
        {
            /* Carga Cuadrante de Descuento*/
            if( !bCargaCuadrante (stPD->iNum_Cuadrante,szFecParam,&stCuadra) )
            {
                vDTrazasLog(modulo,"*** No se Cargo Cuadrante [%d] ***",LOG05,stPD->iNum_Cuadrante);
                return(FALSE);
            }

            if( !bCalculaDescuento(lNumAbonado, &stDescPaso, &stCuadra, dTotalfac) )
            {
                vDTrazasLog(modulo,"*** No se Calculo Descuento Abonado [%ld] ***",LOG02,lNumAbonado);
                return(FALSE);
            }

            if( (stDescPaso.dVal_Descuento != 0.0)||(stDescPaso.dVal_Descuento != 0) )
            {

                if( strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0 )
                    /*contar cantidad de aplicaciones*/
                    if( !bAplicacionConceptos ( lNumAbonado, stPD, &stApli, &stDescPaso, szFecParam) )
                    {
                        vDTrazasLog(modulo,"*** No se Aplico Descuento Abonado [%ld] ***",LOG05,lNumAbonado);
                        return(FALSE);
                    }

                if( strcmp(stPD->szCod_Tipeval,PORFACTURA)==0 )
                    /*if( !bAplicacionConceptosFacturaCliente(lNumAbonado,stPD,&stDescPaso,*szFecParam, dTotalfac) )*/
                    if( !bAplicacionConceptosFacturaCliente(lNumAbonado,stPD,&stDescPaso,dTotalfac) )
                    {
                        vDTrazasLog(modulo,"*** No se Aplicaron Conceptos Factura Abonado [%ld] ***",LOG05,lNumAbonado);
                        return(FALSE);
                    }

                vfnPrintCuadrante(&stValDesc.stDescuentos[idxDesc-1]);
            }
        }
    }
    else
    {
        vDTrazasLog  (modulo,"\t***** Monto de Evaluacion es [0].No se Pueden Efectuar Descuentos", LOG04);
    }
    return(TRUE);
}


/*****************************************************************************/
/*  Funcion : iCargaGrupoEvalua                                              */
/* -Funcion que carga los conceptos de evaluacion                            */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaConceptoEvalua(int iCod_Grupo, char *szFecParam, GRUPOCONCEVAL  *pstEval)
{
    char modulo[]   = "bCargaConceptoEvalua";
    int  iNumRegs;
    int  i=0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    szhFecParam    [15];  /* EXEC SQL VAR szhFecParam  IS STRING(15); */ 

    int     ihCod_Grupo        ;
    int     iahCod_Concepto       [MAX_REGISTROS]    ;
    /* VARCHAR szahInd_Obliga        [MAX_REGISTROS][2] ; */ 
struct { unsigned short len; unsigned char arr[2]; } szahInd_Obliga[3000];

    double  dahMto_MinFact        [MAX_REGISTROS]    ;
    short   i_shMto_MinFact       [MAX_REGISTROS]    ;
    /* EXEC SQL END DECLARE SECTION; */ 


    ihCod_Grupo =  iCod_Grupo;
    strcpy(szhFecParam,szFecParam);

    vDTrazasLog (modulo,"\n\t***** Function bCargaConceptoEvalua *****"
                 "\n\t\t Carga Concepto de Evaluacion con Grupo [%d]- Fecha[%s]"
                 ,LOG04,ihCod_Grupo,szhFecParam);

    /* EXEC SQL
    SELECT COD_CONCEPTO ,
		   IND_OBLIGA  ,
		   MTO_MINFACT
      INTO :iahCod_Concepto  ,
           :szahInd_Obliga   ,
           :dahMto_MinFact :i_shMto_MinFact
      FROM FAD_CONCEVAL
     WHERE COD_GRUPO = :ihCod_Grupo
       AND TO_DATE(:szhFecParam,'yyyymmddhh24miss') BETWEEN FEC_DESDE AND FEC_HASTA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_CONCEPTO ,IND_OBLIGA ,MTO_MINFACT into :b0,:b1\
,:b2:b3  from FAD_CONCEVAL where (COD_GRUPO=:b4 and TO_DATE(:b5,'yyyymmddhh24m\
iss') between FEC_DESDE and FEC_HASTA)";
    sqlstm.iters = (unsigned int  )3000;
    sqlstm.offset = (unsigned int  )202;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)iahCod_Concepto;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)szahInd_Obliga;
    sqlstm.sqhstl[1] = (unsigned long )4;
    sqlstm.sqhsts[1] = (         int  )4;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)dahMto_MinFact;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[2] = (         int  )sizeof(double);
    sqlstm.sqindv[2] = (         short *)i_shMto_MinFact;
    sqlstm.sqinds[2] = (         int  )sizeof(short);
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&ihCod_Grupo;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )sizeof(int);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szhFecParam;
    sqlstm.sqhstl[4] = (unsigned long )15;
    sqlstm.sqhsts[4] = (         int  )15;
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



    iNumRegs = SQLROWS;

    if( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
    {
        vDTrazasLog (modulo,"\n\t\tError en Select de Grupo de Evaluacion",LOG03);
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select de Grupo de Evaluacion", szfnORAerror());
        return(FALSE);
    }
    if( (SQLCODE == SQLNOTFOUND) && (iNumRegs == 0) )
    {
        vDTrazasLog (modulo,"\n\t\tGrupo de Evaluacion [%d] no existe ",LOG03,ihCod_Grupo);

    }

    if( iNumRegs > 0 )
    {
        for( i=0;i<iNumRegs;i++ )
        {
            pstEval->stRegistro[i].iCod_Grupo          =   ihCod_Grupo;
            pstEval->stRegistro[i].iCod_Concepto       =   iahCod_Concepto      [i];
            sprintf(pstEval->stRegistro[i].szInd_Obliga,"%.*s\0",szahInd_Obliga[i].len, szahInd_Obliga[i].arr);

            if( i_shMto_MinFact[i] == ORA_NULL )
                pstEval->stRegistro[i].dMto_MinFact = ORA_NULL;
            else
                pstEval->stRegistro[i].dMto_MinFact = dahMto_MinFact[i];

            vDTrazasLog (szExeName, "\n\t\t***** vPrintConceptosEvaluacion *****"
                         "\n\t\t[%d]-Codigo de Grupo................[%d]"
                         "\n\t\t[%d]-Codigo Concepto................[%d]"
                         "\n\t\t[%d]-Indicador Obligatorio..........[%s]"
                         "\n\t\t[%d]-Monto Minimo Facturado.........[%f]"
                         ,LOG04
                         ,i,pstEval->stRegistro[i].iCod_Grupo
                         ,i,pstEval->stRegistro[i].iCod_Concepto
                         ,i,pstEval->stRegistro[i].szInd_Obliga
                         ,i,pstEval->stRegistro[i].dMto_MinFact)        ;
            pstEval->iNumEval ++;
        }
    }

    vDTrazasLog  (modulo,"\t\t***** Fin Funcion Concepto de Grupo de Evaluacion *****", LOG04);
    return(TRUE);

}
/*************************** Final iCargaGrupoEvalua *****************************/


/*****************************************************************************/
/*  Funcion : bCargaConceptoAplica                                           */
/* -Funcion que carga los conceptos de aplicacion                            */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaConceptoAplica(int iCod_Grupo, char *szFecParam, GRUPOCONAPLI  *pstApli)
{
    char modulo[]   = "bCargaConceptoAplica";
    int  iNumRegs;
    int  i=0;

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    szhFecParam    [15];  /* EXEC SQL VAR szhFecParam  IS STRING(15); */ 

    int     ihCod_Grupo        ;
    int     iahCod_Concepto       [MAX_REGISTROS]    ;
    int     iahCod_ConRel         [MAX_REGISTROS]    ;
    short   i_shCod_ConRel        [MAX_REGISTROS]    ;
    /* EXEC SQL END DECLARE SECTION; */ 



    ihCod_Grupo =  iCod_Grupo;
    strcpy(szhFecParam,szFecParam);

    vDTrazasLog (modulo,"\n\t\t***** Function %s *****"
                 "\n\t\t\t Carga Concepto de Aplicacion con Grupo [%d]- Fecha [%s]"
                 ,LOG04,modulo, ihCod_Grupo,szhFecParam);

    /* EXEC SQL
    SELECT COD_CONCEPTO          ,
    	   COD_CONREL
      INTO :iahCod_Concepto      ,
           :iahCod_ConRel :i_shCod_ConRel
      FROM FAD_CONCAPLI
     WHERE COD_GRUPO = :ihCod_Grupo
       AND TO_DATE(:szhFecParam,'yyyymmddhh24miss') BETWEEN FEC_DESDE AND FEC_HASTA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select COD_CONCEPTO ,COD_CONREL into :b0,:b1:b2  from FAD\
_CONCAPLI where (COD_GRUPO=:b3 and TO_DATE(:b4,'yyyymmddhh24miss') between FEC\
_DESDE and FEC_HASTA)";
    sqlstm.iters = (unsigned int  )3000;
    sqlstm.offset = (unsigned int  )237;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)iahCod_Concepto;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )sizeof(int);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)iahCod_ConRel;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[1] = (         int  )sizeof(int);
    sqlstm.sqindv[1] = (         short *)i_shCod_ConRel;
    sqlstm.sqinds[1] = (         int  )sizeof(short);
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&ihCod_Grupo;
    sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )sizeof(int);
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)szhFecParam;
    sqlstm.sqhstl[3] = (unsigned long )15;
    sqlstm.sqhsts[3] = (         int  )15;
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



    iNumRegs = SQLROWS;

    if( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
    {
        vDTrazasLog  (modulo,"\n\tError en Select de Grupo de Aplicacion ", LOG01);
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select de Grupo de Aplicacion", szfnORAerror());
        return(FALSE);
    }

    if( (SQLCODE == SQLNOTFOUND) && (iNumRegs == 0) )
    {
        vDTrazasLog  (modulo,"\n\tCodigo de Grupo de Aplicacion [%d] no Existe", LOG04,ihCod_Grupo);
        pstApli->iNumAplica = 0;
    }

    if( iNumRegs > 0 )
    {
        for( i=0;i<iNumRegs;i++ )
        {
            pstApli->stRegistro[i].iCod_Grupo          =   ihCod_Grupo;
            pstApli->stRegistro[i].iCod_Concepto       =   iahCod_Concepto      [i];

            if( i_shCod_ConRel[i] == ORA_NULL )
                pstApli->stRegistro[i].iCod_ConRel = ORA_NULL;
            else
                pstApli->stRegistro[i].iCod_ConRel = iahCod_ConRel[i];

            vDTrazasLog (szExeName, "\n\t\t***** vPrintConceptosAplicacion *****"
			                        "\n\t\t[%d]-Codigo de Grupo................[%d]"
			                        "\n\t\t[%d]-Codigo Concepto................[%d]"
			                        "\n\t\t[%d]-Codigo Concepto Relacionado....[%d]"
			                        ,LOG04
			                        ,i,pstApli->stRegistro[i].iCod_Grupo
			                        ,i,pstApli->stRegistro[i].iCod_Concepto
			                        ,i,pstApli->stRegistro[i].iCod_ConRel)      ;
            pstApli->iNumAplica ++;
        }
    }

    vDTrazasLog  (modulo,"\t\t***** Fin Funcion Concepto de Grupo de Aplicacion *****", LOG04);
    return(TRUE);

}
/*************************** Final iCargaconceptoAplica *****************************/



/*****************************************************************************/
/*  Funcion : bCargaCuadrante                                                */
/* -Funcion que carga los cuadrantes de descuentos                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bCargaCuadrante (int iNum_Cuadrante, char *szFecParam, GRUPOCUADRANTE  *pstCuadra)
{
    char modulo[]   = "bCargaCuadrante";
    int  iNumRegs =0;
    int  i=0;
    char Cuadra_Err[7];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    char    szhFecParam    [15];/* EXEC SQL VAR szhFecParam  IS STRING(15); */ 

	    int     ihNum_Cuadrante    ;
	    double  dahVal_Desde        [MAX_REGISTROS]    ;
	    double  dahVal_Hasta        [MAX_REGISTROS]    ;
	    /* VARCHAR szahTip_Descuento   [MAX_REGISTROS][3] ; */ 
struct { unsigned short len; unsigned char arr[6]; } szahTip_Descuento[3000];

	    double  dahVal_Descuento    [MAX_REGISTROS]    ;
	    /* VARCHAR szahTip_Moneda      [MAX_REGISTROS][3] ; */ 
struct { unsigned short len; unsigned char arr[6]; } szahTip_Moneda[3000];

	    short   i_shVal_Hasta       [MAX_REGISTROS]    ;
	    short   i_shTip_Moneda      [MAX_REGISTROS] ;
    /* EXEC SQL END DECLARE SECTION; */ 


    ihNum_Cuadrante =  iNum_Cuadrante;
    strcpy(szhFecParam,szFecParam);
    sprintf(Cuadra_Err,"%d",iNum_Cuadrante);

    vDTrazasLog (modulo,"\n\t\t***** Function bCargaCuadrante *****"
		                 "\n\t\t\tCarga Concepto con Numero de Cuadrante [%d] - Fecha [%s]"
		                 , LOG04,ihNum_Cuadrante,szhFecParam);

    /* EXEC SQL
    SELECT VAL_DESDE           ,
           VAL_HASTA           ,
           TIP_DESCUENTO       ,
           VAL_DESCUENTO       ,
           TIP_MONEDA
      INTO :dahVal_Desde       ,
           :dahVal_Hasta :i_shVal_Hasta       ,
           :szahTip_Descuento  ,
           :dahVal_Descuento   ,
           :szahTip_Moneda :i_shTip_Moneda
      FROM FAD_CUADRANDESC
     WHERE NUM_CUADRANTE = :ihNum_Cuadrante
       AND TO_DATE(:szhFecParam,'yyyymmddhh24miss') BETWEEN FEC_DESDE AND FEC_HASTA; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select VAL_DESDE ,VAL_HASTA ,TIP_DESCUENTO ,VAL_DESCUENTO\
 ,TIP_MONEDA into :b0,:b1:b2,:b3,:b4,:b5:b6  from FAD_CUADRANDESC where (NUM_C\
UADRANTE=:b7 and TO_DATE(:b8,'yyyymmddhh24miss') between FEC_DESDE and FEC_HAS\
TA)";
    sqlstm.iters = (unsigned int  )3000;
    sqlstm.offset = (unsigned int  )268;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)dahVal_Desde;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )sizeof(double);
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqharc[0] = (unsigned long  *)0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)dahVal_Hasta;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[1] = (         int  )sizeof(double);
    sqlstm.sqindv[1] = (         short *)i_shVal_Hasta;
    sqlstm.sqinds[1] = (         int  )sizeof(short);
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqharc[1] = (unsigned long  *)0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)szahTip_Descuento;
    sqlstm.sqhstl[2] = (unsigned long )5;
    sqlstm.sqhsts[2] = (         int  )8;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqharc[2] = (unsigned long  *)0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)dahVal_Descuento;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[3] = (         int  )sizeof(double);
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqharc[3] = (unsigned long  *)0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (unsigned char  *)szahTip_Moneda;
    sqlstm.sqhstl[4] = (unsigned long )5;
    sqlstm.sqhsts[4] = (         int  )8;
    sqlstm.sqindv[4] = (         short *)i_shTip_Moneda;
    sqlstm.sqinds[4] = (         int  )sizeof(short);
    sqlstm.sqharm[4] = (unsigned long )0;
    sqlstm.sqharc[4] = (unsigned long  *)0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqhstv[5] = (unsigned char  *)&ihNum_Cuadrante;
    sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[5] = (         int  )sizeof(int);
    sqlstm.sqindv[5] = (         short *)0;
    sqlstm.sqinds[5] = (         int  )0;
    sqlstm.sqharm[5] = (unsigned long )0;
    sqlstm.sqadto[5] = (unsigned short )0;
    sqlstm.sqtdso[5] = (unsigned short )0;
    sqlstm.sqhstv[6] = (unsigned char  *)szhFecParam;
    sqlstm.sqhstl[6] = (unsigned long )15;
    sqlstm.sqhsts[6] = (         int  )15;
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



    iNumRegs = SQLROWS;
    vDTrazasLog (modulo,"\t\tSqlcode [%d]"
                 "\n\t\tCantidad de Registros del Cuadrante [%d] - [%d]"
                 ,LOG04,SQLCODE,ihNum_Cuadrante,iNumRegs);

    if( SQLCODE != SQLNOTFOUND && SQLCODE != SQLOK )
    {
        vDTrazasLog (modulo,"\n\t\tError en Select de Cuadrante de Descuentos",LOG03);
        iDError (szExeName,ERR000,vInsertarIncidencia,"Select de Cuadrante de Descuentos", szfnORAerror());
        return(FALSE);
    }

    if( (SQLCODE == SQLNOTFOUND) && (iNumRegs == 0) )
    {
        vDTrazasLog (modulo,"\n\t\tNumero de Cuadrante [%d] no existe",LOG03,ihNum_Cuadrante);
        iDError (szExeName,ERR000,vInsertarIncidencia,"Numero de Cuadrante no existe", szfnORAerror());
        return(FALSE);
    }

    if( iNumRegs > 0 )
    {
        for( i=0;i<iNumRegs;i++ )
        {
            pstCuadra->stRegistro[i].iNum_Cuadrante    =   ihNum_Cuadrante;
            pstCuadra->stRegistro[i].dVal_Desde        =   dahVal_Desde[i];

            if( i_shVal_Hasta[i] == ORA_NULL )
                pstCuadra->stRegistro[i].dVal_Hasta = ORA_NULL;
            else
                pstCuadra->stRegistro[i].dVal_Hasta = dahVal_Hasta[i];

            sprintf(pstCuadra->stRegistro[i].szTip_Descuento,"%.*s\0",szahTip_Descuento[i].len, szahTip_Descuento[i].arr);
            pstCuadra->stRegistro[i].dVal_Descuento    =   dahVal_Descuento   [i];

            if( i_shTip_Moneda[i] == ORA_NULL )
                sprintf(pstCuadra->stRegistro[i].szTip_Moneda,"\0");
            else
                sprintf(pstCuadra->stRegistro[i].szTip_Moneda,"%.*s\0",szahTip_Moneda[i].len, szahTip_Moneda[i].arr);

            vDTrazasLog (szExeName, "\n\t\t***** Function vPrintCuadrantesDescuentos *****"
                                    "\n\t\t[%d]-Numero Cuadrante...[%d]"
                                    "\n\t\t[%d]-Valor Desde........[%f]"
                                    "\n\t\t[%d]-Valor Hasta........[%f]"
                                    "\n\t\t[%d]-Tipo Descuento.....[%s]"
                                    "\n\t\t[%d]-Valor Descuento....[%f]"
                                    "\n\t\t[%d]-Tipo de Moneda.....[%s]"
                                    ,LOG04
                                    ,i,pstCuadra->stRegistro[i].iNum_Cuadrante
                                    ,i,pstCuadra->stRegistro[i].dVal_Desde
                                    ,i,pstCuadra->stRegistro[i].dVal_Hasta
                                    ,i,pstCuadra->stRegistro[i].szTip_Descuento
                                    ,i,pstCuadra->stRegistro[i].dVal_Descuento
                                    ,i,pstCuadra->stRegistro[i].szTip_Moneda)     ;
            pstCuadra->iNumCuadrantes ++;
        }
    }

    return(TRUE);

}
/*************************** Final iCargaGrupoEvalua *****************************/

/*****************************************************************************/
static double dValidaMontoMinimo()
{
    int    i = 0 ;
    int    x = 0 ;
    double dtotalfactura = 0.0;
    char   modulo[]="dValidaMontoMinimo";

    for( i=0;i<stPreFactura.iNumRegistros;i++ )
    {
        if( stPreFactura.A_PFactura.iCodTipConce[i]!= CARRIER &&
            stPreFactura.A_PFactura.iCodTipConce[i]!= IMPUESTO )
        {
            dtotalfactura +=  fnCnvDouble(stPreFactura.A_PFactura.dImpFacturable[i],USOFACT);
            vDTrazasLog (modulo,"\t\tdImpFacturable [%f]  - cod_tipconce [%d]  - suma [%f] MFG",
                         LOG04,stPreFactura.A_PFactura.dImpFacturable[i],
                         stPreFactura.A_PFactura.iCodTipConce[i], dtotalfactura);
        vDTrazasLog (modulo,"\t\t dValidaMontoMinimo 1 asigno a stPreFactura.A_PFactura.dImpConcDescApli[%d]=[%f] con [%f] ",LOG04,i, stPreFactura.A_PFactura.dImpConcDescApli[i], stPreFactura.A_PFactura.dImpFacturable[i]);
            stPreFactura.A_PFactura.dImpConcDescApli[i] = stPreFactura.A_PFactura.dImpFacturable[i];
        }
    }

    /* Actualiza Aplicacion de descuentos a conceptos */
    for( i=0;i<stPreFactura.iNumRegistros;i++ )
    {
        if( stPreFactura.A_PFactura.iCodTipConce[i]== DESCUENTO )
        {
            for( x=0;x<stPreFactura.iNumRegistros;x++ )
            {
                if( stPreFactura.A_PFactura.iCodConceRel[i] == stPreFactura.A_PFactura.iCodConcepto[x]
                    && stPreFactura.A_PFactura.lColumnaRel [i] == stPreFactura.A_PFactura.lColumna    [x] )
                {
            vDTrazasLog (modulo,"\t\t dValidaMontoMinimo 2 asigno a stPreFactura.A_PFactura.dImpConcDescApli[%d]=[%f] con [%f] ",LOG04,x,stPreFactura.A_PFactura.dImpConcDescApli[x], stPreFactura.A_PFactura.dImpConcDescApli[x] - fabs(stPreFactura.A_PFactura.dImpConcDescApli[i]));
                    stPreFactura.A_PFactura.dImpConcDescApli[x] =  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli[x] - fabs(stPreFactura.A_PFactura.dImpConcDescApli[i]),USOFACT);
                }

            }
        }
    }
    vDTrazasLog (modulo,"\t\t Total de Validamonto() [%f] ",LOG04,dtotalfactura);

    return(dtotalfactura);
}

/*****************************************************************************/
static double dActualizaDescuentos()
{
    int    i = 0 ;
    double dtotalfactura = 0.0;
    char   modulo[]="dActualizaDescuentos";

    for( i=0;i<stPreFactura.iNumRegistros;i++ )
    {
        if( stPreFactura.A_PFactura.iCodTipConce[i]!= CARRIER  &&
            stPreFactura.A_PFactura.iCodTipConce[i]!= IMPUESTO &&
            stPreFactura.A_PFactura.iCodTipConce[i]!= DESCUENTO )
        {
            dtotalfactura +=  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli[i],USOFACT);
            vDTrazasLog (modulo,"\t\tdImpConcDescApli [%f]  - cod_tipconce [%d]  - suma [%f]",
                         LOG04,stPreFactura.A_PFactura.dImpConcDescApli[i],
                         stPreFactura.A_PFactura.iCodTipConce[i], dtotalfactura);
        }
    }

    return(dtotalfactura);
}
/*****************************************************************************/
/*****************************************************************************/

void vPrintPlanDcto (PLANDCTO *stPD)
{
    vDTrazasLog (szExeName, "\n\t\t***** Function vPrintPlanDcto *****"
                 "\n\t\t-Codigo Tipo Evaluacion....[%s]"
                 "\n\t\t-Codigo Tipo Aplicacion....[%s]"
                 "\n\t\t-Codigo Grupo Evaluacion...[%d]"
                 "\n\t\t-Codigo Grupo Aplicacion...[%d]"
                 "\n\t\t-Numero Cuadrante..........[%d]"
                 "\n\t\t-Tipo de Unidad............[%s]"
                 "\n\t\t-Codigo Concepto Descuento.[%d]"
                 "\n\t\t-Monto Minimo Facturado....[%f]"
                 ,LOG04
                 ,stPD->szCod_Tipeval         ,stPD->szCod_Tipapli
                 ,stPD->iCod_Grupoeval        ,stPD->iCod_Grupoapli
                 ,stPD->iNum_Cuadrante        ,stPD->szTip_Unidad
                 ,stPD->iCod_Concdesc         ,stPD->dMto_Minfact);

}/************************* Final vPrintPlanDcto ******************************/


/*****************************************************************************/
/*  Funcion : bEvaluaciondeConceptos                                         */
/* -Funcion que cuenta la cantidad de conceptos de evaluacion                */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bEvaluaciondeConceptos  ( PLANDCTO *stPD
                                      , GRUPOCONCEVAL *stEval
                                      , double *dTotalfac
                                      , char *szFecParam
                                      , double dTotalMontoPrefactura)
{
    int    iInd    = 0;
    int    iIndF   = 0;
    int    iExiste = 0;
    double dtotal  = 0.0;
    double dtotalunidad = 0.0;
    char   modulo[] = "bEvaluaciondeConceptos";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhFechaAlta ;
    char szhFechaParam   [15];
    char szhFechaCliente [15];
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (modulo,"\n\t***** Function %s *****",LOG04, modulo);
    strcpy(szhFechaParam,szFecParam);
    strcpy(szhFechaCliente,stCliente.szFecAlta);

    if( strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0 )
    {
/* 20040413 CH-200403091728 Se agrega control por Abonado */
        if(strcmp(szEntidad, TIPOENTABONA) == 0)
        {
            for( iInd=0;iInd<stEval->iNumEval;iInd++ )
            {
                vDTrazasLog (modulo,"ABO\t Concepto Evaluacion [%d]   Cod.Grupo[%d]   Ind.Obligat[%s]",
                             LOG04,stEval->stRegistro[iInd].iCod_Concepto
                             ,stEval->stRegistro[iInd].iCod_Grupo
                             ,stEval->stRegistro[iInd].szInd_Obliga);

                iExiste = 0; dtotalunidad  = 0; dtotal = 0;

                for( iIndF=0;iIndF<stPreFactura.iNumRegistros;iIndF++ )
                {
                    if( (stEval->stRegistro[iInd].iCod_Concepto == stPreFactura.A_PFactura.iCodConcepto[iIndF])
                        && (stPreFactura.A_PFactura.lNumAbonado[iIndF] == lgAbonado )
                        && (stPreFactura.A_PFactura.iCodTipConce[iIndF] == ARTICULO ) )
                    {
                        vDTrazasLog (modulo,"ABO\t\t* Conc.Evalua.de PreFactura [%d]"
                                     ,LOG04,stPreFactura.A_PFactura.iCodConcepto[iIndF]);
                        if( strcmp(stPD->szTip_Unidad,UNIDADMINUTOS)==0 )
                        {
                            vDTrazasLog (modulo,"ABO\t\t\t Concepto por UNIDADMINUTOS ",LOG04);
                            dtotalunidad += fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            dtotal += stPreFactura.A_PFactura.lSegConsumido[iIndF];
                            iExiste = 1;
                        }
                        else if( strcmp(stPD->szTip_Unidad,MONTOFACTURA)==0 )
                        {
                            vDTrazasLog (modulo,"ABO\t\t\t Concepto por MONTOFACTURA ",LOG04);
                            dtotalunidad += fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            dtotal +=  fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            iExiste = 1;
                        }
                        vDTrazasLog (modulo,"ABO\t\t\t Valor Monto por Concepto [%f] ",LOG04,dtotal);
                    }
                }

                if( (iExiste == 0) && (strcmp(stEval->stRegistro[iInd].szInd_Obliga,CONCEPTOBLIGADO)==0) )
                {
                    *dTotalfac = 0.0;
                    vDTrazasLog (modulo,"\nABO\t\t* Concepto [%d] es Obligatorio y no Existe en PreFactura",LOG04,stEval->stRegistro[iInd].iCod_Concepto);
                    return(TRUE);
                }
                if( (stEval->stRegistro[iInd].dMto_MinFact > 0) && (dtotalunidad < stEval->stRegistro[iInd].dMto_MinFact) )
                {
                    *dTotalfac = 0.0;
                    vDTrazasLog (modulo,"\nABO\t\t* Monto Acumulado es menor al Minimo a Facturar"
                                 "\nABO\t\t* Monto Acumulado [%f] Minimo a Facturar[%f]"
                                 ,LOG04,dtotalunidad,stEval->stRegistro[iInd].dMto_MinFact);
                    return(TRUE);
                }

                *dTotalfac +=  fnCnvDouble(dtotal,USOFACT);
                vDTrazasLog (modulo,"ABO\t\t------> Monto Total a Calcular es [%f]\n",LOG04,*dTotalfac);
            }
        }
        else
        {
            for( iInd=0;iInd<stEval->iNumEval;iInd++ )
            {
                vDTrazasLog (modulo,"\tConcepto Evaluacion [%d]   Cod.Grupo[%d]   Ind.Obligat[%s]",
                             LOG04,stEval->stRegistro[iInd].iCod_Concepto
                             ,stEval->stRegistro[iInd].iCod_Grupo
                             ,stEval->stRegistro[iInd].szInd_Obliga);

                iExiste = 0; dtotalunidad  = 0; dtotal = 0;

                for( iIndF=0;iIndF<stPreFactura.iNumRegistros;iIndF++ )
                {
                    if( (stEval->stRegistro[iInd].iCod_Concepto == stPreFactura.A_PFactura.iCodConcepto[iIndF])
                        && (stPreFactura.A_PFactura.iCodTipConce[iIndF] == ARTICULO ) )
                    {
                        vDTrazasLog (modulo,"\t\t*ERERERERConc.Evalua.de PreFactura [%d]"
                                     ,LOG04,stPreFactura.A_PFactura.iCodConcepto[iIndF]);
                        if( strcmp(stPD->szTip_Unidad,UNIDADMINUTOS)==0 )
                        {
                            vDTrazasLog (modulo,"\t\t\t Concepto por UNIDADMINUTOS ",LOG04);
                            dtotalunidad += fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            dtotal += stPreFactura.A_PFactura.lSegConsumido[iIndF];
                            iExiste = 1;
                        }
                        else if( strcmp(stPD->szTip_Unidad,MONTOFACTURA)==0 )
                        {
                            vDTrazasLog (modulo,"\t\t\t Concepto por MONTOFACTURA ",LOG04);
                            dtotalunidad += fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            dtotal +=  fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                            iExiste = 1;
                        }
                        vDTrazasLog (modulo,"\t\t\t Valor Monto por Concepto [%f] ",LOG04,dtotal);
                    }
                }

                if( (iExiste == 0) && (strcmp(stEval->stRegistro[iInd].szInd_Obliga,CONCEPTOBLIGADO)==0) )
                {
                    *dTotalfac = 0.0;
                    vDTrazasLog (modulo,"\n\t\t* Concepto [%d] es Obligatorio y no Existe en PreFactura",LOG04,stEval->stRegistro[iInd].iCod_Concepto);
                    return(TRUE);
                }
                if( (stEval->stRegistro[iInd].dMto_MinFact > 0) && (dtotalunidad < stEval->stRegistro[iInd].dMto_MinFact) )
                {
                    *dTotalfac = 0.0;
                    vDTrazasLog (modulo,"\n\t\t* Monto Acumulado es menor al Minimo a Facturar"
                                 "\n\t\t* Monto Acumulado [%f] Minimo a Facturar[%f]"
                                 ,LOG04,dtotalunidad,stEval->stRegistro[iInd].dMto_MinFact);
                    return(TRUE);
                }

                *dTotalfac += fnCnvDouble(dtotal,USOFACT);
                vDTrazasLog (modulo,"\t\t------> Monto Total a Calcular es [%f]\n",LOG04,*dTotalfac);
            }
        }
    }
    else
    {  /* por factura*/
        if( strcmp(stPD->szTip_Unidad,CANTIDADABONADOS)==0 )
        {
            *dTotalfac = stAbonoCli.lNumAbonados;
            vDTrazasLog (modulo,"\t\t Factura por CANTIDADABONADOS "
                         "\n\t\t Factura por [%f] ",LOG04,*dTotalfac);
        }

        if( strcmp(stPD->szTip_Unidad,ANTIGUEDADCLIENTE)==0 )
        {
            vDTrazasLog (modulo,"\t\t Factura por ANTIGUEDADCLIENTE ",LOG04);

            /* EXEC SQL
            SELECT ROUND(TO_DATE(:szhFechaParam,'yyyymmddhh24miss') - TO_DATE(:szhFechaCliente,'yyyymmddhh24miss'))
            INTO :lhFechaAlta FROM dual; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ROUND((TO_DATE(:b0,'yyyymmddhh24miss')-TO_\
DATE(:b1,'yyyymmddhh24miss'))) into :b2  from dual ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )311;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szhFechaParam;
            sqlstm.sqhstl[0] = (unsigned long )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhFechaCliente;
            sqlstm.sqhstl[1] = (unsigned long )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhFechaAlta;
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



            if( SQLCODE != SQLOK )
            {
                vDTrazasLog (modulo,"\n\t\tError en Select para Calcular de Fecha Alta",LOG03);
                iDError (szExeName,ERR000,vInsertarIncidencia,"Select para Calcular de Fecha Alta", szfnORAerror());
                return(FALSE);
            }
            if( SQLCODE == SQLOK )
                *dTotalfac = lhFechaAlta;
            vDTrazasLog (modulo,"\t\t Factura por [%f] ",LOG04,*dTotalfac);
        }
        if( strcmp(stPD->szTip_Unidad,MONTOFACTURA)==0 )
        {
            *dTotalfac = fnCnvDouble(dTotalMontoPrefactura,USOFACT);
            vDTrazasLog (modulo,"\t\t Factura por MONTOFACTURA "
                         "\n\t\t dTotalMontoPrefactura por [%f] ",LOG04,dTotalMontoPrefactura);
            if( *dTotalfac <= stPD->dMto_Minfact )
            {
                vDTrazasLog (modulo,"\t\t--> Monto Minimo es Mayor que el Monto a Facturar"
                             "\t\t--> Monto Minimo [%f] - Monto a Facturar [%f]"
                             ,LOG04,*dTotalfac,stPD->dMto_Minfact);
                return(TRUE);
            }
            vDTrazasLog (modulo,"\t\t Factura por [%f] ",LOG04,*dTotalfac);

        }
    }
    vDTrazasLog (modulo,"\n\t***** Fin Evaluacion de Conceptos *****",LOG04);
    return(TRUE);
}

/*****************************************************************************/

/*****************************************************************************/
/*  Funcion : bAplicacionConceptos                                           */
/* -Funcion que aplica conceptos de descuentos                               */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bAplicacionConceptos  (long lNumAbonado, PLANDCTO *stPD ,GRUPOCONAPLI *stApli
                                   ,VALORDESCUENTO *pstDescPaso, char *szFecParam)
{
    int    i                = 0;
    int    iInd             = 0;
    int    iNumConceptos    = 0;
    char   modulo[] = "bAplicaciondeConceptos";

    vDTrazasLog (modulo,"\n\t\t***** Function bAplicaciondeConceptos *****"
		                "\n\t\t\t Aplicacion por PORCONCEPTO MONTO ENTRANTE MFG [%f]"
		                "\n\t\t\t Nro. de Abonado [%ld]"
		                ,LOG05, dTotalMontoPrefacDesc, lNumAbonado);

    iNumConceptos = stPreFactura.iNumRegistros;

    for( iInd=0;(iInd<stApli->iNumAplica );iInd++ )
    {
        vDTrazasLog (modulo,"\n\t\t\tConcepto de Aplicacion stApli MFG[%d]"
                     ,LOG04,stApli->stRegistro[iInd].iCod_Concepto);

        for( i=0;(i<iNumConceptos);i++ )
        {
            if( stPreFactura.A_PFactura.lNumAbonado      [i] == lNumAbonado
                && stPreFactura.A_PFactura.iCodConcepto     [i] == stApli->stRegistro[iInd].iCod_Concepto
                && stPreFactura.A_PFactura.dImpConcDescApli [i] >  0 )
            {
                vDTrazasLog (modulo,"\t\t\tbAplicacionConceptos Concepto de Aplicacion stPrefactura MFG [%d]",LOG04,stPreFactura.A_PFactura.iCodConcepto[i]);
                strcpy(stValDesc.stDescuentos[idxDesc].szTip_Moneda     ,pstDescPaso->szTip_Moneda);
                stValDesc.stDescuentos[idxDesc].dVal_Descuento =  fnCnvDouble(pstDescPaso->dVal_Descuento,USOFACT);
                strcpy(stValDesc.stDescuentos[idxDesc].szTip_Descuento  ,pstDescPaso->szTip_Descuento);

        vDTrazasLog (modulo,"\n\t\t\tstPreFactura.A_PFactura.dImpConcDescApli MFG [%d](%f) - stValDesc.stDescuentos[%d].dValor_Monto(%f)  =  [%f]", /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */
            LOG05, i, stPreFactura.A_PFactura.dImpConcDescApli [i], idxDesc, stValDesc.stDescuentos[idxDesc].dValor_Monto, fnCnvDouble((stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto),USOFACT) ); /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */

                if( strcmp(stValDesc.stDescuentos[idxDesc].szTip_Descuento,TIPOPORCENTAJE)==0 )
                {
                    stValDesc.stDescuentos[idxDesc].dValor_Monto =  fnCnvDouble((stPreFactura.A_PFactura.dImpConcepto[i] * stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100,USOFACT);
                    vDTrazasLog (modulo,"\t\t\tbAplicacionConceptos Descuento por TIPOPORCENTAJE dValor_Monto MFG[%d]=[%f] [dImpConcepto[%d] [%f] * dVal_Descuento[%d] [%f] /100]",LOG04,idxDesc,
                    stValDesc.stDescuentos[idxDesc].dValor_Monto,i, stPreFactura.A_PFactura.dImpConcepto[i],idxDesc, stValDesc.stDescuentos[idxDesc].dVal_Descuento);




                }
                else if( strcmp(stValDesc.stDescuentos[idxDesc].szTip_Descuento,TIPOMONTO)==0 )
                {
                    stValDesc.stDescuentos[idxDesc].dValor_Monto =  fnCnvDouble(stValDesc.stDescuentos[idxDesc].dVal_Descuento,USOFACT);
                    vDTrazasLog (modulo,"\t\t\tbAplicacionConceptos Descuento por TIPOMONTO [%f]",LOG04,stValDesc.stDescuentos[idxDesc].dValor_Monto);
                    if( !bConverMoneda (stValDesc.stDescuentos[idxDesc].szTip_Moneda, stDatosGener.szCodMoneFact ,szFecParam ,
                                        &stValDesc.stDescuentos[idxDesc].dValor_Monto, stProceso.iCodTipDocum) )
                        return(FALSE);
                }
                else
                {
                    vDTrazasError (modulo,"\n\t\t\tTipo de Descuento Invalido",LOG01);
                    vDTrazasLog   (modulo,"\n\t\t\tTipo de Descuento Invalido",LOG01);
                    return(FALSE);
                }

                /* Valida que el descuento pueda ser rebajado del valor del concepto */
                vDTrazasLog (modulo,"\t\t bAplicacionConceptos dImpConcDescApli[%d]=[%f] - dValor_Monto[%d]=[%f] = [%f] > 0 ?",LOG05,i,
                stPreFactura.A_PFactura.dImpConcDescApli[i],idxDesc, stValDesc.stDescuentos[idxDesc].dValor_Monto,
                fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT));

                if(  fnCnvDouble((stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto),USOFACT) >  0 )
                {
                    vDTrazasLog (modulo,"\t\t bAplicacionConceptos asigno a stPreFactura.A_PFactura.dImpConcDescApli MFG[%d]=[%f] con [%f] [%f - %f]",LOG05,i,
                    stPreFactura.A_PFactura.dImpConcDescApli[i],
                    stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto,
                    stPreFactura.A_PFactura.dImpConcDescApli [i] ,
                    stValDesc.stDescuentos[idxDesc].dValor_Monto);
                    stPreFactura.A_PFactura.dImpConcDescApli [i]=  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT);
                }
                else
                {
                    stValDesc.stDescuentos[idxDesc].dValor_Monto =  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli [i],USOFACT);
                    vDTrazasLog (modulo,"\n\t\t\tstValDesc.stDescuentos[%d].dValor_Monto  =  [%f]", LOG05, idxDesc, stValDesc.stDescuentos[idxDesc].dValor_Monto ); /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */
                    stPreFactura.A_PFactura.dImpConcDescApli [i]    = 0 ;
                }

                stValDesc.stDescuentos[idxDesc].lNumAbonado    = lNumAbonado;
                stValDesc.stDescuentos[idxDesc].iCod_Concepto  = stApli->stRegistro[iInd].iCod_ConRel;
                stValDesc.stDescuentos[idxDesc].lNumSecuencia  = stPD->lNumSecuencia;
                stValDesc.stDescuentos[idxDesc].iPosPrefac     = i;

                stValDesc.stDescuentos[idxDesc].iNum_Cuadrante = pstDescPaso->iNum_Cuadrante;
                stValDesc.stDescuentos[idxDesc].dVal_Desde     = pstDescPaso->dVal_Desde;
                stValDesc.stDescuentos[idxDesc].dVal_Hasta     = pstDescPaso->dVal_Hasta;

                if( !bValidacionDto (&stValDesc.stDescuentos[idxDesc]) )
                {
                    vDTrazasLog (modulo,"\t\t\tConcepto No Encontrado [%d]"
                                 ,LOG03,stValDesc.stDescuentos[idxDesc].iCod_Concepto);
                    return(FALSE);
                }
                dTotalMontoPrefacDesc=  fnCnvDouble(dTotalMontoPrefacDesc - stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT); /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */
                vDTrazasLog (modulo,"\n\t\t\tbAplicacionConceptos Valor concepto.....MFG[%f]"
                             "\n\t\t\tMonto a Descontar.....MFG[%f]"
                              "\n\t\t\tdTotalMontoPrefacDesc MFG = (%f)"
                             ,LOG05,stPreFactura.A_PFactura.dImpConcepto[i]
                             ,stValDesc.stDescuentos[idxDesc].dValor_Monto,dTotalMontoPrefacDesc); /* Homologado por PGonzalez 31-08-2004 XC-200408110239_130804 */

                vDTrazasLog (modulo,"\n\t bAplicacionConceptos Descuento MFG [%d]=[%c%.02lf] [%lf] [%d] [%s]",LOG04, idxDesc,
                                    (stValDesc.stDescuentos[idxDesc].szTip_Descuento[0]=='P'?'%':'$'),
                                    stValDesc.stDescuentos[idxDesc].dVal_Descuento,
                                    stValDesc.stDescuentos[idxDesc].dValor_Monto,
                                    stValDesc.stDescuentos[idxDesc].iCod_Concepto,
                                    stValDesc.stDescuentos[idxDesc].szDescConcepto);
                idxDesc++;
                stValDesc.iNumDescuentos++;
            }
        }
    }

    vDTrazasLog (modulo,"\n\t***** Fin Aplicacion de Conceptos MONTO SALIENTE [%f]*****",LOG05, dTotalMontoPrefacDesc);
    return(TRUE);
}


/*****************************************************************************/
/*****************************************************************************/
static BOOL bfnDescporConceptoCliente (long lNumAbonado, PLANDCTO *stPD,char *szFecParam
                                       , double dTotalMontoPrefactura )
{
    char   modulo[]         = "bfnDescporConceptoCliente";
    double dTotalfac            = 0.0;
    int    x;
    int    iAbo0 = 0;

    GRUPOCONCEVAL   stEval    ;
    GRUPOCONAPLI    stApli    ;
    GRUPOCUADRANTE  stCuadra  ;
    VALORDESCUENTO  stDescPaso;

    memset (&stEval     ,0,sizeof (GRUPOCONCEVAL));
    memset (&stApli     ,0,sizeof (GRUPOCONAPLI));
    memset (&stCuadra   ,0,sizeof (GRUPOCUADRANTE));
    memset (&stDescPaso ,0,sizeof (VALORDESCUENTO));

    dAjuste = 0;

    vDTrazasLog (modulo,"\n\t\t**** Entrada en bfnDescporConceptoCliente "
                 "\n\t\t=> Nro. Abonado : [%ld]", LOG04, lNumAbonado);
    if( dTotalMontoPrefacDesc <= stPD->dMto_Minfact )
    {
        vDTrazasLog (modulo,"\n\t**Monto a Facturar es Menor que el Monto Minimo Permitido"
                     "\n\t**Monto a Facturar [%f] **Monto Minimo Permitido [%f]"
                     ,LOG04,dTotalMontoPrefactura,stPD->dMto_Minfact);
        return(TRUE);
    }

    /*Carga Concepto de Evaluacion */
    if( !bCargaConceptoEvalua (stPD->iCod_Grupoeval,szFecParam,&stEval) )
    {
        vDTrazasLog(modulo,"*** No cargaron Conceptos de Evaluacion grupo [%d] ***",LOG05,stPD->iCod_Grupoeval);
        return(FALSE);
    }

    /*Contar cantidad de evaluaciones*/
    if( !bEvaluaciondeConceptos (stPD,&stEval, &dTotalfac, szFecParam,dTotalMontoPrefactura) )
    {
        vDTrazasLog(modulo,"*** No se Evaluaron Conceptos en grupo [%d] ***",LOG05,stPD->iCod_Grupoeval);
        return(FALSE);
    }

    vDTrazasLog  (modulo,"\n\t***** Total a Facturar por Evaluacion [%f]", LOG04,dTotalfac);

    /*calculo de descuentos */
    if( dTotalfac > 0 )
    {
        /*carga Concepto de Aplicacion*/
        if( !bCargaConceptoAplica (stPD->iCod_Grupoapli,szFecParam,&stApli) )
        {
            vDTrazasLog(modulo,"*** No cargaron Conceptos de Aplicacion grupo [%d] ***",LOG05,stPD->iCod_Grupoapli);
            return(FALSE);
        }

        if( stApli.iNumAplica > 0 )
        {
            /* Carga Cuadrante de Descuento*/
            if( !bCargaCuadrante (stPD->iNum_Cuadrante,szFecParam,&stCuadra) )
            {
                vDTrazasLog(modulo,"*** No se Cargo Cuadrante [%d] ***",LOG05,stPD->iNum_Cuadrante);
                return(FALSE);
            }

            for( x=0;x < (stAbonoCli.lNumAbonados);x++ )
            {
                if( stAbonoCli.pCicloCli[x].lNumAbonado == 0 )
                    iAbo0=-1;
            }

            if( !bCalculaDescuento(iAbo0, &stDescPaso, &stCuadra, dTotalfac) )
            {
                vDTrazasLog(modulo,"*** No se Calculo Descuento Abonado [%ld] ***",LOG02,iAbo0);
                return(FALSE);
            }

            if( (stDescPaso.dVal_Descuento != 0.0)||(stDescPaso.dVal_Descuento != 0) )
            {

                if( strcmp(stDescPaso.szTip_Descuento,TIPOMONTO)==0 )
                    dAjuste = fnCnvDouble(stDescPaso.dValor_Monto - (( stDescPaso.dVal_Descuento * dTotalfac ) / 100),USOFACT) ;

                vDTrazasLog  (modulo,"\t\t***** bfnDescporConceptoCliente Nro Abonados [%ld] dAjuste=%f", LOG04,stAbonoCli.lNumAbonados,dAjuste);

                /* Se Aplican a los conceptos del Abonado 0 */
                for( x=0;x < (stAbonoCli.lNumAbonados);x++ )
                {
                    if( stAbonoCli.pCicloCli[x].lNumAbonado == 0 )
                    {
                        if( !bAplicacionConceptosCliente(stAbonoCli.pCicloCli[x].lNumAbonado,
                                                         -1,
                                                         stPD,
                                                         &stApli,
                                                         &stDescPaso,
                                                         szFecParam) )
                        {
                            vDTrazasLog(modulo,"*** No se Aplico Conceptos Cliente Abonado [%ld] ***",LOG05,stAbonoCli.pCicloCli[x].lNumAbonado);
                            return(FALSE);
                        }
                    }
                }

                /* Se Aplican a los conceptos de cada Abonado */
                for( x=0;x < (stAbonoCli.lNumAbonados);x++ )
                {
                    if( stAbonoCli.pCicloCli[x].lNumAbonado != 0 )
                    {
                        if( !bAplicacionConceptosCliente(stAbonoCli.pCicloCli[x].lNumAbonado,
                                                         stAbonoCli.pCicloCli[x].lNumAbonado,
                                                         stPD,
                                                         &stApli,
                                                         &stDescPaso,
                                                         szFecParam) )
                        {
                            vDTrazasLog(modulo,"*** No se Aplico Conceptos Cliente Abonado [%ld] ***",LOG05,stAbonoCli.pCicloCli[x].lNumAbonado);
                            return(FALSE);
                        }
                    }
                }

		        vDTrazasLog (modulo,"\n\t bfnDescporConceptoCliente aplico Descuento [%d]=[%c%.02lf] [%lf] [%d] [%f] [%s]",LOG05, idxDesc-1,
		         (stValDesc.stDescuentos[idxDesc-1].szTip_Descuento[0]=='P'?'%':'$'),
		         stValDesc.stDescuentos[idxDesc-1].dVal_Descuento,
		         stValDesc.stDescuentos[idxDesc-1].dValor_Monto,
		         stValDesc.stDescuentos[idxDesc-1].iCod_Concepto,
		         dAjuste,
		         stValDesc.stDescuentos[idxDesc-1].szDescConcepto);

                vDTrazasLog(modulo,"*** bfnDescporConceptoCliente se Sumaba a stDescuentos[%d].dValor_Monto[%f] + [%f] = [%f] ***",LOG05,idxDesc-1, stValDesc.stDescuentos[idxDesc-1].dValor_Monto, dAjuste, stValDesc.stDescuentos[idxDesc -1].dValor_Monto+ dAjuste);
/*                 stValDesc.stDescuentos[idxDesc -1].dValor_Monto+= dAjuste;  */
            }
        }
    }
    else
    {
        vDTrazasLog  (modulo,"\t***** Monto de Evaluacion es [0].No se Pueden Efectuar Descuentos", LOG04);
    }
    return(TRUE);
}
/*****************************************************************************/
/*****************************************************************************/
static BOOL bfnDescporFacturaCliente (long lNumAbonado,PLANDCTO *stPD, char *szFecParam
                                      , double dTotalMontoPrefactura)
{
    char   modulo[]         = "bfnDescporFacturaCliente";
    double dTotalfac        = 0.0;
    int    x;
    int    iAbo0 = 0;
    double dAjuste   ;

    GRUPOCONCEVAL   stEval    ;
    GRUPOCONAPLI    stApli    ;
    GRUPOCUADRANTE  stCuadra  ;
    VALORDESCUENTO  stDescPaso;

    memset (&stEval     ,0,sizeof (GRUPOCONCEVAL)) ;
    memset (&stApli     ,0,sizeof (GRUPOCONAPLI))  ;
    memset (&stCuadra   ,0,sizeof (GRUPOCUADRANTE));
    memset (&stDescPaso ,0,sizeof (VALORDESCUENTO));

    vDTrazasLog (modulo,"\n\t\t*** Entrada en bfnDescporFacturaCliente "
                 "\n\t\t=> Nro. Abonado : [%ld]", LOG04, lNumAbonado);

    if( dTotalMontoPrefacDesc <= stPD->dMto_Minfact )
    {
        vDTrazasLog (modulo,"\n\t**Monto a Facturar es Menor que el Monto Minimo Permitido"
                     "\n\t**Monto a Facturar [%f] **Monto Minimo Permitido [%f]"
                     ,LOG04,dTotalMontoPrefactura,stPD->dMto_Minfact);
/*         iDError (szExeName,ERR000,vInsertarIncidencia,"Monto a Facturar es Menor que el Monto Minimo Permitido", "!");  */
/*         bInsertaAnomProceso (&stAnomProceso);                                                                           */
        return(TRUE);
    }

    /*Contar cantidad de evaluaciones*/
    if( !bEvaluaciondeConceptos (stPD, &stEval, &dTotalfac, szFecParam, dTotalMontoPrefactura) )
    {
        vDTrazasLog(modulo,"*** No se Evaluaron Conceptos en grupo [%d] ***",LOG05,stPD->iCod_Grupoeval);
        return(FALSE);
    }

    vDTrazasLog  (modulo,"\n\t***** Total a Facturar por Evaluacion [%f]", LOG04,dTotalfac);

    /*calculo de descuentos */
    if( dTotalfac > 0 )
    {
        /* Carga Cuadrante de Descuento*/
        if( !bCargaCuadrante (stPD->iNum_Cuadrante, szFecParam, &stCuadra) )
        {
            vDTrazasLog(modulo,"*** No se Cargo Cuadrante [%d] ***",LOG05,stPD->iNum_Cuadrante);
            return(FALSE);
        }

        for( x=0;x < (stAbonoCli.lNumAbonados);x++ )
        {
            if( stAbonoCli.pCicloCli[x].lNumAbonado == 0 )
                iAbo0=-1;
        }
        if( !bCalculaDescuento(iAbo0, &stDescPaso, &stCuadra, dTotalfac) )
        {
            vDTrazasLog(modulo,"*** No se Calculo Descuento Abonado [%ld] ***",LOG05,iAbo0);
            return(FALSE);
        }

        if( (stDescPaso.dVal_Descuento != 0.0)||(stDescPaso.dVal_Descuento != 0) )
        {

            if( strcmp(stDescPaso.szTip_Descuento,TIPOMONTO)==0 )
            {
                dAjuste =  fnCnvDouble(stDescPaso.dValor_Monto - (( stDescPaso.dVal_Descuento * dTotalfac ) / 100) ,USOFACT);
            }
            vDTrazasLog  (modulo,"\t\t***** bfnDescporFacturaCliente Nro Abonados [%ld] dAjuste=%f", LOG04,stAbonoCli.lNumAbonados,dAjuste);

            for( x=0;x < (stAbonoCli.lNumAbonados);x++ )
            {
                if( !bAplicacionConceptosFacturaCliente(stAbonoCli.pCicloCli[x].lNumAbonado,
                                                        stPD,
                                                        &stDescPaso,
                                                        /*szFecParam, */
                                                        dTotalMontoPrefactura) )
                {
                    vDTrazasLog(modulo,"*** No se Aplico Conceptos Factura Cliente Abonado [%ld] ***",LOG05,stAbonoCli.pCicloCli[x].lNumAbonado);
                    return(FALSE);
                }
                vfnPrintCuadrante(&stValDesc.stDescuentos[idxDesc]);
                stValDesc.iNumDescuentos++;
            }

        vDTrazasLog (modulo,"\n\t bfnDescporFacturaCliente aplico Descuento [%d]=[%c%.02lf] [%lf] [%d] [%f] [%s]",LOG05, idxDesc-1,
	         (stValDesc.stDescuentos[idxDesc-1].szTip_Descuento[0]=='P'?'%':'$'),
	         stValDesc.stDescuentos[idxDesc-1].dVal_Descuento,
	         stValDesc.stDescuentos[idxDesc-1].dValor_Monto,
	         stValDesc.stDescuentos[idxDesc-1].iCod_Concepto,
	         dAjuste,
	         stValDesc.stDescuentos[idxDesc-1].szDescConcepto);

          vDTrazasLog(modulo,"*** bfnDescporFacturaCliente se Sumaba a stDescuentos[%d].dValor_Monto[%f] + [%f] = [%f] ***",LOG05,idxDesc-1, stValDesc.stDescuentos[idxDesc-1].dValor_Monto, dAjuste, stValDesc.stDescuentos[idxDesc -1].dValor_Monto+ dAjuste);
        }
    }
    else
    {
        vDTrazasLog  (modulo,"\t***** Monto de Evaluacion es [0].No se Pueden Efectuar Descuentos", LOG04);
    }
    return(TRUE);
}

/*****************************************************************************/
/*  Funcion : bAplicacionConceptosCliente                                    */
/* -Funcion que aplica conceptos de descuentos                               */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bAplicacionConceptosCliente (long lNumAbonadoDest   , long lNumAbonadoOrig
                                         ,PLANDCTO *stPD          , GRUPOCONAPLI *stApli
                                         ,VALORDESCUENTO *stDescuentos, char *szFecParam)
{
    int    i       = 0;
    int    iInd    = 0;
    int    iNumConceptos  = 0;
    char   modulo[] = "bAplicacionConceptosCliente";

    vDTrazasLog (modulo,"\n\t\t***** Function bAplicacionConceptosCliente *****"
                 "\n\t\t\t Aplicacion por CONCEPTO",LOG04);

    iNumConceptos = stPreFactura.iNumRegistros;

    for( iInd=0;(iInd<stApli->iNumAplica );iInd++ )
    {
        vDTrazasLog (modulo,"\t\tConcepto de Aplicacion stApli [%d] a [%d]"
                     ,LOG04,stApli->stRegistro[iInd].iCod_Concepto, stApli->stRegistro[iInd].iCod_ConRel);

        for( i=0;(i<iNumConceptos);i++ )
        {

            if( stPreFactura.A_PFactura.lNumAbonado      [i] == lNumAbonadoOrig
                && stPreFactura.A_PFactura.iCodConcepto     [i] == stApli->stRegistro[iInd].iCod_Concepto
                && stPreFactura.A_PFactura.dImpConcDescApli [i] >  0 )
            {
                vDTrazasLog (modulo ,"\t\tbAplicacionConceptosCliente Concepto de Aplicacion stPrefactura [%d] [%ld] [%ld] [%ld]"
                             ,LOG04,stPreFactura.A_PFactura.iCodConcepto[i]
                             ,stPreFactura.A_PFactura.lNumAbonado [i]
                             ,lNumAbonadoDest,lNumAbonadoOrig );
                stValDesc.stDescuentos[idxDesc].dVal_Descuento=  fnCnvDouble(stDescuentos->dVal_Descuento,USOFACT);
                vDTrazasLog (modulo ,"\t\tbAplicacionConceptosCliente 1 Valor_Monto[%d]=[%f] por [%f] (dImpConcepto[%d]=[%f] * dVal_Descuento[%d]=[%f] /100)", LOG04, idxDesc,stValDesc.stDescuentos[idxDesc].dValor_Monto , (stPreFactura.A_PFactura.dImpConcepto[i]*stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100, i, stPreFactura.A_PFactura.dImpConcepto[i], idxDesc, stValDesc.stDescuentos[idxDesc].dVal_Descuento);
                stValDesc.stDescuentos[idxDesc].dValor_Monto = fnCnvDouble((stPreFactura.A_PFactura.dImpConcepto[i] * stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100,USOFACT);
                vDTrazasLog (modulo ,"\t\tbAplicacionConceptosCliente 2 Valor_Monto[%d]=[%f] - dImpConcDescApli[%d]=[%f] = [%f] > 0 ?", LOG04, idxDesc,stValDesc.stDescuentos[idxDesc].dValor_Monto , i, stPreFactura.A_PFactura.dImpConcDescApli [i], (stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto));

                /*  Se valida que el remanente del concepto cubra el descuento */
                if(  fnCnvDouble((stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto),USOFACT) >  0 )
                {
vDTrazasLog (modulo,"\t\t bAplicacionConceptosCliente asigno a stPreFactura.A_PFactura.dImpConcDescApli[%d]=[%f] con [%f] ",LOG04,i, stPreFactura.A_PFactura.dImpConcDescApli[i],  stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto);
                    stPreFactura.A_PFactura.dImpConcDescApli [i]=  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli [i] - stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT);
                }
                else
                {
    vDTrazasLog (modulo,"\n\t\tbAplicacionConceptosCliente Se reemplazara Valor_Monto [%f] con dImpConcDescApli [%f]", LOG05, stValDesc.stDescuentos[idxDesc].dValor_Monto , stPreFactura.A_PFactura.dImpConcDescApli [i]);
                    stValDesc.stDescuentos[idxDesc].dValor_Monto =  fnCnvDouble(stPreFactura.A_PFactura.dImpConcDescApli [i],USOFACT);
                    stPreFactura.A_PFactura.dImpConcDescApli [i]    = 0 ;
    vDTrazasLog (modulo,"\n\t\tbAplicacionConceptosCliente Se reemplazo Valor_Monto [%f], ahora dImpConcDescApli= [%f]", LOG05, stValDesc.stDescuentos[idxDesc].dValor_Monto , stPreFactura.A_PFactura.dImpConcDescApli [i]);
                }

                stValDesc.stDescuentos[idxDesc].lNumSecuencia = stPD->lNumSecuencia;
                stValDesc.stDescuentos[idxDesc].lNumAbonado   = lNumAbonadoDest;
                stValDesc.stDescuentos[idxDesc].iCod_Concepto = stApli->stRegistro[iInd].iCod_ConRel;
                stValDesc.stDescuentos[idxDesc].iNum_Cuadrante= stDescuentos->iNum_Cuadrante;
                stValDesc.stDescuentos[idxDesc].dVal_Desde    = stDescuentos->dVal_Desde;
                stValDesc.stDescuentos[idxDesc].dVal_Hasta    = stDescuentos->dVal_Hasta;
                stValDesc.stDescuentos[idxDesc].iPosPrefac    = i;

                if( !bValidacionDto (&stValDesc.stDescuentos[idxDesc]) )
                {
                    vDTrazasLog (modulo,"\n\t\tConcepto No Encontrado [%d]",LOG04,stValDesc.stDescuentos[idxDesc].iCod_Concepto);
                    return(FALSE);
                }

                strcpy (stValDesc.stDescuentos[idxDesc].szTip_Descuento  ,stDescuentos->szTip_Descuento )  ;
                strcpy (stValDesc.stDescuentos[idxDesc].szTip_Moneda     ,stDescuentos->szTip_Moneda);


                vDTrazasLog  (modulo,"\t\t***** bAplicacionConceptosCliente  [%f]!=[%f] dAjuste[%f]+=%f;", LOG04,
                fnCnvDouble(stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT),
                fnCnvDouble((stPreFactura.A_PFactura.dImpConcepto[i]*stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100,USOFACT),
                dAjuste,
                fnCnvDouble((((stPreFactura.A_PFactura.dImpConcepto[i] * stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100) - stValDesc.stDescuentos[idxDesc].dValor_Monto),USOFACT) );

                if( fnCnvDouble(stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT) != (fnCnvDouble((stPreFactura.A_PFactura.dImpConcepto[i]*stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100,USOFACT)) )
                {
                    dAjuste+= fnCnvDouble(((stPreFactura.A_PFactura.dImpConcepto[i] * stValDesc.stDescuentos[idxDesc].dVal_Descuento)/100) - stValDesc.stDescuentos[idxDesc].dValor_Monto, USOFACT );
                }

                vDTrazasLog (modulo,"\n\t\t\tbAplicacionConceptosCliente Numero Abonado.....[%ld]"
                             "\n\t\t\tValor descuento....[%f]"
                             "\n\t\t\tValor concepto.....[%f]"
                             "\n\t\t\tValor concepto fac.[%f]"
                             "\n\t\t\tMonto a descontar..[%f]"
                             "\n\t\t\tMonto de Ajuste....[%f]"
                             "\n\t\t\tTotal Anterior.....[%f]"
                             "\n\t\t\tTotal Nuevo........[%f]"
                             ,LOG04,stValDesc.stDescuentos[idxDesc].lNumAbonado
                             ,stValDesc.stDescuentos[idxDesc].dVal_Descuento
                             ,stPreFactura.A_PFactura.dImpConcepto[i]
                             ,stPreFactura.A_PFactura.dImpFacturable[i]
                             ,stValDesc.stDescuentos[idxDesc].dValor_Monto
                             ,dAjuste, dTotalMontoPrefacDesc, dTotalMontoPrefacDesc - stValDesc.stDescuentos[idxDesc].dValor_Monto);
                dTotalMontoPrefacDesc=  fnCnvDouble(dTotalMontoPrefacDesc - stValDesc.stDescuentos[idxDesc].dValor_Monto,USOFACT);

        vDTrazasLog (modulo,"\n\t bAplicacionConceptosCliente Descuento [%d]=[%c%.02lf] [%lf] [%d] [%f] [%s]",LOG04, idxDesc,
         (stValDesc.stDescuentos[idxDesc].szTip_Descuento[0]=='P'?'%':'$'),
         stValDesc.stDescuentos[idxDesc].dVal_Descuento,
         stValDesc.stDescuentos[idxDesc].dValor_Monto,
         stValDesc.stDescuentos[idxDesc].iCod_Concepto,
         dTotalMontoPrefacDesc,
         stValDesc.stDescuentos[idxDesc].szDescConcepto);

                idxDesc++;
                stValDesc.iNumDescuentos++;
            }
        }
    }
    vDTrazasLog (modulo,"\n\t***** Fin Aplicacion de Conceptos *****",LOG04);
    return(TRUE);
}

/*****************************************************************************/
/*  Funcion : bAplicacionConceptosFacturaCliente                             */
/* -Funcion que aplica conceptos de descuentos                               */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/

static BOOL bAplicacionConceptosFacturaCliente (long lNumAbonado, PLANDCTO *stPD
                                                , VALORDESCUENTO *stDescuentos
                                                , double dTotalMontoPrefactura )
{
    int    i       = 0;
    char   modulo[] = "bAplicacionConceptosFacturaCliente";

    vDTrazasLog (modulo,"\n\t***** Function bAplicacionConceptosFacturaCliente *****",LOG04);

    if( dTotalMontoPrefactura > 0 )
    {
        for( i=0;i<stPreFactura.iNumRegistros;i++ )
        {
            if( stPreFactura.A_PFactura.iCodTipConce[i]!= CARRIER  &&
                stPreFactura.A_PFactura.iCodTipConce[i]!= IMPUESTO &&
                stPreFactura.A_PFactura.lNumAbonado [i]== lNumAbonado )
            {
                if( stPreFactura.A_PFactura.dImpConcDescApli[i] > 0 )
                {
                    stValDesc.stDescuentos[idxDesc].iCod_Concepto = stPD->iCod_Concdesc;
                    stValDesc.stDescuentos[idxDesc].lNumSecuencia = stPD->lNumSecuencia;
                    stValDesc.stDescuentos[idxDesc].iPosPrefac=i;
                    strcpy(stValDesc.stDescuentos[idxDesc].szTip_Moneda     ,stDescuentos->szTip_Moneda);
                    strcpy(stValDesc.stDescuentos[idxDesc].szTip_Descuento  ,stDescuentos->szTip_Descuento);
                    stValDesc.stDescuentos[idxDesc].dVal_Descuento = stDescuentos->dVal_Descuento;
                    stValDesc.stDescuentos[idxDesc].lNumAbonado   = lNumAbonado;

                    vDTrazasLog (modulo,"\t\tCodigo Concepto......[%d]",LOG04,stValDesc.stDescuentos[idxDesc].iCod_Concepto);

                    if( !bValidacionDto (&stValDesc.stDescuentos[idxDesc]) )
                    {
                        vDTrazasLog (modulo,"\t\tConcepto No Encontrado [%d]"
                                     ,LOG04,stValDesc.stDescuentos[idxDesc].iCod_Concepto);
                        return(FALSE);
                    }
                    /* RAO20021213: Se asume que se aplica por porcentaje, y por monto se convirtio en % */
                    vDTrazasLog (modulo,"\t\tDescuento por TIPOPORCENTAJE",LOG04);
                    stValDesc.stDescuentos[idxDesc].dValor_Monto = (stPreFactura.A_PFactura.dImpFacturable[i] * stValDesc.stDescuentos[idxDesc].dVal_Descuento);
                    stValDesc.stDescuentos[idxDesc].dValor_Monto =  stValDesc.stDescuentos[idxDesc].dValor_Monto / 100;

                    if ((stPreFactura.A_PFactura.dImpConcDescApli[i] - stValDesc.stDescuentos[idxDesc].dValor_Monto) < 0) /* rao 18012006 */
                        stValDesc.stDescuentos[idxDesc].dValor_Monto = stPreFactura.A_PFactura.dImpConcDescApli[i];

                    stPreFactura.A_PFactura.dImpConcDescApli[i] = stPreFactura.A_PFactura.dImpConcDescApli[i] - stValDesc.stDescuentos[idxDesc].dValor_Monto ;

                    dTotalMontoPrefacDesc= dTotalMontoPrefacDesc - stValDesc.stDescuentos[idxDesc].dValor_Monto;

                    if( stValDesc.stDescuentos[idxDesc].dValor_Monto > dTotalMontoPrefactura )
                        stValDesc.stDescuentos[idxDesc].dValor_Monto = dTotalMontoPrefactura;

                    vDTrazasLog (modulo,"\n\t\t\tMonto a Descontar..[%f]",LOG04,stValDesc.stDescuentos[idxDesc].dValor_Monto);

                    idxDesc++;
                    stValDesc.iNumDescuentos++;
                }
            }
        }
    }
    return(TRUE);

}

/******************************************************************************/
void vfnPrintCuadrante (VALORDESCUENTO* stDescuentos)
{
    char   modulo[] = "vfnPrintCuadrante";

    vDTrazasLog (modulo,"\n\t\t\t***** Registro del Cuadrante seleccionado *****"
                 "\n\t\t\tNumero Cuadrante......[%d]"
                 "\n\t\t\tCodigo Concepto.......[%d]"
                 "\n\t\t\tDescripcion Concepto..[%s]"
                 "\n\t\t\tValor Desde...........[%f]"
                 "\n\t\t\tValor Hasta...........[%f]"
                 "\n\t\t\tValor Descuento.......[%f]"
                 "\n\t\t\tTipo de Descuento.....[%s]"
                 "\n\t\t\tTipo de Moneda........[%s]"
                 "\n\t\t\tValor Monto...........[%f]"
                 ,LOG04
                 ,stDescuentos->iNum_Cuadrante
                 ,stDescuentos->iCod_Concepto
                 ,stDescuentos->szDescConcepto
                 ,stDescuentos->dVal_Desde
                 ,stDescuentos->dVal_Hasta
                 ,stDescuentos->dVal_Descuento
                 ,stDescuentos->szTip_Descuento
                 ,stDescuentos->szTip_Moneda
                 ,stDescuentos->dValor_Monto);

}

/*****************************************************************************/
/*  Funcion :                                                 */
/* -Funcion que calcula el cuadrante de descuento                            */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bCalculaDescuento ( long lNumAbonado
                                , VALORDESCUENTO *stValDesc1
                                , GRUPOCUADRANTE *stCuadra
                                , double dTotalfac)
{
    int    i        = 0;
    int    iExiste  = 0;
    char   modulo[] = "bCalculaDescuento";

    vDTrazasLog (modulo,"\n\t***** Function bCalculaDescuento MFG *****"
                 "\n\t\t Monto Cuadrante Entrada [%f]"
                 "\n\t\t Abonado : [%ld]",LOG05,dTotalfac,lNumAbonado );

    for( i=0;i<stCuadra->iNumCuadrantes;i++ )
    {
        if( (dTotalfac >= stCuadra->stRegistro[i].dVal_Desde)
            && (dTotalfac <=stCuadra->stRegistro[i].dVal_Hasta) )
        {
            stValDesc1->iNum_Cuadrante    = stCuadra->stRegistro[i].iNum_Cuadrante;
            stValDesc1->dVal_Desde        = stCuadra->stRegistro[i].dVal_Desde;
            stValDesc1->dVal_Hasta        = stCuadra->stRegistro[i].dVal_Hasta;

            strcpy(stValDesc1->szTip_Descuento  ,stCuadra->stRegistro[i].szTip_Descuento);

            if( lNumAbonado == -1 || lNumAbonado == 0 )
            {   /* se convierte del monto a porcentaje si el Dcto. se aplica al cliente */
                if( strcmp(stValDesc1->szTip_Descuento,TIPOMONTO)==0 )

                {
                    stValDesc1->dVal_Descuento    = fnCnvDouble((( stCuadra->stRegistro[i].dVal_Descuento * 100 ) / dTotalfac),USOFACT);
                    strcpy( stValDesc1->szTip_Descuento,TIPOPORCENTAJE);
                    if (stCuadra->stRegistro[i].dVal_Descuento > dTotalfac || stValDesc1->dVal_Descuento > 100 )
                    {
                        stValDesc1->dVal_Descuento= 100;
                    }
                }
                else
                {
                    stValDesc1->dVal_Descuento    = fnCnvDouble(stCuadra->stRegistro[i].dVal_Descuento,USOFACT);

                }
            }
            else
            {
                stValDesc1->dVal_Descuento    = fnCnvDouble(stCuadra->stRegistro[i].dVal_Descuento,USOFACT);
            }
            if (strcmp( stValDesc1->szTip_Descuento,TIPOPORCENTAJE)==0 && stValDesc1->dVal_Descuento > 100 )
            {
                stValDesc1->dVal_Descuento= 100;
            }

            strcpy(stValDesc1->szTip_Moneda     ,stCuadra->stRegistro[i].szTip_Moneda);

            vDTrazasLog (modulo,"\n\t\tNumero Cuadrante MFG.....[%d]"
                         "\n\t\tValor Desde..........[%f]"
                         "\n\t\tValor Hasta..........[%f]"
                         "\n\t\tValor Descuento......[%f]"
                         "\n\t\tTipo de Descuento....[%s]"
                         "\n\t\tTipo de Moneda.......[%s]"
                         ,LOG05,stValDesc1->iNum_Cuadrante
                         ,stValDesc1->dVal_Desde
                         ,stValDesc1->dVal_Hasta
                         ,stValDesc1->dVal_Descuento
                         ,stValDesc1->szTip_Descuento
                         ,stValDesc1->szTip_Moneda);

            iExiste = 1;
            break;
        }
    }

    if( iExiste == 0 )
    {
        vDTrazasLog (modulo,"\n\t\t**No se Encontro Valor en Cuadrante. No se aplica Descuento, abonado [%ld]",LOG03, lNumAbonado);
    }

    return(TRUE);
}

static BOOL bValidacionDto (VALORDESCUENTO *stValDesc1)
{
    char modulo [] = "bValidacionDto";
    int iRes = 0;
    CONCEPTO stConcepto;
    memset (&stConcepto,0,sizeof (CONCEPTO));

    vDTrazasLog (modulo,"\n\t\t** Entrada en bValidacionDto **"
                 "\n\t\t=> Cod. Concepto [%d] ",LOG04,stValDesc1->iCod_Concepto );

    if( !bFindConcepto (stValDesc1->iCod_Concepto,&stConcepto) )
    {
        vDTrazasLog (modulo,"\n\t\tNo Existe Cod_Concepto en Funcion bFindConcepto..[%d]",LOG04,stValDesc1->iCod_Concepto);
        sprintf (stAnomProceso.szObsAnomalia,"Concepto no encontrado [%d]",
                 stValDesc1->iCod_Concepto);
        iRes = ERR015;
    }
    else
    {
        if( stConcepto.iIndActivo == 0 )
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d","Ind.Activo Cero",
                     stConcepto.iIndActivo);
            iRes = ERR001;
        }
        else if( stConcepto.iCodTipConce != DESCUENTO )
        {
            sprintf (stAnomProceso.szObsAnomalia,"%s %d",
                     "Tipo de Concepto (Impuesto o Articulo)",
                     stConcepto.iCodTipConce);
            iRes = ERR001;
        }

        if( iRes != 0 )
        {
            stAnomProceso.iCodConcepto = stValDesc1->iCod_Concepto  ;
            stAnomProceso.iCodProducto = 0  ;
            strcpy (stAnomProceso.szDesProceso,"PreBilling.Descuento");
            stAnomProceso.lNumAbonado  = 0;

            /*stEstDtos.iNumAnomalias++;*/
            vDTrazasLog (modulo,"\n\t\tAnomalias en Validacion de Descuento",LOG03);
            iDError (szExeName,ERR001,vInsertarIncidencia,"Anomalias en Validacion de Descuento");
        }
        else
        {
            strcpy(stValDesc1->szDescConcepto,stConcepto.szDesConcepto);
        }
    }

    return(iRes == 0)?TRUE:FALSE;

}/************************** Final bValidacionDto ***************************/

/*****************************************************************************/
/*****************************************************************************/
/*  Funcion : bCargaPreFactura                                               */
/* -Funcion que carga nuevo registro en PreFactura                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bCargaPreFactura ( int iNumConceptos, VALORDESCUENTO *pstDesc)
{
    int iNumTotDto    = 0;
    int iNumTotDtoSac = 0;
    int iNumTotDtoSer = 0;
    int iNumTotDtoTra = 0;
    int iNumTotDtoAbo = 0;

    char modulo[] = "bCargaPreFactura";

    vDTrazasLog (modulo,"\n\t***** Function bCargaPreFactura *****"
                 "\n\t\tValor de Descuento a Cargar en Prefactura [%f]"
                 "\n\t\tNumero Indice-----> iNumconceptos=[%d]",LOG04, pstDesc->dValor_Monto, iNumConceptos);

    if( stPreFactura.iNumRegistros >= MAX_CONCFACTUR )
    {
        vDTrazasLog (modulo,"\n\t\tstPreFactura.iNumRegistros > = MAX_CONCFACTUR",LOG03);
        iDError (szExeName,ERR035,vInsertarIncidencia,"stPreFactura.iNumRegistros > = MAX_CONCFACTUR");
        return(FALSE);
    }


    if( pstDesc->dValor_Monto!=0.00 )
    {
/*
        if(pstDesc->dValor_Monto > stPreFactura.A_PFactura.dImpConcDescApli[pstDesc->iPosPrefac])
        {
            pstDesc->dValor_Monto = stPreFactura.A_PFactura.dImpConcDescApli[pstDesc->iPosPrefac];      PGG SOPORTE: 21-09-2005 Solucion incidencia CH-200509203081 por Miguel Salas
            vDTrazasLog (modulo,"\n\t Monto de descuentos por concepto se ha exedido.  *****",LOG03);
        }
*/

        stPreFactura.A_PFactura.dImpMontoBase [iNumConceptos] = (pstDesc->dValor_Monto)*-1;
        stPreFactura.A_PFactura.dImpFacturable[iNumConceptos] = fnCnvDouble ((pstDesc->dValor_Monto)*-1,USOFACT);
        stPreFactura.A_PFactura.dImpConcepto  [iNumConceptos] = (pstDesc->dValor_Monto)*-1;
        stPreFactura.A_PFactura.lNumAbonado   [iNumConceptos] = pstDesc->lNumAbonado;
        stPreFactura.A_PFactura.iCodConcepto  [iNumConceptos] = pstDesc->iCod_Concepto;
        strcpy (stPreFactura.A_PFactura.szCodMoneda[iNumConceptos],stDatosGener.szCodMoneFact);
        strcpy (stPreFactura.A_PFactura.szDesConcepto[iNumConceptos],pstDesc->szDescConcepto);

        stPreFactura.A_PFactura.lNumProceso   [iNumConceptos] = stPreFactura.A_PFactura.lNumProceso [pstDesc->iPosPrefac];
        stPreFactura.A_PFactura.lCodCliente   [iNumConceptos] = stPreFactura.A_PFactura.lCodCliente [pstDesc->iPosPrefac];

        if( !bGetMaxColPreFa(stPreFactura.A_PFactura.iCodConcepto[iNumConceptos],
                             &stPreFactura.A_PFactura.lColumna [iNumConceptos]) )
            return(FALSE);

        stPreFactura.A_PFactura.iCodProducto  [iNumConceptos] = stPreFactura.A_PFactura.iCodProducto [pstDesc->iPosPrefac];
        strcpy (stPreFactura.A_PFactura.szFecValor[iNumConceptos],stPreFactura.A_PFactura.szFecValor[pstDesc->iPosPrefac]);
        strcpy (stPreFactura.A_PFactura.szFecEfectividad[iNumConceptos],szSysDate);
        strcpy (stPreFactura.A_PFactura.szCodRegion[iNumConceptos],stPreFactura.A_PFactura.szCodRegion[pstDesc->iPosPrefac]);
        strcpy (stPreFactura.A_PFactura.szCodProvincia[iNumConceptos],stPreFactura.A_PFactura.szCodProvincia[pstDesc->iPosPrefac]);
        strcpy (stPreFactura.A_PFactura.szCodCiudad[iNumConceptos],stPreFactura.A_PFactura.szCodCiudad[pstDesc->iPosPrefac]);
        strcpy (stPreFactura.A_PFactura.szCodModulo[iNumConceptos],stPreFactura.A_PFactura.szCodModulo[pstDesc->iPosPrefac]);

        stPreFactura.A_PFactura.lCodPlanCom   [iNumConceptos] = stPreFactura.A_PFactura.lCodPlanCom [pstDesc->iPosPrefac];
        stPreFactura.A_PFactura.iIndFactur    [iNumConceptos] = FACTURABLE;
        stPreFactura.A_PFactura.iCodCatImpos  [iNumConceptos] = stPreFactura.A_PFactura.iCodCatImpos[pstDesc->iPosPrefac];
        stPreFactura.A_PFactura.iIndEstado    [iNumConceptos] = EST_NORMAL;
        stPreFactura.A_PFactura.iIndEstado    [pstDesc->iPosPrefac]             = EST_DTO   ;
        stPreFactura.A_PFactura.iCodTipConce  [iNumConceptos] = DESCUENTO ;
        stPreFactura.A_PFactura.lNumUnidades  [iNumConceptos] = 1         ; /* Incorporado por PGonzaleg 4-03-2002 */
        stPreFactura.A_PFactura.lCodCiclFact  [iNumConceptos] = stCiclo.lCodCiclFact;

        stPreFactura.A_PFactura.iCodConceRel[iNumConceptos] = stPreFactura.A_PFactura.iCodConcepto[pstDesc->iPosPrefac];
        stPreFactura.A_PFactura.lColumnaRel [iNumConceptos] = stPreFactura.A_PFactura.lColumna    [pstDesc->iPosPrefac];
        strcpy (stPreFactura.A_PFactura.szNumTerminal[iNumConceptos],stPreFactura.A_PFactura.szNumTerminal[pstDesc->iPosPrefac]);
        stPreFactura.A_PFactura.lCapCode    [iNumConceptos] = stPreFactura.A_PFactura.lCapCode[pstDesc->iPosPrefac];
        strcpy (stPreFactura.A_PFactura.szNumSerieMec [iNumConceptos],stPreFactura.A_PFactura.szNumSerieMec[pstDesc->iPosPrefac]);
        strcpy (stPreFactura.A_PFactura.szNumSerieLe  [iNumConceptos],stPreFactura.A_PFactura.szNumSerieLe[pstDesc->iPosPrefac]);
        stPreFactura.A_PFactura.lNumVenta   [iNumConceptos] = stPreFactura.A_PFactura.lNumVenta [pstDesc->iPosPrefac];
        stPreFactura.A_PFactura.lNumTransaccion[iNumConceptos] = stPreFactura.A_PFactura.lNumTransaccion [pstDesc->iPosPrefac];

        stPreFactura.A_PFactura.iFlagImpues  [iNumConceptos] = 0  ;
        stPreFactura.A_PFactura.iFlagDto     [iNumConceptos] = 0  ;
        stPreFactura.A_PFactura.iFlagDto     [pstDesc->iPosPrefac] = 1  ;
        stPreFactura.A_PFactura.fPrcImpuesto [iNumConceptos] = 0.0;
        stPreFactura.A_PFactura.dValDto      [iNumConceptos] = 0.0;
        stPreFactura.A_PFactura.iTipDto      [iNumConceptos] = 0  ;
        stPreFactura.A_PFactura.iMesGarantia [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iIndAlta     [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iIndSuperTel [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iNumPaquete  [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iIndCuota    [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iNumCuotas   [iNumConceptos] = 0;
        stPreFactura.A_PFactura.iOrdCuota    [iNumConceptos] = 0;

/*        stPreFactura.A_PFactura.dImpConcDescApli[pstDesc->iPosPrefac] -= pstDesc->dValor_Monto; PGG SOPORTE: 21-09-2005 Solucion incidencia CH-200509203081 por Miguel Salas */

        if( stPreFactura.A_PFactura.bOptPenaliza [pstDesc->iPosPrefac] )
        {
            stPreFactura.A_PFactura.bOptPenaliza [iNumConceptos] = TRUE;
            iNumTotDtoSac++;
            iNumTotDto++   ;
        }
        if( stPreFactura.A_PFactura.bOptServicios [pstDesc->iPosPrefac] )
        {
            stPreFactura.A_PFactura.bOptServicios[iNumConceptos] = TRUE;
            iNumTotDtoSer++;
            iNumTotDto++   ;
        }
        if( stPreFactura.A_PFactura.bOptAbonos [pstDesc->iPosPrefac] )
        {
            stPreFactura.A_PFactura.bOptAbonos [iNumConceptos] =  TRUE;
            iNumTotDtoAbo++;
            iNumTotDto++   ;
        }
        if( stPreFactura.A_PFactura.bOptTrafico [pstDesc->iPosPrefac] )
        {
            stPreFactura.A_PFactura.bOptTrafico [iNumConceptos] = TRUE;
            iNumTotDtoTra++;
            iNumTotDto++   ;
        }

        stPreFactura.iNumRegistros++;

        vDTrazasLog (modulo,"\n\t\tFin de la Carga de PreFactura"
                     "\n\t\t\tNumero de Proceso.....[%ld]"
                     "\n\t\t\tCodigo Cliente........[%ld]"
                     "\n\t\t\tNumero Abonado........[%ld]"
                     "\n\t\t\tCodigo Concepto.......[%d]"
                     ,LOG04,stPreFactura.A_PFactura.lNumProceso [iNumConceptos]
                     ,stPreFactura.A_PFactura.lCodCliente [iNumConceptos]
                     ,stPreFactura.A_PFactura.lNumAbonado [iNumConceptos]
                     ,pstDesc->iCod_Concepto);
    }
    vDTrazasLog (modulo,"\t\t***** Fin Function bCargaPreFactura *****",LOG04);

    return(TRUE);
}/************************** Final bCargaPreFactura **********************/

/*****************************************************************************/
/*  Funcion : bCargaDescPuntPreFactura                                       */
/* -Funcion que carga nuevo registro en PreFactura                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
BOOL bCargaDescPuntPreFactura ( long lIndCargo, DETCARG_PUNTUALES *pstDescPuntual)
{   
    char   modulo[] = "bCargaDescPuntPreFactura";
    double dImpDescuento = 0.0;
    long   lIndDesc = 0L ;
	CONCEPTO stConcepTemp;

    vDTrazasLog (modulo,"\n\t***** Function %s *****"
		                "\n\t\tValor de Descuento a Cargar en Prefactura [%f]"
		                "\n\t\tNumero Indice-----> iNumconceptos=[%d]"
		                ,LOG04, modulo, pstDescPuntual->dMtoDcto, stPreFactura.iNumRegistros);

    if( stPreFactura.iNumRegistros >= MAX_CONCFACTUR )
    {
        vDTrazasLog (modulo,"\n\t\tstPreFactura.iNumRegistros > = MAX_CONCFACTUR",LOG03);
        iDError (szExeName,ERR035,vInsertarIncidencia,"stPreFactura.iNumRegistros > = MAX_CONCFACTUR");
        return(FALSE);
    }

	vDTrazasLog(modulo,"*** Antes de Calcular dImpDescuento ***",LOG05);
	vDTrazasLog(modulo,"*** pstDescPuntual->dMtoDcto -> %f ***",LOG05,pstDescPuntual->dMtoDcto);
	vDTrazasLog(modulo,"*** pstDescPuntual->dMtoAplicado -> %f ***",LOG05,pstDescPuntual->dMtoAplicado);
	dImpDescuento =  pstDescPuntual->dMtoDcto - pstDescPuntual->dMtoAplicado; // monto a descontar 
	vDTrazasLog(modulo,"*** dImpDescuento ya fue calculado [%f] ***",LOG05,dImpDescuento);
	
    if( (dImpDescuento) > 0.00 )
    {
    	lIndDesc = stPreFactura.iNumRegistros; /* indice del nuevo registro de descuento */

		/* obtiene info descuento a generar */
	    if( !bFindConcepto (pstDescPuntual->lCodConcDesc,&stConcepTemp) )
	    {
	        vDTrazasLog (modulo,"\n\t\tNo Existe Cod_Concepto en Funcion bFindConcepto..[%d]",LOG04,pstDescPuntual->lCodConcDesc);
	        sprintf (stAnomProceso.szObsAnomalia,"Concepto no encontrado [%d]", pstDescPuntual->lCodConcDesc);
	        return (FALSE);
	    }

		stPreFactura.A_PFactura.iCodConcepto[lIndDesc]  = pstDescPuntual->lCodConcDesc;		
        strcpy (stPreFactura.A_PFactura.szDesConcepto[lIndDesc],stConcepTemp.szDesConcepto);
	
        if( !bGetMaxColPreFa(stPreFactura.A_PFactura.iCodConcepto[lIndDesc],
                             &stPreFactura.A_PFactura.lColumna [lIndDesc]) )
            return(FALSE);

		/* se evaluas si el descuento es mayor que el cargo */
		if ((stPreFactura.A_PFactura.dImpConcDescApli[lIndCargo]- dImpDescuento) < 0.0)
		{
			vDTrazasLog(modulo,"*** Antes de descontar el maximo posible ***",LOG05);
			dImpDescuento = stPreFactura.A_PFactura.dImpConcDescApli[lIndCargo]; /* se descuenta el maximo disponible */
			vDTrazasLog(modulo,"*** Ya se desconto el maximo posible -> [%f] ***",LOG05,dImpDescuento);
		}
			
			
        stPreFactura.A_PFactura.dImpConcepto  [lIndDesc] = (dImpDescuento)*-1;
        stPreFactura.A_PFactura.dImpMontoBase [lIndDesc] = (dImpDescuento)*-1;
        stPreFactura.A_PFactura.dImpFacturable[lIndDesc] = fnCnvDouble ((dImpDescuento)*-1,USOFACT);


        stPreFactura.A_PFactura.iCodConceRel[lIndDesc]   = stPreFactura.A_PFactura.iCodConcepto[lIndCargo];
        stPreFactura.A_PFactura.lColumnaRel [lIndDesc]   = stPreFactura.A_PFactura.lColumna    [lIndCargo];

        stPreFactura.A_PFactura.lNumAbonado   [lIndDesc] = stPreFactura.A_PFactura.lNumAbonado [lIndCargo];
        stPreFactura.A_PFactura.lNumProceso   [lIndDesc] = stPreFactura.A_PFactura.lNumProceso [lIndCargo];
        stPreFactura.A_PFactura.lCodCliente   [lIndDesc] = stPreFactura.A_PFactura.lCodCliente [lIndCargo];
        stPreFactura.A_PFactura.iCodProducto  [lIndDesc] = stPreFactura.A_PFactura.iCodProducto[lIndCargo];
       
        strcpy (stPreFactura.A_PFactura.szCodMoneda[lIndDesc],stPreFactura.A_PFactura.szCodMoneda[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szFecValor[lIndDesc] ,stPreFactura.A_PFactura.szFecValor[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szCodRegion[lIndDesc],stPreFactura.A_PFactura.szCodRegion[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szCodProvincia[lIndDesc],stPreFactura.A_PFactura.szCodProvincia[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szCodCiudad[lIndDesc],stPreFactura.A_PFactura.szCodCiudad[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szCodModulo[lIndDesc],stPreFactura.A_PFactura.szCodModulo[lIndCargo]);

        stPreFactura.A_PFactura.lCodPlanCom   [lIndDesc] = stPreFactura.A_PFactura.lCodPlanCom [lIndCargo];
        stPreFactura.A_PFactura.iIndFactur    [lIndDesc] = FACTURABLE;
        stPreFactura.A_PFactura.iCodCatImpos  [lIndDesc] = stPreFactura.A_PFactura.iCodCatImpos[lIndCargo];
        stPreFactura.A_PFactura.iIndEstado    [lIndDesc] = EST_NORMAL;
        stPreFactura.A_PFactura.iCodTipConce  [lIndDesc] = DESCUENTO ;
        stPreFactura.A_PFactura.lNumUnidades  [lIndDesc] = 1         ; /* Incorporado por PGonzaleg 4-03-2002 */
        stPreFactura.A_PFactura.lCodCiclFact  [lIndDesc] = stCiclo.lCodCiclFact;
        strcpy (stPreFactura.A_PFactura.szFecEfectividad[lIndDesc],szSysDate);

        strcpy (stPreFactura.A_PFactura.szNumTerminal[lIndDesc],stPreFactura.A_PFactura.szNumTerminal[lIndCargo]);
        stPreFactura.A_PFactura.lCapCode    [lIndDesc]   = stPreFactura.A_PFactura.lCapCode[lIndCargo];
        strcpy (stPreFactura.A_PFactura.szNumSerieMec [lIndDesc],stPreFactura.A_PFactura.szNumSerieMec[lIndCargo]);
        strcpy (stPreFactura.A_PFactura.szNumSerieLe  [lIndDesc],stPreFactura.A_PFactura.szNumSerieLe[lIndCargo]);
        stPreFactura.A_PFactura.lNumVenta   [lIndDesc]   = stPreFactura.A_PFactura.lNumVenta [lIndCargo];
        stPreFactura.A_PFactura.lNumTransaccion[lIndDesc]= stPreFactura.A_PFactura.lNumTransaccion [lIndCargo];
        stPreFactura.A_PFactura.bOptPenaliza  [lIndDesc] = stPreFactura.A_PFactura.bOptPenaliza  [lIndCargo];  
        stPreFactura.A_PFactura.bOptServicios [lIndDesc] = stPreFactura.A_PFactura.bOptServicios [lIndCargo]; 
        stPreFactura.A_PFactura.bOptAbonos    [lIndDesc] = stPreFactura.A_PFactura.bOptAbonos    [lIndCargo]; 
        stPreFactura.A_PFactura.bOptTrafico   [lIndDesc] = stPreFactura.A_PFactura.bOptTrafico   [lIndCargo]; 

        stPreFactura.A_PFactura.iFlagImpues  [lIndDesc] = 0  ;
        stPreFactura.A_PFactura.iFlagDto     [lIndDesc] = 0  ;
        stPreFactura.A_PFactura.fPrcImpuesto [lIndDesc] = 0.0;
        stPreFactura.A_PFactura.dValDto      [lIndDesc] = 0.0;
        stPreFactura.A_PFactura.iTipDto      [lIndDesc] = 0  ;
        stPreFactura.A_PFactura.iMesGarantia [lIndDesc] = 0;
        stPreFactura.A_PFactura.iIndAlta     [lIndDesc] = 0;
        stPreFactura.A_PFactura.iIndSuperTel [lIndDesc] = 0;
        stPreFactura.A_PFactura.iNumPaquete  [lIndDesc] = 0;
        stPreFactura.A_PFactura.iIndCuota    [lIndDesc] = 0;
        stPreFactura.A_PFactura.iNumCuotas   [lIndDesc] = 0;
        stPreFactura.A_PFactura.iOrdCuota    [lIndDesc] = 0;


		/* actualiza el concepto de cargo */
        stPreFactura.A_PFactura.iIndEstado      [lIndCargo]  = EST_DTO   ;
        stPreFactura.A_PFactura.dImpConcDescApli[lIndCargo] -= dImpDescuento;
        stPreFactura.A_PFactura.iFlagDto        [lIndCargo]  = 1  ;

	
        stPreFactura.iNumRegistros++;
		
		vDTrazasLog(modulo,"*** Antes de Registrar el monto descontado ***",LOG05);
		vDTrazasLog(modulo,"*** pstDescPuntual->dMtoAplicado -> %f ***",LOG05,pstDescPuntual->dMtoAplicado);
		vDTrazasLog(modulo,"*** dImpDescuento -> %f ***",LOG05,dImpDescuento);
		/* registra el monto descontado */
		pstDescPuntual->dMtoAplicado = dImpDescuento - pstDescPuntual->dMtoAplicado;
		vDTrazasLog(modulo,"*** Monto descontado -> [%f] ***",LOG05,pstDescPuntual->dMtoAplicado);
		

        vDTrazasLog (modulo,"\n\t\tFin de la Carga de PreFactura"
		                     "\n\t\t\tNumero de Proceso.....[%ld]"
		                     "\n\t\t\tCodigo Cliente........[%ld]"
		                     "\n\t\t\tNumero Abonado........[%ld]"
		                     "\n\t\t\tCodigo Concepto.......[%d]"
		                     ,LOG04,stPreFactura.A_PFactura.lNumProceso [lIndDesc]
		                     ,stPreFactura.A_PFactura.lCodCliente [lIndDesc]
		                     ,stPreFactura.A_PFactura.lNumAbonado [lIndDesc]
		                     ,stPreFactura.A_PFactura.iCodConcepto[lIndDesc]);
    }
    vDTrazasLog (modulo,"\t\t***** Fin Function bCargaDescPuntPreFactura *****",LOG04);

    return(TRUE);
} /************************** Final bCargaDescPuntPreFactura **********************/


/*****************************************************************************/
/*  Funcion : bfnMarcaDcto                                                   */
/* -Funcion que carga nuevo registro en PreFactura                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnMarcaDcto (long lNumSecuencia)
{
    char modulo[] = "bfnMarcaDcto";
    int i,x ;

    vDTrazasLog (modulo,"\n\t\t ********* bfnMarcaDcto ********",LOG05);
    for( i=0; i<stPlanesDesc.iNumAbonados;i++ )
    {
        for( x=0; x<stPlanesDesc.stAbonado[i].iNumPlanes;x++ )
        {
            if( stPlanesDesc.stAbonado[i].stPlanDes[x].stPD.lNumSecuencia == lNumSecuencia )
            {
                stPlanesDesc.stAbonado[i].stPlanDes[x].stPD.iCodEstado = 1;
            }
        }
    }
    return(TRUE);
}/************************* Fin bfnMarcaDcto *********************************/

static BOOL bModifBeneficios (long lNumSecuencia)
{
    char modulo[] = "bfnBeneficios";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhNumSecuencia;
    long lhCodCliente ;
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (modulo,"\n\t\t***** Function bModifBeneficios *****"
                 "\n\t\t\tNro Secuencia  [%ld]",LOG05,lNumSecuencia);

    if( lNumSecuencia >0 )
    {
        lhNumSecuencia  = lNumSecuencia;
        lhCodCliente    = stCliente.lCodCliente;
        vDTrazasLog (modulo,"\n\t\t\tCliente        [%ld]",LOG05, lhCodCliente);
        /* EXEC SQL
        UPDATE BPT_BENEFICIOS
        SET COD_ESTADO = 'EJE' , FEC_ESTADO = SYSDATE
        WHERE COD_CLIENTE = :lhCodCliente
        AND NUM_SECUENCIA = :lhNumSecuencia; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update BPT_BENEFICIOS  set COD_ESTADO='EJE',FEC_ESTAD\
O=SYSDATE where (COD_CLIENTE=:b0 and NUM_SECUENCIA=:b1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )338;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&lhNumSecuencia;
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



        vDTrazasLog (modulo,"\n\t\t***** Function bModifBeneficios *****"
                     "\n\t\t\tREG ACTUALIZADOS [%ld]",LOG05,sqlca.sqlerrd[2]);

        if( sqlca.sqlcode != SQLOK && sqlca.sqlcode != SQLNOTFOUND )
        {
            vDTrazasLog (modulo,"\n\t\tError Update de BPT_BENEFICIOS",LOG01);
            iDError (szExeName,ERR000,vInsertarIncidencia,"update BPT_BENEFICIOS Plan Dcto.", szfnORAerror());
            return(FALSE);
        }

    }
    return(TRUE);
}

/*****************************************************************************/
/*  Funcion : bfnCargaPlanesGrupo                                            */
/* -Funcion que carga los planes de descuentos de Grupo                      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnCargaPlanesGrupo ()
{
    int     idxAbon = 0, idxPlan = 0, idzAbon = 0, idzPlan = 0;
    char    plCodPlan[6];
    char    modulo[] = "bfnCargaPlanesGrupo";
    BOOL    bExiste=FALSE;

    vDTrazasLog (modulo,"\n\t\t***** Entrada en %s *****", LOG04, modulo);

    strcpy(plCodPlan, stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].szCod_Plandesc);

    stPlanesGrupo.iNumPlanesGrupo = 1;

    for( idxAbon=0;idxAbon < stPlanesDesc.iNumAbonados;idxAbon++ )
    {
        for( idxPlan=0;idxPlan < stPlanesDesc.stAbonado[idxAbon].iNumPlanes;idxPlan++ )
        {
            if( strcmp(stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].szTipEntidad ,TIPOENTGRUPO)==0 )
            {
                for( idzPlan=0;idzPlan<stPlanesGrupo.iNumPlanesGrupo;idzPlan++ )
                {

                    if( strcmp(stPlanesGrupo.stPlanGrupo[idzPlan].szCod_Plandesc, stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].szCod_Plandesc)==0 )
                    {
                        bExiste=TRUE;
                        break;
                    }
                }
                if( !bExiste )
                {
                    idzPlan=stPlanesGrupo.iNumPlanesGrupo-1;
                    idzAbon = stPlanesGrupo.stPlanGrupo[idzPlan].iNumAbonados;
                    stPlanesGrupo.iNumPlanesGrupo++;
                }
                else
                {
                    idzAbon = stPlanesGrupo.stPlanGrupo[idzPlan].iNumAbonados;  /* - 1; */
                }

                stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumAbonado = stPlanesDesc.stAbonado[idxAbon].lNumAbonado;
                strcpy(stPlanesGrupo.stPlanGrupo[idzPlan].szCod_Plandesc           , stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].szCod_Plandesc);
                strcpy(stPlanesGrupo.stPlanGrupo[idzPlan].stPD.szCod_Tipeval       , stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.szCod_Tipeval);
                strcpy(stPlanesGrupo.stPlanGrupo[idzPlan].stPD.szCod_Tipapli       , stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.szCod_Tipapli);
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.iCod_Grupoeval             = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.iCod_Grupoeval;
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.iCod_Grupoapli             = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.iCod_Grupoapli;
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.iNum_Cuadrante             = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.iNum_Cuadrante;
                strcpy(stPlanesGrupo.stPlanGrupo[idzPlan].stPD.szTip_Unidad        , stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.szTip_Unidad);
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.iCod_Concdesc              = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.iCod_Concdesc;
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.dMto_Minfact               = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.dMto_Minfact;


                stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumSecuencia  = stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.lNumSecuencia;
                stPlanesGrupo.stPlanGrupo[idzPlan].stPD.iCodEstado = 1;                                 /* PGG 26-05-2010 - Probando 130638 - Creo que esta linea esta de mas, pq es absolutamnte innecesaria */
                stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.iCodEstado = 1; /* PGG 26-05-2010 - Probando 130638 */

                vDTrazasLog (modulo ,"\n\t\t\t=> Abonado..........[%ld] *****"
                             "\n\t\t\t=> Tipo Apliicacion.[%s] *****"
                             "\n\t\t\t=> Secuencia       .[%ld] *****"
                             , LOG05, stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumAbonado
                             , stPlanesGrupo.stPlanGrupo[idzPlan].stPD.szCod_Tipapli
                             , stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumSecuencia);
                idzAbon++;
                stPlanesGrupo.stPlanGrupo[idzPlan].iNumAbonados++;
                bExiste=FALSE;

            }
            else
            {    /* Incidencia CH-1403 : Correccion a la marcacion de estado de la BPT_BENEFICIO a estado 'EJE' para los
                                         descuentos de tipo 'A' y 'C'. */
                vDTrazasLog (modulo,"\n\t\t ModifBeneficios Entidad A o C [%ld], Entidad[%s] ",LOG05,
                             stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.lNumSecuencia,
                             stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].szTipEntidad);
                if( !bModifBeneficios ( stPlanesDesc.stAbonado[idxAbon].stPlanDes[idxPlan].stPD.lNumSecuencia) )
                {
                    vDTrazasLog (modulo,"\n\t\t ModifBeneficios Entidad A o C RETURN FALSE. ",LOG05);
                    return(FALSE);
                }
            }
        }
    }

    vDTrazasLog (modulo ,"\n\t=> CONTENIDO DE STPLANESGRUPO..........[%ld] *****"
                 , LOG05, stPlanesGrupo.iNumPlanesGrupo);
    for( idzPlan=0; idzPlan<stPlanesGrupo.iNumPlanesGrupo - 1; idzPlan++ )
    {
        for( idzAbon=0; idzAbon<stPlanesGrupo.stPlanGrupo[idzPlan].iNumAbonados ; idzAbon++ )
        {
            vDTrazasLog (modulo ,  "\t\t\t=> lNumAbonado  [%d] ........[%ld] *****"
		                         "\n\t\t\t=> lNumSecuencia[%d] ........[%ld] *****"
		                         , LOG05, idzAbon, stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumAbonado,
		                         idzAbon, stPlanesGrupo.stPlanGrupo[idzPlan].stAbonadosGrupo[idzAbon].lNumSecuencia);
        }
    }
    return(TRUE);

}

/*****************************************************************************/
/*  Funcion : bfnDescporGrupo                                                */
/* -Funcion que procesa los descuentos a nivel de grupo                      */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
/*****************************************************************************/
static BOOL bfnDescporGrupo ( char          *szFecParam
                            , double        dTotalMontoPrefactura )
{
    int     idxPlan = 0;
    char    modulo[] = "bfnDescporGrupo";

    vDTrazasLog (modulo,"\n\t\t***** Entrada en %s *****"
                 "\n\t\t==> Procesando Planes Grupo por Conceptos", LOG04, modulo);

    for( idxPlan=0;idxPlan < stPlanesGrupo.iNumPlanesGrupo;idxPlan++ )
    {
        vDTrazasLog (modulo, "\n\t\t\t=> Plan Descuento [%s]", LOG04
                     , stPlanesGrupo.stPlanGrupo[idxPlan].szCod_Plandesc);
        if( strcmp(stPlanesGrupo.stPlanGrupo[idxPlan].stPD.szCod_Tipapli , PORCONCEPTO)  == 0 )
        {
            if( !bfnDescporConceptoGrupo  (&stPlanesGrupo.stPlanGrupo[idxPlan].stPD
                                           ,&stPlanesGrupo.stPlanGrupo[idxPlan]
                                           ,szFecParam, dTotalMontoPrefactura) )
                return(FALSE);
        }
    }

    vDTrazasLog (modulo,"\n\t\t==> Procesando Planes Grupo por Factura", LOG04);

    for( idxPlan=0;idxPlan < stPlanesGrupo.iNumPlanesGrupo;idxPlan++ )
    {
        if( strcmp(stPlanesGrupo.stPlanGrupo[idxPlan].stPD.szCod_Tipeval , PORFACTURA)   == 0 )
        {
            if( !bfnDescporConceptoGrupo ( &stPlanesGrupo.stPlanGrupo[idxPlan].stPD
                                           ,&stPlanesGrupo.stPlanGrupo[idxPlan]
                                           ,szFecParam, dTotalMontoPrefactura) )
                return(FALSE);
        }
    }
    return(TRUE);
}

/*****************************************************************************/
/*  Funcion : bfnDescporConceptoGrupo                                        */
/* -Funcion que procesa los descuentos de grupo por conceptos                */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bfnDescporConceptoGrupo ( PLANDCTO      *stPD
                                      , PLANGRUPO     *pstPlanGrupo
                                      , char          *szFecParam
                                      , double        dTotalMontoPrefactura)
{

    char    modulo[]        = "bfnDescporConceptoGrupo";
    int     idxAbon         = 0;

    GRUPOCONCEVAL  stEval   ;
    GRUPOCONAPLI   stApli   ;
    GRUPOCUADRANTE stCuadra ;
    VALORDESCUENTO stDescPaso;

    vDTrazasLog (modulo,"\n\t\t*** Entrada en %s ", LOG04, modulo);


    memset (&stEval     ,0,sizeof (GRUPOCONCEVAL));
    memset (&stApli     ,0,sizeof (GRUPOCONAPLI));
    memset (&stCuadra   ,0,sizeof (GRUPOCUADRANTE));
    memset (&stDescPaso ,0,sizeof (VALORDESCUENTO));

    if( dTotalMontoPrefacDesc <= stPD->dMto_Minfact )
    {
        vDTrazasLog (modulo,"\n\t**Monto a Facturar es Menor que el Monto Minimo Permitido"
                     "\n\t**Monto a Facturar [%f] **Monto Minimo Permitido [%f]"
                     ,LOG02,dTotalMontoPrefacDesc,stPD->dMto_Minfact);
/*         iDError (szExeName,ERR000,vInsertarIncidencia,"Monto a Facturar es Menor que el Monto Minimo Permitido", "!");  */
/*         bInsertaAnomProceso (&stAnomProceso);                                                                           */
        return(TRUE);
    }

    /*Carga Conceptos de Evaluacion */
    if( !bCargaConceptoEvalua (stPD->iCod_Grupoeval,szFecParam,&stEval) )
        return(FALSE);

    /*carga Concepto de Aplicacion*/
    if( !bCargaConceptoAplica (stPD->iCod_Grupoapli,szFecParam,&stApli) )
        return(FALSE);

/* SAAM-20030526 Se modifica salida segun incidecia CH-200520030751 para que solo siga si el indicador d conceptos a aplicar es mayor que cero */

    if( stApli.iNumAplica > 0 )
    {
        /* Carga Cuadrante de Descuento*/
        if( !bCargaCuadrante (stPD->iNum_Cuadrante,szFecParam,&stCuadra) )
            return(FALSE);

        /*Contar cantidad de evaluaciones*/
        if( !bfnEvaluaciondeConceptosGrupo (stPD,&stEval,pstPlanGrupo,szFecParam,dTotalMontoPrefactura) )
            return(FALSE);

        vDTrazasLog (modulo,"\n\t***** Total a Facturar por Evaluacion [%f][%f]",LOG05,pstPlanGrupo->dTotMonto,dMontoEvalDcto_aux);

        if(dMontoEvalDcto_aux != pstPlanGrupo->dTotMonto || dMontoEvalDcto_aux<=0)
        {
            vDTrazasLog (modulo,"\n\t***** Dcto. Total por Evaluacion diferentes [%f][%f]\n",LOG02,pstPlanGrupo->dTotMonto,dMontoEvalDcto_aux);
            pstPlanGrupo->dTotMonto=dMontoEvalDcto_aux;
        }

        /*calculo de descuentos */
        if( pstPlanGrupo->dTotMonto <= 0 )
        {
            vDTrazasLog(modulo,"\t***** Monto de Evaluacion es [%f]. No se Pueden Efectuar Descuentos",LOG04, pstPlanGrupo->dTotMonto);
        }
        else
        {
            if( !bCalculaDescuento( -1, &stDescPaso, &stCuadra, pstPlanGrupo->dTotMonto) )
                return(FALSE);

			/* SAAM-20030526 Evaluamos que el descuento sea mayor a cero */
            if( (stDescPaso.dVal_Descuento != 0.0)||(stDescPaso.dVal_Descuento != 0) )
            {
                /*contar cantidad de aplicaciones*/
                for( idxAbon=0; idxAbon < pstPlanGrupo->iNumAbonados;idxAbon++ )
                {

                    if( !bAplicacionConceptos ( pstPlanGrupo->stAbonadosGrupo[idxAbon].lNumAbonado,
                                                stPD,
                                                &stApli,
                                                &stDescPaso,
                                                szFecParam) )
                        return(FALSE);
                    vfnPrintCuadrante(&stValDesc.stDescuentos[idxDesc-1]);
                }
            }
        }
    }
    return(TRUE);
}


/*****************************************************************************/
/*  Funcion : bfnEvaluaciondeConceptosGrupo                                  */
/* -Funcion que evalua los conceptos de evaluacion                           */
/* -Valores Retorno : Error->FALSE, !Error->TRUE                             */
static BOOL bfnEvaluaciondeConceptosGrupo ( PLANDCTO      *stPD
                                            , GRUPOCONCEVAL *stEval
                                            , PLANGRUPO     *pstPlanGrupo
                                            , char          *szFecParam
                                            , double        dTotalMontoPrefactura)
{
    int    iInd    = 0, iIndF   = 0, iExiste = 0, idxAbon = 0;
    double dtotalunidad = 0.0;
    char   modulo[] = "bfnEvaluaciondeConceptosGrupo";

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    long lhFechaAlta ;
    char szhFechaParam   [15];
    char szhFechaCliente [15];
    /* EXEC SQL END DECLARE SECTION; */ 


    vDTrazasLog (modulo,"\n\t***** Function bfnEvaluaciondeConceptosGrupo *****",LOG04);
    strcpy(szhFechaParam,szFecParam);
    strcpy(szhFechaCliente,stCliente.szFecAlta);

    if( strcmp(stPD->szCod_Tipeval,PORCONCEPTO)==0 )
    {
        for( iInd=0;iInd<stEval->iNumEval;iInd++ )
        {
            vDTrazasLog (modulo,"\tConcepto Evaluacion [%d]   Cod.Grupo[%d]   Ind.Obligat[%s]",
                         LOG04,stEval->stRegistro[iInd].iCod_Concepto
                         ,stEval->stRegistro[iInd].iCod_Grupo
                         ,stEval->stRegistro[iInd].szInd_Obliga);

            iExiste = 0; dtotalunidad  = 0;

            for( iIndF=0;iIndF<stPreFactura.iNumRegistros;iIndF++ )
            {
                if( (stEval->stRegistro[iInd].iCod_Concepto == stPreFactura.A_PFactura.iCodConcepto[iIndF])
                    && (stPreFactura.A_PFactura.iCodTipConce[iIndF] == ARTICULO ) )
                {
                    for( idxAbon=0; idxAbon < pstPlanGrupo->iNumAbonados; idxAbon++ )
                    {
                        if( pstPlanGrupo->stAbonadosGrupo[idxAbon].lNumAbonado == stPreFactura.A_PFactura.lNumAbonado[iIndF] )
                        {
                            vDTrazasLog (modulo,"\t\t*Conc.Evalua.de PreFactura [%d]"
                                         ,LOG04,stPreFactura.A_PFactura.iCodConcepto[iIndF]);
                            if( strcmp(stPD->szTip_Unidad,UNIDADMINUTOS)==0 )
                            {
                                vDTrazasLog (modulo,"\t\t\t Concepto por UNIDADMINUTOS ",LOG04);
                                pstPlanGrupo->lTotUnidad += (stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]); /* Incorporado por PGonzaleg 4-03-2002 */
                                pstPlanGrupo->dTotMonto  += stPreFactura.A_PFactura.lSegConsumido[iIndF];
                                iExiste = 1;
                            }
                            else if( strcmp(stPD->szTip_Unidad,MONTOFACTURA)==0 )
                            {
                                vDTrazasLog (modulo,"\t\t\t Concepto por MONTOFACTURA ",LOG04);
                                pstPlanGrupo->lTotUnidad += (stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]); /* Incorporado por PGonzaleg 4-03-2002 */
                                pstPlanGrupo->dTotMonto  += fnCnvDouble((stPreFactura.A_PFactura.dImpFacturable[iIndF] * stPreFactura.A_PFactura.lNumUnidades [iIndF]),USOFACT); /* Incorporado por PGonzaleg 4-03-2002 */
                                iExiste = 1;
                            }
                            vDTrazasLog (modulo,"\t\t\t Valor Monto por Concepto [%f] ",LOG04,pstPlanGrupo->dTotMonto);
                        }
                    }
                }
            }

            if( (strcmp(stEval->stRegistro[iInd].szInd_Obliga,CONCEPTOBLIGADO)==0) && (iExiste == 0) )
            {
                pstPlanGrupo->dTotMonto = 0.0;
                vDTrazasLog (modulo,"\n\t\t* Concepto [%d] es Obligatorio y no Existe en PreFactura",LOG04,stEval->stRegistro[iInd].iCod_Concepto);
                return(TRUE);
            }
            if( (stEval->stRegistro[iInd].dMto_MinFact > 0) && (pstPlanGrupo->lTotUnidad < stEval->stRegistro[iInd].dMto_MinFact) )
            {
                pstPlanGrupo->dTotMonto = 0.0;
                vDTrazasLog (modulo,"\n\t\t* Monto Acumulado es menor al Minimo a Facturar"
                             "\n\t\t* Monto Acumulado [%f] Minimo a Facturar[%f]"
                             ,LOG04,dtotalunidad,stEval->stRegistro[iInd].dMto_MinFact);
                return(TRUE);
            }

            dMontoEvalDcto_aux=pstPlanGrupo->dTotMonto;
            vDTrazasLog (modulo,"\t\t------> Monto Total a Calcular es [%f][%f]\n",LOG04,pstPlanGrupo->dTotMonto, dMontoEvalDcto_aux);
        }
    }
    else
    {  /* por factura*/
        if( strcmp(stPD->szTip_Unidad,CANTIDADABONADOS)==0 )
        {
            pstPlanGrupo->dTotMonto = pstPlanGrupo->iNumAbonados;
            vDTrazasLog (modulo,"\t\t Factura por CANTIDADABONADOS "
                         "\n\t\t Factura por [%f] ",LOG04,pstPlanGrupo->dTotMonto);
        }

        if( strcmp(stPD->szTip_Unidad,ANTIGUEDADCLIENTE)==0 )
        {
            vDTrazasLog (modulo,"\t\t Factura por ANTIGUEDADCLIENTE ",LOG04);

            /* EXEC SQL
            SELECT ROUND(TO_DATE(:szhFechaParam,'yyyymmddhh24miss') - TO_DATE(:szhFechaCliente,'yyyymmddhh24miss'))
            INTO :lhFechaAlta FROM dual; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 10;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ROUND((TO_DATE(:b0,'yyyymmddhh24miss')-TO_\
DATE(:b1,'yyyymmddhh24miss'))) into :b2  from dual ";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )361;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)256;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)szhFechaParam;
            sqlstm.sqhstl[0] = (unsigned long )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)szhFechaCliente;
            sqlstm.sqhstl[1] = (unsigned long )15;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&lhFechaAlta;
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



            if( SQLCODE != SQLOK )
            {
                vDTrazasLog (modulo,"\n\t\tError en Select para Calcular de Fecha Alta",LOG03);
                iDError (szExeName,ERR000,vInsertarIncidencia,"Select para Calcular de Fecha Alta", szfnORAerror());
                return(FALSE);
            }
            if( SQLCODE == SQLOK )
                pstPlanGrupo->dTotMonto = lhFechaAlta;
            vDTrazasLog (modulo,"\t\t Factura por [%f] ",LOG04,pstPlanGrupo->dTotMonto);
        }
        if( strcmp(stPD->szTip_Unidad,MONTOFACTURA)==0 )
        {
            pstPlanGrupo->dTotMonto = fnCnvDouble(dTotalMontoPrefactura,USOFACT);
            vDTrazasLog (modulo,"\t\t Factura por MONTOFACTURA "
                         "\n\t\t dTotalMontoPrefactura por [%f] ",LOG04,dTotalMontoPrefactura);
            if( pstPlanGrupo->dTotMonto <= stPD->dMto_Minfact )
            {
                vDTrazasLog (modulo,"\t\t--> Monto Minimo es Mayor que el Monto a Facturar"
                             "\t\t--> Monto Minimo [%f] - Monto a Facturar [%f]"
                             ,LOG02,pstPlanGrupo->dTotMonto,stPD->dMto_Minfact);
                return(TRUE);
            }
            dMontoEvalDcto_aux=pstPlanGrupo->dTotMonto;
            vDTrazasLog (modulo,"\t\t Factura por [%f][%f] ",LOG04,pstPlanGrupo->dTotMonto, dMontoEvalDcto_aux);
        }
    }
    vDTrazasLog (modulo,"\n\t***** Fin bfnEvaluaciondeConceptosGrupo Monto=[%f][%f]*****",LOG04,pstPlanGrupo->dTotMonto,dMontoEvalDcto_aux);
    return(TRUE); 
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
