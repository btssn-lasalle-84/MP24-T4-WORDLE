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

    void        afficherMotAdeviner();
    void        afficherLettreEnCouleurSelonEtat() const;
    void        afficherScore() const;
    std::string saisirMot();
    void        afficherNomWordle() const;
    void        nbTentativesAtteint() const;
    void        afficherRegles() const;
};

#endif // IHMPARTIE_H