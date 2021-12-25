#ifndef __OPENVINO_BACKEND_HPP__
#define __OPENVINO_BACKEND_HPP__

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
class openvino_engine : public IEngine, public NceEngineCreator<openvino_engine, IEngine, OPENVINO>
{
public:
    NCE_S32 engine_init(const YAML::Node &                     config,
                        vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map);

    NCE_S32 engine_inference(img_t &pc_img);

    NCE_S32 engine_get_result(map<int, tmp_map_result> &st_engine_result);

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

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
