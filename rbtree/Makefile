CC = gcc
CFLAGXX := -Wall -std=c99
CFLAGXX += -g3
INC := .
BIN := ../bin
TARGET = rbtreedemo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INC) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INC) -c $^ -o $@

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CC) $^ -o $(shell pwd)/$(BIN)/$(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
