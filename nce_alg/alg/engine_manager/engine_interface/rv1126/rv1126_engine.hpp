#ifndef __ENGINE_HISI_3516DV300_HPP__
#define __ENGINE_HISI_3516DV300_HPP__

#include <alg_type.h>
#include <IEngine.hpp>
#include "factory.hpp"
#include <unordered_map>
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

    NCE_S32
    engine_init(const param_info &                  st_param_info,
                vector<input_tensor_info> &         st_tensor_infos,
                unordered_map<string, tmp_map_result> &st_result_map);

    NCE_S32 engine_inference(vector<img_t> &pc_imgs);

    NCE_S32 engine_get_result(unordered_map<string, tmp_map_result> &st_engine_result);

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
