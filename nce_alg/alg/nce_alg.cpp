#include "alg_type.h"
#include "nce_alg.hpp"
#include "IAlg.hpp"
#include "IEngine.hpp"
#include "factory.hpp"
#include "nce_tensor.hpp"
#include <map>
#include <cstring>
#include "yaml-cpp/yaml.h"
#include "hook.hpp"
/*祭奠一下宏定义拼接的实现方案*/
/*#define __strcat_task_cls(ALG, ENGINE) ALG##_##ENGINE
#define strcat_task_cls(ALG, ENGINE) __strcat_task_cls(ALG, ENGINE)
*/
#define HOOK_INVOKE(vechook, func_name, ...) \
    {                                        \
        for (auto &hook : vechook)           \
        {                                    \
            hook->func_name(__VA_ARGS__);    \
        }                                    \
    }
using namespace std;
namespace nce_alg {
typedef nce_base_process *(*base_process_create)(ImageProcessParam param);

class nce_alg_machine::dynamic_factory
{
public:
    shared_ptr<IEngine>                             pEngine;
    shared_ptr<IAlg>                                pAlg;
    std::map<std::string, vector<shared_ptr<Hook>>> hook_map;
    LinkedHashMap<string, tmp_map_result>           tmp_map;

    static std::map<NCE_S32, base_process_create> img_process_map;
    static std::map<std::string, custom_hook>     hook_str2enum_map;

    std::vector<nce_base_process *> img_pre_processes;
    YAML::Node                      config;
    vector<input_tensor_info>       ImageInfo;
    vector<img_t>                   privImgs;

    NCE_S32 dynamic_factory_init(YAML::Node &input_config)
    {
        auto hooks = input_config["custom_hook"];
        for (auto i = hooks.begin(); i != hooks.end(); i++)
        {
            auto name = i->first.as<std::string>();
            auto hook = i->second;
            auto iter = hook_str2enum_map.find(name);
            if (iter != hook_str2enum_map.end())
                printf("hook: %s! registered!\n", name.c_str());
            else
            {
                printf("hook: %s! not found!\n", name.c_str());
                return NCE_FAILED;
            }
            custom_hook hook_type = hook_str2enum_map[name];
            auto        hook_ptr  = NceFactory<Hook>::GetInstance()->CreateObject(hook_type);
            if (nullptr == hook_ptr)
            {
                printf("hook create failed! please check target hook: %s is registored\n", name.c_str());
            }
            hook_ptr->hook_init(hook);
            for (auto used_func : hook["used_func"])
            {
                std::string func_name = used_func.as<std::string>();
                hook_map[func_name].push_back(hook_ptr);
            }
        }
        config = input_config;
        return NCE_SUCCESS;
    }
    dynamic_factory()
    {}
    ~dynamic_factory()
    {}

private:
};
std::map<std::string, custom_hook> nce_alg_machine::dynamic_factory::hook_str2enum_map = {
    { "reflection_filter_hook", REFLECTION_FILTER },
    { "body_nms_hook", BODY_NMS },
    { "softmax_hook", SOFTMAX }
};
std::map<NCE_S32, base_process_create> nce_alg_machine::dynamic_factory::img_process_map = {
    { PROC_PACKAGE2PLANNER, nce_package2planner::create_instance },
    { PROC_PLANNER2PACKAGE, nce_planner2package::create_instance },
    { PROC_NORMALIZATION, nce_normalization::create_instance },
    { PROC_RESIZE, nce_resize::create_instance },
};

nce_alg_machine::nce_alg_machine(taskcls alg_type, const platform engine_type)
{

    pPriv = shared_ptr<dynamic_factory>(new nce_alg_machine::dynamic_factory());
    printf("target alg is %d\n", alg_type);
    pPriv->pAlg = NceFactory<IAlg>::GetInstance()->CreateObject(alg_type);
    if (nullptr == pPriv->pAlg) 
    {
        printf("Alg create failed! please check alg type: %d in registered!\n", alg_type);
    }
    printf("target engine is %d\n", engine_type);
    pPriv->pEngine = NceFactory<IEngine>::GetInstance()->CreateObject(engine_type);
    if (nullptr == pPriv->pEngine)
    {
        printf("engine_type create failed! please check engine_type type: %d in registered!\n", engine_type);
    }
}

NCE_S32 nce_alg_machine::nce_alg_init(const char *yaml_path, vector<img_info> &st_img_infos)
{
    auto config        = YAML::LoadFile(yaml_path);
    auto engine_config = config["engine_config"];
    auto alg_config    = config["alg_config"];
    if (NCE_SUCCESS != pPriv->dynamic_factory_init(config))
    {
        printf("hook init error!\n");
    }
    printf("dynamic_factory_init success!\n");
    HOOK_INVOKE(pPriv->hook_map["before_alg_init"], before_alg_init, pPriv->ImageInfo, pPriv->tmp_map, config);
    pPriv->pAlg->alg_init(pPriv->ImageInfo, pPriv->tmp_map, alg_config);
    HOOK_INVOKE(pPriv->hook_map["after_alg_init"], after_alg_init, pPriv->ImageInfo, pPriv->tmp_map, config);
    HOOK_INVOKE(pPriv->hook_map["before_engine_init"], before_engine_init, config, pPriv->ImageInfo, pPriv->tmp_map);
    pPriv->pEngine->engine_init(engine_config, pPriv->ImageInfo, pPriv->tmp_map);
    HOOK_INVOKE(pPriv->hook_map["after_engine_init"], after_engine_init, config, pPriv->ImageInfo, pPriv->tmp_map);

    NCE_S32 count = 0;
    for (auto info : pPriv->ImageInfo)
    {
        img_info tmp;
        tmp.u32Width   = info.width;
        tmp.u32Height  = info.height;
        tmp.u32channel = info.channel;
        tmp.order      = info.order;
        tmp.format     = info.format;
        img_t tmp_img{ 0 };
        tmp_img.image = new NCE_U8[info.width * info.height * info.channel];
        printf("alg init %d %d %d\n", info.width, info.height, info.channel);
        pPriv->privImgs.push_back(tmp_img);

        img_info tmp_img_info;
        tmp_img_info.u32Height  = info.height;
        tmp_img_info.u32Width   = info.width;
        tmp_img_info.u32channel = info.channel;

        st_img_infos.push_back(tmp_img_info);
    }

    return NCE_SUCCESS;
}

NCE_S32 nce_alg_machine::nce_alg_init(const param_info &st_param_info, vector<img_info> &st_img_infos)
{
    NCE_S32 ret = NCE_FAILED;

    ret = pPriv->pAlg->alg_init(pPriv->ImageInfo, pPriv->tmp_map);
    ret = pPriv->pEngine->engine_init(st_param_info, pPriv->ImageInfo, pPriv->tmp_map);

    NCE_S32 count = 0;
    for (auto info : pPriv->ImageInfo)
    {
        img_info tmp;
        tmp.u32Width   = info.width;
        tmp.u32Height  = info.height;
        tmp.u32channel = info.channel;
        tmp.order      = info.order;
        tmp.format     = info.format;
        img_t tmp_img{ 0 };
        tmp_img.image = new NCE_U8[info.width * info.height * info.channel];
        printf("alg init %d %d %d\n", info.width, info.height, info.channel);
        pPriv->privImgs.push_back(tmp_img);

        img_info tmp_img_info;
        tmp_img_info.u32Height  = info.height;
        tmp_img_info.u32Width   = info.width;
        tmp_img_info.u32channel = info.channel;

        st_img_infos.push_back(tmp_img_info);
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

NCE_S32 nce_alg_machine::nce_alg_inference(vector<img_t> &pc_imgs)
{
    for (auto &img : pc_imgs)
    {
        if (img.image == nullptr)
        {
            printf("inference buffer is empty!!!\n");
            return NCE_FAILED;
        }
    }
    int k = 0;
    if (pc_imgs.size() != pPriv->ImageInfo.size())
    {
        printf("input num should equal model input num!!! \n");
        return NCE_FAILED;
    }
    NCE_S32 ret = NCE_FAILED;
    for (k = 0; k < pPriv->img_pre_processes.size(); k++)
    {
        for (int i = 0; i < pc_imgs.size(); i++)
        {
            if (k == 0)
                pPriv->img_pre_processes[k]->forward(pc_imgs[i], pPriv->privImgs[i]);
            else
                pPriv->img_pre_processes[k]->forward(pPriv->privImgs[i], pPriv->privImgs[i]);
        }
    }
    if (k > 0)
    {
        for (NCE_U32 i = 0; i < pPriv->ImageInfo.size(); i++)
        {
            if (pPriv->privImgs[i].image_attr.u32Height != pPriv->ImageInfo[i].height
                || pPriv->privImgs[i].image_attr.u32Width != pPriv->ImageInfo[i].width
                || pPriv->privImgs[i].image_attr.u32channel != pPriv->ImageInfo[i].channel
                || pPriv->privImgs[i].image_attr.format != pPriv->ImageInfo[i].format
                || pPriv->privImgs[i].image_attr.order != pPriv->ImageInfo[i].order)
            {
                printf("[%d] your img preproc is wrong, img doesn't fit the [%d] model input\n", i, i);
                printf("your param:   h %d w %d c %d order %d format %d\n",
                       pPriv->privImgs[i].image_attr.u32Height,
                       pPriv->privImgs[i].image_attr.u32Width,
                       pPriv->privImgs[i].image_attr.u32channel,
                       pPriv->privImgs[i].image_attr.order,
                       pPriv->privImgs[i].image_attr.format);
                printf("should param: h %d w %d c %d order %d format %d\n",
                       pPriv->ImageInfo[i].height,
                       pPriv->ImageInfo[i].width,
                       pPriv->ImageInfo[i].channel,
                       pPriv->ImageInfo[i].order,
                       pPriv->ImageInfo[i].format);
                return NCE_FAILED;
            }
        }
        HOOK_INVOKE(pPriv->hook_map["before_engine_inference"], before_engine_inference, pPriv->privImgs);
        ret = pPriv->pEngine->engine_inference(pPriv->privImgs);
        HOOK_INVOKE(pPriv->hook_map["after_engine_inference"], before_engine_inference, pPriv->privImgs);
    }
    else
    {
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
        HOOK_INVOKE(pPriv->hook_map["before_engine_inference"], before_engine_inference, pc_imgs);
        ret = pPriv->pEngine->engine_inference(pc_imgs);
        HOOK_INVOKE(pPriv->hook_map["after_engine_inference"], before_engine_inference, pc_imgs);
    }
    return ret;
}

NCE_S32 nce_alg_machine::nce_alg_get_result(alg_result_info &results)
{
    NCE_S32 ret = NCE_FAILED;
    HOOK_INVOKE(pPriv->hook_map["before_engine_get_result"], before_engine_get_result, pPriv->tmp_map);
    ret = pPriv->pEngine->engine_get_result(pPriv->tmp_map);
    HOOK_INVOKE(pPriv->hook_map["after_engine_get_result"], after_engine_get_result, pPriv->tmp_map);
    HOOK_INVOKE(pPriv->hook_map["before_alg_get_result"], before_alg_get_result, results, pPriv->tmp_map);
    ret = pPriv->pAlg->alg_get_result(results, pPriv->tmp_map);
    HOOK_INVOKE(pPriv->hook_map["after_alg_get_result"], after_alg_get_result, results, pPriv->tmp_map);

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
    for (auto &it : pPriv->privImgs)
    {
        delete it.image;
    }
    return ret;
}

} // namespace nce_alg