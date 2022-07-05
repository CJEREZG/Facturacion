# Programa : renombra.sh
# Author   : Carlos Rozas A.
# Date     : 23/9/99
# Remarks  : Crea tablas fa_detcelular_<ciclo> a partir de la tabla pf_tarificadas.
# =================================================================================

TEMP=`cat /dbt1/tools/bin/.archivo.dat`

WORKDIR=/usr/users/explota/bin/crea_fadet;export WORKDIR
. ~tools/oracle817
ORACLE_SID=scel;export ORACLE_SID;
PATH=$PATH:.
export PATH=.:$ORACLE_HOME/bin:$PATH

  sqlplus -s siscel/$TEMP @$WORKDIR/ciclo.sql $1 > /dev/null
  if [ `wc -l $WORKDIR/ciclo.dat | awk '{print $1}'` = 1 ] 
  then
    sqlplus -s siscel/$TEMP @$WORKDIR/cuentao.sql  > /dev/null
    cuentaold=`cat $WORKDIR/cuentao.dat|awk '{print $1}'`
    echo "\na pasar $cuentaold registros"
    sqlplus -s siscel/$TEMP @$WORKDIR/copia.sql $1
    sqlplus -s siscel/$TEMP @$WORKDIR/cuentan.sql $1 > /dev/null
    cuentanew=`cat $WORKDIR/cuentan.dat|awk '{print $1}'`
    echo "\n pasados $cuentanew registros"
    if [ $cuentaold = $cuentanew ]
    then
       sqlplus -s siscel/$TEMP @$WORKDIR/trunca.sql
       sqlplus -s siscel/$TEMP @$WORKDIR/permiso.sql $1
       sqlplus -s siscel/$TEMP @$WORKDIR/indice.sql $1
    else  
        echo "\nContactarse con el DBA de Turno... Hay diferencia de Registros Paso de llamadas"
    fi
  else 
    echo "\nEl ciclo ingresado no es valido, verifique por favor..."
  fi
exit
