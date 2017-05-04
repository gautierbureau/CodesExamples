#include <iostream>
#include <fstream>
#include "addition.h"
#include "change.h"
#include <vector>
#include <string>
#include "Personnage.h"
#include "Duree.h"

// -> est équivalent au . pour un objet quand l'objet est un pointeur

using namespace std;

int main(int argc, char * argv[])
{
// paramètres
	int a(2),b(3),resu(0);
	string test("saluts");
	int *addresseResu(&resu);
	vector<int> vecteur(10,2);
	int tableau(10);
	Personnage david(10,"Epee"), goliath(5,"Epee");
	Personnage gautier;
	//Personnage *ratata = new Personnage();
	Duree duree1(0, 10, 28), duree2(0, 15, 2);

	//int *nb = new int(25);

	//cout << nb << endl;
	//cout << *nb << endl;

	//delete nb;

	//cout << nb << endl;
	//cout << *nb << endl;

	if (a == 1 ) {
		++a;
	}
	else if (a == 0) {
		++a;
	}
	else {
		++a;
	}

	switch (a) {
		case 1: 
			++a;
			break;
		default: ++a;
			break;
	}

	//while( a == 1 )
	//do { } while(a==1);

	for (int i = 0 ; i < 2 ; ++i) {
		++a;
	}

//calculs
	resu = addition(a,b);

	//cout << resu << endl;

	change(addresseResu);

	//cout << &resu << " " << addresseResu << endl;

	//cout << resu << endl;

	//cout << test.size() << endl;

	david.augmenterVie();

	//cout << "Vie : " << david.getVie() << endl;

	david.setVie(20);

	//cout << "Vie : " << david.getVie() << endl;

	david.attaquer(goliath);

	//cout << "Vie de goliath : " << goliath.getVie() << endl;

	//cout << gautier.getVie() << endl;

	//ratata->setVie(12);

	//cout << "ratata " << ratata->getVie() << endl;

	//cout << (*ratata).getVie() << endl;

	//cout << ratata << " " << &(*ratata) << endl; 

	//delete ratata;

	//cout << ratata->getVie() << endl;

	//cout << ratata << endl;
	
	//(&gautier)->setVie(15);

	//cout << &gautier << endl;

	//cout << gautier.getVie() << endl;

//files

	//ifstream fichier("test.txt", ios::in);  // on ouvre le fichier en lecture
	ofstream fichier("test.txt", ios::out);

        if(fichier)  // si l'ouverture a réussi
        {       
            	string nom = "Xav57";
                int age = 19;
                fichier << "Date de naissance : " << 24 << '/' << 3 << '/' << 1988 << endl;
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;

	return 0;
}


/*

Tu utilises new quand tu fais de l'allocation mémoire sur le tas et non sur la pile.
Tu as 2 manières de déclarer une variable, un tableau ou autre objet primitif: sur le tas, ou sur la pile. Sur la pile, l'objet ne sera plus accessible dès que tu sortiras du scope {...} dans lequel il a été déclaré. Pour ça, il faut déclarer sur le tas. D'autre part, la taille de la pile est limitée, il faut éviter d'y coller bcp de gros objets sous peine de "stack overflow". C'est donc une zone mémoire pour les objets temporaires.
 

Les objets sur le tas, eux, ont une durée de vie qui s'arrête à l'appel d'un delete ou à la terminaison du programme.
Les free et les delete doivent être rigoureusement appairés sous peine de plantage ou de fuite mémoire. Pour éviter cela, une habitude à prendre dès le début est d'écrire le delete juste après avoir écrit le new, de façon à avoir en tête la durée de vie de l'objet alloué.

*/

/*

First, remember that objects in C++ can be created either on the stack or on on the heap.

1. A stack frame (or scope) is defined by a {} pair. Any local variable defined within such a pair will go out of scope once the program exits that pair. So here is an example of a local object being defined on the stack and then going out of scope:

2. Now, an object can also be declared on the heap. This allows it to "survive" between stack frames. Such an object must be referred to by a pointer. One could say that an object declared on the heap never goes out of scope, but that's really because the object is never really associated with any scope.

However, objects declared on the heap must be referred to by pointers, which can be local variables associated with scopes. And, you guessed it, the pointer can go out of scope. If you haven't explicitly freed the object the pointer is pointing to, then the block of heap memory will never be freed until the process exits (this is called a memory leak).

So to go to your linked list example: typically, nodes of such a list are declared on the heap, with each node holding a pointer to the next node. All of this is sitting on the heap and never goes out of scope. The only thing that could go out of scope is the pointer that points to the root of the list - the pointer you use to reference into the list in the first place. That can go out of scope.

*/

/*
int a = 1;
int b = 1;
int c = 1;
//Pré-incrémentation :
c = ++a; // c vaut 2
//Post-incrémentation :
c = b++; // c vaut 1
//Dans tous les cas, a et b valent à présent 2
*/

/*

Qu’est ce qu’une fonction virtuelle ?

Celle-là, on adore la poser aussi !

Réponse : méthode destinée à être redéfinie dans ses classes filles. Appuyez vous sur le mot “polymorphisme” !

*/
