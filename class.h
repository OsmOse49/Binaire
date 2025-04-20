#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Le header permet de déclarer les classes et fonctions

const double G = 6.67430e-11;
const double AU = 1.496e11;
const double M_SUN = 1.989e30;
const double c = 299792458;

struct Velocity {
    double vx, vy, vz;
};

struct Position {
private:
    double x, y, z;
public:
    Position();
    Position(double a,double b, double c);
    ~Position();
    double& getx() { return x; }; // Retourne une référence pour modification
    double& gety() { return y; };
    double& getz() { return z; };

    const double& getx() const { return x; }; // Const pour l'accès en lecture seulement
    const double& gety() const { return y; };
    const double& getz() const { return z; };

    void setx(double val) { x = val; };
    void sety(double val) { y = val; };
    void setz(double val) { z = val; };
};



class etoile {
private:
    double m, x, y, z, vx, vy, vz, r;
    string nom;
public:
    etoile();
    ~etoile();
    double getx()const;
    double gety()const;
    double getz()const;
    double getvx()const;
    double getvy()const;
    double getvz()const;
    double getmass()const;
    double getr()const;
    string getnom()const;

    void creeretoile();
    void afficheetoile();
    void set_mass();
    void set_x();
    void set_y();
    void set_z();
    void setvx(double newvx);
    void setvy(double newvy);
    void setvz(double newvz);
    void setx(double newx);
    void sety(double newy);
    void setz(double newz);
    


    double pulsation(const etoile& e1, const etoile& e2);
    double ratiomasse(const etoile& e1, const etoile& e2);
    double massetot(const etoile& e1, const etoile& e2);
    double energieOG(const etoile& e1, const etoile& e2);
};

// Fonctions amies
double distance(const etoile& e1, const etoile& e2);
Position gravitationalForce(const etoile& e1, const etoile& e2);
void calculateOrbitalVelocities(etoile& e1, etoile& e2);
etoile updateStarReturn(const etoile& e, const Position& force, double dt, const etoile& autre);
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2);


#endif
