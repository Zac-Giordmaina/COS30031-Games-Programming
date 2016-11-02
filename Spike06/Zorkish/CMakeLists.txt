cmake_minimum_required(VERSION 3.5)
project(Zorkish)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp StateManager/StateManager.cpp StateManager/StateManager.h State/State.cpp State/State.h MainMenu/MainMenu.cpp MainMenu/MainMenu.h GameManager/GameManager.cpp GameManager/GameManager.h AdventureMenu/AdventureMenu.cpp AdventureMenu/AdventureMenu.h About/About.cpp About/About.h FameHall/FameHall.cpp FameHall/FameHall.h Help/Help.cpp Help/Help.h AdventureState/AdventureState.cpp AdventureState/AdventureState.h InventoryMadnessAdventure/InventoryMadnessAdventure.cpp InventoryMadnessAdventure/InventoryMadnessAdventure.h Inventory/Inventory.cpp Inventory/Inventory.h InventoryItem/InventoryItem.cpp InventoryItem/InventoryItem.h Gem/Gem.cpp Gem/Gem.h Player/Player.cpp Player/Player.h)
add_executable(Zorkish ${SOURCE_FILES})