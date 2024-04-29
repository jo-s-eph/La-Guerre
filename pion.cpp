#include "pion.h"

Pion::Pion(int x, int y, int pv) : x(x), y(y), pv(pv) {}

void Pion::deplacer(int newX, int newY) {
    x = newX;
    y = newY;
}

void Pion::attaquer(Pion& cible) {
    cible.pv -= 5; 
}

int Pion::getX() const { return x; }
int Pion::getY() const { return y; }
int Pion::getPv() const { return pv; }