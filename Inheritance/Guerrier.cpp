# include <iostream>
# include "Guerrier.hpp"

void Guerrier::SePresenter() const
{
    Personnage::SePresenter();
    std::cout << "Et je suis aussi un Guerrier." << std::endl;
}
