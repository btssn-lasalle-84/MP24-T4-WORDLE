#include "Partie.h"
#include "Joueur.h"

int main()
{
    Joueur joueur1("Joueur1");

    std::vector<Joueur> joueurs = { joueur1, joueur2 };
    Partie              partie(joueurs);

    partie.demarrerPartie();

    return 0;
}
