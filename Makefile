CC = g++
CFLAGXX = -Wall -std=c++11 -g3
INCDIR = inc
LIBDIR = lib
BINDIR = bin
MAKE = make
LIBS = libmybasic.so libmysort.so

all: binary

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

TESTDIR = test
binary: ${LIBS}
	@echo "Entering into ${TESTDIR}"
	@cd ${TESTDIR} && ${MAKE}
	@echo "Leaving from ${TESTDIR}"

.PHONY:
clean:
	@echo -e "\nEntering into ${BASICDIR}"
	@cd ${BASICDIR} && ${MAKE} clean
	@echo "Leaving from ${BASICDIR}"
	@echo -e "\nEntering into ${SORTDIR}"
	@cd ${SORTDIR} && ${MAKE} clean
	@echo "Leaving from ${SORTDIR}"
	@echo "Removing binary and object files ..."
	-rm -f *.o ${LIBDIR}/lib*.so ${BINDIR}/*
