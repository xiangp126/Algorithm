# wildcard and pattern substitute, := directly expand
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c, %.o, $(patsubst %.cpp, %.o, $(SOURCE)))

TARGET  := demo

CC   := g++
MAKE := make
LIBS := -lpthread
LIBDIR  :=
LDFLAGS :=
INCLUDE :=
CXXFLAGS:= -Wall -std=c++11 -g3

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(INCLUDE) $(LIBS)

.PHONY: clean
clean:
	@echo Removing binary and objects
	-rm -rf *.o $(TARGET)
