#ifndef MODEL_IMPL_H_
#define MODEL_IMPL_H_

#include <iostream>

#include "Model.h"
#include "Factory.h"

class ModelFactory : public Factory {
  public:

    ModelFactory() { std::cout << "ModelFactory::ModelFactory()" << std::endl; }

    ~ModelFactory() { std::cout << "ModelFactory::~ModelFactory()" << std::endl; }

    Model* create() const;

    void destroy(Model*) const;
};

class ModelImpl : public Model {
  public:

    ModelImpl();

    ~ModelImpl();

  public:

    void init();

    int getSizeInit();

  protected:

    double impl_size_;

    int init_size_;
};

#endif // MODEL_IMPL_H_
