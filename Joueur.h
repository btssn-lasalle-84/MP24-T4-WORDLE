#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>

#define DEBUG_JOUEUR

#define INCREMENTATION_SCORE      1
#define INCREMENTATION_TENTATIVES 1
#define NB_TENTATIVES_MAX         6

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
    int  incrementerTentatives();
    int  getScore() const;
    int  incrementerScore();
    int  getTentativesRestantes() const;
    int  getTentativesMax() const;
    void reinitialiserJeu();
    void proposerMot(const std::string& motPropose);
};

#endif // JOUEUR_H
