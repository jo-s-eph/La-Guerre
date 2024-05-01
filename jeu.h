#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include "joueur.h"
#include "pion.h"

class Jeu {
public:
    Jeu();
    void demarrer();
    void afficherEtatJeu();
    void placerPion(Pion* pion, int x, int y);
    void supprimerPion(int x, int y);
    void deplacerPion(int x, int y, int newx, int newy);

private:
    std::vector<std::vector<Pion*>> plateau;
    Joueur rouge;
    Joueur bleu;
    void initialiserPlateau();
};