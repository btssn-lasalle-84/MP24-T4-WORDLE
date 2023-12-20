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

void IHMPartie::nbTentativesAtteint() const
{
    std::cout << "Perdu ! Vous n'avez pas trouvé le mot."
              << " Le mot à trouver était : " << jeuWordle->getMotADeviner() << std::endl;
}