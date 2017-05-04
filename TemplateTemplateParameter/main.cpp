template <typename T> struct A{};
template <typename T> struct B : A<T>{};

template <template <typename> class C, typename T>
C<T> foo()
{
	C<T> ct;
	return ct;
}

int main()
{
	A<int> const & a = foo<B, int>();
}