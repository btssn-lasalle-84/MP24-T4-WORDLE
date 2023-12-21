#include "IHMPartie.h"
#include "Wordle.h"
#include <iostream>
using namespace std;

IHMPartie::IHMPartie(Wordle* wordle) : jeuWordle(wordle)
{
}

void IHMPartie::afficherMotAdeviner()
{
    std::cout << "Mot à deviner : " << jeuWordle->getMotADeviner() << std::endl;
}

void IHMPartie::afficherLettreEnCouleurSelonEtat() const
{
    std::cout << "Mot entré : " << jeuWordle->mettreLettreEnCouleurSelonEtat() << std::endl;
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

void IHMPartie::afficherNomWordle() const
{
    cout << R"(

  █████   ███   █████    ███████    ███████████   ██████████   █████       ██████████
 ░░███   ░███  ░░███   ███░░░░░███ ░░███░░░░░███ ░░███░░░░███ ░░███       ░░███░░░░░█
  ░███   ░███   ░███  ███     ░░███ ░███    ░███  ░███   ░░███ ░███        ░███  █ ░
  ░███   ░███   ░███ ░███      ░███ ░██████████   ░███    ░███ ░███        ░██████
  ░░███  █████  ███  ░███      ░███ ░███░░░░░███  ░███    ░███ ░███        ░███░░█
   ░░░█████░█████░   ░░███     ███  ░███    ░███  ░███    ███  ░███      █ ░███ ░   █
     ░░███ ░░███      ░░░███████░   █████   █████ ██████████   ███████████ ██████████
      ░░░   ░░░         ░░░░░░░    ░░░░░   ░░░░░ ░░░░░░░░░░   ░░░░░░░░░░░ ░░░░░░░░░░
)"
        << endl;
}

bool IHMPartie::demanderContinuerPartie() const
{
    char choix;
    cout << "Voulez-vous continuer à jouer ? (O/N) : ";
    cin >> choix;
    return (choix == 'O' || choix == 'o');
}
