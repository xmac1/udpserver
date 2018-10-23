//
// Created by xmac on 18-10-23.
//

#include "../../include/unp.h"

int main(int argc, char** argv) {
    int sockfd, n;
    char* recvline[MAXLINE];
    struct sockadr_in servaddr;
    struct in_addr **pptr;
    struct in_adddr *inetaddrp[2];
    struct in_addr inetaddr;
    struct servent *sp;

    if (argc != 3) {
        err_quit("usage: daytimetcpcli1 <hostname> <service>");
    }
}