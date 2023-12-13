#ifndef WORDLE_H
#define WORDLE_H

#include "Dictionnaire.h"
#include <string>

#define TAILLE_MAX_MOT 5

#define DEBUG_WORDLE

class Joueur;
class IHMPartie;

class Wordle
{
  private:
    std::string  motADeviner;
    std::string  motEntre;
    Joueur*      joueur;
    IHMPartie*   ihmPartie;
    Dictionnaire dictionnaire;

    void initialiserPartie();
    bool estMotCorrect() const;
    bool estLettreCorrecte(char lettre, int position) const;

  public:
    enum Couleur
    {
        Rouge = 0,
        Vert,
        Jaune
    };

    Wordle();
    ~Wordle();

    void               demarrerPartie();
    const std::string& getMotADeviner() const;
    const std::string& getMotEntre() const;
    bool               setMotEntre(const std::string& motSaisi);

    std::string convertirCouleurEnString(Couleur couleur);
};

#endif
