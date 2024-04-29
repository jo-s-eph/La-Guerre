#pragma once   // Prévient les inclusions multiples
#include <string>

class Pion {
public:
    Pion(int x, int y, int pv);

    virtual ~Pion() = default;
    virtual void deplacer(int newX, int newY);
    virtual void attaquer(Pion& cible);
    
    int getX() const;
    int getY() const;
    int getPv() const;
    
protected:
    int x, y;   // Coordonnées du pion
    int pv;     // Point de vie du pion
    int puiss;  // Nb de points de vie enlevé à la cible lors d’une attaque du pion
    int depl;   // Nb maximum de cases parcourues par le pion à chaque tour
    int prod;   // Qté d’or produite par le pion (lors d’une action pour un paysan)/
    int cout;   // Coût en or pour construire un pion de ce type.
};