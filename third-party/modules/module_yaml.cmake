

################################################################
if(CMAKE_BUILD_TYPE MATCHES "Debug")
#set(YAML_LIB yaml-cpp)
set(YAML_LIB yaml-cppd)
endif()
if(CMAKE_BUILD_TYPE MATCHES "Release")
set(YAML_LIB yaml-cpp)
endif()

message("YAML_BUILD_TYPE IS ${CMAKE_BUILD_TYPE}")
include_directories(${YAMLCPP_HEADER_DIR})
link_directories(${YAMLCPP_LINK_DIR})

################################################################