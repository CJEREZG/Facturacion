include $(FA_ENV_PRECOM)

OBJETOS=compos.o $(FA_LIB_PATH)/PlanVcto.o 
O=$(FA_LIB_PATH)/
H=$(FA_INC_PATH)/


EXE=$(XPF_EXE)/

all: $(OBJETOS) 

compos.c: $(PC)compos.pc $(H)compos.h 
	$(PROC)  $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=20 userid=$(USERPASS) iname=$(PC)compos.pc oname=$(C)compos.c

compos.o: compos.c $(H)compos.h 
	$(CC)  $(CFLAGS) $(FA_INCLUDE) -c $(C)compos.c -o $(O)compos.o

clean: 
	-rm $(O)compos.o $(C)compos.c
