#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
#include <string>

#define DEBUG_DICTIONNAIRE

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;

  public:
    Dictionnaire();

    std::string getMotAleatoire() const;
    bool        estMotValable(const std::string& mot) const;
    bool        estMotDejaPropose(const std::string& mot) const;
};

#endif