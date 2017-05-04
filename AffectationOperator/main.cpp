
class A
{
public:
    A();
    A(const A& a);
    ~A();

    A& operator=(const A& a);
};

class B
{
public:
    B();
    B(const B& b);
    ~B();

    const B& operator=(const B& b);

private:
    A* ptrA;
};

const B& B::operator=(const B& b)
{
  if (this != &b) {
    ptrA = b.ptrA;
  }
  return *this;
}

B::B()
{
}

B::~B()
{
}

int main()
{
  B b1;
  B b2;
  b1 = b2;
  return 0;
}
