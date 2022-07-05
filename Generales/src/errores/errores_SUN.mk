include $(ENV_PRECOMP)

PROFUENTES=errores.pc
OBJETOS=errores.o

all: errores.o

errores.c: $(PC)errores.pc
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) iname=$(PC)errores.pc oname=$(C)errores.c

errores.o: errores.c $(GE_INC_PATH)/errores.h
	$(CC) $(CFLAGS) -c $(C)errores.c -o $(GE_LIB_PATH)/errores.o

clean:
	-rm $(GE_LIB_PATH)/errores.o $(C)errores.c

debug:
	cp ./*.pc ./../debug/
	cp ./*.c  ./../debug/
	cp ./*.o  ./../debug/
	cp ./*.h  ./../debug/
