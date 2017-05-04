# include <iostream>

# include "Foo.hpp"

int main()
{
    
    Foo foo1;
    Foo foo2("foo2");
    
    foo1.PrintFoo();
    foo2.PrintFoo();
    
    foo1.SetMessage("message changed");
    
    foo1.PrintFoo();
    
    std::cout << foo2.GetMessage() << std::endl;
    
    return 0;
}
