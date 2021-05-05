#include "pompe.h"
using namespace std;
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>

Pompe::Pompe()
{
    type=pompePrimaire;
    etat=ARRET;
}

Pompe::Pompe(int t){
    type=t;
    etat=ARRET;
}

Pompe::~Pompe(){cout<<"destruction pompe"<<endl;}

void Pompe::arreterP(){etat=ARRET;}

void Pompe::demarrerP(){etat=MARCHE;}

void Pompe::panneP(){etat=PANNE;}

int Pompe::getEtat(){return etat;}

int Pompe::setEtat(int val){etat=val;}
