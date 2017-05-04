#include <iostream>
#include <string>
#include <vector>

int main()
{
    char catname[15] = "qqqqqq1qqqqqqw";
    //catname = "Millie";
	//catname[15] = "Millie";
	//catname[ ] = "Millie";
	//double price = 7,450.98;
	
	//catname[2] = "2";
    
    const char* a;
    char const* b;
	
	char c = '2';
	char* const d = &c;
	
	char* const e = nullptr;
	
	const char test[] = "dfdsfd";
	
	const int i = 1;
	
	int const u = 10;
	
	int const j = 40;
	
	int k = 50;
	
	a = "hello";
		
	std::cout << a << std::endl;
	
	std::cout << catname << std::endl;
	
	std::cout << catname[12] << std::endl;
	
	std::cout << test << std::endl;
	
	
	const int x = 1;      // constant int
	//x = 2;            // illegal - can't modify x

	const int* pX;    // changeable pointer to constant int
	//*pX = 3;          // illegal -  can't use pX to modify an int
	pX = &i;      // legal - pX can point somewhere else

	int* const pY = &k;              // constant pointer to changeable int
	*pY = 4;                    // legal - can use pY to modify an int
	//pY = &i;      // illegal - can't make pY point anywhere else

	const int* const pZ = &j;        // const pointer to const int
	//*pZ = 5;                    // illegal - can't use pZ to modify an int
	//pZ = &i;      // illegal - can't make pZ point anywhere else
	

	char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char myword2[] = "Hello"; 
	
	myword[2] = '1';
	
	std::cout << myword << " " << myword2 << std::endl;
	
	char arr[ ] = "This is a test";

	std::string str(arr);
	
	// string to char
	std::string mytest("Please split this sentence into tokens");
	char* cstr = new char [mytest.length()+1];
	std::strcpy(cstr, mytest.c_str());
	
	std::string str2 = "string";
	const char* cstr2 = str2.c_str();
	
	std::vector<char> cstr3(str2.c_str(), str2.c_str() + str2.size() + 1);
	
	std::cout << arr << " " << str << std::endl;
	
	std::cout << mytest << " " << cstr << std::endl;
	
	std::cout << cstr[1] << std::endl;
	
	
    //char* const c = "a";
}
