#ifndef DEF_GUERRIER
#define DEF_GUERRIER

# include "Personnage.hpp"

class Guerrier : public Personnage
{
public:
    
    Guerrier() = default;
    
    ~Guerrier() = default;
    
    void SePresenter() const; // exemple de masquage
    
};

# include "Guerrier.hxx"

#endif
