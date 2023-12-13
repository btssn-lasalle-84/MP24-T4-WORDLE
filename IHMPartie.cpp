#include "IHMPartie.h"
#include "Wordle.h"
#include <iostream>
using namespace std;

IHMPartie::IHMPartie(Wordle* wordle) : jeuWordle(wordle)
{
#ifdef DEBUG_IHMPARTIE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "wordle = " << wordle << " | jeuWordle = " << jeuWordle << std::endl;
#endif
}

void IHMPartie::afficherAccueil()
{
    std::cout << "WORDLE" << std::endl;
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

string IHMPartie::saisirMot()
{
    string entree;

    cout << "Veuillez entrer un mot : ";
    cin >> entree;

    return entree;
}
