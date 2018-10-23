//
// Created by xmac on 18-10-22.
//

#include "../../include/unp.h"

void dg_cli(FILE* fp, int sockfd, const SA* pservaddr, socklen_t servlen)  {
    int n;
    char recvline[MAXLINE + 1], sendline[MAXLINE];

    Connect(sockfd, pservaddr, servlen);

    while(Fgets(sendline, MAXLINE, fp) != NULL ) {
        Write(sockfd, sendline, strlen(sendline));

        n = Read(sockfd, recvline, MAXLINE);

        recvline[n] = 0;
        Fputs(recvline, fp);
    }
}