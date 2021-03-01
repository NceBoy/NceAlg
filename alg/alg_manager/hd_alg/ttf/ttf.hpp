#ifndef __TTF_HPP__
#define __TTF_HPP__
#include<iostream>
#include "alg_type.h"
#include "hd_alg.hpp"
#include<memory>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg
{
    class ttf_host : public hd_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results)
        {
            return NCE_SUCCESS;
        };


    };
    class ttf_openvino : public hd_alg
    {
    public:
        NCE_S32 alg_get_result(alg_result_info & results);

    };

	class ttf_hisi_3516dv300 : public hd_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results);


    };
    class ttf_hisi_3559av100 : public hd_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results);


    };
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif