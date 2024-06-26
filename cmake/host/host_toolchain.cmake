set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_CHIP_NAME host)

set(CMAKE_CROSS_PREFIX  "")
set(CMAKE_C_COMPILER    "gcc")
set(CMAKE_CXX_COMPILER  "g++")
set(CMAKE_AR            "ar")
set(CMAKE_LINER         "g++")
set(CMAKE_LD            "ld")
add_compile_options(-std=c++11)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
