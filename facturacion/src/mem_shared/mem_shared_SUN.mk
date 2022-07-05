include $(FA_ENV_PRECOM)

THREADS=YES
#USERPASS=OPS\$$XPFACTUR/xpfactur
#USERPASS=factura/factura

SRCPC 		= tablasora.pc
SRCS1 		= tablasora.c
SRCC2 		= shared.c tablas.c mem_shared.c
SRCC4  		= shared.c tablas.c lector.c
INCS  		= $(H)tablas.h $(H)shared.h /usr/include/pthread.h $(H)semap.h
INCX  		= $(GE_INC_PATH)/GenORA.h
#----------------
PROJ1  		= carga_inicial
PROJ3  		= limpiar_shared
PROJ4		= lector

OBJS1 		= carga_inicial.o tablas.o general.o shared.o semap.o tablasora.o $(GE_LIB_PATH)/GenORA.o
OBJS4   	= tablasora.o tablas.o shared.o semap.o general.o lector.o
OBJS3   	= limpiar_shared.o shared.o general.o
OBJETOS_EXT1    =$(O)carga_inicial.o $(O)tablas.o $(O)general.o $(O)shared.o $(O)semap.o $(O)tablasora.o $(GE_LIB_PATH)/GenORA.o $(GE_LIB_PATH)/errores.o $(GE_LIB_PATH)/trazafact.o
OBJETOS_EXT3    =$(O)limpiar_shared.o $(O)general.o $(O)shared.o
OBJETOS_EXT4    =$(O)lector.o $(O)tablas.o $(O)general.o $(O)shared.o $(O)semap.o $(O)tablasora.o $(GE_LIB_PATH)/GenORA.o
#----------------
OBJS2 		= tablasora.o tablas.o shared.o semap.o general.o mem_shared.o
OBJX  		= $(GE_LIB_PATH)/GenORA.o $(FA_HOME)/generales/src/ORAcarga/o/ORAcarga.o /usr/lib/libposix4.so
LIBX  		= -L$(FA_HOME)/lib
OBJETOS_EXT2    = $(O)mem_shared.o $(O)tablas.o $(O)general.o $(O)shared.o $(O)semap.o $(O)tablasora.o $(GE_LIB_PATH)/GenORA.o

all: $(OBJS2) $(PROJ1) $(PROJ3) $(PROJ4) install copia

#----------------
$(PROJ1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(PROJ1) $(OBJETOS_EXT1) $(PROLDLIBS) -lthread
$(PROJ3): $(OBJS3)
	$(CC) $(CFLAGS) -o $(PROJ3) $(OBJETOS_EXT3) $(PROLDLIBS) -lthread
$(PROJ4): $(OBJS4)
	$(CC) $(CFLAGS) -o $(PROJ4) $(OBJETOS_EXT4) $(PROLDLIBS) -lthread
#----------------
semap.o: $(C)semap.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)semap.c -o $(O)semap.o
general.o: $(C)general.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)general.c -o $(O)general.o
tablasora.c: $(PC)tablasora.pc $(INCS) $(INCX)
	@echo $(FA_PROCFLAGS)
	$(PROC) $(FA_PROCFLAGS) threads=yes userid=$(USERPASS) iname=$(PC)tablasora.pc oname=$(C)tablasora.c
tablasora.o: tablasora.c $(INCS) $(INCX) 
	$(CC) $(CFLAGS) -c $(C)tablasora.c -o $(O)tablasora.o 
tablas.o: $(C)tablas.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)tablas.c -o $(O)tablas.o
shared.o: $(C)shared.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)shared.c -o $(O)shared.o
mem_shared.o: $(C)mem_shared.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)mem_shared.c -o $(O)mem_shared.o
carga_inicial.o: $(C)carga_inicial.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)carga_inicial.c -o $(O)carga_inicial.o
limpiar_shared.o: $(C)limpiar_shared.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)limpiar_shared.c -o $(O)limpiar_shared.o
lector.o: $(C)lector.c $(INCS) $(INCX)
	$(CC) $(CFLAGS) -c $(C)lector.c -o $(O)lector.o

clean:
	-rm $(O)mem_shared.o	

install:
	-cp $(O)general.o	$(FA_LIB_PATH)/general.o	
	-cp $(O)semap.o		$(FA_LIB_PATH)/semap.o
	-cp $(O)shared.o	$(FA_LIB_PATH)/shared.o
	-cp $(O)tablas.o	$(FA_LIB_PATH)/tablas.o
	-cp $(O)tablasora.o	$(FA_LIB_PATH)/tablasora.o
	-cp $(O)mem_shared.o	$(FA_LIB_PATH)/mem_shared.o
	
copia:
	@echo -------------------------------------------------------
	@echo            Copiando ejecutable a XPFACTUR
	@echo -------------------------------------------------------
	-mv carga_inicial $(XPF_EXE)
	-mv limpiar_shared $(XPF_EXE)
	-mv lector $(XPF_EXE)
	-cp shell/coordinador_MC $(XPF_EXE)
	-cp shell/datos.txt $(XPF_CFG)
	chmod 775 $(XPF_CFG)/datos.txt
	#-cp $(XPF_EXE)/carga_inicial /usr01/desarrollo_cuzco/xpfactur/facturacion/exe/
	#-cp $(XPF_EXE)/limpiar_shared /usr01/desarrollo_cuzco/xpfactur/facturacion/exe/
	#-cp $(XPF_EXE)/lector /usr01/desarrollo_cuzco/xpfactur/facturacion/exe/
	@echo =======================================================

	
