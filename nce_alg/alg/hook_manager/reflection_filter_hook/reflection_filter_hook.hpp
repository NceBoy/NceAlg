/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-01-20 19:48:03
 */
#ifndef __REFLECTION_FILTER_HOOK_HPP__
#define __REFLECTION_FILTER_HOOK_HPP__

#include <alg_type.h>
#include "hook.hpp"
#include <map>
#include <memory>
#include "factory.hpp"
#include "linkedhashmap.h"
#ifdef __cplusplus
#if __cplusplus

using namespace std;
extern "C" {
#endif
#endif /* __cplusplus */

namespace nce_alg {
class reflection_filter_hook : public Hook, public NceCreator<reflection_filter_hook, Hook, REFLECTION_FILTER>
{
public:
    reflection_filter_hook();

    NCE_S32 hook_init(YAML::Node &config);

    NCE_S32 before_engine_inference(vector<img_t> &pc_imgs);

    NCE_S32 after_alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map);

private:
    NCE_F32     mean_thresh;
    NCE_F32     var_thresh;
    NCE_F32     conf_thresh;
    //todo async for pingpongbuffer
    img_t       pcur_img;
    YAML::Node *pconfig;
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI_3516DV300_HPP__ */
