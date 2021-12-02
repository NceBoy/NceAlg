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

using namespace std;
using namespace nce_alg;


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
        resize_info.Info.resize_info.dst_height  = 128;
        resize_info.Info.resize_info.dst_width   = 128;

        nce_resize func_resize(resize_info);
        printf("before func_resize");

        func_resize.forward(input_img, input_img);
        nce_write_img("test_.jpg", input_img);
        printf("after func_resize");
        // cvtColor(image, image, COLOR_BGR2RGB);
        vector<img_t> frames;

        img_t frame;
        frame.image                 = input_img.image;
        frame.image_attr.u32channel = 3;
        frame.image_attr.u32Height  = 128;
        frame.image_attr.u32Width   = 128;
        frame.image_attr.order      = RGB;
        frame.image_attr.format     = PACKAGE;

        frames.push_back(frame);
        param_info mnn_param;
        mnn_param.pc_model_path = pcModelName;

        task_config_info task_config;
        task_config.threshold                   = 0.95;
        task_config.isLog                       = 0;
        alg_result_info results;

        vector<img_info> imgInfo;
        nce_alg_machine  ob_model(OBJECT_RECOGNITION, MNNPLATFORM);
        //ob_model.nce_alg_init(mnn_param, imgInfo);
        const char *yaml_path = "./repvgg_recognition.yaml";
        ob_model.nce_alg_init(yaml_path, imgInfo);
        //ob_model.nce_alg_cfg_set(task_config);
        OSA_DEBUG_DEFINE_TIME
        OSA_DEBUG_START_TIME
        ob_model.nce_alg_inference(frames);
        ob_model.nce_alg_get_result(results);
        OSA_DEBUG_END_TIME(object recognize cost:)
        humanbody_reco *result = NULL;
        printf("model recognize %d results\n", results.num);
        NCE_S32 color[3] = { 0, 0, 255 };
        for (int i = 0; i < results.num; i++)
        {
            result = ((humanbody_reco *)(results.st_alg_results + i)->obj);
            auto label = result->label;
            auto score = result->score[label];
            printf("classification label: %d score: %f\n", label, score);
        }
        ob_model.nce_alg_destroy();

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
