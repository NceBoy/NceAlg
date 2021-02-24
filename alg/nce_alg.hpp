#ifndef __NCE_ALG_HPP__
#define __NCE_ALG_HPP__
#include "IAlg.hpp"
#include "memory"
#ifdef __cplusplus
#if __cplusplus

extern "C"{
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg
{
    class nce_alg_machine
    {
    public:

        nce_alg_machine(taskcls st_taskcls);

        NCE_S32 nce_alg_init(const engine_param_info &st_engine_param_info);

        NCE_S32 nce_alg_cfg_set(const task_config_info & st_task_config_info);

        NCE_S32 nce_alg_inference(img_info & pc_img);

        NCE_S32 nce_alg_get_result(alg_result_info & results);

        NCE_S32 nce_alg_destroy();

    private:
        shared_ptr<IAlg> pPriv;

    };
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */