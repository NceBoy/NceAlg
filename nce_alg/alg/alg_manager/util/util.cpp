#include "util/util.hpp"
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

            NCE_F32 score = inner_area / (area0 + area1 - inner_area);
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

NCE_F32 nce_mean(NCE_U8 *img, NCE_S32 num_ele)
{
    ;
    NCE_F32 sum = 0;
    for (NCE_S32 i = 0; i < num_ele; i++)
    {
        sum += img[i];
    }
    return sum / (NCE_F32)num_ele;
}

std::pair<NCE_F32, NCE_F32> nce_mean_var(NCE_U8 *img, NCE_S32 num_ele)
{
    NCE_F32 var  = 0;
    NCE_F32 mean = nce_mean(img, num_ele);
    for (NCE_S32 i = 0; i < num_ele; i++)
    {
        var += pow(((NCE_F32)img[i] - mean), 2);
    }
    var = var / num_ele;
    return std::pair<NCE_F32, NCE_F32>(mean, var);
};

NCE_S32 get_saturation(const img_t &img, detect_result Bbox, NCE_U8 *output_sat)
{
    if (img.image_attr.u32channel != 3)
    {
        printf("get_saturation only support rgb package img!!!");
        assert(false);
    }
    NCE_S32 crop_width  = Bbox.x2 - Bbox.x1;
    NCE_S32 crop_height = Bbox.y2 - Bbox.y1;
    NCE_S32 img_width   = img.image_attr.u32Width;
    NCE_S32 img_height  = img.image_attr.u32Height;

    NCE_U8 *img_data         = img.image;
    NCE_S32 img_width_stride = 0, img_height_stride = 0, img_channel_stride = 0;

    if (img.image_attr.format == PACKAGE)
    {
        img_channel_stride = 1;
        img_width_stride   = img.image_attr.u32channel;
        img_height_stride  = img_width * img_width_stride;
    }
    else if (img.image_attr.format == PLANNER)
    {
        img_channel_stride = img.image_attr.u32Height * img.image_attr.u32Width;
        img_width_stride   = 1;
        img_height_stride  = img.image_attr.u32Width;
    }
    else
    {
        printf("only support package or planner rgb img!!!");
        assert(false);
    }

    for (NCE_S32 h = 0; h < crop_height; h++)
    {
        for (NCE_S32 w = 0; w < crop_width; w++)
        {
            NCE_U8  channel_min  = 0;
            NCE_U8  channel_max  = 255;
            NCE_S32 global_x     = Bbox.x1 + w;
            NCE_S32 global_y     = Bbox.y1 + h;
            NCE_S32 global_index = global_x * img_width_stride + global_y * img_height_stride;
            NCE_S32 local_index  = crop_width * h + w;

            NCE_U8 one   = img_data[global_index + 0 * img_channel_stride];
            NCE_U8 two   = img_data[global_index + 1 * img_channel_stride];
            NCE_U8 three = img_data[global_index + 2 * img_channel_stride];

            if (one > two)
            {
                if (one > three)
                {
                    channel_max = one;
                    if (two > three)
                    {
                        channel_min = three;
                    }
                    else
                    {
                        channel_min = two;
                    }
                }
                else
                {
                    channel_max = three;
                    channel_min = two;
                }
            }
            else
            {
                if (one < three)
                {
                    channel_min = one;
                    if (two < three)
                    {
                        channel_max = three;
                    }
                    else
                    {
                        channel_max = two;
                    }
                }
                else
                {
                    channel_min = three;
                    channel_max = two;
                }
            }
            NCE_U8 sat              = channel_max - channel_min;
            output_sat[local_index] = sat;
        }
    }
    return NCE_SUCCESS;
}

NCE_S32 refelction_judge(const img_t &          frame,
                         alg_result_info        &results,
                         NCE_F32                conf_thresh,
                         NCE_F32                mean_thresh,
                         NCE_F32                var_thresh)
{
    static NCE_U8 sat_data[1000 * 1000];
    assert(frame.image_attr.u32channel == 3);
    for (NCE_S32 i = 0; i < results.num; i++) 
    {
        auto box = (detect_result *)(results.st_alg_results + i)->obj;
        if (box->score < conf_thresh)
        {
            NCE_S32 x1      = box->x1;
            NCE_S32 y1      = box->y1;
            NCE_S32 x2      = box->x2;
            NCE_S32 y2      = box->y2;
            NCE_S32 h       = y2 - y1;
            NCE_S32 w       = x2 - x1;
            NCE_S32 num_ele = h * w;

            get_saturation(frame, *box, sat_data);
            auto    mean_var = nce_mean_var(sat_data, num_ele);
            NCE_F32 mean     = mean_var.first;
            NCE_F32 var      = mean_var.second;

            if (var < mean_thresh & mean < mean_thresh)
            {
                box->score = 0;
            }
        }
    }

    return NCE_SUCCESS;
}

} // namespace nce_alg