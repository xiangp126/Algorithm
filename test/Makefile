CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
INCDIR = ../inc
BINDIR = ../bin
LIBDIR = ../lib
LIBS   = -lmybasic -lmysort

SOURCE = $(wildcard *.cpp)
OBJS   = $(patsubst %.cpp, %.o, $(SOURCE))
TARGET = $(patsubst %.cpp, %, $(SOURCE))

%.o: %.cpp
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

all: $(TARGET)

sortdemo: sortdemo.o
	@mkdir -p ${BINDIR}
	${CC} $< -L ${LIBDIR} -lmybasic -lmysort -o ${BINDIR}/$@

kmpdemo: kmpdemo.o
	@mkdir -p ${BINDIR}
	${CC} $< -L ${LIBDIR} -lmybasic -lmykmp -o ${BINDIR}/$@

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -rf $(BINDIR)
	-rm -f *.o
