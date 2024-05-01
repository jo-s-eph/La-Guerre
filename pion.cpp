#include "pion.h"

int Pion::getX() const { return x; }
int Pion::getY() const { return y; }
int Pion::getPv() const { return pv; }
int Pion::getColor() const { return color; }
char Pion::getIcon() const { return icon; }

void Pion::setX(int newx) { this->x = newx; }
void Pion::setY(int newy) { this->y = newy; }
void Pion::addPv(int newpv) { this->pv += newpv; }

int Pion::deplacer()
{
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

    jeu.afficherCases(adjacentes);
    while (true) {
        std::cout << " ☞ Où souhaitez vous déplacer votre pion "<< this->getIcon() << " ? (x y): ";
        std::cin >> userx >> usery;
        if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
            std::cerr << " ✕ : Coordonnées hors du plateau, choisisez parmi les cases vertes." << std::endl;
        } else {
            if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end()) {
                std::cerr << " ✕ : Case inaccessible, choisisez parmi les cases vertes." << std::endl;
            } else {
                jeu.deplacerPion(x,y,userx,usery);
                std::cout << " ☞ Pion déplacé ! " << std::endl;
                ordre = true;
                return 1;
            }
        }
    }
    return 0;
}

int Pion::attaquer()
{
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
        return 0;
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
                cible->addPv(-puiss);
                std::cout << " ☞ Pion attaqué ! "<< RED << "-"<< puiss << " PV "<< RESET << "au pion "<< cible->getIcon() << "." << std::endl;
                if (cible->getPv() <= 0)
                {
                    jeu.supprimerPion(userx,usery);
                    std::cout << " ☞ Le pion "<< cible->getIcon() << " a succombé à l'attaque." << std::endl;
                }
                ordre = true;
                return 1;
            }
        }
    }
}

int Pion::genererOr()
{
    Joueur* player = jeu.getJoueur2();
    if (getColor()){ player = jeu.getJoueur1();}
    player->addOr(prod);
    std::cout << " ☞ Le pion "<< getIcon() << " vient de produire" << YELLOW << prod << RESET << "pièces d'or.";
    if (getIcon() == 'P') { ordre = true; } // Car le château génère de l'or passivement
    return 1;
}

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

int Chateau::produirePion() {
    std::vector<std::pair<int, int>> adjacentes;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Haut, droite, bas, gauche
    int userx, usery;

    for (auto& dir : directions) {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && !jeu.estOccupee(nx, ny))
            adjacentes.push_back({nx, ny});
    }
    if (adjacentes.size() == 0)
    {
        std::cout << " ☞ Aucun case adjacente de libre pour produire un pion." << std::endl;;
        return 0;
    }

    jeu.afficherCases(adjacentes);

    while (true) {
        std::cout << " ☞ Sur quelle case souhaitez-vous produire un pion ? (x y): ";
        std::cin >> userx >> usery;
        if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
            std::cerr << " ✕ : Coordonnées hors du plateau, choisisez parmi les cases vertes." << std::endl;
        } else {
            if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end()) {
                std::cerr << " ✕ : Case inaccessible, choisisez parmi les cases vertes." << std::endl;
            } else {
                char choix;
                std::cout << "\t ☞ Quel pion souhaitez-vous produire ? (S, G, P): ";
                std::cin >> choix;
                Joueur* player = jeu.getJoueur2();
                if (getColor()){ player = jeu.getJoueur1();}
                
                if (choix == 'S') {
                    if (player->getOr() < 10)
                        std::cerr << " ✕ : Vous n'avez pas assez d'or pour produire un seigneur." << std::endl;
                    else
                    {
                        Seigneur* s = new Seigneur(getColor(), jeu);
                        jeu.placerPion(s, userx, usery);
                        player->addOr(-10);
                    }
                } else if (choix == 'G') {
                    if (player->getOr() < 10)
                        std::cerr << " ✕ : Vous n'avez pas assez d'or pour produire un guerrier." << std::endl;
                    else
                    {
                    Guerrier* g = new Guerrier(getColor(), jeu);
                    jeu.placerPion(g, userx, usery);
                    player->addOr(-10);
                    }
                } else if (choix == 'P') {
                    if (player->getOr() < 20)
                        std::cerr << " ✕ : Vous n'avez pas assez d'or pour produire un seigneur." << std::endl;
                    else
                    {
                    Paysan* p = new Paysan(getColor(), jeu);
                    jeu.placerPion(p, userx, usery);
                    player->addOr(-20);
                    }
                } else {
                    std::cerr << " ✕ : Erreur, choix invalide." << std::endl;
                }
                std::cout << " ☞ Le pion a été généré avec succès à la case (" << userx << ", " << usery << ")." << std::endl;
                ordre = true;
                return 1;
            }
        }
    }
    return 0;
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

int Seigneur::transformation() {
    Joueur* player = jeu.getJoueur2();
    if (getColor()){ player = jeu.getJoueur1();}

    if (player->getOr() < 15)
        std::cerr << " ✕ : Vous n'avez pas assez d'or pour transformer votre seigneur en château." << std::endl;
    else
    {
        Chateau* chateau = new Chateau(getColor(), jeu);
        chateau->setX(x);
        chateau->setY(y);
        jeu.supprimerPion(x,y);
        jeu.placerPion(chateau, x, y);
        player->addOr(-15);
        std::cout << "  ☞  Le seigneur s'est transformé en château !" << std::endl;
        ordre = true;
        return 1;
    }
    return 0;
}