#include <string>
#include <iostream>

int main()
{
	std::string str = "HELLO WORLD";
	std::transform(str.begin(), str.end(), str.begin(), tolower);
	
	std::cout << str << std::endl;
}

