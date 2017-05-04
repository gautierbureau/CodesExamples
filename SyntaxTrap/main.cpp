# include <iostream>

int main()
{
    int i = 0 ;
    int j = 0;
	
	//     if (++i || j++)
	//     {
	//         i = 1;
	//         std::cout << j << std::endl;
	//     }
	//
	// std::cout << "case i++ || j++ " << i + j << std::endl;
    
    if (i++ && j++)
    {
        i = 1;
        j = 2;
    }
    
    std::cout << "case i++ && j++ " << i + j << std::endl;
    
    if (i++ || j++)
    {
        i = 1;
        j = 2;
    }
    
    std::cout << "case i++ || j++ " << i + j << std::endl;
    
    
    if (++i && ++j)
    {
        i = 1;
        j = 2;
    }
    
    std::cout << "case ++i && ++j " << i + j << std::endl;
    
    if (++i || ++j)
    {
        i = 1;
        j = 2;
    }
    
    std::cout << "case ++i || ++j " << i + j << std::endl;
    
    int k = 0;
    
    if (i = 2)
    {
        k = 2;
    }
    
    std::cout << "case i = 2 " <<  k << std::endl;
    
    return 0;
}
