#ifndef CLASS2_H
#define CLASS2_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

// Constantes physiques
const double G = 6.67430e-11; // Constante gravitationnelle en m^3 kg^-1 s^-2
const double AU = 1.496e11; // Unité astronomique en mètres (distance Terre-Soleil)
const double M_SUN = 1.989e30; // Masse solaire en kg

// Structure représentant la position en 3D
struct Position {
    double x, y, z;
};

// Structure représentant la vitesse en 3D
struct Velocity {
    double vx, vy, vz;
};

// Structure représentant une étoile
struct Star {
    double mass;  // Masse en kilogrammes
    Position position; // Position de l'étoile
    Velocity velocity; // Vitesse de l'étoile
};

// Fonction pour calculer la distance entre deux positions
double distance(const Position& p1, const Position& p2);

// Fonction pour calculer la force gravitationnelle entre deux étoiles
Position gravitationalForce(const Star& star1, const Star& star2);

// Fonction pour mettre à jour la position et la vitesse d'une étoile selon la force gravitationnelle
void updateStar(Star& star, const Position& force, double dt);

// Fonction pour enregistrer les données dans un fichier
void writeToFile(std::ofstream& file, double time, const Star& star1, const Star& star2);

#endif // CLASS_H
