#ifndef __FC_FK_ALG_HPP__
#define __FC_FK_ALG_HPP__
#include <iostream>
#include "alg_type.h"
#include "IAlg.hpp"
#include <map>
#include "IEngine.hpp"
#include <vector>
#include <memory>
#include "nce_tensor.hpp"
#include "factory.hpp"
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */


using namespace std;
namespace nce_alg {

class fc_fk_alg_priv
{
public:
    task_config_info    alg_cfg;
    vector<alg_result>  tmp_result;
    vector<person_head> head_info;
    img_info *          input_info;
    NCE_F32 *           score;
    img_info            model_image_info;

    fc_fk_alg_priv();

    ~fc_fk_alg_priv();

    NCE_S32 alg_priv_engine_init();
};

class fc_fk_alg : public IAlg, public NceCreator<fc_fk_alg, IAlg, FACE_FAKE>
{
public:
    NCE_S32 alg_init(const param_info &st_param_info, map<int, tmp_map_result> &st_result_map);

    NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info);

    NCE_S32 alg_inference(img_t &pc_img);

    NCE_S32 alg_get_result(alg_result_info &results, map<int, tmp_map_result> &st_result_map);

    NCE_S32 alg_destroy();

protected:
    shared_ptr<fc_fk_alg_priv> pPriv;
};

} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
