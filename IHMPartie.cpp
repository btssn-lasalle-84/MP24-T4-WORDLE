#include "IHMPartie.h"
#include "Wordle.h"
#include "Dictionnaire.h"
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

IHMPartie::IHMPartie(Wordle* wordle) : jeuWordle(wordle)
{
}

std::string IHMPartie::choisirTheme(std::vector<std::string> listeThemes) const
{
    if(listeThemes.empty())
    {
        return "";
    }

std::cout << "Choisissez le thème :" << std::endl;

    std::vector<std::string> nomsThemes = dictionnaire.getNomsThemes();
    for (size_t i = 0; i < nomsThemes.size(); ++i)
    {
        std::cout << i + 1 << " - " << nomsThemes[i] << std::endl;
    }

    int choixTheme;
    std::cin >> choixTheme;

    while (choixTheme < 1 || choixTheme > static_cast<int>(listeThemes.size()))
    {
        std::cout << "Saisie invalide. Veuillez choisir un thème valide." << std::endl;
        std::cin >> choixTheme;
    }
    return listeThemes[choixTheme - 1];
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

Version 2.0
)" << endl;
}

bool IHMPartie::afficherMenuFin() const
{
    std::cout << "Menu : " << std::endl;
    std::cout << "1 - Rejouer" << std::endl;
    std::cout << "2 - Afficher l'historique" << std::endl;
    std::cout << "3 - Quitter le jeu" << std::endl;

    return true;
}

void IHMPartie::nbTentativesAtteint() const
{
    std::cout << "Perdu ! Vous n'avez pas trouvé le mot."
              << " Le mot à trouver était : " << jeuWordle->getMotADeviner() << std::endl;
}

void IHMPartie::afficherHistoriqueParties() const
{
    std::vector<std::string> historique = jeuWordle->getHistoriqueParties();

    std::cout << "Historique des parties en cours :" << std::endl;

    for(size_t i = 0; i < historique.size(); ++i)
    {
        std::cout << historique[i] << std::endl;
    }

    bool partieGagnee = jeuWordle->estMotCorrect();

    if(partieGagnee)
    {
        std::cout << "Partie gagnée !";
    }
    else
    {
        std::cout << "Partie perdue. Le mot était : " << jeuWordle->getMotADeviner();
    }

    std::cout << std::endl;

    afficherMenuFin();
    jeuWordle->saisirChoixMenu();
}
