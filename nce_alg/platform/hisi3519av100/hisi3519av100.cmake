INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi3519av100/MNN/include)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/MNN/ ENGINE_3519av100_SRC)

#设置hisi3516dv300所需源文件
set(PLATFORM_SRC 
${ENGINE_3519av100_SRC}
) 


link_directories("${PROJECT_SOURCE_DIR}/platform/hisi3519av100/lib/")


#设置hisi3516dv300所需库文件
set(PLATFORM_LIB
-lMNN
-ldl
-lpthread
-lm
-lrt
)

# link_directories("/home/video/user/yehc/sdk/hisi/arm-himix200-linux/arm-himix200-linux/lib")
# link_directories("/home/video/user/yehc/sdk/hisi/arm-himix200-linux/arm-himix200-linux/bin")
# SET(CMAKE_SYSROOT "/home/video/user/yehc/sdk/hisi/arm-himix200-linux/")


