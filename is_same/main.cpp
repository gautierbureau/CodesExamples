#include <type_traits>
#include <iostream>

// #include "header.h"

int main ()
{
  bool toto = std::is_same<std::basic_string<char>, double>::value;

  std::cout << toto << std::endl;

  // double angle = 0;
  //
  // std::string tutu(angle);
  //
  // char tata;

  // int ret =foo<char>(tata);

  // std::cout << ret << std::endl;

  return 0;
}
