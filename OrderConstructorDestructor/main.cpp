#include <iostream>

using namespace std;
//
// struct A
// {
//     A(){cout << "A() C-tor" << endl;}
//     ~A(){cout << "~A() D-tor" << endl;}
// };
//
// struct B : public A
// {
//     B(){cout << "B() C-tor" << endl;}
//     ~B(){cout << "~B() D-tor" << endl;}
//
//     A a;
// };
//
// int main()
// {
//     B b;
// }

class Base
{
    public:
    Base(){cout << "In Base Ctor\n";
}

    class Nest
    {
        public:
        Nest(){cout << "In Nest Ctor\n"; }
    };   
};

class Derive : public Base
{
    public:       
    Derive(){cout << "In Derive Ctor\n"; }
};

int main()
{
    Derive obj;
}