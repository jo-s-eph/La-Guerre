#pragma once
#include <vector>
#include <iostream>

class Pion;
class Joueur;

class JeuInterface {
public:
    virtual void afficherEtatJeu() = 0;
    virtual void afficherGrille() = 0;
    virtual void afficherOr() = 0;
    virtual void afficherDepl(const std::vector<std::pair<int, int>>& cases) = 0;

    virtual void placerPion(Pion* pion, int x, int y) = 0;
    virtual void supprimerPion(int x, int y) = 0;
    virtual void deplacerPion(int x, int y, int newx, int newy) = 0;
    virtual Pion* getPion(int x, int y) = 0;
    virtual Joueur* getJoueur1() = 0;
    virtual Joueur* getJoueur2() = 0;

    virtual bool estOccupee(int x, int y) = 0;
    virtual ~JeuInterface() {}
};