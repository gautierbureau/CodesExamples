#include <iostream>
 
using namespace std;

struct Foo
{
public:
	
	Foo(int n) : n_(n) { }
	
	bool operator==(const Foo& foo) const { return n_ == foo.n_; };
	
public:
	
	int n_;
};
 
int main()
{
    Foo foo1(7);
    Foo foo2(12);
	Foo foo3(7);
	
	bool test1 = (foo1 == foo2);
	bool test2 = (foo1 == foo3);
	
	cout << test1 << endl; 
	cout << test2 << endl; 
 
	return 0;
}
