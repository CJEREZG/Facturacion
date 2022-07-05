# Programa : crea_cic.sh
# Se aplican modificaciones hechas en la operadora CH-200507052957
export DBT_MOUNT0=/ora01
export ORACLE_BASE=$DBT_MOUNT0/oracle01
export ORACLE_HOME=$ORACLE_BASE/product/8.1.7
export LD_LIBRARY_PATH=$ORACLE_HOME/lib:$LD_LIBRARY_PATH:$PATH
export NLS_LANG=AMERICAN_AMERICA.WE8DEC
export ORA_NLS=$ORACLE_HOME/ocommon/nls/admin/data
export ORA_NLS33=$ORACLE_HOME/ocommon/nls/admin/data
export TNS_ADMIN=$ORACLE_HOME/network/admin
PATH=$PATH:$ORACLE_HOME/bin:


## ---Begin DB Settings---
  export TOOLS_BASE=~tools/app
  . $TOOLS_BASE/oop01env
  export ORACLE_BASE=$DBT_MOUNT0/app/oracle01
  . $OOP_OSS/oracle01817
  TEMP=`cat $OOP_PAR/.archivo.dat`
## ---End DB Settings---
export ORACLE_SID=scel
unset TWO_TASK

export WORKDIR=~explota/bin/crea_ciclo

## ---End DB Settings---
echo "Entrando a crea_cic.sh"
export PATH=.:$ORACLE_HOME/bin:$PATH

echo "Verificando ciclo...."
sqlplus -s siscel/$TEMP @$WORKDIR/ciclo.sql $1 # > /dev/null
  if [ `wc -l $WORKDIR/ciclo.dat | awk '{print $1}'` = 1 ]
  then
        rm -f $WORKDIR/tab_*.lst
        echo "Creando tablas...."
        sqlplus -s siscel/$TEMP @$WORKDIR/fatabcon.sql $1 # > /dev/null
        sqlplus -s siscel/$TEMP @$WORKDIR/fatabcli.sql $1 # > /dev/null
        sqlplus -s siscel/$TEMP @$WORKDIR/fataconc.sql $1 # > /dev/null
        sqlplus -s siscel/$TEMP @$WORKDIR/fatabtecno.sql $1 # > /dev/null
        sqlplus -s siscel/$TEMP @$WORKDIR/fafadocu.sql $1 # > /dev/null
        sqlplus -s siscel/$TEMP @$WORKDIR/crea_fk.sql $1 # > /dev/null
        ksh $WORKDIR/revisa.sh $1
  else
    echo "\nEl ciclo ingresado no es valido, verifique por favor..."
  fi

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

