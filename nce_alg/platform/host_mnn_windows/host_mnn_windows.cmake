INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/platform/host_mnn/MNN/include)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/alg/engine_manager/engine_interface/MNN/ HOST_MNN_SRC)

# link_directories(F:/VSproject/NceAlg/platform/host_mnn/MNN/lib)

set(PLATFORM_SRC 
${HOST_MNN_SRC}
) 
set(
PLATFORM_LIB
${PROJECT_SOURCE_DIR}/platform/host_mnn_windows/MNN/lib/MNN.lib
)


file(WRITE "${PROJECT_SOURCE_DIR}/../build_host_mnn/demo/nce_alg_test_common.vcxproj.user" [=[
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="Current" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <LocalDebuggerEnvironment>PATH=..\..\nce_alg\platform\host_mnn_windows\MNN\lib;..\..\lib\Debug</LocalDebuggerEnvironment>
    <DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>
  </PropertyGroup>
</Project>
]=])
