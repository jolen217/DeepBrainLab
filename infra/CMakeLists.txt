cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES "*.cpp")
add_library(infra SHARED ${SRC_FILES})
target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
