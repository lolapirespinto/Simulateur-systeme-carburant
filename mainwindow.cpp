#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vanne.h"
#include <string>
#include "connexion.h"
#include <QTextEdit>
#include <fstream>
#include "windows.h"
using namespace std;





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    //au lancement les pompes primaire fonctionnent
     ui->setupUi(this);

   /*file= new QFile("leot.txt");

     file->open(QIODevice::WriteOnly | QIODevice::Text);



     flux->setCodec("UTF-8");
     flux << "Test de Leo Lamoureux:"<< endl;
     flux << "flux"<< endl;


     QTextEdit *zoneTexte=new QTextEdit;
     zoneTexte->setGeometry(100,100,400,200);
     zoneTexte->setReadOnly(true);
     QString fileName = "leot.txt";
     QFile fichier(fileName);
     if(fichier.open( QIODevice::ReadOnly | QIODevice::Text))
     {
         fileName = fichier.readAll();
         fichier.close();
      }
          zoneTexte->setText(fileName);
          zoneTexte->show();

*/



     tank1.pompeP->setEtat(MARCHE);
      tank2.pompeP->setEtat(MARCHE);
       tank3.pompeP->setEtat(MARCHE);
    //initialisation des couleurs
     vert.setColor(QPalette::Background,QColor::fromRgb(85, 170, 127));
     rouge.setColor(QPalette::Background,QColor::fromRgb(255, 94, 94));
     noir.setColor(QPalette::Background, Qt::black);
     blanc.setColor(QPalette::Background, Qt::white);



    //progressbar tank1


    m_pb = new QProgressBar(this);
    m_pb->setGeometry(10, 10, 120, 20);

    m_pb->setRange(0,tank1.getCapa());
    m_pb->setValue(tank1.getEtat());
    m_pb->setFormat("%v /%m");

    m_pb->move(593,115);


    //progressbar tank2

    m_pb2 = new QProgressBar(this);
    m_pb2->setGeometry(10, 10, 120, 20);

    m_pb2->setRange(0,tank2.getCapa());
    m_pb2->setValue(tank2.getEtat());
    m_pb2->setFormat("%v /%m");

    m_pb2->move(853,115);


    //progressbar tank3

    m_pb3 = new QProgressBar(this);
    m_pb3->setGeometry(10, 10, 120, 20);

    m_pb3->setRange(0,tank3.getCapa());
    m_pb3->setValue(tank3.getEtat());
    m_pb3->setFormat("%v /%m");

    m_pb3->move(1093,115);
   /* m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_pb, SLOT(setValue(int)));*/





     //les vannes
    VT12ouverte = new QWidget(this);
    VT12ouverte->setGeometry(270,270,21,4);
    VT12ouverte->move(770,68);
    VT12ouverte->setAutoFillBackground(true);
    VT12ouverte->setPalette(blanc);
    VT12ouverte->hide();

    VT12fermee = new QWidget(this);
    VT12fermee->setGeometry(270,270,4,21);
    VT12fermee->move(778,60);
    VT12fermee->setAutoFillBackground(true);

    VT23ouverte = new QWidget(this);
    VT23ouverte->setGeometry(270,270,21,4);
    VT23ouverte->move(1020,67);
    VT23ouverte->setAutoFillBackground(true);
    VT23ouverte->setPalette(blanc);
    VT23ouverte->hide();

    VT23fermee = new QWidget(this);
    VT23fermee->setGeometry(270,270,4,21);
    VT23fermee->move(1028,60);
    VT23fermee->setAutoFillBackground(true);

    V13ouverte = new QWidget(this);
    V13ouverte->setGeometry(270,270,21,4);
    V13ouverte->move(950,208);
    V13ouverte->setAutoFillBackground(true);
    V13ouverte->setPalette(blanc);
    V13ouverte->hide();

    V13fermee = new QWidget(this);
    V13fermee->setGeometry(270,270,4,21);
    V13fermee->move(958,201);
    V13fermee->setAutoFillBackground(true);

    V12ouverte = new QWidget(this);
    V12ouverte->setGeometry(270,270,21,4);
    V12ouverte->move(760,297);
    V12ouverte->setAutoFillBackground(true);
    V12ouverte->setPalette(blanc);
    V12ouverte->hide();

    V12fermee = new QWidget(this);
    V12fermee->setGeometry(270,270,4,21);
    V12fermee->move(768,290);
    V12fermee->setAutoFillBackground(true);
    V12fermee->setPalette(blanc);

    V23ouverte = new QWidget(this);
    V23ouverte->setGeometry(270,270,21,4);
    V23ouverte->move(1020,338);
    V23ouverte->setAutoFillBackground(true);
    V23ouverte->setPalette(blanc);
    V23ouverte->hide();

    V23fermee = new QWidget(this);
    V23fermee->setGeometry(270,270,4,21);
    V23fermee->move(1028,331);
    V23fermee->setAutoFillBackground(true);
    V23fermee->setPalette(blanc);


    //les moteurs

    M1marche = new QWidget(this);
    M1marche->setGeometry(0,0,81,151);
    M1marche->move(600,380);
    M1marche->setAutoFillBackground(true);
    M1marche->setPalette(vert);
    M1marche->show();

    M2marche = new QWidget(this);
    M2marche->setGeometry(0,0,81,151);
    M2marche->move(860,380);
    M2marche->setAutoFillBackground(true);
    M2marche->setPalette(vert);
    M2marche->show();

    M3marche = new QWidget(this);
    M3marche->setGeometry(0,0,81,151);
    M3marche->move(1120,380);
    M3marche->setAutoFillBackground(true);
    M3marche->setPalette(vert);
    M3marche->show();

    M1arret = new QWidget(this);
    M1arret->setGeometry(0,0,81,151);
    M1arret->move(600,380);
    M1arret->setAutoFillBackground(true);
    M1arret->setPalette(rouge);
    M1arret->hide();

    M2arret = new QWidget(this);
    M2arret->setGeometry(0,0,81,151);
    M2arret->move(860,380);
    M2arret->setAutoFillBackground(true);
    M2arret->setPalette(rouge);
    M2arret->hide();

    M3arret = new QWidget(this);
    M3arret->setGeometry(0,0,81,151);
    M3arret->move(1120,380);
    M3arret->setAutoFillBackground(true);
    M3arret->setPalette(rouge);
    M3arret->hide();


demo =OFF;
}

MainWindow::~MainWindow()
{
    delete ui;
}



//remplir tank1
void MainWindow::on_pushButton_clicked()
{

      tank1.setEtat(PLEIN)  ;
      m_pb->setValue(tank1.getEtat());
      if(M1.getEtat()==ARRETM && VT12.getEtat()==FERME && V12.getEtat()==FERME && V13.getEtat()==FERME){

          M1.demarrerM();
          M1marche->show();
          M1arret->hide();
      }
}

//bouton vidange tank1
void MainWindow::on_pushButton_2_clicked()
{


    if (VT12.getEtat()==FERME){
        tank1.setEtat(VIDE);
        m_pb->setValue(tank1.getEtat());
        cout<<"Tank 1 : "<<tank1.getEtat()<<endl;
    }

    if( VT12.getEtat()==OUVERT){
        tank1.setEtat(tank2.getEtat()/2);
        m_pb->setValue(tank1.getEtat());
        tank2.setEtat(tank2.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
          cout<<"Tank 1 : "<<tank1.getEtat()<<", Tank1 alimenté par tank2 !"<<endl;

    }



    if(tank1.getEtat()<1){tank1.setEtat(VIDE);}
    if(tank2.getEtat()<1){tank2.setEtat(VIDE);}



    if (tank1.getEtat()==VIDE && V13.getEtat()==FERME && V12.getEtat()==FERME){
        M1.arreterM();
        M1arret->show();
        M1marche->hide();
          cout<<"M1 plus alimente, tank1 VIDE"<<endl;
    }

    if (tank1.getEtat()==VIDE && V13.getEtat()==FERME && V12.getEtat()==FERME && V23.getEtat()==FERME && VT12.getEtat()==OUVERT && tank2.getEtat()==VIDE){
        M1.arreterM();
        M1arret->show();
        M1marche->hide();
          cout<<"M1 plus alimente, tank1 VIDE"<<endl;
          M2.arreterM();
          M2arret->show();
          M2marche->hide();
            cout<<"M2 plus alimente, tank2 VIDE"<<endl;

    }
    if (tank1.getEtat()==VIDE && V13.getEtat()==OUVERT && V12.getEtat()==FERME && tank3.getEtat()!=VIDE)
    {  if (M1.getEtat()==ARRETM){
            M1.demarrerM();
            M1marche->show();
            M1arret->hide();
              cout<<"M1 alimente par tank3"<<endl;
        }
    }
    if (tank1.getEtat()==VIDE && V12.getEtat()==OUVERT && V13.getEtat()==FERME && tank2.getEtat()!=VIDE)
    {  if (M1.getEtat()==ARRETM){
            M1.demarrerM();
            M1marche->show();
            M1arret->hide();
            cout<<"M1 alimente par tank2"<<endl;
        }
    }
    if (tank1.getEtat()==VIDE && V13.getEtat()==OUVERT && V12.getEtat()==OUVERT
            && (tank2.getEtat()!=VIDE || tank3.getEtat()!=VIDE))
    {  if (M1.getEtat()==ARRETM){
            M1.demarrerM();
            M1marche->show();
            M1arret->hide();
            cout<<"M1 alimente par un des autres moteurs !"<<endl;
        }
    }

}


//bouton vidange tank3
void MainWindow::on_pushButton_4_clicked()
{


    if (VT23.getEtat()==FERME){
        tank3.setEtat(VIDE);
        m_pb3->setValue(tank3.getEtat());
        cout<<"Tank 3 : VIDE, "<<tank3.getEtat()<<endl;
    }

    if( VT23.getEtat()==OUVERT){
        tank3.setEtat(tank2.getEtat()/2);
        m_pb3->setValue(tank3.getEtat());
        tank2.setEtat(tank2.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
          cout<<"Tank 3 : "<<tank3.getEtat()<<", Tank3 alimente par tank2 !"<<endl;

    }

    if(tank3.getEtat()<1){tank3.setEtat(VIDE);}
    if(tank2.getEtat()<1){tank2.setEtat(VIDE);}

    if (tank3.getEtat()==VIDE && V13.getEtat()==FERME && V23.getEtat()==FERME){
        M3.arreterM();
        M3arret->show();
        M3marche->hide();
          cout<<"M3 plus alimente, tank3 VIDE"<<endl;
    }
    if (tank3.getEtat()==VIDE && V13.getEtat()==OUVERT && V23.getEtat()==FERME && tank1.getEtat()!=VIDE)
    {  if (M3.getEtat()==ARRETM){
            M3.demarrerM();
            M3marche->show();
            M3arret->hide();
              cout<<"M3 alimente par tank1"<<endl;
        }
    }
    if (tank3.getEtat()==VIDE && V23.getEtat()==OUVERT && V13.getEtat()==FERME && tank2.getEtat()!=VIDE)
    {  if (M3.getEtat()==ARRETM){
            M3.demarrerM();
            M3marche->show();
            M3arret->hide();
            cout<<"M3 alimente par tank2"<<endl;
        }
    }
    if (tank3.getEtat()==VIDE && V23.getEtat()==OUVERT && V13.getEtat()==OUVERT
            && (tank2.getEtat()!=VIDE || tank1.getEtat()!=VIDE))
    {  if (M3.getEtat()==ARRETM){
            M3.demarrerM();
            M3marche->show();
            M3arret->hide();
            cout<<"M3 alimente par un des autres moteurs !"<<endl;
        }
    }


}

//ouverture V23
void MainWindow::on_pushButton_5_clicked()
{
    V23.ouvrirV();
    V23fermee->hide();
    V23ouverte->show();
    if(V23.getEtat()==30){cout<<"vanne V23 OUVERTE"<<endl;}
                     else{cout<<"vanne V23 FERMEE"<<endl; }

    if ((tank2.getEtat()==VIDE || (tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET))
             && tank3.getEtat()!=VIDE
            && (((tank3.pompeP->getEtat()==MARCHE && tank3.pompeS->getEtat()==MARCHE))
            || ((tank3.pompeP->getEtat()==MARCHE || tank3.pompeS->getEtat()==MARCHE) && M3.getEtat()==ARRETM))){
        if (M2.getEtat()==ARRETM){
            M2.demarrerM();
            M2marche->show();
            M2arret->hide();
        }
    }

    if ((tank3.getEtat()==VIDE || (tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET))
      && tank2.getEtat()!=VIDE
            && (((tank2.pompeP->getEtat()==MARCHE && tank2.pompeS->getEtat()==MARCHE))
            || ((tank2.pompeP->getEtat()==MARCHE || tank2.pompeS->getEtat()==MARCHE) && M2.getEtat()==ARRETM))){

            M3.demarrerM();
            M3marche->show();
            M3arret->hide();

    }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "ouverture V23" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}

void MainWindow::on_pushButton_6_clicked()
{
    V23.fermerV();
    V23ouverte->hide();
    V23fermee->show();

    if(V23.getEtat()==30){cout<<"vanne V23 OUVERTE"<<endl;}
                     else{cout<<"vanne V23 FERMEE"<<endl; }
    if((tank2.getEtat()==VIDE || (tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET)) && V12.getEtat()==FERME){
        M2.arreterM();
        M2marche->hide();
        M2arret->show();

    }
    if ((tank3.getEtat()==VIDE || (tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET)) && V13.getEtat()==FERME){
        M3.arreterM();
        M3marche->hide();
        M3arret->show();
    }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "fermeture V23" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}
//démarrer P12
void MainWindow::on_pushButton_7_clicked()
{
    tank1.pompeS->demarrerP();
    tank1.pompeS->setEtat(MARCHE);
    if(tank1.pompeS->getEtat()==MARCHE){
        M1.demarrerM();
        M1marche->show();
        M1arret->hide();
        cout<<"pompe P12 (pompeS tank1) MARCHE"<<endl;}
                     else{cout<<"pompe P12 (pompeS tank1) ARRET"<<endl; }


    if (demo == ON){
    if(tank1.pompeS->getEtat()==MARCHE){cout<<"bien joue"<<endl;

    tank1.setEtat(VIDE);
    m_pb->setValue(tank1.getEtat());
    cout<<"le probleme de pompe est repare mais le tank1 n'a maintenant plus de carburant !\n aidez le"<<endl;
    M1.arreterM();
    M1marche->hide();
    M1arret->show();


}
    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "demarrer P12" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }



    }

}
//bouton arret pompe P12
void MainWindow::on_pushButton_8_clicked()
{
    tank1.pompeS->arreterP();
    if (tank1.pompeP->getEtat()==PANNE
            || (V13.getEtat()==OUVERT && (tank3.getEtat()==VIDE ||( tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET))
                && M3.getEtat()==MARCHE)
            || (V12.getEtat()==OUVERT && (tank2.getEtat()==VIDE ||( tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET))
                && M2.getEtat()==MARCHE)
            ){
        M1.arreterM();
        M1marche->hide();
        M1arret->show();
    }
    if(tank1.pompeS->getEtat()==20){cout<<"pompe P12 (pompeS tank1) MARCHE"<<endl;}
                     else{cout<<"pompe P12 (pompeS tank1) ARRET"<<endl; }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "arret P12" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}
//demarrer P22
void MainWindow::on_pushButton_9_clicked()
{
    tank2.pompeS->demarrerP();
    tank2.pompeS->setEtat(MARCHE);
    if(tank2.pompeS->getEtat()==MARCHE){
        M2.demarrerM();
        M2marche->show();
        M2arret->hide();
    cout<<"pompe P22 (pompeS tank2) MARCHE"<<endl;}
                     else{cout<<"pompe P22 (pompeS tank2) ARRET"<<endl; }

    if (demo==ON && tank1.getEtat()==VIDE && tank1.pompeP->getEtat()==PANNE){

        cout<<"1 ere etape bonnne"<<endl;


    }
    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "demarrer P22" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}

//arreter P22
void MainWindow::on_pushButton_10_clicked()
{
    tank2.pompeS->arreterP();
    if (tank2.pompeP->getEtat()==PANNE
            || (V23.getEtat()==OUVERT && (tank3.getEtat()==VIDE ||( tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET))
                && M3.getEtat()==MARCHE)
            || (V12.getEtat()==OUVERT && (tank1.getEtat()==VIDE ||( tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET))
                && M1.getEtat()==MARCHE)
            ){
        M2.arreterM();
        M2marche->hide();
        M2arret->show();
    }


    if(tank2.pompeS->getEtat()==20){cout<<"pompe P22 (pompeS tank2) MARCHE"<<endl;}
                     else{cout<<"pompe P22 (pompeS tank2) ARRET"<<endl; }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "arret P22" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}

//demarrer P32
void MainWindow::on_pushButton_11_clicked()
{
    tank3.pompeS->demarrerP();
    if(tank3.pompeS->getEtat()==MARCHE){
        M3.demarrerM();
        M3marche->show();
        M3arret->hide();cout<<"pompe P32 (pompeS tank3) MARCHE"<<endl;}
                     else{cout<<"pompe P32 (pompeS tank3) ARRET"<<endl; }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "demarrer P32" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}
//arreter P32
void MainWindow::on_pushButton_12_clicked()
{
    tank3.pompeS->arreterP();
    if (tank3.pompeP->getEtat()==PANNE
            || (V13.getEtat()==OUVERT && (tank1.getEtat()==VIDE ||( tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET))
                && M1.getEtat()==MARCHE)
            || (V23.getEtat()==OUVERT && (tank2.getEtat()==VIDE ||( tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET))
                && M2.getEtat()==MARCHE)
            ){
        M3.arreterM();
        M3marche->hide();
        M3arret->show();
    }
    if(tank3.pompeS->getEtat()==20){cout<<"pompe P32 (pompeS tank3) MARCHE"<<endl;}
                     else{cout<<"pompe P32 (pompeS tank3) ARRET"<<endl; }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "arreter P32" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }

}
//DEMARRER TEST
void MainWindow::on_pushButton_13_clicked()
{
        demo=ON;
        tank1.pompeP->setEtat(PANNE);
        M1.arreterM();
        M1marche->hide();
        M1arret->show();
        cout<<"pompe primaire du tank 1 en panne !"<<endl;



}



void MainWindow::on_pushButton_16_clicked()
{

   tank1.pompeP->demarrerP();
   tank2.pompeP->demarrerP();
   tank3.pompeP->demarrerP();

 if(tank1.pompeP->getEtat()==PANNE || tank1.pompeP->getEtat()==ARRET){cout<<"Pompe Primaire du tank1 en panne !"<<endl;}
 else {
     if(tank1.getEtat()!=VIDE){
      M1.demarrerM();
        if (M1.getEtat()==MARCHEM) {
            M1marche->show();
            M1arret->hide();
     cout<<"Pompe primaire du tank1 a nouveau en marche"<<endl;
     cout<<"Redemarrage Moteur 1"<<endl;}}}

 if(tank2.pompeP->getEtat()==PANNE || tank2.pompeP->getEtat()==ARRET){cout<<"Pompe Primaire du tank2 en panne !"<<endl;}
 else {
      if(tank1.getEtat()!=VIDE){
      M2.demarrerM();
      if (M2.getEtat()==MARCHEM) {
          M2marche->show();
          M2arret->hide();
     cout<<"Pompe primaire du tank2 a nouveau en marche"<<endl;
     cout<<"Redemarrage Moteur 2"<<endl;}}}

 if(tank3.pompeP->getEtat()==PANNE || tank3.pompeP->getEtat()==ARRET){cout<<"Pompe Primaire du tank3 en panne !"<<endl;}
 else {
      if(tank1.getEtat()!=VIDE){
      M3.demarrerM();
        if (M3.getEtat()==MARCHEM) {
            M3marche->show();
            M3arret->hide();
     cout<<"Pompe primaire du tank3 a nouveau en marche"<<endl;
     cout<<"Redemarrage Moteur 3"<<endl;}}}


}
//ouvrir vanne V13
void MainWindow::on_pushButton_17_clicked()
{
    V13.ouvrirV();
    V13fermee->hide();
    V13ouverte->show();

    if(V13.getEtat()==30){
        cout<<"vanne V13 OUVERTE"<<endl;
    }
    else{cout<<"vanne V13 FERMEE"<<endl; }



    if ((tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET))
             && tank3.getEtat()!=VIDE
            && ((tank3.pompeP->getEtat()==MARCHE && tank3.pompeS->getEtat()==MARCHE)
            || ((tank3.pompeP->getEtat()==MARCHE || tank3.pompeS->getEtat()==MARCHE) && M3.getEtat()==ARRETM))){
        if (M1.getEtat()==ARRETM){
            M1.demarrerM();
            M1marche->show();
            M1arret->hide();
        }
    }

    if ((tank3.getEtat()==VIDE || (tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET))
        && tank1.getEtat()!=VIDE
            && ((tank1.pompeP->getEtat()==MARCHE && tank1.pompeS->getEtat()==MARCHE)
            || ((tank1.pompeP->getEtat()==MARCHE || tank1.pompeS->getEtat()==MARCHE) && M1.getEtat()==ARRETM))){
        if (M3.getEtat()==ARRETM){
            M3.demarrerM();
            M3marche->show();
            M3arret->hide();
        }
    }
        if(V12.getEtat()==OUVERT){cout<<"vanne V12 OUVERTE"<<endl;}
                         else{cout<<"vanne V12 FERMEE"<<endl; }

        if(demo==ON){


            ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
            if(monFlux)
            {
                monFlux << "ouvrir V13" << endl;

            }
            else
            {
                cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
            }

        }

}

//bouton ouvrir Vanne VT12
void MainWindow::on_pushButton_21_clicked()
{
    VT12.ouvrirV();

    VT12ouverte->show();
    VT12fermee->hide();

    if(VT12.getEtat()==30){cout<<"vanne VT12 OUVERTE"<<endl;}
                     else{cout<<"vanne VT12 FERMEE"<<endl; }
    if(tank1.getEtat()==VIDE && tank2.getEtat()!=VIDE){
        tank1.setEtat(tank2.getEtat()/2);
        tank2.setEtat(tank2.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        m_pb->setValue(tank1.getEtat());
          cout<<"Tank 1 : "<<tank1.getEtat()<<"Tank1 alimente par tank2 !"<<endl;
          if(M1.getEtat()==ARRETM){
              M1.demarrerM();
              M1marche->show();
              M1arret->hide();
          }


    }
    if(tank2.getEtat()==VIDE && tank1.getEtat()!=VIDE){
        tank2.setEtat(tank1.getEtat()/2);
        tank1.setEtat(tank1.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        m_pb->setValue(tank1.getEtat());
          cout<<"Tank 2 : "<<tank2.getEtat()<<"Tank2 alimente par tank1 !"<<endl;
          if(M2.getEtat()==ARRETM){
              M2.demarrerM();
              M2marche->show();
              M2arret->hide();
          }

          if(tank1.getEtat()==VIDE && tank2.getEtat()==VIDE){
              M1.arreterM();
              M1marche->hide();
              M1arret->show();

              M2.arreterM();
              M2marche->hide();
              M2arret->show();
          }
          if (tank3.getEtat()==VIDE && VT23.getEtat()==OUVERT){
              tank3.setEtat(tank2.getEtat()/2);
              tank2.setEtat(tank2.getEtat()/2);
              m_pb3->setValue(tank3.getEtat());
              m_pb2->setValue(tank2.getEtat());
                cout<<"Tank 3 : "<<tank1.getEtat()<<"Tank3 alimente par tank2 par l'intermediaire du tank1 !"<<endl;
                if(M3.getEtat()==ARRETM){
                    M3.demarrerM();
                    M3marche->show();
                    M3arret->hide();
                }
          }


    }
    if(demo==ON){
        cout<<"coucou"<<endl;

        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "ouverture VT12" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }


        }


}
//bouton fermer VT12
void MainWindow::on_pushButton_22_clicked()
{

    VT12.fermerV();
    VT12ouverte->hide();
    VT12fermee->show();


    if(VT12.getEtat()==30){cout<<"vanne VT12 OUVERTE"<<endl;}
                     else{cout<<"vanne VT12 FERMEE"<<endl; }

    if(tank1.getEtat()==VIDE && V12.getEtat()==FERME && V13.getEtat()==FERME){

       M1.arreterM();
       M1arret->show();
       M1marche->hide();
    }
    if(tank1.getEtat()==VIDE && V12.getEtat()==OUVERT && tank2.getEtat()==VIDE && V13.getEtat()==FERME){
       M1.arreterM();
       M1arret->show();
       M1marche->hide();
    }
    if(tank1.getEtat()==VIDE && V12.getEtat()==OUVERT && tank2.getEtat()!=VIDE && V13.getEtat()==FERME){
       if(M1.getEtat()==ARRETM){
           M1.demarrerM();
           M1arret->hide();
           M1marche->show();}
    }
    if(tank1.getEtat()==VIDE && V12.getEtat()==FERME && V13.getEtat()==OUVERT && tank3.getEtat()==VIDE){
       M1.arreterM();
       M1arret->show();
       M1marche->hide();
    }
    if(tank1.getEtat()==VIDE && V12.getEtat()==FERME && V13.getEtat()==OUVERT && tank3.getEtat()!=VIDE){
        if(M1.getEtat()==ARRETM){
            M1.demarrerM();
            M1arret->hide();
            M1marche->show();}
    }
    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "fermeture VT12" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }
}


//bouton ouvrir VT23
void MainWindow::on_pushButton_23_clicked()
{
    VT23.ouvrirV();
    VT23fermee->hide();
    VT23ouverte->show();

    if(VT23.getEtat()==30){cout<<"vanne VT23 OUVERTE"<<endl;}
                     else{cout<<"vanne VT23 FERMEE"<<endl; }

    if(tank2.getEtat()==VIDE && tank3.getEtat()!=VIDE){
        tank2.setEtat(tank3.getEtat()/2);
        tank3.setEtat(tank3.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        m_pb3->setValue(tank3.getEtat());
          cout<<"Tank 2 : "<<tank2.getEtat()<<", Tank2 alimente par tank3 !"<<endl;
          if(M2.getEtat()==ARRETM){
              M2.demarrerM();
              M2marche->show();
              M2arret->hide();
          }
if (tank1.getEtat()==VIDE && VT12.getEtat()==OUVERT){
    tank1.setEtat(tank2.getEtat()/2);
    tank2.setEtat(tank2.getEtat()/2);
    m_pb->setValue(tank1.getEtat());
    m_pb2->setValue(tank2.getEtat());
      cout<<"Tank 1 : "<<tank1.getEtat()<<", Tank1 alimente par tank2 par l'intermediaire du tank3 !"<<endl;
      if(M1.getEtat()==ARRETM){
          M1.demarrerM();
          M1marche->show();
          M1arret->hide();
      }
}

    }

    if(tank3.getEtat()==VIDE && tank2.getEtat()!=VIDE){
        tank3.setEtat(tank2.getEtat()/2);
        tank2.setEtat(tank2.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        m_pb3->setValue(tank3.getEtat());
          cout<<"Tank 3 : "<<tank3.getEtat()<<", Tank3 alimente par tank2 !"<<endl;
          if(M3.getEtat()==ARRETM){
              M3.demarrerM();
              M3marche->show();
              M3arret->hide();
          }


    }
    if(tank2.getEtat()==VIDE
       && tank3.getEtat()==VIDE
       && V13.getEtat()==FERME
       && V12.getEtat()==FERME){

          M2.arreterM();
          M2marche->hide();
          M2arret->show();

          M3.arreterM();
          M3marche->hide();
          M3arret->show();

}
    if(tank2.getEtat()==VIDE
       && tank3.getEtat()==VIDE
       && V13.getEtat()==FERME
       && tank1.getEtat()!=VIDE){

          M3.arreterM();
          M3marche->hide();
          M3arret->show();

}
    if(tank2.getEtat()==VIDE
       && tank3.getEtat()==VIDE
       && V12.getEtat()==FERME
       && tank1.getEtat()!=VIDE){

          M2.arreterM();
          M2marche->hide();
          M2arret->show();

}
    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "ouvrir VT23" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }

}
//fermer VT23
void MainWindow::on_pushButton_24_clicked()
{
    VT23.fermerV();
    VT23ouverte->hide();
    VT23fermee->show();

    if(VT23.getEtat()==30){cout<<"vanne VT23 OUVERTE"<<endl;}
                     else{cout<<"vanne VT23 FERMEE"<<endl; }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "fermeture VT23" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
    }
}
//ouvrir vanne V12
void MainWindow::on_pushButton_19_clicked()
{

    V12.ouvrirV();
    V12fermee->hide();
    V12ouverte->show();


if (tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET)){
    if( tank2.getEtat()!=VIDE
        && (
(tank2.pompeP->getEtat()==MARCHE && tank2.pompeS->getEtat()==MARCHE) || ((tank2.pompeP->getEtat()==MARCHE || tank2.pompeS->getEtat()==MARCHE) && M2.getEtat()==ARRETM)
           )
       ){
            M1.demarrerM();
            M1marche->show();
            M1arret->hide();
            cout<<"moteur M1 alimente par M2"<<endl;

    }}
    if (tank2.getEtat()==VIDE || (tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET)){
        if ( tank1.getEtat()!=VIDE
            && (((tank1.pompeP->getEtat()==MARCHE && tank1.pompeS->getEtat()==MARCHE))
            || ((tank1.pompeP->getEtat()==MARCHE || tank1.pompeS->getEtat()==MARCHE) && M1.getEtat()==ARRETM))){

            M2.demarrerM();
            M2marche->show();
            M2arret->hide();
            cout<<"moteur M2 alimente par M1"<<endl;

    }}
    if(V12.getEtat()==OUVERT){cout<<"vanne V12 OUVERTE"<<endl;}
                     else{cout<<"vanne V12 FERMEE"<<endl; }

    if(demo==ON && (tank2.pompeS->getEtat()==MARCHE)){
        demo=OFF;
        cout<<"bien joue, test 1 fini"<<endl;


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        ifstream fichier("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "ouvrir V12 \n" << endl;
            string ligne;
int cmp=0;
                 while(getline(fichier, ligne))
                 {

                    if ((ligne=="test de Léo :") || (ligne=="test de Lola :")){
                        cmp=0;
                    }
                    cmp++;

                 }
if (cmp==6){monFlux << "Tout bon : 10/10\n" << endl;}
if (cmp==7){monFlux << "9/10 \n" << endl;}
if (cmp==8){monFlux << "8/10 \n" << endl;}
if (cmp==9){monFlux << "7/10 \n" << endl;}
if (cmp<6 || cmp>9){monFlux << "5/10, peu mieux faire \n" << endl;


}

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }



    }
    /*
//cas V12 et V13 ouvert
    if (tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==ARRET && tank1.pompeS->getEtat()==ARRET)){

        if (V13.getEtat()==OUVERT && V23.getEtat()==FERME
    && (tank3.getEtat()!=VIDE && M3.getEtat()==MARCHEM
    && (tank3.pompeP->getEtat()==MARCHE && tank3.pompeS->getEtat()==MARCHE))){
            if (M1.getEtat()==ARRETM){
                M1.demarrerM();
                M1marche->show();
                M1arret->hide();
            }
        }

        if (V13.getEtat()==OUVERT
     && (tank3.getEtat()!=VIDE && M3.getEtat()==ARRETM
     && (tank3.pompeP->getEtat()==MARCHE || tank3.pompeS->getEtat()==MARCHE))){
            if (M1.getEtat()==ARRETM){
                M1.demarrerM();
                M1marche->show();
                M1arret->hide();
            }
        }

    }
    if (tank3.getEtat()==VIDE || (tank3.pompeP->getEtat()==ARRET && tank3.pompeS->getEtat()==ARRET)){

        if (V13.getEtat()==OUVERT && V23.getEtat()==FERME
    && (tank1.getEtat()!=VIDE && (M1.getEtat()==ARRETM || (M2.getEtat()==ARRETM ))
    && (tank1.pompeP->getEtat()==MARCHE && tank1.pompeS->getEtat()==MARCHE))){
            if (M3.getEtat()==ARRETM){
                M3.demarrerM();
                M3marche->show();
                M3arret->hide();
            }
        }



    }

// cas V12 et V23 ouvert
    if (tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==ARRET && tank1.pompeS->getEtat()==ARRET)){

        if (V23.getEtat()==OUVERT && V13.getEtat()==FERME
    && (tank3.getEtat()!=VIDE && M3.getEtat()==MARCHEM
    && (tank3.pompeP->getEtat()==MARCHE && tank3.pompeS->getEtat()==MARCHE))){
            if (M1.getEtat()==ARRETM){
                M1.demarrerM();
                M1marche->show();
                M1arret->hide();
            }
        }

        if (V23.getEtat()==OUVERT
     && (tank3.getEtat()!=VIDE && M3.getEtat()==ARRETM
     && (tank3.pompeP->getEtat()==MARCHE || tank3.pompeS->getEtat()==MARCHE))){
            if (M1.getEtat()==ARRETM){
                M1.demarrerM();
                M1marche->show();
                M1arret->hide();
            }
        }

    }

*/


}
//fermer Vanne V12
void MainWindow::on_pushButton_20_clicked()
{
    V12.fermerV();
    V12ouverte->hide();
    V12fermee->show();

    if(V12.getEtat()==30){cout<<"vanne V12 OUVERTE"<<endl;}
                     else{cout<<"vanne V12 FERMEE"<<endl; }

    if((tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET)) && V13.getEtat()==FERME){
        M1.arreterM();
        M1marche->hide();
        M1arret->show();

    }
    if ((tank2.getEtat()==VIDE || (tank2.pompeP->getEtat()==PANNE && tank2.pompeS->getEtat()==ARRET)) && V23.getEtat()==FERME){
        M2.arreterM();
        M2marche->hide();
        M2arret->show();
    }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "fermeture V12" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }

}
//fermer V13
void MainWindow::on_pushButton_18_clicked()
{
    V13.fermerV();
    V13ouverte->hide();
    V13fermee->show();

    if(V13.getEtat()==30){cout<<"vanne V13 OUVERTE"<<endl;}
                     else{cout<<"vanne V13 FERMEE"<<endl; }

    if((tank3.getEtat()==VIDE || (tank3.pompeP->getEtat()==PANNE && tank3.pompeS->getEtat()==ARRET)) && V23.getEtat()==FERME){
        M3.arreterM();
        M3marche->hide();
        M3arret->show();

    }
    if ((tank1.getEtat()==VIDE || (tank1.pompeP->getEtat()==PANNE && tank1.pompeS->getEtat()==ARRET)) && V12.getEtat()==FERME){
        M1.arreterM();
        M1marche->hide();
        M1arret->show();
    }

    if(demo==ON){


        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "fermeture V13" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }

    }

}

//bouton vidange tank2
void MainWindow::on_pushButton_3_clicked()
{

    if (VT12.getEtat()==FERME && VT23.getEtat()==FERME){
        tank2.setEtat(VIDE);
        m_pb2->setValue(tank2.getEtat());
        cout<<"Tank 2 : VIDE, "<<tank2.getEtat()<<endl;
    }

    if( VT12.getEtat()==OUVERT && VT23.getEtat()==FERME){
        tank2.setEtat(tank1.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        tank1.setEtat(tank1.getEtat()/2);
        m_pb->setValue(tank1.getEtat());
          cout<<"Tank 2 : "<<tank2.getEtat()<<", Tank2 alimente par tank1 !"<<endl;

    }
    if( VT23.getEtat()==OUVERT && VT12.getEtat()==FERME){
        tank2.setEtat(tank3.getEtat()/2);
        tank3.setEtat(tank3.getEtat()/2);
        m_pb2->setValue(tank2.getEtat());
        m_pb3->setValue(tank3.getEtat());
          cout<<"Tank 2 : "<<tank2.getEtat()<<", Tank2 alimente par tank3 !"<<endl;

    }
    if (VT12.getEtat()==OUVERT && VT23.getEtat()==OUVERT){
        tank2.setEtat(tank1.getEtat()/3+tank3.getEtat()/3);
        tank1.setEtat(tank1.getEtat()-tank1.getEtat()/3);
        tank3.setEtat(tank3.getEtat()-tank3.getEtat()/3);
        m_pb2->setValue(tank2.getEtat());
        m_pb->setValue(tank1.getEtat());
        m_pb3->setValue(tank3.getEtat());
         cout<<"Tank 2 : "<<tank2.getEtat()<<", Tank2 alimente par tank1 et tank3 !"<<endl;
    }



    if(tank1.getEtat()<1){tank1.setEtat(VIDE); cout<<"tank 1 VIDE"<<endl;}
    if(tank2.getEtat()<1){tank2.setEtat(VIDE); cout<<"tank 2 VIDE"<<endl;}
    if(tank3.getEtat()<1){tank3.setEtat(VIDE); cout<<"tank 3 VIDE"<<endl;}


    if (tank2.getEtat()==VIDE && V12.getEtat()==FERME && V23.getEtat()==FERME){
        M2.arreterM();
        M2arret->show();
        M2marche->hide();
          cout<<"M2 plus alimente, tank2 VIDE"<<endl;
    }

    if (tank2.getEtat()==VIDE && V12.getEtat()==OUVERT && V23.getEtat()==FERME && tank1.getEtat()!=VIDE)
    {  if (M2.getEtat()==ARRETM){
            M2.demarrerM();
            M2marche->show();
            M2arret->hide();
              cout<<"M2 alimente par tank1"<<endl;
        }
    }
    if (tank2.getEtat()==VIDE && V23.getEtat()==OUVERT && V12.getEtat()==FERME && tank3.getEtat()!=VIDE)
    {  if (M2.getEtat()==ARRETM){
            M2.demarrerM();
            M2marche->show();
            M2arret->hide();
            cout<<"M2 alimente par tank3"<<endl;
        }
    }

    if (tank2.getEtat()==VIDE && V23.getEtat()==OUVERT && V12.getEtat()==OUVERT
            && (tank3.getEtat()!=VIDE || tank1.getEtat()!=VIDE))
    {  if (M2.getEtat()==ARRETM){
            M2.demarrerM();
            M2marche->show();
            M2arret->hide();
            cout<<"M2 alimente par un des autres moteurs !"<<endl;
        }
    }

}
//bouton panne P11
void MainWindow::on_pushButton_15_clicked()
{
   tank1.pompeP->panneP();
   if(tank1.pompeP->getEtat()==PANNE){cout<<"Pompe Primaire du tank1 en panne !"<<endl;}
   if(tank1.pompeS->getEtat()==ARRET && V12.getEtat()==FERME &&  V13.getEtat()==FERME && VT12.getEtat()==FERME)
   {M1.arreterM();
       if(M1.getEtat()==ARRETM) cout<<"moteur 1 ARRET"<<endl;
       if(M1.getEtat()==MARCHEM) cout<<"moteur 1 MARCHE"<<endl;
    M1arret->show();

   }

}


void MainWindow::on_pushButton_25_clicked()
{
    tank2.pompeP->panneP();
    if(tank2.pompeP->getEtat()==22){cout<<"Pompe Primaire du tank2 en panne !"<<endl;}
    if(tank2.pompeS->getEtat()==21 && V12.getEtat()==31 &&  V13.getEtat()==31 && VT12.getEtat()==31 && VT23.getEtat()==31 && V23.getEtat()==31 )
    {M2.arreterM();
        if(M2.getEtat()==ARRETM) cout<<"moteur 2 ARRET"<<endl;
        if(M2.getEtat()==MARCHEM) cout<<"moteur 2 MARCHE"<<endl;
     M2arret->show();
    }
}

void MainWindow::on_pushButton_26_clicked()
{
    tank3.pompeP->panneP();
    if(tank3.pompeP->getEtat()==22){cout<<"Pompe Primaire du tank1 en panne !"<<endl;}
    if(tank3.pompeS->getEtat()==21 &&  V13.getEtat()==31 && VT23.getEtat()==31)
    {M3.arreterM();
        if(M3.getEtat()==ARRETM) cout<<"moteur 3 ARRET"<<endl;
        if(M3.getEtat()==MARCHEM) cout<<"moteur 3 MARCHE"<<endl;
     M3arret->show();
    }

}
