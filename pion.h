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
    char icon;  // Lettre Représentant le pion
    int puiss;  // Nb de points de vie enlevé à la cible lors d’une attaque du pion
    int depl;   // Nb maximum de cases parcourues par le pion à chaque tour
    int prod;   // Qté d’or produite par le pion (lors d’une action pour un paysan)/
    int cout;   // Coût en or pour construire un pion de ce type.
};

/*
Un guerrier peut se déplacer et attaquer.
*/

class Guerrier : public Pion {   
    // Déclaration de la classe Guerrier héritant de Pion
public:
    Guerrier(int x, int y);
    // virtual void deplacer(int newX, int newY) override;
};

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
    // virtual void deplacer(int newX, int newY) override;
};

/*
Un paysan peut se déplacer ou produire des ressources.
*/

class Paysan : public Pion {   
    // Déclaration de la classe Paysan héritant de Pion
public:
    Paysan(int x, int y);
    void genererOr();       // Méthode spé à Paysan
    // virtual void deplacer(int newX, int newY) override;
};

/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans ce
cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/

class Seigneur : public Pion {   
    // Déclaration de la classe Guerrier héritant de Pion
public:
    Seigneur(int x, int y);
    void transformation();       // Méthode spé à Seigneur
};