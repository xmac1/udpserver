//
// Created by xmac on 18-10-21.
//

#include "../../include/unp.h"

void str_cli(FILE* fp, int sockfd) {
    int maxfpl, stdineof;
    fd_set rset;

    int n;
    char buf[MAXLINE];

    stdineof = 0;
    FD_ZERO(&rset);

    while (true) {
        if (stdineof == 0)
            FD_SET(fileno(fp), &rset);

        FD_SET(sockfd, &rset);
        maxfpl =max(fileno(fp), sockfd) + 1;
        Select(maxfpl, &rset, NULL, NULL, NULL);

        if (FD_ISSET((fileno(fp)), &rset)) {
            if (n = Read(fileno(fp), buf, sizeof(buf)); n == 0) {
                stdineof = 1;
                Shutdown(sockfd, SHUT_WR);
                FD_CLR(fileno(fp), &rset);
                continue;
            }
            Writen(sockfd, buf, n);
        }

        if (FD_ISSET(sockfd, &rset)) {
            if (n = Read(sockfd, buf, MAXLINE); n == 0) {
                if (stdineof) {
                    return;
                }
                err_quit("str_cli: server terminated prematurely");
            }
            Writen(fileno(stdout), buf, n);
        }
    }
}
