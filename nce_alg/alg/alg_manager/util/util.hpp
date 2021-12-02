#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <iostream>
#include "alg_type.h"
#include <vector>
#include <yaml-cpp/yaml.h>
#include <assert.h>

using namespace std;
namespace nce_alg {
NCE_S32 nms(vector<detect_result> input, vector<detect_result> &output, float threshold);
NCE_S32 RB_REPLACE_PACKAGE(img_t &frame);
NCE_S32 RB_REPLACE_PLANNER(img_t &frame);
NCE_S32 softmax(NCE_U32 dim, NCE_F32 *score);
NCE_S32 refelction_judge(const img_t &          frame,
                         alg_result_info        &results,
                         NCE_F32                conf_thresh,
                         NCE_F32                mean_thresh,
                         NCE_F32                var_thresh);

template <typename T>
T get_yaml_default(const YAML::Node &config, std::string key, T value = -10000)
{
    auto sub_node = config[key];
    bool is_defined = false;
    try
    {
        is_defined = sub_node.IsDefined();
    }
    catch(...)
    {
    }
    if (!is_defined)
    {
        if (-10000 == value)
        {
            printf("%s is not defined! and default value is NULL!!\n", key.c_str());
            assert(false);
        }
        printf("%s is not defined! get default value\n", key.c_str());
        return value;
    }
    return sub_node.as<T>();
}
} // namespace nce_alg

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
