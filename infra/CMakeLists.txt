file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_library(infra STATIC ${SRC_FILES})
target_include_directories(infra PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
