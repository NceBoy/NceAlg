#include "common.h"
#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"

NCE_S32 nce_read_img(const char *img_path, img_t &input_img)
{

    int width, height, channels;

    input_img.image = stbi_load(img_path, &width, &height, &channels, 0);

    if (!input_img.image)
    {
        fprintf(stderr, "Cannot load image \"%s\"\nSTB Reason: %s\n", img_path, stbi_failure_reason());
        return NCE_FAILED;
    }

    input_img.image_attr.u32Width   = width;
    input_img.image_attr.u32Height  = height;
    input_img.image_attr.u32channel = channels;
    input_img.image_attr.order      = RGB;
    input_img.image_attr.format     = PACKAGE;
    return NCE_SUCCESS;
}

NCE_S32 nce_write_img(const char *img_path, img_t &input_img)
{
    char buff[256];

    NCE_S32 success = 0;
    NCE_S32 f       = 0;
    NCE_S32 len     = strlen(img_path);
    NCE_S32 width   = input_img.image_attr.u32Width;
    NCE_S32 height  = input_img.image_attr.u32Height;
    NCE_S32 channel = input_img.image_attr.u32channel;

    if (img_path[len - 2] == 'j' && img_path[len - 1] == 'p' && img_path[len] == 'g')
        f = 0;
    if (img_path[len - 2] == 'p' && img_path[len - 1] == 'n' && img_path[len] == 'g')
        f = 1;
    if (img_path[len - 2] == 't' && img_path[len - 1] == 'g' && img_path[len] == 'a')
        f = 2;
    if (img_path[len - 2] == 'b' && img_path[len - 1] == 'm' && img_path[len] == 'p')
        f = 3;

    switch (f)
    {
        case 0:
            sprintf(buff, "%s", img_path);
            success = stbi_write_jpg(buff, width, height, channel, input_img.image, 80);
            break;
        case 1:
            sprintf(buff, "%s", img_path);
            success = stbi_write_png(buff, width, height, channel, input_img.image, width * channel);
            break;
        case 2:
            sprintf(buff, "%s", img_path);
            success = stbi_write_tga(buff, width, height, channel, input_img.image);
            break;
        case 3:
            sprintf(buff, "%s", img_path);
            success = stbi_write_bmp(buff, width, height, channel, input_img.image);
            break;
        default:
            return NCE_FAILED;
    }

    if (!success)
    {
        fprintf(stderr, "Failed to write image %s\n", buff);
        return NCE_FAILED;
    }

    return NCE_SUCCESS;
}

NCE_S32 nce_free_img(img_t &input_img)
{

    if (nullptr != input_img.image)
    {
        free(input_img.image);
        input_img.image = nullptr;
        return NCE_SUCCESS;
    }
    printf("cannot be delete twice");
    return NCE_FAILED;
}

NCE_S32 nce_draw_bbox(img_t &input_img, Bbox box, NCE_S32 line_width, NCE_S32 color[3])
{
    /*color: rgb order*/
    NCE_S32 i;

    NCE_S32 x1 = box.x1 - line_width / 2;
    NCE_S32 y1 = box.y1 - line_width / 2;
    NCE_S32 x2 = box.x2 + line_width / 2;
    NCE_S32 y2 = box.y2 + line_width / 2;

    for (i = 0; i < line_width; ++i)
    {
        x1 += i;
        y1 += i;
        x2 -= i;
        y2 -= i;
        if (x1 < 0)
            x1 = 0;
        if (x1 >= input_img.image_attr.u32Width)
            x1 = input_img.image_attr.u32Width - 1;
        if (x2 < 0)
            x2 = 0;
        if (x2 >= input_img.image_attr.u32Width)
            x2 = input_img.image_attr.u32Width - 1;

        if (y1 < 0)
            y1 = 0;
        if (y1 >= input_img.image_attr.u32Height)
            y1 = input_img.image_attr.u32Height - 1;
        if (y2 < 0)
            y2 = 0;
        if (y2 >= input_img.image_attr.u32Height)
            y2 = input_img.image_attr.u32Height - 1;

        for (i = x1; i <= x2; ++i)
        {
            input_img.image[(i + y1 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 0] = color[0];
            input_img.image[(i + y2 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 0] = color[0];

            input_img.image[(i + y1 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 1] = color[1];
            input_img.image[(i + y2 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 1] = color[1];

            input_img.image[(i + y1 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 2] = color[2];
            input_img.image[(i + y2 * input_img.image_attr.u32Width) * input_img.image_attr.u32channel + 2] = color[2];
        }
        for (i = y1; i <= y2; ++i)
        {
            input_img.image[(i * input_img.image_attr.u32Width + x1) * input_img.image_attr.u32channel + 0] = color[0];
            input_img.image[(i * input_img.image_attr.u32Width + x2) * input_img.image_attr.u32channel + 0] = color[0];

            input_img.image[(i * input_img.image_attr.u32Width + x1) * input_img.image_attr.u32channel + 1] = color[1];
            input_img.image[(i * input_img.image_attr.u32Width + x2) * input_img.image_attr.u32channel + 1] = color[1];

            input_img.image[(i * input_img.image_attr.u32Width + x1) * input_img.image_attr.u32channel + 2] = color[2];
            input_img.image[(i * input_img.image_attr.u32Width + x2) * input_img.image_attr.u32channel + 2] = color[2];
        }
    }

    return NCE_SUCCESS;
}

NCE_S32 nce_trans(img_t &input_img, ImageProcessParam param)
{
    return NCE_SUCCESS;
}

nce_planner2package::nce_planner2package(ImageProcessParam param)
{
    NCE_S32 width   = param.Info.planner2package_info.width;
    NCE_S32 height  = param.Info.planner2package_info.height;
    NCE_S32 channel = param.Info.planner2package_info.channel;
    tmp_buffer      = new NCE_U8[width * height * channel];
}

nce_planner2package::~nce_planner2package()
{
    if (nullptr != tmp_buffer)
    {
        delete[] tmp_buffer;
        tmp_buffer = nullptr;
    }
    else
        printf("tmp_buffer cannot be delete twice!\n");
}

NCE_S32 nce_planner2package::forward(img_t &input_img, img_t &output_img)
{
    NCE_S32 width    = input_img.image_attr.u32Width;
    NCE_S32 height   = input_img.image_attr.u32Height;
    NCE_S32 channel  = input_img.image_attr.u32channel;
    NCE_U32 img_size = width * height;
    NCE_U8 *image    = input_img.image;
    assert(output_img.image != nullptr);
    for (NCE_U32 c = 0; c < channel; c++)
    {
        for (NCE_U32 h = 0; h < height; h++)
        {
            for (NCE_U32 w = 0; w < width; w++)
            {
                tmp_buffer[(h * width + w) * channel + c] = image[c * img_size + h * width + w];
            }
        }
    }

    memcpy(output_img.image, tmp_buffer, img_size * channel);
    if (input_img.image != output_img.image)
        memcpy(&output_img.image_attr, &input_img.image_attr, sizeof(img_info));
    input_img.image_attr.format = PACKAGE;
    return NCE_SUCCESS;
}

nce_package2planner::nce_package2planner(ImageProcessParam param)
{
    NCE_S32 width   = param.Info.planner2package_info.width;
    NCE_S32 height  = param.Info.planner2package_info.height;
    NCE_S32 channel = param.Info.planner2package_info.channel;
    tmp_buffer      = new NCE_U8[width * height * channel];
}

nce_package2planner::~nce_package2planner()
{
    if (nullptr != tmp_buffer)
    {
        delete[] tmp_buffer;
        tmp_buffer = nullptr;
    }
    else
        printf("tmp_buffer cannot be delete twice!\n");
}

NCE_S32 nce_package2planner::forward(img_t &input_img, img_t &output_img)
{
    NCE_S32 width    = input_img.image_attr.u32Width;
    NCE_S32 height   = input_img.image_attr.u32Height;
    NCE_S32 channel  = input_img.image_attr.u32channel;
    NCE_U32 img_size = width * height;
    NCE_U8 *image    = input_img.image;
    assert(output_img.image != nullptr);
    for (NCE_U32 c = 0; c < channel; c++)
    {
        for (NCE_U32 h = 0; h < height; h++)
        {
            for (NCE_U32 w = 0; w < width; w++)
            {
                tmp_buffer[c * img_size + h * width + w] = image[(h * width + w) * channel + c];
            }
        }
    }
    memcpy(output_img.image, tmp_buffer, img_size * channel);
    if (input_img.image != output_img.image)
        memcpy(&output_img.image_attr, &input_img.image_attr, sizeof(img_info));
    output_img.image_attr.format = PLANNER;
    return NCE_SUCCESS;
}

nce_normalization::nce_normalization(ImageProcessParam param)
{
    memcpy(mean, param.Info.normal_info.mean, sizeof(mean));
    memcpy(var, param.Info.normal_info.var, sizeof(var));
}

NCE_S32 nce_normalization::forward(img_t &input_img, img_t &output_img)
{
    NCE_U8 *image   = input_img.image;
    NCE_S32 width   = input_img.image_attr.u32Width;
    NCE_S32 height  = input_img.image_attr.u32Height;
    NCE_S32 channel = input_img.image_attr.u32channel;
    assert(output_img.image != nullptr);
    for (NCE_U32 c = 0; c < channel; c++)
    {
        for (NCE_U32 h = 0; h < height; h++)
        {
            for (NCE_U32 w = 0; w < width; w++)
            {
                output_img.image[h * channel * width + width * channel + c] =
                    (image[h * channel * width + width * channel + c] - mean[c]) / var[c];
            }
        }
    }
    if (input_img.image != output_img.image)
        memcpy(&output_img.image_attr, &input_img.image_attr, sizeof(img_info));
    return NCE_SUCCESS;
}

nce_resize::nce_resize(ImageProcessParam param)
{
    NCE_U32 width   = param.Info.resize_info.dst_width;
    NCE_U32 height  = param.Info.resize_info.dst_height;
    NCE_U32 channel = param.Info.resize_info.dst_channel;

    tmp_img.image_attr.u32Width   = width;
    tmp_img.image_attr.u32Height  = height;
    tmp_img.image_attr.u32channel = channel;
    tmp_img.image                 = (NCE_U8 *)STBI_MALLOC(width * height * channel);
}

nce_resize::~nce_resize()
{
    nce_free_img(tmp_img);
}

NCE_S32 nce_resize::forward(img_t &input_img, img_t &output_img)
{
    NCE_F32 src_width   = (NCE_F32)input_img.image_attr.u32Width;
    NCE_F32 src_height  = (NCE_F32)input_img.image_attr.u32Height;
    NCE_U32 src_channel = (NCE_U32)input_img.image_attr.u32channel;

    NCE_F32 dst_width   = (NCE_F32)tmp_img.image_attr.u32Width;
    NCE_F32 dst_height  = (NCE_F32)tmp_img.image_attr.u32Height;
    NCE_U32 dst_channel = (NCE_U32)tmp_img.image_attr.u32channel;
    NCE_U8 *dst_img     = output_img.image;
    assert(src_channel == dst_channel);
    assert(output_img.image != nullptr);
    // if src == dst
    if (input_img.image == output_img.image)
        dst_img = tmp_img.image;
    NCE_F32 factor_x = src_width / dst_width;
    NCE_F32 factor_y = src_height / dst_height;
    for (NCE_U32 h = 0; h < dst_height; h++)
    {
        for (NCE_U32 w = 0; w < dst_width; w++)
        {
            NCE_F32 src_x    = (w + 1) * factor_x - 1;
            NCE_F32 src_y    = (h + 1) * factor_y - 1;

            NCE_U32 src_x_lt = (NCE_U32)std::min(src_x, src_width - 2);
            NCE_U32 src_y_lt = (NCE_U32)std::min(src_y, src_height - 2);

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


                dst_img[dst_index] =
                    input_img.image[src_index_lt] * factor_lt + input_img.image[src_index_lb] * factor_lb
                    + input_img.image[src_index_rt] * factor_rt + input_img.image[src_index_rb] * factor_rb;
            }
        }
    }
 
    // if src == dst realloc src and memcpy from tmp data
    if (input_img.image == output_img.image)
    {
        input_img.image = (NCE_U8 *)STBI_REALLOC((void *)input_img.image,
                                                 tmp_img.image_attr.u32Width * tmp_img.image_attr.u32Height
                                                     * tmp_img.image_attr.u32channel);
        if (input_img.image != NULL)
            memcpy(input_img.image,
                   tmp_img.image,
                   tmp_img.image_attr.u32Width * tmp_img.image_attr.u32Height * tmp_img.image_attr.u32channel);

    }
    tmp_img.image_attr.format = input_img.image_attr.format; 
    tmp_img.image_attr.order = input_img.image_attr.order;

    memcpy(&output_img.image_attr, &tmp_img.image_attr, sizeof(img_info));


    return NCE_SUCCESS;
}
