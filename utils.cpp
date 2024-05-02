#include "utils.h"


int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

std::pair<int,int> askCoord(std::string question)
{
    int userx, usery;
    while (true) {
        std::cout << question << "(x y) : ";
        std::cin >> userx >> usery;
        if (userx < 1 || userx > TAILLE || usery < 1 || usery > TAILLE)
            printErr("Coordonnées hors du plateau.");
        else
            return std::make_pair(userx, usery);
    }
}

void printErr(std::string msg)
{
    std::cerr << RED << " ✕ " << RESET << ' ' << msg << std::endl;
}

void printValid(std::string msg)
{
    std::cerr << GREEN2 << " ✓ " << RESET << ' ' << msg << std::endl;
}