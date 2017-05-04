#include <boost/shared_ptr.hpp>
#include <iostream>

#include "Factory.h"
#include "Model.h"
#include "Singleton.h"
#include "foo.h"

int main() {

  SingletonAdd add1;
  add1.add();

  Model* model(Factory::createModelFromLib("./Model.so"));
  model->init();
  std::cout << model->getSize() << std::endl;
  std::cout << model->getSizeInit() << std::endl;

  Model* model2(Factory::createModelFromLib("./Model.so"));
  model2->init();
  std::cout << model2->getSize() << std::endl;
  std::cout << model2->getSizeInit() << std::endl;

  Foo foo;
  foo.print();

  Factory::resetFactories();

  return 0;
}
