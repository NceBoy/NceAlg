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
|     **RV1126**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|    **openvino**     |    **✔️**    |    **?**    |   **/**   |   **/**   |         **/**         |
|       **MNN**       |    **/**    |    **/**    |   **/**   |   **/**   |         **/**         |

# 目录结构说明:
```
.
├── alg                                    多任务实现部分
│   ├── alg_manager                             算法任务管理层
│   │   ├── face_fake                               真伪检测
│   │   ├── hd_alg                                  人头检测
│   │   └── util                                    工具接口
│   └── engine_manager                     跨平台引擎管理层 
│       └── engine_interface
│           ├── hisi3516dv300                       hisi3516dv300 
│           ├── hisi3559av100                       hisi3559av100
│           ├── host                                 host
│           ├── openvino_backend                     openvino
│           └── rv1126                               rv1126
├── data                                   模型/图片层
│   ├── image
│   │   └── head_detect
│   └── model
│       ├── hisi3516_dv300
│       │   └── hisimodel
│       ├── openvino
│       └── rv1126
├── demo                                   示例
│   ├── hisi3516dv300
│   ├── hisi3559av100
│   ├── host
│   ├── openvino
│   └── rv1126
└── platform                               平台相关sdk/库/头文件
    ├── hisi3516dv300
    ├── hisi3559av100
    ├── host
    ├── openvino
    └── rv1126
```
# 编译运行步骤:

## 依赖下载：

### HISI_3516dv300

- 百度网盘地址：[https://pan.baidu.com/s/10BrgrOfU5dZNbzFQ7Ep7QA](https://pan.baidu.com/s/10BrgrOfU5dZNbzFQ7Ep7QA) 密码ojbk(解压后将lib放在**platform/HISI_3516dv300**目录下)
- 相关编译链
- cmake 3.11+

### openvino

- 百度网盘地址：https://pan.baidu.com/s/1Z1f6jfutojzNzoRCdxDOAQ 密码ojbk(解压后将lib放在**platform/openvino**目录下，当前版本为**2020.3**月版本)
- vs2015+
- cmake 3.11+

## 编译+运行步骤

### 编译RV_1126

```bash
cd NceAlg
cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=./platform/rv1126/rv1126.cmake -DPLATFORM=rv1126 -DOPENCVOPTION=ON -DEXE_TEST=ON -DCMAKE_BUILD_TYPE=Debug
make install
```

### 运行

在板端为LD_LIBRARY_PATH增加对应opencv动态库路径，即可运行。
### 编译HISI_3516dv300

```bash
cd NceAlg
cmake -Bbuild -DCMAKE_TOOLCHAIN_FILE=./platform/hisi3516dv300/hi3516d.cmake -DPLATFORM=hisi3516dv300 -DOPENCVOPTION=ON -DEXE_TEST=ON -DCMAKE_BUILD_TYPE=Debug
make install
```
### 运行

在板端为LD_LIBRARY_PATH增加对应opencv动态库路径，即可运行。


### 编译HISI_3559av100

```bash
cd NceAlg
mkdir build
cmake .. 
cmake -DCMAKE_TOOLCHAIN_FILE=./platform/hisi3559av100/hi3559.cmake -DPLATFORM=hisi3559av100 -DOPENCVOPTION=ON -DEXE_TEST=OFF -DCMAKE_BUILD_TYPE=Debug
make install
```

### 运行

在板端为LD_LIBRARY_PATH增加对应opencv动态库路径，即可运行。

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






