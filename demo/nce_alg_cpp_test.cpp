/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-23 10:12:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-26 12:22:58
 */

#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "common.h"
#include <time.h>

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
    // return 0;
#if 1
    if (argc < 5 || argc > 5)
    {
        Show_Usage();
        return -1;
    }
    try
    {
        char *pcYamlName = argv[1];
        char *pcSrcFile   = argv[2];

        // opencv读进来 是hwc 也就是 pakcage
        img_t input_img;
        NCE_S32 res = nce_read_img(pcSrcFile, input_img);
        if (res == NCE_SUCCESS)
        {
            printf("successful load img! h: %d w: %d c: %d\n",
                   input_img.image_attr.u32Height,
                   input_img.image_attr.u32Width,
                   input_img.image_attr.u32channel);
        }
        else
        {
            printf("load img failed!\n");
            return NCE_FAILED;
        }

        vector<img_info> imgInfo;
        nce_alg_machine  hd_model(taskcls(atoi(argv[4])), platform(atoi(argv[3])));
        hd_model.nce_alg_init(pcYamlName, imgInfo);
        auto model_input = imgInfo[0];
        printf("input img dim is width: %d, height: %d, channel: %d",
               model_input.u32Width,
               model_input.u32Height,
               model_input.u32channel);

        ImageProcessParam resize_info;
        resize_info.type                         = PROC_RESIZE;
        resize_info.Info.resize_info.dst_channel = model_input.u32channel;
        resize_info.Info.resize_info.dst_height  = model_input.u32Height;
        resize_info.Info.resize_info.dst_width   = model_input.u32Width;

        nce_resize func_resize(resize_info);
        printf("before func_resize\n");
        func_resize.forward(input_img, input_img);
        printf("after func_resize\n");



        alg_result_info results;
        OSA_DEBUG_DEFINE_TIME
        for (int i = 0; i < 20; i++)
        {
            vector<img_t> frames;
            frames.clear();
            frames.push_back(input_img);
            OSA_DEBUG_START_TIME
            hd_model.nce_alg_inference(frames);
            hd_model.nce_alg_get_result(results);
            OSA_DEBUG_END_TIME(head detect cost:)
        }
        detect_result *result = NULL;
        printf("model detect %d results\n", results.num);
        NCE_S32 color[3] = { 255, 0, 0 };
        for (int i = 0; i < results.num; i++)
        {
            result = (detect_result *)((results.st_alg_results + i)->obj);
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
