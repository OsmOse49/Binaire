
#include <iostream>
#include <cmath>
#include "header.h"
#include "Projet.cpp"
#include "io.cpp"

using namespace std;
int main() {
    // Initialisation des conditions initiales
    x = 1.496e11;  
    y = 0;
    vx = 0;
    vy = 29800;    
    ax = 0;
    ay = 0;
void menu();
void calcul(double x, double y, double &ax, double &ay);
void retour(double &vx, double &vy, double &x, double &y, double ax, double ay);

    for (int i = 0; i < 1000; ++i) {
        calcul(x, y, ax, ay);
        retour(vx, vy, x, y, ax, ay);

        std::cout << "Temps : " << i * dt << " s, Position : (" << x << ", " << y << ")\n";
    }
menu();
    return 0;
}
