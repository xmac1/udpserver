//
// Created by xmac on 18-10-23.
//

#include "../include/unp.h"

char* gf_time() {
    struct timeval tv;
    static char str[30];
    char* ptr;

    if (gettimeofday(&tv, NULL) < 0) {
        err_sys("gettimeofday error");
    }

    ptr = ctime(&tv.tv_sec);
    strcpy(str, &ptr[11]);

    snprintf(str + 8, sizeof(str) - 8, ".06ld", tv.tv_usec);
    return str;
}
