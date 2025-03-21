#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class etoile {
private:
    double m;       // Masse
    double x, y;    // Position
    double vx, vy;  // Vitesse
    string nom;

public:
    etoile();        // Constructeur
    ~etoile();       // Destructeur

    double getx();   // Getter pour x
    double gety();   // Getter pour y
    double getmass(); // Getter pour la masse
    string getnom(); // Getter pour le nom

    void afficheetoile(); // Affichage de l'étoile
    void creeretoile();   // Création de l'étoile
    void set_mass();
    void set_x();
    void set_y();
    void set_vitesse(double vx, double vy); // Setter pour la vitesse
    void mise_a_jour_position(double dt); // Met à jour la position après un petit intervalle de temps
    void calcul_acceleration(double ax, double ay); // Calcule l'accélération
};

#endif
