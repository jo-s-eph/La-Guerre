#include "pion.h"

void Pion::deplacer(int newX, int newY) {
    x = newX;
    y = newY;
}

void Pion::attaquer(Pion& cible) {
    cible.pv -= this->puiss ; 
}

int Pion::getX() const { return x; }
void Pion::setX(int newx) { this->x = newx; }
int Pion::getY() const { return y; }
void Pion::setY(int newy) { this->y = newy; }
char Pion::getIcon() const { return icon; }
int Pion::getPv() const { return pv; }
int Pion::getColor() const { return color; }

/*
Un guerrier peut se déplacer et attaquer.
*/

Guerrier::Guerrier(int couleur, Jeu* j) : Pion(couleur, j) {
    icon = 'G';
    puiss = 5;
    depl = 3;
    pv = 10;
    prod = 0;
    cout = 10;
    color = couleur;
    jeu = j;
}
/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

Chateau::Chateau(int couleur, Jeu* j) : Pion(couleur, j) { 
    icon = 'C';
    puiss = 0;
    depl = 0;   // Château ne se déplace pas
    prod = 2;
    cout = 15;   // Coût en or pour produire (supposé)
    pv = 20;
    color = couleur;
    jeu = j;
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

Paysan::Paysan(int couleur, Jeu* j) : Pion(couleur, j) { 
    icon = 'P';
    puiss = 0;
    depl = 2;
    prod = 5;
    cout = 20;
    pv = 1;
    color = couleur;
    jeu = j;
}

void Paysan::genererOr() {
    // Logique pr générer de l'or
}

/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans ce
cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/

Seigneur::Seigneur(int couleur, Jeu* j) : Pion(couleur, j) { 
    icon = 'S';
    puiss = 3;
    depl = 1;
    prod = 0;
    cout = 10;
    pv = 5;
    color = couleur;
    jeu = j;
}

void Seigneur::transformation() {
    // Logique pr se transformer en chateau
}