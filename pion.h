#ifndef PION_H
#define PION_H

#include <string>

using namespace std;

enum TypePion { BLANC , NOIR , VIDE , JOUABLE };

class Pion {
 private:
 public:
  TypePion type;

  Pion();
  string Texte();
};

class Vide : public Pion {
 public:
  Vide() { this->type = VIDE; }
};

class Blanc : public Pion {
 public:
  Blanc() { this->type = BLANC; }
};

class Noir : public Pion {
 public:
  Noir() { this->type = NOIR; }
};

class PionJoueur : public Pion {
 public:
  PionJoueur(TypePion t) {
    this->type = t;
  }
};

#endif  // PION_H
