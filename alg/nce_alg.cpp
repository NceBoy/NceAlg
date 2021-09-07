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
namespace nce_alg {
typedef nce_base_process *(*base_process_create)(ImageProcessParam param);

class nce_alg_machine::dynamic_factory
{
public:
    shared_ptr<IEngine>                pEngine;
    shared_ptr<IAlg>                   pAlg;
    std::map<int, tmp_map_result>      tmp_map;
    std::map<int, base_process_create> img_process_map = {
        { PROC_PACKAGE2PLANNER, create_instance<nce_package2planner> },
        { PROC_PLANNER2PACKAGE, create_instance<nce_planner2package> },
        { PROC_NORMALIZATION, create_instance<nce_normalization> },
    };
    std::vector<nce_base_process *> img_pre_processes;

    vector<img_info> ImageInfo;
    dynamic_factory()
    {
        memset(&ImageInfo, 0, sizeof(img_info));
    }
    ~dynamic_factory()
    {}
};

nce_alg_machine::nce_alg_machine(taskcls alg_type, const platform engine_type)
{

    pPriv          = shared_ptr<dynamic_factory>(new nce_alg_machine::dynamic_factory());
    auto map_alg = NceFactory::Instance()._create_alg_function_map;
    auto map_engine = NceFactory::Instance()._create_alg_function_map;
    pPriv->pAlg    = NceFactory::Instance().CreateAlg(alg_type);
    pPriv->pEngine = NceFactory::Instance().CreateEngine(engine_type);
}

NCE_S32 nce_alg_machine::nce_alg_init(const param_info &st_param_info, vector<img_info> &st_img_infos)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = pPriv->pAlg->alg_init(st_img_infos, pPriv->tmp_map);
    ret         = pPriv->pEngine->engine_init(st_param_info, st_img_infos, pPriv->tmp_map);

    memcpy(&pPriv->ImageInfo, &st_img_infos, sizeof(img_info) * st_img_infos.size());

    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_cfg_set(const task_config_info &st_task_config_info)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = pPriv->pAlg->alg_cfg_set(st_task_config_info);

    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_process_set(std::vector<ImageProcessParam> &pre_proc_cfg)
{
    pPriv->img_pre_processes.clear();
    NCE_S32 ret = NCE_FAILED;
    for (auto iter : pre_proc_cfg)
    {
        pPriv->img_pre_processes.push_back(pPriv->img_process_map[iter.type](iter));
    }
    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_inference(vector<img_t> &pc_imgs)
{
    if (pc_imgs.size() != pPriv->ImageInfo.size())
    {
        printf("input num should equal model input num!!! \n");
        return NCE_FAILED;
    }
    NCE_S32 ret = NCE_FAILED;
    for (auto iter : pPriv->img_pre_processes)
    {
        for (auto img : pc_imgs)
        {
            iter->forward(img);
        }
    }

    for (NCE_U32 i = 0; i < pPriv->ImageInfo.size(); i++)
    {
        if (pc_imgs[i].image_attr.u32Height != pPriv->ImageInfo[i].u32Height
            || pc_imgs[i].image_attr.u32Width != pPriv->ImageInfo[i].u32Width
            || pc_imgs[i].image_attr.u32channel != pPriv->ImageInfo[i].u32channel
            || pc_imgs[i].image_attr.format != pPriv->ImageInfo[i].format)
        {
            printf("[%d] input size doesn't fit the [%d] model input\n", i, i);
        }

        printf("your param:   h %d w %d c %d order %d format %d\n",
               pc_imgs[i].image_attr.u32Height,
               pc_imgs[i].image_attr.u32Width,
               pc_imgs[i].image_attr.u32channel,
               pc_imgs[i].image_attr.order,
               pc_imgs[i].image_attr.format);
        printf("should param: h %d w %d c %d order %d format %d\n",
               pPriv->ImageInfo[i].u32Height,
               pPriv->ImageInfo[i].u32Width,
               pPriv->ImageInfo[i].u32channel,
               pPriv->ImageInfo[i].order,
               pPriv->ImageInfo[i].format);
    }

    ret = pPriv->pEngine->engine_inference(pc_imgs);

    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_get_result(alg_result_info &results)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = pPriv->pEngine->engine_get_result(pPriv->tmp_map);
    ret         = pPriv->pAlg->alg_get_result(results, pPriv->tmp_map);

    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = pPriv->pEngine->engine_destroy();
    ret         = pPriv->pAlg->alg_destroy();

    return ret;
}

} // namespace nce_alg