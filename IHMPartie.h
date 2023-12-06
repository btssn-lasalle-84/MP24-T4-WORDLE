#ifndef IHMPARTIE_H
#define IHMPARTIE_H

#define DEBUG_IHMPARTIE

class Wordle;

class IHMPartie
{
  private:
    Wordle* jeuWordle;

  public:
    IHMPartie(Wordle* wordle = nullptr);

    void afficherAccueil();
    void afficherMotAdeviner();
    void afficherResultats();
    void afficherScore() const;
    char saisirLettre();
};

#endif // IHMPARTIE_H
