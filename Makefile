CC = g++
CFLAGXX = -Wall -std=c++11 -g3
INCDIR = inc
LIBDIR = src/lib
LIB = libmysort.so
OBJS = demo.o
MAKE = make

all: demo

SUBDIR = src
${LIB}:
	@echo "Entering into ${SUBDIR}"
	@cd ${SUBDIR} && ${MAKE}
	@echo "Leaving from ${SUBDIR}"

demo.o: demo.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} -c $<

demo: ${OBJS} ${LIB}
	${CC} ${OBJS} -L ${LIBDIR} -lmysort -o $@

.PHONY:
clean:
	@echo "Removing binary and object files ..."
	-rm -f *.o demo
	@echo -e "\nEntering into ${SUBDIR}"
	@cd ${SUBDIR} && ${MAKE} clean
	@echo "Leaving from ${SUBDIR}"
