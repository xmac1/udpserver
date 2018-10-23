//
// Created by xmac on 18-10-21.
//

#include "../../include/unp.h"

void sig_chld(int);

int main(int argc, char** argv) {
    int listenfd, connfd;
    int maxfd, i, maxi, sockfd;
    int nready, client[FD_SETSIZE];
    fd_set rset, allset;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buf[MAXLINE];
    ssize_t  n;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Signal(SIGCHLD, sig_chld);

    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    maxfd = listenfd;
    maxi = -1;

    for (i = 0; i < FD_SETSIZE; i++) {
        client[i] = -1; // indicate available entry
    }

    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);

    while (true) {
        rset = allset; // init all set
        nready = Select(maxfd + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(listenfd, &rset)) {
            clilen = sizeof(cliaddr);

            connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);

            for (i = 0; i < FD_SETSIZE; i++) {
                if (client[i] < 0) {
                    client[i] = connfd;
                    break;
                }
            }

            if (i == FD_SETSIZE) {
                err_quit("too many client");
            }

            FD_SET(connfd, &allset);
            if (connfd > maxfd) {
                maxfd = connfd;
            }
            if (i > maxi) {
                maxi = i;
            }

            if (--nready <= 0) {
                continue;
            }
        }

        for (i = 0; i <= maxi; i++) {
            if (sockfd = client[i]; sockfd < 0) {
                continue;
            }

            if (FD_ISSET(sockfd, &rset)) {
                if (n = Read(sockfd, buf, MAXLINE); n == 0) { // EOF
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                } else {
                    Writen(sockfd, buf, n);
                }

                if (--nready <= 0) {
                    break;
                }
            }

        }
    }
}