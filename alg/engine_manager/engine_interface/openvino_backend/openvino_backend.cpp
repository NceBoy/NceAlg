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


    NCE_S32 openvino_engine::engine_init(const engine_param_info & st_engine_param_info)
    {

		char* pc_device = st_engine_param_info.st_engine_info.st_openvino_param.pc_device_name;
        char* pc_model_path = st_engine_param_info.pc_model_path;

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

        return NCE_SUCCESS;

    }


    NCE_S32 openvino_engine::engine_inference(img_info & pc_img)
    {
      InferenceEngine::Blob::Ptr input = pPriv->requestCurr.GetBlob(pPriv->network.getInputsInfo().begin()->first);
      auto buffer = input->buffer().as<InferenceEngine::PrecisionTrait<InferenceEngine::Precision::U8>::value_type *>();
	  NCE_U8 *tmpImage;
      if (PACKAGE == pc_img.format)
      {
      	  pPriv->package2planner(pc_img.image);
		  tmpImage = pPriv->pu8InputImage;
      }

      else if (PLANNER == pc_img.format)
      {
		  tmpImage = pc_img.image;
      }
      
	  memcpy(buffer, tmpImage, pPriv->u32Width*pPriv->u32Height*pPriv->u32Dims);
	  pPriv->requestCurr.Infer();

	  return NCE_SUCCESS;
    }

    NCE_S32 openvino_engine::engine_get_result(map<string, NCE_S32*> & engine_result)
    {
		std::map<string, NCE_S32*>::iterator iter;
        NCE_S32 count = 0;
        for (iter=engine_result.begin(); iter!=engine_result.end(); iter++)
        {
            iter->second = (NCE_S32*)pPriv->requestCurr.GetBlob(iter->first)->buffer();
            count++;
        }

		return NCE_SUCCESS;
    }



    NCE_S32 openvino_engine::engine_destroy()
    {
        NCE_S32 s32Ret = NCE_SUCCESS;
		return s32Ret;
    }
}   