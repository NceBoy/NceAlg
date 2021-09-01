#ifndef __NCE_ALG_C_H__
#define __NCE_ALG_C_H__
#include "alg_type.h"

#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */
#define PARAM_NUM_MAX 8
/*typedef struct nce_alg_c_machine
{
    NCE_PTR  pPriv;
} */
typedef struct nce_alg_c_img_process_param
{
    NCE_U32           param_num;
    ImageProcessParam params[PARAM_NUM_MAX];
} nce_alg_c_img_process_param;

typedef NCE_S32 (*nce_alg_c_init)(NCE_PTR pPriv, param_info *st_param_info, img_info *st_img_info);

typedef NCE_S32 (*nnce_alg_c_cfg_set)(NCE_PTR pPriv, task_config_info *st_task_config_info);

typedef NCE_S32 (*nce_alg_c_inference)(NCE_PTR pPriv, img_t *pc_img);

typedef NCE_S32 (*nce_alg_c_get_result)(NCE_PTR pPriv, alg_result_info *results);

typedef NCE_S32 (*nce_alg_c_process_set)(NCE_PTR pPriv, nce_alg_c_img_process_param *img_proc_params);

typedef NCE_S32 (*nce_alg_c_destroy)(NCE_PTR pPriv);

typedef struct nce_alg_c_machine
{
    NCE_PTR               pPriv;
    taskcls               clstype;
    platform              platformtype;
    nce_alg_c_init        init_func;
    nnce_alg_c_cfg_set    cfg_set_func;
    nce_alg_c_inference   inference_func;
    nce_alg_c_process_set process_set_func;
    nce_alg_c_get_result  getResult_func;
    nce_alg_c_destroy     destroy_func;

} nce_alg_c_machine;

NCE_S32 nce_alg_c_machine_int(nce_alg_c_machine *machine);
NCE_S32 nce_alg_c_machine_destroy(nce_alg_c_machine *machine);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */