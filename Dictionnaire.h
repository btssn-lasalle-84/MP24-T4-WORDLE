#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <vector>
#include <string>

#define DEBUG_DICTIONNAIRE

#define CHEMIN_THEMES    "themes/"
#define EXTENSION_THEMES ".dic"

class Dictionnaire
{
  private:
    std::vector<std::string> listeMots;
    std::vector<std::string> listeThemes;

  public:
    Dictionnaire();

    std::string              getMotAleatoire() const;
    void                     chargerMots(int numeroThemeChoisi);
    std::vector<std::string> getListeMots() const;
    std::vector<std::string> getListeThemes() const;
    void                     chargerThemes();
    std::vector<std::string> getNomsThemes() const;
};

#endif