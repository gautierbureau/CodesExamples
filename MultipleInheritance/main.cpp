class Base 

{ 

    public: 

    int data; 

}; 

 

//class DerivedOne : public Base {}; // wrong
//class DerivedOne : virtual public Base {}; //right 
class DerivedOne : public virtual Base {}; //right 
 

//class DerivedTwo : public Base {}; // wrong
class DerivedTwo : virtual public Base {}; 

 

class Derived : public DerivedOne, public DerivedTwo {}; 

 

int main() 
{ 

    Derived obj; 

    obj.data = 5; 

}