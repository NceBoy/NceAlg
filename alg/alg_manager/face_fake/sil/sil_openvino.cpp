#include<vector>
#include "sil.hpp"
#include"util/util.hpp"

using namespace std;
namespace nce_alg
{

    NCE_S32 sil_openvino::alg_get_result(alg_result_info & results)
    {
		results.num = 1;

        NCE_S32 ret = NCE_FAILED;
		if (NULL == pPriv)
		{
			printf("Failed to init pPriv of alg");
			return NCE_FAILED;
		}
		pPriv->st_engine_result["Conv_97"] = engine_result{0};

        ret = pPriv->engine_ptr->engine_get_result(pPriv->st_engine_result);
    
		NCE_F32* cls = (NCE_F32*)pPriv->st_engine_result["Conv_97"].pu32Feat;

		pPriv->score[0] = cls[0];
		pPriv->score[1] = cls[1];
		pPriv->score[2] = cls[2];

		softmax(3, pPriv->score);

		pPriv->head_info = person_head{ pPriv->score[0], {0, 0, 0}};

		pPriv->tmp_result = {0, 0, 0, 0, 0.f, PERSON_HEAD, &pPriv->head_info};

		results.st_alg_results = &pPriv->tmp_result;

        return ret;
    }

}

