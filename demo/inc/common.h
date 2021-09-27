#ifndef _COMMON_H_
#define _COMMON_H_
#include "alg_type.h"

NCE_S32 NCE_PUBLIC nce_read_img(const char *img_path, img_t &input_img);

NCE_S32 NCE_PUBLIC nce_write_img(const char *img_path, img_t &input_img);

NCE_S32 NCE_PUBLIC nce_free_img(img_t &input_img);

NCE_S32 NCE_PUBLIC nce_draw_bbox(img_t &input_img, Bbox box, NCE_S32 line_width, NCE_S32 color[3]);

NCE_S32 NCE_PUBLIC nce_trans(img_t &input_img, ImageProcessParam param);

class nce_base_process
{
public:
    NCE_PUBLIC nce_base_process()
    {}
    // nce_base_process* create_instance(ImageProcessParam param){ return nullptr;}
    NCE_S32 NCE_PUBLIC virtual forward(img_t &input_img,img_t &output_img)
    {
        return NCE_FAILED;
    }

    virtual ~nce_base_process()
    {
        
    }
};

template <class P>
nce_base_process *create_aainstance(ImageProcessParam param)
{
    P *parent_ptr;
    parent_ptr = new P(param);
    return (nce_base_process *)parent_ptr;
}

class nce_planner2package : public nce_base_process
{
public:
    NCE_PUBLIC nce_planner2package(ImageProcessParam param);
    NCE_PUBLIC ~nce_planner2package();
    static nce_base_process NCE_PUBLIC *create_instance(ImageProcessParam param)
    {
        nce_planner2package *parent_ptr;
        parent_ptr = new nce_planner2package(param);
        return (nce_base_process *)parent_ptr;
    }
    NCE_S32 NCE_PUBLIC forward(img_t &input_img,img_t &output_img);

private:
    NCE_U8 *tmp_buffer;
};

class nce_package2planner : public nce_base_process
{
public:
    NCE_PUBLIC nce_package2planner(ImageProcessParam param);
    static nce_base_process NCE_PUBLIC *create_instance(ImageProcessParam param)
    {
        nce_package2planner *parent_ptr;
        parent_ptr = new nce_package2planner(param);
        return (nce_base_process *)parent_ptr;
    }
    NCE_S32 NCE_PUBLIC forward(img_t &input_img,img_t &output_img);
    NCE_PUBLIC  ~nce_package2planner();

private:
    NCE_U8 *tmp_buffer;
};

class nce_gray2bgr : public nce_base_process
{
public:
    NCE_PUBLIC nce_gray2bgr(ImageProcessParam param);
    NCE_S32 NCE_PUBLIC forward(img_t &input_img,img_t &output_img);
};
class nce_normalization : public nce_base_process
{
public:
    NCE_PUBLIC nce_normalization(ImageProcessParam param);
    static nce_base_process NCE_PUBLIC *create_instance(ImageProcessParam param)
    {
        nce_normalization *parent_ptr;
        parent_ptr = new nce_normalization(param);
        return (nce_base_process *)parent_ptr;
    }
    NCE_S32 NCE_PUBLIC forward(img_t &input_img,img_t &output_img);

private:
    NCE_F32 mean[3];
    NCE_F32 var[3];
};



class nce_resize : public nce_base_process
{
public:
    NCE_PUBLIC nce_resize(ImageProcessParam param);
    static nce_base_process NCE_PUBLIC *create_instance(ImageProcessParam param)
    {
        nce_resize *parent_ptr;
        parent_ptr = new nce_resize(param);
        return (nce_base_process *)parent_ptr;
    }
    NCE_S32 NCE_PUBLIC forward(img_t &input_img,img_t &output_img);
    NCE_PUBLIC  ~nce_resize();

private:
    img_t tmp_img;
};

#endif