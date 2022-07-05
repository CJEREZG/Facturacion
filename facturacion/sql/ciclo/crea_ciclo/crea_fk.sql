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
--** Información de Versionado *************************************************************
--******************************************************************************************
--** Pieza                                               : 
--**  %ARCHIVE%
--** Identificador en PVCS                               : 
--**  %PID%
--** Producto                                            : 
--**  %PP%
--** Revisión                                            : 
--**  %PR%
--** Autor de la Revisión                                :          
--**  %AUTHOR%
--** Estado de la Revisión ($TO_BE_DEFINED es Check-Out) : 
--**  %PS%
--** Fecha de Creación de la Revisión                    : 
--**  %DATE% 
--** Worksets ******************************************************************************
--** %PIRW%
--** Historia ******************************************************************************
--** %PL%
--******************************************************************************************

