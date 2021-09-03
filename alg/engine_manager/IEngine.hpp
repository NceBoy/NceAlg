#ifndef __IENGINE_HPP__
#define __IENGINE_HPP__
#include <iostream>
#include <map>
#include "alg_type.h"
#include "self_type.hpp"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg {

class IEngine
{
public:
    virtual NCE_S32
    engine_init(const param_info &st_param_info, img_info &st_img_info, map<int, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 engine_inference(img_t &pc_img)
    {
        return NCE_FAILED;
    }
    virtual NCE_S32 engine_get_result(map<int, tmp_map_result> &st_engine_result)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 engine_destroy()
    {
        return NCE_FAILED;
    }
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
