#include <iostream>

#include <stdio.h>

#include "alg_type.h"

#include "common.h"

#include "nce_alg.hpp"


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

        char *pcModelName = argv[1];

        char *pcSrcFile = argv[2];

        // opencv读进来 是hwc 也就是 pakcage

        img_t frame;
        nce_read_img(pcSrcFile, frame);

        // cvtColor(image, image, COLOR_BGR2RGB);

        unsigned char *pu8PicAddr = NULL;

        unsigned long long u64VirAddr = 0;

        unsigned long long u64PhyAddr = 0;

        int ret;

        std::vector<ImageProcessParam> preprocesses;

        // nce_alg::RB_REPLACE_PACKAGE(frame);

        param_info rv1126_param;

        rv1126_param.pc_model_path = pcModelName;

        task_config_info task_config;

        task_config.threshold = 0.3;

        task_config.isLog = 0;

        task_config.st_cfg.hd_config.nms_thresh = 0.6;

        alg_result_info results;

        vector<img_info> imgInfo;
        vector<img_t> imgs;
        imgs.push_back(frame);

        nce_alg_machine hd_model(PERSON_HEAD, HOST);

        hd_model.nce_alg_init(rv1126_param, imgInfo);

        hd_model.nce_alg_cfg_set(task_config);

        hd_model.nce_alg_process_set(preprocesses);

        hd_model.nce_alg_inference(imgs);

        long spend;

        struct timespec start, next, end;

        clock_gettime(0, &start);

        hd_model.nce_alg_get_result(results);

        clock_gettime(0, &end);

        spend = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

        printf("\n[for hisi]===== TIME SPEND: %ld ms =====\n", spend);

        detect_result *result = NULL;

        NCE_S32 color[3] = { 0, 0, 255 };

        Bbox box;

        for (int i = 0; i < results.num; i++)

        {

            result = ((detect_result *)results.st_alg_results->obj) + i;

            box.x1 = result->x1;

            box.y1 = result->y1;

            box.x2 = result->x2;

            box.y2 = result->y2;

            printf(" %d %d %d %d\n", box.x1, box.x2, box.y1, box.y2);

            nce_draw_bbox(frame, box, 2, color);
        }

        hd_model.nce_alg_destroy();

        nce_write_img(pcSrcFile, frame);

        nce_free_img(frame);

    }

    // HI_MPI_SYS_Munmap((void *)&u64VirAddr, 640*640*12);

    catch (const std::exception &error)
    {

        std::cerr << "[ ERROR ] " << error.what() << std::endl;

        return EXIT_FAILURE;

    }

    catch (...)
    {

        std::cerr << "[ ERROR ] Unknown/internal exception happened." << std::endl;

        return EXIT_FAILURE;
    }
}
