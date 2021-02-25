

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/openvino/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/openvino/common/)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/openvino_backend/ OPENVINO_SRC)

#设置hisi3516dv300所需源文件
set(PLATFORM_SRC ${OPENVINO_SRC}) 

#设置hisi3516dv300所需库文件
set(PLATFORM_LIB
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_legacy${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_c_api${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_nn_builder${CMAKE_BUILD_TYPE_POSTFIX}.lib"
)

if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/opencv_340/lib/opencv_core340${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/opencv_340/lib/opencv_highgui340${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/opencv_340/lib/opencv_imgproc340${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/opencv_340/lib/opencv_imgcodecs340${CMAKE_BUILD_TYPE_POSTFIX}.lib"
)
elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()


