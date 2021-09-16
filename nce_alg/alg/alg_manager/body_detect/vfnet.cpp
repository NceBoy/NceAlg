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
#include "vfnet.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include "util.hpp"
#include <algorithm>
#include <cmath>
// TODO:去除打印

using namespace std;
namespace nce_alg {
typedef struct pos_score
{
    int   index;
    float score;
} pos_score;

NCE_S32 body_nms(vector<alg_result> input, vector<alg_result> &output, float threshold)
{
    output.clear();
    sort(input.begin(), input.end(), [](const alg_result &a, const alg_result &b) { return a.score > b.score; });

    int box_num = input.size();

    vector<int> merged(box_num, 0);

    for (int i = 0; i < box_num; i++)
    {
        if (merged[i])
            continue;

        // output.push_back(input[i]);
        output.emplace_back(input[i]);

        float h0 = input[i].y2 - input[i].y1 + 1;
        float w0 = input[i].x2 - input[i].x1 + 1;

        float area0 = h0 * w0;

        for (int j = i + 1; j < box_num; j++)
        {
            if (merged[j])
                continue;

            float inner_x0 = max(input[i].x1, input[j].x1);
            float inner_y0 = max(input[i].y1, input[j].y1);

            float inner_x1 = min(input[i].x2, input[j].x2);
            float inner_y1 = min(input[i].y2, input[j].y2);

            float inner_h = inner_y1 - inner_y0 + 1;
            float inner_w = inner_x1 - inner_x0 + 1;

            if (inner_h <= 0 || inner_w <= 0)
                continue;

            float inner_area = inner_h * inner_w;

            float h1 = input[j].y2 - input[j].y1 + 1;
            float w1 = input[j].x2 - input[j].x1 + 1;

            float area1 = h1 * w1;

            float score        = inner_area / (area0 + area1 - inner_area);
            float score2       = inner_area / min(area1, area0);
            float deltah_threh = 0.05 * h1;
            float delta_y1     = min((NCE_S32)input[i].y1 - (NCE_S32)input[j].y1, 0);
            if (score > threshold)
                merged[j] = 1;
            if (score2 > deltah_threh && delta_y1 > deltah_threh)
                merged[j] = 1;
        }
    }
    return NCE_SUCCESS;
}

vfnet_priv::vfnet_priv()
{
    alg_cfg.threshold = 0.3;
    alg_cfg.isLog     = false;
    score             = new NCE_F32[3];
    topk              = 100;
    model_image_info  = { 0 };
}

vfnet_priv::~vfnet_priv()
{
    delete score;
}

NCE_S32 vfnet::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                        unordered_map<string, tmp_map_result> &st_result_map)
{
    NCE_S32 ret                = NCE_FAILED;
    pPriv                      = shared_ptr<vfnet_priv>(new vfnet_priv());
    pPriv->input_tensor_infos  = nullptr;
    st_result_map["P3_logits"] = tmp_map_result{ 0 };
    st_result_map["P4_logits"] = tmp_map_result{ 0 };
    st_result_map["P5_logits"] = tmp_map_result{ 0 };
    st_result_map["P6_logits"] = tmp_map_result{ 0 };
    st_result_map["P7_logits"] = tmp_map_result{ 0 };

    st_result_map["P3_bbox_reg"] = tmp_map_result{ 0 };
    st_result_map["P4_bbox_reg"] = tmp_map_result{ 0 };
    st_result_map["P5_bbox_reg"] = tmp_map_result{ 0 };
    st_result_map["P6_bbox_reg"] = tmp_map_result{ 0 };
    st_result_map["P7_bbox_reg"] = tmp_map_result{ 0 };

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    NCE_F32 mean0[3] = { 127.5f, 127.5f, 127.5f };
    NCE_F32 std[3]   = { 0.0078125f, 0.0078125f, 0.0078125f };

    memcpy(input0.mean, mean0, sizeof(NCE_F32) * 3);
    memcpy(input0.std, std, sizeof(NCE_F32) * 3);
    st_tensor_infos.push_back(input0);
    pPriv->input_tensor_infos = &st_tensor_infos;

    return ret;
}

NCE_S32 vfnet::alg_cfg_set(const task_config_info &st_task_config_info)
{
    NCE_S32 ret = NCE_FAILED;

    pPriv->alg_cfg.threshold                   = st_task_config_info.threshold;
    pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
    pPriv->alg_cfg.isLog                       = st_task_config_info.isLog;
    ret                                        = NCE_SUCCESS;
    return ret;
}

NCE_S32 vfnet::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 vfnet::alg_get_result(alg_result_info &results, unordered_map<string, tmp_map_result> &st_result_map)
{
    results.num = 0;
    pPriv->head_info.clear();
    pPriv->tmp_result.clear();

    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }

    vector<tmp_map_result> all_logits = {
        st_result_map["P3_logits"], st_result_map["P4_logits"], st_result_map["P5_logits"],
        st_result_map["P6_logits"], st_result_map["P7_logits"],
    };

    vector<tmp_map_result> all_reg = {
        st_result_map["P3_bbox_reg"], st_result_map["P4_bbox_reg"], st_result_map["P5_bbox_reg"],
        st_result_map["P6_bbox_reg"], st_result_map["P7_bbox_reg"],
    };

    for (int i = 0; i < 5; i++)
    {
        // auto shape = output_logits[0]->shape();

        NCE_F32 *logits = (NCE_F32 *)all_logits[i].pu32Feat;
        NCE_F32 *bboxes = (NCE_F32 *)all_reg[i].pu32Feat;

        auto feat_width  = all_logits[i].tensor.u32Stride;
        auto feat_height = all_logits[i].tensor.u32FeatHeight;

        NCE_S32 feature_size = feat_width * feat_height;
        NCE_S32 cur_stride   = pow(2, i + 3);
        for (NCE_S32 index = 0; index < feature_size; index++)
        {
            NCE_S32 x = index % feat_width * cur_stride;
            NCE_S32 y = index / feat_width * cur_stride;
            for (NCE_S32 anchor_index = 0; anchor_index < 3; anchor_index++)
            {

                NCE_F32 score = logits[feature_size * anchor_index * 4 + index];
                score         = sqrt(score);
                if (score < 0.6)
                    continue;

                NCE_F32 left   = bboxes[feature_size * (anchor_index * 4 + 0) + index];
                NCE_F32 top    = bboxes[feature_size * (anchor_index * 4 + 1) + index];
                NCE_F32 right  = bboxes[feature_size * (anchor_index * 4 + 2) + index];
                NCE_F32 bottom = bboxes[feature_size * (anchor_index * 4 + 3) + index];

                NCE_U32 x1 = std::max((NCE_F32)0, x - left);
                NCE_U32 y1 = std::max((NCE_F32)0, y - top);
                NCE_U32 x2 = std::min((NCE_F32)(*pPriv->input_tensor_infos)[0].width, x + right);
                NCE_U32 y2 = std::min((NCE_F32)(*pPriv->input_tensor_infos)[0].height, y + bottom);

                NCE_F32 fake     = 0.f;
                NCE_S32 angle[3] = { 0, 0, 0 };

                pPriv->head_info.push_back(person_head{ fake, angle[0], angle[1], angle[2] });
                pPriv->tmp_result.push_back(
                    alg_result{ x1, y1, x2, y2, score, PERSON_HEAD, &pPriv->head_info[pPriv->head_info.size() - 1] });
            }
        }
    }

    body_nms(pPriv->tmp_result, pPriv->tmp_result, pPriv->alg_cfg.st_cfg.hd_config.nms_thresh);
    NCE_U32 num = pPriv->tmp_result.size();
    results.num = num;
    if (num > 0)
        results.st_alg_results = &pPriv->tmp_result[0];

    return ret;
}
NCE_S32 vfnet::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg