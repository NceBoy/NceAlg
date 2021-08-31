/*
 * @Descripttion: 
 * @version: 
 * @Author: Haochen Ye
 * @Date: 2021-08-23 10:12:26
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-08-30 14:34:50
 */
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "util/util.hpp"

#include <time.h>
#define	OSA_DEBUG_DEFINE_TIME \
  struct timespec start; \
  struct timespec end;

#define OSA_DEBUG_START_TIME \
  clock_gettime(CLOCK_REALTIME, &start);

#define OSA_DEBUG_END_TIME(S) \
  clock_gettime(CLOCK_REALTIME, &end); \
  printf("%s %ld ms\n", #S, 1000 * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000);

using namespace std;
using namespace nce_alg;
using namespace cv;



/******************************************************************************
* function : show usage
******************************************************************************/
void Show_Usage(char* pchPrgName)
{
    printf("Usage : %s <index> \n", pchPrgName);
    printf("index:\n");
    printf("\t 4) Cnn(Read File).\n");
}

int main(int argc, char *argv[])
{
    //return 0;
#if 1
	if (argc < 3 || argc > 3)
    {
        Show_Usage(argv[0]);
    }
	try
	{
	char  * pcModelName = argv[1];
	char  * pcSrcFile = argv[2];

    
//opencv读进来 是hwc 也就是 pakcage
        printf("after imread");            
		Mat image = imread(pcSrcFile);
        cv::resize(image, image, cv::Size(512, 288));
        printf("before imread");
		//cvtColor(image, image, COLOR_BGR2RGB);

		int ret;

		img_t frame;
		frame.image = image.data;
		frame.image_attr.u32channel = 3;
		frame.image_attr.u32Height = 288;
		frame.image_attr.u32Width = 512;
		frame.image_attr.order = BGR;
		frame.image_attr.format = PLANNER;
		//nce_alg::RB_REPLACE_PACKAGE(frame);


		param_info mnn_param;
		mnn_param.pc_model_path = pcModelName;
        
		task_config_info task_config;
		task_config.threshold = 0.3;
		task_config.isLog = 0;
		task_config.st_cfg.hd_config.nms_thresh = 0.6;
		alg_result_info results;

		img_info imgInfo;
		nce_alg_machine hd_model(CENTERNET, MNNPLATFORM);
		hd_model.nce_alg_init(mnn_param, imgInfo);
		hd_model.nce_alg_cfg_set(task_config);

        OSA_DEBUG_DEFINE_TIME
        OSA_DEBUG_START_TIME
		hd_model.nce_alg_inference(frame);
		hd_model.nce_alg_get_result(results);
        OSA_DEBUG_END_TIME(head detect cost:)
		alg_result * result = NULL;
        printf("model detect %d results\n", results.num);
		for (int i = 0; i < results.num; i++)
		{
			result = ((alg_result *)results.st_alg_results) + i;
			int x1 = result->x1;
			int y1 = result->y1;
			int x2 = result->x2;
			int y2 = result->y2;
            printf("x1: %d y1: %d x2:%d y2: %d\n", x1, y1, x2, y2);
			rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 0, 255));

		}
		hd_model.nce_alg_destroy();

		imwrite("test.jpg", image);
	}
    //HI_MPI_SYS_Munmap((void *)&u64VirAddr, 640*640*12);

	catch (const std::exception& error) {
		std::cerr << "[ ERROR ] " << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "[ ERROR ] Unknown/internal exception happened." << std::endl;
		return EXIT_FAILURE;
	}
#endif
}
