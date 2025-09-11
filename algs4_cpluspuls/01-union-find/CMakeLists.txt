cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Release) # Debug
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

