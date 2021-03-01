#include "engine_manager.hpp"
#include "engine_hisi_3559av100.hpp"
#include "engine_hisi_3516dv300.hpp"
#include "openvino_backend.hpp"
#include "host_engine.hpp"

using namespace std;
namespace nce_alg

{
    NCE_S32 engine_manager(shared_ptr<IEngine> & engine_ptr)
    {
        engine_ptr = shared_ptr<strcat_engine_cls(PLATFORM)>(new strcat_engine_cls(PLATFORM)());
        return NCE_SUCCESS;
    }
}
    
    
    
