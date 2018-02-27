CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
OBJS = mybasic.o
LIB = libmybasic.so

all: ${LIB}

mybasic.o: mybasic.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c

${LIB}: ${OBJS}
	@mkdir -p ${LIBDIR}
	${CC} -fPIC -shared $^ -o ${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -rf *.o ${LIBDIR}/${LIB}
