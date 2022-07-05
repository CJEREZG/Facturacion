set ver off

prompt Primary key PK_FA_HISTCONC_&1

alter table FA_HISTCONC_&1
add constraint PK_FA_HISTCONC_&1 PRIMARY KEY
(IND_ORDENTOTAL
,COD_CONCEPTO
,COLUMNA
)
using index
pctfree     5
initrans    8
maxtrans    255
tablespace   "QTL_HCONC_C05_scl001"    
storage
(initial    50M    
next        5M       
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/


prompt index AK_FA_HISTCONC_&1._PRODUCTO

create  index AK_FA_HISTCONC_&1._PRODUCTO on FA_HISTCONC_&1
(COD_PRODUCTO
)
pctfree     5
initrans    8
maxtrans    255
tablespace  "QTL_HCONC_C05_scl001"
storage
(initial    20M   
next        3M    
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

prompt index AK_FA_HISTCONC_&1._CONCEREL

create  index AK_FA_HISTCONC_&1._CONCEREL on FA_HISTCONC_&1
(IND_ORDENTOTAL, COD_CONCEREL, COLUMNA_REL) 
pctfree     5
initrans    8
maxtrans    255
tablespace  "QTL_HCONC_C05_scl001"
storage
(initial    20M   
next        3M    
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

alter table FA_HISTCONC_&1 add constraint
FK_HCON_&1._HISTDOCU_&1 foreign key
(IND_ORDENTOTAL)
references FA_HISTDOCU (IND_ORDENTOTAL)
on delete cascade
/
exit;

