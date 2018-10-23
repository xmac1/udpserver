//
// Created by xmac on 18-10-23.
//

#include "../include/unp.h"

static void connect_alarm(int);

int connect_timeo(int sockfd, const SA* saptr, socklen_t salen, int nsec) {
    Sigfunc *sigfunc;
    int n;

    sigfunc = Signal(SIGALRM, connect_alarm);
    if (alarm(nsec) != 0)
        err_msg("connect_timo: alarm was already set");

}