#include <string>
#include <iostream>
#include <sstream>

class A
{
public:
	
	virtual void foo() { std::cout << "A::foo" << std::endl; };
	
public:
	
	int toto_ = 12;
};

class B : virtual public A
{
public:
	void foo() { std::cout << "B::foo" << std::endl; };
};

class C : virtual public A
{
public:
	void foo() { std::cout << "C::foo" << std::endl; };
};

class D : public B, public C
{
public:
	void foo() { std::cout << "D::foo" << std::endl; C::foo(); };
};

int main()
{
   
	D d;
	
	d.foo();
	
	d.toto_;
   
	return EXIT_SUCCESS;
}
