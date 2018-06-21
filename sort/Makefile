CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
BINDIR = ../bin
LIB = libsort.so

TARGET := sort_demo

all: ${TARGET}

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))
LIBOBJS = $(filter-out sort_demo.o, $(OBJS))

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

${TARGET}: ${OBJS}
	@mkdir -p ${BINDIR}
	$(CC) -L $(LIBDIR) -lcommon $^ -o $(shell pwd)/$(BINDIR)/$(TARGET)
	${CC} -fPIC -shared $(LIBOBJS) -L ${LIBDIR} -lcommon -o ${shell pwd}/${LIBDIR}/${LIB}

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
