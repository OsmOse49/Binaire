#ifndef CLASS_CPP
#define CLASS_CPP
#include "class.h"
#include <cmath>
#include <string>
using namespace std;



etoile::etoile() : m(0), x(0), y(0), z(0), vx(0), vy(0), vz(0), r(0),nom (""){}

etoile::~etoile() {}

double etoile::getx() const { return x; }
double etoile::gety() const { return y; }
double etoile::getz() const { return z; }
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
    cout << "Quelle est la position z de l'etoile ? ";
    cin >> z;
    cout << "Quelle est la masse de l'etoile ? ";
    cin >> m;
    cout<<"Quel est le rayon de l'etoile ?";
    cin >> r;
    // Initialisation des vitesses à zéro
    vx = 0;
    vy = 0;
    vz = 0;
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
void etoile::set_z(){
    double newz;
    cout<<"Quelle est la nouvelle position z de l'etoile ?";
    cin>>newz;
    z=newz;
}


double etoile::pulsation(const etoile& e1, const etoile& e2) {
    return sqrt(G * massetot(e1, e2) / pow(e1.r, 3));
}

double etoile::ratiomasse(const etoile& e1, const etoile& e2) {
    return (e1.m * e2.m) / pow(e1.m + e2.m, 2);
}

double etoile::massetot(const etoile& e1, const etoile& e2) {
    return e1.m + e2.m;
}

double etoile::energieOG(const etoile& e1, const etoile& e2) {
    double w = pulsation(e1, e2);
    double mr = massetot(e1, e2) * ratiomasse(e1, e2);
    return (2.0 / 5.0) * pow(G * mr, 2) * pow(e1.r, 4) * pow(w, 6) / pow(c, 5);
}

   
// Fonction pour calculer la distance entre deux positions
double distance(const etoile& e1, const etoile& e2)
{
     return sqrt(pow(e2.getx() - e1.getx(), 2) + 
                pow(e2.gety() - e1.gety(), 2) + 
                pow(e2.getz() - e1.getz(), 2));
}

// Fonction pour calculer la force gravitationnelle entre deux étoiles
Position gravitationalForce(const etoile& e1, const etoile& e2) {
    double r = distance(e1, e2);
    double f = G * e1.m * e2.m / (r * r);
    Position force = {
        f * (e2.x - e1.x) / r,
        f * (e2.y - e1.y) / r,
        f * (e2.z - e1.z) / r
    };
    return force;
}

void calculateOrbitalVelocities(etoile& e1, etoile& e2) {
   double dx = e2.x - e1.x, dy = e2.y - e1.y, dz = e2.z - e1.z;
    double r = sqrt(dx * dx + dy * dy + dz * dz);
    double ux = -dy / r, uy = dx / r;
    double M = e1.m + e2.m;
    double r1 = (e2.m / M) * r;
    double r2 = (e1.m / M) * r;
    double v = sqrt(G * M / r);
    e1.vx = ux * v * (r1 / r); e1.vy = uy * v * (r1 / r);
    e2.vx = -ux * v * (r2 / r); e2.vy = -uy * v * (r2 / r);

}


// Fonction pour mettre à jour la position et la vitesse d'une étoile selon la force gravitationnelle
void updateStar(etoile& e, const Position& force, double dt) {
 Position a = {force.x / e.m, force.y / e.m, force.z / e.m};
    e.vx += a.x * dt; e.vy += a.y * dt; e.vz += a.z * dt;
    e.x += e.vx * dt; e.y += e.vy * dt; e.z += e.vz * dt;

}


// Fonction pour enregistrer les données dans un fichier
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2) {
    file << time << " " 
         << e1.x / AU << " " << e1.y / AU << " " << e1.z / AU << " "
         << e2.x / AU << " " << e2.y / AU << " " << e2.z / AU << "\n";
}
#endif
