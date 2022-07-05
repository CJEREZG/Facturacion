--------------------------------------------
-- Traspaso trafico de TA_LLAMADASROA
-----------------------------------------------
-- Parametros
-- $1 Ciclo facturacion DDMMYY

SET serveroutput on
SET term on
SET feedback off
SET verify off

DECLARE 

LV_COD_TARIFICACION 	FA_HISTACUMLLAM.COD_TARIFICACION%type;
LV_IND_TABLA 		FA_HISTACUMLLAM.IND_TABLA%type;
LV_COD_PRODUCTO 	FA_HISTACUMLLAM.COD_PRODUCTO%type;
LV_NUM_PULSOS		FA_HISTACUMLLAM.NUM_PULSOS%type;
LV_FEC_EFECTIVIDAD      FA_HISTACUMLLAM.FEC_EFECTIVIDAD%type;
LV_NUM_PROCESO          FA_HISTACUMLLAM.NUM_PROCESO%type; 
LV_COD_CLIENTE		FA_HISTACUMLLAM.COD_CLIENTE%type; 
LV_IND_DESTINO		FA_HISTACUMLLAM.IND_DESTINO%type;
LV_COD_SERVICIO		FA_HISTACUMLLAM.COD_SERVICIO%type; 
LV_COD_OPERADOR		FA_HISTACUMLLAM.COD_OPERADOR%type;
LN_COD_TIPDOCUM         NUMBER(2);
LN_NUM_FOLIO            NUMBER(9);
LN_Cantidad             NUMBER(10);
LN_CantidadAC           NUMBER(10);
LN_CantidadDEL		NUMBER(10);
LN_CantidadDEL_ACUM	NUMBER(10);
LN_CantidadINS		NUMBER(10);
LN_CantidadINSAC	NUMBER(10);


BEGIN
LN_Cantidad             := 0;
LN_CantidadAC           := 0;
LN_CantidadDEL		:= 0;
LN_CantidadDEL_ACUM :=0;
LN_CantidadINS		:= 0;
LN_CantidadINSAC	:= 0;
LN_COD_TIPDOCUM         := 0;
LN_NUM_FOLIO            := 0;
LV_COD_TARIFICACION     := 0;
LV_IND_TABLA 		:= 1;
LV_COD_PRODUCTO 	:= 1;	
LV_NUM_PULSOS		:= 0;
LV_FEC_EFECTIVIDAD      := SYSDATE;
LV_NUM_PROCESO          := 0;
LV_IND_DESTINO		:= NULL;
LV_COD_SERVICIO		:= NULL;	
LV_COD_OPERADOR		:= NULL;

   BEGIN
    
        SELECT  count(1)
        INTO	LN_Cantidad
        FROM	TA_LLAMADASROA
        WHERE	COD_CLIENTE  = '&1' AND
                NUM_ABONADO  = '&2' AND
                COD_CICLFACT = '&3';
    
        EXCEPTION 
        WHEN OTHERS THEN
              DBMS_OUTPUT.PUT_LINE(SQLERRM);
              RAISE_APPLICATION_ERROR (-20000, 'ERROR en SELECT a TA_LLAMADASROA' );
    END;


   BEGIN
        SELECT  count(1)
        INTO	LN_CantidadAC
	FROM    TA_ACUMLLAMADASROA
	WHERE   COD_CLIENTE  = '&1' AND
                NUM_ABONADO  = '&2' AND
                COD_CICLFACT = '&3';
        EXCEPTION 
        WHEN OTHERS THEN
              DBMS_OUTPUT.PUT_LINE(SQLERRM);
              RAISE_APPLICATION_ERROR (-20001, 'ERROR en SELECT a TA_ACUMLLAMADASROA' );
    END;

   BEGIN
        SELECT  NUM_PROCESO,       COD_TIPDOCUM,    NUM_FOLIO
        INTO	LV_NUM_PROCESO, LN_COD_TIPDOCUM, LN_NUM_FOLIO
	FROM    FA_HISTDOCU
	WHERE   COD_CLIENTE  = '&1' AND
                NUM_FOLIO    = '&4';

        DBMS_OUTPUT.PUT_LINE('NUMERO DE PROCESO RECUPERADO DESDE FA_HISTDOCU = '||LV_NUM_PROCESO );
        DBMS_OUTPUT.PUT_LINE('TIPO DE DOCUMENTO RECUPERADO DESDE FA_HISTDOCU = '||LN_COD_TIPDOCUM );
        DBMS_OUTPUT.PUT_LINE('NUMERO DE FOLIO RECUPERADO DESDE FA_HISTDOCU   = '||LN_NUM_FOLIO );
         
        EXCEPTION 
        WHEN OTHERS THEN
              DBMS_OUTPUT.PUT_LINE(SQLERRM);
              RAISE_APPLICATION_ERROR (-20002, 'ERROR en SELECT a FA_HISTDOCU' );
    END;
        
    
      
    IF (LN_Cantidad=0) THEN 
       DBMS_OUTPUT.PUT_LINE('NO SE ENCONTRARON REGISTROS A TRASPASAR (TA_LLAMADASROA='||LN_Cantidad||' Y TA_ACUMLLAMADASROA='||LN_CantidadAC||')');
    ELSE  
         
         IF (LN_CantidadAC=0) THEN 
           /* Insertar en TA_ACUMLLAMADASROA */
           DBMS_OUTPUT.PUT_LINE('NO SE ENCONTRARON REGISTROS EN TA_ACUMLLAMADASROA, SE INSERTA DESDE TA_LLAMADASROA');
           
           BEGIN
           
             INSERT INTO TA_ACUMLLAMADASROA(
                         COD_CLIENTE, 
                         COD_OPERADOR, 
                         NUM_ABONADO, 
                         COD_CICLFACT, 
                         NUM_PROCESO, 
                         IMP_CONSUMIDO, 
                         SEG_CONSUMIDO)
             SELECT 
                   A.COD_CLIENTE, 
                   B.COD_OPERADOR,  
                   A.NUM_ABONADO, 
                   A.COD_CICLFACT, 
                   LV_NUM_PROCESO as NUM_PROCESO ,
                   sum(A.IMP_MONTOAIRE+A.IMP_MONTOLARGA) as IMP_CONSUMIDO, 
                   sum(A.SEG_AIRE+A.SEG_DURA) as SEG_CONSUMIDO 
                   FROM TA_LLAMADASROA A, TA_CONCILIACION B
                   WHERE COD_CLIENTE = '&1'  AND 
                         NUM_ABONADO = '&2'  AND 
                         COD_CICLFACT = '&3' AND
                         A.NUM_BLOQUE = B.NUM_BLOQUE AND
                         B.IND_OPERACION=0              
                   GROUP BY A.COD_CLIENTE,B.COD_OPERADOR,A.NUM_ABONADO,A.COD_CICLFACT ;
                   
                   DBMS_OUTPUT.PUT_LINE('INSERT A TA_ACUMLLAMADASROA OK');
                   LN_CantidadINSAC := SQL%ROWCOUNT;
                   
           EXCEPTION 
           WHEN OTHERS THEN
              DBMS_OUTPUT.PUT_LINE(SQLERRM);
              RAISE_APPLICATION_ERROR (-20003, 'ERROR en INSERT A TA_ACUMLLAMADASROA' );
           END;
             
         END IF;
             
                            
         BEGIN
         
	    INSERT INTO FA_LLAMADASROA (
		    COD_CLIENTE     ,
		    NUM_ABONADO     ,
		    COD_CICLFACT    ,
		    NUM_MOVIL       ,
		    NUM_ASIGNADO    ,
		    FEC_LLAMADA     ,
		    HOR_LLAMADA     ,
		    SEG_AIRE        ,
		    SEG_DURA        ,
		    IMP_MONTOLARGA  ,
		    IMP_MONTOAIRE   ,
		    NUM_DESTINO     ,
		    IND_ENTSAL      ,
		    IND_LARGA       ,
		    DES_DESTINO     ,
		    NUM_BLOQUE      ,
		    SEC_LLAMADAS    )
	    SELECT  LLA.COD_CLIENTE     ,
		    LLA.NUM_ABONADO     ,
		    LLA.COD_CICLFACT    ,
		    LLA.NUM_MOVIL       ,
		    LLA.NUM_ASIGNADO    ,
		    LLA.FEC_LLAMADA     ,
		    LLA.HOR_LLAMADA     ,
		    LLA.SEG_AIRE        ,
		    LLA.SEG_DURA        ,
		    LLA.IMP_MONTOLARGA  ,
		    LLA.IMP_MONTOAIRE   ,
		    LLA.NUM_DESTINO     ,
		    LLA.IND_ENTSAL      ,
		    LLA.IND_LARGA       ,
		    LLA.DES_DESTINO     ,
		    LLA.NUM_BLOQUE      ,
		    LLA.SEC_LLAMADAS
	    FROM    TA_LLAMADASROA      LLA,
		    TA_CONCILIACION     CON
	    WHERE   LLA.COD_CLIENTE  = '&1'
	    AND     LLA.NUM_ABONADO  = '&2'
	    AND     LLA.COD_CICLFACT = '&3'
	    AND     LLA.NUM_BLOQUE   = CON.NUM_BLOQUE
	    AND     CON.COD_OPERADOR IN (
					 SELECT  COD_OPERADOR    
					 FROM    TA_ACUMLLAMADASROA
					 WHERE   COD_CLIENTE  = '&1' AND
						 NUM_ABONADO  = '&2' AND
						 COD_CICLFACT = '&3')
	    AND     CON.IND_OPERACION = 0;          
                    
            DBMS_OUTPUT.PUT_LINE('INSERT A FA_LLAMADASROA OK');
            LN_CantidadINS := SQL%ROWCOUNT;
            
            EXCEPTION 
            WHEN OTHERS THEN
                   ROLLBACK;
                   DBMS_OUTPUT.PUT_LINE(SQLERRM);
                   RAISE_APPLICATION_ERROR (-20004, 'ERROR en INSERT A FA_LLAMADASROA');
         END;
	     
         BEGIN
         
	    INSERT INTO FA_HISTACUMLLAM (
		    NUM_ABONADO         ,
		    COD_CICLFACT        ,
		    IND_ENTSAL          ,
		    COD_TARIFICACION    ,
		    IND_TABLA           ,
		    COD_PRODUCTO        ,
		    IMP_CONSUMIDO       ,
		    SEG_CONSOPER        ,
		    IMP_CONSOPER        ,
		    SEG_CONSUMIDO       ,
		    NUM_PULSOS          ,
		    FEC_EFECTIVIDAD     ,
		    NUM_PROCESO         ,
		    COD_CLIENTE         )
	    SELECT  NUM_ABONADO         ,
		    COD_CICLFACT        ,
		    2                   ,
		    COD_OPERADOR        ,
		    3                   ,
		    1                   ,
		    IMP_CONSUMIDO       ,
		    SEG_CONSUMIDO       ,
		    IMP_CONSUMIDO       ,
		    SEG_CONSUMIDO       ,
		    0                   ,
		    LV_FEC_EFECTIVIDAD  ,
		    LV_NUM_PROCESO      ,
		    COD_CLIENTE
	    FROM    TA_ACUMLLAMADASROA
	    WHERE   COD_CLIENTE  = '&1' AND
		    NUM_ABONADO  = '&2' AND
		    COD_CICLFACT = '&3';
   	                       
            DBMS_OUTPUT.PUT_LINE('INSERT EN FA_HISTACUMLLAM OK');
   	            
   	         
                EXCEPTION 
                WHEN OTHERS THEN
                    ROLLBACK;
                    DBMS_OUTPUT.PUT_LINE(SQLERRM);
                    RAISE_APPLICATION_ERROR (-20005,'ERROR en INSERT a FA_HISTACUMLLAM' );
         END;	 

	 BEGIN
		    DELETE
		    FROM    TA_LLAMADASROA  A
		    WHERE   A.COD_CLIENTE  = '&1'
		    AND     A.NUM_ABONADO  = '&2'
		    AND     A.COD_CICLFACT = '&3'
		    AND     A.NUM_BLOQUE in (   SELECT B.NUM_BLOQUE
						FROM   TA_CONCILIACION B
						WHERE  B.COD_OPERADOR  IN (
						 SELECT  COD_OPERADOR    
						 FROM    TA_ACUMLLAMADASROA
						 WHERE   COD_CLIENTE  = '&1' AND
							 NUM_ABONADO  = '&2' AND
							 COD_CICLFACT = '&3')
						AND    B.IND_OPERACION  = 0
						AND    B.NUM_BLOQUE     = A.NUM_BLOQUE);

   	                       
                DBMS_OUTPUT.PUT_LINE('DELETE EN TA_LLAMADASROA OK');
   	            
   	        LN_CantidadDEL := SQL%ROWCOUNT;
   	         
                EXCEPTION 
                WHEN OTHERS THEN
                    ROLLBACK;
                    DBMS_OUTPUT.PUT_LINE(SQLERRM);
                    RAISE_APPLICATION_ERROR (-20006,'ERROR en DELETE a TA_LLAMADASROA' );
	 END;
	 
	 /*36131 - HHA - Rechazo
	   Falta eliminar de TA_ACUMLLAMADASROA*/
	   BEGIN
	   		DELETE FROM TA_ACUMLLAMADASROA
	   		WHERE COD_CLIENTE  = '&1' AND
		    	  NUM_ABONADO  = '&2' AND
		    	  COD_CICLFACT = '&3';
		    
		    LN_CantidadDEL_ACUM := SQL%ROWCOUNT;
		    EXCEPTION 
                WHEN OTHERS THEN
                    ROLLBACK;
                    DBMS_OUTPUT.PUT_LINE(SQLERRM);
                    RAISE_APPLICATION_ERROR (-20007,'ERROR en DELETE a TA_ACUMLLAMADASROA' );

		    DBMS_OUTPUT.PUT_LINE('DELETE EN TA_ACUMLLAMADASROA OK');                    
	   END;
	 /*36131 - HHA - Rechazo*/
         
         DBMS_OUTPUT.PUT_LINE('===========================================================');
         DBMS_OUTPUT.PUT_LINE('CUADRATURA: ');
         DBMS_OUTPUT.PUT_LINE('===========================================================');
         DBMS_OUTPUT.PUT_LINE('REGISTROS A TRASPASAR DESDE TA_LLAMADASROA = '||LN_Cantidad );
         DBMS_OUTPUT.PUT_LINE('REGISTROS INSERTADOS EN  FA_LLAMADASROA    = '||LN_CantidadINS );
         DBMS_OUTPUT.PUT_LINE('REGISTROS ELIMINADOS DE TA_LLAMADASROA     = '||LN_CantidadDEL );
         DBMS_OUTPUT.PUT_LINE('REGISTROS INSERTADOS EN TA_ACUMLLAMADASROA = '||LN_CantidadINSAC );
         DBMS_OUTPUT.PUT_LINE('REGISTROS ELIMINADOS EN TA_ACUMLLAMADASROA = '||LN_CantidadDEL_ACUM );
         DBMS_OUTPUT.PUT_LINE('===========================================================');
         
         COMMIT;
     END IF;
         
END;

/
EXIT;
