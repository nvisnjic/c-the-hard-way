#Basic makefile

CFLAGS=-Wall -g

all: ex19

ex19: object.o

clean:
	rm -f ex19 object.o

test:
	./testscript 			 # run BASH test script
	./expecting_a_walk 20	 # run expect script 1 - walk test
	./expecting_to_kill 30 1 # run expect script 2 - hunt test
