# Programa : DeleteTaTarificadas.sh
# Author   : PGG
# Date     : 30/08/2007
# Remarks  : Elimina los Registros de la tabla TA_TARIFICADASx
# =============================================================================

echo "Entrando a DeleteTaTarificadas.sh"

export WORKDIR=$HOME/facturacion/sql/ciclo/Borra_Detalle
echo $ORACLE_HOME

PATH=$PATH:.

STAT_INI=1
STAT_FAIL=2
STAT_OK=3

SQLPLUS="sqlplus -s"
#USERID=reports/reports
USERID=/
SQL=${XPF_SQL}
SQL_INSPECT_TRAZA=inspect_traza
CICLFACT=${1:?Cod_CiclFact}
COD_PROCESO_PREV=3000
COD_PROCESO=5300
RM="rm "

# PGG SOPORTE 66364 26-06-2008 --> Desde Aqui 

DIGITO=$2



if [ "$DIGITO" = "" ]
then
        echo 'Revisando Digito por parametro. Digito vacio'
        exit
fi

if [ $DIGITO -le -1 ]
then
  echo 'Revisando Digito por parametro. Digito Fuera de Rango (0-9) --> ' ${DIGITO}
  exit
fi

if [ $DIGITO -ge 10 ]
then
  echo 'Revisando Digito por parametro. Digito Fuera de Rango (0-9) --> ' ${DIGITO}
	exit
fi


FILE_LOG="DeleteTaTarificadas_"${CICLFACT}"_"${DIGITO}".log" 	

echo "\n --> INICIO DEL BORRADO DE LLAMADAS <--\n" >> $FILE_LOG


COD_PROCESO=$(expr $COD_PROCESO + $DIGITO)

# PGG SOPORTE 66364 26-06-2008 --> Hasta Aqui 


OBSERVACION="Proceso de borrado de llamadas en ejecucion"



szQUERY_1="Inserta_registro_"${DIGITO}".sql"	
szQUERY_2="Update_registro_"${DIGITO}".sql"




echo "Revisando estado en tabla de trazas de facturacion ... \n" >> $FILE_LOG
status="$(${SQLPLUS} ${USERID} @${SQL}/${SQL_INSPECT_TRAZA} ${CICLFACT} ${COD_PROCESO_PREV})"
[ "${status}" = "" ] &&
{
  status=0
}
[ ${status} -ne ${STAT_OK} ] &&
{
   echo "\nLa tabla de trazas indica que el proceso precedente [${COD_PROCESO_PREV}]  no termino correctamente o no existe." >> $FILE_LOG
   echo "\nEsta ejecucion se cancela. " >> $FILE_LOG
   
   exit
}


status="$(${SQLPLUS} ${USERID} @${SQL}/${SQL_INSPECT_TRAZA} ${CICLFACT} ${COD_PROCESO})"
[ "${status}" = "" ] &&
{
       	echo "No existe registro en la tabla FA_TRAZAPROC. Se insertara registro correspondiente al proceso "${COD_PROCESO}"\n" >> $FILE_LOG
       	
       	Inserta_FA_TRAZAPROC="INSERT INTO FA_TRAZAPROC (COD_CICLFACT, COD_PROCESO, COD_ESTAPROC, FEC_INICIO, GLS_PROCESO) VALUES ("
				valores_FA_TRAZAPROC="${CICLFACT}, ${COD_PROCESO}, ${STAT_INI}, SYSDATE, '${OBSERVACION}');"
		    
		    echo "${Inserta_FA_TRAZAPROC}${valores_FA_TRAZAPROC}\ncommit;\nexit;" >> $szQUERY_1
							
				${SQLPLUS} ${USERID} @${szQUERY_1}
				
				echo "\nREGISTRO INSERTADO en FA_TRAZAPROC... \n" >> $FILE_LOG
				       
        status=0
}

echo "exit" >> $szQUERY_1

[ ${status} -eq ${STAT_INI} ] &&
{   
   	echo "\nLa tabla de trazas indica que existe otro proceso de Eliminacion de llamadas en curso. " >> $FILE_LOG
   	echo "\nEsta ejecucion se cancela. " >> $FILE_LOG
		
		${RM} ${szQUERY_1}
		
   	exit
}

[ ${status} -eq ${STAT_OK} ] &&
{   
   	echo "\nLa tabla de trazas indica que este proceso ya fue ejecutado para el ciclo y digito indicado. " >> $FILE_LOG
   	echo "\nEsta ejecucion se cancela. " >> $FILE_LOG
   	
   	${RM} ${szQUERY_1}
		
   	exit
}


sqlplus -s / @$WORKDIR/val_ciclo.sql $1 > /dev/null

if [ `wc -l $WORKDIR/val_ciclo.dat | awk '{print $1}'` = 1 ]
then

        codCiclo=`cat $WORKDIR/val_ciclo.dat|awk '{print $1}'`

## -------------------> Aqui cuenta e informa cuantos registros se eliminaran de la tabla TA_TARIFICADASx
        
        file_name_CuentaTA="erase_TADet_"$1"_"$2".dat"
        
        
        sqlplus -s / @$WORKDIR/cuenta_TADet.sql $1 $2 $codCiclo >> $file_name_CuentaTA
        
        cuentaTA=`cat $file_name_CuentaTA|awk '{print $1}'`
				
				echo "-----------------------------------------------------------------------\n" >> $FILE_LOG
				echo "Registros a Eliminar de la tabla TA_TARIFICADAS"${DIGITO}": " $cuentaTA >> $FILE_LOG
				

## --> Hasta aqui

				
        if [ `wc -l $file_name_CuentaTA | awk '{print $1}'` = 1 ]
        then
        			${RM} ${file_name_CuentaTA}
        			
        			file_name_TA="erase_TADet_"$1"_"$2".dat"
        			
			  			sqlplus -s / @$WORKDIR/erase_TADet.sql $1 $2 $codCiclo >> $file_name_TA

							cuentaBorrados=`cat $file_name_TA|awk '{print $1}'`
														
							echo "Registros Borrados de la tabla TA_TARIFICADAS"${DIGITO}": "$cuentaBorrados >> $FILE_LOG
			  			
			  			${RM} ${file_name_TA}
			  			
				else
							echo "\n[ERROR] No existe Tabla de detalle TAS"
							
							OBSERVACION="Borrado de llamadas Finalizado Con Error"
							
							Update_Error_FA_TRAZAPROC="UPDATE FA_TRAZAPROC SET COD_ESTAPROC = ${STAT_FAIL}, FEC_TERMINO = SYSDATE, GLS_PROCESO = '${OBSERVACION}' where cod_ciclfact= ${CICLFACT} and cod_proceso = ${COD_PROCESO};"				
							echo "${Update_Error_FA_TRAZAPROC}\ncommit;\nexit;" >> $szQUERY_2							
							${SQLPLUS} ${USERID} @${szQUERY_2}
							
							echo "Registro actualizado en trazas de facturacion con indicador de estado en Error ...\n" >> $FILE_LOG
							
							${RM} ${szQUERY_1}
							${RM} ${szQUERY_2}
							
							exit
							
				fi

				if [ $DIGITO -eq 1 ]
				then
						## -------------------> Aqui cuenta e informa cuantos registros se eliminaran de la tabla PF_TARIFICADAS
		        
						file_name_cuentaPF="cuenta_PFDet_"$1"_"$2".dat"
		        
		        sqlplus -s / @$WORKDIR/cuenta_PFDet.sql $1 $2 $codCiclo >> $file_name_cuentaPF
		        
		        cuentaPF=`cat $file_name_cuentaPF|awk '{print $1}'`
						
						echo "\n-----------------------------------------------------------------------\n" >> $FILE_LOG
						echo "Registros a Eliminar de la tabla PF_TARIFICADAS: " $cuentaPF >> $FILE_LOG
						
						## --> Hasta aqui
		
						
		        if [ `wc -l $file_name_cuentaPF | awk '{print $1}'` = 1 ]
		        then
		        			${RM} ${file_name_cuentaPF}
		        			file_name_PF="erase_PFDet_"$1"_"$2".dat"
		        			
					  			sqlplus -s / @$WORKDIR/erase_PFDet.sql $1 $2 $codCiclo >> $file_name_PF
		
									cuentaBorradosPF=`cat $file_name_PF|awk '{print $1}'`
																
									echo "Registros Borrados de la tabla PF_TARIFICADAS: "$cuentaBorradosPF >> $FILE_LOG
					  			
					  			${RM} ${file_name_PF}
					  			
					  			
						else
									echo "\n[ERROR] No existe Tabla de detalle PF"
									
									OBSERVACION="Borrado de llamadas Finalizado Con Error"
									
									Update_Error_FA_TRAZAPROC="UPDATE FA_TRAZAPROC SET COD_ESTAPROC = ${STAT_FAIL}, FEC_TERMINO = SYSDATE, GLS_PROCESO = '${OBSERVACION}' where cod_ciclfact= ${CICLFACT} and cod_proceso = ${COD_PROCESO};"				
									echo "${Update_Error_FA_TRAZAPROC}\ncommit;\nexit;" >> $szQUERY_2							
									${SQLPLUS} ${USERID} @${szQUERY_2}
									
									echo "Registro actualizado en trazas de facturacion con indicador de estado en Error ...\n" >> $FILE_LOG
									
									${RM} ${szQUERY_1}
									${RM} ${szQUERY_2}
									
									exit
									
						fi
			fi 
				
else
    	echo "\n[ERROR] El ciclo ingresado no es valido, verifique por favor..." >> $FILE_LOG
    	
    	OBSERVACION="Borrado de llamadas Finalizado Con Error"
    	
			Update_Error_FA_TRAZAPROC="UPDATE FA_TRAZAPROC SET COD_ESTAPROC = ${STAT_FAIL}, FEC_TERMINO = SYSDATE, GLS_PROCESO = '${OBSERVACION}' where cod_ciclfact= ${CICLFACT} and cod_proceso = ${COD_PROCESO};"				
			echo "${Update_Error_FA_TRAZAPROC}\ncommit;\nexit;" >> $szQUERY_2							
			${SQLPLUS} ${USERID} @${szQUERY_2}
			
			echo "Registro actualizado en trazas de facturacion con indicador de estado en Error ...\n" >> $FILE_LOG
			
			${RM} ${szQUERY_1}
			${RM} ${szQUERY_2}
			
			exit
    	
fi


OBSERVACION="Proceso de borrado de llamadas Finalizado OK"
Update_OK_FA_TRAZAPROC="UPDATE FA_TRAZAPROC SET COD_ESTAPROC = ${STAT_OK}, NUM_REGISTROS = ${cuentaBorrados}, FEC_TERMINO = SYSDATE, GLS_PROCESO = '${OBSERVACION}' where cod_ciclfact= ${CICLFACT} and cod_proceso = ${COD_PROCESO};"
echo "${Update_OK_FA_TRAZAPROC}\ncommit;\nexit;" >> $szQUERY_2							
${SQLPLUS} ${USERID} @${szQUERY_2}

echo "-----------------------------------------------------------------------\n" >> $FILE_LOG
echo "Registro actualizado en trazas de facturacion con indicador de estado OK ...\n" >> $FILE_LOG
 
echo "\n --> FIN DEL BORRADO DE LLAMADAS <--\n" >> $FILE_LOG

${RM} ${szQUERY_1}
${RM} ${szQUERY_2}
${RM} *.dat

exit
