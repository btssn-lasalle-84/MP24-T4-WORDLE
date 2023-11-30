#ifndef PARTIE_H
#define PARTIE_H

#include "Wordle.h"

class Partie
{
  private:
    void afficherAccueil();
    void afficherMotAdeviner();
    void afficherResultats(); // TODO
    Wordle jeuWordle;


  public:
    Partie();

    void demarrerPartie();
};

#endif
