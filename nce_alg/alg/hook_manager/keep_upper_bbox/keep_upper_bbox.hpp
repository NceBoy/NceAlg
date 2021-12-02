/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-09-06 18:35:37
 */
#ifndef __KEEP_UPPER_BBOX_HPP__
#define __KEEP_UPPER_BBOX_HPP__

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
class keep_upper_bbox : public Hook, public NceCreator<keep_upper_bbox, Hook, REFLECTION_FILTER>
{
public:
    keep_upper_bbox();

    NCE_S32 hook_init(YAML::Node &config);

    NCE_S32 after_alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map);

    NCE_S32 before_engine_inference(vector<img_t> &pc_imgs);

private:
    YAML::Node *pconfig;
    NCE_S32     keep_max;
    NCE_S32     img_width;
    NCE_S32     img_heigth;
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI_3516DV300_HPP__ */
