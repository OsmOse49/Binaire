#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include "class.cpp"
#include <fstream>

using namespace std;

//Nouvelles variables

double r, fx, fy;
double dt = 10; // Pas de temps en secondes
double totalTime = 10e6; // Simuler pendant 1 an 

//Creation du menu:
void menu(etoile& e1, etoile& e2)

{
    int choix=0;
    do{
        cout<<"Bienvenue dans ce menu : Desormais que desirez-vous faire ?"<<endl;
        cout<<"Saisissez le numero correspondant a votre choix"<<endl;
        cout<< '\t'<<"1.Changer la masse d'une etoile "<<endl;
        cout<< '\t'<<"2.Changer la masse des deux etoiles "<<endl;
        cout<< '\t'<<"3.Changer la position d'une etoile"<<endl;
        cout<< '\t'<<"4.Changer la position des deux etoiles"<<endl;
        cout<< '\t'<<"5.Changer la masse et la position d'une etoile"<<endl;
        cout<< '\t'<<"6.Changer la masse et la position des deux etoiles"<<endl;
        cout<< '\t'<<"7.Quitter"<<endl;

    cin>>choix;
    }while (choix !=1 && choix !=2 && choix !=3 && choix !=4 && choix !=5 && choix !=6 && choix !=7 ); // l'utilisateur doit saisir un nombre entre 1 et 7
    if (choix != 1 && choix != 2 && choix !=3 && choix !=4 && choix !=5 && choix !=6 && choix !=7)
    {
        cout<<"choix invalide, veuillez ressaisir un numéro"<<endl;
        return menu(e1,e2);
    } // si l'utilisateur choisi un nombre invalide le message d'erreur s'affiche et la boucle recommence 
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
    } //permet de quitter le programme 

    // une fois les variables souhaitées modifiées, le programme se relance

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
        
        ofstream dataFile;
        dataFile.open("Data.txt");
            if (!dataFile)
            {
                cout << "Error : File couldn't be openend" << endl;
            }

        // Enregistrer les positions dans le fichier tous les 30 jours
        if (static_cast<int>(t / dt) % 30 == 0) {
            writeToFile(dataFile, t / 86400, e1, e2);  
        }
        
        // Fermer le fichier
        dataFile.close();

        std::cout << "Données enregistrées dans data.txt." << std::endl;
    }
        
}