cmake_minimum_required(VERSION 3.24)
project(TowerDefence)

set(CMAKE_CXX_STANDARD 17)

add_executable(TowerDefence main.cpp Game_elements/game_elements.cpp Game_elements/game_elements.h Game_elements/player.cpp Game_elements/player.h)
target_link_libraries(TowerDefence rpcrt4.lib)