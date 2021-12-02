/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-09-06 18:35:37
 */
#ifndef __BODY_NMS_HOOK_HPP__
#define __BODY_NMS_HOOK_HPP__

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
class body_nms_hook : public Hook, public NceCreator<body_nms_hook, Hook, BODY_NMS>
{

public:
    body_nms_hook();

    NCE_S32 hook_init(YAML::Node &config);

    NCE_S32 after_alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map);

    bool _is_overlap(detect_result &bbox1, detect_result &bbox2);

private:
    NCE_F32     nms_thresh;
    NCE_F32     small_thresh;
    NCE_F32     height_thresh;
    bool        is_body;
    YAML::Node *pconfig;
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI_3516DV300_HPP__ */
