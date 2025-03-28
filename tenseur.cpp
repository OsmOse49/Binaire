#include "tenseur.h"
#include <cmath>
#include <string>
using namespace std;

//constructeur
tenseur::tenseur ()
    {
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                T[i][j] = 0;
            }
        }
    }
//destructeur                    
tenseur::~tenseur () {}


//fonctions
double tenseur::gettenseur(int i, int j) { return T[i][j];}
void tenseur::remplirtenseur()
{
        for (int i = 0; i < 4; ++i) 
        {   
            for (int j = 0; j < 4; ++j) 
            {       cout<<"Quelle est la valeur comprise a la position ("<<i<<";"<<j<<")?"<<endl;
                    cin>>T[i][j];
            }
        }
}
void tenseur::affichetenseur()
{  
    cout<<"La matrice du tenseur est: "<<endl;
     for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
               cout<<T[i][j];
            }
            cout<<endl;
        }

}
