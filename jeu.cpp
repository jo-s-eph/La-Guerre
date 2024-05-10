#include "jeu.h"


Jeu::Jeu() : Joueur1(1, OR_DEPART, "Rouge"), Joueur2(0, OR_DEPART, "Bleu") {
    initialiserPlateau();
}

void Jeu::initialiserPlateau() {
    plateau.resize(TAILLE, std::vector<Pion*>(TAILLE, nullptr));

    Chateau* chateauRouge = new Chateau(1,*this);
    Paysan* paysanRouge = new Paysan(1,*this);
    Chateau* chateauBleu = new Chateau(0,*this);
    Paysan* paysanBleu = new Paysan(0,*this);

    placerPion(chateauRouge,9,4);
    Joueur1.addNbChateau(1);
    placerPion(paysanRouge,10,4);
    placerPion(chateauBleu,9,16);
    Joueur2.addNbChateau(1);
    placerPion(paysanBleu,10,16);
}


void Jeu::demarrer() 
{
    afficherEtatJeu();
    bool tourOk;
    int userx, usery;
    char userc;
    bool isRedTurn = true;
    Joueur* player;

    while (!FinPartie())
    {
        if (isRedTurn) {player = &Joueur1;} 
        else {player = &Joueur2;}
        tourOk = false;
        printTour(isRedTurn);
        afficherEtatJeu();
        resetOrdrePion();

        while (!tourOk) 
        {
            printChoix();
            userc = askChar(" ");

            switch (userc)
            {
                case 'V':
                    tourOk = true;
                    break;
                case 'O':
                    while (true) 
                    {
                        std::pair<int, int> coord = askCoord(" ☞ Sur quel pion souhaitez-vous agir ? ");
                        std::tie(userx, usery) = coord;
                        Pion* p = getPion(userx, usery);
                        
                        if (p == nullptr) {
                            printErr("Aucun pion sur cette case.");
                        } else {
                            if (p->getColor() != player->getId())
                            {
                                printErr("Ce pion ne vous appartient pas.");
                            } else {
                                if (p->ordre) {
                                    printErr("Vous avez déjà donné un ordre à ce pion.");
                                    break;
                                } else {
                                    ChoixActions(p);
                                    afficherEtatJeu();
                                    break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    printErr("Choix incorrect.");
            }
        }
        isRedTurn = !isRedTurn;
    }
}

bool Jeu::FinPartie()
{
    return (Joueur1.getNbChateau() == 0 || Joueur2.getNbChateau() == 0);   
}

Pion* Jeu::getPion(int x, int y){
    return plateau[x - 1][y - 1];
}

void Jeu::resetOrdrePion()
{
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            Pion* p = plateau[i][j];
            if (p != nullptr) {
                p->ordre = 0;
            }
        }
    }
}
int Jeu::ChoixActions(Pion* pion)
{
    int choix;
    print("Pion séléctionné : " + std::string(YELLOW) + pion->getIcon() + RESET);
    print("Action(s) possible(s) : ");

    if (pion->getIcon() == 'C') {
        Chateau* chateau = static_cast<Chateau*>(pion);
        while (true)
        {
            print("\t[2] -  Construire un pion sur une case adjacente");
            print("Votre choix : ");
            std::cin >> choix;

            if (choix != 2)
                printErr("Veuillez choisir une action parmi la liste ci-dessus");
            else
                return chateau->produirePion();
        }
    } else if (pion->getIcon() == 'P') {
        Paysan* paysan = static_cast<Paysan*>(pion);
        while (true)
        {
            print("\t[0] -  Se déplacer");
            print("\t[3] -  Amasser des ressources");
            print("Votre choix : ");
            std::cin >> choix;
            switch (choix)
            {
            case 0:
                return paysan->deplacer();
            case 3:
                return paysan->genererOr();
            default:
                printErr("Veuillez choisir une action parmi la liste ci-dessus");
            }
        }
    } else if (pion->getIcon() == 'S') {
        Seigneur* seigneur = static_cast<Seigneur*>(pion);
        while (true)
        {
            print("\t[0] -  Se déplacer");
            print("\t[1] -  Attaquer");
            print("\t[4] -  Se transformer en château");
            print("Votre choix : ");
            std::cin >> choix;
            switch (choix)
            {
            case 0:
                return seigneur->deplacer();
            case 1:
                return seigneur->attaquer();
            case 4:
                return seigneur->transformation();
            default:
                printErr("Veuillez choisir une action parmi la liste ci-dessus");
            }
        }
    } else if (pion->getIcon() == 'G') {
        Guerrier* guerrier = static_cast<Guerrier*>(pion);
        while (true)
        {
            print("\t[0] -  Se déplacer");
            print("\t[1] -  Attaquer");
            print("Votre choix : ");
            std::cin >> choix;
            switch (choix)
            {
            case 0:
                return guerrier->deplacer();
            case 1:
                return guerrier->attaquer();
            default:
                printErr("Veuillez choisir une action parmi la liste ci-dessus");
            }
        }
    } else {
        printErr("Type de pion inconnu.");
        return 0;
    }
}

Joueur* Jeu::getJoueur1(){ return &Joueur1; }
Joueur* Jeu::getJoueur2(){ return &Joueur2; }

int Jeu::placerPion(Pion* pion, int x, int y){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
        printErr("Coordonnées hors du plateau.");
        return 0;
    }
    if (plateau[x-1][y-1] != nullptr) {
        printErr("Case déjà occupée.");
        return 0;
    }

    plateau[x - 1][y - 1] = pion;
    pion->setX(x);
    pion->setY(y);
    return 1;
}


int Jeu::supprimerPion(int x, int y){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
        printErr("Coordonnées hors du plateau.");
        return 0;
    }
    if (plateau[x-1][y-1] == nullptr) {
        printErr("Case déjà occupée.");
        return 0;
    }
    // delete plateau[x-1][y-1];
    plateau[x-1][y-1] = nullptr;
    return 1;
}

int Jeu::deplacerPion(int x, int y, int newx, int newy){
    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE || newx < 1 || newx > TAILLE || newy < 1 || newy > TAILLE) {
        printErr("Coordonnées hors du plateau.");
        return 0;
    }
    if (plateau[x-1][y-1] == nullptr) {
        printErr("Case déjà occupée.");
        return 0;
    }
    placerPion(plateau[x-1][y-1], newx, newy);
    supprimerPion(x, y);
    return 1;
}

bool Jeu::estOccupee(int x, int y) { return (plateau[x - 1][y - 1] != nullptr); }

void Jeu::afficherEtatJeu() {
    afficherOr();
    afficherGrille();
}

void Jeu::afficherOr()
{
    std::cout << YELLOW << "\n\tJoueur " << Joueur1.getNom() << " : " << Joueur1.getOr() << " ◉";
    std::cout << "\t\tJoueur " << Joueur2.getNom() << " : " << Joueur2.getOr() << " ◉";
}

void Jeu::afficherGrille()
{
    std::cout << RESET << "\n\n";
    for (int i = TAILLE - 1; i >= 0; --i) {
        std::cout << i + 1 << "\t";
        for (int j = 0; j < TAILLE; ++j) {
            if (plateau[j][i] != nullptr) {
                if (plateau[j][i]->getColor())
                    std::cout << RED << plateau[j][i]->getIcon() << RESET << " ";
                else
                    std::cout << BLUE << plateau[j][i]->getIcon() << RESET << " ";              
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

void Jeu::afficherCases(const std::vector<std::pair<int, int>>& cases)
{
    // Afficher la grille avec les cases données en surbrillances
    std::cout << RESET << "\n\n";
    for (int i = TAILLE - 1; i >= 0; --i) {
        std::cout << i + 1 << "\t";
        for (int j = 0; j < TAILLE; ++j) {
            if (plateau[j][i] != nullptr) {
                if (plateau[j][i]->getColor())
                    std::cout << RED << plateau[j][i]->getIcon() << RESET << " ";
                else
                    std::cout << BLUE << plateau[j][i]->getIcon() << RESET << " ";            
            } 
            else {
                if (std::find(cases.begin(), cases.end(), std::make_pair(j + 1, i + 1)) != cases.end())
                    std::cout << LIGHT_GREEN << "◼︎ " << RESET;
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