#include "DlSystem/DlError.hpp"
#include "DlSystem/RuntimeList.hpp"

#include "DlSystem/UserBufferMap.hpp"
#include "DlSystem/UDLFunc.hpp"
#include "DlSystem/IUserBuffer.hpp"
#include "DlSystem/IUserBufferFactory.hpp"
#include "DlSystem/ITensorFactory.hpp"
#include "DlSystem/PlatformConfig.hpp"
#include "DlContainer/IDlContainer.hpp"

#include "SNPE/SNPEBuilder.hpp"
#include "SNPE/SNPE.hpp"
#include "SNPE/SNPEFactory.hpp"

#include "qt845_android/snpe.hpp"
#include "udlExample.hpp"
#include <map>
#include <assert.h>

namespace nce_alg {

class SNPE_engine::engine_priv
{
public:
    engine_priv()
    {
        printf("snpe engine priv create!\n");
        _inputTensorMap  = std::unique_ptr<zdl::DlSystem::TensorMap>(new zdl::DlSystem::TensorMap);
        _outputTensorMap = std::unique_ptr<zdl::DlSystem::TensorMap>(new zdl::DlSystem::TensorMap);
    };

    ~engine_priv()
    {
        for (auto &kv : _output_map)
        {
            if (nullptr != kv.second)
            {
                delete kv.second;
                printf("delete output: %s", kv.first.c_str());
            }
            else
            {
                printf("output cannot be delete twice!!\n");
                assert(false);
            }
        }

        for (auto &k : _input_mid_datas)
        {
            if (nullptr != k)
            {
                delete k;
            }
        }
        printf("engine_priv deinit!\n");
    }

    std::unique_ptr<zdl::DlContainer::IDlContainer> loadContainerFromFile(const char *dlc_file)
    {
        std::unique_ptr<zdl::DlContainer::IDlContainer> container;
        container = zdl::DlContainer::IDlContainer::open(zdl::DlSystem::String(dlc_file));
        if (nullptr == container.get())
        {
            printf("load dlc file failed!\n");
            assert(false);
        }
        return container;
    }

    NCE_S32 load_model(const param_info &                     st_param_info,
                       vector<input_tensor_info> &            st_tensor_infos,
                       LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        zdl::DlSystem::UDLBundle      udlBundle;
        zdl::DlSystem::Runtime_t      runtime;
        zdl::DlSystem::PlatformConfig platformConfig;
        zdl::DlSystem::RuntimeList    runtimeList;

        _container                            = loadContainerFromFile(st_param_info.pc_model_path);
        zdl::DlSystem::UDLFactoryFunc udlFunc = UdlExample::MyUDLFactory;
        udlBundle.cookie                      = (void *)0xdeadbeaf;
        udlBundle.func                        = udlFunc; // 0xdeadbeaf to test cookie
        bool useUserSuppliedBuffers           = st_param_info.st_engine_info.snpe_param.useUserSuppliedBuffers;
        bool usingInitCaching                 = st_param_info.st_engine_info.snpe_param.usingInitCaching;

        if (0 == strcmp("DSP", st_param_info.st_engine_info.snpe_param.device_name))
        {
            runtime = zdl::DlSystem::Runtime_t::DSP;
        }
        else if (0 == strcmp("CPU", st_param_info.st_engine_info.snpe_param.device_name))
        {
            runtime = zdl::DlSystem::Runtime_t::CPU;
        }
        else if (0 == strcmp("GPU", st_param_info.st_engine_info.snpe_param.device_name))
        {
            runtime = zdl::DlSystem::Runtime_t::GPU;
        }

        runtimeList.clear();

        if (true != runtimeList.add(runtime))
        {
            printf("snpe runtime list add error!!\n");
        }

        _init_snpe_builder(st_result_map,
                           _container,
                           runtime,
                           runtimeList,
                           udlBundle,
                           useUserSuppliedBuffers,
                           platformConfig,
                           usingInitCaching);
        if (nullptr == _snpe)
        {
            printf("failed to init snpe\n");
            return NCE_FAILED;
        }

        const auto &strList_opt = _snpe->getInputTensorNames();
        if (!strList_opt)
        {
            printf("Get input tensor name failed!!\n");
            return NCE_FAILED;
        }

        NCE_S32     count   = 0;
        const auto &strList = *strList_opt;
        for (auto &kv : strList)
        {
            const auto &inputDims_opt = _snpe->getInputDimensions(kv);
            const auto &inputDims     = *inputDims_opt;
            printf("Get input tensor name: %s N: %ld C: %ld H: %ld W:%ld\n",
                   kv,
                   inputDims[0],
                   inputDims[3],
                   inputDims[1],
                   inputDims[2]);
            _input_names.push_back(kv);
            auto tmp_tensor = zdl::SNPE::SNPEFactory::getTensorFactory().createTensor(inputDims);
            _input_tensors.push_back(std::move(tmp_tensor));
            _inputTensorMap->add(kv, _input_tensors[count].get());

            _input_mid_datas.push_back(new NCE_F32[inputDims[1] * inputDims[2] * inputDims[3]]);

            st_tensor_infos[count].width   = inputDims[2];
            st_tensor_infos[count].height  = inputDims[1];
            st_tensor_infos[count].channel = inputDims[3];
            st_tensor_infos[count].format  = PACKAGE;
            st_tensor_infos[count].name    = kv;
            std::copy(st_tensor_infos[count].mean, st_tensor_infos[count].mean + 3, _input_means[count]);
            std::copy(st_tensor_infos[count].std, st_tensor_infos[count].std + 3, _input_stds[count]);
            count++;
        }

        printf("start pre excute!!\n");
        if (true != _snpe->execute(*_inputTensorMap, *_outputTensorMap))
        {
            printf("snpe pre excute failed!!\n");
        }
        printf("finished pre excute!!\n");

        for (auto &kv : st_result_map)
        {
            auto output_shape = _outputTensorMap->getTensor(kv.c_str())->getShape();
            printf("Get output tensor name: %s N: %ld C: %ld H: %ld W:%ld\n",
                   kv.c_str(),
                   output_shape[0],
                   output_shape[3],
                   output_shape[1],
                   output_shape[2]);
            _output_names.push_back(kv);
            _output_map[kv] = new NCE_F32[output_shape[1] * output_shape[2] * output_shape[3]];

            st_result_map[kv].tensor.channel_stride = 1;
            st_result_map[kv].tensor.height_stride  = output_shape[3] * output_shape[2];
            st_result_map[kv].tensor.width_stride   = output_shape[3];
            st_result_map[kv].tensor.outfmt         = PACKAGE;
            st_result_map[kv].tensor.u32ch          = output_shape[3];
            st_result_map[kv].tensor.u32FeatHeight  = output_shape[1];
            st_result_map[kv].tensor.u32FeatWidth   = output_shape[2];
            st_result_map[kv].tensor.name           = kv;
        }

        return NCE_SUCCESS;
    }

    NCE_S32 inference(vector<img_t> &imgs)
    {
        // TODO sequence of input img is unknown!

        NCE_S32 count = 0;
        for (auto &kv : _input_names)
        {
            auto    img          = imgs[count].image;
            auto    tmp_tensor   = _inputTensorMap->getTensor(kv.c_str());
            auto    tensor_shape = tmp_tensor->getShape();
            NCE_S32 height       = tensor_shape[1];
            NCE_S32 width        = tensor_shape[2];
            NCE_S32 channel      = tensor_shape[3];

            auto     iter     = tmp_tensor->begin();
            NCE_F32 *mid_data = _input_mid_datas[count];
            auto     num_ele  = height * width * channel;

            for (NCE_S32 i = 0; i < num_ele; i++)
            {
                NCE_S32 c       = i % channel;
                NCE_F32 p       = ((NCE_F32)img[i] - _input_means[count][c]) * _input_stds[count][c];
                *(mid_data + i) = p;
            }
            count++;
            std::copy(mid_data, mid_data + num_ele, iter);
        }
        if (true != _snpe->execute(*_inputTensorMap, *_outputTensorMap))
        {
            printf("snpe excute failed!\n");
            return NCE_FAILED;
        }
        return NCE_SUCCESS;
    }

    NCE_S32 get_results(LinkedHashMap<string, tmp_map_result> &st_engine_result)
    {
        for (auto &kv : st_engine_result)
        {
            auto    tmp_tensor   = _outputTensorMap->getTensor(kv.c_str());
            auto    tensor_shape = tmp_tensor->getShape();
            NCE_S32 height       = tensor_shape[1];
            NCE_S32 width        = tensor_shape[2];
            NCE_S32 channel      = tensor_shape[3];

            auto batch_chunk = height * width * channel;
            std::copy(tmp_tensor->begin(), tmp_tensor->begin() + batch_chunk, _output_map[kv]);
            st_engine_result[kv].pu32Feat = (NCE_S32 *)_output_map[kv];
        }
        return NCE_SUCCESS;
    }

private:
    std::unique_ptr<zdl::DlContainer::IDlContainer>      _container;
    std::unique_ptr<zdl::SNPE::SNPE>                     _snpe;
    std::unique_ptr<zdl::DlSystem::TensorMap>            _outputTensorMap;
    std::unique_ptr<zdl::DlSystem::TensorMap>            _inputTensorMap;
    std::vector<std::string>                             _input_names;
    std::vector<std::string>                             _output_names;
    std::vector<std::unique_ptr<zdl::DlSystem::ITensor>> _input_tensors;
    NCE_F32                                              _input_means[10][3];
    NCE_F32                                              _input_stds[10][3];
    std::vector<NCE_F32 *>                               _input_mid_datas;

    std::map<std::string, NCE_F32 *> _output_map;

    NCE_S32
    _init_snpe_builder(LinkedHashMap<string, tmp_map_result>            tmp_result_map,
                       std::unique_ptr<zdl::DlContainer::IDlContainer> &container,
                       zdl::DlSystem::Runtime_t                         runtime,
                       zdl::DlSystem::RuntimeList                       runtimeList,
                       zdl::DlSystem::UDLBundle                         udlBundle,
                       bool                                             useUserSuppliedBuffers,
                       zdl::DlSystem::PlatformConfig                    platformConfig,
                       bool                                             useCaching)
    {
        zdl::SNPE::SNPEBuilder    snpeBuilder(container.get());
        zdl::DlSystem::StringList output_layer_names;

        if (runtimeList.empty())
        {
            runtimeList.add(runtime);
        }

        for (auto &kv : tmp_result_map)
        {
            output_layer_names.append(kv.c_str());
        }

        _snpe = snpeBuilder /*.setOutputLayers(output_layer_names)*/
                    .setOutputTensors(output_layer_names)
                    .setRuntimeProcessorOrder(runtimeList)
                    .setUdlBundle(udlBundle)
                    .setUseUserSuppliedBuffers(useUserSuppliedBuffers)
                    .setPlatformConfig(platformConfig)
                    .setInitCacheMode(useCaching)
                    .build();

        return NCE_SUCCESS;
    }
};

SNPE_engine::SNPE_engine()
{
    pPriv = std::shared_ptr<engine_priv>(new engine_priv());
};

NCE_S32 SNPE_engine::engine_init(const param_info &                     st_param_info,
                                 vector<input_tensor_info> &            st_tensor_infos,
                                 LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    if (NCE_SUCCESS != pPriv->load_model(st_param_info, st_tensor_infos, st_result_map))
    {
        printf("engine load model failed!\n");
        return NCE_FAILED;
    };

    return NCE_SUCCESS;
};

NCE_S32 SNPE_engine::engine_inference(vector<img_t> &pc_imgs)
{
    if (NCE_SUCCESS != pPriv->inference(pc_imgs))
    {
        printf("snpe inference failed!\n");
    };
    return NCE_SUCCESS;
}

NCE_S32 SNPE_engine::engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
{
    if (NCE_SUCCESS != pPriv->get_results(st_engine_result))
    {
        printf("snpe get result failed!\n");
        return NCE_FAILED;
    };
    return NCE_FAILED;
}

NCE_S32 SNPE_engine::engine_destroy()
{
    printf("snpe delete successful\n");
    return NCE_SUCCESS;
}

} // namespace nce_alg
