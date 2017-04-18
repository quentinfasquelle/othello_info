#include "manager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Manager::Manager() {
  grille = new Grille();
  joueur = BLANC;
}

Manager::~Manager() {}


void Manager::RafraichirAffichage() {
  CLEAR();
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


  if (grille->EstVide(x - 1, y - 1)) {
    grille->AjouterPion(x - 1, y - 1, NOIR);
    Elimine(x-1,y-1);

    cout << "Le Pion a bien ete ajoute!" << endl;
  } else {
    cout << "La case choisie n'est pas vide, ou pas en bordure!" << endl;
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
        if(grille->EstVide(k,l)){
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
    int i,j;
    for(j=y-2; j<=y+2; j++)
    {
        i = x-2;
        if(grille->EstDeType(i,j,NOIR))
        {
            i=x-1;
            if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
        }
    }
    for(j=y-2; j<=y+2; j++)
    {
        i = x+2;
        if(grille->EstDeType(i,j,NOIR))
        {
            i=x+1;
            if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
        }
    }
    if(grille->EstDeType(x,y-2,NOIR))ChangerPion(x,y-1,BLANC);
    if(grille->EstDeType(x,y+2,NOIR))ChangerPion(x,y+1,BLANC);
}


int Manager::Balayage()
{
    int tab[8][8];
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(grille->EstVide(i,j))tab[i][j]=VIDE;
            if(grille->EstDeType(i,j,BLANC))tab[i][j]=BLANC;
            else tab[i][j]=NOIR;
        }
    }
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){

        }
    }
    return tab;
}
