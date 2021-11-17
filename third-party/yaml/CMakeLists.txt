project(yaml)

ExternalProject_Add(build-${PROJECT_NAME}
    URL ${PROJECT_SOURCE_DIR}/yaml-cpp-master.tar.gz
    CMAKE_COMMAND cmake -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix
    BUILD_COMMAND make
    INSTALL_COMMAND make install
    COMMAND rm -rf ${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/lib/cmake
    COMMAND rm -rf ${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/lib/pkgconfig)

# set search path
set(YAMLCPP_HEADER_DIR "${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/include"
    CACHE PATH INTERNAL FORCE)
set(YAMLCPP_LINK_DIR "${PROJECT_BINARY_DIR}/build-${PROJECT_NAME}-prefix/lib"
    CACHE PATH INTERNAL FORCE)
