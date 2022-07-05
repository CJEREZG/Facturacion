include $(FA_ENV_PRECOM)

PROFUENTES=comora.pc
FUENTES=composi.c comora.c 
OBJETOS=composi.o comora.o
O=$(FA_LIB_PATH)/
H=$(FA_INC_PATH)/

EXE=$(XPF_EXE)/

all: $(OBJETOS) 

composi.o: $(C)composi.c $(H)composi.h $(H)comora.h
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)composi.c -o $(O)composi.o

comora.c: $(PC)comora.pc $(H)comora.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)comora.pc oname=$(C)comora.c

comora.o: comora.c $(H)comora.h
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)comora.c -o $(O)comora.o

clean:
	-rm $(O)composi.o
	-rm $(O)comora.o
	-rm $(C)comora.c

debug:
	-cp -R ./ ./../debug/
