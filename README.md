# NceAlg

<a href="https://scan.coverity.com/projects/nceboy-ncealg">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/nceboy-ncealg/badge.svg"/>
</a>

# 介绍:
这是一套跨平台的异构算法框架
- 跨平台：支持x64、cpu(MNN)/hisi(nnie)/rk(npu)/ipu/dsp/gpu等不同网络推理单元。
- 易扩展：添加平台和算法任务方便简洁
- 接口简洁统一：无论算法任务和平台差异，对外的提供统一的c/c++接口调用
- 高自由度：灵活的yaml配置方案，以及自定义钩子模块，能够让开发者提高自由发挥的空间。
### 支持平台

|                     | Windows CPU | Windows GPU | Linux CPU | Linux GPU | 加速单元(NNIE/IPUDSP) |
| :-----------------: | :---------: | :---------: | :-------: | :-------: | :-------------------: |
| **hisi3516dv300** |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3559av100**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3519av100**  |    **✔️**    |    **/**    |   **/**   |   **/**   |         **/**         |
|     **RV1126**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|    **openvino**     |    **✔️**    |    **?**    |   **/**   |   **/**   |         **/**         |
|       **MNN**       |    **✔️**    |    **/**    |   **✔️**   |   **/**   |         **/**         |
| **TensorRT** | **/** | **todo** | **/** | **todo** | **/** |
| **openppl** | **todo** | **todo** | **todo** | **todo** | **/** |
# 目录结构说明:
```
.
├── cmake
│   ├── hisi3516dv300
│   ├── hisi3519av100
│   ├── hisi3559av100
│   ├── host
│   ├── host_mnn
│   ├── host_mnn_windows
│   ├── openvino
│   └── rv1126
├── demo
│   └── data
│       ├── config
│       ├── image
│       │   └── head_detect
│       └── model
│           ├── hisi3516_dv300
│           ├── hisi3559av100
│           ├── openvino
│           └── rv_1126
├── install
│   ├── bin
│   ├── include
│   └── lib
├── nce_alg
│   ├── alg
│   │   ├── alg_manager
│   │   │   ├── centernet
│   │   │   ├── face_fake
│   │   │   ├── ttf
│   │   │   ├── util
│   │   │   └── vfnet
│   │   ├── core
│   │   ├── engine_manager
│   │   │   ├── engine_closed_source
│   │   │   ├── hisi_3516dv300
│   │   │   ├── hisi_3559av100
│   │   │   ├── host
│   │   │   ├── MNN
│   │   │   ├── openvino_backend
│   │   │   └── rv1126
│   │   └── hook_manager
│   │       ├── keep_upper_bbox
│   │       ├── nms_hook
│   │       ├── reflection_filter_hook
│   │       └── softmax_hook
│   ├── common
│   ├── include
│   ├── platform
│   │   ├── hisi3516dv300
│   │   │   ├── audio
│   │   │   ├── common
│   │   │   ├── common_sys
│   │   │   ├── include
│   │   │   ├── lib
│   │   │   ├── rtsp-v2
│   │   │   ├── sample_nnie_software
│   │   │   └── tools
│   │   ├── hisi3519av100
│   │   │   └── MNN
│   │   │       └── include
│   │   │           └── MNN
│   │   │               ├── expr
│   │   │               └── plugin
│   │   ├── hisi3559av100
│   │   │   ├── drv
│   │   │   │   └── hisi_sdk_src
│   │   │   │       ├── common
│   │   │   │       └── nnie
│   │   │   │           ├── sample
│   │   │   │           └── sample_nnie_software
│   │   │   ├── include
│   │   │   └── lib
│   │   ├── host
│   │   ├── host_mnn
│   │   │   └── MNN
│   │   │       └── include
│   │   │           └── MNN
│   │   │               ├── expr
│   │   │               └── plugin
│   │   ├── host_mnn_windows
│   │   │   └── MNN
│   │   │       ├── include
│   │   │       │   └── MNN
│   │   │       │       ├── expr
│   │   │       │       └── plugin
│   │   │       └── lib
│   │   ├── openvino
│   │   │   ├── builders
│   │   │   ├── c_api
│   │   │   ├── cldnn
│   │   │   ├── cpp
│   │   │   ├── details
│   │   │   │   └── os
│   │   │   ├── gna
│   │   │   ├── gpu
│   │   │   │   └── details
│   │   │   ├── hetero
│   │   │   ├── multi-device
│   │   │   ├── os
│   │   │   │   └── windows
│   │   │   ├── samples
│   │   │   └── vpu
│   │   └── rv1126
│   │       ├── include
│   │       └── lib
│   └── StanfordCPPLib
└── third-party
    ├── modules
    └── yaml

112 directories
```
# 编译运行步骤:

## 依赖下载：




## 编译+运行步骤
### linux
### 编译

```bash
cd NceAlg
./build.sh -i host -b Debug
make install
```
- 对于支持的多平台可以通过 ./build.sh -h 查看，如果无法执行，可能是格式问题. vi打开build.sh,输入：set ff=unix 并保存即可。
- -i选择平台，-b选择Debug还是Release
### windows

### 生成VS2019工程

- MNN平台
```bash
cmake -G "Visual Studio 16 2019" -A x64 -Bbuild -DCMAKE_TOOLCHAIN_FILE=./cmake/host_mnn_windows/host_mnn_windows.cmake -DPLATFORM=host_mnn_windows  -DCMAKE_INSTALL_PREFIX=./install/ -DCMAKE_BUILD_TYPE=Debug -DNCE_BUILD_SHARED=ON
```





