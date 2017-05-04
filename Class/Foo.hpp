# include <string>

class Foo
{
public:
    
    Foo();
    
    Foo(std::string message);
    
    // -std=c++11
    ~Foo() = default;
    
    void PrintFoo();
    
    void SetMessage(std::string message);
    
    const std::string GetMessage() const;
    
private:
    
    void PrintMessage();
    
private:
    
    std::string message_;
    
};

# include "Foo.hxx"
