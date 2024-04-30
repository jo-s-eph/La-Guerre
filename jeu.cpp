#include "jeu.h"
#include <iostream>
#include "utils.h"


Jeu::Jeu() : Joueur1(1, 20, "Rouge"), Joueur2(0, 20, "Bleu"), nbtour(0) {
    initialiserPlateau();
}

void Jeu::initialiserPlateau() {
    plateau.resize(TAILLE, std::vector<Pion*>(TAILLE, nullptr));

    Chateau* chateauRouge = new Chateau(1);
    C1 = chateauRouge;
    Paysan* paysanRouge = new Paysan(1);
    placerPion(chateauRouge,10,1);
    placerPion(paysanRouge,11,1);

    Chateau* chateauBleu = new Chateau(0);
    C2 = chateauBleu;
    Paysan* paysanBleu = new Paysan(0);
    placerPion(chateauBleu,10,20);
    placerPion(paysanBleu,11,20);
}

void Jeu::demarrer() {
    while (true) {
        afficherEtatJeu();
        // Logique de jeu
    }
}

void Jeu::placerPion(Pion* pion, int x, int y){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
        std::cerr << "Erreur : Coordonnées hors du plateau." << std::endl;
        return;
    }
    if (plateau[x-1][y-1] != nullptr) {
        std::cerr << "Erreur : Case déjà occupée." << std::endl;
        return;
    }
    plateau[x - 1][y - 1] = pion;
    pion->setX(x);
    pion->setY(y);
}

void Jeu::supprimerPion(int x, int y){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
        std::cerr << "Erreur : Coordonnées hors du plateau." << std::endl;
        return;
    }
    if (plateau[x-1][y-1] == nullptr) {
        std::cerr << "Erreur : Pas de pion à supprimer." << std::endl;
        return;
    }
    // delete plateau[x-1][y-1];
    plateau[x-1][y-1] = nullptr;
}

void Jeu::deplacerPion(int x, int y, int newx, int newy){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE || newx < 1 || newx > TAILLE || newy < 1 || newy > TAILLE) {
        std::cerr << "Erreur : Coordonnées hors du plateau." << std::endl;
        return;
    }
    if (plateau[x-1][y-1] == nullptr) {
        std::cerr << "Erreur : Pas de pion à déplacer." << std::endl;
        return;
    }
    placerPion(plateau[x-1][y-1], newx, newy);
    supprimerPion(x, y);
}

void Jeu::afficherEtatJeu() {

    // Afficher l'or de chaque joueur
    std::cout << YELLOW << "\n\tJoueur 1 (" << Joueur1.getNom() << ") : " << Joueur1.getOr() << " ◉";
    std::cout << "\t\tJoueur 2 (" << Joueur2.getNom() << ") : " << Joueur2.getOr() << " ◉";

    std::cout << RESET << "\n\n";

    // Afficher la grille
    for (int i = TAILLE - 1; i >= 0; --i) {
        std::cout << i + 1 << "\t";
        for (int j = 0; j < TAILLE; ++j) {
            if (plateau[j][i] != nullptr) {
                if (plateau[j][i]->getColor())
                    std::cout << RED << plateau[j][i]->getIcon() << " " << RESET;
                else
                    std::cout << BLUE << plateau[j][i]->getIcon() << " " << RESET;                
            } else {
                std::cout << GREY << "☐ " << RESET;
            }
            if (j < TAILLE - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n\t";
    for (int j = 0; j < TAILLE; ++j) {
        std::cout << j + 1 << " ";
        if (j + 1 < 10)
            std::cout << " ";
    }
    std::cout << "\n" << std::endl;
}