#ifndef JOUEUR_H
#define JOUEUR_H

#pragma once
#include <vector>
#include "pion.h"

class Joueur {
public:
    Joueur(int id, int gold, const std::string& nom);

    std::string getNom() const;
    int getOr() const;
    int getId() const;
    void addOr(int montant);
    int getNbChateau() const;
    void addNbChateau(int montant);

protected:
    int nbchateau = 0;
    int id;
    int gold;
    std::string nom; 
};

#endif // JOUEUR_H