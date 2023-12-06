#include "IHMPartie.h"
#include "Wordle.h"
#include <iostream>

IHMPartie::IHMPartie(Wordle* wordle) : jeuWordle(wordle)
{
#ifdef DEBUG_IHMPARTIE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "wordle = " << wordle << " | jeuWordle = " << jeuWordle << std::endl;
#endif
}

void IHMPartie::afficherAccueil()
{
    std::cout << "Jeu du pendu" << std::endl;
}

void IHMPartie::afficherMotAdeviner()
{
    std::cout << "Mot à deviner : " << jeuWordle->getMotADeviner() << std::endl;
}

void IHMPartie::afficherResultats()
{
}

void IHMPartie::afficherScore() const
{
}

char IHMPartie::saisirLettre()
{
    char entree;

    std::cout << "Veuillez entrer une lettre : ";
    std::cin >> entree;

    return entree;
}
