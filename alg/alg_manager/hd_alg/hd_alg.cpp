#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string.h>
#include "hd_alg.hpp"
#include "util.hpp"

#ifndef HISI_4096
#define HISI_4096 1.0f
#endif
using namespace std;
namespace nce_alg {

hd_alg_priv::hd_alg_priv()
{
    alg_cfg.threshold                   = 0.3;
    alg_cfg.st_cfg.hd_config.nms_thresh = 0.6;
    alg_cfg.isLog                       = false;
    u32Stride                           = 0;
    memset(&model_image_info, 0, sizeof(img_info));
}

hd_alg::hd_alg()
{}
/*
 * alg_init 算法层初始化
 * 将输出层map定义好
 * ...
 */
NCE_S32 hd_alg::alg_init(vector<img_info> &st_img_info, map<int, tmp_map_result> &st_result_map)
{
    NCE_S32 ret = NCE_FAILED;
    pPriv       = shared_ptr<hd_alg_priv>(new hd_alg_priv());
    // st_result_map.insert({0,pPriv->tag[0]});
    // st_result_map.insert({1,pPriv->tag[1]});
    st_result_map[0]             = tmp_map_result{ 0 };
    st_result_map[1]             = tmp_map_result{ 0 };
    st_result_map[0].tensor.name = "hm";
    st_result_map[1].tensor.name = "wh";
    if (NULL != pPriv)
    {
        ret = NCE_SUCCESS;
    }
    return ret;
}

NCE_S32 hd_alg::alg_cfg_set(const task_config_info &st_task_config_info)
{
    NCE_S32 ret = NCE_FAILED;

    pPriv->alg_cfg.threshold                   = st_task_config_info.threshold;
    pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
    pPriv->alg_cfg.isLog                       = st_task_config_info.isLog;
    ret                                        = NCE_SUCCESS;
    return ret;
}

NCE_S32 hd_alg::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

NCE_S32 hd_alg::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

NCE_S32 hd_alg::alg_get_result(alg_result_info &results, map<int, tmp_map_result> &st_result_map)
{
    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }
    printf("aa!\n");
    // TODO 此处为清除上一轮调用结果，所以使用者必须及时拷贝走数据结果，且该函数不可重入
    pPriv->tmp_result.clear();
    pPriv->head_info.clear();

    NCE_F32 ratio  = 4;
    NCE_U32 width  = st_result_map[0].tensor.u32FeatWidth;
    NCE_U32 height = st_result_map[0].tensor.u32FeatHeight;
    NCE_U32 stride = st_result_map[0].tensor.u32Stride;

    NCE_F32 *cls = (NCE_F32 *)st_result_map[0].pu32Feat;
    NCE_F32 *reg = (NCE_F32 *)st_result_map[1].pu32Feat;

    NCE_U32 feature_size   = width * height;
    NCE_U32 feature_stride = stride * height;

    // TODO 异常后处理模块 nchw nhwc处理
    NCE_F32 xi = /*(st_result_map[0].tensor.zp - st_result_map[0].tensor.fl)**/ st_result_map[0].tensor.scale;
    printf("%f,output %d zp %d fl %d, sacle %f \n",
           xi,
           st_result_map[0].tensor.outfmt,
           st_result_map[0].tensor.zp,
           st_result_map[0].tensor.fl,
           st_result_map[0].tensor.scale);
    if (st_result_map[0].tensor.outfmt == PLANNER)
    {
        if (xi == 1.0f)
        {
            printf("a\n");
            for (NCE_U32 i = 0; i < feature_size; i++)
            {
                NCE_U32 cur_h = i / width;
                NCE_U32 cur_w = i % width;

                NCE_F32 score = (NCE_F32)(cls[cur_h * stride + cur_w]);
                NCE_U32 left  = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 0]);
                NCE_U32 top   = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 1]);
                NCE_U32 right = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 2]);
                NCE_U32 down  = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 3]);

                if (score < pPriv->alg_cfg.threshold)
                    continue;
                // printf("count:%d score:%f\n", i, score);
                NCE_U32 x1       = cur_w * ratio - left;
                NCE_U32 y1       = cur_h * ratio - top;
                NCE_U32 x2       = cur_w * ratio + right;
                NCE_U32 y2       = cur_h * ratio + down;
                NCE_F32 fake     = 0.f;
                NCE_S32 angle[3] = { 0, 0, 0 };
                pPriv->head_info.push_back(person_head{ fake, angle[0], angle[1], angle[2] });
                // cun shu xing
                pPriv->tmp_result.push_back(
                    alg_result{ x1, y1, x2, y2, score, PERSON_HEAD, &pPriv->head_info[pPriv->head_info.size() - 1] });
            }
        }
        else
        {
            for (NCE_U32 i = 0; i < feature_size; i++)
            {
                NCE_U32 cur_h = i / width;
                NCE_U32 cur_w = i % width;

                NCE_F32 score = (NCE_F32)(cls[cur_h * stride + cur_w]) / xi;
                NCE_U32 left  = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 0]) / xi;
                NCE_U32 top   = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 1]) / xi;
                NCE_U32 right = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 2]) / xi;
                NCE_U32 down  = (NCE_F32)(reg[cur_h * stride + cur_w + feature_stride * 3]) / xi;

                if (score < pPriv->alg_cfg.threshold)
                    continue;

                NCE_U32 x1       = cur_w * ratio - left;
                NCE_U32 y1       = cur_h * ratio - top;
                NCE_U32 x2       = cur_w * ratio + right;
                NCE_U32 y2       = cur_h * ratio + down;
                NCE_F32 fake     = 0.f;
                NCE_S32 angle[3] = { 0, 0, 0 };
                pPriv->head_info.push_back(person_head{ fake, angle[0], angle[1], angle[2] });
                // cun shu xing
                pPriv->tmp_result.push_back(
                    alg_result{ x1, y1, x2, y2, score, PERSON_HEAD, &pPriv->head_info[pPriv->head_info.size() - 1] });
            }
        }
    }
    else
    {
    }
    nms(pPriv->tmp_result, pPriv->tmp_result, pPriv->alg_cfg.st_cfg.hd_config.nms_thresh);
    results.num            = pPriv->tmp_result.size();
    results.st_alg_results = &pPriv->tmp_result[0];

    return ret;
}
} // namespace nce_alg
