/*
 * @Descripttion: 
 * @version: 
 * @Author: Haochen Ye
 * @Date: 2021-08-20 11:44:46
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-08-20 11:46:40
 */
#ifndef __MNN_BACKEND_HPP__
#define __MNN_BACKEND_HPP__

#include<alg_type.h>
#include<IEngine.hpp>
#include<map>
#include<memory>
#include"factory.hpp"
#ifdef __cplusplus
#if __cplusplus


using namespace std;
extern "C"{
#endif
#endif /* __cplusplus */

namespace nce_alg
{
    class MNN_engine: public IEngine,public NceEngineCreator<MNN_engine>
    {
    public:
        MNN_engine();

        NCE_S32 engine_init(const param_info & st_param_info, img_info & st_img_info,map<int, tmp_map_result> & st_result_map);

        NCE_S32 engine_inference(img_t & pc_img);

        NCE_S32 engine_get_result(map<int, tmp_map_result> & st_engine_result);

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



