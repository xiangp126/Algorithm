CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
LIBDIR = ../lib
INCDIR = ../inc
LIB = libmybasic.so

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))

all: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p $(LIBDIR)
	$(CC) -fPIC -shared $^ -o $(shell pwd)/$(LIBDIR)/$(LIB)

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o
