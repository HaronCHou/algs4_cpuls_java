cmake_minimum_required(VERSION 3.10)
# set(CMAKE_BUILD_TYPE Release) # Debug，对时间开销帮助不大
set(CMAKE_BUILD_TYPE Debug)
# Set compiler optimization flags for Release mode: 启用最大优化
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g0") # gcc，启用编译器高级优化标志，`-O3`
    message("CMKAE_BUILD+TYPE:${CMAKE_BUILD_TYPE}")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0")  # 禁用调试符号
endif()

# add_executable(Percolation src/PercolationStats.cpp)
# set_target_properties(Percolation PROPERTIES CXX_STANDARD 11)

add_executable(PercolationVisualizer src/PercolationVisualizer.cpp)
target_link_libraries(PercolationVisualizer PRIVATE sfml-graphics sfml-window sfml-system)