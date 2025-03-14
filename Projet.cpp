#include <iostream>
#include <cmath>

// Constantes physiques
const double G = 6.67430e-11; 
const double M1 = 3e30; 
const double dt = 1e5;

// Variables de position et vitesse
double x, y; 
double vx, vy;
double ax, ay;

// Fonction pour calculer l'accélération
void calcul(double x, double y, double &ax, double &ay) {
    double r = std::sqrt(x * x + y * y);
    double force = -G * (M1 / (r * r));
    ax = force * (x / r);
    ay = force * (y / r);
}

// Fonction pour mettre à jour la position et la vitesse
void retour(double &vx, double &vy, double &x, double &y, double ax, double ay) {
    vx += ax * dt;
    vy += ay * dt;

    x += vx * dt;
    y += vy * dt;
}


//Creation du menu:
void menu()
{
    int choix=0;
    do{
        cout<<"Que desirez-vous faire ?"<<endl;
        cout<<"Saisissez le numero correspondant a votre choix"<<endl;
        cout<<"1."
    }
}