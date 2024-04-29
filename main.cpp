#include <iostream>
#include "jeu.h"
#include "pion.h"

int main()
{
    Jeu J;
    Guerrier G(12,0);
    std::cout << G.getPv() << std::endl;
    return 0;
}