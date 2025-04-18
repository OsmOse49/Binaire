#include "class2.h"

// Fonction pour calculer la distance entre deux positions
double distance(const Position& p1, const Position& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

// Fonction pour calculer la force gravitationnelle entre deux étoiles
Position gravitationalForce(const Star& star1, const Star& star2) {
    double r = distance(star1.position, star2.position);
    double forceMagnitude = (G * star1.mass * star2.mass) / (r * r);

    // Direction de la force (du centre de masse de l'une vers l'autre)
    Position forceDirection = {star2.position.x - star1.position.x, 
                               star2.position.y - star1.position.y, 
                               star2.position.z - star1.position.z};

    // Normaliser la direction
    double norm = sqrt(forceDirection.x * forceDirection.x + forceDirection.y * forceDirection.y + forceDirection.z * forceDirection.z);
    forceDirection.x /= norm;
    forceDirection.y /= norm;
    forceDirection.z /= norm;

    // Multiplier par la force
    Position force = {forceDirection.x * forceMagnitude, 
                      forceDirection.y * forceMagnitude, 
                      forceDirection.z * forceMagnitude};

    return force;
}

void calculateOrbitalVelocities(Star& star1, Star& star2) {
    // Vecteur de séparation
    double dx = star2.position.x - star1.position.x;
    double dy = star2.position.y - star1.position.y;
    double dz = star2.position.z - star1.position.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    // Unité perpendiculaire au vecteur de séparation (plan XY uniquement)
    double ux = -dy / r;
    double uy = dx / r;

    // Centre de masse (CM)
    double totalMass = star1.mass + star2.mass;
    double r1 = (star2.mass / totalMass) * r;
    double r2 = (star1.mass / totalMass) * r;

    // Vitesse nécessaire pour orbite circulaire
    double v = sqrt(G * totalMass / r); // vitesse relative

    // Chaque étoile tourne autour du CM, donc leurs vitesses sont proportionnelles à leurs distances au CM
    double v1 = v * (r1 / r);
    double v2 = v * (r2 / r);

    // Appliquer les vitesses perpendiculaires à la ligne de séparation
    star1.velocity.vx = ux * v1;
    star1.velocity.vy = uy * v1;
    star1.velocity.vz = 0;

    star2.velocity.vx = -ux * v2;
    star2.velocity.vy = -uy * v2;
    star2.velocity.vz = 0;
}


// Fonction pour mettre à jour la position et la vitesse d'une étoile selon la force gravitationnelle
void updateStar(Star& star, const Position& force, double dt) {
    // Accélération : F = ma => a = F / m
    Velocity acceleration = {force.x / star.mass, force.y / star.mass, force.z / star.mass};

    // Mise à jour de la vitesse : v = v0 + a * dt
    star.velocity.vx += acceleration.vx * dt;
    star.velocity.vy += acceleration.vy * dt;
    star.velocity.vz += acceleration.vz * dt;

    // Mise à jour de la position : r = r0 + v * dt
    star.position.x += star.velocity.vx * dt;
    star.position.y += star.velocity.vy * dt;
    star.position.z += star.velocity.vz * dt;
}


// Fonction pour enregistrer les données dans un fichier
void writeToFile(std::ofstream& file, double time, const Star& star1, const Star& star2) {
    file << time << " " 
         << star1.position.x / AU << " " << star1.position.y / AU << " " << star1.position.z / AU << " "
         << star2.position.x / AU << " " << star2.position.y / AU << " " << star2.position.z / AU << "\n";
}