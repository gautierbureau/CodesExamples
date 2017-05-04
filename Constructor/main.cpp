#include <iostream>

class A
{
public:
    A() { std::cout << "Constructeur de A" << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << "Constructeur de B" << std::endl; }
};

class C : public A
{
public:
    C() { std::cout << "Constructeur de C" << std::endl; }
};

class D : public A, public B, public C
{
public:
    D() { std::cout << "Constructeur de D" << std::endl; }
};


int main()
{
   D d;

   return 0;
}
