cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(nms_demo.x nms_demo.cpp)
target_include_directories(nms_demo.x PUBLIC ${PROJECT_BINARY_DIR})

add_executable(video_demo.x video_demo.cpp)
target_link_libraries(video_demo.x PUBLIC ${OpenCV_LIBS})
target_include_directories(video_demo.x PUBLIC ${PROJECT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS})

add_executable(imouse_demo.x imouse_demo.cpp)
target_link_libraries(imouse_demo.x PUBLIC ${OpenCV_LIBS})
target_include_directories(imouse_demo.x PUBLIC ${PROJECT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS})
