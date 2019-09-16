#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

class B;

class A : public boost::enable_shared_from_this<A>
{
public:
    A(boost::shared_ptr<B> b);
    ~A();

    void associateToB();

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
  //ptrB->setA(getptr()); // not working because I think A is not constructed at this point
}

void A::associateToB() {
  ptrB->setA(shared_from_this());
}

B::B() { std::cout << "B()" << std::endl; }

B::~B() { std::cout << "~B()" << std::endl; }

A::~A() { std::cout << "~A()" << std::endl; }

void B::setA(boost::shared_ptr<A> a)
{
  ptrA = a;
}

int main ()
{
  boost::shared_ptr<B> b(new B());
  boost::shared_ptr<A> a(new A(b));
  a->associateToB();

  return 0;
}
