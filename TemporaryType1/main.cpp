// Snippet 1
struct Bar{};
Bar foo(){ return Bar(); }
Bar & b = foo();

// Good Version 
//const Bar & b = foo();

int main()
{
	
}
