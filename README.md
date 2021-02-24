# cmake指令

```shell
mkdir build && cd build && cmake .. -G "Visual Studio 14 2015 Win64" -DPLATFORM=openvino -DOPENCVOPTION=ON -DEXE_TEST=ON -DCMAKE_BUILD_TYPE=Release
```

# 注意事项：

### 1.Openvino东静态库位于

```shell
home\NceAlg\platform\openvino\lib
```

### 目前未添加x86的库，以release为例，运行时需要配置PATH环境变量：

```
NceAlg\platform\openvino\lib\x64\Release\dynamic
```

### 2.Openvino下的opencv时x64环境3.4.0的完整opencv，build目录下的opencv是当前工程所需的dll

### 3.Openvino的库放在build路径下，程序无法加载MKLDNNPlugind.dll（Debug）这个库


hisi

cmake -Bbuild1 -DCMAKE_TOOLCHAIN_FILE=./platform/hisi_3516dv300/hi3516d.cmake -DPLATFORM=hisi_3516dv300 -DOPENCVOPTION=ON -DEXE_TEST=OFF -DCMAKE_BUILD_TYPE=Debug



TODO:
写一个不依赖opencv的BGR2RGB，方便测试。



