#include <iostream>
#include <memory>
 
using namespace std;

class Foo
{
public:
	
	//! Constructor
	Foo() = default;
	
	//! Destructor.
    ~Foo() = default;

	void Print(const int* values[]);
	
	void Values(int values[]);		  
};

void Foo::Print(const int* values[])
{
}

void Foo::Values(int values[])
{
}

 
int main () 
{
   Foo foo;
   
   const int* values; // pointeur sur un const int
   
   int* values2;

   foo.Print(&values);
   
   foo.Values(values2);
   
   return 0;
}
