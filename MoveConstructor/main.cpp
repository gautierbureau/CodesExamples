#include <iostream>
 
using namespace std;

struct Foo
{
public:
	
	Foo(int n) : n_(n) { };
	
	// Move constructor
	Foo(Foo&& foo) noexcept : n_(std::move(foo.n_)) { };
	
public:
	
	int n_;
};
 
int main()
{
    Foo foo1(7);
    Foo foo2 = std::move(foo1);
	
	cout << foo1.n_ << endl;
	cout << foo2.n_ << endl;
 
	return 0;
}
