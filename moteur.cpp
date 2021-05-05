#include "moteur.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;


Moteur::Moteur()
{
    conso=CONSO;
    etat=ARRETM;
}

Moteur::~Moteur(){cout<<"destruction moteur"<<endl;}

void Moteur::arreterM(){etat=ARRETM;}

void Moteur::demarrerM(){etat=MARCHEM;}

int Moteur::getEtat(){return etat;}

int Moteur::setEtat(int val){etat=val;}
