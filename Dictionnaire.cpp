#include "Dictionnaire.h"
#include <algorithm> // find

using namespace std;

Dictionnaire::Dictionnaire()
{
    listeMots = { "chat", "chien", "oiseau", "maison", "ordinateur" };
    std::srand(static_cast<unsigned>(time(nullptr)));
}

std::string Dictionnaire::getMotAleatoire() const
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}
