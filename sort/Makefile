CC = g++
CFLAGXX = -Wall -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
OBJS = bubblesort.o \
	   insertsort.o \
	   shellsort.o \
	   quicksort.o \
	   quicksortoptimized.o \
	   heapsort.o \
	   bucketsort.o \
	   radixsort.o \
	   mergesort.o
LIB = libmysort.so

all: ${LIB}

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
bucketsort.o: bucketsort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
radixsort.o: radixsort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c
mergesort.o: mergesort.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} $< -c

${LIB}: ${OBJS}
	@mkdir -p ${LIBDIR}
	${CC} -fPIC -shared $^ -L ${LIBDIR} -lmybasic -o ${PWD}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
	# -rm -rf *.o ${LIBDIR}/${LIB}
