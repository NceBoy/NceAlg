#ifndef __ENGINE_MANAGER_HPP__
#define __ENGINE_MANAGER_HPP__
#include<iostream>
#include<map>
#include<memory>
#include "alg_type.h"
#include<IEngine.hpp>

#define __strcat_engine_cls(arg) arg##_engine
#define strcat_engine_cls(arg) __strcat_engine_cls(arg)




#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

using namespace std;
namespace nce_alg
{
    NCE_S32 engine_manager(shared_ptr<IEngine> & engine_ptr);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
#endif