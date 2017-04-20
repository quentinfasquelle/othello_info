#ifndef GRILLE_H
#define GRILLE_H

#include <stdlib.h>
#include <vector>
#include "pion.h"

#define CLEAR() system("cls")


using namespace std;

class Grille {
 public:
  Pion* contenu[8][8]; // contenu[x][y]

  Grille();
  bool EstDeType(int x, int y);
  bool EstDeType(int x, int y, TypePion t);
  void AjouterPion(int x, int y, TypePion t);
  void ChangerPionBlanc(int x, int y);
  void ChangerPionNoir(int x, int y);
  void Afficher();
};



#endif  // GRILLE_H
