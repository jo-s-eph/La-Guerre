#include "pion.h"
#include <vector>

class Jeu {
public:
    Jeu();
    void demarrer();
    void afficherEtatJeu();

private:
    std::vector<std::vector<Pion*>> plateau;
    void initialiserPlateau();
};