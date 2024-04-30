#pragma once
#include <vector>
#include "pion.h"

class Joueur {
public:
    Joueur(int id, int gold, const std::string& nom);
    void deplacerPion(Pion* pion, int x, int y);
    void produirePion(Pion* chateau, PionType type);
    void attaquer(Pion* attaquant, Pion* cible);
    std::string getNom() const;
    int getOr() const;
    void ajouterOr(int montant);

private:
    int id;
    int gold;
    std::string nom; 
    // std::vector<Pion*> pions;  // Liste des pions contrôlés par le joueur
};
