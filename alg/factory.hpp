#ifndef _NCE_FACTORY_
#define _NCE_FACTORY_
#include "alg_type.h"
#include "IAlg.hpp"
#include "IEngine.hpp"
#include <memory>
#ifndef __GNUC__
	#define NCE_CLASS_NAME(sour)   typeid(sour).name() 
#else
	#include <cxxabi.h>
	#define NCE_CLASS_NAME(sour)  abi::__cxa_demangle(typeid(sour).name(), nullptr, nullptr, nullptr)
#endif

using namespace std;
namespace nce_alg
{
    static std::map<int,std::string> _enumstr_alg_map = 
    {
        {PERSON_HEAD,"nce_alg::hd_alg"},
        {FACE_DETECT,"nce_alg::fd_alg"},
        {FACE_PRNET,"nce_alg::fp_alg"},
        {FACE_RECOGNIZE,"nce_alg::fr_alg"},
        {FACE_FAKE,"nce_alg::fc_fk_alg"},
    };
    static std::map<int,std::string> _enumstr_engine_map =
    {
        {HISI_3516DV300,"nce_alg::hisi_3516dv300_engine"},
        {HISI_3559AV100,"nce_alg::hisi_3559av100_engine"},
        {RK_1808,"nce_alg::rk_1808_engine"},
        {RV_1126,"nce_alg::rv1126_engine"},
        {RV_1109,"nce_alg::rv_1109_engine"},
        {OPENVINO,"nce_alg::openvino_engine"},
        {HOST,"nce_alg::host_engine"},
    };
// 动态对象创建工厂
    class NceFactory
    {
    public:
            typedef shared_ptr<IAlg> (*CreateAlgFunction)();
            typedef shared_ptr<IEngine> (*CreateEngineFunction)();

            std::map<std::string, CreateAlgFunction> _create_alg_function_map;
            std::map<std::string, CreateEngineFunction> _create_engine_function_map;

            static NceFactory & Instance()
            {
                static NceFactory fac;
                return fac;
            }
        
            bool RegistAlg(const char * name, CreateAlgFunction func);

            bool RegistEngine(const char * name, CreateEngineFunction func);

            shared_ptr<IAlg> CreateAlg(int alg_type/*const std::string & alg_name*/);
 
            shared_ptr<IEngine> CreateEngine(int platform_type);

    };


    // 动态对象创建器
    template<typename T>
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
                if (!NceFactory::Instance().RegistAlg(NCE_CLASS_NAME(T), CreateAlgObject))
                {
                
                }

            }
    
            inline void do_nothing()const { }
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

    // 动态对象创建器
    template<typename T>
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
                if (!NceFactory::Instance().RegistEngine(NCE_CLASS_NAME(T), CreateEngineObject))
                {
                }
            }
    
            inline void do_nothing()const { }
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
    //不理解这种写法
    template <typename T>
    typename NceAlgCreator<T>::Registor NceAlgCreator<T>::alg_registor;

    template <typename T>
    typename NceEngineCreator<T>::Registor NceEngineCreator<T>::engine_registor;
}
#endif
