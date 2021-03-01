#ifndef __SIL_HPP__
#define __SIL_HPP__
#include<iostream>
#include "alg_type.h"
#include "fc_fk_alg.hpp"
#include<memory>
#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg
{
    class sil_host : public fc_fk_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results)
        {
            return NCE_SUCCESS;
        }

    };

    class sil_openvino : public fc_fk_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results);

    };

	class sil_hisi_3516dv300 : public fc_fk_alg
    {
    public:

        NCE_S32 alg_get_result(alg_result_info & results);

    };

	class sil_hisi_3559av100 : public fc_fk_alg
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