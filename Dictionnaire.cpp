#include "Dictionnaire.h"
#include <ctime>

Dictionnaire::Dictionnaire()
{
    listeMots = { "chat", "chien", "oiseau", "maison", "ordinateur" };
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string Dictionnaire::getMotAleatoire() const
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}
