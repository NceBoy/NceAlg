#include "keep_upper_bbox/keep_upper_bbox.hpp"
#include "util/util.hpp"

namespace nce_alg {
keep_upper_bbox::keep_upper_bbox() : img_width(0), img_heigth(0), keep_max(true), pconfig(nullptr)
{
    printf("keep_upper_bbox \n");
}

NCE_S32 keep_upper_bbox::hook_init(YAML::Node &config)
{
    keep_max = config["keep_upper_bbox"]["keep_max"].as<bool>();
    printf("keep_upper_bbox keep_max: %d\n", keep_max);
    pconfig = &config;
    return NCE_SUCCESS;
}

NCE_S32 keep_upper_bbox::after_alg_get_result(alg_result_info &                      results,
                                              LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    NCE_S32 new_num       = 0;
    NCE_S32 centy         = img_heigth / 2;
    NCE_S32 centx         = img_width / 2;
    NCE_S32 max_score_idx = 0;
    NCE_F32 max_score     = 0.f;

    for (NCE_S32 i = 0; i < results.num; i++)
    {
        detect_result *fast_bbox = (detect_result *)(results.st_alg_results + i)->obj;

        NCE_F32 cur_score  = fast_bbox->score;
        NCE_S32 bbox_centy = (fast_bbox->y1 + fast_bbox->y2) / 2.f;

        if (keep_max)
        {
            if (cur_score > max_score)
            {
                max_score_idx = new_num;
                max_score     = cur_score;
            }
        }

        if (bbox_centy > centy)
            continue;
        detect_result *slow_bbox = (detect_result *)(results.st_alg_results + new_num)->obj;
        memcpy(slow_bbox, fast_bbox, sizeof(detect_result));
        new_num++;
    }

    if (keep_max)
    {
        memcpy(results.st_alg_results + 0, results.st_alg_results + max_score_idx, sizeof(alg_result));
        new_num = 1;
    }
    results.num = new_num;
    return NCE_SUCCESS;
}

NCE_S32 keep_upper_bbox::before_engine_inference(vector<img_t> &pc_imgs)
{
    auto pcur_img = &pc_imgs[0];
    img_width     = pcur_img->image_attr.u32Width;
    img_heigth    = pcur_img->image_attr.u32Height;
    return NCE_SUCCESS;
}
} // namespace nce_alg