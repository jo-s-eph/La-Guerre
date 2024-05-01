#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include "joueur.h"
#include "pion.h"
#include "utils.h"
#include "interface.h"


class Jeu : public JeuInterface {
public:
    Jeu();
    void demarrer();

    void afficherEtatJeu();
    void afficherGrille();
    void afficherDepl(const std::vector<std::pair<int, int>>& cases);
    void afficherOr();

    void placerPion(Pion* pion, int x, int y);
    void supprimerPion(int x, int y);
    void deplacerPion(int x, int y, int newx, int newy);
    Pion* getPion(int x, int y);

    bool estOccupee(int x, int y);

private:
    void initialiserPlateau();
    friend class Joueur;
    std::vector<std::vector<Pion*>> plateau;
    Joueur Joueur1;
    Joueur Joueur2;
};

#endif // JEU_H