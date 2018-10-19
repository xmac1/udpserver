//
// Created by xmac on 18-10-18.
//


#include "../include/unp.h"

ssize_t  writen(in fd, const void* vptr, size_t n) {
    size_t nleft;
    ssize_t  nwrite;
    const char* ptr = vptr;

    nleft = n;

    while(nleft > 0) {
        if ((nwrite = write(fd, ptr, nleft)) <= 0) {
            if (nwrite < 0 && errno == EINTR)
                nwrite = 0;
            else
                return -1;
        }
        nleft = n - nwrite;
        ptr += nwrite;
    }
    return n;
}
