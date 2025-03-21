#include "class.h"
#include <cmath>

const double G = 6.67430e-11;  // Constante gravitationnelle

etoile::etoile() : m(0), x(0), y(0), vx(0), vy(0) {}

etoile::~etoile() {}

double etoile::getx() { return x; }
double etoile::gety() { return y; }
double etoile::getmass() { return m; }
string etoile::getnom() { return nom; }

void etoile::afficheetoile() {
    cout << "L'etoile " << nom << " est à la position (" << x << ", " << y << ") avec une masse " << m << endl;
}

void etoile::creeretoile() {
    cout << "Comment s'appelle l'etoile ? ";
    cin >> nom;
    cout << "Quelle est la position x de l'etoile ? ";
    cin >> x;
    cout << "Quelle est la position y de l'etoile ? ";
    cin >> y;
    cout << "Quelle est la masse de l'etoile ? ";
    cin >> m;
    // Initialisation des vitesses à zéro
    vx = 0;
    vy = 0;
}

void etoile::set_vitesse(double v_x, double v_y) {
    vx = v_x;
    vy = v_y;
}

void etoile::mise_a_jour_position(double dt) {
    x += vx * dt;
    y += vy * dt;
}

void etoile::calcul_acceleration(double ax, double ay) {
    vx += ax;
    vy += ay;
}



