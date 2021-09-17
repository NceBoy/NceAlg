/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:12:49
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-08-30 11:19:39
 */
#include <iostream>
#include <string>
#include <vector>
#include "centernet.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include "util.hpp"
#include <algorithm>
// TODO:去除打印

using namespace std;
namespace nce_alg {
typedef struct pos_score
{
    int   index;
    float score;
} pos_score;

centernet_priv::centernet_priv()
{
    alg_cfg.threshold = 0.3;
    alg_cfg.isLog     = false;
    score             = new NCE_F32[3];
    input_info        = NULL;
    topk              = 100;
    memset(&model_image_info, 0, sizeof(img_info));
}

centernet_priv::~centernet_priv()
{
    delete score;
}

NCE_S32 centernet::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                            unordered_map<string, tmp_map_result> &st_result_map)
{
    NCE_S32 ret           = NCE_FAILED;
    pPriv                 = shared_ptr<centernet_priv>(new centernet_priv());
    st_result_map["hm"]   = tmp_map_result{ 0 };
    st_result_map["pool"] = tmp_map_result{ 0 };
    st_result_map["wh"]   = tmp_map_result{ 0 };
    st_result_map["off"]  = tmp_map_result{ 0 };

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    NCE_F32 mean0[3] = { 127.5f, 127.5f, 127.5f };
    NCE_F32 std[3]   = { 0.0078125f, 0.0078125f, 0.0078125f };
    memcpy(input0.mean, mean0, sizeof(NCE_F32) * 3);
    memcpy(input0.std, std, sizeof(NCE_F32) * 3);
    st_tensor_infos.push_back(input0);

    return ret;
}

NCE_S32 centernet::alg_cfg_set(const task_config_info &st_task_config_info)
{
    NCE_S32 ret = NCE_FAILED;

    pPriv->alg_cfg.threshold                   = st_task_config_info.threshold;
    pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
    pPriv->alg_cfg.isLog                       = st_task_config_info.isLog;
    ret                                        = NCE_SUCCESS;
    return ret;
}

NCE_S32 centernet::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 centernet::alg_get_result(alg_result_info &results, unordered_map<string, tmp_map_result> &st_result_map)
{
    results.num = 0;
    pPriv->detect_results.clear();
    pPriv->tmp_result.clear();

    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }

    NCE_F32 *hm      = (NCE_F32 *)st_result_map["hm"].pu32Feat;
    NCE_F32 *maxpool = (NCE_F32 *)st_result_map["pool"].pu32Feat;
    NCE_F32 *wh      = (NCE_F32 *)st_result_map["wh"].pu32Feat;
    NCE_F32 *offset  = (NCE_F32 *)st_result_map["off"].pu32Feat;


    NCE_U32 width        = st_result_map["hm"].tensor.u32FeatWidth;
    NCE_U32 height       = st_result_map["hm"].tensor.u32FeatHeight;
    NCE_U32 stride       = st_result_map["hm"].tensor.u32Stride;

    NCE_U32 feature_size = width * height;

    NCE_F32 xi = st_result_map["hm"].tensor.scale;

    std::vector<pos_score> valid_value;
    for (int index = 0; index < feature_size; index++)
    {
        if (hm[index] == maxpool[index])
        {
            valid_value.push_back({ index, hm[index] });
        }
    }

    std::sort(valid_value.begin(), valid_value.end(), [](pos_score a, pos_score b) { return a.score > b.score; });
    NCE_U32 valid_topk = min(pPriv->topk, (NCE_U32)valid_value.size());

    for (int i = 0; i < valid_topk; i++)
    {
        pos_score tmp   = valid_value[i];
        NCE_U32   index = tmp.index;
        NCE_F32   score = tmp.score;
        NCE_U32   cur_h = index / width;
        NCE_U32   cur_w = index % width;
        // printf("topk score is : %f\n", score);
        if (score < pPriv->alg_cfg.threshold)
            continue;
        NCE_U32 w  = wh[index + 0 * feature_size] * 4;
        NCE_U32 h  = wh[index + 1 * feature_size] * 4;
        NCE_U32 dx = offset[index + 0 * feature_size] * 4;
        NCE_U32 dy = offset[index + 1 * feature_size] * 4;

        NCE_U32 ct_x = cur_w * 4 + dx;
        NCE_U32 ct_y = cur_h * 4 + dy;

        NCE_U32 x1 = ct_x + dx - w / 2;
        NCE_U32 y1 = ct_y + dy - h / 2;
        NCE_U32 x2 = ct_x + dx + w / 2;
        NCE_U32 y2 = ct_y + dy + h / 2;

        pPriv->detect_results.push_back(detect_result{ x1, y1, x2, y2, score });
    }

    nms(pPriv->detect_results, pPriv->detect_results, pPriv->alg_cfg.st_cfg.hd_config.nms_thresh);
    for (auto &item : pPriv->detect_results)
    {
        pPriv->tmp_result.push_back(alg_result{ VFNET, &item });
    }
    NCE_U32 num = pPriv->tmp_result.size();
    results.num = num;
    if (num > 0)
        results.st_alg_results = &pPriv->tmp_result[0];

    return ret;
}
NCE_S32 centernet::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg
