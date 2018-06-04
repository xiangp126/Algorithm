CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
INCDIR = ../inc
TARGET = treedemo

all: $(TARGET)

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
