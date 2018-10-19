//
// Created by xmac on 18-10-19.
//

#include "../../include/unp.h"

void sig_chld(int signo) {
    pid_t  pid;
    int stat;

    pid = wait(&stat);

    printf("child %d termination\n", pid);
    return;
}