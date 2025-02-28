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

int main() {
    // Initialisation des conditions initiales
    x = 1.496e11;  
    y = 0;
    vx = 0;
    vy = 29800;    
    ax = 0;
    ay = 0;


    for (int i = 0; i < 1000; ++i) {
        calcul(x, y, ax, ay);
        retour(vx, vy, x, y, ax, ay);

        std::cout << "Temps : " << i * dt << " s, Position : (" << x << ", " << y << ")\n";
    }

    return 0;
}
