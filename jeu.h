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
    Joueur* getJoueur1();
    Joueur* getJoueur2();

    bool estOccupee(int x, int y);
    std::vector<std::vector<Pion*>> plateau;

private:
    Joueur Joueur1;
    Joueur Joueur2;
    void initialiserPlateau();
    friend class Joueur;
};

#endif // JEU_H