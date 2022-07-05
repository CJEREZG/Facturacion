whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode


/* ----->CONSULTA 1 <------ */   

/*--------- PREPARA CONSULTA PARA COD_CONCEPTOART DE AL ARTICULOS---------------*/                
                                
UPDATE AL_ARTICULOS    A        
SET    COD_CONCEPTOART =(SELECT DISTINCT CODIGO_DESTINO 
                         FROM FA_ENTRADA_TO B 
                         WHERE A.COD_CONCEPTOART=B.CODIGO_CONCEPTO)
WHERE A.COD_CONCEPTOART IN (SELECT CODIGO_CONCEPTO FROM FA_ENTRADA_TO);
        
COMMIT;

/*-------   PREPARA CONSULTA PARA COD_CONCEPTODTO DE AL ARTICULOS------------------*/

UPDATE AL_ARTICULOS A        
SET    COD_CONCEPTODTO=(SELECT DISTINCT C.COD_CONCEPTO
                        FROM FA_ENTRADA_TO B, FA_CONCEPTOS C 
                        WHERE A.COD_CONCEPTOART=B.CODIGO_CONCEPTO
                        AND B.CODIGO_DESTINO=C.COD_CONCORIG)
WHERE A.COD_CONCEPTODTO IN (SELECT COD_CONCEPTO 
                            FROM FA_CONCEPTOS D, FA_ENTRADA_TO E
                            WHERE A.COD_CONCEPTODTO=D.COD_CONCEPTO
                            AND D.COD_CONCORIG=E.CODIGO_CONCEPTO);
                                
                                
COMMIT;

EXIT 0;