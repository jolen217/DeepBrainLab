cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project(DBL VERSION 1.0)

add_subdirectory(infra)

file(GLOB_RECURSE SRC_FILES "samples/*.cpp")

find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(demo.x ${SRC_FILES})
target_include_directories(demo.x PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(demo.x PUBLIC infra PRIVATE ${OpenCV_LIBS})
