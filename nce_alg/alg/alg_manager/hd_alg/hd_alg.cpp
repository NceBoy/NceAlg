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
    model_image_info                    = { 0 };
    output_stride                       = 4;
    input_tensor_infos                  = nullptr;
}

hd_alg::hd_alg()
{}

NCE_S32 hd_alg::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                         LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    NCE_S32 ret = NCE_FAILED;
    pPriv       = shared_ptr<hd_alg_priv>(new hd_alg_priv());
    // st_result_map.insert({0,pPriv->tag[0]});
    // st_result_map.insert({1,pPriv->tag[1]});
    st_result_map.insert(std::make_pair("hm",tmp_map_result{ 0 }));
    st_result_map.insert(std::make_pair("wh",tmp_map_result{ 0 }));
    st_result_map["hm"].tensor.name = "hm";
    st_result_map["wh"].tensor.name = "wh";

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    NCE_F32 mean0[3] = { 127.5f, 127.5f, 127.5f };
    NCE_F32 std[3]   = { 0.0078125f, 0.0078125f, 0.0078125f };

    memcpy(input0.mean, mean0, sizeof(NCE_F32) * 3);
    memcpy(input0.std, std, sizeof(NCE_F32) * 3);
    st_tensor_infos.push_back(input0);
    pPriv->input_tensor_infos = &st_tensor_infos;

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

NCE_S32 hd_alg::alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }

    pPriv->tmp_result.clear();
    pPriv->detect_results.clear();

    auto hm = st_result_map["hm"];
    auto wh = st_result_map["wh"];

    auto feat_width  = hm.tensor.u32FeatWidth;
    auto feat_height = hm.tensor.u32FeatHeight;

    auto hm_height_stride  = hm.tensor.height_stride;
    auto hm_width_stride   = hm.tensor.width_stride;
    auto hm_channel_stride = hm.tensor.channel_stride;

    auto wh_height_stride  = wh.tensor.height_stride;
    auto wh_width_stride   = wh.tensor.width_stride;
    auto wh_channel_stride = wh.tensor.channel_stride;
    NCE_F32 *hm_feat = (NCE_F32 *)hm.pu32Feat;
    NCE_F32 *wh_feat = (NCE_F32 *)wh.pu32Feat;
    for (NCE_U32 y = 0; y < feat_height; y++)
    {
        for (NCE_U32 x = 0; x < feat_width; x++)
        {
            NCE_U32 hm_index = x * hm_width_stride + y * hm_height_stride;
            NCE_U32 wh_index = x * wh_width_stride + y * wh_height_stride;

            NCE_F32 score = hm_feat[hm_index];
            if (score < pPriv->alg_cfg.threshold)
                continue;
            NCE_F32 left  = wh_feat[wh_index + 0 * wh_channel_stride];
            NCE_F32 top   = wh_feat[wh_index + 1 * wh_channel_stride];
            NCE_F32 right = wh_feat[wh_index + 2 * wh_channel_stride];
            NCE_F32 down  = wh_feat[wh_index + 3 * wh_channel_stride];

            NCE_U32 x1 = x * pPriv->output_stride - left;
            NCE_U32 y1 = y * pPriv->output_stride - top;
            NCE_U32 x2 = x * pPriv->output_stride + right;
            NCE_U32 y2 = y * pPriv->output_stride + down;

            pPriv->detect_results.push_back({ x1, y1, x2, y2, score });
        }
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
} // namespace nce_alg
