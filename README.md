# NceAlg

<a href="https://scan.coverity.com/projects/nceboy-ncealg">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/nceboy-ncealg/badge.svg"/>
</a>

## 简介:

众所周知，如今深度学习算法在实际应用中使用得越来越多，而部署作为深度学习算法落地的最后一个环节，就显得尤为重要。算法在部署的过程中，需要先将权重转换成对应平台的模型结构，然后在相应的平台进行部署，得到最终的需求结果（例如在瑞芯微的芯片上部署 pytorch 模型，需要将模型转换成 .rknn 格式，然后使用瑞芯微的 sdk 进行部署）。现在各大平台百花齐放，且都有自己的部署流程，比如 tensorRT，MNN，NCNN，hisi，rk 等。当算法部署涉及到多个平台时，需要维护多套部署流程，对开发人员不友好。因此，我们开发了一套跨平台的神经网络部署插件 **NceAlg**，用户可以使用统一的接口在不同的平台完成深度学习算法的部署。目前 NceAlg 已经能够在海思系列、瑞芯微系列、[MNN]([alibaba/MNN: MNN is a blazing fast, lightweight deep learning framework, battle-tested by business-critical use cases in Alibaba (github.com)](https://github.com/alibaba/MNN)) 上成功运行多个深度学习算法，包括 [vfocal]([[2008.13367\] VarifocalNet: An IoU-aware Dense Object Detector (arxiv.org)](https://arxiv.org/abs/2008.13367))、[centernet]([[1904.07850\] Objects as Points (arxiv.org)](https://arxiv.org/abs/1904.07850))、[retinaface]([insightface/detection/retinaface at master · deepinsight/insightface (github.com)](https://github.com/deepinsight/insightface/tree/master/detection/retinaface))、[arcface](https://github.com/deepinsight/insightface/tree/master/detection/retinaface)、[3ddfa]([[1804.01005\] Face Alignment in Full Pose Range: A 3D Total Solution (arxiv.org)](https://arxiv.org/abs/1804.01005)) 等。使用 NceAlg 进行模型部署可以大大减少跨平台带来的工作量，真正做到一次部署，全平台适配。

### 特性介绍

- 跨平台：支持 MNN（cpu）/海思（nnie）/瑞芯微（npu）/星宸科技（ipu）/高通 （dsp）等不同网络推理单元。
- 易扩展：添加平台和算法任务方便简洁
- 接口简洁统一：无论算法任务和平台差异，对外的提供统一的c/c++接口调用
- 高自由度：灵活的 yaml 配置方案，以及自定义钩子模块，能够让开发者提高自由发挥的空间。.

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
### 效果展示

使用 NceAlg 在 hisi3516 上运行人脸检测算法（[ttf]([[1909.00700\] Training-Time-Friendly Network for Real-Time Object Detection (arxiv.org)](https://arxiv.org/abs/1909.00700))）

![hisi640](https://user-images.githubusercontent.com/57566630/155873273-b292a4d9-c09b-4880-ad6a-92fbcb61b82b.gif)

在 rv1126 上运行人脸识别全家桶

![rv640](https://user-images.githubusercontent.com/57566630/155873284-41e8abac-ead9-4087-9bf5-3b7cde4bd0aa.gif)

在 windows 上运行人脸识别 demo（debug）

![win640](https://user-images.githubusercontent.com/57566630/155875536-5d811e91-a176-44d9-b623-886f7bd9cdf8.gif)



## 编译运行步骤:

### 交叉编译

#### 将工具链配置到环境变量

进入 cmake 文件夹下，将你工具链的绝对路径配置到对应平台的 xxx_toolchain.cmake 中。 

```cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR armv)
set(CMAKE_CHIP_NAME hi3519)
set(CMAKE_TOOLCHAIN_PATH  "/home/video/tools/hisi/arm-hisiv600-linux/target/bin")  # 配置成绝对路径 
set(CMAKE_CROSS_PREFIX     "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux")
set(CMAKE_C_COMPILER       "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-gcc")
set(CMAKE_CXX_COMPILER     "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-g++")
set(CMAKE_AR               "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-ar")
set(CMAKE_LINER            "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-g++")
set(CMAKE_LD               "${CMAKE_TOOLCHAIN_PATH}/arm-hisiv600-linux-ld")
```

#### 编译

不同平台的编译指令如下：

```bash
=====we support platform with ==========
build.sh -i rv1126 -b Debug
build.sh -i hisi3516dv300 -b Debug
build.sh -i hisi3559av100 -b Debug
build.sh -i hisi3519av100 -b Debug
build.sh -i openvino -b Debug
build.sh -i host -b Debug
build.sh -i host_mnn -b Debug
build.sh -i qt845_android -b Debug
you should put -i for platform or -h for help
```
-i 选择平台，-b 选择 Debug 还是 Release。

### Linux MNN 编译

如果想使用 MNN 作为推理平台，需要将编译好的 MNN 库放到 nce_alg/platform/host_mnn/lib 下，也可以下载我们提供的预编译库放到对应路径下。

[MNN下载链接，提取码]()

```bash
build.sh -i host_mnn -b Debug
```



### windows 平台 MNN 编译

#### 生成VS2019工程

- MNN平台
```bash
cmake -G "Visual Studio 16 2019" -A x64 -Bbuild -DCMAKE_TOOLCHAIN_FILE=./cmake/host_mnn_windows/host_mnn_windows.cmake -DPLATFORM=host_mnn_windows  -DCMAKE_INSTALL_PREFIX=./install/ -DCMAKE_BUILD_TYPE=Debug -DNCE_BUILD_SHARED=ON
```





