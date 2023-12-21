#include "Wordle.h"
#include "IHMPartie.h"
#include "Joueur.h"

#ifdef DEBUG_WORDLE
#include <iostream>
#include <algorithm> // Add this include for std::transform

#endif

Wordle::Wordle() :
    joueur(new Joueur), ihmPartie(new IHMPartie(this)),
    analyseMot(TAILLE_MAX_MOT, EtatAnalyse::ABSENTE_ROUGE)
{
}

Wordle::~Wordle()
{
    delete joueur;
    delete ihmPartie;
}

void Wordle::demarrerPartie()
{
    do
    {
        initialiserPartie();
        ihmPartie->afficherNomWordle();
        ihmPartie->afficherRegles();

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
                ihmPartie->afficherLettreEnCouleurSelonEtat();
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
    } while(ihmPartie->demanderContinuerPartie());
    ihmPartie->nbTentativesAtteint();
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

    // Recherche des lettres présentes dans le mot mais au mauvais endroit
    // (MAL_PLACE)
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

    std::transform(motSaisi.begin(), motSaisi.end(), motEntre.begin(), ::tolower);

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

std::string Wordle::mettreLettreEnCouleurSelonEtat() const
{
    std::string resultat;

    for(size_t i = 0; i < motEntre.size(); ++i)
    {
        char        lettre = motEntre[i];
        EtatAnalyse etat   = analyseMot[i];

        switch(etat)
        {
            case EtatAnalyse::ABSENTE_ROUGE:
                resultat += "\033[31m" + std::string(1, lettre) + "\033[0m"; // Rouge
                break;
            case EtatAnalyse::BIEN_PLACE_VERT:
                resultat += "\033[32m" + std::string(1, lettre) + "\033[0m"; // Vert
                break;
            case EtatAnalyse::MAL_PLACE_JAUNE:
                resultat += "\033[33m" + std::string(1, lettre) + "\033[0m"; // Jaune
                break;
            default:
                resultat += std::string(1, lettre);
                break;
        }
    }

    return resultat;
}
