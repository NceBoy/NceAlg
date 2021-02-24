#include "nce_alg.hpp"
#include "ttf.hpp"
#include "engine_manager.hpp"

#define __strcat_task_cls(ALG, ENGINE) ALG##_##ENGINE
#define strcat_task_cls(ALG, ENGINE) __strcat_task_cls(ALG, ENGINE)

using namespace std;
namespace nce_alg
{
    shared_ptr<IAlg> alg_manager(taskcls st_taskcls)
    {
        shared_ptr<IAlg> alg_ptr;
        switch(st_taskcls)
        {
            case PERSON_HEAD:
                alg_ptr = shared_ptr<IAlg>(new strcat_task_cls(ttf, PLATFORM)());
                break;

            case PERSON_FACE:
                alg_ptr = shared_ptr<IAlg>(new strcat_task_cls(ttf, PLATFORM)());
                break; 
            case FACE_FAKE:
                alg_ptr = shared_ptr<IAlg>(new strcat_task_cls(ttf, PLATFORM)());
                break; 
            default:
                alg_ptr = shared_ptr<IAlg>(new strcat_task_cls(ttf, PLATFORM)());
                break;         
        }
        return alg_ptr;
    }

    nce_alg_machine::nce_alg_machine(taskcls st_taskcls)
    {
        pPriv = alg_manager(st_taskcls);
    }

    NCE_S32 nce_alg_machine::nce_alg_init(const engine_param_info &st_engine_param_info)
    {
       NCE_S32 ret = NCE_FAILED;
        ret = pPriv->alg_engine_init(st_engine_param_info);
        return ret;
    }
    NCE_S32 nce_alg_machine::nce_alg_cfg_set(const task_config_info &st_task_config_info)
    {
       NCE_S32 ret = NCE_FAILED;
        ret = pPriv->alg_cfg_set(st_task_config_info);
        return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_inference(img_info & pc_img)
    {
       NCE_S32 ret = NCE_FAILED;  
       ret = pPriv->alg_inference(pc_img);
       return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_get_result(alg_result_info & results)
    {
       NCE_S32 ret = NCE_FAILED;  
       ret = pPriv->alg_get_result(results);
       return ret;   
    }

    NCE_S32 nce_alg_machine::nce_alg_destroy()
    {
        NCE_S32 ret = NCE_FAILED;
        ret = pPriv->alg_destroy();
        return ret;
    }

}