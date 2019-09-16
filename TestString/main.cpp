// #define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>

void foo(std::string str) {
  std::cout << str << std::endl;
}

int main() {
  std::string str("toto");
  foo(str);
  return 0;
}
