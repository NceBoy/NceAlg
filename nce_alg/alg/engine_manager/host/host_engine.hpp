#ifndef __HOST_ENGINE_HPP__
#define __HOST_ENGINE_HPP__

#include <alg_type.h>
#include <IEngine.hpp>
#include <map>
#include <memory>

#ifdef __cplusplus
#if __cplusplus

using namespace std;
extern "C" {
#endif
#endif /* __cplusplus */

namespace nce_alg {
class host_engine : public IEngine
{
public:
    NCE_S32 engine_init(const YAML::Node config, img_info &st_img_info, map<int, tmp_map_result> &st_result_map)
    {
        return NCE_SUCCESS;
    };

    NCE_S32 engine_inference(img_t &pc_img)
    {
        return NCE_SUCCESS;
    };

    NCE_S32 engine_get_result(map<int, tmp_map_result> &st_engine_result)
    {
        return NCE_SUCCESS;
    };

    NCE_S32 engine_destroy()
    {
        return NCE_SUCCESS;
    };
};
} // namespace nce_alg

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HOST_ENGINE_HPP__ */
