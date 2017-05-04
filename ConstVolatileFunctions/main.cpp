#include <iostream>

class TestPrint
{
public:

    void Print()
    {
        std::cout << "TestPrint" << std::endl;
    }

    void Print() const
    {
        std::cout << "const TestPrint" << std::endl;
    }

    void Print() volatile
    {
        std::cout << "volatile TestPrint" << std::endl;
    }

    void Print() const volatile
    {
        std::cout << "const volatile TestPrint" << std::endl;
    }
};


int main(int argc, char* argv[])
{
    TestPrint normal_test;
    normal_test.Print();

    const TestPrint const_test;
    const_test.Print();

    volatile TestPrint volatile_test;
    volatile_test.Print();

    const volatile TestPrint const_volatile_test;
    const_volatile_test.Print();
}
