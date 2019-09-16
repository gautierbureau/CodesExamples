#include <boost/core/demangle.hpp>
#include <iostream>

int main ()
{


std::string name("_ZN3DYN5TimerD1Ev");
std::string name2("_ZN3DYN5TimerC1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");

std::cout << boost::core::demangle(name.c_str()) << std::endl;
std::cout << boost::core::demangle(name2.c_str()) << std::endl;

   return 0;
}
