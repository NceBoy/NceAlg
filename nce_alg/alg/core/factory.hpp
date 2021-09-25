#ifndef _NCE_FACTORY_
#define _NCE_FACTORY_
#include <memory>
#include <unordered_map>
using namespace std;
template <typename base>
class NceFactory
{
public:
    typedef shared_ptr<base> (*CreateFunction)();
    static NceFactory *GetInstance()
    {
        if (nullptr == fac_)
        {
            fac_ = new NceFactory;
        }
        return fac_;
    }

    bool Regist(NCE_S32 type, CreateFunction func)
    {
        auto _create_function_map = GetReigistMap();
        if (!func)
        {
            return false;
        }
        (*_create_function_map)[type] = func;
        return true;
    }

    shared_ptr<base> CreateObject(int alg_type)
    {

        if (alg_type < 0 || alg_type >= 10)
        {
            return NULL;
        }
        auto _create_function_map = GetReigistMap();
        auto it                   = _create_function_map->find(alg_type);
        if (it == _create_function_map->end())
        {
            printf("no match alg!\n");
            return NULL;
        }
        printf("match alg!\n");
        return it->second();
    }

    static unordered_map<NCE_S32, CreateFunction> *GetReigistMap()
    {
        static unordered_map<NCE_S32, CreateFunction> *_create_function_map =
            new unordered_map<NCE_S32, CreateFunction>;
        return _create_function_map;
    }

private:
    NceFactory()
    {}
    static NceFactory<base> *fac_;
};

template <typename base>
NceFactory<base> *NceFactory<base>::fac_;

template <typename child, typename base, NCE_S32 type>
class NceCreator
{
public:
    static shared_ptr<base> ClassCreator()
    {
        return shared_ptr<base>((base *)(new child));
    }
    struct Registor
    {
        Registor()
        {
            NceFactory<base>::GetInstance()->Regist(type, ClassCreator);
        }

        void inline do_nothing(){};
    };

    virtual ~NceCreator()
    {
        cls_registor.do_nothing();
    };

    static Registor cls_registor;
};

template <typename child, typename base, NCE_S32 type>
typename NceCreator<child, base, type>::Registor NceCreator<child, base, type>::cls_registor;

#endif