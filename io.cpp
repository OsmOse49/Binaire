#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
//Nouvelles variables
double newx;
double newvy;

//Creation du menu:
void menu()
{
    int choix=0;
    do{
        cout<<"Que desirez-vous faire ?"<<endl;
        cout<<"Saisissez le numero correspondant a votre choix"<<endl;
        cout<<"1.Changer la position"<<endl;
        cout<<"2.Changer la vitesse"<<endl;
        cout<<"3.Changer la position et la vitesse"<<endl;
        cout<<"4.Quitter"<<endl;

    cin>>choix;

    if (choix != 1 && choix != 2 && choix !=3 && choix !=4)
    {
        cout<<"choix invalide, veuillez ressaisir un numéro"<<endl;
        return menu();
    }
    if(choix ==1)
    {
        cout<<"Saississez la nouvelle valeur de x:"<<endl;
        cin>>newx;
        newx=x;
        for (int i = 0; i < 1000; ++i) 
        {
        calcul(x, y, ax, ay);
        retour(vx, vy, x, y, ax, ay);

        std::cout << "Temps : " << i * dt << " s, Position : (" << x << ", " << y << ")\n";
        }
    }
    if(choix==2)
    {
        cout<<"Saisissez la nouvelle valeur de vy"<<endl;
        cin>>newvy;
        newvy=vy;
        for (int i = 0; i < 1000; ++i) 
        {
        calcul(x, y, ax, ay);
        retour(vx, vy, x, y, ax, ay);

        std::cout << "Temps : " << i * dt << " s, Position : (" << x << ", " << y << ")\n";
        }
    }
    if(choix==3)
    {
        cout<<"Saisissez la nouvelle valeur de x:"<<endl;
        cin>>newx;
        cout<<"Saisissez la nouvelle valeur de vy"<<endl;
        cin>>newvy;
        newx=x;
        newvy=vy;
        for (int i = 0; i < 1000; ++i) 
        {
        calcul(x, y, ax, ay);
        retour(vx, vy, x, y, ax, ay);

        std::cout << "Temps : " << i * dt << " s, Position : (" << x << ", " << y << ")\n";
        }
    }
    if(choix ==4)
    {
        exit(0);
    }
    }
        while(choix > 4);

    
}