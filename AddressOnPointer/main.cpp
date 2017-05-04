#include <iostream>
#include <memory>
#include <string>
 
using namespace std;

class Object
{
	public:
		Object(std::string value);
		
		void PrintString();
		
	private:
		
		std::string string_value_ = "";
};

Object::Object(std::string value)
	:string_value_(value)
{
}

void Object::PrintString()
{
	std::cout << string_value_ << std::endl;
}

class Foo
{
public:
	
	//! Constructor
	Foo() = default;
	
	//! Destructor.
    ~Foo();

   //! Copy constructor.
   //Foo(const Foo&) = default;

   //! Move constructor.
   //Foo(Foo&&) = delete;

   //! Copy affectation.
   //Foo& operator=(const Foo&) = delete;

   //! Move affectation.
   //Foo& operator=(Foo&&) = delete;
   
	Foo(int value,
		std::string string_value);

	void PrintParameter();
	
	std::shared_ptr<Object> GetObjectPointerNoRef();
	
	std::shared_ptr<Object>& GetObjectPointerRef();
	
	Object* GetRawObjectPointerNoRef();
	
	Object*& GetRawObjectPointerRef();
	
private:
	
	int parameter_;
	
	std::shared_ptr<Object> object_ptr_ = nullptr;
	
	Object* raw_object_ptr_ = nullptr;
		  
};

Foo::Foo(int value,
		std::string string_value)
	: parameter_(value)
{
	object_ptr_ = std::make_shared<Object>(string_value);
	raw_object_ptr_ = new Object("tata");
}

Foo::~Foo()
{
	delete raw_object_ptr_;
}


void Foo::PrintParameter()
{
	std::cout << "&object_ptr_ " << &object_ptr_ << std::endl;
	std::cout << "&(*object_ptr_)" << &(*object_ptr_) << std::endl;
	std::cout << "&raw_object_ptr_ " << &raw_object_ptr_ << std::endl;
	std::cout << "&(*raw_object_ptr_)" << &(*raw_object_ptr_) << std::endl;
	std::cout << "parameter " << parameter_ << std::endl;
}

std::shared_ptr<Object> Foo::GetObjectPointerNoRef()
{
	return object_ptr_;
}

std::shared_ptr<Object>& Foo::GetObjectPointerRef()
{
	return object_ptr_;
}

Object* Foo::GetRawObjectPointerNoRef()
{
	return raw_object_ptr_;
}

Object*& Foo::GetRawObjectPointerRef()
{
	return raw_object_ptr_;
}
 
int main () 
{
   Foo foo(50, "toto");
   Foo* foo_ptr;
   foo_ptr = &foo;
   
   foo.PrintParameter();
   
   auto object1 = foo.GetObjectPointerNoRef();
   auto& object2 = foo.GetObjectPointerRef();
   
   std::cout << "object1 " << object1 << std::endl;
   std::cout << "&object1 " << &object1 << std::endl;
   std::cout << "object2 " << object2 << std::endl;
   std::cout << "&object2 " << &object2 << std::endl;
   
   object1->PrintString();
   object2->PrintString();
   
   auto object3 = foo.GetRawObjectPointerNoRef();
   auto& object4 = foo.GetRawObjectPointerRef();
   
   std::cout << "object3 " << object3 << std::endl;
   std::cout << "&object3 " << &object3 << std::endl;
   std::cout << "object4 " << object4 << std::endl;
   std::cout << "&object4 " << &object4 << std::endl;
   
   object3->PrintString();
   object4->PrintString();
   
   return 0;
}
