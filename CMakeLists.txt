cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/")
find_package(Featherkit REQUIRED COMPONENTS entity ui structure rendering messaging sfml)

add_subdirectory("00_windowandinput")
add_subdirectory("01_quadrendering")
add_subdirectory("02_gameapplication")
add_subdirectory("03_gamestatemachine")
add_subdirectory("04_tilesanimations")
