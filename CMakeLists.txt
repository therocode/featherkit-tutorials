cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/")
find_package(Featherkit REQUIRED COMPONENTS entity ui structure rendering sfml)
find_package(GLM REQUIRED)
if(${GLM_FOUND})
    include_directories(${GLM_INCLUDE_DIRS})
endif()

add_subdirectory("00_windowandinput")
add_subdirectory("01_quadrendering")
add_subdirectory("02_gameapplication")
add_subdirectory("03_gamestatemachine")
add_subdirectory("04_tilesanimations")
