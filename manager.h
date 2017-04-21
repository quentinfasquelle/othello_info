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
  void RafraichirAffichageTab();
  void AjouterAlea();
  void ChangerJoueur(bool humain);
  void ElimineJoueur(int x, int y);
  void ElimineIA(int x, int y);
  void BalayageIA();
  void BalayageJoueur();
};

#endif // MANAGER_H
