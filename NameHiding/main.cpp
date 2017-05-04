#include <iostream>

class Base
{
  public:
    virtual void method();
    virtual void method(int i);
};

class Derived : public Base
{
  public:
    void method(double i);
};

void Base::method() { std::cout << "Base::method()" << std::endl; }

void Base::method(int i) { std::cout << "Base::method(int)" << std::endl; }

void Derived::method(double i) { std::cout << "Derived::method(double)" << std::endl; }

int main ()
{
  Derived d;
  int i = 0;
  double j = 2;
  d.method(j);
  // d.method();
  d.method(i);

  return 0;
}
