set(CMAKE_CROSS_PREFIX  "aarch64-himix100-linux")
set(CMAKE_C_COMPILER    "aarch64-himix100-linux-gcc")
set(CMAKE_CXX_COMPILER  "aarch64-himix100-linux-g++")
set(CMAKE_AR            "aarch64-himix100-linux-ar")
set(CMAKE_LINER         "aarch64-himix100-linux-g++")
set(CMAKE_LD            "aarch64-himix100-linux-ld")

set(CMAKE_CXX_FLAGS "-ffunction-sections -fdata-sections -mcpu=cortex-a73.cortex-a53  -fno-aggressive-loop-optimizations")
set(CMAKE_CXX_FLAGS "-fPIC -O2  -mcpu=cortex-a73.cortex-a53  ${CMAKE_CXX_FLAGS}")
#set(CMAKE_SYSROOT /home/cjyvm2/3516rootfs/rootfs)
# This crosstool doesn't define SO_REUSEPORT

#add_compile_options(-std=c++11)
# This chip provides the floating-point operation unit and NEON.
# The libraries in the file system are compiled with hard floating point and neon compatible with the soft floating point call interface.
#add_compile_options(-mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -fno-aggressive-loop-optimizations)


