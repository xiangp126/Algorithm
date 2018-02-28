CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
BINDIR = ../bin

all: sortdemo kmpdemo

sortdemo.o: sortdemo.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
sortdemo: sortdemo.o
	@mkdir -p ${BINDIR}
	${CC} $< -L ${LIBDIR} -lmybasic -lmysort -o ${BINDIR}/$@

kmpdemo.o: kmpdemo.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
kmpdemo: kmpdemo.o
	@mkdir -p ${BINDIR}
	${CC} $< -L ${LIBDIR} -lmybasic -lmykmp -o ${BINDIR}/$@

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
