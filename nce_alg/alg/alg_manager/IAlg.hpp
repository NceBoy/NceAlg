/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-16 17:44:02
 */
#ifndef __IALG_HPP__
#define __IALG_HPP__

#include <iostream>
#include <alg_type.h>
#include "nce_tensor.hpp"
#include "linkedhashmap.h"
#include <vector>
#include "yaml-cpp/yaml.h"
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif

using namespace std;
namespace nce_alg {
class IAlg
{
public:
    virtual NCE_S32 alg_init(vector<input_tensor_info> &            st_tensor_infos,
                             LinkedHashMap<string, tmp_map_result> &st_result_map,
                             YAML::Node &                           config)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_cfg_set(const task_config_info &st_task_config_info)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_inference(vector<img_t> &pc_imgs) //后续改成图片预处理？
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 alg_destroy()
    {
        return NCE_FAILED;
    }

    virtual ~IAlg()
    {}
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
