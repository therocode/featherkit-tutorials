cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)   #for executables

#project name
set(project_name tilesanimations)
project(${project_name})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -O3")

file(GLOB_RECURSE source_files "src/*.cpp")
file(GLOB_RECURSE header_files "src/*.h")

add_executable(${project_name} ${header_files} ${source_files})

if(FEATHERKIT_FOUND)
    include_directories(${FEATHERKIT_INCLUDE_DIRS})
    target_link_libraries(${project_name} ${FEATHERKIT_LIBRARIES})
endif()

target_link_libraries(${project_name} GL GLU GLEW sfml-window sfml-system sfml-graphics)
