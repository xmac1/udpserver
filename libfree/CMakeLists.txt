cmake_minimum_required(VERSION 3.12)
project(libfree)

set(UNPLIB ../libs)

find_library(UNPLIB libunp.as)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY .)

add_library(libfree inet_pton_ipv4.cpp inet_ntop_ipv4.cpp)