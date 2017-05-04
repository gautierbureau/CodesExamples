#include <iostream>

using namespace std;

class base
{
};

class der : public base
{
};

void SomeFunc(base& b){ cout << "1" << endl; } 

void SomeFunc(base b){ cout << "2" << endl;  } 

void SomeFunc(der& b){ cout << "3" << endl;  } 

void SomeFunc(der b){ cout << "4" << endl;  }
 

int main() 

{ 

der d; 

SomeFunc(d); 

}