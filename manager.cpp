#include "manager.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


Manager::Manager() {
  grille = new Grille();
  joueur = BLANC;
}

Manager::~Manager() {}


void Manager::RafraichirAffichage() {
  CLEAR();
  BalayageIA();
  BalayageJoueur();
  grille->Afficher();
}


void Manager::AjouterPion() {
  int x, y;
  //int i, j;

  RafraichirAffichage();
  cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
  cout << "Indiquez les coordonnees voulues" << endl;
  cout << "Quelle colonne ? (1-8) ";
  cin >> x;
  cout << endl << "Quelle ligne ? (1-8) ";
  cin >> y;

  while ((x < 1) || (x > 8) || (y < 1) || (y > 8)) {
    RafraichirAffichage();
    cout << endl << "les coordonnees choisies sont erronees" << endl;
    cout << "Vous avez choisi de rentrer un pion sur la grille" << endl;
    cout << "Indiquez les coordonnees voulues" << endl;
    cout << "Quelle colonne ? (1-8) ";
    cin >> x;
    cout << endl << "Quelle ligne ? (1-8) ";
    cin >> y;
  }

  RafraichirAffichage();

    if(grille->EstDeType(x-1,y-1,JOUEUR)){
        grille->contenu[x-1][y-1]->type = VIDE;
    grille->AjouterPion(x - 1, y - 1, NOIR);
    ElimineJoueur(x-1,y-1);

    cout << "Le Pion a bien ete ajoute!" << endl;
  } else {
    cout << "La case choisie n'est pas vide, ou pas en bordure!" << endl;
    //Balayage();
    AjouterPion();
  }
}



void Manager::ChangerPion(int x,int y, TypePion t) {

    if(t == NOIR) grille->ChangerPionBlanc(x,y);
    if(t == BLANC) grille->ChangerPionNoir(x,y);
}

int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

void Manager::AjouterAlea() {
    int k = 0;
    int l = 0;
    int sortie=0;
    BalayageIA();
    for(k=0;k<8;k++){
        for(l=0;l<8;l++){
        if(sortie == 0){
        if(grille->EstDeType(k,l,JOUABLE)){
            grille->AjouterPion(k,l,BLANC);
            ElimineIA(k,l);
            sortie =1;
        }
        }
    }
    }

   RafraichirAffichage();
}


void Manager::ChangerJoueur(bool humain) {
  if (humain)
    joueur = NOIR;
  else
    joueur = BLANC;
}


void Manager::ElimineJoueur(int x, int y){

    if(grille->EstDeType(x,y,NOIR)){
        if((x>=0 && y>=0) && (x+2<8 && y+2<8)){
            if(grille->EstDeType(x+1,y+1,BLANC)){
                if(grille->EstDeType(x+2,y+2,NOIR)){
                    grille->contenu[x+1][y+1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y>=0) && (x<8 && y+2<8)){
            if(grille->EstDeType(x,y+1,BLANC)){
                if(grille->EstDeType(x,y+2,NOIR)){
                    grille->contenu[x][y+1]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y>=0) && (x<8 && y+2<8)){
            if(grille->EstDeType(x-1,y+1,BLANC)){
                if(grille->EstDeType(x-2,y+2,NOIR)){
                    grille->contenu[x-1][y+1]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x-1,y,BLANC)){
                if(grille->EstDeType(x-2,y,NOIR)){
                    grille->contenu[x-1][y]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y-2>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x-1,y-1,BLANC)){
                if(grille->EstDeType(x-2,y-2,NOIR)){
                    grille->contenu[x-1][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y-2>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x,y-1,BLANC)){
                if(grille->EstDeType(x,y-2,NOIR)){
                    grille->contenu[x][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y-2>=0) && (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y-1,BLANC)){
                if(grille->EstDeType(x+2,y-2,NOIR)){
                    grille->contenu[x+1][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y>=0) && (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y,BLANC)){
                if(grille->EstDeType(x+2,y,NOIR)){
                    grille->contenu[x+1][y]->type = NOIR;
                }
            }
        }
    }

}
void Manager::ElimineIA(int x, int y){

    if(grille->EstDeType(x,y,BLANC)){
        if((x>=0 && y>=0) && (x+2<8 && y+2<8)){
            if(grille->EstDeType(x+1,y+1,NOIR)){
                if(grille->EstDeType(x+2,y+2,BLANC)){
                    grille->contenu[x+1][y+1]->type = BLANC;
                }
            }
        }
        if((x>=0 && y>=0) && (x<8 && y+2<8)){
            if(grille->EstDeType(x,y+1,NOIR)){
                if(grille->EstDeType(x,y+2,BLANC)){
                    grille->contenu[x][y+1]->type = BLANC;
                }
            }
        }
        if((x-2>=0 && y>=0) && (x<8 && y+2<8)){
            if(grille->EstDeType(x-1,y+1,NOIR)){
                if(grille->EstDeType(x-2,y+2,BLANC)){
                    grille->contenu[x-1][y+1]->type = BLANC;
                }
            }
        }
        if((x-2>=0 && y>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x-1,y,NOIR)){
                if(grille->EstDeType(x-2,y,BLANC)){
                    grille->contenu[x-1][y]->type = BLANC;
                }
            }
        }
        if((x-2>=0 && y-2>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x-1,y-1,NOIR)){
                if(grille->EstDeType(x-2,y-2,BLANC)){
                    grille->contenu[x-1][y-1]->type = BLANC;
                }
            }
        }
        if((x>=0 && y-2>=0) && (x<8 && y<8)){
            if(grille->EstDeType(x,y-1,NOIR)){
                if(grille->EstDeType(x,y-2,BLANC)){
                    grille->contenu[x][y-1]->type = BLANC;
                }
            }
        }
        if((x>=0 && y-2>=0) && (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y-1,NOIR)){
                if(grille->EstDeType(x+2,y-2,BLANC)){
                    grille->contenu[x+1][y-1]->type = BLANC;
                }
            }
        }
        if((x>=0 && y>=0) && (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y,NOIR)){
                if(grille->EstDeType(x+2,y,BLANC)){
                    grille->contenu[x+1][y]->type = BLANC;
                }
            }
        }
    }

}
void Manager::BalayageIA()
{
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(grille->EstDeType(i,j,BLANC)){
                if((i>=0 && j>=0) && (i+2<8 && j+2<8)){
                    if(grille->EstDeType(i+1,j+1,NOIR)){
                        if(grille->EstDeType(i+2,j+2,VIDE)){
                            grille->contenu[i+2][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j>=0) && (i<8 && j+2<8)){
                    if(grille->EstDeType(i,j+1,NOIR)){
                        if(grille->EstDeType(i,j+2,VIDE)){
                            grille->contenu[i][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j>=0) && (i<8 && j+2<8)){
                    if(grille->EstDeType(i-1,j+1,NOIR)){
                        if(grille->EstDeType(i-2,j+2,VIDE)){
                            grille->contenu[i-2][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j,NOIR)){
                        if(grille->EstDeType(i-2,j,VIDE)){
                            grille->contenu[i-2][j]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j-2>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j-1,NOIR)){
                        if(grille->EstDeType(i-2,j-2,VIDE)){
                            grille->contenu[i-2][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j-2>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i,j-1,NOIR)){
                        if(grille->EstDeType(i,j-2,VIDE)){
                            grille->contenu[i][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j-2>=0) && (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j-1,NOIR)){
                        if(grille->EstDeType(i+2,j-2,VIDE)){
                            grille->contenu[i+2][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j>=0) && (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j,NOIR)){
                        if(grille->EstDeType(i+2,j,VIDE)){
                            grille->contenu[i+2][j]->type = JOUABLE;
                        }
                    }
                }
            }

        }
    }
}

void Manager::BalayageJoueur()
{
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(grille->EstDeType(i,j,NOIR)){
                if((i>=0 && j>=0) && (i+2<8 && j+2<8)){
                    if(grille->EstDeType(i+1,j+1,BLANC)){
                        if(grille->EstDeType(i+2,j+2,VIDE)){
                            grille->contenu[i+2][j+2]->type = JOUEUR;
                        }
                    }
                }
                if((i>=0 && j>=0) && (i<8 && j+2<8)){
                    if(grille->EstDeType(i,j+1,BLANC)){
                        if(grille->EstDeType(i,j+2,VIDE)){
                            grille->contenu[i][j+2]->type = JOUEUR;
                        }
                    }
                }
                if((i-2>=0 && j>=0) && (i<8 && j+2<8)){
                    if(grille->EstDeType(i-1,j+1,BLANC)){
                        if(grille->EstDeType(i-2,j+2,VIDE)){
                            grille->contenu[i-2][j+2]->type = JOUEUR;
                        }
                    }
                }
                if((i-2>=0 && j>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j,BLANC)){
                        if(grille->EstDeType(i-2,j,VIDE)){
                            grille->contenu[i-2][j]->type = JOUEUR;
                        }
                    }
                }
                if((i-2>=0 && j-2>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j-1,BLANC)){
                        if(grille->EstDeType(i-2,j-2,VIDE)){
                            grille->contenu[i-2][j-2]->type = JOUEUR;
                        }
                    }
                }
                if((i>=0 && j-2>=0) && (i<8 && j<8)){
                    if(grille->EstDeType(i,j-1,BLANC)){
                        if(grille->EstDeType(i,j-2,VIDE)){
                            grille->contenu[i][j-2]->type = JOUEUR;
                        }
                    }
                }
                if((i>=0 && j-2>=0) && (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j-1,BLANC)){
                        if(grille->EstDeType(i+2,j-2,VIDE)){
                            grille->contenu[i+2][j-2]->type = JOUEUR;
                        }
                    }
                }
                if((i>=0 && j>=0) && (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j,BLANC)){
                        if(grille->EstDeType(i+2,j,VIDE)){
                            grille->contenu[i+2][j]->type = JOUEUR;
                        }
                    }
                }
            }

        }
    }
}
