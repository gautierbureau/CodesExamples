#include <iostream>

class A
{
    public:
		A() { std::cout << "A::A()" << std::endl; }
		A(const A& a) { std::cout << "A::A(const A&)" << std::endl; }
		A& operator=(const A& a) { std::cout << "operator =" << std::endl; return *this; }
}; 

int main() 
{ 

    A a1; 
	A a2 = a1; 
	A a3;
	a3 = a2;

	return 0;
}