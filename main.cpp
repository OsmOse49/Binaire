#include "class.h"
#include "class.cpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "io.cpp"
using namespace std;
#include <fstream>


int main() {
    
    

    // Creation des etoiles
    etoile e1, e2;
    e1.creeretoile();
    e2.creeretoile();
    
    
    // Ouvrir le fichier pour l'écriture des données
    std::ofstream dataFile("data.txt");

    // Vérifier si le fichier s'est bien ouvert
    if (!dataFile) {
        std::cerr << "Impossible d'ouvrir le fichier data.txt pour l'écriture." << std::endl;
        return 1;
    }

    // Calculer les vitesses orbitales des étoiles
    calculateOrbitalVelocities(e1, e2);

    double dt = 8000; // Pas de temps en secondes
    double totalTime = 365.25 * 24 * 7200; // Simuler pendant 1 an 

    // Boucle pour mettre à jour les positions et vitesses
    for (double t = 0; t < totalTime; t += dt) {
        // Calculer la force gravitationnelle entre les deux étoiles
        Position force = gravitationalForce(e1, e2);

        // Mettre à jour les positions et vitesses des deux étoiles
        updateStar(e1, force, dt);
        updateStar(e2, {-force.x, -force.y, -force.z}, dt); // Force opposée pour la deuxième étoile

        // Enregistrer les positions dans le fichier tous les 30 jours 
        if (static_cast<int>(t / dt) % 30 == 0) {
            writeToFile(dataFile, t / 86400, e1, e2);  
        }
    }

    // Fermer le fichier
    dataFile.close();

    std::cout << "Données enregistrées dans data.txt." << std::endl;

menu(e1,e2);

    return 0;
}

