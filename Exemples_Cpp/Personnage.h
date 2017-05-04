#include <string>

class Personnage {

	private :

	int vie;
	std::string nomArme;

	public :

	Personnage();
	Personnage(int p_vie, std::string p_nomArme);
	~Personnage();
	void augmenterVie();
	void diminuerVie();
	void attaquer(Personnage &perso);
	int getVie() const;
	void setVie(int p_vie);
	virtual void affiche() const;
};
