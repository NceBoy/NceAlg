#include <stdio.h>
#include <stdlib.h>
#include "alg_type.h"
#include "nce_alg_c.h"
#include <time.h>


/******************************************************************************
 * function : show usage
 ******************************************************************************/
void Show_Usage()
{
    printf("the 1th param is yampath\n"
           "the 2th param is picturepath\n"
           "the 3th param is alg type\n"
            "----HISI_3516DV300------0\n"
            "----HISI_3559AV100------1\n"
            "----RK_1808-------------2\n"
            "----RV_1126-------------3\n"
            "----RV_1109-------------4\n"
            "----OPENVINO------------5\n"
            "----MNNPLATFORM---------6\n"
            "----SNPE_PLATFORM-------7\n"
            "----HOST----------------8\n"
            "the 4th param is alg type\n"
            "----PERSON_HEAD---------0\n"
            "----FACE_DETECT---------1\n"
            "----FACE_PRNET----------2\n"
            "----FACE_RECOGNIZE------3\n"
            "----FACE_FAKE-----------4\n"
            "----CENTERNET-----------5\n"
            "----VFNET---------------6\n"
            "----YOLOX---------------7\n"
            "----OBJECT_RECOGNITION--8\n");
}

int main(int argc, char *argv[])
{
    if (argc < 5 || argc > 5)
    {
        Show_Usage();
        return -1;
    }    

    //注意 该接口如果在编码模块已经调用，则无需再次调用
    //SAMPLE_COMM_SVP_CheckSysInit();
    char *pcYamlName = argv[1];
    char *pcSrcFile   = argv[2];

    // 读进来 是hwc 也就是 pakcage
    img_t frame;
    int                            ret;
    nce_alg_c_machine              machine;
    long            spend;
    struct timespec start, next, end;



    //根据类型，算法构造相应的引擎工厂
    machine.clstype = atoi(argv[4]);//VFNET;
    machine.platformtype = atoi(argv[3]);//HISI_3559AV100;
    nce_alg_c_machine_init(&machine);

    //读图测试，实际运行不需要，实际hisi需要rgb，planner格式的图片
    nce_c_read_img(pcSrcFile, &frame);
    nce_c_package2planner(&frame);

    //初始化
    //初始化参数 IN
    param_info hisi3559_param;
    hisi3559_param.yaml_cfg_path = pcYamlName;//"./config.yaml";
    //图片组信息 OUT
    nce_alg_c_img_infos img_infos;
    
    machine.init_func(machine.pPriv,&hisi3559_param,&img_infos);

    //设置算法运行时参数
    /*task_config_info task_config;
    task_config.threshold                   = 0.3;
    task_config.isLog                       = 0;
    task_config.st_cfg.hd_config.nms_thresh = 0.6;
    machine.cfg_set_func(machine.pPriv,&task_config);*/
    
    
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
    printf("\n[for inference]===== TIME SPEND: %ld ms =====\n", spend);
    

    //注意！！！！由于alg_result_info中的 st_alg_results指针
    // 以及st_alg_results指针中的 obj 都由算法分配
    // 所以如果把推理和取结果两个接口做异步，必须在得到结果后立马拷贝出来，防止被覆盖！

        detect_result *result   = NULL; 
    
    //绘图接口需要在package下完成
    nce_c_planner2package(&frame);
    Bbox box;
    for (int i = 0; i < results.num; i++)
    {
        result = (detect_result *)((results.st_alg_results + i)->obj);
        //result = ((detect_result *)results.st_alg_results->obj) + i;
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

    //SAMPLE_COMM_SVP_CheckSysExit();

}
