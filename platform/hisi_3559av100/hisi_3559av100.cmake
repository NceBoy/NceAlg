INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_inc/
					${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/common/
					${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/nnie/sample/
					${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/nnie/sample_nnie_software/
					(${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/opencv/)
					)

file(GLOB  PLATFORM_SRC ${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/common/*.c
						${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/nnie/sample/*.c
						${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/drv/hisi_sdk_src/nnie/sample_nnie_software/*.c
						${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/hisi_3559av100/*.cpp
						)
					 
message("${PLATFORM_SRC}")


SET(HISI_4096 4096.f)
if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
"${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/opencv/libopencv_core.so"
"${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/opencv/libopencv_highgui.so"
"${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/opencv/libopencv_imgproc.so"
"${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/opencv/libopencv_imgcodecs.so"
"${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/opencv/libopencv_videoio.so.3.4"
)

file (GLOB_RECURSE PLATFORM_LIB ${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/hisi/*.so ${PROJECT_SOURCE_DIR}/platform/hisi_3559av100/lib/hisi/*.a)


elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()
