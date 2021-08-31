#ifndef _COMMON_H_
#define _COMMON_H_
#include "alg_type.h"

//#ifdef __cplusplus
//#if __cplusplus
//extern "C"{
//#endif
//#endif /* __cplusplus */

typedef enum TagImageProcessType 
{
    PROC_PACKAGE2PLANNER,
    PROC_PLANNER2PACKAGE,
    PROC_RESIZE,
    PROC_NORMALIZATION,
    PROC_TRANS,
    PROC_GRAY2BGR,
    PROC_MAX
}ImageProcessType;

typedef struct TagImageProcessParam
{
    ImageProcessType type;
    union ParamInfo
    {
        struct FuncResizeInfo
        {
            NCE_U32 dst_width;
            NCE_U32 dst_height;
            NCE_U32 dst_channel;
        }resize_info;

        struct FuncNormalInfo
        {
            NCE_F32 mean[3];
            NCE_F32 var[3];
        }normal_info;

        struct FuncTransInfo
        {
            /* data */
        }trans_info;

        struct FuncPlanner2PackageInfo
        {
            NCE_S32 width;
            NCE_S32 height;
            NCE_S32 channel;
        }planner2package_info;

        struct FuncPackage2PlannerInfo
        {
            NCE_S32 width;
            NCE_S32 height;
            NCE_S32 channel;
        }package2planner_info;
 
    }Info;

}ImageProcessParam;

typedef struct TagBoundingBbox
{
    NCE_S32 x1;
    NCE_S32 y1;
    NCE_S32 x2;
    NCE_S32 y2;
    NCE_F32 score; 
}Bbox;



NCE_S32 nce_read_img(const char* img_path, img_t & input_img);

NCE_S32 nce_write_img(const char* img_path, img_t & input_img);

NCE_S32 nce_free_img(img_t & input_img);

NCE_S32 nce_draw_bbox(img_t & input_img, Bbox box, NCE_S32 line_width, NCE_S32 color[3]);

NCE_S32 nce_trans(img_t & input_img, ImageProcessParam param);


class nce_base_process
{
public:
    nce_base_process() {}
    //nce_base_process* create_instance(ImageProcessParam param){ return nullptr;}
    NCE_S32 forward(img_t& input_img) { return NCE_FAILED; }
};


template<class P>
nce_base_process* create_instance(ImageProcessParam param)
{
    P* parent_ptr;
    parent_ptr = new P(param);
    return (nce_base_process*)parent_ptr;
}

class nce_planner2package :public nce_base_process
{
public:
    nce_planner2package(ImageProcessParam param);
    ~nce_planner2package();
    NCE_S32 forward(img_t& input_img);
private:
    NCE_U8* tmp_buffer;
};

class nce_package2planner: public nce_base_process
{
public:
    nce_package2planner(ImageProcessParam param);
    NCE_S32 forward(img_t& input_img);
    ~nce_package2planner();
private:
    NCE_U8* tmp_buffer;
};

class nce_gray2bgr: public nce_base_process
{
public:
    nce_gray2bgr(ImageProcessParam param);
    NCE_S32 forward(img_t& input_img);

};
class nce_normalization: public nce_base_process
{
public:
    nce_normalization(ImageProcessParam param);
    NCE_S32 forward(img_t& input_img);
private:
    NCE_F32 mean[3];
    NCE_F32 var[3];
};

class hhhh : public nce_base_process
{
public:
    hhhh(ImageProcessParam param);
    NCE_S32 forward(img_t& input_img);
    ~hhhh();
private:
    img_t output_img;
};

class nce_resize: public nce_base_process
{
public:
    nce_resize(ImageProcessParam param);
    NCE_S32 forward(img_t& input_img);
    ~nce_resize();
private:
    img_t output_img;
};
//#ifdef __cplusplus
//#if __cplusplus
//}
//#endif
//#endif /* __cplusplus */
#endif