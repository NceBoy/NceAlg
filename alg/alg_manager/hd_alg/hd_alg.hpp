#ifndef __HD_ALG__
#define __HD_ALG__

#include<iostream>
#include "alg_type.h"
#include "IAlg.hpp"
#include <map>
#include "IEngine.hpp"
#include<vector>
#include <memory>
#ifdef __cplusplus
#if __cplusplus

extern "C"{
#endif
#endif /* __cplusplus */

/*
DIR alg_manager
Ialg.hpp
	DIR hd_alg
	hd_dt.hpp(继承IAlg, 实现init、setconfig、inference、destroy)
	DIR ttf
		ttf.cpp(继承hd_dt, 实现getresult)
		ttf.hpp
	
*/



using namespace std;
namespace nce_alg
{

	class alg_priv
	{
	public:
		task_config_info    	alg_cfg;
		shared_ptr<IEngine> 	engine_ptr;
		map<string, NCE_S32*>   engine_result;
		vector<alg_result>      tmp_result;
		vector<person_head>     head_info;
		img_info* 			    input_info;

		alg_priv();

		NCE_S32 alg_priv_engine_init();

	};

    class hd_alg : public IAlg
    {
    public:

        NCE_S32 alg_engine_init(const engine_param_info &st_engine_param_info);

        NCE_S32 alg_cfg_set(const task_config_info & st_task_config_info);

        NCE_S32 alg_inference(img_info & pc_img);

        NCE_S32 alg_destroy();
	
	protected:

		shared_ptr<alg_priv> pPriv;
    };
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __ENGINE_HISI3516_DV300_HPP__ */
