#include <vector>

int main() 
{
	std::vector<int> vec(20);
	
	for (int i = 0 ; i < vec.size() ; ++i)
	{
		vec[i] = i;
	}
	
	return 0;
}