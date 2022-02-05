/*
 * @Descripttion:
 * @version:
 * @Author: Haochen Ye
 * @Date: 2021-08-24 20:12:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2022-01-24 11:37:52
 */
#include <iostream>
#include <string>
#include <vector>
#include "3ddfa/tddfa.hpp"
#include <memory>
#include "IEngine.hpp"
#include <string.h>
#include <algorithm>
#include <cmath>
#include "util/util.hpp"

using namespace std;
namespace nce_alg {

tddfa_priv::tddfa_priv()
    : param_mean(nullptr), 
        param_std(nullptr), 
        w_exp_base(nullptr), 
        w_shp_base(nullptr), 
        u_base(nullptr)
{
    landmark_result.dims = 68;
    landmark_result.points = new point[68];
}

tddfa_priv::~tddfa_priv()
{
    delete param_mean;
    delete param_std;
    delete w_exp_base;
    delete w_shp_base;
    delete u_base;
    delete landmark_result.points;
}

NCE_S32 tddfa_priv::read_face_model(string file_path, NCE_F32 **buffer)
{
    FILE *fp = NULL;
    char *_buffer;
    fp = fopen(file_path.c_str(), "rb"); 
    if (NULL == fp)
    {
        return (-1);
    }

    fseek(fp, 0, SEEK_END);
    long f_length = ftell(fp);
    _buffer       = new char[f_length];
    fseek(fp, 0, SEEK_SET);
    fread(_buffer, 1, f_length, fp); // 二进制读
    *buffer = (NCE_F32 *)_buffer;

    fclose(fp);
    return 0;
}

NCE_S32 tddfa::alg_init(vector<input_tensor_info> &            st_tensor_infos,
                        LinkedHashMap<string, tmp_map_result> &st_result_map,
                        YAML::Node &                           config)
{
    NCE_S32 ret = NCE_FAILED;
    pPriv       = shared_ptr<tddfa_priv>(new tddfa_priv());
    int i       = 0;

    const auto names = config["output_names"];
    for (auto &iter : names)
    {
        st_result_map.insert(make_pair(iter.as<string>(), tmp_map_result{ 0 }));
    }

    input_tensor_info input0{ 0 };
    input0.order     = RGB;
    const auto mean0 = config["mean0"];
    const auto std0  = config["std0"];

    for (i = 0; i < 3; i++)
    {
        input0.mean[i] = mean0[i].as<float>();
        input0.std[i]  = std0[i].as<float>();
    }
    st_tensor_infos.push_back(input0);

    pPriv->input_tensor_infos = &st_tensor_infos;
    printf("finshed alg init\n!");

    string mean_file = config["face_mean"].as<string>().c_str();
    string std_file  = config["face_std"].as<string>().c_str();
    string exp_file  = config["face_exp"].as<string>().c_str();
    string shp_file  = config["face_shp"].as<string>().c_str();
    string base_file = config["face_base"].as<string>().c_str();

    pPriv->read_face_model(mean_file, &pPriv->param_mean);
    pPriv->read_face_model(std_file, &pPriv->param_std);
    pPriv->read_face_model(exp_file, &pPriv->w_exp_base);
    pPriv->read_face_model(shp_file, &pPriv->w_shp_base);
    pPriv->read_face_model(base_file, &pPriv->u_base);
    return ret;
}

NCE_S32 tddfa::alg_cfg_set(const task_config_info &st_task_config_info)
{
    return NCE_SUCCESS;
}
NCE_S32 tddfa::alg_inference(vector<img_t> &pc_img)
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    printf("finish alg_inference\n");
    return ret;
}

NCE_S32 tddfa::alg_get_result(alg_result_info &results, LinkedHashMap<string, tmp_map_result> &st_result_map)
{
    results.num = 0;

    NCE_S32 ret = NCE_FAILED;
    if (NULL == pPriv)
    {
        printf("Failed to init pPriv of alg");
        return NCE_FAILED;
    }

    static NCE_F32* vertices = (NCE_F32*)st_result_map["vertices"].pu32Feat;

    NCE_S32 img_width  = (*pPriv->input_tensor_infos)[0].width;
    NCE_S32 img_height = (*pPriv->input_tensor_infos)[0].height;


    for (int i = 0; i < 62; i++)
    {
        vertices[i] = pPriv->param_mean[i] + pPriv->param_std[i] * vertices[i];
    }


    pPriv->trans_matrix[0] = vertices[0];
    pPriv->trans_matrix[1] = vertices[1];
    pPriv->trans_matrix[2] = vertices[2];
    pPriv->trans_matrix[3] = vertices[4];
    pPriv->trans_matrix[4] = vertices[5];
    pPriv->trans_matrix[5] = vertices[6];
    pPriv->trans_matrix[6] = vertices[8];
    pPriv->trans_matrix[7] = vertices[9];
    pPriv->trans_matrix[8] = vertices[10];

    float off_set[3];

    off_set[0] = vertices[3];
    off_set[1] = vertices[7];
    off_set[2] = vertices[11];

    float alpha_shp[40];
    for (int i = 12; i < 52; i++)
    {
        alpha_shp[i - 12] = vertices[i];
    }

    float alpha_exp[10];

    for (int i = 52; i < 62; i++)
    {
        alpha_exp[i - 52] = vertices[i];
    }
    memset(pPriv->kpt, 0, sizeof(float) * 204);
    for (int i = 0; i < 204; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            int start = i * 40;
            pPriv->kpt[i] += pPriv->w_shp_base[start + j] * alpha_shp[j];
        }

        for (int j = 0; j < 10; j++)
        {
            int start = i * 10;
            pPriv->kpt[i] += pPriv->w_exp_base[start + j] * alpha_exp[j];
        }

        pPriv->kpt[i] += pPriv->u_base[i];
    }

    for (int i = 0; i < 68; i++)
    {
        NCE_F32 x = pPriv->kpt[3 * i + 0];
        NCE_F32 y = pPriv->kpt[3 * i + 1];
        NCE_F32 z = pPriv->kpt[3 * i + 2];

        pPriv->kpt[3 * i + 0] = pPriv->trans_matrix[0] * x + pPriv->trans_matrix[1] * y + pPriv->trans_matrix[2] * z + off_set[0];
        pPriv->kpt[3 * i + 1] = pPriv->trans_matrix[3] * x + pPriv->trans_matrix[4] * y + pPriv->trans_matrix[5] * z + off_set[1];
        pPriv->kpt[3 * i + 1] = 120 - pPriv->kpt[3 * i + 1];
        pPriv->kpt[3 * i + 2] = pPriv->trans_matrix[6] * x + pPriv->trans_matrix[7] * y + pPriv->trans_matrix[8] * z + off_set[2];

        (pPriv->landmark_result.points + i)->x = pPriv->kpt[3*i + 0];
        (pPriv->landmark_result.points + i)->y = pPriv->kpt[3*i + 1];
        (pPriv->landmark_result.points + i)->z = pPriv->kpt[3*i + 2];
    }
    pPriv->tmp_result.obj = (NCE_PTR*)(&pPriv->landmark_result);
    pPriv->tmp_result.type = THREE_DDFA;

    results.num = 1;
    results.st_alg_results = &pPriv->tmp_result;
    return ret;
}
NCE_S32 tddfa::alg_destroy()
{
    NCE_S32 ret = NCE_FAILED;
    ret         = NCE_SUCCESS;
    return ret;
}

} // namespace nce_alg
