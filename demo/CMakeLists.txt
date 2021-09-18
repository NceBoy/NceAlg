project(demo)

cmake_minimum_required(VERSION 3.11)

if(CMAKE_BUILD_TYPE MATCHES "Release")
SET(CMAKE_BUILD_TYPE_POSTFIX "")
endif()
if(CMAKE_BUILD_TYPE MATCHES "Debug")
SET(CMAKE_BUILD_TYPE_POSTFIX "d")
endif()

link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${LIBRARY_OUTPUT_PATH}/${CMAKE_BUILD_TYPE})

execute_process(
    COMMAND mkdir -p ${PROJECT_SOURCE_DIR}/inc/
    COMMAND cp ${NCE_BUILD_PATH}/nce_alg/common/common.h    ${PROJECT_SOURCE_DIR}/inc/
    COMMAND cp ${NCE_BUILD_PATH}/nce_alg/alg/nce_alg_c.h    ${PROJECT_SOURCE_DIR}/inc/
    COMMAND cp ${NCE_BUILD_PATH}/nce_alg/alg/nce_alg.hpp    ${PROJECT_SOURCE_DIR}/inc/
    COMMAND cp ${NCE_BUILD_PATH}/nce_alg/alg/alg_type.h     ${PROJECT_SOURCE_DIR}/inc/
    COMMAND cp  -rf ${NCE_BUILD_PATH}/nce_alg/platform/${PLATFORM}/lib   ${PROJECT_SOURCE_DIR}/${PLATFORM}
)
# Find all main*.cpp files and store in list mains
file(GLOB_RECURSE demos ${PROJECT_SOURCE_DIR}/${PLATFORM}/*.cpp)
foreach(mainfile IN LISTS demos)
    # Get file name without directory
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/${PLATFORM}/include/)
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/inc/)
    link_directories(${PROJECT_SOURCE_DIR}/${PLATFORM}/lib/)
    file(GLOB_RECURSE libs ${PROJECT_SOURCE_DIR}/${PLATFORM}/lib/*)
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
    target_link_libraries(${mainname} nce_alg ${libs})
    add_dependencies(${mainname} nce_alg)
    install(TARGETS ${mainname} DESTINATION ${PROJECT_SOURCE_DIR})
endforeach()


	
