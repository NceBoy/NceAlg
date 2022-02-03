#include <stdio.h>
#include <stdlib.h>
#include "alg_type.h"
#include "nce_alg_c.h"
#if (defined WIN32)
#include <time.h>
#define OSA_DEBUG_DEFINE_TIME \
    clock_t start;            \
    clock_t end;
#else
#include <sys/time.h>
#include <time.h>
#define OSA_DEBUG_DEFINE_TIME \
    struct timespec start;    \
    struct timespec end;
#endif

#if (defined WIN32)
#define OSA_DEBUG_START_TIME start = clock();
#else
#define OSA_DEBUG_START_TIME clock_gettime(CLOCK_REALTIME, &start);
#endif

#if (defined WIN32)
#define OSA_DEBUG_END_TIME(S) \
    end = clock();            \
    printf("%s %ld ms\n", #S, end - start);
#else
#define OSA_DEBUG_END_TIME(S)            \
    clock_gettime(CLOCK_REALTIME, &end); \
    printf("%s %ld ms\n", #S, 1000 * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000);
#endif

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

    char *pcYamlName = argv[1];
    char *pcSrcFile   = argv[2];

    img_t frame;
    int                            ret;
    nce_alg_c_machine              machine;
    long            spend;

    OSA_DEBUG_DEFINE_TIME

    machine.clstype = atoi(argv[4]);
    machine.platformtype = atoi(argv[3]);
    nce_alg_c_machine_init(&machine);


    nce_c_read_img(pcSrcFile, &frame);
    nce_c_package2planner(&frame);

    param_info hisi3559_param;
    hisi3559_param.yaml_cfg_path = pcYamlName;//"./config.yaml";
    nce_alg_c_img_infos img_infos;

    machine.init_func(machine.pPriv,&hisi3559_param,&img_infos);

    /*task_config_info task_config;
    task_config.threshold                   = 0.3;
    task_config.isLog                       = 0;
    task_config.st_cfg.hd_config.nms_thresh = 0.6;
    machine.cfg_set_func(machine.pPriv,&task_config);*/

    
    OSA_DEBUG_START_TIME
    img_t *pimg = &frame;
    img_t **ppimg = &pimg; 

    machine.inference_func(machine.pPriv,ppimg,1);

    alg_result_info results;
    machine.getResult_func(machine.pPriv,&results);

    OSA_DEBUG_END_TIME(detec time is)

    detect_result *result   = NULL; 
    
    nce_c_planner2package(&frame);
    Bbox box = {0};
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
    return 0;
    //SAMPLE_COMM_SVP_CheckSysExit();

}
