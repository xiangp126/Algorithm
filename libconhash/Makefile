CC = gcc
CFLAGXX += -Wall
CFLAGXX += -g3
INCDIR = ../inc
TARGET = demo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
