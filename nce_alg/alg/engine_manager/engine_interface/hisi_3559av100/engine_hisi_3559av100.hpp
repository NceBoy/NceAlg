/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-10-23 10:56:05
 */
#ifndef __ENGINE_HISI_3559AV100_HPP__
#define __ENGINE_HISI_3559AV100_HPP__

#include <alg_type.h>
#include <IEngine.hpp>
#include <map>
#include <memory>
#include "factory.hpp"

#ifdef __cplusplus
#if __cplusplus

using namespace std;
extern "C" {
#endif
#endif /* __cplusplus */

namespace nce_alg {
class hisi_3559av100_engine : public IEngine, public NceCreator<hisi_3559av100_engine, IEngine, HISI_3559AV100>
{
public:
    hisi_3559av100_engine();

    NCE_S32 engine_init(const param_info &                     st_param_info,
                        vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map);

    NCE_S32 engine_init(const YAML::Node &                     config,
                        vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map);

    NCE_S32 engine_inference(vector<img_t> &pc_img);

    NCE_S32 engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result);

    NCE_S32 engine_destroy();

private:
    class engine_priv;
    shared_ptr<engine_priv> pPriv;
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI_3516DV300_HPP__ */
