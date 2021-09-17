#ifndef _NCE_FACTORY_
#define _NCE_FACTORY_
#include "alg_type.h"
#include "IAlg.hpp"
#include "IEngine.hpp"
#include <memory>
#include <unordered_map>

#ifndef __GNUC__
#define NCE_CLASS_NAME(sour) typeid(sour).name()
#else
#include <cxxabi.h>
#define NCE_CLASS_NAME(sour) abi::__cxa_demangle(typeid(sour).name(), nullptr, nullptr, nullptr)
#endif
using namespace std;

namespace nce_alg {

class NceFactory
{
public:
    typedef shared_ptr<IAlg> (*CreateAlgFunction)();
    typedef shared_ptr<IEngine> (*CreateEngineFunction)();

    unordered_map<NCE_S32, CreateAlgFunction> _create_alg_function_map;
    unordered_map<NCE_S32, CreateEngineFunction> _create_engine_function_map;

    static NceFactory &Instance()
    {
        static NceFactory fac;
        return fac;
    }

    bool RegistAlg(NCE_S32 alg_type, CreateAlgFunction func);

    bool RegistEngine(NCE_S32 engine_type, CreateEngineFunction func);

    shared_ptr<IAlg> CreateAlg(int alg_type /*const std::string & alg_name*/);

    shared_ptr<IEngine> CreateEngine(int platform_type);
};

template <typename T, NCE_S32 alg_type>
class NceAlgCreator
{
public:
    static shared_ptr<IAlg> CreateAlgObject()
    {
        return (shared_ptr<IAlg>)shared_ptr<T>(new T);
    }

    struct Registor
    {
        Registor()
        {
            if (!NceFactory::Instance().RegistAlg(alg_type, CreateAlgObject)) {}
        }

        inline void do_nothing() const
        {}
    };

    static Registor alg_registor;

public:
    NceAlgCreator()
    {
        alg_registor.do_nothing();
    }

    virtual ~NceAlgCreator()
    {
        alg_registor.do_nothing();
    }
};

template <typename T, NCE_S32 engine_type>
class NceEngineCreator
{
public:
    static shared_ptr<IEngine> CreateEngineObject()
    {
        return (shared_ptr<IEngine>)shared_ptr<T>(new T);
    }

    struct Registor
    {
        Registor()
        {
            if (!NceFactory::Instance().RegistEngine(engine_type, CreateEngineObject)) {}
        }

        inline void do_nothing() const
        {}
    };

    static Registor engine_registor;

public:
    NceEngineCreator()
    {
        engine_registor.do_nothing();
    }

    virtual ~NceEngineCreator()
    {
        engine_registor.do_nothing();
    }
};

template <typename T, NCE_S32 alg_type>
typename NceAlgCreator<T, alg_type>::Registor NceAlgCreator<T, alg_type>::alg_registor;

template <typename T, NCE_S32 engine_type>
typename NceEngineCreator<T, engine_type>::Registor NceEngineCreator<T, engine_type>::engine_registor;
} // namespace nce_alg
#endif
