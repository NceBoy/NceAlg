/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 11:15:00
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-09-06 15:47:40
 */

#include "MNN_backend.hpp"
#include "MNN/Interpreter.hpp"
#include <MNN/ImageProcess.hpp>
#include <memory>

namespace nce_alg {

class MNN_engine::engine_priv
{
public:
    typedef struct TagMNNTensorUion
    {
    public:
        std::map<std::string, MNN::Tensor *> input_tensors_map; /*tensor in net should not be managed by us*/
        std::map<std::string, MNN::Tensor *> output_tensors_map_host;
        std::map<std::string, MNN::Tensor *> output_tensors_map;

        ~TagMNNTensorUion()
        {
            for (auto &kv : output_tensors_map_host)
            {
                if (kv.second != nullptr)
                {
                    delete kv.second;
                    kv.second = nullptr;
                }
            }
        }
    } MNNTensorUnion;

    engine_priv()
    {
        printf("successful create engine_priv\n");
    }

    ~engine_priv()
    {
        pnet->releaseSession(psession);
        pnet->releaseModel();
    }

private:
    MNN::ScheduleConfig                   schedue_config;
    vector<MNN::CV::ImageProcess::Config> configs;
    MNN::Session *                        psession;
    MNNTensorUnion                        all_tensor;

    MNN::Interpreter *              pnet;
    vector<MNN::CV::ImageProcess *> pprocessors;
    // std::unique_ptr<MNN::Interpreter>        pnet;
    // std::unique_ptr<MNN::CV::ImageProcess>   pprocessor;

    NCE_S32 model_channel;

public:
    NCE_S32
    load_model(const char *               model_path,
               map<int, tmp_map_result> & st_result_map,
               vector<input_tensor_info> &st_tensor_infos)
    {
        // pnet          = unique_ptr<MNN::Interpreter>(MNN::Interpreter::createFromFile(model_path));
        pnet     = MNN::Interpreter::createFromFile(model_path);
        psession = pnet->createSession(schedue_config);

        all_tensor.input_tensors_map  = pnet->getSessionInputAll(psession);
        all_tensor.output_tensors_map = pnet->getSessionOutputAll(psession);
        // TODO Ugly and useless code!!! must be removed
        NCE_S32                       count = 0;
        MNN::CV::ImageProcess::Config tmp_config;
        for (auto &kv : all_tensor.input_tensors_map)
        {
            std::string  name    = kv.first;
            MNN::Tensor *pTensor = kv.second;
            auto         shape   = pTensor->shape();

            printf("input[%d] name is: %s\n", count, name.c_str());
            st_tensor_infos[count].channel = shape[1];
            st_tensor_infos[count].height  = shape[2];
            st_tensor_infos[count].width   = shape[3];
            st_tensor_infos[count].format  = PACKAGE;
            st_tensor_infos[count].name    = name;

            tmp_config.sourceFormat = MNN::CV::RGB;
            tmp_config.destFormat   = MNN::CV::RGB;
            memcpy(tmp_config.mean, st_tensor_infos[count].mean, sizeof(NCE_F32) * 3);
            memcpy(tmp_config.normal, st_tensor_infos[count].std, sizeof(NCE_F32) * 3);
            pprocessors.push_back(MNN::CV::ImageProcess::create(tmp_config));
            count++;
        }

        count = 0;
        for (auto &kv : all_tensor.output_tensors_map)
        {
            std::string  name                        = kv.first;
            MNN::Tensor *pTensor                     = kv.second;
            auto         shape                       = pTensor->shape();
            all_tensor.output_tensors_map_host[name] = new MNN::Tensor(pTensor, pTensor->getDimensionType());
            printf("st_result_map[%d] name is: %s\n", count, name.c_str());
            st_result_map[count].tensor.name          = name;
            st_result_map[count].tensor.outfmt        = PLANNER;
            st_result_map[count].tensor.scale         = 1;
            st_result_map[count].tensor.u32ch         = shape[1];
            st_result_map[count].tensor.u32FeatHeight = shape[2];
            st_result_map[count].tensor.u32FeatWidth  = shape[3];
            st_result_map[count].tensor.u32Stride     = shape[3];
            st_result_map[count].tensor.zp            = 0;

            count++;
        }

        // pprocessor = unique_ptr<MNN::CV::ImageProcess>(MNN::CV::ImageProcess::create());

        return NCE_SUCCESS;
    }

    NCE_S32 inference(vector<img_t> &image_datas)
    {
        printf("start inference\n");
        NCE_S32 count = 0;
        for (auto &kv : all_tensor.input_tensors_map)
        {
            printf("start convert, model_width: %d model_height: %d\n");
            pprocessors[count]->convert(image_datas[count].image,
                                        image_datas[count].image_attr.u32Width,
                                        image_datas[count].image_attr.u32Height,
                                        0,
                                        kv.second);
            printf("finish convert\n");
            count++;
        }
        pnet->runSession(psession);
        printf("finish inference\n");
        return NCE_SUCCESS;
    }

    NCE_S32 get_result(map<int, tmp_map_result> &st_engine_result)
    {
        printf("start get result\n");
        for (auto &kv : st_engine_result)
        {
            std::string  name            = kv.second.tensor.name;
            MNN::Tensor *tmp_output      = all_tensor.output_tensors_map[name];
            MNN::Tensor *tmp_output_host = all_tensor.output_tensors_map_host[name];
            printf("st_engine_resul name is: %s\n", name.c_str());
            tmp_output->copyToHostTensor(tmp_output_host);
            kv.second.pu32Feat = tmp_output_host->host<NCE_S32>();
        }
        return NCE_SUCCESS;
    }
};

MNN_engine::MNN_engine()
{
    pPriv = shared_ptr<engine_priv>(new engine_priv());
}

NCE_S32
MNN_engine::engine_init(const param_info &         st_param_info,
                        vector<input_tensor_info> &st_tensor_infos,
                        map<int, tmp_map_result> & st_result_map)
{
    // TODO support multi-image input, assert input and model dimension
    pPriv->load_model(st_param_info.pc_model_path, st_result_map, st_tensor_infos);
    return NCE_SUCCESS;
}

NCE_S32 MNN_engine::engine_inference(vector<img_t> &pc_img)
{
    pPriv->inference(pc_img);
    return NCE_SUCCESS;
}

NCE_S32 MNN_engine::engine_get_result(map<int, tmp_map_result> &st_engine_result)
{
    pPriv->get_result(st_engine_result);
    return NCE_SUCCESS;
}

NCE_S32 MNN_engine::engine_destroy()
{
    printf("successful engine destroy");
    return NCE_SUCCESS;
}
} // namespace nce_alg