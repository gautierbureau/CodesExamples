#include <iostream>
#include <memory>
 
using namespace std;

class Foo
{
public:
	Foo(int value);
	
	void PrintParameter();
	
private:
	int parameter_;
		  
};

Foo::Foo(int value)
	: parameter_(value)
{
}

void Foo::PrintParameter()
{
	std::cout << "parameter " << parameter_ << std::endl;
}

 
int main () 
{
	
   int* p1 = new int(12);
   
   int* p2 = nullptr;
   
   int* p3 = new int(10);
   
   std::cout << *p1 << std::endl;
   //std::cout << *p2 << std::endl;
   std::cout << *p3 << std::endl;
   
   p2 = p1;
   p2 = &(*p1);
   
   std::cout << *p2 << std::endl;
   std::cout << p1 << std::endl;
   std::cout << p2 << std::endl;
   
   delete p1;
   //delete p2;
   delete p3; 
   
   Foo foo1(1);
   
   std::unique_ptr<Foo> foo_u_ptr = std::make_unique<Foo>(12);
   
   Foo& foo_u = *foo_u_ptr;
   
   Foo* foo_ptr;
   
   Foo* foo_ptr2 = new Foo(50);
   
   foo1.PrintParameter();
   foo_u_ptr->PrintParameter();
   foo_u.PrintParameter();
   
   // First way to put the pointer in the raw pointer
   //foo_ptr = foo_u_ptr.get();
   
   // Second way
   foo_ptr = &foo_u;
   
   // Third way
   //foo_ptr = &(*foo_u_ptr);
      
   std::cout << "address of the pointers" << std::endl;
   std::cout << &foo_u_ptr << std::endl;
   std::cout << &foo_ptr << std::endl;
   
   std::cout << "address of the underlying objects" << std::endl;
   std::cout << foo_ptr << std::endl;   
   std::cout << &(*foo_u_ptr) << std::endl;
   
   foo_ptr->PrintParameter();
   
   std::cout << "address of foo1 " << &foo1 << std::endl;
   
   foo_ptr = &foo1;
   
   foo_ptr->PrintParameter();
   std::cout << "object " << foo_ptr << std::endl; 
   std::cout << "pointer " << &foo_ptr << std::endl;
   
   foo_ptr2->PrintParameter();
   
   std::cout << "object foo_ptr " << foo_ptr << std::endl; 
   std::cout << "pointer foo_ptr " << &foo_ptr << std::endl;
   std::cout << "object foo_ptr2 " << foo_ptr2 << std::endl; 
   std::cout << "pointer foo_ptr2 " << &foo_ptr2 << std::endl;
   
   // I swap the pointers to see the efefct of delete.
   // If I don't take the object created in foo_ptr2 and put it in another pointer than maybe it is never destroyed.
   //foo_ptr = &(*foo_ptr2); // First way
   foo_ptr = foo_ptr2; // Second way
   foo_ptr2 = &foo1;
   
   foo_ptr->PrintParameter();
   foo_ptr2->PrintParameter();
   
   std::cout << "object foo_ptr " << foo_ptr << std::endl; 
   std::cout << "pointer foo_ptr " << &foo_ptr << std::endl;
   std::cout << "object foo_ptr2 " << foo_ptr2 << std::endl; 
   std::cout << "pointer foo_ptr2 " << &foo_ptr2 << std::endl;
   
   delete foo_ptr;
   
   return 0;
}
