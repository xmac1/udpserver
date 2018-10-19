//
// Created by xmac on 18-10-17.
//

#include <bits/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>

int inet_pton(int family, const char* strptr, void* addrptr) {
    if (family == AF_INET) {
        struct in_addr in_val;

        if (inet_aton(strptr, &in_val)) {
            memcpy(addrptr, &in_val, sizeof(struct in_addr));
            return (1);
        }

        return 0;
    }
    errno = EAFNOSUPPORT;
}
