#ifndef __ALG_TYPE_H__
#define __ALG_TYPE_H__

#define NCE_SUCCESS 0
#define NCE_FAILED -1
#define NCE_IN
#define NCE_OUT
typedef signed char        NCE_S8;
typedef int                NCE_S32;
typedef short              NCE_S16;
typedef unsigned char      NCE_U8;
typedef float              NCE_F32;
typedef void *             NCE_PTR;
typedef unsigned long long NCE_U64;
typedef unsigned int       NCE_U32;
typedef int                NCE_BOOL;
#include<string>
// TO DO: 删除
typedef enum
{
    HISI_3516DV300,
    HISI_3559AV100,
    RK_1808,
    RV_1126,
    RV_1109,
    OPENVINO,
    MNNPLATFORM,
    HOST,
    MAX_PLATFORM,
} platform;

typedef enum
{
    PERSON_HEAD, //对应的结构体是person_head
    FACE_DETECT,
    FACE_PRNET,
    FACE_RECOGNIZE,
    FACE_FAKE,
    CENTERNET,
    MAX_CLS,

} taskcls;

typedef enum
{
    PACKAGE,
    PLANNER,
    YUV
} image_format;

typedef enum
{
    RGB,
    BGR,
} image_order;

typedef enum TagImageProcessType
{
    PROC_PACKAGE2PLANNER,
    PROC_PLANNER2PACKAGE,
    PROC_RESIZE,
    PROC_NORMALIZATION,
    PROC_TRANS,
    PROC_GRAY2BGR,
    PROC_MAX
} ImageProcessType;

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
        } resize_info;

        struct FuncNormalInfo
        {
            NCE_F32 mean[3];
            NCE_F32 var[3];
        } normal_info;

        struct FuncTransInfo
        {
            /* data */
        } trans_info;

        struct FuncPlanner2PackageInfo
        {
            NCE_S32 width;
            NCE_S32 height;
            NCE_S32 channel;
        } planner2package_info;

        struct FuncPackage2PlannerInfo
        {
            NCE_S32 width;
            NCE_S32 height;
            NCE_S32 channel;
        } package2planner_info;

    } Info;

} ImageProcessParam;

typedef struct person_head
{
    NCE_F32 fake;
    NCE_S32 angle[3]; //角度的三个顺序
} person_head;

typedef struct alg_result
{
    NCE_U32 x1;
    NCE_U32 y1;
    NCE_U32 x2;
    NCE_U32 y2;
    NCE_F32 score;

    taskcls type;
    NCE_PTR obj;

} alg_result;

typedef struct alg_result_info
{
    NCE_S16 num;
    NCE_PTR st_alg_results;
} alg_result_info;

typedef struct param_info
{
    union engine_info
    {
        struct nnie_param
        {

        } st_nnie_param;

        struct ipu_param
        {

        } st_ipu_param;
        struct openvino_param
        {
            char *pc_device_name;

        } st_openvino_param;

        struct MNN_param
        {
            char *pc_device_name;

        } MNN_param;
        /* data */
    } st_engine_info;
    char *pc_model_path;
} param_info;

typedef struct task_config_info
{

    union cfg
    {

        struct fd_config // face
        {

        } fd_config;

        struct hd_config // head
        {
            NCE_F32 nms_thresh;
        } hd_config;

        struct fr_config // face recog
        {

        } fr_config;
        /* data */

        struct fk_config // face
        {

        } fk_config;

    } st_cfg;

    NCE_F32  threshold;
    NCE_BOOL isLog;
    /* data */
} task_config_info;

typedef struct img_info
{
    NCE_U32      u32Width;   /* RW;The width of the image */
    NCE_U32      u32Height;  /* RW;The height of the image */
    NCE_U32      u32channel; /* RW;The height of the image */
    image_format format;     /* RW;The type of the image */
    image_order  order;
    std::string  name;
    NCE_F32      mean[3];
    NCE_F32      std[3];

} img_info;

typedef struct img_t
{
    NCE_U8 *image; /* RW;The physical address of the image */
                   // NCE_U64       PhyAddr[3]; /* RW;The virtual address of the image */
    // NCE_U32       au32Stride[3];  /* RW;The stride of the image */
    img_info image_attr;
} img_t;

typedef struct TagBoundingBbox
{
    NCE_S32 x1;
    NCE_S32 y1;
    NCE_S32 x2;
    NCE_S32 y2;
    NCE_F32 score;
} Bbox;

#endif
