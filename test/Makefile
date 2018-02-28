CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
BINDIR = ../bin

all: sortdemo

sortdemo.o: sortdemo.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
sortdemo: sortdemo.o
	${CC} $< -L ${LIBDIR} -lmybasic -lmysort -o ${BINDIR}/$@

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
