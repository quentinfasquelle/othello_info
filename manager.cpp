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
  int i, j;

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
    for(j = y-2; j < y+3 ; j++)
    {
        i = x-2;
        if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
    }
    for(j = y-2; j < y+3 ; j++)
    {
        i = x+2;
        if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
    }
    for(i= x-1; i < x+2 ; i++)
    {
        j = x-1;
        if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
    }
    for(i= x-1; i < x+2 ; i++)
    {
        j = x+1;
        if(grille->EstDeType(i,j,BLANC))ChangerPion(i,j,BLANC);
    }

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
    int i = 0;
    int j = 0;

    while(sortie == 0)
    {
        i = rand_a_b(0,8);
        j = rand_a_b(0,8);
        if(grille->EstVide(i,j)){
            grille->AjouterPion(i,j,BLANC);
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
