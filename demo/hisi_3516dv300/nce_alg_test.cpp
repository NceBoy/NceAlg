#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "alg_type.h"
#include "nce_alg.hpp"
#include "hi_comm_svp.h"
#include "sample_comm_svp.h"
#include "util/util.hpp"


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
	if (argc < 3 || argc > 3)
    {
        Show_Usage(argv[0]);
    }

	
	try
	{
	SAMPLE_COMM_SVP_CheckSysInit();
	char  * pcModelName = argv[1];
	char  * pcSrcFile = argv[2];

    
//opencv读进来 是hwc 也就是 pakcage
		Mat image = imread(pcSrcFile);
		//cvtColor(image, image, COLOR_BGR2RGB);


		unsigned char* pu8PicAddr = NULL;
		unsigned long long u64VirAddr = 0;
		unsigned long long u64PhyAddr = 0;

		int ret;

		img_t frame;
		frame.image = image.data;
		frame.image_attr.u32channel = 3;
		frame.image_attr.u32Height = 640;
		frame.image_attr.u32Width = 640;
		frame.image_attr.order = BGR;
		frame.image_attr.format = PACKAGE;
		//nce_alg::RB_REPLACE_PACKAGE(frame);


		param_info openvino_param;
		openvino_param.pc_model_path = pcModelName;


		task_config_info task_config;
		task_config.threshold = 0.3;
		task_config.isLog = 0;
		task_config.st_cfg.hd_config.nms_thresh = 0.6;
		alg_result_info results;

		img_info imgInfo;
		nce_alg_machine hd_model(PERSON_HEAD,HISI_3516DV300);
		hd_model.nce_alg_init(openvino_param,imgInfo);
		hd_model.nce_alg_cfg_set(task_config);
		hd_model.nce_alg_inference(frame);
		hd_model.nce_alg_get_result(results);

		alg_result * result = NULL;

		for (int i = 0; i < results.num; i++)
		{
			result = ((alg_result *)results.st_alg_results) + i;
			int x1 = result->x1;
			int y1 = result->y1;
			int x2 = result->x2;
			int y2 = result->y2;

			rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0, 0, 255));

		}
		hd_model.nce_alg_destroy();

		imwrite("test.jpg", image);
    SAMPLE_COMM_SVP_CheckSysExit();
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
}
