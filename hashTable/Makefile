CC = gcc
CFLAGXX := -Wall -g3
CFLAGXX += -fPIC
INCDIR := . -I ../inc
BINDIR := ../bin
LIBDIR := ../lib
LIB := libhlist.so

TARGET = hlist_demo

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
	$(CC) $^ -o $(shell pwd)/$(BINDIR)/$(TARGET)
	# $(CC) -fPIC -shared $(LIBOBJS) -L $(LIBDIR) -lrbtree -o $(shell pwd)/$(LIBDIR)/$(LIB)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
