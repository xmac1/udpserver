//
// Created by xmac on 18-10-20.
//

#include "../../include/unp.h"

int main(int argc, char** argv) {
    int i, sockfd[5];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        err_quit("usage: tcpcli<IP address>");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr.s_addr);

    for (i = 0; i < 5; i++) {
        sockfd[0] = Socket(AF_INET, SOCK_STREAM, 0);
        Connect(sockfd[0], (SA*) &servaddr, sizeof(servaddr));
    }

    str_cli(stdin, sockfd[0]);
}