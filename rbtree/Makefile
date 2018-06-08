CC = gcc
CFLAGXX := -Wall -std=c99
CFLAGXX += -g3
INCDIR := .
BINDIR := ../bin
LIBDIR := ../lib
LIB := librbtree.so

TARGET = rbtreedemo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))
LIBOBJS = $(filter-out rbtreedemo.o, $(OBJS))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

# Also generate rbtree & md5 .so
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(shell pwd)/$(BINDIR)/$(TARGET)
	$(CC) -fPIC -shared $(LIBOBJS) -o $(shell pwd)/$(LIBDIR)/$(LIB)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
