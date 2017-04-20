#include "grille.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void gotoligcol(int lig, int col){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),mycoord);
}

Grille::Grille() {  // Déclaration de la grille avec les montagnes
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      contenu[i][j] = new Vide();
    }
  }

  // Pion
  contenu[3][3] = new Blanc();
  contenu[4][4] = new Blanc();
  contenu[3][4] = new Noir();
  contenu[4][3] = new Noir();
}

bool Grille::EstVide(int x, int y) { return contenu[x][y]->type == VIDE; }

// on vérifie le contenu de grille
bool Grille::EstDeType(int x, int y, TypePion t) {
  return contenu[x][y]->type == t;
}

// Affichage de la grille avec la table ASCII
void Grille::Afficher() {
  string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
         horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
         horLH = "+";
    gotoligcol(0,0);
  cout << vertHG;
  for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLH;
  cout << horM << horM << horM << vertHD << endl;
  for (int i = 0; i < 8; i++) {
    cout << vertM;
    for (int j = 0; j < 8; j++) cout << contenu[j][i]->Texte() << vertM;
    cout << endl;

    if (i == 4) {
      cout << vertBG;
      for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLB;
      cout << horM << horM << horM << vertBD;
    } else {
        cout << horLG << horM << horM << horM << horL4 << horM << horM << horM
             << horL4 << horM << horM << horM << horL4 << horM << horM << horM
             << horL4 << horM << horM << horM << horL4 << horM << horM << horM
             << horL4 << horM << horM << horM << horL4 << horM << horM << horM << horLD;
    }
    cout << endl;
  }
}

// on ajoute un pion selon son type: blanc ou noir
void Grille::AjouterPion(int x, int y, TypePion t) {
  switch (t) {
    case BLANC:
      contenu[x][y] = new PionJoueur(BLANC);
      break;
    case NOIR:
      contenu[x][y] = new PionJoueur(NOIR);
      break;
    default:
      contenu[x][y] = new Vide();
      break;
  }
}



// On cree un pion de type vide pour retirer le pion existant
void Grille::ChangerPionBlanc(int x, int y) { contenu[x][y] = new Blanc(); }

void Grille::ChangerPionNoir(int x, int y) { contenu[x][y] = new Noir(); }


void Grille::AfficherTab(){
    string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
           horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
           horLH = "+";

    gotoligcol(0,80);
    cout << vertHG;
    for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLH;
    cout << horM << horM << horM << vertHD << endl;
    for (int i = 0; i < 8; i++) {
      cout << vertM;
      for (int j = 0; j < 8; j++) cout << contenu[i][j]->Texte() << vertM;
      cout << endl;

      if (i == 4) {
        cout << vertBG;
        for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLB;
        cout << horM << horM << horM << vertBD;
      } else {
          cout << horLG << horM << horM << horM << horL4 << horM << horM << horM
               << horL4 << horM << horM << horM << horL4 << horM << horM << horM
               << horL4 << horM << horM << horM << horL4 << horM << horM << horM
               << horL4 << horM << horM << horM << horL4 << horM << horM << horM << horLD;
      }
      cout << endl;
    }
}


