#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vanne.h"
#include "pompe.h"
#include "QProgressBar"
#include <QMainWindow>
#include <QDialog>
#include "reservoir.h"
#include "connexion.h"

#define ON 96
#define OFF 97

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int demo;
   /* QFile *file;

    QTextStream *flux=new QTextStream(file);*/





///Widgets
    //vie des reservoirs
    QProgressBar *m_pb;
    QProgressBar *m_pb2;
    QProgressBar *m_pb3;

          //Widgets des Vannes
          QWidget *VT12ouverte;
          QWidget *VT12fermee;
          QWidget *VT23ouverte;
          QWidget *VT23fermee;
          QWidget *V12ouverte;
          QWidget *V12fermee;
          QWidget *V13ouverte;
          QWidget *V13fermee;
          QWidget *V23ouverte;
          QWidget *V23fermee;


          //Widgets des moteurs
          QWidget *M1marche;
          QWidget *M1arret;
          QWidget *M2marche;
          QWidget *M2arret;
          QWidget *M3marche;
          QWidget *M3arret;


          //pompes
          QWidget *P11marche;
          QWidget *P11arret;


         //couleurs
         QPalette noir = palette();
         QPalette vert = palette();
         QPalette blanc = palette();
         QPalette rouge = palette();


///Objets

 //initialisation des reservoirs
 Reservoir tank1=Reservoir(200,"tank1");
 Reservoir tank2=Reservoir(300,"tank2");
 Reservoir tank3=Reservoir(200,"tank3");

 //initialisation des vannes
    Vanne VT12=Vanne();
    Vanne VT23=Vanne();
    Vanne V13=Vanne();
    Vanne V12=Vanne();
    Vanne V23=Vanne();

//initialisation des moteurs
    Moteur M1=Moteur();
    Moteur M2=Moteur();
    Moteur M3=Moteur();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


   // void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    //void on_pushButton_14_clicked();

   // void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
