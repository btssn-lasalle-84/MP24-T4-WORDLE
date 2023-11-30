#include "Joueur.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define NB_ENTREES_MAX 6

Joueur::Joueur() : scoreActuel(0), nbTentatives(0)
{
}

int Joueur::score() const
{
    return scoreActuel;
}

int Joueur::incrementerScore()
{
    scoreActuel += 2;
    return scoreActuel;
}

int Joueur::tentativesRestantes() const
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

char Joueur::entreeJoueur()
{
    char entree;
    cout << "Veuillez entrer une lettre : ";
    cin >> entree;

    return entree;
}

void Joueur::afficherScore() const
{
    cout << "Score : " << score() << endl;
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

