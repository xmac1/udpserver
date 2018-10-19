cmake_minimum_required(VERSION 3.12)
project(udpserver)

INCLUDE_DIRECTORIES(
        include
)

link_directories(libs)
link_libraries(libunp.a)

AUX_SOURCE_DIRECTORY(
        src DIR_SRC
)

set(CMAKE_CXX_STANDARD 17)
SET(EXECUTABLE_OUTPUT_PATH  build)



ADD_SUBDIRECTORY(src/intro)
add_subdirectory(libfree)
add_subdirectory(libs)
add_subdirectory(src/tcpcliserv)

add_executable(main main.cpp main.cpp)