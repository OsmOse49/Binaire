#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const double G = 6.67430e-11;
const double AU = 1.496e11;
const double M_SUN = 1.989e30;
const double c = 299792458;

struct Velocity {
    double vx, vy, vz;
};

struct Position {
    double x, y, z;
};

class etoile {
public:
    double m, x, y, z, vx, vy, vz, r;
    string nom;

    etoile();
    ~etoile();
    double getx()const;
    double gety()const;
    double getz()const;
    double getmass();
    double getr();
    string getnom();

    void creeretoile();
    void afficheetoile();
    void set_mass();
    void set_x();
    void set_y();
    void set_z();

    double pulsation(const etoile& e1, const etoile& e2);
    double ratiomasse(const etoile& e1, const etoile& e2);
    double massetot(const etoile& e1, const etoile& e2);
    double energieOG(const etoile& e1, const etoile& e2);
};

// Fonctions amies
double distance(const etoile& e1, const etoile& e2);
Position gravitationalForce(const etoile& e1, const etoile& e2);
void calculateOrbitalVelocities(etoile& e1, etoile& e2);
void updateStar(etoile& e, const Position& force, double dt);
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2);

#endif
