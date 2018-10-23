//
// Created by xmac on 18-10-20.
//

#include "../../include/unp.h"

int sig_chld(int signo) {
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n ", pid);
    return pid;
}