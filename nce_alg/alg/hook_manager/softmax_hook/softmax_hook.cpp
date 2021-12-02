#include "softmax_hook/softmax_hook.hpp"
#include "util/util.hpp"

namespace nce_alg {
softmax_hook::softmax_hook() : pconfig(nullptr), pcur_img(nullptr)
{
    printf("Softmax_hook \n");
}

NCE_S32 softmax_hook::hook_init(YAML::Node &config)
{
    printf("No parameters are required for softmax_hook \n");
    pconfig = &config;
    return NCE_SUCCESS;
}

NCE_S32 softmax_hook::after_alg_get_result(alg_result_info &                      results,
                                           LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    auto    rec_result = (humanbody_reco *)(results.st_alg_results->obj);
    auto    score      = rec_result->score;
    auto    dim        = rec_result->dim;
    softmax(dim, score);
    NCE_S32 target_idx = 0;
    NCE_F32 max_num    = 0;

    for (NCE_S32 i = 0; i < dim; i++)
    {
        if (score[i] > max_num) 
        {
            max_num    = score[i];
            target_idx = i;
        }
    }
    
    rec_result->label = target_idx;
    return NCE_SUCCESS;
}

NCE_S32 softmax_hook::before_engine_inference(vector<img_t> &pc_imgs)
{
    pcur_img = &pc_imgs[0];
    return NCE_SUCCESS;
}
} // namespace nce_alg