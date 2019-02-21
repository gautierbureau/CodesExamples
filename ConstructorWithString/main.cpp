#include <iostream>

class A
{
    public:
		A(std::string& s);
		
	private:
		std::string& data;
}; 

A::A(std::string& s) {
	data = s;
}

// A::A(std::string& s) : data(s) {
// }

int main() 
{ 

	std::string a = "toto";
    A a1(a); 

	return 0;
}