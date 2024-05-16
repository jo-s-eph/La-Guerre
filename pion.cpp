#include "pion.h"
#include "joueur.h"

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
    int userx, usery;
    std::vector<std::pair<int, int>> adjacentes;
    std::queue<std::pair<std::pair<int, int>, int>> queue;
    std::set<std::pair<int, int>> visited;

    queue.push({{x, y}, 0});
    visited.insert({x, y});

    while (!queue.empty())
    {
        auto current = queue.front();
        queue.pop();

        int currentDepth = current.second;
        if (currentDepth >= depl)
            continue;

        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, O
        for (auto &dir : directions)
        {
            int nx = current.first.first + dir.first;
            int ny = current.first.second + dir.second;

            if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && !jeu.estOccupee(nx, ny) &&
                visited.find({nx, ny}) == visited.end())
            {

                queue.push({{nx, ny}, currentDepth + 1});
                visited.insert({nx, ny});
                adjacentes.push_back({nx, ny});
            }
        }
    }

    jeu.afficherCases(adjacentes);
    while (true)
    {
        std::pair<int, int> coord = askCoord(" ☞ Où souhaitez vous déplacer votre pion " + std::string(1, this->getIcon()) + " ? ");
        std::tie(userx, usery) = coord;
        if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end())
            printErr("Case inaccessible, choisisez parmi les cases vertes.");
        else
        {
            jeu.deplacerPion(x, y, userx, usery);
            printValid("Pion déplacé !");
            ordre = true;
            return 1;
        }
    }
    return 0;
}

int Pion::attaquer()
{
    std::vector<std::pair<int, int>> adjacentes;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int userx, usery;

    for (auto &dir : directions)
    {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && jeu.estOccupee(nx, ny))
            adjacentes.push_back({nx, ny});
    }
    if (adjacentes.size() == 0)
    {
        printErr("Aucun pion assez proche à attaquer.");
        return 0;
    }
    while (true)
    {
        std::pair<int, int> coord = askCoord(" ☞ Quel pion souhaitez-vous attaquer avec " + std::string(1, this->getIcon()) + " ?");
        std::tie(userx, usery) = coord;
        Pion *cible = jeu.getPion(userx, usery);

        if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end())
            printErr("Case inaccessible.");

        if (cible->color == this->color)
            printErr("Vous ne pouvez pas attaquer vos propres pions.");
        else
        {
            break;
        }
    }

    Pion *cible = jeu.getPion(userx, usery);
    cible->addPv(-puiss);
    print(" ☞ Pion attaqué ! " + std::string(RED) + "-" + std::to_string(puiss) + " PV" + std::string(RESET) + " au pion " + cible->getIcon());
    print(" ☞ PV Restants à la victime : " + std::to_string(cible->getPv()) + " PV.");
    if (cible->getPv() <= 0)
    {
        std::cout << " ☞ Le pion " << cible->getIcon() << " a succombé à l'attaque." << std::endl;
        jeu.supprimerPion(userx, usery);
    }
    ordre = true;
    return 1;
}

int Pion::genererOr()
{
    Joueur *player = jeu.getJoueur2();
    if (getColor())
    {
        player = jeu.getJoueur1();
    }
    player->addOr(prod);
    print(" ☞ Le pion " + std::string(1, getIcon()) + " vient de produire " + YELLOW + std::to_string(prod) + RESET + " pièces d'or.");
    if (getIcon() == 'P')
    {
        ordre = true;
    } // Car le château génère de l'or passivement
    return 1;
}

Guerrier::Guerrier(int couleur, JeuInterface &j) : Pion(couleur, j)
// Un guerrier peut se déplacer et attaquer.
{
    icon = 'G';
    puiss = 5;
    depl = 3;
    pv = 10;
    prod = 0;
    cout = 10;
    color = couleur;
    jeu = j;
}

Chateau::Chateau(int couleur, JeuInterface &j) : Pion(couleur, j)
/*
Un château peut produire des seigneurs, des guerriers ou des paysans en consommant l’or de l’équipe.
Un château ne peut ni se déplacer ni attaquer mais produit de l’or passivement.
*/
{
    icon = 'C';
    puiss = 0;
    depl = 0; // Château ne se déplace pas
    prod = 2;
    cout = 15; // Coût en or pour produire (supposé)
    pv = 3;
    color = couleur;
    jeu = j;
}

Chateau::~Chateau()
{
    Joueur *player = jeu.getJoueur2();
    if (getColor())
    {
        player = jeu.getJoueur1();
    }
    player->addNbChateau(-1);
    print(" ☞ Un château de l'équipe " + player->getNom() + " vient de s'effondrer.");
}

int Chateau::produirePion()
{
    std::vector<std::pair<int, int>> adjacentes;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, O
    int userx, usery;

    for (auto &dir : directions)
    {
        int nx = x + dir.first;
        int ny = y + dir.second;

        if (nx >= 1 && nx <= TAILLE && ny >= 1 && ny <= TAILLE && !jeu.estOccupee(nx, ny))
            adjacentes.push_back({nx, ny});
    }
    if (adjacentes.size() == 0)
    {
        printErr(" Aucun case adjacente de libre pour produire un pion.");
        return 0;
    }

    jeu.afficherCases(adjacentes);

    while (true)
    {
        std::pair<int, int> coord = askCoord(" ☞ Sur quelle case souhaitez-vous produire un pion ?");
        std::tie(userx, usery) = coord;
        if (std::find(adjacentes.begin(), adjacentes.end(), std::make_pair(userx, usery)) == adjacentes.end())
            printErr("Case inaccessible, choisisez parmi les cases vertes.");
        else
        {
            char choix;
            while (true)
            {
                std::cout << "\t ☞ Quel pion souhaitez-vous produire ? (S, G, P): ";
                std::cin >> choix;
                if (choix == 'S' || choix == 'G' || choix == 'P')
                    break;
                else
                    printErr("Erreur, choix invalide.");
            }
            Joueur *player = jeu.getJoueur2();
            if (getColor())
            {
                player = jeu.getJoueur1();
            }

            switch (choix)
            {
            case 'S':
                if (player->getOr() < 10)
                    printErr("Vous n'avez pas assez d'or pour produire un seigneur.");
                else
                {
                    Seigneur *s = new Seigneur(getColor(), jeu);
                    jeu.placerPion(s, userx, usery);
                    player->addOr(-10);
                }
                break;
            case 'G':
                if (player->getOr() < 10)
                    printErr("Vous n'avez pas assez d'or pour produire un guerrier.");
                else
                {
                    Guerrier *g = new Guerrier(getColor(), jeu);
                    jeu.placerPion(g, userx, usery);
                    player->addOr(-10);
                }
                break;
            case 'P':
                if (player->getOr() < 20)
                    printErr("Vous n'avez pas assez d'or pour produire un paysan.");
                else
                {
                    Paysan *p = new Paysan(getColor(), jeu);
                    jeu.placerPion(p, userx, usery);
                    player->addOr(-20);
                }
                break;
            default:
                printErr("Erreur, choix invalide.");
            }
            ordre = true;
            return 1;
        }
    }
    return 0;
}

Paysan::Paysan(int couleur, JeuInterface &j) : Pion(couleur, j)
/*
Un paysan peut se déplacer ou produire des ressources.
*/
{
    icon = 'P';
    puiss = 0;
    depl = 2;
    prod = 5;
    cout = 20;
    pv = 1;
    color = couleur;
    jeu = j;
}

Seigneur::Seigneur(int couleur, JeuInterface &j) : Pion(couleur, j)
/*
Un seigneur peut se déplacer et attaquer ou consommer de l’or pour se construire un château et dans
ce cas rentre dedans pour ne plus en sortir (autrement dit un seigneur peut se transformer en château).
*/
{
    icon = 'S';
    puiss = 3;
    depl = 1;
    prod = 0;
    cout = 10;
    pv = 5;
    color = couleur;
    jeu = j;
}

int Seigneur::transformation()
{
    Joueur *player = jeu.getJoueur2();
    if (getColor())
    {
        player = jeu.getJoueur1();
    }

    if (player->getOr() < 15)
        printErr("Vous n'avez pas assez d'or pour transformer votre seigneur en château.");
    else
    {
        Chateau *chateau = new Chateau(getColor(), jeu);
        chateau->setX(x);
        chateau->setY(y);
        jeu.libererCase(x, y);
        jeu.placerPion(chateau, x, y);
        player->addOr(-15);
        player->addNbChateau(1);
        printValid("Le seigneur s'est transformé en château !");
        ordre = true;
        return 1;
    }
    return 0;
}