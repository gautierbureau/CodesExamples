#include <iostream>
 
double foo(const double& value)
{
	double ret = value + 10.;
	return ret;
}
 
int main () 
{
	double value = 2.;
	
	double ret = foo(value);
	
	std::cout << "value " << ret << std::endl;
   
	return 0;
}
