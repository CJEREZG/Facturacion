whenever sqlerror exit sql.sqlcode
whenever oserror  exit oscode

alter session set db_file_multiblock_read_count=1024
/

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 19010102, null, sysdate, sqlcode, 'PROCESAMIENTO DE SISCEL.FA_HISTCONC_19010102  TRUNCATE'); 

create index AK_FHCON_190101_TMP_IND
 on ops$xpfactur.fa_histconc_19010102_tmp (IND_ORDENTOTAL)
TABLESPACE install_Index
PCTFREE    5
INITRANS   32
MAXTRANS   255
STORAGE    (
            INITIAL          16M
            NEXT             16M
            MINEXTENTS       1
            MAXEXTENTS       2147483645
            PCTINCREASE      0
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;

create index AK_FHCON_190101_DIFF_IND
 on ops$xpfactur.fa_histconc_19010102_diff (IND_ORDENTOTAL)
TABLESPACE install_Index
PCTFREE    5
INITRANS   32
MAXTRANS   255
STORAGE    (
            INITIAL          16M
            NEXT             16M
            MINEXTENTS       1
            MAXEXTENTS       2147483645
            PCTINCREASE      0
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;

alter table SISCEL.FA_HISTECNO_TH_19010102
DROP constraint FA_HISTCONC_HTNC_FK_19010102
/

alter table SISCEL.FA_HISTCONC_19010102 
modify constraint 
FK_FAHCONC_19010102_FAHDOCU   
disable
/

ALTER TABLE SISCEL.FA_HISTCONC_19010102 DROP
CONSTRAINT PK_FA_HISTCONC_19010102 
/

DROP INDEX SISCEL.AK_FA_HCONC_19010102_PRODUCTO 	
/

truncate table SISCEL.fa_histconc_19010102
/

DECLARE
   v_nMin   NUMBER;
   v_nMax   NUMBER;
   v_nDelta NUMBER; 
BEGIN
   SELECT MIN( IND_ORDENTOTAL ) , MAX( IND_ORDENTOTAL )
   INTO   v_nMin , v_nMax 
   FROM   ops$xpfactur.fa_histconc_19010102_tmp ;
   v_nDelta := TRUNC( ( v_nMax - v_nMin ) / 100 );
	   LOOP
      EXIT WHEN v_nMin > v_nMax ;
      INSERT INTO fa_histconc_19010102
      SELECT * 
      FROM   ops$xpfactur.fa_histconc_19010102_tmp
      WHERE  ind_ordentotal BETWEEN v_nMin AND v_nMin + v_nDelta ;
      COMMIT;
      v_nMin := v_nMin + v_nDelta + 1 ;
   END LOOP;
   COMMIT;
END;
/

DECLARE
   v_nMin   NUMBER;
   v_nMax   NUMBER;
   v_nDelta NUMBER; 
BEGIN
   SELECT MIN( IND_ORDENTOTAL ) , MAX( IND_ORDENTOTAL )
   INTO   v_nMin , v_nMax 
   FROM   ops$xpfactur.fa_histconc_19010102_diff ;
   v_nDelta := TRUNC( ( v_nMax - v_nMin ) / 100 );
	   LOOP
      EXIT WHEN v_nMin > v_nMax ;
      INSERT INTO fa_histconc_19010102
      SELECT * 
      FROM   ops$xpfactur.fa_histconc_19010102_diff
      WHERE  ind_ordentotal BETWEEN v_nMin AND v_nMin + v_nDelta ;
      COMMIT;
      v_nMin := v_nMin + v_nDelta + 1 ;
   END LOOP;
   COMMIT;
END;
/

CREATE INDEX AK_FA_HCONC_19010102_PRODUCTO ON SISCEL.FA_HISTCONC_19010102
(COD_PRODUCTO)
LOGGING
TABLESPACE TIL_NO_SCL002
PCTFREE    5
INITRANS   32
MAXTRANS   255
STORAGE    (
            INITIAL          16M
            NEXT             16M
            MINEXTENTS       1
            MAXEXTENTS       2147483645
            PCTINCREASE      0
            BUFFER_POOL      DEFAULT
           )
NOPARALLEL;

ALTER TABLE SISCEL.FA_HISTCONC_19010102 ADD (
  CONSTRAINT PK_FA_HISTCONC_19010102 PRIMARY KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA)
    USING INDEX 
    TABLESPACE TIL_LA_SCL001
    PCTFREE    0
    INITRANS   32
    MAXTRANS   255
    STORAGE    (
                INITIAL          128M
                NEXT             128M
                MINEXTENTS       1
                MAXEXTENTS       2147483645
                PCTINCREASE      0
               ));


alter table SISCEL.FA_HISTCONC_19010102 
modify constraint 
FK_FAHCONC_19010102_FAHDOCU  
enable
/

ALTER TABLE SISCEL.FA_HISTECNO_TH_19010102 ADD (
CONSTRAINT FA_HISTCONC_HTNC_FK_19010102 
FOREIGN KEY (IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA) 
REFERENCES FA_HISTCONC_19010102 (IND_ORDENTOTAL,COD_CONCEPTO,COLUMNA) );

EXECUTE FA_REASIG_COD_CONCEPT_FACT_PG.FA_PROC_GRAB_LOG(null, 19010102, null, sysdate, sqlcode, 'PROCESAMIENTO DE SISCEL.FA_HISTCONC_19010102  TRUNCATE'); 

EXIT;
