#include "Partie.h"
#include <iostream>

Partie::Partie()
{
}

void Partie::afficherAccueil()
{
    std::cout << "Jeu du pendu" << std::endl;
}

void Partie::afficherMotAdeviner()
{
    std::cout << "Mot à deviner : " << jeuWordle.getMotAdeviner() << std::endl;
}

void Partie::afficherResultats()
{
}