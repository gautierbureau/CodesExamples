#include <iostream>
#include <vector>

class A
{
public:
    A() { for (int i = 0; i < 10; ++i) data.push_back(i); }

    std::vector<int> getData() const;

private:
    std::vector<int> data;
};

std::vector<int> A::getData() const
{
    return data;
}

int
main(int argc, char** argv)
{
    A a;

    std::vector<int>::const_iterator itD;
    for (itD = a.getData().begin(); itD != a.getData().end(); ++itD)
        std::cout << *itD << std::endl;

    return 0;
}
