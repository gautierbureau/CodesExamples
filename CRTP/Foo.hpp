
template <class DerivedT>
struct Base
{
public:
	
	Base(int n) : n_(n) { }
	
	// Copy constructors
    void Forward() { static_cast<DerivedT&>(*this).Forward(); };
	
public:
	
	int n_;
};

struct Derived : public Base<Derived>
{	
public:
	
	Derived(int n) : Base(n) {};
	
	void Forward() { std::cout << "Derived Forward" << std::endl; };
	
};
