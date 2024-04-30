#include "pion.h"
#include "joueur.h"
#include <vector>

class Jeu {
public:
    Jeu();
    void demarrer();
    void afficherEtatJeu();
    void placerPion(Pion* pion, int x, int y);
    void supprimerPion(int x, int y);
    void deplacerPion(int x, int y, int newx, int newy);

private:
    void initialiserPlateau();
    friend class Joueur;
    std::vector<std::vector<Pion*>> plateau;
    Joueur Joueur1;
    Joueur Joueur2;
}; 