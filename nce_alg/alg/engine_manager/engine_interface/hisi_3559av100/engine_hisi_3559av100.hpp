/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-09-06 15:52:24
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

    NCE_S32
    engine_init(const param_info &        st_param_info,
                vector<img_info> &        st_img_infos,
                map<int, tmp_map_result> &st_result_map);

    NCE_S32 engine_inference(vector<img_t> &pc_imgs);

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

#endif /* __ENGINE_HISI_3516DV300_HPP__ */
