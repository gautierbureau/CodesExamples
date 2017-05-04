#include <iostream>
 
using namespace std;

struct Foo
{
public:
	
	Foo(int n) : n_(n) { }
	
	// Copy assignement
	Foo& operator=( const Foo& rhs ) { n_ = rhs.n_; return *this; };
	Foo& operator=( Foo& rhs ) { n_ = rhs.n_; return *this; };
	//Foo& operator=( Foo rhs ) { n_ = rhs.n_; return *this; };
	//const Foo& operator=( const Foo& rhs ) { n_ = rhs.n_; return *this; };
	//const Foo& operator=( Foo& rhs ) { n_ = rhs.n_; return *this; };
	//const Foo& operator=( Foo rhs ) { n_ = rhs.n_; return *this; };
	//Foo operator=( const Foo& rhs ) { n_ = rhs.n_; return *this; };
	//Foo operator=( Foo& rhs ) { n_ = rhs.n_; return *this; };
	//Foo operator=( Foo rhs ) { n_ = rhs.n_; return *this; };
	
public:
	
	int n_;
};
 
int main()
{
    Foo foo1(7);
    const Foo foo2(12);
	
	cout << foo1.n_ << endl; 
	
	foo1 = foo2;
	
	cout << foo1.n_ << endl; 
 
	return 0;
}
