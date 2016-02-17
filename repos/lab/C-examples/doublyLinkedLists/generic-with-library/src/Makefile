
INSTALL=..
INCLUDE=$(INSTALL)/include
LIBS=$(INSTALL)/lib
LFLAGS=-L$(LIBS) -lmylib
CC=gcc
#CFLAGS=-Wall -g  -static  -I$(INCLUDE)
CFLAGS=-Wall -g  -I$(INCLUDE)

all: RandomTestList SimpleTestList


RandomTestList: RandomTestList.o Object.o
	$(CC) $(CFLAGS) -o $@ RandomTestList.o Object.o  $(LFLAGS)

SimpleTestList: SimpleTestList.o 
	$(CC) $(CFLAGS) -o $@ SimpleTestList.o   $(LFLAGS)

clean:
	rm --force list *.o RandomTestList SimpleTestList
