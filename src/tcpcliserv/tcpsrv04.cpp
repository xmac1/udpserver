//
// Created by xmac on 18-10-20.
//

#include "../../include/unp.h"

void sig_chld(int);

int main(int argc, char** argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t  clilen;
    pid_t  childpid;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);


    Signal(SIGCHLD, sig_chld);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    while(true) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (SA*)&cliaddr, &clilen);
        if (connfd < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                err_sys("accept error");
            }
        }

        if (childpid = Fork(); childpid == 0) {
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        } else {
            Close(connfd);
        }

    }
}