#include <iostream>
#include <memory>
 
using namespace std;

class Foo
{
public:
	
	//! Constructor
	Foo() { std::cout << this << std::endl; }
	
	//! Destructor.
    ~Foo() = default;

   //! Copy constructor.
   //Foo(const Foo&) = default;

   //! Move constructor.
   //Foo(Foo&&) = delete;

   //! Copy affectation.
   //Foo& operator=(const Foo&) = delete;

   //! Move affectation.
   //Foo& operator=(Foo&&) = delete;
   
	Foo(int value);

	void PrintParameter();
	
private:
	int parameter_;
		  
};

Foo::Foo(int value)
	: parameter_(value)
{
	std::cout << this << std::endl;
}

void Foo::PrintParameter()
{
	std::cout << "parameter " << parameter_ << std::endl;
}

 
int main () 
{
   Foo foo(50);
   Foo* foo_ptr;
   foo_ptr = &foo;
   
   foo.PrintParameter();
   foo_ptr->PrintParameter();
   
   Foo& foo_deref_add = *foo_ptr;
   Foo foo_deref_no_add = *foo_ptr;
   
   foo_deref_add.PrintParameter();
   foo_deref_no_add.PrintParameter();
   
   std::cout << &foo_deref_add << std::endl;
   std::cout << foo_ptr << std::endl;
   std::cout << &foo_deref_no_add << std::endl;
   
   return 0;
}
