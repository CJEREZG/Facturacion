NOMBRE=genco

include $(ENV_PRECOMP)

RMF=rm -f
CPF=cp -f
CCc=cc -c

C=./c/
PC=./pc/

INCLUDE=$(I_SYM)$(ORACLE_HOME)/precomp/public $(I_SYM)$(GE_INC_PATH)/ $(I_SYM)$(GE_INC_PATH)
PROCINCLUDE=include=$(GE_INC_PATH)/ include=$(GE_INC_PATH)
OBJ_EXTERNOS=$(GE_LIB_PATH)/geora.o

all: $(NOMBRE).o 

$(NOMBRE).o: $(C)$(NOMBRE).c
	$(CCc) -o $(GE_LIB_PATH)/$(NOMBRE).o $(CFLAGS) $(OBJ_EXTERNOS) -c $(C)$(NOMBRE).c

$(C)$(NOMBRE).c: $(PC)$(NOMBRE).pc
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) $(PROCINCLUDE) iname=$(PC)$(NOMBRE).pc oname=$(C)$(NOMBRE).c
			
clean:
	$(RMF) $(GE_LIB_PATH)/$(NOMBRE).o
	$(RMF) $(C)$(NOMBRE).c
				

