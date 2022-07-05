alter table FA_FACTABON_&1 add constraint
FK_ABO_&1._FACTDOCU_&1 foreign key
(IND_ORDENTOTAL)
references FA_FACTDOCU_&1 (IND_ORDENTOTAL)
on delete cascade;

alter table FA_FACTCLIE_&1 add constraint
FK_CLI_&1._FACTDOCU_&1 foreign key
(IND_ORDENTOTAL)
references FA_FACTDOCU_&1 (IND_ORDENTOTAL)
on delete cascade;

alter table FA_FACTCONC_&1 add constraint
FK_CON_&1._FACTDOCU_&1 foreign key
(IND_ORDENTOTAL)
references FA_FACTDOCU_&1 (IND_ORDENTOTAL)
on delete cascade;

ALTER TABLE FA_FACTECNO_TO_&1 add constraint 
FA_FACTCONC_TECI_FK_&1 foreign key 
( IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA ) 
references FA_FACTCONC_&1 ( IND_ORDENTOTAL, COD_CONCEPTO, COLUMNA )
on delete cascade;

exit;

--******************************************************************************************
--** Informaci�n de Versionado *************************************************************
--******************************************************************************************
--** Pieza                                               : 
--**  %ARCHIVE%
--** Identificador en PVCS                               : 
--**  %PID%
--** Producto                                            : 
--**  %PP%
--** Revisi�n                                            : 
--**  %PR%
--** Autor de la Revisi�n                                :          
--**  %AUTHOR%
--** Estado de la Revisi�n ($TO_BE_DEFINED es Check-Out) : 
--**  %PS%
--** Fecha de Creaci�n de la Revisi�n                    : 
--**  %DATE% 
--** Worksets ******************************************************************************
--** %PIRW%
--** Historia ******************************************************************************
--** %PL%
--******************************************************************************************

