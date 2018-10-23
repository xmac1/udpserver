//
// Created by xmac on 18-10-22.
//

#include "../../include/unp.h"

void dg_cli(FILE* fp, int sockfd, const SA* servaddr, socklen_t socklen);

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        err_quit("usage: ./udpcli01 <IP address>");
    }

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    dg_cli(stdin, sockfd,  (SA*) &servaddr, sizeof(servaddr));
}