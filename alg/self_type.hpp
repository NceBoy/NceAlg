#ifndef __SELF_TYPE_H__
#define __SELF_TYPE_H__
#include "alg_type.h"
namespace nce_alg
{
    typedef enum Tagfeattype
    {
        FEAT_S32,
        FEAT_F32,
        FEAT_MAX,
    }feattype;

    typedef struct output_tensor
    {
        NCE_S32  u32Stride;
        NCE_S32  u32FeatWidth;
        NCE_S32  u32FeatHeight;
        NCE_S32  u32ch;
        NCE_S8   fl;                                          /* fractional length . */
        NCE_S32  zp;                                        /* zero point. */
        NCE_F32  scale;                                        /* scale  */
        image_format outfmt;                             /* the data format of tensor. */
        char     name[8];
    }output_tensor;

    typedef struct tmp_map_result
    {
        NCE_S32  feat_type;  
        NCE_S32* pu32Feat;
        output_tensor tensor;
    }tmp_map_result;
}
#endif 
