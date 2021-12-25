#!/bin/bash
###
 # @Author: your name
 # @Date: 2021-09-16 10:31:35
 # @LastEditTime: 2021-12-02 11:02:33
 # @LastEditors: Please set LastEditors
 # @Description: In User Settings Edit
 # @FilePath: \NceAlg\build.sh
### 
# 1.该行是如果出现错误，就退出脚本执行
set -e
 
# ---设置基本环境变量start---------------------
export LC_ALL=en_US.UTF-8
# 1. BASH_SOURCE[0]等价于BASH_SOURCE,取得当前脚本文件所在的路径及文件名, eg: my/src/file/build.sh
# 2. %/*代表取从头到最后一个slash之前的所有内容, eg:my/src/file
# 3. #*/代表去取从第一个slash之后的所有内容, eg: src/file/build.sh
export HOME_PATH=`cd ${BASH_SOURCE[0]%/*}; pwd`

#-----设置基本环境变量end---------------------
 
function process_param()
{
    export HELP="no"
    export PLATFORM="no"
# 1. 命令行解析
    TEMP=`getopt -o b:i:t::a::h:: --long platform::,target::,action::,help:: -n 'build.sh' -- "$@"`
# 1.这里没有执行其他脚本，所以默认都是等于0的。
# 2.文件描述符：0代表标准输入，1点标准输出，2代表标准错误
# 3.重定向符号：>, <
    if [ $? != 0 ] ; then echo "Terminating..." >&2 ; exit 1 ; fi
 
    eval set -- "$TEMP"
# 1.对每个传入的参数进行处理
    while :; do
        case "$1" in
            -i|--platform) export PLATFORM=$2; shift 2;;
            -t|--target) export TARGET=$2; shift 2;;
            -a|--action) export ACTION=$2; shift 2;;
            -b) export DEBUG=$2; shift 2;;
            -h|--help) export HELP="yes"; shift 2;;
            --) shift; break;;
            *) echo "Internal error!" ; exit 1 ;;
        esac
    done
# 1.{var:-string}:如果var为空，则用string替换; 如果var不为空，就用var替换
# 2.{var:=string}:如果var为空，则用string替换并且赋值给var; 如果var不为空，就用var替换
}
 
function prepare_env()
{
    # 1.设置工程环境变量
    export MY_CODE=`pwd`
    export MY_INTERFACE=$MY_CODE/itf
    export MY_PATH=$MY_CODE
# -z：代表如果后面$SETENV_PATH的长度为0，则为真
    if [ -z $SETENV_PATH ];then
        echo "please set setenv via --setenv-path/-s "
        exit 1
    fi
}
 
function build_project()
{
    if [ "$HELP" == "yes" ];then
        echo "=====we support platform with =========="
        echo "build.sh -i rv1126 -b Debug"
        echo "build.sh -i hisi3516dv300 -b Debug"
        echo "build.sh -i hisi3559av100 -b Debug"
        echo "build.sh -i hisi3519av100 -b Debug"
        echo "build.sh -i openvino -b Debug"
        echo "build.sh -i host -b Debug"
        echo "build.sh -i host_mnn -b Debug"
        echo "build.sh -i host_mnn_windows -b Debug"
		echo "build.sh -i qt845_android -b Debug"
    fi

    if [ "$PLATFORM" == "no" ];then
        echo "you should put -i for platform or -h for help"
	# elif [ "$PLATFORM" == "qt845_android" ];
	# then
	# 	echo "PLATFORM=$PLATFORM BUILDTYPE=$DEBUG"
	# 	rm -rf build
	# 	ANDROID_NDK=/home/video/user/yehc/sdk/android-ndk-r21/
	# 	NDK_PLATFORM=${ANDROID_NDK}/platforms/android-24/arch-arm64
	# 	cmake -Bbuild																\
	# 		  -DCMAKE_TOOLCHAIN_FILE=/home/video/user/yehc/sdk/android-ndk-r21/build/cmake/android.toolchain.cmake      \
	# 		  -DCMAKE_BUILD_TYPE=Release                                            \
	# 		  -DANDROID_FORCE_ARM_BUILD=ON                                          \
	# 		  -DANDROID_NDK=${ANDROID_NDK}                                          \
	# 		  -DANDROID_SYSROOT=${NDK_PLATFORM}                                     \
	# 		  -DANDROID_ABI="arm64-v8a"                                 			\
	# 		  -DANDROID_TOOLCHAIN=clang												\
	# 		  -DANDROID_TOOLCHAIN_NAME="aarch64-linux-android-4.9"                  \
	# 		  -DANDROID_NATIVE_API_LEVEL=android-24                                 \
	# 		  -DANDROID_STL=c++_shared                                              \
	# 		  -DPLATFORM=qt845_android
    #     cd build
    #     make                                              
    else
        rm -rf build
        echo "PLATFORM=$PLATFORM BUILDTYPE=$DEBUG"
        cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=./cmake/$PLATFORM/${PLATFORM}_toolchain.cmake -DPLATFORM=$PLATFORM  -DCMAKE_INSTALL_PREFIX=./install/ -DCMAKE_BUILD_TYPE=$DEBUG
        cd build
        make
        make install
    fi
}
function build_output()
{
	cd $HOME_PATH
if [ ! -d output_$PLATFORM ]; then
    mkdir output_$PLATFORM
fi
    cp $HOME_PATH/install/lib/* output_$PLATFORM
    cp $HOME_PATH/install/bin/* output_$PLATFORM
    cp $HOME_PATH/install/include/* output_$PLATFORM

}
process_param $*
#prepare_env
build_project
build_output

