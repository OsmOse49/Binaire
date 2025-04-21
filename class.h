/*
    Ceci est le header, c'est à dire l'interface du fichier class.
    Il contient tout ce que le compilateur doit connaitre: définitions, variables privées et publiques, fonctions, classes, structures...
    Il permet de déclarer
*/


#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//définition des constantes utilisées

const double G = 6.67430e-11;
const double AU = 1.496e11;
const double M_SUN = 1.989e30;
const double c = 299792458;
/*
    Creation des structures, elles permettent de regrouper des variables dans une nouvelle entité.
    Les éléments de la strucutre sont souvent utilisés pour des données simples comme des coordonnées
*/
struct Velocity {
    double vx, vy, vz;
};

struct Position {
private:
    double x, y, z; //on choisi de mettre les éléments sensibles en privés pour plus de sécurité
public:
    Position(); //création des paramètres initialisés à 0 au cas ou l'espace dédié comporterait déjà des valeurs
    Position(double a,double b, double c); //initialisation des paramètres
    ~Position(); //destruction
    double& getx() { return x; }; // Permet d'accéder aux valeurs privées
    double& gety() { return y; };
    double& getz() { return z; };

    const double& getx() const { return x; }; // on ajoute const pour permettre l'accès en lecture seulement
    const double& gety() const { return y; };
    const double& getz() const { return z; };

    void setx(double val) { x = val; }; //Permet de modifier les valeurs
    void sety(double val) { y = val; };
    void setz(double val) { z = val; };
};

/*
    La classe agit comme la structure mais permet également d'utiliser l'héritage et les méthodes. On l'utilise pour des données complexes
*/

class etoile {
private:
    double m, x, y, z, vx, vy, vz, r;
    string nom;
public:
    etoile(); //constructeur    
    ~etoile(); //destructeur
    double getx()const; //fonctions qui permettent d'accéder aux données privées dites "accesseurs" ou "getters"
    double gety()const;
    double getz()const;
    double getvx()const;
    double getvy()const;
    double getvz()const;
    double getmass()const;
    double getr()const;
    string getnom()const;

    void creeretoile(); //fonction qui demande à l'utilisateur de saisir les paramètres de l'étoile
    void afficheetoile(); //fonction qui affiche les paramètres
    void set_mass(); //fonctions qui permettent de modifier dites "setters"
    void set_x();
    void set_y();
    void set_z();
    void setvx(double newvx);
    void setvy(double newvy);
    void setvz(double newvz);
    void setx(double newx);
    void sety(double newy);
    void setz(double newz);
    
};

// Fonctions amies
double distance(const etoile& e1, const etoile& e2); //fonction qui calcule la distance entre deux positions
Position gravitationalForce(const etoile& e1, const etoile& e2); //fonction qui calcule la force gravitationnelle entre deux étoilmes
void calculateOrbitalVelocities(etoile& e1, etoile& e2); //fonction qui permet de calculer la vitesse circulaire d'une étoile
etoile updateStarReturn(const etoile& e, const Position& force, double dt, const etoile& autre); //fonction qui permet de calculer la vitesse orbitale à l'aide de la méthode Runge-Kutta
void writeToFile(std::ofstream& file, double time, const etoile& e1, const etoile& e2); //fonction qui permet d'enregistrer les données dans un fichier


#endif //permet de s'assurer que le contenu du fichier ne sera inclus qu'une seule fois lors de la compilation
