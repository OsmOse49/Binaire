#ifndef CLASS_CPP
#define CLASS_CPP
#include "class.h"
#include <cmath>
#include <string>
using namespace std;

const double G = 6.67430e-11;  // Constante gravitationnelle
double c= 3*10e8; //celerite

etoile::etoile() : m(0), x(0), y(0), vx(0), vy(0), r(0),nom (""){}

etoile::~etoile() {}

double etoile::getx() { return x; }
double etoile::gety() { return y; }
double etoile::getmass() { return m; }
double etoile::getr() { return r; }
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
    cout<<"Quel est le rayon de l'etoile ?";
    cin >> r;
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

double etoile::pulsation (etoile e1, etoile e2) // pulsation de l'etoile 1 (e1,e2), de l'etoile 2 (e2,e1)
{
    double w =sqrt((G*massetot(e1,e2))/pow(e1.r,3));
    return w; 
}
double etoile::ratiomasse(etoile e1, etoile e2)
{
    double n=(e1.getmass()*e2.getmass())/pow(e1.getmass()+e2.getmass(),2);
    return n;
}

double etoile::massetot(etoile e1, etoile e2)
{
    double M=e1.getmass()+e2.getmass();
    return M;
}
double etoile::energieOG (etoile e1, etoile e2)
{
    double E= (2/5)*(G*pow(massetot(e1,e2)*ratiomasse(e1,e2),2)*pow(e1.r,4)*pow(pulsation(e1,e2),6))/pow(c,4);
    return E;
}
   

#endif
