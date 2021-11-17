#include "util.hpp"
#include "alg_type.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
using namespace std;
namespace nce_alg {
NCE_S32 nms(vector<detect_result> input, vector<detect_result> &output, NCE_F32 threshold)
{
    output.clear();
    sort(input.begin(), input.end(), [](const detect_result &a, const detect_result &b) { return a.score > b.score; });

    NCE_S32 box_num = input.size();

    vector<NCE_S32> merged(box_num, 0);

    for (NCE_S32 i = 0; i < box_num; i++)
    {
        if (merged[i])
            continue;

        // output.push_back(input[i]);
        output.emplace_back(input[i]);

        NCE_F32 h0 = input[i].y2 - input[i].y1 + 1;
        NCE_F32 w0 = input[i].x2 - input[i].x1 + 1;

        NCE_F32 area0 = h0 * w0;

        for (NCE_S32 j = i + 1; j < box_num; j++)
        {
            if (merged[j])
                continue;

            NCE_F32 inner_x0 = max(input[i].x1, input[j].x1);
            NCE_F32 inner_y0 = max(input[i].y1, input[j].y1);

            NCE_F32 inner_x1 = min(input[i].x2, input[j].x2);
            NCE_F32 inner_y1 = min(input[i].y2, input[j].y2);

            NCE_F32 inner_h = inner_y1 - inner_y0 + 1;
            NCE_F32 inner_w = inner_x1 - inner_x0 + 1;

            if (inner_h <= 0 || inner_w <= 0)
                continue;

            NCE_F32 inner_area = inner_h * inner_w;

            NCE_F32 h1 = input[j].y2 - input[j].y1 + 1;
            NCE_F32 w1 = input[j].x2 - input[j].x1 + 1;

            NCE_F32 area1 = h1 * w1;

            NCE_F32 score        = inner_area / (area0 + area1 - inner_area);
            if (score > threshold)
                merged[j] = 1;
        }
    }
    return NCE_SUCCESS;
}

NCE_S32 RB_REPLACE_PACKAGE(img_t &frame)
//"Only used for rgb_package image"
{

    for (NCE_U32 h = 0; h < frame.image_attr.u32Width; h++)
    {
        for (NCE_U32 w = 0; w < frame.image_attr.u32Height; w++)
        {
            NCE_U8 u8tmpB = frame.image[(h * frame.image_attr.u32Width + w) * frame.image_attr.u32channel + 0];
            frame.image[(h * frame.image_attr.u32Width + w) * frame.image_attr.u32channel + 0] =
                frame.image[(h * frame.image_attr.u32Width + w) * frame.image_attr.u32channel + 2];
            frame.image[(h * frame.image_attr.u32Width + w) * frame.image_attr.u32channel + 2] = u8tmpB;
        }
    }

    return NCE_SUCCESS;
}

NCE_S32 RB_REPLACE_PLANNER(img_t &frame)
//"Only used for rgb_package image"
{
    NCE_U32 u32ImageSize = frame.image_attr.u32Width * frame.image_attr.u32Height;
    for (NCE_U32 h = 0; h < frame.image_attr.u32Width; h++)
    {
        for (NCE_U32 w = 0; w < frame.image_attr.u32Height; w++)
        {
            NCE_U8 u8tmpB = frame.image[0 * u32ImageSize + h * frame.image_attr.u32Width + w];
            frame.image[0 * u32ImageSize + h * frame.image_attr.u32Width + w] =
                frame.image[2 * u32ImageSize + h * frame.image_attr.u32Width + w];
            ;
            frame.image[2 * u32ImageSize + h * frame.image_attr.u32Width + w] = u8tmpB;
        }
    }

    return NCE_SUCCESS;
}

NCE_S32 softmax(NCE_U32 dim, NCE_F32 *score)
{
    NCE_F32 sum = 0;
    for (NCE_U32 i = 0; i < dim; i++)
    {
        sum = sum + exp(score[i]);
    }

    for (NCE_U32 i = 0; i < dim; i++)
    {
        score[i] = exp(score[i]) / sum;
    }
    return NCE_SUCCESS;
}


NCE_F32 nce_mean(NCE_S32* img, NCE_S32 num_ele)
{;
    NCE_F32 sum = 0;
    for (NCE_S32 i = 0; i < num_ele; i++)
    {
        sum += img[i];
    }
    return sum / (NCE_F32)num_ele;
}

NCE_F32 nce_var(NCE_S32 *img, NCE_S32 num_ele)
{
    NCE_F32 var  = 0;
    NCE_F32 mean = nce_mean(img, num_ele);
    for (NCE_S32 i = 0; i < num_ele; i++)
    {
        var += pow(((NCE_F32)img[i] - mean), 2);
    }
    var = var / num_ele;
};

NCE_S32 shadow_judge(const img_t &          frame,
                     vector<detect_result> &input_bboxes,
                     vector<detect_result>  output_bboxes,
                     NCE_F32                thresh)
{
    output_bboxes.clear();
   
    for (auto &box : input_bboxes)
    {
        if (box.score > thresh)
        {
            output_bboxes.push_back(box);
        } 
        else
        {
            NCE_S32 x1 = box.x1;
            NCE_S32 y1 = box.y1;
            NCE_S32 x2 = box.x2;
            NCE_S32 y2 = box.y2;

            for (NCE_S32 x = x1; x < x2; x++)
            {
                for (NCE_S32 y = y1; y < y2; y++)
                {

                }
            }
        }
    }
}

} // namespace nce_alg