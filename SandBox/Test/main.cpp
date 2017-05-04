#include <iostream> 
#include <cstdio>

#define language 437 
#if language < 400
#undef language 
#else  
#define language 850 
#ifdef language 
	printf("%d", language); 
#endif
#endif

  

using namespace std; 

 

class ExBase 

{ 

private: 

   static int stat; 

public: 

   static int GetStat(){ return stat; } 

}; 

 

int ExBase::stat = 25; 

class ExDer1 : public ExBase 

{ 

public: 

   friend int Der1Fn(){ return ExBase::stat; } 

}; 

 

class ExDer2 : public ExBase{}; 
 

class ExDer : public ExDer1, public ExDer2{};

int main() 

{ 

    ExDer d; 

    cout << d.Der1Fn() << endl; 

}

// int main()
//
// {
//
//     ExDer d;
//
//     cout << d.GetStat() << endl;
//
// }
//
// int main()
//
// {
//
//     cout << ExDer1::GetStat() << endl;
//
// }
//
// int main()
//
// {
//
//     cout << ExDer1::ExBase::GetStat() << endl;
//
// }