CC = gcc
CFLAGXX := -Wall -std=c99
CFLAGXX += -fPIC
INCDIR := . -I ../inc
BINDIR := ../bin
LIBDIR := ../lib

SERVER_NAME = epoll_server
CLIENT_NAME = epoll_client
TARGET = $(SERVER_NAME) $(CLIENT_NAME)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGXX) -I $(INCDIR) -c $^ -o $@

epoll_client: epoll_client.o
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(shell pwd)/$(BINDIR)/$(CLIENT_NAME)

epoll_server: epoll_server.o
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(shell pwd)/$(BINDIR)/$(SERVER_NAME)

.PHONY:
clean:
	@echo Removing binary and object files ...
	-rm -f *.o $(TARGET)
