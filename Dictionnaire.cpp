#include "Dictionnaire.h"
#include <iostream>

using namespace std;

Dictionnaire::Dictionnaire()
{
    listeMots = { "chat", "chien", "oiseau", "maison", "ordinateur" };
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

std::string Dictionnaire::getMotAleatoire()
{
    int indiceAleatoire = std::rand() % listeMots.size();
    return listeMots[indiceAleatoire];
}
