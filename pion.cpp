#include "pion.h"

void Pion::deplacer(int newX, int newY) {
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE)
        std::cerr << "Erreur : Coordonnées hors du plateau." << std::endl;

    int userx, usery;
    std::vector<std::pair<int, int>> adjacentes;
    std::queue<std::pair<int, int>> queue;
    std::set<std::pair<int, int>> visited;

    queue.push({x, y});
    visited.insert({x, y});

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();

        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& dir : directions) {
            int nx = current.first + dir.first;
            int ny = current.second + dir.second;

            if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && !jeu.estOccupee(nx, ny) &&
                visited.find({nx, ny}) == visited.end() && manhattanDistance(x, y, nx, ny) <= depl) {
                
                queue.push({nx, ny});
                visited.insert({nx, ny});
                adjacentes.push_back({nx, ny});
            }
        }
    }

    jeu.afficherDepl(adjacentes);
    while (true) {
        std::cout << " ☞ Où souhaitez vous déplacer votre pion "<< this->getIcon() << " ? (x y): ";
        std::cin >> userx >> usery;
        if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
            std::cerr << " ✕ : Coordonnées hors du plateau, choissisez parmi les cases vertes." << std::endl;
        } else {
            if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end()) {
                std::cerr << " ✕ : Case inaccessible, choissisez parmi les cases vertes." << std::endl;
            } else {
                jeu.deplacerPion(x,y,userx,usery);
                std::cout << " ☞ Pion déplacé ! " << std::endl;
                jeu.afficherEtatJeu();
                return;
            }
        }
    }
}

void Pion::attaquer() {
    std::vector<std::pair<int, int>> adjacentes;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Haut, droite, bas, gauche
    int userx, usery;

    for (auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && jeu.estOccupee(nx, ny))
            adjacentes.push_back({nx, ny});
    }
    if (adjacentes.size() == 0)
    {
        std::cout << " ☞ Aucun pion proche à attaquer. " << std::endl;;
        jeu.afficherEtatJeu();
        return;
    }
    while (true) {
        std::cout << " ☞ Quel pion souhaitez-vous attaquer avec "<< this->getIcon() << " ? (x y): ";
        std::cin >> userx >> usery;
        if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
            std::cerr << " ✕ : Coordonnées hors du plateau" << std::endl;
        } else {
            if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end()) {
                std::cerr << " ✕ : Case inaccessible." << std::endl;
            } else {
                Pion* cible = jeu.getPion(userx,usery);
                cible->setPv(cible->getPv() - puiss);
                std::cout << " ☞ Pion attaqué ! "<< RED << "-"<< puiss << " PV "<< RESET << "au pion "<< cible->getIcon() << "." << std::endl;
                if (cible->getPv() <= 0)
                {
                    jeu.supprimerPion(userx,usery);
                    std::cout << " ☞ Le pion "<< cible->getIcon() << " a succombé à l'attaque." << std::endl;
                }
                jeu.afficherEtatJeu();
                return;
            }
        }
    }
}

int Pion::getX() const { return x; }
int Pion::getY() const { return y; }
void Pion::setX(int newx) { this->x = newx; }
void Pion::setY(int newy) { this->y = newy; }
void Pion::setPv(int newpv) { this->pv = newpv; }
char Pion::getIcon() const { return icon; }
int Pion::getPv() const { return pv; }
int Pion::getColor() const { return color; }

/*
Un guerrier peut se déplacer et attaquer.
*/

Guerrier::Guerrier(int couleur, JeuInterface& j) : Pion(couleur, j) {
    icon = 'G';
    puiss = 5;
    depl = 3;
    pv = 10;
    prod = 0;
    cout = 10;
    color = couleur;
    jeu = j;
}

// void Guerrier::deplacer(int newx, int newy) {
    
//     if (x < 1 || x > TAILLE || y < 1 || y > TAILLE)
//         std::cerr << "Erreur : Coordonnées hors du plateau." << std::endl;

//     int userx, usery;
//     std::vector<std::pair<int, int>> voisins;
//     std::queue<std::pair<int, int>> queue;
//     std::set<std::pair<int, int>> visited;

//     queue.push({x, y});
//     visited.insert({x, y});

//     while (!queue.empty()) {
//         auto current = queue.front();
//         queue.pop();

//         std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//         for (auto& dir : directions) {
//             int nx = current.first + dir.first;
//             int ny = current.second + dir.second;

//             if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && !jeu.estOccupee(nx, ny) &&
//                 visited.find({nx, ny}) == visited.end() && manhattanDistance(x, y, nx, ny) <= depl) {
                
//                 queue.push({nx, ny});
//                 visited.insert({nx, ny});
//                 voisins.push_back({nx, ny});
//             }
//         }
//     }

//     jeu.afficherDepl(voisins);
//     while (true) {
//         std::cout << " ☞ Où souhaitez vous déplacer votre pion ? (x y): ";
//         std::cin >> userx >> usery;
//         if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
//             std::cerr << " ✕ : Coordonnées hors du plateau, choissisez parmi les cases vertes." << std::endl;
//         } else {
//             if (std::find(voisins.begin(), voisins.end(), std::make_pair(userx, usery)) == voisins.end()) {
//                 std::cerr << " ✕ : Case inaccessible, choissisez parmi les cases vertes." << std::endl;
//             } else {
//                 jeu.deplacerPion(x,y,userx,usery);
//                 std::cout << " ☞ Pion déplacé ! " << std::endl;
//                 jeu.afficherEtatJeu();
//                 return;
//             }
//         }
//     }
    
// }
/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe. 
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/

Chateau::Chateau(int couleur, JeuInterface& j) : Pion(couleur, j) { 
    icon = 'C';
    puiss = 0;
    depl = 0;   // Château ne se déplace pas
    prod = 2;
    cout = 15;   // Coût en or pour produire (supposé)
    pv = 20;
    color = couleur;
    jeu = j;
}

void Chateau::produirePion() {
    // Logique pr produire un nouveau pion
}

void Chateau::genererOr() {
    // Logique pr générer de l'or
}

/*
Un paysan peut se déplacer ou produire des ressources.
*/

Paysan::Paysan(int couleur, JeuInterface& j) : Pion(couleur, j) { 
    icon = 'P';
    puiss = 0;
    depl = 2;
    prod = 5;
    cout = 20;
    pv = 1;
    color = couleur;
    jeu = j;
}

void Paysan::genererOr() {
    // Logique pr générer de l'or
}

/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans ce
cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/

Seigneur::Seigneur(int couleur, JeuInterface& j) : Pion(couleur, j) { 
    icon = 'S';
    puiss = 3;
    depl = 1;
    prod = 0;
    cout = 10;
    pv = 5;
    color = couleur;
    jeu = j;
}

void Seigneur::transformation() {
    // Logique pr se transformer en chateau
}