cmake_minimum_required(VERSION 3.10)
# set(CMAKE_BUILD_TYPE Release) # Debug，对时间开销帮助不大
set(CMAKE_BUILD_TYPE Debug)
# Set compiler optimization flags for Release mode: 启用最大优化
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g0") # gcc，启用编译器高级优化标志，`-O3`
    message("CMKAE_BUILD+TYPE:${CMAKE_BUILD_TYPE}")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0")  # 禁用调试符号
endif()


set(PROJECT_NAME UF)
project(${PROJECT_NAME})

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)

# 设置 QuickFindUF 可执行文件
add_executable(QuickFindUF src/QuickFindUF.cpp) # ./QuickFindUF < ../input/tiny.txt > QuickFindUF_res.txt
add_executable(QuickUionUF src/QuickUionUF.cpp)
add_executable(WeightedQuickUnionUF src/WeightedQuickUnionUF.cpp)
add_executable(WeightedQuickUnionPCUF src/WeightedQuickUnionPCUF.cpp)

