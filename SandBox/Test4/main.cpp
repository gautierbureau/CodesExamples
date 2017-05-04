class SomeClass 

{
public: 

int data; 

friend void use_someclass();

protected: 

class Nest 

{

public: 

int nested; 

};

public: 

static Nest* createNest(){return new Nest;} 

};

 
void use_someclass() 

{

SomeClass::Nest* nst = SomeClass::createNest(); 

nst->nested = 5; 

}

int main()
{
	int i =0;
}