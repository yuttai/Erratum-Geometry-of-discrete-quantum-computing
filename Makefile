CC= gcc
CPFLAGS= -g -Wall -std=c++11
LDFLAGS= -lstdc++

all: default

default: async_run tensorQ

tensorQ: tensorQ.o
	$(CC) $(CPFLAGS) -o tensorQ tensorQ.o $(LDFLAGS) 

tensorQ.o: tensorQ.cpp
	$(CC) -c $(CPFLAGS) tensorQ.cpp

tensorQ.cpp:

async_run: async_run.o
	$(CC) $(CPFLAGS) -o async_run async_run.o $(LDFLAGS) 

async_run.o: async_run.cpp
	$(CC) -c $(CPFLAGS) async_run.cpp

async_run.cpp:

clean:
	rm -rf async_run tensorQ *.o *.exe
