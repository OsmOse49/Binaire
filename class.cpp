#include "class.h"

#include <iostream>
using namespace std;

etoile::etoile()
{
    x=0;
    y=0;
    m=0;
}
etoile::~etoile()
{

}

    double etoile::getx ()
    {
        return x;
    }
    double etoile::gety ()
    {
        return y;
    }
    double etoile::getmass ()
    {
        return m;
    }
    string etoile::getnom()
    {
        return nom;
    }
    void etoile::creeretoile ()
    {
        cout<<"Comment s'appelle l'etoile ?"<<endl;
        cin>>nom;
        cout<<"Quelle est la position x de l'etoile ?"<<endl;
        cin>>x;
        cout<<"Quelle est la position y de l'etoile ?"<<endl;
        cin>>y;
        cout<<"Quelle est la masse de l'etoile ?"<<endl;
        cin>>m;
    }
    void etoile::afficheetoile()
    {
        cout<<"L'etoile est: "<<nom<<" ("<<x<<","<<y<<")"<<" de masse "<<m<<endl;
    }
    

