cmake_minimum_required(VERSION 3.5)
project(GridWorld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CMakeLists.txt
    main.cpp)

add_executable(GridWorld ${SOURCE_FILES})