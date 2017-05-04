#define SEALED(className) \
   className ## Sealer \
      { \
      private: className ## Sealer(){}; \
      friend class className; \
      }; \
class className : virtual private className ## Sealer \

class SEALED(MyClass) {};

class MyClassDisallowed : public MyClass {};

int main()
{
   // Perfectly legal construction
   MyClass myClass;

   // Illegal construction, super-class is sealed
   MyClassDisallowed myClassDisallowed;
}