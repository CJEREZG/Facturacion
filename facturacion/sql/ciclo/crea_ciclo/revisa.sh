##############################################
# Programa : revisa.sh
##############################################

#Se aplican modificaciones hechas en la operadora CH-200507052957

 export WORKDIR=$HOME/bin/crea_ciclo
export TEMP=`cat $OOP_PAR/.archivo.dat`

grep -l "Table created" $WORKDIR/log/*$1.log > $WORKDIR/salida
export ciclo=`cat $WORKDIR/ciclo.dat`
export cantidad=`cat $WORKDIR/salida|wc -l`

if [ "$cantidad" -eq "5" ]
    then
        glosa="'Creacion de tablas Ciclo Ok'"
	cod_estad=3
else
        glosa="'Creacion de tablas Ciclo con problemas'"
        cod_estad=2
fi

sqlplus -s << EOF
siscel/$TEMP
@$WORKDIR/inserta_traza.sql $cod_estad $glosa $ciclo
exit;
EOF
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

