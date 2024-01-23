#include "Joueur.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Joueur::Joueur() : scoreActuel(0), nbTentatives(0)
{
}

Joueur::~Joueur()
{
}

int Joueur::incrementerTentatives()
{
    nbTentatives += INCREMENTATION_TENTATIVES;
    return nbTentatives;
}

int Joueur::getNbTentatives() const
{
    return nbTentatives;
}

void Joueur::reinitialiserJeu()
{
    scoreActuel  = 0;
    nbTentatives = 0;
    motsProposes.clear();
}

void Joueur::proposerMot(const std::string& motPropose)
{
    motsProposes.push_back(motPropose);
#ifdef DEBUG_JOUEUR
    std::cout << "Nombre de mots proposés = " << motsProposes.size() << " - Mots Proposés = ";
    for(int i = 0; i < motsProposes.size(); ++i)
        std::cout << motsProposes[i] << " ";
    std::cout << std::endl;
#endif
}

std::vector<std::string> Joueur::getMotsProposes() const
{
    return motsProposes;
}
