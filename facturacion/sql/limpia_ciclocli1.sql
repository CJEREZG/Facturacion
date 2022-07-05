SET VERI OFF
UPDATE FA_CICLOCLI A
SET A.NUM_PROCESO = -99, A.IND_MASCARA = 0 
WHERE EXISTS (SELECT 1 FROM GA_ABOCEL B
                    WHERE B.FEC_BAJA    < SYSDATE -90
                      AND B.COD_CLIENTE = A.COD_CLIENTE
                      AND B.NUM_ABONADO = A.NUM_ABONADO
                      AND B.COD_CICLO   = A.COD_CICLO)
AND A.COD_CICLO = &1
AND A.COD_PRODUCTO = 1
AND NOT EXISTS (SELECT 1 FROM CO_REG_DEUDACLI DD
                WHERE DD.COD_CLIENTE = A.COD_CLIENTE 
                AND DD.COD_CICLFACT  = &2);
COMMIT;
EXIT;

