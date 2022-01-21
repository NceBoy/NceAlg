#include module for include_dir and link_dir and lib_name
include(module_yaml)
#include(XXX)



#for target link
set(THIRD_PARTY_LIB
  ${YAML_LIB}
)

set(THIRD_PARTY_NEED
  build-yaml
#build-xxx
)