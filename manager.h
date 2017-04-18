#ifndef MANAGER_H
#define MANAGER_H

#include "grille.h"
#include "pion.h"

class Manager {
 public:
  TypePion joueur;
  Grille *grille;
  Manager();
  ~Manager();

  void AjouterPion();
  void ChangerPion(int x,int y, TypePion t);
  void RafraichirAffichage();
  void AjouterAlea();
  void ChangerJoueur(bool humain);
  void Elimine(int x, int y);
  void Balayage();
};

#endif  // MANAGER_H
