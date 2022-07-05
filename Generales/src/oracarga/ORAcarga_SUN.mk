include $(ENV_PRECOMP)

PROFUENTES=ORAcarga.pc
FUENTES=ORAcarga.c
OBJETOS=ORAcarga.o
H=$(GE_INC_PATH)/


all: $(OBJETOS)  

ORAcarga.c: $(PC)ORAcarga.pc $(GE_INC_PATH)/ORAcarga.h
	$(PROC) $(PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=65 userid=$(USERPASS) iname=$(PC)ORAcarga.pc oname=$(C)ORAcarga.c

ORAcarga.o: ORAcarga.c $(GE_INC_PATH)/ORAcarga.h 
	$(CC) $(CFLAGS) $(INCLUDE) -c -Ae $(C)ORAcarga.c -o $(GE_LIB_PATH)/ORAcarga.o


clean: 
	-rm $(GE_LIB_PATH)/ORAcarga.o
	-rm $(C)ORAcarga.c

debug:
	cp ./*.pc ./../debug/
	cp ./*.c  ./../debug/


