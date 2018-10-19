//
// Created by xmac on 18-10-19.
//

#include <iostream>
#include <netinet/in.h>

using namespace std;

int main(int argc, char** argv) {
    char line[100];

    struct sockaddr_in sa;

    cout << "sizeof(sa): " << sizeof(sa) << endl;
}
