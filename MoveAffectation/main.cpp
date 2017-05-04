#include <iostream>
 
using namespace std;

struct Foo
{
public:
	
	Foo(int n) : n_(n) { }
	
	// Move assignement
	Foo& operator=(Foo&& foo) { n_ = std::move(foo.n_); std::cout << "move assigned\n"; return *this; }
	
public:
	
	int n_;
};
 
int main()
{
    Foo foo1(7);
    Foo foo2(12);
	
	foo2 = std::move(foo1);
	
	cout << foo2.n_ << endl; 
		 
	return 0;
}
