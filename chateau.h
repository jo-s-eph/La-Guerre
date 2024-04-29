#pragma once   
#include "pion.h"

/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

class Chateau : public Pion {   
    // Déclaration de la classe Chateau héritant de Pion
public:
    Chateau(int x, int y);
    void produirePion();    // Méthode spé à Chateau
    void genererOr();       // Méthode spé à Chateau
    virtual void deplacer(int newX, int newY) override;
};