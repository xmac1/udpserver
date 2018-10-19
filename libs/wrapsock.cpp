//
// Created by xmac on 18-10-19.
//
#include "../include/unp.h"

void Listen(int fd, int backlog) {
    char *ptr;
    if ((ptr = getenv("LISTENNQ")) != NULL) {
        backlog = atoi(ptr);
    }
    if (listen(fd, backlog) < 0)
        err_sys("listen error");
}