#ifndef __ENGINE_HISI_3559AV100_HPP__
#define __ENGINE_HISI_3559AV100_HPP__

#include<alg_type.h>
#include<IEngine.hpp>
#include<map>
#include<memory>

#ifdef __cplusplus
#if __cplusplus


using namespace std;
extern "C"{
#endif
#endif /* __cplusplus */

namespace nce_alg
{
    class hisi_3559av100_engine: public IEngine
    {
    public:
        hisi_3559av100_engine();

        NCE_S32 engine_init(const engine_param_info & st_engine_param_info, img_info & st_img_info);

        NCE_S32 engine_inference(img_t & pc_img);

        NCE_S32 engine_get_result(map<string, engine_result> & st_engine_result);

        NCE_S32 engine_destroy();

    private:
        class engine_priv;
        shared_ptr<engine_priv> pPriv;

    };
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI_3516DV300_HPP__ */



