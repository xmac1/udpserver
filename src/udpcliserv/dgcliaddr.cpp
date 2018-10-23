//
// Created by xmac on 18-10-22.
//

#include "unp.h"

void dg_cli(FILE* fp, int sockfd, const SA* pservaddr, socklen_t socklen) {
    int n;
    char recvline[MAXLINE], sendline[MAXLINE];

    socklen_t len;
    struct sockaddr* preply_addr;

    preply_addr =(struct sockaddr*) Malloc(socklen);

    while (Fgets(sendline, MAXLINE, fp) != NULL) {
        Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, socklen);

        len = socklen;
        Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
        if (len != socklen || memcmp(pservaddr, preply_addr, len) != 0) {
            printf("receive from %s(ignore)\n", Sock_ntop(preply_addr, len));
        }

        Fputs(recvline, fp);

    }
}