#include "joueur.h"

Joueur::Joueur(int id, int gold, const std::string& nom) : id(id), gold(gold), nom(nom) {}


std::string Joueur::getNom() const {return nom;}

int Joueur::getOr() const {return gold;}
void Joueur::addOr(int montant) {gold += montant;}