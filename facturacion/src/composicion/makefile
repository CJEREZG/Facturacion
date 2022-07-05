include $(FA_ENV_PRECOM)

PROFUENTES=comora.pc
FUENTES=composi.c comora.c 
OBJETOS=composi.o comora.o

EXE=$(XPF_EXE)/

all: $(OBJETOS) install

composi.o: $(C)composi.c $(H)composi.h $(H)comora.h
	@cp $(H)composi.h $(FA_INC_PATH)
	@cp $(H)comora.h $(FA_INC_PATH)
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)composi.c -o $(O)composi.o

comora.c: $(PC)comora.pc $(H)comora.h
	@cp $(H)comora.h $(FA_INC_PATH)
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)comora.pc oname=$(C)comora.c

comora.o: comora.c $(H)comora.h
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)comora.c -o $(O)comora.o

install:
	-cp $(H)composi.h  $(FA_INC_PATH)/composi.h
	-cp $(H)comora.h   $(FA_INC_PATH)/comora.h
	-cp $(O)composi.o  $(FA_LIB_PATH)/composi.o
	-cp $(O)comora.o   $(FA_LIB_PATH)/comora.o

clean:
	-rm $(O)composi.o
	-rm $(O)comora.o
	-rm $(C)comora.c

debug:
	-cp -R ./ ./../debug/
