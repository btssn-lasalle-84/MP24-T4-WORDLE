#include "Dictionnaire.h"
#include <algorithm> // find
#include <fstream>
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire() :
    listeMots{ "samba", "livre", "pomme", "porte", "vague", "tigre", "jambe", "conte" },
    listeThemes{ "aliments.dic", "animaux.dic", "divers.dic" }
{
    std::srand(static_cast<unsigned>(time(nullptr)));

    chargerThemes();
}

std::string Dictionnaire::getMotAleatoire() const
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}

void Dictionnaire::chargerMotsDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);

    if(!fichier.is_open())
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }

    listeMots.clear();
    std::string mot;
    while(getline(fichier, mot))
    {
        if(!mot.empty())
        {
            listeMots.push_back(mot);
        }
    }

    fichier.close();
}

std::vector<std::string> Dictionnaire::getListeMots() const
{
    return listeMots;
}

std::vector<std::string> Dictionnaire::getListeThemes() const
{
    return listeThemes;
}

void Dictionnaire::chargerThemes()
{
    // @todo : initialiser l'attribut listeThemes avec les noms des fichiers .dic du dossier
    // ./themes
}