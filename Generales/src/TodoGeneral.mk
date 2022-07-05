PROGS = utils geora GenORA FaORA errores trazafact rutinasgen New_Interfact GenFA ORAcarga
 
all:
	@for i in $(PROGS); \
	  do  \
		echo; \
		echo; \
		echo Compilando $$i;\
		echo; \
		cd $$i;\
		make all -f $${i}_SUN.mk; \
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
		make -f $${i}_SUN.mk clean; \
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
		make install -f $${i}_SUN.mk; \
		cd ..;\
	done; 
