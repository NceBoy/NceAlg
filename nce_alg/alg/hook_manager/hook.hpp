/*
 * @Author: your name
 * @Date: 2021-09-26 10:15:19
 * @LastEditTime: 2021-11-16 17:44:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \NceAlg\nce_alg\alg\engine_manager\IEngine.hpp
 */
#ifndef __HOOK_HPP__
#define __HOOK_HPP__
#include "linkedhashmap.h"
#include "alg_type.h"
#include "nce_tensor.hpp"
#include <vector>
#include "yaml-cpp/yaml.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg {

class Hook
{
public:
    virtual NCE_S32 hook_init(YAML::Node  & config)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 before_engine_init(const YAML::Node &                     config,
                                       vector<input_tensor_info> &            st_img_infos,
                                       LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_engine_init(const YAML::Node &                     config,
                                      vector<input_tensor_info> &            st_img_infos,
                                      LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_SUCCESS;
    }


    virtual NCE_S32 before_alg_init(vector<input_tensor_info> &            st_tensor_infos,
                                    LinkedHashMap<string, tmp_map_result> &st_result_map,
                                    YAML::Node &                           config)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_alg_init(vector<input_tensor_info> &            st_tensor_infos,
                                   LinkedHashMap<string, tmp_map_result> &st_result_map,
                                   YAML::Node &                           config)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 before_engine_inference(vector<img_t> &pc_imgs)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_engine_inference(vector<img_t> &pc_imgs)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 before_alg_inference()
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_alg_inference()
    {
        return NCE_SUCCESS;
    }


    virtual NCE_S32 before_engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 before_alg_get_result(alg_result_info &                      results,
                                          LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_SUCCESS;
    }

    virtual NCE_S32 after_alg_get_result(alg_result_info &                      results,
                                         LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_SUCCESS;
    }

    virtual ~Hook()
    {}
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
