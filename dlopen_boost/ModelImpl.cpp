#include <iostream>

#include "Factory.h"
#include "Model.h"
#include "ModelImpl.h"

extern "C" Factory* getFactory() {
  std::cout << "extern C Factory* getFactory()" << std::endl;
  return (new ModelFactory());
}

extern "C" void deleteFactory(Factory* factory) {
  std::cout << "extern C void deleteFactory(Factory* factory)" << std::endl;
  delete factory;
}

extern "C" Model* ModelFactory::create() const {
  std::cout << "extern C Model* ModelFactory::create()" << std::endl;
  Model* model(new ModelImpl());
  return model;
}

extern "C" void ModelFactory::destroy(Model* model) const {
  std::cout << "extern C void ModelFactory::destroy(Model* model) " << model->getSizeInit() << std::endl;
  delete model;
}

ModelImpl::ModelImpl() {
  std::cout << "ModelImpl::ModelImpl" << std::endl;
  impl_size_ = 14.;
}

ModelImpl::~ModelImpl() {
  std::cout << "ModelImpl::~ModelImpl" << std::endl;
}

void ModelImpl::init(int size) {
  init_size_ = size;
  std::cout << "hello" << std::endl;
}

int ModelImpl::getSizeInit() {
  return init_size_;
}
