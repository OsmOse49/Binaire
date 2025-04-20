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
    // vecteur de séparation
    double dx = e2.x - e1.x;
    double dy = e2.y - e1.y;
    double dz = e2.z - e1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    if (r < 1e6) r = 1e6; // Assurer une distance minimale

    // vecteur radial unitaire
    double ux = dx / r;
    double uy = dy / r;
    // vecteur tangentiel unitaire (dans le plan XY)
    double tx = -uy;
    double ty = ux;

    // vitesse circulaire (relative)
    double M = e1.m + e2.m;
    double v_circ = sqrt(G * M / r);  // Vitesse circulaire de chaque étoile

    // répartition des vitesses pour chaque étoile en fonction de leurs masses
    double v1 = v_circ * (e2.m / M);
    double v2 = v_circ * (e1.m / M);

    // étoile 1 : tangentiel uniquement
    e1.vx = tx * v1;
    e1.vy = ty * v1;
    e1.vz = 0;

    // étoile 2 : opposé tangentiel
    e2.vx = -tx * v2;
    e2.vy = -ty * v2;
    e2.vz = 0;
}


/// Fonction pour calculer les vitesses orbitales des deux étoiles avec RK4
etoile updateStarReturnRK4(const etoile& e, const Position& force, double dt, const etoile& autre) {
    etoile updated = e;

    // Calcul des positions et vitesses relatives
    Position r_vec = {
        autre.x - e.x,
        autre.y - e.y,
        autre.z - e.z
    };
    double r = sqrt(r_vec.x * r_vec.x + r_vec.y * r_vec.y + r_vec.z * r_vec.z);
    if (r < 1e6) r = 1e6;  // Sécuriser contre une distance trop petite

    // Calcul de l'accélération gravitationnelle
    Position a_grav = {
        force.x / e.m,
        force.y / e.m,
        force.z / e.m
    };

    // Calcul de la vitesse relative
    Position v_rel = {
        autre.vx - e.vx,
        autre.vy - e.vy,
        autre.vz - e.vz
    };

    // Produit scalaire v . r
    double v_dot_r = v_rel.x * r_vec.x + v_rel.y * r_vec.y + v_rel.z * r_vec.z;

    // Dissipation gravitationnelle (modèle de Peters-Mathews simplifié)
    double coef = -(32.0 / 5.0) * pow(G, 3.5) * (e.m * autre.m / (e.m + autre.m)) * (e.m + autre.m) * sqrt(e.m + autre.m) / (pow(c, 5) * pow(r, 4.5));

    // Calcul de l'accélération due aux ondes gravitationnelles
    Position a_gw = {
        coef * v_dot_r * r_vec.x / r / e.m,
        coef * v_dot_r * r_vec.y / r / e.m,
        coef * v_dot_r * r_vec.z / r / e.m
    };

    // Accélération totale
    Position a_tot = {
        a_grav.x + a_gw.x,
        a_grav.y + a_gw.y,
        a_grav.z + a_gw.z
    };

    // Variables de stockage pour RK4
    Position k1v, k2v, k3v, k4v;
    Position k1p, k2p, k3p, k4p;
    
    // Calcul des différentes étapes de Runge-Kutta
    // 1. k1
    k1v.x = a_tot.x * dt;
    k1v.y = a_tot.y * dt;
    k1v.z = a_tot.z * dt;

    k1p.x = e.vx * dt;
    k1p.y = e.vy * dt;
    k1p.z = e.vz * dt;

    // 2. k2
    k2v.x = (a_tot.x + 0.5 * k1v.x) * dt;
    k2v.y = (a_tot.y + 0.5 * k1v.y) * dt;
    k2v.z = (a_tot.z + 0.5 * k1v.z) * dt;

    k2p.x = (e.vx + 0.5 * k1v.x) * dt;
    k2p.y = (e.vy + 0.5 * k1v.y) * dt;
    k2p.z = (e.vz + 0.5 * k1v.z) * dt;

    // 3. k3
    k3v.x = (a_tot.x + 0.5 * k2v.x) * dt;
    k3v.y = (a_tot.y + 0.5 * k2v.y) * dt;
    k3v.z = (a_tot.z + 0.5 * k2v.z) * dt;

    k3p.x = (e.vx + 0.5 * k2v.x) * dt;
    k3p.y = (e.vy + 0.5 * k2v.y) * dt;
    k3p.z = (e.vz + 0.5 * k2v.z) * dt;

    // 4. k4
    k4v.x = (a_tot.x + k3v.x) * dt;
    k4v.y = (a_tot.y + k3v.y) * dt;
    k4v.z = (a_tot.z + k3v.z) * dt;

    k4p.x = (e.vx + k3v.x) * dt;
    k4p.y = (e.vy + k3v.y) * dt;
    k4p.z = (e.vz + k3v.z) * dt;

    // Mise à jour des vitesses et positions
    updated.vx += (k1v.x + 2.0 * k2v.x + 2.0 * k3v.x + k4v.x) / 6.0;
    updated.vy += (k1v.y + 2.0 * k2v.y + 2.0 * k3v.y + k4v.y) / 6.0;
    updated.vz += (k1v.z + 2.0 * k2v.z + 2.0 * k3v.z + k4v.z) / 6.0;

    updated.x += (k1p.x + 2.0 * k2p.x + 2.0 * k3p.x + k4p.x) / 6.0;
    updated.y += (k1p.y + 2.0 * k2p.y + 2.0 * k3p.y + k4p.y) / 6.0;
    updated.z += (k1p.z + 2.0 * k2p.z + 2.0 * k3p.z + k4p.z) / 6.0;

    return updated;
}




// Fonction pour enregistrer les données dans un fichier
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2) {
    file << time << " " 
         << e1.x / AU << " " << e1.y / AU << " " << e1.z / AU << " "
         << e2.x / AU << " " << e2.y / AU << " " << e2.z / AU << "\n";
}
#endif

