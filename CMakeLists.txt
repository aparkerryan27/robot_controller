
cmake_minimum_required(VERSION 3.3)

project(robot_controller)

add_executable( robot_controller src/main.cpp include/joystick.h include/controller.h include/ptcp.h src/joystick.cpp src/controller.cpp src/ptcp.cpp)
add_executable( print_data tests/print_data.cpp) 

configure_file(tests/straight_line.txt straight_line.txt COPYONLY)

target_include_directories(robot_controller PRIVATE include)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
