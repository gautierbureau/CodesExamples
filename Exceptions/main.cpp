#include <string>
#include <iostream>
#include <sstream>

int main()
{
   try 
   { 
       throw std::string( "Exemple d'exception" ); 
   } 
   catch ( const std::string& e ) 
   { 
       // affiche "Exemple d'exception" 
	   std::ostringstream oconv;
	   oconv << "Exception caught : " << e << std::endl;
	   std::cout << oconv.str();
	   // ou std::cerr << e.what();
   }
   catch ( const std::exception& e ) 
   { 
       // affiche "Exemple d'exception" 
	   std::ostringstream oconv;
	   oconv << "Exception caught : " << e.what() << std::endl;
	   std::cout << oconv.str();
	   // ou std::cerr << e.what();
   } 
   
	return EXIT_SUCCESS;
}
