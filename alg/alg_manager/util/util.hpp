#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>
#include "alg_type.h"
#include<vector>
#ifdef __cplusplus
#if __cplusplus

extern "C"
{
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg
{
	NCE_S32 nms(vector<alg_result> input, vector<alg_result> &output, float threshold);
	NCE_S32 RB_REPLACE_PACKAGE(img_t & frame);
	NCE_S32 RB_REPLACE_PLANNER(img_t & frame);
	NCE_S32 softmax(NCE_U32 dim, NCE_F32* score);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
