#include "utils.h"


int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

std::pair<int,int> askCoord(std::string question)
{
    int userx, usery;
    while (true) {
        std::cout << question << "(x y) : ";
        if (!(std::cin >> userx >> usery)) {
            printErr("Entrée invalide. Veuillez entrer deux entiers.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (userx < 1 || userx > TAILLE || usery < 1 || usery > TAILLE) {
            printErr("Coordonnées hors du plateau.");
        } else {
            return std::make_pair(userx, usery);
        }
    }
}

char askChar(std::string question)
{
    char userChar;
    while (true) {
        std::cout << question << " : ";
        std::cin >> userChar;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            printErr("Entrée invalide. Veuillez entrer un seul caractère.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return userChar;
        }
    }
}

void print(std::string msg)
{
    std::cout << msg << std::endl;
}

void printErr(std::string msg)
{
    std::cerr << RED << " ✕ " << RESET << ' ' << msg << std::endl;
}

void printValid(std::string msg)
{
    std::cout << GREEN << " ✓ " << RESET << ' ' << msg << std::endl;
}


void printChoix() {
    std::cout << " ☞ Souhaitez-vous" << MAGENTA << " donner un ordre " << RESET << "ou" << CYAN << " valider votre tour " << RESET << "(" << MAGENTA << "O" << RESET << "/" << CYAN << "V" << RESET << ")";
}

void printTour(bool isRedTurn) {
    std::cout << (isRedTurn ? RED : BLUE) << "\n\t\tC'est au tour de l'équipe " << (isRedTurn ? "Rouge" : "Bleu") << " de jouer : \t\t" << RESET << std::endl;
}
