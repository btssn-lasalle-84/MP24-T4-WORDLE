#ifndef IHMPARTIE_H
#define IHMPARTIE_H

#define DEBUG_IHMPARTIE

#include <string>
#include <vector>

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
    bool        afficherMenuFin() const;
    void        nbTentativesAtteint() const;
    void        afficherRegles() const;
    void        afficherHistoriqueParties() const;
    int         choisirTheme(const std::vector<std::string>& nomsThemes) const;
};

#endif // IHMPARTIE_H