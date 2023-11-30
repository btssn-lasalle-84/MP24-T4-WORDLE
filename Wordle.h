#ifndef WORDLE_H
#define WORDLE_H

#include "Dictionnaire.h"
#include <string>

class Wordle
{
  private:
    std::string motADeviner;
    std::string motEntre;

  public:
    enum Couleur
    {
        Rouge,
        Vert,
        Jaune
    };

    void demarrerPartie();

    const std::string& getMotAdeviner() const;
    const std::string& getMotEntre() const;
    void               setMotEntre(const std::string& mot);

    std::string couleurToString(Couleur couleur);
};

#endif
