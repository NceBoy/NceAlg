#include<vector>
#include "ttf.hpp"
#include"util/util.hpp"
using namespace std;
namespace nce_alg
{

    NCE_S32 ttf_openvino::alg_get_result(alg_result_info & results)
    {
        NCE_S32 ret = NCE_FAILED;
		if (NULL == pPriv)
		{
			printf("Failed to init pPriv of alg");
			return NCE_FAILED;
		}

		pPriv->st_engine_result["hm"] = engine_result{0};
		pPriv->st_engine_result["wh"] = engine_result{0};

    
        pPriv->tmp_result.clear();
        pPriv->head_info.clear();
        NCE_F32  ratio   = 4;

		NCE_U32  width   = pPriv->st_engine_result["hm"].u32FeatWidth;
		NCE_U32  height  = pPriv->st_engine_result["hm"].u32FeatHeight;
		NCE_U32  stride  = pPriv->st_engine_result["hm"].u32Stride;

        NCE_F32* cls = (NCE_F32*)pPriv->st_engine_result["hm"].pu32Feat;
        NCE_F32* reg = (NCE_F32*)pPriv->st_engine_result["wh"].pu32Feat;

        NCE_U32 feature_size   = width  * height;

        for (NCE_U32 i = 0; i < feature_size; i++)
        {
            NCE_U32   cur_h    = i / width;
            NCE_U32   cur_w    = i % width;

            NCE_F32   score    = (NCE_F32) (cls[cur_h * stride + cur_w]);

            NCE_U32   left     = (NCE_F32) (reg[cur_h * stride + cur_w + feature_size*0]); 
            NCE_U32   top      = (NCE_F32) (reg[cur_h * stride + cur_w + feature_size*1]);
            NCE_U32   right    = (NCE_F32) (reg[cur_h * stride + cur_w + feature_size*2]);
            NCE_U32   down     = (NCE_F32) (reg[cur_h * stride + cur_w + feature_size*3]);

            if (score < pPriv->alg_cfg.threshold) continue;
            //printf("count:%d score:%f\n", i, score);
            NCE_U32 x1    = cur_w * ratio - left;
            NCE_U32 y1    = cur_h * ratio - top;
            NCE_U32 x2    = cur_w * ratio + right;
            NCE_U32 y2    = cur_h * ratio + down;
			
            NCE_F32 fake = true;
            NCE_S32  angle[3] = {0, 0, 0};
            pPriv->head_info.push_back(person_head{fake, angle[0], angle[1], angle[2]});
            //cun shu xing
            pPriv->tmp_result.push_back(alg_result{x1, y1, x2, y2, score, PERSON_HEAD, &pPriv->head_info[pPriv->head_info.size()-1]});
        }
		
		nms(pPriv->tmp_result, pPriv->tmp_result, pPriv->alg_cfg.st_cfg.hd_config.nms_thresh);
        results.num = pPriv->tmp_result.size();
        results.st_alg_results = &pPriv->tmp_result[0];
        return ret;
    }

}

