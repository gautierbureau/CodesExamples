#include <iostream>
#include <dlfcn.h>
#include "/home/bureaugau/Codes/dynamo/dynawo-worktree/dynawo/sources/Modeler/Common/DYNSubModelFactory.h"
#include "/home/bureaugau/Codes/dynamo/dynawo-worktree/dynawo/sources/Modeler/Common/DYNSubModel.h"

int main() {
    using std::cout;
    using std::cerr;

    typedef DYN::SubModelFactory* getFactory_t();

    void* lib = dlopen("/home/bureaugau/Codes/dynamo/dynawo-worktree/install/gcc7/41_static_compilation_rebase/Debug/static/dynawo/ddb/LOAD_ALPHA_BETA.so", RTLD_NOW);
    if (!lib) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }

    // reset errors
    dlerror();

    // load the symbols
    getFactory_t* getFactory = (getFactory_t*) dlsym(lib, "getFactory");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }
    DYN::SubModelFactory* factory = getFactory();
    DYN::SubModel* model;
    model = factory->create();

    // destroy_t* destroy_triangle = (destroy_t*) dlsym(triangle, "destroy");
    // dlsym_error = dlerror();
    // if (dlsym_error) {
    //     cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
    //     return 1;
    // }

    delete factory;

    // unload the triangle library
    dlclose(lib);
}
