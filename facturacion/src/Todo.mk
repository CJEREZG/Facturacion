PROGS = checktraza abofact BalanceInicial CargaBalance cierrefact CritAsigDesp CritAsigMens FaSched ForCob ImpresionScl infctlfactur infctlpreciclo LibroVenta LibroVentaAux loadtarif New_FactOnline New_FolAuto New_FolBatch New_FolOnlConsig New_FolOnline New_Impdetalle New_ImpDetLlam New_ImpDetLlamTol New_ImpreOnline New_Impresion New_LibroVenta New_PHistorico New_QueueAdmin New_VisOnline pasohist prefac procCuotas recargos SolicNCBaja

all:
	@for i in $(PROGS); \
	  do  \
		echo; \
		echo; \
		echo Compilando $$i;\
		echo; \
		cd $$i;\
		make all; \
		make install; \
		cd ..;\
	done; 

clean:
	@for i in $(PROGS); \
	  do  \
		echo; \
		echo; \
		echo Borrando $$i;\
		echo; \
		cd $$i;\
		make clean; \
		cd ..;\
	done; 

install:
	@for i in $(PROGS); \
	  do  \
		echo; \
		echo; \
		echo Instalando $$i;\
		echo; \
		cd $$i;\
		make -f $$i.mk install; \
		cd ..;\
	done; 

#carrier 