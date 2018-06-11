CC = gcc
CFLAGXX := -Wall -std=c99
CFLAGXX += -g3 -fPIC
INCDIR := . -I ../inc
BINDIR := ../bin
LIBDIR := ../lib
LIB := libconhash.so

TARGET = conhashdemo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))
LIBOBJS = $(filter-out rbtreedemo.o, $(OBJS))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -L $(LIBDIR) -lrbtree -o $(shell pwd)/$(BINDIR)/$(TARGET)
	$(CC) -fPIC -shared $(LIBOBJS) -L $(LIBDIR) -lrbtree -o $(shell pwd)/$(LIBDIR)/$(LIB)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
