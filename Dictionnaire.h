#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
#include <string>

#define DEBUG_DICTIONNAIRE

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;
    std::vector<std::string> listeThemes;

  public:
    Dictionnaire();

    std::string              getMotAleatoire() const;
    void                     chargerMotsDepuisFichier(const std::string& nomFichier);
    std::vector<std::string> getListeMots() const;
    std::vector<std::string> getListeThemes() const;
    void                     chargerThemes();
};

#endif