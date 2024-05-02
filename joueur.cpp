#include "joueur.h"

Joueur::Joueur(int id, int gold, const std::string& nom) : id(id), gold(gold), nom(nom) {}


std::string Joueur::getNom() const {return nom;}

int Joueur::getOr() const {return gold;}
int Joueur::getNbChateau() const {return nbchateau;}

void Joueur::addOr(int montant) {gold += montant;}
void Joueur::addNbChateau(int montant) {nbchateau += montant;}