add_compile_options(-Wno-unused-function)
add_compile_options(-std=c++11 -fexceptions -frtti -O3)
add_compile_options(-nodefaultlibs)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/qt845_android/zdl/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface)

file(GLOB_RECURSE  PLATFORM_SRC ${PROJECT_SOURCE_DIR}/platform/qt845_android/*.c
						${PROJECT_SOURCE_DIR}/platform/qt845_android/*.cpp
						${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/qt845_android/*.cpp
						)


link_directories(${PROJECT_SOURCE_DIR}/platform/qt845_android/lib)
set(PLATFORM_LIB
-lSNPE
-lsymphony-cpu
-lEGL
-lGLESv2
-llog
# -ladsprpc
# -lcdsprpc
# -lcdsprpc_system
)