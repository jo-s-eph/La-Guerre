#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include "joueur.h"
#include "pion.h"
#include "utils.h"
#include "interface.h"


class Jeu : public JeuInterface {
public:
    Jeu();
    void demarrer();

    void afficherEtatJeu();
    void afficherGrille();
    void afficherCases(const std::vector<std::pair<int, int>>& cases);
    void afficherOr();
    int placerPion(Pion* pion, int x, int y);
    int supprimerPion(int x, int y);
    int deplacerPion(int x, int y, int newx, int newy);
    int libererCase(int x, int y);
    void resetOrdrePion();
    Pion* getPion(int x, int y);
    int ChoixActions(Pion* pion);
    int FinPartie();
    Joueur* getJoueur1();
    Joueur* getJoueur2();

    bool estOccupee(int x, int y);
    std::vector<std::vector<Pion*>> plateau;
    Joueur Joueur1;
    Joueur Joueur2;

protected:
    void initialiserPlateau();
    friend class Joueur;
};

#endif // JEU_H