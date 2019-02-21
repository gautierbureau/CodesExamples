#include <iostream>

class A
{
    public:
		A() { std::cout << "A" << std::endl; }
}; 

class B
{
    public:
		B() { std::cout << "B" << std::endl; }
}; 

class C
{
    public:
		C() { std::cout << "C" << std::endl; }
}; 

class D : public A, public C, public B
{
    public:
		D() { std::cout << "D" << std::endl; }
}; 

int main() 
{ 

    D d; 

	return 0;
}