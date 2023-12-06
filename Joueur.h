#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>

#define DEBUG_JOUEUR

#define NB_ENTREES_MAX 6

class Joueur
{
  private:
    std::string              nom;
    std::vector<std::string> motsProposes;
    int                      scoreActuel;
    int                      nbTentatives;

  public:
    Joueur();
    ~Joueur();

    int  getScore() const;
    int  incrementerScore();
    int  getTentativesRestantes() const;
    void reinitialiserJeu();
    void proposerMot(std::string motPropose);
};

#endif // JOUEUR_H
