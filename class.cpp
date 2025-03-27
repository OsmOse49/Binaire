#ifndef CLASS_CPP
#define CLASS_CPP
#include "class.h"
#include <cmath>
#include <string>
using namespace std;

const double G = 6.67430e-11;  // Constante gravitationnelle

etoile::etoile() : m(0), x(0), y(0), vx(0), vy(0), nom (""){}

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

void etoile::set_mass(){
    double newm;
    cout<<"Quelle est la nouvelle masse de l'etoile ?";
    cin>>newm;
    m=newm;

}
void etoile::set_x(){
    double newx;
    cout<<"Quelle est la nouvelle poisition x de l'etoile ?";
    cin>>newx;
    x=newx;
}
void etoile::set_y(){
    double newy;
    cout<<"Quelle est la nouvelle position y de l'etoile ?";
    cin>>newy;
    y=newy;
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


#endif
