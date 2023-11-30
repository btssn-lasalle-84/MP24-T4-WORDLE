#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
#include <string>

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;

  public:
    Dictionnaire();

    std::string getMotAleatoire();
    bool        estMotValide(const std::string& mot); // TODO
};

#endif