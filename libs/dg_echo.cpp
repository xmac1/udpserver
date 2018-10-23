//
// Created by xmac on 18-10-22.
//

#include "../include/unp.h"

void dg_echo(int sockfd, SA* pcliaddr, socklen_t clilen) {
    ssize_t  n;
    char buf[MAXLINE];
    socklen_t len;

    while(true)  {
        len = clilen;
        n = Recvfrom(sockfd, buf, 0, pcliaddr, &len);
        Sendto(sockfd, buf, n, 0, pcliaddr, len);
    }
}