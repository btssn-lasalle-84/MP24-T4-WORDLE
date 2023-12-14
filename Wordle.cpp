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

    int tentative = INCREMENTATION_TENTATIVES;
    while(tentative <= NB_TENTATIVES_MAX)
    {
        std::string motSaisi = ihmPartie->saisirMot();
    if (motSaisi.size() != TAILLE_MAX_MOT)
    {
        std::cerr << "Erreur : La taille du mot doit être exactement de " << TAILLE_MAX_MOT << " lettres." << std::endl;
        continue;
    }
        if(motsDejaSaisis.find(motSaisi) != motsDejaSaisis.end())
        {
            std::cerr << "Erreur : Ce mot a déjà été saisi auparavant." << std::endl;
            continue;
        }

        if(setMotEntre(motSaisi))
        {
            motsDejaSaisis.insert(motSaisi);
            joueur->proposerMot(motSaisi);
            joueur->incrementerTentatives();

            if(estMotCorrect())
            {
#ifdef DEBUG_WORDLE
                std::cout << "Félicitations ! Vous avez deviné le mot." << std::endl;
#endif
                break;
            }
        }
        else
        {
        }
        ++tentative;
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
