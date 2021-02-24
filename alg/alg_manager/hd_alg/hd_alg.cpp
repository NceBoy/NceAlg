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
	alg_priv::alg_priv()
	{
		alg_cfg.threshold = 0.3;
		alg_cfg.st_cfg.hd_config.nms_thresh = 0.6;
		alg_cfg.isLog = false;
		//alg_cfg.hd_config.....
	}

	NCE_S32 alg_priv::alg_priv_engine_init()
	{
		engine_manager(engine_ptr);
		return NCE_SUCCESS;
	}
    
   

    NCE_S32 hd_alg::alg_engine_init(const engine_param_info &st_engine_param_info)
    {
        NCE_S32 ret = NCE_FAILED;
		pPriv = shared_ptr<alg_priv>(new alg_priv());
        ret = pPriv->alg_priv_engine_init();
        ret = pPriv->engine_ptr->engine_init(st_engine_param_info);

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

