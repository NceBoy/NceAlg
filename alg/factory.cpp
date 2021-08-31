/*
 * @Descripttion: 
 * @version: 
 * @Author: Haochen Ye
 * @Date: 2021-08-20 10:32:17
 * @LastEditors: Haochen Ye
 * @LastEditTime: 2021-08-31 14:43:00
 */
#include "factory.hpp"
#include "stdio.h"




using namespace std;
namespace nce_alg
{    

    bool NceFactory::RegistAlg(const char * name, CreateAlgFunction func)
    {
        if (!func)
        {
            return false;
        }
        return _create_alg_function_map.insert(std::make_pair(name, func)).second;
    }

    bool NceFactory::RegistEngine(const char * name, CreateEngineFunction func)
    {
        if (!func)
        {
            return false;
        }
        return _create_engine_function_map.insert(std::make_pair(name, func)).second;
    }

    shared_ptr<IAlg> NceFactory::CreateAlg(int alg_type)
    {
        /*控制元素下标范围，防止越界*/
        if (alg_type < 0 || alg_type >= MAX_CLS)
        {
            return NULL;
        }

        std::map<std::string, CreateAlgFunction>::iterator it = _create_alg_function_map.find(_enumstr_alg_map[alg_type]);
        if (it == _create_alg_function_map.end())
        {
	        printf("no match alg!\n");
            return NULL;
        }
        return it->second();
    }

    shared_ptr<IEngine> NceFactory :: CreateEngine(int platform_type)
    {
        /*控制元素下标范围，防止越界*/
        if (platform_type < 0 || platform_type >= MAX_PLATFORM)
        {
            return NULL;
        }

        std::map<std::string, CreateEngineFunction>::iterator it = _create_engine_function_map.find(_enumstr_engine_map[platform_type]);
        if (it == _create_engine_function_map.end())
        {
            printf("no match engine!\n");
            return NULL;
        }
        return it->second();
    }
}
