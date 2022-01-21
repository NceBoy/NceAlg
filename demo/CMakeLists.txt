project(demo)

cmake_minimum_required(VERSION 3.5)

if(CMAKE_BUILD_TYPE MATCHES "Release")
SET(CMAKE_BUILD_TYPE_POSTFIX "")
endif()
if(CMAKE_BUILD_TYPE MATCHES "Debug")
SET(CMAKE_BUILD_TYPE_POSTFIX "d")
endif()

message("OUR SYSTEM IS ${CMAKE_SYSTEM_NAME}")
link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${LIBRARY_OUTPUT_PATH}/${CMAKE_BUILD_TYPE})
#third party
link_directories(${YAMLCPP_LINK_DIR})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(EXTRALIB "stdc++")
    file(GLOB_RECURSE ENGINE_RUNTIME_LIB  ${PROJECT_SOURCE_DIR}/../nce_alg/platform/${PLATFORM}/lib/*.so)
    set(RUNTIME_LIB_PATH ${LIBRARY_OUTPUT_PATH})
else(CMAKE_SYSTEM_NAME MATCHES "Windows")
    if(MSVC)
        set(EXTRALIB "")
        file(GLOB_RECURSE ENGINE_RUNTIME_LIB  ${PROJECT_SOURCE_DIR}/../nce_alg/platform/${PLATFORM}/lib/*.dll)
        set(RUNTIME_LIB_PATH ${LIBRARY_OUTPUT_PATH}${CMAKE_BUILD_TYPE})
    endif()
endif()
message("OURT ENGINE RUNTIME LIB IS ${ENGINE_RUNTIME_LIB}")
# Find all main*.cpp files and store in list mains
file(GLOB_RECURSE demos ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.c)
foreach(mainfile IN LISTS demos)
    # Get file name without directory
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../nce_alg/platform/${PLATFORM}/include/)
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../nce_alg/include/)
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../nce_alg/common/)
    link_directories(${PROJECT_SOURCE_DIR}/../nce_alg/platform/${PLATFORM}/lib/)
    #file(GLOB_RECURSE libs ${PROJECT_SOURCE_DIR}/../nce_alg/platform/${PLATFORM}/lib/*)
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
    target_link_libraries(${mainname} nce_alg ${libs} ${EXTRALIB})
    add_dependencies(${mainname} nce_alg)
if(ENGINE_RUNTIME_LIB)
    add_custom_command(TARGET ${mainname} 
    POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ENGINE_RUNTIME_LIB} ${RUNTIME_LIB_PATH}
    )
endif()
    install(TARGETS ${mainname} DESTINATION  ${CMAKE_INSTALL_PREFIX}/bin/)
endforeach()


	
