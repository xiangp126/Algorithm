CC = gcc
CFLAGXX += -Wall
CFLAGXX += -g3
INCDIR = ../inc
TARGET = demo

all: $(TARGET)

SOURCE = $(wildcard *.c)
OBJS   = $(patsubst %.c, %.o, $(SOURCE))

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
