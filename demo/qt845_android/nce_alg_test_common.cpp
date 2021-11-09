/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-23 10:12:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-26 12:23:16
 */

#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "common.h"

#if (defined WIN32)
#include <time.h>
#define OSA_DEBUG_DEFINE_TIME \
    clock_t start;            \
    clock_t end;
#else
#include <sys/time.h>
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
    // return 0;
#if 1
    if (argc < 3 || argc > 3)
    {
        Show_Usage(argv[0]);
    }
    try
    {
        char *pcModelName = argv[1];
        char *pcSrcFile   = argv[2];

        // opencv读进来 是hwc 也就是 pakcage

        printf("before imread\n");
        img_t input_img;
        printf("after imread\n");
        nce_read_img(pcSrcFile, input_img);

        param_info snpe_param;
        snpe_param.pc_model_path = pcModelName;
        snpe_param.st_engine_info.snpe_param.device_name = "DSP";
        snpe_param.st_engine_info.snpe_param.useUserSuppliedBuffers = false;
        snpe_param.st_engine_info.snpe_param.usingInitCaching       = false;

        task_config_info task_config;
        task_config.threshold                   = 0.5f;
        task_config.isLog                       = 0;
        // task_config.st_cfg.hd_config.nms_thresh = 0.3f;
        task_config.st_cfg.bd_config.nms_thresh  = 0.3f;
        task_config.st_cfg.bd_config.num_cls    = 6;
        task_config.st_cfg.bd_config.num_anchors = 3;
        alg_result_info results;

        vector<img_info> imgInfo;
        nce_alg_machine  hd_model(VFNET, SNPE_PLATFORM);
        hd_model.nce_alg_init(snpe_param, imgInfo);
        printf("input width: %d, height: %d\n", imgInfo[0].u32Width, imgInfo[0].u32Height);
        ImageProcessParam resize_info;
        resize_info.type                         = PROC_RESIZE;
        resize_info.Info.resize_info.dst_channel = 3;
        resize_info.Info.resize_info.dst_height  = imgInfo[0].u32Height;
        resize_info.Info.resize_info.dst_width   = imgInfo[0].u32Width;

        nce_resize func_resize(resize_info);
        printf("before func_resize");
        func_resize.forward(input_img, input_img);
        printf("after func_resize");

        vector<img_t> frames;

        img_t frame;
        frame.image                 = input_img.image;
        frame.image_attr.u32channel = 3;
        frame.image_attr.u32Height  = imgInfo[0].u32Height;
        frame.image_attr.u32Width   = imgInfo[0].u32Width;
        frame.image_attr.order      = RGB;
        frame.image_attr.format     = PACKAGE;

        frames.push_back(frame);

        hd_model.nce_alg_cfg_set(task_config);
        OSA_DEBUG_DEFINE_TIME
        OSA_DEBUG_START_TIME
        hd_model.nce_alg_inference(frames);
        hd_model.nce_alg_get_result(results);
        OSA_DEBUG_END_TIME(head detect cost:)
        detect_result *result = NULL;
        printf("model detect %d results\n", results.num);
        NCE_S32 color[3] = { 0, 0, 255 };
        for (int i = 0; i < results.num; i++)
        {
            result = ((detect_result *)results.st_alg_results->obj) + i;
            Bbox box;
            box.x1 = result->x1;
            box.y1 = result->y1;
            box.x2 = result->x2;
            box.y2 = result->y2;
            // printf("x1: %d y1: %d x2:%d y2: %d\n", box.x1, box.y1, box.x2, box.y2);
            nce_draw_bbox(input_img, box, 2, color);
        }
        hd_model.nce_alg_destroy();

        nce_write_img("test.jpg", input_img);
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
#endif
}
