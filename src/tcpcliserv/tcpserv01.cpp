//
// Created by xmac on 18-10-19.
//

#include "../../include/unp.h"


void sig_chld(int signo);

int main(int argc, char** argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, &sig_chld);

    while(true) {
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (SA*) &cliaddr, &clilen);
        if (childpid = Fork(); childpid == 0) { // child process
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        } else { // parent process
            Close(connfd);
        }
    }
}

void str_echo(int sockfd) {
    ssize_t  n;
    char buf[MAXLINE];

    again:
    while((n = read(sockfd, buf, sizeof(buf))) > 0) {
        Writen(sockfd, buf, n);
    }

    if (n < 0 && errno == EINTR) {
        goto again;
    } else if (n < 0) {
        err_sys("str_echo: read error");
    }
}