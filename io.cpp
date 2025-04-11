#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include "class.cpp"
#include <fstream>

using namespace std;

//Nouvelles variables

double r, fx, fy;
double dt = 8000; // Pas de temps en secondes
double totalTime = 365.25 * 24 * 7200; // Simuler pendant 1 an 

//Creation du menu:
void menu(etoile& e1, etoile& e2)

{
    int choix=0;
    do{
        cout<<"Que desirez-vous faire ?"<<endl;
        cout<<"Saisissez le numero correspondant a votre choix"<<endl;
        cout<<"1.Changer la masse d'une etoile "<<endl;
        cout<<"2.Changer la masse des deux etoiles "<<endl;
        cout<<"3.Changer la position d'une etoile"<<endl;
        cout<<"4.Changer la position des deux etoiles"<<endl;
        cout<<"5.Changer la masse et la position d'une etoile"<<endl;
        cout<<"6.Changer la masse et la position des deux etoiles"<<endl;
        cout<<"7.Quitter"<<endl;

    cin>>choix;
    }while (choix !=1 && choix !=2 && choix !=3 && choix !=4 && choix !=5 && choix !=6 && choix !=7 );
    if (choix != 1 && choix != 2 && choix !=3 && choix !=4 && choix !=5 && choix !=6 && choix !=7)
    {
        cout<<"choix invalide, veuillez ressaisir un numéro"<<endl;
        return menu(e1,e2);
    }
    if(choix ==1)
    {   
        int choix=0;
        do {
            cout<<"Quelle etoile desirez vous modifier ? Saisissez le numero correspondant a l'etoile:"<<endl;
            cout<<"1."<<e1.getnom()<<endl;
            cout<<"2."<<e2.getnom()<<endl;
            cin>>choix;
        } while( choix !=1 && choix !=2);
        
    if (choix == 1 )
    {
        e1.set_mass();
    }
   if (choix == 2 )
    {
        e2.set_mass();
    }
    }

    if(choix==2)
    {
        
        e1.set_mass();

        e2.set_mass();
           
    }
    
    if (choix==3)
    {
            int choix=0;
        do {
            cout<<"Quelle etoile desirez vous modifier ? Saisissez le numero correspondant a l'etoile:"<<endl;
            cout<<"1."<<e1.getnom()<<endl;
            cout<<"2."<<e2.getnom()<<endl;
             cin>>choix;
        } while (choix !=1 && choix !=2);
       
    if (choix == 1 )
    {
    
        e1.set_x();
        e1.set_y();
        e1.set_z();
    }
    if (choix == 2 )
    {
        
        e2.set_x();
        e2.set_y();
        e2.set_z();
    }
    }
    if (choix==4)
    {
        
        e1.set_x();
        e1.set_y();
        e1.set_z();
        e2.set_x();
        e2.set_y();
        e2.set_z();
    }
   if (choix==5)
   {
        int choix=0;
        do {
            cout<<"Quelle etoile desirez vous modifier ? Saisissez le numero correspondant a l etoile:"<<endl;
            cout<<"1."<<e1.getnom()<<endl;
            cout<<"2."<<e2.getnom()<<endl;
            cin>>choix;
        } while(choix !=1 && choix !=2);
        
    if (choix == 1 )
    {
        
        e1.set_mass();
        e1.set_x();
        e1.set_y();
        e1.set_z();
    }

    if (choix == 2 )
    {
        
        e2.set_mass();
        e2.set_x();
        e2.set_y();
        e2.set_z();
    }
        
   }
   if (choix==6)
   {
    
        e1.set_mass();
        e1.set_x();
        e1.set_y();
        e1.set_z();
        e2.set_mass();
        e2.set_x();
        e2.set_y();
        e2.set_z();
   }
    if(choix ==7)
    {
        exit(0);
    }
    
     // Calculer les vitesses orbitales des étoiles
    calculateOrbitalVelocities(e1, e2);

   ofstream dataFile("resultats_simulation.txt");


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
        
}