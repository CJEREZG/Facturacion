include $(ENV_PRECOMP)

OBJETOS=GenFA.o
PROCFLAGS=ireclen=255 oreclen=255 include=$(GE_INC_PATH)/ include=$(GE_INC_PATH)

all: $(OBJETOS) 

GenFA.c: $(PC)GenFA.pc $(GE_INC_PATH)/StFactur.h $(GE_INC_PATH)/GenFA.h 
	$(PROC)  $(PROCFLAGS) HOLD_CURSOR=YES RELEASE_CURSOR=NO MAXOPENCURSORS=65 code=ansi_c userid=$(USERPASS) iname=$(PC)GenFA.pc oname=$(C)GenFA.c

GenFA.o: GenFA.c $(GE_INC_PATH)/StFactur.h $(GE_INC_PATH)/GenFA.h 
	$(CC)  $(CFLAGS) $(INCLUDE) -c $(C)GenFA.c -o $(GE_LIB_PATH)/GenFA.o -lm

clean: 
	-rm $(GE_LIB_PATH)/GenFA.o $(C)GenFA.c

