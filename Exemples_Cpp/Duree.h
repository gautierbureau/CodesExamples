class Duree
{
    	public:
 
    	Duree(int heures = 0, int minutes = 0, int secondes = 0);
	Duree& operator+=(Duree const& duree);
	bool estEgal(Duree const& b) const;
 
   	private:
 
   	int m_heures;
    	int m_minutes;
    	int m_secondes;
};

bool operator==(Duree const& a, Duree const& b);
