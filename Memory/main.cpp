// stack = pile
// heap = tas

# include <iostream>

int global_init_var = 12;
int global_var;

void function()
{
    int stack_var;

    std::cout << "function's stack var " << &stack_var << std::endl; 
}

int main()
{
    int stack_var;
    static int static_init_var = 5;
    static int static_var;
    int* heap_var_ptr;

    heap_var_ptr = new int(2);

    // Variables dans le segment de donnes (data segment) : adresses basses
    std::cout << "global_init_var " << &global_init_var << std::endl;
    std::cout << "static_init_var " << &static_init_var << std::endl;
	
    // Variables dans le segment bss (bss segment)  : adresses basses
    std::cout << "global_var " << &global_var << std::endl;
    std::cout << "static_var " << &static_var << std::endl;
	
    // Variables dans le tas (heap segment) : adresses hautes
    std::cout << "&heap_var_ptr " << &heap_var_ptr << std::endl;
	std::cout << "heap_var_ptr " << heap_var_ptr << std::endl;
	
    // Variables dans la pile (stack segment) : adresses hautes
    std::cout << "stack_var " << &stack_var << std::endl;
	
	function();
	
	delete heap_var_ptr;
}
