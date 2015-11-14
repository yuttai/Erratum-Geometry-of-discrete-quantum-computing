CC= gcc
CPFLAGS= -g -Wall -std=c++11
LDFLAGS= -lcrypto -lstdc++ -pthread

OBJ = async_run.o 
BIN = async_run

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CPFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS) 


async_run.o: async_run.cpp
	$(CC) -c $(CPFLAGS) async_run.cpp

async_run.cpp:

clean:
	rm -rf $(OBJ) $(BIN) *.exe
