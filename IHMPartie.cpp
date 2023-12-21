#include "IHMPartie.h"
#include "Wordle.h"
#include <iostream>
#include <algorithm>

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

void IHMPartie::afficherRegles() const
{
    std::cout << "Bienvenue sur Wordle !" << std::endl
              << std::endl
              << "Les règles du jeu sont simple :  " << std::endl
              << std::endl
              << " - Deviner un mot de 5 lettres en 6 tentatives maximum  " << std::endl
              << std::endl
              << " - La lettre s'affiche en vert si elle est à la bonne place  " << std::endl
              << std::endl
              << " - La lettre s'affiche en jaune si elle est présente dans le "
                 "mot mais au mauvais "
                 "emplacement  "
              << std::endl
              << std::endl
              << " - La lettre s'affiche en rouge si elle n'est pas présente "
                 "dans le mot  "
              << std::endl
              << std::endl
              << "Bonne chance ! " << std::endl
              << std::endl;
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

Version 1.0
)" << endl;
}

bool IHMPartie::demanderContinuerPartie() const
{
    char choix;
    cout << "Voulez-vous continuer à jouer ? (O/N) : ";
    cin >> choix;
    return (choix == 'O' || choix == 'o');
}

void IHMPartie::nbTentativesAtteint() const
{
    std::cout << "Perdu ! Vous n'avez pas trouvé le mot."
              << " Le mot à trouver était : " << jeuWordle->getMotADeviner() << std::endl;
}
