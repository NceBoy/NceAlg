set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CHIP_NAME rv1126)

set(CMAKE_CROSS_PREFIX  "/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf")
set(CMAKE_C_COMPILER    "/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER  "/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++")
set(CMAKE_AR            /opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-ar CACHE FILEPATH "Archiver")
set(CMAKE_LINER         "/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++")
set(CMAKE_LD            "/opt/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-ld")
#set(CMAKE_SYSROOT /home/cjyvm2/3516rootfs/rootfs)
# This crosstool doesn't define SO_REUSEPORT
add_compile_options(-Wno-unused-function)
#add_compile_options(-std=c++11)
# This chip provides the floating-point operation unit and NEON.
# The libraries in the file system are compiled with hard floating point and neon compatible with the soft floating point call interface.
#add_compile_options(-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
