#include "util.hpp"
#include "alg_type.h"
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
namespace nce_alg
{
	NCE_S32 nms(vector<alg_result> input, vector<alg_result> &output, float threshold)
	{
		output.clear();
		sort(input.begin(), input.end(),
			[](const alg_result &a, const alg_result &b) {
			return a.score > b.score;
		});

		int box_num = input.size();

		vector<int> merged(box_num, 0);

		for (int i = 0; i < box_num; i++)
		{
			if (merged[i])
				continue;

			//output.push_back(input[i]);
			output.emplace_back(input[i]);

			float h0 = input[i].y2 - input[i].y1 + 1;
			float w0 = input[i].x2 - input[i].x1 + 1;

			float area0 = h0 * w0;

			for (int j = i + 1; j < box_num; j++)
			{
				if (merged[j])
					continue;

				float inner_x0 = max(input[i].x1, input[j].x1);
				float inner_y0 = max(input[i].y1, input[j].y1);

				float inner_x1 = min(input[i].x2, input[j].x2);
				float inner_y1 = min(input[i].y2, input[j].y2);

				float inner_h = inner_y1 - inner_y0 + 1;
				float inner_w = inner_x1 - inner_x0 + 1;

				if (inner_h <= 0 || inner_w <= 0)
					continue;

				float inner_area = inner_h * inner_w;

				float h1 = input[j].y2 - input[j].y1 + 1;
				float w1 = input[j].x2 - input[j].x1 + 1;

				float area1 = h1 * w1;

				float score = inner_area / (area0 + area1 - inner_area);

				if (score > threshold)
					merged[j] = 1;

			}
		}
		return NCE_SUCCESS;
	}

	NCE_S32 RB_REPLACE_PACKAGE(img_info & frame)
		//"Only used for rgb_package image"
	{

		for (NCE_U32 h = 0; h < frame.u32Width; h++)
		{
			for (NCE_U32 w = 0; w < frame.u32Height; w++)
			{
				NCE_U8 u8tmpB = frame.image[(h*frame.u32Width + w)*frame.u32channel + 0];
				frame.image[(h*frame.u32Width + w)*frame.u32channel + 0] = frame.image[(h*frame.u32Width + w)*frame.u32channel + 2];
				frame.image[(h*frame.u32Width + w)*frame.u32channel + 2] = u8tmpB;
			}
		}


		return NCE_SUCCESS;
	}

	NCE_S32 RB_REPLACE_PLANNER(img_info & frame)
		//"Only used for rgb_package image"
	{
		NCE_U32 u32ImageSize = frame.u32Width * frame.u32Height;
		for (NCE_U32 h = 0; h < frame.u32Width; h++)
		{
			for (NCE_U32 w = 0; w < frame.u32Height; w++)
			{
				NCE_U8 u8tmpB = frame.image[0 * u32ImageSize + h*frame.u32Width + w];
				frame.image[0 * u32ImageSize + h*frame.u32Width + w] = frame.image[2 * u32ImageSize + h*frame.u32Width + w];;
				frame.image[2 * u32ImageSize + h*frame.u32Width + w] = u8tmpB;
			}
		}

		return NCE_SUCCESS;
	}

	NCE_S32 softmax(NCE_U32 dim, NCE_F32* score)
	{
		NCE_F32 sum = 0;
		for (NCE_U32 i=0; i < dim; i++)
		{
			sum = sum + exp(score[i]);
		}

		for (NCE_U32 i=0; i < dim; i++)
		{
			score[i] = exp(score[i])/sum;
		}
		return NCE_SUCCESS;
	}

}