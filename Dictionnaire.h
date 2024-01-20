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
    void chargerMotsDepuisFichier(const std::string& nomFichier);
    const std::vector<std::string> &getListeMots() const;

};

#endif