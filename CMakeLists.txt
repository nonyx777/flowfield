cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Grid VERSION 1.0)

find_package(SFML 2 REQUIRED network audio graphics window system)

file(GLOB_RECURSE SRC_FILES src/*.cpp demos/*.cpp)
add_executable(flowfield ${SRC_FILES})

target_include_directories(flowfield PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR})
target_link_libraries(flowfield PUBLIC -lsfml-window -lsfml-graphics -lsfml-system)
