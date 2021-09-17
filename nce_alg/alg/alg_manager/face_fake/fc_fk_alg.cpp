#include <iostream>
#include <string>
#include <vector>
#include "fc_fk_alg.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include "util.hpp"
// TODO:去除打印

using namespace std;
namespace nce_alg {

fc_fk_alg_priv::fc_fk_alg_priv()
{
    alg_cfg.threshold = 0.3;
    alg_cfg.isLog     = false;
    score             = new NCE_F32[3];
    input_info        = NULL;
    memset(&model_image_info, 0, sizeof(img_info));
}

fc_fk_alg_priv::~fc_fk_alg_priv()
{
    delete score;
}

NCE_S32 fc_fk_alg::alg_init(const param_info &st_param_info, map<int, tmp_map_result> &st_result_map)
{
    NCE_S32 ret                  = NCE_FAILED;
    pPriv                        = shared_ptr<fc_fk_alg_priv>(new fc_fk_alg_priv());
    st_result_map[0]             = tmp_map_result{ 0 };
    st_result_map[0].tensor.name = "Conv_97";
    return ret;
}

NCE_S32 fc_fk_alg::alg_cfg_set(const task_config_info &st_task_config_info)
{
    NCE_S32 ret = NCE_FAILED;

    pPriv->alg_cfg.threshold                   = st_task_config_info.threshold;
    pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
    pPriv->alg_cfg.isLog                       = st_task_config_info.isLog;
    ret                                        = NCE_SUCCESS;
    return ret;
}

NCE_S32 fc_fk_alg::alg_inference(img_t &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 fc_fk_alg::alg_get_result(alg_result_info &results, map<int, tmp_map_result> &st_result_map)
{
    results.num = 1;

    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }

    NCE_F32 *cls    = (NCE_F32 *)st_result_map[0].pu32Feat;
    NCE_U32  width  = st_result_map[0].tensor.u32FeatWidth;
    NCE_U32  height = st_result_map[0].tensor.u32FeatHeight;
    NCE_U32  stride = st_result_map[0].tensor.u32Stride;

    NCE_F32 xi = st_result_map[0].tensor.scale;
    /*(st_result_map[0].tensor.zp - st_result_map[0].tensor.fl)**/
    // printf("%f,output %d zp %d fl %d, sacle %f
    // \n",xi,st_result_map[0].tensor.outfmt,st_result_map[0].tensor.zp,st_result_map[0].tensor.fl,st_result_map[0].tensor.scale);
    if (st_result_map[0].tensor.outfmt == PLANNER)
    {
        if (xi == 1.0f)
        {
            pPriv->score[0] = cls[0 * stride];
            pPriv->score[1] = cls[1 * stride];
            pPriv->score[2] = cls[2 * stride];
        }
        else
        {
            pPriv->score[0] = cls[0 * stride] / xi;
            pPriv->score[1] = cls[1 * stride] / xi;
            pPriv->score[2] = cls[2 * stride] / xi;
        }
    }
    else
    {
    }

    softmax(3, pPriv->score);
    pPriv->head_info.push_back(person_head{ pPriv->score[0], { 0, 0, 0 } });
    pPriv->tmp_result.push_back(alg_result{PERSON_HEAD, &pPriv->head_info[0] });
    results.st_alg_results = &pPriv->tmp_result[0];

    return ret;
}
NCE_S32 fc_fk_alg::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg
