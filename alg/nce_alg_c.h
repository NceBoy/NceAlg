#ifndef __NCE_ALG_C_H__
#define __NCE_ALG_C_H__
#include "alg_type.h"

#ifdef __cplusplus
#if __cplusplus

extern "C"{
#endif
#endif /* __cplusplus */

/*typedef struct nce_alg_c_machine
{
    NCE_PTR  pPriv;
} */

typedef NCE_S32 (*nce_alg_c_init)(NCE_PTR pPriv,engine_param_info * st_engine_param_info);

typedef NCE_S32 (*nnce_alg_c_cfg_set)(NCE_PTR pPriv,task_config_info * st_task_config_info);

typedef NCE_S32 (*nce_alg_c_inference)(NCE_PTR pPriv,img_info * pc_img);

typedef NCE_S32 (*nce_alg_c_get_result)(NCE_PTR pPriv,alg_result_info * results);

typedef NCE_S32 (*nce_alg_c_destroy)(NCE_PTR pPriv);

typedef struct nce_alg_c_machine
{
    NCE_PTR  pPriv;
    taskcls  clstype;
    nce_alg_c_init init_func;
    nnce_alg_c_cfg_set cfg_set_func;
    nce_alg_c_inference inference_func;
    nce_alg_c_get_result getResult_func;
    nce_alg_c_destroy destroy_func;

}nce_alg_c_machine;

NCE_S32 nce_alg_c_machine_int(nce_alg_c_machine *machine);
NCE_S32 nce_alg_c_machine_destroy(nce_alg_c_machine *machine);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */