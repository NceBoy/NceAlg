add_definitions(-DPLATFORM=${PLATFORM})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/openvino/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/openvino/common/)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/openvino_backend/ OPENVINO_SRC)

#设置hisi3516dv300所需源文件
set(PLATFORM_SRC ${OPENVINO_SRC}) 

#设置hisi3516dv300所需库文件
set(PLATFORM_LIB
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_legacy${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_c_api${CMAKE_BUILD_TYPE_POSTFIX}.lib"
"${PROJECT_SOURCE_DIR}/platform/openvino/lib/openvino_2020_3/lib/x64/${CMAKE_BUILD_TYPE}/static/inference_engine_nn_builder${CMAKE_BUILD_TYPE_POSTFIX}.lib"
)


