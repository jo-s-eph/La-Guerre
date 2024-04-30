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
    friend class Joueur;
    void initialiserPlateau();
    std::vector<std::vector<Pion*>> plateau;
    Joueur Joueur1;
    Joueur Joueur2;
    int nbtour;
    Chateau* C1;
    Chateau* C2;
}; 