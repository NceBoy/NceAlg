/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:13:03
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-08-25 11:03:53
 */
#ifndef __CENTERNET_HPP__
#define __CENTERNET_HPP__

#include <iostream>
#include "alg_type.h"
#include "IAlg.hpp"
#include <unordered_map>
#include "IEngine.hpp"
#include <vector>
#include <memory>
#include "self_type.hpp"
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

class centernet_priv
{
public:
    task_config_info           alg_cfg;
    vector<alg_result>         tmp_result;
    vector<detect_result>      detect_results;
    vector<input_tensor_info> *input_tensor_infos;
    NCE_U32                    topk;

    centernet_priv();

    ~centernet_priv();

    NCE_S32 alg_priv_engine_init();
};

class centernet : public IAlg, public NceAlgCreator<centernet, CENTERNET>
{
public:
    NCE_S32 alg_init(vector<input_tensor_info> &st_tensor_infos, unordered_map<string, tmp_map_result> &st_result_map);

    NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info);

    NCE_S32 alg_inference(vector<img_t> &pc_img);

    NCE_S32 alg_get_result(alg_result_info &results, unordered_map<string, tmp_map_result> &st_result_map);

    NCE_S32 alg_destroy();

protected:
    shared_ptr<centernet_priv> pPriv;
};

} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
