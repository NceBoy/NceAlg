#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "common.h"
#include "nce_alg.hpp"
#include "hi_comm_svp.h"
#include "sample_comm_svp.h"

using namespace std;
using namespace nce_alg;

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
    {
        Show_Usage(argv[0]);
    }

    try
    {
        SAMPLE_COMM_SVP_CheckSysInit();
        char *pcModelName = argv[1];
        char *pcSrcFile   = argv[2];

        // opencv读进来 是hwc 也就是 pakcage
        img_t frame;
        nce_read_img(pcSrcFile, frame);
        // cvtColor(image, image, COLOR_BGR2RGB);

        unsigned char *    pu8PicAddr = NULL;
        unsigned long long u64VirAddr = 0;
        unsigned long long u64PhyAddr = 0;

        int                            ret;
        std::vector<ImageProcessParam> preprocesses;
        ImageProcessParam              package2planner;
        package2planner.type                              = PROC_PACKAGE2PLANNER;
        package2planner.Info.package2planner_info.channel = 3;
        package2planner.Info.package2planner_info.width   = 896;
        package2planner.Info.package2planner_info.height  = 640;
        ImageProcessParam planner2package;
        planner2package.type                              = PROC_PLANNER2PACKAGE;
        planner2package.Info.planner2package_info.channel = 3;
        planner2package.Info.planner2package_info.width   = 896;
        planner2package.Info.planner2package_info.height  = 640;
        ImageProcessParam resizer;
        resizer.type = PROC_RESIZE;
        resizer.Info.resize_info.dst_width = 384;    
        resizer.Info.resize_info.dst_height = 640;    
        resizer.Info.resize_info.dst_channel = 3;          
        preprocesses.push_back(resizer);
        preprocesses.push_back(package2planner);
        // preprocesses.push_back(resizer);
        // preprocesses.push_back(planner2package);

        // nce_alg::RB_REPLACE_PACKAGE(frame);
        nce_resize func_resize(resizer);
        printf("before func_resize");
        nce_package2planner doo(package2planner);

        doo.forward(frame, frame);
        //func_resize.forward(frame,frame);
        param_info hisi3516_param;
        hisi3516_param.pc_model_path = pcModelName;
        task_config_info task_config;
        task_config.threshold                   = 0.6;
        task_config.isLog                       = 0;
        task_config.st_cfg.hd_config.nms_thresh = 0.6;
        alg_result_info results;

        vector<img_info> imgInfos;
        nce_alg_machine  hd_model(VFNET, HISI_3559AV100);

        //hd_model.nce_alg_init(hisi3516_param, imgInfos);
        hd_model.nce_alg_init("./config.yaml", imgInfos);
        // hd_model.nce_alg_cfg_set(task_config);
        //hd_model.nce_alg_process_set(preprocesses);


        vector<img_t> imgs;
        imgs.push_back(frame);
        long            spend;
        struct timespec start, next, end;
        clock_gettime(0, &start);
        hd_model.nce_alg_inference(imgs);
        hd_model.nce_alg_get_result(results);
        clock_gettime(0, &end);
        spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
        printf("\n[for hisi]===== TIME SPEND: %ld ms =====\n", spend);
        detect_result *result   = NULL;
        NCE_S32        color[3] = { 0, 0, 255 };
        Bbox           box;
        nce_planner2package doo2(planner2package);
        doo2.forward(frame,frame);
        for (int i = 0; i < results.num; i++)
        {

            result = ((detect_result *)results.st_alg_results->obj) + i;
            box.x1 = result->x1;
            box.y1 = result->y1;
            box.x2 = result->x2;
            box.y2 = result->y2;
            printf(" %d %d %d %d %f\n", box.x1, box.x2, box.y1, box.y2, result->score);
            nce_draw_bbox(frame, box, 2, color);
        }
        hd_model.nce_alg_destroy();


        nce_write_img("result.jpg", frame);
        nce_free_img(frame);
        SAMPLE_COMM_SVP_CheckSysExit();
    }
    // HI_MPI_SYS_Munmap((void *)&u64VirAddr, 640*640*12);

    catch (const std::exception &error)
    {
        std::cerr << "[ ERROR ] " << error.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...)
    {
        std::cerr << "[ ERROR ] Unknown/internal exception happened." << std::endl;
        return EXIT_FAILURE;
    }
}
