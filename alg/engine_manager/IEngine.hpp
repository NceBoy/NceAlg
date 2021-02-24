#ifndef __IENGINE_HPP__
#define __IENGINE_HPP__
#include<iostream>
#include<alg_type.h>
#include<map>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */



using namespace std;
namespace nce_alg
{
    class IEngine
    {
    public:

        virtual NCE_S32 engine_init(const engine_param_info & st_engine_param_info)
        {
            return NCE_FAILED;
        }

        virtual NCE_S32 engine_inference(img_info & pc_img)
        {
            return NCE_FAILED;
        }
        virtual NCE_S32 engine_get_result(map<string, NCE_S32*> & engine_result)
        {
            return NCE_FAILED;
        }

        virtual NCE_S32 engine_destroy()
        {
            return NCE_FAILED;
        }
    };
}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif
