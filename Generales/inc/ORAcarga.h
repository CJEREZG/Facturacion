/*****************************************************************************/
/*    Fichero     : ORAcarga.h                                               */
/*    Descripcion : libreria soporte de ORAcarga.pc                          */
/*    Autor       : Javier Garcia Paredes                                    */
/*    Fecha       : 21-Oct-96                                                */
/*****************************************************************************/
#ifndef _ORACARGA_H_
#define _ORACARGA_H_

#include <predefs.h>
#include <GenFA.h>


#undef access
#define access extern
/*****************************************************************************/
/*                   Declaracion de prototipos de ORAcarga.pc                */
/*****************************************************************************/
#ifdef  _ORACARGA_PC_ 

static int  ifnSelectCiudad (CIUDADES *pC)             ;
static BOOL bfnCargaCiudad  (CIUDADES *pC)             ;

static int  ifnSelectComuna (COMUNAS *pC)              ;
static BOOL bfnCargaComuna  (COMUNAS *pC)              ;
       
static int  iOpenZonaCiudad (void)                     ;
static int  iFetchZonaCiudad(ZONACIUDAD* )             ;
static int  iCloseZonaCiudad(void)                     ;

static int  ifnDBOpenServEspeciales (void)             ;
static int  ifnDBFetchServEspeciales(SERVESPECIALES *) ;
static int  ifnDBCloseServEspeciales(void)             ;

static int ifnDBOpenTipTerminales (void)               ;
static int ifnDBFetchTipTerminales(TIPOSTERMINALES *)  ;
static int ifnDBCloseTipTerminales (void)              ;

static int ifnDBOpenTipCobertura (void)            ;
static int ifnDBFetchTipCobertura(TIPCOBERTURA *)  ;
static int ifnDBCloseTipCobertura (void)           ;


static int  ifnOpenLimCreditos (void);
static int  ifnFetchLimCreditos (LIMCREDITOS *);
static int  ifnCloseLimCreditos (void);
static void vfnPrintLimCreditos (LIMCREDITOS *,int);

static int  iOpenCatImpClientes  (void)                ;
static int  iCloseCatImpClientes (void)                ;

static int  iOpenTipImpues (void)                      ;
static int  iFetchTipImpues (TIPIMPUES* )              ;
static int  iCloseTipImpues(void)                      ;

static int  iOpenCatImpositiva (void)                  ;
static int  iFetchCatImpositiva (CATIMPOSITIVA* )      ;
static int  iCloseCatImpositiva (void)                 ;

static int  iOpenZonaImpositiva (void)                 ;
static int  iFetchZonaImpositiva (ZONAIMPOSITIVA* )    ;
static int  iCloseZonaImpositiva (void)                ;

static int  iOpenImpuestos (void)                      ;
static int  iFetchImpuestos (IMPUESTOS* pImpu)         ;
static int  iCloseImpuestos (void)                     ;

static int  iOpenGrpSerConc (void)                     ;
static int  iFetchGrpSerConc (GRPSERCONC* )            ;
static int  iCloseGrpSerConc (void)                    ;

static int  iOpenDirecciones (void)                    ;
static int  iFetchDirecciones (DIRECCIONES* pDir)      ;
static int  iCloseDirecciones (void)                   ;

static int  iOpenDireccli (void)                       ;
static int  iFetchDireccli (DIRECCLI*)                 ;
static int  iCloseDireccli (void)                      ;

static int iOpenCiclFact (void)                        ;
static int iFetchCiclFact (CICLO* )                    ;
static int iCloseCiclFact (void)                       ;

static int iOpenCargos (int iTipoFact,long ,long)      ;
static int iFetchCargos (CARGOS *,int iTipoFac)        ;
static int iCloseCargos (int iTipoFact,long lNumVenta) ;

static int iOpenPenalizaciones  (int,long)             ;
static int iFetchPenalizaciones (int,PENALIZA *)       ;
static int iClosePenalizaciones (int)                  ;

static int  ifnOraCuentaConceptos(int*)               ;
static int  iOpenConceptos (void)                      ;
static int iFetchConceptos (CONCEPTO* pstConceptos, int *iCodConcepto ) ;
static int  iCloseConceptos(void)                      ;

static int  iOpenConceptos_mi (void)                      ;
static int  iFetchConceptos_mi(CONCEPTO_MI* pConc_mi)           ;
static int  iCloseConceptos_mi(void)                      ;

static int  iOpenTaConcepFact (void)                   ;
static int  iFetchTaConcepFact (TACONCEPFACT *)        ;
static int  iCloseTaConcepFact (void)                  ;

static int  iOpenAnomalias (void)                      ;
static int  iFetchAnomalias (ANOMALIAS *)              ;
static int  iCloseAnomalias (void)                     ;

static int  iOpenConversion (char *,char *)            ;
static int  iFetchConversion(CONVERSION *)             ;
static int  iCloseConversion(void)                     ;

static int  iOpenLetras (void)                         ;
static int  iFetchLetras(LETRAS *pLetra)               ;
static int  iCloseLetras(void)                         ;

static int  iOpenDocumSucursal (void)                  ;
static int  iFetchDocumSucursal(DOCUMSUCURSAL *)       ;
static int  iCloseDocumSucursal(void)                  ;

static int  iOpenActuaServ (void)                      ;
static int  iFetchActuaServ(ACTUASERV *)               ;
static int  iCloseActuaServ(void)                      ;

static int  iOpenCargosBasico (void)                   ;
static int  iFetchCargosBasico(CARGOSBASICO *)         ;
static int  iCloseCargosBasico(void)                   ;

static int  iOpenPlanTarif (void)                      ;
static int  iFetchPlanTarif(PLANTARIF*)                ;
static int  iClosePlanTarif(void)                      ;

static int  iOpenGrupoCob (void)                       ;
static int  iFetchGrupoCob(GRUPOCOB *)                 ;
static int  iCloseGrupoCob(void)                       ;

static int  iOpenCabCuotas  (int,long,long)            ;
static int  iFetchCabCuotas (CABCUOTAS *,int)          ;
static int  iCloseCabCuotas (int)                      ;


static int  iOpenCtoPlan (void)                        ;
static int  iFetchCtoPlan(CTOPLAN *)                   ;
static int  iCloseCtoPlan(void)                        ;

static int  iOpenPlanCtoPlan (void)                    ;
static int  iFetchPlanCtoPlan(PLANCTOPLAN *)           ;
static int  iClosePlanCtoPlan(void)                    ;

static int  iOpenArriendo (void)                       ;
static int  iFetchArriendo (ARRIENDO *)                ;
static int  iCloseArriendo (void)                      ;
static int  iCmpArriendo (const void*,const void*)     ;
static void vPrintArriendo (ARRIENDO *,int)            ;

static int  iOpenProvincias (void)                     ;
static int  iFetchProvincias (PROVINCIAS *)            ;
static int  iCloseProvincias (void)                    ;
static void vPrintProvincias (PROVINCIAS *,int)        ;

static int  iOpenRegiones (void)                       ;
static int  iFetchRegiones (REGIONES *)                ;
static int  iCloseRegiones (void)                      ;

static int  iOpenActividades (void)                    ;
static int  iFetchActividades(ACTIVIDADES *)           ;
static int  iCloseActividades(void)                    ;
static void vPrintActividades(ACTIVIDADES *,int)       ;

static int  ifnOpenRangoTabla (void)                   ;
static int  ifnFetchRangoTabla (RANGOTABLA *)          ;
static int  ifnCloseRangoTabla (void)                  ;
access void vfnPrintRangoTabla (RANGOTABLA *,int )     ;

static int  ifnOpenDesAcumulado (void)                 ;
static int  ifnFetchDesAcumulado(DESACUMULADO *)       ;
static int  ifnCloseDesAcumulado(void)                 ;
static void vfnPrintDesAcumulado(DESACUMULADO *,int)   ;
access int  ifnCmpDesAcumulado(const void*,const void*);

static int  iOpenFactCarriers (void)                   ;
static int  iFetchFactCarriers(FACTCARRIERS *)         ;
static int  iCloseFactCarriers(void)                   ;
static int  iCmpFactCarriers (const void *cad1, 
                              const void *cad2)        ;

static int  ifnDBOpenOptimo   (void)                   ;
static int  ifnDBFetchOptimo  (OPTIMO *)               ;
static int  ifnDBCloseOptimo  (void)                   ;

static int  ifnDBOpenAlms     (void)                   ;
static int  ifnDBFetchAlms    (ALMS *)                 ;
static int  ifnDBCloseAlms    (void)                   ;

static BOOL bfnOpenFeriados   (void)                   ;
static BOOL bfnFetchFeriados  (FERIADOS *)             ;
static BOOL bfnCloseFeriados  (void)                   ;

access void vPrintDirecciones (DIRECCIONES*, int)      ;
access void vPrintDirecCli    (DIRECCLI*   , int)      ;
access void vPrintFaConceptos (CONCEPTO*   , int)      ;
access void vPrintTipImpues   (TIPIMPUES*  , int)      ;

access void vPrintZonaImpositiva (ZONAIMPOSITIVA*,int) ;
access void vPrintPenalizaciones (PENALIZA *, int )    ;
access void vPrintCargos (CARGOS *,int)                ;
access void vPrintTaConcepFact (TACONCEPFACT *,int  )  ;
access void vPrintFactCarriers (FACTCARRIERS *,int  )  ;

access void vPrintFaConceptos_mi (CONCEPTO_MI* pConc_mi,long )   ;

static BOOL bfnOpenFaCiclFact (void)				;
static BOOL bfnFetchFaCiclFact (int *pstFaCiclFact);
static int bfnCloseFaCiclFact (void)				;
void vfnPrintFaCiclFact (int *pstFaCiclFact, int iNumFaCiclFact);

static int  ifnOpenOficinas   (void)				   ;
static BOOL bfnFetchOficinas  (OFICINA_HOSTS *pstHost,long *plNumFilas);
static int  ifnCloseOficinas  (void)				   ;
access void vfnPrintOficinas 	(OFICINA *pstOficina, int iNumOficinas);


static int ifnOpenOperServEsp (void);
static BOOL bfnFetchOperServEsp (OPERSERVESP_HOSTS *pstHost,long *plNumFilas);
void vfnPrintOperServEsp (OPERSERVESP *pstOperSerEsp, int iNumOperSerEsp);
int ifnCloseOperServEsp (void);

static int ifnOpenDetPlanDesc (char *szFechaParam);
static BOOL bfnFetchDetPlanDesc (DETPLANDESC_HOSTS *pstHost,long *plNumFilas);
int ifnCloseDetPlanDesc (void);
access BOOL bfnCargaDetPlanDesc (DETPLANDESC **pstDetPlanDesc, int *iNumRegs, char *szFechaParam);

static int  ifnOpenDescPuntual (void);
static BOOL bfnFetchDescPuntual (DETCARG_PUNTUALES_HOSTS *pstHost,long *plNumFilas);
int ifnCloseDescPuntual (void);

access int  iCmpCargDescPuntual (const void*,const void*);

#else
#undef access
#define access extern
access BOOL bfnFindCiudad (CIUDADES *pC,int iTipoFact) ;
access BOOL bfnFindComuna (COMUNAS  *pC,int iTipoFact) ;

access int  ifnCmpServEspeciales  (const void*, const void*);
access void vfnPrintServEspeciales(GSERVESPECIALES)         ;
access BOOL bfnFindServEspeciales (SERVESPECIALES*)         ;
access BOOL bfnCargaServEspeciales(GSERVESPECIALES *)       ;


access BOOL bfnCargaTipTerminales (GTIPOSTERMINALES *)      ;
access void vfnPrintTipTerminales (GTIPOSTERMINALES)        ;
access int  ifnCmpTipTerminales (const void* , const void* );
access BOOL bfnFindTipTerminales (TIPOSTERMINALES *)        ;

access BOOL bfnCargaTipCobertura  (GTIPCOBERTURA *)         ; 
access void vfnPrintTipCobertura  (GTIPCOBERTURA)           ;
access int  ifnCmpTipCobertura  (const void* , const void* );
access BOOL bfnFindTipCobertura  (TIPCOBERTURA *)           ;



access BOOL bCargaConceptos (CONCEPTO** pstConc,int*)   ;
access void vPrintFaConceptos (CONCEPTO* pConc,int )   ;

access BOOL bCargaConceptos_mi (CONCEPTO_MI* pstConc_mi,long*)   ;

access BOOL bCargaGrpSerConc (GRPSERCONC* , int*)      ;

access BOOL bCargaZonaCiudad (ZONACIUDAD*,int* )       ;

access BOOL bCargaProvincias (PROVINCIAS*,int*)        ;

access BOOL bCargaRegiones (REGIONES*,int*)            ;

access BOOL bCargaTipImpues (TIPIMPUES* ,int*)         ;
access int  iCmpTipImpues (const void*, const void*)   ;
access void vPrintTipImpues (TIPIMPUES*,int)           ;


access BOOL bCargaCatImpositiva (CATIMPOSITIVA*,int* ) ;
access int  iCmpCatImpositiva (const void*,const void*);
access void vPrintCatImpositiva (CATIMPOSITIVA*,int)   ;

access BOOL bCargaZonaImpositiva (ZONAIMPOSITIVA*,int*) ;
access int  iCmpZonaImpositiva (const void*,const void*);
access void vPrintZonaImpositiva (ZONAIMPOSITIVA*,int)  ;

access BOOL bCargaCatImpClientes (CATIMPCLIENTES*,int*);

access BOOL bCargaImpuestos (IMPUESTOS* pstImpuestos,int*);
access int  iCmpImpuestos (const void*, const void*  )    ;

access BOOL bCargaDirecciones (DIRECCIONES* ,int*)     ;
access int  iCmpDirecciones (const void*, const void*) ;
access void vPrintDirecciones (DIRECCIONES*,int)       ;

access BOOL bCargaDirecCli (DIRECCLI* ,int*)           ;
access int  iCmpDirecCli (const void*, const void* )   ;
access void vPrintDirecCli (DIRECCLI*,int)             ;

access BOOL bCargaCiclFact (CICLO* ,int*)              ;

access BOOL bCargaCargos (CARGOS * ,int*,int,long,long);
access int  iCmpCargos (const void*,const void*)       ;
access void vPrintCargos (CARGOS *,int )               ;

access BOOL bCargaPenalizaciones (PENALIZA *,int *,int,long);
access int  iCmpPenalizaciones(const void*,const void*)     ;
access void vPrintPenalizaciones (PENALIZA *, int )         ;

access BOOL bCargaTaConcepFact (TACONCEPFACT *,int *)  ;
access int  iCmpTaConcepFact (const void*, const void*);
access void vPrintTaConcepFact (TACONCEPFACT *,int  )  ;

access BOOL bCargaAnomalias (ANOMALIAS *,int *)        ;

access BOOL bCargaConversion (CONVERSION *,int *,char*,
                              char*)                   ;
access void vPrintConversion (CONVERSION *,int  )      ;

access BOOL bCargaLetras (LETRAS *, int *)             ;

access BOOL bCargaDocumSucursal (DOCUMSUCURSAL *,int *);

access BOOL bCargaActuaServ (ACTUASERV *,int *)        ;
access int  iCmpActuaServ (const void*,const void*)    ;
access void vPrintActuaServ(ACTUASERV *,int )          ;

access BOOL bCargaPlanTarif (PLANTARIF*,int *)         ;
access int  iCmpPlanTarif (const void*,const void*)    ;
access void vPrintPlanTarif(PLANTARIF*, int )          ;

access BOOL bCargaGrupoCob (GRUPOCOB* ,int *)          ;

access BOOL bCargaCargosBasico (CARGOSBASICO*,int*)    ;
access int  iCmpCargosBasico (const void*,const void*) ;
access void vPrintCargosBasico (CARGOSBASICO*,int)     ;

access BOOL bCargaCuotas (CUOTAS *,int *,int,long)     ;
access int  iCmpCuotas   (const void*,const void*)     ;
access int  iOpenCuotas  (int,long)                    ;
access int  iFetchCuotas (CUOTAS *,int)                ;
access int  iCloseCuotas (int)                         ;

access BOOL bCargaCtoPlan(CTOPLAN *,int *)             ;
access int  iCmpCtoPlan  (const void*,const void*)     ;
access void vPrintCtoPlan (CTOPLAN *,int )             ;

access BOOL bCargaPlanCtoPlan(PLANCTOPLAN *,int *)     ;
access int  iCmpPlanCtoPlan  (const void*,const void*) ;
access void vPrintPlanCtoPlan (PLANCTOPLAN *,int )     ;

access BOOL bCargaCabCuotas(CABCUOTAS *,int *,int,long,long);
access int  iCmpCabCuotas(const void*,const void*)     ;

access BOOL bCargaActividades (ACTIVIDADES *,int *)    ;
access int  iCmpActividades (const void*,const void*)  ;

access BOOL bCargaArriendo (ARRIENDO *,int *)          ;

access BOOL bfnCargaRangoTabla (RANGOTABLA *,int *)    ;
access void vfnPrintRangoTabla (RANGOTABLA *,int )     ;

access BOOL bfnCargaLimCreditos (LIMCREDITOS *,int *)  ;
access int  iCmpLimCreditos (const void*,const void*)  ;

access BOOL bfnCargaDesAcumlado (DESACUMULADO*,int *)  ;
access int  ifnCmpDesAcumulado(const void*,const void*);
access BOOL bfnFindDesAcumulado (int ,DESACUMULADO *)  ;

access BOOL bfnCargaOptimo (OPTIMO *, int *)           ;
access int  ifnCmpOptimo   (const void*, const void*)  ;
access BOOL bfnFindOptimo  (OPTIMO *)                  ;
 
access BOOL bCargaFactCarriers (FACTCARRIERS *, int *) ;

access BOOL bfnCargaAlms (ALMS *, int *)               ;
access int  ifnCmpAlms   (const void *, const void *)  ;
access BOOL bfnFindAlms  (ALMS *)                      ; 

access BOOL bfnCargaFeriados (FERIADOS *, int *)       ; 

access BOOL bCargaPlanTarif (PLANTARIF *, int *)       ; 

access BOOL bfnCargaDesAcumulado (DESACUMULADO *pDes, int *iNumDes);

access BOOL bCargaTarifas (TARIFAS *pTar,int *iNumTar) ;

access BOOL bCargaCuadCtoPlan (CUADCTOPLAN *pCuad,int *iNumCuad);

access BOOL bfnCargaFactCobr (FACTCOBR **pstFactCobr, int *iNumFactCobr);

access BOOL bfnCargaOficinas (OFICINA **pstOficinas, int *iNumOficinas);

access BOOL bfnCargaOperServEsp (OPERSERVESP **pstOperServEsp, int *iNumOperServEsp);

access BOOL bfnCargaFaCiclFact (int *pstFaCiclFact, int *iNumFaCiclFact);
access BOOL bfnCargaDetPlanDesc (DETPLANDESC **pstDetPlanDesc, int *iNumRegs, char *szFechaParam);


access BOOL bfnCargaDescPuntual (DETCARG_PUNTUALES **pstDescPuntuales, int *iNumDetCarg);

#endif /* _ORACARGA_H_ */
#endif /* _ORACARGA_PC_*/


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

