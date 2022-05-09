cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(DBL VERSION 1.0)

add_subdirectory(infra)

file(GLOB_RECURSE SRC_FILES "samples/*.cpp")
add_executable(demo.x ${SRC_FILES})
target_link_libraries(demo.x PUBLIC infra)
