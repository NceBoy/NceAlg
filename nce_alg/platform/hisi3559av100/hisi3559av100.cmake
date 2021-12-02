INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi3559av100/include/)

file(GLOB  PLATFORM_SRC ${PROJECT_SOURCE_DIR}/platform/hisi3559av100/drv/hisi_sdk_src/common/*.c
						${PROJECT_SOURCE_DIR}/platform/hisi3559av100/drv/hisi_sdk_src/nnie/sample/*.c
						${PROJECT_SOURCE_DIR}/platform/hisi3559av100/drv/hisi_sdk_src/nnie/sample_nnie_software/*.c
						${PROJECT_SOURCE_DIR}/alg/engine_manager/hisi_3559av100/*.cpp
						)
					 
message("${PLATFORM_SRC}")
set(PLATFORM_LIB
-ldnvqe
-lVoiceEngine
-ldsp
-live
-lmd
-lnnie
-lmpi
-lupvqe
-lsecurec
-ldl
-lpthread
-lm
)
link_directories(${PROJECT_SOURCE_DIR}/platform/hisi3559av100/lib)
SET(HISI_4096 4096.f)
