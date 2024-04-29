#pragma once
#include <vector>
#include "Pion.h"

class Joueur {
public:
    Joueur(int id, const std::string& nom);
    void ajouterPion(Pion* pion);
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
    std::vector<Pion*> pions;  // Liste des pions contrôlés par le joueur
};
