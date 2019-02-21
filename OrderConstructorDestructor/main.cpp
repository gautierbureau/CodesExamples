#include <iostream>

using namespace std;

struct A
{
    A(){cout << "A() C-tor" << endl;}
    virtual ~A(){cout << "~A() D-tor" << endl;}
};

struct B : public A
{
    B(){cout << "B() C-tor" << endl;}
    ~B(){cout << "~B() D-tor" << endl;}

    //A a;
};

class Base
{
    public:
    Base(){cout << "In Base Ctor\n";}
	~Base(){cout << "In Base Dtor\n";}

    class Nest
    {
        public:
        Nest(){cout << "In Nest Ctor\n"; }
		~Nest(){cout << "In Nest Dtor\n";}
    };
	
	Nest nest_;   
};

class Derive : public Base
{
    public:       
    Derive(){cout << "In Derive Ctor\n"; }
	~Derive(){cout << "In Derive Dtor\n"; }
};

int main()
{
    Derive obj;
	A* a = new B();
	delete a;
}