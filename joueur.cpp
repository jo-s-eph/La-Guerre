#include "joueur.h"

Joueur::Joueur(int id, int gold, const std::string& nom) : id(id), gold(gold), nom(nom) {}

void Joueur::deplacerPion(Pion* pion, int x, int y) {
    pion->deplacer(x, y);
}

void Joueur::produirePion(Pion* chateau, PionType type) {
    if (dynamic_cast<Chateau*>(chateau) != nullptr) { // if chateau is of type Chateau
    }
    
}

void Joueur::attaquer(Pion* attaquant, Pion* cible) {
    attaquant->attaquer(*cible);
}

std::string Joueur::getNom() const {return nom;}

int Joueur::getOr() const {return gold;}

void Joueur::ajouterOr(int montant) {gold += montant;}