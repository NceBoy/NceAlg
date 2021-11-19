#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>
#include "alg_type.h"
#include <vector>
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg {
NCE_S32 nms(vector<detect_result> input, vector<detect_result> &output, float threshold);
NCE_S32 RB_REPLACE_PACKAGE(img_t &frame);
NCE_S32 RB_REPLACE_PLANNER(img_t &frame);
NCE_S32 softmax(NCE_U32 dim, NCE_F32 *score);
NCE_S32 refelction_judge(const img_t &          frame,
                         alg_result_info        &results,
                         NCE_F32                conf_thresh,
                         NCE_F32                mean_thresh,
                         NCE_F32                var_thresh);
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
