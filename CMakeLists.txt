cmake_minimum_required(VERSION 3.11)

SET(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
SET(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/lib/)
add_definitions(-DPLATFORM=${PLATFORM})

add_subdirectory("nce_alg")
add_subdirectory("demo")