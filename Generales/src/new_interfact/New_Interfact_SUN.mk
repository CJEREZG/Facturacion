include $(ENV_PRECOMP)

AUTO_CONNECT=YES
NLS_LOCAL=YES

all: New_Interfact.o

New_Interfact.o: $(PC)New_Interfact.pc $(GE_INC_PATH)/New_Interfact.h
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) iname=$(PC)New_Interfact.pc oname=$(C)New_Interfact.c
	$(CC) -o $(GE_LIB_PATH)/New_Interfact.o $(CFLAGS) -c $(C)New_Interfact.c
	
clean:
	$(RMF) $(C)New_Interfact.c
	$(RMF) $(GE_LIB_PATH)/New_Interfact.o 

