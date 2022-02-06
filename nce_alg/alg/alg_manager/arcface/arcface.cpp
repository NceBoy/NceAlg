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
#include "arcface/arcface.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include <algorithm>
#include <cmath>
#include "util/util.hpp"

using namespace std;
namespace nce_alg {

NCE_S32 arcface::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                          LinkedHashMap<string, tmp_map_result> &st_result_map,
                          YAML::Node &                           config)
{
    pPriv               = shared_ptr<arcface_priv>(new arcface_priv);
    NCE_S32 ret         = NCE_FAILED;
    pPriv->face_id.dims = config["dims"].as<NCE_S32>();
    const auto names    = config["output_names"];
    for (auto &iter : names)
    {
        st_result_map.insert(make_pair(iter.as<string>(), tmp_map_result{ 0 }));
    }

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    const auto mean0 = config["mean0"];
    const auto std0  = config["std0"];

    for (NCE_S32 i = 0; i < 3; i++)
    {
        input0.mean[i] = mean0[i].as<float>();
        input0.std[i]  = std0[i].as<float>();
    }
    st_tensor_infos.push_back(input0);

    printf("finshed alg init\n!");
    return ret;
}

NCE_S32 arcface::alg_cfg_set(const task_config_info &st_task_config_info)
{
    return NCE_SUCCESS;
}
NCE_S32 arcface::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 arcface::alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    results.num = 1;

    NCE_S32         ret    = NCE_SUCCESS;
    static NCE_F32 *feat   = (NCE_F32 *)st_result_map["face_id"].pu32Feat;
    pPriv->face_id.face_id = feat;
    pPriv->tmp_result.type = ARC_FACE;
    pPriv->tmp_result.obj  = (FaceID *)(&pPriv->face_id);
    results.st_alg_results = &pPriv->tmp_result;
    return ret;
}
NCE_S32 arcface::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg
