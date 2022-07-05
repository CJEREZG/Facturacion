whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

--BM NO VA PORQUE SE HACE EL VACIADO DESDE LA TEMPORALA A LA TABLA
--drop table FA_HISTCONC_&&1;
 
--BM este paso no aplica ya que se hace select insert masivo en el script Graba_Det_Doctos_Ciclicos.sql 
--rename FA_HISTCONC_&&1._AUX to FA_HISTCONC_&&1;


drop table FA_HISTCONC_&&1._AUX;
 
drop table vm_fa_histdocu;

drop table vm_fa_histconc_dnotac;

drop table vm_fa_ajusteconc; 

drop table VM_FA_HISTDOCU_PRE_CICLO;

TRUNCATE TABLE SISCEL.FA_CAMBIA_LLAVE_TO;

UPDATE FA_CICLOS_PROCESADOS_TO
SET ESTADO='OK'
WHERE COD_CICLFACT=&&1;

COMMIT;

--DECLARE 
--Tecnologia 		Varchar2(10);
--Tabla_Ren_A             Varchar2(30);
--Tabla_Dest_b            Varchar2(30);
--
--   BEGIN  
--   	SELECT DISTINCT 'EXISTE' 
--   	INTO Tecnologia
--   	FROM all_tables WHERE table_name='FA_HISTECNO_TH_&&1';  
--   EXCEPTION 
--   	WHEN OTHERS THEN
--   		Tecnologia:='NO EXISTE';
--   
--   IF Tecnologia='EXISTE' THEN
--   	Tabla_Ren_A:='FA_HISTECNO_TH_&&1._AUX';
--   	Tabla_Dest_b:='FA_HISTECNO_TH_&&1';
--   
--   	--BM se solicito cambiar instrucción por procedimiento, rename FA_HISTECNO_TH_&&1._AUX to FA_HISTECNO_TH_&&1;
--	FA_REASIG_COD_CONCEPT_FACT_PG.FA_RENAME_TABLE_PR(Tabla_Ren_A, Tabla_Dest_b);
--   END IF;
--   
--   END;	 
/

exit 0; 
 