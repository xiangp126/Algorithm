CC = g++
CFLAGXX = -Wall -std=c++11
INCDIR = inc
LIBDIR = src/lib
LIB = libmysort.so
MAKE = make

all: demo ${LIB}

SUBDIR = src
${LIB}:
	@echo "Entering into ${SUBDIR}"
	@cd ${SUBDIR} && ${MAKE}

demo: demo.cpp ${LIB}
	${CC} ${CFLAGXX} $< -I ${INCDIR} -L ${LIBDIR} -lmysort -o $@

.PHONY:
clean:
	@echo "Removing binary and object files ..."
	-rm -f *.o demo
	@echo "\nEntering into ${SUBDIR}"
	@cd ${SUBDIR} && ${MAKE} clean
