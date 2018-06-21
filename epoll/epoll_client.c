#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "config.h"

#define MAX_DATA_SIZE 1024
#define SERVER_IP     "127.0.0.1"
#define SERVER_PORT   1300


int main(int argc, char *argv[])
{
    char msg[MAXDATASIZE];
    int sockFd;
    struct sockaddr_in servAddr;

    if ((sockFd == socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        oops("get socket error!");
    }

    memset(&servAddr, '\0', sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servAddr.sin_port = htons(SERVER_PORT);

    if (connect(sockFd, (const struct sockaddr *)&servAddr, sizeof(servAddr))) {
        oops("connect error!");
    }

    printf("connection request has sent!\n");



    return 0;
}
