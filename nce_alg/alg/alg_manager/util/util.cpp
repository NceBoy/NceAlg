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

NCE_S32 refelction_judge(const img_t &    frame,
                         alg_result_info &results,
                         NCE_F32          conf_thresh,
                         NCE_F32          mean_thresh,
                         NCE_F32          var_thresh)
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

NCE_S32 get_inv_affine_matrix(point point1[2], point point2[2], NCE_F32 affine_matrix[9])
{
    NCE_F32 x1 = point1[0].x;
    NCE_F32 y1 = point1[0].y;
    NCE_F32 x2 = point1[1].x;
    NCE_F32 y2 = point1[1].y;

    NCE_F32 x1_ = point2[0].x;
    NCE_F32 y1_ = point2[0].y;
    NCE_F32 x2_ = point2[1].x;
    NCE_F32 y2_ = point2[1].y;

    NCE_F32 theta;
    NCE_F32 a;
    if ((x1 - x2) * (x1_ - x2_) + (y1 - y2) * (y1_ - y2_) == 0)
    {
        if (((x1 - x2) * (y1_ - y2_) - (y1 - y2) * (x1_ - x2_)) <= 0)
        {
            theta = asin(1.0) * 1;
        }
        else
        {
            theta = asin(1.0) * 3;
        }
    }
    else
     theta =
        atan(((x1 - x2) * (y1_ - y2_) - (y1 - y2) * (x1_ - x2_)) / ((x1 - x2) * (x1_ - x2_) + (y1 - y2) * (y1_ - y2_)));
    if ((cos(theta) * (x1 - x2) - sin(theta) * (y1 - y2)) == 0) a = 1;
    else a = (x1_ - x2_) / (cos(theta) * (x1 - x2) - sin(theta) * (y1 - y2));
    NCE_F32 c = x1_ - a * cos(theta) * x1 + a * y1 * sin(theta);
    NCE_F32 d = y1_ - a * sin(theta) * x1 - a * y1 * cos(theta);

    affine_matrix[0] = cos(theta) / a;
    affine_matrix[1] = sin(theta) / a;
    affine_matrix[2] = (-sin(theta) * d - c * cos(theta)) / a;
    affine_matrix[3] = -sin(theta);
    affine_matrix[4] = cos(theta) / a;
    affine_matrix[5] = -(cos(theta) * d - sin(theta) * c) / a;
    affine_matrix[6] = 0;
    affine_matrix[7] = 0;
    affine_matrix[8] = 1;

    return NCE_SUCCESS;
}

NCE_S32 inv_warp_affine(img_t src, img_t dst, NCE_F32 affine_matrix[9])
{
    NCE_F32 src_width = src.image_attr.u32Width;
    NCE_F32 src_height = src.image_attr.u32Height;
    NCE_F32 src_channel = src.image_attr.u32channel;

    NCE_F32 dst_width = dst.image_attr.u32Width;
    NCE_F32 dst_height = dst.image_attr.u32Height;
    NCE_S32 dst_channel = dst.image_attr.u32channel;
    for (NCE_F32 h = 0; h < dst.image_attr.u32Height; h++)
    {
        for (NCE_F32 w = 0; w < dst.image_attr.u32Height; w++)
        {
            NCE_F32 src_x = w * affine_matrix[0] + (h + 1) * affine_matrix[1] + affine_matrix[2];
            NCE_F32 src_y = w * affine_matrix[3] + (h + 1) * affine_matrix[4] + affine_matrix[5];

            if (src_x > src_width || src_x < 0 || src_y > src_height || src_y < 0)
            {
                //printf("idx out of range\n");
                continue;
            }

            NCE_U32 src_x_lt = (NCE_U32)min(src_x, src_width - 2);
            NCE_U32 src_y_lt = (NCE_U32)min(src_y, src_height - 2);

            NCE_U32 src_x_rb = src_x_lt + 1;
            NCE_U32 src_y_rb = src_y_lt + 1;

            NCE_U32 src_x_lb = src_x_lt;
            NCE_U32 src_y_lb = src_y_lt + 1;

            NCE_U32 src_x_rt = src_x_lt + 1;
            NCE_U32 src_y_rt = src_y_lt;

            NCE_F32 dx = src_x - src_x_lt;
            NCE_F32 dy = src_y - src_y_lt;

            NCE_F32 factor_lt = (1 - dx) * (1 - dy);
            NCE_F32 factor_lb = (1 - dx) * dy;
            NCE_F32 factor_rt = dx * (1 - dy);
            NCE_F32 factor_rb = dx * dy;

            for (NCE_U32 c = 0; c < dst_channel; c++)
            {
                NCE_U32 dst_index = NCE_U32((NCE_U32)(h * dst_width + w) * dst_channel) + c;

                NCE_U32 src_index_lt = (src_y_lt * (NCE_U32)src_width + src_x_lt) * src_channel + c;
                NCE_U32 src_index_lb = (src_y_lb * (NCE_U32)src_width + src_x_lb) * src_channel + c;
                NCE_U32 src_index_rt = (src_y_rt * (NCE_U32)src_width + src_x_rt) * src_channel + c;
                NCE_U32 src_index_rb = (src_y_rb * (NCE_U32)src_width + src_x_rb) * src_channel + c;


                dst.image[dst_index] =
                    src.image[src_index_lt] * factor_lt + src.image[src_index_lb] * factor_lb
                    + src.image[src_index_rt] * factor_rt + src.image[src_index_rb] * factor_rb;
            }
        }
    }
    return NCE_SUCCESS;
}
} // namespace nce_alg