#include "Wordle.h"

void Wordle::demarrerPartie()
{
}

const std::string& Wordle::getMotAdeviner() const
{
    return motADeviner;
}

const std::string& Wordle::getMotEntre() const
{
    return motEntre;
}

void Wordle::setMotEntre(const std::string& mot)
{
    motEntre = mot;
}

std::string Wordle::couleurToString(Couleur couleur)
{
    switch(couleur)
    {
        case Rouge:
            return "Rouge";
        case Vert:
            return "Vert";
        case Jaune:
            return "Jaune";
        default:
            return "Inconnu";
    }
}
