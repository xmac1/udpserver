cmake_minimum_required(VERSION 3.12)
project(intro)

link_directories(../../libs)
link_libraries(libunp.a)

set(CMAKE_CXX_STANDARD 17)

add_executable(cli daytimetcpcli.cpp)
add_executable(srv daytimetcpsrv.cpp)
