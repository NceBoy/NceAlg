
#include <stdio.h>
#include <mpi_sys.h>
#include "alg_type.h"
#include "nce_alg_c.h"
#include "hi_comm_svp.h"
#include "sample_comm_svp.h"



int main()
{
    char *pcModelName = "./data/nnie_model/face/ttf_RepVGG_inst.wk";
    char *pcSrcFile   = "./data/nnie_image/rgb_planar/yhc_test.bgr";
    char *pcImagePath = "./data/nnie_image/rgb_planar/yhc_test.jpg";
    
    
    FILE* fp = NULL;
    fp = fopen(pcSrcFile, "rb");

    unsigned char* pu8PicAddr = NULL;
    unsigned long long u64VirAddr = 0;
	unsigned long long u64PhyAddr = 0;
    u64VirAddr = (HI_U64)(size_t)pu8PicAddr;
    SAMPLE_COMM_SVP_CheckSysInit();
    int ret;
    ret = HI_MPI_SYS_MmzAlloc_Cached((unsigned long long*)&u64PhyAddr, (void **)&u64VirAddr, "SAMPLE_NNIE_TASK1", NULL, 640*640*12);
    printf("HI_MPI_SYS_MmzAlloc_Cached ret is %d ",ret);
    pu8PicAddr = (unsigned char*)(size_t)u64VirAddr;
    for(int i = 0;i < 3; i++)
    {
        for(int j = 0; j < 640; j++)
        {
            fread(pu8PicAddr,640*1,1,fp);
            pu8PicAddr += 640;
        }
    }

    ret = HI_MPI_SYS_MmzFlushCache(u64PhyAddr, (void *)(size_t)u64VirAddr,640*640*12);
        printf("HI_MPI_SYS_MmzFlushCache ret is %d ",ret);
    img_info frame;
    frame.VirAddr[0] =  pu8PicAddr;
    //frame.PhyAddr[0] =  u64PhyAddr;

    engine_param_info nnie_param;
    nnie_param.pc_model_path = pcModelName;
    nnie_param.engine_type   = HISI;

    task_config_info task_config;
    task_config.threshold = 0.3;
    task_config.isLog = 0;
    alg_result_info results;

    nce_alg_c_machine hd_model;
    hd_model.clstype = PERSON_HEAD;
    nce_alg_c_machine_int(&hd_model);

    hd_model.init_func(hd_model.pPriv,&nnie_param);
    hd_model.cfg_set_func(hd_model.pPriv,&task_config);
    hd_model.inference_func(hd_model.pPriv,&frame);
    hd_model.getResult_func(hd_model.pPriv,&results);

    alg_result * result = NULL;

    for(int i = 0; i < results.num; i++)
    {
        result = ((alg_result *)results.st_alg_results) + i;
        int x1 = result->x1;
        int y1 = result->y1;
        int x2 = result->x2;
        int y2 = result->y2;
        
        //rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 0, 255));

    }
    hd_model.destroy_func(hd_model.pPriv);
    nce_alg_c_machine_destroy(&hd_model);
    //HI_MPI_SYS_Munmap((void *)&u64VirAddr, 640*640*12);
    HI_MPI_SYS_MmzFree(u64PhyAddr, (HI_VOID*)(size_t)u64VirAddr);
    SAMPLE_COMM_SVP_CheckSysExit();
}
