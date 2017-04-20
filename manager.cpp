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
  Balayage();
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

  if (grille->EstDeType(x - 1, y - 1)) {
    grille->AjouterPion(x - 1, y - 1, NOIR);
    Elimine(x-1,y-1);

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

    int sortie = 0;
   // int i = 0;
    // int j = 0;
    int k = 0;
    int l = 0;
    //int x = 0;
    //int y = 0;

    while(sortie == 0)
    {
        k = rand_a_b(0,8);
        l = rand_a_b(0,8);
        if(grille->EstDeType(k,l)){
            grille->AjouterPion(k,l,BLANC);
            sortie = 1;
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


void Manager::Elimine(int x, int y){

    if(grille->EstDeType(x,y,NOIR)){
        if((x>=0 && y>=0) || (x+2<8 && y+2<8)){
            if(grille->EstDeType(x+1,y+1,BLANC)){
                if(grille->EstDeType(x+2,y+2,NOIR)){
                    grille->contenu[x+1][y+1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y>=0) || (x<8 && y+2<8)){
            if(grille->EstDeType(x,y+1,BLANC)){
                if(grille->EstDeType(x,y+2,NOIR)){
                    grille->contenu[x][y+1]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y>=0) || (x<8 && y+2<8)){
            if(grille->EstDeType(x-1,y+1,BLANC)){
                if(grille->EstDeType(x-2,y+2,NOIR)){
                    grille->contenu[x-1][y+1]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y>=0) || (x<8 && y<8)){
            if(grille->EstDeType(x-1,y,BLANC)){
                if(grille->EstDeType(x-2,y,NOIR)){
                    grille->contenu[x-1][y]->type = NOIR;
                }
            }
        }
        if((x-2>=0 && y-2>=0) || (x<8 && y<8)){
            if(grille->EstDeType(x-1,y-1,BLANC)){
                if(grille->EstDeType(x-2,y-2,NOIR)){
                    grille->contenu[x-1][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y-2>=0) || (x<8 && y<8)){
            if(grille->EstDeType(x,y-1,BLANC)){
                if(grille->EstDeType(x,y-2,NOIR)){
                    grille->contenu[x][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y-2>=0) || (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y-1,BLANC)){
                if(grille->EstDeType(x+2,y-2,NOIR)){
                    grille->contenu[x+1][y-1]->type = NOIR;
                }
            }
        }
        if((x>=0 && y>=0) || (x+2<8 && y<8)){
            if(grille->EstDeType(x+1,y,BLANC)){
                if(grille->EstDeType(x+2,y,NOIR)){
                    grille->contenu[x+1][y]->type = NOIR;
                }
            }
        }
    }

}

void Manager::Balayage()
{
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(grille->EstDeType(i,j,BLANC)){
                if((i>=0 && j>=0) || (i+2<8 && j+2<8)){
                    if(grille->EstDeType(i+1,j+1,NOIR)){
                        if(grille->EstDeType(i+2,j+2)){
                            grille->contenu[i+2][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j>=0) || (i<8 && j+2<8)){
                    if(grille->EstDeType(i,j+1,NOIR)){
                        if(grille->EstDeType(i,j+2)){
                            grille->contenu[i][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j>=0) || (i<8 && j+2<8)){
                    if(grille->EstDeType(i-1,j+1,NOIR)){
                        if(grille->EstDeType(i-2,j+2)){
                            grille->contenu[i-2][j+2]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j>=0) || (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j,NOIR)){
                        if(grille->EstDeType(i-2,j)){
                            grille->contenu[i-2][j]->type = JOUABLE;
                        }
                    }
                }
                if((i-2>=0 && j-2>=0) || (i<8 && j<8)){
                    if(grille->EstDeType(i-1,j-1,NOIR)){
                        if(grille->EstDeType(i-2,j-2)){
                            grille->contenu[i-2][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j-2>=0) || (i<8 && j<8)){
                    if(grille->EstDeType(i,j-1,NOIR)){
                        if(grille->EstDeType(i,j-2)){
                            grille->contenu[i][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j-2>=0) || (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j-1,NOIR)){
                        if(grille->EstDeType(i+2,j-2)){
                            grille->contenu[i+2][j-2]->type = JOUABLE;
                        }
                    }
                }
                if((i>=0 && j>=0) || (i+2<8 && j<8)){
                    if(grille->EstDeType(i+1,j,NOIR)){
                        if(grille->EstDeType(i+2,j)){
                            grille->contenu[i+2][j]->type = JOUABLE;
                        }
                    }
                }
            }

        }
    }


}
