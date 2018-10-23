project(sockopt)

link_directories(../../libs)
link_libraries(libunp.a)

add_executable(checkopts checkopts.cpp)