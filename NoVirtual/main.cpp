#include <iostream>

class A
{
  public:
    void func() { std::cout << "A" << std::endl; };
};

class B : public A
{
  public:
    void func() { std::cout << "B" << std::endl; };
};



int main ()
{
  A* a = new A();
  A* b = new B();

  a->func();
  b->func();

   return 0;
}
