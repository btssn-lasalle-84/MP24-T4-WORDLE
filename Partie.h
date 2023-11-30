#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include "Joueur.h"
#include "Dictionnaire.h"
#include "Wordle.h"

class Partie
{
  private:
    std::vector<Joueur> joueurs;
    Dictionnaire        dictionnaire;
    Wordle              wordle;

    void initialiserPartie();
    void afficherMotAdeviner();
    void afficherResultats(); // TODO

  public:
    Partie(const std::vector<Joueur>& joueurs);

    void demarrerPartie();
};

#endif
