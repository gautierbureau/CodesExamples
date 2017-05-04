#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <iostream>

class B;

class A
{
public:
    A(boost::shared_ptr<B> b);
    ~A();

public:
    boost::shared_ptr<B> ptrB;
};

class B
{
public:
    B();
    ~B();

    void setA(boost::shared_ptr<A> a);

public:
    boost::weak_ptr<A> ptrA;
};

A::A(boost::shared_ptr<B> b)
{
  std::cout << "A(boost::shared_ptr<B> b)" << std::endl;
  ptrB = b;
std::cout << "b " << b << std::endl;
std::cout << "A::this " << this << std::endl;
  ptrB->setA(boost::shared_ptr<A>(this));
}

B::B() { std::cout << "B()" << std::endl; }

B::~B() { std::cout << "~B()" << std::endl; }

A::~A() { std::cout << "~A()" << std::endl; }

void B::setA(boost::shared_ptr<A> a)
{
  std::cout << "B::setA(boost::shared_ptr<A> a)" << std::endl;
  std::cout << "B::this "<< this << std::endl;
  std::cout << "a "<< a << std::endl;
  ptrA = a;
}

int main ()
{
  boost::shared_ptr<B> b(new B());
  std::cout << "B::this " << b << std::endl;
  boost::shared_ptr<A> a(new A(b));
  //b->setA(a);

  return 0;
}
