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
    double r; //rayon
    string nom;

public:
    etoile();        // Constructeur
    ~etoile();       // Destructeur

    double getx();   // Getter pour x
    double gety();   // Getter pour y
    double getmass(); // Getter pour la masse
    double getr ();  // Getter pour le rayon
    string getnom(); // Getter pour le nom

    void afficheetoile(); // Affichage de l'étoile
    void creeretoile();   // Création de l'étoile
    void set_mass(); //setter pour la masse
    void set_x(); //setter pour la position en x
    void set_y(); //setter pour la position en y
    void set_vitesse(double vx, double vy); // Setter pour la vitesse
    void mise_a_jour_position(double dt); // Met à jour la position après un petit intervalle de temps
    void calcul_acceleration(double ax, double ay); // Calcule l'accélération
    double pulsation (etoile e1, etoile e2); //calcul de la pulsation
    double ratiomasse (etoile e1, etoile e2); //calcul du ratio des masses    
    double massetot (etoile e1, etoile e2); //calcul de la masse totale 
    double energieOG (etoile e1, etoile e2); //calcul des OG
};

#endif
