/*
 * @Author: your name
 * @Date: 2021-09-26 10:15:19
 * @LastEditTime: 2021-11-16 17:44:12
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \NceAlg\nce_alg\alg\engine_manager\IEngine.hpp
 */
#ifndef __IENGINE_HPP__
#define __IENGINE_HPP__
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

class IEngine
{
public:
    virtual NCE_S32 engine_init(const param_info &                     st_param_info,
                                vector<input_tensor_info> &            st_img_infos,
                                LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 engine_init(const YAML::Node &                     config,
                                vector<input_tensor_info> &            st_img_infos,
                                LinkedHashMap<string, tmp_map_result> &st_result_map)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 engine_inference(vector<img_t> &pc_imgs)
    {
        return NCE_FAILED;
    }
    virtual NCE_S32 engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
    {
        return NCE_FAILED;
    }

    virtual NCE_S32 engine_destroy()
    {
        return NCE_FAILED;
    }

    virtual ~IEngine()
    {}
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
