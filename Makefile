CC = g++

CFLAGS  = -O3
CFLAGS += -Wall -Wextra -Werror -pendantic
CFLAGS += -std=c11

LIBS = -lpthread

all:
	$(CC) simpledb.cpp -o simpledb $(LIBS)

clean:
	rm simpledb
