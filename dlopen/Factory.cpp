#include <map>
#include <iostream>
#include <dlfcn.h>
#include <sstream>

#include "Factory.h"
#include "Model.h"

using std::map;
using std::string;
using std::stringstream;

Factories Factory::factories_;
std::vector<Model*> Factory::models_;

Factories::Factories() {
  std::cout << "Factories::Factories" << std::endl;
}

Factories::~Factories() {
  std::cout << "Factories::~Factories" << std::endl;
  std::map<std::string, Factory*>::iterator iter = factoryMap_.begin();
  for (; iter != factoryMap_.end(); ++iter)
    delete iter->second;
}

std::map<std::string, Factory*>::iterator
Factories::find(const std::string & lib) {
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

void Factories::reset() {
  std::cout << "Factories::reset" << std::endl;
  std::map<std::string, Factory*>::iterator iter = factoryMap_.begin();
  std::cout << "factoryMap_.size() " << factoryMap_.size() << std::endl;
  for (; iter != factoryMap_.end(); ++iter) {
    std::cout << "Factories::reset 10" << std::endl;
    void * handle = iter->second->handle_;
    std::cout << "Factories::reset 20" << std::endl;
    for (int i = 0 ; i < iter->second->models_.size(); ++i) {
      iter->second->destroy(iter->second->models_[i]);
    }
    delete iter->second;
    std::cout << "Factories::reset 30" << std::endl;

    if (handle) {
      std::cout << "Factories::reset 40" << std::endl;
      dlclose(handle);
      std::cout << "Factories::reset 50" << std::endl;
    }
  }
  std::cout << "Factories::reset 60" << std::endl;
  factoryMap_.clear();
  std::cout << "Factories::reset 70" << std::endl;
}

Model* Factory::createModelFromLib(const std::string& lib) {
  std::cout << "Factory::createModelFromLib" << std::endl;
  typedef Factory * getFactory_t();

  map<string, Factory*>::iterator iter = factories_.find(lib);
  Model* model;

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

    dlerror();
    getFactory_t* getFactory = reinterpret_cast<getFactory_t*> (dlsym(handle, "getFactory"));
    if ((error = dlerror()) != NULL) {
      stringstream msg;
      msg << "Load error :" << error;
      std::cout << msg.str() << std::endl;
      throw(msg.str().c_str());
    }
    Factory * factory = getFactory();
    factory->handle_ = handle;
    factories_.add(lib, factory);
    model = factory->create();
    models_.push_back(model);
  } else {
    std::cout << "else model = iter->second->create();" << std::endl;
    model = iter->second->create();
    models_.push_back(model);
  }
  return model;
}

void Factory::resetFactories() {
  std::cout << "Factory::resetFactories" << std::endl;
  factories_.reset();
}
