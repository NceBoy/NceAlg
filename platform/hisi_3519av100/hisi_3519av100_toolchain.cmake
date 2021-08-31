set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv)
set(CMAKE_CHIP_NAME hi3519)
set(CMAKE_TOOLCHAIN_PATH  "/home/video/user/yehc/sdk/arm-hisiv600-linux/bin/")
set(CMAKE_CROSS_PREFIX     "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi")
set(CMAKE_C_COMPILER       "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER     "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi-g++")
set(CMAKE_AR               "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi-ar")
set(CMAKE_LINER            "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi-g++")
set(CMAKE_LD               "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gnueabi-ld")
#set(CMAKE_SYSROOT /home/cjyvm2/3516rootfs/rootfs)
# This crosstool doesn't define SO_REUSEPORT
add_compile_options(-Wno-unused-function)

#add_compile_options(-std=c++11)
# This chip provides the floating-point operation unit and NEON.
# The libraries in the file system are compiled with hard floating point and neon compatible with the soft floating point call interface.
#add_compile_options(-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations)

set(CMAKE_CXX_FLAGS "-mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations -ffunction-sections -fdata-sections ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-g -fPIC -O3  -std=c++11 -mcpu=cortex-a17.cortex-a7 -ldl -lrt   -lpthread ${CMAKE_CXX_FLAGS}")

# add_compile_options(-g -fPIC -O3 -std=c++11 -mcpu=cortex-a17.cortex-a7)
# add_compile_options(-mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations -ffunction-sections -fdata-sections)

# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)