#Compile for AR.Drone ARM: make ARM=1

ifdef ARM
	#arm-none-linux-gnueabi-gcc
CC      := arm-linux-gnueabi-gcc
TARGET  := threading_arm

else
CC      := gcc
TARGET  := threading
endif
SRCS    := threading.c
OBJS    := ${SRCS:.c=.o} 
DEPS    := ${SRCS:.c=.dep} 
XDEPS   := $(wildcard ${DEPS}) 

LDFLAGS = -lpthread
CCFLAGS = -std=gnu99 -O2 -Wall -Werror 
CCFLAGS+= -ggdb

#mkdir ./src
#cd ./src

.PHONY: all clean distclean 
all:: ${TARGET} 

ifneq (${XDEPS},) 
include ${XDEPS} 
endif 

${TARGET}: ${OBJS} 
	${CC} ${LDFLAGS} -o $@ $^ ${LIBS} 
	#strip $@

${OBJS}: %.o: %.c %.dep 
	${CC} ${CCFLAGS} -o $@ -c $< 

${DEPS}: %.dep: %.c Makefile 
	${CC} ${CCFLAGS} -MM $< > $@ 

clean:: 
	-rm -f *~ *.o ${TARGET} 

distclean:: clean
