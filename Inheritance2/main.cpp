#include <iostream>

class A
{
    public:
		A() { init(); }
		void init() { init2();}
		virtual void init2() = 0;
}; 

class B : public A
{
    public:
		virtual void init2() { std::cout << "B::init2()" << std::endl;}
}; 

int main() 
{ 

    B b; 

	return 0;
}