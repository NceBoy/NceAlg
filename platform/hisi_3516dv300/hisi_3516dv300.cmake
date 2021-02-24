add_definitions(-DPLATFORM=${PLATFORM})

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Os")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Os")
SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/inc/")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/common/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/common_sys/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/sample_nnie_software/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/include/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/rtsp-v2/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/audio/)

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/hisi_3516dv300/ ENGINE_3516DV300_SRC)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/sample_nnie_software/ NNIE_SRC)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/common/ COMMON_SRC)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/common_sys/ COMMON_SYS_SRC)

#设置hisi3516dv300所需源文件
set(PLATFORM_SRC 
${ENGINE_3516DV300_SRC}
${NNIE_SRC} 
${COMMON_SRC}) 

#设置hisi3516dv300所需库文件
set(PLATFORM_LIB
-ldnvqe
-lVoiceEngine
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

if(OPENCVOPTION MATCHES "ON")
SET(OPENCV_LIB
-lopencv_core
-lopencv_highgui
-lopencv_imgproc
-lopencv_imgcodecs)
elseif(OPENCVOPTION MATCHES "OFF")
SET(OPENCV_LIB "")
endif()

link_directories(${PROJECT_SOURCE_DIR}/platform/hisi_3516dv300/lib)
link_directories("/home/cjyvm2/3516rootfs/rootfs/lib/")
link_directories("/home/cjyvm2/3516rootfs/rootfs/usr/lib")
