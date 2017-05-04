#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "foo.hxx"

void foo(const char* message)
{
  std::cout << "length " << std::strlen(message) << std::endl;
  std::cout << "value " << message << std::endl;
}

int main()
{

  std::vector<std::string> string2Keep;

  std::stringstream ss("");
  ss << std::setprecision(3) << std::fixed << 12.;
  const std::string tmp = ss.str();

  string2Keep.push_back(tmp);

  foo(string2Keep.back().c_str());
foo2(string2Keep.back().c_str());
    //const char* a;
    //char const* b;


}
