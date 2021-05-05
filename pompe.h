#ifndef POMPE_H
#define POMPE_H


#include <iostream>
using namespace std;
#define pompeSecondaire 10
#define pompePrimaire 11
#define MARCHE 20
#define ARRET 21
#define PANNE 22
#define UTILISEE 20800

class Pompe
{
protected:
    int type;
    int etat;

public:
    Pompe();
    Pompe(int t);
    ~Pompe();

    void demarrerP();
    void arreterP();
    void panneP();
    int getEtat();
    int setEtat(int val);
};

#endif // POMPE_H
