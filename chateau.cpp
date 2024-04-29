#include "Chateau.h"

/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

Chateau::Chateau(int x, int y) : Pion(x, y, 20) { 
    puiss = 0;
    depl = 0;   // Château ne se déplace pas
    prod = 2;
    cout = 15;   // Coût en or pour produire (supposé)
}

void Chateau::produirePion() {
    // Logique pr produire un nouveau pion
}

void Chateau::genererOr() {
    // Logique pr générer de l'or
}

void Chateau::deplacer(int newX, int newY) {}
