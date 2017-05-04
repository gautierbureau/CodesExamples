# include <iostream>
# include "Foo.hpp"

Foo::Foo()
: message_("default")
{
}

//Foo::~Foo()
//{
//}

Foo::Foo(std::string message)
: message_(message)
{
}

void Foo::PrintFoo()
{
    PrintMessage();
}

void Foo::PrintMessage()
{
    std::cout << message_ << std::endl;
}
