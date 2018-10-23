//
// Created by xmac on 18-10-21.
//

#include "../../include/unp.h"

void str_cli(FILE *fp, int sockfd) {
    int maxfdpl1;
    fd_set rset;
    char sendline[MAXLINE], recvline[MAXLINE];

    FD_ZERO(&rset);

    while (true) {
        FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdpl1 = max(sockfd, fileno(fp)) + 1;
        Select(maxfdpl1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset)) {
            if (Readline(sockfd, recvline, MAXLINE) == 0) {
                printf("%d", errno);
                err_quit("str_cli: server terminated prematurely");
            }
            Fputs(recvline, stdout);
        }

        if (FD_ISSET(fileno(fp), &rset)) {
            if (Fgets(sendline, MAXLINE, fp) == NULL) {
                return;
            }
            Writen(sockfd, sendline, strlen(sendline));
        }
    }
}
