

include $(FA_ENV_PRECOM)

#include=$(I_SYM)$(FA_INC_PATH) $(I_SYM)$(FA_INC_PATH) $(I_SYM)$(ORACLE_HOME)/precomp/public
#PROCFLAGS=ireclen=255 oreclen=255  SQLCHECK=SEMANTICS USERID=factura/factura include=$(FA_INC_PATH)

#SQLCHECK=SEMANTICS 
PROFUENTES = imptoiva.pc
FUENTES    = imptoiva.c
OBJETO     = imptoiva.o
RCP=@echo rcp -p

#C=./c/
#O=./o/
#H=./h/
#PC=./pc/
#EXE=$(XPF_EXE)/

all: $(OBJETO) install


imptoiva.c: $(PC)imptoiva.pc $(FA_INC_PATH)/imptoiva.h
	$(PROC) $(FA_PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=12 userid=$(USERPASS) iname=$(PC)imptoiva.pc oname=$(C)imptoiva.c

imptoiva.o: imptoiva.c 
	$(CC) $(CFLAGS) $(FA_INCLUDE) -c $(C)imptoiva.c -o $(O)imptoiva.o

install:
	-cp $(O)imptoiva.o $(FA_LIB_PATH)/imptoiva.o

clean:
	-@rm $(O)$(OBJETO) 
	-@rm $(C)$(FUENTES) 

startel1:
	$(RCP) $(PC)imptoiva.pc    factura@startel1:unix/src/impuestos/
