#include "manager.h"
#include <vector>
using namespace std;
#include <iostream>


void affichage()
{
    string vertM = "|", vertHG = "+", vertHD = "+", vertBG = "+", vertBD = "+",
           horM = "-", horLG = "|", horLD = "|", horL4 = "+", horLB = "+",
           horLH = "+";

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
