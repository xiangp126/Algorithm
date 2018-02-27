CC = g++
CFLAGXX = -Wall -std=c++11 -g3
INCDIR = inc
LIBDIR = lib
OBJS = demo.o
MAKE = make
LIBS = libmybasic.so libmysort.so

all: demo

BASICDIR = basic
libmybasic.so:
	@echo "Entering into ${BASICDIR}"
	@cd ${BASICDIR} && ${MAKE}
	@echo "Leaving from ${BASICDIR}"

SORTDIR = sort
libmysort.so:
	@echo "Entering into ${SORTDIR}"
	@cd ${SORTDIR} && ${MAKE}
	@echo "Leaving from ${SORTDIR}"

demo.o: demo.cpp
	${CC} ${CFLAGXX} -I ${INCDIR} -c $<

demo: ${OBJS} ${LIBS}
	${CC} ${OBJS} -L ${LIBDIR} -lmybasic -lmysort -o $@

.PHONY:
clean:
	@echo "Removing binary and object files ..."
	-rm -f *.o demo
	@echo -e "\nEntering into ${BASICDIR}"
	@cd ${BASICDIR} && ${MAKE} clean
	@echo "Leaving from ${BASICDIR}"
	@echo -e "\nEntering into ${SORTDIR}"
	@cd ${SORTDIR} && ${MAKE} clean
	@echo "Leaving from ${SORTDIR}"
