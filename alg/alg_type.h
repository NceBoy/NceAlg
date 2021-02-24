#ifndef __ALG_TYPE_H__
#define __ALG_TYPE_H__

#define NCE_SUCCESS   0
#define NCE_FAILED   -1

typedef int                     NCE_S32;
typedef short                   NCE_S16;
typedef unsigned char           NCE_U8;
typedef float                   NCE_F32;
typedef void*                   NCE_PTR;
typedef unsigned long long      NCE_U64;
typedef unsigned int            NCE_U32;
typedef int                     NCE_BOOL;


typedef enum
{
    HISI,
    RK,
    HOST,
}platform;

typedef enum
{
    PERSON_HEAD, //对应的结构体是person_head
    PERSON_FACE,
    FACE_FAKE,
    MAX_CLS,
}taskcls;

typedef enum
{
    PACKAGE,
    PLANNER,
    YUV
}image_format;

typedef struct person_head
{
    NCE_BOOL      fake;
    NCE_S32   angle[3]; //角度的三个顺序
}person_head;

typedef struct alg_result
{
    NCE_U32 x1;
    NCE_U32 y1;
    NCE_U32 x2;
    NCE_U32 y2;
    NCE_F32 score;
    
    taskcls type;
    NCE_PTR  obj;

}alg_result;

typedef struct alg_result_info
{
    NCE_S16    num;
    NCE_PTR    st_alg_results;
}alg_result_info;

typedef struct engine_param_info
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
            char* pc_device_name;

        }st_openvino_param;
        /* data */
    }st_engine_info;

	char*       pc_model_path;
	platform    engine_type;

}engine_param_info;


typedef struct task_config_info
{

    union cfg
    {

        struct fd_config //face
        {

            
        } fd_config;
        
        struct hd_config //head
        {
			NCE_F32 nms_thresh;
        } hd_config;

        struct fr_config //face recog
        {

        } fr_config;
        /* data */

        struct fk_config //face
        {

            
        } fk_config;


    }st_cfg;

	NCE_F32   threshold;
	NCE_BOOL  isLog;
    /* data */
}task_config_info;

typedef struct img_info
{
    NCE_U8*       image; /* RW;The physical address of the image */ 
	//NCE_U64       PhyAddr[3]; /* RW;The virtual address of the image */
	//NCE_U32       au32Stride[3];  /* RW;The stride of the image */
	NCE_U32       u32Width;       /* RW;The width of the image */    
	NCE_U32       u32Height;      /* RW;The height of the image */
	NCE_U32       u32channel;      /* RW;The height of the image */
    image_format  format; /* RW;The type of the image */
}img_info;

#endif
