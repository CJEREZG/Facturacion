include $(ENV_PRECOMP)

AUTO_CONNECT=YES
NLS_LOCAL=YES

all: trazafact.o

trazafact.o: $(PC)trazafact.pc
	$(PROC) $(PROCFLAGS) code=ansi_c userid=$(USERPASS) iname=$(PC)trazafact.pc
	$(MV) $(PC)trazafact.c $(C)
	$(CC) -o $(GE_LIB_PATH)/trazafact.o $(CFLAGS) -c $(C)trazafact.c -o $(GE_LIB_PATH)/trazafact.o
	
	
clean:
	$(RMF) $(C)trazafact.c
	$(RMF) $(GE_LIB_PATH)/trazafact.o 

