INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/host_mnn/MNN/include)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/MNN/ HOST_MNN_SRC)

set(PLATFORM_SRC 
${HOST_MNN_SRC}
) 
if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
-lopencv_core
-lopencv_highgui
-lopencv_imgproc
-lopencv_imgcodecs)
elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()
