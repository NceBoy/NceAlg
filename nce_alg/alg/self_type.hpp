/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-09-06 15:58:08
 */
#ifndef __SELF_TYPE_H__
#define __SELF_TYPE_H__
#include "alg_type.h"
namespace nce_alg {
typedef enum Tagfeattype
{
    FEAT_S32,
    FEAT_F32,
    FEAT_MAX,
} feattype;

typedef struct tag_input_tensor_info
{
    NCE_S32      width;
    NCE_S32      height;
    NCE_S32      channel;
    image_order  order;
    image_format format;
    NCE_S32      std[3];
    NCE_S32      mean[3];
    std::string  name;
} input_tensor_info;
typedef struct output_tensor
{
    NCE_S32      u32Stride;
    NCE_S32      u32FeatWidth;
    NCE_S32      u32FeatHeight;
    NCE_S32      u32ch;
    NCE_S8       fl;     /* fractional length . */
    NCE_S32      zp;     /* zero point. */
    NCE_F32      scale;  /* scale  */
    image_format outfmt; /* the data format of tensor. */
    std::string  name;

} output_tensor;

typedef struct tmp_map_result
{
    NCE_S32       feat_type;
    NCE_S32 *     pu32Feat;
    output_tensor tensor;
} tmp_map_result;
} // namespace nce_alg
#endif