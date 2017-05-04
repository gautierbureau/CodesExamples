#include <iostream>

int main() 
{ 
	const int Mon = 1, Tue = 2; 

	enum DOW{ Mon = 11, Tue = 12 };
	
	DOW var = DOW::Mon;
}