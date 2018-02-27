CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = lib
INCDIR = ../inc
LIB = libmysort.so
OBJS = mybasic.o \
	   bubblesort.o \
	   insertsort.o \
	   shellsort.o \
	   quicksort.o \
	   quicksortoptimized.o \
	   heapsort.o

all: ${LIB}

mybasic.o: mybasic.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
bubblesort.o: bubblesort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
insertsort.o: insertsort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
shellsort.o: shellsort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
quicksort.o: quicksort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
quicksortoptimized.o: quicksortoptimized.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
heapsort.o: heapsort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c

${LIB}: ${OBJS}
	@mkdir -p ${LIBDIR}
	${CC} -fPIC -shared $^ -o ${PWD}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -rf *.o ${LIBDIR}/*.so
