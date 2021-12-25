/*
 * @Author: your name
 * @Date: 2021-09-26 10:15:19
 * @LastEditTime: 2021-11-19 17:27:16
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \NceAlg\nce_alg\alg\engine_manager\rv1126\rv1126_engine.hpp
 */
#ifndef __ENGINE_HISI_3516DV300_HPP__
#define __ENGINE_HISI_3516DV300_HPP__

#include <alg_type.h>
#include <IEngine.hpp>
#include "factory.hpp"
#include "linkedhashmap.h"
#include <memory>

#ifdef __cplusplus
#if __cplusplus

using namespace std;
extern "C" {
#endif
#endif /* __cplusplus */

namespace nce_alg {
class rv1126_engine : public IEngine, public NceCreator<rv1126_engine, IEngine, RV_1126>
{
public:
    rv1126_engine();

    NCE_S32 engine_init(const YAML::Node &                     config,
                        vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map);

    NCE_S32 engine_inference(vector<img_t> &pc_imgs);

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
