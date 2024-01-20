#include "Dictionnaire.h"
#include <algorithm> // find
#include <fstream>
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire() : listeMots{ "samba", "livre", "pomme", "porte", "vague", "tigre", "jambe", "conte" }
{
    std::srand(static_cast<unsigned>(time(nullptr)));
}

std::string Dictionnaire::getMotAleatoire() const
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}

void Dictionnaire::chargerMotsDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open())
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }

    listeMots.clear();
    std::string mot;
    while (getline(fichier, mot))
    {
        listeMots.push_back(mot);
    }

    fichier.close();
}

const std::vector<std::string> &Dictionnaire::getListeMots() const
{
    return listeMots;
}