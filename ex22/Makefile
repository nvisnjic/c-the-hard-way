#Basic makefile

CFLAGS=-Wall -g

all: ex22_main

ex22_main: ex22.o

clean:
	rm -f ex22_main ex22.o

.PHONY: nodebug
nodebug: ex22.o
	$(CC) $(CFLAGS) -DNDEBUG ex22_main.c ex22.o -o ex22_main
