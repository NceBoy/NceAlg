#include "reflection_filter_hook/reflection_filter_hook.hpp"
#include "util/util.hpp"

namespace nce_alg {
reflection_filter_hook::reflection_filter_hook() : mean_thresh(0), var_thresh(0), conf_thresh(0), pconfig(nullptr), pcur_img(nullptr)
{
    printf("reflection_filter_hook \n");
}

NCE_S32 reflection_filter_hook::hook_init(YAML::Node &config)
{
    mean_thresh = config["mean_thresh"].as<NCE_F32>();
    var_thresh  = config["var_thresh"].as<NCE_F32>();
    conf_thresh = config["conf_thresh"].as<NCE_F32>();
    printf("reflection_filter_hook mean thresh: %f  val_threhs: %f conf_thresh: %f\n",
           mean_thresh,
           var_thresh,
           conf_thresh);
    pconfig = &config;
    return NCE_SUCCESS;
}

NCE_S32 reflection_filter_hook::after_alg_get_result(alg_result_info &                      results,
                                                     LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    refelction_judge(*pcur_img, results, conf_thresh, mean_thresh, var_thresh);
    NCE_S32 new_num = 0;
    for (NCE_S32 i = 0; i < results.num; i++)
    {
        detect_result* fast_bbox = (detect_result*)(results.st_alg_results + i)->obj;
        NCE_F32        score     = fast_bbox->score;
        if (score < 1e-3) continue;
        detect_result* slow_bbox = (detect_result *)(results.st_alg_results + new_num)->obj;
        memcpy(slow_bbox, fast_bbox, sizeof(detect_result));
        new_num++;
    }
    results.num = new_num;
    return NCE_SUCCESS;
}

NCE_S32 reflection_filter_hook::before_engine_inference(vector<img_t> &pc_imgs)
{
    pcur_img = &pc_imgs[0];
    return NCE_SUCCESS;
}
} // namespace nce_alg