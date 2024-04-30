#include "pion.h"
#include "joueur.h"
#include <vector>

class Jeu {
public:
    Jeu();
    void demarrer();
    void afficherEtatJeu();

private:
    std::vector<std::vector<Pion*>> plateau;
    Joueur rouge;
    Joueur bleu;
    void initialiserPlateau();
};