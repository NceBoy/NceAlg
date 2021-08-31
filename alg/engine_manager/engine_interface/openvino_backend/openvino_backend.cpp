#include "samples/common.hpp"
#include "inference_engine.hpp"
#include "alg_type.h"
#include "openvino_backend.hpp"


#include<opencv2/opencv.hpp>


using namespace std;
namespace nce_alg
{

    class openvino_engine::engine_priv
    {
    public:
		NCE_U8* pu8InputImage;
		NCE_U32 u32Height;
		NCE_U32 u32Width;
		NCE_U32 u32Dims;
		NCE_U32 u32ImageSize;

        InferenceEngine::CNNNetwork network;
        InferenceEngine::ExecutableNetwork executableNetwork;
        InferenceEngine::InferRequest requestCurr;
		InferenceEngine::Core ie;

        engine_priv()
        {
            //memset(&network,0,sizeof(InferenceEngine::CNNNetwork));
            //memset(&executableNetwork,0,sizeof(InferenceEngine::ExecutableNetwork));
            //memset(&requestCurr,0,sizeof(InferenceEngine::InferRequest));
            printf("successful create engine_priv");
        }

        NCE_S32 engine_priv::package2planner(NCE_U8* pu8Image)
        //"Only used for rgb_package image"
        {
            for (NCE_U32 c=0; c<u32Dims; c++)
            {
                for (NCE_U32 h=0; h<u32Height; h++)
                {
                    for (NCE_U32 w=0; w<u32Width; w++)
                    {
                        pu8InputImage[c*u32ImageSize+h*u32Width+w] = pu8Image[(h*u32Width+w)*u32Dims+c];
                    }
                }
            }

            return NCE_SUCCESS;
        }

		~engine_priv()
		{
			delete pu8InputImage;
		}

    };


    NCE_S32 openvino_engine::engine_init(const param_info & st_param_info, img_info & st_img_info, map<int, tmp_map_result> & st_result_map)
    {
        std::map<int, tmp_map_result>::iterator iter;
		char* pc_device = st_param_info.st_engine_info.st_openvino_param.pc_device_name;
        char* pc_model_path = st_param_info.pc_model_path;

		pPriv = shared_ptr<openvino_engine::engine_priv>(new openvino_engine::engine_priv());
        pPriv->network = pPriv->ie.ReadNetwork(pc_model_path);	
        


        const auto& inputInfo = pPriv->network.getInputsInfo();
        const auto& imageInputInfo = *inputInfo.begin();
        const auto& imageInputDims = imageInputInfo.second->getTensorDesc().getDims();

        imageInputInfo.second->setPrecision(InferenceEngine::Precision::U8);

        pPriv->u32Width       = imageInputDims[3];
        pPriv->u32Height      = imageInputDims[2];
        pPriv->u32Dims        = imageInputDims[1];
        pPriv->u32ImageSize   = pPriv->u32Height * pPriv->u32Width;
		pPriv->pu8InputImage  = new NCE_U8[pPriv->u32ImageSize*pPriv->u32Dims];
        pPriv->executableNetwork = pPriv->ie.LoadNetwork(pPriv->network, pc_device);
        pPriv->requestCurr       = pPriv->executableNetwork.CreateInferRequest();

		u32Stride = pPriv->u32Width;

		st_img_info.u32channel = pPriv->u32Dims;
		st_img_info.u32Width = pPriv->u32Width;
		st_img_info.u32Height = pPriv->u32Height;

        st_img_info.format = PLANNER;
        //NCE强制要求RGB，给你脸了？
        st_img_info.order = RGB;
        int count = 0;
        for (iter=st_result_map.begin(); iter!=st_result_map.end(); iter++,count++)
        {
            InferenceEngine::Blob::Ptr  feat     = pPriv->requestCurr.GetBlob(iter->second.tensor.name);
			InferenceEngine::SizeVector featdims = feat->getTensorDesc().getDims();
            st_result_map[count].tensor.u32ch = featdims[1];
            st_result_map[count].tensor.u32FeatWidth  = featdims[3];
			st_result_map[count].tensor.u32FeatHeight = featdims[2];
			st_result_map[count].tensor.u32Stride   = featdims[3];
            st_result_map[count].tensor.zp = 0;
            st_result_map[count].tensor.fl = 0;
            st_result_map[count].tensor.scale = 1;
            st_result_map[count].tensor.outfmt = PLANNER;
            st_result_map[count].feat_type = FEAT_F32;
        }
        return NCE_SUCCESS;

    }


    NCE_S32 openvino_engine::engine_inference(img_t & pc_img)
    {
      InferenceEngine::Blob::Ptr input = pPriv->requestCurr.GetBlob(pPriv->network.getInputsInfo().begin()->first);
      auto buffer = input->buffer().as<InferenceEngine::PrecisionTrait<InferenceEngine::Precision::U8>::value_type *>();
	  NCE_U8 *tmpImage;
      if (PACKAGE == pc_img.image_attr.format)
      {
      	  pPriv->package2planner(pc_img.image);
		  tmpImage = pPriv->pu8InputImage;
      }

      else if (PLANNER == pc_img.image_attr.format)
      {
		  tmpImage = pc_img.image;
      }
      
	  memcpy(buffer, tmpImage, pPriv->u32Width*pPriv->u32Height*pPriv->u32Dims);
	  pPriv->requestCurr.Infer();

	  return NCE_SUCCESS;
    }

    NCE_S32 openvino_engine::engine_get_result(map<int, tmp_map_result> & st_engine_result)
    {
		std::map<int, tmp_map_result>::iterator iter;
        for (iter=st_engine_result.begin(); iter!=st_engine_result.end(); iter++)
        {
            iter->second.pu32Feat       = (NCE_S32*)pPriv->requestCurr.GetBlob(iter->second.tensor.name)->buffer();
        }

		return NCE_SUCCESS;
    }



    NCE_S32 openvino_engine::engine_destroy()
    {
        NCE_S32 s32Ret = NCE_SUCCESS;
		return s32Ret;
    }
}   