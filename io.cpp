#include <iostream>
#include <fstream>
#include "class2.h"

// Fonction de menu pour interagir avec les étoiles
void menu(Star& e1, Star& e2, std::vector<std::pair<double, double>>& positions_e1, std::vector<std::pair<double, double>>& positions_e2, std::ofstream& dataFile) {
    int choix = 0;
    do {
        std::cout << "Que desirez-vous faire ?" << std::endl;
        std::cout << "1. Changer la masse d'une etoile" << std::endl;
        std::cout << "2. Changer la masse des deux etoiles" << std::endl;
        std::cout << "3. Changer la position d'une etoile" << std::endl;
        std::cout << "4. Changer la position des deux etoiles" << std::endl;
        std::cout << "5. Changer la masse et la position d'une etoile" << std::endl;
        std::cout << "6. Changer la masse et la position des deux etoiles" << std::endl;
        std::cout << "7. Quitter" << std::endl;
        std::cin >> choix;

        if (choix == 1) {
            int etoile_choisie;
            std::cout << "Quelle etoile desirez-vous modifier ? (1 pour " << e1.get_name() << ", 2 pour " << e2.get_name() << "): ";
            std::cin >> etoile_choisie;
            if (etoile_choisie == 1) {
                e1.set_mass();
            } else if (etoile_choisie == 2) {
                e2.set_mass();
            }
        } else if (choix == 2) {
            e1.set_mass();
            e2.set_mass();
        } else if (choix == 3) {
            int etoile_choisie;
            std::cout << "Quelle etoile desirez-vous modifier ? (1 pour " << e1.get_name() << ", 2 pour " << e2.get_name() << "): ";
            std::cin >> etoile_choisie;
            if (etoile_choisie == 1) {
                e1.set_position();
            } else if (etoile_choisie == 2) {
                e2.set_position();
            }
        } else if (choix == 4) {
            e1.set_position();
            e2.set_position();
        } else if (choix == 5) {
            int etoile_choisie;
            std::cout << "Quelle etoile desirez-vous modifier ? (1 pour " << e1.get_name() << ", 2 pour " << e2.get_name() << "): ";
            std::cin >> etoile_choisie;
            if (etoile_choisie == 1) {
                e1.set_mass();
                e1.set_position();
            } else if (etoile_choisie == 2) {
                e2.set_mass();
                e2.set_position();
            }
        } else if (choix == 6) {
            e1.set_mass();
            e1.set_position();
            e2.set_mass();
            e2.set_position();
        } else if (choix == 7) {
            exit(0); // Quitter le programme
        }

        // Mettre à jour et enregistrer les positions dans le fichier
        writeToFile(dataFile, 0.0
