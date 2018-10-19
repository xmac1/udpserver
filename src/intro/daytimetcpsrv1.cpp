//
// Created by xmac on 18-10-19.
//

#include "../../include/unp.h"
#include <ctime>


int main(int argc, char** argv) {
    int listenfd, connfd;
    socklen_t len;

    struct sockaddr_in servaddr, cliaddr;

    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_port = htons(1335);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    while(true) {
        len = sizeof(cliaddr);

        connfd = Accept(listenfd, (SA*) &cliaddr, &len);
        printf("connection from :%s, port: %d,", Inet_ntop(AF_INET, &cliaddr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
}