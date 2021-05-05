#ifndef MOTEUR_H
#define MOTEUR_H
#include "pompe.h"

#include "vanne.h"
#include <iostream>


#define CONSO 50
#define MARCHEM 60
#define ARRETM 61

class Moteur
{

protected:
    int conso;
    int etat;

public:
    Moteur();
    void demarrerM();
    void arreterM();
    ~Moteur();
    int getEtat();
    int setEtat(int val);
};

#endif // MOTEUR_H
