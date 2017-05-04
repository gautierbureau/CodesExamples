#include <iostream>
#include <fstream>

int test(const char* fileName) {
  std::ifstream ifile(fileName);
  return (ifile > 0);
}

int main() {
  int a = 12;
  a = test("/home/gautbure/Codes/CodesExamples/main.cpp");

  std::cout << a << std::endl;

  return 0;
}

