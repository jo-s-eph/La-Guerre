#pragma once
#include "pion.h"

class JeuInterface {
public:
    virtual void placerPion(Pion* pion, int x, int y) = 0;
    virtual void supprimerPion(int x, int y) = 0;
    virtual void deplacerPion(int x, int y, int newx, int newy) = 0;
    virtual ~JeuInterface() {}
};