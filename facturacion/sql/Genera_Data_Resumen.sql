--Baja Totales de de Pago/Resumen Consumo a Archivo Plano
--Genera El Archivo <PAGO_RES_TOT.data>
--con los totales dado el numero de secuencia

SET PAGES 0;
SET PAUSE OFF;
SET VERI OFF;
--SET HEAD OFF;
SET LINESIZE 600;
SET FEEDBACK OFF;
SET COLSEP "|";
SET TAB OFF;
SET TRIMSPOOL ON;
COLUMN NUM_SECUINFO   FORMAT 99999999
COLUMN NOM_ARCHIVO    FORMAT A250;
COLUMN NUM_CLIENTES   FORMAT 9999999999;
COLUMN TOT_FACTURAS   FORMAT 999999999999999;
COLUMN TOT_CUOTAS     FORMAT 999999999999999;
COLUMN TOT_SALDOANT   FORMAT 999999999999999;
COLUMN TOT_PAGAR      FORMAT 999999999999999;

SELECT NUM_SECUINFO , 
       NOM_ARCHIVO , 
       NUM_CLIENTES , 
       TOT_SALDOANT,  
       TOT_CUOTAS,
       TOT_FACTURAS,
       TOT_PAGAR
FROM   FAD_CTLIMPRES 
WHERE  NUM_SECUINFO = &1;
QUIT;