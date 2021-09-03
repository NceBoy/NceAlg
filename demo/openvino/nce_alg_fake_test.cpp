#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "util.hpp"

using namespace std;
using namespace nce_alg;
using namespace cv;

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
        char *pcSrcFile   = argv[2];

        Mat image = imread(pcSrcFile);
        resize(image, image, Size(80, 80));

        // cvtColor(image, image, COLOR_BGR2RGB);

        int ret;

        img_info frame;
        frame.image      = image.data;
        frame.u32channel = 3;
        frame.u32Height  = 80;
        frame.u32Width   = 80;
        frame.format     = PACKAGE;
        nce_alg::RB_REPLACE_PACKAGE(frame);

        engine_param_info openvino_param;
        openvino_param.pc_model_path                                   = pcModelName;
        openvino_param.st_engine_info.st_openvino_param.pc_device_name = "CPU";

        task_config_info task_config;
        task_config.threshold                   = 0.3;
        task_config.st_cfg.hd_config.nms_thresh = 0.6;
        task_config.isLog                       = 0;
        alg_result_info results;

        nce_alg_machine hd_model(FACE_FAKE);
        hd_model.nce_alg_init(openvino_param);
        hd_model.nce_alg_cfg_set(task_config);
        hd_model.nce_alg_inference(frame);
        hd_model.nce_alg_get_result(results);

        alg_result *result = NULL;

        for (int i = 0; i < results.num; i++)
        {
            char        str[30];
            alg_result *result = (alg_result *)results.st_alg_results;
            NCE_F32     score  = ((person_head *)result->obj)->fake;
            sprintf(str, "score:%f", score);
            putText(image, str, Point(5, 5), 0, 0.2, Scalar(0, 0, 255), 0.3);
        }
        hd_model.nce_alg_destroy();

        imwrite("test.jpg", image);
        return 0;
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
