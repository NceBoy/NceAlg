#include "alg_type.h"
#include "nce_alg.hpp"
#include "IAlg.hpp"
#include "IEngine.hpp"
#include "factory.hpp"
#include "nce_tensor.hpp"
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
    shared_ptr<IEngine>                        pEngine;
    shared_ptr<IAlg>                           pAlg;
    LinkedHashMap<string, tmp_map_result> tmp_map;
    std::map<int, base_process_create>         img_process_map = {
        { PROC_PACKAGE2PLANNER, nce_package2planner::create_instance },
        { PROC_PLANNER2PACKAGE, nce_planner2package::create_instance },
        { PROC_NORMALIZATION, nce_normalization::create_instance },
        { PROC_RESIZE, nce_resize::create_instance },
    };
    std::vector<nce_base_process *> img_pre_processes;

    vector<input_tensor_info> ImageInfo;
    dynamic_factory()
    {}
    ~dynamic_factory()
    {}
};

nce_alg_machine::nce_alg_machine(taskcls alg_type, const platform engine_type)
{

    pPriv          = shared_ptr<dynamic_factory>(new nce_alg_machine::dynamic_factory());
    auto map = NceFactory<IAlg>::GetReigistMap();
    pPriv->pAlg = NceFactory<IAlg>::GetInstance()->CreateObject(alg_type);
    pPriv->pEngine = NceFactory<IEngine>::GetInstance()->CreateObject(engine_type);
}

NCE_S32 nce_alg_machine::nce_alg_init(const param_info &st_param_info, vector<img_info> &st_img_infos)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = pPriv->pAlg->alg_init(pPriv->ImageInfo, pPriv->tmp_map);
    ret         = pPriv->pEngine->engine_init(st_param_info, pPriv->ImageInfo, pPriv->tmp_map);

    for (auto info : pPriv->ImageInfo)
    {
        img_info tmp;
        tmp.u32Width   = info.width;
        tmp.u32Height  = info.height;
        tmp.u32channel = info.channel;
        tmp.order      = info.order;
        tmp.format     = info.format;
    }

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
    for (auto &iter : pre_proc_cfg)
    {
        pPriv->img_pre_processes.push_back(pPriv->img_process_map[iter.type](iter));
    }
    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_img_convert(img_t &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    for (int k = 0; k < pPriv->img_pre_processes.size(); k++)
    {
        pPriv->img_pre_processes[k]->forward(pc_img);
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


    for (NCE_U32 i = 0; i < pPriv->ImageInfo.size(); i++)
    {
        if (pc_imgs[i].image_attr.u32Height != pPriv->ImageInfo[i].height
            || pc_imgs[i].image_attr.u32Width != pPriv->ImageInfo[i].width
            || pc_imgs[i].image_attr.u32channel != pPriv->ImageInfo[i].channel
            || pc_imgs[i].image_attr.format != pPriv->ImageInfo[i].format
            || pc_imgs[i].image_attr.order != pPriv->ImageInfo[i].order)
        {
            printf("[%d] input size doesn't fit the [%d] model input\n", i, i);
            printf("your param:   h %d w %d c %d order %d format %d\n",
                   pc_imgs[i].image_attr.u32Height,
                   pc_imgs[i].image_attr.u32Width,
                   pc_imgs[i].image_attr.u32channel,
                   pc_imgs[i].image_attr.order,
                   pc_imgs[i].image_attr.format);
            printf("should param: h %d w %d c %d order %d format %d\n",
                   pPriv->ImageInfo[i].height,
                   pPriv->ImageInfo[i].width,
                   pPriv->ImageInfo[i].channel,
                   pPriv->ImageInfo[i].order,
                   pPriv->ImageInfo[i].format);
            return NCE_FAILED;
        }
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
    for (auto &iter : pPriv->img_pre_processes)
    {
        delete iter;
    }
    return ret;
}

} // namespace nce_alg