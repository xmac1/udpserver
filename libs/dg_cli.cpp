//
// Created by xmac on 18-10-22.
//

#include "../include/unp.h"

void dg_cli(FILE* fp, int sockfd, const SA* servaddr, socklen_t addrlen) {
    int n;
    int recvline[MAXLINE], sendline[MAXLINE];

    while(Fgets(sendline, MAXLINE, fp) != NULL) {
        Sendto(sockfd, sendline, strlen(recvline), 0, servaddr, addrlen);

        Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        Fputs(recvline, stdout);
    }
}