#ifndef RESERVOIR_H
#define RESERVOIR_H
#include "pompe.h"

#include <iostream>
#include "moteur.h"
#include <string.h>
using namespace std;

#define PLEIN 200
#define VIDE 0
#define ALIMENTE 770

class Reservoir
{
    friend class Pompe;
    friend class Moteur;

protected:
    string nom;
    int capacite;
    int etat;
    Moteur *m;



public:

    Pompe *pompeP = new Pompe(pompePrimaire);
    Pompe *pompeS = new Pompe(pompeSecondaire);
    Reservoir();
    Reservoir(int c, string n);
    ~Reservoir();
    string getNom();
    int getEtat();
    int getCapa();
    int setEtat(int val);
};


#endif //RESERVOIR_H
