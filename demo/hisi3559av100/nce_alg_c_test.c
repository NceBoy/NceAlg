#include <stdio.h>
#include "alg_type.h"
#include "nce_alg_c.h"
#include "hi_comm_svp.h"
#include "sample_comm_svp.h"
#include <time.h>


/******************************************************************************
 * function : show usage
 ******************************************************************************/
void Show_Usage(char *pchPrgName)
{
    printf("Usage : %s <index> \n", pchPrgName);
    printf("index:\n");
    printf("\t 4) Cnn(Read File).\n");
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3)
        Show_Usage(argv[0]);

    //注意 该接口如果在编码模块已经调用，则无需再次调用
    SAMPLE_COMM_SVP_CheckSysInit();
    char *pcModelName = argv[1];
    char *pcSrcFile   = argv[2];

    // 读进来 是hwc 也就是 pakcage
    img_t frame;
    int                            ret;
    nce_alg_c_machine              machine;
    long            spend;
    struct timespec start, next, end;



    //根据类型，算法构造相应的引擎工厂
    machine.clstype = VFNET;
    machine.platformtype = HISI_3559AV100;
    nce_alg_c_machine_init(&machine);

    //读图测试，实际运行不需要，实际hisi需要rgb，planner格式的图片
    nce_c_read_img(pcSrcFile, &frame);
    nce_c_package2planner(&frame);

    //初始化
    //初始化参数 IN
    param_info hisi3559_param;
    hisi3559_param.pc_model_path = pcModelName;
    hisi3559_param.priv_cfg_path = NULL;//"./config.yaml";
    //图片组信息 OUT
    nce_alg_c_img_infos img_infos;
    
    machine.init_func(machine.pPriv,&hisi3559_param,&img_infos);

    //设置算法运行时参数
    task_config_info task_config;
    task_config.threshold                   = 0.6;
    task_config.isLog                       = 0;
    task_config.st_cfg.hd_config.nms_thresh = 0.6;
    machine.cfg_set_func(machine.pPriv,&task_config);
    
    
    clock_gettime(0, &start);
    //推理
    img_t *pimg = &frame;
    img_t **ppimg = &pimg; 

    machine.inference_func(machine.pPriv,ppimg,1);

    //取结果
    alg_result_info results;
    machine.getResult_func(machine.pPriv,&results);

    clock_gettime(0, &end);
    spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("\n[for hisi]===== TIME SPEND: %ld ms =====\n", spend);
    

    //注意！！！！由于alg_result_info中的 st_alg_results指针
    // 以及st_alg_results指针中的 obj 都由算法分配
    // 所以如果把推理和取结果两个接口做异步，必须在得到结果后立马拷贝出来，防止被覆盖！

        detect_result *result   = NULL; 
    
    //绘图接口需要在package下完成
    nce_c_planner2package(&frame);
    Bbox box;
    for (int i = 0; i < results.num; i++)
    {

        result = ((detect_result *)results.st_alg_results->obj) + i;
        box.x1 = result->x1;
        box.y1 = result->y1;
        box.x2 = result->x2;
        box.y2 = result->y2;
        printf(" %d %d %d %d %f\n", box.x1, box.x2, box.y1, box.y2, result->score);
        nce_c_draw_bbox(&frame, box);
    }

    nce_c_write_img("result", &frame);
    nce_c_free_img(&frame);
    nce_alg_c_machine_deinit(&machine);

    SAMPLE_COMM_SVP_CheckSysExit();

}
