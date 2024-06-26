project(nce_alg)

cmake_minimum_required(VERSION 3.5)

if(CMAKE_BUILD_TYPE MATCHES "Release")
SET(CMAKE_BUILD_TYPE_POSTFIX "")
endif()
if(CMAKE_BUILD_TYPE MATCHES "Debug")
SET(CMAKE_BUILD_TYPE_POSTFIX "d")
endif()

option(NCE_BUILD_SHARED "Build ncealg shared library" ON)


include(${PROJECT_SOURCE_DIR}/platform/${PLATFORM}/${PLATFORM}.cmake) 
include(${PROJECT_SOURCE_DIR}/../third-party/modules.cmake) 


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/core/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/alg_manager/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/StanfordCPPLib/)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/common/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/hook_manager/)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/engine_manager/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/engine_manager/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/engine_manager/host/)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg LIB_SRC)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/StanfordCPPLib CPPLIB_SRC)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/common/ COMMON_SRC)

file(GLOB_RECURSE  ALG_SRC ${PROJECT_SOURCE_DIR}/alg/alg_manager/*.c
						    ${PROJECT_SOURCE_DIR}/alg/alg_manager/*.cpp)

file(GLOB_RECURSE  HOOK_SRC ${PROJECT_SOURCE_DIR}/alg/hook_manager/*.c
                              ${PROJECT_SOURCE_DIR}/alg/hook_manager/*.cpp)


#third-party
message( STATUS ${THIRD_PARTY_LIB})



#INCLUDE_DIRECTORIES(${YAMLCPP_HEADER_DIR})
#link_directories(${YAMLCPP_LINK_DIR})
#生成动态库  静态库则 STATIC
if(NCE_BUILD_SHARED)
ADD_LIBRARY(${PROJECT_NAME} SHARED 
${LIB_SRC}
${ALG_SRC}
${HOOK_SRC}
${PLATFORM_SRC}
${COMMON_SRC}
${CPPLIB_SRC})

target_link_libraries(${PROJECT_NAME}
-Wl,--start-group
${OPENCV_LIB}
${PLATFORM_LIB}
${THIRD_PARTY_LIB}
-Wl,--end-group)

add_dependencies(${PROJECT_NAME} ${THIRD_PARTY_NEED})
# VERSION指代动态库版本，SOVERSION指代API版本。
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES VERSION 1.2 SOVERSION 1)

else()

#静态库不能写为同名，否则会被动态库覆盖
ADD_LIBRARY(${PROJECT_NAME} STATIC
${LIB_SRC}
${ALG_SRC}
${HOOK_SRC}
${PLATFORM_SRC}
${COMMON_SRC}
${CPPLIB_SRC})

target_link_libraries(${PROJECT_NAME}
-Wl,--start-group
${OPENCV_LIB}
${PLATFORM_LIB}
${THIRD_PARTY_LIB}
-Wl,--end-group)

add_dependencies(${PROJECT_NAME} ${THIRD_PARTY_NEED})

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
endif()


file(GLOB_RECURSE PLATFORM_LIB  ${PROJECT_SOURCE_DIR}/platform/${PLATFORM}/lib/*)
install(TARGETS ${PROJECT_NAME}  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
install(FILES ${PLATFORM_LIB} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
# 安装头文件
INSTALL(FILES ${PROJECT_SOURCE_DIR}/include/nce_alg_c.h
${PROJECT_SOURCE_DIR}/include/nce_alg.hpp
${PROJECT_SOURCE_DIR}/include/alg_type.h
${PROJECT_SOURCE_DIR}/common/common.h
 DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

