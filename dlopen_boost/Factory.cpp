#include <map>
#include <iostream>
#include <dlfcn.h>
#include <sstream>

#include "Factory.h"
#include "Model.h"

using std::map;
using std::string;
using std::stringstream;

typedef Factory* getFactory_t();

Factories Factory::factories_;

Factories::Factories() {
  std::cout << "Factories::Factories" << std::endl;
}

Factories::~Factories() {
  std::cout << "begin Factories::~Factories" << std::endl;
  // std::map<std::string, Factory*>::iterator iter = factoryMap_.begin();
  // for (; iter != factoryMap_.end(); ++iter)
  //   delete iter->second;

  std::map<std::string, Factory*>::iterator iter = factoryMap_.begin();
  for (; iter != factoryMap_.end(); ++iter) {
    void* handle = iter->second->handle_;

    destroy_t* deleteFactory = factoryMapDestroy_.find(iter->first)->second;

    deleteFactory(iter->second);

    if (handle) {
      dlclose(handle);
    }
  }
  factoryMap_.clear();
  factoryMapDestroy_.clear();
  std::cout << "end Factories::~Factories" << std::endl;
}

std::map<std::string, Factory*>::iterator
Factories::find(const std::string& lib) {
  std::cout << "Factories::find" << std::endl;
  return (factoryMap_.find(lib));
}

bool Factories::end(std::map<std::string, Factory*>::iterator& iter) {
  std::cout << "Factories::end" << std::endl;
  return (iter == factoryMap_.end());
}

void Factories::add(const std::string& lib, Factory* factory) {
  std::cout << "Factories::add" << std::endl;
  factoryMap_.insert(std::make_pair(lib, factory));
}

void Factories::add(const std::string& lib, destroy_t* deleteFactory) {
  std::cout << "Factories::add destroy" << std::endl;
  factoryMapDestroy_.insert(std::make_pair(lib, deleteFactory));
}

boost::shared_ptr<Model> Factory::createModelFromLib(const std::string& lib) {
  std::cout << "Factory::createModelFromLib" << std::endl;

  map<string, Factory*>::iterator iter = factories_.find(lib);
  Model* model;
  boost::shared_ptr<Model> model_shared;

  if (factories_.end(iter)) {
    // load the library
    void *handle;
    handle = dlopen(lib.c_str(), RTLD_NOW);
    char* error;
    if (!handle) {
      stringstream msg;
      msg << "Load error :" << dlerror();
      std::cout << msg.str() << std::endl;
      throw(msg.str().c_str());
    }

    // reset errors
    dlerror();

    getFactory_t* getFactory = reinterpret_cast<getFactory_t*> (dlsym(handle, "getFactory"));
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
      stringstream msg;
      msg << "Load error :" << error;
      std::cout << msg.str() << std::endl;
      throw(msg.str().c_str());
    }

    destroy_t* deleteFactory = reinterpret_cast<destroy_t*>(dlsym(handle, "deleteFactory"));
    dlsym_error = dlerror();
    if (dlsym_error) {
      stringstream msg;
      msg << "Load error :" << dlsym_error;
      std::cout << msg.str() << std::endl;
      throw(msg.str().c_str());
    }

    std::cout << "Factory* factory = getFactory();" << std::endl;

    Factory* factory = getFactory();
    factory->handle_ = handle;
    factories_.add(lib, factory);
    factories_.add(lib, deleteFactory);
    model = factory->create();
    ModelDelete deleteModel(factory);
    std::cout << "after ModelDelete deleteModel(factory);" << std::endl;
    model_shared.reset(model, deleteModel);
    // model_shared.reset(model, [=](Model* model_ptr){ factory_->destroy(model_ptr); });
    std::cout << "after model_shared.reset(model, deleteModel);" << std::endl;
  } else {
    std::cout << "else model = iter->second->create();" << std::endl;
    model = iter->second->create();
    ModelDelete deleteModel(iter->second);
    std::cout << "after ModelDelete deleteModel(iter->second);" << std::endl;
    model_shared.reset(model, deleteModel);
    // model_shared.reset(model, [=](Model* model_ptr){ factory_->destroy(model_ptr); });
    std::cout << "after model_shared.reset(model, deleteModel);" << std::endl;
    // models_.push_back(model);
  }
  std::cout << "end createModelFromLib" << std::endl;
  return model_shared;
}

ModelDelete::ModelDelete(Factory* factory) : factory_(factory) {
  std::cout << "ModelDelete::ModelDelete(Factory* factory)" << std::endl;
}


void ModelDelete::operator()(Model* model) {
  std::cout << "void ModelDelete::operator()(Model* model)" << std::endl;
  factory_->destroy(model);
}

// https://thispointer.com/shared_ptr-and-custom-deletor/
// https://www.bfilipek.com/2016/04/custom-deleters-for-c-smart-pointers.html
// https://stackoverflow.com/questions/40109135/c-dynamic-loading-of-classes-why-is-a-destroy-function-needed
