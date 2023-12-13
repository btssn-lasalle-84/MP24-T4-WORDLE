#ifndef IHMPARTIE_H
#define IHMPARTIE_H
#include <iostream>
#define DEBUG_IHMPARTIE

class Wordle;

class IHMPartie
{
  private:
    Wordle* jeuWordle;

  public:
    IHMPartie(Wordle* wordle = nullptr);

    void        afficherAccueil();
    void        afficherMotAdeviner();
    void        afficherResultats();
    void        afficherScore() const;
    std::string saisirMot();
};

#endif // IHMPARTIE_H
