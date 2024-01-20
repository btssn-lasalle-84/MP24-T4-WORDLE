#ifndef IHMPARTIE_H
#define IHMPARTIE_H
#include <iostream>
#define DEBUG_IHMPARTIE
#include "Dictionnaire.h"
#include <vector>

class Wordle;

class IHMPartie
{
  private:
    Wordle* jeuWordle;
    Dictionnaire dictionnaire;

  public:
    IHMPartie(Wordle* wordle = nullptr);

    void        afficherMotAdeviner();
    void        afficherLettreEnCouleurSelonEtat() const;
    void        afficherScore() const;
    std::string saisirMot();
    void        afficherNomWordle() const;
    bool        afficherMenuFin() const;
    void        nbTentativesAtteint() const;
    void        afficherRegles() const;
    void        afficherHistoriqueParties() const;
    void        choisirTheme();

};

#endif // IHMPARTIE_H