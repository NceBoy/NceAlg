cmake_minimum_required(VERSION 3.11)

if(CMAKE_BUILD_TYPE MATCHES "Release")
SET(NCE_BUILD "Release")
endif()
if(CMAKE_BUILD_TYPE MATCHES "Debug")
SET(NCE_BUILD "Debug")
endif()

SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin/)
SET(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/lib/)
SET(NCE_BUILD_PATH  ${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-DPLATFORM=${PLATFORM})

add_subdirectory("third-party")
add_subdirectory("nce_alg")
add_subdirectory("demo")