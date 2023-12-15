#include "Wordle.h"
#include "Joueur.h"
#include "IHMPartie.h"

#ifdef DEBUG_WORDLE
#include <iostream>
#endif

Wordle::Wordle() :
    joueur(new Joueur), ihmPartie(new IHMPartie(this)),
    analyseMot(TAILLE_MAX_MOT, EtatAnalyse::ABSENTE_ROUGE)
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
        if(motSaisi.size() != TAILLE_MAX_MOT)
        {
            std::cerr << "Erreur : La taille du mot doit être exactement de " << TAILLE_MAX_MOT
                      << " lettres." << std::endl;
            continue;
        }
        if(motsDejaSaisis.find(motSaisi) != motsDejaSaisis.end())
        {
            std::cerr << "Erreur : Ce mot a déjà été saisi auparavant." << std::endl;
            continue;
        }

        if(setMotEntre(motSaisi))
        {
            analyserMot();
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

void Wordle::analyserMot()
{
    if(motADeviner.size() != motEntre.size() || motADeviner.size() != TAILLE_MAX_MOT)
    {
#ifdef DEBUG_WORDLE
        std::cerr << "Erreur : problème de taille !" << std::endl;
#endif
        return;
    }

#ifdef DEBUG_WORDLE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "motADeviner = " << motADeviner << " - motEntre = " << motEntre << std::endl;
#endif
    // Mise des états 2 à 0 dans le vecteur analyseMot
    for(size_t i = 0; i < motADeviner.size(); ++i)
    {
        if(analyseMot[i] == EtatAnalyse::MAL_PLACE_JAUNE)
        {
            analyseMot[i] = EtatAnalyse::ABSENTE_ROUGE;
        }
    }
    // Mise des états 1 à 0 dans le vecteur analyseMot
    for(size_t i = 0; i < motADeviner.size(); ++i)
    {
        if(analyseMot[i] == EtatAnalyse::BIEN_PLACE_VERT)
        {
            analyseMot[i] = EtatAnalyse::ABSENTE_ROUGE;
        }
    }
    // Recherche des lettres présentes dans le mot au bon endroit (BIEN_PLACE)
    for(size_t i = 0; i < motADeviner.size(); ++i)
    {
        if(motADeviner[i] == motEntre[i] && analyseMot[i] == EtatAnalyse::ABSENTE_ROUGE)
        {
            analyseMot[i] = EtatAnalyse::BIEN_PLACE_VERT;
        }
    }

    // Recherche des lettres présentes dans le mot mais au mauvais endroit (MAL_PLACE)
    for(size_t i = 0; i < motEntre.size(); ++i)
    {
        if(analyseMot[i] == EtatAnalyse::ABSENTE_ROUGE)
        {
            for(size_t j = 0; j < motADeviner.size(); ++j)
            {
                if(i != j && motEntre[i] == motADeviner[j])
                {
                    analyseMot[i] = EtatAnalyse::MAL_PLACE_JAUNE;
                    break;
                }
            }
        }
    }

#ifdef DEBUG_WORDLE
    std::cout << "[" << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__ << "] "
              << "analyseMot = " << std::endl;
    for(size_t i = 0; i < analyseMot.size(); ++i)
        std::cout << analyseMot[i] << " ";
    std::cout << std::endl;
#endif
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

std::string Wordle::convertirCouleurEnString(EtatAnalyse etat)
{
    switch(etat)
    {
        case EtatAnalyse::ABSENTE_ROUGE:
            return "Rouge";
        case EtatAnalyse::BIEN_PLACE_VERT:
            return "Vert";
        case EtatAnalyse::MAL_PLACE_JAUNE:
            return "Jaune";
        default:
            return "Inconnu";
    }
}

std::string Wordle::convertirEtatEnString(EtatAnalyse etat)
{
    switch(etat)
    {
        case EtatAnalyse::ABSENTE_ROUGE:
            return "Absente";
        case EtatAnalyse::BIEN_PLACE_VERT:
            return "Bien placée";
        case EtatAnalyse::MAL_PLACE_JAUNE:
            return "Mal placée";
        default:
            return "Inconnu";
    }
}
