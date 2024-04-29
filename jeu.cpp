#include "jeu.h"
#include <iostream>

int taille = 20;

Jeu::Jeu() {
    initialiserPlateau();
}

void Jeu::initialiserPlateau() {
    // Initialisation du plateau avec des pions et des cases vides
}

void Jeu::demarrer() {
    while (true) {
        afficherEtatJeu();
        // Logique de jeu
    }
}

void Jeu::afficherEtatJeu() {
    // for (auto& ligne : plateau) {
    //     for (auto pion : ligne) {
    //         if (pion) std::cout << pion->getSymbol() << " ";
    //         else std::cout << "- ";
    //     }
    //     std::cout << std::endl;
    // }
}
