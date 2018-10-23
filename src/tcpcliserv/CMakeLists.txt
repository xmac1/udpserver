project(tcpcliseullptr, nullptr);

        if (FD_ISSET(STDIN_FILENO, &rset)) {
            if (n = read(STDIN_FILENO, toiptr, &to[MAXLINE] - toiptr); n < 0) {
                if (errno != EWOULDBLOCK)
                    err_sys("read error on stdin");
            } else if (n == 0) {
                fprintf(stderr, "%s: EOF on stdin\n", gf_time());
                stdineof = 1;
                if (toiptr == tooptr)
                    Shutdown(sockfd, SHUT_WR);
            } else {
                fprintf(stderr, "%s: read %ld bytes from stdin\n", gf_time(), n);
                toiptr += n;
                FD_SET(sockfd, &wrv)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../include)
link_libraries(libunp.a)
link_directories(../../libs)

add_executable(tcpsrv1 tcpserv01.cpp sigchldwait.cpp str_echo.cpp sigchldwaitpid.cpp)
add_executable(tcpcli1 tcpcli01.cpp ../nonblock/strclinonb.cpp)
add_executable(tcpcli04 tcpcli04.cpp ../nonblock/strclinonb.cpp)
add_executable(tcpsrv04 tcpsrv04.cpp sigchldwaitpid.cpp)
add_executable(srvselect01 tcpservselect01.cpp sigchldwaitpid.cpp str_echo.cpp)