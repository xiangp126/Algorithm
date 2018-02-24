CC = g++
CFLAGXX = -Wall -std=c++11
LIBDIR = lib
INCDIR = ../inc
LIB = libmysort.so

all: ${LIB}

${LIB}: mysort.cpp mybasic.cpp
	@mkdir -p ${LIBDIR}
	${CC} ${CFLAGXX} $^ -I ${INCDIR} -fPIC -shared -o ${PWD}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -rf *.o ${LIBDIR}/*
