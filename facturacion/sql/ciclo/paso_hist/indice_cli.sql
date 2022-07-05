set ver off
prompt Primary key PK_FA_HISTCLIE_&1

alter table FA_HISTCLIE_&1
add constraint PK_FA_HISTCLIE_&1 PRIMARY KEY
(IND_ORDENTOTAL
)
using index
pctfree     5
initrans    8
maxtrans    255
tablespace   FACTURACION_CICLOS_HIND
storage
(initial    10M   
next        2M   
minextents  1
maxextents  256
pctincrease 0
freelists   8)
/

alter table FA_HISTCLIE_&1 add constraint
FK_HCLI_&1._HISTDOCU_&1 foreign key
(IND_ORDENTOTAL)
references FA_HISTDOCU (IND_ORDENTOTAL)
on delete cascade
/

exit;