#include <iostream>
#include "Personnage.h"

using namespace std;

void Personnage::augmenterVie() {

	++vie;
}

void Personnage::diminuerVie() {

	--vie;
}

void Personnage::attaquer(Personnage &perso) {

	perso.diminuerVie();
}

Personnage::Personnage() {

	vie = 10;
	nomArme = "Epee";
}

Personnage::Personnage(int p_vie, string p_nomArme) {

	vie = p_vie;
	nomArme = p_nomArme;
}

Personnage::~Personnage() {
	
}

int Personnage::getVie() const {

	return vie;
}

void Personnage::setVie(int p_vie) {

	vie = p_vie;	
}
