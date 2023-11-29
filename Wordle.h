#include <iostream>

#define WORDLE_H

class Wordle
{
  private:
    std::string motADeviner() const;
    std::string motEntre() const;

  public:
    void jouer();
};