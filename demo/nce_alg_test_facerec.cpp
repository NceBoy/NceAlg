/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-23 10:12:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-01-24 11:43:56
 */

#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "common.h"
#include <time.h>
#include "string.h"
#include <math.h>
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

float getMold_c(float *vec, NCE_S32 dims)
{
    int   n   = dims;
    float sum = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sum += vec[i] * vec[i];
    }

    return sqrt(sum);
}

float getSimilarity_c(float *lhs, float *rhs, NCE_S32 dims)
{
    int   n   = dims;
    float tmp = 0.0;
    for (int i = 0; i < n; ++i)
        tmp += lhs[i] * rhs[i];

    return tmp / (getMold_c(lhs, dims) * getMold_c(rhs, dims));
}

/******************************************************************************
 * function : show usage
 ******************************************************************************/
void Show_Usage()
{
    printf("the 1th param is yampath\n"
           "the 2th param is picturepath\n"
           "the 3th param is picturepath\n"
           "the 4th param is alg type\n"
           "----HISI_3516DV300------0\n"
           "----HISI_3559AV100------1\n"
           "----RK_1808-------------2\n"
           "----RV_1126-------------3\n"
           "----RV_1109-------------4\n"
           "----OPENVINO------------5\n"
           "----MNNPLATFORM---------6\n"
           "----SNPE_PLATFORM-------7\n"
           "----HOST----------------8\n"
           "the 5th param is alg type\n"
           "----ARCFACE-------------11\n");
}
int main(int argc, char *argv[])
{
    // return 0;
#if 1
    if (argc != 6)
    {
        Show_Usage();
        return -1;
    }
    try
    {
        char *pcYamlName     = argv[1];
        char *face_img1_path = argv[2];
        char *face_img2_path = argv[3];

        // opencv读进来 是hwc 也就是 pakcage
        img_t   face_img1;
        img_t   face_img2;
        NCE_S32 res = nce_read_img(face_img1_path, face_img1);
        if (res == NCE_SUCCESS)
        {
            printf("successful load img! h: %d w: %d c: %d\n",
                   face_img1.image_attr.u32Height,
                   face_img1.image_attr.u32Width,
                   face_img1.image_attr.u32channel);
        }
        else
        {
            printf("load img failed!\n");
            return NCE_FAILED;
        }
        res = nce_read_img(face_img2_path, face_img2);
        if (res == NCE_SUCCESS)
        {
            printf("successful load img! h: %d w: %d c: %d\n",
                   face_img2.image_attr.u32Height,
                   face_img2.image_attr.u32Width,
                   face_img2.image_attr.u32channel);
        }
        else
        {
            printf("load img failed!\n");
            return NCE_FAILED;
        }

        vector<img_info> imgInfo;
        nce_alg_machine  face_model(taskcls(atoi(argv[5])), platform(atoi(argv[4])));
        face_model.nce_alg_init(pcYamlName, imgInfo);
        auto model_input = imgInfo[0];
        printf("input img dim is width: %d, height: %d, channel: %d",
               model_input.u32Width,
               model_input.u32Height,
               model_input.u32channel);



        ImageProcessParam resized;
        resized.type                         = PROC_RESIZE;
        resized.Info.resize_info.dst_channel = model_input.u32channel;
        resized.Info.resize_info.dst_height  = model_input.u32Height;
        resized.Info.resize_info.dst_width   = model_input.u32Width;

        nce_resize dooresize(resized);
        printf("before func_resize\n");
        dooresize.forward(face_img1, face_img1);
        dooresize.forward(face_img2, face_img2);
        printf("after func_resize\n");

        ImageProcessParam pkg2pln;
        pkg2pln.type                         = PROC_PACKAGE2PLANNER;
        pkg2pln.Info.package2planner_info.channel = model_input.u32channel;
        pkg2pln.Info.package2planner_info.height  = model_input.u32Height;
        pkg2pln.Info.package2planner_info.width   = model_input.u32Width;

        nce_package2planner doo(pkg2pln);

        doo.forward(face_img1, face_img1);
        doo.forward(face_img2, face_img2);
        printf("after func_pkg2pln\n");
        nce_write_img("face_img1.jpg", face_img1);
        nce_write_img("face_img2.jpg", face_img2);
        alg_result_info results1;
        alg_result_info results2;
        OSA_DEBUG_DEFINE_TIME

        vector<img_t> frames1;
        vector<img_t> frames2;
        frames1.push_back(face_img1);
        frames2.push_back(face_img2);
        OSA_DEBUG_START_TIME
        face_model.nce_alg_inference(frames1);
        face_model.nce_alg_get_result(results1);
        NCE_S32  dims = ((FaceID *)(results1.st_alg_results->obj))->dims;
        NCE_F32 *id1 = new NCE_F32[dims];
        memcpy(id1, ((FaceID *)(results1.st_alg_results->obj))->face_id, dims * sizeof(NCE_F32));
        OSA_DEBUG_END_TIME(head detect cost:)

        OSA_DEBUG_START_TIME
        face_model.nce_alg_inference(frames2);
        face_model.nce_alg_get_result(results2);
        NCE_F32 *id2 = new NCE_F32[dims];
        memcpy(id2, ((FaceID *)(results1.st_alg_results->obj))->face_id, dims * sizeof(NCE_F32));
        OSA_DEBUG_END_TIME(head detect cost:)

        landmarks *result = NULL;






        NCE_F32  sim  = getSimilarity_c(id1, id2, dims);

        printf("similarity of image1 and image 2 is: %f\n", sim);

        delete id1;
        delete id2;
        /*ImageProcessParam pln2pkg;
        pln2pkg.type                         = PROC_PLANNER2PACKAGE;
        pln2pkg.Info.planner2package_info.channel = pkg2pln.Info.package2planner_info.channel;
        pln2pkg.Info.planner2package_info.height  = pkg2pln.Info.package2planner_info.height;
        pln2pkg.Info.planner2package_info.width   = pkg2pln.Info.package2planner_info.width;

        nce_planner2package doo2(pln2pkg);
        printf("before func_resize\n");
        doo2.forward(input_img, input_img);
        printf("after func_resize\n");*/

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
