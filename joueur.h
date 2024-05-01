#pragma once
#include <vector>
#include "pion.h"

class Joueur {
public:
    Joueur(int id, int gold, const std::string& nom);
    
    std::string getNom() const;
    int getOr() const;
    void addOr(int montant);

private:
    int id;
    int gold;
    std::string nom; 
};
