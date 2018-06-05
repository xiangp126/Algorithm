CC = clang
CFLAGXX := -Wall
CFLAGXX += -g3
INC := .
TARGET = demo

all: $(TARGET)

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INC) -c $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INC) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
