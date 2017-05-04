#include <cstddef>
#include <iostream>

struct Foo
{
    virtual size_t func(size_t st = 0) const = 0;
};

struct Bar : Foo
{
    virtual size_t func(size_t st = 999) const
    {
        return st;
    }
};

int main()
{
    Foo const & foo = Bar();
    size_t st = foo.func(); // What value does st have?
	std::cout << st << std::endl;
}
