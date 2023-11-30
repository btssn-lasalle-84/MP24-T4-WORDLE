#include "Partie.h"
#include <iostream>

Partie::Partie(const std::vector<Joueur>& j) : joueurs(j)
{
}

void Partie::demarrerPartie()
{
    initialiserPartie();
    afficherResultats();
}

void Partie::initialiserPartie()
{
    dictionnaire.getMotAleatoire();
}

void Partie::afficherMotAdeviner()
{
    std::cout << "Mot à deviner : " << wordle.getMotAdeviner() << std::endl;
}
