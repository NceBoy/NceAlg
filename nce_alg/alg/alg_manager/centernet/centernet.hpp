/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:13:03
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-16 16:14:38
 */
#ifndef __CENTERNET_HPP__
#define __CENTERNET_HPP__

#include <iostream>
#include "alg_type.h"
#include "IAlg.hpp"
#include "linkedhashmap.h"
#include "IEngine.hpp"
#include <vector>
#include <memory>
#include "nce_tensor.hpp"
#include "factory.hpp"
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif

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
    NCE_U32                    output_stride;
    centernet_priv();

    ~centernet_priv();

    NCE_S32 alg_priv_engine_init();
};

class centernet : public IAlg, public NceCreator<centernet, IAlg, CENTERNET>
{
public:
    NCE_S32 alg_init(vector<input_tensor_info> &st_tensor_infos, LinkedHashMap<string, tmp_map_result> &st_result_map);
    
    NCE_S32 alg_init(vector<input_tensor_info> &            st_tensor_infos,
                     LinkedHashMap<string, tmp_map_result> &st_result_map,
                     YAML::Node &                           config);
    NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info);

    NCE_S32 alg_inference(vector<img_t> &pc_img);

    NCE_S32 alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map);

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
