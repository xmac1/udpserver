project(libunp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY .)

add_library(libunp sock_ntop.cpp readn.cpp writen.cpp readline1.cpp readline.cpp wrapsock.cpp signal.cpp dg_echo.cpp dg_cli.cpp ../src/udpcliserv/dgcliaddr.cpp connect_timeo.cpp gf_time.cpp)