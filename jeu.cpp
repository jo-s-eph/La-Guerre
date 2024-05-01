#include "jeu.h"


Jeu::Jeu() : Joueur1(1, 20, "Rouge"), Joueur2(0, 20, "Bleu") {
    initialiserPlateau();
}

void Jeu::initialiserPlateau() {
    plateau.resize(TAILLE, std::vector<Pion*>(TAILLE, nullptr));

    Chateau* chateauRouge = new Chateau(1,*this);
    Paysan* paysanRouge = new Paysan(1,*this);
    Guerrier* guerrierRouge = new Guerrier(1,*this);
    placerPion(chateauRouge,1,1);
    placerPion(paysanRouge,2,2);

    Chateau* chateauBleu = new Chateau(0,*this);
    Paysan* paysanBleu = new Paysan(0,*this);
    placerPion(chateauBleu,20,20);
    placerPion(paysanBleu,19,19);
    deplacerPion(19,19,3,13);
    placerPion(guerrierRouge,2,16);
    guerrierRouge->deplacer(7,7);
    afficherEtatJeu();
    guerrierRouge->attaquer();
}

void Jeu::demarrer() {
    while (true) {
        afficherEtatJeu();
    }
}
Pion* Jeu::getPion(int x, int y){
    return plateau[x - 1][y - 1];
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

bool Jeu::estOccupee(int x, int y) {
    // std::cout << "Comp (" << x << "," << y << ")" << std::endl;   DEBUG
    return (plateau[x - 1][y - 1] != nullptr);
}
void Jeu::afficherEtatJeu() {
    afficherOr();
    afficherGrille();
}
void Jeu::afficherOr()
{
    // Afficher l'or de chaque joueur
    std::cout << YELLOW << "\n\tJoueur 1 (" << Joueur1.getNom() << ") : " << Joueur1.getOr() << " ◉";
    std::cout << "\t\tJoueur 2 (" << Joueur2.getNom() << ") : " << Joueur2.getOr() << " ◉";

}

void Jeu::afficherGrille()
{
        // Afficher la grille
    std::cout << RESET << "\n\n";
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

void Jeu::afficherDepl(const std::vector<std::pair<int, int>>& cases)
{
        // Afficher la grille avec les déplacements passés en param
    std::cout << RESET << "\n\n";
    for (int i = TAILLE - 1; i >= 0; --i) {
        std::cout << i + 1 << "\t";
        for (int j = 0; j < TAILLE; ++j) {
            if (plateau[j][i] != nullptr) {
                if (plateau[j][i]->getColor())
                {
                    std::cout << RED << plateau[j][i]->getIcon() << " " << RESET;
                }
                else
                {
                    std::cout << BLUE << plateau[j][i]->getIcon() << " " << RESET;                
                }
            } 
            else {
                if (std::find(cases.begin(), cases.end(), std::make_pair(j + 1, i + 1)) != cases.end())
                    std::cout << GREEN << "◼︎ " << RESET;
                else
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