#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include "alg_type.h"
#include "rv1126_engine.hpp"
#include "rknn_api.h"
#include "rv1126_tool.hpp"
#define NO_ZERO_MAP 0
using namespace std;
namespace nce_alg {

class rv1126_engine::engine_priv
{
public:
    NCE_U8 *                pModel;
    void *                  drm_buf;
    NCE_S32                 model_len;
    rknn_context            ctx;
    rknn_input_output_num   io_num;
    vector<rknn_tensor_mem> inmem;
    vector<rknn_input>      inputs;
    vector<rknn_output>     outputs; // TODO 这里是因为result传出去的是指针，那内存不能直接销毁，其他平台的*feat 例如海思
                                 // 是海思自己申请 自己维护的。 我们这里也要自己维护
    vector<rknn_tensor_attr> input_attrs;
    NCE_S32                  drm_fd;
    drm_context              drm_ctx;
    vector<NCE_U32>          u32Strides;
    vector<NCE_U32>          u32Chs;
    vector<NCE_U32>          u32Heights;
    vector<NCE_U32>          u32Widths;

    vector<NCE_U32> u32OutStrides;
    vector<NCE_U32> u32OutChs;
    vector<NCE_U32> u32OutHeights;
    vector<NCE_U32> u32OutWidths;

    engine_priv()
    {
        drm_fd = -1;
        printf("successful create engine_priv");
    }

    NCE_S32 package2planner(NCE_U8 *InputImage, NCE_U8 *OutputImage, NCE_U32 hh, NCE_U32 ww, NCE_U32 cc)
    //"Only used for rgb_package image"
    {
        NCE_U32 ImageSize = hh * ww;
        for (NCE_U32 c = 0; c < cc; c++)
        {
            for (NCE_U32 h = 0; h < hh; h++)
            {
                for (NCE_U32 w = 0; w < ww; w++)
                {
                    OutputImage[c * ImageSize + h * ww + w] = InputImage[(h * hh + w) * cc + c];
                }
            }
        }
        return NCE_SUCCESS;
    }
    void printRKNNTensor(rknn_tensor_attr *attr)
    {
        printf("index=%d name=%s n_dims=%d dims=[%d %d %d %d] n_elems=%d size=%d fmt=%d type=%d qnt_type=%d fl=%d "
               "zp=%d scale=%f\n",
               attr->index,
               attr->name,
               attr->n_dims,
               attr->dims[3],
               attr->dims[2],
               attr->dims[1],
               attr->dims[0],
               attr->n_elems,
               attr->size,
               0,
               attr->type,
               attr->qnt_type,
               attr->fl,
               attr->zp,
               attr->scale);
    }
    NCE_U8 *load_model(const char *filename, int *model_size)
    {
        FILE *fp = fopen(filename, "rb");
        if (fp == nullptr)
        {
            printf("fopen %s fail!\n", filename);
            return NULL;
        }
        fseek(fp, 0, SEEK_END);
        NCE_S32 model_len = ftell(fp);
        NCE_U8 *model     = new NCE_U8[model_len];
        fseek(fp, 0, SEEK_SET);
        if (model_len != fread(model, 1, model_len, fp))
        {
            printf("fread %s fail!\n", filename);
            free(model);
            return NULL;
        }
        *model_size = model_len;
        if (fp)
        {
            fclose(fp);
        }
        return model;
    }
    NCE_S32 engine_init(const char *                           pc_model_path,
                        vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        NCE_U32 ret = NCE_FAILED;
        /*RKNN Load model*/
        printf("rknn Load model!\n");
        pModel = load_model(pc_model_path, &model_len);

        ret = rknn_init(&ctx, pModel, model_len, 0);
        if (ret < 0)
        {
            printf("rknn_init fail! ret=%d\n", ret);
            return NCE_FAILED;
        }
        // Get Model Input Output Info
        ret = rknn_query(ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(rknn_input_output_num));
        if (ret != RKNN_SUCC)
        {
            printf("rknn_query fail! ret=%d\n", ret);
            return NCE_FAILED;
        }

        rknn_tensor_attr tensor_input[io_num.n_input];
        memset(tensor_input, 0, sizeof(tensor_input));

        for (int i = 0; i < io_num.n_input; i++)
        {
            tensor_input[i].index = i;

            ret = rknn_query(ctx, RKNN_QUERY_INPUT_ATTR, &tensor_input[i], sizeof(rknn_tensor_attr));
            if (ret != RKNN_SUCC)
            {
                printf("rknn_query fail! ret=%d\n", ret);
                return NCE_FAILED;
            }
            printf("fmt %d \n", tensor_input[i].fmt);
            if (tensor_input[i].fmt == RKNN_TENSOR_NHWC)
            {
                // 0  1  2  3 ---- 3  2  1  0
                u32Chs.push_back(tensor_input[i].dims[0]);
                u32Heights.push_back(tensor_input[i].dims[2]);
                u32Widths.push_back(tensor_input[i].dims[1]);
                // TODO 这里我们现在默认输出层就一层，后续需要适配改成多输入。
                st_tensor_infos[i].format  = PACKAGE;
                st_tensor_infos[i].channel = tensor_input[i].dims[0];
                st_tensor_infos[i].height  = tensor_input[i].dims[2];
                st_tensor_infos[i].width   = tensor_input[i].dims[1];
                // TODO NCE强制规定模型是RGB模型，给你脸了？
            }
            else
            {
                u32Chs.push_back(tensor_input[i].dims[2]);
                u32Heights.push_back(tensor_input[i].dims[1]);
                u32Widths.push_back(tensor_input[i].dims[0]);
                st_tensor_infos[i].format  = PLANNER;
                st_tensor_infos[i].channel = tensor_input[i].dims[2];
                st_tensor_infos[i].height  = tensor_input[i].dims[1];
                st_tensor_infos[i].width   = tensor_input[i].dims[0];
            }

            // input_attrs Init
            input_attrs.push_back(tensor_input[i]);
            // Input  Data Init
            // TODO 更便捷的初始化方法？
            inputs.push_back(rknn_input{ 0, 0, 0, 0, tensor_input[i].type, tensor_input[i].fmt });
            /*drm_fd = drm_init(&drm_ctx);
            drm_buf = drm_buf_alloc(&drm_ctx, drm_fd, img_width, img_height, channel * 8,
                                &buf_fd, &handle, &actual_size);*/
            inmem.push_back(rknn_tensor_mem{ 0 });
            printRKNNTensor(&tensor_input[i]);
        }
        ret = rknn_inputs_map(ctx, io_num.n_input, &inmem[0]);
        //查询输出信息，预分配内存，并填写好输出层的层信息
        rknn_tensor_attr tensor_output[io_num.n_output];
        memset(tensor_output, 0, sizeof(tensor_output));
        rknn_output rkoput[io_num.n_output];
        memset(rkoput, 0, sizeof(rkoput));
        for (int i = 0; i < io_num.n_output; i++)
        {

            tensor_output[i].index = i;

            ret = rknn_query(ctx, RKNN_QUERY_OUTPUT_ATTR, &tensor_output[i], sizeof(rknn_tensor_attr));
            if (ret != RKNN_SUCC)
            {
                printf("rknn_query fail! ret=%d\n", ret);
                return NCE_FAILED;
            }
            rkoput[i].index       = 0;
            rkoput[i].want_float  = 1; // TODO 此处是否可变?
            rkoput[i].is_prealloc = 0; // TODO ENGINE预分配
            // rkoput[i].buf = malloc(tensor_output[i].size);
            outputs.push_back(rkoput[i]);
            if (tensor_output[i].fmt == RKNN_TENSOR_NHWC)
            {
                u32OutChs.push_back(tensor_output[i].dims[0]);
                u32OutHeights.push_back(tensor_output[i].dims[2]);
                u32OutWidths.push_back(tensor_output[i].dims[1]);
            }
            else
            {
                u32OutChs.push_back(tensor_output[i].dims[2]);
                u32OutHeights.push_back(tensor_output[i].dims[1]);
                u32OutWidths.push_back(tensor_output[i].dims[0]);
            }
            // out_tensor get

            // printf("%d \n",i);
            printRKNNTensor(&tensor_output[i]);
        }
        int kvcnt = 0;
        if (tensor_output[kvcnt].fmt == RKNN_TENSOR_NCHW)
        {
            for (auto &kv : st_result_map)
            {

                st_result_map[kv].tensor.u32ch          = u32OutChs[kvcnt];
                st_result_map[kv].tensor.u32FeatWidth   = u32OutWidths[kvcnt];
                st_result_map[kv].tensor.u32FeatHeight  = u32OutHeights[kvcnt];
                st_result_map[kv].tensor.width_stride   = 1;
                st_result_map[kv].tensor.height_stride  = u32OutWidths[kvcnt];
                st_result_map[kv].tensor.channel_stride = u32OutWidths[kvcnt] * u32OutHeights[kvcnt];
                st_result_map[kv].tensor.zp             = 0;
                st_result_map[kv].tensor.fl             = 0;
                st_result_map[kv].tensor.scale          = 1;
                st_result_map[kv].tensor.outfmt         = PLANNER;
                st_result_map[kv].feat_type             = FEAT_F32;
                kvcnt++;
            }
        }
        else
        {
            for (auto &kv : st_result_map)
            {

                st_result_map[kv].tensor.u32ch         = u32OutChs[kvcnt];
                st_result_map[kv].tensor.u32FeatWidth  = u32OutWidths[kvcnt];
                st_result_map[kv].tensor.u32FeatHeight = u32OutHeights[kvcnt];
                st_result_map[kv].tensor.width_stride  = u32OutChs[kvcnt];
                st_result_map[kv].tensor.height_stride = u32OutChs[kvcnt] * u32OutWidths[kvcnt];
                ;
                st_result_map[kv].tensor.channel_stride = 1;
                st_result_map[kv].tensor.zp             = 0;
                st_result_map[kv].tensor.fl             = 0;
                st_result_map[kv].tensor.scale          = 1;
                st_result_map[kv].tensor.outfmt         = PACKAGE;
                st_result_map[kv].feat_type             = FEAT_F32;
                kvcnt++;
            }
        }

        return NCE_SUCCESS;
    }

private:
    NCE_U8 *pu8PicAddr  = NULL;
    NCE_U8 *pu8ImageTmp = NULL;
    NCE_U32 u32VarSize  = 0;
};

rv1126_engine::rv1126_engine()
{
    pPriv = shared_ptr<engine_priv>(new rv1126_engine::engine_priv());
};

NCE_S32 rv1126_engine::engine_init(const param_info &                     st_param_info,
                                   vector<input_tensor_info> &            st_tensor_infos,
                                   LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    pPriv->engine_init(st_param_info.pc_model_path, st_tensor_infos, st_result_map);
    return NCE_SUCCESS;
}

NCE_S32 rv1126_engine::engine_init(const YAML::Node &                     config,
                                   vector<input_tensor_info> &            st_tensor_infos,
                                   LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    pPriv->engine_init(config["model_path"].as<string>().c_str(), st_tensor_infos, st_result_map);
    return NCE_SUCCESS;
}

NCE_S32 rv1126_engine::engine_inference(vector<img_t> &pc_imgs)
{

    NCE_U32 ret = NCE_FAILED;
    // set inputs
    long            spend;
    struct timespec start, next, end;
    clock_gettime(0, &start);

    for (int i = 0; i < pPriv->io_num.n_input; i++)
    {
#if NO_ZERO_MAP
        pPriv->inputs[i].index = i;
        if (pc_imgs[i].image_attr.format == PACKAGE)
            pPriv->inputs[i].fmt = RKNN_TENSOR_NHWC;
        else
            pPriv->inputs[i].fmt = RKNN_TENSOR_NCHW;
        pPriv->inputs[i].type = pPriv->input_attrs[i].type;
        pPriv->inputs[i].size =
            pc_imgs[i].image_attr.u32Width * pc_imgs[i].image_attr.u32Height * pc_imgs[i].image_attr.u32channel;

        pPriv->inputs[i].buf = pc_imgs[i].image;
        printf("pc_imgs %d %d %d %d %d\n",
               pc_imgs[i].image_attr.format,
               pc_imgs[i].image_attr.order,
               pc_imgs[i].image_attr.u32Height,
               pc_imgs[i].image_attr.u32Width,
               pc_imgs[i].image_attr.u32channel);
#else
        memcpy(pPriv->inmem[i].logical_addr,
               pc_imgs[i].image,
               pc_imgs[i].image_attr.u32Width * pc_imgs[i].image_attr.u32Height * pc_imgs[i].image_attr.u32channel);
#endif
    }
#if NO_ZERO_MAP
    ret = rknn_inputs_set(pPriv->ctx, pPriv->io_num.n_input, &pPriv->inputs[0]);
#else
    ret = rknn_inputs_sync(pPriv->ctx, pPriv->io_num.n_input, &pPriv->inmem[0]);
#endif

    if (ret < 0)
    {
        printf("rknn_input_set fail! ret=%d\n", ret);
        return NCE_FAILED;
    }
    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("\n[for set]===== TIME SPEND: %ld ms =====\n", spend);
    clock_gettime(0, &start);
    ret = rknn_run(pPriv->ctx, nullptr);
    if (ret < 0)
    {
        printf("rknn_run fail! ret=%d\n", ret);
        return NCE_FAILED;
    }
    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("\n[for rv_engine_run]===== TIME SPEND: %ld ms =====\n", spend);
    return NCE_SUCCESS;
}

NCE_S32 rv1126_engine::engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
{
    NCE_S32         count = 0;
    NCE_U32         ret   = NCE_FAILED;
    long            spend;
    struct timespec start, next, end;
    clock_gettime(0, &start);
    ret = rknn_outputs_get(pPriv->ctx, pPriv->io_num.n_output, &pPriv->outputs[0], NULL);
    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("\n[for get]===== TIME SPEND: %ld ms =====\n", spend);
    for (auto &kv : st_engine_result)
    {
        st_engine_result[kv].pu32Feat = (NCE_S32 *)(pPriv->outputs[count].buf);
        printf("string %s, output %d", kv.c_str(), count);
        count++;
    }

    return ret;
}

NCE_S32 rv1126_engine::engine_destroy()
{
    NCE_U32 ret = NCE_FAILED;
    /*hardware para deinit*/
    if (pPriv->pModel != NULL)
    {
        delete pPriv->pModel;
    }
    /*model deinit*/
    /*for (int i = 0; i < pPriv->io_num.n_input; i++)
    {

        if(pPriv->outputs[i].buf!=NULL)
        {
            free(pPriv->outputs[i].buf);
        }

    }*/
    rknn_outputs_release(pPriv->ctx, pPriv->io_num.n_output, &pPriv->outputs[0]);
    return NCE_SUCCESS;
}
} // namespace nce_alg
