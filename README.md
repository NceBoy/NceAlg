# NceAlg

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

### 编译HISI_3516dv300

```bash
cd NceAlg
mkdir build
cmake .. 
cmake -DCMAKE_TOOLCHAIN_FILE=./platform/hisi_3516dv300/hi3516d.cmake -DPLATFORM=hisi_3516dv300 -DOPENCVOPTION=ON -DEXE_TEST=OFF -DCMAKE_BUILD_TYPE=Debug
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



### 支持平台

|                     | Windows CPU | Windows GPU | Linux CPU | Linux GPU | 加速单元(NNIE/IPUDSP) |
| :-----------------: | :---------: | :---------: | :-------: | :-------: | :-------------------: |
| **hisi_3516_dv300** |    **/**    |    **/**    |   **/**   |   **/**   |         **✔️**         |
| **hisi_3559av100**  |    **/**    |    **/**    |   **/**   |   **/**   |         **/**         |
|     **RK3399**      |    **/**    |    **/**    |   **/**   |   **/**   |         **/**         |
|    **openvino**     |    **✔️**    |    **?**    |   **/**   |   **/**   |         **/**         |
|       **MNN**       |    **/**    |    **/**    |   **/**   |   **/**   |         **/**         |



