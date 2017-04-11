#include "pion.h"

Pion::Pion() {
  this->type = VIDE;
}


string Pion::Texte() {
  string s = "";
  switch (this->type) {
    case BLANC:
      return  " O ";
    case NOIR:
      return "\E[31;1m X \E[m";
    case VIDE:
      return "   ";
    default:
      s += " ?";
  }

  return s;
}
