#include <iostream>

#include "Factory.h"
#include "Model.h"
#include "ModelImpl.h"
#include "Singleton.h"
#include "foo.h"

extern "C" Factory* getFactory() {
  std::cout << "extern C Factory* getFactory()" << std::endl;
  return (new ModelFactory());
}

extern "C" Model* ModelFactory::create() const {
  std::cout << "extern C Model* ModelFactory::create()" << std::endl;
  Model* model(new ModelImpl());
  return model;
}

extern "C" void ModelFactory::destroy(Model* model) const {
  delete model;
}

ModelImpl::ModelImpl() {
  std::cout << "ModelImpl::ModelImpl" << std::endl;
  impl_size_ = 14.;
}

ModelImpl::~ModelImpl() {
  std::cout << "ModelImpl::~ModelImpl" << std::endl;
}

void ModelImpl::init() {
  init_size_ = 15;
  std::cout << "hello" << std::endl;
  SingletonAdd addSingl;
  addSingl.add();
  Foo foo;
  foo.print();
}

int ModelImpl::getSizeInit() {
  return init_size_;
}
