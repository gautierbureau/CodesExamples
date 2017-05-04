#include <iostream>
 
using namespace std;

int func_one()
{
	cout << "Func one" << endl;
	return 12;
}

void func_two(double value)
{
	cout << "Func two " << value << endl;
}
 
int main () 
{
	void (*func_ptr)(double);
	func_ptr = func_two; // with & or not

	int (*func_ptr2)();
	func_ptr2 = &func_one;
	
	int value = func_ptr2();
	cout << "value " << value << endl;
	
	func_ptr(42);

   return 0;
}
