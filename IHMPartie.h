#ifndef IHMPARTIE_H
#define IHMPARTIE_H

#include <string>
#include <vector>

class Wordle;

class IHMPartie
{
  public:
    enum EntreeMenu
    {
        JOUER_PARTIE = 1,
        AFFICHER_HISTORIQUE,
        QUITTER
    };

  private:
    Wordle* jeuWordle;

  public:
    IHMPartie(Wordle* wordle = nullptr);

    int         choisirMenu() const;
    int         choisirTheme(const std::vector<std::string>& nomsThemes) const;
    std::string saisirMot();
    void        afficherLettreEnCouleurSelonEtat() const;
    void        afficherTentatives(const std::vector<std::string>& motsProposes) const;
    void        afficherInformationsPartie() const;
    void        afficherRegles() const;
    void        afficherNomWordle() const;
    bool        afficherMenuFin() const;
    void        afficherMessageDefaite() const;
    void        afficherMessageVictoire(int nbTentatives) const;
    void        afficherHistoriqueParties() const;

    static void afficherErreur(const std::string& erreur);
};

#endif // IHMPARTIE_H