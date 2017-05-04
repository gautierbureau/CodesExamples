# include <iostream>
# include <assert.h>

int main()
{
    int i = 2;
    
    assert(i < 1 && "i should be greater than one.");
	
    return 0;
}
