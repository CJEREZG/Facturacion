include $(ENV_PRECOMP)
INCLUDE=$(I_SYM)$(GE_INC_PATH)/ $(I_SYM)$(ORACLE_HOME)/precomp/public $(I_SYM)$(GE_INC_PATH)

PROFUENTES=FaORA.pc
FUENTES=FaORA.c
OBJETOS=FaORA.o
PROCFLAGS=ireclen=255 oreclen=255 include=$(GE_INC_PATH)/ include=$(GE_INC_PATH)

C=./c/
PC=./pc/

all: FaORA.o

FaORA.c: $(PC)FaORA.pc $(GE_INC_PATH)/deftypes.h $(GE_INC_PATH)/FaORA.h
	$(PROC) $(PROCFLAGS) code=ansi_c iname=$(PC)FaORA.pc oname=$(C)FaORA.c

FaORA.o: FaORA.c
	$(CC) $(CFLAGS) -c $(C)FaORA.c -o $(GE_LIB_PATH)/FaORA.o


clean:
	rm -f $(GE_LIB_PATH)/FaORA.o

