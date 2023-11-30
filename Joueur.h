#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
#include <iostream>

class Joueur
{
  private:
    std::vector<std::string> motsProposes;
    int                      scoreActuel;
    int                      nbTentatives;

  public:
    Joueur();
    int  score() const;
    int  incrementerScore();
    int  tentativesRestantes() const;
    char entreeJoueur();
    void afficherScore() const;
    void reinitialiserJeu();
    void proposerMot(std::string motPropose);
};

#endif // JOUEUR_H
