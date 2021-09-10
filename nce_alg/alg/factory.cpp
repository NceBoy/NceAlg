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
namespace nce_alg {

bool NceFactory::RegistAlg(NCE_S32 alg_type, CreateAlgFunction func)
{
    if (!func)
    {
        return false;
    }
    return _create_alg_function_map.insert(std::make_pair(alg_type, func)).second;
}

bool NceFactory::RegistEngine(NCE_S32 engine_type, CreateEngineFunction func)
{
    if (!func)
    {
        return false;
    }
    return _create_engine_function_map.insert(std::make_pair(engine_type, func)).second;
}

shared_ptr<IAlg> NceFactory::CreateAlg(int alg_type)
{
    if (alg_type < 0 || alg_type >= MAX_CLS)
    {
        return NULL;
    }

    auto it = _create_alg_function_map.find(alg_type);
    if (it == _create_alg_function_map.end())
    {
        printf("no match alg!\n");
        return NULL;
    }
    return it->second();
}

shared_ptr<IEngine> NceFactory ::CreateEngine(int platform_type)
{
    if (platform_type < 0 || platform_type >= MAX_PLATFORM)
    {
        return NULL;
    }

    auto it = _create_engine_function_map.find(platform_type);
    if (it == _create_engine_function_map.end())
    {
        printf("no match engine!\n");
        return NULL;
    }
    return it->second();
}
} // namespace nce_alg
