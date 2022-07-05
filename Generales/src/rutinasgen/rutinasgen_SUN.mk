include $(ENV_PRECOMP)

AUTO_CONNECT=YES
NLS_LOCAL=YES

all: $(GE_LIB_PATH)/rutinasgen.o

$(GE_LIB_PATH)/rutinasgen.o: $(PC)rutinasgen.pc
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) iname=$(PC)rutinasgen.pc oname=$(C)rutinasgen.c
	$(CC) -o $(GE_LIB_PATH)/rutinasgen.o $(CFLAGS) -c $(C)rutinasgen.c
	
	
clean:
	$(RMF) $(C)rutinasgen.c
	$(RMF) $(GE_LIB_PATH)/rutinasgen.o 

