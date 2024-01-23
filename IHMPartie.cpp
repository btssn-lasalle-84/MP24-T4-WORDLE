#include "IHMPartie.h"
#include "Wordle.h"
#include "Joueur.h"
#include <iostream>
#include <limits>

using namespace std;

IHMPartie::IHMPartie(Wordle* wordle) : jeuWordle(wordle)
{
}

int IHMPartie::choisirMenu() const
{
    int choix;
    std::cout << "Veuillez entrer votre choix : ";
    std::cin >> choix;

    while(choix < 1 || choix > EntreeMenu::QUITTER)
    {
        std::cout << "Saisie invalide !" << std::endl;
        std::cout << "Veuillez entrer votre choix : ";
        std::cin >> choix;
    }
    return choix;
}

int IHMPartie::choisirTheme(const std::vector<std::string>& nomsThemes) const
{
    if(nomsThemes.empty())
    {
        return -1;
    }

    std::cout << "Liste des thèmes :" << std::endl;

    for(size_t i = 0; i < nomsThemes.size(); ++i)
    {
        std::cout << i + 1 << " - " << nomsThemes[i] << std::endl;
    }

    int choixTheme;
    std::cout << "Veuillez entrer votre choix : ";
    std::cin >> choixTheme;

    while(choixTheme < 1 || choixTheme > static_cast<int>(nomsThemes.size()))
    {
        std::cout << "Saisie invalide !" << std::endl;
        std::cout << "Veuillez entrer votre choix : ";
        std::cin >> choixTheme;
    }
    std::cout << std::endl;
    return (choixTheme - 1);
}

string IHMPartie::saisirMot()
{
    string entree;

    cout << "Veuillez entrer un mot : ";
    cin >> entree;
    return entree;
}

void IHMPartie::afficherLettreEnCouleurSelonEtat() const
{
    std::cout << "Résultat : " << jeuWordle->mettreLettreEnCouleurSelonEtat() << std::endl;
}

void IHMPartie::afficherTentatives(const std::vector<std::string>& motsProposes) const
{
    std::cout << "Tentative n° " << motsProposes.size();
    if(motsProposes.size() > 1)
    {
        std::cout << " - Mots déjà proposés = ";
    }
    else
    {
        std::cout << " - Mot déjà proposé = ";
    }
    for(int i = 0; i < motsProposes.size(); ++i)
        std::cout << motsProposes[i] << " ";
    std::cout << std::endl << std::endl;
}

void IHMPartie::afficherInformationsPartie() const
{
    afficherNomWordle();
    afficherRegles();
}

void IHMPartie::afficherRegles() const
{
    std::cout << "Bienvenue sur Wordle !" << std::endl
              << std::endl
              << "Les règles du jeu sont :  " << std::endl
              << std::endl
              << " - Deviner un mot de " << TAILLE_MAX_MOT << " lettres en " << NB_TENTATIVES_MAX
              << " tentatives maximum  " << std::endl
              << " - La lettre s'affiche en vert si elle est à la bonne place  " << std::endl
              << " - La lettre s'affiche en jaune si elle est présente dans le "
                 "mot mais au mauvais "
                 "emplacement  "
              << std::endl
              << " - La lettre s'affiche en rouge si elle n'est pas présente "
                 "dans le mot  "
              << std::endl
              << std::endl
              << "Bonne chance ! " << std::endl
              << std::endl;
}

void IHMPartie::afficherNomWordle() const
{
    std::cout << R"(

  █████   ███   █████    ███████    ███████████   ██████████   █████       ██████████
 ░░███   ░███  ░░███   ███░░░░░███ ░░███░░░░░███ ░░███░░░░███ ░░███       ░░███░░░░░█
  ░███   ░███   ░███  ███     ░░███ ░███    ░███  ░███   ░░███ ░███        ░███  █ ░
  ░███   ░███   ░███ ░███      ░███ ░██████████   ░███    ░███ ░███        ░██████
  ░░███  █████  ███  ░███      ░███ ░███░░░░░███  ░███    ░███ ░███        ░███░░█
   ░░░█████░█████░   ░░███     ███  ░███    ░███  ░███    ███  ░███      █ ░███ ░   █
     ░░███ ░░███      ░░░███████░   █████   █████ ██████████   ███████████ ██████████
      ░░░   ░░░         ░░░░░░░    ░░░░░   ░░░░░ ░░░░░░░░░░   ░░░░░░░░░░░ ░░░░░░░░░░

)" << std::endl;
    std::cout << jeuWordle->getVersion() << std::endl << std::endl;
}

bool IHMPartie::afficherMenuFin() const
{
    std::cout << "Menu : " << std::endl;
    std::cout << "1 - Rejouer" << std::endl;
    std::cout << "2 - Afficher l'historique" << std::endl;
    std::cout << "3 - Quitter le jeu" << std::endl;

    return true;
}

void IHMPartie::afficherMessageDefaite() const
{
    std::cout << "Perdu ! Vous n'avez pas trouvé le mot."
              << " Le mot à deviner était : " << jeuWordle->getMotADeviner() << std::endl
              << std::endl;
}

void IHMPartie::afficherMessageVictoire(int nbTentatives) const
{
    std::cout << "Félicitations ! Vous avez deviné le mot en " << nbTentatives << " tentatives."
              << std::endl
              << std::endl;
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
    jeuWordle->gererMenu();
}

void IHMPartie::afficherErreur(const std::string& erreur)
{
    std::cerr << "Erreur : " << erreur << std::endl;
}
