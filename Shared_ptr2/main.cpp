#include <memory>
#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

struct B;
struct A {
  boost::shared_ptr<B> b;
  ~A() { std::cout << "~A()\n"; }
};

struct B {
  boost::shared_ptr<A> a;
  //boost::weak_ptr<A> a;
  ~B() { std::cout << "~B()\n"; }
};

void useAnB() {
  // auto a = std::make_shared<A>();
  // auto b = std::make_shared<B>();
  boost::shared_ptr<B> b(new B());
  boost::shared_ptr<A> a(new A());
  a->b = b;
  b->a = a;
}

int main() {
   useAnB();
   std::cout << "Finished using A and B\n";
}
