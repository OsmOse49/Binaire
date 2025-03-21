#include "class.h"
#include "class.cpp"
#include <iostream>
#include <cmath>
#include <vector>
#include "io.cpp"
using namespace std;



int main() {
    etoile e1, e2;
    e1.creeretoile();
    e2.creeretoile();

    double dt = 1e3;  // Pas de temps (en secondes)
    double r, fx, fy;
    vector<pair<double, double>> positions_e1, positions_e2; // Vecteurs pour stocker les positions

    // On commence avec une vitesse initiale nulle
    e1.set_vitesse(0, 0);
    e2.set_vitesse(0, 0);

    // Boucle de simulation
    for (int i = 0; i < 10000; ++i) {
        // Calculer la distance entre les deux étoiles
        r = sqrt(pow(e2.getx() - e1.getx(), 2) + pow(e2.gety() - e1.gety(), 2));

        // Calcul de la force gravitationnelle
        fx = G * e1.getmass() * e2.getmass() * (e2.getx() - e1.getx()) / pow(r, 3);
        fy = G * e1.getmass() * e2.getmass() * (e2.gety() - e1.gety()) / pow(r, 3);

        // Calcul de l'accélération sur chaque étoile
        e1.calcul_acceleration(fx / e1.getmass(), fy / e1.getmass());
        e2.calcul_acceleration(-fx / e2.getmass(), -fy / e2.getmass());

        // Mise à jour des positions
        e1.mise_a_jour_position(dt);
        e2.mise_a_jour_position(dt);

        // Stocker les positions pour le tracé
        positions_e1.push_back({e1.getx(), e1.gety()});
        positions_e2.push_back({e2.getx(), e2.gety()});
    }

    // Afficher les positions stockées
    for (int i = 0; i < positions_e1.size(); i++) {
        cout << "Etoile 1 - Position: (" << positions_e1[i].first << ", " << positions_e1[i].second << ")\n";
        cout << "Etoile 2 - Position: (" << positions_e2[i].first << ", " << positions_e2[i].second << ")\n";
    }
menu();
    return 0;
}
