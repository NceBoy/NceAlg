# NceAlg

<a href="https://scan.coverity.com/projects/nceboy-ncealg">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/nceboy-ncealg/badge.svg"/>
</a>

# 介绍:
这是一套跨平台的异构算法框架
- 跨平台：支持x64/hisi(nnie)/rk(npu)/ipu/dsp等不同网络推理单元。
- 易扩展：添加平台和算法任务方便简洁
- 接口简洁统一：无论算法任务和平台差异，对外的提供统一的c/c++接口调用
### 支持平台

|                     | Windows CPU | Windows GPU | Linux CPU | Linux GPU | 加速单元(NNIE/IPUDSP) |
| :-----------------: | :---------: | :---------: | :-------: | :-------: | :-------------------: |
| **hisi_3516_dv300** |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3559av100**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3199av100**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1126**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|    **openvino**     |    **✔️**    |    **?**    |   **/**   |   **/**   |         **/**         |
|       **MNN**       |    **✔️**    |    **/**    |   **✔️**   |   **/**   |         **/**         |

# 目录结构说明:
```
.
├── cmake
│   ├── hisi3516dv300
│   ├── hisi3519av100
│   ├── hisi3559av100
│   ├── host
│   ├── host_mnn
│   ├── openvino
│   └── rv1126
├── demo
│   ├── data
│   │   ├── image
│   │   │   └── head_detect
│   │   └── model
│   │       ├── hisi3516_dv300
│   │       ├── openvino
│   │       └── rv_1126
│   ├── hisi3516dv300
│   │   └── include
│   ├── hisi3519av100
│   ├── hisi3559av100
│   ├── host
│   ├── host_mnn
│   ├── host_mnn_windows
│   ├── inc
│   ├── openvino
│   └── rv1126
└── nce_alg
    ├── alg
    │   ├── alg_manager
    │   │   ├── body_detect
    │   │   ├── face_fake
    │   │   ├── hd_alg
    │   │   └── util
    │   └── engine_manager
    │       └── engine_interface
    │           ├── hisi_3516dv300
    │           ├── hisi_3559av100
    │           ├── host
    │           ├── MNN
    │           ├── openvino_backend
    │           └── rv1126
    ├── common
    └── platform
        ├── hisi3516dv300
        │   ├── audio
        │   ├── common
        │   ├── common_sys
        │   ├── include
        │   ├── lib
        │   ├── rtsp-v2
        │   ├── sample_nnie_software
        │   └── tools
        ├── hisi3519av100
        │   └── MNN
        │       └── include
        │           └── MNN
        │               ├── expr
        │               └── plugin
        ├── hisi3559av100
        │   └── drv
        │       ├── hisi_sdk_inc
        │       └── hisi_sdk_src
        │           ├── common
        │           └── nnie
        │               ├── sample
        │               └── sample_nnie_software
        ├── host
        ├── host_mnn
        │   └── MNN
        │       └── include
        │           └── MNN
        │               ├── expr
        │               └── plugin
        ├── host_mnn_windows
        ├── openvino
        │   ├── builders
        │   ├── c_api
        │   ├── cldnn
        │   ├── cpp
        │   ├── details
        │   │   └── os
        │   ├── gna
        │   ├── gpu
        │   │   └── details
        │   ├── hetero
        │   ├── multi-device
        │   ├── os
        │   │   └── windows
        │   ├── samples
        │   └── vpu
        └── rv1126
            ├── include
            └── lib
```
# 编译运行步骤:

## 依赖下载：

### HISI_3516dv300

### openvino


## 编译+运行步骤
### linux
### 编译

```bash
cd NceAlg
./build.sh -i host -b Debug
make install
```
- 对于支持的多平台可以通过 ./build.sh -h 查看
### windows

### 生成openvinoVS工程

```bash
cd NceAlg
mkdir build
cmake ..
cmake .. -G "Visual Studio 14 2015 Win64" -DPLATFORM=openvino -DOPENCVOPTION=ON -DEXE_TEST=ON -DCMAKE_BUILD_TYPE=Debug#或者release
```

### 运行

将以下openvino的动态库路径配置到windows环境变量中

```bash
${工程路径}/NceAlg_cjy/NceAlg/platform/openvino/lib/openvino_2020_3/lib/x64/Debug
${工程路径}/NceAlg_cjy/NceAlg/platform/openvino/lib/openvino_2020_3/lib/x64/Release
${工程路径}/NceAlg_cjy/NceAlg/platform/opencv_340/bin
```

本地有opencv的话可以使用本地opencv。配置环境在VS工程中完成编译，并传参运行。






