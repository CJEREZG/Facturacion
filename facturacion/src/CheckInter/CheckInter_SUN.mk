NOMBRE=CheckInter

include $(FA_ENV_PRECOM)

OBJ_EXTERNO=$(GE_LIB_PATH)/errores.o $(GE_LIB_PATH)/FaORA.o $(GE_LIB_PATH)/ORAcarga.o $(GE_LIB_PATH)/GenFA.o $(GE_LIB_PATH)/geora.o $(GE_LIB_PATH)/trazafact.o $(GE_LIB_PATH)/rutinasgen.o 

EXE=$(XPF_EXE)/

APLICACION=$(EXE)$(NOMBRE)
OBJETO_LOCAL=$(O)$(NOMBRE).o
INTERMEDIO_C=$(C)$(NOMBRE).c
FUENTE_PC=$(PC)$(NOMBRE).pc
CABECERA_H=$(H)$(NOMBRE).h

all: $(APLICACION)

$(APLICACION) : $(OBJETO_LOCAL) $(OBJ_EXTERNO)
	$(CC) $(CFLAGS) -o $(APLICACION) $(OBJETO_LOCAL) $(OBJ_EXTERNO) $(PROLDLIBS)

$(OBJETO_LOCAL) : $(INTERMEDIO_C)
	$(CC) -o $(OBJETO_LOCAL) $(CFLAGS) $(INCLUDE) -c $(INTERMEDIO_C)

$(INTERMEDIO_C)	: $(FUENTE_PC)
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) iname=$(FUENTE_PC) oname=$(INTERMEDIO_C)

clean:
	$(RMF) $(INTERMEDIO_C)
	$(RMF) $(OBJETO_LOCAL)

cleanall: clean
	$(RMF) $(APLICACION)
