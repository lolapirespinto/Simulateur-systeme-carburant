#include "reservoir.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//constructeurs
Reservoir::Reservoir()
{
    nom="reservoir anonyme";
    capacite =200;
    etat=PLEIN;
    pompeP= new Pompe(pompePrimaire);
    pompeS= new Pompe(pompeSecondaire);
    m=new Moteur();
}

Reservoir::Reservoir(int c, string n){
    nom=n;
    capacite =c;
    etat=c;
    pompeP= new Pompe(pompePrimaire);
    pompeS= new Pompe(pompeSecondaire);
    m= new Moteur();
}

//destructeur
Reservoir::~Reservoir(){
    cout<<"destruction du reservoir "<<getNom()<<endl;
}

//getters et setters
string Reservoir::getNom(){return nom;}

int Reservoir::getEtat(){return etat;}

int Reservoir::getCapa(){return capacite;}

int Reservoir::setEtat(int val){etat=val;}
