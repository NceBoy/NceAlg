/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:12:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-12-02 11:34:11
 */
#include <iostream>
#include <string>
#include <vector>
#include "centernet/centernet.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include <algorithm>

using namespace std;
namespace nce_alg {

centernet_priv::centernet_priv()
{
    alg_cfg.threshold  = 0.3;
    alg_cfg.isLog      = false;
    input_tensor_infos = nullptr;
    topk               = 100;
    output_stride      = 4;
}

centernet_priv::~centernet_priv()
{}

NCE_S32 centernet::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                            LinkedHashMap<string, tmp_map_result> &st_result_map,
                            YAML::Node &                           config)
{
    NCE_S32 ret      = NCE_FAILED;
    int     i        = 0;
    pPriv            = shared_ptr<centernet_priv>(new centernet_priv());
    const auto names = config["output_names"];
    for (auto &iter : names)
    {
        st_result_map.insert(make_pair(iter.as<string>(), tmp_map_result{ 0 }));
    }

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    const auto mean0 = config["mean0"];
    const auto std0  = config["std0"];
    for (i = 0; i < 3; i++)
    {
        input0.mean[i] = mean0[i].as<float>();
        input0.std[i]  = std0[i].as<float>();
    }
    st_tensor_infos.push_back(input0);
    pPriv->output_stride      = config["out_stride"].as<NCE_S32>();
    pPriv->alg_cfg.threshold  = config["conf_thresh"].as<NCE_F32>();
    pPriv->input_tensor_infos = &st_tensor_infos;

    if (NULL != pPriv)
    {
        ret = NCE_SUCCESS;
    }
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

NCE_S32 centernet::alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
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

    auto hm      = st_result_map["hm"];
    auto maxpool = st_result_map["pool"];
    auto wh      = st_result_map["wh"];
    auto offset  = st_result_map["off"];

    auto feat_width  = hm.tensor.u32FeatWidth;
    auto feat_height = hm.tensor.u32FeatHeight;

    auto hm_height_stride  = hm.tensor.height_stride;
    auto hm_width_stride   = hm.tensor.width_stride;
    auto hm_channel_stride = hm.tensor.channel_stride;

    auto wh_height_stride  = wh.tensor.height_stride;
    auto wh_width_stride   = wh.tensor.width_stride;
    auto wh_channel_stride = wh.tensor.channel_stride;

    NCE_F32 *hm_feat  = (NCE_F32 *)hm.pu32Feat;
    NCE_F32 *wh_feat  = (NCE_F32 *)wh.pu32Feat;
    NCE_F32 *off_feat = (NCE_F32 *)offset.pu32Feat;

    for (NCE_U32 y = 0; y < feat_height; y++)
    {
        for (NCE_U32 x = 0; x < feat_width; x++)
        {
            NCE_U32 hm_index = x * hm_width_stride + y * hm_height_stride;
            NCE_U32 wh_index = x * wh_width_stride + y * wh_height_stride;

            NCE_F32 score = hm_feat[hm_index];
            if (score < pPriv->alg_cfg.threshold)
                continue;

            NCE_F32 w  = wh_feat[wh_index + 0 * wh_channel_stride] * pPriv->output_stride;
            NCE_F32 h  = wh_feat[wh_index + 1 * wh_channel_stride] * pPriv->output_stride;
            NCE_F32 dx = off_feat[wh_index + 0 * wh_channel_stride] * pPriv->output_stride;
            NCE_F32 dy = off_feat[wh_index + 1 * wh_channel_stride] * pPriv->output_stride;

            NCE_F32 ct_x = x * pPriv->output_stride + dx;
            NCE_F32 ct_y = y * pPriv->output_stride + dy;

            NCE_U32 x1 = ct_x + dx - w / 2;
            NCE_U32 y1 = ct_y + dy - h / 2;
            NCE_U32 x2 = ct_x + dx + w / 2;
            NCE_U32 y2 = ct_y + dy + h / 2;

            pPriv->detect_results.push_back({ x1, y1, x2, y2, score });
        }
    }

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
