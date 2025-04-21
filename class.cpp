/*
    Ce fichier regroupe les définitions, variables privées et publiques, fonctions, classes, structures... de façon détaillées
    Il permet d'implémenter
*/
#ifndef CLASS_CPP
#define CLASS_CPP
#include "class.h"
#include <cmath>
#include <string>
using namespace std;



etoile::etoile() : m(0), x(0), y(0), z(0), vx(0), vy(0), vz(0),nom (""){} //constructeur de la classe initialisé à 0 pour s'assurer de ne pas avoir des valeurs préremplies
etoile::~etoile() {} // destructeur de la classe

Position::Position() : x(0), y(0), z(0) {} //constructeur qui initialise à 0
Position::Position(double a, double b, double c) //constructeur qui initialise avec les valeurs souhaitées
{
    x=a, y=b, z=c;
}
Position::~Position() {} // destructeur de la classe


double etoile::getx() const { return x; } //comme les variables sont privée on ajoute des accesseurs 
double etoile::gety() const { return y; }
double etoile::getz() const { return z; }
double etoile::getvx() const { return vx; }
double etoile::getvy() const { return vy; }
double etoile::getvz() const { return vz; }
double etoile::getmass()const { return m; }
string etoile::getnom() const { return nom; }

void etoile::afficheetoile() {
    cout << "L'etoile " << nom << " est à la position (" << x << ", " << y << ") avec une masse " << m << endl;
}

void etoile::creeretoile() {
    cout << "Comment s'appelle l'etoile ? ";
    cin >> nom;
    cout << "Quelle est la position x de l'etoile ? (en m) ";
    cin >> x;
    cout << "Quelle est la position y de l'etoile ? (en m) ";
    cin >> y;
    cout << "Quelle est la position z de l'etoile ? (en m) ";
    cin >> z;

    cout << "Quelle est la masse de l'etoile (en kg)? ";
    cin >> m;

    cout << endl;
    // Initialisation des vitesses à zéro
    vx = 0;
    vy = 0;
    vz = 0;
} //on demande à l'utilisateur de saisir les données

void etoile::set_mass(){
    double newm;
    cout<<"Quelle est la nouvelle masse de l'etoile ?";
    cin>>newm;
    m=newm;

} //création de setters qui permettent de modifier nos données qui sont privées
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

void etoile::setvx(double newvx) { vx = newvx; }
void etoile::setvy(double newvy) { vy = newvy; }
void etoile::setvz(double newvz) { vz = newvz; }

void etoile::setx(double newx) { x = newx; }
void etoile::sety(double newy) { y = newy; }
void etoile::setz(double newz) { z = newz; }


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
    double f = G * e1.getmass() * e2.getmass() / (r * r);
    Position force = {
        f * (e2.getx() - e1.getx()) / r,
        f * (e2.gety() - e1.gety()) / r,
        f * (e2.getz() - e1.getz()) / r
    };
    return force;
}

void calculateOrbitalVelocities(etoile& e1, etoile& e2) {
    // vecteur de séparation
    double dx = e2.getx() - e1.getx();
    double dy = e2.gety() - e1.gety();
    double dz = e2.getz() - e1.getz();
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    if (r < 1e6) r = 1e6; // Assurer une distance minimale

    // vecteur radial unitaire
    double ux = dx / r;
    double uy = dy / r;
    // vecteur tangentiel unitaire (dans le plan XY)
    double tx = -uy;
    double ty = ux;

    // vitesse circulaire (relative)
    double M = e1.getmass() + e2.getmass();
    double v_circ = sqrt(G * M / r);  // Vitesse circulaire de chaque étoile

    // répartition des vitesses pour chaque étoile en fonction de leurs masses
    double v1 = v_circ * (e2.getmass() / M);
    double v2 = v_circ * (e1.getmass() / M);

    // étoile 1 : tangentiel uniquement
    e1.setvx(tx * v1);
    e1.setvy(ty * v1);
    e1.setvz(0);

    // étoile 2 : opposé tangentiel
    e2.setvx(-tx * v2);
    e2.setvy(-ty * v2);
    e2.setvz(0);
}


/// Fonction pour calculer les vitesses orbitales des deux étoiles avec RK4
etoile updateStarReturnRK4(const etoile& e, const Position& force, double dt, const etoile& autre) {
    etoile updated = e;

    // Calcul des positions et vitesses relatives
    Position r_vec = {
        autre.getx() - e.getx(),
        autre.gety() - e.gety(),
        autre.getz() - e.getz()
    };
    double r = sqrt(r_vec.getx() * r_vec.getx() + r_vec.gety() * r_vec.gety() + r_vec.getz() * r_vec.getz());
    if (r < 1e6) r = 1e6;  // Sécuriser contre une distance trop petite

    // Calcul de l'accélération gravitationnelle
    Position a_grav = {
        force.getx() / e.getmass(),
        force.gety() / e.getmass(),
        force.getz() / e.getmass()
    };

    // Calcul de la vitesse relative
    Position v_rel = {
        autre.getvx() - e.getvx(),
        autre.getvy() - e.getvy(),
        autre.getvz() - e.getvz()
    };

    // Produit scalaire v . r
    double v_dot_r = v_rel.getx() * r_vec.getx() + v_rel.gety() * r_vec.gety() + v_rel.getz() * r_vec.getz();

    // Dissipation gravitationnelle (modèle de Peters-Mathews simplifié)
    double coef = -(32.0 / 5.0) * pow(G, 3.5) * (e.getmass() * autre.getmass() / (e.getmass() + autre.getmass())) * (e.getmass() + autre.getmass()) * sqrt(e.getmass() + autre.getmass()) / (pow(c, 5) * pow(r, 4.5));

    // Calcul de l'accélération due aux ondes gravitationnelles
    Position a_gw = {
        coef * v_dot_r * r_vec.getx() / r / e.getmass(),
        coef * v_dot_r * r_vec.gety() / r / e.getmass(),
        coef * v_dot_r * r_vec.getz() / r / e.getmass()
    };

    // Accélération totale
    Position a_tot = {
        a_grav.getx() + a_gw.getx(),
        a_grav.gety() + a_gw.gety(),
        a_grav.getz() + a_gw.getz()

    };

    // Variables de stockage pour RK4
    Position k1v, k2v, k3v, k4v;
    Position k1p, k2p, k3p, k4p;
    
    // Calcul des différentes étapes de Runge-Kutta
    // 1. k1
    k1v.getx() = a_tot.getx() * dt;
    k1v.gety() = a_tot.gety() * dt;
    k1v.getz() = a_tot.getz() * dt;

    k1p.getx() = e.getvx() * dt;
    k1p.gety() = e.getvy() * dt;
    k1p.getz() = e.getvz() * dt;

    // 2. k2
    k2v.getx() = (a_tot.getx() + 0.5 * k1v.getx()) * dt;
    k2v.gety() = (a_tot.gety() + 0.5 * k1v.gety()) * dt;
    k2v.getz() = (a_tot.getz() + 0.5 * k1v.getz()) * dt;


    k2p.getx() = (e.getvx() + 0.5 * k1v.getx()) * dt;
    k2p.gety() = (e.getvy() + 0.5 * k1v.gety()) * dt;
    k2p.getz() = (e.getvz() + 0.5 * k1v.getz()) * dt;

    // 3. k3
    k3v.getx() = (a_tot.getx() + 0.5 * k2v.getx()) * dt;
    k3v.gety() = (a_tot.gety() + 0.5 * k2v.gety()) * dt;
    k3v.getz() = (a_tot.getz() + 0.5 * k2v.getz()) * dt;


    k3p.getx() = (e.getvx() + 0.5 * k2v.getx()) * dt;
    k3p.gety() = (e.getvy() + 0.5 * k2v.gety()) * dt;
    k3p.getz() = (e.getvz() + 0.5 * k2v.getz()) * dt;

    // 4. k4
    k4v.getx() = (a_tot.getx() + k3v.getx()) * dt;
    k4v.gety() = (a_tot.gety() + k3v.gety()) * dt;
    k4v.getz() = (a_tot.getz() + k3v.getz()) * dt;


    k4p.getx() = (e.getvx() + k3v.getx()) * dt;
    k4p.gety() = (e.getvy() + k3v.gety()) * dt;
    k4p.getz() = (e.getvz() + k3v.getz()) * dt;

    // Mise à jour des vitesses et positions
    updated.setvx(updated.getvx() + ((k1v.getx() + 2.0 * k2v.getx() + 2.0 * k3v.getx() + k4v.getx()) / 6.0) );
    updated.setvy(updated.getvy() + ((k1v.gety() + 2.0 * k2v.gety() + 2.0 * k3v.gety() + k4v.gety()) / 6.0) ); 
    updated.setvz(updated.getvz() + ((k1v.getz() + 2.0 * k2v.getz() + 2.0 * k3v.getz() + k4v.getz()) / 6.0) ); 

    updated.setx(updated.getx() + ((k1p.getx() + 2.0 * k2p.getx() + 2.0 * k3p.getx() + k4p.getx()) / 6.0) );
    updated.sety(updated.gety() + ((k1p.gety() + 2.0 * k2p.gety() + 2.0 * k3p.gety() + k4p.gety()) / 6.0) );
    updated.setz(updated.getz() + ((k1p.getz() + 2.0 * k2p.getz() + 2.0 * k3p.getz() + k4p.getz()) / 6.0) );

    return updated;
}


// Fonction pour enregistrer les données dans un fichier
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2) {
    file << time << " " 
         << e1.getx() / AU << " " << e1.gety() / AU << " " << e1.getz() / AU << " "
         << e2.getx() / AU << " " << e2.gety() / AU << " " << e2.getz() / AU << "\n";
}
        
#endif //permet de s'assurer que le contenu du fichier ne sera inclus qu'une seule fois lors de la compilation

