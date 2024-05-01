#include "jeu.h"
#include <iostream>
#include <iomanip> // std::setw

#define TAILLE 20
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREY    "\033[90m"

Jeu::Jeu() : rouge(1, 20, "Rouge"), bleu(0, 20, "Bleu") {
    initialiserPlateau();
}

void Jeu::initialiserPlateau() {
    plateau.resize(TAILLE, std::vector<Pion*>(TAILLE, nullptr));

    Chateau* chateauRouge = new Chateau(1, 1, 1);
    Paysan* paysanRouge = new Paysan(6, 6, 1);
    rouge.ajouterPion(chateauRouge);
    rouge.ajouterPion(paysanRouge);
    plateau[1][1] = chateauRouge;
    plateau[6][6] = paysanRouge;

    Chateau* chateauBleu = new Chateau(15, 15, 0);
    Paysan* paysanBleu = new Paysan(16, 16, 0);
    bleu.ajouterPion(chateauBleu);
    bleu.ajouterPion(paysanBleu);
    plateau[15][15] = chateauBleu;
    plateau[16][16] = paysanBleu;
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