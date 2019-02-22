#include <iostream>

#include "Model.h"

Model::Model() : size_(12) {
  std::cout << "Model::Model()" << std::endl;
}

Model::~Model() {
  std::cout << "Model::~Model()" << std::endl;
}

int Model::getSize() {
  return size_;
}
