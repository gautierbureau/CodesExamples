#include <iostream>
#include "Foo.hpp"
 
using namespace std;

int main()
{
    Derived derived(1);
	
	derived.Forward();
	 
	return 0;
}
