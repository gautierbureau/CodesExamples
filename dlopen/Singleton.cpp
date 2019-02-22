#include <iostream>

#include "Singleton.h"

Singleton Singleton::singleton_instance;

Singleton::Singleton() {
  std::cout << "Singleton::Singleton()" << std::endl;
  ++count_;
  std::cout << "count_ " << count_ << std::endl;

  count_ptr_ = new int(12);
  std::cout << "count_ptr_ " << *count_ptr_ << std::endl;
}

void Singleton::add() {
  std::cout << "Singleton::add()" << std::endl;
  ++count_;
  std::cout << "count_ " << count_ << std::endl;
}

Singleton::~Singleton() {
  std::cout << "Singleton::~Singleton()" << std::endl;
  std::cout << "count_ptr_ " << *count_ptr_ << std::endl;
  std::cout << "count_ " << count_ << std::endl;
  count_ = 0;
  std::cout << "count_ " << count_ << std::endl;
  delete count_ptr_;
}

SingletonAdd::SingletonAdd() {
  std::cout << "SingletonAdd::SingletonAdd()" << std::endl;
}

SingletonAdd::~SingletonAdd() {
  std::cout << "SingletonAdd::~SingletonAdd()" << std::endl;
}

void SingletonAdd::add() {
  std::cout << "SingletonAdd::add()" << std::endl;
  Singleton::singleton_instance.add();
}
