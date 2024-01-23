#include "Wordle.h"
#include "IHMPartie.h"
#include "Joueur.h"
#include <algorithm>

#ifdef DEBUG_WORDLE
#include <iostream>
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
    initialiserPartie();

    int tentative = INCREMENTATION_TENTATIVES;
    while(tentative <= NB_TENTATIVES_MAX)
    {
        std::string motSaisi = saisirMot();
        if(verifierSaisieMot(motSaisi))
        {
            continue;
        }

        if(setMotEntre(motSaisi))
        {
            traiterMotEntre();
            if(estMotCorrect())
            {
                ihmPartie->afficherMessageVictoire(joueur->getNbTentatives());
                break;
            }
        }
        else
        {
            return;
        }

        ++tentative;
    }
    gererFinPartie(tentative);
    ihmPartie->afficherMenuFin();
    gererMenu();
}

void Wordle::initialiserPartie()
{
    joueur->reinitialiserJeu();
    motsDejaSaisis.clear();
    ihmPartie->afficherInformationsPartie();
    int numeroThemeChoisi = ihmPartie->choisirTheme(dictionnaire.getNomsThemes());
    dictionnaire.chargerMots(numeroThemeChoisi);
    motADeviner = dictionnaire.getMotAleatoire();
}

std::string Wordle::saisirMot()
{
    return ihmPartie->saisirMot();
}

bool Wordle::verifierSaisieMot(const std::string& mot)
{
    if(verifierTailleMot(mot) || verifierMotDejaSaisi(mot))
    {
        return true;
    }
    return false;
}

bool Wordle::verifierTailleMot(const std::string& mot)
{
    if(mot.size() != TAILLE_MAX_MOT)
    {
        ihmPartie->afficherErreur("Le mot doit être exactement de " +
                                  std::to_string(TAILLE_MAX_MOT) + " lettres.");
        return true;
    }
    return false;
}

bool Wordle::verifierMotDejaSaisi(const std::string& mot)
{
    if(motsDejaSaisis.find(mot) != motsDejaSaisis.end())
    {
        ihmPartie->afficherErreur("Ce mot a déjà été saisi auparavant.");
        return true;
    }
    return false;
}

void Wordle::traiterMotEntre()
{
    analyserMot();
    motsDejaSaisis.insert(motEntre);
    joueur->proposerMot(motEntre);
    joueur->incrementerTentatives();
    ihmPartie->afficherLettreEnCouleurSelonEtat();
    ihmPartie->afficherTentatives(joueur->getMotsProposes());
}

void Wordle::gererFinPartie(int tentative)
{
    if(tentative > NB_TENTATIVES_MAX)
    {
        ihmPartie->afficherMessageDefaite();
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

    // Initialise le vecteur analyseMot
    for(size_t i = 0; i < motADeviner.size(); ++i)
    {
        analyseMot[i] = EtatAnalyse::ABSENTE_ROUGE;
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

bool Wordle::setMotEntre(const std::string& motSaisi)
{
    if(motSaisi.size() != TAILLE_MAX_MOT)
    {
#ifdef DEBUG_WORDLE
        std::cerr << "Erreur : La taille du mot n'est pas conforme." << std::endl;
#endif
        return false;
    }

    motEntre = motSaisi;

    std::transform(motSaisi.begin(), motSaisi.end(), motEntre.begin(), ::tolower);

    return true;
}

bool Wordle::estMotCorrect() const
{
    return motEntre == motADeviner;
}

std::string Wordle::mettreLettreEnCouleurSelonEtat() const
{
    std::string resultat;

    for(size_t i = 0; i < motEntre.size(); ++i)
    {
        char        lettre = std::toupper(motEntre[i]);
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

bool Wordle::gererMenu()
{
    int choix = ihmPartie->choisirMenu();

    switch(choix)
    {
        case IHMPartie::EntreeMenu::JOUER_PARTIE:
            demarrerPartie();
            break;
        case IHMPartie::EntreeMenu::AFFICHER_HISTORIQUE:
            ihmPartie->afficherHistoriqueParties();
            break;
        case IHMPartie::EntreeMenu::QUITTER:
            return false;
        default:
            ihmPartie->afficherErreur("Choix invalide.");
            break;
    }

    return true;
}

std::vector<std::string> Wordle::getHistoriqueParties() const
{
    return joueur->getMotsProposes();
}

std::string Wordle::getVersion() const
{
    return VERSION;
}
