project(udpcliserv)

link_directories(../../libs)
link_libraries(libunp.a)

add_executable(udpserv01 udpserv01.cpp)
add_executable(udpcli01 udpcli01.cpp dgcliconnect.cpp)