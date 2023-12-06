#include "Wordle.h"
#include "Joueur.h"
#include "IHMPartie.h"

#define TAILLE_MAX_MOT 5

#ifdef DEBUG_WORDLE
#include <iostream>
#endif

Wordle::Wordle() : joueur(new Joueur), ihmPartie(new IHMPartie(this))
{
#ifdef DEBUG_WORDLE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "joueur = " << joueur << std::endl;
#endif
}

Wordle::~Wordle()
{
    delete joueur;
    delete ihmPartie;
#ifdef DEBUG_WORDLE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << std::endl;
#endif
}

void Wordle::demarrerPartie()
{
    initialiserPartie();
}

const std::string& Wordle::getMotADeviner() const
{
    return motADeviner;
}

const std::string& Wordle::getMotEntre() const
{
    return motEntre;
}

bool Wordle::setMotEntre(const std::string& mot)
{
    if(!dictionnaire.estMotValable(mot))
    {
        return false; // @fixme Utiliser des codes d'erreur de retour
    }
    if(mot.size() != TAILLE_MAX_MOT)
    {
        return false; // @fixme Utiliser des codes d'erreur
    }
    if(!dictionnaire.estMotDejaPropose(mot))
    {
        return false; // @fixme Utiliser des codes d'erreur
    }

    motEntre = mot;

    return true;
}

void Wordle::initialiserPartie()
{
    motADeviner = dictionnaire.getMotAleatoire();
}

bool Wordle::estMotCorrect() const
{
    return motEntre == motADeviner;
}

bool Wordle::estLettreCorrecte(char lettre, int position) const
{
    return motADeviner[position] == lettre;
}

std::string Wordle::convertirCouleurEnString(Couleur couleur)
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
