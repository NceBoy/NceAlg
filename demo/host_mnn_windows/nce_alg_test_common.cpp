/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-23 10:12:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-26 12:23:22
 */

#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "common.h"
#include <time.h>
#define OSA_DEBUG_DEFINE_TIME \
    clock_t start;            \
    clock_t end;

#define OSA_DEBUG_START_TIME start = clock();

#define OSA_DEBUG_END_TIME(S) \
    end = clock();            \
    printf("%s %ld ms\n", #S, end - start);

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
        return -1;
    }
    try
    {
        char *pcModelName = argv[1];
        char *pcSrcFile   = argv[2];

        printf("before imread\n");
        img_t input_img;
        printf("after imread\n");
        nce_read_img(pcSrcFile, input_img);

        ImageProcessParam resize_info;
        resize_info.type                         = PROC_RESIZE;
        resize_info.Info.resize_info.dst_channel = 3;
        resize_info.Info.resize_info.dst_height  = 360;
        resize_info.Info.resize_info.dst_width   = 640;

        nce_resize func_resize(resize_info);
        printf("before func_resize");

        func_resize.forward(input_img,input_img);
        nce_write_img("test_.jpg", input_img);
        printf("after func_resize");
        // cvtColor(image, image, COLOR_BGR2RGB);
        vector<img_t> frames;

        img_t frame;
        frame.image                 = input_img.image;
        frame.image_attr.u32channel = 3;
        frame.image_attr.u32Height  = 360;
        frame.image_attr.u32Width   = 640;
        frame.image_attr.order      = RGB;
        frame.image_attr.format     = PACKAGE;

        frames.push_back(frame);
        param_info mnn_param;
        mnn_param.pc_model_path = pcModelName;

        task_config_info task_config;
        task_config.threshold                   = 0.3;
        task_config.isLog                       = 0;
        task_config.st_cfg.hd_config.nms_thresh = 0.3;
        alg_result_info results;

        vector<img_info> imgInfo;
        nce_alg_machine  hd_model(CENTERNET, MNNPLATFORM);
        hd_model.nce_alg_init(mnn_param, imgInfo);
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
            printf("x1: %d y1: %d x2:%d y2: %d\n", box.x1, box.y1, box.x2, box.y2);
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
