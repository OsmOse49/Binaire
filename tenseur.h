#ifndef TENSEUR_H
#define RENSEUR_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class tenseur {
private:
    int T[4][4];

public:
    tenseur();        // Constructeur
    ~tenseur();       // Destructeur
    double gettenseur (int i, int j);
    void remplirtenseur ();
    void affichetenseur ();
    
};
#endif

