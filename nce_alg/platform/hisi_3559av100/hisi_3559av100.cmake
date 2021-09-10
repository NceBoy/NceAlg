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
