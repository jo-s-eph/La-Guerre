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

void Jeu::afficherEtatJeu() {
    std::cout << "\n";
    for (int i = 0; i < TAILLE; ++i) {
        std::cout << TAILLE - i << "\t"; // display X coord on the left
        for (int j = 0; j < TAILLE; ++j) {
            if (plateau[i][j] != nullptr) {
                if (plateau[i][j]->getColor())
                    std::cout << RED << plateau[i][j]->getIcon() << " " << RESET;
                else
                    std::cout << BLUE << plateau[i][j]->getIcon() << " " << RESET;                
            } else {
                std::cout << GREY << "- " << RESET;
            }
            if (j < TAILLE - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\t";
    for (int j = 0; j < TAILLE; ++j) {
        std::cout << j+1 << " ";
        if (j+1 < 9)
        {
             std::cout << " ";
        }
    }
    std::cout << std::endl;
}

// void Jeu::afficherEtatJeu() {
//     for (int i = 0; i < TAILLE; ++i) {
//         // std::cout << TAILLE - i << "\t"; // display X coord on the left
//         std::cout << std::setw(2) << TAILLE - i << "\t"; // Use setw to align
//         for (int j = 0; j < TAILLE; ++j) {
//             if (plateau[i][j] != nullptr) {
//                 if (plateau[i][j]->getColor())
//                     std::cout << RED << plateau[i][j]->getIcon() << RESET;
//                 else
//                     std::cout << BLUE << plateau[i][j]->getIcon() << RESET ;                
//             } else {
//                 std::cout << GREY << "-" << RESET;
//             }
//             std::cout << " "; // Uniform spacing
//             // if (j < TAILLE - 1) {
//             //     std::cout << " ";
//             // }
//         }
//         std::cout << std::endl;
//     }
//     // std::cout << "\t"; // display Y at the bottom of the grid
//     std::cout << std::setw(3) << " "; // Adjust setw to align with your rows
//     for (int j = 0; j < TAILLE; ++j) {
//         if (j < 9) {
//             // Single digit numbers
//             std::cout << j + 1 << "  "; // Two spaces after single digit
//         } else {
//             // Double-digit numbers
//             std::cout << j + 1 << " "; // One space after double digits
//         }
//     }
//     std::cout << std::endl;
// }