#include "pion.h"

Pion::Pion(int x, int y, int pv) : x(x), y(y), pv(pv) {}

void Pion::deplacer(int newX, int newY) {
    x = newX;
    y = newY;
}

void Pion::attaquer(Pion& cible) {
    cible.pv -= this->puiss ; 
}

int Pion::getX() const { return x; }
int Pion::getY() const { return y; }
int Pion::getPv() const { return pv; }

/*
Un guerrier peut se déplacer et attaquer.
*/

Guerrier::Guerrier(int x, int y) : Pion(x, y, 10) { 
    icon = 'G';
    puiss = 5;
    depl = 3;
    prod = 0;   // Guerrier ne produit rien
    cout = 10;
}

/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

Chateau::Chateau(int x, int y) : Pion(x, y, 20) { 
    icon = 'C';
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

/*
Un paysan peut se déplacer ou produire des ressources.
*/

Paysan::Paysan(int x, int y) : Pion(x, y, 1) { 
    icon = 'P';
    puiss = 0;
    depl = 2;
    prod = 5;
    cout = 20;
}

void Paysan::genererOr() {
    // Logique pr générer de l'or
}

/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans ce
cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/

Seigneur::Seigneur(int x, int y) : Pion(x, y, 5) { 
    icon = 'S';
    puiss = 3;
    depl = 1;
    prod = 0;
    cout = 10;
}

void Seigneur::transformation() {
    // Logique pr se transformer en chateau
}