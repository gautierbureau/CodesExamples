#include <iostream>
 
using namespace std;
 
int main () 
{
	
   int* p1;
   
   int* p2 = new int[10];
   
   int* p3 = nullptr;
   
   int* p4 = new int(12);
   
   std::cout << *p4 << std::endl;
   
   //delete p1; --> error at run time
   delete[] p2; 
   // delete p2; --> delete only the first pointer;
   delete p3;
   delete p4;
   

   return 0;
}
