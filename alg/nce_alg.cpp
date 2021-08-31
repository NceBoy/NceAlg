#include "alg_type.h"
#include "nce_alg.hpp"
#include "IAlg.hpp"
#include "IEngine.hpp"
#include "factory.hpp"
#include "self_type.hpp"
#include "hd_alg.hpp"
#include <map>
#include <cstring>

/*祭奠一下宏定义拼接的实现方案*/
/*#define __strcat_task_cls(ALG, ENGINE) ALG##_##ENGINE
#define strcat_task_cls(ALG, ENGINE) __strcat_task_cls(ALG, ENGINE)
*/

using namespace std;
namespace nce_alg
{    
    typedef nce_base_process* (*base_process_create)(ImageProcessParam param);

    class nce_alg_machine::dynamic_factory
    {
        public:
            shared_ptr<IEngine> pEngine;
            shared_ptr<IAlg> pAlg;
            std::map<int, tmp_map_result>      tmp_map;
            std::map<int, base_process_create> img_process_map = 
            {
                {PROC_PACKAGE2PLANNER, create_instance<nce_package2planner>},
                {PROC_PLANNER2PACKAGE, create_instance<nce_planner2package>},
                {PROC_NORMALIZATION,  create_instance<nce_normalization>},
            };
            std::vector<nce_base_process*> img_pre_processes;

            img_info ImageInfo;
        dynamic_factory()
        {
            memset(&ImageInfo,0,sizeof(img_info));
        }
        ~dynamic_factory()
        {}
    };


    nce_alg_machine::nce_alg_machine(taskcls alg_type,const platform engine_type)
    {

        pPriv          = shared_ptr<dynamic_factory>(new nce_alg_machine::dynamic_factory());
        pPriv->pAlg    = NceFactory::Instance().CreateAlg(alg_type);
	    pPriv->pEngine = NceFactory::Instance().CreateEngine(engine_type);

    }

    NCE_S32 nce_alg_machine::nce_alg_init(const param_info &st_param_info, img_info & st_img_info)
    {
        NCE_S32 ret = NCE_FAILED;
        ret         = pPriv->pAlg->alg_init(st_param_info,pPriv->tmp_map);
        ret         = pPriv->pEngine->engine_init(st_param_info, pPriv->ImageInfo, pPriv->tmp_map);

        memcpy(&st_img_info, &pPriv->ImageInfo,sizeof(img_info));

        return ret;
    }

    NCE_S32 nce_alg_machine::nce_alg_cfg_set(const task_config_info &st_task_config_info)
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->pAlg->alg_cfg_set(st_task_config_info);

        return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_process_set(std::vector<ImageProcessParam> & pre_proc_cfg)
    {
        pPriv->img_pre_processes.clear();
        NCE_S32 ret = NCE_FAILED;
        for (auto iter:pre_proc_cfg)
        {
            pPriv->img_pre_processes.push_back(pPriv->img_process_map[iter.type](iter));
        }
        return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_inference(img_t & pc_img)
    {

       NCE_S32 ret = NCE_FAILED;
       for (auto iter : pPriv->img_pre_processes)
       {
           iter->forward(pc_img);
       }


        {
            printf("model image_info doesn't match input image_info\n");
            printf("your param:   h %d w %d c %d order %d format %d\n", pc_img.image_attr.u32Height,
            pc_img.image_attr.u32Width, pc_img.image_attr.u32channel,pc_img.image_attr.order,pc_img.image_attr.format);
            printf("should param: h %d w %d c %d order %d format %d\n", pPriv->ImageInfo.u32Height, pPriv->ImageInfo.u32Width,
            pPriv->ImageInfo.u32channel,pPriv->ImageInfo.order,pPriv->ImageInfo.format);
            //ret = pPriv->pAlg->alg_inference(pc_img);//后续可以将这个函数改为预处理函数
            //return ret;
        }

        ret = pPriv->pEngine->engine_inference(pc_img);
       
       return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_get_result(alg_result_info & results)
    {
       NCE_S32 ret = NCE_FAILED;  
       ret = pPriv->pEngine->engine_get_result(pPriv->tmp_map);
       ret = pPriv->pAlg->alg_get_result(results, pPriv->tmp_map);

       return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_destroy()
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->pEngine->engine_destroy();
        ret = pPriv->pAlg->alg_destroy();

        return ret;

    }

}