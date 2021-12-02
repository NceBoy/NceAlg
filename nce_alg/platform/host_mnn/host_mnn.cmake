INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/host_mnn/MNN/include)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/MNN/ HOST_MNN_SRC)

# link_directories(F:/VSproject/NceAlg/platform/host_mnn/MNN/lib)

set(PLATFORM_SRC 
${HOST_MNN_SRC}
) 
set(
PLATFORM_LIB
${PROJECT_SOURCE_DIR}/platform/host_mnn/MNN/libMNN.so
)
