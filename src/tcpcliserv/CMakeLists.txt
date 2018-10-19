project(tcpcliserv)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../include)
link_libraries(libunp.a)
link_directories(../../libs)

add_executable(tcpsrv1 tcpserv01.cpp sigchldwait.cpp)
add_executable(tcpcli1 tcpcli01.cpp)