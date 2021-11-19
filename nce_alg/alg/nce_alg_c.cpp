/*
 * @Author: your name
 * @Date: 2021-09-06 16:37:12
 * @LastEditTime: 2021-11-19 16:30:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NceAlg\nce_alg\alg\nce_alg_c.cpp
 */
#include "nce_alg_c.h"
#include "nce_alg.hpp"
#include "common.h"
#include "string.h"
using namespace nce_alg;

static NCE_S32 nce_alg_init_self(NCE_PTR pPriv, param_info *st_param_info, nce_alg_c_img_infos *st_img_info)
{
    NCE_S32               ret  = NCE_FAILED;
    nce_alg_machine *     self = (nce_alg_machine *)pPriv;
    std::vector<img_info> img_infos;
    if(st_param_info->priv_cfg_path != NULL)
        ret                       = self->nce_alg_init(st_param_info->priv_cfg_path, img_infos);
    else
        ret                       = self->nce_alg_init(*st_param_info, img_infos);
    st_img_info->img_info_num = img_infos.size();
    memcpy(&st_img_info->infos[0], &img_infos[0], sizeof(img_info) * st_img_info->img_info_num);
    return ret;
}

static NCE_S32 nce_alg_cfg_set_self(NCE_PTR pPriv, task_config_info *st_task_config_info)
{

    NCE_S32          ret  = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret                   = self->nce_alg_cfg_set(*st_task_config_info);
    return ret;
}

static NCE_S32 nce_alg_inference_self(NCE_PTR pPriv, img_t **pc_img, int num)
{
    int                i    = 0;
    NCE_S32            ret  = NCE_FAILED;
    nce_alg_machine *  self = (nce_alg_machine *)pPriv;
    std::vector<img_t> imgs;
    for (i = 0; i < num; i++)
    {
        imgs.push_back(*pc_img[i]);
    }
    ret = self->nce_alg_inference(imgs);
    return ret;
}

static NCE_S32 nce_alg_get_result_self(NCE_PTR pPriv, alg_result_info *results)
{

    NCE_S32          ret  = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret                   = self->nce_alg_get_result(*results);
    return ret;
}

static NCE_S32 nce_alg_process_set_self(NCE_PTR pPriv, nce_alg_c_img_process_param *img_proc_params)
{
    NCE_S32                        ret  = NCE_FAILED;
    nce_alg_machine *              self = (nce_alg_machine *)pPriv;
    NCE_S32                        i    = 0;
    std::vector<ImageProcessParam> preprocesses;
    for (i = 0; i < img_proc_params->param_num; i++)
    {
        preprocesses.push_back(img_proc_params->params[i]);
    }
    ret = self->nce_alg_process_set(preprocesses);
    return NCE_SUCCESS;
}

static NCE_S32 nce_alg_destroy_self(NCE_PTR pPriv)
{

    NCE_S32          ret  = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret                   = self->nce_alg_destroy();
    return ret;
}

NCE_S32 nce_alg_c_machine_init(nce_alg_c_machine *machine)
{

    machine->init_func        = nce_alg_init_self;
    machine->cfg_set_func     = nce_alg_cfg_set_self;
    machine->inference_func   = nce_alg_inference_self;
    machine->getResult_func   = nce_alg_get_result_self;
    machine->process_set_func = nce_alg_process_set_self;
    machine->destroy_func     = nce_alg_destroy_self;
    machine->pPriv            = (NCE_PTR) new nce_alg_machine(machine->clstype, machine->platformtype);
    return NCE_SUCCESS;
}
NCE_S32 nce_alg_c_machine_deinit(nce_alg_c_machine *machine)
{

    delete (nce_alg_machine *)machine->pPriv;
    return NCE_SUCCESS;
}


//读进来的是package，操作都需要在pacakge上完成
NCE_S32  nce_c_read_img(const char *img_path, img_t *input_img)
{
    nce_read_img(img_path, *input_img);
    return 0;
}

NCE_S32 nce_c_write_img(const char *img_path, img_t *input_img)
{
    nce_write_img(img_path, *input_img);
    return 0;
}

NCE_S32 nce_c_free_img(img_t *input_img)
{
    nce_free_img(*input_img);
    return 0;
}

NCE_S32 nce_c_draw_bbox(img_t *input_img, Bbox box)
{
    NCE_S32 color[3] = { 0, 0, 255 };
    nce_draw_bbox(*input_img, box, 2, color);
    return 0;
}

NCE_S32 nce_c_package2planner(img_t *input_img)
{       
    ImageProcessParam              package2planner;
    package2planner.type                              = PROC_PACKAGE2PLANNER;
    package2planner.Info.package2planner_info.channel = input_img->image_attr.u32channel;
    package2planner.Info.package2planner_info.width   = input_img->image_attr.u32Width;
    package2planner.Info.package2planner_info.height  = input_img->image_attr.u32Height;
    
    nce_package2planner doo(package2planner);
    doo.forward(*input_img, *input_img);
    return NCE_SUCCESS;
}

NCE_S32 nce_c_planner2package(img_t *input_img)
{
    ImageProcessParam planner2package;
    planner2package.type                              = PROC_PLANNER2PACKAGE;
    planner2package.Info.planner2package_info.channel = input_img->image_attr.u32channel;
    planner2package.Info.planner2package_info.width   = input_img->image_attr.u32Width;
    planner2package.Info.planner2package_info.height  = input_img->image_attr.u32Height;

    nce_planner2package doo(planner2package);
    doo.forward(*input_img, *input_img);
	return NCE_SUCCESS;
}