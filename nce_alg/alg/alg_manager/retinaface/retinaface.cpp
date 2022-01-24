/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:12:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-01-24 11:37:52
 */
#include <iostream>
#include <string>
#include <vector>
#include "retinaface/retinaface.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include <algorithm>
#include <cmath>
#include "util/util.hpp"

using namespace std;
namespace nce_alg {

retinaface_priv::retinaface_priv()
{
    alg_cfg.threshold  = 0.6;
    alg_cfg.isLog      = false;
    input_tensor_infos = nullptr;

    // TODO support infered by steps and priors
    _m_num_anchors = 2;
    _m_num_strides = 3;
    _m_num_cls     = 1;
    
    _m_anchor_priors[0][0] = 16;
    _m_anchor_priors[0][1] = 32;
    _m_anchor_priors[1][0] = 64;
    _m_anchor_priors[1][1] = 128;
    _m_anchor_priors[2][0] = 256;
    _m_anchor_priors[2][1] = 512;

    _m_strides[0] = 8;
    _m_strides[1] = 16;
    _m_strides[2] = 32;

    memset(&_model_image_info,0,sizeof(img_info));
}
NCE_S32 retinaface_priv::alg_priv_get_anchor(NCE_S32  cur_h,
                                             NCE_S32  cur_w,
                                             NCE_S32  img_width,
                                             NCE_S32  img_height,
                                             NCE_S32  stride_idx,
                                             NCE_S32  anchor_idx,
                                             NCE_F32 *prior)
{
    NCE_F32 cxx   = (cur_w + 0.5f) * _m_strides[stride_idx] / img_width;
    NCE_F32 cyy   = (cur_h + 0.5f) * _m_strides[stride_idx] / img_height;
    NCE_F32 s_kxx = _m_anchor_priors[stride_idx][anchor_idx] / img_width;
    NCE_F32 s_kyy = _m_anchor_priors[stride_idx][anchor_idx] / img_height;
    prior[0]      = cxx;
    prior[1]      = cyy;
    prior[2]      = s_kxx;
    prior[3]      = s_kyy;
    return NCE_SUCCESS;
}

retinaface_priv::~retinaface_priv()
{
    printf("retinaface deinit");
}

NCE_S32 retinaface::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                             LinkedHashMap<string, tmp_map_result> &st_result_map,
                             YAML::Node &                           config)
{
    NCE_S32 ret = NCE_FAILED;
    pPriv       = shared_ptr<retinaface_priv>(new retinaface_priv());
    int i       = 0;

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

    pPriv->_m_num_anchors     = config["num_anchors"].as<int>();
    pPriv->_m_num_cls         = config["num_cls"].as<int>();
    pPriv->alg_cfg.threshold  = config["conf_thresh"].as<float>();
    pPriv->input_tensor_infos = &st_tensor_infos;
    printf("finshed alg init\n!");
    return ret;
}

NCE_S32 retinaface::alg_cfg_set(const task_config_info &st_task_config_info)
{
    return NCE_SUCCESS;
}
NCE_S32 retinaface::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 retinaface::alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
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

    static vector<tmp_map_result> all_logits = {
        st_result_map["logits_1"],
        st_result_map["logits_2"],
        st_result_map["logits_3"],
    };

    static vector<tmp_map_result> all_reg = {
        st_result_map["bboxes_1"],
        st_result_map["bboxes_2"],
        st_result_map["bboxes_3"],
    };

    static vector<tmp_map_result> all_landmarks = {
        st_result_map["landmaeks_1"],
        st_result_map["landmaeks_2"],
        st_result_map["landmaeks_3"],
    };

    NCE_S32 img_width  = (*pPriv->input_tensor_infos)[0].width;
    NCE_S32 img_height = (*pPriv->input_tensor_infos)[0].height;
    for (int i = 0; i < pPriv->_m_num_strides; i++)
    {

        NCE_F32 *logits = (NCE_F32 *)all_logits[i].pu32Feat;
        NCE_F32 *bboxes = (NCE_F32 *)all_reg[i].pu32Feat;
        NCE_F32 *landms = (NCE_F32 *)all_landmarks[i].pu32Feat;

        const auto feat_width  = all_logits[i].tensor.u32FeatWidth;
        const auto feat_height = all_logits[i].tensor.u32FeatHeight;

        const auto logist_height_stride  = all_logits[i].tensor.height_stride;
        const auto logist_width_stride   = all_logits[i].tensor.width_stride;
        const auto logist_channel_stride = all_logits[i].tensor.channel_stride;

        const auto reg_height_stride  = all_reg[i].tensor.height_stride;
        const auto reg_width_stride   = all_reg[i].tensor.width_stride;
        const auto reg_channel_stride = all_reg[i].tensor.channel_stride;

        const auto landms_height_stride  = all_landmarks[i].tensor.height_stride;
        const auto landms_width_stride   = all_landmarks[i].tensor.width_stride;
        const auto landms_channel_stride = all_landmarks[i].tensor.channel_stride;

        NCE_S32 feature_size = feat_width * feat_height;

        for (NCE_S32 h = 0; h < feat_height; h++)
        {
            for (NCE_S32 w = 0; w < feat_width; w++)
            {
                for (NCE_S32 anchor_index = 0; anchor_index < pPriv->_m_num_anchors; anchor_index++)
                {
                    NCE_U32 logits_index =
                        h * logist_height_stride + w * logist_width_stride + anchor_index * logist_channel_stride * 2;
                    NCE_U32 reg_index =
                        h * reg_height_stride + w * reg_width_stride + anchor_index * logist_channel_stride * 4;
                    NCE_U32 landms_index =
                        h * landms_height_stride + w * landms_width_stride + anchor_index * landms_channel_stride * 10;

                    NCE_F32 scores[2];
                    scores[0] = logits[logits_index];
                    scores[1] = logits[logits_index + 1 * logist_channel_stride];
                    softmax(2, scores);
                    NCE_F32 score = scores[1];
                    if (score < 0)
                    {
                        continue;
                    };
                    if (score < pPriv->alg_cfg.threshold)
                        continue;

                    NCE_F32 prior[4];
                    
                    pPriv->alg_priv_get_anchor(h, w, img_width, img_height, i, anchor_index, prior);

                    NCE_F32 ctx         = bboxes[reg_index + 0 * reg_channel_stride];
                    NCE_F32 cty         = bboxes[reg_index + 1 * reg_channel_stride];
                    NCE_F32 bbox_width  = bboxes[reg_index + 2 * reg_channel_stride];
                    NCE_F32 bbox_height = bboxes[reg_index + 3 * reg_channel_stride];

                    ctx         = prior[0] + ctx * 0.1 * prior[2];
                    cty         = prior[1] + cty * 0.1 * prior[3];
                    bbox_width  = prior[2] * exp(bbox_width * 0.2);
                    bbox_height = prior[3] * exp(bbox_height * 0.2);

                    NCE_U32 tmp_landms[10];

                    for (NCE_U8 j = 0; j < 5; j++) 
                    {
                        tmp_landms[2 * j + 0] =
                            (prior[0] + landms[landms_index + 2 * j * landms_channel_stride] * 0.1 * prior[2]) * img_width;
                        tmp_landms[2 * j + 1] =
                            (prior[1] + landms[landms_index + (2 * j + 1) * landms_channel_stride] * 0.1 * prior[3]) * img_height;
                    }

                    NCE_U32 x1 = std::max((NCE_F32)0, ctx - 0.5f * bbox_width) * img_width;
                    NCE_U32 y1 = std::max((NCE_F32)0, cty - 0.5f * bbox_height) * img_height;
                    NCE_U32 x2 = std::min((NCE_F32)(*pPriv->input_tensor_infos)[0].width - 1, ctx + 0.5f * bbox_width)
                                 * img_width;
                    NCE_U32 y2 = std::min((NCE_F32)(*pPriv->input_tensor_infos)[0].height - 1, cty + 0.5f * bbox_height)
                                 * img_height;
         
                    detect_result tmp_result = { x1, y1, x2, y2, score };
                    memcpy(tmp_result.landmark, tmp_landms, sizeof(NCE_U32) * 10);
         
                    pPriv->detect_results.push_back(tmp_result);
                }
            }
        }
    }
    // body_nms(pPriv->detect_results, pPriv->detect_results, pPriv->alg_cfg.st_cfg.hd_config.nms_thresh);
    for (auto &item : pPriv->detect_results)
    {
        pPriv->tmp_result.push_back(alg_result{ RETINAFACE, &item });
    }
    NCE_U32 num = pPriv->detect_results.size();
    results.num = num;
    if (num > 0)
        results.st_alg_results = &pPriv->tmp_result[0];

    return ret;
}
NCE_S32 retinaface::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg
