#include "partie.h"
#include <iostream>

Partie::Partie() {
  string name = "";
  while (name.length() <= 0) {
    CLEAR();
    cout << "----- [ Bienvenue sur le jeu de SIAM ] -----" << endl;
    cout << "Comment s'appelle le Joueur 1 ? ";
    cin >> name;
  }

  j1 = name;

  j2 = "IA";

  nbJ1 = 0;
  nbJ2 = 0;

  manager = new Manager();
  terminee = false;
  humain = true;
}

void Partie::Commencer() {
  string s;
  for (tours = 0; !terminee; tours++) {
    TourSuivant();
  }
}

void Partie::TourSuivant() {
  humain = !humain;
  manager->ChangerJoueur(humain);

  if(humain == false)
  {

  int choix = 0;

  while (choix < 1 || choix > 5) {
    CLEAR();
    manager->grille->Afficher();
    cout << "C'est " << (humain ? "Ordinateur!" : "votre tour!")
         << " (" << (humain ? j2 : j1) << ")" << endl;
    cout << "  (1)  Entrer un pion sur le terrain" << endl;
    /*cout << "  (2)  Se deplacer vers une case libre" << endl;
    cout << "  (3)  Faire pivoter un pion" << endl;
    cout << "  (4)  Sortir un pion" << endl;
    cout << "  (5)  Deplacer un pion et pousser" << endl;*/
    cout << "Que voulez vous faire >> ";
    cin >> choix;
  }

  switch (choix) {
    case 1:
      manager->AjouterPion();
      break;
   /* case 2:
      manager->DeplacerCaseLibre("");
      cout << "C'est bon ca!" << endl;
      break;
    case 3:
      manager->PivoterPion();
      break;
    case 4:
      manager->RetirerPion("");
      break;
    case 5:
      if (manager->PousserPion("")) {
        cout << "Vous avez gagne! " << endl;
        terminee = true;
      }
      break;*/
  }
  }
  else manager->AjouterAlea();


}
