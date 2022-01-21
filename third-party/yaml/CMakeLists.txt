project(yaml)
ExternalProject_Add(build-${PROJECT_NAME}
    URL ${PROJECT_SOURCE_DIR}/yaml-cpp-master.tar.gz
    BUILD_COMMAND ""
    CMAKE_ARGS
#    "-DCMAKE_DEBUG_POSTFIX="
    "-DCMAKE_BUILD_TYPE=${NCE_BUILD}"
    "-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}"
    "-DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix"
    INSTALL_COMMAND
       cmake
       --build .
       --target install
       --config ${NCE_BUILD}
)
# set search path
set(YAMLCPP_HEADER_DIR "${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/include"
    CACHE PATH INTERNAL FORCE)
set(YAMLCPP_LINK_DIR "${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/lib"
    CACHE PATH INTERNAL FORCE)
