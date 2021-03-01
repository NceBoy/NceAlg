#include<vector>
#include "sil.hpp"
#include"util/util.hpp"
//TODO:去除打印
using namespace std;
namespace nce_alg
{

    NCE_S32 sil_hisi_3559av100::alg_get_result(alg_result_info & results)
    {
		results.num = 1;
        NCE_S32 ret = NCE_FAILED;
		if (NULL == pPriv)
		{
			printf("Failed to init pPriv of alg");
			return NCE_FAILED;
		}
		pPriv->st_engine_result["Spoof"] = engine_result{0};

        ret = pPriv->engine_ptr->engine_get_result(pPriv->st_engine_result);
		
		NCE_S32* cls    = pPriv->st_engine_result["Spoof"].pu32Feat;
		NCE_U32  stride = pPriv->st_engine_result["Spoof"].u32Stride;
		NCE_U32  width = pPriv->st_engine_result["Spoof"].u32FeatWidth;
		NCE_U32  height = pPriv->st_engine_result["Spoof"].u32FeatHeight;


		for(NCE_U32 i = 0 ; i < 40; i++)printf("%f\n" ,(NCE_F32) cls[i] / 4096.f);

		pPriv->score[0] = ((NCE_F32) cls[stride*0]) / 4096.f;
		pPriv->score[1] = ((NCE_F32) cls[stride*1]) / 4096.f;
		pPriv->score[2] = ((NCE_F32) cls[stride*2]) / 4096.f;
		
		softmax(3, pPriv->score);

		pPriv->head_info = person_head{pPriv->score[0], {0, 0, 0}};

		pPriv->tmp_result = {0, 0, 0, 0, 0.f, PERSON_HEAD, &pPriv->head_info};

		results.st_alg_results = &pPriv->tmp_result;

        return ret;
    }

}

