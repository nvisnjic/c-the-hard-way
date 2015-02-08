#Basic makefile

CFLAGS=-Wall -g 


all: ex20 ex20nodbg 


ex20 ex20nodbg: dbg.h

clean:
	rm -f ex20 ex20nodbg

nodebug: 
	$(CC) $(CFLAGS)-DNDEBUG ex20.c -o ex20

