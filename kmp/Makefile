CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
OBJS = kmp.o \
	   kmpoptimized.o
LIB = libmykmp.so

all: ${LIB}

kmp.o: kmp.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
kmpoptimized.o: kmpoptimized.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c

${LIB}: ${OBJS}
	@mkdir -p ${LIBDIR}
	${CC} -fPIC -shared $^ -L ${LIBDIR} -lmybasic -o ${PWD}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
