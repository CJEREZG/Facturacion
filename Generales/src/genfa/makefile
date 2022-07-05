include $(ENV_PRECOMP)

OBJETOS=GenFA.o 

all: $(OBJETOS) install

GenFA.c: $(PC)GenFA.pc $(H)StFactur.h $(H)GenFA.h 
	$(PROC)  $(PROCFLAGS) code=ansi_c userid=$(USERPASS) iname=$(PC)GenFA.pc oname=$(C)GenFA.c

GenFA.o: GenFA.c $(H)StFactur.h $(H)GenFA.h 
	$(CC)  $(CFLAGS) -c $(C)GenFA.c -o $(O)GenFA.o

install: 
	-cp $(O)GenFA.o    $(GE_LIB_PATH)
	-cp $(H)GenFA.h    $(GE_INC_PATH)
	-cp $(H)StFactur.h $(GE_INC_PATH)
	-cp $(H)predefs.h  $(GE_INC_PATH)

clean: 
	-rm $(O)GenFA.o $(C)GenFA.c


