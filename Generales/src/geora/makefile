include $(ENV_PRECOMP)

AUTO_CONNECT=YES
NLS_LOCAL=YES

OBJETOS_EXT=
OBJETOS=$(O)geora.o

all: $(O)geora.o

$(O)geora.o: $(C)geora.c $(H)geora.h
	@echo "Generando geora.o..\n"
	$(CC) $(CFLAGS)  -o $(GE_LIB_PATH)/geora.o -c $(C)geora.c
	@cp $(H)geora.h $(GE_INC_PATH)

$(C)geora.c: $(PC)geora.pc $(H)geora.h
	@echo "Generando geora.c..\n"
	$(PROC) $(PROCFLAGS) userid=$(USERPASS) iname=$(PC)geora.pc oname=$(C)geora.c
clean:
	$(RMF) $(C)geora.c 
	$(RMF) $(O)geora.o
	 
