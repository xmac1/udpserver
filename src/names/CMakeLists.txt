project(names)

link_directories(../../libs)
link_libraries(libunp.a)


add_executable(hostent hostent.cpp)
add_executable(daytimetcpcli1 daytimetcpcli1.cpp)