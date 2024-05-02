#ifndef UTILS_H
#define UTILS_H

#include <cmath>

#define TAILLE 20
#define OR_DEPART 5

#define RESET   "\033[0m"
#define RED     "\033[0;101m"
#define BLUE    "\033[0;104m"
#define GREY    "\033[90m"
#define YELLOW  "\033[1m\033[33m"
#define GREEN   "\033[0m\033[32m"
#define WHITE  "\033[1m\033[37m"


int manhattanDistance(int x1, int y1, int x2, int y2);

#endif // UTILS_H