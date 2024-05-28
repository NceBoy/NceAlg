# NceAlg

<a href="https://scan.coverity.com/projects/nceboy-ncealg">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/nceboy-ncealg/badge.svg"/>
</a>

## 简介:

众所周知，如今深度学习算法在实际应用中使用得越来越多，而部署作为算法落地的最后一个环节，就显得尤为重要。算法在部署的过程中，需要先将权重转换成对应平台的模型结构，然后在相应的平台进行部署，得到最终的需求结果（例如在瑞芯微的芯片上部署 pytorch 模型，需要将模型转换成 .rknn 格式，然后使用瑞芯微的 sdk 进行部署）。现在各大平台百花齐放，且都有自己的部署流程，比如 tensorRT，MNN，NCNN，hisi，rk 等。当算法部署涉及到多个平台时，需要维护多套部署流程，对开发人员不友好。因此，我们开发了一套跨平台的神经网络部署插件 **NceAlg**，用户可以使用统一的接口在不同的平台完成深度学习算法的部署。目前 NceAlg 已经能够在海思系列、瑞芯微系列、[MNN](https://github.com/alibaba/MNN) 上成功运行多个深度学习算法，包括 [vfocal](https://arxiv.org/abs/2008.13367)、[centernet](https://arxiv.org/abs/1904.07850)、[retinaface](https://github.com/deepinsight/insightface/tree/master/detection/retinaface)、[arcface](https://github.com/deepinsight/insightface/tree/master/detection/retinaface)、[3ddfa](https://arxiv.org/abs/1804.01005) 等。使用 NceAlg 进行模型部署可以大大减少跨平台带来的工作量，真正做到一次部署，全平台适配。

### 特性介绍

- 跨平台：支持 MNN（cpu）/ 海思（nnie）/ 瑞芯微（npu）/ 星宸科技（ipu）/ 高通（dsp）等不同网络推理单元。
- 易扩展：添加平台和算法任务方便简洁
- 接口简洁统一：无论算法任务和平台差异，对外的提供统一的c/c++接口调用
- 高自由度：灵活的 yaml 配置方案，以及自定义钩子模块，能够让开发者提高自由发挥的空间。.

|                     | Windows CPU | Windows GPU | Linux CPU | Linux GPU | 加速单元(NNIE/IPUDSP) |
| :-----------------: | :---------: | :---------: | :-------: | :-------: | :-------------------: |
| **hisi3516dv300** |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3559av100**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3519av100**  |    **✔/**    |    **/**    |   **/**   |   **/**   |        **✔️**         |
| **hisi3516dv500**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi3519dv500**  |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1106**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1103**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1108**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1109**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|     **RV1126**      |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
|    **openvino**     |    **✔️**    |    **?**    |   **/**   |   **/**   |         **/**         |
|       **MNN**       |    **✔️**    |    **/**    |   **✔️**   |   **/**   |         **/**         |
| **TensorRT** | **/** | **todo** | **/** | **todo** | **✔️** |
| **openppl** | **todo** | **todo** | **todo** | **todo** | **/** |
### 效果展示

使用 NceAlg 在 hisi3516 上运行人脸检测算法 [ttf](https://arxiv.org/abs/1909.00700)

![hisi640](https://user-images.githubusercontent.com/57566630/155873273-b292a4d9-c09b-4880-ad6a-92fbcb61b82b.gif)

在 rv1126 上运行人脸识别全家桶

![rv640](https://user-images.githubusercontent.com/57566630/155873284-41e8abac-ead9-4087-9bf5-3b7cde4bd0aa.gif)

在 windows 上运行人脸识别 demo（debug）

![win640](https://user-images.githubusercontent.com/57566630/155875536-5d811e91-a176-44d9-b623-886f7bd9cdf8.gif)



## 编译运行步骤:

### 交叉编译

#### 配置工具链

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

#### 下载依赖

如果想使用 MNN 作为推理平台，需要将编译好的 MNN 库放到 nce_alg/platform/host_mnn/lib 下，也可以下载我们提供的预编译库放到对应路径下。

[MNN下载链接，提取码]()

#### 编译

```bash
build.sh -i host_mnn -b Debug
```

### windows 平台 MNN 编译

打开 vs20xx 的 本地工具的命令提示（Native tools command prompt），执行

```pow
cmake -A x64 -Bbuild -DCMAKE_TOOLCHAIN_FILE=./cmake/host_mnn_windows/host_mnn_windows.cmake -DPLATFORM=host_mnn_windows  -DCMAKE_INSTALL_PREFIX=./install/ -DCMAKE_BUILD_TYPE=Debug -DNCE_BUILD_SHARED=ON
```

即可生成 vs 工程（默认提供了 debug 版本的 MNN）。

## 使用流程

NceAlg 使用 yaml 来配置模型参数，以 retinaface 为例：

```yaml
alg_config:
    mean0: [127.5,127.5,127.5]					# 模型输入均值
    std0: [0.0078125,0.0078125,0.0078125]		# 模型输入方差
    conf_thresh: 0.6							# 检测置信度
    num_anchors: 2								# retinaface 的模型参数
    num_cls: 1
    stride_num: 5
    output_names: [logits_1, logits_2, logits_3, bboxes_1, bboxes_2, bboxes_3, landmaeks_1, landmaeks_2, landmaeks_3]
engine_config:
    model_path: D:/ccode/deeplearning/inference/NceAlg/build/out/Debug/retinaface.mnn  # 模型路径
custom_hook: 
    body_nms_hook:	# 自定义的极大值抑制
        used_func: [after_alg_get_result]
        nms_thresh: 0.3
        small_thresh: 0.92
        height_thresh: 0.9
        is_body: true
```

定义完配置文件后，我们可以通过 nce_alg_machine 的接口来完成模型的初始化、推理及后处理。具体用例参考 [demo](https://github.com/NceBoy/NceAlg/blob/master/demo/nce_alg_cpp_test.cpp)。

### 小贴士

**我们还针对嵌入式的深度学习做了一些入门的教学视频。**

链接如下：

第一期：

第二期：

第三期：

第四期：

第五期：

**我们在嵌入式上的rpc框架，也是一个通用异构框架，freak，这里暂不赘述。针对NCE_ALG插件，以及freak，有兴趣的可以加群一起学习！欢迎一起来开发维护！！**
![RDEI~24(HXD7~GT@XFHPRIT](https://user-images.githubusercontent.com/20292101/159109399-a95a6441-0fda-4d3c-af15-e0fd8193ee27.jpg)

## QQ群号：542468690

欢迎大家踊跃参与~！
