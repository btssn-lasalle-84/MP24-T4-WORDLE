#include "Dictionnaire.h"
#include <algorithm> // find
#include <fstream>
#include <iostream>
#include <dirent.h> // opendir et readdir
#include <cstring>  // strlen

using namespace std;

Dictionnaire::Dictionnaire() : listeMots{}, listeThemes{}
{
    std::srand(static_cast<unsigned>(time(nullptr)));

    chargerThemes();
}

std::string Dictionnaire::getMotAleatoire() const
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}

void Dictionnaire::chargerMots(int numeroThemeChoisi)
{
    if(numeroThemeChoisi < 0 || numeroThemeChoisi >= static_cast<int>(listeThemes.size()))
    {
        return;
    }

    std::ifstream fichier(listeThemes[numeroThemeChoisi]);

    if(!fichier.is_open())
    {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << listeThemes[numeroThemeChoisi]
                  << std::endl;
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
    listeThemes.clear();

    const std::string cheminDossierThemes = CHEMIN_THEMES;
    DIR*              repertoire          = opendir(cheminDossierThemes.c_str());
    if(repertoire == nullptr)
    {
        std::cerr << "Erreur : Impossible d'ouvrir le répertoire themes" << std::endl;
        return;
    }
    struct dirent* entry;
    while((entry = readdir(repertoire)) != nullptr)
    {
        std::string nomFichier = entry->d_name;
        if(nomFichier.size() > (int)strlen(EXTENSION_THEMES) &&
           nomFichier.substr(nomFichier.size() - (int)strlen(EXTENSION_THEMES)) == EXTENSION_THEMES)
        {
            listeThemes.push_back(cheminDossierThemes + nomFichier);
        }
    }
    closedir(repertoire);
}

std::vector<std::string> Dictionnaire::getNomsThemes() const
{
    std::vector<std::string> nomsThemes;
    for(const auto& themeChemin: listeThemes)
    {
        size_t dernierSlash = themeChemin.find_last_of('/');
        if(dernierSlash != std::string::npos)
        {
            nomsThemes.push_back(themeChemin.substr(dernierSlash + 1));
        }
        else
        {
            nomsThemes.push_back(themeChemin);
        }
    }
    return nomsThemes;
}