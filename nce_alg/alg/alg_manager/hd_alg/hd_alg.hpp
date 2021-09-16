#ifndef __HD_ALG_HPP__
#define __HD_ALG_HPP__

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include "alg_type.h"
#include "self_type.hpp"
#include "IAlg.hpp"
#include "factory.hpp"

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
class hd_alg_priv
{
public:
    task_config_info    alg_cfg;
    vector<alg_result>  tmp_result;
    vector<person_head> head_info;
    NCE_S32             u32Stride;
    img_info            model_image_info;

    hd_alg_priv();
};

class hd_alg : public IAlg, public NceAlgCreator<hd_alg, PERSON_HEAD>
{
public:
    hd_alg();

    NCE_S32 alg_init(vector<input_tensor_info> &st_tensor_infos, unordered_map<string, tmp_map_result> &st_result_map);

    NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info);

    NCE_S32 alg_inference(vector<img_t> &pc_img);

    NCE_S32 alg_get_result(alg_result_info &results, unordered_map<string, tmp_map_result> &st_result_map);

    NCE_S32 alg_destroy();

protected:
    shared_ptr<hd_alg_priv> pPriv;
};

} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
