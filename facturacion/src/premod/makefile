include $(FA_ENV_PRECOM)

PROFUENTES=preabo.pc preser.pc pretar.pc precuo.pc presac.pc precob.pc preext.pc prenot.pc 
FUENTES=preabo.c preser.c pretar.c precuo.c presac.c precob.c prenot.c preext.c 
OBJETOS=preabo.o preser.o pretar.o precuo.o presac.o precob.o prenot.o preext.o

all: $(OBJETOS) install
pretar.c: $(PC)pretar.pc $(H)pretar.h 
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)pretar.pc oname=$(C)pretar.c

pretar.o: pretar.c $(H)pretar.h 
	$(CC) $(CFLAGS) -c $(C)pretar.c -o $(O)pretar.o

presac.c: $(PC)presac.pc $(H)presac.h 
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)presac.pc oname=$(C)presac.c

presac.o: presac.c  $(H)presac.h
	$(CC) $(CFLAGS) -c $(C)presac.c -o $(O)presac.o

preser.c: $(PC)preser.pc $(H)preser.h 
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)preser.pc oname=$(C)preser.c 

preser.o: preser.c  $(H)preser.h
	$(CC) $(CFLAGS) -c $(C)preser.c -o $(O)preser.o

preabo.c: $(PC)preabo.pc $(H)preabo.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)preabo.pc oname=$(C)preabo.c

preabo.o: preabo.c $(H)preabo.h
	$(CC) $(CFLAGS) -c $(C)preabo.c -o $(O)preabo.o

precuo.c: $(PC)precuo.pc $(H)precuo.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)precuo.pc oname=$(C)precuo.c

precuo.o: precuo.c $(H)precuo.h
	$(CC) $(CFLAGS) -c $(C)precuo.c -o $(O)precuo.o

preext.c: $(PC)preext.pc $(H)preext.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)preext.pc oname=$(C)preext.c

preext.o: preext.c $(H)preext.h
	$(CC) $(CFLAGS) -c $(C)preext.c -o $(O)preext.o

precob.c: $(PC)precob.pc $(H)precob.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)precob.pc oname=$(C)precob.c

precob.o: precob.c 
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)precob.c -o $(O)precob.o

prenot.c: $(PC)prenot.pc $(H)prenot.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)prenot.pc oname=$(C)prenot.c

prenot.o: prenot.c 
	$(CC) $(CFLAGS) -c $(C)prenot.c -o $(O)prenot.o

install:
	-cp $(O)pretar.o $(FA_LIB_PATH)/pretar.o
	-cp $(O)presac.o $(FA_LIB_PATH)/presac.o
	-cp $(O)preser.o $(FA_LIB_PATH)/preser.o
	-cp $(O)precob.o $(FA_LIB_PATH)/precob.o
	-cp $(O)preabo.o $(FA_LIB_PATH)/preabo.o
	-cp $(O)precuo.o $(FA_LIB_PATH)/precuo.o
	-cp $(O)prenot.o $(FA_LIB_PATH)/prenot.o
	-cp $(O)preext.o $(FA_LIB_PATH)/preext.o
	-cp $(H)presac.h $(FA_INC_PATH)/presac.h
	-cp $(H)pretar.h $(FA_INC_PATH)/pretar.h
	-cp $(H)preser.h $(FA_INC_PATH)/preser.h
	-cp $(H)precob.h $(FA_INC_PATH)/precob.h
	-cp $(H)preabo.h $(FA_INC_PATH)/preabo.h
	-cp $(H)precuo.h $(FA_INC_PATH)/precuo.h
	-cp $(H)preext.h $(FA_INC_PATH)/preext.h
	-cp $(H)prenot.h $(FA_INC_PATH)/prenot.h

clean:
	-rm $(O)pretar.o $(C)pretar.c
	-rm $(O)presac.o $(C)presac.c
	-rm $(O)preser.o $(C)preser.c
	-rm $(O)preabo.o $(C)preabo.c
	-rm $(O)precob.o $(C)precob.c
	-rm $(O)precuo.o $(C)precuo.c
	-rm $(O)preext.o $(C)preext.c
	-rm $(O)prenot.o $(C)prenot.c

debug:
	cp *.pc  $(DEBUG)
	cp *.c   $(DEBUG)
	cp *.h   $(DEBUG)
	cp *.o   $(DEBUG)
