CC = gcc
CFLAGXX := -Wall -std=c99
CFLAGXX += -g3
INCDIR := .
BINDIR := ../bin
LIBDIR := ../lib
LIB := libmyrbtree.so

TARGET = rbtreedemo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

# Also generate rbtree & md5 .so
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(shell pwd)/$(BINDIR)/$(TARGET)
	$(CC) -fPIC -shared $^ -o $(shell pwd)/$(LIBDIR)/$(LIB)
	$(CC) -fPIC -shared md5.o -o $(shell pwd)/$(LIBDIR)/libmd5.so

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
