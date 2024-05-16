#ifndef PION_H
#define PION_H

#include "utils.h"
#include "interface.h"
#include "joueur.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Jeu;

enum class PionType {
    Chateau,
    Seigneur,
    Guerrier,
    Paysan
};

class Pion {
public:
    Pion(int couleur, JeuInterface& j) : color(couleur), jeu(j) {}
    virtual ~Pion() = default;
    virtual int deplacer();
    virtual int attaquer();
    virtual int genererOr();       // Méthode spé à Chateau
    
    int getX() const;
    int getY() const;
    void setX(int newx);
    void setY(int newy);
    void addPv(int newpv);
    int getPv() const;
    int getColor() const;
    char getIcon() const;
    bool ordre;             // Savoir si un ordre a déjà été donné au pion 
    
protected:
    int x, y;               // Coordonnées du pion
    int pv;                 // Point de vie du pion
    char icon;              // Lettre Représentant le pion
    int color;              // 1 = rouge, 0 = bleu
    int puiss;              // Nb de points de vie enlevé à la cible lors d’une attaque du pion
    int depl;               // Nb maximum de cases parcourues par le pion à chaque tour
    int prod;               // Qté d’or produite par le pion (lors d’une action pour un paysan)/
    int cout;               // Coût en or pour construire un pion de ce type.
    JeuInterface& jeu;      // Jeu dans lequel le pion est présent
};

/*
Un guerrier peut se déplacer et attaquer.
*/

class Guerrier : public Pion {   
public:
    Guerrier(int couleur, JeuInterface& j);
};

/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

class Chateau : public Pion {   
    // Déclaration de la classe Chateau héritant de Pion
public:
    Chateau(int couleur, JeuInterface& j);
    ~Chateau();
    int produirePion();    // Méthode spé à Chateau
};

/*
Un paysan peut se déplacer ou produire des ressources.
*/

class Paysan : public Pion {   
    // Déclaration de la classe Paysan héritant de Pion
public:
    Paysan(int couleur, JeuInterface& j);
};

/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans ce
cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/

class Seigneur : public Pion {   
    // Déclaration de la classe Guerrier héritant de Pion
public:
    Seigneur(int couleur, JeuInterface& j);
    int transformation();       // Méthode spé à Seigneur
};

#endif // PION_H