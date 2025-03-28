#include "class2.h"
#include <iostream>

int main() {
    // Ouvrir le fichier pour l'écriture des données
    std::ofstream dataFile("data.txt");

    // Vérifier si le fichier s'est bien ouvert
    if (!dataFile) {
        std::cerr << "Impossible d'ouvrir le fichier data.txt pour l'écriture." << std::endl;
        return 1;
    }

    // Définir les étoiles en demandant à l'utilisateur les valeurs
    Star star1, star2;

    // Demander les paramètres pour la première étoile
    std::cout << "Entrez la masse de la première étoile (en kg) : ";
    std::cin >> star1.mass;
    std::cout << "Entrez la position de la première étoile (x, y, z) en mètres : ";
    std::cin >> star1.position.x >> star1.position.y >> star1.position.z;
    std::cout << "Entrez la vitesse de la première étoile (vx, vy, vz) en m/s : ";
    std::cin >> star1.velocity.vx >> star1.velocity.vy >> star1.velocity.vz;

    // Demander les paramètres pour la deuxième étoile
    std::cout << "Entrez la masse de la deuxième étoile (en kg) : ";
    std::cin >> star2.mass;
    std::cout << "Entrez la position de la deuxième étoile (x, y, z) en mètres : ";
    std::cin >> star2.position.x >> star2.position.y >> star2.position.z;
    std::cout << "Entrez la vitesse de la deuxième étoile (vx, vy, vz) en m/s : ";
    std::cin >> star2.velocity.vx >> star2.velocity.vy >> star2.velocity.vz;

    double dt = 10; // Pas de temps en secondes
    double totalTime = 365.25 * 24 * 3600; // Simuler pendant 1 an 

    // Boucle pour mettre à jour les positions et vitesses
    for (double t = 0; t < totalTime; t += dt) {
        // Calculer la force gravitationnelle entre les deux étoiles
        Position force = gravitationalForce(star1, star2);

        // Mettre à jour les positions et vitesses des deux étoiles
        updateStar(star1, force, dt);
        updateStar(star2, {-force.x, -force.y, -force.z}, dt); // Force opposée pour la deuxième étoile

        // Enregistrer les positions dans le fichier tous les 30 jours 
        if (static_cast<int>(t / dt) % 30 == 0) {
            writeToFile(dataFile, t / 86400, star1, star2);  
        }
    }

    // Fermer le fichier
    dataFile.close();

    std::cout << "Données enregistrées dans data.txt." << std::endl;
    return 0;
}
