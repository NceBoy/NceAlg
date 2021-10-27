/*
 * @Author: your name
 * @Date: 2021-08-31 15:24:33
 * @LastEditTime: 2021-10-27 12:23:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NceAlg\nce_alg\alg\nce_alg_c.h
 */
#ifndef __NCE_ALG_C_H__
#define __NCE_ALG_C_H__
#include "alg_type.h"

#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */
#define PARAM_NUM_MAX 8
#define IMG_NUM_MAX 8
/*typedef struct nce_alg_c_machine
{
    NCE_PTR  pPriv;
} */
typedef struct nce_alg_c_img_process_param
{
    NCE_U32           param_num;
    ImageProcessParam params[PARAM_NUM_MAX];
} nce_alg_c_img_process_param;

typedef struct nce_alg_c_img_infos
{
    NCE_U32           img_info_num;
    img_info          infos[IMG_NUM_MAX];
} nce_alg_c_img_infos;  

typedef NCE_S32 (*nce_alg_c_init)(NCE_PTR pPriv, param_info *st_param_info, nce_alg_c_img_infos *st_img_info);

typedef NCE_S32 (*nce_alg_c_cfg_set)(NCE_PTR pPriv, task_config_info *st_task_config_info);

typedef NCE_S32 (*nce_alg_c_inference)(NCE_PTR pPriv, img_t **pc_img,int num);

typedef NCE_S32 (*nce_alg_c_get_result)(NCE_PTR pPriv, alg_result_info *results);

typedef NCE_S32 (*nce_alg_c_process_set)(NCE_PTR pPriv, nce_alg_c_img_process_param *img_proc_params);

typedef NCE_S32 (*nce_alg_c_destroy)(NCE_PTR pPriv);

typedef struct nce_alg_c_machine
{
    NCE_PTR               pPriv;
    taskcls               clstype;
    platform              platformtype;
    nce_alg_c_init        init_func;
    nce_alg_c_cfg_set     cfg_set_func;
    nce_alg_c_inference   inference_func;
    nce_alg_c_process_set process_set_func;
    nce_alg_c_get_result  getResult_func;
    nce_alg_c_destroy     destroy_func;

} nce_alg_c_machine;

NCE_S32 nce_alg_c_machine_int(nce_alg_c_machine *machine);
NCE_S32 nce_alg_c_machine_destroy(nce_alg_c_machine *machine);


//读进来的是package，操作都需要在pacakge上完成
NCE_S32 nce_c_read_img(const char *img_path, img_t *input_img);

NCE_S32 nce_c_write_img(const char *img_path, img_t *input_img);

NCE_S32 nce_c_free_img(img_t *input_img);

NCE_S32 nce_c_draw_bbox(img_t *input_img, Bbox box);

NCE_S32 nce_c_package2planner(img_t *input_img);

NCE_S32 nce_c_planner2package(img_t *input_img);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */