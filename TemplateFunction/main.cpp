struct Bar
{
   template <typename U>
   void func() const { }

   template <typename U>
   static void sfunc() { }
};

template <typename T>
void Foo1(T const & t)
{
   t.template func<int>();
   T::sfunc<int>(); // template needs to be specify
}

template <typename T>
void Foo2(T const * pT)
{
   pT->func<int>();
}

int main()
{
   Bar bar;
   Foo1(bar);
   Foo2(&bar);
}