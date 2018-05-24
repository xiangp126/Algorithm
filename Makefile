CC = g++
CFLAGXX += -Wall
CFLAGXX += -std=c++11 -fPIC -g3
INCDIR = inc
LIBDIR = lib
BINDIR = bin
MAKE = make
LIBS = libmybasic.so libmysort.so libmykmp.so

SUBDIRS = basic kmp sort test

all:
	for i in $(SUBDIRS); do $(MAKE) -C $$i || exit 1; done

.PHONY:
clean:
	for i in $(SUBDIRS); do $(MAKE) -C $$i clean || exit 1; done
