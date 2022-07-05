
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
    "./pc/facturaC.pc"
};


static unsigned int sqlctx = 3446339;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4130,1,0,0,
};


/******************************************************************************
 Fichero    : facturaC.c 
 Descripcion: Generamos ejecutable para linea de comandos  

 Fecha      : 19-02-1997 
 Autor      : Javier Garcia Paredes       
*******************************************************************************/


#define _FACTURAUX_C_

#include <factura.h>

/* -------------------------------------------------------------------------- */
/*                  Variables Globales                                        */
/* -------------------------------------------------------------------------- */
CONFIG stConfig;

static char szVersion[]="v.1.0";
static char szUsage[]=
   "\nUso:   facturaC -u [Usuario]/[Password] Opciones"
   "\n\tOPCIONES:                                     "
   "\n\t-contado     [-v NumVenta] -t NumTransaccion(9) -n NumProceso(8)"
   "\n\t              -e CodCliente (8) -l [LogNivel] "
   "\n\t             [-prebilling] [-composicion]     "
   "\n\t-baja         -e CodCliente (8) -f CodCiclFact (8) -a NumAbonado(8)"
   "\n\t              -p CodProducto(1) -n NumProceso(8) -l [LogNivel]  "  
   "\n\t-liquidacion  -e CodCliente (8) -a NumAbonado(8) -p CodProducto(1) "
   "\n\t              -l [LogNivel]                   "
   "\n\t-composicion  -n NumProceso (8) -l [LogNivel] "
   "\n\t-miscelanea   -n NumProceso (8) -l [LogNivel] "
   "\n\t-compra       -n NumProceso (8) -l [LogNivel] "

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

 /*"\n\t-ciclo        -f CodCiclFact(8) -s SizeLog    -l [LogNivel] "*/

   "\n\t-ciclo        -f CodCiclFact(8) -s SizeLog    -l [LogNivel] -mc"

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

   "\n\t              -g [ClienteIni]   -h [ClienteFin] "
   "\n\t-rentphone    -e CodCliente (8) -a NumAbonado (8) -q NumAlquiler(8)"
   "\n\t-roamingvis   -e CodCliente (8) -a NumAbonado (8) -d NumEstaDia (8)"
   "\n\t-notac        -n NumProceso (8) -l [LogNivel] "
   "\n\t-notad        -n NumProceso (8) -l [LogNivel] ";

/* --------------------------------------------------------------------------*/
/*   main (int,char**)                                                       */
/*     Proceso que se encarga de leer la informacion dejada por otros modulos*/
/*     y facturarla en el presente ciclo (Prebilling). Una vez que esten los */
/*     datos del ciclo en fa_prefactura se realiza el proceso de Descuentos  */
/*     para el ciclo de facturacion.                                         */
/*     Argumentos de entrada:                                                */
/*           -u Usuario/Password Oracle -l nivel de log (por defecto 2)      */
/*           -contado      Factura Contado                                   */
/*                                                                           */
/*     Valores retorno: Codigo del error que se ha producido - Error         */
/*                      0 - Todo bien                                        */
/*                      2 - Error de Composicion                             */
/*                      6 - Error de Impresion                               */
/* --------------------------------------------------------------------------*/
int main (int argc,char* argv[])
{
  extern int   opterr;
  extern int   optopt;
  extern char* optarg;
         int   iRes  ;

  char szUsuario [61] = ""; 
  char *psztmp;

  char opt[]="u:c:v:t:n:p:l:e:f:s:m:a:b:q:r:d:g:h:";
  
  long lNumProceso = 0;
  
  int iOpt = 0, iInd = 0, iRegProc = 0;

  fprintf (stderr,"\nExe->facturaC Version [%s]" __DATE__ " " __TIME__ " TMC MC\n\n",szVersionActual);
  
  opterr = 0;
  optopt = 0;

  vInitConfig();

  stStatus.IdPro        = 0            ;
  stStatus.IdPro2       = 0            ;   
  stStatus.ExitApp      = FALSE        ;
  stStatus.ExitCode     = 0            ;
  stStatus.SkipRec      = FALSE        ;
  stStatus.SkipCode     = 0            ;
  stStatus.LogNivel     = iLOGNIVEL_DEF; 
  stStatus.LogFile      = (FILE*)NULL  ;
  stStatus.ErrFile      = (FILE*)NULL  ;
  stStatus.OraConnected = 0            ;


  while ( (iOpt=getopt(argc,argv,opt) ) !=EOF) 
  {
           switch (iOpt)
           {
               case 'u':
                 if ( strlen (optarg) )
                 {
                      strcpy (szUsuario,optarg)         ;
                      stConfig.bOptUsuario = TRUE       ; 
                      fprintf(stderr,"-u %s ",szUsuario);
                 }
                 break;
               case 'l':
                 if ( strlen (optarg) )
                 {
                      if (strcmp (optarg,"iquidacion") == 0)
                      {
                          stConfig.bOptPreBilling  = TRUE            ;
                          stConfig.iTipoFactura    = FACT_LIQUIDACION;
                          stConfig.bOptLiquidacion = TRUE            ;
                          fprintf (stderr,"-liquidacion ")           ;
                      }
                      else
                      {
                         stStatus.LogNivel = (atoi(optarg) > 0)?atoi(optarg) :
                                                                iLOGNIVEL_DEF;
                         fprintf (stderr,"-l %d\n",stStatus.LogNivel)         ;
                      }
                 }
                 break;
               case 'e':
                 if ( strlen (optarg) )
                 {
                       stConfig.lCodCliente = atol (optarg)           ;
                       stConfig.bOptCliente = TRUE                    ;
                       fprintf (stderr,"-e %ld ",stConfig.lCodCliente);
                 }
                 break;
               case 't':
                 if ( strlen (optarg) )
                 {
                       stConfig.lNumTransaccion = atol (optarg) ;
                       stConfig.bOptTransaccion = TRUE          ;
                       fprintf (stderr,"-t %ld ", atol (optarg));
                 }
                 break;
               case 'v':
                 if ( strlen (optarg) )
                 {
                      stConfig.lNumVenta    = atol (optarg)    ;
                      stConfig.bOptNumVenta = TRUE             ;
                      fprintf (stderr,"-v %ld ", atol (optarg));
                 }
                 break;
               case 'n':
                if ( strlen (optarg) )
                {
                   if ( strcmp (optarg,"otac") == 0)
                   {
                        stConfig.bOptPreBilling= TRUE         ;
                        stConfig.iTipoFactura  = FACT_NOTACRED;
                        stConfig.bOptNota      = TRUE         ;
                        fprintf (stderr,"-notac ")            ;
                   }
                   else
                   {
                      if ( strcmp (optarg,"otad") == 0)
                      {
                           stConfig.bOptPreBilling= TRUE         ;
                           stConfig.iTipoFactura  = FACT_NOTADEBI;
                           stConfig.bOptNota      = TRUE         ;
                           fprintf (stderr,"-notad ")            ;
                      }
                      else
                      {
                           stStatus.IdPro          = atol (optarg) ;
                           stConfig.lNumProceso    = atol (optarg) ;
                           stConfig.bOptNumProceso = TRUE          ;
                           fprintf (stderr,"-n %ld ",atol (optarg));
                      }
                   }
                }
                break;
             case 'p':
                if ( strlen (optarg) )
                {
                     if ( !strcmp (optarg,"rebilling") )
                     {
                           stConfig.bOptPreBilling = TRUE ;
                           fprintf (stderr,"-prebilling ");
                     }
                     else
                     {
                           stConfig.iCodProducto = atoi (optarg)  ;
                           stConfig.bOptProducto = TRUE           ;
                           fprintf (stderr,"-p %d ",atoi (optarg));
                     }
                }
                break;
             case 'c':
                if ( strlen (optarg) )
                {
                     if ( !strcmp (optarg,"ontado") )
                     {
                           stConfig.bOptContado  = TRUE        ;
                           stConfig.iTipoFactura = FACT_CONTADO;
                           fprintf (stderr,"-contado ")        ;
                     }
                     if ( !strcmp (optarg,"omposicion") )
                     {
                           stConfig.bOptComposicion = TRUE;
                           fprintf (stderr,"-composicion");
                     }
                     if ( !strcmp (optarg,"iclo") )
                     {
                           stConfig.bOptPreBilling = TRUE      ;
                           stConfig.bOptCiclo      = TRUE      ;
                           stConfig.iTipoFactura   = FACT_CICLO;
                           fprintf (stderr,"-ciclo ")          ;
                     }
                     if ( !strcmp (optarg,"ompra") )
                     {
                           stConfig.bOptPreBilling = TRUE         ;
                           stConfig.bOptCompra     = TRUE         ;
                           stConfig.iTipoFactura   = FACT_COMPRA  ;
                           fprintf (stderr,"-compra ")            ;
                     }
                }
                break;
             case 'r':
                if ( strlen (optarg) )
                {
                     if ( !strcmp (optarg,"entphone" ) )
                     {
                           stConfig.bOptPreBilling= TRUE           ;
                           stConfig.bOptRentPhone = TRUE           ;
                           stConfig.iTipoFactura  = FACT_RENTAPHONE;
                           fprintf (stderr,"-rentphone ")          ;
                     }
                     if ( !strcmp (optarg,"oamingvis") )
                     {
                           stConfig.bOptPreBilling= TRUE           ;
                           stConfig.bOptRoamingVis= TRUE           ;
                           stConfig.iTipoFactura  = FACT_ROAMINGVIS;
                           fprintf (stderr,"roamingvis ")          ;
                     }
                }
                break;
              case 'a':
                if ( strlen (optarg) )
                {
                     stConfig.lNumAbonado = atol (optarg)     ;
                     stConfig.bOptAbonado = TRUE              ;
                     fprintf (stderr,"-a %ld ", atol (optarg));
                }
                break;
              case 'b':
                if ( strlen (optarg) )
                {
                     if (!strcmp (optarg,"aja"))
                     {
                          stConfig.bOptPreBilling = TRUE     ;
                          stConfig.bOptBaja       = TRUE     ;
                          stConfig.iTipoFactura   = FACT_BAJA;
                          fprintf (stderr,"-baja ")          ;
                     }
                }
                break;
              case 'f':
                if ( strlen (optarg) )
                {
                     stConfig.lCodCiclFact = atol (optarg)   ;
                     stConfig.bOptCiclFact = TRUE            ; 
                     fprintf (stderr,"-f %ld ",atol (optarg));
                }
                break;
              case 's':
               if ( strlen (optarg) )
               {
                    stStatus.iSizeFileLog = atoi (optarg)  ;
                    stConfig.bOptSizeLog  = TRUE           ;
                    fprintf (stderr,"-s %d ",atoi (optarg));
               }
               break;
               case 'm':
                if ( strlen (optarg) )
                {
                     if ( !strcmp (optarg,"iscelanea") )
                     {
                           stConfig.bOptPreBilling = TRUE         ;
                           stConfig.bOptMiscelanea = TRUE         ;
                           stConfig.iTipoFactura   = FACT_MISCELAN;
                           fprintf (stderr,"-miscelanea ")        ;
                     }

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

		     if ( !strcmp (optarg,"c") )
                     {
                           stConfig.bOptMemShared  = TRUE         ;
                           fprintf (stderr,"-mc ")        ;
                     }

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

                }
                break;
               case 'q':
               if ( strlen (optarg) )
               {
                    stConfig.lNumAlquiler    = atol (optarg) ;
                    stConfig.bOptNumAlquiler = TRUE          ;
                    fprintf (stderr,"-q %ld ", atol (optarg));
               }
               break;
               case 'd':
               if ( strlen (optarg) )
               {
                    stConfig.lNumEstaDia     = atol (optarg) ;
                    stConfig.bOptNumEstaDia  = TRUE          ;
                    fprintf (stderr,"-d %ld ", atol (optarg)); 
               }
               break;
               case 'g':
                 if ( strlen (optarg) )
                 {
                       stConfig.lClienteIni = atol (optarg) ;
                       stConfig.bOptClienteIni = TRUE          ;
                       fprintf (stderr,"-t %ld ", atol (optarg));
                       lCodClienteIni = atol (optarg); 
                 }
                 break;
               case 'h':
                 if ( strlen (optarg) )
                 {
                       stConfig.lClienteFin = atol (optarg) ;
                       stConfig.bOptClienteFin = TRUE          ;
                       fprintf (stderr,"-t %ld ", atol (optarg));
                       lCodClienteFin = atol (optarg);
                 }
                 break;
             default:
                break; 
           }/*  fin switch ... */
 
  }/* fin While getopt ... */

  if (!stConfig.bOptUsuario)
  {
       fprintf (stderr,"\n\tFaltan Parametros de Entrada:\n%s\n",szUsage);
       return (1);
  }
  else
  {
     if ( (psztmp=(char *)strstr (szUsuario,"/"))==(char *)NULL)
     {
           fprintf (stderr,"\n\tUsuario Oracle no Valido\n%s\n",szUsage);
           return (1);
     }
     else
     {
        strncpy (stConfig.szUsuario ,szUsuario,psztmp-szUsuario);
        strcpy  (stConfig.szPassWord,psztmp+1);
     }

  }
  /****        Prueba de Log Detallado       ********/
 /*
  stStatus.LogNivel = 5;
 */

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

  /*if (!bInitInstance(stConfig.iTipoFactura))*/

  if (!bInitInstance(stConfig.iTipoFactura,stConfig.bOptMemShared))

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

       return (2);
  /* Factura Contado              */
  if (! (stConfig.bOptContado     &&
         stConfig.bOptCliente     &&
         stConfig.bOptTransaccion &&
         stConfig.bOptNumProceso) &&
      ! (stConfig.bOptComposicion &&
         stConfig.bOptNumProceso) &&
  /* Factura Ciclo                */

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/
/*    ! (stConfig.bOptCiclo       &&
         stConfig.bOptCiclFact    &&
         stConfig.bOptSizeLog)    &&  */
  /* Factura Ciclo - No MC        */
      ! (stConfig.bOptCiclo       &&
         stConfig.bOptCiclFact    &&
         !stConfig.bOptMemShared  &&
         stConfig.bOptSizeLog)    &&
  /* Factura Ciclo - Si MC        */
      ! (stConfig.bOptCiclo       &&
         stConfig.bOptCiclFact    &&
         stConfig.bOptMemShared   &&
         !stConfig.bOptClienteIni &&
         !stConfig.bOptClienteFin &&
         stConfig.bOptSizeLog)    &&
/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

  /* Factura Miscelanea           */
      ! (stConfig.bOptMiscelanea  &&
         stConfig.bOptNumProceso) &&
  /* Factura Compra               */  
      ! (stConfig.bOptCompra      &&
         stConfig.bOptNumProceso) &&
  /* Factura Baja                 */
      ! (stConfig.bOptBaja        &&
         stConfig.bOptCliente     &&
         stConfig.bOptAbonado     &&
         stConfig.bOptProducto    &&
         stConfig.bOptCiclFact    &&
         stConfig.bOptNumProceso) &&
  /* Factura Liquidacion          */ 
      ! (stConfig.bOptLiquidacion &&
         stConfig.bOptProducto    &&
         stConfig.bOptAbonado     &&
         stConfig.bOptCliente)    &&  
  /* Factura Rent Phone           */
      ! (stConfig.bOptRentPhone   &&
         stConfig.bOptCliente     &&
         stConfig.bOptAbonado     &&
         stConfig.bOptNumAlquiler)&&
  /* Factura Roaming Visitante    */
      ! (stConfig.bOptRoamingVis  &&
         stConfig.bOptCliente     &&
         stConfig.bOptAbonado     &&
         stConfig.bOptNumEstaDia) &&
  /* Factura Nota Credito o Debito*/
      ! (stConfig.bOptNota        &&
         stConfig.bOptNumProceso) ) 
  {
      fprintf (stderr,"\n\tParametros Incorrectos \n%s\n",szUsage);
      if (stStatus.ExitApp)
      {
          bExitInstance ();
          return (1);
      }
  }

  if (stConfig.bOptPreBilling)
  {

/*************************************************************************
	INI MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

      /*if (!bfnPreBilling (stConfig.iTipoFactura,stConfig.lCodCliente ,
                          stConfig.lNumAbonado ,stConfig.iCodProducto,
                          stConfig.lNumAlquiler,stConfig.lNumEstaDia ,
                          stConfig.lCodCiclFact,stConfig.lNumProceso ,
                          stConfig.lNumVenta   ,stConfig.lNumTransaccion,
                          stConfig.lClienteIni ,stConfig.lClienteFin ))*/

      if (!bfnPreBilling (stConfig.iTipoFactura,stConfig.lCodCliente ,
                          stConfig.lNumAbonado ,stConfig.iCodProducto,
                          stConfig.lNumAlquiler,stConfig.lNumEstaDia ,
                          stConfig.lCodCiclFact,stConfig.lNumProceso ,
                          stConfig.lNumVenta   ,stConfig.lNumTransaccion,
                          stConfig.lClienteIni ,stConfig.lClienteFin,
                          stConfig.bOptMemShared ))

/*************************************************************************
	FIN MODIFICACION THALES-IS MC MAYO 2004
*************************************************************************/

      {
           iRes  = (stAnomProceso.iCodAnomalia == ERR041)?6:2;
                                                  

           vDTrazasLog (szExeName,"\n\t\t* Error [%d] - Exit Code [%d]", LOG05,
                        iRes,  stStatus.ExitCode)        ;

           iDError (szExeName,ERR018,vInsertarIncidencia);
           bExitInstance ();
           return  iRes    ; 
      }
  }
  if (stConfig.bOptComposicion && stConfig.bOptContado)
  {
      if (stStatus.IdPro2 > 0)
          iRegProc = 2;
      else
          iRegProc = 1;

      for (iInd=0;iInd<iRegProc;iInd++)
      {
           if (iInd == 1)
               lNumProceso = stStatus.IdPro2;
           else
               lNumProceso = stStatus.IdPro ;

           /**********************************************************/
           /*   Retorno de ifnComposcion :                           */
           /*                              0 => OK                   */
           /*                              1 => Error Composicion    */
           /*                              2 => Error Impresion      */
           /**********************************************************/ 
           iRes = ifnComposicion (lNumProceso, stConfig.lCodCliente,
                                  stConfig.iTipoFactura); 
           if (iRes == 1)
           {
               iDError (szExeName,ERR029,vInsertarIncidencia);
               bExitInstance ();
               return  (2)     ;
           }
           if (iRes == 2)
           {
               iDError (szExeName,ERR041,vInsertarIncidencia);
               bExitInstance ();
               return (6)      ;
           }
       }

  }/* fin if bOptComposicion */
      
  bExitInstance ();
  return (0);
}/**************************** Final main ************************************/



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

