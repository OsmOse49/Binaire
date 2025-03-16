#include <iostream>
#include <string>
using namespace std;

class etoile {
private:
    double m;
    double x;
    double y;
    string nom;
public:
    etoile ();
    ~etoile ();
double getx ();
double gety ();
double getmass ();
string getnom();
void afficheetoile();
void creeretoile ();
};
