project(GWExtension)

set(SOURCE_FILES Validator/Validator.cpp Validator/Validator.h GameController/GameController.cpp GameController/GameController.h Player/Player.cpp Player/Player.h Map/Map.cpp Map/Map.h MovementController/MovementController.cpp MovementController/MovementController.h)

add_library(src STATIC ${SOURCE_FILES})
