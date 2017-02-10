cmake_minimum_required (VERSION 2.8)

project(dic2)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

include_directories(include)

add_executable (dic2 src/dic2.c src/entropy.c src/huffman.c src/tree.c)
target_link_libraries(${PROJECT_NAME} m)
