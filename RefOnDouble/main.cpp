#include <iostream>

using namespace std;

double foo(const double& test)
{
  const double value = test + 1;

  return value;
}

int main ()
{
	 double ur = 10.;

   const double ii = foo(ur);

   cout << ii << endl;

   return 0;
}
