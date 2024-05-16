#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <iostream>

#define TAILLE 20
#define OR_DEPART 250

#define RESET           "\033[0m"
#define RED             "\033[0;101m"
#define BLUE            "\033[0;104m"
#define GREEN           "\033[0;102m"
#define LIGHT_GREEN     "\033[0m\033[32m"
#define YELLOW          "\033[1m\033[33m"
#define MAGENTA         "\033[1m\033[35m"
#define CYAN            "\033[1m\033[36m"
#define GREY            "\033[90m"
#define WHITE           "\033[1m\033[37m"

int manhattanDistance(int x1, int y1, int x2, int y2);

std::pair<int, int> askCoord(std::string question);
char askChar(std::string question);
void print(std::string msg);
void printErr(std::string msg);
void printValid(std::string msg);
void printChoix();
void printTour(bool who);
void printGagnant(int who);

#endif // UTILS_H