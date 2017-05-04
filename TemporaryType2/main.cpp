// Snippet 2
struct Bar{};
void foo(Bar & b){  }

// Correction
//void foo(const Bar & b){  }

int main()
{
	foo(Bar());
}
