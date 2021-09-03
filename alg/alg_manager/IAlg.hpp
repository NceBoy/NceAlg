#ifndef __IALG_HPP__
#define __IALG_HPP__

#include <iostream>
#include <alg_type.h>
#include "self_type.hpp"
#include <map>
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */

/*
DIR alg_manager
Ialg.hpp
        DIR hd_alg
        hd_dt.hpp(继承IAlg, 实现init、setconfig、inference、destroy)
        DIR ttf
                ttf.cpp(继承hd_dt, 实现getresult)
                ttf.hpp

*/

using namespace std;
namespace nce_alg {
class IAlg
{
public:
    virtual NCE_S32 alg_init(const param_info &st_param_info, map<int, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_inference(img_t &pc_img) //后续改成图片预处理？
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_get_result(alg_result_info &results, map<int, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_destroy()
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

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
