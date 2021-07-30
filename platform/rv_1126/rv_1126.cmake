

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Os")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Os")
SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/inc/")
SET(HISI_4096 1.0f)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/rv_1126/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/rv_1126/)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/rv1126/ ENGINE_RV1126_SRC)



#设置hisi3516dv300所需源文件
set(PLATFORM_SRC 
${ENGINE_RV1126_SRC}) 

#设置hisi3516dv300所需库文件
set(PLATFORM_LIB
-lrknn_api
-ldl
-lpthread
-lm
-lrt
)

if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
-lopencv_calib3d
-lopencv_core
-lopencv_features2d
-lopencv_imgproc
-lopencv_imgcodecs
-lzlib
-llibwebp
-llibpng
-llibjpeg-turbo
-llibjasper
-lIlmImf
-ltegra_hal
-llibtiff)
elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()

link_directories(${PROJECT_SOURCE_DIR}/platform/rv_1126/lib)
