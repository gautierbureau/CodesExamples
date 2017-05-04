#include <iostream>
 
using namespace std;

struct Foo
{
public:
	
	Foo(int n) : n_(n) { }
	
	// Copy constructors
    Foo(const Foo& foo) : n_(foo.n_) { }; 
	Foo(Foo& foo) : n_(foo.n_) { };
	Foo(volatile const Foo& foo) : n_(foo.n_) { };
	Foo(volatile Foo& foo) : n_(foo.n_) { };
	
public:
	
	int n_;
};
 
int main()
{
    Foo foo1(7);
    Foo foo2(foo1); 
 
	return 0;
}
