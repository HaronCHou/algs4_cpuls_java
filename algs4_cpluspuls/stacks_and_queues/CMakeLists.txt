cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)


add_executable(LinkedStack src/LinkedStack.cpp)
add_executable(FixedCapacityStack src/FixedCapacityStack.cpp)


add_executable(LinkedStack_iterator src_iterator/LinkedStack.cpp)
add_executable(FixedCapacityStack_iterator src_iterator/FixedCapacityStack.cpp)
add_executable(ResizingArrayStack_iterator src_iterator/ResizingArrayStack.cpp)