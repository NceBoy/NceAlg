#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "alg_type.h"
#include "nce_tensor.hpp"
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <math.h>
#include "hi_common.h"
#include "hi_comm_sys.h"
#include "hi_comm_svp.h"
#include "sample_comm.h"
#include "sample_comm_svp.h"
#include "sample_comm_nnie.h"
#include "sample_svp_nnie_software.h"
#include "sample_comm_ive.h"
#include "hi_type.h"
#include <vector>
#include "engine_hisi_3516dv300.hpp"

#define SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_CLREAR()
#define SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_SRC_FLUSH_TIME()
#define SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_PRE_DST_FLUSH_TIME()
#define SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_AFTER_DST_FLUSH_TIME()
#define SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_OP_TIME()
using namespace std;
namespace nce_alg {

class hisi_3516dv300_engine::engine_priv
{
public:
    SAMPLE_SVP_NNIE_MODEL_S stENnieModel;
    SAMPLE_SVP_NNIE_PARAM_S stENnieParam;
    SAMPLE_SVP_NNIE_CFG_S   stNnieCfg;

    NCE_U32 input_num;
    // NCE_U32 u32Stride;
    // NCE_U32 u32Ch;
    // NCE_U32 u32Height;
    // NCE_U32 u32Width;

    engine_priv()
    {
        memset(&stENnieModel, 0, sizeof(SAMPLE_SVP_NNIE_MODEL_S));
        memset(&stENnieParam, 0, sizeof(SAMPLE_SVP_NNIE_PARAM_S));
        memset(&stNnieCfg, 0, sizeof(SAMPLE_SVP_NNIE_CFG_S));
        printf("successful create engine_priv");
    }

    NCE_S32 package2planner(NCE_U8 *InputImage, NCE_U8 *OutputImage, NCE_S32 u32Width, NCE_S32 u32Height, NCE_S32 u32Ch)
    //"Only used for rgb_package image"
    {
        NCE_U32 ImageSize = u32Width * u32Height;
        for (NCE_U32 c = 0; c < u32Ch; c++)
        {
            for (NCE_U32 h = 0; h < u32Height; h++)
            {
                for (NCE_U32 w = 0; w < u32Width; w++)
                {
                    OutputImage[c * ImageSize + h * u32Width + w] = InputImage[(h * u32Width + w) * u32Ch + c];
                }
            }
        }
        return NCE_SUCCESS;
    }

    HI_S32 SAMPLE_SVP_NNIE_FillSrcData(SAMPLE_SVP_NNIE_PARAM_S *pstNnieParam, vector<img_t> &frames)
    {

        HI_U8 *pu8ImgTmp_stack[input_num];
        for (NCE_U32 i = 0; i < input_num; i++)
        {
            NCE_S32 width   = pstNnieParam->astSegData[i].astSrc->unShape.stWhc.u32Width;
            NCE_S32 height  = pstNnieParam->astSegData[i].astSrc->unShape.stWhc.u32Height;
            NCE_S32 channel = pstNnieParam->astSegData[i].astSrc->unShape.stWhc.u32Chn;

            if (frames[i].image_attr.format == PACKAGE)
            {

                package2planner(frames[i].image, pu8ImageTmp[i], width, height, channel);
                pu8ImgTmp_stack[i] = pu8ImageTmp[i];
            }
            else
            {
                pu8ImgTmp_stack[i] = frames[i].image;
            }
        }

        // pu8PicAddr =
        // SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(HI_U8,pstNnieParam->astSegData[u32SegIdx].astSrc[u32NodeIdx].u64VirAddr);
        // pstNnieParam->astSegData[0].astSrc[0].u64PhyAddr = Frame->PhyAddr[0];
        for (NCE_U32 t = 0; t < input_num; t++)
        {
            pu8PicAddr      = (HI_U8 *)(size_t)(pstNnieParam->astSegData[0].astSrc[t].u64VirAddr);
            NCE_S32 width   = pstNnieParam->astSegData[0].astSrc[t].unShape.stWhc.u32Width;
            NCE_S32 height  = pstNnieParam->astSegData[0].astSrc[t].unShape.stWhc.u32Height;
            NCE_S32 channel = pstNnieParam->astSegData[0].astSrc[t].unShape.stWhc.u32Chn;
            NCE_S32 stride  = pstNnieParam->astSegData[0].astSrc[t].u32Stride;

            for (NCE_U32 n = 0; n < pstNnieParam->astSegData[0].astSrc[t].u32Num; n++)
            {
                for (int i = 0; i < channel; i++)
                {
                    for (int j = 0; j < height; j++)
                    {
                        // s32Ret = fread(pu8PicAddr,u32Width*u32VarSize,1,fp);
                        //  SAMPLE_SVP_CHECK_EXPR_GOTO(1 != s32Ret,FAIL,SAMPLE_SVP_ERR_LEVEL_ERROR,"Error,Read image
                        //  file failed!\n");
                        memcpy(pu8PicAddr, pu8ImgTmp_stack[t], width * u32VarSize);
                        pu8PicAddr += stride;
                        pu8ImgTmp_stack[t] += width * u32VarSize;
                    }
                }
            }
            SAMPLE_COMM_SVP_FlushCache(pstNnieParam->astSegData[0].astSrc[t].u64PhyAddr,
                                       (HI_U8 *)(size_t)(pstNnieParam->astSegData[0].astSrc[t].u64VirAddr),
                                       channel * height * stride);
        }

        return HI_SUCCESS;
    }

    HI_S32 SAMPLE_SVP_NNIE_Cnn_ParamInit(SAMPLE_SVP_NNIE_CFG_S *pstNnieCfg, SAMPLE_SVP_NNIE_PARAM_S *pstCnnPara)
    {
        HI_S32 s32Ret = HI_SUCCESS;
        /*init hardware para*/
        s32Ret = SAMPLE_COMM_SVP_NNIE_ParamInit(pstNnieCfg, pstCnnPara);
        SAMPLE_SVP_CHECK_EXPR_GOTO(HI_SUCCESS != s32Ret,
                                   INIT_FAIL_0,
                                   SAMPLE_SVP_ERR_LEVEL_ERROR,
                                   "Error(%#x),SAMPLE_COMM_SVP_NNIE_ParamInit failed!\n",
                                   s32Ret);
        /*get sizeof input type*/
        if (SVP_BLOB_TYPE_U8 <= pstCnnPara->astSegData[0].astSrc[0].enType
            && SVP_BLOB_TYPE_YVU422SP >= pstCnnPara->astSegData[0].astSrc[0].enType)
        {
            u32VarSize = sizeof(HI_U8);
        }
        else
        {
            u32VarSize = sizeof(HI_U32);
        }

        input_num   = stENnieParam.pstModel->astSeg[0].u16SrcNum;
        pu8ImageTmp = new HI_U8 *[input_num];
        for (NCE_U32 i = 0; i < input_num; i++)
        {
            NCE_S32 stride  = stENnieParam.astSegData[0].astSrc[0].u32Stride;
            NCE_S32 channel = stENnieParam.astSegData[0].astSrc[0].unShape.stWhc.u32Chn;
            NCE_S32 height  = stENnieParam.astSegData[0].astSrc[0].unShape.stWhc.u32Height;
            NCE_S32 width   = stENnieParam.astSegData[0].astSrc[0].unShape.stWhc.u32Width;
            pu8ImageTmp[i]  = new NCE_U8[width * height * channel];
        }

        return s32Ret;
    INIT_FAIL_0:
        s32Ret = SAMPLE_SVP_NNIE_Cnn_Deinit(pstCnnPara, NULL);
        SAMPLE_SVP_CHECK_EXPR_RET(HI_SUCCESS != s32Ret,
                                  s32Ret,
                                  SAMPLE_SVP_ERR_LEVEL_ERROR,
                                  "Error(%#x),SAMPLE_SVP_NNIE_Cnn_Deinit failed!\n",
                                  s32Ret);
        return HI_FAILURE;
    }

    HI_S32 SAMPLE_SVP_NNIE_Cnn_Deinit(SAMPLE_SVP_NNIE_PARAM_S *pstNnieParam, SAMPLE_SVP_NNIE_MODEL_S *pstNnieModel)
    {

        HI_S32 s32Ret = HI_SUCCESS;
        /*hardware para deinit*/
        if (pstNnieParam != NULL)
        {
            s32Ret = SAMPLE_COMM_SVP_NNIE_ParamDeinit(pstNnieParam);
            SAMPLE_SVP_CHECK_EXPR_TRACE(
                HI_SUCCESS != s32Ret, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_COMM_SVP_NNIE_ParamDeinit failed!\n");
        }
        /*model deinit*/
        if (pstNnieModel != NULL)
        {
            s32Ret = SAMPLE_COMM_SVP_NNIE_UnloadModel(pstNnieModel);
            SAMPLE_SVP_CHECK_EXPR_TRACE(
                HI_SUCCESS != s32Ret, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_COMM_SVP_NNIE_UnloadModel failed!\n");
        }

        if (pu8ImageTmp != NULL)
        {
            delete pu8ImageTmp;
        }
        return s32Ret;
    }
    HI_S32 SAMPLE_SVP_NNIE_Forward(SAMPLE_SVP_NNIE_PARAM_S *            pstNnieParam,
                                   SAMPLE_SVP_NNIE_INPUT_DATA_INDEX_S * pstInputDataIdx,
                                   SAMPLE_SVP_NNIE_PROCESS_SEG_INDEX_S *pstProcSegIdx,
                                   HI_BOOL                              bInstant)
    {
        HI_S32          s32Ret = HI_SUCCESS;
        HI_U32          i = 0, j = 0;
        HI_BOOL         bFinish         = HI_FALSE;
        SVP_NNIE_HANDLE hSvpNnieHandle  = 0;
        HI_U32          u32TotalStepNum = 0;
        SAMPLE_SVP_NIE_PERF_STAT_DEF_VAR();

        SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_CLREAR();

        SAMPLE_COMM_SVP_FlushCache(
            pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].stTskBuf.u64PhyAddr,
            SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                HI_VOID, pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].stTskBuf.u64VirAddr),
            pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].stTskBuf.u32Size);

        SAMPLE_SVP_NNIE_PERF_STAT_BEGIN();
        for (i = 0; i < pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].u32DstNum; i++)
        {
            if (SVP_BLOB_TYPE_SEQ_S32 == pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].enType)
            {
                for (j = 0; j < pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Num; j++)
                {
                    u32TotalStepNum +=
                        *(SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                              HI_U32,
                              pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stSeq.u64VirAddrStep)
                          + j);
                }
                SAMPLE_COMM_SVP_FlushCache(
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64PhyAddr,
                    SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                        HI_VOID, pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64VirAddr),
                    u32TotalStepNum * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Stride);
            }
            else
            {
                SAMPLE_COMM_SVP_FlushCache(
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64PhyAddr,
                    SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                        HI_VOID, pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64VirAddr),
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Num
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stWhc.u32Chn
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stWhc.u32Height
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Stride);
            }
        }
        SAMPLE_SVP_NNIE_PERF_STAT_END();
        SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_PRE_DST_FLUSH_TIME();

        /*set input blob according to node name*/
        if (pstInputDataIdx->u32SegIdx != pstProcSegIdx->u32SegIdx)
        {
            for (i = 0; i < pstNnieParam->pstModel->astSeg[pstProcSegIdx->u32SegIdx].u16SrcNum; i++)
            {
                for (j = 0; j < pstNnieParam->pstModel->astSeg[pstInputDataIdx->u32SegIdx].u16DstNum; j++)
                {
                    if (0
                        == strncmp(pstNnieParam->pstModel->astSeg[pstInputDataIdx->u32SegIdx].astDstNode[j].szName,
                                   pstNnieParam->pstModel->astSeg[pstProcSegIdx->u32SegIdx].astSrcNode[i].szName,
                                   SVP_NNIE_NODE_NAME_LEN))
                    {
                        pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astSrc[i] =
                            pstNnieParam->astSegData[pstInputDataIdx->u32SegIdx].astDst[j];
                        break;
                    }
                }
                SAMPLE_SVP_CHECK_EXPR_RET((j == pstNnieParam->pstModel->astSeg[pstInputDataIdx->u32SegIdx].u16DstNum),
                                          HI_FAILURE,
                                          SAMPLE_SVP_ERR_LEVEL_ERROR,
                                          "Error,can't find %d-th seg's %d-th src blob!\n",
                                          pstProcSegIdx->u32SegIdx,
                                          i);
            }
        }

        /*NNIE_Forward*/
        SAMPLE_SVP_NNIE_PERF_STAT_BEGIN();
        s32Ret = HI_MPI_SVP_NNIE_Forward(&hSvpNnieHandle,
                                         pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astSrc,
                                         pstNnieParam->pstModel,
                                         pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst,
                                         &pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx],
                                         bInstant);
        SAMPLE_SVP_CHECK_EXPR_RET(
            HI_SUCCESS != s32Ret, s32Ret, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,HI_MPI_SVP_NNIE_Forward failed!\n");

        if (bInstant)
        {
            /*Wait NNIE finish*/
            while (HI_ERR_SVP_NNIE_QUERY_TIMEOUT
                   == (s32Ret = HI_MPI_SVP_NNIE_Query(pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].enNnieId,
                                                      hSvpNnieHandle,
                                                      &bFinish,
                                                      HI_TRUE)))
            {
                usleep(100);
                SAMPLE_SVP_TRACE(SAMPLE_SVP_ERR_LEVEL_INFO, "HI_MPI_SVP_NNIE_Query Query timeout!\n");
            }
        }
        SAMPLE_SVP_NNIE_PERF_STAT_END();
        SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_OP_TIME();
        u32TotalStepNum = 0;

        SAMPLE_SVP_NNIE_PERF_STAT_BEGIN();
        for (i = 0; i < pstNnieParam->astForwardCtrl[pstProcSegIdx->u32SegIdx].u32DstNum; i++)
        {
            if (SVP_BLOB_TYPE_SEQ_S32 == pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].enType)
            {
                for (j = 0; j < pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Num; j++)
                {
                    u32TotalStepNum +=
                        *(SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                              HI_U32,
                              pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stSeq.u64VirAddrStep)
                          + j);
                }
                SAMPLE_COMM_SVP_FlushCache(
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64PhyAddr,
                    SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                        HI_VOID, pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64VirAddr),
                    u32TotalStepNum * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Stride);
            }
            else
            {
                SAMPLE_COMM_SVP_FlushCache(
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64PhyAddr,
                    SAMPLE_SVP_NNIE_CONVERT_64BIT_ADDR(
                        HI_VOID, pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u64VirAddr),
                    pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Num
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stWhc.u32Chn
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].unShape.stWhc.u32Height
                        * pstNnieParam->astSegData[pstProcSegIdx->u32SegIdx].astDst[i].u32Stride);
            }
        }
        SAMPLE_SVP_NNIE_PERF_STAT_END();
        SAMPLE_SVP_NNIE_PERF_STAT_OP_FORWARD_AFTER_DST_FLUSH_TIME();

        return s32Ret;
    }

private:
    HI_U8 * pu8PicAddr  = NULL;
    HI_U8 **pu8ImageTmp = NULL;
    HI_U32  u32VarSize  = 0;
};

hisi_3516dv300_engine::hisi_3516dv300_engine()
{
    pPriv = shared_ptr<engine_priv>(new hisi_3516dv300_engine::engine_priv());
};

NCE_S32 hisi_3516dv300_engine::engine_init(const param_info &                     st_param_info,
                                           vector<input_tensor_info> &            st_tensor_infos,
                                           LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    HI_S32 s32Ret = HI_SUCCESS;
    /*Set configuration parameter*/
    HI_U32 u32PicNum = 1;
    HI_U32 i         = 0;
    HI_U32 count = 0;
    /*Set configuration parameter*/
    pPriv->stNnieCfg.u32MaxInputNum   = u32PicNum; // max input image num in each batch
    pPriv->stNnieCfg.u32MaxRoiNum     = 0;
    pPriv->stNnieCfg.aenNnieCoreId[0] = SVP_NNIE_ID_0; // set NNIE core

    /*Sys init*/
    // SAMPLE_COMM_SVP_CheckSysInit();
    /*CNN Load model*/
    SAMPLE_SVP_TRACE_INFO("Cnn Load model!\n");
    s32Ret = SAMPLE_COMM_SVP_NNIE_LoadModel(st_param_info.pc_model_path, &pPriv->stENnieModel);
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_0, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_COMM_SVP_NNIE_LoadModel failed!\n");
    /*CNN parameter initialization*/
    /*Cnn software parameters are set in SAMPLE_SVP_NNIE_Cnn_SoftwareParaInit,
    if user has changed net struct, please make sure the parameter settings in
    SAMPLE_SVP_NNIE_Cnn_SoftwareParaInit function are correct*/
    SAMPLE_SVP_TRACE_INFO("Cnn parameter initialization!\n");
    pPriv->stENnieParam.pstModel = &pPriv->stENnieModel.stModel;
    s32Ret                       = pPriv->SAMPLE_SVP_NNIE_Cnn_ParamInit(&pPriv->stNnieCfg, &pPriv->stENnieParam);
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_0, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_SVP_NNIE_Cnn_ParamInit failed!\n");
    SAMPLE_SVP_TRACE_INFO("NNIE AddTskBuf!\n");
    /*record tskBuf*/
    s32Ret = HI_MPI_SVP_NNIE_AddTskBuf(&(pPriv->stENnieParam.astForwardCtrl[0].stTskBuf));
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_0, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,HI_MPI_SVP_NNIE_AddTskBuf failed!\n");
    SAMPLE_SVP_TRACE_INFO("NNIE AddTskBuf end!\n");

    for (NCE_U32 i = 0; i < pPriv->input_num; i++)
    {
        st_tensor_infos[i].format    = PLANNER;
        st_tensor_infos[i].name      = to_string(i);
        st_tensor_infos[i].channel   = pPriv->stENnieParam.astSegData[0].astSrc[i].unShape.stWhc.u32Chn;
        st_tensor_infos[i].height    = pPriv->stENnieParam.astSegData[0].astSrc[i].unShape.stWhc.u32Height;
        st_tensor_infos[i].width     = pPriv->stENnieParam.astSegData[0].astSrc[i].unShape.stWhc.u32Width;
    }
    // NCE强制要求RGB，给你脸了？

    //目前不分段
    for (auto &kv : st_result_map)
    {
        st_result_map[kv].tensor.u32ch          = pPriv->stENnieParam.astSegData[0].astDst[count].unShape.stWhc.u32Chn;
        st_result_map[kv].tensor.u32FeatWidth   = pPriv->stENnieParam.astSegData[0].astDst[count].unShape.stWhc.u32Width;
        st_result_map[kv].tensor.u32FeatHeight  = pPriv->stENnieParam.astSegData[0].astDst[count].unShape.stWhc.u32Height;
        st_result_map[kv].tensor.width_stride   = 1;
        st_result_map[kv].tensor.height_stride  = pPriv->stENnieParam.astSegData[0].astDst[count].u32Stride / sizeof(NCE_F32);
        st_result_map[kv].tensor.channel_stride = st_result_map[kv].tensor.height_stride *st_result_map[kv].tensor.u32FeatHeight;
        st_result_map[kv].tensor.zp             = 0;
        st_result_map[kv].tensor.fl             = 0;
        st_result_map[kv].tensor.scale          = 4096;
        st_result_map[kv].tensor.outfmt         = PLANNER;
        st_result_map[kv].feat_type             = FEAT_S32;
        printf("stride w%d h %d c %d\n",st_result_map[kv].tensor.width_stride,
        st_result_map[kv].tensor.height_stride,
        st_result_map[kv].tensor.channel_stride);
        count++;
    }

    return NCE_SUCCESS;

CNN_FAIL_1:
    /*Remove TskBuf*/
    s32Ret = HI_MPI_SVP_NNIE_RemoveTskBuf(&(pPriv->stENnieParam.astForwardCtrl[0].stTskBuf));
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_0, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,HI_MPI_SVP_NNIE_RemoveTskBuf failed!\n");

CNN_FAIL_0:
    SAMPLE_SVP_TRACE_INFO("Why \n");
    pPriv->SAMPLE_SVP_NNIE_Cnn_Deinit(&pPriv->stENnieParam, &pPriv->stENnieModel);
    // SAMPLE_COMM_SVP_CheckSysExit();
}

NCE_S32 hisi_3516dv300_engine::engine_inference(vector<img_t> &pc_imgs)
{
    HI_S32                              s32Ret         = HI_SUCCESS;
    SAMPLE_SVP_NNIE_INPUT_DATA_INDEX_S  stInputDataIdx = { 0 };
    SAMPLE_SVP_NNIE_PROCESS_SEG_INDEX_S stProcSegIdx   = { 0 };

    /*Fill src data*/
    SAMPLE_SVP_TRACE_INFO("Cnn start!\n");
    stInputDataIdx.u32SegIdx  = 0;
    stInputDataIdx.u32NodeIdx = 0;
    s32Ret                    = pPriv->SAMPLE_SVP_NNIE_FillSrcData(&pPriv->stENnieParam, pc_imgs);
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_1, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_SVP_NNIE_FillSrcData failed!\n");
    SAMPLE_SVP_TRACE_INFO("Load Img!\n");
    /*NNIE process(process the 0-th segment)*/
    long            spend;
    struct timespec start, next, end;
    clock_gettime(0, &start);
    stProcSegIdx.u32SegIdx = 0;
    s32Ret = pPriv->SAMPLE_SVP_NNIE_Forward(&pPriv->stENnieParam, &stInputDataIdx, &stProcSegIdx, HI_TRUE);
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_1, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_SVP_NNIE_Forward failed!\n");
    SAMPLE_SVP_TRACE_INFO("Forward!\n");
    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("\n[inference]===== TIME SPEND: %ld ms =====\n", spend);

    return NCE_SUCCESS;
CNN_FAIL_1:
    /*Remove TskBuf*/
    SAMPLE_SVP_TRACE_INFO("Why1 \n");
    s32Ret = HI_MPI_SVP_NNIE_RemoveTskBuf(&(pPriv->stENnieParam.astForwardCtrl[0].stTskBuf));
    SAMPLE_SVP_CHECK_EXPR_GOTO(
        HI_SUCCESS != s32Ret, CNN_FAIL_0, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,HI_MPI_SVP_NNIE_RemoveTskBuf failed!\n");
    return NCE_FAILED;

CNN_FAIL_0:
    SAMPLE_SVP_TRACE_INFO("Why2 \n");
    pPriv->SAMPLE_SVP_NNIE_Cnn_Deinit(&pPriv->stENnieParam, &pPriv->stENnieModel);
    // SAMPLE_COMM_SVP_CheckSysExit();
    return NCE_FAILED;
}

NCE_S32 hisi_3516dv300_engine::engine_get_result(LinkedHashMap<string, tmp_map_result> &st_engine_result)
{
    NCE_S32  count        = 0;
    HI_S32 * tmp_feat     = NULL;
    NCE_F32 *tmp_feat_f32 = NULL;
    int      ret          = 0;

    for (auto &kv : st_engine_result)
    {
        tmp_feat        = (HI_S32 *)((size_t)pPriv->stENnieParam.astSegData[0].astDst[count].u64VirAddr);
        tmp_feat_f32    = (NCE_F32 *)tmp_feat;
        NCE_S32 width   = st_engine_result[kv].tensor.height_stride;
        NCE_S32 height  = st_engine_result[kv].tensor.u32FeatHeight;
        NCE_S32 channel = st_engine_result[kv].tensor.u32ch;
        NCE_S32 num     = width * height * channel;
        printf("%s %d %d %d \n",st_engine_result[kv].tensor.name.c_str(),
        width,
        height,
        channel
        );
        for (int i = 0; i < num; i++)
        {
            *(tmp_feat_f32 + i) = ((NCE_F32)(*(tmp_feat + i)))/4096.f;
        }

        st_engine_result[kv].pu32Feat = (NCE_S32 *)tmp_feat;
        count++;
    }

    return ret;
}

NCE_S32 hisi_3516dv300_engine::engine_destroy()
{
    HI_S32 s32Ret = HI_SUCCESS;
    /*hardware para deinit*/
    if (&pPriv->stENnieParam != NULL)
    {
        s32Ret = SAMPLE_COMM_SVP_NNIE_ParamDeinit(&pPriv->stENnieParam);
        SAMPLE_SVP_CHECK_EXPR_TRACE(
            HI_SUCCESS != s32Ret, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_COMM_SVP_NNIE_ParamDeinit failed!\n");
    }
    /*model deinit*/
    if (&pPriv->stENnieModel != NULL)
    {
        s32Ret = SAMPLE_COMM_SVP_NNIE_UnloadModel(&pPriv->stENnieModel);
        SAMPLE_SVP_CHECK_EXPR_TRACE(
            HI_SUCCESS != s32Ret, SAMPLE_SVP_ERR_LEVEL_ERROR, "Error,SAMPLE_COMM_SVP_NNIE_UnloadModel failed!\n");
    }
    return s32Ret;
}
} // namespace nce_alg
