CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
LIB = libmykmp.so

all: ${LIB}

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

${LIB}: ${OBJS}
	@mkdir -p ${LIBDIR}
	${CC} -fPIC -shared $^ -L ${LIBDIR} -lmybasic -o ${shell pwd}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
