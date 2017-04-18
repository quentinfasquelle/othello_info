#include <iostream>
#include "partie.h"


using namespace std;

int main(int argc, char *argv[]) {
    int a;

  cout<<"***************************************************"<<endl;
  cout<<"********************* OTHELLO *********************"<<endl;
  cout<<"***************************************************"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"Que voulez-vous faire ?"<<endl;
  cout<<"1.Nouvelle partie"<<endl;
  cout<<"2.Regles"<<endl;
  cout<<"3.Quitter"<<endl;
  cin>>a;
  switch(a)
  {
    case 1 :
        {
        Partie *p = new Partie();
        p->Commencer();
        }
        break;
    case 2 :
        cout<<"Chaque joueur choisit son animal. Les joueurs joueront à tour de rôle."<<endl;
        cout<<"Au début du jeu les animaux sont disposés à l'extérieur du plateau et les"<<endl;
        cout<<"montagnes au centre du plateau. Chaque case du plateau est repérée par ses coordonnées."<<endl;
        cout<<"Les éléphants blancs, animaux sacrés dans le royaume de SIAM commenceront à jouer."<<endl;
        break;
    case 3 :
        return 0;
        break;
  }
  return 0;
}
