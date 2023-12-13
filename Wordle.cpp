#include "Wordle.h"
#include "Joueur.h"
#include "IHMPartie.h"

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
    ihmPartie->afficherAccueil();

    for(int i = 0; i < joueur->getTentativesMax(); ++i)
    {
        std::string motSaisi = ihmPartie->saisirMot();

        if(setMotEntre(motSaisi))
        {
            joueur->incrementerTentatives();
            joueur->proposerMot(motSaisi);

            if(estMotCorrect())
            {
#ifdef DEBUG_WORDLE
                std::cout << "Félicitations ! Vous avez deviné le mot." << std::endl;
#endif
                break;
            }
            else
            {
            }
        }
        else
        {
        }
    }
}

const std::string& Wordle::getMotADeviner() const
{
    return motADeviner;
}

const std::string& Wordle::getMotEntre() const
{
    return motEntre;
}

bool Wordle::setMotEntre(const std::string& motSaisi)
{
    if(motSaisi.size() != TAILLE_MAX_MOT)
    {
#ifdef DEBUG_WORDLE
        std::cerr << "Erreur : La taille du mot n'est pas conforme." << std::endl;
#endif
        return false; // @fixme Utiliser des codes d'erreur
    }

    motEntre = motSaisi;

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
