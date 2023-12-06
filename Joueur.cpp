#include "Joueur.h"
#include <vector>
#include <string>
#include <iostream>

#define INCREMENTATION_SCORE 1;

using namespace std;

Joueur::Joueur() : scoreActuel(0), nbTentatives(0)
{
#ifdef DEBUG_JOUEUR
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "scoreActuel = " << scoreActuel << " | nbTentatives = " << nbTentatives
              << std::endl;
#endif
}

Joueur::~Joueur()
{
#ifdef DEBUG_JOUEUR
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << std::endl;
#endif
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

int Joueur::getTentativesRestantes() const
{
    if(nbTentatives < NB_ENTREES_MAX)
    {
        return NB_ENTREES_MAX - nbTentatives;
    }
    else
    {
        return 0;
    }
}

void Joueur::reinitialiserJeu()
{
    scoreActuel  = 0;
    nbTentatives = 0;
    motsProposes.clear();
}

void Joueur::proposerMot(std::string motPropose)
{
    motsProposes.push_back(motPropose);
}
