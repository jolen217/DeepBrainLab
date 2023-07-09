cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(nms_demo.x nms_demo.cpp)
target_include_directories(nms_demo.x PUBLIC ${PROJECT_BINARY_DIR})
