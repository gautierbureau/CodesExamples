
class Foo
{
	public:
		
		Foo() {};
		
	public:
		
		void foo();
		
	private:
		
		double foo_impl(const double& value) const;
};

void Foo::foo()
{
	double value = 2.;
	
	double ret = foo_impl(value);
}
double Foo::foo_impl(const double& value) const
{
	double ret = value + 10.;
	return ret;
}
 
int main () 
{
	Foo f;
	
	f.foo();
	
	return 0;
}
