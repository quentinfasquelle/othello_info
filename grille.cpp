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

bool Grille::EstDeType(int x, int y) { return contenu[x][y]->type == VIDE; }

// on vérifie le contenu de grille
bool Grille::EstDeType(int x, int y, TypePion t) {
  return contenu[x][y]->type == t;
}

// Affichage de la grille avec la table ASCII
void Grille::Afficher() {
    int i,j;
    string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
             horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
             horLH = "+";
             cout <<"  1  "<<" 2  "<<" 3  "<<" 4  "<<" 5  "<<" 6  "<<" 7  "<<" 8  "<<endl;
      cout << " "<<vertHG;
      for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLH;
      cout << horM << horM << horM << vertHD << endl;
      for (int i = 0; i < 8; i++) {
        cout << i+1<<vertM;
        for (int j = 0; j < 8; j++){ cout << contenu[j][i]->Texte() << vertM;}
        cout << endl;
        if (i == 3) {
          cout << " "<< vertBG;
          for (int j = 0; j < 7; j++) cout << horM << horM << horM << horLB;
          cout << horM << horM << horM << vertBD;
        } else {
            cout <<  " " <<horLG << horM << horM << horM << horL4 << horM << horM << horM
                 << horL4 << horM << horM << horM << horL4 << horM << horM << horM
                 << horL4 << horM << horM << horM << horL4 << horM << horM << horM
                 << horL4 << horM << horM << horM << horL4 << horM << horM << horM << horLD;
        }
        cout << endl;
      }
      for(i=0;i<8;i++){
          for(j=0;j<8;j++){
              gotoligcol(i,40);
              if(contenu[i][j]->type == JOUABLE){
                  cout <<"possibilite de l'IA : " << i+1 << j+1;
                  contenu[i][j]->type = VIDE;}

          }
      }
      gotoligcol(20,0);
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



