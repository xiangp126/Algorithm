CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -g3
LIBS  = -lpthread
INCDIR =
BINDIR = ../bin

TARGET := mthread_demo

all: ${TARGET}

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))

%.o: %.cpp
	$(CC) $(CFLAGXX) -c $^ -o $@

${TARGET}: ${OBJS}
	@mkdir -p ${BINDIR}
	$(CC) $(LIBS) $^ -o $(shell pwd)/$(BINDIR)/$(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
