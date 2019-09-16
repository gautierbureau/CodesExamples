#include <boost/shared_ptr.hpp>
#include <iostream>

#include "Factory.h"
#include "Model.h"

int main() {

  boost::shared_ptr<Model> model = Factory::createModelFromLib("./Model.so");
  std::cout << "after model = Factory::createModelFromLib" << std::endl;
  model->init(1);
  std::cout << model->getSize() << std::endl;
  std::cout << model->getSizeInit() << std::endl;

  // boost::shared_ptr<Model> model2 = Factory::createModelFromLib("./Model.so");
  // model2->init(2);
  // std::cout << model2->getSize() << std::endl;
  // std::cout << model2->getSizeInit() << std::endl;

  std::cout << "END OF PROGRAM" << std::endl;

  pthread_exit(NULL);

  return 0;
}
