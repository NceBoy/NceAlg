#include<iostream>
#include"engine_manager.hpp"
#include<string>
#include<vector>
#include "fc_fk_alg.hpp"
#include<memory>
#include "IEngine.hpp"
#include<string.h>
//TODO:去除打印

using namespace std;
namespace nce_alg
{
	
	fc_fk_alg_priv::fc_fk_alg_priv()
	{
		alg_cfg.threshold = 0.3;
		alg_cfg.isLog = false;
		score = new NCE_F32[3];
		input_info = NULL;
		memset(&tmp_result,0,sizeof(alg_result));
		memset(&head_info,0,sizeof(person_head));
		memset(&model_image_info,0,sizeof(img_info));
	}

	NCE_S32 fc_fk_alg_priv::alg_priv_engine_init()
	{
		engine_manager(engine_ptr);
		return NCE_SUCCESS;
	}

	fc_fk_alg_priv::~fc_fk_alg_priv()
	{
		delete score;
	}
   

    NCE_S32 fc_fk_alg::alg_engine_init(const engine_param_info &st_engine_param_info)
    {
        NCE_S32 ret = NCE_FAILED;
		pPriv = shared_ptr<fc_fk_alg_priv>(new fc_fk_alg_priv());
        ret = pPriv->alg_priv_engine_init();
        ret = pPriv->engine_ptr->engine_init(st_engine_param_info, pPriv->model_image_info);

        return ret;
    }

    NCE_S32 fc_fk_alg::alg_cfg_set(const task_config_info &st_task_config_info)
    {
        NCE_S32 ret = NCE_FAILED;

        pPriv->alg_cfg.threshold				   = st_task_config_info.threshold;
		pPriv->alg_cfg.st_cfg.hd_config.nms_thresh = st_task_config_info.st_cfg.hd_config.nms_thresh;
        pPriv->alg_cfg.isLog					   = st_task_config_info.isLog;
        return ret;
    }  

    NCE_S32 fc_fk_alg::alg_inference(img_info & pc_img)
    {
        NCE_S32 ret = NCE_FAILED;
		printf("Begin alg_inference\n");
		if (pPriv->model_image_info.u32channel != pc_img.u32channel ||
			pPriv->model_image_info.u32Height != pc_img.u32Height ||
			pPriv->model_image_info.u32Width != pc_img.u32Width)
		{
			printf("model image_info doesn't match input image_info");
			return ret;
		}

        ret = pPriv->engine_ptr->engine_inference(pc_img);
		pPriv->input_info = &pc_img;
		printf("finish alg_inference\n");
        return ret;
    }

    NCE_S32 fc_fk_alg::alg_destroy()
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->engine_ptr->engine_destroy();
        return ret;
    }

}

