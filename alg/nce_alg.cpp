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

    class nce_alg_machine::dynamic_factory
    {
        public:
            shared_ptr<IEngine> pEngine;
            shared_ptr<IAlg> pAlg;
            std::map<int, tmp_map_result> tmp_map;
            img_info ImageInfo;
        dynamic_factory()
        {}
        ~dynamic_factory()
        {}
    };


    nce_alg_machine::nce_alg_machine(taskcls alg_type,const platform engine_type)
    {

        pPriv = shared_ptr<dynamic_factory>(new nce_alg_machine::dynamic_factory());
        pPriv->pAlg = NceFactory::Instance().CreateAlg(alg_type);
	pPriv->pEngine = NceFactory::Instance().CreateEngine(engine_type);

    }

    NCE_S32 nce_alg_machine::nce_alg_init(const param_info &st_param_info,img_info & st_img_info)
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->pAlg->alg_init(st_param_info,pPriv->tmp_map);
        ret = pPriv->pEngine->engine_init(st_param_info,pPriv->ImageInfo,pPriv->tmp_map);
        memcpy(&st_img_info,&pPriv->ImageInfo,sizeof(img_info));
        return ret;
    }
    NCE_S32 nce_alg_machine::nce_alg_cfg_set(const task_config_info &st_task_config_info)
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->pAlg->alg_cfg_set(st_task_config_info);
        return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_inference(img_t & pc_img)
    {
       NCE_S32 ret = NCE_FAILED;  
       if(pc_img.image_attr.format != pPriv->ImageInfo.format||
            pc_img.image_attr.u32channel != pPriv->ImageInfo.u32channel||
            pc_img.image_attr.u32Height != pPriv->ImageInfo.u32Height||
            pc_img.image_attr.u32Width != pPriv->ImageInfo.u32Width||
            pc_img.image_attr.order != pPriv->ImageInfo.order)
        {
            printf("model image_info doesn't match input image_info\n");
            printf("your param: h %d w %d c %d order %d format %d\n",pc_img.image_attr.u32Height,
            pc_img.image_attr.u32Width,pc_img.image_attr.u32channel,pc_img.image_attr.order,pc_img.image_attr.format);
            printf("should param: h %d w %d c %d order %d format %d\n",pPriv->ImageInfo.u32Height,pPriv->ImageInfo.u32Width,
            pPriv->ImageInfo.u32channel,pPriv->ImageInfo.order,pPriv->ImageInfo.format);
            ret = pPriv->pAlg->alg_inference(pc_img);//后续可以将这个函数改为预处理函数
            //return ret;
        }
        ret = pPriv->pEngine->engine_inference(pc_img);
       

       return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_get_result(alg_result_info & results)
    {
       NCE_S32 ret = NCE_FAILED;  
       ret = pPriv->pEngine->engine_get_result(pPriv->tmp_map);
       ret = pPriv->pAlg->alg_get_result(results,pPriv->tmp_map);
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
