#include <iostream>

#include "foo.h"

Foo::Foo() {
  std::cout << "Foo:Foo()" << std::endl;
}

Foo::~Foo() {
  std::cout << "Foo:~Foo()" << std::endl;
}

void Foo::print() {
  std::cout << "hello from foo" << std::endl;
}
