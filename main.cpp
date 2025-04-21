/*
    Ceci est le fichier main, il fait appel aux définitions, variables privées et publiques, fonctions, classes, structures... crées dans le fichier class.cpp ainsi qu'au menu crée dans io.cpp
    Le main est le fichier qui est exécuté lorsque l'on compile le code
*/


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

    double dt = 10; // Pas de temps en secondes
    double totalTime = 10e6; // Simuler pendant 1 an 

    // Boucle pour mettre à jour les positions et vitesses
    for (double t = 0; t < totalTime; t += dt) {

        // Calculer la force gravitationnelle entre les deux étoiles
        Position force = gravitationalForce(e1, e2);

        // Calculer les nouvelles positions et vitesses des deux étoiles avec RK4 (mise à jour croisée)
        etoile newE1 = updateStarReturnRK4(e1, force, dt, e2);
        etoile newE2 = updateStarReturnRK4(e2, {-force.getx(), -force.gety(), -force.getz()}, dt, e1);

        // Mise à jour des vraies étoiles après calculs
        e1 = newE1;
        e2 = newE2;

        // Enregistrer les positions dans le fichier tous les 30 jours
        if (static_cast<int>(t / dt) % 30 == 0) {
            writeToFile(dataFile, t / 86400, e1, e2);  
        }
    }

    // Fermer le fichier
    dataFile.close();

    std::cout << "Les Donnees ont ete enregistrees dans data.txt avec succes." << std::endl << std::endl;

menu(e1,e2);

    return 0;
}