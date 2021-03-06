#include "nce_alg_c.h"
#include "nce_alg.hpp"

using namespace nce_alg;

static NCE_S32 nce_alg_init_self(NCE_PTR pPriv, engine_param_info * st_engine_param_info)
{

    NCE_S32 ret = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret = self->nce_alg_init(*st_engine_param_info);
    return ret;

}

static NCE_S32 nce_alg_cfg_set_self(NCE_PTR pPriv,task_config_info * st_task_config_info)
{

    NCE_S32 ret = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret = self->nce_alg_cfg_set(*st_task_config_info);
    return ret;

}

static NCE_S32 nce_alg_inference_self(NCE_PTR pPriv,img_info * pc_img)
{

    NCE_S32 ret = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret = self->nce_alg_inference(*pc_img);
    return ret;

}

static NCE_S32 nce_alg_get_result_self(NCE_PTR pPriv,alg_result_info * results)
{

    NCE_S32 ret = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret = self->nce_alg_get_result(*results);
    return ret;

}

static NCE_S32 nce_alg_destroy_self(NCE_PTR pPriv)
{

    NCE_S32 ret = NCE_FAILED;
    nce_alg_machine *self = (nce_alg_machine *)pPriv;
    ret = self->nce_alg_destroy();
    return ret;

}

NCE_S32 nce_alg_c_machine_int(nce_alg_c_machine *machine)
{

    machine->init_func = nce_alg_init_self;
    machine->cfg_set_func = nce_alg_cfg_set_self;
    machine->inference_func = nce_alg_inference_self;
    machine->getResult_func = nce_alg_get_result_self;
    machine->destroy_func = nce_alg_destroy_self; 
    machine->pPriv = (NCE_PTR)new nce_alg_machine(machine->clstype);
    return NCE_SUCCESS;

}
NCE_S32 nce_alg_c_machine_destroy(nce_alg_c_machine *machine)
{

    delete (nce_alg_machine *)machine->pPriv;
    return NCE_SUCCESS;

}
