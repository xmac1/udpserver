//
// Created by xmac on 18-10-19.
//

#include "../include/unp.h"


Sigfunc* signal(int signo, Sigfunc* func) {
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (signo == SIGALRM) {
        act.sa_flags |= SA_INTERRUPT;
    } else {
        act.sa_flags |= SA_RESTART;
    }

    int i = sigaction(signo, &act, &oact);
    if (i < 0)
        return SIG_ERR;
    return oact.sa_handler;
}