include $(ENV_PRECOMP)

CC = cc
RMF= rm -f 

all: utils.o

utils.o: $(C)utils.c 
	$(CC) -o $(GE_LIB_PATH)/utils.o $(CFLAGS) -c $(C)utils.c

clean:
	$(RMF) $(GE_LIB_PATH)/utils.o

