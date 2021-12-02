#include "nms_hook/body_nms_hook.hpp"
#include "util/util.hpp"
#include <vector>

namespace nce_alg {
body_nms_hook::body_nms_hook() : 
    nms_thresh(0.3f), 
    small_thresh(0.92f),
    height_thresh(0.05f), 
    pconfig(nullptr),
    is_body(false)
{
    printf("body_nms_hook \n");
}

NCE_S32 body_nms_hook::hook_init(YAML::Node &config)
{
    nms_thresh    = get_yaml_default(config, "nms_thresh", 0.6f);
    small_thresh  = get_yaml_default(config, "small_thresh", 0.92f);
    height_thresh = get_yaml_default(config, "height_thresh", 0.9f);
    is_body       = get_yaml_default(config, "is_body", false);
    printf("body_nms_hook nms_thresh: %f small_thresh: %f height_thresh: %f\n", nms_thresh, small_thresh, height_thresh);
    pconfig = &config;
    return NCE_SUCCESS;
}

NCE_S32 body_nms_hook::after_alg_get_result(alg_result_info &                      results,
                                            LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    std::sort(results.st_alg_results, results.st_alg_results + results.num, [](alg_result a, alg_result b) {
        return ((detect_result *)a.obj)->score > ((detect_result *)b.obj)->score;
    });

    // std::vector<detect_result> tmp;
    // for (NCE_S32 num = 0; num < results.num; num++)
    // {
    //     tmp.push_back(*((detect_result *)(results.st_alg_results + num)->obj));
    // }

    std::vector<NCE_S32> record(results.num, 0);
    NCE_S32              new_num = 0;

    for (NCE_S32 i = 0; i < results.num; i++)
    {
        auto *&fast_bbox = (results.st_alg_results + i)->obj;
        auto *&slow_bbox = (results.st_alg_results + new_num)->obj;
       
        if (record[i] == 0)
            slow_bbox = fast_bbox;
        else
            continue;
        for (NCE_S32 j = i + 1; j < results.num; j++)
        {
            detect_result *cur_bbox = (detect_result *)(results.st_alg_results + j)->obj;
            if (_is_overlap(*(detect_result*)fast_bbox, *cur_bbox))
                record[j] = 1;
        }
        new_num++;
    }

    //std::vector<detect_result> tmp1;
    //for (NCE_S32 num = 0; num < new_num; num++)
    //{
    //    auto bbox = *((detect_result *)(results.st_alg_results + num)->obj);
    //    tmp1.push_back(bbox);
    //}
    results.num = new_num;

    return NCE_SUCCESS;
}

bool body_nms_hook::_is_overlap(detect_result &bbox1, detect_result &bbox2)
{
    NCE_S32 inner_x1 = std::max(bbox1.x1, bbox2.x1);
    NCE_S32 inner_x2 = std::min(bbox1.x2, bbox2.x2);
    NCE_S32 inner_y1 = std::max(bbox1.y1, bbox2.y1);
    NCE_S32 inner_y2 = std::min(bbox1.y2, bbox2.y2);
    NCE_S32 inner_w  = inner_x2 - inner_x1;
    NCE_S32 inner_h  = inner_y2 - inner_y1;
    if (inner_h < 0 || inner_w < 0)
    {
        return false;
    }
    NCE_F32 bbox1_area = (bbox1.x2 - bbox1.x1) * (bbox1.y2 - bbox1.y1);
    NCE_F32 bbox2_area = (bbox2.x2 - bbox2.x1) * (bbox2.y2 - bbox2.y1);
    NCE_F32 inner_area = (inner_x2 - inner_x1) * (inner_y2 - inner_y1);

    NCE_F32 iou          = inner_area / (bbox1_area + bbox2_area - inner_area);
    NCE_F32 iou_small    = inner_area / min(bbox1_area, bbox2_area);
    NCE_F32 delta_y1     = std::abs(NCE_S32(bbox2.y1) - NCE_S32(bbox1.y1));
    NCE_F32 max_height   = max((bbox2.y2 - bbox2.y1), (bbox1.y2 - bbox1.y1));
    NCE_F32 height_ratio = 1 - (delta_y1 / max_height);

    if (iou > nms_thresh)
        return true;
    if (is_body)
    {
        if (iou_small > small_thresh && height_ratio > height_thresh)
            return true;
    }

    return false;
}
} // namespace nce_alg