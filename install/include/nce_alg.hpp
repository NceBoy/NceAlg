/*
 * @Author: your name
 * @Date: 2021-09-26 10:15:19
 * @LastEditTime: 2021-11-16 13:26:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \NceAlg\nce_alg\include\nce_alg.hpp
 */
#ifndef __NCE_ALG_HPP__
#define __NCE_ALG_HPP__
#include "alg_type.h"
#include "common.h"
#include <memory>
#include <vector>
#ifdef __cplusplus
#if __cplusplus

extern "C" {
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg {
class nce_alg_machine
{
public:
    NCE_PUBLIC nce_alg_machine(taskcls alg_type, const platform engine_type);

    NCE_S32 NCE_PUBLIC nce_alg_init(const char *yaml_cfg_path, vector<img_info> &st_img_infos);

    NCE_S32 NCE_PUBLIC nce_alg_cfg_set(const task_config_info &st_task_config_info);

    NCE_S32 NCE_PUBLIC nce_alg_inference(vector<img_t> &pc_imgs);

    NCE_S32 NCE_PUBLIC nce_alg_get_result(alg_result_info &results);

    NCE_S32 NCE_PUBLIC nce_alg_process_set(std::vector<ImageProcessParam> &pre_proc_cfg);

    NCE_S32 NCE_PUBLIC nce_alg_destroy();

private:
    class dynamic_factory;
    shared_ptr<dynamic_factory> pPriv;
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */