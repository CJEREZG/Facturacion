include $(FA_ENV_PRECOM)
O=$(FA_LIB_PATH)/
H=$(FA_INC_PATH)/


PROFUENTES=preabo.pc preser.pc pretar.pc precuo.pc presac.pc preext.pc prenot.pc 
FUENTES=preabo.c preser.c pretar.c precuo.c presac.c prenot.c preext.c 
OBJETOS=preabo.o preser.o pretar.o precuo.o presac.o prenot.o preext.o

all: $(OBJETOS) 
pretar.c: $(PC)pretar.pc $(H)pretar.h 
	$(PROC) $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=40 userid=$(USERPASS) iname=$(PC)pretar.pc oname=$(C)pretar.c

pretar.o: pretar.c $(H)pretar.h 
	$(CC) $(CFLAGS) -c $(C)pretar.c -o $(O)pretar.o

presac.c: $(PC)presac.pc $(H)presac.h 
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)presac.pc oname=$(C)presac.c

presac.o: presac.c  $(H)presac.h
	$(CC) $(CFLAGS) -c $(C)presac.c -o $(O)presac.o

preser.c: $(PC)preser.pc $(H)preser.h 
	$(PROC) $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=25 userid=$(USERPASS) iname=$(PC)preser.pc oname=$(C)preser.c 

preser.o: preser.c  $(H)preser.h
	$(CC) $(CFLAGS) -c $(C)preser.c -o $(O)preser.o

preabo.c: $(PC)preabo.pc $(H)preabo.h
	$(PROC) $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=3 userid=$(USERPASS) iname=$(PC)preabo.pc oname=$(C)preabo.c

preabo.o: preabo.c $(H)preabo.h
	$(CC) $(CFLAGS) -c $(C)preabo.c -o $(O)preabo.o

precuo.c: $(PC)precuo.pc $(H)precuo.h
	$(PROC) $(FA_PROCFLAGS) userid=$(USERPASS) iname=$(PC)precuo.pc oname=$(C)precuo.c

precuo.o: precuo.c $(H)precuo.h
	$(CC) $(CFLAGS) -c $(C)precuo.c -o $(O)precuo.o

preext.c: $(PC)preext.pc $(H)preext.h
	$(PROC) $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=3 userid=$(USERPASS) iname=$(PC)preext.pc oname=$(C)preext.c

preext.o: preext.c $(H)preext.h
	$(CC) $(CFLAGS) -c $(C)preext.c -o $(O)preext.o

prenot.c: $(PC)prenot.pc $(H)prenot.h
	$(PROC) $(FA_PROCFLAGS)  HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=7 userid=$(USERPASS) iname=$(PC)prenot.pc oname=$(C)prenot.c

prenot.o: prenot.c 
	$(CC) $(CFLAGS) -c $(C)prenot.c -o $(O)prenot.o

clean:
	-rm $(O)pretar.o $(C)pretar.c
	-rm $(O)presac.o $(C)presac.c
	-rm $(O)preser.o $(C)preser.c
	-rm $(O)preabo.o $(C)preabo.c
	-rm $(O)precuo.o $(C)precuo.c
	-rm $(O)preext.o $(C)preext.c
	-rm $(O)prenot.o $(C)prenot.c

