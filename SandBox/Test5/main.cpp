#include <iostream>  
  
class Outer  
{  
   int m_o;  
   public:  
   class Inner  
   {  
      int m_i;  
      public:  
        Inner(){}  
        Inner(Outer m_outer, int x)  
        {  
           m_outer.m_o = x;  
        }  
   };  
    
   Outer(int y)  
   {  
       m_inner.m_i = y;  
   }  
   void Display()  
   {  
       using namespace std;  
       cout << m_o << endl  
            << m_inner.m_i << endl;  
   }  
   Inner m_inner;  
};  
  
void main()  
{  
   Outer    objOut(10);  
   Outer::Inner objIn(objOut, 5);  
   objOut.Display();  
}  