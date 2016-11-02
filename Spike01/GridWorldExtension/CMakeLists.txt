cmake_minimum_required(VERSION 3.5)
project(GridWorldExtension)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CMakeLists.txt
    main.cpp Validator/Validator.cpp Validator/Validator.h GameController/GameController.cpp GameController/GameController.h Player/Player.cpp Player/Player.h Map/Map.cpp Map/Map.h MovementController/MovementController.cpp MovementController/MovementController.h)

add_executable(GridWorldExtension ${SOURCE_FILES})