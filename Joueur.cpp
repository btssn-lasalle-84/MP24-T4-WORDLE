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

int Joueur::getScore() const
{
    return scoreActuel;
}

int Joueur::incrementerScore()
{
    scoreActuel += INCREMENTATION_SCORE;
    return scoreActuel;
}

int Joueur::incrementerTentatives()
{
    nbTentatives += INCREMENTATION_TENTATIVES;
    return nbTentatives;
}

int Joueur::getTentativesRestantes() const
{
    if(nbTentatives < NB_TENTATIVES_MAX)
    {
        return NB_TENTATIVES_MAX - nbTentatives;
    }
    else
    {
        return 0;
    }
}

int Joueur::getTentativesMax() const
{
    return NB_TENTATIVES_MAX;
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
