#ifndef WORDLE_H
#define WORDLE_H

#include "Dictionnaire.h"
#include <string>
#include <vector>
#include <set>

#define TAILLE_MAX_MOT 5
#define DEBUG_WORDLE

class Joueur;
class IHMPartie;

class Wordle
{
  public:
    enum EtatAnalyse // Couleur
    {
        // VERT : la lettre est dans le mot et au bon endroit (BIEN_PLACE)
        // JAUNE : la lettre est dans le mot mais au mauvais endroit (MAL_PLACE)
        // ROUGE : (facultatif) : la lettre n’est dans le mot à aucun endroit (ABSENTE)
        ABSENTE_ROUGE = 0,
        BIEN_PLACE_VERT,
        MAL_PLACE_JAUNE
    };

  private:
    std::string              motADeviner;
    std::string              motEntre;
    Joueur*                  joueur;
    IHMPartie*               ihmPartie;
    Dictionnaire             dictionnaire;
    std::vector<EtatAnalyse> analyseMot;

    std::set<std::string> motsDejaSaisis;

    void initialiserPartie();
    bool estLettreCorrecte(char lettre, int position) const;

  public:
    Wordle();
    ~Wordle();

    void               demarrerPartie();
    void               analyserMot();
    const std::string& getMotADeviner() const;
    const std::string& getMotEntre() const;
    bool               setMotEntre(const std::string& motSaisi);
    std::string        mettreLettreEnCouleurSelonEtat() const;
    void               afficherInformationsPartie();
    std::string        saisirMot();
    bool               verifierSaisieMot(const std::string& mot);
    void               traiterMotEntre();
    void               gererFinPartie(int tentative);
    void               afficherMessageVictoire();
    bool               saisirChoixMenu();
    bool               verifierTailleMot(const std::string& mot);
    bool               verifierMotDejaSaisi(const std::string& mot);
    std::vector<std::string> getHistoriqueParties() const;
    bool estMotCorrect() const;


};

#endif