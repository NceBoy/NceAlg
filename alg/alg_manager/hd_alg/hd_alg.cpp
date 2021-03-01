#include<iostream>
#include"engine_manager.hpp"
#include<string>
#include<vector>
#include "hd_alg.hpp"
#include<memory>
#include "IEngine.hpp"

using namespace std;
namespace nce_alg
{

	hd_alg_priv::hd_alg_priv()
	{
		alg_cfg.threshold = 0.3;
		alg_cfg.st_cfg.hd_config.nms_thresh = 0.6;
		alg_cfg.isLog = false;
		input_info = NULL;
        	u32Stride = 0;
        	memset(&model_image_info,0,sizeof(img_info));
	}

	NCE_S32 hd_alg_priv::alg_priv_engine_init()
	{
		engine_manager(engine_ptr);
		return NCE_SUCCESS;
	}
    
   

    NCE_S32 hd_alg::alg_engine_init(const engine_param_info &st_engine_param_info)
    {
        NCE_S32 ret = NCE_FAILED;
		pPriv = shared_ptr<hd_alg_priv>(new hd_alg_priv());
        ret = pPriv->alg_priv_engine_init();
        ret = pPriv->engine_ptr->engine_init(st_engine_param_info, pPriv->model_image_info);
        return ret;
    }

    NCE_S32 hd_alg::alg_cfg_set(const task_config_info &st_task_config_info)
    {
        NCE_S32 ret = NCE_FAILED;

        pPriv->alg_cfg.threshold				   = st_task_config_info.threshold;
		pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
        pPriv->alg_cfg.isLog					   = st_task_config_info.isLog;
        return ret;
    }  

    NCE_S32 hd_alg::alg_inference(img_info & pc_img)
    {
        NCE_S32 ret = NCE_FAILED;
		if (pPriv->model_image_info.u32channel != pc_img.u32channel ||
			pPriv->model_image_info.u32Height != pc_img.u32Height ||
			pPriv->model_image_info.u32Width != pc_img.u32Width)
		{
			printf("model image_info doesn't match input image_info");
			return ret;
		}
        ret = pPriv->engine_ptr->engine_inference(pc_img);
		pPriv->input_info = &pc_img;
        return ret;
    }

    NCE_S32 hd_alg::alg_destroy()
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->engine_ptr->engine_destroy();
        return ret;
    }

}

